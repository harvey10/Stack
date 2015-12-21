#include <iostream>

using namespace std;

const int maxStackSize = 10;

class Stack {
public:
  int getStackSize();
  void push(int);
  int pop();
  bool isEmpty();
  bool isFull();
  void print();
  Stack();
  ~Stack();
private:
  int stackSize;
  int *stackArray;
};

int Stack::getStackSize() {
  return stackSize;
}

void Stack::push(int a) {
  try {
    if (isFull())
      throw a;
    else {
      stackSize++;
      stackArray[stackSize] = a;
    }
  }
  catch(int a) {
    cout << "Stack is full" << endl;
  }
  catch(...) {
    cout << a << " is not an acceptable input. Try again." << endl;
  }
}

int Stack::pop() {
  try {
    if (isEmpty())
      throw;
  return stackArray[stackSize--];
}
catch(...) {
  cout << "Stack is already empty" << endl;
}
}

bool Stack::isEmpty() {
  return stackSize == 0;
}

bool Stack::isFull() {
  return stackSize == maxStackSize;
}

void Stack::print() {
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
  }
  else {
    for (int i = 0; i < stackSize; i++) {
      cout << stackArray[i];
      if (i != stackSize-1) {
        cout << " ,"
      }
    }
    cout << endl;
  }
}

Stack::Stack() {
  stackSize = 0;
  stackArray = new int[maxStackSize];
}

Stack::~Stack() {
  delete [] stackArray;
}
