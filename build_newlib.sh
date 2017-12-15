#!/bin/sh

# Put this in newlib-1.8.2/newlib/libc (version not final)

AGBCC=${HOME}/pmd-red/tools/agbcc  # change this to wherever you keep your agbcc source

# Make sure DEVKITARM is defined in your environment, otherwise this will fail

CPP=cpp
CPPFLAGS="-undef -nostdinc -I${AGBCC}/include -Ilibc/include -iquote libm/common -D__thumb__ -D__GNUC__"
CC1=${AGBCC}/bin/old_agbcc
CCFLAGS="-O2 -fhex-asm"
AS=${DEVKITARM}/bin/arm-none-eabi-as
ASFLAGS="-mcpu=arm7tdmi"
AR=ar
ARFLAGS="-rc"

dummy=

names="
	libc/string/memcpy
	libc/string/memset
	libc/stdio/sprintf
	libc/string/strcat
	libc/string/strcmp
	libc/string/strcpy
	libc/string/strlen
	libc/string/strncpy
	libc/stdio/vfprintf
	libc/stdio/vsprintf
	libc/stdio/wsetup
	libc/stdlib/dtoa
	libc/stdio/fflush
	libc/stdio/findfp
	${dummy# libc/stdlib/mallocr:FREE}
	libc/stdio/fvwrite
	libc/stdio/fwalk
	libc/locale/locale
	libc/stdio/makebuf
	${dummy# libc/stdlib/mallocr:MALLOC}
	libc/stdlib/mbtowc
	libc/string/memchr
	libc/string/memmove
	libc/stdlib/mlock
	libc/stdlib/mprec
	libm/math/s_isinf
	libm/math/s_isnan
	libc/reent/sbrkr
	libc/stdio/stdio
	libc/sys/arm/syscalls
	libc/reent/writer
	${dummy# libc/stdlib/mallocr:CALLOC}
	libc/reent/closer
	libc/reent/impure
	libc/reent/fstatr
	libc/stdlib/abort
	libc/sys/arm/syscalls
	libc/sys/arm/libcfunc
	libc/reent/lseekr
	libc/reent/readr
"

compile () {
	lib=$1
	name=$2
	outp=$3
	ADDCPPFLAGS="$4"
	${CPP} ${CPPFLAGS} ${ADDCPPFLAGS} -o ${outp}.i ${name}.c && \
	${CC1} ${CCFLAGS} ${outp}.i && \
	rm -f ${outp}.i && \
	bash -c 'echo -e ".text\n\t.align\t2, 0\n"' >> ${outp}.s && \
	${AS} ${ASFLAGS} -o ${outp}.o ${outp}.s && \
	# rm -f ${outp}.s && \
	${AR} ${ARFLAGS} tmp${lib}.a ${outp}.o && \
	rm -f ${outp}.o || echo error in ${name}
}

rm -f tmplibc.a tmplibm.a
set -e
for name in $(echo ${names})
do
    echo ${name}
    lib=$(echo ${name} | cut -d'/' -f1)
    compile ${lib} ${name} ${name} ""
done

# For some reason the two halves of mallocr are assembled separately

for comp in MALLOC FREE CALLOC
do
	echo stdlib/mallocr with ${comp}
	compile libc libc/stdlib/mallocr libc/stdlib/mallocr_${comp} "-DINTERNAL_NEWLIB -DDEFINE_${comp}"
done

mv tmplibc.a libc.a
mv tmplibm.a libm.a
