.section .rodata

.global gDungeonFileArchive
gDungeonFileArchive: @ 83B0000
.string "pksdir0\0"
.byte 0xc7, 0x01, 0x00, 0x00 @ 455 entries
.4byte StartOfDungeonTable
.string "pksdir0\0"

.global StartOfDungeonTable
StartOfDungeonTable:
.4byte gUnknown_83B1CBC @ Pointer to b00canm
.4byte gUnknown_83B1CCC
.4byte gUnknown_83B1CB4 @ Pointer to b00cel
.4byte gUnknown_83B235C @ Pointer to AT4PX string (yay compression)
.4byte gUnknown_83B1CAC @ Pointer to b00cex
.4byte gUnknown_83B2A64 @ Pointer to SIRO header
.4byte gUnknown_83B1CA4 @ Pointer to b00fon
.4byte gUnknown_83B2D3C @ Pointer to AT4PX string
.4byte gUnknown_83B1C9C @ Pointer to gUnknown_83B49D1
.4byte gUnknown_83B49D1


.4byte gUnknown_83B1C94 @ Pointer to b01canm
.4byte gUnknown_83B4CD0 @ Pointer to SIRO header
.4byte gUnknown_83B1C8C @ Pointer to b01cel 
.4byte gUnknown_83B5220 @ Pointer to AT4PX 
.4byte gUnknown_83B1C84 @ Pointer to b01cex
.4byte gUnknown_83B5918 @ Pointer to SIRO header
.4byte gUnknown_83B1C7C @ Pointer to b01fon
.4byte gUnknown_83B5C4F @ Pointer to AT4PX 
.4byte gUnknown_83B1C74 @ Pointer to b01pal
.4byte gUnknown_83B8538 @ Start of palette

.4byte gUnknown_83B1C6C @ Pointer to b02can 
.4byte gUnknown_83B8838 @ Pointer to SIRO header
.4byte gUnknown_83B1C64 @ Pointer to b02cel
.4byte gUnknown_83B8C88 @ Pointer to AT4PX 
.4byte gUnknown_83B1C5C @ Pointer to b02cex
.4byte gUnknown_83B9530 @ Pointer to SIRO header
.4byte gUnknown_83B1C54 @ Pointer to b02fon
.4byte gUnknown_83B98C6 @ Pointer to AT4PX 
.4byte gUnknown_83B1C4C @ Pointer to b02pal
.4byte gUnknown_83BBD08 @ Start of palette

.4byte gUnknown_83B1C44 @ Pointer to b03can 
.4byte gUnknown_83BC008 @ Pointer to SIRO header
.4byte gUnknown_83B1C3C @ Pointer to b03cel
.4byte gUnknown_83BC458 @ Pointer to AT4PX 
.4byte gUnknown_83B1C34 @ Pointer to b03cex
.4byte gUnknown_83BCBCC @ Pointer to SIRO header
.4byte gUnknown_83B1C2C @ Pointer to b03fon
.4byte gUnknown_83BCF01 @ Pointer to AT4PX 
.4byte gUnknown_83B1C24 @ Pointer to b03pal
.4byte gUnknown_83BF124 @ Start of palette

.4byte gUnknown_83B1C1C
.4byte gUnknown_83BF424
.4byte gUnknown_83B1C14
.4byte gUnknown_83BF974
.4byte gUnknown_83B1C0C
.4byte gUnknown_83C0088
.4byte gUnknown_83B1C04
.4byte gUnknown_83C03D8
.4byte gUnknown_83B1BFC
.4byte gUnknown_83C2670

.4byte gUnknown_83B1BF4
.4byte gUnknown_83C2970
.4byte gUnknown_83B1BEC
.4byte gUnknown_83C2EC0
.4byte gUnknown_83B1BE4
.4byte gUnknown_83C35C0
.4byte gUnknown_83B1BDC
.4byte gUnknown_83C38FE
.4byte gUnknown_83B1BD4
.4byte gUnknown_83C53E4

.4byte gUnknown_83B1BCC
.4byte gUnknown_83C56E4
.4byte gUnknown_83B1BC4
.4byte gUnknown_83C5B34
.4byte gUnknown_83B1BBC
.4byte gUnknown_83C6304
.4byte gUnknown_83B1BB4
.4byte gUnknown_83C6645
.4byte gUnknown_83B1BAC
.4byte gUnknown_83C97EC

.4byte gUnknown_83B1BA4
.4byte gUnknown_83C9AEC
.4byte gUnknown_83B1B9C
.4byte gUnknown_83C9F3C
.4byte gUnknown_83B1B94
.4byte gUnknown_83CA70C
.4byte gUnknown_83B1B8C
.4byte gUnknown_83CAAA2
.4byte gUnknown_83B1B84
.4byte gUnknown_83CC9A4

.4byte gUnknown_83B1B7C
.4byte gUnknown_83CCCA4
.4byte gUnknown_83B1B74
.4byte gUnknown_83CD0F4
.4byte gUnknown_83B1B6C
.4byte gUnknown_83CD8B0
.4byte gUnknown_83B1B64
.4byte gUnknown_83CDBFD
.4byte gUnknown_83B1B5C
.4byte gUnknown_83D0C3C

.4byte gUnknown_83B1B54
.4byte gUnknown_83D0F3C
.4byte gUnknown_83B1B4C
.4byte gUnknown_83D1394
.4byte gUnknown_83B1B44
.4byte gUnknown_83D1AB4
.4byte gUnknown_83B1B3C
.4byte gUnknown_83D1E19
.4byte gUnknown_83B1B34
.4byte gUnknown_83D3FC4

.4byte gUnknown_83B1B2C
.4byte gUnknown_83D42C4
.4byte gUnknown_83B1B24
.4byte gUnknown_83D4714
.4byte gUnknown_83B1B1C
.4byte gUnknown_83D4F1C
.4byte gUnknown_83B1B14
.4byte gUnknown_83D5253
.4byte gUnknown_83B1B0C
.4byte gUnknown_83D7A14

.4byte gUnknown_83B1B04
.4byte gUnknown_83D7D14
.4byte gUnknown_83B1AFC
.4byte gUnknown_83D8164
.4byte gUnknown_83B1AF4
.4byte gUnknown_83D88F4
.4byte gUnknown_83B1AEC
.4byte gUnknown_83D8C2B
.4byte gUnknown_83B1AE4
.4byte gUnknown_83DB640

.4byte gUnknown_83B1ADC
.4byte gUnknown_83DB940
.4byte gUnknown_83B1AD4
.4byte gUnknown_83DBFD0
.4byte gUnknown_83B1ACC
.4byte gUnknown_83DC7BC
.4byte gUnknown_83B1AC4
.4byte gUnknown_83DCAD0
.4byte gUnknown_83B1ABC
.4byte gUnknown_83DF0A0

.4byte gUnknown_83B1AB4
.4byte gUnknown_83DF3A0
.4byte gUnknown_83B1AAC
.4byte gUnknown_83DF7F0
.4byte gUnknown_83B1AA4
.4byte gUnknown_83DFF64
.4byte gUnknown_83B1A9C
.4byte gUnknown_83E0298
.4byte gUnknown_83B1A94
.4byte gUnknown_83E2190

.4byte gUnknown_83B1A8C
.4byte gUnknown_83E2490
.4byte gUnknown_83B1A84
.4byte gUnknown_83E29E0
.4byte gUnknown_83B1A7C
.4byte gUnknown_83E31C8
.4byte gUnknown_83B1A74
.4byte gUnknown_83E355F
.4byte gUnknown_83B1A6C
.4byte gUnknown_83E55A8

.4byte gUnknown_83B1A64
.4byte gUnknown_83E58A8
.4byte gUnknown_83B1A5C
.4byte gUnknown_83E5CF8
.4byte gUnknown_83B1A54
.4byte gUnknown_83E63E0
.4byte gUnknown_83B1A4C
.4byte gUnknown_83E674E
.4byte gUnknown_83B1A44
.4byte gUnknown_83E84EC

.4byte gUnknown_83B1A3C
.4byte gUnknown_83E87EC
.4byte gUnknown_83B1A34
.4byte gUnknown_83E8E7C
.4byte gUnknown_83B1A2C
.4byte gUnknown_83E95C0
.4byte gUnknown_83B1A24
.4byte gUnknown_83E98EA
.4byte gUnknown_83B1A1C
.4byte gUnknown_83EB52C

