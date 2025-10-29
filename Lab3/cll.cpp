#include <iostream>
using namespace std;

class CircularNode{
    public:
        int data;
        CircularNode* next;

        CircularNode (int value){
            data = value;
            next = nullptr;
        }
};

class CircularLinkedList{
    private:
        CircularNode* head;
        CircularNode* tail;
        int size;
        
    public:
        CircularLinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void add(int value){
            CircularNode* newNode = new CircularNode(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                tail->next = head;
            } else {
                tail->next = newNode;
                newNode->next = head;
                tail = newNode;
            }
            size++;
        }

        void deleteHead(){
            if(head == nullptr) return;

            if(head->next == head){
                delete head;
                head = tail = nullptr;
                size--;
                return;
            };

            CircularNode* t = head;

            head = head->next;
            tail->next = head;

            delete t;
            size--;
        }

        bool search(int value){
            if(head == nullptr) return false;
            CircularNode* t = head;
            for(int i = 0; i<size; i++){
                if(t->data == value) return true;
                t = t->next;
            }
            return false;
        }

        void display(){
            if (head == nullptr) return;
            CircularNode *t = head;
            do {
                cout << t->data << " -> ";
                t = t->next;
            } while (t != head);
            cout << "(back to head)\n";
        }

};

int main(){
    CircularLinkedList list;
    
    list.add(10);
    list.add(20);
    list.add(30);
    
    list.display();
    
    list.deleteHead();
    list.display();
    
    list.deleteHead();
    list.display();
    
    list.deleteHead();
    list.display();
    
    return 0;
    return 0;
}