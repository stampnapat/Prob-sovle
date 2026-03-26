#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<long long> arr;
    for(int i = 0; i<n; i++){
        long long x;
        cin >> x;
        arr.push_back(x);

    }

    for(int i = 0; i<m; i++){
        int ope;
        cin >> ope;
        if(ope == 1){
            long long x;
            cin >> x;
            auto it = arr.begin();
            arr.insert(it, x);
        }else if(ope ==2){
            long long x;
            cin >> x;
            arr.push_back(x);
        }else if (ope == 3){
            long long x;
            cin >> x;
            auto it = find(arr.begin(), arr.end(), x);
            if(it != arr.end() && it != arr.begin()){
                arr.erase(it);
            }
        }else if (ope == 4){
            long long x;
            cin >> x;
            auto it = find(arr.begin(), arr.end(), x);
            if(it != arr.end() && it != arr.begin()){
            arr.erase(it);
            auto front = arr.begin();
            arr.insert(front, x);
            }
            
        }
    }

    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << "\n";
    }

}


