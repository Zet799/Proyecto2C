#ifndef REWARD_H
#define REWARD_H

#include <QObject>
#include <QDebug>
#include <QGraphicsScene>

#include "sprite.h"

class Reward : public Sprite
{
    Q_OBJECT
public:
    Reward(QObject *parent = nullptr, const char *dir = ":/img/reward.png");

    Sprite *spriteReward;
};

#endif // REWARD_H
