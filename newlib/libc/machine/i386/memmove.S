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
	
	.global SYM (memmove)

SYM (memmove):

	pushl ebp
	movl esp,ebp
	pushl esi
	pushl edi
	pushl ebx
	movl 8(ebp),edi
	movl 16(ebp),ecx
	movl 12(ebp),esi

/*  check for destructive overlap (src < dst && dst < src + length) */
	
	cld
	cmpl edi,esi
	jae  .L2
	leal -1(ecx,esi),ebx
	cmpl ebx,edi
	ja   .L2

/* destructive overlap, must copy backwards...do it a byte at a time since it is uncommon */	

	decl edi
	movl ebx,esi
	addl ecx,edi
	std
	jmp BYTEMOVE
.L2:
#ifndef __OPTIMIZE_SIZE__
/* non-destructive overlap so we can try and move 4 bytes at a time */
			
	movl esi,eax
	orl edi,eax
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
		
	movl 8(ebp),eax

	leal -12(ebp),esp
	popl ebx
	popl edi
	popl esi
	leave
	ret
