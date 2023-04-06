#include <iostream>
#include <chrono>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = NULL;
        }
};

class Stack {
    private:
        Node* top;
    public:
        Stack() {
            top = NULL;
        }
        void push(int val) {
            Node* new_node = new Node(val);
            if (top == NULL) {
                top = new_node;
            }
            else {
                new_node->next = top;
                top = new_node;
            }
        }
        int pop() {
            if (top == NULL) {
                cout << "Stack Underflow\n";
                return -1;
            }
            else {
                int val = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
                return val;
            }
        }
        bool is_empty() {
            return top == NULL;}
        
        
        void display() {
            if (is_empty()) {
                cout << "Stack is empty\n";
            }
            else {
                cout << "Stack: ";
                Node* temp = top;
                while (temp != NULL) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main() {
      auto start_time = chrono::high_resolution_clock::now(); 

    
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();  // Output: Stack: 17 20 18 6 23 15 11 5 10 8
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();  // Output: Stack: 11 5 10 8
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();  // Output: Stack: 1 3 30 4 11 5 10 8
    
auto end_time = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
cout << "Execution time: " << duration << " ns" ;
return 0;
    
}
