//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <vector>

using namespace std;

// Function to display the array
void printArray(vector<int>& arrayToPrint) {
    for (int num : arrayToPrint) {
        cout << num << " ";
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(vector<int>& arrayToSort) {
    int size = arrayToSort.size();
    for (int i = 1; i < size; i++) {
        int key = arrayToSort[i];
        int j = i - 1;
        while (j >= 0 && arrayToSort[j] > key) {
            arrayToSort[j + 1] = arrayToSort[j];
            j--;
        }
        arrayToSort[j + 1] = key;
        cout << "Iteration " << i << ": ";
        printArray(arrayToSort);
    }
}

// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arrayToSort) {
    int size = arrayToSort.size();
    for (int i = 1; i < size; i++) {
        int key = arrayToSort[i];
        int left = 0, right = i;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (key < arrayToSort[mid])
                right = mid;
            else
                left = mid + 1;
        }
        for (int j = i; j > left; j--) {
            arrayToSort[j] = arrayToSort[j - 1];
        }
        arrayToSort[left] = key;
        cout << "Iteration " << i << ": ";
        printArray(arrayToSort);
    }
}

// Selection Sort
void selectionSort(vector<int>& arrayToSort) {
    int size = arrayToSort.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arrayToSort[j] < arrayToSort[minIndex])
                minIndex = j;
        }
        swap(arrayToSort[i], arrayToSort[minIndex]);
        cout << "Iteration " << i + 1 << ": ";
        printArray(arrayToSort);
    }
}

int main() {
    vector<int> arrayToSort = { 64, 25, 12, 22, 11 };

    cout << "Insertion Sort:" << endl;
    insertionSort(arrayToSort);
    cout << endl;

    arrayToSort = { 64, 25, 12, 22, 11 };
    cout << "Binary Insertion Sort:" << endl;
    binaryInsertionSort(arrayToSort);
    cout << endl;

    arrayToSort = { 64, 25, 12, 22, 11 };
    cout << "Selection Sort:" << endl;
    selectionSort(arrayToSort);

    return 0;
}