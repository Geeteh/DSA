/* Homework 5, Drake Geeteh */
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

TreeNode* search(TreeNode* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

void breadthFirstTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    int choice;
    int data;

    do {
        cout << "M E N U\n";
        cout << "Create (0), Search (1), Breadth-First Traversal (2)\n";
        cout << "Depth-First Traversal: preorder (3), inorder (4), postorder (5)\n";
        cout << "Delete (6), Exit Program (7)\n";
        cout << "Choose? ";
        cin >> choice;

        switch (choice) {
            case 0: {
                cout << "Enter sequence of data separated by spaces: ";
                string input;
                getline(cin >> ws, input);
                istringstream iss(input);
                while (iss >> data) {
                    root = insert(root, data);
                }
                break;
            }
            case 1:
                cout << "Enter data to search: ";
                cin >> data;
                if (search(root, data)) {
                    cout << "Node found in the tree.\n";
                } else {
                    cout << "There is no such node in the tree!\n";
                }
                break;
            case 2:
                cout << "Breadth-First Traversal: ";
                breadthFirstTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
			case 6: {
                cout << "Enter key to delete: ";
                cin >> data;
                root = deleteNode(root, data);
                cout << "Node with key " << data << " deleted.\n";
                break;
            }
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 7);

    return 0;
}