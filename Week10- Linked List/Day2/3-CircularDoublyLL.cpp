#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printLL(Node* head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl << endl;
}

int main() {
    Node* first = new Node(50);
    Node* second = new Node(60);
    Node* third = new Node(70);
    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    //Circular Doubly LL-->>
    third->next = first;
    first->prev = third;

    printLL(head);
}