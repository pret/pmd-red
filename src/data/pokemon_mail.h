// Forward declaration for the array of Mail
extern const u8 gMail_WelcomeHeadline[];
extern const u8 gMail_WelcomeText[];
extern const u8 gMail_BasicsHeadline[];
extern const u8 gMail_BasicsText[];
extern const u8 gMail_JobHeadline[];
extern const u8 gMail_JobText[];
extern const u8 gMail_HungerHeadline[];
extern const u8 gMail_HungerText[];
extern const u8 gMail_SeedHeadline[];
extern const u8 gMail_SeedText[];
extern const u8 gMail_DisasterHeadline[];
extern const u8 gMail_DisasterText[];
extern const u8 gMail_OptionsHeadline[];
extern const u8 gMail_OptionsText[];
extern const u8 gMail_MoveHeadline[];
extern const u8 gMail_MoveText[];
extern const u8 gMail_WonderHeadline[];
extern const u8 gMail_WonderText[];
extern const u8 gMail_DungeonHeadline[];
extern const u8 gMail_DungeonText[];
extern const u8 gMail_TypeHeadline[];
extern const u8 gMail_TypeText[];
extern const u8 gMail_LinkedEntryHeadline1[];
extern const u8 gMail_LinkedEntryText1[];
extern const u8 gMail_LinkedEntryHeadline2[];
extern const u8 gMail_LinkedEntryText2[];
extern const u8 gMail_LinkedEntryHeadline3[];
extern const u8 gMail_LinkedEntryText3[];
extern const u8 gMail_PollHeadline[];
extern const u8 gMail_PollText[];
extern const u8 gMail_WondersHeadline[];
extern const u8 gMail_WondersText[];
extern const u8 gMail_TeamMoveHeadline[];
extern const u8 gMail_TeamMoveText[];
extern const u8 gMail_AddMembersHeadline[];
extern const u8 gMail_AddMembersText[];
extern const u8 gMail_MoveTipsHeadline[];
extern const u8 gMail_MoveTipsText[];
extern const u8 gMail_GummiHeadline[];
extern const u8 gMail_GummiText[];
extern const u8 gMail_UltimateHeadline[];
extern const u8 gMail_UltimateText[];
extern const u8 gMail_MachineHeadline[];
extern const u8 gMail_MachineText[];
extern const u8 gMail_MakuhitaHeadline[];
extern const u8 gMail_MakuhitaText[];
extern const u8 gMail_TrapTileHeadline[];
extern const u8 gMail_TrapTileText[];
extern const u8 gMail_IQHeadline[];
extern const u8 gMail_IQText[];
extern const u8 gMail_RangeHeadline[];
extern const u8 gMail_RangeText[];
extern const u8 gMail_SweetHeadline[];
extern const u8 gMail_SweetText[];
extern const u8 gMail_KeyHeadline[];
extern const u8 gMail_KeyText[];
extern const u8 gMail_AzurillHeadline[];
extern const u8 gMail_AzurillText[];
extern const u8 gMail_WeatherHeadline1[];
extern const u8 gMail_WeatherText1[];
extern const u8 gMail_PechaHeadline[];
extern const u8 gMail_PechaText[];
extern const u8 gMail_WobbuffetHeadline[];
extern const u8 gMail_WobbuffetText[];
extern const u8 gMail_WeatherHeadline2[];
extern const u8 gMail_WeatherText2[];
extern const u8 gMail_KecleonHeadline[];
extern const u8 gMail_KecleonText[];
extern const u8 gMail_SwitchHeadline[];
extern const u8 gMail_SwitchText[];
extern const u8 gMail_KeyItemHeadline1[];
extern const u8 gMail_KeyItemText1[];
extern const u8 gMail_KeyItemHeadline2[];
extern const u8 gMail_KeyItemText2[];
extern const u8 gMail_GasHeadline[];
extern const u8 gMail_GasText[];
extern const u8 gMail_CastformHeadline[];
extern const u8 gMail_CastformText[];
extern const u8 gMail_SmeargleHeadline[];
extern const u8 gMail_SmeargleText[];
extern const u8 gMail_KabutoHeadline[];
extern const u8 gMail_KabutoText[];
extern const u8 gMail_ChanseyHeadline[];
extern const u8 gMail_ChanseyText[];
extern const u8 gMail_ClubHeadline[];
extern const u8 gMail_ClubText[];
extern const u8 gMail_RawstHeadline[];
extern const u8 gMail_RawstText[];
extern const u8 gMail_VileplumeHeadline[];
extern const u8 gMail_VileplumeText[];
extern const u8 gMail_SeaRescueHeadline[];
extern const u8 gMail_SeaRescueText[];
extern const u8 gMail_PitfallHeadline[];
extern const u8 gMail_PitfallText[];
extern const u8 gMail_SlakothHeadline[];
extern const u8 gMail_SlakothText[];
extern const u8 gMail_LinkedProHeadline1[];
extern const u8 gMail_LinkedProText1[];
extern const u8 gMail_LinkedProHeadline2[];
extern const u8 gMail_LinkedProText2[];
extern const u8 gMail_PelipperHeadline[];
extern const u8 gMail_PelipperText[];
extern const u8 gMail_NewsHeadline1[];
extern const u8 gMail_NewsText1[];
extern const u8 gMail_NewsHeadline2[];
extern const u8 gMail_NewsText2[];
extern const u8 gMail_BuriedRelicHeadline[];
extern const u8 gMail_BuriedRelicText[];
extern const u8 gMail_LucarioRankHeadline[];
extern const u8 gMail_LucarioRankText[];
extern const u8 gMail_NewFriendAreasHeadline[];
extern const u8 gMail_NewFriendAreasText[];


