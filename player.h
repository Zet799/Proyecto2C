#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QList>
#include <QTimer>
#include <QMessageBox>

#include "sprite.h"
#include "enemy.h"
#include "box.h"
#include "reward.h"

class Player : public Sprite
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr, const char *dir = ":/img/sprite.png");

    enum class Direction {UP, DOWN, LEFT, RIGHT, NONE};
    enum class DirectionCollide {UP_COLLIDE, DOWN_COLLIDE, LEFT_COLLIDE, RIGHT_COLLIDE, NO_COLLIDE};
    Sprite *spritePlayer;
    QMessageBox msgBox;

    int _x;
    int _y;

signals:

public slots:
    void move();
    bool blocked();
    void keyPressEvent(QKeyEvent *event);
    int collide();

private:
    // main private attributes
    Direction movementDirection_;
    DirectionCollide movementCollide;

};

#endif // PLAYER_H
