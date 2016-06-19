#include "blackbird.h"

blackbird::blackbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}
void blackbird::skill(){
    g_body->SetAngularVelocity(20);
    g_body->SetLinearVelocity(b2Vec2(-20,-10));
}
