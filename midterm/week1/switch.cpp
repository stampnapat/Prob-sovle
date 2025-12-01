#include <iostream>
using namespace std;

int max(int a, int b){
  return (a>b) ? a:b;
}

int main() {
  int n;
  cin >> n;
  int pattern[n];
  int count = 1;
  int de[n];
  int is_duplicate = 0;
  int news[n];

  for(int i = 0; i<n; i++){
    cin >> pattern[i] ;
    pattern[i] -= 1;
    de[i] = 0;
  }
 
  for (int i = 1; i<=n; ++i){
    if (!de[i]){
      int current = i;
      int length = 0;

      while (!de[current]){
        de[current] = 1;
        current = pattern[current];
        length++;
      }
      if (length > 0){
        count = max(count, length);
      }
    }
  }
  cout << count;
}
