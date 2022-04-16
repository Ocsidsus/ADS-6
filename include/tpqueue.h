// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  private:
    T arr[size];
    int first;
    int last;
  public:
    TPQueue() : first(0), last(0) { }
    void push(T x) {
        if (last - first >= size)
            throw std::string("Full!");
        else {
            int i = last++;
            while ((--i >= first) && (arr[i % size].prior < x.prior)) {
                arr[(i + 1) % size] = arr[i % size];
            }
        }
        arr[(i + 1) % size] = x;
    }
    T pop() {
        return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
