/*Name:Faatin Nur Husna binti Izmir 
ID:22010085 
LAB CPP1 
heehheheheh ads*/
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
    int contact; 
};

int main() {
    const int n = 5;
    Student students[n];


    for (int i = 0; i < n; ++i) {
        cout << "Enter details for Student " << i + 1 << ":\n";

        cout << "ID: ";
        cin >> students[i].id;
        
         cin.ignore();

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Email: ";
        getline(cin, students[i].email);

        cout << "Contact number: ";
        cin >> students[i].contact;

        cout << endl;
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << " - ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Email: " << students[i].email
             << ", Contact: " << students[i].contact << "\n";
    }

    return 0;
}
