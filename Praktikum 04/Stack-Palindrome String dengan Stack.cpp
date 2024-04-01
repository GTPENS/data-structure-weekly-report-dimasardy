//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& inputString) {
    stack<char> charStack;
    string tempString = inputString;

    // Menghapus spasi dan mengubah ke huruf kecil
    tempString.erase(remove_if(tempString.begin(), tempString.end(), ::isspace), tempString.end());
    transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);

    // Mendorong setengah karakter ke dalam stack
    for (int i = 0; i < tempString.length() / 2; i++) {
        charStack.push(tempString[i]);
    }

    // Memulai dari tengah (atau tengah + 1 jika panjang ganjil)
    int start = tempString.length() % 2 == 0 ? tempString.length() / 2 : (tempString.length() / 2) + 1;

    // Memastikan karakter yang sesuai dengan stack
    for (int i = start; i < tempString.length(); i++) {
        if (tempString[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string inputString;
    cout << "Masukkan sebuah string: ";
    getline(cin, inputString);

    cout << "\"" << inputString << "\" is " << (isPalindrome(inputString) ? "a palindrome" : "not a palindrome") << endl;

    return 0;
}

//Rangkuman Penjelasan
Program tersebut adalah program C++ untuk memeriksa apakah sebuah string adalah palindrom atau tidak. Ini dilakukan dengan menggunakan sebuah stack untuk membandingkan setengah karakter pertama dengan setengah karakter terakhir dari string. Program akan menghapus spasi dan mengubah huruf-huruf menjadi huruf kecil sebelum melakukan pengecekan.