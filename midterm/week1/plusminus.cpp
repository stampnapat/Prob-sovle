#include <iostream>
using namespace std;

int main() {
  int n;
  int num[1000];
  char op[999];
  cin >> n;
  int count = n + n -1;

  for (int i = 0; i< count; i++){
    if (i%2 == 0) {
      cin >> num[i/2];  
    }else {
      cin >> op[(i-1)/2];
    }
  }

  int sum = num[0];

  for (int i =0; i<n-1; i++){
    int nextN = num[i+1];
    int cop = op[i];
    if (cop == '+'){
      sum += nextN;
    }else sum -= nextN;

  }

  cout << sum;
}
