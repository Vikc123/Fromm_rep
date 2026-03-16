#include <iostream>

using namespace std;

template<typename T>
class set {
    private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        Node *parent;

        Node(T d, Node *&p) {
            data = d;
            left = nullptr;
            right = nullptr;
            parent = p;
        }
    };
    Node *root;
    Node *parent;
    int count;

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
    bool empty(Node* root) {
        if (root == nullptr) {
            return true;
        } else {
            return false;
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
    class iterator {
        private:
        Node* node;
        public:
        iterator(Node* n = nullptr) {
            node = n;
        }
        iterator& errase(iterator& it) {
            if (node != nullptr) {
                Node* temp = node;
                if (temp->parent && temp == temp->parent->left) {
                    if (temp->left) {
                        temp = temp->left;
                        while (temp->right) {
                            temp = temp->right;
                        }
                        node->data = temp->data;
                        temp->parent->right = temp->left;
                        delete temp;
                        return it;
                    }
                    else if (temp->right){
                        temp->right->parent = temp->parent;
                        node = node->parent;
                        node->left = temp->right;
                        delete temp;
                        return it;
                    }
                    else {
                        node = node->parent;
                        node->left = nullptr;
                        delete temp;
                        return it;
                    }
                }
                else if (temp->parent && temp == temp->parent->right) {
                    if (temp->left) {
                        temp = temp->left;
                        while (temp->right) {
                            temp = temp->right;
                        }
                        node->data = temp->data;
                        temp->parent->right = temp->left;
                        delete temp;
                        return it;
                    }
                    else if (temp->right) {
                        temp->right->parent = temp->parent;
                        node = node->parent;
                        node->right = temp->right;
                        delete temp;
                        return it;
                    } else {
                        node = node->parent;
                        node->right = nullptr;
                        delete temp;
                        return it;
                    }
                }
                else {
                    if (temp->left) {
                        temp = temp->left;
                        while (temp->right) {
                            temp = temp->right;
                        }
                        node->data = temp->data;
                        temp->parent->right = temp->left;
                        delete temp;
                        return it;
                    }
                    else if (temp->right) {
                        temp = temp->right;
                        if (temp->left) {
                            while (temp->left) {
                                temp = temp->left;
                            }
                            node->data = temp->data;
                            temp->parent->left = temp->right;
                            delete temp;
                            return it;
                        }
                        else {
                            // temp->left->parent = temp->parent;
                            // temp->right->parent = temp->parent;
                            // node->left = temp->left;
                            // node->right = temp->right;
                            // temp->data = node->data;
                            delete temp;
                            node = nullptr;
                            return it;
                        }
                    }
                    else {
                        node = nullptr;
                        delete temp;
                        return it;
                    }
                }
            } else {
                cout << "Null iterator" << endl;
                return it;
            }
        }
        T& operator*() {
            return node->data;
        }
        iterator& operator++() {
            if (node->right) {
                node = node->right;
                while (node->left) {
                    node = node->left;
                }
                return *this;
            }
            Node* p = node->parent;
            while (p && node == p->right) {
                node = p;
                p = p->parent;
            }
            node = p;
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        iterator& operator--() {
            if (node->parent && node == (node->parent)->left) {
                if (node->left) {
                    node = node->left;
                    while (node->right) {
                        node = node->right;
                    }
                    return *this;
                } else {
                    node = node->parent->parent;
                    return *this;
                }
            }
            if (node->parent && node == (node->parent)->right) {
                if (node->left) {
                    node = node->left;
                    while (node->right) {
                        node = node->right;
                    }
                    return *this;
                } else {
                    node = node->parent;
                    return *this;
                }
            } else {
                if (node->left) {
                    node = node->left;
                    while (node->right) {
                        node = node->right;
                    }
                    return *this;
                } else {
                    return *this;
                }
            }
        }
        iterator operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }
        bool operator!=(const iterator& other) {
            return node != other.node;
        }
        bool operator==(const iterator& other) {
            return node == other.node;
        }
    };
    class reverse_iterator {
        private:
        Node* node;
        public:
        reverse_iterator(Node* n = nullptr) {
            node = n;
        }
        reverse_iterator& errase(iterator& it) {
            if (node != nullptr) {
                Node* temp = node;
                if (temp->parent && temp == temp->parent->left) {
                    if (temp->left) {
                        temp = temp->left;
                        while (temp->right) {
                            temp = temp->right;
                        }
                        node->data = temp->data;
                        temp->parent->right = temp->left;
                        delete temp;
                        return it;
                    }
                    else if (temp->right){
                        temp->right->parent = temp->parent;
                        node = node->parent;
                        node->left = temp->right;
                        delete temp;
                        return it;
                    }
                    else {
                        node = node->parent;
                        node->left = nullptr;
                        delete temp;
                        return it;
                    }
                }
                else if (temp->parent && temp == temp->parent->right) {
                    if (temp->left) {
                        temp = temp->left;
                        while (temp->right) {
                            temp = temp->right;
                        }
                        node->data = temp->data;
                        temp->parent->right = temp->left;
                        delete temp;
                        return it;
                    }
                    else if (temp->right) {
                        temp->right->parent = temp->parent;
                        node = node->parent;
                        node->right = temp->right;
                        delete temp;
                        return it;
                    } else {
                        node = node->parent;
                        node->right = nullptr;
                        delete temp;
                        return it;
                    }
                }
                else {
                    if (temp->left) {
                        temp = temp->left;
                        while (temp->right) {
                            temp = temp->right;
                        }
                        node->data = temp->data;
                        temp->parent->right = temp->left;
                        delete temp;
                        return it;
                    }
                    else if (temp->right) {
                        temp = temp->right;
                        if (temp->left) {
                            while (temp->left) {
                                temp = temp->left;
                            }
                            node->data = temp->data;
                            temp->parent->left = temp->right;
                            delete temp;
                            return it;
                        }
                        else {
                            // temp->left->parent = temp->parent;
                            // temp->right->parent = temp->parent;
                            // node->left = temp->left;
                            // node->right = temp->right;
                            // temp->data = node->data;
                            delete temp;
                            node = nullptr;
                            return it;
                        }
                    }
                    else {
                        node = nullptr;
                        delete temp;
                        return it;
                    }
                }
            } else {
                cout << "Null iterator" << endl;
                return it;
            }
        }
        T& operator*() {
            return node->data;
        }
        reverse_iterator& operator++() {
            if (node->parent && node == (node->parent)->left) {
                if (node->left) {
                    node = node->left;
                    while (node->right) {
                        node = node->right;
                    }
                    return *this;
                } else {
                    node = node->parent->parent;
                    return *this;
                }
            }
            if (node->parent && node == (node->parent)->right) {
                if (node->left) {
                    node = node->left;
                    while (node->right) {
                        node = node->right;
                    }
                    return *this;
                } else {
                    node = node->parent;
                    return *this;
                }
            } else {
                if (node->left) {
                    node = node->left;
                    while (node->right) {
                        node = node->right;
                    }
                    return *this;
                } else {
                    return *this;
                }
            }
        }
        reverse_iterator operator++(int) {
            reverse_iterator temp = *this;
            ++(*this);
            return temp;
        }
        reverse_iterator& operator--() {
            if (node->right) {
                node = node->right;
                while (node->left) {
                    node = node->left;
                }
                return *this;
            }
            Node* p = node->parent;
            while (p && node == p->right) {
                node = p;
                p = p->parent;
            }
            node = p;
            return *this;
        }
        reverse_iterator operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }
        bool operator!=(const iterator& other) {
            return node != other.node;
        }
        bool operator==(const iterator& other) {
            return node == other.node;
        }
    };
    set() {
        root = nullptr;
        parent = nullptr;
        count = 0;
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
    void insert(int data) {
        root = insert(root, parent, data);
        parent = root;
        count += 1;
    }
    void print_i() {
        if (root) {
        inorder_traversal(root);
        } else {
            cout << "Empty Tree" << endl;
        }
    }
    void print_p() {
        postorder_traversal(root);
    }
    void errase(int val) {
        root = errase(root, val);
    }
    void clear() {
        self_destruct(root);
        root = nullptr;
        count = 0;
    }
    iterator& errase(iterator& it) {
        it.errase(it);
        return it;
    }
    iterator begin() {
        return iterator(min(root));
    }
    iterator end() {
        return iterator(max(root));
    }
    reverse_iterator rbegin() {
        return reverse_iterator(max(root));
    }
    reverse_iterator rend() {
        return reverse_iterator(min(root));
    }
    reverse_iterator& errase(reverse_iterator& it) {
        it.errase(it);
        return it;
    }
    ~set() {
        self_destruct(root);
    }
};