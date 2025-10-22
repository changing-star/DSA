#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node (int value){
            data = value;
            next = nullptr;
        }
};

class SinglyLinkedList{
    private:
        Node* head;
        Node* tail;

        int size;
    
    public:
        SinglyLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }


    void insertAtBegin(int value){
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        if(!tail) tail = newNode;
        size++;
        
    }

    void insertAtEnd(int value){
        Node *newNode = new Node(value);

        if(!tail){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void insertAtMiddle(int value){
        if(size<=1) return;

        Node *current = head;
        for(int i =0; i<(size/2)-1;i++){
            current = current->next;
        }

        Node *newNode = new Node(value);

        newNode->next = current->next;
        current->next = newNode;

        size++;
    }

    void deleteAtBegin(){
        if(!head) return;
        Node *temp = head;
        head = head->next;
        if(!head) tail = nullptr;
        delete temp;
        size--;
    }

    void deleteAtEnd(){
        if(!head) return;
        if(!head->next){
            delete head;
            head = tail = nullptr;
        } else {
            Node *current = head;
            while(current->next->next) current = current->next;

            delete current->next;
            current->next = nullptr;
            tail = current;
        }

        size--;
    }

    void deleteAtMiddle(){
        if(size<=1) return;

        Node *temp = head;
        Node *previous = nullptr;
        
        for(int i = 0; i<size/2; i++){
            previous = temp;
            temp = temp->next;
        }

        previous->next = temp->next;

        delete temp;

        size--;

    }

    void swap(int x, int y){
        if(x==y||size<=1) return;

        Node *previousX = nullptr, *currentX = nullptr;
        Node *previousY = nullptr, *currentY = nullptr;

        Node *current = head;
        int count = 0;

        while(current){
            count++;
            if(count == x){
                currentX = current;
                break;
            }
            previousX = current;
            current = current->next;
        }
        count = 0;
        current = head;

        while(current){
            count++;
            if(count == y){
                currentY = current;
                break;
            }
            previousY = current;
            current = current->next;
        }
        count = 0;

        if(!currentX||!currentY) return;

        if(previousX){
            previousX->next = currentY;
        } else {
            head = currentY;
        }

        if(previousY){
            previousY->next = currentX;
        } else {
            head = currentX;
        }

        Node *temp = currentY->next;
        currentY->next = currentX->next;
        currentX->next = temp;
    }

    int count(){
        return size;
    }

    bool search(int value){
        Node *current = head;
        while (current){
            if(current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    void display(){
        if(head == nullptr){
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        cout << "Linked list: ";

        while(temp!=nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL \n";
    }
};

int main(){
    SinglyLinkedList myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);

    myList.display();

    myList.insertAtBegin(3);
    myList.display();

}