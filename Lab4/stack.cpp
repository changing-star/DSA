#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int capacity;
        int *arr;
    public:
        Stack(int size){
            capacity = size;
            arr = new int[capacity]; //Array
            top = -1; //Empty Stack 
        }
    ~Stack(){
        delete[] arr;
    }

    void push(int value){
        if(top == capacity - 1) cout << "Stack Overflow!\n";
        else {
            ++top;
            arr[top] = value;
        }
    };

    void pop(){
        if(top == -1) cout << "Stack Underflow!\n";
        else top--;
    }

    int peek(){
        if(top == -1) cout << "Stack Underflow!\n";
        return arr[top];
    
    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack: \n";
            for(int i = top; i >= 0; i--){
                cout << arr[i] << "\n";
            }
        }
    }
};

int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();

    cout << "Top after pop: " << s.peek() << endl;

    return 0;
}