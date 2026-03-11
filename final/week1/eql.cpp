#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int p[201];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    bool dp[301][301] = {false};
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        bool next[301][301] = {false};
        for (int a = 0; a <= sum; a++) {
            for (int b = 0; b <= sum; b++) {
                if (!dp[a][b]) continue;
                next[a][b] = true;
                if (a + p[i] <= sum) next[a + p[i]][b] = true;
                if (b + p[i] <= sum) next[a][b + p[i]] = true;
            }
        }
        for (int a = 0; a <= sum; a++)
            for (int b = 0; b <= sum; b++)
                dp[a][b] = next[a][b];
    }

    int ans = 0;
    for (int s = 1; s <= sum; s++)
        if (dp[s][s]) ans = s;

    cout << ans << '\n';
    return 0;
}
