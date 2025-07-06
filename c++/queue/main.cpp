#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class ArrayQueue {
  private:
    T* _arr;
    int _front;
    int _rear;
    int _size;
    int _count;
   public:
     ArrayQueue(int size = 10) : _front(0), _rear(-1), _size(size), _count(0) {
                                   _arr = new T[size];
     };
     ~ArrayQueue() {
       delete[] _arr;
     }

     /*
      Ex1.
      Let's say we have a Queue of size 5
    Current status:
    - _front = 3
    - _rear = 1
    Queue: [?,?,?,40,50]
    Enqueue(60)
      Queue: [?,?,60, 40,50]
      _rear moves from 1 to (1+1) % 5 = 2

    Dequeue(40)
      Queue: [?,?, 60, ?, 50]
      - _front(3 + 1) % 5 = 4
     */


    //add a value to the rear
    void Enqueue(T value) {
      if (_count == _size) //check for an overflow. if there is no room to add a new element. Array is full.
        throw std::runtime_error("Queue is full");
      _rear = (_rear + 1) % _size; //incr rear - go to the next avaliable space [?,item2,item3] loop back around to see if we have a space at the beginning
      _arr[_rear] = value;
      _count++;
    }
    //remove and return the value at the front
    T Dequeue() {
      if(IsEmpty()) throw std::runtime_error("Queue is empty");
      T valueToReturn = _arr[_front];
      _front = (_front + 1) % _size;
      _count--;
      return valueToReturn;  //return the reference
    }

    //return the value at the front without removing it
    T Peek() {
      if (!IsEmpty()) return _arr[_front];
    }

    bool IsEmpty() const {
      return _count == 0;
    }

    int Size() const {
      return _count;
    }

};


template <typename T>
struct Node {
  T data;
  Node<T>* next;

  Node(T data, Node<T>* next = nullptr) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedListQueue {
private:
  Node<T>* _head;
  Node<T>* _tail;
public:
  LinkedListQueue() : _head(nullptr), _tail(nullptr) {}
  ~LinkedListQueue() {        //O(n)
    while (!IsEmpty())
      Dequeue();
  }
  void Enqueue(T value) { //O(1)
    Node<T>* newNode = new Node<T>(value);
    if (_tail) _tail->next = newNode;
    _tail = newNode;
    if (!_head) _head = _tail;  //if it's completely empty, _head = _tail when we enqueue a single node
  }

  //removing a value from the head
  T Dequeue() {
    if (IsEmpty()) throw std::runtime_error("Queue is empty");
    Node<T>* oldHeadPointer = _head;  //reference to the old head node
    T valueToReturn = oldHeadPointer->data; //grabbing a value to return
    _head = _head->next;  //adjust head ptr to point to a new value
    if (!_head) _tail = nullptr;  //make sure that _tail is also pointing to nullptr
    delete oldHeadPointer;
    return valueToReturn;
  }

  T Peek() {
    if (IsEmpty()) throw std::runtime_error("Queue is empty");
    return _head->data;  //return the data that about t be dequeued
  }
  bool IsEmpty() const {
    return !_head;
  }
};

int main() {
  //ArrayQueue<int> intQueue(3);
  LinkedListQueue<int> intQueue;
  intQueue.Enqueue(10);
  intQueue.Enqueue(20);
  intQueue.Enqueue(30);
  intQueue.Dequeue();
  intQueue.Enqueue(40);

  while(!intQueue.IsEmpty())
    cout <<"Dequeued: " << intQueue.Dequeue() << endl;

  return 0;
}

