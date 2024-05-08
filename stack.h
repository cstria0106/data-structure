#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

class Stack : public LinkedList {
public:
  void push(int data) { LinkedList::insert(0, data); }

  int pop() {
    if (size_ == 0)
      throw "Stack::pop() called on empty stack";
    int value = head_->value();
    LinkedList::remove(0);
    return value;
  }

  void insert(int index, int value) {
    throw "Stack::insert(int index, int value) is not supported";
  }
  int get(int index) { throw "Stack::get(int index) is not supported"; }
  void remove(int index) { throw "Stack::remove(int index) is not supported"; }

  Stack &operator+=(int data) {
    push(data);
    return *this;
  }
};

#endif