const struct PokemonMail gPokemonMail[NUM_POKEMON_MAIL] =
{
    {
        .headline = gMail_WelcomeHeadline,
        .text = gMail_WelcomeText,
    },
    {
        .headline = gMail_BasicsHeadline,
        .text = gMail_BasicsText,
    },
    {
        .headline = gMail_JobHeadline,
        .text = gMail_JobText,
    },
    {
        .headline = gMail_HungerHeadline,
        .text = gMail_HungerText,
    },
    {
        .headline = gMail_SeedHeadline,
        .text = gMail_SeedText,
    },
    {
        .headline = gMail_DisasterHeadline,
        .text = gMail_DisasterText,
    },
    {
        .headline = gMail_OptionsHeadline,
        .text = gMail_OptionsText,
    },
    {
        .headline = gMail_MoveHeadline,
        .text = gMail_MoveText,
    },
    {
        .headline = gMail_WonderHeadline,
        .text = gMail_WonderText,
    },
    {
        .headline = gMail_DungeonHeadline,
        .text = gMail_DungeonText,
    },
    {
        .headline = gMail_TypeHeadline,
        .text = gMail_TypeText,
    },
    {
        .headline = gMail_LinkedEntryHeadline1,
        .text = gMail_LinkedEntryText1,
    },
    {
        .headline = gMail_LinkedEntryHeadline2,
        .text = gMail_LinkedEntryText2,
    },
    {
        .headline = gMail_LinkedEntryHeadline3,
        .text = gMail_LinkedEntryText3,
    },
    {
        .headline = gMail_PollHeadline,
        .text = gMail_PollText,
    },
    {
        .headline = gMail_WondersHeadline,
        .text = gMail_WondersText,
    },
    {
        .headline = gMail_TeamMoveHeadline,
        .text = gMail_TeamMoveText,
    },
    {
        .headline = gMail_AddMembersHeadline,
        .text = gMail_AddMembersText,
    },
    {
        .headline = gMail_MoveTipsHeadline,
        .text = gMail_MoveTipsText,
    },
    {
        .headline = gMail_GummiHeadline,
        .text = gMail_GummiText,
    },
    {
        .headline = gMail_UltimateHeadline,
        .text = gMail_UltimateText,
    },
    {
        .headline = gMail_MachineHeadline,
        .text = gMail_MachineText,
    },
    {
        .headline = gMail_MakuhitaHeadline,
        .text = gMail_MakuhitaText,
    },
    {
        .headline = gMail_TrapTileHeadline,
        .text = gMail_TrapTileText,
    },
    {
        .headline = gMail_IQHeadline,
        .text = gMail_IQText,
    },
    {
        .headline = gMail_RangeHeadline,
        .text = gMail_RangeText,
    },
    {
        .headline = gMail_SweetHeadline,
        .text = gMail_SweetText,
    },
    {
        .headline = gMail_KeyHeadline,
        .text = gMail_KeyText,
    },
    {
        .headline = gMail_AzurillHeadline,
        .text = gMail_AzurillText,
    },
    {
        .headline = gMail_WeatherHeadline1,
        .text = gMail_WeatherText1,
    },
    {
        .headline = gMail_PechaHeadline,
        .text = gMail_PechaText,
    },
    {
        .headline = gMail_WobbuffetHeadline,
        .text = gMail_WobbuffetText,
    },
    {
        .headline = gMail_WeatherHeadline2,
        .text = gMail_WeatherText2,
    },
    {
        .headline = gMail_KecleonHeadline,
        .text = gMail_KecleonText,
    },
    {
        .headline = gMail_SwitchHeadline,
        .text = gMail_SwitchText,
    },
    {
        .headline = gMail_KeyItemHeadline1,
        .text = gMail_KeyItemText1,
    },
    {
        .headline = gMail_KeyItemHeadline2,
        .text = gMail_KeyItemText2,
    },
    {
        .headline = gMail_GasHeadline,
        .text = gMail_GasText,
    },
    {
        .headline = gMail_CastformHeadline,
        .text = gMail_CastformText,
    },
    {
        .headline = gMail_SmeargleHeadline,
        .text = gMail_SmeargleText,
    },
    {
        .headline = gMail_KabutoHeadline,
        .text = gMail_KabutoText,
    },
    {
        .headline = gMail_ChanseyHeadline,
        .text = gMail_ChanseyText,
    },
    {
        .headline = gMail_ClubHeadline,
        .text = gMail_ClubText,
    },
    {
        .headline = gMail_RawstHeadline,
        .text = gMail_RawstText,
    },
    {
        .headline = gMail_VileplumeHeadline,
        .text = gMail_VileplumeText,
    },
    {
        .headline = gMail_SeaRescueHeadline,
        .text = gMail_SeaRescueText,
    },
    {
        .headline = gMail_PitfallHeadline,
        .text = gMail_PitfallText,
    },
    {
        .headline = gMail_SlakothHeadline,
        .text = gMail_SlakothText,
    },
    {
        .headline = gMail_LinkedProHeadline1,
        .text = gMail_LinkedProText1,
    },
    {
        .headline = gMail_LinkedProHeadline2,
        .text = gMail_LinkedProText2,
    },
    {
        .headline = gMail_PelipperHeadline,
        .text = gMail_PelipperText,
    },
    {
        .headline = gMail_NewsHeadline1,
        .text = gMail_NewsText1,
    },
    {
        .headline = gMail_NewsHeadline2,
        .text = gMail_NewsText2,
    },
    {
        .headline = gMail_BuriedRelicHeadline,
        .text = gMail_BuriedRelicText,
    },
    {
        .headline = gMail_LucarioRankHeadline,
        .text = gMail_LucarioRankText,
    },
    {
        .headline = gMail_NewFriendAreasHeadline,
        .text = gMail_NewFriendAreasText
    }
};

ALIGNED(4) const u8 gMail_NewFriendAreasText[] = _(
     "The Wigglytuff Club has added new Friend\n"
     "Areas for sale!\n"
     "Rescue Teams are urged to check with\n"
     "Wigglytuff for what is available.\n"
     "By adding to your Friend Areas{COMMA} you can\n"
     "recruit Pokémon that wouldn{APOSTROPHE}t join your\n"
     "rescue team before!");

ALIGNED(4) const u8 gMail_NewFriendAreasHeadline[] = "New Friend Areas!";

ALIGNED(4) const u8 gMail_LucarioRankText[] = _(
    "Congratulations! Your team has attained\n"
    "the Lucario Rank--the top rank among\n"
    "rescue teams! In commemoration of your\n"
    "fantastic achievement{COMMA} we award you the\n"
    "Lucario Statue{COMMA} crafted after the legendary\n"
    "rescue team leader.\n"
    "Keep working for world peace!\n"
    "   - Pokémon Rescue Organization -");


ALIGNED(4) const u8 gMail_LucarioRankHeadline[] = "Congratulations - Lucario Rank!";

