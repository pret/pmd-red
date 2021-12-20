// dungeonjson.cpp

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::find;

#include <map>
using std::map;

#include <fstream>
using std::ofstream; using std::ifstream;

#include <sstream>
using std::ostringstream;

#include <limits>
using std::numeric_limits;

#include "json11.h"
using json11::Json;

#include "dungeonjson.h"

const string TABLE_END = "@ END OF TABLE\n";

string read_text_file(string filepath) {
    ifstream in_file(filepath);

    if (!in_file.is_open())
        FATAL_ERROR("Cannot open file %s for reading.\n", filepath.c_str());

    string text;

    in_file.seekg(0, std::ios::end);
    text.resize(in_file.tellg());

    in_file.seekg(0, std::ios::beg);
    in_file.read(&text[0], text.size());

    in_file.close();

    return text;
}

void write_text_file(string filepath, string text) {
    ofstream out_file(filepath, std::ofstream::binary);

    if (!out_file.is_open())
        FATAL_ERROR("Cannot open file %s for writing.\n", filepath.c_str());

    out_file << text;

    out_file.close();
}

string generate_map_header_text(Json map_data, Json layouts_data, string version) {
    string map_layout_id = map_data["layout"].string_value();

    vector<Json> matched;

    for (auto &field : layouts_data["layouts"].array_items()) {
        if (map_layout_id == field["id"].string_value())
            matched.push_back(field);
    }

    if (matched.size() != 1)
        FATAL_ERROR("Failed to find matching layout for %s.\n", map_layout_id.c_str());

    Json layout = matched[0];

    ostringstream text;

    text << map_data["name"].string_value() << ":\n"
         << "\t.4byte " << layout["name"].string_value() << "\n";

    if (map_data.object_items().find("shared_events_map") != map_data.object_items().end())
        text << "\t.4byte " << map_data["shared_events_map"].string_value() << "_MapEvents\n";
    else
        text << "\t.4byte " << map_data["name"].string_value() << "_MapEvents\n";

    if (map_data.object_items().find("shared_scripts_map") != map_data.object_items().end())
        text << "\t.4byte " << map_data["shared_scripts_map"].string_value() << "_MapScripts\n";
    else
        text << "\t.4byte " << map_data["name"].string_value() << "_MapScripts\n";

    if (map_data.object_items().find("connections") != map_data.object_items().end()
     && map_data["connections"].array_items().size() > 0)
        text << "\t.4byte " << map_data["name"].string_value() << "_MapConnections\n";
    else
        text << "\t.4byte 0x0\n";

    text << "\t.2byte " << map_data["music"].string_value() << "\n"
         << "\t.2byte " << layout["id"].string_value() << "\n"
         << "\t.byte "  << map_data["region_map_section"].string_value() << "\n"
         << "\t.byte "  << map_data["requires_flash"].bool_value() << "\n"
         << "\t.byte "  << map_data["weather"].string_value() << "\n"
         << "\t.byte "  << map_data["map_type"].string_value() << "\n"
         << "\t.2byte 0\n";

    if (version == "ruby")
        text << "\t.byte " << map_data["show_map_name"].bool_value() << "\n";
    else if (version == "emerald")
        text << "\tmap_header_flags "
             << "allow_cycling=" << map_data["allow_cycling"].bool_value() << ", "
             << "allow_escaping=" << map_data["allow_escaping"].bool_value() << ", "
             << "allow_running=" << map_data["allow_running"].bool_value() << ", "
             << "show_map_name=" << map_data["show_map_name"].bool_value() << "\n";

     text << "\t.byte " << map_data["battle_scene"].string_value() << "\n\n";

    return text.str();
}

string generate_map_connections_text(Json map_data) {
    if (map_data["connections"] == Json())
        return string("\n");

    ostringstream text;

    text << map_data["name"].string_value() << "_MapConnectionsList:\n";

    for (auto &connection : map_data["connections"].array_items()) {
        text << "\tconnection "
             << connection["direction"].string_value() << ", "
             << connection["offset"].int_value() << ", "
             << connection["map"].string_value() << "\n";
    }

    text << "\n" << map_data["name"].string_value() << "_MapConnections:\n"
         << "\t.4byte " << map_data["connections"].array_items().size() << "\n"
         << "\t.4byte " << map_data["name"].string_value() << "_MapConnectionsList\n\n";

    return text.str();
}

