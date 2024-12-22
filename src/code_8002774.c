#include "global.h"
#include "code_8002774.h"
#include "constants/direction.h"
#include "structs/str_position.h"

s32 sub_8002A70(s32 _direction1, s32 _direction2, s32 _caseId)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);
    s32 caseId = (u8)(_caseId);

    if (direction1 == direction2)
        return direction1;

    switch (caseId) {
        case 1:
            if (direction1 >= 0) {
                direction1 += 7;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 2:
            if (direction1 >= 0) {
                direction1 += 1;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 3:
            if (direction1 >= 0) {
                direction1 += 6;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 4:
            if (direction1 >= 0) {
                direction1 += 2;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 11:
            direction1 = sub_8002B04(direction1, direction2);
            // Fallthrough
        case 10:
            direction1 = sub_8002B04(direction1, direction2);
            break;
    }
    return direction1;
}

s32 sub_8002B04(s32 _direction1, s32 _direction2)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);

    if (direction2 != -1)
    {
        s32 newDirection = ((direction2 + NUM_DIRECTIONS) - direction1) % NUM_DIRECTIONS;

        if (newDirection != 0) {
            if (newDirection < 4)
                newDirection = (direction1 + 1) % NUM_DIRECTIONS;
            else
                newDirection = (direction1 + 7) % NUM_DIRECTIONS;

            direction1 = (s8)newDirection;
        }
    }
    return direction1;
}

s32 sub_8002B5C(int _direction1, int _direction2)
{
  int newDirection;
  int iVar2;
  int direction1;
  int direction2;
  
  direction1 = (s8)_direction1;
  direction2 = (s8)_direction2;
    
  if (direction2 != -1) {
    iVar2 = (direction2 + NUM_DIRECTIONS) - direction1;
    newDirection = iVar2;
    if (iVar2 < 0) {
      newDirection = iVar2 + 7;
    }
    newDirection = iVar2 + ((newDirection >> 3) * -8);
      
    if (newDirection != 0) {
      if (newDirection < 4) {
        iVar2 = direction1 + 2;
        newDirection = iVar2;
        if (iVar2 < 0) {
          newDirection = direction1 + 9;
        }
      }
      else {
        iVar2 = direction1 + 6;
        newDirection = iVar2;
        if (iVar2 < 0) {
          newDirection = direction1 + 0xd;
        }
      }
      direction1 = (s8)(iVar2 + (newDirection >> 3) * -8);
    }
  }
  return direction1 & 6;
}

NAKED void SetVecFromDirectionSpeed(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tlsls r1, 24\n"
	"\tasrs r1, 21\n"
	"\tldr r3, _08002BD8\n"
	"\tadds r1, r3\n"
	"\tldr r5, [r1]\n"
	"\tadds r3, r5, 0\n"
	"\tmuls r3, r2\n"
	"\tldr r1, [r1, 0x4]\n"
	"\tadds r4, r1, 0\n"
	"\tmuls r4, r2\n"
	"\tstr r3, [r0]\n"
	"\tstr r4, [r0, 0x4]\n"
	"\tpop {r4,r5}\n"
	"\tpop {r2}\n"
	"\tbx r2\n"
	"\t.align 2, 0\n"
"_08002BD8: .4byte gVectorDirections");
}

s32 VecDirection8Sign(PixelPos *param_1)
{  
  if (param_1->x < 0) {
    if (param_1->y < 0) {
      return 5;
    }
    else if (param_1->y >= 1) {
      return 7;
    }
    else {
      return 6;
    }
  }
  else if (param_1->x >= 1) {
    if (param_1->y < 0) {
      return 3;
    }
    else if (param_1->y > 0) {
      return 1;
    }
    else {
      return 2;
    }
  }
  else if (param_1->y < 0) {
    return 4;
  }
  else if (param_1->y > 0) {
    return 0;
  }
  else {
    return -1;
  }
}

s32 VecDirection4SignYX(PixelPos *param_1)
{
  if (param_1->y < 0) {
    return 4;
  }
  else if (param_1->y > 0) {
    return 0;
  }
  else {
    if (param_1->x < 0) {
      return 6;
    }
    else if (param_1->x > 0) {
      return 2;
    }
    else {
      return -1;
    }
  }
}

