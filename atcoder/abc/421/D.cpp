#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int rt, ct, ra, ca; cin >> rt >> ct >> ra >> ca;
    int64_t n; cin >> n;
    int m, l; cin >> m >> l;
    struct info {
        char dir{};
        int k{};
    };
    vector<info> t(m);
    vector<info> a(l);
    for (auto& [c, k]:t) cin >> c >> k;
    for (auto& [c, k]:a) cin >> c >> k;

    vector<info> vt, va;
    vt.reserve(m+l); va.reserve(m+l);
    {
        int i{}, j{};
        while (i<m && j<l) {
            const auto x {min(t[i].k, a[j].k)};
            vt.push_back({t[i].dir, x});
            va.push_back({a[j].dir, x});
            t[i].k -= x;
            a[j].k -= x;
            if (t[i].k == 0) ++i;
            if (a[j].k == 0) ++j;
        }
        while (i<m) {
            vt.push_back({t[i].dir, t[i].k});
            ++i;
        }
        while (j<l) {
            va.push_back({a[j].dir, a[j].k});
            ++j;
        }
    }

    struct cell {
        int64_t r{};
        int64_t c{};
    };

    struct range {
        int64_t l{};
        int64_t r{};
    };

    auto get_dir = [](char c) -> cell {
        if (c == 'U') return {-1, 0};
        if (c == 'D') return { 1, 0};
        if (c == 'L') return { 0,-1};
        if (c == 'R') return { 0, 1};
        return {};
    };

    auto opposite_dir = [](char c1, char c2) -> bool {
        return (c1 == 'U' && c2 == 'D') || 
               (c1 == 'D' && c2 == 'U') || 
               (c1 == 'L' && c2 == 'R') || 
               (c1 == 'R' && c2 == 'L');
    };

    auto sort_range_bounds = [](range& rn) {
        if (rn.l > rn.r) swap(rn.l, rn.r);
    };

    auto overlaps = [](const range& r1, const range& r2) {
        return (r1.l <= r2.r && r2.l <= r1.r);
    };

    int64_t ans{};
    int N {(int)vt.size()}; // vt.size() == va.size()
    // current cells
    cell taka {rt, ct};
    cell aoki {ra, ca};
    for (int i{}; i<N; ++i) {
        const auto d_taka {get_dir(vt[i].dir)};
        const auto d_aoki {get_dir(va[i].dir)};

        if (vt[i].dir == va[i].dir) {
            if (taka.r == aoki.r && taka.c == aoki.c) {
                ans += vt[i].k;
            }
        }
        // will meet at most 1 times if on same row or column and ranges overlap and range len is odd
        else if (opposite_dir(vt[i].dir, va[i].dir)) {
            range range_taka {-1, -1};
            range range_aoki {1, 1};
            int64_t len{};
            if (!(taka.r == aoki.r && taka.c == aoki.c)) {
                if (taka.r == aoki.r) {
                    range_taka.l = taka.c;
                    range_taka.r = taka.c+vt[i].k*get_dir(vt[i].dir).c;

                    range_aoki.l = aoki.c;
                    range_aoki.r = aoki.c+va[i].k*get_dir(va[i].dir).c;
                    len = abs(taka.c-aoki.c) + 1;
                }
                else if (taka.c == aoki.c) {
                    range_taka.l = taka.r;
                    range_taka.r = taka.r+vt[i].k*get_dir(vt[i].dir).r;

                    range_aoki.l = aoki.r;
                    range_aoki.r = aoki.r+va[i].k*get_dir(va[i].dir).r;
                    len = abs(taka.r-aoki.r) + 1;
                }
                sort_range_bounds(range_taka);
                sort_range_bounds(range_aoki);
                if ((len%2 == 1) && overlaps(range_taka, range_aoki)) ++ans;
            }
        }
        else {
            range range_taka_r {taka.r, taka.r+vt[i].k*d_taka.r};
            range range_taka_c {taka.c, taka.c+vt[i].k*d_taka.c};
            range range_aoki_r {aoki.r, aoki.r+va[i].k*d_aoki.r};
            range range_aoki_c {aoki.c, aoki.c+va[i].k*d_aoki.c};
            sort_range_bounds(range_taka_r);
            sort_range_bounds(range_taka_c);
            sort_range_bounds(range_aoki_r);
            sort_range_bounds(range_aoki_c);
            bool rows {overlaps(range_taka_r, range_aoki_r)};
            bool cols {overlaps(range_taka_c, range_aoki_c)};
            bool good_angle {abs(taka.r-aoki.r) == abs(taka.c-aoki.c)};
            if (rows && cols && good_angle && !(taka.r==aoki.r && taka.c==aoki.c)) ++ans;
        }

        taka.r += vt[i].k*d_taka.r;
        taka.c += vt[i].k*d_taka.c;
        aoki.r += va[i].k*d_aoki.r;
        aoki.c += va[i].k*d_aoki.c;
    }

    cout << ans << '\n';
    return 0;
}

