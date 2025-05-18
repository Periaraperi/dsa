#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<int64_t> v;
    for (int64_t i=1; i<=36; ++i) {
        v.push_back(9*std::pow(10, (i+1)/2 - 1));
    }

    ++v[0]; // because of 0
    for (int64_t i=1; i<=36; ++i) {
        cout << i << ": " << v[i-1] << '\n';
    }

    std::vector<int64_t> ps(v.size()+1);
    std::cout << "PREFIX\n";
    for (int64_t i=1; i<=36; ++i) {
        ps[i] = ps[i-1]+v[i-1];
        cout << i << ": " << ps[i] << '\n';
    }

    const auto num = 79972799729;
    const auto it = std::lower_bound(ps.cbegin(), ps.cend(), static_cast<int64_t>(79972799729));
    //const auto it = std::lower_bound(ps.cbegin(), ps.cend(), static_cast<int64_t>(1e18));
    const auto index = it - ps.begin(); // answer will have index number of digits
    std::cout << index << '\n';

    std::cout << ps[index] - ps[index-1] << '\n';

    const auto pos = num - ps[index-1]; // answer is number 'pos' in all 'index' digited numbers
    std::cout << pos << '\n';
    
    const auto half = (index%2 == 1) ? index/2 + 1 : index/2;

    // ans is 21 digits long -> [1][0][0][0][0][0][0][0][0][0]
    // 59972799730
    return 0;
}
