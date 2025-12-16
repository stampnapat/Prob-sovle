#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        while (true) {
            int first;
            cin >> first;
            if (first == 0) break;

            vector<int> target(n);
            target[0] = first;
            for (int i = 1; i < n; i++) {
                cin >> target[i];
            }

            stack<int> station;
            int current = 1;
            bool possible = true;

            for (int i = 0; i < n; i++) {
                int desired = target[i];
                while (current <= n && (station.empty() || station.top() != desired)) {
                    station.push(current);
                    current++;
                }

                if (station.top() == desired) {
                    station.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }
    return 0;
}

