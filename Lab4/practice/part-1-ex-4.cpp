#include <iostream>
#include <string>

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


void BankCounterQueue() {
    cout << "\n--- 4. Bank Counter Queue Simulation ---\n";
    Queue bankQueue;
    int customerID = 201;

    cout << "Customer " << customerID << " arrives (Enqueue).\n";
    bankQueue.enqueue(customerID++);
    bankQueue.display();

    cout << "Customer " << customerID << " arrives (Enqueue).\n";
    bankQueue.enqueue(customerID++);
    bankQueue.display();

    cout << "\nServing customer (Dequeue).\n";
    bankQueue.dequeue();
    bankQueue.display();

    cout << "Customer " << customerID << " arrives (Enqueue).\n";
    bankQueue.enqueue(customerID++);
    bankQueue.display();

    cout << "\nServing customer (Dequeue).\n";
    bankQueue.dequeue();
    bankQueue.display();

    cout << "Serving customer (Dequeue).\n";
    bankQueue.dequeue();
    bankQueue.display();
    
    cout << "\nTrying to serve empty queue:\n";
    bankQueue.dequeue();
}


int main(){
    BankCounterQueue();
    return 0;
}