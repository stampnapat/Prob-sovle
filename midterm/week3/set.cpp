#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main() {
  int n, m;
  vector<int> out;
  cin >> n >> m;

  set<int> Nset;
  set<int> Mset;

  for(int i =0; i<n; i++){
    int x;
    cin >> x;
    Nset.insert(x);
  }

  for(int i =0; i<m; i++){
    int y;
    cin >> y;
    // Mset.insert(y);

    auto it = Nset.lower_bound(y);

    if (it == Nset.begin()){
       //cout << *it << "\n";
      out.push_back(*it);

    }else if (it == Nset.end()){
      it--;
       //cout << *it << "\n";
      out.push_back(*it);
    }else {
      int right_value = *it;
      it--;
      int left_value = *it;

      if((right_value - y) >= (y - left_value)  ){
        // cout << left_value ;
        out.push_back(left_value);
      }else{
       //  cout << right_value << "\n";
       out.push_back(right_value);
      }

    }
  }

    for(int o : out){
      cout << o << "\n";
    }

 
}
