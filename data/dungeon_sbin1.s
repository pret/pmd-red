.section .rodata

.global gDungeonFileArchive
gDungeonFileArchive: @ 83B0000
.string "pksdir0\0"
.byte 0xc7, 0x01, 0x00, 0x00 @ 455 entries
.4byte StartOfDungeonTable
.string "pksdir0\0"

.global StartOfDungeonTable
StartOfDungeonTable:
.4byte gUnknown_83B1CBC @ "b00canm"
.4byte gUnknown_83B1CCC @ b00canm SIRO
.4byte gUnknown_83B1CB4 @ "b00cel"
.4byte gUnknown_83B235C @ b00cel AT4PX
.4byte gUnknown_83B1CAC @ "b00cex"
.4byte gUnknown_83B2A64 @ b00cex SIRO
.4byte gUnknown_83B1CA4 @ "b00fon"
.4byte gUnknown_83B2D3C @ b00fon AT4PX
.4byte gUnknown_83B1C9C @ "b00pal"
.4byte gUnknown_83B49D1 @ b00pal palette

.4byte gUnknown_83B1C94 @ "b01canm"
.4byte gUnknown_83B4CD0 @ b01canm SIRO
.4byte gUnknown_83B1C8C @ "b01cel"
.4byte gUnknown_83B5220 @ b01cel AT4PX
.4byte gUnknown_83B1C84 @ "b01cex"
.4byte gUnknown_83B5918 @ b01cex SIRO
.4byte gUnknown_83B1C7C @ "b01fon"
.4byte gUnknown_83B5C4F @ b01fon AT4PX
.4byte gUnknown_83B1C74 @ "b01pal"
.4byte gUnknown_83B8538 @ b01pal palette

.4byte gUnknown_83B1C6C @ "b02canm"
.4byte gUnknown_83B8838 @ b02canm SIRO
.4byte gUnknown_83B1C64 @ "b02cel"
.4byte gUnknown_83B8C88 @ b02cel AT4PX
.4byte gUnknown_83B1C5C @ "b02cex"
.4byte gUnknown_83B9530 @ b02cex SIRO
.4byte gUnknown_83B1C54 @ "b02fon"
.4byte gUnknown_83B98C6 @ b02fon AT4PX
.4byte gUnknown_83B1C4C @ "b02pal"
.4byte gUnknown_83BBD08 @ b02pal palette

.4byte gUnknown_83B1C44 @ "b03canm"
.4byte gUnknown_83BC008 @ b03canm SIRO
.4byte gUnknown_83B1C3C @ "b03cel"
.4byte gUnknown_83BC458 @ b03cel AT4PX
.4byte gUnknown_83B1C34 @ "b03cex"
.4byte gUnknown_83BCBCC @ b03cex SIRO
.4byte gUnknown_83B1C2C @ "b03fon"
.4byte gUnknown_83BCF01 @ b03fon AT4PX
.4byte gUnknown_83B1C24 @ "b03pal"
.4byte gUnknown_83BF124 @ b03pal palette

.4byte gUnknown_83B1C1C @ "b04canm"
.4byte gUnknown_83BF424 @ b04canm SIRO
.4byte gUnknown_83B1C14 @ "b04cel"
.4byte gUnknown_83BF974 @ b04cel AT4PX
.4byte gUnknown_83B1C0C @ "b04cex"
.4byte gUnknown_83C0088 @ b04cex SIRO
.4byte gUnknown_83B1C04 @ "b04fon"
.4byte gUnknown_83C03D8 @ b04fon AT4PX
.4byte gUnknown_83B1BFC @ "b04pal"
.4byte gUnknown_83C2670 @ b04pal palette

.4byte gUnknown_83B1BF4 @ "b05canm"
.4byte gUnknown_83C2970 @ b05canm SIRO
.4byte gUnknown_83B1BEC @ "b05cel"
.4byte gUnknown_83C2EC0 @ b05cel AT4PX
.4byte gUnknown_83B1BE4 @ "b05cex"
.4byte gUnknown_83C35C0 @ b05cex SIRO
.4byte gUnknown_83B1BDC @ "b05fon"
.4byte gUnknown_83C38FE @ b05fon AT4PX
.4byte gUnknown_83B1BD4 @ "b05pal"
.4byte gUnknown_83C53E4 @ b05pal palette

.4byte gUnknown_83B1BCC @ "b06canm"
.4byte gUnknown_83C56E4 @ b06canm SIRO
.4byte gUnknown_83B1BC4 @ "b06cel"
.4byte gUnknown_83C5B34 @ b06cel AT4PX
.4byte gUnknown_83B1BBC @ "b06cex"
.4byte gUnknown_83C6304 @ b06cex SIRO
.4byte gUnknown_83B1BB4 @ "b06fon"
.4byte gUnknown_83C6645 @ b06fon AT4PX
.4byte gUnknown_83B1BAC @ "b06pal"
.4byte gUnknown_83C97EC @ b06pal palette

.4byte gUnknown_83B1BA4 @ "b07canm"
.4byte gUnknown_83C9AEC @ b07canm SIRO
.4byte gUnknown_83B1B9C @ "b07cel"
.4byte gUnknown_83C9F3C @ b07cel AT4PX
.4byte gUnknown_83B1B94 @ "b07cex"
.4byte gUnknown_83CA70C @ b07cex SIRO
.4byte gUnknown_83B1B8C @ "b07fon"
.4byte gUnknown_83CAAA2 @ b07fon AT4PX
.4byte gUnknown_83B1B84 @ "b07pal"
.4byte gUnknown_83CC9A4 @ b07pal palette

