#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    const long long INF = (long long)4e18;

    int n, m;
    long long l;
    cin >> n >> m >> l;

    vector<long long> r(n + 1);
    for (int i = 1; i <= n; i++) cin >> r[i];

    vector<vector<pair<int,int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<long long> dist(n + 1, INF);
    set<pair<long long,int>> s;

    dist[1] = 0;
    s.insert({0,1});

    while (!s.empty()) {
        auto it = s.begin();
        long long d = it->first;
        int u = it->second;
        s.erase(it);

        if (d != dist[u]) continue;

        for (auto &e : g[u]) {
            int v = e.first;
            long long nd = d + e.second;
            if (nd < dist[v]) {
                auto oldIt = s.find({dist[v], v});
                if (oldIt != s.end()) s.erase(oldIt);
                dist[v] = nd;
                s.insert({dist[v], v});
            }
        }
    }

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] >= INF/2) continue;
        ans += min(r[i], l) * dist[i];
    }

    cout << ans;
    return 0;
}
