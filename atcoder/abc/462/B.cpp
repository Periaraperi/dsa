#include <iostream>
#include <set>
#include <vector>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::set<int>> v(n+1);
    for (int i{}; i<n; ++i) {
        int k; std::cin >> k;
        for (int j{}; j<k; ++j) {
            int x; std::cin >> x; --x;
            v[x].insert(i);
        }
    }
    for (int i{}; i<n; ++i) {
        std::cout << v[i].size() << " ";
        for (const auto& j:v[i])
            std::cout << j+1 << " ";
        std::cout << '\n';
    }
    return 0;
}

