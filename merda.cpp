/*if((a == 1 and p == paret::NORD) or (a==M.num_files() and p == paret::SUD) or 
            (b == 1 and p == paret::OEST) or (b == M.num_columnes() and p == paret::EST) ){
              fallo=true;
            }*/
            /*if(a==M.num_files() and p == paret::SUD and not fallo){
              fallo=true;
              //elimines el 2 de les possibilitats;
            }
            if(b == 1 and p == paret::OEST and not fallo){
              fallo=true;
              //elimines el paret::OEST de les possibilitats;
            }
            if(b == M.num_columnes() and p == paret::EST and not fallo){
              fallo=true;
              //elimines el paret::EST de les possibilitats;
            }*/
            


            //while(fallo){
            //p= R(0,3);
            /*int k;
            if(a == 1){
              k=10;
            }
            if(a==M.num_files()){
              k+=100;
            }
            if(b==M.num_columnes()){
              k+=1000;
            }
            if(b==1){
              k+=1;
            }
            k=1111;
            if(k%10==1){
              
            }

              if(a==M.num_files()){
                if(b)
                p=R(5,6);
                if(p=5) p=paret::;
                if(p=6) p=1
                //p = R(R(1),R(3));
              }
            */
            

            pair<bool,int> es_adjacent(nat a, nat b, nat a1, nat b1){
    pair<bool, int> p;
    p.first = false;
    if(a1==0 or b1==0){
      return p;
    }
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
        p.second = paret::NORD;
        
      }
      else if(a == a1-1){
        p.first = true;
        p.second = paret::SUD;
        
      }
    }
    return p;
  }
