#include <iostream>
using namespace std;

int main() {
  int times;
  int sum = 0;
  cin >> times;
  for (int i = 0; i<times; i++){
    int x;
    cin >> x;
    if (x>=0) {
      sum += x;
    }else continue;
  }

  cout << sum;

}
