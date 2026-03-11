#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int price[205];
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
        total += price[i];
    }

    const int MAXS = 300;
    static bool dp[MAXS + 1][MAXS + 1];

    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        int p = price[i];
        for (int a = MAXS - p; a >= 0; a--) {
            for (int b = MAXS; b >= 0; b--) {
                if (dp[a][b]) dp[a + p][b] = true;
            }
        }
        for (int a = MAXS; a >= 0; a--) {
            for (int b = MAXS - p; b >= 0; b--) {
                if (dp[a][b]) dp[a][b + p] = true;
            }
        }
    }

    int best = 0;
    for (int s = 1; s <= MAXS; s++) {
        if (dp[s][s]) best = s;
    }

    cout << best << "\n";
    return 0;
}

