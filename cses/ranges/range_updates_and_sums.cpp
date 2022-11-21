#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+1;

template<typename T>
class Segment_tree {
public:
    struct Node {
        Node() :lo(0), hi(0), sum(0), lazy_increment(0), lazy_set(0), set_range(false) {}
        int lo;
        int hi; 
        T sum;
        T lazy_increment;
        T lazy_set;
        bool set_range;
    };
    Segment_tree(const vector<T>& data) 
        :n((int)data.size()),
        tree(vector<Node>(4*n))
    {
        init(1,0,n-1,data);
    }
    
    void range_update(int l, int r, T val)
    {
        if (l>r) return;
        range_update(1,l,r,val);
    }

    void range_set(int l, int r, T val)
    {
        if (l>r) return;
        range_set(1,l,r,val);
    }

    T query(int l, int r)
    {
        if (l>r) return 0;
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
            tree[v].sum = data[l]; 
            return;
        }
        int m = (l+r)/2;
        init(2*v,l,m,data);
        init(2*v+1,m+1,r,data);
        merge(v);
    }
    
    void prop(int v)
    {
        if (tree[v].set_range) {
            // override children updates by parent
            tree[2*v].set_range = true;
            tree[2*v+1].set_range = true;

            tree[2*v].lazy_set = tree[v].lazy_set;
            tree[2*v+1].lazy_set = tree[v].lazy_set;

            tree[2*v].lazy_increment = tree[v].lazy_increment;
            tree[2*v+1].lazy_increment = tree[v].lazy_increment;
        } else {
            tree[2*v].lazy_increment += tree[v].lazy_increment;
            tree[2*v+1].lazy_increment += tree[v].lazy_increment;
        }
        tree[v].set_range = false;
        tree[v].lazy_set = 0;
        tree[v].lazy_increment = 0;
    } 

    void merge(int v)
    {
        T left = 0;
        T right = 0;
        if (tree[2*v].set_range) left = (tree[2*v].lazy_set+tree[2*v].lazy_increment)*(tree[2*v].hi-tree[2*v].lo+1);
        else                     left = tree[2*v].sum + tree[2*v].lazy_increment*(tree[2*v].hi-tree[2*v].lo+1);

        if (tree[2*v+1].set_range) right = (tree[2*v+1].lazy_set+tree[2*v+1].lazy_increment)*(tree[2*v+1].hi-tree[2*v+1].lo+1);
        else                       right = tree[2*v+1].sum + tree[2*v+1].lazy_increment*(tree[2*v+1].hi-tree[2*v+1].lo+1);

        tree[v].sum = left+right;
    }
    
    void range_set(int v, int l, int r, T val)
    {
        auto& lo = tree[v].lo;
        auto& hi = tree[v].hi;
        if (lo>r || hi<l)
            return;
        if (lo>=l && hi<=r) {
            tree[v].lazy_increment = 0;
            tree[v].set_range = true;
            tree[v].lazy_set = val;
            return;
        }
        prop(v);
        range_set(2*v,l,r,val);
        range_set(2*v+1,l,r,val);
        merge(v);
    } 

    void range_update(int v, int l, int r, T val)
    {
        auto& lo = tree[v].lo;
        auto& hi = tree[v].hi;
        if (lo>r || hi<l)
            return;
        if (lo>=l && hi<=r) {
            tree[v].lazy_increment += val;
            return;
        }
        prop(v);
        range_update(2*v,l,r,val);
        range_update(2*v+1,l,r,val);
        merge(v);
    }

    T query(int v, int l, int r)
    {
        auto& lo = tree[v].lo;
        auto& hi = tree[v].hi;
        if (lo>r || hi<l)
            return 0;
        if (lo>=l && hi<=r) {
            if (tree[v].set_range) 
                return (tree[v].lazy_set+tree[v].lazy_increment)*(hi-lo+1);
            else
                return tree[v].sum + tree[v].lazy_increment*(hi-lo+1);
        }
        prop(v);

        T left = query(2*v,l,r);
        T right = query(2*v+1,l,r);

        merge(v);

        return left+right;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q; cin >> n >> q;
    vector<long long> v(n);
    for (auto& num:v) cin >> num;
    
    Segment_tree<long long> tree(v);

    while (q--) {
        int x; cin >> x;
        if (x==1) {
            int a,b,val; cin >> a >> b >> val;
            --a; --b;
            tree.range_update(a,b,val);
        } else if (x==2) {
            int a,b,val; cin >> a >> b >> val;
            --a; --b;
            tree.range_set(a,b,val);
        } else {
            int a,b; cin >> a >> b;
            --a; --b;
            cout << tree.query(a,b) << '\n';
        }
    }

    return 0;
}


