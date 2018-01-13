#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "mainwindow.h"

//#include "data.h"
#include "ui_mainwindow.h"
#include "calculation.h"
#include "transformation.h"
#include "notoperator.h"
#include "data.h"

class Calculator
{
private:
    QString input;
    int mode;
    bool radordeg;
    bool alpha;
    bool draw;
    bool error;
    QString ans;
public:
    Calculator();
    MainWindow w;

    //Data data;
    Notoperator nop;

    void setinput(QString);
    void setmode(int);
    void setshift(bool);
    void setalpha(bool);
    void setdraw(bool);
    void setans(QString);
    void getdata(QString &,int &,bool &,bool &,bool &,bool &,QString &);
    bool get_ang_mode();

};

#endif // CALCULATOR_H
