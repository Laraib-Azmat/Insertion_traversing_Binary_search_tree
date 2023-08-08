#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}


//deletion


Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* minNode = findMinNode(root->right);
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    return root;
}



void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;

    int choice;
    int number;

    while (true) {
        cout << "Binary Tree Operations:" << endl;
        cout << "1. Insert a number" << endl;
        cout << "2. Inorder traversal" << endl;
        cout << "3. Preorder traversal" << endl;
        cout << "4. Postorder traversal" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                root = insert(root, number);
                cout << "Number inserted successfully.n" << endl;
                break;
            case 2:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}