#include <iostream>
#include <string>
using namespace std;

const int maksimal = 100;
char stack[maksimal];
int top = 0;

bool isFull(){
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void push(char data){
    if (!isFull()){
        stack[top] = data;
        top++;
    }
}

char pop(){
    if (!isEmpty()){
        top--;
        return stack[top];
    }
    return '\0';
}

bool isPalindrome(string str){
    int length = str.length();
    
    for (int i = 0; i < length; i++){
        push(str[i]);
    }

    for (int i = 0; i < length; i++){
        if (str[i] != pop()){
            return false;
        }
    }
    return true;
}

int main(){
    string input;
    cout << "Masukkan kata: ";
    cin >> input;
    
    if (isPalindrome(input)){
        cout << "Keterangan: Kata tersebut termasuk palindrom" << endl;
    } else {
        cout << "Keterangan: Kata tersebut bukan palindrom" << endl;
    }
    
    return 0;
}//2311102072