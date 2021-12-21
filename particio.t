#include "particio.hpp"
#include <iostream>
using namespace std;
 // Construeix una particio amb n elements com a màxim.
  template <typename T>
  particio<T>::particio(nat n) throw(error){
      MAX=n;
      num=0;
      num_grups=0;
      _arrel = NULL;
  }

  // Constructora per còpia, assignació i destructora.
  template <typename T>
  particio<T>::particio(const particio & p) throw(error){

  }
  template <typename T>
  particio<T> & particio<T>::operator=(const particio & p) throw(error){
      return *this;
  }
  template <typename T>
  particio<T>::~particio() throw(){

  }

  // Afegeix un nou element a la particio. Aquest nou element formarà ell sol
  // un nou grup. En cas que l'element ja estigués present a la partició llavors
  // no es modifica la partició. Es produeix un error si la particio ja té el
  // número màxim d'elements abans d'afegir aquest nou.
  template <typename T>
  void particio<T>::afegir(const T &x) throw(error){
      //si no està l'afegeixes on toca i representant ell mateix
        bool aug=false;
        _arrel=insert(_arrel, x, aug);
        //augmentar si cal el numero de grups i elements
        if(aug){
            if(num_elements()>=num_maxim()) throw error(ParticioPlena);
            num+=1;
            num_grups+=1;
        }
      
  }

  // Uneix els dos grups als quals pertanyen aquests dos elements. Si tots dos
  // elements ja pertanyien al mateix grup no fa res.
  // Es produeix un error si algun dels elements no pertany a la partició.
  template <typename T>
  void particio<T>::unir(const T & x, const T & y) throw(error){
      //buscar els dos membres
      node* nx=busca(_arrel,x);
      node* ny=busca(_arrel,y);
      if(nx==NULL or ny==NULL) throw(ElemInexistent);
      else{
          while(nx->es_arrel != true){
              nx=nx->repr;
          }
          while(ny->es_arrel != true){
              ny=ny->repr;
          }
          if(nx!=ny){
              if(ny->pes>nx->pes){
                  nx->repr=ny;
                  nx->es_arrel=false;
                  ny->pes=ny->pes+nx->pes;
              }
              else if(ny->pes>=nx->pes){
                  ny->repr=nx;
                  ny->es_arrel=false;
                  nx->pes=ny->pes+nx->pes;
              }
              num_grups--;
          }
      }
  }

  // Retorna si els elements x i y pertanyen al mateix grup.
  // Es produeix un error si algun dels dos elements no pertany a la partició.
  template <typename T>
  bool particio<T>::mateix_grup(const T & x, const T & y) const throw(error){
      node* nx=busca(_arrel, x);
      node* ny=busca(_arrel, y);
      if(nx== NULL or ny == NULL) throw(ElemInexistent);
      else{
          while(nx->es_arrel != true){
              nx=nx->repr;
          }
          while(ny->es_arrel != true){
              ny=ny->repr;
          }
          if(nx == ny){
              return true;
          }
          else{
              return false;
          }
      }
  }

  // Retorna el número de grups que té la particio.
  template <typename T>
  nat particio<T>::size() const throw(){
      return num_grups;
  }

  // Retorna el número d'elements que té la particio.
  template <typename T>
  nat particio<T>::num_elements() const throw(){
      return num;
  }

  // Retorna el número màxim d'elements que pot tenir la particio.
  template <typename T>
  nat particio<T>::num_maxim() const throw(){
    return MAX;
  }

  //ESPECIFICACIÓ METODES PRIVATS
    template <typename T>
    int particio<T>::altura(node *N)
    {
    if (N == NULL)
        return 0;
    return N->altura;
    }
    template <typename T>
    int particio<T>::max(int a, int b)
    {
        return (a > b)? a : b;
    }
    template <typename T>
    typename particio<T>::node* particio<T>::newnode(int clau)
    {
        node* n;
        n = new node;
        n->clau = clau;
        n->f_esq = NULL;
        n->f_dret = NULL;
        n->altura = 1; // new node is initially
                        // added at leaf
        n->repr = n;
        n->pes=1;
        n->es_arrel=true;
        return(n);
    }

    template <typename T>
    typename particio<T>::node* particio<T>::f_dretRotate(node *y)
    {
        node *x = y->f_esq;
        node *T2 = x->f_dret;
    
        // Perform rotation
        x->f_dret = y;
        y->f_esq = T2;
    
        // Update alturas
        y->altura = max(altura(y->f_esq),
                        altura(y->f_dret)) + 1;
        x->altura = max(altura(x->f_esq),
                        altura(x->f_dret)) + 1;
    
        // Return new root
        return x;
    };

    template <typename T>
    typename particio<T>::node* particio<T>::f_esqRotate(node* x)
    {
        node *y = x->f_dret;
        node *T2 = y->f_esq;
    
        // Perform rotation
        y->f_esq = x;
        x->f_dret = T2;
    
        // Update alturas
        x->altura = max(altura(x->f_esq),   
                        altura(x->f_dret)) + 1;
        y->altura = max(altura(y->f_esq),
                        altura(y->f_dret)) + 1;
    
        // Return new root
        return y;
    };

    template <typename T>
    typename particio<T>::node* particio<T>::insert(node* node, T clau, bool &aug)
    {
        if (node == NULL){
            aug=true;
            return(newnode(clau));  
        }
        if (clau < node->clau){
            //cout<<"ins esq";
            node->f_esq = insert(node->f_esq, clau, aug);
        }
        else if (clau > node->clau){
            //cout<<"ins dret";
            node->f_dret = insert(node->f_dret, clau, aug);
        }
        else if(clau == node->clau){// Si ja està al BST no fa res
            //cout<<"ei"<<endl;
            return node;
        }
    

        node->altura = 1 + max(altura(node->f_esq),
                            altura(node->f_dret));
    
        
        int balance = getBalance(node);
    
        // Cas f_esq f_esq 
        if (balance > 1 && clau < node->f_esq->clau)
            return f_dretRotate(node);
    
        // Cas f_dret f_dret 
        if (balance < -1 && clau > node->f_dret->clau)
            return f_esqRotate(node);
    
        // Cas f_esq f_dret
        if (balance > 1 && clau > node->f_esq->clau)
        {
            node->f_esq = f_esqRotate(node->f_esq);
            return f_dretRotate(node);
        }
    
        // Cas f_dret f_esq
        if (balance < -1 && clau < node->f_dret->clau)
        {
            node->f_dret = f_dretRotate(node->f_dret);
            return f_esqRotate(node);
        }
    
        
        return node;
    }
    template <typename T>
    int particio<T>::getBalance(node *N)
    {
        if (N == NULL)
            return 0;
        return altura(N->f_esq) - altura(N->f_dret);
    }

    template <typename T>
    typename particio<T>::node* particio<T>::busca(node* n, const T &k){
        if (n == NULL or n->clau == k) {
          return n;
        }
        else {
          if (k < n->clau) {
            return busca(n->f_esq, k);
          }
          else { // k > p->_k
            return busca(n->f_dret, k);
          }
        }
    }
