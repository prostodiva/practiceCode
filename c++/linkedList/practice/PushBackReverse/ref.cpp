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
  //Initialize pointers
  Node<T>* temp = head;      //temp node starts at the head
  Node<T>* prev = nullptr;   //prev node starts at null
  Node<T>* next = nullptr;   //next node starts at null

  //traverse the list
  while (temp != nullptr) {
    next = temp->next;      //save the next node
    temp->next = prev;      //reverse the list
    //move pointers forward
    prev = temp;            //move prev to temp node
    temp = next;            //move temp to next node
  }

  //the list is reversed. going to oppisite direction to print
  // or just return prev(for leetcode problem)
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