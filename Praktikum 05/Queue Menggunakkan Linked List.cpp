//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* nextNode;
        Node(int v, Node* n) : data(v), nextNode(n) {} 
    };

    Node* firstNode = nullptr;
    Node* lastNode = nullptr;
    int elementCount = 0;

public:
    int getSize() { return elementCount; }
    bool isEmpty() { return elementCount == 0; }

    void printQueue() {
        Node* tempNode = firstNode;
        while (tempNode != nullptr) {
            cout << tempNode->data << " ";
            tempNode = tempNode->nextNode;
        }
        cout << endl;
    }

    int peekFront() {
        if (isEmpty()) {
            throw invalid_argument("QueueEmptyException");
        }
        return firstNode->data;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value, nullptr);
        if (firstNode == nullptr) {
            firstNode = lastNode = newNode;
        } else {
            lastNode->nextNode = newNode;
            lastNode = newNode;
        }
        elementCount++;
    }

    int dequeue() {
        if (isEmpty()) {
            throw invalid_argument("QueueEmptyException");
        }
        int value = firstNode->data;
        Node* tempNode = firstNode;
        firstNode = firstNode->nextNode;
        delete tempNode;
        elementCount--;
        return value;
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 100; i++) {
        q.enqueue(i);
    }
    for (int i = 1; i <= 50; i++) {
        q.dequeue();
    }
    q.printQueue();
    return 0;
}

//Rangkuman Penjelasan
Program tersebut adalah implementasi sederhana dari struktur data antrian (queue) menggunakan linked list dalam C++. Antrian mengikuti aturan FIFO (First In First Out). Program ini memiliki fungsi untuk menambahkan elemen ke antrian (`enqueue`), menghapus elemen dari antrian (`dequeue`), serta melihat elemen pertama tanpa menghapusnya (`peekFront`). Program menguji implementasi antrian dengan memasukkan 100 elemen ke antrian, menghapus 50 elemen, dan mencetak sisa elemen dalam antrian.