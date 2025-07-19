//delete first node
//delete at position
//don't forget to delete temp

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {};
};

void InsertAtBack(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//create temp
//move a head to next node
//save the value from temp
// delete temp
void DeleteFirstNode(Node*& head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

//(remove at position 3(it means index 2))
// 20 30 40 50
//create two pointers
//search for index
//relink prev
//deallocate temp
void DeleteAtPosition(Node*& head, int position) {
  Node* temp = head;
  Node* prev = nullptr;
  for (int i = 0; i < position - 1; i++) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  delete temp;
}

//returns deleted data value
int DeleteNode(Node*& head, int position) {
   Node* temp = head;
   Node* prev = nullptr;
   int x = -1;
   if (head == nullptr) return x;
   if (position == 1) {
     head = head->next;
     x = temp->data;
     delete temp;
   }
   for (int i = 0; i < position - 1 && temp != nullptr; i++) {
     prev = temp;
     temp = temp->next;
   }
   if (temp != nullptr) {
     prev->next = temp->next;
     x = temp->data;
     delete temp;
   }
   return x;
}

//test this function
Node* removeNthFromEnd(Node* head, int n) {
    if (head == nullptr) return nullptr;

    // Use two pointers approach
    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n && fast != nullptr; i++) {
        fast = fast->next;
    }

    // If fast becomes null, we need to remove the head
    if (fast == nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from end
    prev->next = slow->next;
    delete slow;

    return head;
}

void PrintList(Node*& head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" <<endl;
}


//sorted list: 10 20 30 40 50
//delete 10
//delete 40 (position 4(it means index3))
//delete 30 (position 3(index 0))
// the final output: 20 50
// 30
int main() {
    Node* singlyLL = nullptr;
    InsertAtBack(singlyLL, 10);
    InsertAtBack(singlyLL, 20);
    InsertAtBack(singlyLL, 30);
    InsertAtBack(singlyLL, 40);
    InsertAtBack(singlyLL, 50);
    PrintList(singlyLL);

    DeleteFirstNode(singlyLL);
    PrintList(singlyLL);

    DeleteAtPosition(singlyLL, 3); //where 3 is a position. it will be index 2
    PrintList(singlyLL);

    //20 30 50
    int result = DeleteNode(singlyLL, 2);     //2 is a position
    // 20 50
    PrintList(singlyLL);
    cout << result;


    return 0;
}