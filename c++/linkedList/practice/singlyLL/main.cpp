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
void PushAtFront(Node<T>*& head, T value) {
  Node<T>* newNode = new Node<T>(value);
  newNode->next = head;
  head = newNode;
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

template<typename T>
void deleteList(Node<T>*& head) {
  while (head != nullptr) {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
}

//10, 30 20
int main() {
  Node<int>* singlyLL = nullptr;
  PushAtFront(singlyLL, 20);
  PushAtFront(singlyLL, 30);
  PushAtFront(singlyLL, 10);

  PrintList(singlyLL);
  
  // DEALLOCATE ALL MEMORY
  deleteList(singlyLL);
  singlyLL = nullptr;  // Good practice
  
  return 0;
}