#include "calculation.h"

#include <iostream>
#include <stdio.h>
#define nu 100
#define rad true
#define deg false
using namespace std;
Calculation::Calculation()
{
    answer=0;
    DX_len=0;
}
Calculation::Calculation(double a,bool r){
    answer=a;
    radordeg=r;
    DX_len=0;

}
Calculation::Calculation(QString b){

}
ostream &operator<<(ostream &os, const Calculation &l)
{

}
QString Calculation::cal(char form[],int len,bool &error){
    //cout<<len<<endl;
    double all[100];
    char sym[500];
    int count,sc,num=0;


    count=0;
    sc=0;

    for(int j=0;j<len;j++){
        //cout<<j<<"tt"<<endl;
        if(form[j]=='n'){
            //cout<<"test"<<endl;
            all[count++]=x[num++];

            //cout<<temp<<endl;

            cout<<x[num-1]<<endl;
        }

        if(form[j]=='+'||form[j]=='-'||form[j]=='*'||form[j]=='/'||form[j]=='('||form[j]==')'||form[j]=='s'||form[j]=='c'||form[j]=='t'||form[j]=='u'||form[j]=='U'||form[j]=='v'||form[j]=='^'||form[j]=='$'||form[j]=='!'||form[j]=='P'||form[j]=='C'||form[j]=='Q'||form[j]=='S'||form[j]=='G'||form[j]=='T'){
            sym[sc]=form[j];
            sc++;
        }

        if(count-1<0||sc-1<0){

            continue;
        }

        if(sym[sc-1]=='+'){
            //cout<<j<<endl;
            all[count-2]=all[count-2]+all[count-1];
            count--;
            sc--;
        }

        else if(sym[sc-1]=='-'){
            all[count-2]=all[count-2]-all[count-1];
            count--;
            sc--;
        }
        else if(sym[sc-1]=='*'){
            all[count-2]=all[count-2]*all[count-1];
            count--;
            sc--;
        }
        else if(sym[sc-1]=='/'){
            all[count-2]=all[count-2]/all[count-1];
            count--;
            sc--;
        }
        else if(sym[sc-1]=='^'){
            all[count-2]=pow(all[count-2],all[count-1]);
            count--;
            sc--;
        }
        else if(sym[sc-1]=='$'){
            all[count-2]=all[count-2]*all[count-1];
            count--;
            sc--;
        }
        else if(sym[sc-1]=='P'){
            all[count-2]=nPr(all[count-2],all[count-1]);
            count--;
            sc--;
        }
        else if(sym[sc-1]=='C'){
            all[count-2]=nCr(all[count-2],all[count-1]);
            count--;
            sc--;
        }
        else if(sym[sc-1]=='U'){
            all[count-2]=tri_log(all[count-2],all[count-1]);
            count--;
            sc--;
        }
        else if(sym[sc-1]=='Q'){
            all[count-2]=pow(all[count-1],1./all[count-2]);
            count--;
            sc--;
        }


        else if(sym[sc-1]=='s'){
            all[count-1]=tri_sin(all[count-1]);
            sc--;
        }

        else if(sym[sc-1]=='c'){
            all[count-1]=tri_cos(all[count-1]);
            sc--;
        }

        else if(sym[sc-1]=='t'){
            all[count-1]=tri_tan(all[count-1],error);
            sc--;
        }
        else if(sym[sc-1]=='S'){
            all[count-1]=tri_arcsin(all[count-1]);
            sc--;
        }

        else if(sym[sc-1]=='G'){
            all[count-1]=tri_arccos(all[count-1]);
            sc--;
        }

        else if(sym[sc-1]=='T'){
            all[count-1]=tri_arctan(all[count-1]);
            sc--;
        }
        else if(sym[sc-1]=='u'){
            all[count-1]=tri_log(10,all[count-1]);
            sc--;
        }
        else if(sym[sc-1]=='v'){
            all[count-1]=tri_ln(all[count-1]);
            sc--;
        }
        else if(sym[sc-1]=='!'){

            all[count-1]=x_order(all[count-1]);
            sc--;
        }
    }
    if(count!=1)
        error=true;
    //cout<<all[0];
    answer=all[0];
    QString ans=QString::number(all[0]);

    x_len=0;
    //cout<<count<<"th"<<endl;
    //cout<<ans<<endl;
    return ans;

}

