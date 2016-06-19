#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class blackBird : public Bird
{
public:
    blackBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BLACKBIRD_H
