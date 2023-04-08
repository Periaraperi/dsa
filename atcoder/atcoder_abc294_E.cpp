#include <bits/stdc++.h>
 
using namespace std;
 
struct Range {
    long long val,l,r;
    friend ostream& operator<<(ostream& os, const Range& rng) 
    {
        return os << "{ " << rng.val << " [" << rng.l << " " << rng.r << "] }";  
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        long long L; cin >> L;
        int N1, N2; cin >> N1 >> N2;
        vector<pair<long long, long long>> v1(N1);
        vector<pair<long long, long long>> v2(N2);
        for (auto& [l,r]:v1) cin >> l >> r;
        for (auto& [l,r]:v2) cin >> l >> r;

        auto check_range = [](const Range& a, const Range& b) -> bool {
            if (a.l>b.r || b.l>a.r) return false;
            return true;
        };

        int i=0,j=0;
        Range rng1 = {-1LL,0LL,0LL}; bool rng1_changed = true;
        Range rng2 = {-1LL,0LL,0LL}; bool rng2_changed = true;
        long long ans = 0;
        while (i<N1 && j<N2) {
            //cout << " i,j " << i << " " << j << '\n';
            if (rng1_changed) {
                rng1.val = v1[i].first;
                rng1.l = (rng1.r+1);
                rng1.r = rng1.l+v1[i].second-1;
            }
            //cout << rng1 << '\n';
            if (rng2_changed) {
                rng2.val = v2[j].first;
                rng2.l = (rng2.r+1);
                rng2.r = rng2.l+v2[j].second-1;
            }
            //cout << rng2 << '\n';

            if (rng1.val==rng2.val) {
                if (!check_range(rng1,rng2)) {
                    if (rng1.r<rng2.r) {++i; rng1_changed = true; rng2_changed = false;}
                    else {++j; rng2_changed = true; rng1_changed = false;}
                } else {
                    if (rng1.l>=rng2.l && rng1.r<=rng2.r) {
                        ans += (rng1.r-rng1.l+1);
                        ++i;
                        rng1_changed = true; rng2_changed = false;
                    } else if (rng2.l>=rng1.l && rng2.r<=rng1.r) {
                        ans += (rng2.r-rng2.l+1);
                        ++j;
                        rng2_changed = true; rng1_changed = false;
                    } else { // partial overlap
                        if (rng1.r>rng2.l && rng1.r<rng2.r) {
                            ans += (rng1.r-rng2.l+1);    
                            ++i;
                            rng1_changed = true; rng2_changed = false;
                        } else if (rng1.l>rng2.l && rng1.l<rng2.r) {
                            ans += (rng2.r-rng1.l+1);
                            ++j;
                            rng2_changed = true; rng1_changed = false;
                        }
                    }
                }
            } else { // no equal values
                if (rng1.r<rng2.r) {++i; rng1_changed = true; rng2_changed = false;}
                else               {++j; rng2_changed = true; rng1_changed = false;}
            }

            //cout << ans << "\n";
        }
        cout << ans << '\n';

    }
    return 0;
}

