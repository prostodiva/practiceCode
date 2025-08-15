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

void PrintList(Node* head) {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}

int main() {
  Node* singlyLL = nullptr;
  InsertAtFront(singlyLL, 10);
  InsertAtFront(singlyLL, 5);

  PrintList(singlyLL);

  return 0;
}