#include "shooter.h"

shooter::shooter(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
   // g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
//    b2CircleShape bodyshape;
//    bodyshape.m_radius = radius;
    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w,h);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = SHOOTER_DENSITY;
    fixturedef.friction = SHOOTER_FRICTION;
    fixturedef.restitution = SHOOTER_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    scene->addItem(&g_pixmap);
    paint();

}
