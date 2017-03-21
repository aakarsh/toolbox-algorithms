#include <iostream>
#include <vector>

using std::vector;
/**
 * Using greedy stratergy pick coin of least denomination first.  Till
 * we are below that denomination, then pick next smallest
 * denomination.
 */
int get_change(int m) {
  vector<int> denomination = {10 , 5, 1};
  vector<int> count(denomination.size(),0);
  
  int cur = 0;
  while(true) {
    if(m <= 0) break;
    while(denomination[cur] <= m) {
      count[cur]++;
      m = m - denomination[cur];
    }
    cur++;
  }
  
  int sum = 0;
  for(auto s : count) {
    sum += s;
  }
  
  return sum;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
