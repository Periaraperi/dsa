#include <iostream>
#include <vector>
#include <iomanip>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    struct info {
        int count {};
        int sum {};
    };
    std::vector<info> v(m+1);

    for (int i{}; i<n; ++i) {
        std::cin >> a[i] >> b[i];
        ++v[a[i]].count;
        v[a[i]].sum += b[i];
    }

    for (int i{1}; i<=m; ++i) {
        std::cout << std::setprecision(20) << static_cast<long double>(v[i].sum)/static_cast<long double>(v[i].count) << '\n';
    }

    return 0;
}

