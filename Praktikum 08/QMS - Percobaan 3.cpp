//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid;
    k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid + 1, right);
    }
}

int main() {
    int arr[MAX];
    int temp[MAX];
    srand(time(NULL));

    cout << "Data sebelum terurut: ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, temp, 0, MAX - 1);

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}