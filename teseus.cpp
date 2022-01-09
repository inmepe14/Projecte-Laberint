#include "teseus.hpp"
#include "queue"
using namespace std;

  bool valid(const posicio pos, const laberint & M){
    if(pos.first >= 1 and pos.first <= M.num_files()){
      if(pos.second >= 1 and pos.second <= M.num_columnes()){
        return true;
      }
    }
    return false;
  }


  // Dados un grafo G, sus pesos W, el número de nodos n, y dos nodos s, t devuelve la mínima
// distancia entre s y t
/*priority_queue <posicio> dijkstra (laberint M, int n, posicio s, posicio t){
    vector <bool> vis(n, false); //nodos visitados, inicialmente ninguno
    priority_queue <posicio> Q; //cola de prioridad
    Q.push(s); //introducimos el nodo origen (a distancia 0 de él mismo)

    while (not Q.empty()){
        posicio arc = Q.top(); //arco con menor peso desde F hasta G\F 
        Q.pop(); //lo quitamos de la cola

        //int v = arc.second; //vértice de Q a menor distancia del nodo origen
        //int p = arc.first; //distancia entre el nodo origen y v
        
        if (s == t) return Q; //si es el nodo destino hemos acabado

        if (not vis[v]){ //si no lo hemos visitado
            vis[v] = true;
            for (int i = 0; i < G[v].size(); ++i){ //miramos sus vecinos
                int u = G[v][i];
                //int w = W[v][i];

                Q.push({p-w, u}); // añadimos los vecinos con la distancia a s
            }
        }
    }

    return inf; // no hay caminos entre s y t
  }*/
  // Genera una llista de posicions que conté el camí mínim. El primer element
  // d'aquesta llista serà la posició inici, i l'última la posició final.
  // Una posició respecte a la seva anterior o posterior ha de ser consecutiva.
  // Dues posicions són consecutives si i només si la diferència de les primeres
  // components de les posicions és en valor absolut 1 i les segones components
  // són iguals, o si la diferència de les segones components és en valor
  // absolut 1 i les primeres components són iguals. Es produeix un error si no
  // hi ha cap camí que vagi des de la cambra inicial del laberint a la final,
  // o si la cambra inicial o final no són vàlides.
  void teseus::buscar(const laberint & M, 
              const posicio & inici, const posicio & final, 
              std::list<posicio> & L) throw(error){
                /*if(!(valid(inici, M)) or (!(valid(final, M)))){
                  throw error(IniciFinalNoValid);
                }*/
                //ara mirem les possibles següents posicions


/*
                  comprobar que inicial i final siguin valids -> throw error en cas que no
                  agafar la primera pos seguent-> seg.first = inici.first seg.second = inici.second+1 i comprovar si existeix
                                                    -- si existeix fas tot el recorregut
                                                  seg.first = inici.first seg.second = inici.second-1 i comprovar si existeix
                                                  seg.second = inici.second seg.first = inici.first+1 i comprovar si existeix
                                                  seg.second = inici.second seg.first = inici.first-1 i comprovar si existeix
                  -- si existeix fas tot el recorregut
                  pos inici -> pos seguent -- 
                  2 2 -> 2 1, 2 3, 1 2, 3 2
*/
                  /*if(inici.first == seg.first){
                    if(inici.second-seg.second==1 or inici.second-seg.second==-1)
                      son consecutius
                  }
                  if(inici.second == seguent.second){
                      if(inici.first - seguent.first == 1 or inici.first - seguent.first == -1)
                  }*/
                  nat k=M.num_files();
                  k+=inici.first;
                  k+=final.first;
                  L.push_front(inici);

              }