#ifndef CALCULATION_H
#define CALCULATION_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
#include <iostream>
using namespace std;
class Calculation:public Operator
{
private:
    QString input;
    int mode;
    bool radordeg;
    bool alpha;
    bool draw;
    double answer;


    double x[100];
    long long int x_h[100];
    int x_len;

    double DX_up[100];
    double DX_down[100];
    int DX_len;
public:
    Calculation();
    Calculation(double,bool);
    Calculation(QString);
    void intial(QString,int,bool,bool,bool);
    QString cal(char [],int,bool&);
    double get_ans();

    void input_formu();
    double x_order(double);
    void zero();
    QString &output(const Calculation &);
    double nPr(double,double);
    double nCr(double,double);

    QString getans(QString,int,bool &);
    QString d_dx(QString);
    double tri_tan(double,bool &);
    double tri_sin(double);
    double tri_cos(double);
    double tri_arctan(double);
    double tri_arcsin(double);
    double tri_arccos(double);
    double tri_cot(double);

    double tri_log(double,double);
    double tri_ln(double);
    double tri_pow(double,double);
    friend class MainWindow;
    int trans(char[]);
    friend ostream &operator<<(ostream &, const Calculation &);
};

#endif // CALCULATION_H
