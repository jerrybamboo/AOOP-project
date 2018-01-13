#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculation.h"
#include "calculator.h"
#include <iostream>
#include <cmath>
#include <QPalette>
#include <QApplication>
#include "QDebug"
#define nu 100
#define rad true
#define deg false
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    a="";
    for(int i=0;i<5;i++){
        rec[i]="";
        a_rec[i]="0";
        dot_rec[i]="";
        ans_rec[i]="0";
    }
    answer=0;
    radordeg=deg;
    dot[0]="Deg";
    open=false;
    alpha=false;

    range_x=359.9;
    bf_draw="";
    bf=false;
    ui->setupUi(this);
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);

    //choose_revise，0->正常，n->修改n
    choose_revise=0;

    //设置背景長寬
    ui->m_pWidget->setGeometry(0, 0, this->width(),this->height() );
    QPalette pal(ui->m_pWidget->palette());

    //设置背景黑色
    pal.setColor(QPalette::Background, Qt::gray);
    ui->m_pWidget->setAutoFillBackground(true);
    ui->m_pWidget->setPalette(pal);
    ui->m_pWidget->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_44_clicked()
{
    a+='0';
    dot[1]+="0";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::show_error()
{
    dot[0]="";
    dot[1]="SYNTEX ERROR";
    dot[2]="";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    if(radordeg)
        dot[0]="Rad";
    else
        dot[0]="Deg";
    dot[1]="";
    dot[2]="";
    a="";
    data.clrerror();
}
void MainWindow::push_alpha(){
    ui->pushButton_20->setText("sin^(-1)");
    ui->pushButton_21->setText("cos^(-1)");
    ui->pushButton_22->setText("tan^(-1)");
}
void MainWindow::recover_from_alpha(){
    ui->pushButton_20->setText("sin");
    ui->pushButton_21->setText("cos");
    ui->pushButton_22->setText("tan");
    alpha=false;
}

void MainWindow::on_pushButton_45_clicked()
{
    a+='.';
    dot[1]+=".";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_46_clicked()
{
    a+="*10^";
    dot[1]+="x10^";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_47_clicked()
{
    a+="A";
    dot[1]+="Ans";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_48_clicked()//按下'='後
{

    //開始計算
    char p[1000];
    bool DX=false;

    for(int i=0;i<a.length();i++)
        p[i]=a[i].toLatin1();
    p[a.length()]='\0';
    cout<<p<<endl;


    Calculation c(answer,radordeg);
    QString ans="";
    int l=c.trans(p);
    ui->lineEdit->setText(p);
    for(int i=0;i<strlen(p);i++){
        if(p[i]=='D'){
            DX=true;
            break;
        }
    }

    if(!DX){

    }
    else{
        //ans=cal_dx(a)
    }

    data.judge_error(a);

    if(data.error()){
        show_error();
        return;
    }


    //記錄各次方程式之內部計算
    if(!choose_revise){
        a_rec[4]=a_rec[3];
        a_rec[3]=a_rec[2];
        a_rec[2]=a_rec[1];
        a_rec[1]=a_rec[0];
        a_rec[0]=a;
    }
    else{
        a_rec[choose_revise-1]=a;
    }





    //記錄各次方程式之外部顯示
    if(!choose_revise){
        dot_rec[4]=dot_rec[3];
        dot_rec[3]=dot_rec[2];
        dot_rec[2]=dot_rec[1];
        dot_rec[1]=dot_rec[0];
        dot_rec[0]=dot[1];
    }
    else{
        dot_rec[choose_revise-1]=dot[1];
    }



    a+='=';
    dot[1]+="=";

    bool test_error=false;
    ans=c.cal(p,l,test_error);
    if(test_error){
        show_error();
        return;
    }
    dot[1]+=ans;

    if(!choose_revise){
        ans_rec[4]=ans_rec[3];
        ans_rec[3]=ans_rec[2];
        ans_rec[2]=ans_rec[1];
        ans_rec[1]=ans_rec[0];
        ans_rec[0]=ans;
    }
    else{
        ans_rec[choose_revise-1]=ans;
    }



    //記錄各次方程式之外部顯示(label)
    if(!choose_revise){
        rec[4]=rec[3];
        rec[3]=rec[2];
        rec[2]=rec[1];
        rec[1]=rec[0];
        rec[0]=dot[1];
    }
    else{
        rec[choose_revise-1]=dot[1];
        choose_revise=0;
    }



    ui->label->setText("( 1 ) "+rec[0]);
    ui->label_2->setText("(2)  "+rec[1]);
    ui->label_3->setText("(3)  "+rec[2]);
    ui->label_4->setText("(4)  "+rec[3]);
    ui->label_5->setText("(5)  "+rec[4]);
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    dot[1]="";
    a="";
    answer=c.get_ans();
    cout<<answer<<endl;
}

QString MainWindow::cal_dx(QString txt,double up,double down,bool &error,double sum){

    /*
    for(int i=txt.length()-1;i>=0;i--){
        if(txt[i]=='D'){
            QString temp;
            temp=txt.mid(0,i);
            //txt=cal_dx(temp,up,doen,error)+txt.mid(i+1,txt.length()-i-1);

        }
    }



    char p[1000];

    for(int i=0;i<a.length();i++)
        p[i]=txt[i].toLatin1();
    p[txt.length()]='\0';



    char p[1000];
    QString b;

    while(1){
        data.clrerror();
        if(down>up){
            break;
        }

        b=a;
        b.replace('X',QString::number(down));
        for(int i=0;i<b.length();i++)
            p[i]=b[i].toLatin1();
        p[b.length()]='\0';
        bool test_error=false;
        data.judge_error(b);
        if(data.error()){
            continue;
        }


        Calculation c(answer,radordeg);
        QString ans="";
        int l=c.trans(p);
        ans=c.cal(p,l,test_error);
        if(test_error){
            continue;
        }
        answer=c.get_ans();
        sum+=ans;

        down+=0.1;
    }

    return QString::number(sum);
    */
}

void MainWindow::on_pushButton_39_clicked()
{
    a+='1';
    dot[1]+="1";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_40_clicked()
{
    a+='2';
    dot[1]+="2";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_41_clicked()
{
    a+='3';
    dot[1]+="3";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_42_clicked()
{
    a+='+';
    dot[1]+="+";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_43_clicked()
{
    a+='-';
    dot[1]+="-";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);

}

void MainWindow::on_pushButton_34_clicked()
{
    a+='4';
    dot[1]+="4";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_35_clicked()
{
    a+='5';
    dot[1]+="5";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_36_clicked()
{
    a+='6';
    dot[1]+="6";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_37_clicked()
{
    a+='*';
    dot[1]+="x";

    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_38_clicked()
{
    a+='/';
    dot[1]+="/";

    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_29_clicked()
{
    a+='7';
    dot[1]+="7";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_30_clicked()
{
    a+='8';
    dot[1]+="8";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_31_clicked()
{
    a+='9';
    dot[1]+="9";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_32_clicked()//DEL
{
    if(a==""){
        data.seterror();
        show_error();
        return;
    }

    notoperator.del_data(dot,a);

    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_33_clicked()
{

    notoperator.clr_data(dot,a,radordeg);
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_23_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+=",";
    for(int i=a.length()-2;i>=0;i--){
        if((a[i]!='.'&&(a[i]>'9'||a[i]<'0'))){
            a.insert(i+1,'P');
            break;
        }
        else if(i==0){
            a.insert(0,'P');
            break;
        }

    }
    dot[1]+="P";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_24_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+=",";
    for(int i=a.length()-2;i>=0;i--){
        if((a[i]!='.'&&(a[i]>'9'||a[i]<'0'))){
            a.insert(i+1,'C');
            break;
        }
        else if(i==0){
            a.insert(0,'C');
            break;
        }

    }
    dot[1]+="C";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_25_clicked()
{
    a+='(';
    dot[1]+="(";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_26_clicked()
{
    a+=')';
    dot[1]+=")";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_27_clicked()
{
    a+='i';
}

void MainWindow::on_pushButton_28_clicked()
{
    a+='X';
    dot[1]+="X";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_17_clicked()
{
    a+=QString::number(exp(1));
    dot[1]+="e";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_18_clicked()
{
    a+=QString::number(M_PI);
    dot[1]+="PI";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_19_clicked()
{
    a+=',';
    dot[1]+=",";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_20_clicked()
{
    if(!alpha){
        a+="s(";
        dot[1]+="sin(";
    }
    else{
        a+="S(";
        dot[1]+="sin^(-1)(";
        recover_from_alpha();
    }
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);


}

void MainWindow::on_pushButton_21_clicked()
{
    if(!alpha){
        a+="c(";
        dot[1]+="cos(";
    }
    else{
        a+="G(";
        dot[1]+="cos^(-1)(";
        recover_from_alpha();
    }
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);

}

void MainWindow::on_pushButton_22_clicked()
{
    if(!alpha){
        a+="t(";
        dot[1]+="tan(";
    }
    else {
        a+="T(";
        dot[1]+="tan^(-1)(";
        recover_from_alpha();
    }
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);


}

void MainWindow::on_pushButton_11_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+=",";
    for(int i=a.length()-2;i>=0;i--){
        if((a[i]!='.'&&(a[i]>'9'||a[i]<'0'))){
            a.insert(i+1,'Q');
            break;
        }
        else if(i==0){
            a.insert(0,'Q');
            break;
        }

    }
    dot[1]+="√";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_12_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+="^(0.5)";

    dot[1]+="^(0.5)";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_13_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+="^(2)";

    dot[1]+="^2";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_14_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+='^';

    dot[1]+="^";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_15_clicked()
{
    a+="u(";
    dot[1]+="log(";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_16_clicked()
{
    a+="v(";
    dot[1]+="ln(";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_7_clicked()
{

    for(int i=a.length()-1;i>=0;i--){
        if((a[i]!='.'&&(a[i]>'9'||a[i]<'0'))){
            a.insert(i+1,'!');
            break;
        }
        else if(i==0){
            a.insert(0,'!');
            break;
        }

    }
    dot[1]+="!";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_8_clicked()
{
    open=true;
    a+='D';
    dot[1]+="∫(";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);

}

void MainWindow::on_pushButton_9_clicked()
{
    if(data.judge_bf_num(a)){
        show_error();
        return;
    }
    a+="^(-1)";
    dot[1]+="^(-1)";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_10_clicked()//EX:log(a,b)
{
    a+="U(";
    dot[1]+="log(";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_clicked()
{
    radordeg=!radordeg;
    if(radordeg)
        dot[0]="Rad";
    else
        dot[0]="Deg";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_2_clicked()
{

    alpha=!alpha;
    if(alpha){
        push_alpha();
    }
    else{
        recover_from_alpha();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    a+='C';
    if(c==1){
        c++;
        dot[1]+="/";
        ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    }
    else if(c==2){
        c=0;
        dot[1]+=")";
        ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    }
    else if(c==3){

    }
    else if(c==4){

    }
    else if(c==5){

    }
    else if(c==6){
        c=0;
    }
    else if(c==7){
        c=0;
        dot[1]+=")^-1";
        ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    }
    else if(c==8){
        c=9;
        dot[1]+=")(";
        ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    }
    else if(c==9){
        c=0;
        dot[1]+=")";
        ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    a+='D';
}

void MainWindow::on_pushButton_5_clicked()
{
    a+='d';

    dot[1]+="'";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->graphicsView->init();
    bf_formu=dot[1];
    bf_draw=a;
    double num;
    char p[1000];
    QString b;

    range_x=ui->horizontalSlider->value()/10+1;
    range_y=ui->horizontalSlider_2->value()/10+1;

    for(int i=0;i<500;i++){
        data.clrerror();
        num=-22.5*range_x + (i/500.)*44.9*range_x;
        b=a;
        b.replace('X',QString::number(num));
        for(int i=0;i<b.length();i++)
            p[i]=b[i].toLatin1();
        p[b.length()]='\0';
        bool test_error=false;
        data.judge_error(b);
        if(data.error()){
            continue;
        }


        Calculation c(answer,radordeg);
        QString ans="";
        int l=c.trans(p);
        ans=c.cal(p,l,test_error);
        if(test_error){
            continue;
        }
        answer=c.get_ans();
        cout<<"hi"<<endl;
        cout<<num<<" "<<answer<<endl;
        ui->graphicsView->update(i,num,answer,range_y);

    }
    ui->graphicsView->draw();

    dot[1]=bf_formu;
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}
void MainWindow::draw_pic(){
    ui->graphicsView->init();

    double num;
    char p[1000];
    QString b;
    range_x=ui->horizontalSlider->value()/10+1;
    range_y=ui->horizontalSlider_2->value()/10+1;

    for(int i=0;i<500;i++){
        data.clrerror();
        num=-22.5*range_x + (i/500.)*44.9*range_x;
        b=bf_draw;
        b.replace('X',QString::number(num));
        for(int i=0;i<b.length();i++)
            p[i]=b[i].toLatin1();
        p[b.length()]='\0';
        bool test_error=false;
        data.judge_error(b);
        if(data.error()){
            continue;
        }


        Calculation c(answer,radordeg);
        QString ans="";
        int l=c.trans(p);
        ans=c.cal(p,l,test_error);
        if(test_error){
            continue;
        }
        answer=c.get_ans();
        cout<<"hi"<<endl;
        cout<<num<<" "<<answer<<endl;
        ui->graphicsView->update(i,num,answer,range_y);

    }
    ui->graphicsView->draw();
    dot[1]=bf_formu;
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_pushButton_49_clicked()
{
    a+=QString::number(exp(1))+"^";
    dot[1]+="e^";

    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    draw_pic();
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    draw_pic();
}

void MainWindow::on_revise_button_clicked()
{
    choose_revise=1;
    a=a_rec[0];
    dot[1]=dot_rec[0];
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_revise_button_2_clicked()
{
    choose_revise=2;
    a=a_rec[1];
    dot[1]=dot_rec[1];
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_revise_button_3_clicked()
{
    choose_revise=3;
    a=a_rec[2];
    dot[1]=dot_rec[2];
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_revise_button_4_clicked()
{
    choose_revise=4;
    a=a_rec[3];
    dot[1]=dot_rec[3];
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_revise_button_5_clicked()
{
    choose_revise=5;
    a=a_rec[4];
    dot[1]=dot_rec[4];
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_ans_button_1_clicked()
{
    a+=ans_rec[0];
    dot[1]+="ANS1";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_ans_button_2_clicked()
{
    a+=ans_rec[1];
    dot[1]+="ANS2";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_ans_button_3_clicked()
{
    a+=ans_rec[2];
    dot[1]+="ANS3";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_ans_button_4_clicked()
{
    a+=ans_rec[3];
    dot[1]+="ANS4";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_ans_button_5_clicked()
{
    a+=ans_rec[4];
    dot[1]+="ANS5";
    ui->textEdit->setText(dot[0]+'\n'+dot[1]+'\n'+dot[2]);
}

void MainWindow::on_clear_button_clicked()
{
    for(int i=0;i<5;i++){
        rec[i]="";
        a_rec[i]="0";
        dot_rec[i]="";
        ans_rec[i]="0";
    }
    ui->label->setText("( 1 ) "+rec[0]);
    ui->label_2->setText("(2)  "+rec[1]);
    ui->label_3->setText("(3)  "+rec[2]);
    ui->label_4->setText("(4)  "+rec[3]);
    ui->label_5->setText("(5)  "+rec[4]);
}


