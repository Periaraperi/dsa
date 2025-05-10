#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int64_t> v(N);
    vector<int64_t> pref_sum(N+1, 0);

    for (int i{}; i<N; ++i) {
        cin >> v[i];
        pref_sum[i+1] = pref_sum[i] + v[i];
    }

    int64_t ans{};
    for (int i{}; i<N; ++i) {
        ans += (v[i]*(pref_sum[N]-pref_sum[i+1]));
    }
    cout << ans << '\n';

    return 0;
}