.4byte gUnknown_83B1B7C @ "b08canm"
.4byte gUnknown_83CCCA4 @ b08canm SIRO
.4byte gUnknown_83B1B74 @ "b08cel"
.4byte gUnknown_83CD0F4 @ b08cel AT4PX
.4byte gUnknown_83B1B6C @ "b08cex"
.4byte gUnknown_83CD8B0 @ b08cex SIRO
.4byte gUnknown_83B1B64 @ "b08fon"
.4byte gUnknown_83CDBFD @ b08fon AT4PX
.4byte gUnknown_83B1B5C @ "b08pal"
.4byte gUnknown_83D0C3C @ b08pal palette

.4byte gUnknown_83B1B54 @ "b09canm"
.4byte gUnknown_83D0F3C @ b09canm SIRO
.4byte gUnknown_83B1B4C @ "b09cel"
.4byte gUnknown_83D1394 @ b09cel AT4PX
.4byte gUnknown_83B1B44 @ "b09cex"
.4byte gUnknown_83D1AB4 @ b09cex SIRO
.4byte gUnknown_83B1B3C @ "b09fon"
.4byte gUnknown_83D1E19 @ b09fon AT4PX
.4byte gUnknown_83B1B34 @ "b09pal"
.4byte gUnknown_83D3FC4 @ b09pal palette

.4byte gUnknown_83B1B2C @ "b10canm"
.4byte gUnknown_83D42C4 @ b10canm SIRO
.4byte gUnknown_83B1B24 @ "b10cel"
.4byte gUnknown_83D4714 @ b10cel AT4PX
.4byte gUnknown_83B1B1C @ "b10cex"
.4byte gUnknown_83D4F1C @ b10cex SIRO
.4byte gUnknown_83B1B14 @ "b10fon"
.4byte gUnknown_83D5253 @ b10fon AT4PX
.4byte gUnknown_83B1B0C @ "b10pal"
.4byte gUnknown_83D7A14 @ b10pal palette

.4byte gUnknown_83B1B04 @ "b11canm"
.4byte gUnknown_83D7D14 @ b11canm SIRO
.4byte gUnknown_83B1AFC @ "b11cel"
.4byte gUnknown_83D8164 @ b11cel AT4PX
.4byte gUnknown_83B1AF4 @ "b11cex"
.4byte gUnknown_83D88F4 @ b11cex SIRO
.4byte gUnknown_83B1AEC @ "b11fon"
.4byte gUnknown_83D8C2B @ b11fon AT4PX
.4byte gUnknown_83B1AE4 @ "b11pal"
.4byte gUnknown_83DB640 @ b11pal palette

.4byte gUnknown_83B1ADC @ "b12canm"
.4byte gUnknown_83DB940 @ b12canm SIRO
.4byte gUnknown_83B1AD4 @ "b12cel"
.4byte gUnknown_83DBFD0 @ b12cel AT4PX
.4byte gUnknown_83B1ACC @ "b12cex"
.4byte gUnknown_83DC7BC @ b12cex SIRO
.4byte gUnknown_83B1AC4 @ "b12fon"
.4byte gUnknown_83DCAD0 @ b12fon AT4PX
.4byte gUnknown_83B1ABC @ "b12pal"
.4byte gUnknown_83DF0A0 @ b12pal palette

.4byte gUnknown_83B1AB4 @ "b13canm"
.4byte gUnknown_83DF3A0 @ b13canm SIRO
.4byte gUnknown_83B1AAC @ "b13cel"
.4byte gUnknown_83DF7F0 @ b13cel AT4PX
.4byte gUnknown_83B1AA4 @ "b13cex"
.4byte gUnknown_83DFF64 @ b13cex SIRO
.4byte gUnknown_83B1A9C @ "b13fon"
.4byte gUnknown_83E0298 @ b13fon AT4PX
.4byte gUnknown_83B1A94 @ "b13pal"
.4byte gUnknown_83E2190 @ b13pal palette

.4byte gUnknown_83B1A8C @ "b14canm"
.4byte gUnknown_83E2490 @ b14canm SIRO
.4byte gUnknown_83B1A84 @ "b14cel"
.4byte gUnknown_83E29E0 @ b14cel AT4PX
.4byte gUnknown_83B1A7C @ "b14cex"
.4byte gUnknown_83E31C8 @ b14cex SIRO
.4byte gUnknown_83B1A74 @ "b14fon"
.4byte gUnknown_83E355F @ b14fon AT4PX
.4byte gUnknown_83B1A6C @ "b14pal"
.4byte gUnknown_83E55A8 @ b14pal palette

.4byte gUnknown_83B1A64 @ "b15canm"
.4byte gUnknown_83E58A8 @ b15canm SIRO
.4byte gUnknown_83B1A5C @ "b15cel"
.4byte gUnknown_83E5CF8 @ b15cel AT4PX
.4byte gUnknown_83B1A54 @ "b15cex"
.4byte gUnknown_83E63E0 @ b15cex SIRO
.4byte gUnknown_83B1A4C @ "b15fon"
.4byte gUnknown_83E674E @ b15fon AT4PX
.4byte gUnknown_83B1A44 @ "b15pal"
.4byte gUnknown_83E84EC @ b15pal palette

.4byte gUnknown_83B1A3C @ "b16canm"
.4byte gUnknown_83E87EC @ b16canm SIRO
.4byte gUnknown_83B1A34 @ "b16cel"
.4byte gUnknown_83E8E7C @ b16cel AT4PX
.4byte gUnknown_83B1A2C @ "b16cex"
.4byte gUnknown_83E95C0 @ b16cex SIRO
.4byte gUnknown_83B1A24 @ "b16fon"
.4byte gUnknown_83E98EA @ b16fon AT4PX
.4byte gUnknown_83B1A1C @ "b16pal"
.4byte gUnknown_83EB52C @ b16pal palette

