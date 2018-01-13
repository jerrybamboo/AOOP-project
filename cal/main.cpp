#include "mainwindow.h"
#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator c;
    //MainWindow w;
    //w.show();
    //c.w.show();
    //return a.exec();



    c.w.resize(1530,700);      //窗口尺寸為300*300
    c.w.move(100,100);        //窗口移動到距螢幕左上角100*100處
    int windowXPos = c.w.x(); //窗口左上角x座標
    int windowYPos = c.w.y(); //窗口左上角y座標
    QRect windowGeometry = c.w.frameGeometry() ;//返回的QRect可得窗口長、寬、位置等資訊。
    c.w.setWindowTitle(QObject::tr("工程計算機&繪圖")); //設定窗口標題
    c.w.show();               //在螢幕上秀出窗口
    return a.exec();
}