ALIGNED(4) const u8 gMail_BuriedRelicText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Mystery Ruin Found Underground!{END_COLOR_TEXT_1}\n"
    "Its site had been hidden by the crater of a\n"
    "meteor strike in ancient times. The Buried\n"
    "Relic is thought to date back beyond\n"
    "recorded history. There are rumors of\n"
    "treasures... And perhaps even Pokémon\n"
    "that lived in ancient times. The Buried\n"
    "Relic is the main topic in Pokémon Square.");


ALIGNED(4) const u8 gMail_BuriedRelicHeadline[] =
    "Buried Relic Discovered!";


ALIGNED(4) const u8 gMail_NewsText2[] = _(
    "{CENTER_ALIGN}{COLOR_1 CYAN}{ARG_POKEMON_0} Innocent! Part 2{END_COLOR_TEXT_1}\n"
    "{COLOR_1 GREEN}Quote from Charizard on the scene:{END_COLOR_TEXT_1}\n"
    "{QUOTE_START}That{APOSTROPHE}s what I thought right from\n"
    "the start{COMMA} hahaha!{QUOTE_END}\n"
    "{COLOR_1 GREEN}Quote from Tyranitar on the scene:{END_COLOR_TEXT_1}\n"
    "{QUOTE_START}That muckraking Gengar...\n"
    "He{APOSTROPHE}s not getting away with this!\n"
    "He{APOSTROPHE}d better be ready for it!{QUOTE_END}");


ALIGNED(4) const u8 gMail_NewsHeadline2[] = _(
    "Pokémon News Extra 2");


ALIGNED(4) const u8 gMail_NewsText1[] = _(
    "{CENTER_ALIGN}{COLOR_1 CYAN}{ARG_POKEMON_0} Innocent! Part 1{END_COLOR_TEXT_1}\n"
    "{ARG_POKEMON_1} met with Ninetales on {COLOR_1 RED}Mt. Freeze{END_COLOR_TEXT_1}.\n"
    "Ninetales testified that {ARG_POKEMON_0} was\n"
    "not the human that appeared in the legend.\n"
    "As a result{COMMA} Gengar{APOSTROPHE}s claims were found to\n"
    "be malicious lies.\n"
    "{COLOR_1 GREEN}The clearly dismayed Gengar{APOSTROPHE}s quote:{END_COLOR_TEXT_1}\n"
    "{QUOTE_START}Ugegegegegegegegegegegeh!{QUOTE_END}");


ALIGNED(4) const u8 gMail_NewsHeadline1[] = _(
    "Pokémon News Extra 1");


ALIGNED(4) const u8 gMail_PelipperText[] = _(
    "Yo! Amigo! It{APOSTROPHE}s awesome you{APOSTROPHE}re back!\n"
    "I{APOSTROPHE}ll be delivering mail to you again!\n"
    "I{APOSTROPHE}ve been looking forward to this with\n"
    "my bill outstretched!\n"
    "I{APOSTROPHE}ll deliver tons of mail{COMMA} so you{APOSTROPHE}d better\n"
    "be ready{COMMA} amigo!\n\n"
    " - The wandering postal carrier{COMMA} Pelipper -");


ALIGNED(4) const u8 gMail_PelipperHeadline[] =
    "A Letter from Pelipper";


ALIGNED(4) const u8 gMail_LinkedProText2[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Try These Linked Moves to KO Foes!{END_COLOR_TEXT_1}\n\n"
    "Psyduck\n"
    "{COLOR_1 GREEN}Confusion{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Disable{END_COLOR_TEXT_1}\n"
    "Totodile\n"
    "{COLOR_1 GREEN}Bite{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Scary Face{END_COLOR_TEXT_1}\n"
    "Cyndaquil\n"
    "{COLOR_1 GREEN}Flame Wheel{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Smokescreen{END_COLOR_TEXT_1}{EXTRA_MSG}"
    "Pikachu\n"
    "{COLOR_1 GREEN}Thunderbolt{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Double Team{END_COLOR_TEXT_1}\n"
    "Skitty\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Doubleslap{END_COLOR_TEXT_1}");


ALIGNED(4) const u8 gMail_LinkedProHeadline2[] =
    "#50 Linked Moves Pro Level 2";


ALIGNED(4) const u8 gMail_LinkedProText1[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}These Linked Move Combinations{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Can Be Devastating!{END_COLOR_TEXT_1}\n\n"
    "Bulbasaur\n"
    "{COLOR_1 GREEN}Razor Leaf{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Sleep Powder{END_COLOR_TEXT_1}\n"
    "Chikorita\n"
    "{COLOR_1 GREEN}Body Slam{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Reflect{END_COLOR_TEXT_1}{EXTRA_MSG}"
    "Treecko\n"
    "{COLOR_1 GREEN}Screech{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Pound{END_COLOR_TEXT_1}\n"
    "Machop\n"
    "{COLOR_1 GREEN}Focus Energy{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Karate Chop{END_COLOR_TEXT_1}\n"
    "Cubone\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Bonemerang{END_COLOR_TEXT_1}");


ALIGNED(4) const u8 gMail_LinkedProHeadline1[] = 
    "#49 Linked Moves Pro Level 1";


ALIGNED(4) const u8 gMail_SlakothText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Relief for Delicate Souls Who Can{APOSTROPHE}t{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Sleep with Different Pillows!{END_COLOR_TEXT_1}\n"
    "Insomniacs rejoiced over the announcement\n"
    "of the Slakoth Pillow{COMMA} which is said to\n"
    "induce sleepiness just by seeing it.\n"
    "Already the inventor is swamped with\n"
    "inquiries from all over. However{COMMA}\n"
    "production is said to be not yet ready.");


ALIGNED(4) const u8 gMail_SlakothHeadline[] = 
    "#48 Slakoth Pillows for Insomnia!";


ALIGNED(4) const u8 gMail_PitfallText[] = _(
    "As a result of the natural disasters{COMMA}\n"
    "there have been many reports of Pitfall\n"
    "Traps appearing in dungeons.\n"
    "However{COMMA} there also appear to be pitfalls\n"
    "made by Pokémon that are not harmful.\n"
    "The latter are thought to be made by\n"
    "foraging Swinub. Some even turn out to\n"
    "be hot springs that erupt occasionally.");


