extern const char dungeons_string[];
extern const char field_string[];
extern const char field_map_string[];
extern const char field_script_string[];
extern const char debug_menu_string[];
extern const char storage_string[];
extern const char h_open_string[];

const struct MenuItem gDebugMenuItems[8] =
{
    {dungeons_string, MENU_DEBUG_MENU_DUNGEONS},
    {field_string, MENU_DEBUG_MENU_FIELD},
    {field_map_string, MENU_DEBUG_MENU_FIELD_MAP},
    {field_script_string, MENU_DEBUG_MENU_FIELD_SCRIPT},
    {debug_menu_string, MENU_DEBUG_MENU_DEBUG_MENU},
    {storage_string, MENU_DEBUG_MENU_STORAGE},
    {h_open_string, MENU_DEBUG_MENU_H_OPEN},
    {NULL, 10},
};

ALIGNED(4) static const char h_open_string[] = "h-open";
ALIGNED(4) static const char storage_string[] = "Storage";
ALIGNED(4) static const char debug_menu_string[] = "Debug Menu";
ALIGNED(4) static const char field_script_string[] = "Field Script";
ALIGNED(4) static const char field_map_string[] = "Field Map";
ALIGNED(4) static const char field_string[] = "Field";
ALIGNED(4) static const char dungeons_string[] = "Dungeons";

ALIGNED(4) static const char debug_menu_fill0[] = "pksdir0";
ALIGNED(4) static const char debug_menu_fill1[] = "pksdir0";
ALIGNED(4) static const char debug_menu_fill2[] = "pksdir0";
ALIGNED(4) static const char debug_menu_fill3[] = "pksdir0";
ALIGNED(4) static const char debug_menu_fill4[] = "pksdir0";
ALIGNED(4) static const char debug_menu_fill5[] = "pksdir0";
ALIGNED(4) static const char debug_menu_fill6[] = "pksdir0";
