#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    long long L;
    if (!(cin >> N >> L)) return;

    vector<pair<long long, long long>> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i].first >> houses[i].second;
    }

    int fence_count = 0;
    long long current_fence_end = -1;

    for (int i = 0; i < N; i++) {
        // ถ้าบ้านหลังปัจจุบันยังไม่มีรั้วไหนคลุมมิด
        if (houses[i].second > current_fence_end) {
            fence_count++;
            // วางรั้วใหม่ให้เริ่มที่ Si เพื่อให้ไปทางขวาได้ไกลที่สุด (Si + L)
            current_fence_end = houses[i].first + L;
            
            // หมายเหตุ: houses[i].second <= current_fence_end เสมอ 
            // เพราะโจทย์การันตีว่า L >= Ti - Si
        }
    }

    cout << fence_count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}