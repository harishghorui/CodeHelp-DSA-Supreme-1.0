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

bool findLLCircular(Node* &first) {
    //edge case
    if(first == NULL) {
        cout << "Empty LL" << endl;
        return false;
    }

    Node* temp = first->next;
    while(temp != first && temp != NULL) {
        temp = temp->next;
    }
    if(temp == first) {
        return true;
    }
    else return false;

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
    //sixth->next = first;

    cout << findLLCircular(first) << endl;
}