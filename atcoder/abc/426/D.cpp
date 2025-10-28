#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t {1}; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        struct info {
            int count {};
            int c {};
        };
        vector<info> v;
        for (int i{}; i<n; ) {
            int j {i+1};
            while (j<n && s[i]==s[j]) ++j;
            v.push_back({j-i, s[i]=='0'?0:1});
            i = j;
        }
        if (s.size()>1 && s.back()!=s[s.size()-1]) v.push_back({1, s.back()=='0'?0:1});
        const int m {static_cast<int>(v.size())};
        
        vector<int> pref_zero(m, 0);
        vector<int> pref_one(m, 0);
        for (int i{}; i<m; ++i) {
            if (i==0) {
                if (v[i].c==0) {
                    pref_zero[i] = v[i].count;
                }
                else {
                    pref_one[i] = v[i].count;
                }
                continue;
            }
            pref_zero[i] += pref_zero[i-1];
            pref_one[i] += pref_one[i-1];
            if (v[i].c==0) pref_zero[i] += v[i].count;
            else pref_one[i] += v[i].count;
        }

        constexpr int INF {numeric_limits<int>::max()};
        int ans {INF};

        for (int i{0}; i<m; ++i) {
            // fix i-th block
            int l {i-1}; // sum in prefix
            int r {i}; // sum in suffix
            int a {INF}, b {INF};

            if (v[i].c==0) {
                if (l>=0) {
                    a = pref_one[l] + 2*pref_zero[l];
                }
                else a = 0;

                a += (2*(pref_zero[m-1]-pref_zero[r]) + (pref_one[m-1]-pref_one[r]));
            }
            else {
                if (l>=0) {
                    b = 2*pref_one[l] + pref_zero[l];
                } 
                else b = 0;
                b += ((pref_zero[m-1]-pref_zero[r]) + 2*(pref_one[m-1]-pref_one[r]));
            }
            
            ans = min(ans, min(a, b));
        }

        cout << ans << '\n';
    }
    return 0;
}

/*
    110010111100101 
    2   124   4 121
    2+1+2+4+4+1+2+1 = 17
simply choosing 1 or 0 based on their frequency won't work, since we can't take from middle.

idea 1 - try to get all 0s and then all 1s and choose min.
        Problem: how to simulate fast?

observation 1

if we want to achieve all 1s, and have [111111][0000][1111][0000][11111]
we need to make the rightmost or leftmost range of all 1s into 0s first and then back to 1s.
Because we need to "get to" 0s in the middle to flip them.

do this thingy from left to right and then from right to left when "fixing" for 1.
do same thingy but fix 0.


[00][11][0][1][0][111111][0000][1111][0000][11111]
(2, 0) (2, 1) (1, 0) (1, 1) (1, 0) (6, 1) (4, 0) (4, 1) (4, 0) (5, 1)
 

001101011111100001111000011111
*/

