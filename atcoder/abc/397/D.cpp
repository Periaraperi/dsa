#include <cmath>
#include <cstdint>
#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N; cin >> N;
    for (int64_t i{1}; i*i*i<=N; ++i) {
        if (N%i == 0) {
            const auto d1 {i};
            const auto d2 {N/i};
            //3b^2 + 3d1b + (d1^2-d2) = 0
            const auto A {3};
            const auto B {3*d1};
            const auto C {static_cast<uint64_t>(d2-d1*d1)}; // flip because C is always negative
            const auto D {B*B+4*A*C}; // turn - to + because C is negative, and we flipped it above. Need to not overflow.
            const auto d {static_cast<uint64_t>(sqrt(D))};
            if (d*d == D) {
                if ((-B+d)%(2*A) == 0) {
                    const auto b {(-B+d)/(2*A)};
                    const auto a {d1+b};
                    if (a>0 && b>0 && a>b) {
                        cout << a << " " << b << '\n';
                        return 0;
                    }
                }
                if ((-B-d)%(2*A) == 0) {
                    const auto b {(-B-d)/(2*A)};
                    const auto a {d1+b};
                    if (a>0 && b>0 && a>b) {
                        cout << a << " " << b << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << '\n';

    return 0;
}