.4byte gUnknown_83B1A14
.4byte gUnknown_83EB82C
.4byte gUnknown_83B1A0C
.4byte gUnknown_83EBD40
.4byte gUnknown_83B1A04
.4byte gUnknown_83EC570
.4byte gUnknown_83B19FC
.4byte gUnknown_83EC90A
.4byte gUnknown_83B19F4
.4byte gUnknown_83EEA4C
.4byte gUnknown_83B19EC
.4byte gUnknown_83EED4C
.4byte gUnknown_83B19E4
.4byte gUnknown_83EF19C
.4byte gUnknown_83B19DC
.4byte gUnknown_83EF954
.4byte gUnknown_83B19D4
.4byte gUnknown_83EFCBB
.4byte gUnknown_83B19CC
.4byte gUnknown_83F24EC
.4byte gUnknown_83B19C4
.4byte gUnknown_83F27EC
.4byte gUnknown_83B19BC
.4byte gUnknown_83F2D3C
.4byte gUnknown_83B19B4
.4byte gUnknown_83F3494
.4byte gUnknown_83B19AC
.4byte gUnknown_83F382C
.4byte gUnknown_83B19A4
.4byte gUnknown_83F5194
.4byte gUnknown_83B199C
.4byte gUnknown_83F5494
.4byte gUnknown_83B1994
.4byte gUnknown_83F59E4
.4byte gUnknown_83B198C
.4byte gUnknown_83F6188
.4byte gUnknown_83B1984
.4byte gUnknown_83F64A1
.4byte gUnknown_83B197C
.4byte gUnknown_83F8C68
.4byte gUnknown_83B1974
.4byte gUnknown_83F8F68
.4byte gUnknown_83B196C
.4byte gUnknown_83F95B8
.4byte gUnknown_83B1964
.4byte gUnknown_83F9CBC
.4byte gUnknown_83B195C
.4byte gUnknown_83FA051
.4byte gUnknown_83B1954
.4byte gUnknown_83FB4B0
.4byte gUnknown_83B194C
.4byte gUnknown_83FB7B0
.4byte gUnknown_83B1944
.4byte gUnknown_83FBD80
.4byte gUnknown_83B193C
.4byte gUnknown_83FC080
.4byte gUnknown_83B1934
.4byte gUnknown_83FC5D0
.4byte gUnknown_83B192C
.4byte gUnknown_83FCD4C
.4byte gUnknown_83B1924
.4byte gUnknown_83FD098
.4byte gUnknown_83B191C
.4byte gUnknown_83FF330
.4byte gUnknown_83B1914
.4byte gUnknown_83FF630
.4byte gUnknown_83B190C
.4byte gUnknown_83FFA80
.4byte gUnknown_83B1904
.4byte gUnknown_8400114
.4byte gUnknown_83B18FC
.4byte gUnknown_840044A
.4byte gUnknown_83B18F4
.4byte gUnknown_8401C98
.4byte gUnknown_83B18EC
.4byte gUnknown_8401F98
.4byte gUnknown_83B18E4
.4byte gUnknown_84023E8
.4byte gUnknown_83B18DC
.4byte gUnknown_8402BF0
.4byte gUnknown_83B18D4
.4byte gUnknown_8402F86
.4byte gUnknown_83B18CC
.4byte gUnknown_8404A44
.4byte gUnknown_83B18C4
.4byte gUnknown_8404D44
.4byte gUnknown_83B18BC
.4byte gUnknown_8405294
.4byte gUnknown_83B18B4
.4byte gUnknown_8405594
.4byte gUnknown_83B18AC
.4byte gUnknown_8405AE4
.4byte gUnknown_83B18A4
.4byte gUnknown_8405DE4
.4byte gUnknown_83B189C
.4byte gUnknown_8406434
.4byte gUnknown_83B1894
.4byte gUnknown_8406B5C
.4byte gUnknown_83B188C
.4byte gUnknown_8406E82
.4byte gUnknown_83B1884
.4byte gUnknown_840873C
.4byte gUnknown_83B187C
.4byte gUnknown_8408A3C
.4byte gUnknown_83B1874
.4byte gUnknown_8408F8C
.4byte gUnknown_83B186C
.4byte gUnknown_84096B8
.4byte gUnknown_83B1864
.4byte gUnknown_84099E9
.4byte gUnknown_83B185C
.4byte gUnknown_840BCA0
.4byte gUnknown_83B1854
.4byte gUnknown_840BFA0
.4byte gUnknown_83B184C
.4byte gUnknown_840C4F0
.4byte gUnknown_83B1844
.4byte gUnknown_840CBC4
.4byte gUnknown_83B183C
.4byte gUnknown_840CF0F
.4byte gUnknown_83B1834
.4byte gUnknown_840E5EC
.4byte gUnknown_83B182C
.4byte gUnknown_840E8EC
.4byte gUnknown_83B1824
.4byte gUnknown_840EE3C
.4byte gUnknown_83B181C
.4byte gUnknown_840F5E8
.4byte gUnknown_83B1814
.4byte gUnknown_840F920
.4byte gUnknown_83B180C
.4byte gUnknown_8411918
.4byte gUnknown_83B1804
.4byte gUnknown_8411C18
.4byte gUnknown_83B17FC
.4byte gUnknown_8412728
.4byte gUnknown_83B17F4
.4byte gUnknown_8412D88
.4byte gUnknown_83B17EC
.4byte gUnknown_84130A4
.4byte gUnknown_83B17E4
.4byte gUnknown_84141E4
.4byte gUnknown_83B17DC
.4byte gUnknown_84144E4
.4byte gUnknown_83B17D4
.4byte gUnknown_8414FF4
.4byte gUnknown_83B17CC
.4byte gUnknown_8415654
.4byte gUnknown_83B17C4
.4byte gUnknown_8415970
.4byte gUnknown_83B17BC
.4byte gUnknown_8416A54
.4byte gUnknown_83B17B4
.4byte gUnknown_8416D5C
.4byte gUnknown_83B17AC
.4byte gUnknown_84173AC
.4byte gUnknown_83B17A4
.4byte gUnknown_84176AC
.4byte gUnknown_83B179C
.4byte gUnknown_8417CBC
.4byte gUnknown_83B1794
.4byte gUnknown_84184A8
.4byte gUnknown_83B178C
.4byte gUnknown_84187DF
.4byte gUnknown_83B1784
.4byte gUnknown_841A980
.4byte gUnknown_83B177C
.4byte gUnknown_841AC80
.4byte gUnknown_83B1774
.4byte gUnknown_841B290
.4byte gUnknown_83B176C
.4byte gUnknown_841BA28
.4byte gUnknown_83B1764
.4byte gUnknown_841BDAD
.4byte gUnknown_83B175C
.4byte gUnknown_841E074
.4byte gUnknown_83B1754
.4byte gUnknown_841E374
.4byte gUnknown_83B174C
.4byte gUnknown_841E8C4
.4byte gUnknown_83B1744
.4byte gUnknown_841EFD4
.4byte gUnknown_83B173C
.4byte gUnknown_841F34F
.4byte gUnknown_83B1734
.4byte gUnknown_8420F9C
.4byte gUnknown_83B172C
.4byte gUnknown_842129C
.4byte gUnknown_83B1724
.4byte gUnknown_84217EC
.4byte gUnknown_83B171C
.4byte gUnknown_8421AEC
.4byte gUnknown_83B1714
.4byte gUnknown_842203C
.4byte gUnknown_83B170C
.4byte gUnknown_842272C
.4byte gUnknown_83B1704
.4byte gUnknown_8422ABC
.4byte gUnknown_83B16FC
.4byte gUnknown_8424088
.4byte gUnknown_83B16F4
.4byte gUnknown_8424388
.4byte gUnknown_83B16EC
.4byte gUnknown_84248D8
.4byte gUnknown_83B16E4
.4byte gUnknown_8424FD8
.4byte gUnknown_83B16DC
.4byte gUnknown_842534E
.4byte gUnknown_83B16D4
.4byte gUnknown_8426F84
.4byte gUnknown_83B16CC
.4byte gUnknown_8427284
.4byte gUnknown_83B16C4
.4byte gUnknown_84277D4
.4byte gUnknown_83B16BC
.4byte gUnknown_8427EE4
.4byte gUnknown_83B16B4
.4byte gUnknown_84281FD
.4byte gUnknown_83B16AC
.4byte gUnknown_842AA28
.4byte gUnknown_83B16A4
.4byte gUnknown_842AD28
.4byte gUnknown_83B169C
.4byte gUnknown_842B278
.4byte gUnknown_83B1694
.4byte gUnknown_842BA04
.4byte gUnknown_83B168C
.4byte gUnknown_842BD19
.4byte gUnknown_83B1684
.4byte gUnknown_842DEB4
.4byte gUnknown_83B167C
.4byte gUnknown_842E1B4
.4byte gUnknown_83B1674
.4byte gUnknown_842E704
.4byte gUnknown_83B166C
.4byte gUnknown_842EEDC
.4byte gUnknown_83B1664
.4byte gUnknown_842F273
.4byte gUnknown_83B165C
.4byte gUnknown_8431B30
.4byte gUnknown_83B1654
.4byte gUnknown_8431E30
.4byte gUnknown_83B164C
.4byte gUnknown_8432440
.4byte gUnknown_83B1644
.4byte gUnknown_8432C48
.4byte gUnknown_83B163C
.4byte gUnknown_8432F83
.4byte gUnknown_83B1634
.4byte gUnknown_8435188
.4byte gUnknown_83B162C
.4byte gUnknown_8435488
.4byte gUnknown_83B1624
.4byte gUnknown_84358D8
.4byte gUnknown_83B161C
.4byte gUnknown_8436058
.4byte gUnknown_83B1614
.4byte gUnknown_843638D
.4byte gUnknown_83B160C
.4byte gUnknown_8438AFC
.4byte gUnknown_83B1604
.4byte gUnknown_8438DFC
.4byte gUnknown_83B15FC
.4byte gUnknown_843950C
.4byte gUnknown_83B15F4
.4byte gUnknown_8439C30
.4byte gUnknown_83B15EC
.4byte gUnknown_8439F4C
.4byte gUnknown_83B15E4
.4byte gUnknown_843C16C
.4byte gUnknown_83B15DC
.4byte gUnknown_843C46C
.4byte gUnknown_83B15D4
.4byte gUnknown_843C8BC
.4byte gUnknown_83B15CC
.4byte gUnknown_843D094
.4byte gUnknown_83B15C4
.4byte gUnknown_843D42A
.4byte gUnknown_83B15BC
.4byte gUnknown_843F768
.4byte gUnknown_83B15B4
.4byte gUnknown_843FA68
.4byte gUnknown_83B15AC
.4byte gUnknown_8440638
.4byte gUnknown_83B15A4
.4byte gUnknown_8440DA0
.4byte gUnknown_83B159C
.4byte gUnknown_8441101
.4byte gUnknown_83B1594
.4byte gUnknown_8443054
.4byte gUnknown_83B158C
.4byte gUnknown_844335C
.4byte gUnknown_83B1584
.4byte gUnknown_84438EC
.4byte gUnknown_83B157C
.4byte gUnknown_8443FF4
.4byte gUnknown_83B1574
.4byte gUnknown_84442CC
.4byte gUnknown_83B156C
.4byte gUnknown_8445F60
.4byte gUnknown_83B1564
.4byte gUnknown_8446260
.4byte gUnknown_83B155C
.4byte gUnknown_84467B0
.4byte gUnknown_83B1554
.4byte gUnknown_8446F2C
.4byte gUnknown_83B154C
.4byte gUnknown_844729F
.4byte gUnknown_83B1544
.4byte gUnknown_84495C4
.4byte gUnknown_83B153C
.4byte gUnknown_84498C4
.4byte gUnknown_83B1534
.4byte gUnknown_8449D14
.4byte gUnknown_83B152C
.4byte gUnknown_844A488
.4byte gUnknown_83B1524
.4byte gUnknown_844A7D7
.4byte gUnknown_83B151C
.4byte gUnknown_844CE80
.4byte gUnknown_83B1514
.4byte gUnknown_844D180
.4byte gUnknown_83B150C
.4byte gUnknown_844D6D0
.4byte gUnknown_83B1504
.4byte gUnknown_844DDE0
.4byte gUnknown_83B14FC
.4byte gUnknown_844E0F9
.4byte gUnknown_83B14F4
.4byte gUnknown_8450924
.4byte gUnknown_83B14EC
.4byte gUnknown_8450C24
.4byte gUnknown_83B14E4
.4byte gUnknown_8451174
.4byte gUnknown_83B14DC
.4byte gUnknown_84518B8
.4byte gUnknown_83B14D4
.4byte gUnknown_8451C08
.4byte gUnknown_83B14CC
.4byte gUnknown_845416C
.4byte gUnknown_83B14C4
.4byte gUnknown_845446C
.4byte gUnknown_83B14BC
.4byte gUnknown_84549BC
.4byte gUnknown_83B14B4
.4byte gUnknown_84550C4
.4byte gUnknown_83B14AC
.4byte gUnknown_845539C
.4byte gUnknown_83B14A4
.4byte gUnknown_8457030
.4byte gUnknown_83B149C
.4byte gUnknown_8457330
.4byte gUnknown_83B1494
.4byte gUnknown_8457780
.4byte gUnknown_83B148C
.4byte gUnknown_8457E98
.4byte gUnknown_83B1484
.4byte gUnknown_84581CC
.4byte gUnknown_83B147C
.4byte gUnknown_845ACCC
.4byte gUnknown_83B1474
.4byte gUnknown_845AFCC
.4byte gUnknown_83B146C
.4byte gUnknown_845B41C
.4byte gUnknown_83B1464
.4byte gUnknown_845BBA4
.4byte gUnknown_83B145C
.4byte gUnknown_845BEE7
.4byte gUnknown_83B1454
.4byte gUnknown_845E880
.4byte gUnknown_83B144C
.4byte gUnknown_845EB80
.4byte gUnknown_83B1444
.4byte gUnknown_845EFD0
.4byte gUnknown_83B143C
.4byte gUnknown_845F2D0
.4byte gUnknown_83B1434
.4byte gUnknown_845F720
.4byte gUnknown_83B142C
.4byte gUnknown_845FA20
.4byte gUnknown_83B1424
.4byte gUnknown_845FE30
.4byte gUnknown_83B141C
.4byte gUnknown_84604C0
.4byte gUnknown_83B1414
.4byte gUnknown_84607DB
.4byte gUnknown_83B140C
.4byte gUnknown_84627FC
.4byte gUnknown_83B1404
.4byte gUnknown_8462AFC
.4byte gUnknown_83B13FC
.4byte gUnknown_8462F4C
.4byte gUnknown_83B13F4
.4byte gUnknown_84636BC
.4byte gUnknown_83B13EC
.4byte gUnknown_84639F2
.4byte gUnknown_83B13E4
.4byte gUnknown_8465E6C
.4byte gUnknown_83B13DC
.4byte gUnknown_846616C
.4byte gUnknown_83B13D4
.4byte gUnknown_8466A7C
.4byte gUnknown_83B13CC
.4byte gUnknown_8466D7C
.4byte gUnknown_83B13C4
.4byte gUnknown_84671CC
.4byte gUnknown_83B13BC
.4byte gUnknown_8467950
.4byte gUnknown_83B13B4
.4byte gUnknown_8467C74
.4byte gUnknown_83B13AC
.4byte gUnknown_846A37C
.4byte gUnknown_83B13A4
.4byte gUnknown_846A67C
.4byte gUnknown_83B139C
.4byte gUnknown_846ACCC
.4byte gUnknown_83B1394
.4byte gUnknown_846B42C
.4byte gUnknown_83B138C
.4byte gUnknown_846B771
.4byte gUnknown_83B1384
.4byte gUnknown_846DB74
.4byte gUnknown_83B137C
.4byte gUnknown_846DE74
.4byte gUnknown_83B1374
.4byte gUnknown_846E444
.4byte gUnknown_83B1368
.4byte gUnknown_846F248
.4byte gUnknown_83B1360
.4byte gUnknown_846F418
.4byte gUnknown_83B1358
.4byte gUnknown_8470FBC
.4byte gUnknown_83B1350
.4byte gUnknown_84712BC
.4byte gUnknown_83B1348
.4byte gUnknown_847188C
.4byte gUnknown_83B133C
.4byte gUnknown_8472130
.4byte gUnknown_83B1334
.4byte gUnknown_84722F3
.4byte gUnknown_83B132C
.4byte gUnknown_8473608
.4byte gUnknown_83B1324
.4byte gUnknown_8473908
.4byte gUnknown_83B131C
.4byte gUnknown_8474298
.4byte gUnknown_83B1310
.4byte gUnknown_8474E60
.4byte gUnknown_83B1308
.4byte gUnknown_847500B
.4byte gUnknown_83B1300
.4byte gUnknown_847745C
.4byte gUnknown_83B12F8
.4byte gUnknown_847775C
.4byte gUnknown_83B12F0
.4byte gUnknown_8477BEC
.4byte gUnknown_83B12E4
.4byte gUnknown_84789A8
.4byte gUnknown_83B12DC
.4byte gUnknown_8478BA9
.4byte gUnknown_83B12D4
.4byte gUnknown_847A598
.4byte gUnknown_83B12CC
.4byte gUnknown_847A898
.4byte gUnknown_83B12C4
.4byte gUnknown_847AE68
.4byte gUnknown_83B12B8
.4byte gUnknown_847B910
.4byte gUnknown_83B12B0
.4byte gUnknown_847BB13
.4byte gUnknown_83B12A8
.4byte gUnknown_847DF24
.4byte gUnknown_83B12A0
.4byte gUnknown_847E224
.4byte gUnknown_83B1298
.4byte gUnknown_847E63C
.4byte gUnknown_83B128C
.4byte gUnknown_847F268
.4byte gUnknown_83B1284
.4byte gUnknown_847F420
.4byte gUnknown_83B127C
.4byte gUnknown_8481E08
.4byte gUnknown_83B1274
.4byte gUnknown_8482108
.4byte gUnknown_83B126C
.4byte gUnknown_8482618
.4byte gUnknown_83B1260
.4byte gUnknown_8482FF8
.4byte gUnknown_83B1258
.4byte gUnknown_848311F
.4byte gUnknown_83B1250
.4byte gUnknown_8485F50
.4byte gUnknown_83B1248
.4byte gUnknown_8486250
.4byte gUnknown_83B1240
.4byte gUnknown_84865A0
.4byte gUnknown_83B1234
.4byte gUnknown_848720C
.4byte gUnknown_83B122C
.4byte gUnknown_84873BA
.4byte gUnknown_83B1224
.4byte gUnknown_848979C
.4byte gUnknown_83B121C
.4byte gUnknown_8489A9C
.4byte gUnknown_83B1214
.4byte gUnknown_848A0AC
.4byte gUnknown_83B1208
.4byte gUnknown_848AD10
.4byte gUnknown_83B1200
.4byte gUnknown_848AEE5
.4byte gUnknown_83B11F8
.4byte gUnknown_848D5D8
.4byte gUnknown_83B11F0
.4byte gUnknown_848D8D8
.4byte gUnknown_83B11E8
.4byte gUnknown_848E028
.4byte gUnknown_83B11DC
.4byte gUnknown_848ED84
.4byte gUnknown_83B11D4
.4byte gUnknown_848EF18
.4byte gUnknown_83B11CC
.4byte gUnknown_8490BF0
.4byte gUnknown_83B11C4
.4byte gUnknown_8490EF0
.4byte gUnknown_83B11BC
.4byte gUnknown_8491480
.4byte gUnknown_83B11B0
.4byte gUnknown_84922D0
.4byte gUnknown_83B11A8
.4byte gUnknown_8492474
.4byte gUnknown_83B11A0
.4byte gUnknown_8494A68
.4byte gUnknown_83B1198
.4byte gUnknown_8494D68
.4byte gUnknown_83B1190
.4byte gUnknown_8494EF8
.4byte gUnknown_83B1184
.4byte gUnknown_8495DD0
.4byte gUnknown_83B117C
.4byte gUnknown_8495F6F
.4byte gUnknown_83B1174
.4byte gUnknown_8499554

