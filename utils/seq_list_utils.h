#ifndef SEQ_LIST_UTILS_H
#define SEQ_LIST_UTILS_H

#include <iostream>
using namespace std;

#define Element_Type int
#define MAXSIZE 100

struct Linear_List {
    Element_Type data[MAXSIZE];
    int length = 0;
};

#endif // SEQ_LIST_UTILS_H
