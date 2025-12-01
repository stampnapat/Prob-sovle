#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int count = 0;
  long long arr[100000];
  
  for (int i = 0; i<n; i++){
    cin >> arr[i];
  }

  long long bestT = arr[0];
  for (int u = 0; u<n; u++){
      if (arr[u] < bestT){
      bestT = arr[u];
    }
  }

  // int limit = 2*bestT;
  // for (int j = 0; j<n; j++){
  //   if (arr[j] == bestT || arr[j] > limit) {
  //     count++;
  //   } 
  // }
  long long win = 1LL * k * bestT;
  long long need = k-1;
  
  for (int j= 0; j<n; j++) {
    if (win > need * arr[j]) {
      count++;
    }
  }
  cout << count;
  }


