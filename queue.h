#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

class Queue : public LinkedList {
public:
  void push(int data) { LinkedList::insert(size_, data); }

  int pop() {
    if (size_ == 0)
      throw "Queue::pop() called on empty queue";
    int value = head_->value();
    LinkedList::remove(0);
    return value;
  }

  void insert(int index, int value) {
    throw "Queue::insert(int index, int value) is not supported";
  }
  int get(int index) { throw "Queue::get(int index) is not supported"; }
  void remove(int index) { throw "Queue::remove(int index) is not supported"; }

  Queue &operator+=(int data) {
    push(data);
    return *this;
  }
};

#endif