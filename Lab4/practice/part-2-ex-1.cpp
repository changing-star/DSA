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
    CharStack() { top = nullptr; }

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

    bool isEmpty() {
        return top == nullptr;
    }
};


bool checkBalancedParentheses(string expression) {
    CharStack s;

    for (char c : expression) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.isEmpty()) {
                return false; 
            }
            s.pop();
        }
    }

    return s.isEmpty();
}

int main() {
    string exp1 = "(A+B)*(C-D)";
    string exp2 = "(A+B)*(C-D";
    string exp3 = ")A+B(";

    cout << "Expression 1: " << exp1 << " is " << (checkBalancedParentheses(exp1) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 2: " << exp2 << " is " << (checkBalancedParentheses(exp2) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 3: " << exp3 << " is " << (checkBalancedParentheses(exp3) ? "Balanced" : "Unbalanced") << endl;

    return 0;
}