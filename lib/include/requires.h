#ifndef __REQUIRES_H__
#define __REQUIRES_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define sqr(x) (x) * (x)

#define random(min, max) \
    ((double)rand() / RAND_MAX) * ((max) - (min) + 1) + (min)

#define _INT_ sizeof(int)
#define _FLOAT_ sizeof(float)
#define _P_INT_ sizeof(int *)
#define _P_FLOAT_ sizeof(float *)

#define undefined void *

#define STR_SIZE 255
#define NAME_SIZE 45

#endif