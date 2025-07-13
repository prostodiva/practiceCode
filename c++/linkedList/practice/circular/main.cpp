#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {}
};


Node* CreateList(Node*& head, int value) {
  Node* newNode = new Node(value);
  if (head == nullptr) {
    newNode->next = newNode;  //first node points to itself
    head = newNode;
  } else {
    Node* temp = head;
    while(temp->next != head) { //find the last node and insert after
      temp = temp->next;
    }
    newNode->next = head;      //the new node poits to the first node
    temp->next = newNode;      //the last node points to the new node
  }
  return head;
}

void PrintList(Node* head) {
  Node* temp = head;
  do {
    cout << temp->data <<"->";
    temp = temp->next;
  } while (temp != head);
}

void DeleteList(Node*& head) {
  if (head == nullptr) return;

  Node* temp = head->next;
  while (temp != head) {
    Node* last = temp;
    temp = temp->next;
    delete last;
  }
  delete head;
  head = nullptr;
}

int main() {
  Node* circularList = nullptr;
  
  CreateList(circularList, 10);
  CreateList(circularList, 20);
  CreateList(circularList, 30);

  PrintList(circularList);
  DeleteList(circularList);
  
  return 0;
}
