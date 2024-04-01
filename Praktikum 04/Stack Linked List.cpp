//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val, Node* n = nullptr) {
        data = val;
        next = n;
    }
};

class ListStack {
private:
    Node* top;
    int count;

public:
    ListStack() {
        top = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    int peek() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return top->data;
    }

    void push(int value) {
        top = new Node(value, top);
        count++;
    }

    int pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return value;
    }
};

int main() {
    ListStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}

//Rangkuman Penjelasam
Program tersebut adalah implementasi stack menggunakan linked list dalam bahasa C++. Stack digunakan untuk menyimpan dan mengakses data dengan prinsip Last In First Out (LIFO). Program ini memiliki dua kelas utama: `Node` untuk merepresentasikan elemen dalam stack, dan `ListStack` untuk implementasi stack menggunakan linked list. Elemen-elemen ditambahkan ke stack menggunakan metode `push`, dihapus dari stack menggunakan metode `pop`, dan nilai teratas dari stack dapat dilihat menggunakan metode `peek`.