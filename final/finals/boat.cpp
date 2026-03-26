#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    multiset<long long> boats;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        boats.insert(x);
    }

    int count = 0;
    for (int j = 0; j < M; j++) {
        long long y;
        cin >> y;
        
        auto it = boats.lower_bound(y);

        if (it != boats.end()) {
            count++;
            boats.erase(it);
        } else {
            break;
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}