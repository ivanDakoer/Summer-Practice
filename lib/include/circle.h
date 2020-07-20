#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "requires.h"

typedef struct { float x, y; } Point;

void GetPoint(Point *point);

typedef struct { Point center; float radius; } Circle;

int CircleContainsPoint(Point point, Circle circle);

#endif