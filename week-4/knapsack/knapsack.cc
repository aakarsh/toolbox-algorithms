#include <iomanip>
#include <iostream>
#include <vector>

using std::vector;

#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif

int optimal_weight(int W, const vector<int> &w) {
  
  int nitems = w.size();
  vector<vector<int>> opt_values(nitems+1, vector<int>(W+1,-1));
  int current_weight = 0;

  // Set all weights without any itmes to 0 
  for(int i = 0; i <= W; i++) opt_values[0][i] = 0; 
  
  // Set all knapsack with 0-weight to 0 
  for(int i = 0; i <= nitems; i++) opt_values[i][0] = 0;

  for(int i = 1; i <= nitems ; i++) { 
    
    int cur_weight = w[i-1]; // 0 indexed
    
    for(int j = 1; j <= W; j++) { // for each cur_weight
      
      // weight acheived by (0..i-1) with knapsack size j 
      int skip_current = opt_values[i-1][j];
      
      // weight acheived by (0..i-1) with knapsack size of W-w[i-1] (cur_weights are zero index)
      int add_current = 0;
      
      if(j >= cur_weight)
        add_current = opt_values[i - 1][j - cur_weight];
      
      if( (add_current + cur_weight) <= j) {

        if(skip_current <= j) {
          opt_values[i][j] = std::max(add_current + cur_weight,skip_current);
        } else {
          opt_values[i][j] = add_current + cur_weight;
        }        
        
      } else if(skip_current <= j) {
        opt_values[i][j] = skip_current;
      } else {
        opt_values[i][j] = 0;
      }
      
    } 
    
  }
  
  if(debug) {
    for(int i = 0 ; i <= nitems; i++) {
      for(int j = 0; j <= W ; j++) {
        std::cerr<<std::setw(4)<<opt_values[i][j]<<"("<<i<<","<<j<<")"<<" ";
      }
      std::cerr<<std::endl;
    }
  }
  
  return opt_values[nitems][W];
}

int main() {
  
  int n, W;
  std::cin >> W >> n;
  
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  
  std::cout << optimal_weight(W, w) << '\n';
}
