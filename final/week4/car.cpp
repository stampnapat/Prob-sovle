#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    long long c[105], p[105], w[105];
    for (int i = 0; i < k; i++) cin >> c[i] >> p[i] >> w[i];

    long long a[1005], mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i];
    }

    long long ans = (1LL << 60);

    for (int i = 0; i < k; i++) {
        if (mx > w[i]) continue;   

        long long l = 1, cur = 0;  
        for (int j = 0; j < n; j++) {
            if (cur + a[j] <= w[i]) cur += a[j];
            else { l++; cur = a[j]; }
        }

        long long cost = c[i] + l * p[i];
        if (cost < ans) ans = cost;
    }

    cout << ans << "\n";
    return 0;
}