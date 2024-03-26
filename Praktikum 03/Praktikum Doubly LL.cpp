//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
using namespace std;

struct LinkedListNode {
    int value;
    LinkedListNode *next;
    LinkedListNode *prev;
};

LinkedListNode *listHead = NULL, *listTail = NULL;

void insertAtHead(int value) {
    LinkedListNode* newNode = new LinkedListNode();
    if (listHead == NULL && listTail == NULL) {
        listHead = newNode;
        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = NULL;
    } else if (listHead == NULL && listTail != NULL) {
        listHead = newNode;
        newNode->value = value;
        newNode->next = listTail;
        newNode->prev = NULL;
        listTail->prev = newNode;
    } else if (listHead != NULL && listTail == NULL) {
        newNode->value = value;
        newNode->next = listHead;
        listHead->prev = newNode;
        listTail = listHead;
        listHead = newNode;
    } else {
        newNode->value = value;
        newNode->next = listHead;
        listHead->prev = newNode;
        listHead = newNode;
    }
}

void insertAtTail(int value) {
    LinkedListNode *newNode = new LinkedListNode();
    if (listHead == NULL && listTail == NULL) {
        listTail = newNode;
        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = NULL;
    } else if (listHead != NULL && listTail == NULL) {
        listTail = newNode;
        newNode->value = value;
        newNode->prev = listHead;
        newNode->next = NULL;
        listHead->next = newNode;
    } else if (listHead == NULL && listTail != NULL) {
        newNode->value = value;
        newNode->prev = listTail;
        newNode->next = NULL;
        listTail->next = newNode;
        listHead = listTail;
        listTail = newNode;
    } else {
        newNode->value = value;
        newNode->prev = listTail;
        newNode->next = NULL;
        listTail->next = newNode;
        listTail = newNode;
    }
}

void insertAfterNode(LinkedListNode* prevNode, int value) {
    LinkedListNode* newNode = new LinkedListNode();
    newNode->value = value;
    if (prevNode == listTail) {
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = NULL;
        listTail = newNode;
    } else {
        LinkedListNode *Temp = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = Temp;
        Temp->prev = newNode;
    }
}

void insertBeforeNode(LinkedListNode* nextNode, int value) {
    LinkedListNode* newNode = new LinkedListNode();
    newNode->value = value;
    if (nextNode == listHead) {
        newNode->next = listHead;
        newNode->prev = NULL;
        listHead->prev = newNode;
        listHead = newNode;
    } else {
        LinkedListNode* Temp = nextNode->prev;
        Temp->next = newNode;
        newNode->prev = Temp;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
}

void displayFiFo() {
    LinkedListNode *temp = listHead;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayLiFo() {
    LinkedListNode *temp = listTail;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void deleteNode(int value) {
    LinkedListNode *current = listHead;

    while (current != NULL) {
        if (current->value == value) {
            if (current == listHead) {
                listHead = current->next;
                listHead->prev = NULL;
                delete current;
                return;
            } else if (current == listTail) {
                listTail = current->prev;
                listTail->next = NULL;
                delete current;
                return;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
        }
        current = current->next;
    }
    cout << "Data not found" << endl;
}

void deleteHead() {
    if (listHead != NULL) {
        LinkedListNode *temp = listHead;
        if (listHead->next != NULL) {
            listHead = listHead->next;
            listHead->prev = NULL;
            delete temp;
        } else {
            listHead = NULL;
        }
    } else {
        cout << "Head not found" << endl;
    }
}

void deleteTail() {
    if (listTail != NULL) {
        LinkedListNode *temp = listTail;
        if (listTail->prev != NULL) {
            listTail = listTail->prev;
            listTail->next = NULL;
            delete temp;
        } else {
            listTail = NULL;
        }
    } else {
        cout << "Tail not found" << endl;
    }
}

LinkedListNode* findNode(int value) {
    LinkedListNode* current = listHead;
    while (current != NULL && current->value != value) {
        current = current->next;
    }
    return current;
}

int main() {
    int x, choice;
    do {
        cout << "\nLinked List Operation Menu:\n";
        cout << "1.  Insert Data at Head\n";
        cout << "2.  Insert Data at Tail\n";
        cout << "3.  Search for a Node\n";
        cout << "4.  Display Linked List using FiFo method\n";
        cout << "5.  Display Linked List using LiFo method\n";
        cout << "6.  Delete a Specific Node\n";
        cout << "7.  Delete Head\n";
        cout << "8.  Delete Tail\n";
        cout << "9.  Add Data after a specific Node\n";
        cout << "10. Add Data before a specific Node\n";
        cout << "11. Exit Program\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout <<"Enter Data to insert: ";
                cin >> x;
                insertAtHead(x);
                break;
            case 2:
                cout << "Enter Data to insert: ";
                cin >> x;
                insertAtTail(x);
                break;
            case 3:
                cout << "Enter Data to search: ";
                cin >> x;
                if (findNode(x) != NULL) {
                    cout << "Data found: " << findNode(x)->value << endl;
                } else {
                    cout << "Data not found." << endl;  
                }
                break;
            case 4:
                cout << "Data: ";
                displayFiFo();
                break;
            case 5:
                cout << "Data: ";
                displayLiFo();
                break;
            case 6:
                cout << "Enter Data to delete: ";
                cin >> x;
                deleteNode(x);
                break;
            case 7:
                deleteHead();
                break;
            case 8:
                deleteTail();
                break;
            case 9:
                cout << "Enter Node value in the list: ";
                cin >> x;
                if (findNode(x) != NULL) {
                LinkedListNode *target = findNode(x);
                cout << "Enter Data to insert after node " << x << ": ";
                cin >> x;
                insertAfterNode(target, x);
                } else {
                cout << "Node not found." << endl;
                }
                break;
            case 10:
                cout << "Enter Node value in the list: ";
                cin >> x;
                if (findNode(x) != NULL) {
                LinkedListNode *target = findNode(x);
                cout << "Enter Data to insert before node " << x << ": ";
                cin >> x;
                insertBeforeNode(target, x);
                } else {
                cout << "Node not found." << endl;
                }
                break;
            case 11:
                cout << "Thank you for using this program.\n";
                break;
                default:
                if (choice > 11) {
                cout << "Invalid choice! Enter a number between 1-11.\n";
                } else {
                cout << "Invalid choice!\n";
                }
                break;
      }
    }while (choice != 11);

  return 0;
}