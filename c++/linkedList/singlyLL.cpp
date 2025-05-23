#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node* next;

  //constructor
  Node(T value) : data(value), next(nullptr) {}
};

  //function to add a new node to the front of the singly LinkedList
template <typename T>
void InsertAtFront(Node<T>*& head, T value) {
  //create a new node
  Node<T>* newNode = new Node<T>(value);
  //have to assign this node at the beginning. Make this new node a head
  newNode->next = head; //head was first, now it is not(dereferencing)
  head = newNode; //now head is at the beginning
}

template <typename T>
void InsertAtEnd(Node<T>*& head, T value) {
  Node<T>* newNode = new Node<T>(value);
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

//significally more inefficient than an array. Traversing through all of the elements until you meet the criteria you want
template <typename T>
void InsertAtIndex(Node<T>*& head, int index, T value) {
  if(index < 0) return;
  if(index == 0) {
    InsertAtFront(head, value);
    return;
  }

  Node<T>* current = head;  //a new temp pointer
  //traverse through the list until we hit the node before the provided index
  for(int i = 0; current != nullptr && i < index-1; i++) {
      current = current->next; //reference to another node of nullprt
  }
  
  if(current == nullptr) {
    return; //or throw the error:  cerr << ""
  }
  
  //if we make it here, current points to Node that we're looking for at index -1
  Node<T>* newNode = new Node<T>(value); //create a new node
  newNode->next = current->next;  //new node gets injected into linked list
  current->next = newNode;  //current node now points to a new node
}

//function to print all the elements in LinkedList format
template <typename T>
void Print(Node<T>*& head) {
  Node<T>* temp = head; //usefull for if you pass a reference var.
  //travercing from head to tail. check for the nullprt
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;  //update a nullptr, when we reached the end of the list
  }
  cout << "nullptr"<< endl;
}

int main() {
  //start of my linked List currently set to an empty list
  Node<int>* headIntList = nullptr;
  //head updates over and over
  InsertAtFront(headIntList, 3); //list now should be 3->nullptr
  InsertAtFront(headIntList, 1); //list now should be 1->3->nullptr
  InsertAtFront(headIntList, 8);
  Print(headIntList);

  InsertAtIndex(headIntList, 2, 5); //insert a new node with value '5' BEFORE index [2]
  Print(headIntList);

  InsertAtEnd(headIntList, 10);
  Print(headIntList);

  //create a new list type strings
  Node<string>* headStringList = nullptr;
  InsertAtFront(headStringList, string("world"));
  InsertAtFront(headStringList, string("hello"));
  Print(headStringList);

  InsertAtIndex(headStringList, 1, string("cool"));
  Print(headStringList);
  return 0;
}