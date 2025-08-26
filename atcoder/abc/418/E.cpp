#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    struct point { // acts both as point and as slope
        point() = default;
        point(int xx, int yy): x{xx}, y{yy} {}
        int x{};
        int y{};
        bool operator<(const point& other)
        {
            if (x == other.x) {
                return y < other.y;
            }
            return x < other.x;
        }
    };
    vector<point> points(n);
    for (auto& [x, y]:points) {
        cin >> x >> y;
    }

    vector<point> slopes; slopes.reserve(n*n);
    vector<point> midpoints; midpoints.reserve(n*n); // will store xi+xj and yi+yj without div by 2

    for (int i{}; i<n; ++i) {
        for (int j{i+1}; j<n; ++j) {
            auto dx {points[i].x-points[j].x};
            auto dy {points[i].y-points[j].y};
            const auto g {std::gcd(dx, dy)}; // store slope as simplest fraction. Simplest fraction will be unique for different slopes
            dx /= g;
            dy /= g;
            // 2 vectors are still parallel even though they face different directions (rot 180 deg)
            // y/x must be treated the same as -y/-x
            // y/-x must be treated the same as -y/x
            // if either x or y is 0 treat other as positive
            if (dx == 0 && dy < 0) dy *= -1;
            if (dy == 0 && dx < 0) dx *= -1;
            if ((dx < 0 && dy > 0) || (dx < 0 && dy < 0)) {
                dx *= -1;
                dy *= -1;
            }
            slopes.emplace_back(dx, dy);
            midpoints.emplace_back(points[i].x+points[j].x, points[i].y+points[j].y);
        }
    }

    // sort so that same values are adjacent
    sort(slopes.begin(), slopes.end());
    sort(midpoints.begin(), midpoints.end());
    int64_t ans{};
    for (int i{}; i<(int)slopes.size(); ++i) {
        int64_t running_count{1};
        while (i<(int)slopes.size()-1 && slopes[i].x==slopes[i+1].x && slopes[i].y==slopes[i+1].y) {
            ++running_count;
            ++i;
        }
        ans += (running_count*(running_count-1) / 2);
    }

    // remove double counted parallelograms
    for (int i{}; i<(int)midpoints.size(); ++i) {
        int64_t running_count{1};
        while (i<(int)midpoints.size()-1 && midpoints[i].x==midpoints[i+1].x && midpoints[i].y==midpoints[i+1].y) {
            ++running_count;
            ++i;
        }
        ans -= (running_count*(running_count-1) / 2);
    }
    cout << ans << '\n';

    return 0;
}

