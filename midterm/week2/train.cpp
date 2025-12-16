#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<list<long long>> l(n+1);

    while (m--) {
        char type;
        cin >> type;

        if (type == 'N') {
            long long x;
            int i;
            cin >> x >> i;
            l[i].push_back(x);
        } else {
            int i, j;
            cin >> i >> j;
            l[j].splice(l[j].end(), l[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (auto t : l[i]) {
            cout << t << "\n";
        }
    }
}
