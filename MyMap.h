// Chuma Okoro CISC 3130 MY9 MyMap.h

#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Entry.h"
using namespace std;

class MyMap
{
    vector<list<Entry> > table;
    int hashString (string key);

public:
    MyMap(int buckets=21);
    void insert (const string& key, int value);
    bool containsKey(const string& key);
    bool containsValue(int value);
    void erase (const string& key);
    int getValueOf(const string& key);
    int& operator [] (const string& key);
    int size();
    bool empty();
};

#endif // MYMAP_H
