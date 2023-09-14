#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize the node with data and set next to NULL
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a node at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);
    // Step 2: Point the new node to the current head
    newNode->next = head;
    // Step 3: Update the head to the new node
    head = newNode;
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);
    // Step 2: Point the current tail to the new node
    tail->next = newNode;
    // Step 3: Update the tail to the new node
    tail = newNode;
}

// Function to print the linked list
void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to find the length of the linked list
int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Handling edge cases
    if(position == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    // Step 1: Find the previous node
    int i = 1;
    Node* prev = head;
    while(i < position) {
        prev = prev->next;
        i++;
    } // Found the previous node
    Node* curr = prev->next; // Found the current node

    // Step 2: Create a new node for the position
    Node* newNode = new Node(data);

    // Step 3: Point the new node to the current node
    newNode->next = curr;

    // Step 4: Point the previous node's next to the new node
    prev->next = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting at the head
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);

    // Inserting at the tail
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);

    // Printing the linked list
    print(head);
    cout << endl << endl;

    // Inserting at a specific position
    insertAtPosition(9, 7, head, tail);
    print(head);
}