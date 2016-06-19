#include "yellowbird.h"

yellowbird::yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}
void yellowbird::skill(){
    g_body->SetLinearVelocity(b2Vec2(50,0));
}
