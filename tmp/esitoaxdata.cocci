@ @
struct EntitySpriteInfo *e;
@@
(
- e->unk0
+ e->flags
|
- e->spriteAnimationCounter
+ e->animFrames
|
- e->spriteAnimationIndex
+ e->animWaitFrames
|
- e->spriteAnimationCounter2
+ e->totalFrames
|
- e->spritePos
+ e->sub1.pos
|
- e->spritePosOffset
+ e->sub1.offset
|
- e->unk14
+ e->sub1.unkC
|
- e->unk18
+ e->sub1.unk10
|
- e->unk1C
+ e->sub1.vramTileOrMaybeAnimTimer
|
- e->spriteIndexForEntity
+ e->sub1.poseId
|
- e->spriteIndexForEntity2
+ e->sub1.lastPoseId
|
- e->spriteBaseForDirection
+ e->nextAnimData
|
- e->spriteGlobalIndex
+ e->activeAnimData
|
- e->unk30
+ e->paletteData
|
- e->unk34
+ e->poseData
|
- e->unk38
+ e->spriteData
)

@ @
struct EntitySpriteInfo *e;
expression v;
type T;
@@
(
- e->nextAnimData = (T)v
+ e->nextAnimData = v
|
- e->activeAnimData = (T)v
+ e->activeAnimData = v
|
- e->paletteData = (T)v
+ e->paletteData = v
|
- e->poseData = (T)v
+ e->poseData = v
|
- e->spriteData = (T)v
+ e->spriteData = v
)

@ @
expression a;
@@
- (*(struct EntitySpriteInfo*)&(a))
+ a

@ @
typedef EntitySpriteInfo;
typedef axdata;
@@
- EntitySpriteInfo*
+ axdata*

@ @
struct axdata e;
@@
(
- e.unk18
+ e.sub1.unk10
)
