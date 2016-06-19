#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>


class yellowBird : public Bird
{
public:
    yellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // YELLOWBIRD_H
