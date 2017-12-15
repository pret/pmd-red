/*
 * ====================================================
 * Copyright (C) 1998 by Cygnus Solutions. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

	#include "i386mach.h"

	.global	SYM (memcpy)

SYM (memcpy):

	pushl ebp
	movl esp,ebp
	subl $16,esp
	pushl edi
	pushl esi
	movl 8(ebp),edi
	movl 12(ebp),esi
	movl 16(ebp),ecx
	cld

#ifndef __OPTIMIZE_SIZE__
/* if aligned on long boundary, move doublewords at a time first */

	movl edi,eax
	orl esi,eax
	testb $3,al
	jne BYTEMOVE
	shrl $2,ecx
	rep
	movsl

/* calculate any remainder bytes after moving doublewords */

	movl 16(ebp),ecx
	andl $3,ecx
#endif /* not __OPTIMIZE_SIZE__ */
	
/* move any unaligned bytes or remainder bytes, one at a time */

BYTEMOVE: 
	rep
	movsb

/* return destination address */

	movl 8(ebp),eax

	leal -24(ebp),esp
	popl esi
	popl edi
	leave
	ret
