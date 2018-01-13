#ifndef DATA_H
#define DATA_H
//#include "mainwindow.h"
#include "ui_mainwindow.h"

class Data
{
    //Q_OBJECT
private:
    bool syntax_error;
public:

    Data();
    void judge_error(QString);
    bool judge_bf_num(QString);
    bool judge_zero(double);
    bool error();
    void seterror();
    void clrerror();
};

#endif // DATA_H
