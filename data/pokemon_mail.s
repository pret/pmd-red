        .section .rodata

        .global gPokemonMail
gPokemonMail: @ 80EBA18
    @ replacing .incbin "baserom.gba", 0x000eba18, 0x463c
    .4byte gMail_WelcomeHeadline
    .4byte gMail_WelcomeText
    .4byte gMail_BasicsHeadline
    .4byte gMail_BasicsText
    .4byte gMail_JobHeadline
    .4byte gMail_JobText
    .4byte gMail_HungerHeadline
    .4byte gMail_HungerText
    .4byte gMail_SeedHeadline
    .4byte gMail_SeedText
    .4byte gMail_DisasterHeadline
    .4byte gMail_DisasterText
    .4byte gMail_OptionsHeadline
    .4byte gMail_OptionsText
    .4byte gMail_MoveHeadline
    .4byte gMail_MoveText
    .4byte gMail_WonderHeadline
    .4byte gMail_WonderText
    .4byte gMail_DungeonHeadline
    .4byte gMail_DungeonText
    .4byte gMail_TypeHeadline
    .4byte gMail_TypeText
    .4byte gMail_LinkedEntryHeadline1
    .4byte gMail_LinkedEntryText1
    .4byte gMail_LinkedEntryHeadline2
    .4byte gMail_LinkedEntryText2
    .4byte gMail_LinkedEntryHeadline3
    .4byte gMail_LinkedEntryText3
    .4byte gMail_PollHeadline
    .4byte gMail_PollText
    .4byte gMail_WondersHeadline
    .4byte gMail_WondersText
    .4byte gMail_TeamMoveHeadline
    .4byte gMail_TeamMoveText
    .4byte gMail_AddMembersHeadline
    .4byte gMail_AddMembersText
    .4byte gMail_MoveTipsHeadline
    .4byte gMail_MoveTipsText
    .4byte gMail_GummiHeadline
    .4byte gMail_GummiText
    .4byte gMail_UltimateHeadline
    .4byte gMail_UltimateText
    .4byte gMail_MachineHeadline
    .4byte gMail_MachineText
    .4byte gMail_MakuhitaHeadline
    .4byte gMail_MakuhitaText
    .4byte gMail_TrapTileHeadline
    .4byte gMail_TrapTileText
    .4byte gMail_IQHeadline
    .4byte gMail_IQText
    .4byte gMail_RangeHeadline
    .4byte gMail_RangeText
    .4byte gMail_SweetHeadline
    .4byte gMail_SweetText
    .4byte gMail_KeyHeadline
    .4byte gMail_KeyText
    .4byte gMail_AzurillHeadline
    .4byte gMail_AzurillText
    .4byte gMail_WeatherHeadline1
    .4byte gMail_WeatherText1
    .4byte gMail_PechaHeadline
    .4byte gMail_PechaText
    .4byte gMail_WobbuffetHeadline
    .4byte gMail_WobbuffetText
    .4byte gMail_WeatherHeadline2
    .4byte gMail_WeatherText2
    .4byte gMail_KecleonHeadline
    .4byte gMail_KecleonText
    .4byte gMail_SwitchHeadline
    .4byte gMail_SwitchText
    .4byte gMail_KeyItemHeadline1
    .4byte gMail_KeyItemText1
    .4byte gMail_KeyItemHeadline2
    .4byte gMail_KeyItemText2
    .4byte gMail_GasHeadline
    .4byte gMail_GasText
    .4byte gMail_CastformHeadline
    .4byte gMail_CastformText
    .4byte gMail_SmeargleHeadline
    .4byte gMail_SmeargleText
    .4byte gMail_KabutoHeadline
    .4byte gMail_KabutoText
    .4byte gMail_ChanseyHeadline
    .4byte gMail_ChanseyText
    .4byte gMail_ClubHeadline
    .4byte gMail_ClubText
    .4byte gMail_RawstHeadline
    .4byte gMail_RawstText
    .4byte gMail_VileplumeHeadline
    .4byte gMail_VileplumeText
    .4byte gMail_SeaRescueHeadline
    .4byte gMail_SeaRescueText
    .4byte gMail_PitfallHeadline
    .4byte gMail_PitfallText
    .4byte gMail_SlakothHeadline
    .4byte gMail_SlakothText
    .4byte gMail_LinkedProHeadline1
    .4byte gMail_LinkedProText1
    .4byte gMail_LinkedProHeadline2
    .4byte gMail_LinkedProText2
    .4byte gMail_PelipperHeadline
    .4byte gMail_PelipperText
    .4byte gMail_NewsHeadline1
    .4byte gMail_NewsText1
    .4byte gMail_NewsHeadline2
    .4byte gMail_NewsText2
    .4byte gMail_BuriedRelicHeadline
    .4byte gMail_BuriedRelicText
    .4byte gMail_LucarioRankHeadline
    .4byte gMail_LucarioRankText
    .4byte gMail_NewFriendAreasHeadline
    .4byte gMail_NewFriendAreasText

    .global gMail_NewFriendAreasText
    gMail_NewFriendAreasText:
    .string "The Wigglytuff Club has added new Friend\n"
    .string "Areas for sale!\n"
    .string "Rescue Teams are urged to check with\n"
    .string "Wigglytuff for what is available.\n"
    .string "By adding to your Friend Areas~2c you can\n"
    .string "recruit Pokémon that wouldn~27t join your\n"
    .string "rescue team before!\0"
    .align 2,0

    .global gMail_NewFriendAreasHeadline
    gMail_NewFriendAreasHeadline:
    .string "New Friend Areas!\0"
    .align 2,0

    .global gMail_LucarioRankText
    gMail_LucarioRankText:
    .string "Congratulations! Your team has attained\n"
    .string "the Lucario Rank--the top rank among\n"
    .string "rescue teams! In commemoration of your\n"
    .string "fantastic achievement~2c we award you the\n"
    .string "Lucario Statue~2c crafted after the legendary\n"
    .string "rescue team leader.\n"
    .string "Keep working for world peace!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global gMail_LucarioRankHeadline
    gMail_LucarioRankHeadline:
    .string "Congratulations - Lucario Rank!\0"

    .global gMail_BuriedRelicText
    gMail_BuriedRelicText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Mystery Ruin Found Underground!{END_COLOR_TEXT_1}\n"
    .string "Its site had been hidden by the crater of a\n"
    .string "meteor strike in ancient times. The Buried\n"
    .string "Relic is thought to date back beyond\n"
    .string "recorded history. There are rumors of\n"
    .string "treasures... And perhaps even Pokémon\n"
    .string "that lived in ancient times. The Buried\n"
    .string "Relic is the main topic in Pokémon Square.\0"
    .align 2,0

    .global gMail_BuriedRelicHeadline
    gMail_BuriedRelicHeadline:
    .string "Buried Relic Discovered!\0"
    .align 2,0

    .global gMail_NewsText2
    gMail_NewsText2:
    .string "#+{COLOR_1 CYAN}$m0 Innocent! Part 2{END_COLOR_TEXT_1}\n"
    .string "{COLOR_1 GREEN}Quote from Charizard on the scene:{END_COLOR_TEXT_1}\n"
    .string "~93That~27s what I thought right from\n"
    .string "the start~2c hahaha!~94\n"
    .string "{COLOR_1 GREEN}Quote from Tyranitar on the scene:{END_COLOR_TEXT_1}\n"
    .string "~93That muckraking Gengar...\n"
    .string "He~27s not getting away with this!\n"
    .string "He~27d better be ready for it!~94\0"
    .align 2,0

    .global gMail_NewsHeadline2
    gMail_NewsHeadline2:
    .string "Pokémon News Extra 2\0"
    .align 2,0

    .global gMail_NewsText1
    gMail_NewsText1:
    .string "#+{COLOR_1 CYAN}$m0 Innocent! Part 1{END_COLOR_TEXT_1}\n"
    .string "$m1 met with Ninetales on {COLOR_1 RED}Mt. Freeze{END_COLOR_TEXT_1}.\n"
    .string "Ninetales testified that $m0 was\n"
    .string "not the human that appeared in the legend.\n"
    .string "As a result~2c Gengar~27s claims were found to\n"
    .string "be malicious lies.\n"
    .string "{COLOR_1 GREEN}The clearly dismayed Gengar~27s quote:{END_COLOR_TEXT_1}\n"
    .string "~93Ugegegegegegegegegegegeh!~94\0"
    .align 2,0

    .global gMail_NewsHeadline1
    gMail_NewsHeadline1:
    .string "Pokémon News Extra 1\0"
    .align 2,0

    .global gMail_PelipperText
    gMail_PelipperText:
    .string "Yo! Amigo! It~27s awesome you~27re back!\n"
    .string "I~27ll be delivering mail to you again!\n"
    .string "I~27ve been looking forward to this with\n"
    .string "my bill outstretched!\n"
    .string "I~27ll deliver tons of mail~2c so you~27d better\n"
    .string "be ready~2c amigo!\n\n"
    .string " - The wandering postal carrier~2c Pelipper -\0"
    .align 2,0

    .global gMail_PelipperHeadline
    gMail_PelipperHeadline:
    .string "A Letter from Pelipper\0"
    .align 2,0

    .global gMail_LinkedProText2
    gMail_LinkedProText2:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Try These Linked Moves to KO Foes!{END_COLOR_TEXT_1}\n\n"
    .string "Psyduck\n"
    .string "{COLOR_1 GREEN}Confusion{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Disable{END_COLOR_TEXT_1}\n"
    .string "Totodile\n"
    .string "{COLOR_1 GREEN}Bite{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Scary Face{END_COLOR_TEXT_1}\n"
    .string "Cyndaquil\n"
    .string "{COLOR_1 GREEN}Flame Wheel{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Smokescreen{END_COLOR_TEXT_1}#P"
    .string "Pikachu\n"
    .string "{COLOR_1 GREEN}Thunderbolt{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Double Team{END_COLOR_TEXT_1}\n"
    .string "Skitty\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Doubleslap{END_COLOR_TEXT_1}\0"
    .align 2,0

    .global gMail_LinkedProHeadline2
    gMail_LinkedProHeadline2:
    .string "#50 Linked Moves Pro Level 2\0"
    .align 2,0

    .global gMail_LinkedProText1
    gMail_LinkedProText1:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}These Linked Move Combinations{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Can Be Devastating!{END_COLOR_TEXT_1}\n\n"
    .string "Bulbasaur\n"
    .string "{COLOR_1 GREEN}Razor Leaf{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Sleep Powder{END_COLOR_TEXT_1}\n"
    .string "Chikorita\n"
    .string "{COLOR_1 GREEN}Body Slam{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Reflect{END_COLOR_TEXT_1}#P"
    .string "Treecko\n"
    .string "{COLOR_1 GREEN}Screech{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Pound{END_COLOR_TEXT_1}\n"
    .string "Machop\n"
    .string "{COLOR_1 GREEN}Focus Energy{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Karate Chop{END_COLOR_TEXT_1}\n"
    .string "Cubone\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Bonemerang{END_COLOR_TEXT_1}\0"
    .align 2,0

    .global gMail_LinkedProHeadline1
    gMail_LinkedProHeadline1:
    .string "#49 Linked Moves Pro Level 1\0"
    .align 2,0

    .global gMail_SlakothText
    gMail_SlakothText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Relief for Delicate Souls Who Can~27t{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Sleep with Different Pillows!{END_COLOR_TEXT_1}\n"
    .string "Insomniacs rejoiced over the announcement\n"
    .string "of the Slakoth Pillow~2c which is said to\n"
    .string "induce sleepiness just by seeing it.\n"
    .string "Already the inventor is swamped with\n"
    .string "inquiries from all over. However~2c\n"
    .string "production is said to be not yet ready.\0"
    .align 2,0

    .global gMail_SlakothHeadline
    gMail_SlakothHeadline:
    .string "#48 Slakoth Pillows for Insomnia!\0"
    .align 2,0

    .global gMail_PitfallText
    gMail_PitfallText:
    .string "As a result of the natural disasters~2c\n"
    .string "there have been many reports of Pitfall\n"
    .string "Traps appearing in dungeons.\n"
    .string "However~2c there also appear to be pitfalls\n"
    .string "made by Pokémon that are not harmful.\n"
    .string "The latter are thought to be made by\n"
    .string "foraging Swinub. Some even turn out to\n"
    .string "be hot springs that erupt occasionally.\0"
    .align 2,0

    .global gMail_PitfallHeadline
    gMail_PitfallHeadline:
    .string "#47 Beware of Pitfalls\0"
    .align 2,0

    .global gMail_SeaRescueText
    gMail_SeaRescueText:
    .string "A high-seas rescue in the {COLOR_1 RED}Stormy Sea{END_COLOR_TEXT_1} by\n"
    .string "{COLOR_1 CYAN}Team Sea Dragons{END_COLOR_TEXT_1} ended yesterday with\n"
    .string "the successful recovery of Tentacool.\n"
    .string "The client~2c Corsola~2c is said to be delighted\n"
    .string "by the outcome.\n"
    .string "Tentacool stated~2c ~93I didn~27t realize how far\n"
    .string "I~27d been washed out to sea.~94\n"
    .string "The {COLOR_1 RED}Stormy Sea{END_COLOR_TEXT_1} is unforgiving!\0"
    .align 2,0

    .global gMail_SeaRescueHeadline
    gMail_SeaRescueHeadline:
    .string "#46 Sea Rescue a Success!\0"
    .align 2,0

    .global gMail_VileplumeText
    gMail_VileplumeText:
    .string "Vileplume are widely recognized for \n"
    .string "their massive flower. However~2c few dare\n"
    .string "to approach Vileplume because they\n"
    .string "scatter clouds of allergy-inducing\n"
    .string "pollen. Vileplume complain that they tire\n"
    .string "very easily because the flower~27s weight\n"
    .string "makes their head heavy.\0"
    .align 2,0

    .global gMail_VileplumeHeadline
    gMail_VileplumeHeadline:
    .string "#45 Vileplume~27s Weighty Problem\0"
    .align 2,0

    .global gMail_RawstText
    gMail_RawstText:
    .string "Research has revealed that {COLOR_1 GREEN}Rawst Berries{END_COLOR_TEXT_1}\n"
    .string "found in dungeons are usually unripened\n"
    .string "and colored green. When ripe~2c they turn a\n"
    .string "sky blue color. An unripened one is easier\n"
    .string "to eat~2c however~2c because it has not yet\n"
    .string "turned bitter. It is known to heal all\n"
    .string "burns.\0"
    .align 2,0

    .global gMail_RawstHeadline
    gMail_RawstHeadline:
    .string "#44 Rawst Berry~27s Effect\0"
    .align 2,0

    .global gMail_ClubText
    gMail_ClubText:
    .string "We proudly announce the foundation of\n"
    .string "the Red & Blue Fan Club~2c an organization\n"
    .string "for supporting Pokémon rescue teams.\n"
    .string "We are currently recruiting new members.\n"
    .string "Won~27t you join and throw your support\n"
    .string "behind our hard-working rescue heroes?\n\n"
    .string "  - Plusle and Minun -\0"
    .align 2,0

    .global gMail_ClubHeadline
    gMail_ClubHeadline:
    .string "#43 Fan Club Seeks Members!\0"
    .align 2,0

    .global gMail_ChanseyText
    gMail_ChanseyText:
    .string "As a special treat~2c I~27ll share a simple\n"
    .string "way to tell fortunes with you!\n"
    .string "The key is the first thing you find in the\n"
    .string "day~27s first dungeon.\n"
    .string "If it~27s money~2c you~27ll be sure to make more.\n"
    .string "If it~27s a Berry~2c your health luck is good.\n"
    .string "If it~27s an Apple~2c you~27re super lucky!\n"
    .string "  - Chansey -\0"
    .align 2,0

    .global gMail_ChanseyHeadline
    gMail_ChanseyHeadline:
    .string "#42 Chansey~27s Fortune-Telling\0"
    .align 2,0

    .global gMail_KabutoText
    gMail_KabutoText:
    .string "One of our oldest residents claims to feel\n"
    .string "rejuvenated. Kabuto reportedly had an\n"
    .string "encounter with Relicanth in which both\n"
    .string "parties reminisced about the ~93old days.~94\n"
    .string "However~2c even Kabuto could not keep up\n"
    .string "with Relicanth~27s tales from a hundred\n"
    .string "million years ago. Kabuto stated~2c ~93It\n"
    .string "made me feel young talking to Relicanth.~94\0"
    .align 2,0

    .global gMail_KabutoHeadline
    gMail_KabutoHeadline:
    .string "#41 Kabuto Feels Young Again!\0"
    .align 2,0

    .global gMail_SmeargleText
    gMail_SmeargleText:
    .string "Smeargle~2c the artist known for his unique\n"
    .string "artistic vision~2c had a windfall day as one\n"
    .string "of his paintings was auctioned for 300\n"
    .string "million {POKE} yesterday. The auctioned\n"
    .string "artwork was one of Smeargle~27s signature\n"
    .string "works from early in his career.\0"
    .align 2,0

    .global gMail_SmeargleHeadline
    gMail_SmeargleHeadline:
    .string "#40 Smeargle Painting Auctioned!\0"
    .align 2,0

    .global gMail_CastformText
    gMail_CastformText:
    .string "Today~2c the weather over Pokémon\n"
    .string "Square promises to be clear with no\n"
    .string "chance of showers.\n"
    .string "Other regions can expect showers followed\n"
    .string "by clouds. There may be sun breaks\n"
    .string "depending on the day~27s moods.\0"
    .align 2,0

    .global gMail_CastformHeadline
    gMail_CastformHeadline:
    .string "#39 Castform~27s Daily Weather\0"
    .align 2,0

    .global gMail_GasText
    gMail_GasText:
    .string "Reports of a noxious gas leak caused\n"
    .string "widespread chaos in the {COLOR_1 YELLOW_3}Sinister Woods{END_COLOR_TEXT_1}.\n"
    .string "Specialists speculate that the recent\n"
    .string "natural disasters are to blame. However~2c\n"
    .string "some also blame {COLOR_1 CYAN}Team Koffing{END_COLOR_TEXT_1}~27s training\n"
    .string "in the area for the foul-smelling gas.\n"
    .string "The answer~2c apparently~2c is blowing in the\n"
    .string "wind.\0"
    .align 2,0

    .global gMail_GasHeadline
    gMail_GasHeadline:
    .string "#38 Noxious Gas Leak?!\0"
    .align 2,0

    .global gMail_KeyItemText2
    gMail_KeyItemText2:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}When Used Somewhere Special...{END_COLOR_TEXT_1}\n"
    .string "Eevee and Water Stone~2c Fire Stone~2c\n"
    .string "Thunderstone~2c or...\n"
    .string "Exeggcute and Leaf Stone...\n"
    .string "Onix~2c Metal Coat~2c and Link Cable...\n"
    .string "There appear to be many others!\0"
    .align 2,0
    
    .global gMail_KeyItemHeadline2
    gMail_KeyItemHeadline2:
    .string "#37 Key Items for Pokémon 2\0"
    .align 2,0
    
    .global gMail_KeyItemText1
    gMail_KeyItemText1:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}When Used Somewhere Special...{END_COLOR_TEXT_1}\n"
    .string "Sunkern and Sun Stone...\n"
    .string "Skitty and Moon Stone...\n"
    .string "Growlithe and Fire Stone...\n"
    .string "Shellder and Water Stone...\n"
    .string "Clamperl and Deepseatooth...\n"
    .string "There appear to be many others!\0"
    .align 2,0
    
    .global gMail_KeyItemHeadline1
    gMail_KeyItemHeadline1:
    .string "#36 Key Items for Pokémon 1\0"
    .align 2,0
    
    .global gMail_SwitchText
    gMail_SwitchText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Power Up Combination Attacks!{END_COLOR_TEXT_1}\n"
    .string "Some dungeons allow rescue teams to\n"
    .string "switch leaders on the spot for doing\n"
    .string "combination attacks and so on.\n"
    .string "When you enter a dungeon~2c open the menu~2c\n"
    .string "choose the Pokémon you want as the\n"
    .string "leader under {COLOR_1 YELLOW}Team{END_COLOR_TEXT_1}~2c then select the\n"
    .string "command {COLOR_1 YELLOW}Leader{END_COLOR_TEXT_1}.\0"
    .align 2,0
    
    .global gMail_SwitchHeadline
    gMail_SwitchHeadline:
    .string "#35 Switching Leaders\0"
    .align 2,0
    
    .global gMail_KecleonText
    gMail_KecleonText:
    .string "There have been numerous reports that\n"
    .string "the older of the Kecleon merchants in\n"
    .string "Pokémon Square occasionally goes\n"
    .string "missing. Some residents claim~2c ~93He~27s\n"
    .string "greedy. He must be off doing business\n"
    .string "somewhere.~94 His younger brother denies\n"
    .string "such claims: ~93He wouldn~27t get free items\n"
    .string "in dungeons and try to sell them...~94\0"
    .align 2,0
    
    .global gMail_KecleonHeadline
    gMail_KecleonHeadline:
    .string "#34 Where Is Kecleon?\0"
    .align 2,0
    
    .global gMail_WeatherText2
    gMail_WeatherText2:
    .string "Clear: Pleasant weather.\n"
    .string "Hail: Regularly inflicts damage~2c\n"
    .string "except on the Ice type.\n"
    .string "Fog: Turns the status of all Pokémon on\n"
    .string "the floor to Mud Sport.\n"
    .string "Blizzard: Boosts the movement speed of\n"
    .string "Ice-type Pokémon by one level.\0"
    .align 2,0
    
    .global gMail_WeatherHeadline2
    gMail_WeatherHeadline2:
    .string "#33 Dungeons and Weather 2\0"
    .align 2,0
    
    .global gMail_WobbuffetText
    gMail_WobbuffetText:
    .string "Earlier today~2c Wobbuffet reportedly\n"
    .string "wobbled the wrong way and wandered off.\n"
    .string "It had to be rescued by the famous\n"
    .string "{COLOR_1 CYAN}Team Hydro{END_COLOR_TEXT_1}.\n"
    .string "Fortunately~2c the wayward wanderer\n"
    .string "Wobbuffet was only wobbly and otherwise\n"
    .string "unharmed.\0"
    .align 2,0
    
    .global gMail_WobbuffetHeadline
    gMail_WobbuffetHeadline:
    .string "#32 Wobbly Wobbuffet Wanders!\0"
    .align 2,0
    
    .global gMail_PechaText
    gMail_PechaText:
    .string "Among rescue teams~2c there is growing\n"
    .string "demand for equipment that is not only\n"
    .string "practical~2c but also fashionably appealing.\n"
    .string "The pink {COLOR_1 GREEN}Pecha Scarf{END_COLOR_TEXT_1} is especially popular.\n"
    .string "Even the {COLOR_1 CYAN}Kecleon Shop{END_COLOR_TEXT_1} is having trouble\n"
    .string "keeping it in stock.\n"
    .string "If you~27re lucky enough to spot one~2c make a\n"
    .string "beeline for it!\0"
    .align 2,0
    
    .global gMail_PechaHeadline
    gMail_PechaHeadline:
    .string "#31 Pecha Scarf--Top Popularity!\0"
    .align 2,0

    .global gMail_WeatherText1
    gMail_WeatherText1:
    .string "Sunny: Boosts Fire-type moves~2c and\n"
    .string "weakens Water-type moves.\n"
    .string "Sandstorm: Regularly inflicts damage\n"
    .string "except on Ground~2c Rock~2c and Steel types.\n"
    .string "Cloudy: All moves and attacks~2c excluding\n"
    .string "the Normal type~2c are weakened.\n"
    .string "Rain: Boosts Water-type moves~2c and\n"
    .string "weakens Fire. Prevents explosions.\0"
    .align 2,0
    
    .global gMail_WeatherHeadline1
    gMail_WeatherHeadline1:
    .string "#30 Dungeons and Weather 1\0"
    .align 2,0
    
    .global gMail_AzurillText
    gMail_AzurillText:
    .string "With a simple act of courage~2c Azurill\n"
    .string "became a hero despite being small in size.\n"
    .string "Azurill came across Slowpoke~2c who had\n"
    .string "fallen into a pond. Our hero~27s tail~2c thrown\n"
    .string "at the struggling Slowpoke~2c saved a sure\n"
    .string "drowning! Slowpoke claimed to have\n"
    .string "entirely forgotten having the ability to\n"
    .string "swim capably.\0"
    .align 2,0
    
    .global gMail_AzurillHeadline
    gMail_AzurillHeadline:
    .string "#29 Azurill--the Little Hero!\0"
    .align 2,0
    
    .global gMail_KeyText
    gMail_KeyText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Head Out to the Desert Region!{END_COLOR_TEXT_1}\n"
    .string "If you~27ve been wondering what lies behind\n"
    .string "the mysterious locked doors of the #CDSolar\n"
    .string "Cave{END_COLOR_TEXT_1}~2c there~27s been a breakthrough!\n"
    .string "Reports indicate the door keys are easily\n"
    .string "found in the #CDDesert Region{END_COLOR_TEXT_1}. Explorers are\n"
    .string "advised to compose teams with Pokémon\n"
    .string "adapted to the desert environment.\0"
    .align 2,0
    
    .global gMail_KeyHeadline
    gMail_KeyHeadline:
    .string "#28 The Key\0"
    .align 2,0
    
    .global gMail_SweetText
    gMail_SweetText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Feel a Little Envious?{END_COLOR_TEXT_1}\n"
    .string "Teddiursa is often seen licking its paws\n"
    .string "that have soaked up sweet honey. While it\n"
    .string "may be sticky shaking paws with\n"
    .string "Teddiursa~2c one can~27t help but feel a\n"
    .string "twinge of envy.\0"
    .align 2,0
    
    .global gMail_SweetHeadline
    gMail_SweetHeadline:
    .string "#27 Sweet Hands!\0"
    .align 2,0
    
    .global gMail_RangeText
    gMail_RangeText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}All Moves Have Effective Ranges{END_COLOR_TEXT_1}\n"
    .string "Moves that affect an entire room have a\n"
    .string "range of two tiles in a corridor. The move\n"
    .string "{COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}~2c which lowers the Attack stat of\n"
    .string "foes in a room~2c will reach two tiles away\n"
    .string "in a corridor~2c for example. If~2c however~2c\n"
    .string "the visibility is limited to just one tile~2c\n"
    .string "the range of moves will also be limited.\0"
    .align 2,0

    .global gMail_RangeHeadline
    gMail_RangeHeadline:
    .string "#26 The Range of Moves\0"
    .align 2,0

    .global gMail_IQText
    gMail_IQText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Make Your Explorations Easier by{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Boosting the IQ of Team Members!{END_COLOR_TEXT_1}\n"
    .string "Eating Gummis boosts the IQ of Pokémon.\n"
    .string "Upon reaching certain IQ levels~2c a Pokémon\n"
    .string "learns IQ Skills that can be very helpful\n"
    .string "(for example~2c learning to seek out foes\n"
    .string "with type disadvantages). Check\n"
    .string "the IQ Skills of your team members!\0"
    .align 2,0

    .global gMail_IQHeadline
    gMail_IQHeadline:
    .string "#25 IQ\0"
    .align 2,0

    .global gMail_TrapTileText
    gMail_TrapTileText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}New Types of Floor Tiles?{END_COLOR_TEXT_1}\n"
    .string "There have been numerous reports of new\n"
    .string "floor tiles other than Wonder Tiles.\n"
    .string "Believed to have been made by the recent\n"
    .string "natural disasters~2c these floor tiles remain\n"
    .string "hidden until they are stepped on. They then\n"
    .string "trigger a variety of traps. Rescue teams\n"
    .string "are urged to use extreme caution.\0"
    .align 2,0

    .global gMail_TrapTileHeadline
    gMail_TrapTileHeadline:
    .string "#24 New Floor Tiles?\0"
    .align 2,0

    .global gMail_MakuhitaText
    gMail_MakuhitaText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Study Type Matchups{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}at the Makuhita Dojo!{END_COLOR_TEXT_1}\n"
    .string "At the Makuhita Dojo~2c one can learn how\n"
    .string "Pokémon type matchups affect battles.\n"
    .string "It~27s because the dojo~27s training rooms are\n"
    .string "divided by type. For example~2c in the #CDFire\n"
    .string "Maze{END_COLOR_TEXT_1}~2c there are only Fire-type Pokémon.\n"
    .string "Try move types to see what works best!\0"
    .align 2,0

    .global gMail_MakuhitaHeadline
    gMail_MakuhitaHeadline:
    .string "#23 Train at the Makuhita Dojo!\0"
    .align 2,0

    .global gMail_MachineText
    gMail_MachineText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}New Types of Machines Discovered?{END_COLOR_TEXT_1}\n"
    .string "In a recently discovered cave~2c explorers\n"
    .string "found unique types of Technical Machines.\n"
    .string "They apparently do not break after a single\n"
    .string "use. Further studies are said to be under\n"
    .string "consideration by the authorities.\n"
    .string "In related news~2c the cave is to be named\n"
    .string "the #CDSolar Cave{END_COLOR_TEXT_1}.\0"
    .align 2,0

    .global gMail_MachineHeadline
    gMail_MachineHeadline:
    .string "#22 New Types of Machines?\0"
    .align 2,0

    .global gMail_UltimateText
    gMail_UltimateText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}The Ultimate Dungeon{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Challenges You to Do Your Best!{END_COLOR_TEXT_1}\n"
    .string "Somewhere in the world~2c there supposedly\n"
    .string "is an incredibly tough dungeon. One must\n"
    .string "enter alone at Level 1~2c and without any\n"
    .string "items. No one has ever completed the\n"
    .string "challenge. It is considered a test not of\n"
    .string "power~2c but of intelligence and wits.\0"
    .align 2,0

    .global gMail_UltimateHeadline
    gMail_UltimateHeadline:
    .string "#21 The Ultimate Dungeon\0"
    .align 2,0

    .global gMail_GummiText
    gMail_GummiText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Gummis That Make You Smart{END_COLOR_TEXT_1}\n"
    .string "Research has revealed that popular Gummi\n"
    .string "treats not only enhance intelligence~2c they\n"
    .string "also have different effects depending on\n"
    .string "type. Share Gummis with your friends and\n"
    .string "get smarter for your adventures! In\n"
    .string "dungeons~2c throw them at your friends.\n"
    .string "Use them in Friend Areas and...?\0"
    .align 2,0

    .global gMail_GummiHeadline
    gMail_GummiHeadline:
    .string "#20 Secrets of the Gummi\0"
    .align 2,0

    .global gMail_MoveTipsText
    gMail_MoveTipsText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Moving Diagonally{END_COLOR_TEXT_1}\n"
    .string "Move diagonally to avoid foes!\n"
    .string "Keeping {R_BUTTON}"
    .string " pressed~2c use\n"
    .byte 0x87
    .string "R to move diagonally.\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Changing Direction{END_COLOR_TEXT_1}\n"
    .string "It~27s also very important to change\n"
    .string "directions without moving. Check Hints to\n"
    .string "see how you can do this maneuver!\0"
    .align 2,0

    .global gMail_MoveTipsHeadline
    gMail_MoveTipsHeadline:
    .string "#19 Important Moving Tips\0"
    .align 2,0

    .global gMail_AddMembersText
    gMail_AddMembersText:
    .string "If you want to enlarge your rescue team~2c\n"
    .string "you must first get Friend Areas. When\n"
    .string "a Pokémon that can live in an obtained\n"
    .string "Friend Area is defeated~2c it may ask to\n"
    .string "join your rescue team. Add to your\n"
    .string "Friend Areas so you can recruit more\n"
    .string "members! Incidentally~2c you may take no\n"
    .string "more than three friends into a dungeon.\0"
    .align 2,0

    .global gMail_AddMembersHeadline
    gMail_AddMembersHeadline:
    .string "#18 Adding Team Members\0"
    .align 2,0

    .global gMail_TeamMoveText
    gMail_TeamMoveText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Use Team Members Effectively!{END_COLOR_TEXT_1}\n"
    .string "When you~27re fighting in a dungeon~2c it~27s\n"
    .string "important to use your team members. If\n"
    .string "attacked from the side~2c move horizontally.\n"
    .string "If attacked from above or below~2c move\n"
    .string "vertically. That way~2c you can have several\n"
    .string "Pokémon fighting a single foe. Change\n"
    .string "Tactics if members don~27t move properly.\0"
    .align 2,0

    .global gMail_TeamMoveHeadline
    gMail_TeamMoveHeadline:
    .string "#17 Moving as a Team\0"
    .align 2,0

    .global gMail_WondersText
    gMail_WondersText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}The Seven Wonders of Pokémon?{END_COLOR_TEXT_1}\n"
    .string "The mysterious feet of Diglett.\n"
    .string "What is inside Forretress~27s shell.\n"
    .string "The intelligence of Girafarig~27s tail.\n"
    .string "Arbok~27s variety of patterns.\n"
    .string "We await submissions from readers on\n"
    .string "other Pokémon mysteries!\n"
    .string "  - Mystery Hunter Team -\0"
    .align 2,0

    .global gMail_WondersHeadline
    gMail_WondersHeadline:
    .string "#16 Seven Wonders of Pokémon\0"
    .align 2,0

    .global gMail_PollText
    gMail_PollText:
    .string "{COLOR_1 YELLOW}First#=2Gravelerock{END_COLOR_TEXT_1}\n"
    .string "{COLOR_1 YELLOW}Second#=2Oran Berry{END_COLOR_TEXT_1}\n"
    .string "In a nationwide survey involving rescue\n"
    .string "teams~2c the most popular item was found to\n"
    .string "be {COLOR_1 GREEN}Gravelerocks{END_COLOR_TEXT_1}. According to Sudowoodo\n"
    .string "of {COLOR_1 CYAN}Team Fakers{END_COLOR_TEXT_1}~2c ~93It lets you attack\n"
    .string "from far away. It~27s invaluable.~94 The next\n"
    .string "most popular item was {COLOR_1 GREEN}Oran Berries{END_COLOR_TEXT_1}.\0"
    .align 2,0

    .global gMail_PollHeadline
    gMail_PollHeadline:
    .string "#15 Poll: Top Two Items\0"
    .align 2,0

    .global gMail_LinkedEntryText3
    gMail_LinkedEntryText3:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}These Are the Final Linked Moves{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}We Recommend in the Entry Level!{END_COLOR_TEXT_1}\n"
    .string "{COLOR_1 RED}Electric and Water Types{END_COLOR_TEXT_1}\n"
    .string "Pikachu\n"
    .string "{COLOR_1 GREEN}Thundershock{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    .string "Squirtle\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}#PTotodile\n"
    .string "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Scratch{END_COLOR_TEXT_1}\n"
    .string "Mudkip\n"
    .string "{COLOR_1 GREEN}Water Gun{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Mud-Slap{END_COLOR_TEXT_1}\n"
    .string "Psyduck\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Scratch{END_COLOR_TEXT_1}\0"
    .align 2,0

    .global gMail_LinkedEntryHeadline3
    gMail_LinkedEntryHeadline3:
    .string "#14 Linked Moves Entry Level 3\0"
    .align 2,0

    .global gMail_LinkedEntryText2
    gMail_LinkedEntryText2:
    .string "{COLOR_1 RED}Fire and Normal Types{END_COLOR_TEXT_1}\n"
    .string "Charmander\n"
    .string "{COLOR_1 GREEN}Ember{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    .string "Cyndaquil\n"
    .string "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}\n"
    .string "Torchic\n"
    .string "{COLOR_1 GREEN}Ember{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}#PEevee\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}\n"
    .string "Meowth\n"
    .string "{COLOR_1 GREEN}Scratch{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    .string "Skitty\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Tackle{END_COLOR_TEXT_1}\0"
    .align 2,0

    .global gMail_LinkedEntryHeadline2
    gMail_LinkedEntryHeadline2:
    .string "#13 Linked Moves Entry Level 2\0"
    .align 2,0

    .global gMail_LinkedEntryText1
    gMail_LinkedEntryText1:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}These Are the Recommended{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Linked Moves for Beginners!{END_COLOR_TEXT_1}\n"
    .string "{COLOR_1 RED}Grass~2c Fighting~2c and Ground Types{END_COLOR_TEXT_1}\n"
    .string "Bulbasaur\n"
    .string "{COLOR_1 GREEN}Vine Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}\n"
    .string "Chikorita\n"
    .string "{COLOR_1 GREEN}Razor Leaf{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}#PTreecko\n"
    .string "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Pound{END_COLOR_TEXT_1}\n"
    .string "Machop\n"
    .string "{COLOR_1 GREEN}Leer{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Low Kick{END_COLOR_TEXT_1}\n"
    .string "Cubone\n"
    .string "{COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1} + {COLOR_1 GREEN}Bone Club{END_COLOR_TEXT_1}\0"
    .align 2,0

    .global gMail_LinkedEntryHeadline1
    gMail_LinkedEntryHeadline1:
    .string "#12 Linked Moves Entry Level 1\0"
    .align 2,0

    .global gMail_TypeText
    gMail_TypeText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Learn How Types Match Up!{END_COLOR_TEXT_1}\n"
    .string "All Pokémon are of certain types~2c such as\n"
    .string "{COLOR_1 RED}Fire{END_COLOR_TEXT_1} and {COLOR_1 CYAN}Water{END_COLOR_TEXT_1}. In a battle~2c the damage\n"
    .string "inflicted depends on how the Pokémon~27s\n"
    .string "type matches up with the move~27s type.\n"
    .string "For example~2c a {COLOR_1 RED}Fire{END_COLOR_TEXT_1}-type Pokémon is\n"
    .string "weak against {COLOR_1 CYAN}Water{END_COLOR_TEXT_1}-type moves.\n"
    .string "Exploit type matchups to win battles!\0"
    .align 2,0

    .global gMail_TypeHeadline
    gMail_TypeHeadline:
    .string "#11 Types and Matchups\0"
    .align 2,0

    .global gMail_DungeonText
    gMail_DungeonText:
    .string "If your rescue team is defeated in a\n"
    .string "dungeon~2c you lose several items and\n"
    .string "all the money you are carrying.\n"
    .string "Beware of what you~27re carrying before\n"
    .string "you go off on a rescue or an outing.\n"
    .string "Use {COLOR_1 CYAN}Kangaskhan Storage{END_COLOR_TEXT_1} to keep\n"
    .string "invaluable items safely stored.\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global gMail_DungeonHeadline
    gMail_DungeonHeadline:
    .string "#10 Mysterious Dungeons?\0"
    .align 2,0

    .global gMail_WonderText
    gMail_WonderText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Wonder Tiles Reset Attack and Defense!{END_COLOR_TEXT_1}\n"
    .string "If your Attack is lowered by a foe~27s\n"
    .string "{COLOR_1 GREEN}Growl{END_COLOR_TEXT_1}~2c or your Defense is lowered\n"
    .string "by a foe~27s {COLOR_1 GREEN}Tail Whip{END_COLOR_TEXT_1}~2c for example~2c the\n"
    .string "affected stat can be reset to normal by\n"
    .string "stepping on a Wonder Tile or going to the\n"
    .string "next floor. Beware~2c enhanced stats are\n"
    .string "also reset to normal!\0"
    .align 2,0

    .global gMail_WonderHeadline
    gMail_WonderHeadline:
    .string "#9 Wonder Tiles\0"
    .align 2,0

    .global gMail_MoveText
    gMail_MoveText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}The Benefits of Using Moves{END_COLOR_TEXT_1}\n"
    .string "If a move is used on a foe~2c when it is\n"
    .string "defeated~2c {COLOR_1 CYAN}you earn more Exp. Points{END_COLOR_TEXT_1}!\n"
    .string "A move only has to be used once on the\n"
    .string "foe: after that it can be defeated using a\n"
    .string "regular attack to earn more Exp. Points.\n"
    .string "Moves are also more likely to become\n"
    .string "{COLOR_1 CYAN}critical hits{END_COLOR_TEXT_1}! Don~27t overuse them~2c though!\0"
    .align 2,0

    .global gMail_MoveHeadline
    gMail_MoveHeadline:
    .string "#8 Let~27s Use Moves!\0"
    .align 2,0

    .global gMail_OptionsText
    gMail_OptionsText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Change Your Option Settings{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}to Suit Your Play Style!{END_COLOR_TEXT_1}\n"
    .string "Press {B_BUTTON} to open the menu~2c then\n"
    .string "choose {COLOR_1 YELLOW}Others{END_COLOR_TEXT_1} and {COLOR_1 YELLOW}Game Options{END_COLOR_TEXT_1}.\n"
    .string "You can change settings to suit the way\n"
    .string "you play.\0"
    .align 2,0

    .global gMail_OptionsHeadline
    gMail_OptionsHeadline:
    .string "#7 Game Options\0"
    .align 2,0

    .global gMail_DisasterText
    gMail_DisasterText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Investigations Under Way into{END_COLOR_TEXT_1}\n"
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Recent Rash of Natural Disasters{END_COLOR_TEXT_1}\n"
    .string "Pokémon in affected areas attack any\n"
    .string "outsider without hesitation. Some believe\n"
    .string "a mysterious force is behind their\n"
    .string "behavior. One source blamed Diglett\n"
    .string "for triggering earthquakes~2c but the\n"
    .string "investigative team is skeptical.\0"
    .align 2,0

    .global gMail_DisasterHeadline
    gMail_DisasterHeadline:
    .string "#6 Recent Natural Disasters\0"
    .align 2,0

    .global gMail_SeedText
    gMail_SeedText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Seeds Can Be Thrown~2c Too!{END_COLOR_TEXT_1}\n"
    .string "Seeds are usually meant to be eaten.\n"
    .string "But did you know? They can also be thrown\n"
    .string "at other Pokémon to unlock their effects.\n"
    .string "Toss seeds you don~27t want to eat at foes!\n"
    .string "Throw good seeds at friends!\n"
    .string "Don~27t be afraid to throw your seeds!\0"
    .align 2,0

    .global gMail_SeedHeadline
    gMail_SeedHeadline:
    .string "#5 Throw Seeds!\0"
    .align 2,0

    .global gMail_HungerText
    gMail_HungerText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Eat Something When You Get Hungry!{END_COLOR_TEXT_1}\n"
    .string "While you~27re exploring a dungeon~2c you will\n"
    .string "get progressively hungry (your Belly goes\n"
    .string "down). If you become famished~2c you will\n"
    .string "eventually lose HP and even faint.\n"
    .string "That~27s why you should eat something to fill\n"
    .string "your Belly! You can always buy food at the\n"
    .string "{COLOR_1 CYAN}Kecleon Shop{END_COLOR_TEXT_1}.\0"
    .align 2,0

    .global gMail_HungerHeadline
    gMail_HungerHeadline:
    .string "#4 Getting Hungry\0"
    .align 2,0

    .global gMail_JobText
    gMail_JobText:
    .string "If you want to go on a rescue job listed\n"
    .string "on the Bulletin Board at the Pelipper Post\n"
    .string "Office~2c or one that~27s delivered to your\n"
    .string "Mailbox~2c you first need to {COLOR_1 YELLOW}Accept{END_COLOR_TEXT_1} the job~2c\n"
    .string "then choose {COLOR_1 YELLOW}Take Job{END_COLOR_TEXT_1}. Only then will you\n"
    .string "be able to handle that job.\n"
    .string "Try to do accepted jobs quickly!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global gMail_JobHeadline
    gMail_JobHeadline:
    .string "#3 Accepting Rescue Jobs\0"
    .align 2,0
    
    .global gMail_BasicsText
    gMail_BasicsText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}Saving Your Adventure and Pokémon News{END_COLOR_TEXT_1}\n"
    .string "You can save your adventure by going to\n"
    .string "your bed. Get in the habit of saving often.\n"
    .string "You should also store old Pokémon News.\n"
    .string "If your Mailbox is full~2c you won~27t get the\n"
    .string "latest issue of the news or any job mail.\n"
    .string "Check the Mailbox and store old news!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global gMail_BasicsHeadline
    gMail_BasicsHeadline:
    .string "#2 Rescue Team Basics\0"
    .align 2,0

    .global gMail_WelcomeText
    gMail_WelcomeText:
    .string "{CENTER_ALIGN COLOR_1 YELLOW}To All New Members!{END_COLOR_TEXT_1}\n"
    .string "Your badge has the power to send back\n"
    .string "to town any Pokémon you~27ve rescued. Just\n"
    .string "hold the badge up~2c and it does the rest.\n"
    .string "By completing rescue jobs~2c you will be\n"
    .string "awarded points that raise your team~27s\n"
    .string "ranking. Aim for the Bronze Rank for now!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global gMail_WelcomeHeadline
    gMail_WelcomeHeadline:
    .string "#1 Welcome to a Rescue Team!\0"
    .align 2,0

    .string "pksdir0\0"
