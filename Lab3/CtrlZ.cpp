#include <iostream>
#include <string>
using namespace std;

class Action {
public:
    string action;
    Action* next;
    Action* prev;
    
    Action(string act) {
        action = act;
        next = nullptr;
        prev = nullptr;
    }
};

class UndoRedoSystem {
private:
    Action* undoHead;
    Action* redoHead;
    Action* current;

public:
    UndoRedoSystem() {
        undoHead = nullptr;
        redoHead = nullptr;
        current = nullptr;
    }

    void execute(string action) {
        Action* newAction = new Action(action);
        
        clearRedo();
        
        if (undoHead == nullptr) {
            undoHead = newAction;
        } else {
            current->next = newAction;
            newAction->prev = current;
        }
        current = newAction;
        cout << "✓ " << action << endl;
    }

    void undo() {
        if (current == nullptr) {
            cout << "Nothing to undo" << endl;
            return;
        }
        
        Action* cmd = current;
        current = current->prev;
        
        cmd->next = redoHead;
        if (redoHead != nullptr) redoHead->prev = cmd;
        redoHead = cmd;
        redoHead->prev = nullptr;
        
        cout << "Undo: " << cmd->action << endl;
    }

    void redo() {
        if (redoHead == nullptr) {
            cout << "Nothing to redo" << endl;
            return;
        }
        
        Action* cmd = redoHead;
        redoHead = redoHead->next;
        
        if (current != nullptr) {
            current->next = cmd;
            cmd->prev = current;
        } else {
            undoHead = cmd;
        }
        current = cmd;
        current->next = nullptr;
        
        cout << "Redo: " << cmd->action << endl;
    }

    void show() {
        cout << "\nUndo: ";
        Action* temp = undoHead;
        while (temp != nullptr) {
            cout << temp->action;
            if (temp == current) cout << " [Current]";
            cout << " → ";
            temp = temp->next;
        }
        cout << "NULL\n";
        
        cout << "Redo: ";
        temp = redoHead;
        while (temp != nullptr) {
            cout << temp->action << " → ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

private:
    void clearRedo() {
        while (redoHead != nullptr) {
            Action* temp = redoHead;
            redoHead = redoHead->next;
            delete temp;
        }
    }
};

int main() {
    UndoRedoSystem sys;
    
    sys.execute("Type Hello");
    sys.execute("Add World");
    sys.execute("Bold text");
    
    sys.show();
    
    sys.undo();
    sys.undo();
    sys.redo();
    
    sys.show();
    
    sys.execute("New Action");
    sys.show();
    
    return 0;
}