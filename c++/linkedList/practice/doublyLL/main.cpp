#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {};
};

//relink three pounters
void PushAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;
    } else {
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

//modify 4 pointers(when found the correct index(pos - 1))
void InsertAtPosition(Node*& head, int pos, int value) {
    if (pos == 0) PushAtFront(head, value);
    if (head == nullptr) PushAtFront(head, value);
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
     //start modifying 4 links
     newNode->next = temp->next;
     newNode->prev = temp;
     //check if the next node is avaliable
     if (temp->next != nullptr) {
         temp->next->prev = newNode; 
     }
     temp->next = newNode;
}

void PrintList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr"<<endl;
}


void DeleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* doublyLL = nullptr;
    PushAtFront(doublyLL, 10);
    PushAtFront(doublyLL, 8);
    PushAtFront(doublyLL, 6);
    PushAtFront(doublyLL, 4);
    PushAtFront(doublyLL, 2);
    PrintList(doublyLL);

    InsertAtPosition(doublyLL, 4, 5);
    PrintList(doublyLL);

    DeleteList(doublyLL);

    return 0;
}
