#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QTimer>
#include <math.h>

#include "sprite.h"
#include "player.h"

class Enemy : public Sprite
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent = nullptr, const char *dir = ":/img/sprite.png");

    Sprite *spriteEnemy;

    enum class MovementDirection {UP, DOWN, LEFT, RIGHT};

    float _distanceUp;
    float _distanceDown;
    float _distanceRight;
    float _distanceLeft;

    float distance[4];

signals:

public slots:
    void move();
    void direction(int x, int y);
    int indexSmall(float array[], int size);

private:
    MovementDirection _movementDirection;
};

#endif // ENEMY_H
