#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int value){
            data = value;
            next = nullptr;
        }
};

class Queue{
    private:
        Node *front, *rear;
    public:
        Queue(){
            front = nullptr; rear = nullptr; 
        }

    void enqueue(int value){
        Node* newNode = new Node(value);

        if(front == nullptr) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(front == nullptr){
            cout << "Queue Underflow!\n";
            return;
        }

        Node* t = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete t;

    }

    int peek(){
        return front->data;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void display(){
        Node* t = front;
        cout << "Queue (front -> rear): ";
        while(t){
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
    }

};

void QueueSimulation() {
    cout << "\n--- 2. Queue Simulation - Customer Line ---\n";
    Queue customerLine;

    cout << "C101 arrives: ";
    customerLine.enqueue(101);
    customerLine.display();

    cout << "C102 arrives: ";
    customerLine.enqueue(102);
    customerLine.display();

    cout << "Serve customer (C101): ";
    customerLine.dequeue();
    customerLine.display();

    cout << "C103 arrives: ";
    customerLine.enqueue(103);
    customerLine.display();

    cout << "Serve customer (C102): ";
    customerLine.dequeue();
    customerLine.display();

    cout << "Serve customer (C103): ";
    customerLine.dequeue();
    customerLine.display();
}