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
        this->next = nullptr;
    }
};


class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void empty() {
        if (isEmpty()) {
            cout << "NULL LIST EMPTY" << endl;
        } else {
            cout << "stack not empty:))." << endl;
        }
    }

    void add_item(Node* node) {
        node->next = head;
        head = node;
    }

    void pop() {
        if (isEmpty()) {
            cout << "empty :(, cannot pop." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "yey popped: " << temp->name << endl;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "NULL" << endl;
        } else {
            cout << "top: " << head->name << endl;
        }
    }

    void display_list() {
        if (isEmpty()) {
            cout << "NULL" << endl;
            return;
        }

        Node* temp = head;
        cout << "contents:" << endl;
        while (temp != nullptr) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};


int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    Stack std_list;

    std_list.empty();             

    std_list.add_item(node1);     
    std_list.add_item(node2);     
    std_list.add_item(node3);     

    std_list.display_list();      
    std_list.peek();              

    std_list.pop();   
    std_list.peek(); 
    std_list.pop();  
    std_list.peek(); 
    std_list.pop();  

    std_list.empty();            

    std_list.display_list();      

    return 0;
}
