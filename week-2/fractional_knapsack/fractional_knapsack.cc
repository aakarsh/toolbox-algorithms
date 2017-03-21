#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;

bool pair_by_first(const std::pair<double,int> & p1 , const std::pair<double,int> & p2) {
  return p1.first > p2.first; 
}
/**
 * Theif will pick the greatest density item till its done. 
 * moving to next less dense item next
 */
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  
  double value = 0.0;
  
  vector<double> fractional(weights.size());
  vector<pair<double,int>> densities(weights.size());
  
  for(int i = 0 ; i < values.size(); i++){
    densities[i] = std::make_pair((values[i]*1.0) / weights[i], i);
  }
  
  std::sort(densities.begin(), densities.end(),pair_by_first);
  for(auto d: densities) {
    //std::cerr<<" "<<d.first<<"["<<d.second<<"]";
  }
  
  //std::cerr<<std::endl;
  
  int cur = 0;
  while(capacity > 0 && cur < densities.size()) {
    int top = densities[cur].second; // position of most dense item
    fractional[top] = 1;
    if( capacity < weights[top]) { // cannot fit most dense item  
      fractional[top] = capacity/(weights[top]*1.0);
    }
    capacity -= fractional[top]*weights[top];
    cur++;
  }
  
  for(auto dense : densities) {
    
    int top = dense.second;
    double density = dense.first;
    double qty = fractional[top];
    
    //std::cerr<<"qty "<<qty<<" density "<<density<<" pos "<<top<<std::endl;
    
    value += (qty*weights[top]) * density;
    
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
