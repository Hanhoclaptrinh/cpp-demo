#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* tree_search(Node* root, int target) {
	if (root == nullptr || root->data == target) {
		return root;
	}
	if (target < root->data) {
		return tree_search(root->left, target);
	} else {
		return tree_search(root->right, target);
	}
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
	Node* root = nullptr;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 7);
	insert(root, 2);
	insert(root, 4);
	
	inorder(root);
	cout << endl;	
	int target = 4;
    Node* result = tree_search(root, target);
    cout << "Search for " << target << ": " << (result ? "Found" : "Not Found") << endl;

    target = 8;
    result = tree_search(root, target);
    cout << "Search for " << target << ": " << (result ? "Found" : "Not Found") << endl;
	
	return 0;
}
