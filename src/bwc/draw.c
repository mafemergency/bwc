#include "bwc/bwc.h"

int bwcDrawRectangle(struct bwcClient *client, enum bwcCoordinateType coord,
    int ax, int ay, int bx, int by, int color, int solid) {

    struct bwcShape shape;
    shape.type = BWC_SHAPE_BOX;
    shape.ctype = coord;
    shape.x1 = ax;
    shape.y1 = ay;
    shape.x2 = bx;
    shape.y2 = by;
    shape.extra1 = 0;
    shape.extra2 = 0;
    shape.color = color;
    shape.isSolid = solid;

    return bwcAddShape(client, shape, NULL);
}

int bwcDrawTriangle(struct bwcClient *client, enum bwcCoordinateType coord,
    int ax, int ay, int bx, int by, int cx, int cy, int color, int solid) {

    struct bwcShape shape;
    shape.type = BWC_SHAPE_TRIANGLE;
    shape.ctype = coord;
    shape.x1 = ax;
    shape.y1 = ay;
    shape.x2 = bx;
    shape.y2 = by;
    shape.extra1 = cx;
    shape.extra2 = cy;
    shape.color = color;
    shape.isSolid = solid;

    return bwcAddShape(client, shape, NULL);
}

int bwcDrawCircle(struct bwcClient *client, enum bwcCoordinateType coord,
    int x, int y, int r, int color, int solid) {

    struct bwcShape shape;
    shape.type = BWC_SHAPE_CIRCLE;
    shape.ctype = coord;
    shape.x1 = x;
    shape.y1 = y;
    shape.x2 = 0;
    shape.y2 = 0;
    shape.extra1 = r;
    shape.extra2 = 0;
    shape.color = color;
    shape.isSolid = solid;

    return bwcAddShape(client, shape, NULL);
}

int bwcDrawEllipse(struct bwcClient *client, enum bwcCoordinateType coord,
    int x, int y, int xrad, int yrad, int color, int solid) {

    struct bwcShape shape;
    shape.type = BWC_SHAPE_ELLIPSE;
    shape.ctype = coord;
    shape.x1 = x;
    shape.y1 = y;
    shape.x2 = 0;
    shape.y2 = 0;
    shape.extra1 = xrad;
    shape.extra2 = yrad;
    shape.color = color;
    shape.isSolid = solid;

    return bwcAddShape(client, shape, NULL);
}

int bwcDrawPoint(struct bwcClient *client, enum bwcCoordinateType coord,
    int x, int y, int color, int solid) {

    struct bwcShape shape;
    shape.type = BWC_SHAPE_DOT;
    shape.ctype = coord;
    shape.x1 = x;
    shape.y1 = y;
    shape.x2 = 0;
    shape.y2 = 0;
    shape.extra1 = 0;
    shape.extra2 = 0;
    shape.color = color;
    shape.isSolid = solid;

    return bwcAddShape(client, shape, NULL);
}

int bwcDrawLine(struct bwcClient *client, enum bwcCoordinateType coord,
    int ax, int ay, int bx, int by, int color, int solid) {

    struct bwcShape shape;
    shape.type = BWC_SHAPE_LINE;
    shape.ctype = coord;
    shape.x1 = ax;
    shape.y1 = ay;
    shape.x2 = bx;
    shape.y2 = by;
    shape.extra1 = 0;
    shape.extra2 = 0;
    shape.color = color;
    shape.isSolid = solid;

    return bwcAddShape(client, shape, NULL);
}
