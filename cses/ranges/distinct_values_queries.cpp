#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+1;

template<typename T>
class Segment_tree {
public:
    struct Node {
        Node() :lo(0), hi(0) {}
        int lo;
        int hi; 
        vector<T> arr; // store sorted array at each node in range [lo,hi]
    };
    Segment_tree(const vector<T>& data) 
        :n((int)data.size()),
        tree(vector<Node>(4*n))
    {
        init(1,0,n-1,data);
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
            // leaf will have vector of size one with data[l]
            tree[v].arr.push_back(data[l]); 
            return;
        }
        int m = (l+r)/2;
        init(2*v,l,m,data);
        init(2*v+1,m+1,r,data);
        merge(v);
    }
    
    void merge(int v)
    {
        // merge with two pointers, same as merge sort
        auto& left_arr = tree[2*v].arr;
        auto& right_arr = tree[2*v+1].arr;
        tree[v].arr.resize((int)left_arr.size()+(int)right_arr.size());
        int i = 0, j = 0, k = 0;
        while (i<(int)left_arr.size() && j<(int)right_arr.size()) {
            if (left_arr[i]<=right_arr[j]) {
                tree[v].arr[k] = left_arr[i];
                ++i;
            } else {
                tree[v].arr[k] = right_arr[j];
                ++j;
            }
            ++k;
        }
        while (i<(int)left_arr.size()) {
            tree[v].arr[k] = left_arr[i];
            ++i;
            ++k;
        }
        while (j<(int)right_arr.size()) {
            tree[v].arr[k] = right_arr[j];
            ++j;
            ++k;
        }
    }
    
    T query(int v, int l, int r)
    {
        auto& lo = tree[v].lo;
        auto& hi = tree[v].hi;
        if (lo>r || hi<l)
            return 0;
        if (lo>=l && hi<=r) {
            auto it = upper_bound(tree[v].arr.begin(),tree[v].arr.end(),r);
            return std::distance(it,tree[v].arr.end());
        }

        T left = query(2*v,l,r);
        T right = query(2*v+1,l,r);
        return left+right;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q; cin >> n >> q;
    vector<int> v(n);
    unordered_map<int,int> idx;
    idx.reserve(1<<20);
    for (auto& num:v) {
        cin >> num;
        if (idx.find(num)==idx.end()) {
            idx.insert({num,INF});
        }
    }
    
    vector<int> next_index(n);
    for (int i=n-1; i>=0; --i) {
        next_index[i] = idx[v[i]];
        idx[v[i]] = i;
    }
    Segment_tree<int> tree(next_index);
    
    while (q--) {
        int l,r; cin >> l >> r;
        --l; --r;
        cout << tree.query(l,r) << '\n';
    }

    return 0;
}
