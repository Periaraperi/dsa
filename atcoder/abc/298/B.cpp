#include <bits/stdc++.h>
 
using namespace std;
 
void rotate(vector<vector<int>>& a)
{
    int N = (int)a.size();
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> a(n,vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> b(n,vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> b[i][j];
            }
        }

        auto check = [nn=n](const auto& aa, const auto& bb) -> bool {
            for (int i=0; i<nn; ++i) {
                for (int j=0; j<nn; ++j) {
                    if (aa[i][j]==1) {
                        if (bb[i][j]!=1) {
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        bool ok = false;
        for (int k=0; k<4; ++k) {
            if (check(a,b)) {
                ok = 1;
                break;
            }
            rotate(a);
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

