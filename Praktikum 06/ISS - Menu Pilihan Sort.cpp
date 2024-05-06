//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 10
int Data[MAX];

// Fungsi pertukaran bilangan
void Tukar(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort()
{
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

// Fungsi pengurutan penyisipan biner
void BinaryInsertSort()
{
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
    }
}

// Fungsi pengurutan seleksi
void SelectionSort()
{
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++)
            if (Data[k] > Data[j])
                k = j;
        Tukar(&Data[i], &Data[k]);
    }
}

int main()
{
    int i, choice;
    srand(0);

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        Data[i] = (int)rand() / 1000 + 1;
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    // Menu pilihan metode pengurutan
    cout << "\nPilih metode pengurutan:" << endl;
    cout << "1. Straight Insertion Sort" << endl;
    cout << "2. Binary Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        StraightInsertSort();
        break;
    case 2:
        BinaryInsertSort();
        break;
    case 3:
        SelectionSort();
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
        return 0;
    }

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (i = 0; i < MAX; i++)
    {
        cout << "Data ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}