#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif

vector<int> optimal_sequence(int n) {
  
  std::vector<int> sequence(n+1,-1);
  std::vector<int> previous(n+1,-1);
  int i = 1;
  
  sequence[0] = 0;
  sequence[1] = 1;
  previous[0] = 0;
  previous[1] = 0;
  
  while(i <= n ){
    
    vector<int> nexts = {i+1,i*2,i*3};
    int pos = 0;
    
    for(auto j : nexts){
      if(j > n) continue;
      
      if(sequence[j] == -1  || sequence[j] > sequence[i]+1) {
        sequence[j] = sequence[i]+1;
        previous[j] = i;
        if(debug)
          std::cerr<<"prev "<<j<<" is "<<i<<std::endl;
      }
      
    }
    i++;
  }
  
  std::vector<int> intermediates;
  int k = n;
  do {
    intermediates.push_back(k);
    k = previous[k];
  } while(k >= 1); 

  reverse(intermediates.begin(),intermediates.end());
  
  return intermediates ;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
