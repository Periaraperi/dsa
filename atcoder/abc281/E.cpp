#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int n,m,k; cin >> n >> m >> k;
        vector<int> v(n);
        for (auto& i:v) cin >> i;
        // split window in 2 multisets
        // one will store k-lowest elements
        // the other one will store rest of the elements in window
        multiset<int> k_lowest, upper;
        vector<int> starting_window = vector<int>(v.begin(),v.begin()+m);
        sort(starting_window.begin(),starting_window.end());
        long long running_sum = 0;
        for (int i=0; i<m; ++i) {
            if (i<k) {
                k_lowest.insert(starting_window[i]);
                running_sum += starting_window[i];
            } else upper.insert(starting_window[i]);
        }
        cout << running_sum << " ";

        int l = 1;
        int r = m;
        while (l<=r && r<n) {
            auto found = k_lowest.find(v[l-1]);
            if (found!=k_lowest.end()) {
                running_sum -= v[l-1];
                k_lowest.erase(found);
                if (!upper.empty()) {
                    auto first = upper.begin();
                    if (*first<v[r]) {
                        running_sum += *first;
                        k_lowest.insert(*first);
                        upper.erase(first);
                        upper.insert(v[r]);
                    } else {
                        running_sum += v[r];
                        k_lowest.insert(v[r]);
                    }
                } else {
                    running_sum += v[r];
                    k_lowest.insert(v[r]);
                }
            } else {
                upper.erase(v[l-1]);
                auto last_in_lowest = --k_lowest.end();
                if (v[r]<*last_in_lowest) {
                    running_sum -= *last_in_lowest;
                    running_sum += v[r];
                    upper.insert(*last_in_lowest);
                    k_lowest.erase(last_in_lowest);
                    k_lowest.insert(v[r]);
                } else {
                    upper.insert(v[r]);
                }
            }
            cout << running_sum << " ";
            ++l;
            ++r;
        }
        cout << '\n';
    }
    return 0;
}