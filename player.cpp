#include "player.h"
#include <QCoreApplication>

Player::Player(QObject *parent, const char *dir) : Sprite(parent)
{
    spritePlayer = new Sprite();
    pixmap = new QPixmap(dir);

    timerSprite->start(150);
    connect(timerSprite, &QTimer::timeout, this, &Sprite::refresh);

    QTimer* timerMove = new QTimer(this);
    timerMove->start(300);
    connect(timerMove, &QTimer::timeout, this, &Player::move);
}

void Player::move()
{
    _x = x();
    _y = y();

    blocked();

    switch (movementDirection_) {
    case Direction::UP:
        row = 192;
        if(y() >= 32 && movementCollide != DirectionCollide::UP_COLLIDE) setPos(x(),y()-16);
        break;
    case Direction::DOWN:
        row = 0;
        if(y() <= 532 && movementCollide != DirectionCollide::DOWN_COLLIDE) setPos(x(),y()+16);
        break;
    case Direction::LEFT:
        row = 64;
        if(x() >= 32 && movementCollide != DirectionCollide::LEFT_COLLIDE) setPos(x()-16,y());
        break;
    case Direction::RIGHT:
        row = 128;
        if(x() <= 538 && movementCollide != DirectionCollide::RIGHT_COLLIDE) setPos(x()+16,y());
        break;
    default:
        ;
    }
}

bool Player::blocked()
{
    int blocked = collide();

    if(blocked == 1){
        switch (movementDirection_) {
        case Direction::UP:
            movementCollide = DirectionCollide::UP_COLLIDE;
            movementDirection_ = Direction::NONE;
            setPos(x(),y()+16);
            break;
        case Direction::DOWN:
            movementCollide = DirectionCollide::DOWN_COLLIDE;
            movementDirection_ = Direction::NONE;
            setPos(x(),y()-16);
            break;
        case Direction::LEFT:
            movementCollide = DirectionCollide::LEFT_COLLIDE;
            movementDirection_ = Direction::NONE;
            setPos(x()+16,y());
            break;
        case Direction::RIGHT:
            movementCollide = DirectionCollide::RIGHT_COLLIDE;
            movementDirection_ = Direction::NONE;
            setPos(x()-16,y());
            break;
        default:
            movementCollide = DirectionCollide::NO_COLLIDE;
            movementDirection_ = Direction::NONE;
            break;
            }

        return true;
    }

    return false;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        movementDirection_ = Direction::UP;
        break;
    case Qt::Key_Down:
        movementDirection_ = Direction::DOWN;
        break;
    case Qt::Key_Right:
        movementDirection_ = Direction::RIGHT;
        break;
    case Qt::Key_Left:
        movementDirection_ = Direction::LEFT;
        break;
    default:
        movementDirection_ = Direction::NONE;
    }
    movementCollide = DirectionCollide::NO_COLLIDE;
}

int Player::collide()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i=0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Box)){
            return 1;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            msgBox.setWindowTitle("Juego Terminado");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("El enemigo te ha capturado!\nGAMEOVER");
            msgBox.setStandardButtons(QMessageBox::Ok);
            if (QMessageBox::Ok == msgBox.exec()){
                        QCoreApplication::quit();
                    }
            return 2;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Reward)){
            msgBox.setWindowTitle("Juego Terminado");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Has llegado al objetivo!\nCONGRATULATIONS");
            msgBox.setStandardButtons(QMessageBox::Ok);
            if (QMessageBox::Ok == msgBox.exec()){
                        QCoreApplication::quit();
                    }
            return 2;
        }
        else{
            return 10;
        }
    }
}

