#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int64_t> freq(n+1, 0);
    for (int i{}; i<m; ++i) {
        int a, b; cin >> a >> b;
        ++freq[(a+b)%n];
    }

    int64_t parallels {};
    for (int i{}; i<=n; ++i) {
        if (freq[i] > 0) {
            parallels += (freq[i]*(freq[i]-1)/2);
        }
    }

    cout << (int64_t)m*(m-1) / 2 - parallels << '\n';
    return 0;
}
