#include "mygraphicsview.h"
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <cmath>
#include <iostream>
#define pi 3.1415926
using namespace std;
MyGraphicsView::MyGraphicsView(QWidget* parent):
    QGraphicsView(parent)
{

}

void MyGraphicsView::init()
{
    // initialize
    scene = new QGraphicsScene();
    pixmap1 = new QPixmap(500-2, 500-2);
    pixmap2 = new QPixmap(500-2, 500-2);
    painter1 = new QPainter(pixmap1);
    painter2 = new QPainter(pixmap2);
    point = new QPoint [500];
    pointf = new QPointF [500];
    this->setScene(scene);
    painter1->fillRect(0, 0, 500, 500, Qt::white);
    item = scene->addPixmap(*pixmap1);
}

void MyGraphicsView::update(int i,double x,double y,double r_y)
{
    // update point[] and pointf[]


    pointf[i].setX(x);
    pointf[i].setY(y);
    //cout<<i<<" he"<<endl;

    y= (-y/10)*250;
    point[i].setX(i);

    point[i].setY((ceil(y)*r_y)+250);
    // point[i].setX(...) point[i].setY(...)
    // pointf[i].setX(...) pointf[i].setY(...)
}

void MyGraphicsView::draw()
{
    painter1->fillRect(0, 0, 500, 500, Qt::white);
    painter1->setPen(Qt::red);
   /* QPoint sa,sa2;
    sa.setX(0);
    sa.setY(0);
    sa2.setX(1000);
    sa2.setY(300);*/
    for(int i=1;i<500;i++)
        painter1->drawLine(point[i],point[i-1]);
    QPoint st,ed;
    painter1->setPen(Qt::black);
    st.setX(250);
    st.setY(0);
    ed.setX(250);
    ed.setY(500);
    painter1->drawLine(st,ed);
    st.setX(0);
    st.setY(249);
    ed.setX(500);
    ed.setY(249);
    painter1->drawLine(st,ed);
    painter1->drawText(255,10,"Y");
    painter1->drawText(485,249,"X");
    item->setPixmap(*pixmap1);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    // copy pixmap1 to pixmap2
    painter2->drawPixmap(0, 0, *pixmap1);
    QBrush b;
    QString s;
    // find the point and show it

    // ... your code here ...
    int x=event->x(),y=event->y();
    int dis=500*500;
    int find;
    for(int i=0;i<500;i++)
    {
        if(pow(point[i].x()-x,2)+pow(point[i].y()-y,2) < dis)
        {
            dis=pow(point[i].x()-x,2)+pow(point[i].y()-y,2);
            find=i;
        }
    }
    dis=500*500;
    b.setColor(Qt::blue);
    painter2->setPen(Qt::blue);
    painter2->setBrush(b);
    painter2->drawEllipse(point[find],3,3);
    painter2->drawLine(249,point[find].y(),point[find].x(),point[find].y());
    painter2->drawLine(point[find].x(),249,point[find].x(),point[find].y());
    s=QString::number(pointf[find].y());
    painter2->drawText(250,point[find].y(),s);
    s=QString::number(pointf[find].x());
    painter2->drawText(point[find].x(),249,s);
    // event->x() event->y() (mouse position)
    // painter2->setBrush(...) (set fill-color)
    // painter2->drawEllipse(...) (draw circle)

    // display pixmap2
    item->setPixmap(*pixmap2);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    // display pixmap1
    item->setPixmap(*pixmap1);
}

MyGraphicsView::~MyGraphicsView()
{
    delete point;
    delete pointf;
    delete painter1;
    delete painter2;
    delete pixmap1;
    delete pixmap2;
    delete scene;
}
