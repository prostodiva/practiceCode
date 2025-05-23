#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node* next;
  Node* prev;

  Node(T value) : data(value), next(nullptr), prev(nullptr) {};
};

template <typename T>
struct DoublyLL {
  Node<T>* head;
  Node<T>* tail;

  DoublyLL() : head(nullptr), tail(nullptr) {};

  void InsertAtFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    if (head != nullptr) {
      head->prev = newNode;
    } else {
      tail = newNode;
    }
    head = newNode;
  }

  void InsertAtEnd(T value) {
    //if the list is empty
    if (tail == nullptr) {
      InsertAtFront(value);
    }
    Node<T>* newNode = new Node<T>(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  void PrintForward() {
    Node<T>* current = head;
    cout << "nullptr <- ";
    while (current != nullptr) {
      cout << "(" << current->data << ")";
      if (current->next != nullptr) {
        cout << " <-> ";
      }
      current = current->next;
    }
    cout << " -> nullptr" << endl;
  }

  void PrintBackwards() {
    Node<T>* current = tail;
    cout << "nullptr <- ";
    while (current != nullptr) {
      cout << "(" << current->data << ")";
      if (current->prev != nullptr) {
        cout << " <-> ";
      }
      current = current->prev;
    }
    cout << " -> nullptr" << endl;
  }
};

template <typename T>
void printList(Node<T> *head) {

}

int main() {
  DoublyLL<string> DbLinkedList;
  DbLinkedList.InsertAtFront("world");
  DbLinkedList.InsertAtFront("hello");
  DbLinkedList.PrintForward();
  DbLinkedList.InsertAtEnd("Rita");
  DbLinkedList.PrintForward();
  DbLinkedList.PrintBackwards();
  return 0;
}