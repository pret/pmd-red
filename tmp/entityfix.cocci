@@
Entity *e;
@@

- e->spriteInfo
+ (*(struct EntitySpriteInfo *)&e->axObj.axdata)

@@
Entity *e;
@@

- e->sprite
+ e->axObj.spriteFile

@@
Entity *e;
@@

- e->unk68
+ e->axObj.unk40_maybeAnimTimer

@@
Entity *e;
@@

- e->unk6A
+ e->axObj.unk42_animId1

@@
Entity *e;
@@

- e->unk6B
+ e->axObj.unk43_animId2

@@
Entity *e;
@@

- e->direction
+ e->axObj.unk44_direction1

@@
Entity *e;
@@

- e->direction2
+ e->axObj.unk45_orientation

@@
Entity *e;
@@

- e->unk6E
+ e->axObj.unk46

@@
Entity *e;
@@

- e->unk6F
+ e->axObj.unk47

@@
Entity *e;
@@

- e->info
+ e->axObj.info

@@
Entity e;
@@

- e.info
+ e.axObj.info