.4byte gUnknown_83B116C
.4byte banfont_SIRO
.4byte gUnknown_83B1164
.4byte banrpal
.4byte gUnknown_83B115C
.4byte colvec_SIRO
.4byte gUnknown_83B1154
.4byte etcfont
.4byte gUnknown_83B1148
.4byte etcfonta_SIRO
.4byte gUnknown_83B113C
.4byte fixedmap_SIRO
.4byte gUnknown_83B1134
.4byte hp5font
.4byte gUnknown_83B112C
.4byte itempat_SIRO
.4byte gUnknown_83B1124
.4byte jyochu_SIRO
.4byte gUnknown_83B111C
.4byte levfont_SIRO
.4byte gUnknown_83B1110
.4byte Mapparam_SIRO @ DungeonMasterTable SIRO
.4byte gUnknown_83B1108
.4byte PartnerDialogue0SIRO
.4byte gUnknown_83B1100
.4byte PartnerDialogue1SIRO
.4byte gUnknown_83B10F8
.4byte PartnerDialogue10SIRO
.4byte gUnknown_83B10F0
.4byte PartnerDialogue11SIRO
.4byte gUnknown_83B10E8
.4byte PartnerDialogue12SIRO
.4byte gUnknown_83B10E0
.4byte PartnerDialogue13SIRO
.4byte gUnknown_83B10D8
.4byte PartnerDialogue14SIRO
.4byte gUnknown_83B10D0
.4byte PartnerDialogue15SIRO
.4byte gUnknown_83B10C8
.4byte PartnerDialogue16SIRO
.4byte gUnknown_83B10C0
.4byte PartnerDialogue17SIRO
.4byte gUnknown_83B10B8
.4byte PartnerDialogue18SIRO
.4byte gUnknown_83B10B0
.4byte PartnerDialogue19SIRO
.4byte gUnknown_83B10A8
.4byte PartnerDialogue2SIRO
.4byte gUnknown_83B10A0
.4byte PartnerDialogue20SIRO
.4byte gUnknown_83B1098
.4byte PartnerDialogue21SIRO
.4byte gUnknown_83B1090
.4byte PartnerDialogue22SIRO
.4byte gUnknown_83B1088
.4byte PartnerDialogue23SIRO
.4byte gUnknown_83B1080
.4byte PartnerDialogue24SIRO
.4byte gUnknown_83B1078
.4byte PartnerDialogue25SIRO
.4byte gUnknown_83B1070
.4byte PartnerDialogue26SIRO
.4byte gUnknown_83B1068
.4byte PartnerDialogue27SIRO
.4byte gUnknown_83B1060
.4byte PartnerDialogue28SIRO
.4byte gUnknown_83B1058
.4byte PartnerDialogue29SIRO
.4byte gUnknown_83B1050
.4byte PartnerDialogue3SIRO
.4byte gUnknown_83B1048
.4byte PartnerDialogue30SIRO
.4byte gUnknown_83B1040
.4byte PartnerDialogue31SIRO
.4byte gUnknown_83B1038
.4byte PartnerDialogue32SIRO
.4byte gUnknown_83B1030
.4byte PartnerDialogue33SIRO
.4byte gUnknown_83B1028
.4byte PartnerDialogue34SIRO
.4byte gUnknown_83B1020
.4byte PartnerDialogue35SIRO
.4byte gUnknown_83B1018
.4byte PartnerDialogue36SIRO
.4byte gUnknown_83B1010
.4byte PartnerDialogue37SIRO
.4byte gUnknown_83B1008
.4byte PartnerDialogue38SIRO
.4byte gUnknown_83B1000
.4byte PartnerDialogue39SIRO
.4byte gUnknown_83B0FF8
.4byte PartnerDialogue4SIRO
.4byte gUnknown_83B0FF0
.4byte PartnerDialogue40SIRO
.4byte gUnknown_83B0FE8
.4byte PartnerDialogue41SIRO
.4byte gUnknown_83B0FE0
.4byte PartnerDialogue42SIRO
.4byte gUnknown_83B0FD8
.4byte PartnerDialogue5SIRO
.4byte gUnknown_83B0FD0
.4byte PartnerDialogue6SIRO
.4byte gUnknown_83B0FC8
.4byte PartnerDialogue7SIRO
.4byte gUnknown_83B0FC0
.4byte PartnerDialogue8SIRO
.4byte gUnknown_83B0FB8
.4byte PartnerDialogue9SIRO
.4byte gUnknown_83B0FB0
.4byte PartnerConversion0SIRO
.4byte gUnknown_83B0FA8
.4byte PartnerConversion1SIRO
.4byte gUnknown_83B0FA0
.4byte PartnerConversion10SIRO
.4byte gUnknown_83B0F98
.4byte PartnerConversion11SIRO
.4byte gUnknown_83B0F90
.4byte PartnerConversion12SIRO
.4byte gUnknown_83B0F88
.4byte PartnerConversion13SIRO
.4byte gUnknown_83B0F80
.4byte PartnerConversion14SIRO
.4byte gUnknown_83B0F78
.4byte PartnerConversion15SIRO
.4byte gUnknown_83B0F70
.4byte PartnerConversion16SIRO
.4byte gUnknown_83B0F68
.4byte PartnerConversion17SIRO
.4byte gUnknown_83B0F60
.4byte PartnerConversion18SIRO
.4byte gUnknown_83B0F58
.4byte PartnerConversion19SIRO
.4byte talkp2_string
.4byte PartnerConversion2SIRO
.4byte talkp20_string
.4byte PartnerConversion20SIRO
.4byte talkp21_string
.4byte PartnerConversion21SIRO
.4byte talkp22_string
.4byte PartnerConversion22SIRO
.4byte talkp23_string
.4byte PartnerConversion23SIRO
.4byte talkp24_string
.4byte PartnerConversion24SIRO
.4byte talkp25_string
.4byte PartnerConversion25SIRO
.4byte talkp26_string
.4byte PartnerConversion26SIRO
.4byte talkp27_string
.4byte PartnerConversion27SIRO
.4byte talkp28_string
.4byte PartnerConversion28SIRO
.4byte talkp29_string
.4byte PartnerConversion29SIRO
.4byte talkp3_string
.4byte PartnerConversion3SIRO
.4byte talkp30_string
.4byte PartnerConversion30SIRO
.4byte talkp31_string
.4byte PartnerConversion31SIRO
.4byte talkp32_string
.4byte PartnerConversion32SIRO
.4byte talkp33_string
.4byte PartnerConversion33SIRO
.4byte talkp34_string
.4byte PartnerConversion34SIRO
.4byte talkp35_string
.4byte PartnerConversion35SIRO
.4byte talkp36_string
.4byte PartnerConversion36SIRO
.4byte talkp37_string
.4byte PartnerConversion37SIRO
.4byte talkp38_string
.4byte PartnerConversion38SIRO
.4byte talkp39_string
.4byte PartnerConversion39SIRO
.4byte talkp4_string
.4byte PartnerConversion4SIRO
.4byte talkp40_string
.4byte PartnerConversion40SIRO
.4byte talkp41_string
.4byte PartnerConversion41SIRO
.4byte talkp42_string
.4byte PartnerConversion42SIRO
.4byte talkp5_string
.4byte PartnerConversion5SIRO
.4byte talkp6_string
.4byte PartnerConversion6SIRO
.4byte talkp7_string
.4byte PartnerConversion7SIRO
.4byte talkp8_string
.4byte PartnerConversion8SIRO
.4byte talkp9_string
.4byte PartnerConversion9SIRO
.4byte trappat_string
.4byte Trappat_SIRO
.4byte zmappat_string
.4byte Zmappat_SIRO

