//A string is a palindrome if it reads forward and backward in the same way
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
void InsertAtBack(Node<T>*& head, T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template<typename T>
void InsertAtFront(Node<T>*& head, T value) {
    Node<T>* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

//Find the Middle of the Linked List
//     Use the slow and fast pointers where slow advances by one step and fast by two steps.
//By the time fast reaches the end of the list, slow will be at the middle.
//Reverse the Second Half of the List
//     Reverse the linked list starting from the node at the slow pointer position.
//     use sliding three pointers technique
//Compare Both Halves
//Restore the List
//Return the Result
template<typename T>
bool isPalindrome(Node<T>* head) {
  Node<T>* slow = head;
  Node<T>* fast = head;
  if (head == nullptr || head->next == nullptr) return true;
  //find the middle
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
    //reverse the second half(with sliding three pointers)
    Node<T>* prev = nullptr;
    Node<T>* temp = nullptr;
    Node<T>* next = slow->next;
    while (next != nullptr) {
      prev = temp;
      temp = next;
      next = next->next;
      temp->next = prev;
     }
     prev = temp;
    //compare both halfs
    Node<T>* first = head;
    Node<T>* second = prev;
    bool palindrome = true;
    while (second != nullptr) {
      if (first->data != second->data) {
        palindrome = false;
        break;
      }
      first = first->next;
      second = second->next;
    }
    //restore the list
    temp = prev;
    prev = nullptr;
    while (temp) {
        Node<T>* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    slow->next = prev;

    //Return result
    return palindrome;
    }


template<typename T>
void PrintList(Node<T>*& head) {
    Node<T>* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" <<endl;
}

template<typename T>
void DeleteList(Node<T>*& head) {
  while (head != nullptr) {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
  head = nullptr;
}


//mom
int main() {
    Node<string>* singlyLL = nullptr;
    InsertAtBack(singlyLL, string("m"));
    InsertAtBack(singlyLL, string("o"));
    InsertAtBack(singlyLL, string("m"));
    PrintList(singlyLL);

    Node<int>* singlyIntList = nullptr;
    InsertAtBack(singlyIntList, 5);
    InsertAtBack(singlyIntList, 3);
    InsertAtBack(singlyIntList, 5);
    PrintList(singlyIntList);

    Node<int>* singlyLL2 = nullptr;
    InsertAtBack(singlyLL2, 5);
    InsertAtBack(singlyLL2, 7);
    InsertAtBack(singlyLL2, 9);
    PrintList(singlyLL2);

    cout << isPalindrome(singlyLL) <<endl;
    cout << isPalindrome(singlyIntList) <<endl;
    cout << isPalindrome(singlyLL2) <<endl;

    DeleteList(singlyLL);
    DeleteList(singlyLL2);
    DeleteList(singlyIntList);

    return 0;
}