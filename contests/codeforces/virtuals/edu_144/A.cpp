#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    constexpr int N = 1e3;
    string S;
    for (int i=1; i<=N; ++i) {
        if (i%3==0) S.push_back('F');
        if (i%5==0) S.push_back('B');
    }
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (S.find(s)!=string::npos) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}

