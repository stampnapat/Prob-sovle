#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  int index = 0;
  int last = n;
  int arr[n+1];
  arr[index++] = n;
  int answer[n];
  int Y[n];

  if (t == 1) {
    for(int i = 1; i<=n; i++){
      cin >> arr[index] ;
      if(arr[index] < last){
        answer[i-1] = 0; 
      }else {
        answer[i-1] = 1;
      }
      last = arr[index];
    }
  } 
  else {
    int Z[n];
    for(int i = 1; i <= n; i++){
      cin >> arr[index];
      Z[i-1] = arr[index];
    }

    Y[0] = Z[0];

    for(int i = 2; i <= n; i++){
      int zp = Z[i-1];
      int yp = Y[i-2];

      int y0 = zp - yp;
      int y1 = zp - 2*yp;

      if (y1 == yp + 1) {
        Y[i-1] = y1;
        answer[i-1] = 1;
      } else {
        Y[i-1] = y0;
        answer[i-1] = 0;
      }
    }

    if (Y[0] == n + 1) answer[0] = 1;
    else answer[0] = 0;
  }
  
  for(int i = 0; i<n; i++){
    cout << answer[i] << "\n";
  }

}

