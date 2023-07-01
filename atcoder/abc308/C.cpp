#include <bits/stdc++.h>
 
using namespace std;

struct Item {
	int64_t a,b;
	int id;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
		int n; cin >> n;
		vector<Item> v(n);
		for (int i=0; i<n; ++i) {
			cin >> v[i].a >> v[i].b;
			v[i].b += v[i].a;
			v[i].id = i+1;
		}

		auto cmp = [](const Item& x, const Item& y) -> bool {
			auto l = x.a*y.b;
			auto r = x.b*y.a;
			if (l==r) {
				return x.id<y.id;
			}
			return l>r;
		};
		sort(v.begin(),v.end(),cmp);
		for (int i=0; i<n; ++i) {
			cout << v[i].id << " ";
		}
		cout << '\n';

    }
    return 0;
}

