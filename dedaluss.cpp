#include "dedalus.hpp"
#include "list"
// Excava el laberint, fent un laberint perfecte. Un laberint està excavat
  // si i només si alguna de les seves cambres té alguna porta oberta.
  // Es produeix un error si el laberint ja està excavat.
  
  void dedalus::construir(laberint & M) throw(error){
    int contador = 0;
    pair<bool, int> pa;
    int p;
    particio<pair<nat,nat> > part(M.num_files()*M.num_columnes());
    for(nat i=1; i<=M.num_files(); i++){
      for(nat j=1; j<=M.num_columnes(); j++){
        pair<nat,nat> pos = make_pair(i, j);
        p=0;
        bool obert=false;
        while(p<4 and not obert){
          obert = obert and M(pos).porta_oberta(p);
          p++;
        }
        if(obert) throw error(EstaExcavat);
        part.afegir(pos);
    
        }}
        
        nat a, b;
        //bool adjacents = false;
        while(part.size()>1){
          //adjacents=false;
          pair<nat,nat> pos1;
          pair<nat,nat> pos2;
          bool trobat = false;
          while(not trobat){
            contador++;
            cout<<contador<<endl;
            util::Random R;
            a = R(1,M.num_files());
            b = R(1,M.num_columnes());
            pos1 = make_pair(a, b);
            //cout<<a<<" "<<b<<endl;
            int paret=0;
            vector<int> v;
            while(paret<4){
              if(!M(pos1).porta_oberta(paret))
              {
                if(not ((pos1.first == 1 and paret==paret::NORD) or (pos1.first==M.num_files() and paret==paret::SUD)
                or (pos1.second == 1 and paret==paret::OEST) or (pos1.second == M.num_columnes() and paret==paret::EST))){
                //pot sortir este valor de p;
                  v.push_back(paret);
                }
              }
              paret++;
            }
            if(v.size()==0){
              trobat=false;
            }
            else if (v.size()>0){
              int pi=R(0,v.size()-1);
              p=v[pi];
              //v.pop_back();
              trobat=true;
            }
            else if(v.size()==1){
              p=v[0];
              trobat=true;
            }
            cout<<"p: "<<p<<" v.size() "<<v.size()<<" pos: "<<pos1.first<<pos1.second<<endl;
            //p = R(0,3);
            //cout<<pos1.first<<pos1.second<<p<<endl;
            /*if(M(pos1).porta_oberta(p)==true){
              trobat = false;
            }*/
            /*if((pos1.first == 1 and p==paret::NORD) or (pos1.first==M.num_files() and p==paret::SUD)
                or (pos1.second == 1 and p==paret::OEST) or (pos1.second == M.num_columnes() and p==paret::EST)){
                  trobat = false;
                }
            */
            //else trobat=true;
            if(trobat){
              if(p==paret::NORD){
                pos2 = make_pair(pos1.first-1, pos1.second);
              }
              else if(p==paret::SUD){
                pos2 = make_pair(pos1.first+1, pos1.second);
              }
              else if(p==paret::EST){
                pos2 = make_pair(pos1.first, pos1.second+1);
              }
              else if(p==paret::OEST){
                pos2 = make_pair(pos1.first, pos1.second-1);
              }
              if(!(part.mateix_grup(pos1, pos2))){
                  part.unir(pos1, pos2);
                  M.obre_porta(p,pos1);
              }
              else{
                trobat= false;
              }
            //if(M(pos1).porta_oberta(p)==true) trobat=true;
            //cout<<"ei"<<endl;
              //obrir porta random
              //cout<<a<<" "<<b<<" "<<pos2.first<<" "<<pos2.second<<" "<<p<<endl;
            }
          }
          //cout<<part.size()<<endl;
        }
        //cout<<"contador= "<<contador<<endl;
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