string generate_map_events_text(Json map_data) {
    if (map_data.object_items().find("shared_events_map") != map_data.object_items().end())
        return string("\n");

    ostringstream text;

    string objects_label, warps_label, coords_label, bgs_label;

    if (map_data["object_events"].array_items().size() > 0) {
        objects_label = map_data["name"].string_value() + "_ObjectEvents";
        text << objects_label << ":\n";
        for (unsigned int i = 0; i < map_data["object_events"].array_items().size(); i++) {
            auto obj_event = map_data["object_events"].array_items()[i];
            text << "\tobject_event " << i + 1 << ", "
                 << obj_event["graphics_id"].string_value() << ", 0, "
                 << obj_event["x"].int_value() << ", "
                 << obj_event["y"].int_value() << ", "
                 << obj_event["elevation"].int_value() << ", "
                 << obj_event["movement_type"].string_value() << ", "
                 << obj_event["movement_range_x"].int_value() << ", "
                 << obj_event["movement_range_y"].int_value() << ", "
                 << obj_event["trainer_type"].string_value() << ", "
                 << obj_event["trainer_sight_or_berry_tree_id"].string_value() << ", "
                 << obj_event["script"].string_value() << ", "
                 << obj_event["flag"].string_value() << "\n";
        }
        text << "\n";
    } else {
        objects_label = "0x0";
    }

    if (map_data["warp_events"].array_items().size() > 0) {
        warps_label = map_data["name"].string_value() + "_MapWarps";
        text << warps_label << ":\n";
        for (auto &warp_event : map_data["warp_events"].array_items()) {
            text << "\twarp_def "
                 << warp_event["x"].int_value() << ", "
                 << warp_event["y"].int_value() << ", "
                 << warp_event["elevation"].int_value() << ", "
                 << warp_event["dest_warp_id"].int_value() << ", "
                 << warp_event["dest_map"].string_value() << "\n";
        }
        text << "\n";
    } else {
        warps_label = "0x0";
    }

    if (map_data["coord_events"].array_items().size() > 0) {
        coords_label = map_data["name"].string_value() + "_MapCoordEvents";
        text << coords_label << ":\n";
        for (auto &coord_event : map_data["coord_events"].array_items()) {
            if (coord_event["type"].string_value() == "trigger") {
                text << "\tcoord_event "
                     << coord_event["x"].int_value() << ", "
                     << coord_event["y"].int_value() << ", "
                     << coord_event["elevation"].int_value() << ", "
                     << coord_event["var"].string_value() << ", "
                     << coord_event["var_value"].string_value() << ", "
                     << coord_event["script"].string_value() << "\n";
            }
            else if (coord_event["type"] == "weather") {
                text << "\tcoord_weather_event "
                     << coord_event["x"].int_value() << ", "
                     << coord_event["y"].int_value() << ", "
                     << coord_event["elevation"].int_value() << ", "
                     << coord_event["weather"].string_value() << "\n";
            }
        }
        text << "\n";
    } else {
        coords_label = "0x0";
    }

    if (map_data["bg_events"].array_items().size() > 0) {
        bgs_label = map_data["name"].string_value() + "_MapBGEvents";
        text << bgs_label << ":\n";
        for (auto &bg_event : map_data["bg_events"].array_items()) {
            if (bg_event["type"] == "sign") {
                text << "\tbg_event "
                     << bg_event["x"].int_value() << ", "
                     << bg_event["y"].int_value() << ", "
                     << bg_event["elevation"].int_value() << ", "
                     << bg_event["player_facing_dir"].string_value() << ", "
                     << bg_event["script"].string_value() << "\n";
            }
            else if (bg_event["type"] == "hidden_item") {
                text << "\tbg_hidden_item_event "
                     << bg_event["x"].int_value() << ", "
                     << bg_event["y"].int_value() << ", "
                     << bg_event["elevation"].int_value() << ", "
                     << bg_event["item"].string_value() << ", "
                     << bg_event["flag"].string_value() << "\n";
            }
            else if (bg_event["type"] == "secret_base") {
                text << "\tbg_secret_base_event "
                     << bg_event["x"].int_value() << ", "
                     << bg_event["y"].int_value() << ", "
                     << bg_event["elevation"].int_value() << ", "
                     << bg_event["secret_base_id"].string_value() << "\n";
            }
        }
        text << "\n";
    } else {
        bgs_label = "0x0";
    }

    text << map_data["name"].string_value() << "_MapEvents::\n"
         << "\tmap_events " << objects_label << ", " << warps_label << ", "
         << coords_label << ", " << bgs_label << "\n\n";

    return text.str();
}

