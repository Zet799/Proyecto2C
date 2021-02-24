#include "sprite.h"

Sprite::Sprite(QObject *parent) : QObject(parent), QGraphicsItem()
{
    timerSprite = new QTimer();
    row = 0;
    column = 0;

    // dimensiones de imagenes
    width = 64;
    height = 64;
}

void Sprite::refresh()
{
    column += 64;
    if(column >= 256){
        column = 0;
    }
    this->update(-width/2, -height/2, width, height);
}

QRectF Sprite::boundingRect() const
{
    return QRectF(-width/2, -height/2, width, height);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-width/2, -height/2, *pixmap, column, row, width, height);
}