.4byte gUnknown_83B1A14 @ "b17canm"
.4byte gUnknown_83EB82C @ b17canm SIRO
.4byte gUnknown_83B1A0C @ "b17cel"
.4byte gUnknown_83EBD40 @ b17cel AT4PX
.4byte gUnknown_83B1A04 @ "b17cex"
.4byte gUnknown_83EC570 @ b17cex SIRO
.4byte gUnknown_83B19FC @ "b17fon"
.4byte gUnknown_83EC90A @ b17fon AT4PX
.4byte gUnknown_83B19F4 @ "b17pal"
.4byte gUnknown_83EEA4C @ b17pal palette

.4byte gUnknown_83B19EC @ "b18canm"
.4byte gUnknown_83EED4C @ b18canm SIRO
.4byte gUnknown_83B19E4 @ "b18cel"
.4byte gUnknown_83EF19C @ b18cel AT4PX
.4byte gUnknown_83B19DC @ "b18cex"
.4byte gUnknown_83EF954 @ b18cex SIRO
.4byte gUnknown_83B19D4 @ "b18fon"
.4byte gUnknown_83EFCBB @ b18fon AT4PX
.4byte gUnknown_83B19CC @ "b18pal"
.4byte gUnknown_83F24EC @ b18pal palette

.4byte gUnknown_83B19C4 @ "b19canm"
.4byte gUnknown_83F27EC @ b19canm SIRO
.4byte gUnknown_83B19BC @ "b19cel"
.4byte gUnknown_83F2D3C @ b19cel AT4PX
.4byte gUnknown_83B19B4 @ "b19cex"
.4byte gUnknown_83F3494 @ b19cex SIRO
.4byte gUnknown_83B19AC @ "b19fon"
.4byte gUnknown_83F382C @ b19fon AT4PX
.4byte gUnknown_83B19A4 @ "b19pal"
.4byte gUnknown_83F5194 @ b19pal palette

.4byte gUnknown_83B199C @ "b20canm"
.4byte gUnknown_83F5494 @ b20canm SIRO
.4byte gUnknown_83B1994 @ "b20cel"
.4byte gUnknown_83F59E4 @ b20cel AT4PX
.4byte gUnknown_83B198C @ "b20cex"
.4byte gUnknown_83F6188 @ b20cex SIRO
.4byte gUnknown_83B1984 @ "b20fon"
.4byte gUnknown_83F64A1 @ b20fon AT4PX
.4byte gUnknown_83B197C @ "b20pal"
.4byte gUnknown_83F8C68 @ b20pal palette

.4byte gUnknown_83B1974 @ "b21canm"
.4byte gUnknown_83F8F68 @ b21canm SIRO
.4byte gUnknown_83B196C @ "b21cel"
.4byte gUnknown_83F95B8 @ b21cel AT4PX
.4byte gUnknown_83B1964 @ "b21cex"
.4byte gUnknown_83F9CBC @ b21cex SIRO
.4byte gUnknown_83B195C @ "b21fon"
.4byte gUnknown_83FA051 @ b21fon AT4PX
.4byte gUnknown_83B1954 @ "b21pal"
.4byte gUnknown_83FB4B0 @ b21pal palette

.4byte gUnknown_83B194C @ "b22canm"
.4byte gUnknown_83FB7B0 @ b22canm SIRO
.4byte gUnknown_83B1944 @ "b22pal"
.4byte gUnknown_83FBD80 @ b22pal palette

.4byte gUnknown_83B193C @ "b23canm"
.4byte gUnknown_83FC080 @ b23canm SIRO
.4byte gUnknown_83B1934 @ "b23cel"
.4byte gUnknown_83FC5D0 @ b23cel AT4PX
.4byte gUnknown_83B192C @ "b23cex"
.4byte gUnknown_83FCD4C @ b23cex SIRO
.4byte gUnknown_83B1924 @ "b23fon"
.4byte gUnknown_83FD098 @ b23fon AT4PX
.4byte gUnknown_83B191C @ "b23pal"
.4byte gUnknown_83FF330 @ b23pal palette

.4byte gUnknown_83B1914 @ "b24canm"
.4byte gUnknown_83FF630 @ b24canm SIRO
.4byte gUnknown_83B190C @ "b24cel"
.4byte gUnknown_83FFA80 @ b24cel AT4PX
.4byte gUnknown_83B1904 @ "b24cex"
.4byte gUnknown_8400114 @ b24cex SIRO
.4byte gUnknown_83B18FC @ "b24fon"
.4byte gUnknown_840044A @ b24fon AT4PX
.4byte gUnknown_83B18F4 @ "b24pal"
.4byte gUnknown_8401C98 @ b24pal palette

.4byte gUnknown_83B18EC @ "b25canm"
.4byte gUnknown_8401F98 @ b25canm SIRO
.4byte gUnknown_83B18E4 @ "b25cel"
.4byte gUnknown_84023E8 @ b25cel AT4PX
.4byte gUnknown_83B18DC @ "b25cex"
.4byte gUnknown_8402BF0 @ b25cex SIRO
.4byte gUnknown_83B18D4 @ "b25fon"
.4byte gUnknown_8402F86 @ b25fon AT4PX
.4byte gUnknown_83B18CC @ "b25pal"
.4byte gUnknown_8404A44 @ b25pal palette

.4byte gUnknown_83B18C4 @ "b26canm"
.4byte gUnknown_8404D44 @ b26canm SIRO
.4byte gUnknown_83B18BC @ "b26pal"
.4byte gUnknown_8405294 @ b26pal palette

