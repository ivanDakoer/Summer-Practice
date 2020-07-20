#include "circle.h"

int CircleContainsPoint(Point point, Circle circle) {
    return sqr(point.x - circle.center.x) + sqr(point.y - circle.center.y) <= sqr(circle.radius);
}

void GetPoint(Point *point) {
    printf("Enter x: ");
    scanf("%f", &point->x);

    printf("Enter y: ");
    scanf("%f", &point->y);
}