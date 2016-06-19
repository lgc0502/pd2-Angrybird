#ifndef OBJ_H
#define OBJ_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define OBJ_DENSITY 0.5f
#define OBJ_FRICTION 0.2f
#define OBJ_RESTITUTION 0.1f


class obj: public GameItem
{
public:
    obj(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // OBJ_H
