        .section .rodata

        .global gPokemonMail
gPokemonMail: @ 80EBA18
    @ replacing .incbin "baserom.gba", 0x000eba18, 0x463c
    .4byte WelcomeHeadline
    .4byte WelcomeText
    .4byte BasicsHeadline
    .4byte BasicsText
    .4byte JobHeadline
    .4byte JobText
    .4byte HungerHeadline
    .4byte HungerText
    .4byte SeedHeadline
    .4byte SeedText
    .4byte DisasterHeadline
    .4byte DisasterText
    .4byte OptionsHeadline
    .4byte OptionsText
    .4byte MoveHeadline
    .4byte MoveText
    .4byte WonderHeadline
    .4byte WonderText
    .4byte DungeonHeadline
    .4byte DungeonText
    .4byte TypeHeadline
    .4byte TypeText
    .4byte LinkedEntryHeadline1
    .4byte LinkedEntryText1
    .4byte LinkedEntryHeadline2
    .4byte LinkedEntryText2
    .4byte LinkedEntryHeadline3
    .4byte LinkedEntryText3
    .4byte PollHeadline
    .4byte PollText
    .4byte WondersHeadline
    .4byte WondersText
    .4byte TeamMoveHeadline
    .4byte TeamMoveText
    .4byte AddMembersHeadline
    .4byte AddMembersText
    .4byte MoveTipsHeadline
    .4byte MoveTipsText
    .4byte GummiHeadline
    .4byte GummiText
    .4byte UltimateHeadline
    .4byte UltimateText
    .4byte MachineHeadline
    .4byte MachineText
    .4byte MakuhitaHeadline
    .4byte MakuhitaText
    .4byte TrapTileHeadline
    .4byte TrapTileText
    .4byte IQHeadline
    .4byte IQText
    .4byte RangeHeadline
    .4byte RangeText
    .4byte SweetHeadline
    .4byte SweetText
    .4byte KeyHeadline
    .4byte KeyText
    .4byte AzurillHeadline
    .4byte AzurillText
    .4byte WeatherHeadline1
    .4byte WeatherText1
    .4byte PechaHeadline
    .4byte PechaText
    .4byte WobbuffetHeadline
    .4byte WobbuffetText
    .4byte WeatherHeadline2
    .4byte WeatherText2
    .4byte KecleonHeadline
    .4byte KecleonText
    .4byte SwitchHeadline
    .4byte SwitchText
    .4byte KeyItemHeadline1
    .4byte KeyItemText1
    .4byte KeyItemHeadline2
    .4byte KeyItemText2
    .4byte GasHeadline
    .4byte GasText
    .4byte CastformHeadline
    .4byte CastformText
    .4byte SmeargleHeadline
    .4byte SmeargleText
    .4byte KabutoHeadline
    .4byte KabutoText
    .4byte ChanseyHeadline
    .4byte ChanseyText
    .4byte ClubHeadline
    .4byte ClubText
    .4byte RawstHeadline
    .4byte RawstText
    .4byte VileplumeHeadline
    .4byte VileplumeText
    .4byte SeaRescueHeadline
    .4byte SeaRescueText
    .4byte PitfallHeadline
    .4byte PitfallText
    .4byte SlakothHeadline
    .4byte SlakothText
    .4byte LinkedProHeadline1
    .4byte LinkedProText1
    .4byte LinkedProHeadline2
    .4byte LinkedProText2
    .4byte PelipperHeadline
    .4byte PelipperText
    .4byte NewsHeadline1
    .4byte NewsText1
    .4byte NewsHeadline2
    .4byte NewsText2
    .4byte BuriedRelicHeadline
    .4byte BuriedRelicText
    .4byte LucarioRankHeadline
    .4byte LucarioRankText
    .4byte NewFriendAreasHeadline
    .4byte NewFriendAreasText

    .global NewFriendAreasText
    NewFriendAreasText:
    .string "The Wigglytuff Club has added new Friend\n"
    .string "Areas for sale!\n"
    .string "Rescue Teams are urged to check with\n"
    .string "Wigglytuff for what is available.\n"
    .string "By adding to your Friend Areas~2c you can\n"
    .string "recruit Pokémon that wouldn~27t join your\n"
    .string "rescue team before!\0"
    .align 2,0

    .global NewFriendAreasHeadline
    NewFriendAreasHeadline:
    .string "New Friend Areas!\0"
    .align 2,0

    .global LucarioRankText
    LucarioRankText:
    .string "Congratulations! Your team has attained\n"
    .string "the Lucario Rank--the top rank among\n"
    .string "rescue teams! In commemoration of your\n"
    .string "fantastic achievement~2c we award you the\n"
    .string "Lucario Statue~2c crafted after the legendary\n"
    .string "rescue team leader.\n"
    .string "Keep working for world peace!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global LucarioRankHeadline
    LucarioRankHeadline:
    .string "Congratulations - Lucario Rank!\0"

    .global BuriedRelicText
    BuriedRelicText:
    .string "#+#C6Mystery Ruin Found Underground!#R\n"
    .string "Its site had been hidden by the crater of a\n"
    .string "meteor strike in ancient times. The Buried\n"
    .string "Relic is thought to date back beyond\n"
    .string "recorded history. There are rumors of\n"
    .string "treasures... And perhaps even Pokémon\n"
    .string "that lived in ancient times. The Buried\n"
    .string "Relic is the main topic in Pokémon Square.\0"
    .align 2,0

    .global BuriedRelicHeadline
    BuriedRelicHeadline:
    .string "Buried Relic Discovered!\0"
    .align 2,0

    .global NewsText2
    NewsText2:
    .string "#+#C5$m0 Innocent! Part 2#R\n"
    .string "#C4Quote from Charizard on the scene:#R\n"
    .string "~93That~27s what I thought right from\n"
    .string "the start~2c hahaha!~94\n"
    .string "#C4Quote from Tyranitar on the scene:#R\n"
    .string "~93That muckraking Gengar...\n"
    .string "He~27s not getting away with this!\n"
    .string "He~27d better be ready for it!~94\0"
    .align 2,0

    .global NewsHeadline2
    NewsHeadline2:
    .string "Pokémon News Extra 2\0"
    .align 2,0

    .global NewsText1
    NewsText1:
    .string "#+#C5$m0 Innocent! Part 1#R\n"
    .string "$m1 met with Ninetales on #C2Mt. Freeze#R.\n"
    .string "Ninetales testified that $m0 was\n"
    .string "not the human that appeared in the legend.\n"
    .string "As a result~2c Gengar~27s claims were found to\n"
    .string "be malicious lies.\n"
    .string "#C4The clearly dismayed Gengar~27s quote:#R\n"
    .string "~93Ugegegegegegegegegegegeh!~94\0"
    .align 2,0

    .global NewsHeadline1
    NewsHeadline1:
    .string "Pokémon News Extra 1\0"
    .align 2,0

    .global PelipperText
    PelipperText:
    .string "Yo! Amigo! It~27s awesome you~27re back!\n"
    .string "I~27ll be delivering mail to you again!\n"
    .string "I~27ve been looking forward to this with\n"
    .string "my bill outstretched!\n"
    .string "I~27ll deliver tons of mail~2c so you~27d better\n"
    .string "be ready~2c amigo!\n\n"
    .string " - The wandering postal carrier~2c Pelipper -\0"
    .align 2,0

    .global PelipperHeadline
    PelipperHeadline:
    .string "A Letter from Pelipper\0"
    .align 2,0

    .global LinkedProText2
    LinkedProText2:
    .string "#+#C6Try These Linked Moves to KO Foes!#R\n\n"
    .string "Psyduck\n"
    .string "#C4Confusion#R + #C4Disable#R\n"
    .string "Totodile\n"
    .string "#C4Bite#R + #C4Scary Face#R\n"
    .string "Cyndaquil\n"
    .string "#C4Flame Wheel#R + #C4Smokescreen#R#P"
    .string "Pikachu\n"
    .string "#C4Thunderbolt#R + #C4Double Team#R\n"
    .string "Skitty\n"
    .string "#C4Tail Whip#R + #C4Doubleslap#R\0"
    .align 2,0

    .global LinkedProHeadline2
    LinkedProHeadline2:
    .string "#50 Linked Moves Pro Level 2\0"
    .align 2,0

    .global LinkedProText1
    LinkedProText1:
    .string "#+#C6These Linked Move Combinations#R\n"
    .string "#+#C6Can Be Devastating!#R\n\n"
    .string "Bulbasaur\n"
    .string "#C4Razor Leaf#R + #C4Sleep Powder#R\n"
    .string "Chikorita\n"
    .string "#C4Body Slam#R + #C4Reflect#R#P"
    .string "Treecko\n"
    .string "#C4Screech#R + #C4Pound#R\n"
    .string "Machop\n"
    .string "#C4Focus Energy#R + #C4Karate Chop#R\n"
    .string "Cubone\n"
    .string "#C4Tail Whip#R + #C4Bonemerang#R\0"
    .align 2,0

    .global LinkedProHeadline1
    LinkedProHeadline1:
    .string "#49 Linked Moves Pro Level 1\0"
    .align 2,0

    .global SlakothText
    SlakothText:
    .string "#+#C6Relief for Delicate Souls Who Can~27t#R\n"
    .string "#+#C6Sleep with Different Pillows!#R\n"
    .string "Insomniacs rejoiced over the announcement\n"
    .string "of the Slakoth Pillow~2c which is said to\n"
    .string "induce sleepiness just by seeing it.\n"
    .string "Already the inventor is swamped with\n"
    .string "inquiries from all over. However~2c\n"
    .string "production is said to be not yet ready.\0"
    .align 2,0

    .global SlakothHeadline
    SlakothHeadline:
    .string "#48 Slakoth Pillows for Insomnia!\0"
    .align 2,0

    .global PitfallText
    PitfallText:
    .string "As a result of the natural disasters~2c\n"
    .string "there have been many reports of Pitfall\n"
    .string "Traps appearing in dungeons.\n"
    .string "However~2c there also appear to be pitfalls\n"
    .string "made by Pokémon that are not harmful.\n"
    .string "The latter are thought to be made by\n"
    .string "foraging Swinub. Some even turn out to\n"
    .string "be hot springs that erupt occasionally.\0"
    .align 2,0

    .global PitfallHeadline
    PitfallHeadline:
    .string "#47 Beware of Pitfalls\0"
    .align 2,0

    .global SeaRescueText
    SeaRescueText:
    .string "A high-seas rescue in the #C2Stormy Sea#R by\n"
    .string "#C5Team Sea Dragons#R ended yesterday with\n"
    .string "the successful recovery of Tentacool.\n"
    .string "The client~2c Corsola~2c is said to be delighted\n"
    .string "by the outcome.\n"
    .string "Tentacool stated~2c ~93I didn~27t realize how far\n"
    .string "I~27d been washed out to sea.~94\n"
    .string "The #C2Stormy Sea#R is unforgiving!\0"
    .align 2,0

    .global SeaRescueHeadline
    SeaRescueHeadline:
    .string "#46 Sea Rescue a Success!\0"
    .align 2,0

    .global VileplumeText
    VileplumeText:
    .string "Vileplume are widely recognized for \n"
    .string "their massive flower. However~2c few dare\n"
    .string "to approach Vileplume because they\n"
    .string "scatter clouds of allergy-inducing\n"
    .string "pollen. Vileplume complain that they tire\n"
    .string "very easily because the flower~27s weight\n"
    .string "makes their head heavy.\0"
    .align 2,0

    .global VileplumeHeadline
    VileplumeHeadline:
    .string "#45 Vileplume~27s Weighty Problem\0"
    .align 2,0

    .global RawstText
    RawstText:
    .string "Research has revealed that #C4Rawst Berries#R\n"
    .string "found in dungeons are usually unripened\n"
    .string "and colored green. When ripe~2c they turn a\n"
    .string "sky blue color. An unripened one is easier\n"
    .string "to eat~2c however~2c because it has not yet\n"
    .string "turned bitter. It is known to heal all\n"
    .string "burns.\0"
    .align 2,0

    .global RawstHeadline
    RawstHeadline:
    .string "#44 Rawst Berry~27s Effect\0"
    .align 2,0

    .global ClubText
    ClubText:
    .string "We proudly announce the foundation of\n"
    .string "the Red & Blue Fan Club~2c an organization\n"
    .string "for supporting Pokémon rescue teams.\n"
    .string "We are currently recruiting new members.\n"
    .string "Won~27t you join and throw your support\n"
    .string "behind our hard-working rescue heroes?\n\n"
    .string "  - Plusle and Minun -\0"
    .align 2,0

    .global ClubHeadline
    ClubHeadline:
    .string "#43 Fan Club Seeks Members!\0"
    .align 2,0

    .global ChanseyText
    ChanseyText:
    .string "As a special treat~2c I~27ll share a simple\n"
    .string "way to tell fortunes with you!\n"
    .string "The key is the first thing you find in the\n"
    .string "day~27s first dungeon.\n"
    .string "If it~27s money~2c you~27ll be sure to make more.\n"
    .string "If it~27s a Berry~2c your health luck is good.\n"
    .string "If it~27s an Apple~2c you~27re super lucky!\n"
    .string "  - Chansey -\0"
    .align 2,0

    .global ChanseyHeadline
    ChanseyHeadline:
    .string "#42 Chansey~27s Fortune-Telling\0"
    .align 2,0

    .global KabutoText
    KabutoText:
    .string "One of our oldest residents claims to feel\n"
    .string "rejuvenated. Kabuto reportedly had an\n"
    .string "encounter with Relicanth in which both\n"
    .string "parties reminisced about the ~93old days.~94\n"
    .string "However~2c even Kabuto could not keep up\n"
    .string "with Relicanth~27s tales from a hundred\n"
    .string "million years ago. Kabuto stated~2c ~93It\n"
    .string "made me feel young talking to Relicanth.~94\0"
    .align 2,0

    .global KabutoHeadline
    KabutoHeadline:
    .string "#41 Kabuto Feels Young Again!\0"
    .align 2,0

    .global SmeargleText
    SmeargleText:
    .string "Smeargle~2c the artist known for his unique\n"
    .string "artistic vision~2c had a windfall day as one\n"
    .string "of his paintings was auctioned for 300\n"
    .string "million "
    .byte 0x83, 0xbf, 0x83, 0xc4, 0x20 @ POKE
    .string "yesterday. The auctioned\n"
    .string "artwork was one of Smeargle~27s signature\n"
    .string "works from early in his career.\0"
    .align 2,0

    .global SmeargleHeadline
    SmeargleHeadline:
    .string "#40 Smeargle Painting Auctioned!\0"
    .align 2,0

    .global CastformText
    CastformText:
    .string "Today~2c the weather over Pokémon\n"
    .string "Square promises to be clear with no\n"
    .string "chance of showers.\n"
    .string "Other regions can expect showers followed\n"
    .string "by clouds. There may be sun breaks\n"
    .string "depending on the day~27s moods.\0"
    .align 2,0

    .global CastformHeadline
    CastformHeadline:
    .string "#39 Castform~27s Daily Weather\0"
    .align 2,0

    .global GasText
    GasText:
    .string "Reports of a noxious gas leak caused\n"
    .string "widespread chaos in the #CDSinister Woods#R.\n"
    .string "Specialists speculate that the recent\n"
    .string "natural disasters are to blame. However~2c\n"
    .string "some also blame #C5Team Koffing#R~27s training\n"
    .string "in the area for the foul-smelling gas.\n"
    .string "The answer~2c apparently~2c is blowing in the\n"
    .string "wind.\0"
    .align 2,0

    .global GasHeadline
    GasHeadline:
    .string "#38 Noxious Gas Leak?!\0"
    .align 2,0

    .global KeyItemText2
    KeyItemText2:
    .string "#+#C6When Used Somewhere Special...#R\n"
    .string "Eevee and Water Stone~2c Fire Stone~2c\n"
    .string "Thunderstone~2c or...\n"
    .string "Exeggcute and Leaf Stone...\n"
    .string "Onix~2c Metal Coat~2c and Link Cable...\n"
    .string "There appear to be many others!\0"
    .align 2,0
    
    .global KeyItemHeadline2
    KeyItemHeadline2:
    .string "#37 Key Items for Pokémon 2\0"
    .align 2,0
    
    .global KeyItemText1
    KeyItemText1:
    .string "#+#C6When Used Somewhere Special...#R\n"
    .string "Sunkern and Sun Stone...\n"
    .string "Skitty and Moon Stone...\n"
    .string "Growlithe and Fire Stone...\n"
    .string "Shellder and Water Stone...\n"
    .string "Clamperl and Deepseatooth...\n"
    .string "There appear to be many others!\0"
    .align 2,0
    
    .global KeyItemHeadline1
    KeyItemHeadline1:
    .string "#36 Key Items for Pokémon 1\0"
    .align 2,0
    
    .global SwitchText
    SwitchText:
    .string "#+#C6Power Up Combination Attacks!#R\n"
    .string "Some dungeons allow rescue teams to\n"
    .string "switch leaders on the spot for doing\n"
    .string "combination attacks and so on.\n"
    .string "When you enter a dungeon~2c open the menu~2c\n"
    .string "choose the Pokémon you want as the\n"
    .string "leader under #C6Team#R~2c then select the\n"
    .string "command #C6Leader#R.\0"
    .align 2,0
    
    .global SwitchHeadline
    SwitchHeadline:
    .string "#35 Switching Leaders\0"
    .align 2,0
    
    .global KecleonText
    KecleonText:
    .string "There have been numerous reports that\n"
    .string "the older of the Kecleon merchants in\n"
    .string "Pokémon Square occasionally goes\n"
    .string "missing. Some residents claim~2c ~93He~27s\n"
    .string "greedy. He must be off doing business\n"
    .string "somewhere.~94 His younger brother denies\n"
    .string "such claims: ~93He wouldn~27t get free items\n"
    .string "in dungeons and try to sell them...~94\0"
    .align 2,0
    
    .global KecleonHeadline
    KecleonHeadline:
    .string "#34 Where Is Kecleon?\0"
    .align 2,0
    
    .global WeatherText2
    WeatherText2:
    .string "Clear: Pleasant weather.\n"
    .string "Hail: Regularly inflicts damage~2c\n"
    .string "except on the Ice type.\n"
    .string "Fog: Turns the status of all Pokémon on\n"
    .string "the floor to Mud Sport.\n"
    .string "Blizzard: Boosts the movement speed of\n"
    .string "Ice-type Pokémon by one level.\0"
    .align 2,0
    
    .global WeatherHeadline2
    WeatherHeadline2:
    .string "#33 Dungeons and Weather 2\0"
    .align 2,0
    
    .global WobbuffetText
    WobbuffetText:
    .string "Earlier today~2c Wobbuffet reportedly\n"
    .string "wobbled the wrong way and wandered off.\n"
    .string "It had to be rescued by the famous\n"
    .string "#C5Team Hydro#R.\n"
    .string "Fortunately~2c the wayward wanderer\n"
    .string "Wobbuffet was only wobbly and otherwise\n"
    .string "unharmed.\0"
    .align 2,0
    
    .global WobbuffetHeadline
    WobbuffetHeadline:
    .string "#32 Wobbly Wobbuffet Wanders!\0"
    .align 2,0
    
    .global PechaText
    PechaText:
    .string "Among rescue teams~2c there is growing\n"
    .string "demand for equipment that is not only\n"
    .string "practical~2c but also fashionably appealing.\n"
    .string "The pink #C4Pecha Scarf#R is especially popular.\n"
    .string "Even the #C5Kecleon Shop#R is having trouble\n"
    .string "keeping it in stock.\n"
    .string "If you~27re lucky enough to spot one~2c make a\n"
    .string "beeline for it!\0"
    .align 2,0
    
    .global PechaHeadline
    PechaHeadline:
    .string "#31 Pecha Scarf--Top Popularity!\0"
    .align 2,0

    .global WeatherText1
    WeatherText1:
    .string "Sunny: Boosts Fire-type moves~2c and\n"
    .string "weakens Water-type moves.\n"
    .string "Sandstorm: Regularly inflicts damage\n"
    .string "except on Ground~2c Rock~2c and Steel types.\n"
    .string "Cloudy: All moves and attacks~2c excluding\n"
    .string "the Normal type~2c are weakened.\n"
    .string "Rain: Boosts Water-type moves~2c and\n"
    .string "weakens Fire. Prevents explosions.\0"
    .align 2,0
    
    .global WeatherHeadline1
    WeatherHeadline1:
    .string "#30 Dungeons and Weather 1\0"
    .align 2,0
    
    .global AzurillText
    AzurillText:
    .string "With a simple act of courage~2c Azurill\n"
    .string "became a hero despite being small in size.\n"
    .string "Azurill came across Slowpoke~2c who had\n"
    .string "fallen into a pond. Our hero~27s tail~2c thrown\n"
    .string "at the struggling Slowpoke~2c saved a sure\n"
    .string "drowning! Slowpoke claimed to have\n"
    .string "entirely forgotten having the ability to\n"
    .string "swim capably.\0"
    .align 2,0
    
    .global AzurillHeadline
    AzurillHeadline:
    .string "#29 Azurill--the Little Hero!\0"
    .align 2,0
    
    .global KeyText
    KeyText:
    .string "#+#C6Head Out to the Desert Region!#R\n"
    .string "If you~27ve been wondering what lies behind\n"
    .string "the mysterious locked doors of the #CDSolar\n"
    .string "Cave#R~2c there~27s been a breakthrough!\n"
    .string "Reports indicate the door keys are easily\n"
    .string "found in the #CDDesert Region#R. Explorers are\n"
    .string "advised to compose teams with Pokémon\n"
    .string "adapted to the desert environment.\0"
    .align 2,0
    
    .global KeyHeadline
    KeyHeadline:
    .string "#28 The Key\0"
    .align 2,0
    
    .global SweetText
    SweetText:
    .string "#+#C6Feel a Little Envious?#R\n"
    .string "Teddiursa is often seen licking its paws\n"
    .string "that have soaked up sweet honey. While it\n"
    .string "may be sticky shaking paws with\n"
    .string "Teddiursa~2c one can~27t help but feel a\n"
    .string "twinge of envy.\0"
    .align 2,0
    
    .global SweetHeadline
    SweetHeadline:
    .string "#27 Sweet Hands!\0"
    .align 2,0
    
    .global RangeText
    RangeText:
    .string "#+#C6All Moves Have Effective Ranges#R\n"
    .string "Moves that affect an entire room have a\n"
    .string "range of two tiles in a corridor. The move\n"
    .string "#C4Growl#R~2c which lowers the Attack stat of\n"
    .string "foes in a room~2c will reach two tiles away\n"
    .string "in a corridor~2c for example. If~2c however~2c\n"
    .string "the visibility is limited to just one tile~2c\n"
    .string "the range of moves will also be limited.\0"
    .align 2,0

    .global RangeHeadline
    RangeHeadline:
    .string "#26 The Range of Moves\0"
    .align 2,0

    .global IQText
    IQText:
    .string "#+#C6Make Your Explorations Easier by#R\n"
    .string "#+#C6Boosting the IQ of Team Members!#R\n"
    .string "Eating Gummis boosts the IQ of Pokémon.\n"
    .string "Upon reaching certain IQ levels~2c a Pokémon\n"
    .string "learns IQ Skills that can be very helpful\n"
    .string "(for example~2c learning to seek out foes\n"
    .string "with type disadvantages). Check\n"
    .string "the IQ Skills of your team members!\0"
    .align 2,0

    .global IQHeadline
    IQHeadline:
    .string "#25 IQ\0"
    .align 2,0

    .global TrapTileText
    TrapTileText:
    .string "#+#C6New Types of Floor Tiles?#R\n"
    .string "There have been numerous reports of new\n"
    .string "floor tiles other than Wonder Tiles.\n"
    .string "Believed to have been made by the recent\n"
    .string "natural disasters~2c these floor tiles remain\n"
    .string "hidden until they are stepped on. They then\n"
    .string "trigger a variety of traps. Rescue teams\n"
    .string "are urged to use extreme caution.\0"
    .align 2,0

    .global TrapTileHeadline
    TrapTileHeadline:
    .string "#24 New Floor Tiles?\0"
    .align 2,0

    .global MakuhitaText
    MakuhitaText:
    .string "#+#C6Study Type Matchups#R\n"
    .string "#+#C6at the Makuhita Dojo!#R\n"
    .string "At the Makuhita Dojo~2c one can learn how\n"
    .string "Pokémon type matchups affect battles.\n"
    .string "It~27s because the dojo~27s training rooms are\n"
    .string "divided by type. For example~2c in the #CDFire\n"
    .string "Maze#R~2c there are only Fire-type Pokémon.\n"
    .string "Try move types to see what works best!\0"
    .align 2,0

    .global MakuhitaHeadline
    MakuhitaHeadline:
    .string "#23 Train at the Makuhita Dojo!\0"
    .align 2,0

    .global MachineText
    MachineText:
    .string "#+#C6New Types of Machines Discovered?#R\n"
    .string "In a recently discovered cave~2c explorers\n"
    .string "found unique types of Technical Machines.\n"
    .string "They apparently do not break after a single\n"
    .string "use. Further studies are said to be under\n"
    .string "consideration by the authorities.\n"
    .string "In related news~2c the cave is to be named\n"
    .string "the #CDSolar Cave#R.\0"
    .align 2,0

    .global MachineHeadline
    MachineHeadline:
    .string "#22 New Types of Machines?\0"
    .align 2,0

    .global UltimateText
    UltimateText:
    .string "#+#C6The Ultimate Dungeon#R\n"
    .string "#+#C6Challenges You to Do Your Best!#R\n"
    .string "Somewhere in the world~2c there supposedly\n"
    .string "is an incredibly tough dungeon. One must\n"
    .string "enter alone at Level 1~2c and without any\n"
    .string "items. No one has ever completed the\n"
    .string "challenge. It is considered a test not of\n"
    .string "power~2c but of intelligence and wits.\0"
    .align 2,0

    .global UltimateHeadline
    UltimateHeadline:
    .string "#21 The Ultimate Dungeon\0"
    .align 2,0

    .global GummiText
    GummiText:
    .string "#+#C6Gummis That Make You Smart#R\n"
    .string "Research has revealed that popular Gummi\n"
    .string "treats not only enhance intelligence~2c they\n"
    .string "also have different effects depending on\n"
    .string "type. Share Gummis with your friends and\n"
    .string "get smarter for your adventures! In\n"
    .string "dungeons~2c throw them at your friends.\n"
    .string "Use them in Friend Areas and...?\0"
    .align 2,0

    .global GummiHeadline
    GummiHeadline:
    .string "#20 Secrets of the Gummi\0"
    .align 2,0

    .global MoveTipsText
    MoveTipsText:
    .string "#+#C6Moving Diagonally#R\n"
    .string "Move diagonally to avoid foes!\n"
    .string "Keeping \204\206 pressed~2c use\n"
    .string "\207R to move diagonally.\n"
    .string "#+#C6Changing Direction#R\n"
    .string "It~27s also very important to change\n"
    .string "directions without moving. Check Hints to\n"
    .string "see how you can do this maneuver!\0"
    .align 2,0

    .global MoveTipsHeadline
    MoveTipsHeadline:
    .string "#19 Important Moving Tips\0"
    .align 2,0

    .global AddMembersText
    AddMembersText:
    .string "If you want to enlarge your rescue team~2c\n"
    .string "you must first get Friend Areas. When\n"
    .string "a Pokémon that can live in an obtained\n"
    .string "Friend Area is defeated~2c it may ask to\n"
    .string "join your rescue team. Add to your\n"
    .string "Friend Areas so you can recruit more\n"
    .string "members! Incidentally~2c you may take no\n"
    .string "more than three friends into a dungeon.\0"
    .align 2,0

    .global AddMembersHeadline
    AddMembersHeadline:
    .string "#18 Adding Team Members\0"
    .align 2,0

    .global TeamMoveText
    TeamMoveText:
    .string "#+#C6Use Team Members Effectively!#R\n"
    .string "When you~27re fighting in a dungeon~2c it~27s\n"
    .string "important to use your team members. If\n"
    .string "attacked from the side~2c move horizontally.\n"
    .string "If attacked from above or below~2c move\n"
    .string "vertically. That way~2c you can have several\n"
    .string "Pokémon fighting a single foe. Change\n"
    .string "Tactics if members don~27t move properly.\0"
    .align 2,0

    .global TeamMoveHeadline
    TeamMoveHeadline:
    .string "#17 Moving as a Team\0"
    .align 2,0

    .global WondersText
    WondersText:
    .string "#+#C6The Seven Wonders of Pokémon?#R\n"
    .string "The mysterious feet of Diglett.\n"
    .string "What is inside Forretress~27s shell.\n"
    .string "The intelligence of Girafarig~27s tail.\n"
    .string "Arbok~27s variety of patterns.\n"
    .string "We await submissions from readers on\n"
    .string "other Pokémon mysteries!\n"
    .string "  - Mystery Hunter Team -\0"
    .align 2,0

    .global WondersHeadline
    WondersHeadline:
    .string "#16 Seven Wonders of Pokémon\0"
    .align 2,0

    .global PollText
    PollText:
    .string "#C6First#=2Gravelerock#R\n"
    .string "#C6Second#=2Oran Berry#R\n"
    .string "In a nationwide survey involving rescue\n"
    .string "teams~2c the most popular item was found to\n"
    .string "be #C4Gravelerocks#R. According to Sudowoodo\n"
    .string "of #C5Team Fakers#R~2c ~93It lets you attack\n"
    .string "from far away. It~27s invaluable.~94 The next\n"
    .string "most popular item was #C4Oran Berries#R.\0"
    .align 2,0

    .global PollHeadline
    PollHeadline:
    .string "#15 Poll: Top Two Items\0"
    .align 2,0

    .global LinkedEntryText3
    LinkedEntryText3:
    .string "#+#C6These Are the Final Linked Moves#R\n"
    .string "#+#C6We Recommend in the Entry Level!#R\n"
    .string "#C2Electric and Water Types#R\n"
    .string "Pikachu\n"
    .string "#C4Thundershock#R + #C4Growl#R\n"
    .string "Squirtle\n"
    .string "#C4Tail Whip#R + #C4Tackle#R#PTotodile\n"
    .string "#C4Leer#R + #C4Scratch#R\n"
    .string "Mudkip\n"
    .string "#C4Water Gun#R + #C4Mud-Slap#R\n"
    .string "Psyduck\n"
    .string "#C4Tail Whip#R + #C4Scratch#R\0"
    .align 2,0

    .global LinkedEntryHeadline3
    LinkedEntryHeadline3:
    .string "#14 Linked Moves Entry Level 3\0"
    .align 2,0

    .global LinkedEntryText2
    LinkedEntryText2:
    .string "#C2Fire and Normal Types#R\n"
    .string "Charmander\n"
    .string "#C4Ember#R + #C4Growl#R\n"
    .string "Cyndaquil\n"
    .string "#C4Leer#R + #C4Tackle#R\n"
    .string "Torchic\n"
    .string "#C4Ember#R + #C4Growl#R#PEevee\n"
    .string "#C4Tail Whip#R + #C4Tackle#R\n"
    .string "Meowth\n"
    .string "#C4Scratch#R + #C4Growl#R\n"
    .string "Skitty\n"
    .string "#C4Tail Whip#R + #C4Tackle#R\0"
    .align 2,0

    .global LinkedEntryHeadline2
    LinkedEntryHeadline2:
    .string "#13 Linked Moves Entry Level 2\0"
    .align 2,0

    .global LinkedEntryText1
    LinkedEntryText1:
    .string "#+#C6These Are the Recommended#R\n"
    .string "#+#C6Linked Moves for Beginners!#R\n"
    .string "#C2Grass~2c Fighting~2c and Ground Types#R\n"
    .string "Bulbasaur\n"
    .string "#C4Vine Whip#R + #C4Growl#R\n"
    .string "Chikorita\n"
    .string "#C4Razor Leaf#R + #C4Growl#R#PTreecko\n"
    .string "#C4Leer#R + #C4Pound#R\n"
    .string "Machop\n"
    .string "#C4Leer#R + #C4Low Kick#R\n"
    .string "Cubone\n"
    .string "#C4Tail Whip#R + #C4Bone Club#R\0"
    .align 2,0

    .global LinkedEntryHeadline1
    LinkedEntryHeadline1:
    .string "#12 Linked Moves Entry Level 1\0"
    .align 2,0

    .global TypeText
    TypeText:
    .string "#+#C6Learn How Types Match Up!#R\n"
    .string "All Pokémon are of certain types~2c such as\n"
    .string "#C2Fire#R and #C5Water#R. In a battle~2c the damage\n"
    .string "inflicted depends on how the Pokémon~27s\n"
    .string "type matches up with the move~27s type.\n"
    .string "For example~2c a #C2Fire#R-type Pokémon is\n"
    .string "weak against #C5Water#R-type moves.\n"
    .string "Exploit type matchups to win battles!\0"
    .align 2,0

    .global TypeHeadline
    TypeHeadline:
    .string "#11 Types and Matchups\0"
    .align 2,0

    .global DungeonText
    DungeonText:
    .string "If your rescue team is defeated in a\n"
    .string "dungeon~2c you lose several items and\n"
    .string "all the money you are carrying.\n"
    .string "Beware of what you~27re carrying before\n"
    .string "you go off on a rescue or an outing.\n"
    .string "Use #C5Kangaskhan Storage#R to keep\n"
    .string "invaluable items safely stored.\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global DungeonHeadline
    DungeonHeadline:
    .string "#10 Mysterious Dungeons?\0"
    .align 2,0

    .global WonderText
    WonderText:
    .string "#+#C6Wonder Tiles Reset Attack and Defense!#R\n"
    .string "If your Attack is lowered by a foe~27s\n"
    .string "#C4Growl#R~2c or your Defense is lowered\n"
    .string "by a foe~27s #C4Tail Whip#R~2c for example~2c the\n"
    .string "affected stat can be reset to normal by\n"
    .string "stepping on a Wonder Tile or going to the\n"
    .string "next floor. Beware~2c enhanced stats are\n"
    .string "also reset to normal!\0"
    .align 2,0

    .global WonderHeadline
    WonderHeadline:
    .string "#9 Wonder Tiles\0"
    .align 2,0

    .global MoveText
    MoveText:
    .string "#+#C6The Benefits of Using Moves#R\n"
    .string "If a move is used on a foe~2c when it is\n"
    .string "defeated~2c #C5you earn more Exp. Points#R!\n"
    .string "A move only has to be used once on the\n"
    .string "foe: after that it can be defeated using a\n"
    .string "regular attack to earn more Exp. Points.\n"
    .string "Moves are also more likely to become\n"
    .string "#C5critical hits#R! Don~27t overuse them~2c though!\0"
    .align 2,0

    .global MoveHeadline
    MoveHeadline:
    .string "#8 Let~27s Use Moves!\0"
    .align 2,0

    .global OptionsText
    OptionsText:
    .string "#+#C6Change Your Option Settings#R\n"
    .string "#+#C6to Suit Your Play Style!#R\n"
    .string "Press \207Q to open the menu~2c then\n"
    .string "choose #C6Others#R and #C6Game Options#R.\n"
    .string "You can change settings to suit the way\n"
    .string "you play.\0"
    .align 2,0

    .global OptionsHeadline
    OptionsHeadline:
    .string "#7 Game Options\0"
    .align 2,0

    .global DisasterText
    DisasterText:
    .string "#+#C6Investigations Under Way into#R\n"
    .string "#+#C6Recent Rash of Natural Disasters#R\n"
    .string "Pokémon in affected areas attack any\n"
    .string "outsider without hesitation. Some believe\n"
    .string "a mysterious force is behind their\n"
    .string "behavior. One source blamed Diglett\n"
    .string "for triggering earthquakes~2c but the\n"
    .string "investigative team is skeptical.\0"
    .align 2,0

    .global DisasterHeadline
    DisasterHeadline:
    .string "#6 Recent Natural Disasters\0"
    .align 2,0

    .global SeedText
    SeedText:
    .string "#+#C6Seeds Can Be Thrown~2c Too!#R\n"
    .string "Seeds are usually meant to be eaten.\n"
    .string "But did you know? They can also be thrown\n"
    .string "at other Pokémon to unlock their effects.\n"
    .string "Toss seeds you don~27t want to eat at foes!\n"
    .string "Throw good seeds at friends!\n"
    .string "Don~27t be afraid to throw your seeds!\0"
    .align 2,0

    .global SeedHeadline
    SeedHeadline:
    .string "#5 Throw Seeds!\0"
    .align 2,0

    .global HungerText
    HungerText:
    .string "#+#C6Eat Something When You Get Hungry!#R\n"
    .string "While you~27re exploring a dungeon~2c you will\n"
    .string "get progressively hungry (your Belly goes\n"
    .string "down). If you become famished~2c you will\n"
    .string "eventually lose HP and even faint.\n"
    .string "That~27s why you should eat something to fill\n"
    .string "your Belly! You can always buy food at the\n"
    .string "#C5Kecleon Shop#R.\0"
    .align 2,0

    .global HungerHeadline
    HungerHeadline:
    .string "#4 Getting Hungry\0"
    .align 2,0

    .global JobText
    JobText:
    .string "If you want to go on a rescue job listed\n"
    .string "on the Bulletin Board at the Pelipper Post\n"
    .string "Office~2c or one that~27s delivered to your\n"
    .string "Mailbox~2c you first need to #C6Accept#R the job~2c\n"
    .string "then choose #C6Take Job#R. Only then will you\n"
    .string "be able to handle that job.\n"
    .string "Try to do accepted jobs quickly!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global JobHeadline
    JobHeadline:
    .string "#3 Accepting Rescue Jobs\0"
    .align 2,0
    
    .global BasicsText
    BasicsText:
    .string "#+#C6Saving Your Adventure and Pokémon News#R\n"
    .string "You can save your adventure by going to\n"
    .string "your bed. Get in the habit of saving often.\n"
    .string "You should also store old Pokémon News.\n"
    .string "If your Mailbox is full~2c you won~27t get the\n"
    .string "latest issue of the news or any job mail.\n"
    .string "Check the Mailbox and store old news!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global BasicsHeadline
    BasicsHeadline:
    .string "#2 Rescue Team Basics\0"
    .align 2,0

    .global WelcomeText
    WelcomeText:
    .string "#+#C6To All New Members!#R\n"
    .string "Your badge has the power to send back\n"
    .string "to town any Pokémon you~27ve rescued. Just\n"
    .string "hold the badge up~2c and it does the rest.\n"
    .string "By completing rescue jobs~2c you will be\n"
    .string "awarded points that raise your team~27s\n"
    .string "ranking. Aim for the Bronze Rank for now!\n"
    .string "   - Pokémon Rescue Organization -\0"
    .align 2,0

    .global WelcomeHeadline
    WelcomeHeadline:
    .string "#1 Welcome to a Rescue Team!\0"
    .align 2,0

    .string "pksdir0\0"
