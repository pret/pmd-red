        .section .rodata

        .include "data/data_80EBA18.inc" @ includes Personality Test Questions

	.global gPersonalityQuestionPointerTable
gPersonalityQuestionPointerTable: @ 80F2624 (pointers to each question text)
        .byte 0xD8, 0x00, 0x0F, 0x08
        .byte 0x5C, 0x01, 0x0F, 0x08
        .byte 0xCC, 0x01, 0x0F, 0x08
        .byte 0x74, 0x02, 0x0F, 0x08
        .byte 0x18, 0x03, 0x0F, 0x08
        .byte 0xCC, 0x03, 0x0F, 0x08
        .byte 0xB0, 0x04, 0x0F, 0x08
        .byte 0xA0, 0x05, 0x0F, 0x08
        .byte 0x10, 0x06, 0x0F, 0x08
        .byte 0x44, 0x07, 0x0F, 0x08
        .byte 0x1C, 0x09, 0x0F, 0x08
        .byte 0x2C, 0x0A, 0x0F, 0x08
        .byte 0xBC, 0x0A, 0x0F, 0x08
        .byte 0x20, 0x0B, 0x0F, 0x08
        .byte 0xD0, 0x0B, 0x0F, 0x08
        .byte 0xBC, 0x0C, 0x0F, 0x08
        .byte 0x94, 0x0D, 0x0F, 0x08
        .byte 0xFC, 0x0D, 0x0F, 0x08
        .byte 0x54, 0x0E, 0x0F, 0x08
        .byte 0x3C, 0x0F, 0x0F, 0x08
        .byte 0xE0, 0x0F, 0x0F, 0x08
        .byte 0x48, 0x10, 0x0F, 0x08
        .byte 0xA8, 0x10, 0x0F, 0x08
        .byte 0x10, 0x11, 0x0F, 0x08
        .byte 0xE8, 0x11, 0x0F, 0x08
        .byte 0xF8, 0x12, 0x0F, 0x08
        .byte 0xCC, 0x13, 0x0F, 0x08
        .byte 0xA4, 0x14, 0x0F, 0x08
        .byte 0x5C, 0x15, 0x0F, 0x08
        .byte 0x48, 0x16, 0x0F, 0x08
        .byte 0x24, 0x17, 0x0F, 0x08
        .byte 0xEC, 0x17, 0x0F, 0x08
        .byte 0xCC, 0x18, 0x0F, 0x08
        .byte 0x5C, 0x19, 0x0F, 0x08
        .byte 0xCC, 0x19, 0x0F, 0x08
        .byte 0x38, 0x1A, 0x0F, 0x08
        .byte 0xB4, 0x1A, 0x0F, 0x08
        .byte 0x38, 0x1B, 0x0F, 0x08
        .byte 0xBC, 0x1B, 0x0F, 0x08
        .byte 0x18, 0x1C, 0x0F, 0x08
        .byte 0x70, 0x1C, 0x0F, 0x08
        .byte 0xE0, 0x1C, 0x0F, 0x08
        .byte 0xB0, 0x1D, 0x0F, 0x08
        .byte 0x28, 0x1E, 0x0F, 0x08
        .byte 0x94, 0x1E, 0x0F, 0x08
        .byte 0x04, 0x1F, 0x0F, 0x08
        .byte 0xB8, 0x1F, 0x0F, 0x08
        .byte 0xA0, 0x20, 0x0F, 0x08
        .4byte QuirkyQuest1
        .4byte QuirkyQuest2
        .4byte QuirkyQuest3
        .4byte QuirkyQuest4
        .4byte MiscQuest1
        .4byte MiscQuest2
        .4byte MiscQuest3
        .byte 0xD8, 0x07, 0x0F, 0x08 @ (pointer to Question 2B for Brave)

	.global gNatureQuestionTable
