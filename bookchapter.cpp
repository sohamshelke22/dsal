#include <iostream>
#include <cstring>
using namespace std;

struct node {
    char name[20];
    node *next, *down;
};

class Gll {
    node *head = nullptr;

    node* createNode() {
        node *p = new node;
        p->next = p->down = nullptr;
        cout << "\nEnter the name: ";
        cin >> p->name;
        return p;
    }

public:
    void insertBook() {
        if (!head) {
            head = createNode();
        } else {
            cout << "\nBook already exists.";
        }
    }

    void insertChapter() {
        if (!head) {
            cout << "\nThere is no book.";
        } else {
            int n;
            cout << "\nHow many chapters to insert: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                node *chapter = createNode();
                if (!head->down) {
                    head->down = chapter;
                } else {
                    node *temp = head->down;
                    while (temp->next) {
                        temp = temp->next;
                    }
                    temp->next = chapter;
                }
            }
        }
    }

    void insertSection() {
        if (!head || !head->down) {
            cout << "\nNo chapters available to add sections.";
        } else {
            int n;
            cout << "\nHow many sections to insert in each chapter: ";
            cin >> n;
            node *chapter = head->down;
            while (chapter) {
                cout << "\nAdding sections to chapter: " << chapter->name;
                for (int i = 0; i < n; i++) {
                    node *section = createNode();
                    if (!chapter->down) {
                        chapter->down = section;
                    } else {
                        node *temp = chapter->down;
                        while (temp->next) {
                            temp = temp->next;
                        }
                        temp->next = section;
                    }
                }
                chapter = chapter->next;
            }
        }
    }

    void insertSubsection() {
        if (!head || !head->down) {
            cout << "\nNo chapters/sections available to add subsections.";
        } else {
            int n;
            cout << "\nHow many subsections to insert into each section: ";
            cin >> n;
            node *chapter = head->down;
            while (chapter) {
                node *section = chapter->down;
                while (section) {
                    cout << "\nAdding subsections to section: " << section->name;
                    for (int i = 0; i < n; i++) {
                        node *subsection = createNode();
                        if (!section->down) {
                            section->down = subsection;
                        } else {
                            node *temp = section->down;
                            while (temp->next) {
                                temp = temp->next;
                            }
                            temp->next = subsection;
                        }
                    }
                    section = section->next;
                }
                chapter = chapter->next;
            }
        }
    }

    void display() {
        if (!head) {
            cout << "\nNo book available.";
        } else {
            cout << "\nBOOK: " << head->name;
            node *chapter = head->down;
            while (chapter) {
                cout << "\n  CHAPTER: " << chapter->name;
                node *section = chapter->down;
                while (section) {
                    cout << "\n    SECTION: " << section->name;
                    node *subsection = section->down;
                    while (subsection) {
                        cout << "\n      SUBSECTION: " << subsection->name;
                        subsection = subsection->next;
                    }
                    section = section->next;
                }
                chapter = chapter->next;
            }
        }
    }
};

int main() {
    Gll g;
    int choice;
    while (true) {
        cout << "\n\nEnter your choice:";
        cout << "\n 1. Insert Book";
        cout << "\n 2. Insert Chapter";
        cout << "\n 3. Insert Section (to all chapters)";
        cout << "\n 4. Insert Subsection (to all sections)";
        cout << "\n 5. Display Book";
        cout << "\n 6. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                g.insertBook();
                break;
            }
            case 2: {
                g.insertChapter();
                break;
            }
            case 3: {
                g.insertSection();
                break;
            }
            case 4: {
                g.insertSubsection();
                break;
            }
            case 5: {
                g.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid option.";
                break;
            }
        }
    }
    return 0;
}