.global zmappat_string
zmappat_string:
.string "zmappat\0"

.global trappat_string
trappat_string:
.string "trappat\0"

.global talkp9_string
talkp9_string:
.string "talkp9\0"
.align 2,0

.global talkp8_string
talkp8_string:
.string "talkp8\0"
.align 2,0

.global talkp7_string
talkp7_string:
.string "talkp7\0"
.align 2,0

.global talkp6_string
talkp6_string:
.string "talkp6\0"
.align 2,0

.global talkp5_string
talkp5_string:
.string "talkp5\0"
.align 2,0

.global talkp42_string
talkp42_string:
.string "talkp42\0"
.global talkp41_string
talkp41_string:
.string "talkp41\0"
.global talkp40_string
talkp40_string:
.string "talkp40\0"
.global talkp4_string
talkp4_string:
.string "talkp4\0"
.align 2,0

.global talkp39_string
talkp39_string:
.string "talkp39\0"
.global talkp38_string
talkp38_string:
.string "talkp38\0"
.global talkp37_string
talkp37_string:
.string "talkp37\0"
.global talkp36_string
talkp36_string:
.string "talkp36\0"
.global talkp35_string
talkp35_string:
.string "talkp35\0"
.global talkp34_string
talkp34_string:
.string "talkp34\0"
.global talkp33_string
talkp33_string:
.string "talkp33\0"
.global talkp32_string
talkp32_string:
.string "talkp32\0"
.global talkp31_string
talkp31_string:
.string "talkp31\0"
.global talkp30_string
talkp30_string:
.string "talkp30\0"
.global talkp3_string
talkp3_string:
.string "talkp3\0"
.align 2,0

.global talkp29_string
talkp29_string:
.string "talkp29\0"
.global talkp28_string
talkp28_string:
.string "talkp28\0"
.global talkp27_string
talkp27_string:
.string "talkp27\0"
.global talkp26_string
talkp26_string:
.string "talkp26\0"
.global talkp25_string
talkp25_string:
.string "talkp25\0"
.global talkp24_string
talkp24_string:
.string "talkp24\0"
.global talkp23_string
talkp23_string:
.string "talkp23\0"
.global talkp22_string
talkp22_string:
.string "talkp22\0"
.global talkp21_string
talkp21_string:
.string "talkp21\0"
.global talkp20_string
talkp20_string:
.string "talkp20\0"
.global talkp2_string
talkp2_string:
.string "talkp2\0"
.align 2,0

.global gUnknown_83B0F58
gUnknown_83B0F58:
.string "talkp19\0"
.global gUnknown_83B0F60
gUnknown_83B0F60:
.string "talkp18\0"
.global gUnknown_83B0F68
gUnknown_83B0F68:
.string "talkp17\0"
.global gUnknown_83B0F70
gUnknown_83B0F70:
.string "talkp16\0"
.global gUnknown_83B0F78
gUnknown_83B0F78:
.string "talkp15\0"
.global gUnknown_83B0F80
gUnknown_83B0F80:
.string "talkp14\0"
.global gUnknown_83B0F88
gUnknown_83B0F88:
.string "talkp13\0"
.global gUnknown_83B0F90
gUnknown_83B0F90:
.string "talkp12\0"
.global gUnknown_83B0F98
gUnknown_83B0F98:
.string "talkp11\0"
.global gUnknown_83B0FA0
gUnknown_83B0FA0:
.string "talkp10\0"
.global gUnknown_83B0FA8
gUnknown_83B0FA8:
.string "talkp1\0"
.align 2,0

.global gUnknown_83B0FB0
gUnknown_83B0FB0:
.string "talkp0\0"
.align 2,0

