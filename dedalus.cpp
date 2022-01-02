#include "dedalus.hpp"
#include <cstdlib>
// Excava el laberint, fent un laberint perfecte. Un laberint està excavat
  // si i només si alguna de les seves cambres té alguna porta oberta.
  // Es produeix un error si el laberint ja està excavat.
  pair<bool,int> es_adjacent(nat a, nat b, nat a1, nat b1){
    pair<bool, int> p;
    p.first = false;
    if(a == a1){
      if(b == b1+1){
        p.first = true;
        p.second = paret::OEST;
        
      }
      else if(b == b1-1){
        p.first = true;
        p.second = paret::EST;
        
      }
    }
    else if(b == b1){
      if(a == a1+1){
        p.first = true;
        p.second = paret::SUD;
        
      }
      else if(a == a1-1){
        p.first = true;
        p.second = paret::NORD;
        
      }
    }
    return p;
  }

  void dedalus::construir(laberint & M) throw(error){
    pair<bool, int> pa;
    particio<int> part(M.num_files()*M.num_columnes());
    for(nat i=1; i<=M.num_files(); i++){
      for(nat j=1; j<=M.num_columnes(); j++){
        pair<nat,nat> pos = make_pair(i, j);
        int p=0;
        bool obert=false;
        while(p<4 and not obert){
          obert = obert and M(pos).porta_oberta(p);
          p++;
        }
        if(obert) throw error(EstaExcavat);
        part.afegir(pos.first*100+pos.second);
        cout<<pos.first*100+pos.second<<endl;
        //cout<<part.size()<<endl;  
        //cout<<part.num_elements()<<endl;
        }}
        //cout<<"ei"<<part.size()<<endl;
        nat a, b, a1, b1;
        bool adjacents = false;
        while(part.size()>1){
          b = 1 + rand() % (M.num_columnes());
          a = 1 + rand() % (M.num_files());
          pair<nat,nat> pos1 = make_pair(a, b);
          pair<nat,nat> pos2;
          while(not adjacents){
            b1 = 1 + rand() % (M.num_columnes());
            a1 = 1 + rand() % (M.num_files());
            pa = es_adjacent(a, b, a1, b1);
            pos2 = make_pair(a1, b1);
            cout<<a<<" "<<b<<" "<<a1<<" "<<b1<<" "<<pa.first<<endl;
            if(pa.first == true) adjacents = true;
          }
          if(!(part.mateix_grup(pos1.first*100+pos1.second, pos2.first*100+pos2.second))){
            M.obre_porta(pa.second,pos1);
            part.unir(pos1.first*100+pos1.second, pos2.first*100+pos2.second);
          }
        }
      }
    
      /*
      while(num_grups>1)
      agafar dos numeros aleatoris dins de numfiles, numscolumnes, que siguin adjacents
      obrir la paret que els uneix
      unir el grup de la particio
      */

    

    /*
    primer mires si ha alguna cambra oberta
    agafes i fas un particio amb totes les cambres, cada una es la seva representant
    agafes dos cambres adjacents aleatories que no estiguin a la mateixa partició
    obres la porta que les uneix i uneixes el grup de les dos cambres
    fins que totes la cambres estiguin al mateix grup
    
    */
