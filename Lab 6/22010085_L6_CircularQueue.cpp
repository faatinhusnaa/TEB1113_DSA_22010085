/*Faatin Nur Husna binti Izmir 22010085*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(string name) {
        Node* newNode = new Node(name);

        if (front == nullptr) { // Queue is empty
            front = rear = newNode;
            rear->next = front;  // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  // maintain circular link
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "queue empty :(" << endl;
            return;
        }

        if (front == rear) { // only one element
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // maintain circular link
            delete temp;
        }
    }

    void display_queue() {
        if (front == nullptr) {
            cout << "queue empty :(" << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->name << "->";
            temp = temp->next;
        } while (temp != front);
        cout << front->name << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("ali");
    q.enqueue("ahmad");
    q.enqueue("alice");
    q.enqueue("hamzah");

    cout << "queue: ";
    q.display_queue();

    q.dequeue(); 

    cout << "dequeue: ";
    q.display_queue();

    return 0;
}
