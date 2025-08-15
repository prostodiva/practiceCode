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
  Node<T>* newNode = new Node<T>(value);    //create a new node
  newNode->next = head;         //make a new node the head
  head = newNode;
}

template<typename T>
void PrintList(Node<T>* head) {
  Node<T>* current = head;        //create a temp pointer with the same address as the head
  while (current != nullptr) {    //while current is nos nullptr(the end of the list)
    cout << current->data << " -> ";  //print the value in the node
    current = current->next;        //move current to the next node
  }
  cout << "nullptr"<<endl;
}

//expected output: 10 -> 8 -> 3 -> nullptr
int main() {
  Node<int>* intList = nullptr;
  InsertAtFront(intList, 3);
  InsertAtFront(intList, 8);
  InsertAtFront(intList, 10);

  PrintList(intList);
  return 0;
}