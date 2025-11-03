#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

/*

H(s) = s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ... + s[n-1]*p^(n-1)
     = SUM (s[i]*p^i) where 0<=i<=s.len-1
     since powers of p and sum may be very big, compute everything modulo M.

H(s) = (s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + s[3]*p^3 + ... + s[n-1]*p^(n-1)) mod M
     = SUM ((s[i]*p^i)mod M) where 0<=i<=s.len-1

p and M are some positive integers.
We want to minimize hash collisions, so take M as a large number.
2^64 (ull) is viable choice, but there exists mechanisms to break it
           and it is independent of choice of p.

In practice, p and M are usually prime numbers, because they give better results.
p is commonly around the size of alphabet

*/

// use ascii values for characters for now.
struct rolling_hash {
    rolling_hash(std::size_t max_len, int power, int64_t m_)
        :p(max_len+1), m{m_}
    {
        p[0] = 1LL;
        for (std::size_t i{1}; i<=max_len; ++i) {
            p[i] = (p[i-1]*power)%m;
        }
    }

    [[nodiscard]]
    static int char_value(unsigned char character) noexcept
    { return static_cast<int>(character)+1; }

    [[nodiscard]]
    int64_t compute_hash(const std::string& s) const noexcept 
    {
        // assert that we are only working with strings up to length = powers.size()
        if (s.size() > p.size()) return -1;

        int64_t hash {};
        for (std::size_t i{}; i<s.size(); ++i) {
            hash = (hash + p[i]*char_value(s[i]))%m;
        }
        return hash;
    }

private:
    vector<int64_t> p;
    const int64_t m {};
};

// search for duplicate strings in a list of strings.
[[nodiscard]]
vector<pair<string, int>> count_duplicates(const vector<string>& strs, const rolling_hash& rh)
{
    const int n {static_cast<int>(strs.size())};

    vector<pair<int64_t, std::size_t>> hashes; hashes.reserve(n);
    for (std::size_t i{}; i<strs.size(); ++i) {
        hashes.emplace_back(make_pair(rh.compute_hash(strs[i]), i));
    }

    // pair sorts by first (by default)
    sort(hashes.begin(), hashes.end()); // Don't sort strs, because we string comparison by default will be linear, so we will get
                                        // time complexity of O(n*log(n)*m), where n is length of list, and m is the length of largest string.
                                        // By getting their hashes, and sorting on hashes we remove extra (*m).
                                        // So we get O(n*m + n*log(n)) --> nlogn for sorting and n*m for hash precomputation (for iterating over each string).

    vector<pair<string, int>> ans; ans.reserve(256);
    for (int i{1}; i<n; ++i) {
        if (hashes[i].first == hashes[i-1].first) {
            ans.emplace_back(make_pair(strs[hashes[i].second], 1));
            while (i<n && hashes[i].first == hashes[i-1].first) {
                ++ans.back().second;
                ++i;
            }
        }
    }
    return ans;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rolling_hash rh {static_cast<size_t>(5e5), 31, static_cast<int64_t>(1e9+9)};
    
    vector<string> strs {"periaraperi", "laga", "laggert", "abc", "abacaba", "abc", 
                         "laga", "peria", "poyera", "abc", "laga", "poyera", "daba", "baba", "caba"};

    const auto dups {count_duplicates(strs, rh)};
    for (const auto& [s, count]:dups) {
        cout << s << " - " << count << '\n';
    }
    
    return 0;
}

