#include <iostream>
using namespace std;

class DoublyNode {
    public:
        int data;
        DoublyNode* next;
        DoublyNode* prev;
        DoublyNode(int value){
            data = value;
            next = nullptr;
            prev = nullptr;
        };
};

class DoublyLinkedList {
    private:
        int size;
        DoublyNode* head;
        DoublyNode* tail;

    public:
        DoublyLinkedList(){
            size = 0;
            head = nullptr;
            tail = nullptr;
        };

        int getSize(){
            return size;
        }

        void add(int value){
            DoublyNode* newNode = new DoublyNode(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            size++;
        }

        void addBegin(int value){
            DoublyNode* newNode = new DoublyNode(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }

        void deleteLast(){
            if(head == nullptr) return;

            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                DoublyNode* t = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete t;
            }
            
            size --;

        }

        void displayForward() {
            DoublyNode* t = head;
            while (t != nullptr) {
                cout << t->data << " <-> ";
                t = t->next;
            }
                cout << "NULL\n";
        }

        void displayBackward() {
            if (head == nullptr) return;
            DoublyNode* t = tail;
            while (t != nullptr) {
                cout << t->data << " <-> ";
                t = t->prev;
            }
            cout << "NULL\n";
        }
};

int main(){
    DoublyLinkedList list;
    
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    
    cout << "Forward traversal: ";
    list.displayForward();
    
    cout << "Backward traversal: ";
    list.displayBackward();
    
    cout << "Size: " << list.getSize() << endl;
    
    return 0;
}