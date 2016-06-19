#ifndef WHITEBIRD_H
#define WHITEBIRD_H

#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>


class whiteBird : public Bird
{
public:
    whiteBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // WHITEBIRD_H
