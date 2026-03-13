#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int d, Node *&p) {
        data = d;
        left = nullptr;
        right = nullptr;
        parent = p;
    }
};

class BinaryTree {
    private:
    Node *root;
    Node *parent;
    int count;
    Node* insert(Node* root, Node*& parent, int data) {
        if (root == nullptr) {
            root = new Node(data, parent);
        }
        if (data < root->data) {
            parent = root;
            root->left = insert(root->left, parent, data);
        }
        else if (data > root->data) {
            parent = root;
            root->right = insert(root->right, parent, data);
        }
        return root;
    }
    void inorder_traversal(Node* root) {
        if (root != nullptr) {
            inorder_traversal(root->left);
            cout << root->data << " ";
            inorder_traversal(root->right);
        }
    }
    void postorder_traversal(Node* root) {
        if (root != nullptr) {
            postorder_traversal(root->right);
            cout << root->data << " ";
            postorder_traversal(root->left);
        }
    }
    void size(Node* root) {
        if (root != nullptr) {
            count += 1;
            size(root->left);
            size(root->right);
        }else {
            return ;
        }
    }
    void self_destruct(Node* root) {
        if (root != nullptr) {
            self_destruct(root->left);
            delete root;
            self_destruct(root->right);
        }
    }
    Node* min(Node* root) {
        if (root == nullptr) {
           return nullptr;
        }
        else if (root->left == nullptr) {
            return root;
        } else {
            return min(root->left);
        }

    }
    Node* max (Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        else if (root->right == nullptr) {
            return root;
        }
        else {
            return max(root->right);
        }
    }
    public:
    BinaryTree() {
        root = nullptr;
        parent = nullptr;
        count = 0;
    }
    void insert(int data) {
        root = insert(root, parent, data);
        parent = root;
    }
    void print_i() {
        inorder_traversal(root);
    }
    void print_p() {
        postorder_traversal(root);
    }
    int min() {
        return min(root)->data;
    }
    int max() {
        return max(root)->data;
    }
    int size() {
        size(root);
        return count;
    }
    ~BinaryTree() {
        self_destruct(root);
    }
};

int main() {
    BinaryTree t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    t.print_i();
    cout << endl;
    t.print_p();
    cout << endl;
    cout << t.min() << endl;
    cout << t.max() << endl;
    cout << t.size() << endl;
    return 0;
}