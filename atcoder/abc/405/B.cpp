#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    vector<int> a(N);
    vector<int> freq(M+1, 0);

    for (auto& i:a) {
        cin >> i;
        ++freq[i];
    }

    auto check = [&]() {
        for (int i{1}; i<=M; ++i) {
            if (freq[i] == 0) {
                return false;
            }
        }
        return true;
    };

    int ans {};
    int j {(int)a.size() - 1};
    while (check()) {
        --freq[a[j]];
        --j;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}

