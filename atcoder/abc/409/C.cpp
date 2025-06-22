#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L; cin >> N >> L;
    vector<int> freq(L+1, 0);
    freq[0] = 1;

    for (int i{}, pref_sum{}; i<N-1; ++i) {
        int d; cin >> d;
        pref_sum += d;
        pref_sum %= L;
        ++freq[pref_sum];
    }
    vector<int> points;
    for (int i{}; i<L; ++i) {
        if (freq[i] > 0) {
            points.emplace_back(i);
        }
    }
    if (L%3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    int64_t ans {};
    int d {L/3};
    for (int i{}; i<(int)points.size(); ++i) {
        int a {(points[i]+d)%L};
        int b {(points[i]+2*d)%L};
        int c {(points[i]+3*d)%L};
        if (freq[a] > 0 && freq[b] > 0 && freq[c] > 0) {
            ans += ((int64_t)freq[a]*freq[b]*freq[c]);
            freq[a] = freq[b] = freq[c] = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}

