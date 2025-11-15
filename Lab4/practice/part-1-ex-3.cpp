#include <iostream>
#include <string>

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

    int pop(){
        if(!top){
            cout << "Stack Underflow!\n";
            return;
        }

        Node* t = top;
        top = top->next;

        return t->data;
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

void BrowserHistory() {
    cout << "--- 3. Browser History Navigation ---\n";

    Stack backStack;
    Stack forwardStack;

    int currentPage = 100;

    auto printState = [&]() {
        cout << "Current Page: " << currentPage << endl;
        backStack.display();
        cout << "Forward Stack: ";
    };

    cout << "\nACTION: Visiting 101, 102, 103...\n";
    backStack.push(currentPage);
    currentPage = 101;
    backStack.push(currentPage);
    currentPage = 102;
    backStack.push(currentPage);
    currentPage = 103;

    printState(); 
    
    if (!backStack.isEmpty()) {
        int pageToMove = currentPage;
        currentPage = backStack.peek();

        backStack.pop(); 
        forwardStack.push(pageToMove); 
        currentPage = 102; 
    }
    
    if (!backStack.isEmpty()) {
        int pageToMove = currentPage;
        backStack.pop();
        forwardStack.push(pageToMove);
        currentPage = 101;
    }
    
    cout << "After 2 Backs:\n";
    cout << "Current Page: " << currentPage << endl;
    backStack.display();
    forwardStack.display();

    cout << "\nACTION: Clicking FORWARD (x1)\n";
    if (!forwardStack.isEmpty()) {
        int pageToMove = forwardStack.pop();
        backStack.push(currentPage);
        currentPage = pageToMove;
    }

    cout << "After 1 Forward:\n";
    cout << "Current Page: " << currentPage << endl;
    backStack.display();
    forwardStack.display();
}