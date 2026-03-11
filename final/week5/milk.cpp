#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;
const int MAX_N = 100010;

int n, q;
int parents[MAX_N];
int s[MAX_N];

void init_union_find() {
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        s[i] = 1;
    }
}

int find(int u) {
    if (parents[u] == u) return u;
    return parents[u] = find(parents[u]);
}

void union_set(int cu, int cv) {
    assert(parents[cu] == cu);
    assert(parents[cv] == cv);
    if (cu == cv) return;

    if (s[cu] > s[cv]) {
        parents[cv] = cu;
        s[cu] += s[cv];
    } else {
        parents[cu] = cv;
        s[cv] += s[cu];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char cmd[10];
    cin >> n >> q;
    init_union_find();

    string out;
    out.reserve(q * 4);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> cmd >> x >> y;
        x--; y--;

        int cx = find(x);
        int cy = find(y);

        if (cmd[0] == 'c') {
            union_set(cx, cy);
        } else {
            if (cx == cy) out += "yes\n";
            else out += "no\n";
        }
    }

    cout << out;
    return 0;
}