.4byte gUnknown_83B18B4 @ "b27canm"
.4byte gUnknown_8405594 @ b27canm SIRO
.4byte gUnknown_83B18AC @ "b27pal"
.4byte gUnknown_8405AE4 @ b27pal palette

.4byte gUnknown_83B18A4 @ "b28canm"
.4byte gUnknown_8405DE4 @ b28canm SIRO
.4byte gUnknown_83B189C @ "b28cel"
.4byte gUnknown_8406434 @ b28cel AT4PX
.4byte gUnknown_83B1894 @ "b28cex"
.4byte gUnknown_8406B5C @ b28cex SIRO
.4byte gUnknown_83B188C @ "b28fon"
.4byte gUnknown_8406E82 @ b28fon AT4PX
.4byte gUnknown_83B1884 @ "b28pal"
.4byte gUnknown_840873C @ b28pal palette

.4byte gUnknown_83B187C @ "b29canm"
.4byte gUnknown_8408A3C @ b29canm SIRO
.4byte gUnknown_83B1874 @ "b29cel"
.4byte gUnknown_8408F8C @ b29cel AT4PX
.4byte gUnknown_83B186C @ "b29cex"
.4byte gUnknown_84096B8 @ b29cex SIRO
.4byte gUnknown_83B1864 @ "b29fon"
.4byte gUnknown_84099E9 @ b29fon AT4PX
.4byte gUnknown_83B185C @ "b29pal"
.4byte gUnknown_840BCA0 @ b29pal palette

.4byte gUnknown_83B1854 @ "b30canm"
.4byte gUnknown_840BFA0 @ b30canm SIRO
.4byte gUnknown_83B184C @ "b30cel"
.4byte gUnknown_840C4F0 @ b30cel AT4PX
.4byte gUnknown_83B1844 @ "b30cex"
.4byte gUnknown_840CBC4 @ b30cex SIRO
.4byte gUnknown_83B183C @ "b30fon"
.4byte gUnknown_840CF0F @ b30fon AT4PX
.4byte gUnknown_83B1834 @ "b30pal"
.4byte gUnknown_840E5EC @ b30pal palette

.4byte gUnknown_83B182C @ "b31canm"
.4byte gUnknown_840E8EC @ b31canm SIRO
.4byte gUnknown_83B1824 @ "b31cel"
.4byte gUnknown_840EE3C @ b31cel AT4PX
.4byte gUnknown_83B181C @ "b31cex"
.4byte gUnknown_840F5E8 @ b31cex SIRO
.4byte gUnknown_83B1814 @ "b31fon"
.4byte gUnknown_840F920 @ b31fon AT4PX
.4byte gUnknown_83B180C @ "b31pal"
.4byte gUnknown_8411918 @ b31pal palette

.4byte gUnknown_83B1804 @ "b32canm"
.4byte gUnknown_8411C18 @ b32canm SIRO
.4byte gUnknown_83B17FC @ "b32cel"
.4byte gUnknown_8412728 @ b32cel AT4PX
.4byte gUnknown_83B17F4 @ "b32cex"
.4byte gUnknown_8412D88 @ b32cex SIRO
.4byte gUnknown_83B17EC @ "b32fon"
.4byte gUnknown_84130A4 @ b32fon AT4PX
.4byte gUnknown_83B17E4 @ "b32pal"
.4byte gUnknown_84141E4 @ b32pal palette

.4byte gUnknown_83B17DC @ "b33canm"
.4byte gUnknown_84144E4 @ b33canm SIRO
.4byte gUnknown_83B17D4 @ "b33cel"
.4byte gUnknown_8414FF4 @ b33cel AT4PX
.4byte gUnknown_83B17CC @ "b33cex"
.4byte gUnknown_8415654 @ b33cex SIRO
.4byte gUnknown_83B17C4 @ "b33fon"
.4byte gUnknown_8415970 @ b33fon AT4PX
.4byte gUnknown_83B17BC @ "b33pal"
.4byte gUnknown_8416A54 @ b33pal palette

.4byte gUnknown_83B17B4 @ "b34canm"
.4byte gUnknown_8416D5C @ b34canm SIRO
.4byte gUnknown_83B17AC @ "b34pal"
.4byte gUnknown_84173AC @ b34pal palette

.4byte gUnknown_83B17A4 @ "b35canm"
.4byte gUnknown_84176AC @ b35canm SIRO
.4byte gUnknown_83B179C @ "b35cel"
.4byte gUnknown_8417CBC @ b35cel AT4PX
.4byte gUnknown_83B1794 @ "b35cex"
.4byte gUnknown_84184A8 @ b35cex SIRO
.4byte gUnknown_83B178C @ "b35fon"
.4byte gUnknown_84187DF @ b35fon AT4PX
.4byte gUnknown_83B1784 @ "b35pal"
.4byte gUnknown_841A980 @ b35pal palette

.4byte gUnknown_83B177C @ "b36canm"
.4byte gUnknown_841AC80 @ b36canm SIRO
.4byte gUnknown_83B1774 @ "b36cel"
.4byte gUnknown_841B290 @ b36cel AT4PX
.4byte gUnknown_83B176C @ "b36cex"
.4byte gUnknown_841BA28 @ b36cex SIRO
.4byte gUnknown_83B1764 @ "b36fon"
.4byte gUnknown_841BDAD @ b36fon AT4PX
.4byte gUnknown_83B175C @ "b36pal"
.4byte gUnknown_841E074 @ b36pal palette

