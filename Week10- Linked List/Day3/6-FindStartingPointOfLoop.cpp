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

Node* findStartingPoint(Node* &head) {
    if(head == NULL) {
        cout << "LL is Empty" << endl;
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast != NULL) {
        //step1: move fast 2step
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            //step2: move slow 1step
            slow = slow->next;
        }
        if(slow == fast) {
            //step3: set slow as head
            slow = head;
            while(slow != fast) {
                //step4: move slow/fast 1steps
                slow = slow->next;
                fast = fast->next;
            }
            //were slow/fast meets is the starting point, return
            return slow;
        }
    }
    return head;
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
    sixth->next = third;

    Node* ans = findStartingPoint(first);
    if(ans == first) {
        cout << "Not a Loop" << endl;
    }
    else {
        cout << "Starting point is: " << ans->data << endl;
    }
}