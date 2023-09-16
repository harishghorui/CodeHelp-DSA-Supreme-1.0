#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
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
    second->next = third;
    
    //Circular Singly LL
    third->next = first;

    printLL(head);
}