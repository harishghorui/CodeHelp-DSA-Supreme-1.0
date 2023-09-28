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

Node* findMiddleNode(Node* &head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

Node* reverseLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    //printLL(prev);
    return prev;
}

bool checkPalindrome(Node* &first) {
    Node* head = first;
    if(head == NULL) {
        cout << "Empty LL" << endl;
        return false;
    }
    if(head->next == NULL) {
        return true;
    }

    Node* middle = findMiddleNode(head);
    Node* reversedHead = middle->next;
    
    reversedHead = reverseLL(reversedHead);
    
    while(reversedHead != NULL) {
        if(head->data != reversedHead->data) {
            return false;
        }
        head = head->next;
        reversedHead = reversedHead->next;
    }
    return true;

}

int main() {
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* forth = new Node(4);
    Node* fifth = new Node(3);
    Node* sixth = new Node(2);
    
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