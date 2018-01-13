#include "calculator.h"
#define rad true
#define deg false

Calculator::Calculator()
{
    w.a="";
    input="";
    mode=0;
    radordeg=deg;
    alpha=false;
    draw=false;
    error=false;
    ans="";

}
void Calculator::setinput(QString s){
    w.a=s;
}
void Calculator::setmode(int n){
    mode=n;
}
void Calculator::setshift(bool b){
    radordeg=b;
}
void Calculator::setalpha(bool b){
    alpha=b;
}
void Calculator::setdraw(bool b){
    draw=b;
}
void Calculator::setans(QString s){
    ans=s;
}
void Calculator::getdata(QString &a,int &b,bool &c,bool &d,bool &e,bool &f,QString &g){
    a=input;
    b=mode;
    c=radordeg;
    d=alpha;
    e=draw;
    f=error;
    g=ans;
}

bool Calculator::get_ang_mode(){
    return radordeg;
}