string generate_pokemon_table_text(Json map_data) {

    ostringstream text;
    int pokemon_mask;
    int probability_total;

    text << "@ This is auto-generated by " << map_data["name"].string_value() << ".json" << "\n";
        for (auto &table: map_data["tables"].array_items()) {
            probability_total = 0;

            text << ".global " << table["name"].string_value() << "\n";
            text << table["name"].string_value() << ":\n";

            for (auto &pokemon: table["pokemon"].array_items()) {
                pokemon_mask = (pokemon["level"].int_value() * 512);
                probability_total += pokemon["probability"].int_value();
                text << ".2byte "  << pokemon["species"].string_value() << " + " << pokemon_mask;
                    // We have to repeat to maintain matching
                    if(pokemon["probability"].int_value() == 0)
                    {
                         text << ", " <<  "0x00, 0x00";
                    }
                    else
                    {
                        text << ", " <<  probability_total << ", " << probability_total;
                    }
                    text << ", " << "0x00" << "\n";
            }

            // Append null entry to end
            text << TABLE_END;
            text << ".2byte " << "0x00, 0x00, 0x00, 0x00" << "\n";
        }

    return text.str();
}

string generate_floorID_table_text(Json map_data) {

    ostringstream text;

    text << "@ This is auto-generated by " << map_data["name"].string_value() << ".json" << "\n";

    text << ".global " << map_data["name"].string_value() << "\n";
    text << map_data["name"].string_value() << ":\n";
        // Append null entry to Start
    text << ".2byte " << "0, 0, 0, 0, 0, 0, 0, 0" << "\n";
    for (auto &table: map_data["tables"].array_items()) {

        text << ".2byte "  << table["MainData"].int_value()
            << ", " << table["Pokemon"].int_value()
            << ", " << table["Traps"].int_value()
            << ", " << table["Items"].int_value()
            << ", " << table["KecleonShop"].int_value()
            << ", " << table["MonsterRoomItems"].int_value()
            << ", " << table["BuriedItems"].int_value()
            << ", " << "0" << "\n";

    }
    text << TABLE_END;

    return text.str();
}

string get_start_bytes(int num_bytes) {
    return num_bytes == 1 ? "\n.byte " : "\n." + std::to_string(num_bytes) + "byte ";
}

string get_json_bool_value(Json data) {
    return data.bool_value() ? "1" : "0";
}

string get_json_int_value(Json data) {
    return std::to_string(data.int_value());
}

string get_json_string_value(Json data) {
    return data.is_string() ? data.string_value() : "0";
}

string get_json_binary_value(Json data) {
    return data.is_string() ? std::to_string(std::stoi(data.string_value().substr(2), NULL, 2)) : "0";
}

string read_json(Json data, int num_bytes, string(*json_reader)(Json)) {
    return get_start_bytes(num_bytes) + json_reader(data);
}

string read_json_bool(Json data) {
    return read_json(data, 1, get_json_bool_value);
}

string read_json_int(Json data, int num_bytes) {
    return read_json(data, num_bytes, get_json_int_value);
}

string read_json_string(Json data, int num_bytes) {
    return read_json(data, num_bytes, get_json_string_value);
}

string read_json_binary(Json data, int num_bytes) {
    return read_json(data, num_bytes, get_json_binary_value);
}

string read_json_array(Json data, int num_bytes, int expected_count, string(*json_reader)(Json)) {
    ostringstream data_string;
    bool first = true;
    vector<Json> data_items = data.array_items();
    for (int i = 0; i < expected_count; i++) {
        string item = i < data_items.size() ? json_reader(data_items[i]) : "0";

        data_string << (first ? "" : ", ") << item;
        first = false;
    }
    return get_start_bytes(num_bytes) + data_string.str();
}

string read_json_bool_array(Json data, int num_bytes, int expected_count) {
    return read_json_array(data, num_bytes, expected_count, get_json_bool_value);
}

