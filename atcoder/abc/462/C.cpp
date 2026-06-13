#include <iostream>
#include <vector>
#include <algorithm>

struct point {
    int x {};
    int y {};
};
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<point> p(n);
    for (auto& [x, y]:p) {
        std::cin >> x >> y;
    }
    std::sort(p.begin(), p.end(), [](const point& a, const point b) {return a.x < b.x;});
    int min_y {1000000};
    int count {};
    for (int i{}; i<n; ++i) {
        if (min_y > p[i].y) { ++count; }
        min_y = std::min(min_y, p[i].y);
    }
    std::cout << count << '\n';

    return 0;
}

