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

void InsertAtIndex(Node*& head, int index, int value) {
  if (index < 0) return;
  if (index == 0) {
    InsertAtFront(head, value); return;
  } else {
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < index - 1; i++) {
      temp = temp->next;
    }
    if (temp == nullptr) return;
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void PrintList(Node*& head) {
  Node* temp = head;
  while(temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}

int main() {
  Node* singlyLL = nullptr;
  InsertAtFront(singlyLL, 1);
  InsertAtFront(singlyLL, 2);
  InsertAtFront(singlyLL, 3);
  PrintList(singlyLL);

  InsertAtIndex(singlyLL, 2, 10);  //at index 2, value 10
  PrintList(singlyLL);
  return 0;
}