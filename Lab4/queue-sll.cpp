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


int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(5);
    myQueue.enqueue(9);
    myQueue.enqueue(0);
    myQueue.enqueue(-1);
    myQueue.enqueue(50);
    myQueue.enqueue(100);

    myQueue.display();

    return 0;
}