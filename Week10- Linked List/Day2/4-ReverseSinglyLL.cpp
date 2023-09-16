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

Node* reverseLL(Node* &prev, Node* &curr) {
    //base case
    if(curr == NULL) {
        return prev;
    }

    //ek case
    Node* temp = curr->next;
    curr->next = prev;

    //RE
    return reverseLL(curr, temp); //passing updated pointers
}

void printLL(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
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

    printLL(head);

    // //Reverse LL-->>
    Node* prev = NULL;
    head = reverseLL(prev, head);

    cout << "Reversed LL: " << endl;
    printLL(head);
}