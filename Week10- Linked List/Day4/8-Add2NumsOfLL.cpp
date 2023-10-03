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
    cout << endl ;
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
    return prev;
}

Node* addNums(Node* &head1, Node* &head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    //part1: reverse both LL
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    //part2: add
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while(head1 != NULL && head2 != NULL) {
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);
        if(ansHead == NULL) {
            ansHead = newNode;
            ansTail = newNode;
        }
        else {
            ansTail->next = newNode;
            ansTail = ansTail->next;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //jab head1 list ki lenght head2 se zada hogi-->>
    while(head1 != NULL) {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = ansTail->next;

        head1 = head1->next;
    }
    
    //jab head2 list ki lenght head1 se zada hogi-->>
    while(head2 != NULL) {
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = ansTail->next;

        head2 = head2->next;
    }

    //head1 & head2 khatam hogaye but carry baaki hai-->>
    while(carry != 0) {
        int digit = carry % 10;
        carry = carry / 10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = ansTail->next;
    }


    //part3: reverse ans LL and return
    return reverseLL(ansHead);
}

int main() {
    //head1-->>
    Node* first = new Node(4);
    Node* second = new Node(8);
    // Node* third = new Node(2);
    //head2-->>
    Node* forth = new Node(2);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    first->next = second;
    //second->next = third;
    
    forth->next = fifth;
    fifth->next = sixth;

    cout << "Num1 : ";
    printLL(first);
    cout << "Num2 : ";
    printLL(forth);

    Node* ans = addNums(first, forth);
    cout << "Sum  : ";
    printLL(ans);
}