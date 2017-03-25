#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using std::vector;
using std::pair;

#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif


std::pair<int,int> get_majority_element(vector<int> &a, int left, int right) {
  
  if (left == right) return std::make_pair(-1,0);
  if (left + 1 == right) return std::make_pair(a[left],1);

  int middle = (left+right)/2;
  int n = right-left;
  
  pair<int,int> m1 = get_majority_element(a,left,middle);
  pair<int,int> m2 = get_majority_element(a,middle,right);
  int v1 = m1.first;
  int v2 = m2.first;
  
  if(v1 == v2) return std::make_pair(v1,m1.second+m2.second);

  int m1_cnt = 0;
  for(int i = middle; i < right; i++)
    if(a[i] == v1) m1_cnt++;
    
  int m2_cnt = 0;
  for(int i = left; i < middle; i++)
    if(a[i] == v2) m2_cnt++;

  int left_count = m1.second;
  int right_count = m2.second;
  
  if(v1!=-1 && v2!=-1){ // simple majority disagrment
    if(right_count+m2_cnt > n/2)
      return std::make_pair(v2,m2_cnt+m2.second);
    if (left_count+m1_cnt > n/2)
      return std::make_pair(v1,m1_cnt+m1.second);
  }

  if( v1 == -1 ) { // no-majority-left
    if(right_count+m2_cnt > n/2)
      return std::make_pair(v2, m2.second+m2_cnt);
  } else if (v2 == -1) { // no-majority-right 
    if(left_count+m1_cnt > n/2)
      return std::make_pair(v1,m1.second+m1_cnt);
  }

  return std::make_pair(-1,0);
}

int get_majority_element_slow(vector<int> &a) {
  
  for(int i = 0; i < a.size(); i++) {
    
    int cur = a[i];
    int cnt = 0;
    
    for(int j = 0; j < a.size(); j++) {
      if(cur == a[j])
        cnt++;
    }
    
    if(cnt > (a.size()/2))
      return cur;
  }
  
  return -1;
}

void test_case(vector<int> & a) {
  int m0 = get_majority_element_slow(a);
  pair<int,int> p1 = get_majority_element(a,0,a.size());
  int m1= p1.first;
  std::cerr<<"Testing: m0 "<<m0<<" m1 "<<m1<<std::endl;
  assert(m0 == m1);
}

void test() {
  vector<int> t0 = { 2, 3 ,9, 2, 2};
  vector<int> t1 = {1, 2, 3, 4};
  //  vector<int> t2 = ;
  test_case(t0);
  test_case(t1);
}

int main() {
  // if(debug)
  //  test();
  
  int n;
  std::cin >> n;
  vector<int> a(n);
  
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  
  std::cout << (get_majority_element(a, 0, a.size()).first != -1) << '\n';
  
}