gNatureQuestionTable: @ 80F2704 (Categories??)
        .byte 0x00, 0x00, 0x00, 0x00 @ (Hardy)
        .byte 0x01, 0x01, 0x01, 0x01 @ (Docile)
        .byte 0x02, 0x02, 0x02, 0x02 @ (Brave)
        .byte 0x03, 0x03, 0x03, 0x03 @ (Jolly)
        .byte 0x04, 0x04, 0x04, 0x04 @ (Impish)
        .byte 0x05, 0x05, 0x05, 0x05 @ (Naive)
        .byte 0x06, 0x06, 0x06, 0x06 @ (Timid)
        .byte 0x07, 0x07, 0x07, 0x07 @ (Hasty)
        .byte 0x08, 0x08, 0x08, 0x08 @ (Sassy)
        .byte 0x09, 0x09, 0x09, 0x09 @ (Calm)
        .byte 0x0A, 0x0A, 0x0A, 0x0A @ (Relaxed)
        .byte 0x0B, 0x0B, 0x0B, 0x0B @ (Lonely)
        .byte 0x0C, 0x0C, 0x0C, 0x0C @ (Quirky)
        .byte 0x0D, 0x0D, 0x0D @ (Miscellaneous)
        .byte 0x02 @ (Question 2b for Brave Category)

	.global gGenderText
gGenderText: @ 80F273C
	.asciz "Are you a boy or a girl?"
        .align 2,0
        .byte 0x3C, 0x27, 0x0F, 0x08 @ pointer to above text

	.global gUnknown_80F275C
gUnknown_80F275C: @ 80F275C
        .4byte BoyText @ Pointer to boy text
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte GirlText @ Pointer to girl text
        .byte 0x01, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00 @ end of table
        .byte 0xFF, 0xFF, 0xFF, 0xFF

        .global GirlText
        GirlText:
        .asciz "Girl."
        .align 2,0

        .global BoyText
        BoyText:
        .string "Boy."

        .byte 0x00
        .byte 0x01
        .byte 0x02
        .byte 0x03
        .byte 0x04
        .byte 0x05
        .byte 0x06
        .byte 0x07
        .byte 0x08
        .byte 0x09
        .byte 0x0A
        .byte 0x0B
        .byte 0x0C
        .byte 0x0D

	.global gStarters
gStarters: @ 80F278E
        .byte 0x04, 0x00 @ Charmander (Hardy M)
        .byte 0x19, 0x00 @ Pikachu (Hardy F)
        .byte 0x01, 0x00 @ Bulbasaur (Docile M)
        .byte 0x98, 0x00 @ Chikorita (Docile F)
        .byte 0x42, 0x00 @ Machop (Brave M)
        .byte 0x04, 0x00 @ Charmander (Brave F)
        .byte 0x07, 0x00 @ Squirtle (Jolly M)
        .byte 0x9E, 0x00 @ Totodile (Jolly F)
        .byte 0x19, 0x00 @ Pikachu (Impish M)
        .byte 0x68, 0x00 @ Cubone (Impish F)
        .byte 0x9E, 0x00 @ Totodile (Naive M)
        .byte 0x85, 0x00 @ Eevee (Naive F)
        .byte 0x9B, 0x00 @ Cyndaquil (Timid M)
        .byte 0x1B, 0x01 @ Mudkip (Timid F)
        .byte 0x18, 0x01 @ Torchic (Hasty M)
        .byte 0x45, 0x01 @ Skitty (Hasty F)
        .byte 0x15, 0x01 @ Treecko (Sassy M)
        .byte 0x18, 0x01 @ Torchic (Sassy F)
        .byte 0x1B, 0x01 @ Mudkip (Calm M)
        .byte 0x01, 0x00 @ Bulbasaur (Calm F)
        .byte 0x36, 0x00 @ Psyduck (Relaxed M)
        .byte 0x07, 0x00 @ Squirtle (Relaxed F)
        .byte 0x68, 0x00 @ Cubone (Lonely M)
        .byte 0x36, 0x00 @ Psyduck (Lonely F)
        .byte 0x34, 0x00 @ Meowth (Quirky M)
        .byte 0x15, 0x01 @ Treecko (Quirky F)
        .byte 0x00, 0x00 @ End of table

	.global gStarterReveal
