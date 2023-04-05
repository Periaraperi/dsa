#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto&& i:v) cin >> i;
        vector<int> ans(n);
        // for subseq of length k we choose last k elems
        // if we add 1 more element, i.e. we extend suffix
        // cost will update by (new element)/(new length), i.e. cost *= (newelem/newlen)
        // since we are decreasing from right to left, division will result in <1
        // so while division results >= 1, we add those elems to suffix
        // for each prefix we binary search leftmost division which results in 1
        for (int i=0; i<n; ++i) {
            int l = 0;
            int r = i; 
            int len = r-l+1;
            while (l<=r) {
                int m = (l+r)/2;
                // in this prefix of length len, m-th element will be divided by len-m
                if (v[m]/(len-m)>=1) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            ans[i] = len-l;
        }
        for (auto i:ans) cout << i << " ";
        cout << '\n';
    }
    return 0;
}

