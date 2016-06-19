#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H
#include <bird.h>

class yellowbird:public Bird
{
public:
    yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // YELLOWBIRD_H
