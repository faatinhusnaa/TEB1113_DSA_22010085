/* Faatin Nur Husna binti Izmir 22010085 */
#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 100; // max size of queue
    string arr[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string name) {
        if (rear == SIZE - 1) {
            cout << "queue full :(" << endl;
            return;
        }

        if (front == -1) front = 0;

        rear++;
        arr[rear] = name;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "queue empty :(" << endl;
            return;
        }

        front++;
        if (front > rear) {
            // Reset the queue after last element removed
            front = rear = -1;
        }
    }

    void display_queue() {
        if (front == -1 || front > rear) {
            cout << "queue empty :(" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << "->";
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
