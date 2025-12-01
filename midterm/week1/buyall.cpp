#include <iostream>
using namespace std;

int mins(int a, int b){
  if (a > b) return b;
  return a;
}

int main() {
  int price[3];
  cin >> price[0] >> price[1] >> price[2];
  int c1 = 0;
  int c2 = 0;
  int c3 = 0;
  int n;
  cin >> n;
  for (int i = 0; i<n; i++){
    int c; 
    cin >> c;
    if (c == 1){
      c1++;
    }else if ( c == 2){
      c2++;
    }else if (c==3){
      c3++;
    }
  }

  int total1 = c1*price[0];
  int total2 = c2*price[1];
  int total3 = c3*price[2];

  int re  = mins(mins(total1, total2), total3);

  cout << re;



  
}
