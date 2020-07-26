#include "circle.h"

Circle OutterCircle = {.center = {0, 0}, .radius = 4};
Circle InnerCircle = {.center = {0, 0}, .radius = 2};

int containsPoint(Point point) {
    if (point.y >= 0) {
        if (point.x <= 0) {
            return CircleContainsPoint(point, OutterCircle);
        } else {
            return CircleContainsPoint(point, InnerCircle) == 0
                && CircleContainsPoint(point, OutterCircle);
        }
    }
    return 0;
}

int main() {
    Point point;

    GetPoint(&point);

    printf("The point (%.2f, %.2f) is %s.", point.x, point.y, 
        containsPoint(point) ? "contained" : "not contained");

    return 0;
}