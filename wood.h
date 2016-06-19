#ifndef WOOD_H
#define WOOD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QPoint>

#define WOOD_DENSITY 0.1f
#define WOOD_FRICTION 0.2f
#define WOOD_RESTITUTION 0.5f

class wood : public GameItem
{
public:
    wood(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // WOOD_H
