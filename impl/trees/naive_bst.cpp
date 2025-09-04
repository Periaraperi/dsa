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

private:
    node* root {nullptr};

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