ALIGNED(4) const u8 gMail_PitfallHeadline[] = 
    "#47 Beware of Pitfalls";


ALIGNED(4) const u8 gMail_SeaRescueText[] = _(
    "A high-seas rescue in the {COLOR_1 RED}Stormy Sea{END_COLOR_TEXT_1} by\n"
    "{COLOR_1 CYAN}Team Sea Dragons{END_COLOR_TEXT_1} ended yesterday with\n"
    "the successful recovery of Tentacool.\n"
    "The client{COMMA} Corsola{COMMA} is said to be delighted\n"
    "by the outcome.\n"
    "Tentacool stated{COMMA} {QUOTE_START}I didn{APOSTROPHE}t realize how far\n"
    "I{APOSTROPHE}d been washed out to sea.{QUOTE_END}\n"
    "The {COLOR_1 RED}Stormy Sea{END_COLOR_TEXT_1} is unforgiving!");


ALIGNED(4) const u8 gMail_SeaRescueHeadline[] = 
    "#46 Sea Rescue a Success!";


ALIGNED(4) const u8 gMail_VileplumeText[] = _(
    "Vileplume are widely recognized for \n"
    "their massive flower. However{COMMA} few dare\n"
    "to approach Vileplume because they\n"
    "scatter clouds of allergy-inducing\n"
    "pollen. Vileplume complain that they tire\n"
    "very easily because the flower{APOSTROPHE}s weight\n"
    "makes their head heavy.");


ALIGNED(4) const u8 gMail_VileplumeHeadline[] = _(
    "#45 Vileplume{APOSTROPHE}s Weighty Problem");


ALIGNED(4) const u8 gMail_RawstText[] = _(
    "Research has revealed that {COLOR_1 GREEN}Rawst Berries{END_COLOR_TEXT_1}\n"
    "found in dungeons are usually unripened\n"
    "and colored green. When ripe{COMMA} they turn a\n"
    "sky blue color. An unripened one is easier\n"
    "to eat{COMMA} however{COMMA} because it has not yet\n"
    "turned bitter. It is known to heal all\n"
    "burns.");


ALIGNED(4) const u8 gMail_RawstHeadline[] = _(
    "#44 Rawst Berry{APOSTROPHE}s Effect");


ALIGNED(4) const u8 gMail_ClubText[] = _(
    "We proudly announce the foundation of\n"
    "the Red & Blue Fan Club{COMMA} an organization\n"
    "for supporting Pokémon rescue teams.\n"
    "We are currently recruiting new members.\n"
    "Won{APOSTROPHE}t you join and throw your support\n"
    "behind our hard-working rescue heroes?\n\n"
    "  - Plusle and Minun -");


ALIGNED(4) const u8 gMail_ClubHeadline[] = 
    "#43 Fan Club Seeks Members!";


ALIGNED(4) const u8 gMail_ChanseyText[] = _(
    "As a special treat{COMMA} I{APOSTROPHE}ll share a simple\n"
    "way to tell fortunes with you!\n"
    "The key is the first thing you find in the\n"
    "day{APOSTROPHE}s first dungeon.\n"
    "If it{APOSTROPHE}s money{COMMA} you{APOSTROPHE}ll be sure to make more.\n"
    "If it{APOSTROPHE}s a Berry{COMMA} your health luck is good.\n"
    "If it{APOSTROPHE}s an Apple{COMMA} you{APOSTROPHE}re super lucky!\n"
    "  - Chansey -");


ALIGNED(4) const u8 gMail_ChanseyHeadline[] = _(
    "#42 Chansey{APOSTROPHE}s Fortune-Telling");


ALIGNED(4) const u8 gMail_KabutoText[] = _(
    "One of our oldest residents claims to feel\n"
    "rejuvenated. Kabuto reportedly had an\n"
    "encounter with Relicanth in which both\n"
    "parties reminisced about the {QUOTE_START}old days.{QUOTE_END}\n"
    "However{COMMA} even Kabuto could not keep up\n"
    "with Relicanth{APOSTROPHE}s tales from a hundred\n"
    "million years ago. Kabuto stated{COMMA} {QUOTE_START}It\n"
    "made me feel young talking to Relicanth.{QUOTE_END}");


ALIGNED(4) const u8 gMail_KabutoHeadline[] = 
    "#41 Kabuto Feels Young Again!";


ALIGNED(4) const u8 gMail_SmeargleText[] = _(
    "Smeargle{COMMA} the artist known for his unique\n"
    "artistic vision{COMMA} had a windfall day as one\n"
    "of his paintings was auctioned for 300\n"
    "million {POKE} yesterday. The auctioned\n"
    "artwork was one of Smeargle{APOSTROPHE}s signature\n"
    "works from early in his career.");


ALIGNED(4) const u8 gMail_SmeargleHeadline[] = 
    "#40 Smeargle Painting Auctioned!";


ALIGNED(4) const u8 gMail_CastformText[] = _(
    "Today{COMMA} the weather over Pokémon\n"
    "Square promises to be clear with no\n"
    "chance of showers.\n"
    "Other regions can expect showers followed\n"
    "by clouds. There may be sun breaks\n"
    "depending on the day{APOSTROPHE}s moods.");


ALIGNED(4) const u8 gMail_CastformHeadline[] = _(
    "#39 Castform{APOSTROPHE}s Daily Weather");


ALIGNED(4) const u8 gMail_GasText[] = _(
    "Reports of a noxious gas leak caused\n"
    "widespread chaos in the {COLOR_1 YELLOW_4}Sinister Woods{END_COLOR_TEXT_1}.\n"
    "Specialists speculate that the recent\n"
    "natural disasters are to blame. However{COMMA}\n"
    "some also blame {COLOR_1 CYAN}Team Koffing{END_COLOR_TEXT_1}{APOSTROPHE}s training\n"
    "in the area for the foul-smelling gas.\n"
    "The answer{COMMA} apparently{COMMA} is blowing in the\n"
    "wind.");


ALIGNED(4) const u8 gMail_GasHeadline[] = 
    "#38 Noxious Gas Leak?!";


