#include "sling.h"

sling::sling(float x, float y, float w, float h, b2World *world, QGraphicsScene *scene):GameItem(world)
{

    g_size = QSize(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    g_body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&g_pixmap);
    paint();
}
