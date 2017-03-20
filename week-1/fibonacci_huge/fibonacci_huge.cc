#include <iostream>
#include <cassert>

long long get_fibonacci_huge_fast(long long n, long long m) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current) %m;
  }
  return current % m;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

    // for(int i =0 ; i < 10000; i++) {
    //   std::cerr<<"i="<<i<<std::endl;
    //   std::cerr<<get_fibonacci_huge_naive(i,10) <<":"<< get_fibonacci_huge_fast(i,10)<<std::endl;
    //   assert(get_fibonacci_huge_naive(i,10) == get_fibonacci_huge_fast(i,10));
    //    }
}
