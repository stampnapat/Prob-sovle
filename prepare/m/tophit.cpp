#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int l, n, k;
    cin >> l >> n >> k;

    vector<pair<int, int>> v(l);
    vector<pair<int, int>> author(l);

    // author[i].first = หมายเลขนักเขียนของหนังสือเล่ม i+1
    // author[i].second = หมายเลขหนังสือ i+1
    for(int i = 0; i < l; i++){
        cin >> author[i].first;
        author[i].second = i + 1;
    }

    // v[i].first = จำนวนโหวตของหนังสือเล่ม i+1
    // v[i].second = หมายเลขหนังสือ i+1
    for(int i = 0; i < l; i++){
        v[i].first = 0;
        v[i].second = i + 1;
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[x - 1].first++;
    }

    // best[a] = หมายเลขหนังสือที่ดีที่สุดของนักเขียน a
    vector<int> best(100001, -1);

    for(int i = 0; i < l; i++){
        int a = author[i].first;   // หมายเลขนักเขียน
        int book = i;              // index ของหนังสือ

        if(best[a] == -1){
            best[a] = book;
        }
        else{
            int old = best[a];

            if(v[book].first > v[old].first){
                best[a] = book;
            }
            else if(v[book].first == v[old].first &&
                    v[book].second < v[old].second){
                best[a] = book;
            }
        }
    }

    vector<int> ans;

    for(int a = 1; a <= 100000; a++){
        if(best[a] != -1){
            ans.push_back(best[a]);
        }
    }

    sort(ans.begin(), ans.end(), [&](int x, int y){
        if(v[x].first != v[y].first) return v[x].first > v[y].first;
        return v[x].second < v[y].second;
    });

    for(int i = 0; i < k; i++){
        cout << v[ans[i]].second << '\n';
    }

    return 0;
}