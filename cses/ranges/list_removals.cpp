#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void build(int v, int nl, int nr, vector<int>& tree)
{
    if(nl==nr) {
        tree[v] = 1;
    } else {
        int m = (nl+nr)/2;
        build(2*v,nl,m,tree);
        build(2*v+1,m+1,nr,tree);
        tree[v] = tree[2*v]+tree[2*v+1];
    }
}

void update(int v, int nl, int nr, int pos, vector<int>& tree)
{
    if(nl==nr) {
        tree[v] = 0;
        return;
    }
    int m = (nl+nr)/2;
    if(pos<=m) {
        update(2*v,nl,m,pos,tree);
    } else {
        update(2*v+1,m+1,nr,pos,tree);
    }
    tree[v] = tree[2*v]+tree[2*v+1];
}

int query(int v, int nl, int nr, int l, int r, vector<int>& tree)
{
    if(nl>r || nr<l) return 0;
    if(nl>=l && nr<=r) return tree[v];
    int m = (nl+nr)/2;
    return query(2*v,nl,m,l,r,tree)+query(2*v+1,m+1,nr,l,r,tree);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n),b(n);
    for(auto& i:a) cin >> i;
    for(auto& i:b) { cin >> i; --i;} // make them 0 indexed
    vector<int> tree(4*n);
    vector<bool> present(n,1);
    build(1,0,n-1,tree);

    for(int i=0; i<n; ++i) {
        int updated_pos = b[i]; // 0 indexed
        int lo = 0;
        int hi = n-1;
        while(lo<=hi) {
            int m = (lo+hi)/2; // binary search original index
            int cnt_not_deleted = query(1,0,n-1,0,m,tree);
            if(cnt_not_deleted<updated_pos+1) {
                lo = m+1;
            } else if(cnt_not_deleted>updated_pos+1) {
                hi = m-1;
            } else {
                if(present[m]) {
                    cout << a[m] << " "; 
                    present[m] = 0;
                    update(1,0,n-1,m,tree);
                    break;
                } else {
                    hi = m-1;
                }
            }
        }
    }

    return 0;
}


