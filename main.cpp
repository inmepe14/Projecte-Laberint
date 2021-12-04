#include "cambra.hpp"
#include "laberint.hpp"
#include <iostream>
using namespace std;

void print(cambra c){
    cout<<"*";
    if(c.porta_oberta(0)){
        cout<<" ";
    }
    else{
        cout<<"*";
    }
    cout<<"*"<<endl;
    //primera linea
    if(c.porta_oberta(3)){
        cout<<" ";
    }
    else{
        cout<<"*";
    }
    cout<<" ";
    if(c.porta_oberta(1)){
        cout<<" ";
    }
    else{
        cout<<"*";
    }
    cout<<endl<<"*";
    if(c.porta_oberta(2)){
        cout<<" ";
    }
    else{
        cout<<"*";
    }
    cout<<"*"<<endl;
    
}

int main(){
    
    cambra C;
    laberint l;
    pair<int,int> pos;
    pos.first=6;
    pos.second=7;
    cout<<l(pos).porta_oberta(1)<<endl;
    //cambra C1;
    /*
    print(C);
    cout<<C.porta_oberta(1)<<endl;
    C.obre_porta(1);        //est i sud
    C.obre_porta(2);        
    C1.obre_porta(0);
    C1.obre_porta(1);
    //C1.obre_porta(3);
    //cout<<C.porta_oberta(1)<<endl;
    cout<<(C<C1)<<endl;
    print(C);*/

}