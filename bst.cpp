#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword, meaning;
    Node* left;
    Node* right;

    Node(string k, string m) : keyword(k), meaning(m), left(nullptr), right(nullptr) {}
};

class Dictionary {
public:
    Node* root = nullptr;

    void create();
    void displayAscending(Node* root);
    void displayDescending(Node* root);
    void insert(Node*& root, Node* temp);
    bool search(Node* root, const string& k, int& comparisons);
    bool update(Node* root, const string& k);
    Node* deleteNode(Node* root, const string& k);
    Node* findMin(Node* root);
};

// Create BST by inserting multiple entries
void Dictionary::create() {
    int ch;
    do {
        string key, meaning;
        cout << "Enter keyword: ";
        cin >> key;
        cout << "Enter meaning: ";
        cin >> meaning;

        Node* temp = new Node(key, meaning);
        insert(root, temp);

        cout << "Add another? (1-Yes / 0-No): ";
        cin >> ch;
    } while (ch == 1);
}

// Recursive insert
void Dictionary::insert(Node*& root, Node* temp) {
    if (!root) {
        root = temp;
    } else if (temp->keyword < root->keyword) {
        insert(root->left, temp);
    } else if (temp->keyword > root->keyword) {
        insert(root->right, temp);
    } else {
        cout << "Keyword already exists!\n";
    }
}

// Ascending order (inorder traversal)
void Dictionary::displayAscending(Node* root) {
    if (root) {
        displayAscending(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        displayAscending(root->right);
    }
}

// Descending order (reverse inorder traversal)
void Dictionary::displayDescending(Node* root) {
    if (root) {
        displayDescending(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        displayDescending(root->left);
    }
}

// Search keyword
bool Dictionary::search(Node* root, const string& k, int& comparisons) {
    while (root) {
        comparisons++;
        if (k == root->keyword)
            return true;
        else if (k < root->keyword)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// Update meaning
bool Dictionary::update(Node* root, const string& k) {
    while (root) {
        if (k == root->keyword) {
            cout << "Enter new meaning for " << k << ": ";
            cin >> root->meaning;
            return true;
        } else if (k < root->keyword)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// Delete a node
Node* Dictionary::deleteNode(Node* root, const string& k) {
    if (!root) return nullptr;

    if (k < root->keyword) {
        root->left = deleteNode(root->left, k);
    } else if (k > root->keyword) {
        root->right = deleteNode(root->right, k);
    } else {
        // Node found
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }
    return root;
}

// Find node with minimum keyword (leftmost)
Node* Dictionary::findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// ----------- MAIN FUNCTION ------------
int main() {
    Dictionary dict;
    int choice;

    do {
        cout << "\nMenu:\n1. Create\n2. Display (Ascending)\n3. Search\n4. Update\n5. Delete\n6. Display (Descending)\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dict.create();
                break;
            case 2:
                if (!dict.root)
                    cout << "Dictionary is empty.\n";
                else
                    dict.displayAscending(dict.root);
                break;
            case 3: {
                if (!dict.root) {
                    cout << "Dictionary is empty.\n";
                    break;
                }
                string k;
                cout << "Enter keyword to search: ";
                cin >> k;
                int comparisons = 0;
                if (dict.search(dict.root, k, comparisons))
                    cout << "Keyword found! Comparisons: " << comparisons << endl;
                else
                    cout << "Keyword not found. Comparisons: " << comparisons << endl;
                break;
            }
            case 4: {
                if (!dict.root) {
                    cout << "Dictionary is empty.\n";
                    break;
                }
                string k;
                cout << "Enter keyword to update: ";
                cin >> k;
                if (dict.update(dict.root, k))
                    cout << "Updated successfully.\n";
                else
                    cout << "Keyword not found.\n";
                break;
            }
            case 5: {
                if (!dict.root) {
                    cout << "Dictionary is empty.\n";
                    break;
                }
                string k;
                cout << "Enter keyword to delete: ";
                cin >> k;
                dict.root = dict.deleteNode(dict.root, k);
                cout << "Keyword deleted if it existed.\n";
                break;
            }
            case 6:
                if (!dict.root)
                    cout << "Dictionary is empty.\n";
                else
                    dict.displayDescending(dict.root);
                break;
            case 7:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 7);
    return 0;
}