string read_json_int_array(Json data, int num_bytes, int expected_count) {
    return read_json_array(data, num_bytes, expected_count, get_json_int_value);
}

string read_json_string_array(Json data, int num_bytes, int expected_count) {
    return read_json_array(data, num_bytes, expected_count, get_json_string_value);
}

string generate_species_data_text(Json data) {
    ostringstream text;

    text << "@ This is auto-generated by species_data.json.\n";
    text << "#include \"constants/ability.h\"\n";
    text << "#include \"constants/evolve_type.h\"\n";
    text << "#include \"constants/friend_area.h\"\n";
    text << "#include \"constants/item.h\"\n";
    text << "#include \"constants/species.h\"\n";
    text << "#include \"constants/type.h\"\n";
    text << "#include \"constants/walkable_tile.h\"\n";
    text << ".global gSpeciesData\n";
    text << "gSpeciesData:";
    for (Json data_entry : data.array_items()) {
        text << read_json_string(data_entry["species"], 4)
            << read_json_string(data_entry["category"], 4)
            << read_json_int(data_entry["overworld_palette"], 1)
            << read_json_int(data_entry["size"], 1)
            << "\n.2byte 0"
            << read_json_int(data_entry["move_speed"], 4)
            << read_json_binary(data_entry["dialogue_sprites"], 2)
            << read_json_bool(data_entry["unk12"])
            << read_json_string_array(data_entry["types"], 1, 2)
            << read_json_string(data_entry["walkable_tiles"], 1)
            << read_json_string(data_entry["friend_area"], 1)
            << read_json_string_array(data_entry["abilities"], 1, 2)
            << read_json_int(data_entry["shadow_size"], 1)
            << read_json_int(data_entry["unk1A"], 1)
            << read_json_int(data_entry["unk1B"], 1)
            << read_json_bool(data_entry["isMoving"])
            << read_json_int(data_entry["unk1D"], 1)
            << read_json_int(data_entry["base_hp"], 2)
            << read_json_int(data_entry["base_exp"], 4)
            << read_json_int_array(data_entry["base_att_spatt"], 2, 2)
            << read_json_int_array(data_entry["base_def_spdef"], 2, 2)
            << read_json_int(data_entry["lowkick_dmg"], 2)
            << read_json_int(data_entry["sizeorb_dmg"], 2)
            << read_json_int(data_entry["unk30"], 1)
            << read_json_int(data_entry["unk31"], 1)
            << read_json_int(data_entry["unk32"], 1)
            << read_json_bool(data_entry["toolboxEnabled"])
            << read_json_string(data_entry["pre"]["evolve_from"], 2)
            << read_json_string(data_entry["pre"]["evolve_type"], 2);

        if (data_entry["pre"]["evolve_type"] == "EVOLVE_TYPE_ITEM") {
            text << read_json_string(data_entry["needs"]["evolve_need1"], 2);
        } else {
            text << read_json_int(data_entry["needs"]["evolve_need1"], 2);
        }

        text << read_json_int(data_entry["needs"]["evolve_need2"], 2)
            << read_json_int_array(data_entry["dexInternal"], 2, 2)
            << read_json_int(data_entry["base_recruit"], 2)
            << read_json_int_array(data_entry["alphabetParent"], 2, 2)
            << "\n.2byte 0\n";
    }
    text << TABLE_END;
    return text.str();
}

string generate_item_data_text(Json data) {
    ostringstream text;

    text << "@ This is auto-generated by item_data.json.\n";
    text << "#include \"constants/item.h\"\n";
    text << "#include \"constants/move_id.h\"\n";
    text << ".global gItemData\n";
    text << "gItemData:";
    for (Json data_entry : data.array_items()) {
        text << read_json_string(data_entry["namePointer"], 4)
            << read_json_int(data_entry["buyPrice"], 4)
            << read_json_int(data_entry["sellPrice"], 4)
            << read_json_string(data_entry["type"], 1)
            << read_json_int(data_entry["icon"], 1)
            << "\n.2byte 0"
            << read_json_string(data_entry["descriptionPointer"], 4)
            << read_json_bool_array(data_entry["aiFlags"], 1, 3)
            << "\n.byte 0"
            << read_json_string(data_entry["move"], 2)
            << read_json_int(data_entry["order"], 1)
            << read_json_int_array(data_entry["unkThrow1B"], 1, 2)
            << read_json_int(data_entry["palette"], 1)
            << read_json_string(data_entry["category"], 1)
            << "\n.byte 0\n";
    }
    text << TABLE_END;
    return text.str();
}

