#include "data.h"
#include "ui_mainwindow.h"
Data::Data()
{
    syntax_error=false;
}

void Data::judge_error(QString s){
    if(s==""){
        seterror();
        return;
    }

    int left=0;//'('的數量
    int right=0;//')'的數量

    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            if(s[i+1]==')'){
                seterror();
                return;
            }
            left++;

        }
        else if(s[i]==')')
            right++;

    }
    if(left!=right)
        seterror();
}
bool Data::judge_bf_num(QString a){
    if(a==""){
        return true;
    }
    else if((a[a.length()-1]>'9'||a[a.length()-1]<'0')&&a[a.length()-1]!=')'&&a[a.length()-1]!='X'){
        return true;
    }

    return false;
}

bool Data::judge_zero(double a){
    if(a==0)
        return true;

    return false;
}

bool Data::error(){
    return syntax_error;
}

void Data::seterror(){
    syntax_error=true;
}

void Data::clrerror(){
    syntax_error=false;
}
