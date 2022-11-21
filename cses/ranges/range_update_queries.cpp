#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void build(int v, int nl, int nr, vector<ll>& tree, const vector<ll>& arr)
{
    if(nl==nr) {
        tree[v] = arr[nl];
    } else {
        int m = (nl+nr)/2;
        build(2*v,nl,m,tree,arr);
        build(2*v+1,m+1,nr,tree,arr);
        tree[v] = 0;
    }
}

void range_update(int v, int nl, int nr, int l, int r, int val, vector<ll>& tree)
{
    if(nl>r || nr<l) {
        return;
    }
    if(nl>=l && nr<=r) {
        tree[v] += val;   
        return;
    }

    int m = (nl+nr)/2;
    range_update(2*v,nl,m,l,r,val,tree);
    range_update(2*v+1,m+1,nr,l,r,val,tree);
}

ll query(int v, int nl, int nr, int pos, vector<ll>& tree)
{
    if(nl==nr)
        return tree[v];

    int m = (nl+nr)/2;
    if(pos<=m) {
        return tree[v]+query(2*v,nl,m,pos,tree);
    } else {
        return tree[v]+query(2*v+1,m+1,nr,pos,tree);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q; cin >> n >> q;
    vector<ll> seg_tree(4*n), arr(n);
    for(auto& a:arr)
        cin >> a;
    build(1,0,n-1,seg_tree,arr);

    while(q--) {
        int type; cin >> type;
        if(type==1) {
            int a,b,val; cin >> a >> b >> val;
            --a;
            --b;
            range_update(1,0,n-1,a,b,val,seg_tree);
        } else {
            int pos; cin >> pos;
            --pos;
            cout << query(1,0,n-1,pos,seg_tree) << '\n';
        }     
    }
    return 0;
}


