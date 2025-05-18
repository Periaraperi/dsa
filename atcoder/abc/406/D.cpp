#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> t_x(H+1, vector<int>());
    vector<vector<int>> t_y(W+1, vector<int>());
    vector<int> cnt_x(H+1, 0);
    vector<int> cnt_y(W+1, 0);
    for (int i{}; i<N; ++i) {
        int x, y; cin >> x >> y;
        t_x[x].push_back(y);
        t_y[y].push_back(x);
        ++cnt_x[x];
        ++cnt_y[y];
    }

    int Q; cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        if (a == 1) {
            cout << cnt_x[b] << '\n';
            for (const auto& i:t_x[b]) {
                cnt_y[i] = max(0, cnt_y[i]-1);
            }
            t_x[b].clear();
            cnt_x[b] = 0;
        }
        else {
            cout << cnt_y[b] << '\n';
            for (const auto& i:t_y[b]) {
                cnt_x[i] = max(0, cnt_x[i]-1);
            }
            t_y[b].clear();
            cnt_y[b] = 0;
        }
    }

    return 0;
}

