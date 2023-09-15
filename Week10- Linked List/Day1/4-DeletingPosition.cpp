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

    ~Node() {
        // H/W to write destructor
    }
};

// Function to insert a node at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);
    // Step 2: Point the new node to the current head
    newNode->next = head;
    // Step 3: Update the head to the new node
    head = newNode;
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1: Create a new node
    Node* newNode = new Node(data);
    // Step 2: Point the current tail to the new node
    tail->next = newNode;
    // Step 3: Update the tail to the new node
    tail = newNode;
}

int findLength(Node* &head) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

void delPosition(int position, Node* &head, Node* &tail) {

    //del position at 1st (1 index)
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    //del last position (last index)
    int length = findLength(head);
    if(position == length) {
        //step1: find prev
        int prevPos = 1;
        Node* prev = head;
        while(prevPos < length-1) {
            prev = prev->next;
            prevPos++;
        }
        //step2: point prev next to null
        prev->next = NULL;
        //step3: new node to point tail
        Node* temp = tail;
        //step4: shift tail to prev
        tail = prev;
        //step5: del the new node (temp)
        delete temp;
        return;
    }

    //del Middle Node
    //step1: find prev
    int prevPtr = 1;
    Node* prev = head;
    while(prevPtr < position - 1) {
        prev = prev->next;
        prevPtr++;
    }
    //creat current
    Node* curr = prev->next;
    //point prev next to curr ka next
    prev->next = curr->next;
    //step4: point curr to Null
    curr->next = NULL;
    //step5: del curr
    delete curr;
}

// Function to print the linked list
void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    // Inserting at the head
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);

    // Inserting at the tail
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);

    print(head);
    cout << endl << endl;

    delPosition(2, head, tail);
    print(head);
}