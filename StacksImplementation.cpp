// Stack Implementation
#include <iostream>
using namespace std;
// the default capacity of the stack
#define MAX 1000

// class to represent a stack
class Stack {
    int top;

public:
    int a[MAX]{}; // maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    [[nodiscard]] bool isEmpty() const;
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
// utility function to pop a top element from the stack
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
// utility function to return the top element of the stack
int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
// utility function to check if the stack is empty or not
bool Stack::isEmpty() const {
    return (top < 0);
}

// driver program
int main() {
    class Stack s;
    // push
    cout << "\tStack Push" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // pop
    cout << "\n\tStack Pop" << endl;
    cout << s.pop() << " popped from stack\n";
    cout << s.pop() << " popped from stack\n";
    cout << s.pop() << " popped from stack\n";
    //print all elements in stack 
    cout << "\nElements present in stack : ";
    while(!s.isEmpty()) {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }

    return 0;
}