string generate_move_data_text(Json data) {
    ostringstream text;

    text << "@ This is auto-generated by move_data.json.\n";
    text << "#include \"constants/type.h\"\n";
    text << ".global gMoveData\n";
    text << "gMoveData:";
    for (Json data_entry : data.array_items()) {
        text << read_json_string(data_entry["namePointer"], 4)
            << read_json_int(data_entry["power"], 1)
            << "\n.byte 0"
            << read_json_string(data_entry["type"], 1)
            << "\n.byte 0"
            << read_json_binary(data_entry["targetingFlags"], 2)
            << read_json_binary(data_entry["aiTargetingFlags"], 2)
            << read_json_int(data_entry["maxPP"], 1)
            << read_json_int(data_entry["weight"], 1)
            << read_json_int(data_entry["accuracy1"], 1)
            << read_json_int(data_entry["accuracy2"], 1)
            << read_json_int(data_entry["useChance"], 1)
            << read_json_int(data_entry["hitCount"], 1)
            << read_json_int(data_entry["unk12"], 1)
            << read_json_int(data_entry["criticalHitChance"], 1)
            << read_json_bool(data_entry["affectedByMagicCoat"])
            << read_json_bool(data_entry["targetsUser"])
            << read_json_bool(data_entry["affectedByMuzzled"])
            << read_json_bool(data_entry["cannotHitFrozen"])
            << read_json_bool(data_entry["dealsDirectDamage"])
            << read_json_int(data_entry["rangeType"], 1)
            << "\n.2byte 0"
            << read_json_string(data_entry["descriptionPointer"], 4)
            << read_json_string(data_entry["useText"], 4);
    }
    text << TABLE_END;
    return text.str();
}

string get_directory_name(string filename) {
    size_t dir_pos = filename.find_last_of("/\\");

    return filename.substr(0, dir_pos + 1);
}

void process_map(string map_filepath, string layouts_filepath, string version) {
    string mapdata_err, layouts_err;

    string mapdata_json_text = read_text_file(map_filepath);
    string layouts_json_text = read_text_file(layouts_filepath);

    Json map_data = Json::parse(mapdata_json_text, mapdata_err);
    if (map_data == Json())
        FATAL_ERROR("%s\n", mapdata_err.c_str());

    Json layouts_data = Json::parse(layouts_json_text, layouts_err);
    if (layouts_data == Json())
        FATAL_ERROR("%s\n", layouts_err.c_str());

    string header_text = generate_map_header_text(map_data, layouts_data, version);
    string events_text = generate_map_events_text(map_data);
    string connections_text = generate_map_connections_text(map_data);

    string files_dir = get_directory_name(map_filepath);
    write_text_file(files_dir + "header.inc", header_text);
    write_text_file(files_dir + "events.inc", events_text);
    write_text_file(files_dir + "connections.inc", connections_text);
}

void process_json(string filepath, string output_file_name, string(*table_text_generator)(Json)) {
    string data_err;

    string data_json_text = read_text_file(filepath);

    Json data = Json::parse(data_json_text, data_err);
    if (data == Json())
        FATAL_ERROR("%s\n", data_err.c_str());

    string table_text = table_text_generator(data);

    string files_dir = get_directory_name(filepath);
    write_text_file(files_dir + output_file_name, table_text);
}

string generate_groups_text(Json groups_data) {
    ostringstream text;

    for (auto &key : groups_data["group_order"].array_items()) {
        string group = key.string_value();
        text << group << "::\n";
        auto maps = groups_data[group].array_items();
        for (Json &map_name : maps)
            text << "\t.4byte " << map_name.string_value() << "\n";
        text << "\n";
    }

    text << "\t.align 2\n" << "gMapGroups::\n";
    for (auto &group : groups_data["group_order"].array_items())
        text << "\t.4byte " << group.string_value() << "\n";
    text << "\n";

    return text.str();
}

