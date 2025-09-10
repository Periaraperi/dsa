#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

struct fenwick {
    explicit fenwick(int n)
        :v(vector<int>(n+1, 0))
    {}

    void update(int i, int increment) // adds 'increment' to i-th cell and all ranges that correspond to i
    {
        while(i <= static_cast<int>(v.size())-1) {
            v[i] += increment;
            i += (i&-i);
        }
    }

    [[nodiscard]]
    int64_t query(int i) // sum from [0, i]
    {
        int64_t sum {};
        while(i > 0) {
            sum += v[i];
            i -= (i&-i);
        }
        return sum;
    }

private:
    vector<int> v;
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    
    const int MAX {m+2};
    fenwick inversions{MAX};
    int64_t total_inversions{};

    // each fenwick tree will operate on values from [1, m] instead of [0, m-1] to work around special 0 index in fenwick tree
    // basically increase all diff_array values and input list values by 1 when storing in fenwick

    for (const auto& i:a) {
        const auto count_more_than_i {inversions.query(MAX)-inversions.query(i+1)};
        total_inversions += count_more_than_i;
        inversions.update(i+1, 1);
    }

    vector<int64_t> ans(m);
    ans[0] = total_inversions;

    vector<int> diff_array(a); // for each element store minimum k, such that elem becomes 0.
    for (auto& i:diff_array) i = m-i;
    vector<int> diff_array_rev(diff_array);
    reverse(diff_array_rev.begin(), diff_array_rev.end());

    fenwick left(MAX);
    fenwick right(MAX);
    // diff arrays never contain 0 so incrementing by 1 for fenwick is not necessary

    for (int i{}; i<n; ++i) {
        if (diff_array[i] < m) {
            const auto more_than_i_left {left.query(MAX)-left.query(diff_array[i])};
            const auto less_than_i_left {left.query(diff_array[i]-1)};
            ans[diff_array[i]] -= (more_than_i_left+less_than_i_left);
        }
        if (diff_array_rev[i] < m) {
            const auto more_than_i_right {right.query(MAX)-right.query(diff_array_rev[i])};
            const auto less_than_i_right {right.query(diff_array_rev[i]-1)};
            ans[diff_array_rev[i]] += (more_than_i_right+less_than_i_right);
        }
        left.update(diff_array[i], 1);
        right.update(diff_array_rev[i], 1);
    }

    for (int i{1}; i<m; ++i) {
        ans[i] = ans[i-1]-ans[i];
    }

    for (const auto& i:ans) {
        cout << i << '\n';
    }

    return 0;
}

