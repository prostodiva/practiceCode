
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

void InsertAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void DisplayForward(Node*& head) {
  Node* temp = head;
  if (temp != nullptr) {
    cout << temp->data<< " -> ";
    DisplayForward(temp->next);
  }
}

void DisplayReversed(Node*& head) {
    Node* temp = head;
    if (temp != nullptr) {
      DisplayReversed(temp->next);
      cout << temp->data<< " -> ";
    }
}

void CountNodes(Node*& head) {
  int count;
  Node* temp = head;
  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  cout <<count;
}

int CountRecursively(Node*& head) {
  Node* temp = head;
  if (temp == nullptr) {
    return 0;
    } else {
    return CountRecursively(temp->next) + 1;
  }
}

int AddValues(Node*& head) {
   Node* temp = head;
   if (temp == 0) {
     return 0;
   } else {
     return AddValues(temp->next) + temp->data;
   }
}

int FindMax(Node*& head) {
  Node* temp = head;
  int max = 0;
  if (temp == nullptr) {
     return 0;
  } else {
     max = FindMax(temp->next);
     return max > temp->data ? max : temp->data;
  }
}



int main() {
    Node* singlyLL = nullptr;
    InsertAtFront(singlyLL, 5);
    InsertAtFront(singlyLL, 4);
    InsertAtFront(singlyLL, 3);
    InsertAtFront(singlyLL, 2);
    InsertAtFront(singlyLL, 1);
    DisplayForward(singlyLL);
    cout <<endl;
    DisplayReversed(singlyLL);

    return 0;
}