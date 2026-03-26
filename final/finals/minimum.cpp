#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int l, r;
};

bool compareSegments(const Segment& a, const Segment& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

void solve(bool first) {
    int M;
    cin >> M;
    vector<Segment> segments;
    int l, r;
    while (cin >> l >> r && (l != 0 || r != 0)) {
        segments.push_back({l, r});
    }

    sort(segments.begin(), segments.end(), compareSegments);

    vector<Segment> result;
    int current_reach = 0;
    int i = 0;
    bool possible = false;

    while (current_reach < M) {
        int best_r = current_reach;
        int best_idx = -1;

        while (i < segments.size() && segments[i].l <= current_reach) {
            if (segments[i].r > best_r) {
                best_r = segments[i].r;
                best_idx = i;
            }
            i++;
        }

        if (best_idx == -1) break;

        result.push_back(segments[best_idx]);
        current_reach = best_r;
        
        if (current_reach >= M) {
            possible = true;
            break;
        }
    }

    if (!first) cout << "\n";
    if (possible) {
        cout << result.size() << "\n";
        for (const auto& seg : result) {
            cout << seg.l << " " << seg.r << "\n";
        }
    } else {
        cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_test_cases;
    cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; i++) {
        solve(i == 0);
    }

    return 0;
}