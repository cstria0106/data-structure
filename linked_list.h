#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <iostream>

class LinkedList {
public:
  LinkedList() {
    head_ = nullptr;
    size_ = 0;
  }

  ~LinkedList() {
    Node *node = head_;
    while (node != nullptr) {
      Node *next = node->next_;
      delete node;
      node = next;
    }
  }

  void insert(int index, int value) {
    if (index < 0 || index > size_)
      throw "LinkedList::insert(int index, int value) index out of bounds";
    Node *node = new Node(value);
    if (index == 0) {
      node->next_ = head_;
      head_ = node;
    } else {
      Node *prev = head_;
      for (int i = 0; i < index - 1; i++)
        prev = prev->next_;
      node->next_ = prev->next_;
      prev->next_ = node;
    }
    size_++;
  }

  int get(int index) {
    if (index < 0 || index >= size_)
      throw "LinkedList::get(int index) index out of bounds";
    Node *node = head_;
    for (int i = 0; i < index; i++)
      node = node->next_;
    return node->value();
  }

  void remove(int index) {
    if (index < 0 || index >= size_)
      throw "LinkedList::remove(int index) index out of bounds";
    Node *node = head_;
    if (index == 0) {
      head_ = head_->next_;
      delete node;
    } else {
      for (int i = 0; i < index - 1; i++)
        node = node->next_;
      Node *next = node->next_;
      node->next_ = next->next_;
      delete next;
    }
    size_--;
  }

  void print() {
    Node *node = head_;
    while (node != nullptr) {
      std::cout << node->value() << " ";
      node = node->next_;
    }
    std::cout << std::endl;
  }

  int size() { return size_; }

protected:
  Node *head_;
  int size_;
};

#endif