ALIGNED(4) const u8 gMail_KeyItemText2[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}When Used Somewhere Special...{END_COLOR_TEXT_1}\n"
    "Eevee and Water Stone{COMMA} Fire Stone{COMMA}\n"
    "Thunderstone{COMMA} or...\n"
    "Exeggcute and Leaf Stone...\n"
    "Onix{COMMA} Metal Coat{COMMA} and Link Cable...\n"
    "There appear to be many others!");


ALIGNED(4) const u8 gMail_KeyItemHeadline2[] = _(
    "#37 Key Items for Pokémon 2");


ALIGNED(4) const u8 gMail_KeyItemText1[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}When Used Somewhere Special...{END_COLOR_TEXT_1}\n"
    "Sunkern and Sun Stone...\n"
    "Skitty and Moon Stone...\n"
    "Growlithe and Fire Stone...\n"
    "Shellder and Water Stone...\n"
    "Clamperl and Deepseatooth...\n"
    "There appear to be many others!");


ALIGNED(4) const u8 gMail_KeyItemHeadline1[] = _(
    "#36 Key Items for Pokémon 1");


ALIGNED(4) const u8 gMail_SwitchText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Power Up Combination Attacks!{END_COLOR_TEXT_1}\n"
    "Some dungeons allow rescue teams to\n"
    "switch leaders on the spot for doing\n"
    "combination attacks and so on.\n"
    "When you enter a dungeon{COMMA} open the menu{COMMA}\n"
    "choose the Pokémon you want as the\n"
    "leader under {COLOR_1 YELLOW}Team{END_COLOR_TEXT_1}{COMMA} then select the\n"
    "command {COLOR_1 YELLOW}Leader{END_COLOR_TEXT_1}.");


ALIGNED(4) const u8 gMail_SwitchHeadline[] = 
    "#35 Switching Leaders";


ALIGNED(4) const u8 gMail_KecleonText[] = _(
    "There have been numerous reports that\n"
    "the older of the Kecleon merchants in\n"
    "Pokémon Square occasionally goes\n"
    "missing. Some residents claim{COMMA} {QUOTE_START}He{APOSTROPHE}s\n"
    "greedy. He must be off doing business\n"
    "somewhere.{QUOTE_END} His younger brother denies\n"
    "such claims: {QUOTE_START}He wouldn{APOSTROPHE}t get free items\n"
    "in dungeons and try to sell them...{QUOTE_END}");


ALIGNED(4) const u8 gMail_KecleonHeadline[] = 
    "#34 Where Is Kecleon?";


ALIGNED(4) const u8 gMail_WeatherText2[] = _(
    "Clear: Pleasant weather.\n"
    "Hail: Regularly inflicts damage{COMMA}\n"
    "except on the Ice type.\n"
    "Fog: Turns the status of all Pokémon on\n"
    "the floor to Mud Sport.\n"
    "Blizzard: Boosts the movement speed of\n"
    "Ice-type Pokémon by one level.");


ALIGNED(4) const u8 gMail_WeatherHeadline2[] = 
    "#33 Dungeons and Weather 2";


ALIGNED(4) const u8 gMail_WobbuffetText[] = _(
    "Earlier today{COMMA} Wobbuffet reportedly\n"
    "wobbled the wrong way and wandered off.\n"
    "It had to be rescued by the famous\n"
    "{COLOR_1 CYAN}Team Hydro{END_COLOR_TEXT_1}.\n"
    "Fortunately{COMMA} the wayward wanderer\n"
    "Wobbuffet was only wobbly and otherwise\n"
    "unharmed.");


ALIGNED(4) const u8 gMail_WobbuffetHeadline[] = 
    "#32 Wobbly Wobbuffet Wanders!";


ALIGNED(4) const u8 gMail_PechaText[] = _(
    "Among rescue teams{COMMA} there is growing\n"
    "demand for equipment that is not only\n"
    "practical{COMMA} but also fashionably appealing.\n"
    "The pink {COLOR_1 GREEN}Pecha Scarf{END_COLOR_TEXT_1} is especially popular.\n"
    "Even the {COLOR_1 CYAN}Kecleon Shop{END_COLOR_TEXT_1} is having trouble\n"
    "keeping it in stock.\n"
    "If you{APOSTROPHE}re lucky enough to spot one{COMMA} make a\n"
    "beeline for it!");


ALIGNED(4) const u8 gMail_PechaHeadline[] = 
    "#31 Pecha Scarf--Top Popularity!";


ALIGNED(4) const u8 gMail_WeatherText1[] = _(
    "Sunny: Boosts Fire-type moves{COMMA} and\n"
    "weakens Water-type moves.\n"
    "Sandstorm: Regularly inflicts damage\n"
    "except on Ground{COMMA} Rock{COMMA} and Steel types.\n"
    "Cloudy: All moves and attacks{COMMA} excluding\n"
    "the Normal type{COMMA} are weakened.\n"
    "Rain: Boosts Water-type moves{COMMA} and\n"
    "weakens Fire. Prevents explosions.");


ALIGNED(4) const u8 gMail_WeatherHeadline1[] = 
    "#30 Dungeons and Weather 1";


ALIGNED(4) const u8 gMail_AzurillText[] = _(
    "With a simple act of courage{COMMA} Azurill\n"
    "became a hero despite being small in size.\n"
    "Azurill came across Slowpoke{COMMA} who had\n"
    "fallen into a pond. Our hero{APOSTROPHE}s tail{COMMA} thrown\n"
    "at the struggling Slowpoke{COMMA} saved a sure\n"
    "drowning! Slowpoke claimed to have\n"
    "entirely forgotten having the ability to\n"
    "swim capably.");


ALIGNED(4) const u8 gMail_AzurillHeadline[] = 
    "#29 Azurill--the Little Hero!";


ALIGNED(4) const u8 gMail_KeyText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Head Out to the Desert Region!{END_COLOR_TEXT_1}\n"
    "If you{APOSTROPHE}ve been wondering what lies behind\n"
    "the mysterious locked doors of the {COLOR_1 YELLOW_4}Solar\n"
    "Cave{END_COLOR_TEXT_1}{COMMA} there{APOSTROPHE}s been a breakthrough!\n"
    "Reports indicate the door keys are easily\n"
    "found in the {COLOR_1 YELLOW_4}Desert Region{END_COLOR_TEXT_1}. Explorers are\n"
    "advised to compose teams with Pokémon\n"
    "adapted to the desert environment.");


