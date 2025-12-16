#include<iostream>
#include<map>
#include<vector>

using namespace std;
int main(){
int n;
cin >> n;

map<int, int> like;
map<int, int> index;
vector<int> arr;

int best = 0;

for (int i =0; i<n; i++){
  int x;
  cin>> x;
  like[x]++;
  index[x] = i;

  if (best == 0) best = x;
  else {
    int current = like[x];
    int best_c = like[best];
    if(current > best_c) best = x;
    else if (current == best_c){
      if (index[x] > index[best]) best = x;
    }
  }

    arr.push_back(best);
  }
for (auto x : arr){
    cout << x << "\n";
  }


}
