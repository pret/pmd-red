#include "global.h"
#include "friend_rescue.h"
#include "pokemon.h"
#include "memory.h"
#include "text.h"

extern void sub_80338C4(u32);
extern s32 sub_80144A4(s32 *);
extern void sub_802F2C0();
extern u8 sub_809539C(u32, u32);
extern void sub_8095240(u8);
extern u32 sub_802F298();

extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern struct WonderMailStruct_203B33C *gUnknown_203B33C;

extern u8 sub_8039880(void);
void ResetUnusedInputStruct(void);

extern void sub_8035300(void);
extern void sub_8035404(u32);
extern void nullsub_41(void);
extern void nullsub_42(void);
extern void nullsub_43(void);
extern void nullsub_44(void);
extern void nullsub_45(void);
extern void nullsub_46(void);
extern void nullsub_47(void);
extern void nullsub_48(void);
extern void nullsub_49(void);
extern void nullsub_50(void);
extern void nullsub_51(void);
extern void sub_8035374(void);
extern void sub_80353BC(void);
extern void sub_8033A2C(void);
extern void sub_803477C(void);
extern void sub_80347AC(void);
extern void sub_80347C8(void);
extern void sub_80347E4(void);
extern void sub_8034804(void);
extern void sub_80344C0(void);
extern void sub_8034478(void);
extern void sub_80344A0(void);
extern void sub_803418C(void);
extern void sub_8034254(void);
extern void sub_8034310(void);
extern void sub_8034378(void);
extern void sub_80343C4(void);
extern void sub_8034404(void);
extern void sub_8034500(void);
extern void sub_8034590(void);
extern void sub_803464C(void);
extern void sub_80346A8(void);
extern void sub_80346D8(void);
extern void sub_8034700(void);
extern void sub_8034720(void);
extern void sub_803473C(void);
extern void sub_8033FB4(void);
extern void sub_8034074(void);
extern void sub_8034130(void);
extern void sub_8033FE4(void);
extern void sub_8033D74(void);
extern void sub_8033D94(void);
extern void sub_8033DBC(void);
extern void sub_8033F64(void);
extern void sub_8033C54(void);
extern void sub_8033CAC(void);
extern void sub_8033D48(void);
extern void sub_8035424(void);
extern void sub_8034970(void);
extern void sub_80351E0(void);
extern void sub_8034D74(void);
extern void sub_8034EF0(void);
extern void sub_8034F38(void);
extern void sub_80352A4(void);
extern void sub_8034EC8(void);
extern void sub_8033B8C(void);
extern void sub_80339C8(void);
extern void sub_80348C4(void);
extern void sub_803482C(void);
extern void sub_80349B0(void);
extern void sub_8034A70(void);
extern void sub_8034B2C(void);
extern void sub_80349E0(void);
extern void sub_8034B88(void);
extern void sub_8034C98(void);
extern void sub_8034C38(void);
extern void sub_8034D54(void);
extern void sub_8034F18(void);
extern void sub_8034F58(void);
extern void sub_8034F88(void);
extern void sub_8035018(void);
extern void sub_8035038(void);
extern void sub_8035094(void);
extern void sub_80350F4(void);
extern void sub_803517C(void);
extern void sub_8035210(void);
extern void sub_8035430(void);
extern void sub_8034848(void);

extern void sub_803084C(void);
extern void sub_8031E10(void);
extern void sub_8023C60(void);
extern void sub_80155F0(void);
extern void sub_801CBB8(void);
extern void sub_802F2C0(void);
extern void sub_8030DE4(void);
extern void sub_802453C(void);
extern void sub_801B450(void);


