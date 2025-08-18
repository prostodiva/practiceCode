#include <iostream>
#include <string>

using namespace std;


void printArr(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i];
  }
  cout << endl;
}

int* deepCopy(int* newArr, int* oldArr, int size) {
  for (int i = 0; i < size; i++) {
    newArr[i] = oldArr[i];
  }
  return newArr;
}

//traverse until find the correct index
//shift the values to the right
//insert the value
void insertAtIndex(int*& arr, int index, int value, int size) {
  for (int i = size; i > index; i--) {
    arr[i] = arr[i-1];
  }
  arr[index] = value;
}

int* deleteAtIndex(int*& arr, int index, int size) {
  for (int i = index; i < size - 1; i ++) {
    arr[i] = arr[i+1];
  }
  return arr;
}

bool searchKey(int*& arr, int key, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      swap(arr[i], arr[0]);
      return true;
    }
  }
  return false;
}


int main() {
  //static
  int arr[5] = {3, 4, 3, 2, 5};
  printArr(arr, 5);

  //dynamic
  int* p = new int[4]{4, 3, 6, 4};
  printArr(p, 4);

  //resizing array - deep copy
  int* q = new int[10];
  deepCopy(q, p, 4);  // 4 elements to copy
  delete[] p;

  cout << "insert at index 2: ";
  insertAtIndex(q, 2, 9, 4);  //insert 9 at index 2. size of the array is 5
  printArr(q, 5);

  cout << "delete at index 1: ";
  deleteAtIndex(q, 1, 5);    //delete value 3
  printArr(q,4);

  cout << "lenear search. Search for key 9 and move it to head"<<endl;
  bool result = searchKey(q, 9, 4);
  cout << result<<endl;
  //print the head
  cout << q[0];

  delete[] q;


  return 0;
}