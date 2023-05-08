#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        int type_1 = 0;
        int type_2 = 0;
        vector<int> type_3;
        vector<bool> vis(m+1);
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            if (a>0 && !vis[a]) {
                type_3.push_back(a);
                vis[a] = true;
            }
            if (a==-1) ++type_1;
            if (a==-2) ++type_2;
        }
        sort(type_3.begin(),type_3.end());
        int ans = 0;
        // note that we can swap seats of type3 with other types, if they are contiguous
        for (int i=0; i<type_3.size(); ++i) { // fixing one type3 first
            int loc = 1;
            int to_left = type_3[i]-1;
            int to_right = m-type_3[i];
            loc += min(to_left,i+type_1);
            loc += min(to_right,(int)type_3.size()-(i+1)+type_2);
            ans = max(ans,loc);
        }

        // check if we start with type1
        {
            int x = min(type_1,m);
            ans = max(ans,min(m,x+(int)type_3.size()));
        }
        // check if we start with type2
        {
            int x = min(type_2,m);
            ans = max(ans,min(m,x+(int)type_3.size()));
        }
        cout << ans << '\n';
    }
    return 0;
}

