#include <iostream>
#include <vector>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr int x {2000};
    std::vector<std::vector<int64_t>> clouded(x+2, std::vector<int64_t>(x+2 , 0));
    std::vector<std::vector<int64_t>> clouded2(x+2, std::vector<int64_t>(x+2 , 0));

    struct info {
        int u, d, l, r; 
    };

    int n; std::cin >> n;
    std::vector<info> v(n);
    int k {1};
    for (auto& [u, d, l, r]:v) {
        std::cin >> u >> d >> l >> r;
        ++clouded[u][l];
        --clouded[u][r+1];
        --clouded[d+1][l];
        ++clouded[d+1][r+1];

        clouded2[u][l] += k;
        clouded2[u][r+1] -= k;
        clouded2[d+1][l] -= k;
        clouded2[d+1][r+1] += k;
        ++k;
    }

    for (int i{1}; i<=x; ++i) {
        for (int j{1}; j<=x; ++j) {
            clouded[i][j] += clouded[i][j-1];
            clouded2[i][j] += clouded2[i][j-1];
        }
    }
    for (int j{1}; j<=x; ++j) {
        for (int i{1}; i<=x; ++i) {
            clouded[i][j] += clouded[i-1][j];
            clouded2[i][j] += clouded2[i-1][j];
        }
    }

    std::vector<int64_t> a(n+2, 0); // a[0] = count of cells not covered at all. a[i] = cells covered only by i-th cloud
    for (int i{1}; i<=x; ++i) {
        for (int j{1}; j<=x; ++j) {
            if (clouded[i][j] == 0) ++a[0];
            if (clouded[i][j] == 1) ++a[clouded2[i][j]]; // since we have only 1 increment in clouded, only 1 cloud covers.
                                                         // so second grid will contain index of that cloud
        }
    }
    for (int i{1}; i<=n; ++i) {
        std::cout << a[0]+a[i] << '\n';
    }
    return 0;
}
