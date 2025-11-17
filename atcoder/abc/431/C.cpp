#include <iostream>
#include <vector>
#include <algorithm>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m);
    for (auto& i:a) std::cin >> i;
    for (auto& i:b) std::cin >> i;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int i {};
    int j {};
    int cnt {};
    while (i<n && j<m) {
        if (a[i] <= b[j]) {
            ++cnt;
            ++i;
            ++j;
        }
        else {
            ++j;
        }
    }
    if (cnt >= k) std::cout <<"Yes\n";
    else std::cout << "No\n";

    return 0;
}

