//find max in the list.
//pseudocode:
//initialise min with -32768;  //MIN_INT
//traverse through the list, compare with min


#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

void InsertAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}


void PrintList(Node*& head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr"<<endl;
}

void FindMax(Node*& head) {
    int m = -32768;
    Node* temp = head;
    while(temp != nullptr) {
      if (temp->data > m) {
        m = temp->data;
      }
      temp = temp->next;
    }
    cout << m <<endl;
}

int main() {
    Node* singlyLL = nullptr;
    InsertAtFront(singlyLL, 5);
    InsertAtFront(singlyLL, 2);
    InsertAtFront(singlyLL, 3);
    PrintList(singlyLL);
    FindMax(singlyLL);
    return 0;
}