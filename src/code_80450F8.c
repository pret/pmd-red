#include "global.h"
#include "structs/str_dungeon.h"
#include "code_803E724.h"
#include "code_80450F8.h"
#include "dungeon_map_access.h"
#include "dungeon_range.h"
#include "dungeon_util.h"
#include "tile_types.h"

// Related to sub_80828E0
// 93.08% https://decomp.me/scratch/AYGBN
/*Entity *sub_80453AC(s16 id)
{
    s32 something; // r1
    s32 uVar8; // r2
    Entity *entity; // r4
    s32 r5;
    u8 bodySize; // r6
    s32 id_; // r8
    //register s32 id_ asm("r8"); // r8
    s32 r9;

    id_ = id; // SpeciesId() ?
    r9 = -1;
    bodySize = GetBodySize(id_);

    for (r5 = 0; r5 <= MAX_TEAM_BODY_SIZE - bodySize; r5++) {
        for (uVar8 = 0; uVar8 < bodySize; uVar8++) {
            if (gUnknown_202EE70[r5 + uVar8] != 0)
                break;
        }

        if (uVar8 == bodySize) {
            r9 = r5;
            break;
        }
    }

    if (r9 != -1) {
        for (r5 = 0; r5 < MAX_TEAM_MEMBERS; r5++) {
            entity = gDungeon->teamPokemon[r5];
            if (!EntityExists(entity)) {
                entity->type = ENTITY_MONSTER;
                entity->unk24 = r5;
                entity->axObj.info = &gDungeon->unk69C[r5];
                entity->axObj.info->id = id_;
                entity->axObj.info->apparentID = sub_8069F54(NULL, id_);
                entity->axObj.info->isNotTeamMember = FALSE;

                entity->axObj.spriteFile = GetSpriteData(sub_8069F54(NULL, id_));
                entity->axObj.unk40_maybeAnimTimer = (r9 * 0x10) + 0x40;
                entity->axObj.unk42_animId1 = 7;
                entity->axObj.unk44_direction1 = 0;
                entity->axObj.unk43_animId2 = 0xFF;
                entity->axObj.unk45_orientation = 1;
                entity->axObj.unk47 = 1;

                entity->unk1C = 0;
                sub_8045ACC();
                entity->axObj.info->unk167 = r9;
                entity->axObj.info->unk168 = bodySize;

                for (something = 0; something < bodySize; something++) {
                    gUnknown_202EE70[r9] = 1;
                    r9++;
                }

                entity->spawnGenID = gDungeon->unk668++;
                return entity;
            }
        }
    }

    return NULL;
}*/
NAKED
Entity *sub_80453AC(s16 id)
{
    asm_unified(
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	mov r8, r0\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	mov r9, r0\n"
"	mov r0, r8\n"
"	bl GetBodySize\n"
"	lsls r0, 24\n"
"	lsrs r6, r0, 24\n"
"	movs r5, 0\n"
"	movs r0, 0x6\n"
"	subs r3, r0, r6\n"
"	ldr r4, _080453D8\n"
"	b _080453DE\n"
"	.align 2, 0\n"
"_080453D8: .4byte gUnknown_202EE70\n"
"_080453DC:\n"
"	adds r5, 0x1\n"
"_080453DE:\n"
"	cmp r5, r3\n"
"	bgt _08045400\n"
"	movs r2, 0\n"
"	cmp r2, r6\n"
"	bge _080453FA\n"
"	adds r1, r5, r4\n"
"	b _080453F4\n"
"_080453EC:\n"
"	adds r1, 0x1\n"
"	adds r2, 0x1\n"
"	cmp r2, r6\n"
"	bge _080453FA\n"
"_080453F4:\n"
"	ldrb r0, [r1]\n"
"	cmp r0, 0\n"
"	beq _080453EC\n"
"_080453FA:\n"
"	cmp r2, r6\n"
"	bne _080453DC\n"
"	mov r9, r5\n"
"_08045400:\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	cmp r9, r0\n"
"	beq _080454FC\n"
"	movs r5, 0\n"
"	ldr r7, _080454DC\n"
"_0804540C:\n"
"	ldr r1, _080454E0\n"
"	ldr r0, [r1]\n"
"	lsls r1, r5, 2\n"
"	ldr r2, _080454E4\n"
"	adds r0, r2\n"
"	adds r0, r1\n"
"	ldr r4, [r0]\n"
"	adds r0, r4, 0\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	mov r10, r0\n"
"	cmp r0, 0\n"
"	bne _080454F0\n"
"	movs r0, 0x1\n"
"	str r0, [r4]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x24\n"
"	strb r5, [r0]\n"
"	ldr r1, _080454E0\n"
"	ldr r0, [r1]\n"
"	adds r0, r7\n"
"	str r0, [r4, 0x70]\n"
"	mov r2, r8\n"
"	strh r2, [r0, 0x2]\n"
"	movs r0, 0\n"
"	mov r1, r8\n"
"	bl GetMonsterApparentID\n"
"	ldr r1, [r4, 0x70]\n"
"	strh r0, [r1, 0x4]\n"
"	ldr r0, [r4, 0x70]\n"
"	movs r5, 0\n"
"	strb r5, [r0, 0x6]\n"
"	movs r0, 0\n"
"	mov r1, r8\n"
"	bl GetMonsterApparentID\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	bl GetSpriteData\n"
"	str r0, [r4, 0x64]\n"
"	mov r1, r9\n"
"	lsls r0, r1, 4\n"
"	adds r0, 0x40\n"
"	adds r1, r4, 0\n"
"	adds r1, 0x68\n"
"	strh r0, [r1]\n"
"	adds r1, 0x2\n"
"	movs r0, 0x7\n"
"	strb r0, [r1]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x6C\n"
"	movs r2, 0\n"
"	strb r2, [r0]\n"
"	adds r1, 0x1\n"
"	movs r0, 0xFF\n"
"	strb r0, [r1]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x6D\n"
"	movs r5, 0x1\n"
"	strb r5, [r0]\n"
"	adds r0, 0x2\n"
"	strb r5, [r0]\n"
"	mov r0, r10\n"
"	str r0, [r4, 0x1C]\n"
"	bl sub_8045ACC\n"
"	ldr r0, [r4, 0x70]\n"
"	ldr r1, _080454E8\n"
"	adds r0, r1\n"
"	mov r2, r9\n"
"	strb r2, [r0]\n"
"	ldr r0, [r4, 0x70]\n"
"	movs r5, 0xB4\n"
"	lsls r5, 1\n"
"	adds r0, r5\n"
"	strb r6, [r0]\n"
"	cmp r6, 0\n"
"	beq _080454C6\n"
"	ldr r3, _080454EC\n"
"	movs r2, 0x1\n"
"	adds r1, r6, 0\n"
"_080454B6:\n"
"	mov r5, r9\n"
"	adds r0, r5, r3\n"
"	strb r2, [r0]\n"
"	movs r0, 0x1\n"
"	add r9, r0\n"
"	subs r1, 0x1\n"
"	cmp r1, 0\n"
"	bne _080454B6\n"
"_080454C6:\n"
"	ldr r1, _080454E0\n"
"	ldr r0, [r1]\n"
"	movs r2, 0xCD\n"
"	lsls r2, 3\n"
"	adds r0, r2\n"
"	ldrh r2, [r0]\n"
"	adds r1, r2, 0x1\n"
"	strh r1, [r0]\n"
"	strh r2, [r4, 0x26]\n"
"	adds r0, r4, 0\n"
"	b _080454FE\n"
"	.align 2, 0\n"
"_080454DC: .4byte 0x0000069c\n"
"_080454E0: .4byte gDungeon\n"
"_080454E4: .4byte 0x0001357c\n"
"_080454E8: .4byte 0x00000167\n"
"_080454EC: .4byte gUnknown_202EE70\n"
"_080454F0:\n"
"	movs r0, 0x82\n"
"	lsls r0, 2\n"
"	adds r7, r0\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x3\n"
"	ble _0804540C\n"
"_080454FC:\n"
"	movs r0, 0\n"
"_080454FE:\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1"
);
}

