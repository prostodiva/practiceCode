
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


//display recursively forward
//time and space compexity O(n) - not efficient
//create temp
//if statement - base condition != nullptr
//print
//call the function again
void DisplayForward(Node*& head) {
  Node* temp = head;
  if (temp != nullptr) {
    cout << temp->data << " -> ";
    DisplayForward(temp->next);
  }
}

void DisplayReversed(Node*& head) {
  Node* temp = head;
  if (temp != nullptr) {
    DisplayReversed(temp->next);
    cout << temp->data << " -> ";
  }
}

//O(n) - time, O(1) - space
void CountTheNodes(Node*& head) {
  Node* temp = head;
  int count = 0;
  while(temp != nullptr) {
    count++;
    temp = temp->next;
  }
  cout << count;
}

//count recursively
//time and space - O(n) - enefficient in terms of space
int CountRecursively(Node*& head) {
  Node* temp = head;
  if (temp == nullptr) {
    return 0;
  } else {
    return CountRecursively(temp->next) + 1;
  }
}

//sum of all the nodes
//time and space - O(n)
int AddValues(Node*& head) {
  Node* temp = head;
  if (temp == 0) {
    return 0;
  } else {
    return AddValues(temp->next) + temp->data;
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
  cout <<endl;
  CountTheNodes(singlyLL);
  cout <<endl;
  CountRecursively(singlyLL);

  return 0;
}