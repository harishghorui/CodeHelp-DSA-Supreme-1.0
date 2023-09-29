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

void removeDuplicatesM2(Node* &head) {
    if(head == NULL) {
        cout << "empty LL" << endl;
        return;
    }
    if(head->next == NULL) {
        cout << "Single LL" << endl;
        return;
    }

    // Nested Loops-->>
    //step1: create node for 1loop
    Node* curr = head;
    while(curr != NULL) {
        //step2: create nodes for pointing prev and next
        Node* prev = curr;
        Node* forward = curr->next;
        
        while(forward != NULL) {
            if(curr->data == forward->data) {
                //duplicate found-->>
                //step3: temp node for delete
                Node* temp = forward;
                //step4: move forward
                forward = forward->next;
                //step5: point prev to forward
                prev->next = forward;

                //step6: del temp
                temp->next = NULL;
                delete temp;
            }
            else {
                //if forward node is not duplicate
                forward = forward->next;
            }
            prev = prev->next;
        }
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

    removeDuplicatesM2(first);

    cout << "Duplicates Removed:" << endl;
    printLL(first);
}