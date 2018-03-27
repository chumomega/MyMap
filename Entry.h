// Chuma Okoro CISC 3130 MY9 Entry.h
#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
using namespace std;

class Entry
{
    pair<string,int> entrypair;
public:
    Entry(const string& key="Default Value", int value=0): entrypair(key,value) {}
    string getKey() {return entrypair.first;}
    int& getValue() {return entrypair.second;}
    void setValue(int value) {entrypair.second=value;}
};

#endif // ENTRY_H

