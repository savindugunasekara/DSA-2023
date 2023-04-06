#include <iostream>
#include<chrono>
using namespace std;

#define max 20

int stack_arr[max];
int top = -1;

void Push(int data) {
    if (top == max - 1) {
        cout << "stack overflow" << endl;
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int Pop() {
    int value;
    if (top == -1) {
        throw "stack underflow";
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

void Display() {
    int i;
    if (top == -1) {
        cout << "stack is empty" << endl;
        return;
    }
    cout << "Stack: ";
    for (i = top; i >= 0; i--) {
        cout << stack_arr[i] << " ";
    }
    cout << endl;
}

int main(){
  auto start_time = chrono::high_resolution_clock::now(); 

    try {
        Push(8);
        Push(10);
        Push(5);
        Push(11);
        Push(15);
        Push(23);
        Push(6);
        Push(18);
        Push(20);
        Push(17);
        Display();

        Pop();
        Pop();
        Pop();
        Pop();
        Pop();
        Display();

        Push(4);
        Push(30);
        Push(3);
        Push(1);
        Display();
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    
auto end_time = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
cout << "Execution time: " << duration << " ns" ;
    
    return 0;
}