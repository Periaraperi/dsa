#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        string str; cin >> str;
        stack<pair<char,int>> stk, stk2;

        for (int i=0; i<n; ++i) {
            if (str[i]>='a' && str[i]<='z') {
                stk2.push({str[i],i});
                continue;
            }

            if (stk.empty()) stk.push({str[i],i});
            else {
                if (stk.top().first=='(' && str[i]==')') {
                    int l = stk.top().second;
                    stk.pop();
                    while (!stk2.empty() && stk2.top().second>l && stk2.top().second<i) {
                        stk2.pop();
                    }
                } else {
                    stk.push({str[i],i});
                }
            }
        }
        
        vector<int> vv;
        while (!stk.empty()) {
            vv.push_back(stk.top().second);
            stk.pop();
        }
        while (!stk2.empty()) {
            vv.push_back(stk2.top().second);
            stk2.pop();
        }
        sort(vv.begin(),vv.end());

        string ans = "";
        for (int i=0; i<(int)vv.size(); ++i) ans += str[vv[i]];
        cout << ans << '\n';
    }
    return 0;
}

