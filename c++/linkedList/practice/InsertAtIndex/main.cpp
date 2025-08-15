#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Node {
  T data;
  Node* next;

  Node(T value) : data(value), next(nullptr) {};
};

template<typename T>
void InsertAtFront(Node<T>*& head, T value) {
  Node<T>* newNode = new Node<T>(value);
  newNode->next = head;
  head = newNode;
}

template<typename T>
void InsertAtIndex(Node<T>*& head, T value, int index) {
  if (index < 0) return;    //don't work with negative
  if (index == 0) {
    InsertAtFront(head, value);
    return;
  }
  Node<T>* temp = head;
  for (int i = 0; temp != nullptr && i < index - 1; i++) {
    temp = temp->next;
  }
  if (temp == nullptr) return;

  Node<T>* newNode = new Node<T>(value);
  newNode->next = temp->next;
  temp->next = newNode;
}

template<typename T>
void PrintList(Node<T>* head) {
  Node<T>* temp = head;
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}

int main() {
  Node<int>* singlyLL = nullptr;
  InsertAtFront(singlyLL, 30);
  InsertAtFront(singlyLL, 20);
  InsertAtFront(singlyLL, 10);
  PrintList(singlyLL);

  InsertAtIndex(singlyLL, 15, 2);
  InsertAtIndex(singlyLL, 20, 0);
  InsertAtIndex(singlyLL, 6, 1);

  PrintList(singlyLL);

  return 0;
}