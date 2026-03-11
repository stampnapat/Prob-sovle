#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    long long b;
    cin >> n >> b >> k;

    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<vector<long long>> val(n + 1, vector<long long>(n + 1, 0));

    for (int l = 1; l <= n; l++) {
        long long mx = 0;
        for (int r = l; r <= n; r++) {
            mx = max(mx, v[r]);
            long long len = r - l + 1;
            long long revenue = ((len + 1) * mx) / 2;
            long long cost = (len - 1) * b;   // FIX: (L-1)*B
            val[l][r] = revenue - cost;
        }
    }

    const long long NEG = -(1LL << 60);
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, NEG));
    dp[0][0] = 0;

    for (int g = 1; g <= k; g++) {
        for (int i = 1; i <= n; i++) {
            long long best = NEG;
            for (int j = 0; j < i; j++) {
                if (dp[j][g - 1] == NEG) continue;
                best = max(best, dp[j][g - 1] + val[j + 1][i]);
            }
            dp[i][g] = best;
        }
    }

    long long answer = NEG;
    for (int g = 1; g <= k; g++) {
        answer = max(answer, dp[n][g]);
    }

    cout << answer << "\n";
    return 0;
}