#include <bits/stdc++.h>
 
using namespace std;
 
// think in terms of sub arrays
// if next is '1' how many ends in 0 before me
// if next is '0' reset, in any case ends in 1

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n);
    for (int i=0; i<n; ++i) 
        v[i] = s[i]-'0';

    auto ans = accumulate(v.begin(),v.end(),0LL);
    int64_t one = 0;
    int64_t zero = 0;
    if (v[0]==1) one = 1;
    else zero = 1;
    
    for (int i=1; i<n; ++i) {
        if (v[i]==0) {
            ans += i; // number of subarrays from [0,i-1]
            zero = 1;
            one = i;
        } else {
            ans += zero;
            zero = one;
            one = (i+1)-zero;
        }
    }
    cout << ans << '\n';
    return 0;
}

