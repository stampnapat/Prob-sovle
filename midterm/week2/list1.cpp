#include<iostream>
#include<list>

using namespace std;

int main() {
  int n;
  cin >> n;
  list<int>Li;
  char arr[100];
  int index = 0;

  for (int i = 0; i<n; i++){
    int x;
    char y;
    cin >> y >> x ;
    if (y == 'I'){
      Li.push_front(x);
    }else {
      if(x<1 || x > Li.size()){
        continue; 
      }
        auto it = Li.begin();
        advance(it, x-1);
        Li.erase(it);
      }
    }
  for (int v : Li){
    cout << v << '\n';
  }
} 



  


