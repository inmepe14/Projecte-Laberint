#include "cambra.hpp"
#include <iostream>
using namespace std;

  // Construeix una cambra amb les portes als llocs indicats.
  cambra::cambra(bool n, bool s, bool e, bool o) throw(error){
                    if(n==true) nord=true;//paret(N);
                    else if(n==false) nord=false;
                    if(s==true) sud=true;//paret(S);
                    else if(s==false) sud=false;
                    if(e==true) est=true;//paret(E);
                    else if(e==false) est=false;
                    if(o==true) oest=true;//paret(O);
                    else if(o==false) oest=false;

                  }

  // Constructora per còpia, assignació i destructora.
  cambra::cambra(const cambra & c) throw(error){
      //paret p;
      nord=c.porta_oberta(0);
      est=c.porta_oberta(1);
      sud=c.porta_oberta(2);
      oest=c.porta_oberta(3);
      //return *this;

  }
  /*cambra::*/cambra & cambra::operator=(const cambra & c) throw(error){
      nord=c.porta_oberta(0);
      est=c.porta_oberta(1);
      sud=c.porta_oberta(2);
      oest=c.porta_oberta(3);
      return *this;
  }
  cambra::~cambra() throw(){

  }

  // Retorna si l'habitació té una porta oberta a la paret indicada.
  bool cambra::porta_oberta(paret p) const throw(){
      if(p==0){
        return nord;
    } 
    if(p==1){
        return est;
    }  
    if(p==2){
        return sud;
    }
    if(p==3){
        return oest;
    }
    /*if(p==4){
        //throw->error(20);
    }*/
  }

  // Obre una nova porta a la paret indicada. Si la porta ja està oberta no
  // fa res. Es produeix un error si la paret és NO_DIR.
  void cambra::obre_porta(paret p) throw(error){
    if(p==0){
        nord=true;
    } 
    if(p==1){
        est=true;
    }  
    if(p==2){
        sud=true;
    }
    if(p==3){
        oest=true;
    }
    if(p==4){
        throw error(ParetInexistent);
    }
  }

  // Tanca la porta a la paret indicada. Si la porta ja estava tancada no
  // fa res. Es produeix un error si la paret és NO_DIR.
  void cambra::tanca_porta(paret p) throw(error){
    if(p==0){
        nord=false;
    } 
    if(p==1){
        est=false;
    }  
    if(p==2){
        sud=false;
    }
    if(p==3){
        oest=false;
    }
    if(p==4){
        throw error(ParetInexistent);
    }
  }

  // Igualtat i desigualtat entre cambres. Dues cambres es consideren iguals
  // si tenen les mateixes portes obertes a les mateixes parets.
  bool cambra::operator==(const cambra & c) const throw(){
      bool ret;
      ret=(nord==c.porta_oberta(0) and est==c.porta_oberta(1) and sud==c.porta_oberta(2) and oest==c.porta_oberta(3));
      return ret;
  }
  bool cambra::operator!=(const cambra & c) const throw(){
      bool ret;
      //ret=(nord!=c.porta_oberta(0) and est!=c.porta_oberta(1) and sud!=c.porta_oberta(2) and est!=c.porta_oberta(3));
      ret=(*this==c);
      return not ret;
  }

  // Operador "menor que" entre cambres. Una cambra és més petita que una
  // altra si té més portes tancades que l'altra. Tenint en compte que una
  // porta tancada és més petita que una porta oberta, en cas que tinguin el
  // mateix número de portes tancades, per decidir qui és més petit es miraran
  // les portes en aquest ordre NORD, EST, SUD i OEST. Per exemple:
  //   cambra c1, c2(true,true), c3(true, false, true);
  //   cout << (c1 < c2); // escriu 'true'
  //   cout << (c2 < c3); // escriu 'true'
  bool cambra::operator<(const cambra & c) const throw(){
      int n=0;
      int b=0;
      int p=0;
      if(nord==true){
          n++;
      }
      if(est==true){
          n++;
      }
      if(sud==true){
          n++;
      }
      if(oest==true){
          n++;
      }
      while(p!=4){
        if(c.porta_oberta(p)==1){
            b++;
            //cout<<c.porta_oberta(p);
        }
        ++p;
      }

        //cout<<"PI: "<<b<<endl;  
      if(n<b){
          return true;
      }
      else if(n>b){
          return false;
      }
      else if(n==b){
          if(nord!=c.porta_oberta(0)){
              if(nord==true){
                  return true;
              }
              else return false;
              
          }
          if(est!=c.porta_oberta(1)){
              if(est==true){
                  return true;
              }
              else return false;
              
          }
          if(sud!=c.porta_oberta(2)){
              if(sud==true){
                  return true;
              }
              else return false;
              
          }
          if(oest!=c.porta_oberta(3)){
              if(oest==true){
                  return true;
              }
              else return false;
              
          }
      }

  }

  // Gestió d'errors.
  static const int  ParetInexistent = 20;
