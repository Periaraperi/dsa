#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n,k,q; cin >> n >> k >> q;

        multiset<int> upper,lower;
        vector<int> v(n+1);
        int64_t running_sum = 0;
        for (int i=0; i<k; ++i) {
            upper.insert(0);
        }
        for (int i=k; i<n; ++i) {
            lower.insert(0);
        }

        while (q--) {
            int x,y; cin >> x >> y;

            auto it = upper.find(v[x]);
            if (it!=upper.end()) {
                int val = *it;
                if (y>=val || lower.empty()) {
                    running_sum += (y-val);
                    upper.erase(it);
                    upper.insert(y);
                } else {
                    auto it2 = --lower.end();
                    int biggest_lower = *it2;
                    if (y>=biggest_lower) {
                        running_sum += (y-val);
                        upper.erase(it);
                        upper.insert(y);
                    } else {
                        lower.erase(it2);
                        upper.erase(it);
                        lower.insert(y);
                        upper.insert(biggest_lower);
                        running_sum += (biggest_lower-val);
                    }
                }
            } else {
                it = lower.find(v[x]);
                int val = *it;
                if (y<=val) {
                    lower.erase(it);
                    lower.insert(y);
                } else {
                    auto it2 = upper.begin();
                    int smallest_upper = *it2;
                    if (y<=smallest_upper) {
                        lower.erase(it);
                        lower.insert(y);
                    } else {
                        lower.erase(it);
                        upper.erase(it2);
                        lower.insert(smallest_upper);
                        upper.insert(y);
                        running_sum += (y-smallest_upper);
                    }
                }
            }
            v[x] = y;
            cout << running_sum << '\n';
        }
    }
    return 0;
}

