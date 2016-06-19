#ifndef SHOOTER_H
#define SHOOTER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define SHOOTER_DENSITY 0.0f
#define SHOOTER_FRICTION 0.2f
#define SHOOTER_RESTITUTION 0.5f

class shooter : public GameItem
{
public:
//    shooter();
    shooter(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // SHOOTER_H
