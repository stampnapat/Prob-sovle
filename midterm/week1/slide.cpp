#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  int arr[300];

  for (int i = 0; i<n; i++){
    cin >> arr[i];
  }

  for (int i = 1; i<n; i++){
    for (int j = 0; j<i; j++){
      if (arr[i]>arr[j]){
        count++;
      }
    }
  }
  cout << count;
}
