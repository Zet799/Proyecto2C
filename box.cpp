#include "box.h"

Box::Box(QObject *parent, const char *dir) : Sprite(parent)
{
    spriteBox = new Sprite();
    pixmap = new QPixmap(dir);
}