QString Calculation::getans(QString txt,int len,bool &error){

   /*
    for(int i=txt.length()-1;i>=0;i--){
        if(text[i]=='D'){
            QString temp;
            temp=txt.mid(0,i);
            txt=dx(temp)+txt.mid(i+1,txt.length()-i-1);

        }
    }
    QString record=txt;


    char p[1000];

    for(int i=0;i<a.length();i++)
        p[i]=txt[i].toLatin1();
    p[txt.length()]='\0';


    return ;
    */
}

double Calculation::get_ans(){
    return answer;
}

void Calculation::input_formu(){

}

double Calculation::x_order(double a){
    double ans=1;
    for(int i=2;i<=a;i++)
        ans*=i;
    return ans;
}

void Calculation::zero(){

}



double Calculation::nPr(double a,double b){
    return x_order(a)/x_order(a-b);
}
double Calculation::nCr(double a,double b){
    return nPr(a,b)/x_order(b);
}



QString Calculation::d_dx(QString text){
    int loc,loc2;
    for(int i=0;i<text.length();i++){

    }
}

double Calculation::tri_tan(double a,bool &error){

    if(radordeg){
        if(fabs(cos(a))<1E-4)error=true;
        return tan(a);

    }
    else{
        if(fabs(cos(a*M_PI/180.))<1E-4)error=true;
        return tan(a*M_PI/180.);
    }
}
double Calculation::tri_sin(double a){
    if(radordeg)
        return sin(a);
    else
        return sin(a*M_PI/180.);
}
double Calculation::tri_cos(double a){
    if(radordeg)
        return cos(a);
    else
        return cos(a*M_PI/180.);
}

double Calculation::tri_arctan(double a){

    if(radordeg){

        return atan(a);

    }
    else{
        return atan(a)*180/M_PI;
    }
}
double Calculation::tri_arcsin(double a){
    if(radordeg){

        return asin(a);

    }
    else{
        return asin(a)*180/M_PI;
    }
}
double Calculation::tri_arccos(double a){
    if(radordeg){

        return acos(a);

    }
    else{
        return acos(a)*180/M_PI;
    }
}

double Calculation::tri_log(double n,double number){
    return log10(number)/log10(n);
}

double Calculation::tri_ln(double number){
    return log(number);
}

double Calculation::tri_pow(double,double){

}
QString &Calculation::output(const Calculation &l)
{

}
int Calculation::trans(char c[]){

    char s[1000];
    int s_len=0;
    bool number=false,point=false;
    double sum=0;
    double point_len=10;
    x_len=0;
    for(int i=0;i<strlen(c);i++){
        if(c[i]<='9'&&c[i]>='0'){
            number=true;
            if(!point){
                sum=sum*10+c[i]-'0';
                sum=(int)(sum);
            }
            else{

                sum=sum+(c[i]-'0')/point_len;
                point_len*=10;
            }
        }
        else if(c[i]=='.'){
            point=true;
            point_len=10;
        }
        else{
            if(number){
                x[x_len]=sum;
                //s[s_len]=x_len+'0';
                s[s_len]='n';
                s_len++;
                x_len++;
                sum=0;

            }
            point=false;
            number=false;

            if((c[i]=='-'&&((c[i-1]>'9')||(c[i-1]<'0')))||(i==0&&c[i]=='-')){
                x[x_len]=-1;
                x_len++;
                s[s_len]='n';
                s_len++;
                s[s_len]='$';
                s_len++;
                continue;
            }
            else if(c[i]=='A'){
                x[x_len]=answer;
                s[s_len]='n';
                s_len++;
                x_len++;
                continue;
            }

            s[s_len]=c[i];
            s_len++;

        }
    }
    if(number){
        x[x_len]=sum;
        //s[s_len]=x_len+'0';
        s[s_len]='n';
        s_len++;
        x_len++;
    }
    s[s_len]='\0';
    for(int i=0;i<=s_len;i++)
        c[i]=s[i];

    char stack[120],pol[120];
    int pri[256];
    int sp1,sp2;


    set_proiority(pri);

    stack[0]=0;

    sp1=0;
    sp2=0;

    for (int i=0;i<strlen(c);i++) {
        while (pri[c[i]]<=pri[stack[sp1]]&&stack[sp1]!='(')
             pol[++sp2]=stack[sp1--];
        if (c[i]!=')')
            stack[++sp1]=c[i];
        else
            sp1--;
    }
    for (int i=sp1;i>0;i--)
        pol[++sp2]=stack[i];

    for(int i=0;i<sp2;i++)
        c[i]=pol[i+1];
    c[sp2]='\0';

    return sp2;

}

