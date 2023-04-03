#include <bits/stdc++.h>
 
using namespace std;

struct parabola_coefficients {
    long long a,b,c;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<long long> line_slopes(n);
        vector<parabola_coefficients> coef(m);
        for (auto& k:line_slopes) {
            cin >> k;
        }
        for (auto& [a,b,c]:coef) {
            cin >> a >> b >> c;
        }
        sort(line_slopes.begin(),line_slopes.end());
        for (auto [a,b,c]:coef) {
            // no intersection if slope lies between [b-sqrt(4ac),b+sqrt(4ac)]
            // take maximal slope <= b and minimal slope >= b
            // if either of these two satisfy (b-k)^2 < 4ac we are good
            
            int i = lower_bound(line_slopes.begin(),line_slopes.end(),b)-line_slopes.begin();
            if (i<n && (b-line_slopes[i])*(b-line_slopes[i])<4*a*c) {
                cout << "YES\n" << line_slopes[i] << '\n';
            } else if (i>0 && (b-line_slopes[i-1])*(b-line_slopes[i-1])<4*a*c) {
                cout << "YES\n" << line_slopes[i-1] << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

