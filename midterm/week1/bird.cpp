#include <iostream>
using namespace std;

int main() {
  int n;
  int arr[1000];
  cin >> n;

  for (int i = 0; i<n; i++){
    cin >> arr[i];
  }  

  int last = 0;
  int count = 0;
  for (int i = 0; i<n-1; i++){
    int current = arr[i];
    int next = arr[i+1];
    if ( current > last && current > next){
      count++;
    }

    last = current;
  } 
  cout << count;
}

