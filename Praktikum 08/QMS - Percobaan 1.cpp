//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX 10
#define MAXSTACK 10

struct Stack {
    int left;
    int right;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortNonRecursive(int arr[]) {
    Stack stack[MAXSTACK];
    int top = 0;
    int l, r, i, j, x;

    stack[top].left = 0;
    stack[top].right = MAX - 1;
    top++;

    while (top > 0) {
        top--;
        l = stack[top].left;
        r = stack[top].right;

        while (r > l) {
            i = l;
            j = r;
            x = arr[(l + r) / 2];

            while (i <= j) {
                while (arr[i] < x) i++;
                while (arr[j] > x) j--;

                if (i <= j) {
                    swap(&arr[i], &arr[j]);
                    i++;
                    j--;
                }
            }

            if (l < j) {
                top++;
                stack[top].left = l;
                stack[top].right = j;
            }

            r = j;
        }
    }
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

    quickSortNonRecursive(arr);

    cout << "Data setelah terurut: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}