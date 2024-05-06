//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;
int Data[MAX];

// Prosedur menukar data
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort() {
    int i, j;
    for (i = 1; i < MAX - 1; i++) {
        for (j = MAX - 1; j >= i; j--) {
            if (Data[j - 1] > Data[j]) {
                Tukar(&Data[j - 1], &Data[j]);
            }
        }
    }
}

// Prosedur pengurutan metode Shell
void ShellSort() {
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;

    while (Jarak > 1) {
        Jarak = Jarak / 2;
        Sudah = false;

        while (!Sudah) {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++) {
                i = j + Jarak;
                if (Data[j] > Data[i]) {
                    Tukar(&Data[j], &Data[i]);
                    Sudah = false;
                }
            }
        }
    }
}

int main() {
    int i, pilihan;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Shell Sort" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
        BubbleSort();
        cout << "\nData setelah diurutkan dengan Bubble Sort:" << endl;
        break;
    case 2:
        ShellSort();
        cout << "\nData setelah diurutkan dengan Shell Sort:" << endl;
        break;
    default:
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    // Menampilkan data setelah diurutkan
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}