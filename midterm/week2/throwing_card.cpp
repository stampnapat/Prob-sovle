#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {

        list<int> l, cut;

        for (int i = 1; i <= n; i++)
            l.push_back(i);

        while (l.size() > 1) {
            cut.push_back(l.front());
            l.pop_front();

            int x = l.front();
            l.pop_front();
            l.push_back(x);
        }

        cout << "Discarded cards:";
        if (!cut.empty()) {
            cout << " ";
            for (auto it = cut.begin(); it != cut.end();) {
                cout << *it;
                ++it;
                if (it != cut.end()) cout << ", ";
            }
        }

        cout << "\nRemaining card: " << l.front() << "\n";
    }

    return 0;
}

