#include <iostream>

namespace peria {

class dynamic_segment_tree {
    struct node {
        int freq {};
        int lazy {};
        node* left {nullptr};
        node* right {nullptr};
    };

    const int n {};
    node* root {new node{}};

    void apply(node* const v, int range_len, int value)
    {
        if (value > 0) {
            v->lazy = value;
            v->freq = range_len*value;
        }
    }

    void push(node* const v, int l, int r)
    {
        if (v->left == nullptr) v->left = new node{};
        if (v->right == nullptr) v->right = new node{};
        const int m {(l+r)/2};
        apply(v->left, m-l+1, v->lazy);
        apply(v->right, r-m, v->lazy);
    }

    [[nodiscard]]
    int range_sum(node* const v, const int& ql, const int& qr, int l, int r)
    {
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return v->freq;
        push(v, l, r);
        const int m {(l+r)/2};
        return range_sum(v->left, ql, qr, l, m) + range_sum(v->right, ql, qr, m+1, r);
    }

    void range_set(node* const v, const int& ql, const int& qr, int l, int r, int value)
    {
        if (ql > r || qr < l) return;
        if (ql <= l && qr >= r) apply(v, r-l+1, value);
        else {
            push(v, l, r);
            const int m {(l+r)/2};
            range_set(v->left, ql, qr, l, m, value);
            range_set(v->right, ql, qr, m+1, r, value);
            v->freq = v->left->freq + v->right->freq;
        }
    }

    void clean_tree(node* v)
    {
        if (v == nullptr) return;
        clean_tree(v->left);
        clean_tree(v->right);
        delete v; v = nullptr;
    }

public:
    explicit dynamic_segment_tree(int n_)
        :n{n_}
    {}
    dynamic_segment_tree()
    { clean_tree(root); }

    [[nodiscard]] int range_sum(int ql, int qr) 
    { return range_sum(root, ql, qr, 0, n-1); }

    void range_set(int ql, int qr, int value)
    { range_set(root, ql, qr, 0, n-1, value); }
};

}
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    peria::dynamic_segment_tree seg_tree{static_cast<int>(1e9 + 1)};
    int n, q; std::cin >> n >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;
        --l; --r;
        seg_tree.range_set(l, r, 1);
        std::cout << n - seg_tree.range_sum(0, n) << '\n';
    }
    return 0;
}
