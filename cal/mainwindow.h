#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "calculator.h"
#include "calculation.h"
//#include "transformation.h"
#include <ui_mainwindow.h>
#include "notoperator.h"
#include "data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString input;
    int mode;
    bool radordeg;
    bool alpha;
    bool draw;
    double answer;
    bool DX_open;
    int DX_stage;//0->輸入積分攻式，1->輸入上界，2->輸入下界

    double range_x;
    double range_y;
    bool bf;
    QString bf_draw;
    QString bf_formu;

    QString rec[5];
    QString a_rec[5];
    QString dot[3];
    QString dot_rec[5];
    QString ans_rec[5];
    int choose_revise;//choose_revise，0->正常，n->修改n

    double DX_up[100];//積分上界
    double DX_down[100];//積分下界
    int DX_len;//有幾個積分
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Calculator c;
    friend class Calculation;
    //Transformation t;
    Notoperator notoperator;
    Data data;

    QString a;

    void show_error();
    void push_alpha();
    void recover_from_alpha();
    void draw_pic();
    QString cal_dx(QString ,double,double,bool&,double)throw(int);
    void cal_dx_bf(QString ,bool&,double)throw(int);

private slots:
    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_49_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_revise_button_clicked();

    void on_revise_button_2_clicked();

    void on_revise_button_3_clicked();

    void on_revise_button_4_clicked();

    void on_revise_button_5_clicked();

    void on_ans_button_1_clicked();

    void on_ans_button_2_clicked();

    void on_ans_button_3_clicked();

    void on_ans_button_4_clicked();

    void on_ans_button_5_clicked();

    void on_clear_button_clicked();

    void on_DX_enter_button_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
