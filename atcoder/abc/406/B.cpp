#include <cstdint>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; cin >> N >> K;
    vector<uint64_t> v(N);
    for (auto& i:v) cin >> i;

    auto digits = [](uint64_t x) {
        int counter {};
        while (x > 0) {
            x /= 10;
            ++counter;
        }
        return counter;
    };

    uint64_t x {1};

    for (const auto& i:v) {
        auto cnt_x {digits(x)};
        auto cnt_i {digits(i)};
        if (cnt_x+cnt_i-1>K) {
            x = 1;
            continue;
        }
        x *= i;
        if (cnt_x+cnt_i>K && digits(x) > K) {
            x = 1;
            continue;
        }
    }
    cout << x << '\n';

    return 0;
}

