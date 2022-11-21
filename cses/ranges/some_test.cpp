#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+1;

template<typename T>
class Segment_tree {
public:
    struct Node {
        Node() :lo(0), hi(0), mn(0) {}
        int lo;
        int hi; 
        T mn;
    };
    Segment_tree(const vector<T>& data) 
        :n((int)data.size()),
        tree(vector<Node>(4*n))
    {
        init(1,0,n-1,data);
    }

    void point_update(int pos, T val)
    {
        point_update(1,pos,val);
    }

    T query(int l, int r)
    {
        if (l>r) return std::numeric_limits<T>::max();
        return query(1,l,r);
    }
private:
    int n;
    vector<Node> tree;
    
    void init(int v, int l, int r, const vector<T>& data)
    {
        tree[v].lo = l;
        tree[v].hi = r;
        if (l==r) {
            tree[v].mn = data[l];
            return;
        }
        int m = (l+r)/2;
        init(2*v,l,m,data);
        init(2*v+1,m+1,r,data);
        merge(v);
    }
    
    void merge(int v)
    {
        tree[v].mn = std::min(tree[2*v].mn,tree[2*v+1].mn);
    }

    void point_update(int v, int pos, T val)
    {
        auto& lo = tree[v].lo;
        auto& hi = tree[v].hi;
        if (lo==hi) {
            tree[v].mn += val;
            return;
        }
        int m = (lo+hi)/2;
        if (pos<=m) {
            point_update(2*v,pos,val);
        } else {
            point_update(2*v+1,pos,val);
        }
        merge(v);
    }
    
    T query(int v, int l, int r)
    {
        auto& lo = tree[v].lo;
        auto& hi = tree[v].hi;
        if (lo>r || hi<l)
            return std::numeric_limits<T>::max();
        if (lo>=l && hi<=r)
            return tree[v].mn;

        T left = query(2*v,l,r);
        T right = query(2*v+1,l,r);
        merge(v); // not necessary here

        return std::min(left,right);
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,q; cin >> n >> q;
    vector<int> v(n);
    for (auto& num:v) cin >> num;
    Segment_tree<int> min_tree(v);

    while (q--) {
        int x; cin >> x;
        switch (x) {
            case 1: {
                int k,u; cin >> k >> u;
                --k;
                min_tree.point_update(k,u-v[k]);
                v[k] = u;
                break;
            }
            case 2: {
                int l,r; cin >> l >> r;
                --l; --r;
                cout << min_tree.query(l,r) << '\n';
                break;
            }
        } 
    } 

    return 0;
}

