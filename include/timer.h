/**
 * Authors.....: Jens Steube <jens.steube@gmail.com>
 * License.....: MIT
 */

#ifndef _TIMER_H
#define _TIMER_H

#ifdef _POSIX
#include <sys/time.h>
#else
#endif

#ifdef _WIN
typedef LARGE_INTEGER  hc_timer_t;
#elif _POSIX
typedef struct timeval hc_timer_t;
#endif

#ifdef _WIN

#define hc_timer_get(a,r) { hc_timer_t hr_freq; QueryPerformanceFrequency (&hr_freq); hc_timer_t hr_tmp; hc_timer_set (&hr_tmp); (r) = (double) ((double) (hr_tmp.QuadPart - (a).QuadPart) / (double) (hr_freq.QuadPart / 1000)); }
#define hc_timer_set(a)   { QueryPerformanceCounter ((a)); }

#elif _POSIX

#define hc_timer_get(a,r) { hc_timer_t hr_tmp; hc_timer_set (&hr_tmp); (r) = (double) (((hr_tmp.tv_sec - (a).tv_sec) * 1000) + ((double) (hr_tmp.tv_usec - (a).tv_usec) / 1000)); }
#define hc_timer_set(a)   { gettimeofday ((a), NULL); }

#endif

#endif // _TIMER_H