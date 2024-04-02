//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

//1. Stack using a Queue
#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> dataQueue; // Queue untuk menyimpan elemen-elemen dalam tumpukan

public:
    // Menambahkan nilai ke dalam tumpukan
    void push(int newValue) {
        int size = dataQueue.size(); // Menyimpan ukuran awal queue
        dataQueue.push(newValue); // Menambahkan nilai baru ke dalam queue

        // Memindahkan elemen-elemen lain ke belakang agar elemen terbaru berada di depan
        for (int i = 0; i < size; i++) {
            dataQueue.push(dataQueue.front()); // Memindahkan elemen depan ke belakang
            dataQueue.pop(); // Menghapus elemen depan yang sudah dipindahkan
        }
    }

    // Menghapus elemen teratas dari tumpukan
    void pop() {
        if (dataQueue.empty()) { // Memeriksa apakah tumpukan kosong
            throw out_of_range("Stack is empty");
        }
        dataQueue.pop(); // Menghapus elemen teratas dari tumpukan
    }

    // Mengembalikan nilai teratas dari tumpukan tanpa menghapusnya
    int top() {
        if (dataQueue.empty()) { // Memeriksa apakah tumpukan kosong
            throw out_of_range("Stack is empty");
        }
        return dataQueue.front(); // Mengembalikan nilai teratas dari tumpukan
    }

    // Memeriksa apakah tumpukan kosong
    bool empty() {
        return dataQueue.empty(); // Mengembalikan true jika tumpukan kosong
    }
};

int main() {
    StackUsingQueue stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top: " << stack.top() << endl; // Menampilkan nilai teratas dari tumpukan

    stack.pop(); // Menghapus elemen teratas dari tumpukan

    cout << "Top: " << stack.top() << endl; // Menampilkan nilai teratas setelah penghapusan

    return 0;
}

//2. Josephus problem
#include <iostream>
#include <list>
using namespace std;

// Fungsi Josephus untuk menemukan orang yang selamat
int josephus(int totalPeople, int step) {
    list<int> people; // Membuat daftar orang menggunakan linked list

    // Membuat daftar orang dari 1 hingga totalPeople
    for (int i = 1; i <= totalPeople; i++) {
        people.push_back(i); // Menambahkan orang ke dalam daftar
    }

    auto iterator = people.begin(); // Inisialisasi iterator yang menunjuk ke awal daftar
    while (people.size() > 1) {
        // Memindahkan iterator sejauh step - 1 langkah
        for (int i = 0; i < step - 1; i++) {
            iterator++; // Memindahkan iterator ke depan sebanyak langkah - 1
            if (iterator == people.end()) {
                iterator = people.begin(); // Kembali ke awal jika sudah mencapai akhir daftar
            }
        }

        // Menghapus orang yang sedang ditunjuk oleh iterator
        auto next = iterator;
        next++;
        if (next == people.end()) {
            next = people.begin();
        }
        iterator = people.erase(iterator); // Menghapus orang dari daftar dan menggeser iterator
        iterator = next; // Menyesuaikan iterator dengan orang berikutnya
    }

    return people.front(); // Mengembalikan nomor orang yang selamat
}

int main() {
    int totalPeople, step;
    cout << "Masukkan jumlah orang: ";
    cin >> totalPeople; // Meminta input jumlah orang dari pengguna
    cout << "Masukkan nilai langkah: ";
    cin >> step; // Meminta input nilai langkah dari pengguna

    int survivor = josephus(totalPeople, step); // Memanggil fungsi Josephus
    cout << "Orang yang selamat adalah: " << survivor << endl; // Menampilkan nomor orang yang selamat

    return 0;
}