string generate_connections_text(Json groups_data) {
    vector<Json> map_names;

    for (auto &group : groups_data["group_order"].array_items())
    for (auto map_name : groups_data[group.string_value()].array_items())
        map_names.push_back(map_name);

    vector<Json> connections_include_order = groups_data["connections_include_order"].array_items();

    if (connections_include_order.size() > 0)
        sort(map_names.begin(), map_names.end(), [connections_include_order](const Json &a, const Json &b) {
            auto iter_a = find(connections_include_order.begin(), connections_include_order.end(), a);
            if (iter_a == connections_include_order.end())
                iter_a = connections_include_order.begin() + numeric_limits<int>::max();
            auto iter_b = find(connections_include_order.begin(), connections_include_order.end(), b);
            if (iter_b == connections_include_order.end())
                iter_b = connections_include_order.begin() + numeric_limits<int>::max();
            return iter_a < iter_b;
        });

    ostringstream text;

    for (Json map_name : map_names)
        text << "\t.include \"data/maps/" << map_name.string_value() << "/connections.inc\"\n";

    return text.str();
}

string generate_headers_text(Json groups_data) {
    vector<string> map_names;

    for (auto &group : groups_data["group_order"].array_items())
    for (auto map_name : groups_data[group.string_value()].array_items())
        map_names.push_back(map_name.string_value());

    ostringstream text;

    for (string map_name : map_names)
        text << "\t.include \"data/maps/" << map_name << "/header.inc\"\n";

    return text.str();
}

string generate_events_text(Json groups_data) {
    vector<string> map_names;

    for (auto &group : groups_data["group_order"].array_items())
    for (auto map_name : groups_data[group.string_value()].array_items())
        map_names.push_back(map_name.string_value());

    ostringstream text;

    for (string map_name : map_names)
        text << "\t.include \"data/maps/" << map_name << "/events.inc\"\n";

    return text.str();
}

string generate_map_constants_text(string groups_filepath, Json groups_data) {
    string file_dir = get_directory_name(groups_filepath);
    char dir_separator = file_dir.back();

    ostringstream text;

    text << "#ifndef GUARD_CONSTANTS_MAP_GROUPS_H\n"
         << "#define GUARD_CONSTANTS_MAP_GROUPS_H\n\n";

    int group_num = 0;

    for (auto &group : groups_data["group_order"].array_items()) {
        text << "// Map Group " << group_num << "\n";
        vector<Json> map_ids;
        size_t max_length = 0;

        for (auto &map_name : groups_data[group.string_value()].array_items()) {
            string header_filepath = file_dir + map_name.string_value() + dir_separator + "map.json";
            string err_str;
            Json map_data = Json::parse(read_text_file(header_filepath), err_str);
            map_ids.push_back(map_data["id"]);
            if (map_data["id"].string_value().length() > max_length)
                max_length = map_data["id"].string_value().length();
        }

        int map_id_num = 0;
        for (Json map_id : map_ids) {
            text << "#define " << map_id.string_value() << string((max_length - map_id.string_value().length() + 1), ' ')
                 << "(" << map_id_num++ << " | (" << group_num << " << 8))\n";
        }
        text << "\n";

        group_num++;
    }

    text << "#define MAP_GROUPS_COUNT " << group_num << "\n\n";
    text << "#endif // GUARD_CONSTANTS_MAP_GROUPS_H\n";

    return text.str();
}

void process_groups(string groups_filepath) {
    string err;
    Json groups_data = Json::parse(read_text_file(groups_filepath), err);

    if (groups_data == Json())
        FATAL_ERROR("%s\n", err.c_str());

    string groups_text = generate_groups_text(groups_data);
    string connections_text = generate_connections_text(groups_data);
    string headers_text = generate_headers_text(groups_data);
    string events_text = generate_events_text(groups_data);
    string map_header_text = generate_map_constants_text(groups_filepath, groups_data);

    string file_dir = get_directory_name(groups_filepath);
    char s = file_dir.back();

    write_text_file(file_dir + "groups.inc", groups_text);
    write_text_file(file_dir + "connections.inc", connections_text);
    write_text_file(file_dir + "headers.inc", headers_text);
    write_text_file(file_dir + "events.inc", events_text);
    write_text_file(file_dir + ".." + s + ".." + s + "include" + s + "constants" + s + "map_groups.h", map_header_text);
}

