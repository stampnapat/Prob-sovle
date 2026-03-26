#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ฟังก์ชันหา LIS สำหรับทุกตำแหน่งใน O(N log N)
vector<int> get_lis(int n, const vector<int>& arr) {
    vector<int> lis_len(n);
    vector<int> tails; // เก็บค่าปลายน้อยที่สุดของ LIS ความยาวต่างๆ

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        if (it == tails.end()) {
            tails.push_back(arr[i]);
            lis_len[i] = tails.size();
        } else {
            *it = arr[i];
            lis_len[i] = distance(tails.begin(), it) + 1;
        }
    }
    return lis_len;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];

        // หา LIS จากซ้ายไปขวา
        vector<int> L = get_lis(n, arr);

        // หา LIS จากขวาไปซ้าย (กลับด้านอาเรย์)
        reverse(arr.begin(), arr.end());
        vector<int> R = get_lis(n, arr);
        reverse(R.begin(), R.end()); // กลับค่า R ให้ตรงกับตำแหน่งเดิม

        int max_wavio = 0;
        for (int i = 0; i < n; ++i) {
            // สูตร: ความยาว Wavio = 2 * min(ฝั่งซ้าย, ฝั่งขวา) - 1
            int current_wavio = 2 * min(L[i], R[i]) - 1;
            max_wavio = max(max_wavio, current_wavio);
        }

        cout << max_wavio << endl;
    }
    return 0;
}