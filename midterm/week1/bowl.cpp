#include <iostream>
using namespace std;

int main() {
  int times;
  int max = 0;
  cin >> times;

  int arr[times];
  int count[100000] = {0};

  for (int i = 0; i<times; i++){
    cin >> arr[i];
    count[arr[i]]++;

    if ( count[arr[i]] > max){
      max = count[arr[i]];
    }
  }

  cout <<  max;
}
