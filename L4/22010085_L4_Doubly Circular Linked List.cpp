// Faatin nur Husna binti Izmir 22010085

#include <iostream>
using namespace std;

// Node structure for doubly circular list
struct Node {
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string val) : name(val), next_ptr(nullptr), prev_ptr(nullptr) {}
};

// Doubly Circular Linked List class
class DoublyCircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyCircularLinkedList() : head(nullptr), tail(nullptr) {}

    // Add element to the end
    void add_element(string name) {
        Node* new_node = new Node(name);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            head->next_ptr = head;
            head->prev_ptr = head;
        } else {
            tail->next_ptr = new_node;
            new_node->prev_ptr = tail;
            new_node->next_ptr = head;
            head->prev_ptr = new_node;
            tail = new_node;
        }
    }

    // Display list forward
    void display_forward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next_ptr;
        } while (temp != head);
        cout << head->name << " (back to head)" << endl;
    }

    // Display list backward
    void display_backward() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = tail;
        do {
            cout << temp->name << " <- ";
            temp = temp->prev_ptr;
        } while (temp != tail);
        cout << tail->name << " (back to tail)" << endl;
    }

    // Destructor to free memory
    ~DoublyCircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        do {
            Node* next = current->next_ptr;
            delete current;
            current = next;
        } while (current != head);

        head = nullptr;
        tail = nullptr;
    }
};

// Main function
int main() {
    DoublyCircularLinkedList list;

    list.add_element("Alice");
    list.add_element("Bob");
    list.add_element("Charlie");

    cout << "Forward: ";
    list.display_forward();

    cout << "Backward: ";
    list.display_backward();

    return 0;
}