gStarterReveal: @ 80F27C4
        .string "\n"
        .string "#+The Pokémon $m0!"
        .byte 0
        .4byte gStarterReveal

	.global gUnknown_80F27DC
gUnknown_80F27DC: @ 80F27DC
        .string "#+This is the final step.#W\n"
        .string "#+Who would you like to have as a partner?#P" @ #P -> scroll down
        .string "#+Choose the Pokémon you want\n"
        .asciz "#+as your partner from this group."
        .align 2,0
        .4byte gUnknown_80F27DC

	.global gUnknown_80F286C
gUnknown_80F286C: @ 80F286C
        .asciz "#+What is your partner~27s nickname?"
        .align 2,0
        .4byte gUnknown_80F286C

	.global gUnknown_80F2898
gUnknown_80F2898: @ 80F2898
        .string "#+OK! We~27re all set!#P"
        .string "#+Let~27s get you into the\n"
        .string "#+world of Pokémon!#P"
        .asciz "#+Go for it!"
        .align 2,0
        .4byte gUnknown_80F2898

	.global gPersonalityTypeDescriptionTable
gPersonalityTypeDescriptionTable: @ 80F28F4
        .4byte gHardyDescription
        .4byte gDocileDescription
        .4byte gBraveDescription
        .4byte gJollyDescription
        .4byte gImpishDescription
        .4byte gNaiveDescription
        .4byte gTimidDescription
        .4byte gHastyDescription
        .4byte gSassyDescription
        .4byte gCalmDescription
        .4byte gRelaxedDescription
        .4byte gLonelyDescription
        .4byte gQuirkyDescription

        .global gQuirkyDescription
        gQuirkyDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The quirky type.#P"
        .string "#+People consider you an eccentric\n"
        .string "#+who does things at your own pace.#P"
        .string "#+You never break tempo.#P"
        .string "#+Your carefree nature makes you\n"
        .string "#+attractive. But you also happen\n"
        .string "#+to be somewhat childish...#P"
        .string "#+You are fickle and cause problems for the\n"
        .string "#+people who have to go along with you.#P"
        .string "#+Maybe people are even upset\n"
        .string "#+with you for being so fickle?#P"
        .string "#+If you realize how selfishly\n"
        .string "#+you~27re behaving~2c try to think\n"
        .string "#+before you do anything rash.#P"
        .asciz  "#+A quirky person like you should be..."
        .align 2,0

        .global gLonelyDescription
        gLonelyDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The lonely type.#P"
        .string "#+You always act cheerful and\n"
        .string "#+jocular around other people.#P"
        .string "#+But that~27s only because\n"
        .string "#+you are with other people.#P"
        .string "#+However~2c when you get alone...#P"
        .string "#+Do you find yourself\n"
        .string "#+feeling oddly depressed?#P"
        .string "#+That~27s why you always\n"
        .string "#+want to be with others.#P"
        .string "#+But if you go around feeling\n"
        .string "#+depressed too much...#P"
        .string "#+Your nutritional balance goes out\n"
        .string "#+of wack. Eat more vegetables!#P"
        .string "#+However...#W\n"
        .string "#+It~27s not a bad thing\n"
        .string "#+to feel lonely.#P"
        .string "#+You know what it~27s like when you aren~27t\n"
        .string "#+alone~2c so that~27s why you feel lonesome.#P"
        .string "#+And that~27s why you aren~27t really alone.#P"
        .asciz "#+A lonely person like you should be..."
        .align 2,0

        .global gRelaxedDescription
        gRelaxedDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The relaxed type.#P"
        .string "#+Do you occasionally\n"
        .string "#+zone out and miss a bus?#P"
        .string "#+Or do you find yourself dozing off?#P"
        .string "#+Or is your reaction time\n"
        .string "#+a little slower than others?#P"
        .string "#+But that~27s not necessarily\n"
        .string "#+a bad thing.#P"
        .string "#+You can do things at your own\n"
        .string "#+tempo without feeling pressured.#P"
        .string "#+You can live in a relaxed and\n"
        .string "#+unhurried manner without worries.#P"
        .string "#+I think that~27s a happy\n"
        .string "#+lifestyle to be envied~2c even.#P"
        .string "#+You~27re also surprisingly popular.#P"
        .string "#+The way you vacantly stare\n"
        .string "#+off into the distance...#P"
        .string "#+It should make that someone\n"
        .string "#+special~27s pulse race.#P"
        .asciz  "#+A relaxed person like you should be..."
        .align 2,0

        .global gCalmDescription
        gCalmDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The calm type.#P"
        .string "#+You~27re capable of giving advice\n"
        .string "#+to friends with worries.#P"
        .string "#+You don~27t like to fight.#P"
        .string "#+You~27re a warm~2c kindhearted\n"
        .string "#+person who cares.#P"
        .string "#+You must have many friends\n"
        .string "#+who look up to you.#P"
        .string "#+However...#W\n"
        .string "#+You may also be somewhat gullible...#P"
        .string "#+As well as a little careless...#P"
        .string "#+And even a little sloppy.#P"
        .string "#+You might want to keep\n"
        .string "#+those points in mind.#P"
        .asciz  "#+A calm person like you should be..."
        .align 2,0

        .global gSassyDescription
        gSassyDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The sassy type.#P"
        .string "#+You tend to be somewhat cynical.#P"
        .string "#+Despite that~2c there is something\n"
        .string "#+appealing and lovable about you.#P"
        .string "#+But do you occasionally say something\n"
        .string "#+arrogant that angers others?#P"
        .string "#+Do you make that mistake?#P"
        .string "#+Or have people called you\n"
        .string "#+conceited~2c vain~2c or selfish?#P"
        .string "#+Have people said that about you?#P"
        .string "#+Huh?#W You~27re telling me to get lost?#P"
        .string "#+Why~2c you... Come here and say that!#W\n"
        .string "#+......Gasp!#P"
        .string "#+...I~27m sorry.\n"
        .string "#+I let my feelings run away.\n"
        .string "#+I truly regret this~2c really.#P"
        .string "#+Anyway~2c your cool and aloof\n"
        .string "#+attitude is what defines you.#P"
        .string "#+It makes you exasperating and\n"
        .string "#+appealing at the same time.#P"
        .asciz  "#+A sassy person like you should be..."
        .align 2,0

        .global gHastyDescription
        gHastyDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The hasty type.#P"
        .string "#+You like to take charge\n"
        .string "#+and get things done.#P"
        .string "#+You~27re a real go-getter.#P"
        .string "#+But are you also stressed out?#P"
        .string "#+You get irritated when your\n"
        .string "#+friends don~27t show up on time.#P"
        .string "#+You get frustrated when things\n"
        .string "#+don~27t turn out the way you expect.#P"
        .string "#+Maybe you jab the elevator button\n"
        .string "#+if the elevator is slow to arrive.#P"
        .string "#+...Maybe you~27re already jabbing\n"
        .string "#+the A Button repeatedly now.#P"
        .string "#+Beware--getting too easily irritated\n"
        .string "#+just isn~27t good for your well-being.#P"
        .asciz  "#+A hasty person like you should be..."
        .align 2,0

        .global gTimidDescription
        gTimidDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The timid type.#P"
        .string "#+You may find it hard to go\n"
        .string "#+to the washroom at night.#P"
        .string "#+You may also find it too frightening\n"
        .string "#+to go back to school to get something\n"
        .string "#+you left behind in class.#P"
        .string "#+If you~27re ever walking on a dark\n"
        .string "#+street at night~2c you probably turn\n"
        .string "#+around often to check behind you.#P"
        .string "#+But your timid nature is\n"
        .string "#+also your good point!#P"
        .string "#+Because those who know fear are\n"
        .string "#+those who know true courage.#P"
        .asciz  "#+A timid person like you should be..."
        .align 2,0

        .global gNaiveDescription
        gNaiveDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The naive type.#P"
        .string "#+You are highly curious~2c\n"
        .string "#+and you love rare things.#P"
        .string "#+Your cheerful and carefree\n"
        .string "#+attitude should make things fun\n"
        .string "#+for the people around you.#P"
        .string "#+But you do have one flaw.\n"
        .string "#+You can be childish.#P"
        .string "#+You can never sit still.\n"
        .string "#+You~27re always on the move.#P"
        .string "#+You can also be selfish~2c\n"
        .string "#+so you should watch yourself.#P"
        .asciz  "#+A naive person like you should be..."
        .align 2,0

        .global gImpishDescription
        gImpishDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The impish type.#P"
        .string "#+You~27re playful~2c cheerful~2c\n"
        .string "#+and you love pranks.#P"
        .string "#+You~27re also kindhearted.#P"
        .string "#+That~27s why the people around\n"
        .string "#+you find you so irresistible.#P"
        .string "#+You must be the most\n"
        .string "#+popular person around!#P"
        .string "#+Oh?#W You~27re not that popular?#W\n"
        .string "#+You~27re either being modest...\n"
        .string "#+or you just don~27t notice it.#P"
        .string "#+I bet people are just too shy\n"
        .string "#+to let their feelings be known.#P"
        .string "#+There~27s someone out there who~27s\n"
        .string "#+afraid to declare their love for you!#P"
        .asciz "#+An impish person like you should be..."
        .align 2,0

        .global gJollyDescription
        gJollyDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The jolly type.#P"
        .string "#+Always laughing and smiling~2c\n"
        .string "#+you uplift everyone around you.#P"
        .string "#+You love jokes!#P"
        .string "#+You have lots of friends~2c and\n"
        .string "#+you~27re popular wherever you go.#P"
        .string "#+But sometimes you get carried away\n"
        .string "#+and say things that get you in trouble.#P"
        .string "#+You should learn to think before\n"
        .string "#+saying or doing anything.#P"
        .asciz "#+A jolly person like you should be..."
        .align 2,0

        .global gBraveDescription
        gBraveDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The brave type.#P"
        .string "#+You have a strong sense of justice.#W\n"
        .string "#+You hate evil.#W\n"
        .string "#+You will take on any opponent.#P"
        .string "#+You are truly a hero!#P"
        .string "#+Go forth!#P"
        .string "#+For justice...#W\n"
        .string "#+For peace on earth...#W\n"
        .string "#+Fight the forces of evil!#P"
        .string "#+......#WIf I~27m wrong...#W\n"
        .string "#+Work at becoming a true hero!#P"
        .asciz "#+A brave person like you should be..."
        .align 2,0

        .global gDocileDescription
        gDocileDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The docile type.#P"
        .string "#+You~27re very kindhearted.#W\n"
        .string "#+Very helpful.#W\n"
        .string "#+You can make friends with anyone.#P"
        .string "#+You~27re a wonderful person.#P"
        .string "#+......#WIs that going overboard?#W\n"
        .string "#+I don~27t think so.#P"
        .string "#+You yourself should be\n"
        .string "#+the best judge of that.#P"
        .asciz "#+A docile person like you should be..."
        .align 2,0

        .global gHardyDescription
        gHardyDescription:
        .string "#+You appear to be...#W\n"
        .string "#+The hardy type.#P"
        .string "#+You do your homework diligently~2c\n"
        .string "#+and you know to eat properly.#P"
        .string "#+You have strong willpower that lets\n"
        .string "#+you complete tasks~2c however tough.#P"
        .string "#+But~2c you can also be stubborn to the\n"
        .string "#+point of even feuding with friends...#P"
        .string "#+Nothing will go right for you when you~27re\n"
        .string "#+irritated~2c so learn to laugh it off.#P"
        .string "#+A hardy person like you should be..."
        .align 2,0