ALIGNED(4) const u8 gMail_KeyHeadline[] = 
    "#28 The Key";


ALIGNED(4) const u8 gMail_SweetText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Feel a Little Envious?{END_COLOR_TEXT_1}\n"
    "Teddiursa is often seen licking its paws\n"
    "that have soaked up sweet honey. While it\n"
    "may be sticky shaking paws with\n"
    "Teddiursa{COMMA} one can{APOSTROPHE}t help but feel a\n"
    "twinge of envy.");

ALIGNED(4) const u8 gMail_SweetHeadline[] = 
    "#27 Sweet Hands!";


ALIGNED(4) const u8 gMail_RangeText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}All Moves Have Effective Ranges{END_COLOR_TEXT_1}\n"
    "Moves that affect an entire room have a\n"
    "range of two tiles in a corridor. The move\n"
    "{COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}{COMMA} which lowers the Attack stat of\n"
    "foes in a room{COMMA} will reach two tiles away\n"
    "in a corridor{COMMA} for example. If{COMMA} however{COMMA}\n"
    "the visibility is limited to just one tile{COMMA}\n"
    "the range of moves will also be limited.");


ALIGNED(4) const u8 gMail_RangeHeadline[] = 
    "#26 The Range of Moves";


ALIGNED(4) const u8 gMail_IQText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Make Your Explorations Easier by{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Boosting the IQ of Team Members!{END_COLOR_TEXT_1}\n"
    "Eating Gummis boosts the IQ of Pokémon.\n"
    "Upon reaching certain IQ levels{COMMA} a Pokémon\n"
    "learns IQ Skills that can be very helpful\n"
    "(for example{COMMA} learning to seek out foes\n"
    "with type disadvantages). Check\n"
    "the IQ Skills of your team members!");


ALIGNED(4) const u8 gMail_IQHeadline[] = 
    "#25 IQ";


ALIGNED(4) const u8 gMail_TrapTileText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}New Types of Floor Tiles?{END_COLOR_TEXT_1}\n"
    "There have been numerous reports of new\n"
    "floor tiles other than Wonder Tiles.\n"
    "Believed to have been made by the recent\n"
    "natural disasters{COMMA} these floor tiles remain\n"
    "hidden until they are stepped on. They then\n"
    "trigger a variety of traps. Rescue teams\n"
    "are urged to use extreme caution.");


ALIGNED(4) const u8 gMail_TrapTileHeadline[] = 
    "#24 New Floor Tiles?";


ALIGNED(4) const u8 gMail_MakuhitaText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Study Type Matchups{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}at the Makuhita Dojo!{END_COLOR_TEXT_1}\n"
    "At the Makuhita Dojo{COMMA} one can learn how\n"
    "Pokémon type matchups affect battles.\n"
    "It{APOSTROPHE}s because the dojo{APOSTROPHE}s training rooms are\n"
    "divided by type. For example{COMMA} in the {COLOR_1 YELLOW_4}Fire\n"
    "Maze{END_COLOR_TEXT_1}{COMMA} there are only Fire-type Pokémon.\n"
    "Try move types to see what works best!");


ALIGNED(4) const u8 gMail_MakuhitaHeadline[] = 
    "#23 Train at the Makuhita Dojo!";


ALIGNED(4) const u8 gMail_MachineText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}New Types of Machines Discovered?{END_COLOR_TEXT_1}\n"
    "In a recently discovered cave{COMMA} explorers\n"
    "found unique types of Technical Machines.\n"
    "They apparently do not break after a single\n"
    "use. Further studies are said to be under\n"
    "consideration by the authorities.\n"
    "In related news{COMMA} the cave is to be named\n"
    "the {COLOR_1 YELLOW_4}Solar Cave{END_COLOR_TEXT_1}.");


ALIGNED(4) const u8 gMail_MachineHeadline[] = 
    "#22 New Types of Machines?";


ALIGNED(4) const u8 gMail_UltimateText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}The Ultimate Dungeon{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Challenges You to Do Your Best!{END_COLOR_TEXT_1}\n"
    "Somewhere in the world{COMMA} there supposedly\n"
    "is an incredibly tough dungeon. One must\n"
    "enter alone at Level 1{COMMA} and without any\n"
    "items. No one has ever completed the\n"
    "challenge. It is considered a test not of\n"
    "power{COMMA} but of intelligence and wits.");


ALIGNED(4) const u8 gMail_UltimateHeadline[] = 
    "#21 The Ultimate Dungeon";


ALIGNED(4) const u8 gMail_GummiText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Gummis That Make You Smart{END_COLOR_TEXT_1}\n"
    "Research has revealed that popular Gummi\n"
    "treats not only enhance intelligence{COMMA} they\n"
    "also have different effects depending on\n"
    "type. Share Gummis with your friends and\n"
    "get smarter for your adventures! In\n"
    "dungeons{COMMA} throw them at your friends.\n"
    "Use them in Friend Areas and...?");


ALIGNED(4) const u8 gMail_GummiHeadline[] = 
    "#20 Secrets of the Gummi";


ALIGNED(4) const u8 gMail_MoveTipsText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Moving Diagonally{END_COLOR_TEXT_1}\n"
    "Move diagonally to avoid foes!\n"
    "Keeping {R_BUTTON}"
    " pressed{COMMA} use\n"
    "{DPAD} to move diagonally.\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Changing Direction{END_COLOR_TEXT_1}\n"
    "It{APOSTROPHE}s also very important to change\n"
    "directions without moving. Check Hints to\n"
    "see how you can do this maneuver!");


ALIGNED(4) const u8 gMail_MoveTipsHeadline[] = 
    "#19 Important Moving Tips";


ALIGNED(4) const u8 gMail_AddMembersText[] = _(
    "If you want to enlarge your rescue team{COMMA}\n"
    "you must first get Friend Areas. When\n"
    "a Pokémon that can live in an obtained\n"
    "Friend Area is defeated{COMMA} it may ask to\n"
    "join your rescue team. Add to your\n"
    "Friend Areas so you can recruit more\n"
    "members! Incidentally{COMMA} you may take no\n"
    "more than three friends into a dungeon.");


ALIGNED(4) const u8 gMail_AddMembersHeadline[] = 
    "#18 Adding Team Members";


