//insert a newNode in a sorted list in sorted position
//approach: two poiters. one follows another.

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

void InsertInSortedList(Node*& head, int value) {
  if (head == nullptr) return;

  Node* prev = nullptr;
  Node* temp = head;
  if (value < temp->data) {
    InsertAtFront(head, value);
    return;
  }
  while (temp != nullptr && temp->data < value) {
    prev = temp;
    temp = temp->next;
  }
  Node* newNode = new Node(value);
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
// 10 20 25 30 40
int main() {
  Node* singlyLL = nullptr;
  InsertAtBack(singlyLL, 10);
  InsertAtBack(singlyLL, 20);
  InsertAtBack(singlyLL, 30);
  InsertAtBack(singlyLL, 40);
  PrintList(singlyLL);

  InsertInSortedList(singlyLL, 25);
  PrintList(singlyLL);

  return 0;
}