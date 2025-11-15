#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = nullptr;
        }
};

class Stack {
    private:
        Node* top;
    public:
        Stack(){
            top = nullptr;
        }
    
    void push(int value){
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(!top){
            cout << "Stack Underflow!\n";
            return;
        }

        Node* t = top;
        top = top->next;
        delete t;
    }

    bool isEmpty(){
        return top == nullptr;
    }
    
    void display(){
        Node* t = top;

        cout << "Stack (top->bottom): ";
        while(t){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    int peek(){
        return top->data;
    }

    ~Stack(){
        Node* curr = top;
        while(curr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        top = nullptr;
    }
};

int main() {
    Stack myStack;

    myStack.push(4); 
    myStack.push(2); 
    myStack.push(6); 
    myStack.push(13);

    myStack.display();

    return 0;
}
