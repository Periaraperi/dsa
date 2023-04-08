#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        long long n,m,k; cin >> n >> m >> k;
        long long lo = 1;
        long long hi = m;

        auto check = [](long long pillows, long long start_bed, long long n, long long total_pillows) -> bool {
            total_pillows -= pillows;
            long long beds_left = start_bed-1;
            if (beds_left>0) {
                long long a = max(1LL,pillows-1);
                if (a>=beds_left) {
                    long long b = a-beds_left;
                    total_pillows -= ((a*(a+1)/2) - (b*(b+1)/2)); // pillows-i, pillows-i+1, pillows-i+2 ... pillows-1
                } else {
                    total_pillows -= ((a*(a+1)/2) + (beds_left-a)); // 1 1 1 1 1 2 3 4 5 ... pillows-1
                }
            }
            long long beds_right = n-start_bed;
            if (beds_right>0) {
                long long a = max(1LL,pillows-1);
                if (a>=beds_right) {
                    long long b = a-beds_right;
                    total_pillows -= ((a*(a+1)/2) - (b*(b+1)/2));
                } else {
                    total_pillows -= ((a*(a+1)/2) + (beds_right-a));
                }
            }
            return total_pillows>=0;
        };

        while (lo<=hi) {
            long long mid = (lo+hi)/2;
            if (check(mid,k,n,m)) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}

