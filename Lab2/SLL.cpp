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
    
    public:
        SinglyLinkedList(){
            head = nullptr;
        }
    
    void insertAtEnd(int value){
        Node *newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        } else {
            Node *temp = head;

            while(temp->next!=nullptr){
                temp = temp->next;
            }

            temp->next=newNode;
        }
    }

    void insertAtBegin(int value){
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;
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