#include <bits/stdc++.h>
 
using namespace std;
 
/*
    reducing problem to smaller managable one,
    was kinda interesting  
*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        auto solve = [](int n, int k, vector<int>& ans) -> void { // solves when k<n
            for (int i=0; i<k-1; ++i) ans[i] = -1;
            if (k-1>=0) ans[k-1] = 100;
            ans[k] = -200;
            for (int i=k+1; i<n; ++i) ans[i] = -1;
        };

        vector<int> ans(n);
        if (k<n) {
            solve(n,k,ans);
        } else {
            int nn = n;
            int kk = k;
            int rec_count = 0;
            while (kk>=nn && nn>1) {
                kk -= nn;
                --nn;
                ++rec_count;
            }
            solve(nn,kk,ans);
            int i = n-1;
            while (rec_count--) {
                ans[i] = 1000;
                --i;
            }
        }
        for (auto i:ans) cout << i << " ";
        cout << '\n';

    }
    return 0;
}

