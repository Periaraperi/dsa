#include <iostream>
#include <utility>
 
// Naive implementation of bst.
// Will degrade to linked-list with some inputs.
namespace peria {

struct naive_bst {
    struct node {
        node() = default;
        explicit node(int v)
            :val{v}
        {}
        int val {};
        node* left  {nullptr};
        node* right {nullptr};
        node* parent {nullptr};
    };

    naive_bst() = default;
    
    naive_bst(const naive_bst& other) = delete;
    naive_bst(naive_bst&& other) = delete;

    naive_bst& operator=(const naive_bst& other) = delete;
    naive_bst& operator=(naive_bst&& other) = delete;

    ~naive_bst() 
    { dealloc_nodes(root); }

    [[nodiscard]]
    node* find(const int target)
    { return find_impl(target); }

    void insert(const int value)
    { insert_impl(value); }

    void erase(const int target)
    { erase_impl(target); }

    void erase(node* x)
    { if (x != nullptr) subtree_delete(x); }

    [[nodiscard]]
    size_t size() noexcept
    { return count; }

    [[nodiscard]]
    bool empty() noexcept
    { return count == 0; }

    void print()
    { in_order_traversal(root); }

    void println()
    { in_order_traversal(root); std::cout << '\n'; }

private:
    node* root {nullptr};
    size_t count {};

    // assumes that x is not nullptr.
    // returns first element in the subtree of node (x).
    [[nodiscard]]
    node* subtree_first(node* x)
    {
        while (x->left != nullptr) x = x->left;
        return x;
    }

    // assumes that x is not nullptr.
    // returns last element in the subtree of node (x).
    [[nodiscard]]
    node* subtree_last(node* x)
    {
        while (x->right != nullptr) x = x->right;
        return x;
    }

    // assumes that x is not nullptr.
    // returns next node after x in traversal order, 
    // or nullptr if x is last node in traversal order.
    [[nodiscard]]
    node* successor(node* x)
    {
        if (x->right != nullptr) {
            return subtree_first(x->right);
        }
        while (x->parent != nullptr && x != x->parent->left) x = x->parent;
        return x->parent;
    }

    // assumes that x is not nullptr.
    // returns previous node before x in traversal order, 
    // or nullptr if x is first node in traversal order.
    [[nodiscard]]
    node* predecessor(node* x)
    {
        if (x->left != nullptr) {
            return subtree_last(x->left);
        }
        while (x->parent != nullptr && x != x->parent->right) x = x->parent;
        return x->parent;
    }

    // assumes that x is not nullptr.
    // inserts node (y) after node (x) in traversal order.
    void insert_after(node* x, node* y)
    {
        if (x->right == nullptr) x->right = y;
        else {
            x = successor(x); // will fall in case 1
            x->left = y;
        }
        y->parent = x;
        ++count;
    }

    // assumes that x is not nullptr.
    // inserts node (y) before node (x) in traversal order.
    void insert_before(node* x, node* y)
    {
        if (x->left == nullptr) x->left = y;
        else {
            x = predecessor(x); // will fall in case 1
            x->right = y;
        }
        y->parent = x;
        ++count;
    }

    // assumes that x is not nullptr.
    // deletes node (x) from the tree;
    void subtree_delete(node* x)
    {
        // case 1: x is leaf (base case)
        if (x->left == nullptr && x->right == nullptr) {
            // x could be leaf and root. (if only 1 element in tree)
            if (auto p {x->parent}; p != nullptr) {
                // detach x from parent
                if (p->left == x) p->left = nullptr;
                else p->right = nullptr;
            }
            delete x;
            --count;
        }
        // case 2: either a left or right child exists.
        // do the swapping of contents with predecessor or successor and recursively
        // call subtree_delete.
        else {
            if (x->left != nullptr) {
                auto x_predecessor {predecessor(x)};
                std::swap(x->val, x_predecessor->val);
                subtree_delete(x_predecessor);
            }
            else {
                auto x_successor {successor(x)};
                std::swap(x->val, x_successor->val);
                subtree_delete(x_successor);
            }
        }
    }

    [[nodiscard]]
    node* find_impl(const int target)
    {
        auto x{root};
        while (x != nullptr && x->val != target) {
            if (target < x->val) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        return x;
    }

    void insert_impl(const int value)
    {
        if (find_impl(value) != nullptr) return;

        if (root == nullptr) {
            root = new node{value};
            ++count;
            return;
        }

        auto x{root};
        while (x != nullptr) {
            if (value < x->val) {
                if (x->left == nullptr) {
                    auto y {new node{value}};
                    insert_before(x, y);
                    return;
                }
                else {
                    x = x->left;
                }
            }
            else {
                if (x->right == nullptr) {
                    auto y {new node{value}};
                    insert_after(x, y);
                    return;
                }
                else {
                    x = x->right;
                }
            }
        }
    }

    void erase_impl(const int target)
    {
        auto x {find_impl(target)};
        if (x == nullptr) return;
        subtree_delete(x);
    }

    void in_order_traversal(const node* const x)
    {
        if (x == nullptr) return;
        in_order_traversal(x->left);
        std::cout << x->val << ' ';
        in_order_traversal(x->right);
    }

    void dealloc_nodes(node* x)
    {
        if (x == nullptr) return;
        dealloc_nodes(x->left);
        dealloc_nodes(x->right);
        delete x;
    }
};

}
 
int main() 
{
    peria::naive_bst st{};
    for(int i{}; i<10; ++i) {
        st.insert(i);
    }
    std::cout << st.size() << '\n';
    st.println();
    return 0;
}
