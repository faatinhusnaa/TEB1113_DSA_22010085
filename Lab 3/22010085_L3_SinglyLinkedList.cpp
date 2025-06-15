/* Faatin Nur Husna binti Izmir 22010085
L3, G2, Singly Linked List */

#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Function to add a node at the end of the list
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display the list
    void displayList() {
        Node* temp = head;
        if (temp == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Value " << value << " not found in the list." << std::endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    
    std::cout << "Current List: ";
    list.displayList();

    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.displayList();

    list.deleteNode(40); // Trying to delete a non-existent value

    return 0;
}