ALIGNED(4) const u8 gMail_TeamMoveText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Use Team Members Effectively!{END_COLOR_TEXT_1}\n"
    "When you{APOSTROPHE}re fighting in a dungeon{COMMA} it{APOSTROPHE}s\n"
    "important to use your team members. If\n"
    "attacked from the side{COMMA} move horizontally.\n"
    "If attacked from above or below{COMMA} move\n"
    "vertically. That way{COMMA} you can have several\n"
    "Pokémon fighting a single foe. Change\n"
    "Tactics if members don{APOSTROPHE}t move properly.");


ALIGNED(4) const u8 gMail_TeamMoveHeadline[] = 
    "#17 Moving as a Team";


ALIGNED(4) const u8 gMail_WondersText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}The Seven Wonders of Pokémon?{END_COLOR_TEXT_1}\n"
    "The mysterious feet of Diglett.\n"
    "What is inside Forretress{APOSTROPHE}s shell.\n"
    "The intelligence of Girafarig{APOSTROPHE}s tail.\n"
    "Arbok{APOSTROPHE}s variety of patterns.\n"
    "We await submissions from readers on\n"
    "other Pokémon mysteries!\n"
    "  - Mystery Hunter Team -");


ALIGNED(4) const u8 gMail_WondersHeadline[] = _(
    "#16 Seven Wonders of Pokémon");


ALIGNED(4) const u8 gMail_PollText[] = _(
    "{COLOR_1 YELLOW}First{UNK_MACRO_3D M3D_50}Gravelerock{END_COLOR_TEXT_1}\n"
    "{COLOR_1 YELLOW}Second{UNK_MACRO_3D M3D_50}Oran Berry{END_COLOR_TEXT_1}\n"
    "In a nationwide survey involving rescue\n"
    "teams{COMMA} the most popular item was found to\n"
    "be {COLOR_1 GREEN}Gravelerocks{END_COLOR_TEXT_1}. According to Sudowoodo\n"
    "of {COLOR_1 CYAN}Team Fakers{END_COLOR_TEXT_1}{COMMA} {QUOTE_START}It lets you attack\n"
    "from far away. It{APOSTROPHE}s invaluable.{QUOTE_END} The next\n"
    "most popular item was {COLOR_1 GREEN}Oran Berries{END_COLOR_TEXT_1}.");


ALIGNED(4) const u8 gMail_PollHeadline[] = 
    "#15 Poll: Top Two Items";


ALIGNED(4) const u8 gMail_LinkedEntryText3[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}These Are the Final Linked Moves{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}We Recommend in the Entry Level!{END_COLOR_TEXT_1}\n"
    "{COLOR_1 RED}Electric and Water Types{END_COLOR_TEXT_1}\n"
    "Pikachu\n"
    "{COLOR_1 GREEN}Thundershock{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    "Squirtle\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}{EXTRA_MSG}Totodile\n"
    "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Scratch{END_COLOR_TEXT_1}\n"
    "Mudkip\n"
    "{COLOR_1 GREEN}Water Gun{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Mud-Slap{END_COLOR_TEXT_1}\n"
    "Psyduck\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Scratch{END_COLOR_TEXT_1}");


ALIGNED(4) const u8 gMail_LinkedEntryHeadline3[] = 
    "#14 Linked Moves Entry Level 3";


ALIGNED(4) const u8 gMail_LinkedEntryText2[] = _(
    "{COLOR_1 RED}Fire and Normal Types{END_COLOR_TEXT_1}\n"
    "Charmander\n"
    "{COLOR_1 GREEN}Ember{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    "Cyndaquil\n"
    "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}\n"
    "Torchic\n"
    "{COLOR_1 GREEN}Ember{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}{EXTRA_MSG}Eevee\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}\n"
    "Meowth\n"
    "{COLOR_1 GREEN}Scratch{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    "Skitty\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}");


ALIGNED(4) const u8 gMail_LinkedEntryHeadline2[] = 
    "#13 Linked Moves Entry Level 2";


ALIGNED(4) const u8 gMail_LinkedEntryText1[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}These Are the Recommended{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Linked Moves for Beginners!{END_COLOR_TEXT_1}\n"
    "{COLOR_1 RED}Grass{COMMA} Fighting{COMMA} and Ground Types{END_COLOR_TEXT_1}\n"
    "Bulbasaur\n"
    "{COLOR_1 GREEN}Vine Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    "Chikorita\n"
    "{COLOR_1 GREEN}Razor Leaf{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}{EXTRA_MSG}Treecko\n"
    "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Pound{END_COLOR_TEXT_1}\n"
    "Machop\n"
    "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Low Kick{END_COLOR_TEXT_1}\n"
    "Cubone\n"
    "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Bone Club{END_COLOR_TEXT_1}");


ALIGNED(4) const u8 gMail_LinkedEntryHeadline1[] = 
    "#12 Linked Moves Entry Level 1";


ALIGNED(4) const u8 gMail_TypeText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Learn How Types Match Up!{END_COLOR_TEXT_1}\n"
    "All Pokémon are of certain types{COMMA} such as\n"
    "{COLOR_1 RED}Fire{END_COLOR_TEXT_1} and {COLOR_1 CYAN}Water{END_COLOR_TEXT_1}. In a battle{COMMA} the damage\n"
    "inflicted depends on how the Pokémon{APOSTROPHE}s\n"
    "type matches up with the move{APOSTROPHE}s type.\n"
    "For example{COMMA} a {COLOR_1 RED}Fire{END_COLOR_TEXT_1}-type Pokémon is\n"
    "weak against {COLOR_1 CYAN}Water{END_COLOR_TEXT_1}-type moves.\n"
    "Exploit type matchups to win battles!");


ALIGNED(4) const u8 gMail_TypeHeadline[] = 
    "#11 Types and Matchups";


ALIGNED(4) const u8 gMail_DungeonText[] = _(
    "If your rescue team is defeated in a\n"
    "dungeon{COMMA} you lose several items and\n"
    "all the money you are carrying.\n"
    "Beware of what you{APOSTROPHE}re carrying before\n"
    "you go off on a rescue or an outing.\n"
    "Use {COLOR_1 CYAN}Kangaskhan Storage{END_COLOR_TEXT_1} to keep\n"
    "invaluable items safely stored.\n"
    "   - Pokémon Rescue Organization -");


