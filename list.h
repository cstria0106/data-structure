#ifndef LIST_H
#define LIST_H

#include "linked_list.h"

class List : public LinkedList {
public:
  void insert(int index, int value) { LinkedList::insert(index, value); }
  int get(int index) { return LinkedList::get(index); }
};

#endif