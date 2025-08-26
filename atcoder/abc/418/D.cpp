#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pref_parity(n+1, 0); // parity of zeroes in the i-th prefix
    for (int i{1}; i<=n; ++i) {
        pref_parity[i] += pref_parity[i-1];
        if (s[i-1] == '0') ++pref_parity[i];
    }
    // [l, r] is good if pref_parity[r] == pref_parity[l-1]
    // ans = number of distinct pairs (l-1, r) with same prefix parity
    int64_t zeroes{};
    int64_t ones{};
    for (int i{}; i<=n; ++i) {
        pref_parity[i] %= 2;
        if (pref_parity[i] == 0) ++zeroes;
        else ++ones;
    }
    cout << (zeroes*(zeroes-1))/2 + (ones*(ones-1))/2 << '\n'; // number of pairs = Nchoose2
    return 0;
}
