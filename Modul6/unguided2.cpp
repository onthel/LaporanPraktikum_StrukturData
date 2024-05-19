#include <iostream>
#include <string>
using namespace std;

const int maksimal = 100;
char stack[maksimal];
int top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void push(char data) {
    if (!isFull()) {
        stack[top] = data;
        top++;
    }
}

char pop() {
    if (!isEmpty()) {
        top--;
        return stack[top];
    }
    return '\0';
}

string reverseString(string str) {
    int length = str.length();
    
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }

    string reversed = "";
    while (!isEmpty()) {
        reversed += pop();
    }
    
    return reversed;
}

int main() {
    string input;
    cout << "Masukkan kata: ";
    getline(cin, input);
    
    string reversed = reverseString(input);
    cout << "Hasil: " << reversed << endl;
    
    return 0;
}//2311102072