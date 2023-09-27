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

bool checkLoop(Node* &head) {
    // Create an unordered_map to store visited nodes
    unordered_map<Node*, bool> map;
    
    // Initialize a temporary pointer to the head of the list
    Node* temp = head;
    
    // Traverse the linked list
    while (temp != NULL) {
        // If the current node is already in the map, it's a loop
        if (map[temp] == true)
            return true;
        
        // Mark the current node as visited in the map
        map[temp] = true;
        
        // Move to the next node
        temp = temp->next;
    }
    
    // If we reach the end of the list without finding a loop, return false
    return false;
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
    sixth->next = NULL;

    cout << checkLoop(first);
}