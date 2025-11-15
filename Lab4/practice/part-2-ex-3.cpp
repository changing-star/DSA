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


void UndoRedoTextEditor() {
    cout << "--- 7. Undo-Redo Text Editor Simulation ---\n";

    Stack undoStack;
    Stack redoStack;
    int currentState = 0;

    cout << "--- A. Performing New Edits ---\n";

    undoStack.push(currentState);
    currentState = 1;
    redoStack = Stack();
    undoStack.display();
    redoStack.display();

    undoStack.push(currentState);
    currentState = 2;
    undoStack.display();
    redoStack.display();

    undoStack.push(currentState);
    currentState = 3;
    undoStack.display();
    redoStack.display();
    
    cout << "\n--- B. Performing UNDO (x2) ---\n";

    if (!undoStack.isEmpty()) {
        redoStack.push(currentState); 
        undoStack.pop();
        
        currentState = 2; 
    }
    undoStack.display();
    redoStack.display();

    if (!undoStack.isEmpty()) {
        redoStack.push(currentState);
        undoStack.pop();
        currentState = 1;
    }
    undoStack.display();
    redoStack.display();

    cout << "\n--- C. Performing REDO (x1) ---\n";
    
    if (!redoStack.isEmpty()) {
        undoStack.push(currentState);
        
        currentState = 2;
        redoStack.pop(); 
    }
    undoStack.display();
    redoStack.display();

    cout << "\n--- D. New Edit (4) ---\n";
    undoStack.push(currentState);
    currentState = 4;
    redoStack = Stack();
    undoStack.display();
    redoStack.display();
}

int main() {
    UndoRedoTextEditor();
    return 0;
}
