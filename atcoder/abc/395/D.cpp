#include <iostream>
#include <set>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;

    vector<set<int>> sets(n+1); // actual nests where birds are inserted and removed
    vector<int> labels(n+1); // nest with label i points to some set
    vector<int> set_parent(n+1); // reverse of labels. set_parent[i] tells me which nest label points to set i
    vector<int> f(n+1); // set number in which bird resides in
    for (int i{1}; i<=n; ++i) {
        f[i] = i;
        set_parent[i] = i;
        labels[i] = i;
        sets[i].insert(i);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pigeon, nest; cin >> pigeon >> nest;
            const auto st_index_remove {f[pigeon]};
            sets[st_index_remove].erase(pigeon);
            const auto st_index_insert {labels[nest]};
            sets[st_index_insert].insert(pigeon);
            f[pigeon] = st_index_insert;
        }
        if (op == 2) {
            int nest_a, nest_b; cin >> nest_a >> nest_b;
            const auto s1 {labels[nest_a]};
            const auto s2 {labels[nest_b]};
            labels[nest_a] = s2;
            labels[nest_b] = s1;
            set_parent[s1] = nest_b;
            set_parent[s2] = nest_a;
        }
        if (op == 3) {
            int pigeon; cin >> pigeon;
            cout << set_parent[f[pigeon]] << '\n';
        }
    }
    
    return 0;
}

