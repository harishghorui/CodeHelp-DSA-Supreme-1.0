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

void sort0s1s2s(Node* &head) {
    Node* temp = head;
    //step1: create counting var
    int countOnes = 0;
    int countZeros = 0;
    int countTwos = 0;

    //step2: itterate LL for counting
    while(temp != NULL) {
        if(temp->data == 0) {
            countZeros++;
        }
        if(temp->data == 1) {
            countOnes++;
        }
        if(temp->data == 2) {
            countTwos++;
        }
        temp = temp->next;
    }

    //step3: update temp
    temp = head;
    //step4: Overwrite LL with counts
    while(temp != NULL) {
        while(countZeros--) {
            temp->data = 0;
            temp = temp->next;
        }
        while(countOnes--) {
            temp->data = 1;
            temp = temp->next;
        }
        while(countTwos--) {
            temp->data = 2;
            temp = temp->next;
        }
    }
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(2);
    Node* forth = new Node(0);
    Node* fifth = new Node(1);
    Node* sixth = new Node(2);
    Node* seventh = new Node(0);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    printLL(first);

    sort0s1s2s(first);

    printLL(first);
}