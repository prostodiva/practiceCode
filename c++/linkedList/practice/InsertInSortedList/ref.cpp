//insert a newNode in a sorted list in sorted position
//approach: three poiters. one follows another.

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

void InsertAtBack(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void InsertAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void InsertInSortedList(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;
    if (head == nullptr) {
        InsertAtFront(head, key); return;
    }
    if (key < temp->data) {
        InsertAtFront(head, key); return;
    }
    while (temp != nullptr && temp->data < key) {
        prev = temp;
        temp = temp->next;
    }
    Node* newNode = new Node(key);
    prev->next = newNode;
    newNode->next = temp;
}


void PrintList(Node*& head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" <<endl;
}


//sorted list: 10 20 30 40
//insert 25
//insert 35
//insert 5
//insert 45
int main() {
    Node* singlyLL = nullptr;
    InsertAtBack(singlyLL, 10);
    InsertAtBack(singlyLL, 20);
    InsertAtBack(singlyLL, 30);
    InsertAtBack(singlyLL, 40);
    PrintList(singlyLL);

    InsertInSortedList(singlyLL, 25);
    PrintList(singlyLL);
    InsertInSortedList(singlyLL, 35);
    PrintList(singlyLL);
    InsertInSortedList(singlyLL, 5);
    PrintList(singlyLL);
    InsertInSortedList(singlyLL, 45);
    PrintList(singlyLL);

    return 0;
}