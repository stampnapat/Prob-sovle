#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
  int n;
  cin >> n;
  list<int>Li;
  int index = 0;
  int x;
  string y;

  for (int i = 0; i<n; i++){
        cin >> y >> x ;

    if (y == "li"){
      Li.push_front(x);

    }else if(y == "ri"){
      Li.push_back(x);
      
    }else if(y == "lr"){
      if (!Li.empty()){
      int front = Li.front();
      auto it = Li.begin();
         Li.erase(it);
          Li.push_back(front);
      }

    }else if(y == "rr"){
      if (!Li.empty()){
      int back = Li.back();
      Li.pop_back();
          Li.push_front(back);
      }
    }
    }
  for (int v : Li){
    cout << v << '\n';
  }
} 


