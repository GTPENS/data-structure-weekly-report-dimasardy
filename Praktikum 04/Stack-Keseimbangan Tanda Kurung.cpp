//Muhammad Dimas Ardiansyah
//5223600019
//Teknologi Game A

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalancedParenthesis(const string& expression) {
    stack<char> parenthesesStack;

    for (char ch : expression) {
        switch (ch) {
        case '(':
        case '[':
        case '{':
            parenthesesStack.push(ch);
            break;
        case ')':
            if (parenthesesStack.empty() || parenthesesStack.top() != '(') {
                return false;
            }
            parenthesesStack.pop();
            break;
        case ']':
            if (parenthesesStack.empty() || parenthesesStack.top() != '[') {
                return false;
            }
            parenthesesStack.pop();
            break;
        case '}':
            if (parenthesesStack.empty() || parenthesesStack.top() != '{') {
                return false;
            }
            parenthesesStack.pop();
            break;
        default:
            break;
        }
    }

    return parenthesesStack.empty();
}

int main() {
    string expression1 = "{()}";
    string expression2 = "{())}";

    cout << "Expression: " << expression1 << " is "
        << (isBalancedParenthesis(expression1) ? "balanced" : "not balanced") << endl;
    cout << "Expression: " << expression2 << " is "
        << (isBalancedParenthesis(expression2) ? "balanced" : "not balanced") << endl;

    return 0;
}

//Rangkuman Penjelasan
Program ini memeriksa keseimbangan tanda kurung dalam sebuah ekspresi matematika. Menggunakan stack, ia memeriksa apakah setiap tanda buka memiliki tanda tutup yang sesuai. Jika semua tanda kurung seimbang, program mengembalikan `true`, jika tidak, mengembalikan `false`. Dalam contoh ini, ekspresi pertama "{()}" seimbang, sedangkan yang kedua "{())}" tidak seimbang.