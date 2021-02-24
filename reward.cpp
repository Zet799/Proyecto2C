#include "reward.h"

Reward::Reward(QObject *parent, const char *dir) : Sprite(parent)
{
    spriteReward = new Sprite();
    pixmap = new QPixmap(dir);

    timerSprite->start(200);
    connect(timerSprite, &QTimer::timeout, this, &Sprite::refresh);
}
