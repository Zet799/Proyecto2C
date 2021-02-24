#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);

    QTimer *timerSprite; // Objeto timer que controlara la velocidad de la animación
    QPixmap *pixmap; // Objeto Pixmap en el cual se agregara la imagen

    float row, column; // atributos que representaran las filas y columnas del sprite
    float width, height;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void refresh(); // Metodo que
};

#endif // SPRITE_H
