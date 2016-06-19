#ifndef OBJ2_H
#define OBJ2_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define OBJ2_DENSITY 0.5f
#define OBJ2_FRICTION 0.2f
#define OBJ2_RESTITUTION 0.1f


class obj2: public GameItem
{
public:
    obj2(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // OBJ2_H
