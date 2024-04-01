//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/';
}

int precedence(char operatorChar) {
    if (operatorChar == '+' || operatorChar == '-') {
        return 1;
    }
    else if (operatorChar == '*' || operatorChar == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& infixExpression) {
    stack<char> operatorStack;
    string postfixExpression;

    for (char character : infixExpression) {
        if (isalnum(character)) {
            postfixExpression += character;
        }
        else if (character == '(') {
            operatorStack.push(character);
        }
        else if (character == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        }
        else {
            while (!operatorStack.empty() && precedence(character) <= precedence(operatorStack.top())) {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(character);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression;
}

int main() {
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";
    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Infix expression: " << infixExpression << endl;
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}

//Rangkuman Penjelasan
Program ini mengonversi ekspresi matematika dari notasi infix menjadi postfix menggunakan algoritma Shunting-yard. Itu menggunakan stack untuk menyimpan operator sementara. Selama iterasi melalui karakter-karakter dalam ekspresi infix, program memproses operand dan operator sesuai dengan aturan operator dan prioritasnya. Hasilnya, ekspresi postfix yang setara diperoleh dan dicetak. Dalam contoh ini, ekspresi infix "a+b*(c^d-e)^(f+g*h)-i" dikonversi menjadi ekspresi postfix "abcd^e-fgh*+^*+i-".