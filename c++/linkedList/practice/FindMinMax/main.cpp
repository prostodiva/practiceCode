#include <iostream>
#include <string>

using namespace std;

struct Node{
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {};
};

Node* CreateList(int arr[], int size) {
  if (size == 0) return nullptr;

  Node* head = new Node(arr[0]);
  Node* temp = head;
  for (int i = 1; i < size; i++) {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }
  return head;
}

void PrintList(Node* head) {
  Node* temp = head;
  while(temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "nullptr"<<endl;
}


int FindMax(Node* head) {
   int max = -32768;
   Node* temp = head;
   while (temp != nullptr) {
     if (temp->data > max) {
       max = temp->data;
     }
     temp = temp->next;
   }
   return max;
}

int FindMin(Node* head) {
  int min = 32768;
  Node* temp = head;
  while(temp != nullptr) {
    if (temp->data < min) {
      min = temp->data;
    }
    temp = temp->next;
  }
  return min;
}


//create a list from the array
int main() {
  int list[] = {5, 10, 2, 8};
  Node* linkedList = CreateList(list, 4);
  PrintList(linkedList);

  int max = FindMax(linkedList);
  cout << max <<endl;

  int min = FindMin(linkedList);
  cout << min << endl;

  return 0;
}