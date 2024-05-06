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
    int i;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    ShellSort();

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}