.4byte gUnknown_83B1754 @ "b37canm"
.4byte gUnknown_841E374 @ b37canm SIRO
.4byte gUnknown_83B174C @ "b37cel"
.4byte gUnknown_841E8C4 @ b37cel AT4PX
.4byte gUnknown_83B1744 @ "b37cex"
.4byte gUnknown_841EFD4 @ b37cex SIRO
.4byte gUnknown_83B173C @ "b37fon"
.4byte gUnknown_841F34F @ b37fon AT4PX
.4byte gUnknown_83B1734 @ "b37pal"
.4byte gUnknown_8420F9C @ b37pal palette

.4byte gUnknown_83B172C @ "b38canm"
.4byte gUnknown_842129C @ b38canm SIRO
.4byte gUnknown_83B1724 @ "b38pal"
.4byte gUnknown_84217EC @ b38pal palette

.4byte gUnknown_83B171C @ "b39canm"
.4byte gUnknown_8421AEC @ b39canm SIRO
.4byte gUnknown_83B1714 @ "b39cel"
.4byte gUnknown_842203C @ b39cel AT4PX
.4byte gUnknown_83B170C @ "b39cex"
.4byte gUnknown_842272C @ b39cex SIRO
.4byte gUnknown_83B1704 @ "b39fon"
.4byte gUnknown_8422ABC @ b39fon AT4PX
.4byte gUnknown_83B16FC @ "b39pal"
.4byte gUnknown_8424088 @ b39pal palette

.4byte gUnknown_83B16F4 @ "b40canm"
.4byte gUnknown_8424388 @ b40canm SIRO
.4byte gUnknown_83B16EC @ "b40cel"
.4byte gUnknown_84248D8 @ b40cel AT4PX
.4byte gUnknown_83B16E4 @ "b40cex"
.4byte gUnknown_8424FD8 @ b40cex SIRO
.4byte gUnknown_83B16DC @ "b40fon"
.4byte gUnknown_842534E @ b40fon AT4PX
.4byte gUnknown_83B16D4 @ "b40pal"
.4byte gUnknown_8426F84 @ b40pal palette

.4byte gUnknown_83B16CC @ "b41canm"
.4byte gUnknown_8427284 @ b41canm SIRO
.4byte gUnknown_83B16C4 @ "b41cel"
.4byte gUnknown_84277D4 @ b41cel AT4PX
.4byte gUnknown_83B16BC @ "b41cex"
.4byte gUnknown_8427EE4 @ b41cex SIRO
.4byte gUnknown_83B16B4 @ "b41fon"
.4byte gUnknown_84281FD @ b41fon AT4PX
.4byte gUnknown_83B16AC @ "b41pal"
.4byte gUnknown_842AA28 @ b41pal palette

.4byte gUnknown_83B16A4 @ "b42canm"
.4byte gUnknown_842AD28 @ b42canm SIRO
.4byte gUnknown_83B169C @ "b42cel"
.4byte gUnknown_842B278 @ b42cel AT4PX
.4byte gUnknown_83B1694 @ "b42cex"
.4byte gUnknown_842BA04 @ b42cex SIRO
.4byte gUnknown_83B168C @ "b42fon"
.4byte gUnknown_842BD19 @ b42fon AT4PX
.4byte gUnknown_83B1684 @ "b42pal"
.4byte gUnknown_842DEB4 @ b42pal palette

.4byte gUnknown_83B167C @ "b43canm"
.4byte gUnknown_842E1B4 @ b43canm SIRO
.4byte gUnknown_83B1674 @ "b43cel"
.4byte gUnknown_842E704 @ b43cel AT4PX
.4byte gUnknown_83B166C @ "b43cex"
.4byte gUnknown_842EEDC @ b43cex SIRO
.4byte gUnknown_83B1664 @ "b43fon"
.4byte gUnknown_842F273 @ b43fon AT4PX
.4byte gUnknown_83B165C @ "b43pal"
.4byte gUnknown_8431B30 @ b43pal palette

.4byte gUnknown_83B1654 @ "b44canm"
.4byte gUnknown_8431E30 @ b44canm SIRO
.4byte gUnknown_83B164C @ "b44cel"
.4byte gUnknown_8432440 @ b44cel AT4PX
.4byte gUnknown_83B1644 @ "b44cex"
.4byte gUnknown_8432C48 @ b44cex SIRO
.4byte gUnknown_83B163C @ "b44fon"
.4byte gUnknown_8432F83 @ b44fon AT4PX
.4byte gUnknown_83B1634 @ "b44pal"
.4byte gUnknown_8435188 @ b44pal palette

.4byte gUnknown_83B162C @ "b45canm"
.4byte gUnknown_8435488 @ b45canm SIRO
.4byte gUnknown_83B1624 @ "b45cel"
.4byte gUnknown_84358D8 @ b45cel AT4PX
.4byte gUnknown_83B161C @ "b45cex"
.4byte gUnknown_8436058 @ b45cex SIRO
.4byte gUnknown_83B1614 @ "b45fon"
.4byte gUnknown_843638D @ b45fon AT4PX
.4byte gUnknown_83B160C @ "b45pal"
.4byte gUnknown_8438AFC @ b45pal palette

.4byte gUnknown_83B1604 @ "b46canm"
.4byte gUnknown_8438DFC @ b46canm SIRO
.4byte gUnknown_83B15FC @ "b46cel"
.4byte gUnknown_843950C @ b46cel AT4PX
.4byte gUnknown_83B15F4 @ "b46cex"
.4byte gUnknown_8439C30 @ b46cex SIRO
.4byte gUnknown_83B15EC @ "b46fon"
.4byte gUnknown_8439F4C @ b46fon AT4PX
.4byte gUnknown_83B15E4 @ "b46pal"
.4byte gUnknown_843C16C @ b46pal palette

