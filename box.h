#ifndef BOX_H
#define BOX_H

#include <QObject>
#include <QDebug>
#include <QGraphicsScene>

#include "sprite.h"

class Box : public Sprite
{
    Q_OBJECT
public:
    explicit Box(QObject *parent = nullptr, const char *dir = ":/img/box.png");

    Sprite *spriteBox;
};

#endif // BOX_H
