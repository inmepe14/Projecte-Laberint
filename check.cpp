#include "laberint.hpp"
#include <esin/util>

using util::nat;
using namespace std;

namespace check {
  
  bool comprova_cami_minim(const posicio& ini, 
			     const posicio& final,
			     const laberint& L,
			     const list<posicio>& cami_candidat) 
    throw(error) {
    cout<<ini.first<<final.first<<L.num_files()<<cami_candidat.size();
    return false;
  }
  
  bool comprova_perfecte(const laberint& L) {
    //cout<<L.num_files();
    if(L.num_files() == 4) return false;
    return false;
    
  }
};
