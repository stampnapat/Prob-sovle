#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    map<int,int> freq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freq[num]++;
    }

    vector< pair<int,int> > vec(freq.begin(), freq.end());

    sort(vec.begin(), vec.end(), cmp);

    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i].first << "\n";
    }
}