string generate_layout_headers_text(Json layouts_data) {
    ostringstream text;

    for (auto &layout : layouts_data["layouts"].array_items()) {
        string border_label = layout["name"].string_value() + "_Border";
        string blockdata_label = layout["name"].string_value() + "_Blockdata";
        text << border_label << "::\n"
             << "\t.incbin \"" << layout["border_filepath"].string_value() << "\"\n\n"
             << blockdata_label << "::\n"
             << "\t.incbin \"" << layout["blockdata_filepath"].string_value() << "\"\n\n"
             << "\t.align 2\n"
             << layout["name"].string_value() << "::\n"
             << "\t.4byte " << layout["width"].int_value() << "\n"
             << "\t.4byte " << layout["height"].int_value() << "\n"
             << "\t.4byte " << border_label << "\n"
             << "\t.4byte " << blockdata_label << "\n"
             << "\t.4byte " << layout["primary_tileset"].string_value() << "\n"
             << "\t.4byte " << layout["secondary_tileset"].string_value() << "\n\n";
    }

    return text.str();
}

string generate_layouts_table_text(Json layouts_data) {
    ostringstream text;

    text << "\t.align 2\n"
         << layouts_data["layouts_table_label"].string_value() << "::\n";

    for (auto &layout : layouts_data["layouts"].array_items())
        text << "\t.4byte " << layout["name"].string_value() << "\n";

    return text.str();
}

string generate_layouts_constants_text(Json layouts_data) {
    ostringstream text;

    text << "#ifndef GUARD_CONSTANTS_LAYOUTS_H\n"
         << "#define GUARD_CONSTANTS_LAYOUTS_H\n\n";

    int i = 0;
    for (auto &layout : layouts_data["layouts"].array_items())
        text << "#define " << layout["id"].string_value() << " " << ++i << "\n";

    text << "\n#endif // GUARD_CONSTANTS_LAYOUTS_H\n";

    return text.str();
}

void process_layouts(string layouts_filepath) {
    string err;
    Json layouts_data = Json::parse(read_text_file(layouts_filepath), err);

    if (layouts_data == Json())
        FATAL_ERROR("%s\n", err.c_str());

    string layout_headers_text = generate_layout_headers_text(layouts_data);
    string layouts_table_text = generate_layouts_table_text(layouts_data);
    string layouts_constants_text = generate_layouts_constants_text(layouts_data);

    string file_dir = get_directory_name(layouts_filepath);
    char s = file_dir.back();

    write_text_file(file_dir + "layouts.inc", layout_headers_text);
    write_text_file(file_dir + "layouts_table.inc", layouts_table_text);
    write_text_file(file_dir + ".." + s + ".." + s + "include" + s + "constants" + s + "layouts.h", layouts_constants_text);
}

int main(int argc, char *argv[]) {
    if (argc < 3)
        FATAL_ERROR("USAGE: dungeonjson <mode> <game-version> [options]\n");

    char *version_arg = argv[2];
    string version(version_arg);
    if (version != "emerald" && version != "ruby" && version != "pmd-red")
        FATAL_ERROR("ERROR: <game-version> must be 'emerald' or 'ruby' or 'pmd-red'.\n");

    char *mode_arg = argv[1];
    string mode(mode_arg);
    string filepath(argv[3]);

    if (mode == "map") {
        if (argc != 5)
            FATAL_ERROR("USAGE: dungeonjson map <game-version> <map_file> <layouts_file>\n");

        string layouts_filepath(argv[4]);

        process_map(filepath, layouts_filepath, version);
    } else {
        if (argc != 4)
            FATAL_ERROR("USAGE: dungeonjson <mode> <game-version> <file>\n");

        if (mode == "groups") {
            process_groups(filepath);
        } else if (mode == "layouts") {
            process_layouts(filepath);
        } else if (mode == "dungeon") {
            process_json(filepath, "pokemon_found.inc", generate_pokemon_table_text);
        } else if (mode == "floor") {
            process_json(filepath, "floor_id.inc", generate_floorID_table_text);
        } else if (mode == "species") {
            process_json(filepath, "species_data.inc", generate_species_data_text);
        } else if (mode == "item") {
            process_json(filepath, "item_data.inc", generate_item_data_text);
        } else if (mode == "move") {
            process_json(filepath, "move_data.inc", generate_move_data_text);
        } else {
            FATAL_ERROR("ERROR: <mode> must be 'layouts', 'map', 'groups', 'dungeon', 'floor', 'species', 'item', or 'move'.\n");
        }
    }

    return 0;
}
