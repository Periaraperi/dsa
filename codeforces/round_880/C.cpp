#include <bits/stdc++.h>
 
using namespace std;
 
int pp(int x, int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    return x*pp(x,y-1);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int A,B,C; cin >> A >> B >> C;
        int64_t k; cin >> k;
        int min_a = pp(10,A-1);
        int max_a = pp(10,A)-1;
        bool ok = false;
        for (int a=min_a; a<=max_a; ++a) {
            int min_b = max(pp(10,C-1)-a,pp(10,B-1));
            int max_b = min(pp(10,B)-1,pp(10,C)-1-a);
            if (min_b>max_b) continue;
            int64_t eq_count = max_b-min_b+1;
            if (eq_count>=k) {
                ok = true;
                cout << a << " + " << min_b+k-1 << " = " << a+min_b+k-1 << '\n';
                break;
            }
            k -= eq_count;
        }
        if (!ok) {
            cout << -1 << '\n';
        }
    }
    return 0;
}

