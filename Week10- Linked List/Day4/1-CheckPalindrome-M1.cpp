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

void reverseLL(Node* &reversed) {
    Node* prev = NULL;
    Node* curr = reversed;
    Node* forward = curr->next;
    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    reversed = prev;
    printLL(reversed);
}

bool checkPalindrome(Node* &first) {
    Node* reversed = first;
    reverseLL(reversed);
    
    Node* temp = first;
    while(temp != NULL) {
        if(temp->data != reversed->data) {
            return false;
        }
        temp = temp->next;
        reversed = reversed->next;
    }

    return true;
}

int main() {
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* forth = new Node(4);
    Node* fifth = new Node(3);
    Node* sixth = new Node(6);
    
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    printLL(first);
    
    if(checkPalindrome(first)) {
        cout << "LL is a Palindrome" << endl;
    }
    else {
        cout << "LL is not a Palindrome" << endl;
    }
}