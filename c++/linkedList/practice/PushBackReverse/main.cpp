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

void InsertAtEnd(Node*& head, int value) {
  if (head == nullptr) {
    InsertAtFront(head, value);
  } else {
    Node* newNode = new Node(value);
  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = nullptr;
  }
}

void PrintList(Node* head) {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}

//create 3 pointers; slide forward until nullptr; relink the middle one to prev; middle pointer is a new head;
Node* ReverseList(Node*& head) {
  if (head == nullptr) return nullptr;
  Node* prev = nullptr;
  Node* temp = nullptr;
  Node* next = head;
  while (next != nullptr) {
    prev = temp;
    temp = next;
    next = next->next;
    //relink the middle pointer - temp
    temp->next = prev;
  }
  head = temp;
return head;
}



int main() {
  Node* singlyLL = nullptr;
  InsertAtEnd(singlyLL, 30);
  InsertAtEnd(singlyLL, 40);
  InsertAtEnd(singlyLL, 50);
  PrintList(singlyLL);

  ReverseList(singlyLL);
  PrintList(singlyLL);

  return 0;
}