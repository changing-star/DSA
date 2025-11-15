#include <iostream>
using namespace std;

class Queue {
    private:
        int front, rear, cap;
        int* arr;

    public:
        Queue(int size){
            cap = size;
            arr = new int[cap];
            front = rear = -1;
        }

    void enqueue(int value){
        if(rear == cap -1) cout << "Queue Overflow!\n";
        if(front == -1) front = 0;
        ++rear;

        arr[rear] = value;
    }

    void dequeue(){
        if(front == -1) cout << "Empty! Queue Underflow!\n";
        else ++front;
    }

    int peek(){
        if(front == -1) cout << "Empty! Queue Underflow!\n"; return -1000000;
        return arr[front];
    }

    bool isEmpty(){
        return front == -1;
    }

    void display(){
        if (isEmpty()) cout << "Queue is empty\n";
        else {
            cout << "Queue (front -> rear)";
            for(int i = front; i<=rear;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    // q.enqueue(11);
    // q.enqueue(22);
    // q.enqueue(33);

    q.display();

    return 0;
}
