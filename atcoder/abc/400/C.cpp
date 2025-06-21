#include <cstdint>
#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t N; cin >> N;
    int64_t ans{};

    for (int64_t a : {1, 2}) {
        for (int64_t b{1}; (1LL<<a)*b*b <= N; ++b) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}
