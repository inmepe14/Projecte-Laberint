#include "laberint.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
 // Constructora d'un laberint buit sense excavar (sense cap porta oberta)
  // de la mida indicada. Totes les cambres del laberint no tenen cap porta.
  // Es produeix un error si el número de files o de columnes del laberint és 0.
   laberint::laberint(nat num_fil, nat num_col) throw(error){
       if (num_fil == 0 || num_col == 0) {
            throw error(FilsColsIncorrecte);
        }
        files = num_fil;
        columnes = num_col;
        matriu = new cambra*[files];
        for (int i = 0; i < files; i++) {
            matriu[i] = new cambra[columnes];
        }
    

   }

  // Constructora d'un laberint a partir d'un istream (canal d'entrada) is.
  // El format de l'istream seguirà l'exposat a l'apartat 2.3. Es presuposa que
  // el laberint és correcte.
   laberint::laberint(std::istream & is) throw(error){
       
   }

  // Constructora per còpia, assignació i destructora.
  laberint::laberint(const laberint & l) throw(error){
    
        files = l.num_files();
        columnes = l.num_columnes();
        matriu = new cambra*[files];
        for (int i = 0; i < files; i++) {
            matriu[i] = new cambra[columnes];
        }

        for(int i=0; i<files; i++){
            for(int j=0; j<columnes; j++){
                pair<int,int> pos=make_pair(i,j);
                matriu[i][j]=l(pos);
            }
        }
  }
  laberint & laberint::operator=(const laberint & l) throw(error){
        files = l.num_files();
        columnes = l.num_columnes();
        matriu = new cambra*[files];
        for (int i = 0; i < files; i++) {
            matriu[i] = new cambra[columnes];
        }

        for(int i=0; i<files; i++){
            for(int j=0; j<columnes; j++){
                pair<int,int> pos=make_pair(i,j);
                matriu[i][j]=l(pos);
            }
        }
        return *this;
  }
  laberint::~laberint() throw(){
      for (int i = 0; i < files; i++) {
            delete [] matriu[i];
        }
        delete [] matriu;
  }

  // Retornen el número de files i columnes que té el laberint, respectivament.
  nat laberint::num_files() const throw(){
      return files;
  }
  nat laberint::num_columnes() const throw(){
      return columnes;
  }

  // Retorna la cambra situada a la posició especificada per pos.
  // Aquest mètode permet utilitzar el laberint d'aquesta manera:
  //   laberint l(3,4);
  //   posicio pos(2,2);
  //   cambra c = l(pos);
  // Es produeix un error si la posició donada no existeix al laberint.
  cambra laberint::operator()(const posicio & pos) const throw(error){
      if (pos.first < 0 || pos.second >= files) {
            throw error(PosicioInexistent);
        }
        if (pos.first < 0 || pos.second >= columnes) {
            throw error(PosicioInexistent);
        }

      return matriu[pos.first][pos.second];
  }

  // Obre la porta en la paret donada de la cambra que està especificada per pos.
  // També obre la porta corresponent en la cambra adjacent. Es produeix un error
  // si la posició no existeix o no es pot obrir una porta en la direcció
  // indicada perquè dóna a l'exterior.
  void laberint::obre_porta(paret p, const posicio & pos) throw(error){
        if (pos.first < 0 || pos.second >= files) {
            throw error(PosicioInexistent);
        }
        if (pos.first < 0 || pos.second >= columnes) {
            throw error(PosicioInexistent);
        }
        if(p==0 and pos.first==0){  //cas exterior pel nord
            throw error(PortaExterior);
        }
        if(p==3 and pos.second==0){  //cas exterior pel oest
            throw error(PortaExterior);
        }
        if(p==2 and pos.first==(files-1)){  //cas exterior pel sud
            throw error(PortaExterior);
        }
        if(p==1 and pos.second==(columnes-1)){  //cas exterior pel oest
            throw error(PortaExterior);
        }

        matriu[pos.first][pos.second].obre_porta(p);


        if(p==0){       //si es nord, hem d'obrir la posició amb la fila-1 el sud
            matriu[pos.first-1][pos.second].obre_porta(2);
        }
        if(p==2){       //si es sud, hem d'obrir la posició amb la fila+1  el nord
            matriu[pos.first+1][pos.second].obre_porta(0);
        }
        if(p==1){       //si es est, hem d'obrir la posició amb la fila-1 el oest
            matriu[pos.first][pos.second+1].obre_porta(3);
        }
        if(p==3){       //si es oest, hem d'obrir la posició amb la fila-1 el est
            matriu[pos.first][pos.second-1].obre_porta(1);
        }
        
  }

  // Tanca la porta en la paret donada de la cambra que està especificada per pos.
  // També tanca la porta corresponent en la cambra adjacent. Es produeix un error
  // si la posició no existeix.
  void laberint::tanca_porta(paret p, const posicio & pos) throw(error){
        if (pos.first < 0 || pos.second >= files) {
            throw error(PosicioInexistent);
        }
        if (pos.first < 0 || pos.second >= columnes) {
            throw error(PosicioInexistent);
        }

         matriu[pos.first][pos.second].tanca_porta(p);

        if(p==0){       //si es nord, hem de tancar la posició amb la fila-1 el sud
            matriu[pos.first-1][pos.second].tanca_porta(2);
        }
        if(p==2){       //si es sud, hem de tancar la posició amb la fila+1  el nord
            matriu[pos.first+1][pos.second].tanca_porta(0);
        }
        if(p==1){       //si es nord, hem de tancar la posició amb la fila-1 el sud
            matriu[pos.first][pos.second+1].tanca_porta(3);
        }
        if(p==3){       //si es nord, hem de tancar la posició amb la fila-1 el sud
            matriu[pos.first][pos.second-1].tanca_porta(1);
        }

  }

  // Escriu el laberint a l'ostream (canal de sortida) os. El format per escriure
  // el laberint seguirà l'exposat a l'apartat 2.3.
  void laberint::print(std::ostream & os) const throw(){
        int cont = ((columnes*3)-(columnes-1));
        //os<< string(cont, '*') <<endl;
        //string.Concat(Enumerable.Repeat("*", 4));
        for(int i=0; i<files; i++){
            os<<"*"/*<<endl*/;
            
            for(int j=0; j< files; j++){
                if(matriu[i][j].porta_oberta(0));
                cout<<" ";
            }
            os<<endl;
        }
  }