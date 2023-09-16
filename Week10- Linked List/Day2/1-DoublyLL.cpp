#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    
};

int findLength(Node* &head) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        length++;
    }
    cout << "Length is: " << length << endl;
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        //LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step1: create Node 
    Node* newNode = new Node(data);
    //step2: point new node to head
    newNode->next = head;
    //step3: point head prev to new node
    head->prev = newNode;
    //step4: update head
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        //LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //step1: create Node 
    Node* newNode = new Node(data);
    //step2: point tail to new node
    tail->next = newNode;
    //step3: point new node prev to tail
    newNode->prev = tail;
    //step4: update tail
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    if(head == NULL) {
        //LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }
    
    int length = findLength(head);
    if(position > length) {
        insertAtTail(head, tail, data);
        return;
    }

    // insertion in middle-->>
    //step1: create node
    Node* newNode = new Node(data);
    //step2: find prev
    int i = 1;
    Node* prevNode = head;
    while(i < position-1) {
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode->next;

    // //step3:
    // prevNode->next = newNode;
    // newNode->prev = prevNode;
    
    // //step4:
    // curr->prev = newNode;
    // newNode->next = curr;

    // Alternate -->> without curr
    //step3:
    prevNode->next->prev = newNode;
    newNode->next = prevNode->next;
    //step4:
    prevNode->next = newNode;
    newNode->prev = prevNode;
    
}

void delPosition(int position, Node* &head, Node* &tail) {

    //handling edge case:
    if(head == NULL) {
        cout << "LL is empty" << endl;
        return;
    }
    if(head->next == NULL) {
        //single node
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if(position > findLength(head)) {
        cout << "please enter valid position" << endl;
    }

    //1st position
    if(position == 1) {
        //step1:
        Node* temp = head;
        //step2: shift head
        head = head->next;
        //step3:
        head->prev = NULL;
        //step4:
        temp->next = NULL;
        //step5:
        delete temp;
        return;
    }
    
    //Last position
    int length = findLength(head);
    if(position == length) {
        //step1:
        Node* temp = tail;
        //step2: shift tail
        tail = tail->prev;
        //step3:
        tail->next = NULL;
        //step4:
        temp->prev = NULL;
        //step5:
        delete temp;
        return;
    }

    //Middle Position
    //step1: create node
    Node* temp = head;
    //step2: place temp to position
    int delNode = 1;
    while(delNode != position) {
        temp = temp->next;
        delNode++;
    }
    //step3:
    temp->prev->next = temp->next;
    //step4:
    temp->next->prev = temp->prev;
    //step5:
    temp->next = NULL;
    temp->prev = NULL;
    //step6:
    delete temp;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    findLength(head);
    print(head);
    cout << endl << endl;

    insertAtHead(head, tail, 5);
    findLength(head);
    print(head);
    cout << endl << endl;

    insertAtTail(head, tail, 40);
    findLength(head);
    print(head);
    cout << endl << endl;

    insertAtPosition(head, tail, 501, 5);
    findLength(head);
    print(head);
    cout << endl << endl;

    delPosition(10, head, tail);
    findLength(head);
    print(head);
    cout << endl << endl;
}