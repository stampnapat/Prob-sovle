#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        list<char> arr;
        auto it = arr.begin();

        for (char c : s) {
            if (c == '[') {
                it = arr.begin();
            }
            else if (c == ']') {
                it = arr.end();
            }
            else {
                arr.insert(it, c);
            }
        }

        for (char c : arr) cout << c;
        cout << "\n";
    }

    return 0;
}