// Related to sub_8082A08
// 91.51% https://decomp.me/scratch/Fp0Kw
/*Entity *sub_804550C(s16 a)
{
    s32 something; // r1
    s32 uVar8; // r2
    Entity *entity; // r4
    s32 r5;
    u8 r6;
    s32 id; // r8
    s32 r9;
    s32 timer; // sp0

    id = a; // SpeciesId() ?
    r9 = -1;
    r6 = GetBodySize(id);

    for (r5 = 0; r5 <= DUNGEON_MAX_WILD_POKEMON_BODY_SIZE - r6; r5++) {
        for (uVar8 = 0; uVar8 < r6; uVar8++) {
            if (gUnknown_202EE76[r5 + uVar8] != 0)
                break;
        }

        if (uVar8 == r6) {
            r9 = r5;
            break;
        }
    }

    if (r9 != -1) {
        for (r5 = 0; r5 < DUNGEON_MAX_WILD_POKEMON_BODY_SIZE; r5++) {
            timer = (r9 * 0x10) + 0xA0;
            entity = gDungeon->wildPokemon[r5];
            if (!EntityExists(entity)) {
                entity->type = ENTITY_MONSTER;
                entity->unk24 = r5;
                entity->unk22 = 0;
                entity->axObj.info = &gDungeon->unkEBC[r5];
                entity->axObj.info->id = id;
                entity->axObj.info->apparentID = sub_8069F54(NULL, id);
                entity->axObj.info->isNotTeamMember = TRUE;

                entity->axObj.spriteFile = GetSpriteData(sub_8069F54(NULL, id));
                entity->axObj.unk40_maybeAnimTimer = timer;
                entity->axObj.unk42_animId1 = 7;
                entity->axObj.unk44_direction1 = 0;
                entity->axObj.unk43_animId2 = 0xFF;
                entity->axObj.unk45_orientation = 1;
                entity->axObj.unk47 = 1;

                entity->unk1C = 0;

                entity->axObj.info->unk167 = r9;
                entity->axObj.info->unk168 = r6;

                for (something = 0; something < r6; something++) {
                    gUnknown_202EE76[r9] = 1;
                    r9++;
                }

                sub_8045ACC();

                entity->spawnGenID = gDungeon->unk668++;
                return entity;
            }
        }
    }

    return NULL;
}*/
NAKED
Entity *sub_804550C(s16 a)
{
    asm_unified(
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x8\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	mov r8, r0\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	mov r9, r0\n"
"	mov r0, r8\n"
"	bl GetBodySize\n"
"	lsls r0, 24\n"
"	lsrs r7, r0, 24\n"
"	movs r5, 0\n"
"	movs r0, 0x10\n"
"	subs r3, r0, r7\n"
"	ldr r4, _08045538\n"
"	b _0804553E\n"
"	.align 2, 0\n"
"_08045538: .4byte gUnknown_202EE76\n"
"_0804553C:\n"
"	adds r5, 0x1\n"
"_0804553E:\n"
"	cmp r5, r3\n"
"	bgt _08045560\n"
"	movs r2, 0\n"
"	cmp r2, r7\n"
"	bge _0804555A\n"
"	adds r1, r5, r4\n"
"	b _08045554\n"
"_0804554C:\n"
"	adds r1, 0x1\n"
"	adds r2, 0x1\n"
"	cmp r2, r7\n"
"	bge _0804555A\n"
"_08045554:\n"
"	ldrb r0, [r1]\n"
"	cmp r0, 0\n"
"	beq _0804554C\n"
"_0804555A:\n"
"	cmp r2, r7\n"
"	bne _0804553C\n"
"	mov r9, r5\n"
"_08045560:\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	cmp r9, r0\n"
"	bne _0804556A\n"
"	b _08045670\n"
"_0804556A:\n"
"	movs r5, 0\n"
"	movs r1, 0x1\n"
"	mov r10, r1\n"
"	ldr r2, _08045650\n"
"	mov r3, r9\n"
"	lsls r0, r3, 4\n"
"	adds r0, 0xA0\n"
"	str r0, [sp]\n"
"_0804557A:\n"
"	ldr r1, _08045654\n"
"	ldr r0, [r1]\n"
"	lsls r1, r5, 2\n"
"	ldr r3, _08045658\n"
"	adds r0, r3\n"
"	adds r0, r1\n"
"	ldr r4, [r0]\n"
"	adds r0, r4, 0\n"
"	str r2, [sp, 0x4]\n"
"	bl EntityExists\n"
"	lsls r0, 24\n"
"	lsrs r6, r0, 24\n"
"	ldr r2, [sp, 0x4]\n"
"	cmp r6, 0\n"
"	bne _08045664\n"
"	mov r0, r10\n"
"	str r0, [r4]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x24\n"
"	strb r5, [r0]\n"
"	subs r0, 0x2\n"
"	strb r6, [r0]\n"
"	ldr r1, _08045654\n"
"	ldr r0, [r1]\n"
"	adds r0, r2\n"
"	str r0, [r4, 0x70]\n"
"	mov r2, r8\n"
"	strh r2, [r0, 0x2]\n"
"	movs r0, 0\n"
"	mov r1, r8\n"
"	bl GetMonsterApparentID\n"
"	ldr r1, [r4, 0x70]\n"
"	strh r0, [r1, 0x4]\n"
"	ldr r0, [r4, 0x70]\n"
"	mov r3, r10\n"
"	strb r3, [r0, 0x6]\n"
"	movs r0, 0\n"
"	mov r1, r8\n"
"	bl GetMonsterApparentID\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	bl GetSpriteData\n"
"	str r0, [r4, 0x64]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x68\n"
"	mov r5, sp\n"
"	ldrh r5, [r5]\n"
"	strh r5, [r0]\n"
"	adds r1, r4, 0\n"
"	adds r1, 0x6A\n"
"	movs r0, 0x7\n"
"	strb r0, [r1]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x6C\n"
"	movs r1, 0\n"
"	strb r1, [r0]\n"
"	adds r1, r4, 0\n"
"	adds r1, 0x6B\n"
"	movs r0, 0xFF\n"
"	strb r0, [r1]\n"
"	adds r0, r4, 0\n"
"	adds r0, 0x6D\n"
"	mov r2, r10\n"
"	strb r2, [r0]\n"
"	adds r0, 0x2\n"
"	strb r2, [r0]\n"
"	str r6, [r4, 0x1C]\n"
"	ldr r0, [r4, 0x70]\n"
"	ldr r3, _0804565C\n"
"	adds r0, r3\n"
"	mov r5, r9\n"
"	strb r5, [r0]\n"
"	ldr r0, [r4, 0x70]\n"
"	movs r1, 0xB4\n"
"	lsls r1, 1\n"
"	adds r0, r1\n"
"	strb r7, [r0]\n"
"	cmp r7, 0\n"
"	beq _08045636\n"
"	ldr r3, _08045660\n"
"	movs r2, 0x1\n"
"	adds r1, r7, 0\n"
"_08045626:\n"
"	mov r5, r9\n"
"	adds r0, r5, r3\n"
"	strb r2, [r0]\n"
"	movs r0, 0x1\n"
"	add r9, r0\n"
"	subs r1, 0x1\n"
"	cmp r1, 0\n"
"	bne _08045626\n"
"_08045636:\n"
"	bl sub_8045ACC\n"
"	ldr r1, _08045654\n"
"	ldr r0, [r1]\n"
"	movs r2, 0xCD\n"
"	lsls r2, 3\n"
"	adds r0, r2\n"
"	ldrh r2, [r0]\n"
"	adds r1, r2, 0x1\n"
"	strh r1, [r0]\n"
"	strh r2, [r4, 0x26]\n"
"	adds r0, r4, 0\n"
"	b _08045672\n"
"	.align 2, 0\n"
"_08045650: .4byte 0x00000ebc\n"
"_08045654: .4byte gDungeon\n"
"_08045658: .4byte 0x0001358c\n"
"_0804565C: .4byte 0x00000167\n"
"_08045660: .4byte gUnknown_202EE76\n"
"_08045664:\n"
"	movs r3, 0x82\n"
"	lsls r3, 2\n"
"	adds r2, r3\n"
"	adds r5, 0x1\n"
"	cmp r5, 0xF\n"
"	ble _0804557A\n"
"_08045670:\n"
"	movs r0, 0\n"
"_08045672:\n"
"	add sp, 0x8\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1"
);
}

