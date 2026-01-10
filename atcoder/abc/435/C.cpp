#include <iostream>
#include <vector>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> v(n), u(n);
    for (int i{}; i<n; ++i) {
        std::cin >> v[i];
        u[i] = i+v[i]-1;
    }
    int mx {};
    int r {};
    for (int i{}; i<n; ) {
        r = std::max(u[i], mx);
        if (r >= n) {
            r = n-1;
            break;
        }
        for (int j{i}; j<=r; ++j) {
            mx = std::max(mx, u[j]);
        }
        if (mx == r) break;
        i = u[i];
    }
    std::cout << r+1 << '\n';
    return 0;
}

