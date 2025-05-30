//Singly LinkedList practice program
//InsertNodeAtFront, InsertNodeAtEnd, PrintListForward, ReverseList
//pseudocode:
//create struct Node: data, next, constructor(assign data with value, next to nullptr)
//create an empty list in main
//InsertNodeAtFront:
//      - create a newNode
//      - make this node a head(deferencing)
//      - now head is at the beginning
//InsertNodeAtEnd:
//      - create a new Node
//      - asign the next pointer of new Node to nullptr
//      - check if the list is empty
//      - if true, make a new Node the head, return
//      - if not, make a temp pointer to traverse the list from head
//      - loop through the list untill it hit nullptr
//      - move to the next node
//      - asign the last node next with nullptr
//InsertAtIndex:
//      - if index < 0 - return. Don't work with negative
//      - if index == 0 - insertAtFront
//      - create temp node
//      - traverse through the linked List (for loop) until we hit the node BEFORE the providing index.
//      - change the next pointer to another node
//      - if next node == nullptr, return
//      - create a new Node
//      - inject a new Node into the Linked List
//      - temp node points to a new node
//PrintListForward:
//      - create a temp pointer to traverse the list from head
//      - traverse the list untill temp hit nullptr
//      - print the values
//      - update a nullptr when we reached the end of the list(move to the next node)
//ReverseList(Given the head of a list, reverse the list and return the head of reversed list):
//      - create a temp pointer to traverse the list from head
//      - create and initialize prev pointer to nullptr
//      - initialize next pointer to nullptr
//      - traverse through the nodes untill we hit nullptr
//      - store next
//      - Reverse current node's next pointer
//      - Move pointers one position ahead
//      - Return the head of reversed linked list
//test the functions in main:
//      - add values, print result, reverse, print again
//refactor (make it generic, using template)

#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node* next;

  Node(T value) : data(value), next(nullptr) {};
};

template <typename T>
void InsertNodeAtFront(Node<T>*& head, T value) {
  Node<T>* newNode = new Node<T>(value);
  newNode->next = head;
  head = newNode;
}

template <typename T>
void InsertNodeAtEnd(Node<T>*& head, T value) {
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

template <typename T>
void InsertAtIndex(Node<T>*& head, int index, T value) {
  if(index < 0) return;
  if(index == 0) {
    InsertNodeAtFront(head, value);
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


template <typename T>
void PrintListForward(Node<T>*& head) {
 Node<T>* temp = head;
 while (temp != nullptr) {
   cout <<temp->data << " -> ";
   temp = temp->next;
 }
 cout << "nullptr"<<endl;
}

template <typename T>
void PrintListBackwards(Node<T>*& head) {
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

  temp = prev;  // prev is now the new head
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr" << endl;
}

int main() {
  Node<int>* singlyLL = nullptr;
  InsertNodeAtFront(singlyLL, 1);
  PrintListForward(singlyLL);

  InsertNodeAtEnd(singlyLL, 2);
  PrintListForward(singlyLL);

  InsertNodeAtEnd(singlyLL, 5);
  PrintListBackwards(singlyLL);

  InsertAtIndex(singlyLL, 2, 5); //insert a new node with value '5' BEFORE index [2]
  PrintListForward(singlyLL);
  return 0;
}