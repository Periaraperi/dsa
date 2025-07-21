#include <iostream>
#include <numeric>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;

        vector<int> x(n), y(n);
        iota(x.begin(), x.end(), 1);
        iota(y.begin(), y.end(), 1);
        vector<int> ans_a;
        vector<int> ans_b;

        if (a+b > n) {
            cout << "NO\n";
        }
        else {
            int s {};
            for (int i{}; i<n-(a+b); ++i) {
                ans_a.push_back(i+1);
                ans_b.push_back(i+1);
                ++s;
            }
            for (int i{n-1}, j{a}, k{}; k<a && i>=0; --i, ++k, --j) {
                ans_a.push_back(x[i]);
                ans_b.push_back(y[s+j-1]);
            }
            for (int i{n-1}, j{b}, k{}; k<b && i>=0; --i, ++k, --j) {
                ans_a.push_back(x[s+j-1]);
                ans_b.push_back(y[i]);
            }

            int aa{}, bb{};
            for (int i{}; i<n; ++i) {
                if (ans_a[i] < ans_b[i]) ++bb;
                if (ans_a[i] > ans_b[i]) ++aa;
            }
            if (aa != a || bb != b) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                for (const auto& i:ans_a) {
                    cout << i << " ";
                }
                cout << '\n';
                for (const auto& i:ans_b) {
                    cout << i << " ";
                }
                cout << '\n';
            }
        }
    }
    return 0;
}