ALIGNED(4) const u8 gMail_DungeonHeadline[] = 
    "#10 Mysterious Dungeons?";


ALIGNED(4) const u8 gMail_WonderText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Wonder Tiles Reset Attack and Defense!{END_COLOR_TEXT_1}\n"
    "If your Attack is lowered by a foe{APOSTROPHE}s\n"
    "{COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}{COMMA} or your Defense is lowered\n"
    "by a foe{APOSTROPHE}s {COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1}{COMMA} for example{COMMA} the\n"
    "affected stat can be reset to normal by\n"
    "stepping on a Wonder Tile or going to the\n"
    "next floor. Beware{COMMA} enhanced stats are\n"
    "also reset to normal!");


ALIGNED(4) const u8 gMail_WonderHeadline[] = 
    "#9 Wonder Tiles";


ALIGNED(4) const u8 gMail_MoveText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}The Benefits of Using Moves{END_COLOR_TEXT_1}\n"
    "If a move is used on a foe{COMMA} when it is\n"
    "defeated{COMMA} {COLOR_1 CYAN}you earn more Exp. Points{END_COLOR_TEXT_1}!\n"
    "A move only has to be used once on the\n"
    "foe: after that it can be defeated using a\n"
    "regular attack to earn more Exp. Points.\n"
    "Moves are also more likely to become\n"
    "{COLOR_1 CYAN}critical hits{END_COLOR_TEXT_1}! Don{APOSTROPHE}t overuse them{COMMA} though!");


ALIGNED(4) const u8 gMail_MoveHeadline[] = _(
    "#8 Let{APOSTROPHE}s Use Moves!");


ALIGNED(4) const u8 gMail_OptionsText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Change Your Option Settings{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}to Suit Your Play Style!{END_COLOR_TEXT_1}\n"
    "Press {B_BUTTON} to open the menu{COMMA} then\n"
    "choose {COLOR_1 YELLOW}Others{END_COLOR_TEXT_1} and {COLOR_1 YELLOW}Game Options{END_COLOR_TEXT_1}.\n"
    "You can change settings to suit the way\n"
    "you play.");


ALIGNED(4) const u8 gMail_OptionsHeadline[] = 
    "#7 Game Options";


ALIGNED(4) const u8 gMail_DisasterText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Investigations Under Way into{END_COLOR_TEXT_1}\n"
    "{CENTER_ALIGN COLOR_1 YELLOW}Recent Rash of Natural Disasters{END_COLOR_TEXT_1}\n"
    "Pokémon in affected areas attack any\n"
    "outsider without hesitation. Some believe\n"
    "a mysterious force is behind their\n"
    "behavior. One source blamed Diglett\n"
    "for triggering earthquakes{COMMA} but the\n"
    "investigative team is skeptical.");


ALIGNED(4) const u8 gMail_DisasterHeadline[] = 
    "#6 Recent Natural Disasters";


ALIGNED(4) const u8 gMail_SeedText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Seeds Can Be Thrown{COMMA} Too!{END_COLOR_TEXT_1}\n"
    "Seeds are usually meant to be eaten.\n"
    "But did you know? They can also be thrown\n"
    "at other Pokémon to unlock their effects.\n"
    "Toss seeds you don{APOSTROPHE}t want to eat at foes!\n"
    "Throw good seeds at friends!\n"
    "Don{APOSTROPHE}t be afraid to throw your seeds!");


ALIGNED(4) const u8 gMail_SeedHeadline[] = 
    "#5 Throw Seeds!";


ALIGNED(4) const u8 gMail_HungerText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Eat Something When You Get Hungry!{END_COLOR_TEXT_1}\n"
    "While you{APOSTROPHE}re exploring a dungeon{COMMA} you will\n"
    "get progressively hungry (your Belly goes\n"
    "down). If you become famished{COMMA} you will\n"
    "eventually lose HP and even faint.\n"
    "That{APOSTROPHE}s why you should eat something to fill\n"
    "your Belly! You can always buy food at the\n"
    "{COLOR_1 CYAN}Kecleon Shop{END_COLOR_TEXT_1}.");


ALIGNED(4) const u8 gMail_HungerHeadline[] = 
    "#4 Getting Hungry";


ALIGNED(4) const u8 gMail_JobText[] = _(
    "If you want to go on a rescue job listed\n"
    "on the Bulletin Board at the Pelipper Post\n"
    "Office{COMMA} or one that{APOSTROPHE}s delivered to your\n"
    "Mailbox{COMMA} you first need to {COLOR_1 YELLOW}Accept{END_COLOR_TEXT_1} the job{COMMA}\n"
    "then choose {COLOR_1 YELLOW}Take Job{END_COLOR_TEXT_1}. Only then will you\n"
    "be able to handle that job.\n"
    "Try to do accepted jobs quickly!\n"
    "   - Pokémon Rescue Organization -");


ALIGNED(4) const u8 gMail_JobHeadline[] = 
    "#3 Accepting Rescue Jobs";


ALIGNED(4) const u8 gMail_BasicsText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}Saving Your Adventure and Pokémon News{END_COLOR_TEXT_1}\n"
    "You can save your adventure by going to\n"
    "your bed. Get in the habit of saving often.\n"
    "You should also store old Pokémon News.\n"
    "If your Mailbox is full{COMMA} you won{APOSTROPHE}t get the\n"
    "latest issue of the news or any job mail.\n"
    "Check the Mailbox and store old news!\n"
    "   - Pokémon Rescue Organization -");


ALIGNED(4) const u8 gMail_BasicsHeadline[] =
    "#2 Rescue Team Basics";


ALIGNED(4) const u8 gMail_WelcomeText[] = _(
    "{CENTER_ALIGN COLOR_1 YELLOW}To All New Members!{END_COLOR_TEXT_1}\n"
    "Your badge has the power to send back\n"
    "to town any Pokémon you{APOSTROPHE}ve rescued. Just\n"
    "hold the badge up{COMMA} and it does the rest.\n"
    "By completing rescue jobs{COMMA} you will be\n"
    "awarded points that raise your team{APOSTROPHE}s\n"
    "ranking. Aim for the Bronze Rank for now!\n"
    "   - Pokémon Rescue Organization -");

ALIGNED(4) const u8 gMail_WelcomeHeadline[] = "#1 Welcome to a Rescue Team!";