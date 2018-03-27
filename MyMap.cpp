// Chuma Okoro CISC 3130 MY9 MyMap.cpp
#include "MyMap.h"

MyMap::MyMap(int buckets):table(buckets)
{}
int MyMap::hashString (string key)
{
    int total=0;
    for(int i=0; i<key.length();i++)
    {
        total+=(int)key[i];//int value of each character
    }


    return (total*2+4)%table.size();//hash
}
void MyMap::insert(const string& key, int value) //insert a a string to the map. the value is the #of strings they have
{
    int keyhash=hashString(key);
    for(list<Entry>::iterator iter=table[keyhash].begin();
                    iter!=table[keyhash].end();iter++) //iterate through the list
    {
        if((*iter).getKey()==key) //check if its there
        {
            (*iter).setValue(value);
            return;
        }

    }

    Entry newentry(key,value); //declare a new entry with the key and value. than add to the table
    table[keyhash].push_back(newentry);
}

bool MyMap::containsKey(const string& key) // returns true or false depending  on if the key is present
{
    int keyhash=hashString(key);
    for(list<Entry>::iterator iter=table[keyhash].begin();
                    iter!=table[keyhash].end();iter++)
    {
        if((*iter).getKey()==key) //check if its there
            return true;
    }
    return false;
}

bool MyMap::containsValue(int value)
{
    for(int i=0;i<table.size();i++)
    {
        for(list<Entry>::iterator iter=table[i].begin();
                    iter!=table[i].end();iter++)
        {
            if((*iter).getValue()==value)
                return true;
        }
    }
    return false;

}

void MyMap::erase(const string& key)
{
    int keyhash=hashString(key);

    for(list<Entry>::iterator iter=table[keyhash].begin();
                    iter!=table[keyhash].end();iter++)
    {
        if((*iter).getKey()==key)
        {
            table[keyhash].erase(iter);
            return;
        }

    }
}

int MyMap::getValueOf(const string& key)
{
    int keyhash=hashString(key);

    for(list<Entry>::iterator iter=table[keyhash].begin();
                    iter!=table[keyhash].end();iter++)
    {
        if((*iter).getKey()==key)
            return (*iter).getValue();
    }
    throw "The Key is not in MyMap"; // may give errors
}

//    int& operator [] (const string& key);
int MyMap::size()
{
    int total=0;
    for(int i=0;i<table.size();i++)// get the size of each list and add it up
    {
        total+=table[i].size();
    }
    return total;
}
bool MyMap::empty()
{
    if(size()==0)
        return true;
    return false;
}

int& MyMap::operator[](const string& key)
{
    int keyhash=hashString(key);
    if(containsKey(key))
    {
        for(list<Entry>::iterator iter=table[keyhash].begin();
                    iter!=table[keyhash].end();iter++)
        {
            if((*iter).getKey()==key)
                 return (*iter).getValue();//return the value by reference
        }

    }
    insert(key,0);//insert the key if not already there
    for(list<Entry>::iterator iter=table[keyhash].begin();
                    iter!=table[keyhash].end();iter++) // return the value of the key we just inserted
        {
            if((*iter).getKey()==key)
                 return (*iter).getValue();
        }

}

