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

//check if head and head->next is nullptr(check for an empty string)
//find the middle of the list(slow is the middle)
//	- create two pointers(fast && slow)
//	- traverse through the list until fast->next != nullptr
//reverse the second half
//	- sliding pointers technique
//	- create three pointers(prev, temp, next);next starts from slow->next
//	- reverse with 4 steps
//  prev is a new head
//compare halfs
//	- create two pointers(first, second)
//restore the list
//return the result
template<typename T>
bool isPalindrome(Node<T>* head) {
    if (head == nullptr && head->next == nullptr) return true;

    Node<T>* slow = head;
    Node<T>* fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

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
    while (temp != nullptr) {
      Node<T>* next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
   slow->next = prev;

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