/* Superlong Sums */
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n), s(n, 0);
    for (int i{}; i<n; ++i) {
        cin >> a[i] >> b[i];
    }

    int carry {};
    for (int i{n-1}; i>=0; --i) {
        int sm {a[i]+b[i]+carry};
        if (sm>9) carry = 1;
        else carry = 0;
        s[i] = sm%10;
    }
    if (carry==1) {
        s.insert(s.begin(), 1);
    }

    for (int i{}; i<static_cast<int>(s.size()); ++i) cout << s[i];
    cout << '\n';

    return 0;
}

