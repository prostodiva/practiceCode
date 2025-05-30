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
void PushBack(Node<T>*& head, T value) {
  Node<T>* newNode = new Node<T>(value);
  newNode->next = nullptr;
  if (head == nullptr) {
    head = newNode;
    return;
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
  while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "nullptr"<<endl;
}

template<typename T>
void ReverseList(Node<T>*& head) {
  Node<T>* temp = head;
  Node<T>* prev = nullptr;
  Node<T>* next = nullptr;

  // First reverse the list
  while (temp != nullptr) {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  //the list is reversed. going to oppisite direction
  temp = prev;   //prev is a new head
  while(temp != nullptr) {
    cout << temp->data <<" -> ";
    temp = temp->next;
  }
  cout <<"nullptr"<<endl;
 }

int main() {
  Node<int>* singlyLL = nullptr;
  PushBack(singlyLL, 10);
  PushBack(singlyLL, 12);
  PushBack(singlyLL, 14);
  PrintList(singlyLL);    //expected output 10 -> 12 -> 14 -> nullptr

  ReverseList(singlyLL);    //expected output 14 -> 12 -> 10

  return 0;
}