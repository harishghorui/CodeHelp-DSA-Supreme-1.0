#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //create new node
    Node* newNode = new Node(data);
    //new node-> next = head
    newNode->next = head;
    //head = new node
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step1
    Node* newNode = new Node(data);
    //step2
    tail->next = newNode;
    //step3
    tail = newNode;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    //head insertion-->>
    Node* head = NULL;
    Node* tail = NULL;

    insertHead(head, tail, 6);
    insertHead(head, tail, 7);
    insertHead(head, tail, 8);
    insertHead(head, tail, 9);

    //tail insertion-->>
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);

    print(head);

}