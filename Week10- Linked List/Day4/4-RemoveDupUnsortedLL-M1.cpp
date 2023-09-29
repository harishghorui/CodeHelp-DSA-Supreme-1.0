#include <iostream>
#include <unordered_map>
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

void removeDuplicatesM1(Node* &head) {
    if(head == NULL) {
        cout << "empty LL" << endl;
        return;
    }
    if(head->next == NULL) {
        cout << "Single LL" << endl;
        return;
    }
    unordered_map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL) {
        if(visited[curr->data] == true) {
            Node* temp = curr;
            curr = curr->next;
            prev->next = curr;
            //det temp
            temp->next = NULL;
            delete temp;
        }
        visited[curr->data] = true;
        prev = curr;
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

    removeDuplicatesM1(first);

    cout << "Duplicates Removed:" << endl;
    printLL(first);
}