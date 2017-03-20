#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long  MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0 ;
  long long max[2] = {-1,-1};
  
  for(int i = 0; i < numbers.size(); i++ ) {
    long long n = numbers[i];
    
    if(n >  max[0]) { // n is new max
      max[1] = max[0];
      max[0] = n;
    } else if( n > max[1] ) { // n is new second max
      max[1] = n;
    }
  }
  
  result =  max[0]*max[1];
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