u32 CreateFriendRescueMenu(void)
{
  char *monName;
  int counter;

  ResetUnusedInputStruct();
  sub_800641C(0, 1, 1);
  gUnknown_203B33C = MemoryAlloc(sizeof(struct WonderMailStruct_203B33C), 8);
  MemoryFill8((u8 *) gUnknown_203B33C, 0, sizeof(struct WonderMailStruct_203B33C));
  gUnknown_203B33C->unk530 = 0;
  gUnknown_203B33C->unk218 = -1;
  gUnknown_203B33C->unk538 = -1;
  CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_PELIPPER);
  monName = GetMonSpecies(SPECIES_PELIPPER);
  strcpy(gAvailablePokemonNames,monName);
  for(counter = 0; counter < 0x36; counter++){
    gUnknown_203B33C->unk8[counter] = 0;
  }
  gUnknown_203B33C->unk4 = 0x7E;
  gUnknown_203B33C->unk52C = sub_8039880();
  gUnknown_203B33C->unk52D = gUnknown_203B33C->unk52C;
  sub_80338C4(0);
  return 1;
}

u32 UpdateFriendRescueMenu(void)
{
  switch(gUnknown_203B33C->unk0)
  {
    case 0x78:
        sub_8035300();
        break;
    case 0x79:
        sub_8035404(0x78);
        break;
    case 0x7A:
        sub_8035374();
        break;
    case 0x7B:
        sub_8035404(0x7a);
        break;
    case 0x7C:
        sub_80353BC();
        break;
    case 0x7D:
        sub_8035404(0x7c);
        break;
    case 3:
    case 4:
        sub_8033A2C();
        break;
    case 0x3D:
        sub_803477C();
        break;
    case 0x3E:
        sub_80347AC();
        break;
    case 0x3F:
        sub_80347C8();
        break;
    case 0x40:
        sub_80347E4();
        break;
    case 0x41:
        sub_8034804();
        break;
    case 0x2D:
        sub_8035404(0x2e);
        break;
    case 0x2E:
        sub_80344C0();
        break;
    case 0x2A:
        sub_8035404(0xd);
        break;
    case 0x2C:
        sub_8034478();
        break;
    case 0x2B:
        sub_80344A0();
        break;
    case 0x25:
        sub_8035404(0x26);
        break;
    case 0x26:
        sub_803418C();
        break;
    case 0x27:
        sub_8034254();
        break;
    case 0x28:
        sub_8034310();
        break;
    case 0x24:
        sub_8034378();
        break;
    case 0x29:
        sub_80343C4();
        break;
    case 0x23:
        sub_8035404(0x21);
        break;
    case 0x21:
        sub_8034404();
        break;
    case 0x31:
        sub_8035404(0x32);
        break;
    case 0x32:
        sub_8034500();
        break;
    case 0x33:
        sub_8034590();
        break;
    case 0x34:
        sub_803464C();
        break;
    case 0x35:
        sub_80346A8();
        break;
    case 0x38:
        sub_80346D8();
        break;
    case 0x37:
        sub_8034700();
        break;
    case 0x39:
        sub_8034720();
        break;
    case 0x3A:
        sub_803473C();
        break;
    case 0x20:
        sub_8033FB4();
        break;
    case 0x1C:
        sub_8035404(0x1d);
        break;
    case 0x1E:
        sub_8034074();
        break;
    case 0x1F:
        sub_8034130();
        break;
    case 0x1D:
        sub_8033FE4();
        break;
    case 0x11:
        sub_8035404(0x12);
        break;
    case 0x12:
        nullsub_42();
        break;
    case 0x13:
        nullsub_43();
        break;
    case 0x14:
        nullsub_44();
        break;
    case 0x15:
        nullsub_45();
        break;
    case 0x16:
        sub_8033D74();
        break;
    case 0x17:
        sub_8033D94();
        break;
    case 0x19:
    case 0x43:
        sub_8035404(0x1a);
        break;
    case 0x1A:
        sub_8033DBC();
        break;
    case 0x1B:
        sub_8033F64();
        break;
    case 5:
        sub_8033C54();
        break;
    case 6:
        nullsub_41();
        break;
    case 7:
        sub_8033CAC();
        break;
    case 8:
        sub_8033D48();
        break;
    case 9:
        sub_8035424();
        break;
    case 10:
        nullsub_50();
        break;
    case 0xB:
    case 0xC:
        sub_8035404(6);
        break;
    case 0xD:
        sub_8035404(7);
        break;
    case 0xE:
        sub_8033B8C();
        break;
    case 0:
    case 1:
        sub_80339C8();
        break;
    case 2:
        return 3;
    case 0x6A:
        sub_80348C4();
        break;
    case 0x6B:
        sub_803482C();
        break;
    case 0x5A:
        sub_80349B0();
        break;
    case 0x5B:
        sub_8035404(0x5c);
        break;
    case 0x5D:
        sub_8034A70();
        break;
    case 0x5E:
        sub_8034B2C();
        break;
    case 0x5C:
        sub_80349E0();
        break;
    case 0x5F:
        sub_8034B88();
        break;
    case 0x60:
        sub_8034C98();
        break;
    case 0x61:
        sub_8034C38();
        break;
    case 0x68:
        sub_8034D54();
        break;
    case 0x66:
        sub_8035404(0x67);
        break;
    case 0x67:
        sub_8034970();
        break;
    case 0x74:
        sub_80351E0();
        break;
    case 0x72:
        sub_8035404(0x73);
        break;
    case 0x73:
        sub_8034D74();
        break;
    case 0x71:
        sub_8034EF0();
        break;
    case 0x70:
        sub_8034F38();
        break;
    case 0x50:
    case 0x6D:
        sub_8035404(0x6e);
        break;
    case 0x6E:
        sub_80352A4();
        break;
    case 0x62:
        sub_8035404(0x6a);
        break;
    case 0x65:
        sub_8034EC8();
        break;
    case 0x64:
        sub_8034F18();
        break;
    case 0x63:
    case 0x6F:
        sub_8035404(0x62);
        break;
    case 0x69:
        sub_8034F58();
        break;
    case 0x58:
        sub_8034F88();
        break;
    case 0x75:
        sub_8035018();
        break;
    case 0x76:
        sub_8035038();
        break;
    case 0x18:
    case 0x2F:
    case 0x3B:
    case 0x42:
    case 0x59:
    case 0x6C:
    case 0x77:
        sub_8035404(2);
        break;
    case 0x57:
        sub_8035404(0x5f);
        break;
    case 0x56:
        sub_8035094();
        break;
    case 0x55:
        sub_80350F4();
        break;
    case 0x53:
        sub_8035404(0x54);
        break;
    case 0x54:
        sub_803517C();
        break;
    case 0x52:
        sub_8035210();
        break;
    case 0x46:
        sub_8035404(0x47);
        break;
    case 0x47:
        nullsub_46();
        break;
    case 0x48:
        nullsub_47();
        break;
    case 0x49:
        nullsub_48();
        break;
    case 0x4A:
        nullsub_49();
        break;
    case 0x4B:
        sub_8035430();
        break;
    case 0x4C:
        nullsub_51();
        break;
    case 0x4D:
    case 0x4E:
        sub_8035404(0x4f);
        break;
    case 0x4F:
        sub_8034848();
        break;
    case 0xF:
    case 0x10:
    case 0x22:
    case 0x30:
    case 0x3C:
    case 0x44:
    case 0x45:
        sub_8035404(1);
        break;
    case 0x51:
        sub_8035404(1);
        break;
    case 0x36:
        break;
  }
  return 0;
}

void CleanFriendRescueMenu(void)
{
  if (gUnknown_203B33C != NULL) {
    MemoryFree(gUnknown_203B33C);
    gUnknown_203B33C = NULL;
    sub_803084C();
    sub_8031E10();
    sub_8023C60();
    sub_80155F0();
    sub_801CBB8();
    sub_802F2C0();
    sub_8030DE4();
    sub_802453C();
    sub_801B450();
  }
}

void nullsub_40(void)
{
}
