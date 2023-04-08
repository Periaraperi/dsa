#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& v, int i, int green, int blue, long long h) 
{
    if (i==(int)v.size()) return 0;
    
    if (v[i]<h) {
        return 1+solve(v,i+1,green,blue,h+v[i]/2);
    }
    int a = 0;
    int b = 0;
    if (green>0) a = solve(v,i,green-1,blue,h*2);
    if (blue>0) b = solve(v,i,green,blue-1,h*3);
    return max(a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        int n;
        long long h;
        cin >> n >> h;
        vector<int> v(n);
        for (auto& i:v) {
            cin >> i;
        }
        sort(v.begin(),v.end());
        int green = 2, blue = 1;
        int ans = 0;
        ans = solve(v,0,green,blue,h);
        cout << ans << '\n';
    }

    return 0;
}