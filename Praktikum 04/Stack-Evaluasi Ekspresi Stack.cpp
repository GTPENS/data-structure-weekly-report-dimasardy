//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> operandStack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            operandStack.push(ch - '0');
        }
        else {
            int secondOperand = operandStack.top();
            operandStack.pop();
            int firstOperand = operandStack.top();
            operandStack.pop();

            switch (ch) {
            case '+':
                operandStack.push(firstOperand + secondOperand);
                break;
            case '-':
                operandStack.push(firstOperand - secondOperand);
                break;
            case '*':
                operandStack.push(firstOperand * secondOperand);
                break;
            case '/':
                operandStack.push(firstOperand / secondOperand);
                break;
            }
        }
    }

    return operandStack.top();
}

int main() {
    string postfixExpression = "83+72*-";
    int evaluationResult = evaluatePostfix(postfixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;
    cout << "Result: " << evaluationResult << endl;

    return 0;
}

//Rangkuman Penjelasan
Program tersebut adalah sebuah program C++ yang mengevaluasi ekspresi matematika dalam bentuk postfix. Ekspresi postfix adalah notasi matematika di mana operator ditempatkan setelah operand-operand yang sesuai. Program menggunakan stack untuk menangani operand-operand dan operator dalam ekspresi postfix. Setiap kali program menemukan operand, itu dimasukkan ke dalam stack. Ketika program menemukan operator, ia mengambil dua operand teratas dari stack, melaksanakan operasi yang sesuai, dan hasilnya dimasukkan kembali ke dalam stack. Setelah iterasi selesai, hasil akhir evaluasi diperoleh dari nilai teratas stack. Dalam contoh ini, ekspresi postfix yang diberikan adalah "83+72*-" yang setelah dievaluasi menghasilkan nilai -25.