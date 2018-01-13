#ifndef CALCULASION_H
#define CALCULASION_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
class Calculasion:public Operator
{
public:
    Calculasion();
    void cal();
    void set_ans();
};

#endif // CALCULASION_H
