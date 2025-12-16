#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, long long> arr;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        if(k == 1){
            int type;
            long long value;
            cin >> type >> value;
            arr[type] += value;
        }
        else if(k == 2){
            int type;
            cin >> type;
            if(arr.count(type))
                cout << arr[type] << "\n";
            else
                cout << 0 << "\n";
        }
        else if(k == 3){
            int type;
            long long value;
            cin >> type >> value;

            long long &ref = arr[type];
            long long can_remove = min(ref, value);
            ref -= can_remove;

            cout << can_remove << "\n";
        }
    }

    return 0;
}

