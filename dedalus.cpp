#include "dedalus.hpp"

// Excava el laberint, fent un laberint perfecte. Un laberint està excavat
  // si i només si alguna de les seves cambres té alguna porta oberta.
  // Es produeix un error si el laberint ja està excavat.
  void dedalus::construir(laberint & M) throw(error){
    
    particio<cambra> part(M.num_files()*M.num_columnes());
    for(nat i=1; i<=M.num_files(); i++){
      for(nat j=1; j<=M.num_columnes(); j++){
        pair<int,int> pos = make_pair(i, j);
        int p=0;
        bool obert=false;
        while(p<4 and not obert){
          obert = obert and M(pos).porta_oberta(p);
        }
        if(obert) throw error(EstaExcavat);
        part.afegir(M(pos));  
        }
      }
      /*
      while(num_grups>1)
      agafar dos numeros aleatoris dins de numfiles, numscolumnes, que siguin adjacents
      obrir la paret que els uneix
      unir el grup de la particio
      */

    }

    /*
    primer mires si ha alguna cambra oberta
    agafes i fas un particio amb totes les cambres, cada una es la seva representant
    agafes dos cambres adjacents aleatories que no estiguin a la mateixa partició
    obres la porta que les uneix i uneixes el grup de les dos cambres
    fins que totes la cambres estiguin al mateix grup
    
    */
