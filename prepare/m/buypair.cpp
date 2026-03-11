#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    long long count = 0;

    sort(prices.begin(), prices.end());

    for(int i = 0; i<n; i++){
        long long v_min = a-prices[i];
        long long v_max = b-prices[i];

        auto l = lower_bound(prices.begin() + i + 1, prices.end(), v_min);
        auto r = upper_bound(prices.begin() + i + 1, prices.end(), v_max);

        count += distance(l, r);

    }
    cout << count;
}
