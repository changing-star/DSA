#include <iostream>
using namespace std;

struct Student{
    int ID;
    string name;
    string major;
};

class Node{
    public:
        Student data;
        Node* next;

        Node (Student value){
            data = value;
            next = nullptr;
        }
};

class SinglyLinkedList{
    private:
        Node* head;
        Node* tail;

        int size;

    
    void deleteAtPosition(int pos){
        if(size<=1) return;

        Node *temp = head;
        Node *previous = nullptr;
        
        for(int i = 0; i<pos; i++){
            previous = temp;
            temp = temp->next;
        }

        previous->next = temp->next;

        delete temp;

        size--;
    }
    
    public:
        SinglyLinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

    void insertAtBegin(Student value){
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        if(!tail) tail = newNode;
        size++;
        
    }

    void insertAtEnd(Student value){
        Node *newNode = new Node(value);

        if(!tail){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

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

    void deleteSpecificElement(int element){
        Node *current = head;
        int position = 0;
        while (current){
            if(current->data.ID == element) {
              deleteAtPosition(position);  
            };
            current = current->next;
            position++;
        }
    }

    void deleteList(){
        Node *current = head;
        while(current != nullptr){
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int count(){
        return size;
    }

    bool search(int value){
        Node *current = head;
        while (current){
            if(current->data.ID == value) return true;
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
            cout << "Student ID: " << temp->data.ID << ", Student Name: " << temp->data.name << ", Student Major: " << temp->data.major << "->";
            temp = temp->next;
        }

        cout << "NULL \n";
    }
};

int main(){
    SinglyLinkedList myList;

    Student S1;
    Student S2;
    Student S3;


    S1.ID = 67;
    S1.name = "Tho Vicheka";
    S1.major = "AI Researcher";

    S2.ID = 68;
    S2.name = "Sliden";
    S2.major = "Drunk Developer";

    S3.ID = 69;
    S3.name = "Reach";
    S3.major = "Fake ass chiller";

    myList.insertAtBegin(S1);
    myList.display();
    myList.insertAtBegin(S2);
    myList.display();

    myList.deleteSpecificElement(67);
    myList.display();
    myList.insertAtBegin(S1);

    myList.display();

    myList.insertAtBegin(S3);
    myList.display();
    myList.deleteAtBegin();
    myList.display();

    myList.deleteList();

    myList.display();

    return 0 ;

    
}