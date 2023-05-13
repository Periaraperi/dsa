#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        vector<int> freq_a(26), freq_b(26);
        set<char> st = {'a','t','c','o','d','e','r'};
        int cnt_a = 0, cnt_b = 0;
        int n = a.size();
        for (int i=0; i<n; ++i) {
            ++freq_a[a[i]-'a'];
            ++freq_b[b[i]-'a'];
            if (a[i]=='@') ++cnt_a;
            if (b[i]=='@') ++cnt_b;
        }

        bool ok = true;
        for (int i=0; i<26; ++i) {
            if (freq_a[i]!=freq_b[i]) {
                if (st.find('a'+i)==st.end()) {
                    ok = false;
                    break;
                } else {
                    if (freq_a[i]<freq_b[i]) {
                        int d = freq_b[i]-freq_a[i];
                        if (cnt_a<d) {
                            ok = false; 
                            break;
                        }
                        cnt_a -= d;
                    } else if (freq_a[i]>freq_b[i]) {
                        int d = freq_a[i]-freq_b[i];
                        if (cnt_b<d) {
                            ok = false; 
                            break;
                        }
                        cnt_b -= d;
                    }
                }
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}

