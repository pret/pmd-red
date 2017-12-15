/*
 *  $Id: times.h,v 1.1 1997/06/24 21:53:03 dje Exp $
 */

#ifndef __POSIX_SYS_TIMES_h
#define __POSIX_SYS_TIMES_h

#include <sys/types.h>

/*
 *  4.5.2 Get Process Times, P1003.1b-1993, p. 92
 */

struct tms {
  clock_t tms_utime;   /* User CPU time */
  clock_t tms_stime;   /* System CPU time */
  clock_t tms_cutime;  /* User CPU time of terminated child processes */
  clock_t tms_cstime;  /* System CPU time of terminated child processes */
};

#endif
/* end of include file */

