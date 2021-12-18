#include "laberint.hpp"
#include <iostream>
#include <sstream>
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
    int num_files;
    int num_columnes;
    string linia;
    /*getline(is, linia);
    //is>>num_files;
    istringstream ss(linia);
    ss>>num_files;
    ss>>num_columnes;*/
    is>>num_files;
    is>>num_columnes;
    files=num_files;
    columnes=num_columnes;
    //is.get(caracter);
    matriu = new cambra*[files];
    for (int i = 0; i < files; i++) {
        matriu[i] = new cambra[columnes];
    }
    
    //init lab_unic laberint ./laberint_3x3.txt
    int i=0;
    char caracter;
    while(i<files){
        cout<<"fila nord0";
        for(int j=0; j<columnes; j++){
            is.get(caracter);
            cout<<caracter;
            is.get(caracter); //llegir la paret nord
            //cambra c=matriu[i][j];
            cout<<caracter;
            if(caracter==' '){
                matriu[i][j].obre_porta(paret::NORD);
                //cout<<"eii"<<endl;
            }
            }
            is.get(caracter);
            cout<<caracter;
            is.get(caracter);
            cout<<caracter;
            //endl
            /*is.get(caracter);
            cout<<"salt de linia"<<caracter;*/
            //is.get(caracter);
            cout<<"fila est";
            for(int j=0; j<columnes; j++){
                //cambra c=matriu[i][j];
                cout<<"i"<<endl;
                is.get(caracter);
                cout<<caracter;
                is.get(caracter);
                cout<<caracter;
                if(caracter==' '){          //es pot mirar d'estalviar una iteració
                    matriu[i][j].obre_porta(paret::EST); 
                    //cout<<"ei"<<endl;
                }
                //https://limnu.com/d/draw.html?nu=1&b=B_vqFdLOPRxtORVJ&
                /*is.get(caracter);
                cout<<caracter;*/

            }
            is.get(caracter);
            cout<<caracter;
            i++;
            }
            //getline(is, linia);            
       //vol llegir un laberint de l'entrada i guardar-lo
       //mirar si la porta està amb un ' ' i guardar-ho com a porta oberta
    /*int* laberint_entrada= new int[dimension];
       std::string laberint_entrada[]; //array d'strings
       is>>laberint_entrada[1];
       if (laberint_entrada[1] == " "){
           obre_porta;
       }*/
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
        /*laberint lab = l;
        files= lab.num_files();
        columnes = lab.num_columnes();
        */
        files = l.num_files();
        columnes = l.num_columnes();
        matriu = new cambra*[files];
        //posar una matriu auxiliar i al final destruirh
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
      if (pos.first <= 0 || pos.first > files) {
            throw error(PosicioInexistent);
        }
        if (pos.second <= 0 || pos.second > columnes) {
            throw error(PosicioInexistent);
        }

      return matriu[pos.first][pos.second];
  }

  // Obre la porta en la paret donada de la cambra que està especificada per pos.
  // També obre la porta corresponent en la cambra adjacent. Es produeix un error
  // si la posició no existeix o no es pot obrir una porta en la direcció
  // indicada perquè dóna a l'exterior.
  void laberint::obre_porta(paret p, const posicio & pos) throw(error){
        if (pos.first <= 0 || pos.first > files) {
            throw error(PosicioInexistent);
        }
        if (pos.second <= 0 || pos.second > columnes) {
            throw error(PosicioInexistent);
        }
        pair<int,int> poss = make_pair(pos.first-1, pos.second-1);
        if(p==0 and poss.first==0){  //cas exterior pel nord
            throw error(PortaExterior);
        }
        if(p==3 and poss.second==0){  //cas exterior pel oest
            throw error(PortaExterior);
        }
        if(p==2 and poss.first==(files-1)){  //cas exterior pel sud
            throw error(PortaExterior);
        }
        if(p==1 and poss.second==(columnes-1)){  //cas exterior pel oest
            throw error(PortaExterior);
        }

        matriu[poss.first][poss.second].obre_porta(p);


        if(p==0){       //si es nord, hem d'obrir la posició amb la fila-1 el sud
            matriu[poss.first-1][poss.second].obre_porta(2);
        }
        if(p==2){       //si es sud, hem d'obrir la posició amb la fila+1  el nord
            matriu[poss.first+1][poss.second].obre_porta(0);
        }
        if(p==1){       //si es est, hem d'obrir la posició amb la fila-1 el oest
            matriu[poss.first][poss.second+1].obre_porta(3);
        }
        if(p==3){       //si es oest, hem d'obrir la posició amb la fila-1 el est
            matriu[poss.first][poss.second-1].obre_porta(1);
        }
        
  }

  // Tanca la porta en la paret donada de la cambra que està especificada per pos.
  // També tanca la porta corresponent en la cambra adjacent. Es produeix un error
  // si la posició no existeix.
  void laberint::tanca_porta(paret p, const posicio & pos) throw(error){
        
        if (pos.first <= 0 || pos.first > files) {
            throw error(PosicioInexistent);
        }
        if (pos.second <= 0 || pos.second > columnes) {
            throw error(PosicioInexistent);
        }
         pair<int,int> poss = make_pair(pos.first-1, pos.second-1);
         matriu[poss.first][poss.second].tanca_porta(p);

        if(p==0){       //si es nord, hem de tancar la posició amb la fila-1 el sud
            matriu[poss.first-1][poss.second].tanca_porta(2);
        }
        if(p==2){       //si es sud, hem de tancar la posició amb la fila+1  el nord
            matriu[poss.first+1][poss.second].tanca_porta(0);
        }
        if(p==1){       //si es nord, hem de tancar la posició amb la fila-1 el sud
            matriu[poss.first][poss.second+1].tanca_porta(3);
        }
        if(p==3){       //si es nord, hem de tancar la posició amb la fila-1 el sud
            matriu[poss.first][poss.second-1].tanca_porta(1);
        }

  }

  // Escriu el laberint a l'ostream (canal de sortida) os. El format per escriure
  // el laberint seguirà l'exposat a l'apartat 2.3.
  void laberint::print(std::ostream & os) const throw(){
      //pre: el laberint es correcte
        int cont = ((columnes*3)-(columnes-1));
        int i=0;
        cout<<files<<" "<<columnes<<endl;
        while(i<files){
            for(int j=0; j<columnes; j++){
                cambra c=matriu[i][j];
                cout<<"*";
                if(c.porta_oberta(0)){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
            cout<<"*"<<endl<<"* ";
            for(int j=0; j<columnes; j++){
                cambra c=matriu[i][j];
                if(j!=0) cout<<" ";
                if(c.porta_oberta(1)){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                } 
            }
            cout<<endl;
            i++;
        }
        os<< string(cont, '*') <<endl;
        
  }