.4byte gUnknown_83B15DC @ "b47canm"
.4byte gUnknown_843C46C @ b47canm SIRO
.4byte gUnknown_83B15D4 @ "b47cel"
.4byte gUnknown_843C8BC @ b47cel AT4PX
.4byte gUnknown_83B15CC @ "b47cex"
.4byte gUnknown_843D094 @ b47cex SIRO
.4byte gUnknown_83B15C4 @ "b47fon"
.4byte gUnknown_843D42A @ b47fon AT4PX
.4byte gUnknown_83B15BC @ "b47pal"
.4byte gUnknown_843F768 @ b47pal palette

.4byte gUnknown_83B15B4 @ "b48canm"
.4byte gUnknown_843FA68 @ b48canm SIRO
.4byte gUnknown_83B15AC @ "b48cel"
.4byte gUnknown_8440638 @ b48cel AT4PX
.4byte gUnknown_83B15A4 @ "b48cex"
.4byte gUnknown_8440DA0 @ b48cex SIRO
.4byte gUnknown_83B159C @ "b48fon"
.4byte gUnknown_8441101 @ b48fon AT4PX
.4byte gUnknown_83B1594 @ "b48pal"
.4byte gUnknown_8443054 @ b48pal palette

.4byte gUnknown_83B158C @ "b49canm"
.4byte gUnknown_844335C @ b49canm SIRO
.4byte gUnknown_83B1584 @ "b49cel"
.4byte gUnknown_84438EC @ b49cel AT4PX
.4byte gUnknown_83B157C @ "b49cex"
.4byte gUnknown_8443FF4 @ b49cex SIRO
.4byte gUnknown_83B1574 @ "b49fon"
.4byte gUnknown_84442CC @ b49fon AT4PX
.4byte gUnknown_83B156C @ "b49pal"
.4byte gUnknown_8445F60 @ b49pal palette

.4byte gUnknown_83B1564 @ "b50canm"
.4byte gUnknown_8446260 @ b50canm SIRO
.4byte gUnknown_83B155C @ "b50cel"
.4byte gUnknown_84467B0 @ b50cel AT4PX
.4byte gUnknown_83B1554 @ "b50cex"
.4byte gUnknown_8446F2C @ b50cex SIRO
.4byte gUnknown_83B154C @ "b50fon"
.4byte gUnknown_844729F @ b50fon AT4PX
.4byte gUnknown_83B1544 @ "b50pal"
.4byte gUnknown_84495C4 @ b50pal palette

.4byte gUnknown_83B153C @ "b51canm"
.4byte gUnknown_84498C4 @ b51canm SIRO
.4byte gUnknown_83B1534 @ "b51cel"
.4byte gUnknown_8449D14 @ b51cel AT4PX
.4byte gUnknown_83B152C @ "b51cex"
.4byte gUnknown_844A488 @ b51cex SIRO
.4byte gUnknown_83B1524 @ "b51fon"
.4byte gUnknown_844A7D7 @ b51fon AT4PX
.4byte gUnknown_83B151C @ "b51pal"
.4byte gUnknown_844CE80 @ b51pal palette

.4byte gUnknown_83B1514 @ "b52canm"
.4byte gUnknown_844D180 @ b52canm SIRO
.4byte gUnknown_83B150C @ "b52cel"
.4byte gUnknown_844D6D0 @ b52cel AT4PX
.4byte gUnknown_83B1504 @ "b52cex"
.4byte gUnknown_844DDE0 @ b52cex SIRO
.4byte gUnknown_83B14FC @ "b52fon"
.4byte gUnknown_844E0F9 @ b52fon AT4PX
.4byte gUnknown_83B14F4 @ "b52pal"
.4byte gUnknown_8450924 @ b52pal palette

.4byte gUnknown_83B14EC @ "b53canm"
.4byte gUnknown_8450C24 @ b53canm SIRO
.4byte gUnknown_83B14E4 @ "b53cel"
.4byte gUnknown_8451174 @ b53cel AT4PX
.4byte gUnknown_83B14DC @ "b53cex"
.4byte gUnknown_84518B8 @ b53cex SIRO
.4byte gUnknown_83B14D4 @ "b53fon"
.4byte gUnknown_8451C08 @ b53fon AT4PX
.4byte gUnknown_83B14CC @ "b53pal"
.4byte gUnknown_845416C @ b53pal palette

.4byte gUnknown_83B14C4 @ "b54canm"
.4byte gUnknown_845446C @ b54canm SIRO
.4byte gUnknown_83B14BC @ "b54cel"
.4byte gUnknown_84549BC @ b54cel AT4PX
.4byte gUnknown_83B14B4 @ "b54cex"
.4byte gUnknown_84550C4 @ b54cex SIRO
.4byte gUnknown_83B14AC @ "b54fon"
.4byte gUnknown_845539C @ b54fon AT4PX
.4byte gUnknown_83B14A4 @ "b54pal"
.4byte gUnknown_8457030 @ b54pal palette

.4byte gUnknown_83B149C @ "b55canm"
.4byte gUnknown_8457330 @ b55canm SIRO
.4byte gUnknown_83B1494 @ "b55cel"
.4byte gUnknown_8457780 @ b55cel AT4PX
.4byte gUnknown_83B148C @ "b55cex"
.4byte gUnknown_8457E98 @ b55cex SIRO
.4byte gUnknown_83B1484 @ "b55fon"
.4byte gUnknown_84581CC @ b55fon AT4PX
.4byte gUnknown_83B147C @ "b55pal"
.4byte gUnknown_845ACCC @ b55pal palette

