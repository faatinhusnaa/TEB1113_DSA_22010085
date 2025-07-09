/* Faatin Nur Husna binti Izmir 22010085*/
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

        if (rear == nullptr) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "queue empty :(" << endl;
            return;
        }else{

        Node* temp = front;
        front = front->next;
        delete temp;
}
        if (front == nullptr) { 
            rear = nullptr;
        }

    }

    void display_queue() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->name << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Ahmad");
    q.enqueue("Abu");

    cout << "queue: ";
    q.display_queue();

    q.dequeue(); 

    cout << "dequeue: ";
    q.display_queue();

    return 0;
}
