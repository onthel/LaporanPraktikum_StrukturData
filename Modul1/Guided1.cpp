#include <iostream>
using namespace std;

int main (){
    char op;
    float num1, num2;

    cout << "Masukkan operator +,-,*,/ : "; 
    cin >> op;
    
    cout << "Masukkan dua angka yang akan dioperasikan :";
    cin >> num1 >> num2;
    switch (op) 
    {
    case '+':
        cout << num1 + num2;
        break;
    case '-':
        cout << num1 - num2;
        break;
    case '*':
        cout << num1 * num2;
        break;
    case '/':
        cout << num1 / num2;
        break;
    
    default:
        cout << "Error! operator is not correct";
        break;
    }
    return 0;
    //syarief2311102072
}   