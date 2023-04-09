#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        auto cc = [=](int x, int y) -> int {
            int cnt = 4;
            if (x-1<1 || x+1>n) --cnt;
            if (y-1<1 || y+1>m) --cnt;
            return cnt;
        };
        auto a = cc(x1,y1);
        auto b = cc(x2,y2);
        cout << min(a,b) << '\n';
    }
    return 0;
}

