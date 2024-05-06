//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortRecursive(int arr[], int l, int r) {
    int i, j, x;

    x = arr[(l + r) / 2];
    i = l;
    j = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quickSortRecursive(arr, l, j);
    if (i < r)
        quickSortRecursive(arr, i, r);
}

int main() {
    int arr[MAX];
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSortRecursive(arr, 0, MAX - 1);

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}