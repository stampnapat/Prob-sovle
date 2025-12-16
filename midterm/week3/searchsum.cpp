#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> price;
  vector<int> can_buy;
  int sum = 0;

  for(int i =0; i<n; i++){
    int x;
    cin >> x;
    sum += x;
    price.push_back(sum);
  }

  for(int i =0; i<k; i++){
    int y;
    cin >> y;
    auto it = upper_bound(price.begin(), price.end(), y);

    can_buy.push_back(it-price.begin());
  }
  for(int i=0; i<can_buy.size(); i++){
    cout << can_buy[i] << "\n";
  }


}
