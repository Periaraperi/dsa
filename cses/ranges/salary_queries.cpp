#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int get_bucket_idx(int val)
{
    return (val-1)/100;
}

void update(int bucket, int N, int val ,vector<int>& fenwick)
{
    while(bucket<N) {
        fenwick[bucket] += val;
        bucket += (bucket&-bucket);
    }
}

int fen_sum(int idx, vector<int>& fenwick)
{
    int tot = 0;
    while(idx>0) {
        tot += fenwick[idx];
        idx -= (idx&-idx);
    }
    return tot;
}

int query(int l, int r, vector<int>& fenwick)
{
    return fen_sum(r,fenwick) - fen_sum(l-1,fenwick);
}

int brute_calc(int l, int r, map<int,int>& freq)
{
    int cnt = 0;
    auto it = freq.lower_bound(l);
    if(it==freq.end()) return cnt;
    while(it!=freq.end() && it->first<=r) {
        cnt += it->second;
        ++it;
    }
    return cnt;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int N = 1e7 + 1;

    int n,q; cin >> n >> q;
    vector<int> arr(n);
    vector<int> freq_buckets(N,0);
    map<int,int> freq;
    
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
        ++freq[arr[i]];
        int bucket_idx = get_bucket_idx(arr[i]);
        ++freq_buckets[bucket_idx];
    }

    vector<int> fenwick(N);
    for(int i=0; i<N; ++i) {
        fenwick[i+1] += freq_buckets[i];
        int j = i + (i&-i);
        if(j<N) fenwick[j] += fenwick[i];
    }

    while(q--) {
        char ch; cin >> ch;
        if(ch=='?') {
            int a,b; cin >> a >> b;
            int left = get_bucket_idx(a);
            int right = get_bucket_idx(b);
            if(left==right) {
                cout << brute_calc(a,b,freq) << '\n';
                continue;
            }
            int tot = 0;
            tot += brute_calc(a,(left+1)*100,freq);
            tot += brute_calc(right*100+1,b,freq);            
            tot += query(left+2,right,fenwick); // fenwick is 1 based, hence left+1+1 and right-1+1
            cout << tot << '\n'; 
        } else {
            int k,val; cin >> k >> val;
            --k;
            --freq[arr[k]];
            update(get_bucket_idx(arr[k])+1,N,-1,fenwick);
            arr[k] = val;
            ++freq[arr[k]];
            update(get_bucket_idx(arr[k])+1,N,1,fenwick);
        }
    }
    return 0;
}


