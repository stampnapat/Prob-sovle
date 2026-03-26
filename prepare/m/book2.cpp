#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for(int i = 0; i<m; i++){
        int ope;
        cin >> ope;
        if (ope == 1){
            int x;
            cin >> x;
            auto find_if = find(arr.begin(), arr.end(), x);
            if (*find_if != x){
            auto it = arr.begin();
            arr.insert(it, x);
        }
    }else if (ope == 2){
        int x;
        cin >> x;
        auto find_if = find(arr.begin(), arr.end(), x);
        if (*find_if != x){
        arr.push_back(x);
        }
    }else if (ope == 3){
        int x;
        cin >> x;
        auto it = find(arr.begin(), arr.end(), x);
        if(*it == x){
         if(it != arr.end() && it != arr.begin()){
            arr.erase(it);
         }}
        }else if(ope == 4){
            int x;
            cin >> x;
            int temp = x;
            auto it = find(arr.begin(), arr.end(), x);
            if(*it == x){
             if(it != arr.end() && it != arr.begin()){
            arr.erase(it);
            auto front = arr.begin();
            arr.insert(front, temp);
             }
            }

        }
    }

    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << "\n";
    }

}