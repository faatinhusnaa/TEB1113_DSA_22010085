/* Faatin Nur Husna binti Izmir 22010085 */

#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 100; 
    string arr[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string name) {
        if ((rear + 1) % SIZE == front) {
            cout << "queue full :(" << endl;
            return;
        }

        if (front == -1) { 
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = name;
    }

    void dequeue() {
        if (front == -1) {
            cout << "queue empty :(" << endl;
            return;
        }

        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display_queue() {
        if (front == -1) {
            cout << "queue empty :(" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << "->";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << arr[front] << endl; 
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
