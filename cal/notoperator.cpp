#include "notoperator.h"

Notoperator::Notoperator():Data()
{

}
void Notoperator::input_data(){

}

void Notoperator::del_data(QString dot[],QString &a){//delete運算
    if(dot[1][dot[1].length()-1]=='=')
        return;

    QString b="";
    bool door=false;
    int del_a=1,del_dot=1;

    if(a[a.length()-1]==',')
        door=true;

    if(dot[1][dot[1].length()-1]=='('){
       if(dot[1][dot[1].length()-2]=='g'||dot[1][dot[1].length()-2]=='s'){//log(   cos(
           del_a=2;
           del_dot=4;

       }
       else if(dot[1][dot[1].length()-2]=='n'){
           del_a=2;
           if(dot[1][dot[1].length()-3]=='l')//ln(
               del_dot=3;
           else                              //sin(
               del_dot=4;
       }
       else if(dot[1][dot[1].length()-2]==')'){
           del_a=2;
           del_dot=9;
       }
    }
    else if(dot[1][dot[1].length()-1]=='S'){//ANS
        del_a=1;
        del_dot=3;
    }
    else if(dot[1][dot[1].length()-2]=='S'&&dot[1][dot[1].length()-1]>='1'&&dot[1][dot[1].length()-1]<='5'){//ANSn
        int site;
        for(site=a.length()-1;site>=0;site--){
            if(!((a[site]<='9'&&a[site]>='0')||a[site]=='.'))
                break;
        }

        del_a=a.length()-site-1;

        del_dot=4;
    }



    for(int i=0;i<a.length()-del_a;i++)
        b[i]=a[i];
    a=b;

    b="";

    for(int i=0;i<dot[1].length()-del_dot;i++)
        b[i]=dot[1][i];
    dot[1]=b;

    if(door){
        a.remove(a.length()-2,1);
    }
}

void Notoperator::clr_data(QString dot[],QString &a,bool radordeg){
    a="";
    if(radordeg)
        dot[0]="Rad";
    else
        dot[0]="Deg";
    dot[1]="";
    dot[2]="";
}
