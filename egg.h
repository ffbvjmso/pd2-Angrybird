#ifndef EGG_H
#define EGG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QPoint>

#define EGG_DENSITY 10.0f
#define EGG_FRICTION 0.2f
#define EGG_RESTITUTION 0.5f

class egg : public GameItem
{
public:
    egg(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void eggsetLinearVelocity(b2Vec2 velocity);
};

#endif // EGG_H
