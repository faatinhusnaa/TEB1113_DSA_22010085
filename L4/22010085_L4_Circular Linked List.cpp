/* Faatin Nur Husna bInti Izmir 22010085*/
#include <iostream>
using namespace std;

// Node structure
struct Node {
    string name;
    Node* next_ptr;

    Node(string val) : name(val), next_ptr(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    // Your add_element function with debug output
    void add_element(string name) {
        Node* new_node = new Node(name);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            tail->next_ptr = head;  // make it circular
            cout << "1" << endl;
        } else {
            tail->next_ptr = new_node;
            tail = new_node;
            tail->next_ptr = head;  // maintain circular link
            cout << "2" << endl;
        }
    }

    // Display the circular linked list with actual head value
    void display_list() {
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

    // Destructor to clean up memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next_ptr;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
        tail = nullptr;
    }
};

// Main function
int main() {
    CircularLinkedList list;

    list.add_element("Alice");   // Prints "1"
    list.add_element("Bob");     // Prints "2"
    list.add_element("Charlie"); // Prints "2"

    cout << "Current List: ";
    list.display_list();         // Prints circular list with head value

    return 0;
}
