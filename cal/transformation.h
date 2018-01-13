#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
class Transformation:public Operator
{
private:
    QString input;
    int mode;
    bool radordeg;
    bool alpha;
    bool draw;

public:
    Transformation();
    QString transformation_to_rad(QString);
    QString transformation_to_deg(QString);
    QString transformation_to_point(QString);
    QString transformation_to_i(QString);
    QString transformation_to_tri(QString);
    QString transformation_to_fra(QString);


};

#endif // TRANSFORMATION_H