Entity *sub_8045684(u8 trapID, DungeonPos *pos, u8 c)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_TRAPS; i++) {
        entity = gDungeon->traps[i];
        if (!EntityExists(entity)) {
            entity->type = ENTITY_TRAP;
            entity->axObj.info.trap = &gDungeon->unk3908[i];
            entity->axObj.info.trap->id = trapID;
            entity->axObj.info.trap->unk1 = c;

            entity->unk1C = 0;
            entity->unk22 = 0;
            entity->pos = *pos;
            entity->spawnGenID = 0;
            return entity;
        }
    }

    return NULL;
}

Entity *sub_8045708(DungeonPos *pos)
{
    s32 i;
    Entity *ent;

    if (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA
        && (GetTileMut(pos->x, pos->y)->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == TERRAIN_TYPE_SECONDARY) {
        return NULL;
    }

    for (i = 0; i < DUNGEON_MAX_ITEMS; i++) {
        ent = gDungeon->items[i];
        if (!EntityExists(ent)) {
            ent->type = ENTITY_ITEM;
            ent->axObj.info.item = &gDungeon->unk3804[i];

            ent->pos = *pos;
            SetEntityPixelPos(ent, ((pos->x * 24) + 4) * 0x100, ((pos->y * 24) + 4) * 0x100);
            ent->spawnGenID = 0;
            ent->unk22 = 0;
            ent->unk1C = 0;
            return ent;
        }
    }

    return NULL;
}

void sub_80457DC(Entity* ent)
{
    ent->type = ENTITY_UNK_5;
    ent->pos.x = 0;
    ent->pos.y = 0;
    SetEntityPixelPos(ent, 0, 0);
    ent->spawnGenID = 0;
    ent->unk22 = 0;
}

bool8 sub_8045804(Entity *ent)
{
    UnkDungeonGlobal_unk181E8_sub* saveTyping;
    Entity* camTarget;
    EntityInfo *monInfo;

    switch (GetEntityType(ent)) {
        case ENTITY_MONSTER: {
            if (ent->isVisible) {
                saveTyping = &gDungeon->unk181e8;
                camTarget = saveTyping->cameraTarget;
                monInfo = GetEntInfo(ent);

                if (!monInfo->isNotTeamMember)
                    return TRUE;

                if (!saveTyping->unk1820F && monInfo->invisibleClassStatus.status == STATUS_INVISIBLE)
                    return FALSE;

                if (saveTyping->unk1820B || saveTyping->unk1820D)
                    return TRUE;

                if (camTarget != NULL)
                    return IsPositionActuallyInSight(&saveTyping->cameraPos, &ent->pos);
            }
            return FALSE;
        }
        /*case ENTITY_TRAP:
        case ENTITY_ITEM:
        case ENTITY_UNK_4:*/
        default: {
            return TRUE;
        }
        case ENTITY_NOTHING:
        case ENTITY_UNK_5: {
            return FALSE;
        }
    }
}

bool8 sub_8045888(Entity *ent)
{
    if (ent->isVisible) {
        s32 x = (ent->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
        s32 y = (ent->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y;

        if (x >= -32 && y >= -32 && x <= 272 && y <= 192) {
            UnkDungeonGlobal_unk181E8_sub *saveTyping = &gDungeon->unk181e8;

            switch (GetEntityType(ent)) {
                case ENTITY_ITEM: {
                    if (!saveTyping->unk1820E && !sub_803F428(&ent->pos))
                        return FALSE;
                    break;
                }
                case ENTITY_MONSTER: {
                    EntityInfo *monInfo = GetEntInfo(ent);

                    if (monInfo->isNotTeamMember) {
                        if (!gDungeon->unk181e8.unk1820F && monInfo->invisibleClassStatus.status == STATUS_INVISIBLE)
                            return FALSE;

                        if (!saveTyping->unk1820D && !sub_803F428(&ent->pos))
                            return FALSE;
                    }
                    break;
                }
                case ENTITY_TRAP: {
                    if (!gDungeon->unk181e8.unk1820F && !ent->isVisible)
                        return FALSE;
                    break;
                }
                case ENTITY_NOTHING:
                case ENTITY_UNK_5: {
                    return FALSE;
                }
                case ENTITY_UNK_4:
                default: {
                    break;
                }
            }

            return TRUE;
        }
    }

    return FALSE;
}