.4byte gUnknown_83B1474 @ "b56canm"
.4byte gUnknown_845AFCC @ b56canm SIRO
.4byte gUnknown_83B146C @ "b56cel"
.4byte gUnknown_845B41C @ b56cel AT4PX
.4byte gUnknown_83B1464 @ "b56cex"
.4byte gUnknown_845BBA4 @ b56cex SIRO
.4byte gUnknown_83B145C @ "b56fon"
.4byte gUnknown_845BEE7 @ b56fon AT4PX
.4byte gUnknown_83B1454 @ "b56pal"
.4byte gUnknown_845E880 @ b56pal palette

.4byte gUnknown_83B144C @ "b57canm"
.4byte gUnknown_845EB80 @ b57canm SIRO
.4byte gUnknown_83B1444 @ "b57pal"
.4byte gUnknown_845EFD0 @ b57pal palette

.4byte gUnknown_83B143C @ "b58canm"
.4byte gUnknown_845F2D0 @ b58canm SIRO
.4byte gUnknown_83B1434 @ "b58pal"
.4byte gUnknown_845F720 @ b58pal palette

.4byte gUnknown_83B142C @ "b59canm"
.4byte gUnknown_845FA20 @ b59canm SIRO
.4byte gUnknown_83B1424 @ "b59cel"
.4byte gUnknown_845FE30 @ b59cel AT4PX
.4byte gUnknown_83B141C @ "b59cex"
.4byte gUnknown_84604C0 @ b59cex SIRO
.4byte gUnknown_83B1414 @ "b59fon"
.4byte gUnknown_84607DB @ b59fon AT4PX
.4byte gUnknown_83B140C @ "b59pal"
.4byte gUnknown_84627FC @ b59pal palette

.4byte gUnknown_83B1404 @ "b60canm"
.4byte gUnknown_8462AFC @ b60canm SIRO
.4byte gUnknown_83B13FC @ "b60cel"
.4byte gUnknown_8462F4C @ b60cel AT4PX
.4byte gUnknown_83B13F4 @ "b60cex"
.4byte gUnknown_84636BC @ b60cex SIRO
.4byte gUnknown_83B13EC @ "b60fon"
.4byte gUnknown_84639F2 @ b60fon AT4PX
.4byte gUnknown_83B13E4 @ "b60pal"
.4byte gUnknown_8465E6C @ b60pal palette

.4byte gUnknown_83B13DC @ "b61canm"
.4byte gUnknown_846616C @ b61canm SIRO
.4byte gUnknown_83B13D4 @ "b61pal"
.4byte gUnknown_8466A7C @ b61pal palette

.4byte gUnknown_83B13CC @ "b62canm"
.4byte gUnknown_8466D7C @ b62canm SIRO
.4byte gUnknown_83B13C4 @ "b62cel"
.4byte gUnknown_84671CC @ b62cel AT4PX
.4byte gUnknown_83B13BC @ "b62cex"
.4byte gUnknown_8467950 @ b62cex SIRO
.4byte gUnknown_83B13B4 @ "b62fon"
.4byte gUnknown_8467C74 @ b62fon AT4PX
.4byte gUnknown_83B13AC @ "b62pal"
.4byte gUnknown_846A37C @ b62pal palette

.4byte gUnknown_83B13A4 @ "b63canm"
.4byte gUnknown_846A67C @ b63canm SIRO
.4byte gUnknown_83B139C @ "b63cel"
.4byte gUnknown_846ACCC @ b63cel AT4PX
.4byte gUnknown_83B1394 @ "b63cex"
.4byte gUnknown_846B42C @ b63cex SIRO
.4byte gUnknown_83B138C @ "b63fon"
.4byte gUnknown_846B771 @ b63fon AT4PX
.4byte gUnknown_83B1384 @ "b63pal"
.4byte gUnknown_846DB74 @ b63pal palette

.4byte gUnknown_83B137C @ "b64canm"
.4byte gUnknown_846DE74 @ b64canm SIRO
.4byte gUnknown_83B1374 @ "b64cel"
.4byte gUnknown_846E444 @ b64cel AT4PX
.4byte gUnknown_83B1368 @ "b64emap0"
.4byte gUnknown_846F248 @ b64emap0 SIRO
.4byte gUnknown_83B1360 @ "b64fon"
.4byte gUnknown_846F418 @ b64fon AT4PX
.4byte gUnknown_83B1358 @ "b64pal"
.4byte gUnknown_8470FBC @ b64pal palette

.4byte gUnknown_83B1350 @ "b65canm"
.4byte gUnknown_84712BC @ b65canm SIRO
.4byte gUnknown_83B1348 @ "b65cel"
.4byte gUnknown_847188C @ b65cel AT4PX
.4byte gUnknown_83B133C @ "b65emap0"
.4byte gUnknown_8472130 @ b65emap0 SIRO
.4byte gUnknown_83B1334 @ "b65fon"
.4byte gUnknown_84722F3 @ b65fon AT4PX
.4byte gUnknown_83B132C @ "b65pal"
.4byte gUnknown_8473608 @ b65pal palette

.4byte gUnknown_83B1324 @ "b66canm"
.4byte gUnknown_8473908 @ b66canm SIRO
.4byte gUnknown_83B131C @ "b66cel"
.4byte gUnknown_8474298 @ b66cel AT4PX
.4byte gUnknown_83B1310 @ "b66emap0"
.4byte gUnknown_8474E60 @ b66emap0 SIRO
.4byte gUnknown_83B1308 @ "b66fon"
.4byte gUnknown_847500B @ b66fon AT4PX
.4byte gUnknown_83B1300 @ "b66pal"
.4byte gUnknown_847745C @ b66pal palette

