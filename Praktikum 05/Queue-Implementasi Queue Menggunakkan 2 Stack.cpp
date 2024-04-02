//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> stack1, stack2;

public:
    void enqueue(int newValue) {
        stack1.push(newValue);
    }

    int dequeue() {
        int extractedValue;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                extractedValue = stack1.top();
                stack1.pop();
                stack2.push(extractedValue);
            }
        }
        if (stack2.empty()) {
            throw invalid_argument("QueueEmptyException");
        }
        extractedValue = stack2.top();
        stack2.pop();
        return extractedValue;
    }
};

int main() {
    QueueUsingStack que;
    que.enqueue(1);
    que.enqueue(11);
    que.enqueue(111);
    cout << que.dequeue() << endl;  
    que.enqueue(2);
    que.enqueue(21);
    que.enqueue(211);
    cout << que.dequeue() << endl;  
    cout << que.dequeue() << endl;  
    return 0;
}

//Rangkuman Penjelasan
Program tersebut adalah implementasi antrian (queue) menggunakan dua tumpukan (stack) dalam bahasa C++. Fungsi `enqueue` menambahkan elemen ke antrian, sementara fungsi `dequeue` menghapus dan mengembalikan elemen dari antrian sesuai dengan aturan FIFO. Dua tumpukan (`stack1` dan `stack2`) digunakan untuk menyimpan elemen antrian. Program diuji dengan menambahkan dan menghapus beberapa elemen dari antrian.