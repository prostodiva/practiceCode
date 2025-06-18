//reversing list using sliding pointers (by reversing linkes)
//create 3 pointers; slide forward until nullptr; relink the middle one to prev; middle pointer is a new head;


#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {};
};

void InsertAtEnd(Node*& head, int value) {
   Node* newNode = new Node(value);
   newNode->next = nullptr;
   if (head == nullptr) {
     head = newNode;
     return;
   } else {
     Node* temp = head;
     while(temp->next != nullptr) {
       temp = temp->next;
     }
     temp->next = newNode;
  }
}

//create 3 pointers; slide forward until nullptr; relink the middle one to prev; middle pointer is a new head;
void ReverseWithSliding(Node*& head) {
  //create 3 pointers
  Node* next = head;
  Node* temp = nullptr;
  Node* prev = nullptr;
  //slide forward
  while(next != nullptr) {
    prev = temp;
    temp = next;
    next = next->next;
  //relink the middle one
    temp->next = prev;
  }
  head = temp;
}



void PrintList(Node*& head) {
  Node* temp = head;
  while(temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<< endl;
}


int main() {
  Node* singlyLL = nullptr;
  InsertAtEnd(singlyLL, 20);
  InsertAtEnd(singlyLL, 30);
  InsertAtEnd(singlyLL, 40);
  InsertAtEnd(singlyLL, 50);

  PrintList(singlyLL);      //20 30 40 50

  ReverseWithSliding(singlyLL);
  PrintList(singlyLL);      //50 40 30 20

  return 0;
}