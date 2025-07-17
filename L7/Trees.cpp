//Faatin Nur Husn Binti Izmir 22010085

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    // Search helper to find a node by name
    Node* find(Node* current, string name) {
        if (current == nullptr) return nullptr;
        if (current->name == name) return current;

        Node* found = find(current->left, name);
        if (found != nullptr) return found;

        return find(current->right, name);
    }

    // Public method: find by name and add left child
    void add_left(string parent_name, string child_name) {
        Node* parent = find(root, parent_name);
        if (parent == nullptr) {
            cout << "Parent node '" << parent_name << "' not found." << endl;
            return;
        }
        if (parent->left != nullptr) {
            cout << "Left child of '" << parent_name << "' already exists." << endl;
            return;
        }
        parent->left = new Node(child_name);
    }

    // Public method: find by name and add right child
    void add_right(string parent_name, string child_name) {
        Node* parent = find(root, parent_name);
        if (parent == nullptr) {
            cout << "Parent node '" << parent_name << "' not found." << endl;
            return;
        }
        if (parent->right != nullptr) {
            cout << "Right child of '" << parent_name << "' already exists." << endl;
            return;
        }
        parent->right = new Node(child_name);
    }

    void print_tree() {
        if (!root) return;
        cout << "Root: " << root->name << endl;
        if (root->left) cout << "Left child of " << root->name << ": " << root->left->name << endl;
        if (root->right) cout << "Right child of " << root->name << ": " << root->right->name << endl;
        if (root->left && root->left->left) cout << "Left child of " << root->left->name << ": " << root->left->left->name << endl;
        if (root->left && root->left->right) cout << "Right child of " << root->left->name << ": " << root->left->right->name << endl;
        if (root->right && root->right->left) cout << "Left child of " << root->right->name << ": " << root->right->left->name << endl;
        if (root->right && root->right->right) cout << "Right child of " << root->right->name << ": " << root->right->right->name << endl;
        if (root->right && root->right->right->right) cout << "Right child of " << root->right->right->name << ": " << root->right->right->right->name << endl;
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");
    tree.add_right("G", "Z");

    tree.print_tree();

    return 0;
}
