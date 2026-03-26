#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, d, r;
    while (cin >> n >> d >> r && (n != 0 || d != 0 || r != 0)) {
        vector<int> morning(n);
        vector<int> evening(n);

        for (int i = 0; i < n; i++) cin >> morning[i];
        for (int i = 0; i < n; i++) cin >> evening[i];

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());

        long long total_overtime = 0;
        for (int i = 0; i < n; i++) {
            int daily_dist = morning[i] + evening[i];
            if (daily_dist > d) {
                total_overtime += (daily_dist - d) * r;
            }
        }

        cout << total_overtime << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}