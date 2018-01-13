#include "operator.h"

Operator::Operator()
{

}

void Operator::set_proiority(int priority[]){
    for (int i=0;i<=255;i++)
         priority[i]=6;
    priority['+']=1;
    priority['-']=1;
    priority['*']=2;
    priority['/']=2;

    //      ?^(1/?)
    priority['Q']=3;
    //       sin           cos           tan           log(e,?)      log(?,?)      ln            ?^?           ?!            ?P?           ?C?           sin-1         cos-1         tan-1
    priority['s']=priority['c']=priority['t']=priority['u']=priority['U']=priority['v']=priority['^']=priority['!']=priority['P']=priority['C']=priority['S']=priority['G']=priority['T']=4;
    priority['$']=5;//EX:-?
    priority['(']=7;
    priority[')']=0;

    priority[0]=-1;
}