// https://decomp.me/scratch/bD5wO 
s8 VecDirection8Radial(PixelPos *param_1)
{
    register s32 r0;
    register s32 r1 asm("r1");
    register s32 r2 asm("r2");
    register s32 r3 asm("r3");
    register s32 r4 asm("r4");
    register s32 r5;


    r0 = param_1->x;
    if (r0 < 0) {
        r0 = -r0;
    }
    r1 = r0;
    r3 = param_1->y;
    r5 = r3;
    if (r3 < 0) {
        r5 = -r3;
    }
    r2 = r5;
    r4 = param_1->x;
    if (r4 < 0) {
        if (r3 < 0) {
            if (r2 > r0 * 2) {
                return 4;
            }
            if (r1 <= r5 * 2) {
                return 5;
            }
            return 6;
        }
        if (r2 <= r0 * 2) {
            if (r1 > r5 * 2) {
                return 6;
            }
            return 7;
        }
    }
    else {
        if (0 < r4) {
            if (r3 < 0) {
                if (r2 > r0 * 2) {
                    return 4;
                }
                if (r1 <= r5 * 2) {
                    return 3;
                }
                return 2;
            }
            else {
                if (r2 > r0 * 2) {
                    return 0;
                }
                if (r1 > r5 * 2) {
                    return 2;
                }
                return 1;
            }

        }
        if (0 > r3) {
            return 4;
        }
        if (r3 < 1) {
            return -1;
        }  
    }
    return 0;
}

// https://decomp.me/scratch/Bgbxc
s8 VecDirection4Radial(PixelPos *param_1)
{
    register s32 r0 asm("r3");
    register s32 r1 asm("r1");
    register s32 r2 asm("r2");
    register s32 r3;
    register s32 r4;
    register s32 r5 asm("r0");

    r0 = param_1->x;
    if (r0 < 0) {
        r0 = -r0;
    }
    r1 = r0;
    r3 = param_1->y;
    r5 = r3;
    if (r3 < 0) {
        r5 = -r3;
    }
    r2 = r5;
    r4 = param_1->x;
    if (r4 < 0) {
        if (r3 < 0) {
            if (r2 > r1) {
                return 4;
            }
            else
                return 6;
        }
        if (r2 <= r1) {
            return 6;
        }
    }
    else {
        if (0 < r4) {
            if (r3 < 0) {
                if (r2 > r1) {
                    return 4;
                }
                else 
                    return 2;
            }
            else {
                if (r2 > r1) {
                    return 0;
                }
                return 2;
            }

        }
        if (0 > r3) {
            return 4;
        }
        if (r3 < 1) {
            return -1;
        }  
    }
    return 0;
}

s8 SizedDeltaDirection4(PixelPos *r0, PixelPos *r1, PixelPos *r2, PixelPos *r3) {
    PixelPos stack;
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;

    stack.x = r2->x  - r0->x;
    stack.y = r2->y  - r0->y;

    if(stack.x >= 0)
    {
        iVar3 = (stack.x + 1);
        iVar3 -= ((r1->x + r3->x) / 2);
        stack.x = iVar3;
        if(stack.x < 0) stack.x = 0;   
    }
    else
    {
        iVar1 = (stack.x - 1);
        iVar1 += ((r1->x + r3->x) / 2);
        stack.x = iVar1;
        if(stack.x > 0) stack.x = 0;
    }

    if(stack.y >= 0)
    {
        iVar2 = (stack.y + 1);
        iVar2 -= ((r1->y + r3->y) / 2);
        stack.y = iVar2;
        if(stack.y < 0) stack.y = 0;
    }
    else
    {
        iVar1 = (stack.y - 1);
        iVar1 += ((r1->y + r3->y) / 2);
        stack.y = iVar1;
        if(stack.y > 0) stack.y = 0;     
    }
    
    
    return VecDirection4Radial(&stack);
}

s8 SizedDeltaDirection8(PixelPos *r0, PixelPos *r1, PixelPos *r2, PixelPos *r3) {
    PixelPos stack;
    s32 iVar1;
    s32 iVar2;
    s32 iVar3;

    stack.x = r2->x  - r0->x;
    stack.y = r2->y  - r0->y;

    if(stack.x >= 0)
    {
        iVar3 = (stack.x + 1);
        iVar3 -= ((r1->x + r3->x) / 2);
        stack.x = iVar3;
        if(stack.x < 0) stack.x = 0;   
    }
    else
    {
        iVar1 = (stack.x - 1);
        iVar1 += ((r1->x + r3->x) / 2);
        stack.x = iVar1;
        if(stack.x > 0) stack.x = 0;
    }

    if(stack.y >= 0)
    {
        iVar2 = (stack.y + 1);
        iVar2 -= ((r1->y + r3->y) / 2);
        stack.y = iVar2;
        if(stack.y < 0) stack.y = 0;
    }
    else
    {
        iVar1 = (stack.y - 1);
        iVar1 += ((r1->y + r3->y) / 2);
        stack.y = iVar1;
        if(stack.y > 0) stack.y = 0;     
    }
    
    
    return VecDirection8Radial(&stack);
}