.4byte gUnknown_83B12F8 @ "b67canm"
.4byte gUnknown_847775C @ b67canm SIRO
.4byte gUnknown_83B12F0 @ "b67cel"
.4byte gUnknown_8477BEC @ b67cel AT4PX
.4byte gUnknown_83B12E4 @ "b67emap0"
.4byte gUnknown_84789A8 @ b67emap0 SIRO
.4byte gUnknown_83B12DC @ "b67fon"
.4byte gUnknown_8478BA9 @ b67fon AT4PX
.4byte gUnknown_83B12D4 @ "b67pal"
.4byte gUnknown_847A598 @ b67pal palette

.4byte gUnknown_83B12CC @ "b68canm"
.4byte gUnknown_847A898 @ b68canm SIRO
.4byte gUnknown_83B12C4 @ "b68cel"
.4byte gUnknown_847AE68 @ b68cel AT4PX
.4byte gUnknown_83B12B8 @ "b68emap0"
.4byte gUnknown_847B910 @ b68emap0 SIRO
.4byte gUnknown_83B12B0 @ "b68fon"
.4byte gUnknown_847BB13 @ b68fon AT4PX
.4byte gUnknown_83B12A8 @ "b68pal"
.4byte gUnknown_847DF24 @ b68pal palette

.4byte gUnknown_83B12A0 @ "b69canm"
.4byte gUnknown_847E224 @ b69canm SIRO
.4byte gUnknown_83B1298 @ "b69cel"
.4byte gUnknown_847E63C @ b69cel AT4PX
.4byte gUnknown_83B128C @ "b69emap0"
.4byte gUnknown_847F268 @ b69emap0 SIRO
.4byte gUnknown_83B1284 @ "b69fon"
.4byte gUnknown_847F420 @ b69fon AT4PX
.4byte gUnknown_83B127C @ "b69pal"
.4byte gUnknown_8481E08 @ b69pal palette

.4byte gUnknown_83B1274 @ "b70canm"
.4byte gUnknown_8482108 @ b70canm SIRO
.4byte gUnknown_83B126C @ "b70cel"
.4byte gUnknown_8482618 @ b70cel AT4PX
.4byte gUnknown_83B1260 @ "b70emap0"
.4byte gUnknown_8482FF8 @ b70emap0 SIRO
.4byte gUnknown_83B1258 @ "b70fon"
.4byte gUnknown_848311F @ b70fon AT4PX
.4byte gUnknown_83B1250 @ "b70pal"
.4byte gUnknown_8485F50 @ b70pal palette

.4byte gUnknown_83B1248 @ "b71canm"
.4byte gUnknown_8486250 @ b71canm SIRO
.4byte gUnknown_83B1240 @ "b71cel"
.4byte gUnknown_84865A0 @ b71cel AT4PX
.4byte gUnknown_83B1234 @ "b71emap0"
.4byte gUnknown_848720C @ b71emap0 SIRO
.4byte gUnknown_83B122C @ "b71fon"
.4byte gUnknown_84873BA @ b71fon AT4PX
.4byte gUnknown_83B1224 @ "b71pal"
.4byte gUnknown_848979C @ b71pal palette

.4byte gUnknown_83B121C @ "b72canm"
.4byte gUnknown_8489A9C @ b72canm SIRO
.4byte gUnknown_83B1214 @ "b72cel"
.4byte gUnknown_848A0AC @ b72cel AT4PX
.4byte gUnknown_83B1208 @ "b72emap0"
.4byte gUnknown_848AD10 @ b72emap0 SIRO
.4byte gUnknown_83B1200 @ "b72fon"
.4byte gUnknown_848AEE5 @ b72fon AT4PX
.4byte gUnknown_83B11F8 @ "b72pal"
.4byte gUnknown_848D5D8 @ b72pal palette

.4byte gUnknown_83B11F0 @ "b73canm"
.4byte gUnknown_848D8D8 @ b73canm SIRO
.4byte gUnknown_83B11E8 @ "b73cel"
.4byte gUnknown_848E028 @ b73cel AT4PX
.4byte gUnknown_83B11DC @ "b73emap0"
.4byte gUnknown_848ED84 @ b73emap0 SIRO
.4byte gUnknown_83B11D4 @ "b73fon"
.4byte gUnknown_848EF18 @ b73fon AT4PX
.4byte gUnknown_83B11CC @ "b73pal"
.4byte gUnknown_8490BF0 @ b73pal palette

.4byte gUnknown_83B11C4 @ "b74canm"
.4byte gUnknown_8490EF0 @ b74canm SIRO
.4byte gUnknown_83B11BC @ "b74cel"
.4byte gUnknown_8491480 @ b74cel AT4PX
.4byte gUnknown_83B11B0 @ "b74emap0"
.4byte gUnknown_84922D0 @ b74emap0 SIRO
.4byte gUnknown_83B11A8 @ "b74fon"
.4byte gUnknown_8492474 @ b74fon AT4PX
.4byte gUnknown_83B11A0 @ "b74pal"
.4byte gUnknown_8494A68 @ b74pal palette

.4byte gUnknown_83B1198 @ "b75canm"
.4byte gUnknown_8494D68 @ b75canm SIRO
.4byte gUnknown_83B1190 @ "b75cel"
.4byte gUnknown_8494EF8 @ b75cel AT4PX
.4byte gUnknown_83B1184 @ "b75emap0"
.4byte gUnknown_8495DD0 @ b75emap0 SIRO
.4byte gUnknown_83B117C @ "b75fon"
.4byte gUnknown_8495F6F @ b75fon AT4PX
.4byte gUnknown_83B1174 @ "b75pal"
.4byte gUnknown_8499554 @ b75pal palette

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
