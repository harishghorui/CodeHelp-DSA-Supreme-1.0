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

void printLL(Node* &first) {
    Node* temp = first;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

bool checkLoop(Node* &head) {
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return false;
    }

    // Node* slow = head;
    // Node* fast = head->next;

    // while(fast != NULL && slow != fast) {
    //     //step1: move fast 2step
    //     fast = fast->next;
    //     if(fast != NULL) {
    //         fast = fast->next;
    //         //step2: move slow 1step
    //         slow = slow->next;
    //     }
    // }
    // if(fast == NULL) {
    //     return false;
    // }
    // else return true;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        //step1: move fast 2step
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            //step2: move slow 1step
            slow = slow->next;
        }

        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* first = new Node(5);
    Node* second = new Node(6);
    Node* third = new Node(7);
    Node* forth = new Node(8);
    Node* fifth = new Node(9);
    Node* sixth = new Node(10);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = third; // loop statement

    //printLL(first);
    cout << checkLoop(first);
}