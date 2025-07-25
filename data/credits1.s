	.section .rodata





@ Actual Start of Credits
        .global Credits_StaffCredits
        Credits_StaffCredits:
        .byte 0x01, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte StaffCredits_80E4AD8
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global StaffCredits_80E4AD8
        StaffCredits_80E4AD8:
        .string "{CENTER_ALIGN}"
        .byte 0x82, 0xa0
        .string "STAFF CREDITS"
        .byte 0x82, 0xa2, 0x00

        .global Credits_Producer
        Credits_Producer:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte Producer_80E4B20
        .byte 0x02, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte KoichiNakamura
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global KoichiNakamura
        KoichiNakamura:
        .string "Koichi Nakamura\0"
        .align 2,0
        .global Producer_80E4B20
        Producer_80E4B20:
        .byte 0x82, 0xa0
        .string "PRODUCER"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00, 0x00

        .global Credits_Director
        Credits_Director:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte Director_80E4B68
        .byte 0x02, 0x00, 0x1e, 0x00
        .byte 0x3c, 0x00, 0x00, 0x00
        .4byte SeeichiroNagahata
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .global SeeichiroNagahata
        SeeichiroNagahata:
        .string "Seiichiro Nagahata\0"
        .align 2,0
        .global Director_80E4B68
        Director_80E4B68:
        .byte 0x82, 0xa0
        .string "DIRECTOR"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00, 0x00

        .global Credits_Scenario
        Credits_Scenario:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x28, 0x00, 0x00, 0x00
        .4byte Scenario_80EB4CC
        .byte 0x02, 0x00, 0x1e, 0x00, 0x37, 0x00, 0x00, 0x00
        .4byte ShinichiroTomie
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte EmikoTanaka
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global EmikoTanaka
        EmikoTanaka:
        .string "Emiko Tanaka\0"
        .align 2,0
        .global ShinichiroTomie
        ShinichiroTomie:
        .string "Shin-ichiro Tomie\0"
        .align 2,0
        .global Scenario_80EB4CC
        Scenario_80EB4CC:
        .byte 0x82, 0xa0
        .string "SCENARIO"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00, 0x00

        .global Credits_GamePlanning
        Credits_GamePlanning:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x23, 0x00, 0x00, 0x00
        .4byte GamePlanning_80E4C48
        .byte 0x02, 0x00, 0x1e, 0x00, 0x32, 0x00, 0x00, 0x00
        .4byte KunimiKawamura
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte ShonosukeMorisue
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte JiroIshii
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global JiroIshii
        JiroIshii:
        .string "Jiro Ishii\0"
        .align 2,0
        .global ShonosukeMorisue
        ShonosukeMorisue:
        .string "Shonosuke Morisue\0"
        .align 2,0
        .global KunimiKawamura
        KunimiKawamura:
        .string "Kunimi Kawamura\0"
        .align 2,0

        .global GamePlanning_80E4C48
        GamePlanning_80E4C48:
        .byte 0x82, 0xa0
        .string "GAME PLANNING"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00

        .global Credits_Programming
        Credits_Programming:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte MainProgramming_80E4D04
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte MasayasuYamamoto
        .byte 0x01, 0x00, 0x0a, 0x00, 0x32, 0x00, 0x00, 0x00
        .4byte Programming_80E4CE0
        .byte 0x02, 0x00, 0x1e, 0x00, 0x41, 0x00, 0x00, 0x00
        .4byte YujiFukuda
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte HironoriIshigami
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte NobuoMorioka
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global NobuoMorioka
        NobuoMorioka:
        .string "Nobuo Morioka\0"
        .align 2,0
        .global HironoriIshigami
        HironoriIshigami:
        .string "Hironori Ishigami\0"
        .align 2,0
        .global YujiFukuda
        YujiFukuda:
        .string "Yuji Fukuda\0"
        .align 2,0

        .global Programming_80E4CE0
        Programming_80E4CE0:
        .byte 0x82, 0xa0
        .string "PROGRAMMING"
        .byte 0x82, 0xa2, 0x00

        .global MasayasuYamamoto
        MasayasuYamamoto:
        .string "Masayasu Yamamoto\0"
        .align 2,0

        .global MainProgramming_80E4D04
        MainProgramming_80E4D04:
        .byte 0x82, 0xa0
        .string "MAIN PROGRAMMING"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00, 0x00

        .global Credits_GraphicsDirectorBGIllus
        Credits_GraphicsDirectorBGIllus:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x23, 0x00, 0x00, 0x00
        .4byte GraphicDirector_80E4D90
        .byte 0x02, 0x00, 0x1e, 0x00, 0x32, 0x00, 0x00, 0x00
        .4byte FuyuhikoKoizumi
        .byte 0x01, 0x00, 0x0a, 0x00, 0x46, 0x00, 0x00, 0x00
        .4byte BGIllustration_80E4D68
        .byte 0x02, 0x00, 0x1e, 0x00, 0x55, 0x00, 0x00, 0x00
        .4byte KaoruHasegawa
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global KaoruHasegawa
        KaoruHasegawa:
        .string "Kaoru Hasegawa\0"
        .align 2,0

        .global BGIllustration_80E4D68
        BGIllustration_80E4D68:
        .byte 0x82, 0xa0
        .string "BG ILLUSTRATION"
        .byte 0x82, 0xa2, 0x00

        .global FuyuhikoKoizumi
        FuyuhikoKoizumi:
        .string "Fuyuhiko Koizumi\0"
        .align 2,0

        .global GraphicDirector_80E4D90
        GraphicDirector_80E4D90:
        .byte 0x82, 0xa0
        .string "GRAPHIC DIRECTOR"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00, 0x00

        .global Credits_DesignDirector
        Credits_DesignDirector:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x23, 0x00, 0x00, 0x00
        .4byte DesignDirector_80E4E1C
        .byte 0x02, 0x00, 0x1e, 0x00, 0x32, 0x00, 0x00, 0x00
        .4byte HiroshiNakamura
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte FujimiOnishi
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YoshihitoTakaishi
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global YoshihitoTakaishi
        YoshihitoTakaishi:
        .string "Yoshihito Takaishi\0"
        .align 2,0
        .global FujimiOnishi
        FujimiOnishi:
        .string "Fujimi O-nishi\0"
        .align 2,0
        .global HiroshiNakamura
        HiroshiNakamura:
        .string "Hiroshi Nakamura\0"
        .align 2,0

        .global DesignDirector_80E4E1C
        DesignDirector_80E4E1C:
        .byte 0x82, 0xa0
        .string "DESIGN DIRECTOR"
        .byte 0x82, 0xa2, 0x00

        .global Credits_CharacterGraphics
        Credits_CharacterGraphics:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte CharacterGraphics_80E4EEC
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte YoshinariKaiho
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte AsamiWatanabe
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YusukeFuruya
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte HirokoFujikawa
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YukoKameyama
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YukiAda
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global YukiUda
        YukiAda:
        .string "Yuki Uda\0"
        .align 2,0
        .global YukoKameyama
        YukoKameyama:
        .string "Yuko Kameyama\0"
        .align 2,0
        .global HirokoFujikawa
        HirokoFujikawa:
        .string "Hiroko Fujikawa\0"
        .align 2,0
        .global YusukeFuruya
        YusukeFuruya:
        .string "Yusuke Furuya\0"
        .align 2,0
        .global AsamiWatanabe
        AsamiWatanabe:
        .string "Asami Watanabe\0"
        .align 2,0
        .global YoshinariKaiho
        YoshinariKaiho:
        .string "Yoshinari Kaiho\0"
        .align 2,0

        .global CharacterGraphics_80E4EEC
        CharacterGraphics_80E4EEC:
        .byte 0x82, 0xa0
        .string "CHARACTER GRAPHICS"
        .byte 0x82, 0xa2, 0x00, 0x00

        .global Credits_CharacterGraphics2
        Credits_CharacterGraphics2:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte CharacterGraphics_80E4EEC
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte MarieHirosawa
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YoshikoOta
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte JunkoHarada
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YuichiHirose
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte NorimasaHigaki
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte MisakiTsukada
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global MisakiTsukada
        MisakiTsukada:
        .string "Misaki Tsukada\0"
        .align 2,0
        .global NorimasaHigaki
        NorimasaHigaki:
        .string "Norimasa Higaki\0"
        .align 2,0
        .global YuichiHirose
        YuichiHirose:
        .string "Yuichi Hirose\0"
        .align 2,0
        .global JunkoHarada
        JunkoHarada:
        .string "Junko Harada\0"
        .align 2,0
        .global YoshikoOta
        YoshikoOta:
        .string "Yoshiko Ota\0"
        .align 2,0
        .global MarieHirosawa
        MarieHirosawa:
        .string "Marie Hirosawa\0"
        .align 2,0

        .global Credits_BGGraphics
        Credits_BGGraphics:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte BGGraphics_80E5088
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte MigakuMatsui
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte ToshimiAoyagi
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte SatoshiMatsuura
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte ShigeruKawahara
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YukoNakagawa
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte ChikaHirano
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global ChikaHirano
        ChikaHirano:
        .string "Chika Hirano\0"
        .align 2,0
        .global YukoNakagawa
        YukoNakagawa:
        .string "Yuko Nakagawa\0"
        .align 2,0
        .global ShigeruKawahara
        ShigeruKawahara:
        .string "Shigeru Kawahara\0"
        .align 2,0
        .global SatoshiMatsuura
        SatoshiMatsuura:
        .string "Satoshi Matsuura\0"
        .align 2,0
        .global ToshimiAoyagi
        ToshimiAoyagi:
        .string "Toshimi Aoyagi\0"
        .align 2,0
        .global MigakuMatsui
        MigakuMatsui:
        .string "Migaku Matsui\0"
        .align 2,0

        .global BGGraphics_80E5088
        BGGraphics_80E5088:
        .byte 0x82, 0xa0
        .string "BG GRAPHICS"
        .byte 0x82, 0xa2, 0x00

        .global Credits_BGGraphics2
        Credits_BGGraphics2:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte BGGraphics_80E5088
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte KyoheiIshida
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte ReikoNagashima
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte MasayukiShirakawa
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global MasayukiShirakawa
        MasayukiShirakawa:
        .string "Masayuki Shirakawa\0"
        .align 2,0
        .global ReikoNagashima
        ReikoNagashima:
        .string "Reiko Nagashima\0"
        .global KyoheiIshida
        KyoheiIshida:
        .align 2,0
        .string "Kyohei Ishida\0"
        .align 2,0

        .global Credits_SoundMusic
        Credits_SoundMusic:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00
        .4byte SoundDirector_80E51D0
        .byte 0x02, 0x00, 0x1e, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte KojiroNakashima
        .byte 0x01, 0x00, 0x0a, 0x00, 0x23, 0x00, 0x00, 0x00
        .4byte Music_80E51B0
        .byte 0x02, 0x00, 0x1e, 0x00, 0x32, 0x00, 0x00, 0x00
        .4byte ArataIiyoshi
        .byte 0x02, 0x00, 0x1e, 0x00, 0x41, 0x00, 0x00, 0x00
        .4byte AtsurhiroIshizuna
        .byte 0x01, 0x00, 0x0a, 0x00, 0x55, 0x00, 0x00, 0x00
        .4byte SoundEffects_80E5178
        .byte 0x02, 0x00, 0x1e, 0x00, 0x64, 0x00, 0x00, 0x00
        .4byte MisakiOkibe
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global MisakiOkibe
        MisakiOkibe:
        .string "Misaki Okibe\0"
        .align 2,0
        .global SoundEffects_80E5178
        SoundEffects_80E5178:
        .byte 0x82, 0xa0
        .string "SOUND EFFECTS"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00

        .global AtsurhiroIshizuna
        AtsurhiroIshizuna:
        .string "Atsuhiro Ishizuna\0"
        .align 2,0
        .global ArataIiyoshi
        ArataIiyoshi:
        .string "Arata Iiyoshi\0"
        .align 2,0

        .global Music_80E51B0
        Music_80E51B0:
        .byte 0x82, 0xa0
        .string "MUSIC"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00

        .global KojiroNakashima
        KojiroNakashima:
        .string "Kojiro Nakashima\0"
        .align 2,0
        .global SoundDirector_80E51D0
        SoundDirector_80E51D0:
        .byte 0x82, 0xa0
        .string "SOUND DIRECTOR"
        .byte 0x82, 0xa2, 0x00, 0x00

        .global Credits_SpecialThanks
        Credits_SpecialThanks:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte SpecialThanks_80E5218
        .byte 0x02, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte KoyushaLTD
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global KoyushaLTD
        KoyushaLTD:
        .string "KOYUSHA LTD.\0"
        .align 2,0
        .global SpecialThanks_80E5218
        SpecialThanks_80E5218:
        .byte 0x82, 0xa0
        .string "SPECIAL THANKS"
        .byte 0x82, 0xa2, 0x00, 0x00

        .global Credits_Debug
        Credits_Debug:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x28, 0x00, 0x00, 0x00
        .4byte Debug_80E5284
        .byte 0x02, 0x00, 0x1e, 0x00, 0x37, 0x00, 0x00, 0x00
        .4byte ChunsoftDebugTeam
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte SuperMarioClub
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global SuperMarioClub
        SuperMarioClub:
        .string "Super Mario Club\0"
        .align 2,0
        .global ChunsoftDebugTeam
        ChunsoftDebugTeam:
        .string "CHUNSOFT Debug Team\0"
        .align 2,0

        .global Debug_80E5284
        Debug_80E5284:
        .byte 0x82, 0xa0
        .string "DEBUG"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00

        .global Credits_PackageIllustration
        Credits_PackageIllustration:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte PackageIllustration_80E52C4
        .byte 0x02, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte KenSugimori
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global KenSugimori
        KenSugimori:
        .string "Ken Sugimori\0"
        .align 2,0
        .global PackageIllustration_80E52C4
        PackageIllustration_80E52C4:
        .byte 0x82, 0xa0
        .string "PACKAGE ILLUSTRATION"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00, 0x00

        .global Credits_Artwork
        Credits_Artwork:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x14, 0x00, 0x00, 0x00
        .4byte Artwork_80E5384
        .byte 0x02, 0x00, 0x1e, 0x00, 0x23, 0x00, 0x00, 0x00
        .4byte KazuhikoNakanishi
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte SakaeKimura
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte KenichiKoga
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte KiyomoOe
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte FujikoNomura
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global FujikoNomura
        FujikoNomura:
        .string "Fujiko Nomura\0"
        .align 2,0
        .global KiyomoOe
        KiyomoOe:
        .string "Kiyomo Oe\0"
        .align 2,0
        .global KenichiKoga
        KenichiKoga:
        .string "Ken-ichi Koga\0"
        .align 2,0
        .global SakaeKimura
        SakaeKimura:
        .string "Sakae Kimura\0"
        .align 2,0
        .global KazuhikoNakanishi
        KazuhikoNakanishi:
        .string "Kazuhiko Nakanishi\0"
        .align 2,0

        .global Artwork_80E5384
        Artwork_80E5384:
        .byte 0x82, 0xa0
        .string "ARTWORK"
        .byte 0x82, 0xa2, 0x00

        .global Credits_DevelopmentSupport
        Credits_DevelopmentSupport:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte DevelopmentSupport_80E544C
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte AkihiroKaneko
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte NobuhiroSaito
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte KosukeYoshida
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte KeikoHoriuchi
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte MayumiIso
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte KensukeOguri
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global KensukeOguri
        KensukeOguri:
        .string "Kensuke Oguri\0"
        .align 2,0
        .global MayumiIso
        MayumiIso:
        .string "Mayumi Iso\0"
        .align 2,0
        .global KeikoHoriuchi
        KeikoHoriuchi:
        .string "Keiko Horiuchi\0"
        .align 2,0
        .global KosukeYoshida
        KosukeYoshida:
        .string "Kosuke Yoshida\0"
        .align 2,0
        .global NobuhiroSaito
        NobuhiroSaito:
        .string "Nobuhiro Saito\0"
        .align 2,0
        .global AkihiroKaneko
        AkihiroKaneko:
        .string "Akihiro Kaneko\0"
        .align 2,0

        .global DevelopmentSupport_80E544C
        DevelopmentSupport_80E544C:
        .byte 0x82, 0xa0
        .string "DEVELOPMENT SUPPORT"
        .byte 0x82, 0xa2, 0x00

        .global Credits_DevelopmentSupport2
        Credits_DevelopmentSupport2:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte DevelopmentSupport_80E544C
        .byte 0x02, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00, 0x00
        .4byte KojiMalta
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte YasufumiFukuda
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte HizukiMisono
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte TakahiroOnishi
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte TakaoNakano
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global TakaoNakano
        TakaoNakano:
        .string "Takao Nakano\0"
        .align 2,0
        .global TakahiroOnishi
        TakahiroOnishi:
        .string "Takahiro O-nishi\0"
        .align 2,0
        .global HizukiMisono
        HizukiMisono:
        .string "Hizuki Misono\0"
        .align 2,0
        .global YasufumiFukuda
        YasufumiFukuda:
        .string "Yasufumi Fukuda\0"
        .align 2,0
        .global KojiMalta
        KojiMalta:
        .string "Koji Malta\0"
        .align 2,0

        .global Credits_Localization
        Credits_Localization:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00
        .4byte LocalizationCoordinators_80E55CC
        .byte 0x02, 0x00, 0x1e, 0x00, 0x0f, 0x00, 0x00, 0x00
        .4byte KeisukeTominaga
        .byte 0x02, 0x00, 0x1e, 0x00, 0x23, 0x00, 0x00, 0x00
        .4byte SethMcMahill
        .byte 0x01, 0x00, 0x0a, 0x00, 0x32, 0x00, 0x00, 0x00
        .4byte Translator_80E5598
        .byte 0x02, 0x00, 0x1e, 0x00, 0x41, 0x00, 0x00, 0x00
        .4byte NobOgasawara
        .byte 0x01, 0x00, 0x0a, 0x00, 0x55, 0x00, 0x00, 0x00
        .4byte Editor_80E557C
        .byte 0x02, 0x00, 0x1e, 0x00, 0x64, 0x00, 0x00, 0x00
        .4byte TeresaLillygren
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global TeresaLillygren
        TeresaLillygren:
        .string "Teresa Lillygren\0"
        .align 2,0
        .global Editor_80E557C
        Editor_80E557C:
        .byte 0x82, 0xa0
        .string "EDITOR"
        .byte 0x82, 0xa2, 0x00, 0x00

        .global NobOgasawara
        NobOgasawara:
        .string "Nob Ogasawara\0"
        .align 2,0

        .global Translator_80E5598
        Translator_80E5598:
        .byte 0x82, 0xa0
        .string "TRANSLATOR"
        .byte 0x82, 0xa2, 0x00, 0x00

        .global SethMcMahill
        SethMcMahill:
        .string "Seth McMahill\0"
        .align 2,0
        .global KeisukeTominaga
        KeisukeTominaga:
        .string "Keisuke Tominaga\0"
        .align 2,0

        .global LocalizationCoordinators_80E55CC
        LocalizationCoordinators_80E55CC:
        .byte 0x82, 0xa0
        .string "LOCALIZATION COORDINATORS"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00

        .global Credits_Product
        Credits_Product:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x05, 0x00, 0x00, 0x00
        .4byte ProductSupport_80E56B8
        .byte 0x02, 0x00, 0x1e, 0x00, 0x14, 0x00, 0x00, 0x00
        .4byte KimikoNakamichi
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte HiroshiAkune
        .byte 0x01, 0x00, 0x0a, 0x00, 0x37, 0x00, 0x00, 0x00
        .4byte NoaProductTesting_80E567C
        .byte 0x02, 0x00, 0x1e, 0x00, 0x46, 0x00, 0x00, 0x00
        .4byte ThomasHertzog
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte JimHoldeman
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte MikaKurosawa
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global MikaKurosawa
        MikaKurosawa:
        .string "Mika Kurosawa\0"
        .align 2,0
        .global JimHoldeman
        JimHoldeman:
        .string "Jim Holdeman\0"
        .align 2,0
        .global ThomasHertzog
        ThomasHertzog:
        .string "Thomas Hertzog\0"
        .align 2,0

        .global NoaProductTesting_80E567C
        NoaProductTesting_80E567C:
        .byte 0x82, 0xa0
        .string "NOA PRODUCT TESTING"
        .byte 0x82, 0xa2, 0x00

        .global HiroshiAkune
        HiroshiAkune:
        .string "Hiroshi Akune\0"
        .align 2,0
        .global KimikoNakamichi
        KimikoNakamichi:
        .string "Kimiko Nakamichi\0"
        .align 2,0
        .global ProductSupport_80E56B8
        ProductSupport_80E56B8:
        .byte 0x82, 0xa0
        .string "PRODUCT SUPPORT"
        .byte 0x82, 0xa2, 0x00

        .global Credits_SpecialThanks2
        Credits_SpecialThanks2:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x19, 0x00, 0x00, 0x00
        .4byte SpecialThanks_80E5218
        .byte 0x02, 0x00, 0x1e, 0x00, 0x28, 0x00, 0x00, 0x00
        .4byte NicolaWright
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte ShellieDow
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte JoshNewman
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte HitomiRoss
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global HitomiRoss
        HitomiRoss:
        .string "Hitomi Ross\0"
        .align 2,0
        .global JoshNewman
        JoshNewman:
        .string "Josh Newman\0"
        .align 2,0
        .global ShellieDow
        ShellieDow:
        .string "Shellie Dow\0"
        .align 2,0
        .global NicolaWright
        NicolaWright:
        .string "Nicola Wright\0"
        .align 2,0

        .global Credits_VerySpecialThanks
        Credits_VerySpecialThanks:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x28, 0x00, 0x00, 0x00
        .4byte VerySpecialThanks_80E579C
        .byte 0x02, 0x00, 0x1e, 0x00, 0x37, 0x00, 0x00, 0x00
        .4byte GameFreakInc
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte AmbrellaCoLtd
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global AmbrellaCoLtd
        AmbrellaCoLtd:
        .asciz "Ambrella Co., Ltd."
        .align 2,0

        .global GameFreakInc
        GameFreakInc:
        .string "GAME FREAK inc.\0"
        .align 2,0

        .global VerySpecialThanks_80E579C
        VerySpecialThanks_80E579C:
        .byte 0x82, 0xa0
        .string "VERY SPECIAL THANKS"
        .byte 0x82, 0xa2, 0x00

        .global Credits_OriginalDirector
        Credits_OriginalDirector:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte OriginalDirector_80E57E8
        .byte 0x02, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte SatoshiTajiri
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global SatoshiTajiri
        SatoshiTajiri:
        .string "Satoshi Tajiri\0"
        .align 2,0
        .global OriginalDirector_80E57E8
        OriginalDirector_80E57E8:
        .byte 0x82, 0xa0
        .string "POK~e9MON ORIGINAL DIRECTOR"
        .byte 0x82, 0xa2, 0x00

        .global Credits_Producers
        Credits_Producers:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x19, 0x00, 0x00, 0x00
        .4byte Producers_80E5888
        .byte 0x02, 0x00, 0x1e, 0x00, 0x28, 0x00, 0x00, 0x00
        .4byte HiroakiTsuru
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte AtsushiSugimoto
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte KunimiKawamura
        .byte 0x02, 0x00, 0x1e, 0x00, 0xf1, 0xff, 0x00, 0x00
        .4byte HitoshiYamagami
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global HitoshiYamagami
        HitoshiYamagami:
        .string "Hitoshi Yamagami\0"
        .align 2,0
        .global AtsushiSugimoto
        AtsushiSugimoto:
        .string "Atsushi Sugimoto\0"
        .align 2,0
        .global HiroakiTsuru
        HiroakiTsuru:
        .string "Hiroaki Tsuru\0"
        .align 2,0

        .global Producers_80E5888
        Producers_80E5888:
        .byte 0x82, 0xa0
        .string "PRODUCERS"
        .byte 0x82, 0xa2, 0x00, 0x00, 0x00

        .global Credits_ExectiveProducer
        Credits_ExecutiveProducer:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte ExecutiveProducer_80E58CC
        .byte 0x02, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte SatoruIwata
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

        .global SatoruIwata
        SatoruIwata:
        .string "Satoru Iwata\0"
        .align 2,0
        .global ExecutiveProducer_80E58CC
        ExecutiveProducer_80E58CC:
        .byte 0x82, 0xa0
        .string "EXECUTIVE PRODUCER"
        .byte 0x82, 0xa2, 0x00, 0x00

        .global Credits_ExectiveProducer2
        Credits_ExecutiveProducer2:
        .byte 0x01, 0x00, 0x0a, 0x00, 0x2d, 0x00, 0x00, 0x00
        .4byte ExecutiveProducer_80E58CC
        .byte 0x02, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00
        .4byte TsuenehazuIshihara
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .global TsunekazuIshihara
        TsuenehazuIshihara:
        .string "Tsunekazu Ishihara\0"
        .align 2,0

	.global gCreditsTable
gCreditsTable: @ 80E591C
@ replacing .incbin "baserom.gba", 0x000e591c, 0x74
        .4byte Credits_StaffCredits
        .4byte Credits_Producer
        .4byte Credits_Director
        .4byte Credits_Scenario
        .4byte Credits_GamePlanning
        .4byte Credits_Programming
        .4byte Credits_GraphicsDirectorBGIllus
        .4byte Credits_DesignDirector
        .4byte Credits_CharacterGraphics
        .4byte Credits_CharacterGraphics2
        .4byte Credits_BGGraphics
        .4byte Credits_BGGraphics2
        .4byte Credits_SoundMusic
        .4byte Credits_SpecialThanks
        .4byte Credits_Debug
        .4byte Credits_PackageIllustration
        .4byte Credits_Artwork
        .4byte Credits_DevelopmentSupport
        .4byte Credits_DevelopmentSupport2
        .4byte Credits_Localization
        .4byte Credits_Product
        .4byte Credits_SpecialThanks2
        .4byte Credits_VerySpecialThanks
        .4byte Credits_OriginalDirector
        .4byte Credits_Producers
        .4byte Credits_ExecutiveProducer
        .4byte Credits_ExecutiveProducer2
