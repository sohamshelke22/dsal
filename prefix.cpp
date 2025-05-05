#include<iostream>
#include<string.h>
using namespace std;

struct node {
    char data;
    node *left;
    node *right;
};

class tree {
    char prefix[50];
public:
    node *top;
    tree() {
        top = NULL;
    }
    void expression(char []);
    void display(node *);
    void deletion(node *node);
};

class stack1 {
public:
    node *data[30];
    int top;
    stack1() {
        top = -1;
    }
    int empty() {
        return top == -1;
    }
    void push(node *p) {
        data[++top] = p;
    }

    node *pop() {
        return data[top--];
    }
};

void tree::expression(char prefix[]) {
    stack1 s;
    node *t1, *t2, *temp;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        temp = new node;
        temp->left = NULL;
        temp->right = NULL;

        if (isalpha(prefix[i])) {
            temp->data = prefix[i];
            s.push(temp);
        } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            t2 = s.pop();
            t1 = s.pop();
            temp->data = prefix[i];
            temp->left = t2;
            temp->right = t1;
            s.push(temp);
        }
    }
    top = s.pop();  
}

void tree::display(node *top) {
    if (top == NULL) return;

    stack1 s1, s2;
    node *T = top;
    s1.push(T);

    while (!s1.empty()) {
        T = s1.pop();
        s2.push(T);

        if (T->left != NULL)
            s1.push(T->left);
        if (T->right != NULL)
            s1.push(T->right);
    }

    while (!s2.empty()) {
        top = s2.pop();
        cout << top->data;
    }
    cout << endl;
}

void tree::deletion(node *node) {
    if (node == NULL)
        return;
    deletion(node->left);
    deletion(node->right);
    cout << "Deleting node: " << node->data << endl;
    delete node; 
}

int main() {
    tree t;
    char exp1[20];
    int ch;

    do {
        cout << "1 -> Enter prefix expression" << endl;
        cout << "2 -> Display postfix Expression" << endl;
        cout << "3 -> Deletion" << endl;
        cout << "4 -> Exit" << endl;
        cout << "Choose an option (1-4):\t";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter the expression (eg.: +--a*bc/def):\t";
                cin >> exp1;
                t.expression(exp1);
                break;
            case 2:
                t.display(t.top);
                break;
            case 3:
                t.deletion(t.top);
                t.top = NULL;
                break;
            case 4:
                cout << "\n// END OF CODE\n" << endl;
                break;
            default:
                cout << "Choose a valid option (1-4)." << endl;
                break;
        }
    } while (ch != 4);
}

