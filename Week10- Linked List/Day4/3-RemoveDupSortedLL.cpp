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

void removeDuplicates(Node* &head) {
    if(head == NULL) {
        cout << "LL is Empty" << endl;
        return;
    }
    if(head->next == NULL) {
        return;
    }

    //step1: create Nodes
    Node* curr = head;

    while(curr != NULL && curr->next != NULL) {
        //step2: check next
        if(curr->data == curr->next->data) {
            //step3: create next pointer
            Node* temp = curr->next;
            //step4: point curr to next-next
            curr->next = curr->next->next;
            //step5: Del Duplicate
            temp->next = NULL;
            delete temp;
        }
        //step6: move curr
        curr = curr->next;
    }
}

int main() {
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(3);
    Node* forth = new Node(4);
    Node* fifth = new Node(4);
    Node* sixth = new Node(5);
    
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    printLL(first);

    removeDuplicates(first);

    cout << "Duplicates Removed:" << endl;
    printLL(first);
}