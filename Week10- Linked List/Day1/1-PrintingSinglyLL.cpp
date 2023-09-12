#include <iostream>
using namespace std;

// Define a class for a singly linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize the node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print the linked list
void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    // Create nodes for the linked list and initialize them with data
    Node* first = new Node(5);
    Node* second = new Node(4);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);

    // Link the nodes together to form a linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Print the linked list
    cout << "Printing LL: " << endl;
    print(first);
}