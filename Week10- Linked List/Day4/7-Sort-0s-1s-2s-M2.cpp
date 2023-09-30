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

Node* sort0s1s2sMethod2(Node* &head) {
    //step1: create dummy
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //step1: itterate and point to dummy nodes-->>>>
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == 0) {
            //separate zero's node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append separated node to dummy node
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        else if(curr->data == 1) {
            //separate zero's node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append separated node to dummy node
            oneTail->next = temp;
            oneTail = oneTail->next;
        }
        else if(curr->data == 2) {
            //separate zero's node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //append separated node to dummy node
            twoTail->next = temp;
            twoTail =  twoTail->next;
        }
    }

    //Step2: delete dummy heads(-1)-->>>>
    //Modify ones LL
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    //modify twos LL
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //step3: join dummy nodes-->>>>
    if(oneHead != NULL) {
        zeroTail->next = oneHead;
        if(twoHead != NULL) {
            oneTail->next = twoHead;
        }
    }
    else {
        zeroTail->next = twoHead;
    }


    //step4: remove zeroHead dummy node-->>>
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(2);
    Node* forth = new Node(1);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    Node* seventh = new Node(0);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    printLL(first);

    first = sort0s1s2sMethod2(first);

    printLL(first);
}