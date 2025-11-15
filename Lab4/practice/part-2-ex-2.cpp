#include <iostream>
#include <string>

using namespace std;

struct PrintJob {
    int jobID;
    int pages;
};

class JobNode {
public:
    PrintJob data;
    JobNode* next;
    JobNode(int id, int pgs) {
        data.jobID = id;
        data.pages = pgs;
        next = nullptr;
    }
};

class PrintQueue {
private:
    JobNode *front, *rear;

public:
    PrintQueue() {
        front = nullptr; rear = nullptr;
    }

    void enqueue(int id, int pages) {
        JobNode* newNode = new JobNode(id, pages);
        
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "JOB RECEIVED: ID " << id << " (" << pages << " pages).\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! No jobs to print.\n";
            return;
        }
        
        cout << "PRINTING COMPLETE: Job ID " << front->data.jobID 
             << " (" << front->data.pages << " pages).\n";

        JobNode* t = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete t;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty. No jobs waiting.\n";
            return;
        }
        
        JobNode* t = front;
        cout << "Current Queue (Front -> Rear): ";
        while (t) {
            cout << "[ID:" << t->data.jobID << ", Pgs:" << t->data.pages << "] ";
            t = t->next;
        }
        cout << endl;
    }
    
    ~PrintQueue(){
        while(front){
            JobNode* next = front->next;
            delete front;
            front = next;
        }
        rear = nullptr;
    }
};

void PrinterQueueManagement() {
    cout << "--- 6. Printer Queue Management ---\n";
    PrintQueue pq;

    pq.enqueue(101, 50);
    pq.enqueue(102, 10);
    pq.display();
    
    pq.dequeue(); 
    pq.display();
    
    pq.enqueue(103, 3);
    pq.display();

    pq.dequeue();
    pq.dequeue();
    pq.display();

    pq.dequeue();
}


int main() {
    PrinterQueueManagement();
    return 0;
}
