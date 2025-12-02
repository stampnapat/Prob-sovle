#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
  int n;
  cin >> n;
  list<int> Li;
  string y;
  int x;

  for (int i =0; i<n; i++){
    cin >> y;

    if (y== "li"){
      cin >> x;
      Li.push_front(x);
    }else if (y == "ri"){
      cin >> x;
      Li.push_back(x);
    }else if (y == "lr"){
      if (!Li.empty()) {
        int front = Li.front();
        Li.pop_front();
        Li.push_back(front);
      }
    }else if (y== "rr"){
      if(!Li.empty()){
        int back = Li.back();
        Li.pop_back();
        Li.push_front(back);
      }
    }
  }

  for (int v: Li) cout<<v<<"\n";

}
