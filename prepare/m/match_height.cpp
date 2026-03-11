#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> id(n);

    for(int i = 0; i < n; i++){
        cin >> h[i];
        id[i] = i;
    }

    sort(id.begin(), id.end(), [&](int a, int b){
        return h[a] < h[b];
    });

    vector<int> ans(n);

    for(int i = 0; i< n; i++){
        int current_id = id[i];
        int min_diff = 1e9;

        if(i>0){
            int left_idx = id[i-1];
            min_diff =min(min_diff, abs(h[current_id] - h[left_idx]));
        }
        if(i < n-1){
            int right_idx = id[i+1];
            min_diff = min(min_diff, abs(h[current_id] - h[right_idx]));
        }
        ans[current_id] = min_diff;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }



}

-----------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> h(n);          // เก็บความสูงตามลำดับเดิม
    vector<int> sorted_h(n);   // เก็บความสูงเพื่อนำไปเรียงลำดับ

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        sorted_h[i] = h[i];    // คัดลอกข้อมูล
    }

    // เรียงลำดับสำเนาความสูง
    sort(sorted_h.begin(), sorted_h.end());

    // คำนวณหาผลต่าง
    for (int i = 0; i < n; i++) {
        // ใช้ lower_bound (Binary Search) เพื่อหาตำแหน่งแรกของความสูง h[i] ใน sorted_h
        auto it = lower_bound(sorted_h.begin(), sorted_h.end(), h[i]);
        
        // แปลง Iterator ให้เป็นเลข Index (0 ถึง n-1)
        int idx = distance(sorted_h.begin(), it);

        int min_diff = 2000000000;

        // เช็คผลต่างกับคนข้างซ้าย (ถ้ามี)
        if (idx > 0) {
            min_diff = min(min_diff, h[i] - sorted_h[idx - 1]);
        }
        
        // เช็คผลต่างกับคนข้างขวา (ถ้ามี)
        if (idx < n - 1) {
            min_diff = min(min_diff, sorted_h[idx + 1] - h[i]);
        }

        // สามารถพิมพ์คำตอบออกมาได้เลย เพราะเราวนลูปตามลำดับเดิม (h[i]) อยู่แล้ว
        cout << min_diff << "\n";
    }

    return 0;
}