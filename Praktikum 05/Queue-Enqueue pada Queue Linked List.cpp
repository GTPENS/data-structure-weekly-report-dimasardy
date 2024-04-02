//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

void Queue::enqueue(int newValue) {
    Node* newNode = new Node(newValue, nullptr);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

//Rangkuman Penjelasan
Program tersebut adalah implementasi sederhana dari struktur data antrian (queue) dalam C++. Fungsi `enqueue` menambahkan elemen baru ke antrian, dan menggunakan linked list untuk penyimpanan. Variabel `count` digunakan untuk melacak jumlah elemen dalam antrian.