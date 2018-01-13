#ifndef DB_H
#define DB_H
#include "mainwindow.h"
#include "ui_mainwindow.h"

class DB
{
    private:
        QString bfinput[10];
        int bfmode[10];
    public:
        DB();
        void GetDB(int[],QString[]);
        void StoreDB(int,QString);
};

#endif // DB_H
