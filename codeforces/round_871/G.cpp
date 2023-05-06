#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    constexpr int N = 2023;
    vector<vector<int64_t>> pref(N+1,vector<int64_t>(N+1));
    vector<pair<int,int>> mp(3e6+1);
    int64_t k = 1;
    
    for (int i=1; i<=N; ++i) {
        for (int row=i,col=1; row>=1 && col<=N; --row,++col) {
            pref[row][col] = k*k;
            mp[k] = {row,col};
            ++k;
        }
    }

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            pref[i][j] += pref[i][j-1];
        }
    }
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            pref[i][j] += pref[i-1][j];
        }
    }

    int t = 1; cin >> t;
    while(t--) {
        int64_t n; cin >> n;
        auto [i,j] = mp[n];
        cout << pref[i][j] << '\n';
    }
    return 0;
}

