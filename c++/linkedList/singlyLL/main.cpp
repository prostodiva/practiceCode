//Singly LinkedList practice program
//InsertNodeAtFront, InsertNodeAtEnd, PrintListForward
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
//PrintListForward:
//      - create a temp pointer to traverse the list from head
//      - traverse the list untill temp hit nullptr
//      - print the values
//      - update a nullptr when we reached the end of the list(move to the next node)
//PrintListBackwards(Given the head of a list, reverse the list and return the head of reversed list):
//      - create a temp pointer to traverse the list from head
//      - create and initialize prev pointer to nullptr
//      - initialize next pointer to nullptr
//      - traverse through the nodes untill we hit nullptr
//      - store next
//      - Reverse current node's next pointer
//      - Move pointers one position ahead
//      - Return the head of reversed linked list
//test the functions in main:
//add values and print a result
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
  
  // Now print the reversed list
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
  return 0;
}