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

void printLL(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int findLength(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* reverseKGroup(Node* &head, int k) {
    //base case
    if(head == NULL) {
        cout << "Empty LL" << endl;
        return NULL;
    }
    int len = findLength(head);
    if(k > len) {
        return head;
    }

    //ek case
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL) {

        head->next = reverseKGroup(forward, k);
    }
    

    return prev;
}

int main() {
    Node* first = new Node(5);
    Node* second = new Node(6);
    Node* third = new Node(7);
    Node* forth = new Node(8);
    Node* fifth = new Node(9);
    Node* sixth = new Node(10);
    Node* head = first;

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    printLL(head);

    head = reverseKGroup(head, 5);

    printLL(head);
}