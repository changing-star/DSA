#include <iostream>
#include <string>

using namespace std;

enum Priority { CRITICAL = 1, URGENT = 2, STABLE = 3 };

class PatientNode {
public:
    int patientID;
    Priority priority;
    PatientNode* next;

    PatientNode(int id, Priority p) {
        patientID = id;
        priority = p;
        next = nullptr;
    }
};
class PriorityQueue {
private:
    PatientNode *front;
public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(int id, Priority p) {
        PatientNode* newNode = new PatientNode(id, p);

        if (front == nullptr || p < front->priority) {
            newNode->next = front;
            front = newNode;
            cout << "Patient ID " << id << " added to FRONT (Priority: " << p << ").\n";
            return;
        }

        PatientNode* current = front;
        while (current->next != nullptr && current->next->priority <= p) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        cout << "Patient ID " << id << " added after ID " << current->patientID << " (Priority: " << p << ").\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! No patients to serve.\n";
            return;
        }

        cout << "Serving highest priority patient: ID " << front->patientID 
             << " (Priority: " << front->priority << ").\n";
        
        PatientNode* t = front;
        front = front->next;
        delete t;
    }

    void display() {
        if (front == nullptr) {
            cout << "The ER Queue is empty.\n";
            return;
        }
        
        PatientNode* t = front;
        cout << "ER Queue (High Priority -> Low Priority): ";
        while (t) {
            cout << "[ID:" << t->patientID << ", P:" << t->priority << "] ";
            t = t->next;
        }
        cout << endl;
    }
    
};

void EmergencyRoomSimulation() {
    cout << "--- 8. Emergency Room Simulation (Priority Queue) ---\n";
    PriorityQueue erQueue;

    erQueue.enqueue(101, STABLE); 
    erQueue.enqueue(102, URGENT); 
    erQueue.enqueue(103, STABLE);
    erQueue.display();

    cout << "\n--- CRITICAL ARRIVAL ---\n";
    erQueue.enqueue(104, CRITICAL);
    erQueue.display();

    cout << "\n--- SERVING PATIENTS (Dequeue) ---\n";
    erQueue.dequeue();
    erQueue.dequeue();
    erQueue.display();

    cout << "\n--- NEW URGENT ARRIVAL ---\n";
    erQueue.enqueue(105, URGENT);
    erQueue.display();
}

int main(){
    EmergencyRoomSimulation();
    return 0;
}