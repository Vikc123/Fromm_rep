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
            count--;
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
    bool empty(Node* root) {
        if (root == nullptr) {
            return true;
        } else {
            return false;
        }
    }
    Node* errase(Node* root, int data) {
        if (root == nullptr)
            return root;
        if (data < root->data) {
            root->left = errase(root->left, data);
        }
        else if (data > root->data) {
            root->right = errase(root->right, data);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                count--;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                count--;
                return temp;
            }
            Node* temp = min(root->right);
            root->data = temp->data;
            root->right = errase(root->right, temp->data);
        }
        return root;
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
        count += 1;
    }
    void print_i() {
        inorder_traversal(root);
    }
    void print_p() {
        postorder_traversal(root);
    }
    int min() {
        Node* m = min(root);
        if (m) return m->data;
        throw runtime_error("empty tree");
    }
    int max() {
        Node* m = max(root);
        if (m) return m->data;
        throw runtime_error("empty tree");
    }
    int size() {
        size(root);
        return count;
    }
    void errase(int val) {
        root = errase(root, val);
    }
    void clear() {
        self_destruct(root);
        root = nullptr;
        count = 0;
    }
    ~BinaryTree() {
        self_destruct(root);
    }
};

int main() {
    BinaryTree t;
    cout << "создали дерево" << endl;
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
    cout << "Минимальное значение: " << endl;
    cout << t.min() << endl;
    cout << "Макчимальное значение: " << endl;
    cout << t.max() << endl;
    cout << "Количество: " << endl;
    cout << t.size() << endl;
    cout << "Удаляем элемент(80): " << endl;
    t.errase(80);
    t.print_p();
    cout << endl;
    cout << "Удаляем элемент(30): " << endl;
    t.errase(30);
    t.print_p();
    cout << endl;
    cout << "Удаляем элемент(50): " << endl;
    t.errase(50);
    t.print_p();
    cout << "Очищаем полностью: " << endl;
    t.clear();
    t.print_i();
    cout << "Вставляем в пустой контейнер: " << endl;
    t.insert(40);
    t.print_i();
    return 0;
}