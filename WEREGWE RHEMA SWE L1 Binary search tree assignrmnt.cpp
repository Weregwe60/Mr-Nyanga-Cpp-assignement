#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// PART 1: BINARY SEARCH TREE (BST) IMPLEMENTATION (Covering a, c, d, e, f, )

 struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

   class BinarySearchTree {
public:
    BSTNode* root;

    BinarySearchTree() {
        root = nullptr;
    }

    // d) Algorithm to perform insertion in a BST
    /*
     * TIME COMPLEXITY:
     * - Best/Average Case: O(log n) -> When the tree is reasonably balanced.
     * - Worst Case: O(n) -> When the tree becomes skewed (like a linked list).
     * SPACE COMPLEXITY:
     * - O(h) where h is the height of the tree, due to the recursion call stack.
     */
    BSTNode* insert(BSTNode* node, int key) {
        if (node == nullptr) {
            return new BSTNode(key);
        }
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // c) Program to search a given key in a BST
    /*
     * TIME COMPLEXITY:
     * - Best/Average Case: O(log n) -> Each step discards half of the remaining nodes.
     * - Worst Case: O(n) -> If you must search through a completely skewed tree.
     * SPACE COMPLEXITY: 
     * - O(h) recursion stack space (where h = tree height).
     */
    BSTNode* search(BSTNode* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }
        if (key < node->data) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    // f) Algorithm to find min key in a BST
    /*
     * TIME COMPLEXITY:
     * - Average Case: O(log n) -> Travels down the leftmost branch.
     * - Worst Case: O(n) -> Skewed tree with everything on the left side.
     * SPACE COMPLEXITY:
     * - O(1) -> Space is constant since it uses an iterative while loop.
     */
    BSTNode* findMin(BSTNode* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // e) Algorithm to find max key in a BST
    /*
     * TIME COMPLEXITY:
     * - Average Case: O(log n) -> Travels down the rightmost branch.
     * - Worst Case: O(n) -> Skewed tree with everything on the right side.
     * SPACE COMPLEXITY:
     * - O(1) -> Space is constant since it uses an iterative while loop.
     */
    BSTNode* findMax(BSTNode* node) {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

                   // g) Algorithm to delete a particular element in a BST
    /*
     * TIME COMPLEXITY:
     * - Average Case: O(log n) -> Finding the element and its successor takes O(log n).
     * - Worst Case: O(n) -> Finding and deleting in a linear/skewed tree structure.
     * SPACE COMPLEXITY:
     * - O(h) recursion stack space (where h = tree height).
     */
                 BSTNode* remove(BSTNode* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data) {
            node->left = remove(node->left, key);
        } else if (key > node->data) {
            node->right = remove(node->right, key);
        } 
        else {
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }

            BSTNode* temp = findMin(node->right);
            node->data = temp->data; 
            node->right = remove(node->right, temp->data); 
        }
        return node;
    }

                     // a) Implement the various orders: Inorder, Preorder, Postorder
    /*
     * TIME COMPLEXITY (For all traversals below):
     * - O(n) -> Every single node in the tree must be visited exactly once.
     * SPACE COMPLEXITY (For all traversals below):
     * - O(h) -> Max space used by the recursion call stack is proportional to tree height.
     */
    void inorder(BSTNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

           void preorder(BSTNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(BSTNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

// PART 2: BINOMIAL TREE MERGING (Covering b)

struct BinomialNode {
    int key;
    int degree;
    BinomialNode* child;
    BinomialNode* sibling;
    BinomialNode* parent;

    BinomialNode(int val) {
        key = val;
        degree = 0;
        child = nullptr;
        sibling = nullptr;
        parent = nullptr;
    }
};

// b) Merging of two Binomial Trees of the same order/degree
/*
 * TIME COMPLEXITY:
 * - O(1) Constant Time -> Since we assume both binomial trees are of the same order, 
 * merging them simply involves changing pointer addresses to connect one tree root 
 * as the leftmost child of the other root.
 * SPACE COMPLEXITY:
 * - O(1) -> No dynamic data structures or recursive call stacks are utilized.
 */
     BinomialNode* mergeBinomialTrees(BinomialNode* t1, BinomialNode* t2) {
    if (t1 == nullptr) return t2;
    if (t2 == nullptr) return t1;

    if (t1->key > t2->key) {
        swap(t1, t2);
    }

    t2->parent = t1;
    t2->sibling = t1->child;
    t1->child = t2;
    t1->degree++;

    return t1;
}

    void printBinomialTree(BinomialNode* root, string indent = "") {
    if (root != nullptr) {
        cout << indent << "— Key: " << root->key << " (Degree: " << root->degree << ")\n";
        printBinomialTree(root->child, indent + "   Child:");
        printBinomialTree(root->sibling, indent + "   Sibling:");
    }
}

// MAIN EXECUTION

        int main() {

    BinarySearchTree bst;
     
       cout << "Inserting elements: 50, 30, 20, 40, 70, 60, 80\n";
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    cout << "\n--- Tree Traversals ---" << endl;
    cout << "Inorder Traversal   : "; bst.inorder(bst.root); cout << endl;
    cout << "Preorder Traversal  : "; bst.preorder(bst.root); cout << endl;
       cout << "Postorder Traversal : "; bst.postorder(bst.root); cout << endl;

    cout << "\n--- Searching Elements ---" << endl;
    int searchKey = 40;
    if (bst.search(bst.root, searchKey)) {
        cout << "Key " << searchKey << " found in the tree.\n";
    } else {
        cout << "Key " << searchKey << " not found in the tree.\n";
    }

    BSTNode* minNode = bst.findMin(bst.root);
    BSTNode* maxNode = bst.findMax(bst.root);
    cout << "\nMinimum element in BST: " << (minNode ? to_string(minNode->data) : "Tree Empty") << endl;
    cout << "Maximum element in BST: " << (maxNode ? to_string(maxNode->data) : "Tree Empty") << endl;

    cout << "\n  Deleting Element 50 (Root with 2 children)" << endl;
    bst.root = bst.remove(bst.root, 50);
    cout << "Inorder Traversal after deletion: "; bst.inorder(bst.root); cout << endl;


    cout << "  RUNNING BINOMIAL TREE MERGE  ";         

    BinomialNode* tree1 = new BinomialNode(12);
    BinomialNode* tree2 = new BinomialNode(8);

    cout << "Merging Tree 1 (Root: 12) and Tree 2 (Root: 8)...\n";
    BinomialNode* mergedTree = mergeBinomialTrees(tree1, tree2);

    cout << "\nResulting Binomial Tree structure:";
    printBinomialTree(mergedTree);

    delete tree1->child; 
    delete tree1;

    return 0;
}