.global gUnknown_83B0FB8
gUnknown_83B0FB8:
.string "talk9\0"
.align 2,0
.global gUnknown_83B0FC0
gUnknown_83B0FC0:
.string "talk8\0"
.align 2,0
.global gUnknown_83B0FC8
gUnknown_83B0FC8:
.string "talk7\0"
.align 2,0
.global gUnknown_83B0FD0
gUnknown_83B0FD0:
.string "talk6\0"
.align 2,0
.global gUnknown_83B0FD8
gUnknown_83B0FD8:
.string "talk5\0"
.align 2,0

.global gUnknown_83B0FE0
gUnknown_83B0FE0:
.string "talk42\0"
.align 2,0
.global gUnknown_83B0FE8
gUnknown_83B0FE8:
.string "talk41\0"
.align 2,0
.global gUnknown_83B0FF0
gUnknown_83B0FF0:
.string "talk40\0"
.align 2,0
.global gUnknown_83B0FF8
gUnknown_83B0FF8:
.string "talk4\0"
.align 2,0


.global gUnknown_83B1000
gUnknown_83B1000:
.string "talk39\0"
.align 2,0
.global gUnknown_83B1008
gUnknown_83B1008:
.string "talk38\0"
.align 2,0
.global gUnknown_83B1010
gUnknown_83B1010:
.string "talk37\0"
.align 2,0
.global gUnknown_83B1018
gUnknown_83B1018:
.string "talk36\0"
.align 2,0
.global gUnknown_83B1020
gUnknown_83B1020:
.string "talk35\0"
.align 2,0
.global gUnknown_83B1028
gUnknown_83B1028:
.string "talk34\0"
.align 2,0
.global gUnknown_83B1030
gUnknown_83B1030:
.string "talk33\0"
.align 2,0
.global gUnknown_83B1038
gUnknown_83B1038:
.string "talk32\0"
.align 2,0
.global gUnknown_83B1040
gUnknown_83B1040:
.string "talk31\0"
.align 2,0
.global gUnknown_83B1048
gUnknown_83B1048:
.string "talk30\0"
.align 2,0
.global gUnknown_83B1050
gUnknown_83B1050:
.string "talk3\0"
.align 2,0

.global gUnknown_83B1058
gUnknown_83B1058:
.string "talk29\0"
.align 2,0
.global gUnknown_83B1060
gUnknown_83B1060:
.string "talk28\0"
.align 2,0
.global gUnknown_83B1068
gUnknown_83B1068:
.string "talk27\0"
.align 2,0
.global gUnknown_83B1070
gUnknown_83B1070:
.string "talk26\0"
.align 2,0
.global gUnknown_83B1078
gUnknown_83B1078:
.string "talk25\0"
.align 2,0
.global gUnknown_83B1080
gUnknown_83B1080:
.string "talk24\0"
.align 2,0
.global gUnknown_83B1088
gUnknown_83B1088:
.string "talk23\0"
.align 2,0
.global gUnknown_83B1090
gUnknown_83B1090:
.string "talk22\0"
.align 2,0
.global gUnknown_83B1098
gUnknown_83B1098:
.string "talk21\0"
.align 2,0
.global gUnknown_83B10A0
gUnknown_83B10A0:
.string "talk20\0"
.align 2,0
.global gUnknown_83B10A8
gUnknown_83B10A8:
.string "talk2\0"
.align 2,0

.global gUnknown_83B10B0
gUnknown_83B10B0:
.string "talk19\0"
.align 2,0
.global gUnknown_83B10B8
gUnknown_83B10B8:
.string "talk18\0"
.align 2,0
.global gUnknown_83B10C0
gUnknown_83B10C0:
.string "talk17\0"
.align 2,0
.global gUnknown_83B10C8
gUnknown_83B10C8:
.string "talk16\0"
.align 2,0
.global gUnknown_83B10D0
gUnknown_83B10D0:
.string "talk15\0"
.align 2,0
.global gUnknown_83B10D8
gUnknown_83B10D8:
.string "talk14\0"
.align 2,0
.global gUnknown_83B10E0
gUnknown_83B10E0:
.string "talk13\0"
.align 2,0
.global gUnknown_83B10E8
gUnknown_83B10E8:
.string "talk12\0"
.align 2,0
.global gUnknown_83B10F0
gUnknown_83B10F0:
.string "talk11\0"
.align 2,0
.global gUnknown_83B10F8
gUnknown_83B10F8:
.string "talk10\0"
.align 2,0
.global gUnknown_83B1100
gUnknown_83B1100:
.string "talk1\0"
.align 2,0

.global gUnknown_83B1108
gUnknown_83B1108:
.string "talk0\0"
.align 2,0

.global gUnknown_83B1110
gUnknown_83B1110:
.string "mapparam\0"
.align 2,0
.global gUnknown_83B111C
gUnknown_83B111C:
.string "levfont\0"
.align 2,0
.global gUnknown_83B1124
gUnknown_83B1124:
.string "jyochu\0"
.align 2,0
.global gUnknown_83B112C
gUnknown_83B112C:
.string "itempat\0"
.align 2,0
.global gUnknown_83B1134
gUnknown_83B1134:
.string "hp5font\0"
.align 2,0
.global gUnknown_83B113C
gUnknown_83B113C:
.string "fixedmap\0"
.align 2,0
.global gUnknown_83B1148
gUnknown_83B1148:
.string "etcfonta\0"
.align 2,0
.global gUnknown_83B1154
gUnknown_83B1154:
.string "etcfont\0"
.align 2,0
.global gUnknown_83B115C
gUnknown_83B115C:
.string "colvec\0"
.align 2,0
.global gUnknown_83B1164
gUnknown_83B1164:
.string "banrpal\0"
.align 2,0
.global gUnknown_83B116C
gUnknown_83B116C:
.string "banfont\0"
.align 2,0

