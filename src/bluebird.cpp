#include "bluebird.h"

bluebird::bluebird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}
void bluebird::skill(){
    g_body->SetLinearVelocity(b2Vec2(0,-50));
}
