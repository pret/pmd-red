#include "global.h"
#include "code_80521D0.h"

extern void sub_80526D0(u8 r0);
extern u8 sub_8045888(Entity *r0);
extern void sub_80523A8(Entity *r0, const char r1[], u8 r2);
extern u8 sub_8052DC0(Entity *);
extern u8 sub_803F428(u32);

void sub_805229C(void)
{
    return sub_80526D0(0x50);
}

void SendMessage(Entity *pokemon, const char message[])
{
    if (sub_8045888(pokemon) != 0){
        sub_80523A8(pokemon, message, 1);
    }
}

void sub_80522C8(Entity *r0, const char r1[])
{
    if (sub_8045888(r0) != 0){
        sub_80523A8(r0, r1, 0);
    }
}

void sub_80522E8(Entity *r0, const char r1[])
{
    sub_80523A8(r0, r1, 0);
}

void sub_80522F4(Entity *r0, Entity *r1, const char r2[])
{
    u8 temp;
    u32 temp_reg;
    u32 temp2;
    temp = sub_8045888(r0);
    temp_reg = (-temp | temp);
    temp2 = temp_reg >> 31;
    if(sub_8052DC0(r1) != 0)
    {
        temp2 = 1;
    }
    if(temp2 != 0)
    {
        sub_80523A8(r0, r2, 1);
    }
}

void sub_805232C(Entity *r0, Entity *r1, const char r2[])
{
    u8 temp;
    u32 temp_reg;
    u32 temp2;
    temp = sub_8045888(r0);
    temp_reg = (-temp | temp);
    temp2 = temp_reg >> 31;
    if(sub_8052DC0(r1) != 0)
    {
        temp2 = 1;
    }
    if(temp2 != 0)
    {
        sub_80523A8(r0, r2, 0);
    }
}

void sub_8052364(Entity *r0, u32 r1, const char r2[])
{
    u8 temp;
    u32 temp_reg;
    u32 temp2;
    temp = sub_8045888(r0);
    temp_reg = (-temp | temp);
    temp2 = temp_reg >> 31;
    if(sub_803F428(r1) != 0)
    {
        temp2 = 1;
    }
    if(temp2 != 0)
    {
        sub_80523A8(r0, r2, 1);
    }
}

void sub_805239C(Entity *r0, const char r1[])
{
    sub_80523A8(r0, r1, 1);
}
