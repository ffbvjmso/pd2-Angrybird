#ifndef BLUEBIRD_H
#define BLUEBIRD_H

#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class blueBird : public Bird
{
public:
    blueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BLUEBIRD_H
