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

int findMiddle(Node* &head) {
    if(head == NULL) {
        cout << "LL is Empty";
    }
    if(head->next == NULL) {
        return head->next->data;
    }

    //1step- create slow & fast
    Node* slow = head;
    Node* fast = head->next;
    // or -->> depend upon question
    // Node* fast = head;
    while(slow != NULL && fast != NULL) {
        //step2- move fast 2step
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            //step3- move slow 1step
            slow = slow->next;
        }
    }
    return slow->data;
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
    int middleData = findMiddle(head);
    cout << "Middle is: " << middleData << endl;
}