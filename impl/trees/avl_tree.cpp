#include <iostream>
#include <utility>
 
// implementation of balanced bst for set of unique keys
namespace peria {

struct avl_tree {
    struct node {
        node() = default;
        explicit node(int v)
            :val{v}
        {}
        int val {};
        int height {};
        node* left  {nullptr};
        node* right {nullptr};
        node* parent {nullptr};
    };

    avl_tree() = default;
    
    avl_tree(const avl_tree& other) = delete;
    avl_tree(avl_tree&& other) = delete;

    avl_tree& operator=(const avl_tree& other) = delete;
    avl_tree& operator=(avl_tree&& other) = delete;

    ~avl_tree() 
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

    [[nodiscard]]
    int tree_height()
    { if (root == nullptr) return -1; return root->height; }

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

    // assume that x != null
    void left_rotate(node* x)
    {
        if (x->right == nullptr) return; // nothing changes here (can't rotate to left any more)
        auto old_parent {x->parent}; // possibly null
        auto y {x->right};
        auto z {y->left}; // possibly null

        y->left = x;
        y->parent = old_parent;
        x->parent = y;
        x->right = z;
        if (z != nullptr) z->parent = x;
        if (old_parent != nullptr) {
            // old parent still points to x in one of its children, so reassign them
            if (old_parent->left == x) {
                old_parent->left = y;
            }
            else {
                old_parent->right = y;
            }
        }

        if (x == root) {
            root = y;
        }

        if (z != nullptr) update(z);
        update(x);
        update(y);
        if (old_parent != nullptr) update(old_parent);
    }

    // assume that x != null
    void right_rotate(node* x)
    {
        if (x->left == nullptr) return; // nothing changes here (can't rotate to right any more)
        auto old_parent {x->parent}; // possibly null
        auto y {x->left};
        auto z {y->right}; // possibly null


        y->right = x;
        y->parent = old_parent;
        x->parent = y;
        x->left = z;
        if (z != nullptr) z->parent = x;
        if (old_parent != nullptr) {
            // old parent still points to x in one of its children, so reassign them
            if (old_parent->left == x) {
                old_parent->left = y;
            }
            else {
                old_parent->right = y;
            }
        }

        if (x == root) {
            root = y;
        }

        if (z != nullptr) update(z);
        update(x);
        update(y);
        if (old_parent != nullptr) update(old_parent);
    }

    // update augmented fields. 
    // Height in this case.
    // assumes x is not nullptr.
    void update(node* x)
    {
        int h_left  {-1};
        int h_right {-1};
        if (x->left  != nullptr) h_left  = x->left->height;
        if (x->right != nullptr) h_right = x->right->height;
        x->height = std::max(h_left, h_right)+1;
    }

    // assumes that x is not nullptr
    [[nodiscard]]
    int balance_factor(node* x)
    {
        int h_left  {-1};
        int h_right {-1};
        if (x->left  != nullptr) h_left  = x->left->height;
        if (x->right != nullptr) h_right = x->right->height;
        return h_right - h_left;
    }

    // will be called if BF of x is either 2 or -2
    void rebalance(node* x)
    {
        if (balance_factor(x) == 2) { // right heavy
            if (balance_factor(x->right) == 1) {
                left_rotate(x);
            }
            else {
                right_rotate(x->right);
                left_rotate(x);
            }
        }
        if (balance_factor(x) == -2) { // left heavy
            if (balance_factor(x->left) == -1) {
                right_rotate(x);
            }
            else {
                left_rotate(x->left);
                right_rotate(x);
            }
        }
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
            auto p {x->parent}; 
            if (p != nullptr) {
                // detach x from parent
                if (p->left == x) p->left = nullptr;
                else p->right = nullptr;
            }
            delete x;
            --count;
            if (count == 0) root = nullptr; // tree is empty
            while (p != nullptr) {
                update(p);
                const auto bf {balance_factor(p)};
                if (bf == 2 || bf == -2) {
                    rebalance(p);
                }
                p = p->parent;
            }
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
        auto y {new node{value}};
        while (x != nullptr) {
            if (value < x->val) {
                if (x->left == nullptr) {
                    insert_before(x, y);
                    break;
                }
                else {
                    x = x->left;
                }
            }
            else {
                if (x->right == nullptr) {
                    insert_after(x, y);
                    break;
                }
                else {
                    x = x->right;
                }
            }
        }
        // y is added, so now go up the tree from y and check if any node is out of balanced
        while (y != nullptr) {
            update(y);
            const auto bf {balance_factor(y)};
            if (bf == 2 || bf == -2) {
                rebalance(y);
            }
            y = y->parent;
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
    return 0;
}
