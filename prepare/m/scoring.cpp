#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> scores(n+1);

    for(int i = 0; i < m; i++){
        int a, s;
        cin >> a >> s;

        scores[a].second++;
        int old = scores[a].first;

        if(scores[a].second <= 5){
            if(s > old)
                scores[a].first = s;
        }else{
            scores[a].first = 0;
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += scores[i].first;
    }

    cout << sum << endl;
}