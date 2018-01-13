#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = 0);
    void init();
    void update(int,double,double,double);
    void draw();
    ~MyGraphicsView();
signals:
public slots:
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QGraphicsScene *scene;
    QPixmap *pixmap1, *pixmap2;
    QPainter *painter1, *painter2;
    QGraphicsPixmapItem *item;
    QPoint *point;
    QPointF *pointf;
};

#endif // MYGRAPHICSVIEW_H

