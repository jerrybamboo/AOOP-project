#ifndef NOTOPERATOR_H
#define NOTOPERATOR_H
//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
class Notoperator:public Data
{
public:
    Notoperator();
    void input_data();
    void del_data(QString [],QString &);
    void clr_data(QString [],QString &,bool);
};

#endif // NOTOPERATOR_H