@ B__ Groups
.global gUnknown_83B1174
gUnknown_83B1174:
.string "b75pal\0\0"
.global gUnknown_83B117C
gUnknown_83B117C:
.string "b75fon\0\0"
.global gUnknown_83B1184
gUnknown_83B1184:
.string "b75emap0\0\0\0\0"
.global gUnknown_83B1190
gUnknown_83B1190:
.string "b75cel\0\0"
.global gUnknown_83B1198
gUnknown_83B1198:
.string "b75canm\0"
.global gUnknown_83B11A0
gUnknown_83B11A0:
.string "b74pal\0\0"
.global gUnknown_83B11A8
gUnknown_83B11A8:
.string "b74fon\0\0"
.global gUnknown_83B11B0
gUnknown_83B11B0:
.string "b74emap0\0\0\0\0"
.global gUnknown_83B11BC
gUnknown_83B11BC:
.string "b74cel\0\0"
.global gUnknown_83B11C4
gUnknown_83B11C4:
.string "b74canm\0"
.global gUnknown_83B11CC
gUnknown_83B11CC:
.string "b73pal\0\0"
.global gUnknown_83B11D4
gUnknown_83B11D4:
.string "b73fon\0\0"
.global gUnknown_83B11DC
gUnknown_83B11DC:
.string "b73emap0\0\0\0\0"
.global gUnknown_83B11E8
gUnknown_83B11E8:
.string "b73cel\0\0"
.global gUnknown_83B11F0
gUnknown_83B11F0:
.string "b73canm\0"
.global gUnknown_83B11F8
gUnknown_83B11F8:
.string "b72pal\0\0"
.global gUnknown_83B1200
gUnknown_83B1200:
.string "b72fon\0\0"
.global gUnknown_83B1208
gUnknown_83B1208:
.string "b72emap0\0\0\0\0"
.global gUnknown_83B1214
gUnknown_83B1214:
.string "b72cel\0\0"
.global gUnknown_83B121C
gUnknown_83B121C:
.string "b72canm\0"
.global gUnknown_83B1224
gUnknown_83B1224:
.string "b71pal\0\0"
.global gUnknown_83B122C
gUnknown_83B122C:
.string "b71fon\0\0"
.global gUnknown_83B1234
gUnknown_83B1234:
.string "b71emap0\0\0\0\0"
.global gUnknown_83B1240
gUnknown_83B1240:
.string "b71cel\0\0"
.global gUnknown_83B1248
gUnknown_83B1248:
.string "b71canm\0"
.global gUnknown_83B1250
gUnknown_83B1250:
.string "b70pal\0\0"
.global gUnknown_83B1258
gUnknown_83B1258:
.string "b70fon\0\0"
.global gUnknown_83B1260
gUnknown_83B1260:
.string "b70emap0\0\0\0\0"
.global gUnknown_83B126C
gUnknown_83B126C:
.string "b70cel\0\0"
.global gUnknown_83B1274
gUnknown_83B1274:
.string "b70canm\0"
.global gUnknown_83B127C
gUnknown_83B127C:
.string "b69pal\0\0"
.global gUnknown_83B1284
gUnknown_83B1284:
.string "b69fon\0\0"
.global gUnknown_83B128C
gUnknown_83B128C:
.string "b69emap0\0\0\0\0"
.global gUnknown_83B1298
gUnknown_83B1298:
.string "b69cel\0\0"
.global gUnknown_83B12A0
gUnknown_83B12A0:
.string "b69canm\0"
.global gUnknown_83B12A8
gUnknown_83B12A8:
.string "b68pal\0\0"
.global gUnknown_83B12B0
gUnknown_83B12B0:
.string "b68fon\0\0"
.global gUnknown_83B12B8
gUnknown_83B12B8:
.string "b68emap0\0\0\0\0"
.global gUnknown_83B12C4
gUnknown_83B12C4:
.string "b68cel\0\0"
.global gUnknown_83B12CC
gUnknown_83B12CC:
.string "b68canm\0"
.global gUnknown_83B12D4
gUnknown_83B12D4:
.string "b67pal\0\0"
.global gUnknown_83B12DC
gUnknown_83B12DC:
.string "b67fon\0\0"
.global gUnknown_83B12E4
gUnknown_83B12E4:
.string "b67emap0\0\0\0\0"
.global gUnknown_83B12F0
gUnknown_83B12F0:
.string "b67cel\0\0"
.global gUnknown_83B12F8
gUnknown_83B12F8:
.string "b67canm\0"
.global gUnknown_83B1300
gUnknown_83B1300:
.string "b66pal\0\0"
.global gUnknown_83B1308
gUnknown_83B1308:
.string "b66fon\0\0"
.global gUnknown_83B1310
gUnknown_83B1310:
.string "b66emap0\0\0\0\0"
.global gUnknown_83B131C
gUnknown_83B131C:
.string "b66cel\0\0"
.global gUnknown_83B1324
gUnknown_83B1324:
.string "b66canm\0"
.global gUnknown_83B132C
gUnknown_83B132C:
.string "b65pal\0\0"
.global gUnknown_83B1334
gUnknown_83B1334:
.string "b65fon\0\0"
.global gUnknown_83B133C
gUnknown_83B133C:
.string "b65emap0\0\0\0\0"
.global gUnknown_83B1348
gUnknown_83B1348:
.string "b65cel\0\0"
.global gUnknown_83B1350
gUnknown_83B1350:
.string "b65canm\0"
.global gUnknown_83B1358
gUnknown_83B1358:
.string "b64pal\0\0"
.global gUnknown_83B1360
gUnknown_83B1360:
.string "b64fon\0\0"
.global gUnknown_83B1368
gUnknown_83B1368:
.string "b64emap0\0\0\0\0"
.global gUnknown_83B1374
gUnknown_83B1374:
.string "b64cel\0\0"
.global gUnknown_83B137C
gUnknown_83B137C:
.string "b64canm\0"
.global gUnknown_83B1384
gUnknown_83B1384:
.string "b63pal\0\0"
.global gUnknown_83B138C
gUnknown_83B138C:
.string "b63fon\0\0"
.global gUnknown_83B1394
gUnknown_83B1394:
.string "b63cex\0\0"
.global gUnknown_83B139C
gUnknown_83B139C:
.string "b63cel\0\0"
.global gUnknown_83B13A4
gUnknown_83B13A4:
.string "b63canm\0"
.global gUnknown_83B13AC
gUnknown_83B13AC:
.string "b62pal\0\0"
.global gUnknown_83B13B4
gUnknown_83B13B4:
.string "b62fon\0\0"
.global gUnknown_83B13BC
gUnknown_83B13BC:
.string "b62cex\0\0"
.global gUnknown_83B13C4
gUnknown_83B13C4:
.string "b62cel\0\0"
.global gUnknown_83B13CC
gUnknown_83B13CC:
.string "b62canm\0"
.global gUnknown_83B13D4
gUnknown_83B13D4:
.string "b61pal\0\0"
.global gUnknown_83B13DC
gUnknown_83B13DC:
.string "b61canm\0"
.global gUnknown_83B13E4
gUnknown_83B13E4:
.string "b60pal\0\0"
.global gUnknown_83B13EC
gUnknown_83B13EC:
.string "b60fon\0\0"
.global gUnknown_83B13F4
gUnknown_83B13F4:
.string "b60cex\0\0"
.global gUnknown_83B13FC
gUnknown_83B13FC:
.string "b60cel\0\0"
.global gUnknown_83B1404
gUnknown_83B1404:
.string "b60canm\0"
.global gUnknown_83B140C
gUnknown_83B140C:
.string "b59pal\0\0"
.global gUnknown_83B1414
gUnknown_83B1414:
.string "b59fon\0\0"
.global gUnknown_83B141C
gUnknown_83B141C:
.string "b59cex\0\0"
.global gUnknown_83B1424
gUnknown_83B1424:
.string "b59cel\0\0"
.global gUnknown_83B142C
gUnknown_83B142C:
.string "b59canm\0"
.global gUnknown_83B1434
gUnknown_83B1434:
.string "b58pal\0\0"
.global gUnknown_83B143C
gUnknown_83B143C:
.string "b58canm\0"
.global gUnknown_83B1444
gUnknown_83B1444:
.string "b57pal\0\0"
.global gUnknown_83B144C
gUnknown_83B144C:
.string "b57canm\0"
.global gUnknown_83B1454
gUnknown_83B1454:
.string "b56pal\0\0"
.global gUnknown_83B145C
gUnknown_83B145C:
.string "b56fon\0\0"
.global gUnknown_83B1464
gUnknown_83B1464:
.string "b56cex\0\0"
.global gUnknown_83B146C
gUnknown_83B146C:
.string "b56cel\0\0"
.global gUnknown_83B1474
gUnknown_83B1474:
.string "b56canm\0"
.global gUnknown_83B147C
gUnknown_83B147C:
.string "b55pal\0\0"
.global gUnknown_83B1484
gUnknown_83B1484:
.string "b55fon\0\0"
.global gUnknown_83B148C
gUnknown_83B148C:
.string "b55cex\0\0"
.global gUnknown_83B1494
gUnknown_83B1494:
.string "b55cel\0\0"
.global gUnknown_83B149C
gUnknown_83B149C:
.string "b55canm\0"
.global gUnknown_83B14A4
gUnknown_83B14A4:
.string "b54pal\0\0"
.global gUnknown_83B14AC
gUnknown_83B14AC:
.string "b54fon\0\0"
.global gUnknown_83B14B4
gUnknown_83B14B4:
.string "b54cex\0\0"
.global gUnknown_83B14BC
gUnknown_83B14BC:
.string "b54cel\0\0"
.global gUnknown_83B14C4
gUnknown_83B14C4:
.string "b54canm\0"
.global gUnknown_83B14CC
gUnknown_83B14CC:
.string "b53pal\0\0"
.global gUnknown_83B14D4
gUnknown_83B14D4:
.string "b53fon\0\0"
.global gUnknown_83B14DC
gUnknown_83B14DC:
.string "b53cex\0\0"
.global gUnknown_83B14E4
gUnknown_83B14E4:
.string "b53cel\0\0"
.global gUnknown_83B14EC
gUnknown_83B14EC:
.string "b53canm\0"
.global gUnknown_83B14F4
gUnknown_83B14F4:
.string "b52pal\0\0"
.global gUnknown_83B14FC
gUnknown_83B14FC:
.string "b52fon\0\0"
.global gUnknown_83B1504
gUnknown_83B1504:
.string "b52cex\0\0"
.global gUnknown_83B150C
gUnknown_83B150C:
.string "b52cel\0\0"
.global gUnknown_83B1514
gUnknown_83B1514:
.string "b52canm\0"
.global gUnknown_83B151C
gUnknown_83B151C:
.string "b51pal\0\0"
.global gUnknown_83B1524
gUnknown_83B1524:
.string "b51fon\0\0"
.global gUnknown_83B152C
gUnknown_83B152C:
.string "b51cex\0\0"
.global gUnknown_83B1534
gUnknown_83B1534:
.string "b51cel\0\0"
.global gUnknown_83B153C
gUnknown_83B153C:
.string "b51canm\0"
.global gUnknown_83B1544
gUnknown_83B1544:
.string "b50pal\0\0"
.global gUnknown_83B154C
gUnknown_83B154C:
.string "b50fon\0\0"
.global gUnknown_83B1554
gUnknown_83B1554:
.string "b50cex\0\0"
.global gUnknown_83B155C
gUnknown_83B155C:
.string "b50cel\0\0"
.global gUnknown_83B1564
gUnknown_83B1564:
.string "b50canm\0"
.global gUnknown_83B156C
gUnknown_83B156C:
.string "b49pal\0\0"
.global gUnknown_83B1574
gUnknown_83B1574:
.string "b49fon\0\0"
.global gUnknown_83B157C
gUnknown_83B157C:
.string "b49cex\0\0"
.global gUnknown_83B1584
gUnknown_83B1584:
.string "b49cel\0\0"
.global gUnknown_83B158C
gUnknown_83B158C:
.string "b49canm\0"
.global gUnknown_83B1594
gUnknown_83B1594:
.string "b48pal\0\0"
.global gUnknown_83B159C
gUnknown_83B159C:
.string "b48fon\0\0"
.global gUnknown_83B15A4
gUnknown_83B15A4:
.string "b48cex\0\0"
.global gUnknown_83B15AC
gUnknown_83B15AC:
.string "b48cel\0\0"
.global gUnknown_83B15B4
gUnknown_83B15B4:
.string "b48canm\0"
.global gUnknown_83B15BC
gUnknown_83B15BC:
.string "b47pal\0\0"
.global gUnknown_83B15C4
gUnknown_83B15C4:
.string "b47fon\0\0"
.global gUnknown_83B15CC
gUnknown_83B15CC:
.string "b47cex\0\0"
.global gUnknown_83B15D4
gUnknown_83B15D4:
.string "b47cel\0\0"
.global gUnknown_83B15DC
gUnknown_83B15DC:
.string "b47canm\0"
.global gUnknown_83B15E4
gUnknown_83B15E4:
.string "b46pal\0\0"
.global gUnknown_83B15EC
gUnknown_83B15EC:
.string "b46fon\0\0"
.global gUnknown_83B15F4
gUnknown_83B15F4:
.string "b46cex\0\0"
.global gUnknown_83B15FC
gUnknown_83B15FC:
.string "b46cel\0\0"
.global gUnknown_83B1604
gUnknown_83B1604:
.string "b46canm\0"
.global gUnknown_83B160C
gUnknown_83B160C:
.string "b45pal\0\0"
.global gUnknown_83B1614
gUnknown_83B1614:
.string "b45fon\0\0"
.global gUnknown_83B161C
gUnknown_83B161C:
.string "b45cex\0\0"
.global gUnknown_83B1624
gUnknown_83B1624:
.string "b45cel\0\0"
.global gUnknown_83B162C
gUnknown_83B162C:
.string "b45canm\0"
.global gUnknown_83B1634
gUnknown_83B1634:
.string "b44pal\0\0"
.global gUnknown_83B163C
gUnknown_83B163C:
.string "b44fon\0\0"
.global gUnknown_83B1644
gUnknown_83B1644:
.string "b44cex\0\0"
.global gUnknown_83B164C
gUnknown_83B164C:
.string "b44cel\0\0"
.global gUnknown_83B1654
gUnknown_83B1654:
.string "b44canm\0"
.global gUnknown_83B165C
gUnknown_83B165C:
.string "b43pal\0\0"
.global gUnknown_83B1664
gUnknown_83B1664:
.string "b43fon\0\0"
.global gUnknown_83B166C
gUnknown_83B166C:
.string "b43cex\0\0"
.global gUnknown_83B1674
gUnknown_83B1674:
.string "b43cel\0\0"
.global gUnknown_83B167C
gUnknown_83B167C:
.string "b43canm\0"
.global gUnknown_83B1684
gUnknown_83B1684:
.string "b42pal\0\0"
.global gUnknown_83B168C
gUnknown_83B168C:
.string "b42fon\0\0"
.global gUnknown_83B1694
gUnknown_83B1694:
.string "b42cex\0\0"
.global gUnknown_83B169C
gUnknown_83B169C:
.string "b42cel\0\0"
.global gUnknown_83B16A4
gUnknown_83B16A4:
.string "b42canm\0"
.global gUnknown_83B16AC
gUnknown_83B16AC:
.string "b41pal\0\0"
.global gUnknown_83B16B4
gUnknown_83B16B4:
.string "b41fon\0\0"
.global gUnknown_83B16BC
gUnknown_83B16BC:
.string "b41cex\0\0"
.global gUnknown_83B16C4
gUnknown_83B16C4:
.string "b41cel\0\0"
.global gUnknown_83B16CC
gUnknown_83B16CC:
.string "b41canm\0"
.global gUnknown_83B16D4
gUnknown_83B16D4:
.string "b40pal\0\0"
.global gUnknown_83B16DC
gUnknown_83B16DC:
.string "b40fon\0\0"
.global gUnknown_83B16E4
gUnknown_83B16E4:
.string "b40cex\0\0"
.global gUnknown_83B16EC
gUnknown_83B16EC:
.string "b40cel\0\0"
.global gUnknown_83B16F4
gUnknown_83B16F4:
.string "b40canm\0"
.global gUnknown_83B16FC
gUnknown_83B16FC:
.string "b39pal\0\0"
.global gUnknown_83B1704
gUnknown_83B1704:
.string "b39fon\0\0"
.global gUnknown_83B170C
gUnknown_83B170C:
.string "b39cex\0\0"
.global gUnknown_83B1714
gUnknown_83B1714:
.string "b39cel\0\0"
.global gUnknown_83B171C
gUnknown_83B171C:
.string "b39canm\0"
.global gUnknown_83B1724
gUnknown_83B1724:
.string "b38pal\0\0"
.global gUnknown_83B172C
gUnknown_83B172C:
.string "b38canm\0"
.global gUnknown_83B1734
gUnknown_83B1734:
.string "b37pal\0\0"
.global gUnknown_83B173C
gUnknown_83B173C:
.string "b37fon\0\0"
.global gUnknown_83B1744
gUnknown_83B1744:
.string "b37cex\0\0"
.global gUnknown_83B174C
gUnknown_83B174C:
.string "b37cel\0\0"
.global gUnknown_83B1754
gUnknown_83B1754:
.string "b37canm\0"
.global gUnknown_83B175C
gUnknown_83B175C:
.string "b36pal\0\0"
.global gUnknown_83B1764
gUnknown_83B1764:
.string "b36fon\0\0"
.global gUnknown_83B176C
gUnknown_83B176C:
.string "b36cex\0\0"
.global gUnknown_83B1774
gUnknown_83B1774:
.string "b36cel\0\0"
.global gUnknown_83B177C
gUnknown_83B177C:
.string "b36canm\0"
.global gUnknown_83B1784
gUnknown_83B1784:
.string "b35pal\0\0"
.global gUnknown_83B178C
gUnknown_83B178C:
.string "b35fon\0\0"
.global gUnknown_83B1794
gUnknown_83B1794:
.string "b35cex\0\0"
.global gUnknown_83B179C
gUnknown_83B179C:
.string "b35cel\0\0"
.global gUnknown_83B17A4
gUnknown_83B17A4:
.string "b35canm\0"
.global gUnknown_83B17AC
gUnknown_83B17AC:
.string "b34pal\0\0"
.global gUnknown_83B17B4
gUnknown_83B17B4:
.string "b34canm\0"
.global gUnknown_83B17BC
gUnknown_83B17BC:
.string "b33pal\0\0"
.global gUnknown_83B17C4
gUnknown_83B17C4:
.string "b33fon\0\0"
.global gUnknown_83B17CC
gUnknown_83B17CC:
.string "b33cex\0\0"
.global gUnknown_83B17D4
gUnknown_83B17D4:
.string "b33cel\0\0"
.global gUnknown_83B17DC
gUnknown_83B17DC:
.string "b33canm\0"
.global gUnknown_83B17E4
gUnknown_83B17E4:
.string "b32pal\0\0"
.global gUnknown_83B17EC
gUnknown_83B17EC:
.string "b32fon\0\0"
.global gUnknown_83B17F4
gUnknown_83B17F4:
.string "b32cex\0\0"
.global gUnknown_83B17FC
gUnknown_83B17FC:
.string "b32cel\0\0"
.global gUnknown_83B1804
gUnknown_83B1804:
.string "b32canm\0"
.global gUnknown_83B180C
gUnknown_83B180C:
.string "b31pal\0\0"
.global gUnknown_83B1814
gUnknown_83B1814:
.string "b31fon\0\0"
.global gUnknown_83B181C
gUnknown_83B181C:
.string "b31cex\0\0"
.global gUnknown_83B1824
gUnknown_83B1824:
.string "b31cel\0\0"
.global gUnknown_83B182C
gUnknown_83B182C:
.string "b31canm\0"
.global gUnknown_83B1834
gUnknown_83B1834:
.string "b30pal\0\0"
.global gUnknown_83B183C
gUnknown_83B183C:
.string "b30fon\0\0"
.global gUnknown_83B1844
gUnknown_83B1844:
.string "b30cex\0\0"
.global gUnknown_83B184C
gUnknown_83B184C:
.string "b30cel\0\0"
.global gUnknown_83B1854
gUnknown_83B1854:
.string "b30canm\0"
.global gUnknown_83B185C
gUnknown_83B185C:
.string "b29pal\0\0"
.global gUnknown_83B1864
gUnknown_83B1864:
.string "b29fon\0\0"
.global gUnknown_83B186C
gUnknown_83B186C:
.string "b29cex\0\0"
.global gUnknown_83B1874
gUnknown_83B1874:
.string "b29cel\0\0"
.global gUnknown_83B187C
gUnknown_83B187C:
.string "b29canm\0"
.global gUnknown_83B1884
gUnknown_83B1884:
.string "b28pal\0\0"
.global gUnknown_83B188C
gUnknown_83B188C:
.string "b28fon\0\0"
.global gUnknown_83B1894
gUnknown_83B1894:
.string "b28cex\0\0"
.global gUnknown_83B189C
gUnknown_83B189C:
.string "b28cel\0\0"
.global gUnknown_83B18A4
gUnknown_83B18A4:
.string "b28canm\0"
.global gUnknown_83B18AC
gUnknown_83B18AC:
.string "b27pal\0\0"
.global gUnknown_83B18B4
gUnknown_83B18B4:
.string "b27canm\0"
.global gUnknown_83B18BC
gUnknown_83B18BC:
.string "b26pal\0\0"
.global gUnknown_83B18C4
gUnknown_83B18C4:
.string "b26canm\0"
.global gUnknown_83B18CC
gUnknown_83B18CC:
.string "b25pal\0\0"
.global gUnknown_83B18D4
gUnknown_83B18D4:
.string "b25fon\0\0"
.global gUnknown_83B18DC
gUnknown_83B18DC:
.string "b25cex\0\0"
.global gUnknown_83B18E4
gUnknown_83B18E4:
.string "b25cel\0\0"
.global gUnknown_83B18EC
gUnknown_83B18EC:
.string "b25canm\0"
.global gUnknown_83B18F4
gUnknown_83B18F4:
.string "b24pal\0\0"
.global gUnknown_83B18FC
gUnknown_83B18FC:
.string "b24fon\0\0"
.global gUnknown_83B1904
gUnknown_83B1904:
.string "b24cex\0\0"
.global gUnknown_83B190C
gUnknown_83B190C:
.string "b24cel\0\0"
.global gUnknown_83B1914
gUnknown_83B1914:
.string "b24canm\0"
.global gUnknown_83B191C
gUnknown_83B191C:
.string "b23pal\0\0"
.global gUnknown_83B1924
gUnknown_83B1924:
.string "b23fon\0\0"
.global gUnknown_83B192C
gUnknown_83B192C:
.string "b23cex\0\0"
.global gUnknown_83B1934
gUnknown_83B1934:
.string "b23cel\0\0"
.global gUnknown_83B193C
gUnknown_83B193C:
.string "b23canm\0"
.global gUnknown_83B1944
gUnknown_83B1944:
.string "b22pal\0\0"
.global gUnknown_83B194C
gUnknown_83B194C:
.string "b22canm\0"
.global gUnknown_83B1954
gUnknown_83B1954:
.string "b21pal\0\0"
.global gUnknown_83B195C
gUnknown_83B195C:
.string "b21fon\0\0"
.global gUnknown_83B1964
gUnknown_83B1964:
.string "b21cex\0\0"
.global gUnknown_83B196C
gUnknown_83B196C:
.string "b21cel\0\0"
.global gUnknown_83B1974
gUnknown_83B1974:
.string "b21canm\0"
.global gUnknown_83B197C
gUnknown_83B197C:
.string "b20pal\0\0"
.global gUnknown_83B1984
gUnknown_83B1984:
.string "b20fon\0\0"
.global gUnknown_83B198C
gUnknown_83B198C:
.string "b20cex\0\0"
.global gUnknown_83B1994
gUnknown_83B1994:
.string "b20cel\0\0"
.global gUnknown_83B199C
gUnknown_83B199C:
.string "b20canm\0"
.global gUnknown_83B19A4
gUnknown_83B19A4:
.string "b19pal\0\0"
.global gUnknown_83B19AC
gUnknown_83B19AC:
.string "b19fon\0\0"
.global gUnknown_83B19B4
gUnknown_83B19B4:
.string "b19cex\0\0"
.global gUnknown_83B19BC
gUnknown_83B19BC:
.string "b19cel\0\0"
.global gUnknown_83B19C4
gUnknown_83B19C4:
.string "b19canm\0"
.global gUnknown_83B19CC
gUnknown_83B19CC:
.string "b18pal\0\0"
.global gUnknown_83B19D4
gUnknown_83B19D4:
.string "b18fon\0\0"
.global gUnknown_83B19DC
gUnknown_83B19DC:
.string "b18cex\0\0"
.global gUnknown_83B19E4
gUnknown_83B19E4:
.string "b18cel\0\0"
.global gUnknown_83B19EC
gUnknown_83B19EC:
.string "b18canm\0"
.global gUnknown_83B19F4
gUnknown_83B19F4:
.string "b17pal\0\0"
.global gUnknown_83B19FC
gUnknown_83B19FC:
.string "b17fon\0\0"
.global gUnknown_83B1A04
gUnknown_83B1A04:
.string "b17cex\0\0"
.global gUnknown_83B1A0C
gUnknown_83B1A0C:
.string "b17cel\0\0"
.global gUnknown_83B1A14
gUnknown_83B1A14:
.string "b17canm\0"
.global gUnknown_83B1A1C
gUnknown_83B1A1C:
.string "b16pal\0\0"
.global gUnknown_83B1A24
gUnknown_83B1A24:
.string "b16fon\0\0"
.global gUnknown_83B1A2C
gUnknown_83B1A2C:
.string "b16cex\0\0"
.global gUnknown_83B1A34
gUnknown_83B1A34:
.string "b16cel\0\0"
.global gUnknown_83B1A3C
gUnknown_83B1A3C:
.string "b16canm\0"
.global gUnknown_83B1A44
gUnknown_83B1A44:
.string "b15pal\0\0"
.global gUnknown_83B1A4C
gUnknown_83B1A4C:
.string "b15fon\0\0"
.global gUnknown_83B1A54
gUnknown_83B1A54:
.string "b15cex\0\0"
.global gUnknown_83B1A5C
gUnknown_83B1A5C:
.string "b15cel\0\0"
.global gUnknown_83B1A64
gUnknown_83B1A64:
.string "b15canm\0"
.global gUnknown_83B1A6C
gUnknown_83B1A6C:
.string "b14pal\0\0"
.global gUnknown_83B1A74
gUnknown_83B1A74:
.string "b14fon\0\0"
.global gUnknown_83B1A7C
gUnknown_83B1A7C:
.string "b14cex\0\0"
.global gUnknown_83B1A84
gUnknown_83B1A84:
.string "b14cel\0\0"
.global gUnknown_83B1A8C
gUnknown_83B1A8C:
.string "b14canm\0"
.global gUnknown_83B1A94
gUnknown_83B1A94:
.string "b13pal\0\0"
.global gUnknown_83B1A9C
gUnknown_83B1A9C:
.string "b13fon\0\0"
.global gUnknown_83B1AA4
gUnknown_83B1AA4:
.string "b13cex\0\0"
.global gUnknown_83B1AAC
gUnknown_83B1AAC:
.string "b13cel\0\0"
.global gUnknown_83B1AB4
gUnknown_83B1AB4:
.string "b13canm\0"
.global gUnknown_83B1ABC
gUnknown_83B1ABC:
.string "b12pal\0\0"
.global gUnknown_83B1AC4
gUnknown_83B1AC4:
.string "b12fon\0\0"
.global gUnknown_83B1ACC
gUnknown_83B1ACC:
.string "b12cex\0\0"
.global gUnknown_83B1AD4
gUnknown_83B1AD4:
.string "b12cel\0\0"
.global gUnknown_83B1ADC
gUnknown_83B1ADC:
.string "b12canm\0"
.global gUnknown_83B1AE4
gUnknown_83B1AE4:
.string "b11pal\0\0"
.global gUnknown_83B1AEC
gUnknown_83B1AEC:
.string "b11fon\0\0"
.global gUnknown_83B1AF4
gUnknown_83B1AF4:
.string "b11cex\0\0"
.global gUnknown_83B1AFC
gUnknown_83B1AFC:
.string "b11cel\0\0"
.global gUnknown_83B1B04
gUnknown_83B1B04:
.string "b11canm\0"
.global gUnknown_83B1B0C
gUnknown_83B1B0C:
.string "b10pal\0\0"
.global gUnknown_83B1B14
gUnknown_83B1B14:
.string "b10fon\0\0"
.global gUnknown_83B1B1C
gUnknown_83B1B1C:
.string "b10cex\0\0"
.global gUnknown_83B1B24
gUnknown_83B1B24:
.string "b10cel\0\0"
.global gUnknown_83B1B2C
gUnknown_83B1B2C:
.string "b10canm\0"
.global gUnknown_83B1B34
gUnknown_83B1B34:
.string "b09pal\0\0"
.global gUnknown_83B1B3C
gUnknown_83B1B3C:
.string "b09fon\0\0"
.global gUnknown_83B1B44
gUnknown_83B1B44:
.string "b09cex\0\0"
.global gUnknown_83B1B4C
gUnknown_83B1B4C:
.string "b09cel\0\0"
.global gUnknown_83B1B54
gUnknown_83B1B54:
.string "b09canm\0"
.global gUnknown_83B1B5C
gUnknown_83B1B5C:
.string "b08pal\0\0"
.global gUnknown_83B1B64
gUnknown_83B1B64:
.string "b08fon\0\0"
.global gUnknown_83B1B6C
gUnknown_83B1B6C:
.string "b08cex\0\0"
.global gUnknown_83B1B74
gUnknown_83B1B74:
.string "b08cel\0\0"
.global gUnknown_83B1B7C
gUnknown_83B1B7C:
.string "b08canm\0"
.global gUnknown_83B1B84
gUnknown_83B1B84:
.string "b07pal\0\0"
.global gUnknown_83B1B8C
gUnknown_83B1B8C:
.string "b07fon\0\0"
.global gUnknown_83B1B94
gUnknown_83B1B94:
.string "b07cex\0\0"
.global gUnknown_83B1B9C
gUnknown_83B1B9C:
.string "b07cel\0\0"
.global gUnknown_83B1BA4
gUnknown_83B1BA4:
.string "b07canm\0"
.global gUnknown_83B1BAC
gUnknown_83B1BAC:
.string "b06pal\0\0"
.global gUnknown_83B1BB4
gUnknown_83B1BB4:
.string "b06fon\0\0"
.global gUnknown_83B1BBC
gUnknown_83B1BBC:
.string "b06cex\0\0"
.global gUnknown_83B1BC4
gUnknown_83B1BC4:
.string "b06cel\0\0"
.global gUnknown_83B1BCC
gUnknown_83B1BCC:
.string "b06canm\0"
.global gUnknown_83B1BD4
gUnknown_83B1BD4:
.string "b05pal\0\0"
.global gUnknown_83B1BDC
gUnknown_83B1BDC:
.string "b05fon\0\0"
.global gUnknown_83B1BE4
gUnknown_83B1BE4:
.string "b05cex\0\0"
.global gUnknown_83B1BEC
gUnknown_83B1BEC:
.string "b05cel\0\0"
.global gUnknown_83B1BF4
gUnknown_83B1BF4:
.string "b05canm\0"
.global gUnknown_83B1BFC
gUnknown_83B1BFC:
.string "b04pal\0\0"
.global gUnknown_83B1C04
gUnknown_83B1C04:
.string "b04fon\0\0"
.global gUnknown_83B1C0C
gUnknown_83B1C0C:
.string "b04cex\0\0"
.global gUnknown_83B1C14
gUnknown_83B1C14:
.string "b04cel\0\0"
.global gUnknown_83B1C1C
gUnknown_83B1C1C:
.string "b04canm\0"
.global gUnknown_83B1C24
gUnknown_83B1C24:
.string "b03pal\0\0"
.global gUnknown_83B1C2C
gUnknown_83B1C2C:
.string "b03fon\0\0"
.global gUnknown_83B1C34
gUnknown_83B1C34:
.string "b03cex\0\0"
.global gUnknown_83B1C3C
gUnknown_83B1C3C:
.string "b03cel\0\0"
.global gUnknown_83B1C44
gUnknown_83B1C44:
.string "b03canm\0"
.global gUnknown_83B1C4C
gUnknown_83B1C4C:
.string "b02pal\0\0"
.global gUnknown_83B1C54
gUnknown_83B1C54:
.string "b02fon\0\0"
.global gUnknown_83B1C5C
gUnknown_83B1C5C:
.string "b02cex\0\0"
.global gUnknown_83B1C64
gUnknown_83B1C64:
.string "b02cel\0\0"
.global gUnknown_83B1C6C
gUnknown_83B1C6C:
.string "b02canm\0"
.global gUnknown_83B1C74
gUnknown_83B1C74:
.string "b01pal\0\0"
.global gUnknown_83B1C7C
gUnknown_83B1C7C:
.string "b01fon\0\0"
.global gUnknown_83B1C84
gUnknown_83B1C84:
.string "b01cex\0\0"
.global gUnknown_83B1C8C
gUnknown_83B1C8C:
.string "b01cel\0\0"
.global gUnknown_83B1C94
gUnknown_83B1C94:
.string "b01canm\0"
.global gUnknown_83B1C9C
gUnknown_83B1C9C:
.string "b00pal\0\0"
.global gUnknown_83B1CA4
gUnknown_83B1CA4:
.string "b00fon\0\0"
.global gUnknown_83B1CAC
gUnknown_83B1CAC:
.string "b00cex\0\0"
.global gUnknown_83B1CB4
gUnknown_83B1CB4:
.string "b00cel\0\0"
.global gUnknown_83B1CBC
gUnknown_83B1CBC:
.string "b00canm\0"

.string "pksdir0\0"
