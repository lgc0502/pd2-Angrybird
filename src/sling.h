#ifndef SLING_H
#define SLING_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>


class sling: public GameItem
{
public:
    sling(float x, float y, float w, float h, b2World *world, QGraphicsScene *scene);
};

#endif // SLING_H
