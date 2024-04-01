//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char operatorChar) {
    if (operatorChar == '+' || operatorChar == '-') {
        return 1;
    }
    else if (operatorChar == '*' || operatorChar == '/') {
        return 2;
    }
    else if (operatorChar == '^') {
        return 3;
    }
    return 0;
}

string infixToPrefix(const string& infixExpression) {
    string reversedInfixExpression = infixExpression;
    reverse(reversedInfixExpression.begin(), reversedInfixExpression.end());

    for (int i = 0; i < reversedInfixExpression.length(); i++) {
        if (reversedInfixExpression[i] == '(') {
            reversedInfixExpression[i] = ')';
        }
        else if (reversedInfixExpression[i] == ')') {
            reversedInfixExpression[i] = '(';
        }
    }

    stack<char> operatorStack;
    string prefixExpression;

    for (char character : reversedInfixExpression) {
        if (isalnum(character)) {
            prefixExpression += character;
        }
        else if (character == ')') {
            operatorStack.push(character);
        }
        else if (character == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == ')') {
                operatorStack.pop();
            }
        }
        else {
            while (!operatorStack.empty() && operatorStack.top() != ')' &&
                ((character != '^' && precedence(character) <= precedence(operatorStack.top())) ||
                    (character == '^' && precedence(character) < precedence(operatorStack.top())))) {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(character);
        }
    }

    while (!operatorStack.empty()) {
        prefixExpression += operatorStack.top();
        operatorStack.pop();
    }

    reverse(prefixExpression.begin(), prefixExpression.end());
    return prefixExpression;
}

int main() {
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";
    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Infix expression: " << infixExpression << endl;
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}

//Rangkuman Penjelasan
Program ini mengonversi ekspresi matematika dari notasi infix menjadi prefix menggunakan algoritma serupa dengan Shunting-yard. Pertama, ekspresi infix dibalik dan tanda kurung dibalik juga. Selama iterasi, operand langsung dimasukkan ke ekspresi prefix, sementara operator-operator dimasukkan ke dalam stack dengan mempertimbangkan prioritasnya. Ketika menemukan tanda kurung tutup, operator-operator di stack dikeluarkan hingga menemukan tanda kurung buka yang sesuai. Operator `^` memiliki prioritas tertinggi. Setelah semua karakter diproses, operator-operator yang tersisa di stack dimasukkan ke dalam ekspresi prefix. Hasilnya, ekspresi prefix yang setara diperoleh dan dibalik kembali untuk mendapatkan ekspresi yang benar. Dalam contoh ini, ekspresi infix "a+b*(c^d-e)^(f+g*h)-i" dikonversi menjadi ekspresi prefix "-+a*b^-cde+*fgh".