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
void insertionSort(vector<int>& arrayToSort, int& comparisonCount, int& shiftCount) {
    int size = arrayToSort.size();
    comparisonCount = 0;
    shiftCount = 0;
    for (int i = 1; i < size; i++) {
        int key = arrayToSort[i];
        int j = i - 1;
        while (j >= 0 && arrayToSort[j] > key) {
            arrayToSort[j + 1] = arrayToSort[j];
            j--;
            shiftCount++;
            comparisonCount++;
        }
        arrayToSort[j + 1] = key;
        shiftCount++;
    }
}

// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arrayToSort, int& comparisonCount, int& shiftCount) {
    int size = arrayToSort.size();
    comparisonCount = 0;
    shiftCount = 0;
    for (int i = 1; i < size; i++) {
        int key = arrayToSort[i];
        int left = 0, right = i;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (key < arrayToSort[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
            comparisonCount++;
        }
        for (int j = i; j > left; j--) {
            arrayToSort[j] = arrayToSort[j - 1];
            shiftCount++;
        }
        arrayToSort[left] = key;
        shiftCount++;
    }
}

// Selection Sort
void selectionSort(vector<int>& arrayToSort, int& comparisonCount, int& shiftCount) {
    int size = arrayToSort.size();
    comparisonCount = 0;
    shiftCount = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arrayToSort[j] < arrayToSort[minIndex]) {
                minIndex = j;
            }
            comparisonCount++;
        }
        swap(arrayToSort[i], arrayToSort[minIndex]);
        shiftCount += 3;  // Each swap requires 3 shifts
    }
}

int main() {
    vector<int> arrayToSort = { 64, 25, 12, 22, 11 };

    int comparisons, shifts;

    cout << "Insertion Sort:" << endl;
    insertionSort(arrayToSort, comparisons, shifts);
    printArray(arrayToSort);
    cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << endl;
    cout << endl;

    arrayToSort = { 64, 25, 12, 22, 11 };
    cout << "Binary Insertion Sort:" << endl;
    binaryInsertionSort(arrayToSort, comparisons, shifts);
    printArray(arrayToSort);
    cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << endl;
    cout << endl;

    arrayToSort = { 64, 25, 12, 22, 11 };
    cout << "Selection Sort:" << endl;
    selectionSort(arrayToSort, comparisons, shifts);
    printArray(arrayToSort);
    cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << endl;

    return 0;
}