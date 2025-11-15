#include <iostream>
#include <string>

using namespace std;

class CharNode {
public:
    char data;
    CharNode* next;
    CharNode(char value) {
        data = value;
        next = nullptr;
    }
};

class CharStack {
private:
    CharNode* top;
public:
    CharStack() {
        top = nullptr;
    }

    void push(char value) {
        CharNode* newNode = new CharNode(value);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (!top) {
            return '\0';
        }
        CharNode* t = top;
        char popped_data = t->data;
        top = top->next;
        delete t;
        return popped_data;
    }
    
    char peek() {
        if (top == nullptr) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

void StackReverse(string input) {
    cout << "--- 1. Stack Reverse ---\n";
    CharStack s;
    string reversed_output = "";

    for (char c : input) {
        s.push(c);
    }

    while (!s.isEmpty()) {
        reversed_output += s.pop();
    }

    cout << "Input: " << input << endl;
    cout << "Output: " << reversed_output << endl;
}