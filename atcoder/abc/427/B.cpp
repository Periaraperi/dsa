#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    auto f = [](int m) {
        int sm {};
        while (m>0) {
            sm += (m%10);
            m /= 10;
        }
        return sm;
    };

    vector<int> v(n+1, 0);
    v[0] = 1;

    for (int i{1}; i<=n; ++i) {
        int s {};
        for (int j{}; j<=i; ++j) {
            s += f(v[j]);
        }
        v[i] = s;
    }
    cout << v[n] << '\n';
    return 0;
}

