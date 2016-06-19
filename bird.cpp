#include "bird.h"

Bird::Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}
float Bird::getPosx()
{
    return g_body->GetPosition().x;
}

float Bird::getPosy()
{
    return g_body->GetPosition().y;
}
float Bird::getVelocityX()
{
    return g_body->GetLinearVelocity().x;
}

float Bird::getVelocityY()
{
    return g_body->GetLinearVelocity().y;
}

b2Vec2 Bird::trans(QPoint pt)
{
    b2Vec2 pos;
    pos.Set((pt.x()*g_worldsize.width()/g_windowsize.width()),((1.0f-(pt.y()/g_windowsize.height()))*g_worldsize.height()));

    return pos;
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
