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
void PushAtBack(Node<T>*& head, T value) {
  Node<T>* newNode = new Node<T>(value);
  newNode->next = nullptr;
  if (head == nullptr) {
    newNode->next = head;
    head = newNode;
  } else {
    Node<T>* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

template<typename T>
void PrintList(Node<T>*& head) {
  Node<T>* temp = head;
  while(temp != nullptr) {
    cout <<temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}

template<typename T>
void ReverseList(Node<T>* head) {
  Node<T>* temp = head;
  Node<T>* next = nullptr;
  Node<T>* prev = nullptr;

  while (temp != nullptr) {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }

  temp = prev;
  while (temp != nullptr) {
    cout << temp->data << " - > ";
    temp = temp->next;
  }
  cout << "nullptr" <<endl;
}

int main() {
  Node<int>* singlyLL = nullptr;
  PushAtBack(singlyLL, 40);
  PushAtBack(singlyLL, 30);
  PushAtBack(singlyLL, 60);

  PrintList(singlyLL);

  ReverseList(singlyLL);

  return 0;
}