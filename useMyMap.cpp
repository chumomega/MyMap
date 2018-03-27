// Chuma Okoro CISC 3130 MY9 useMyMap.cpp
#include "MyMap.cpp"
#include <fstream>

int main()
{
    string random="This is a random string";
    int amount;
    MyMap newmap;

    ifstream infile("test.txt");
    if(infile)
        while(infile>>random>>amount)
            newmap.insert(random,amount);
    cout<<"The number of elements in the map is: "<<newmap.size()<<endl;


    cout<<"The map contains the string Removes_the_frontmost_element_in_this_queue: ";
    cout<<boolalpha<<newmap.containsKey("Removes_the_frontmost_element_in_this_queue")<<endl;

    cout<<newmap.getValueOf("Removes_the_frontmost_element_in_this_queue");
    cout<<" is the value of that string"<<endl;
    newmap.erase("Removes_the_frontmost_element_in_this_queue");

    cout<<"The map contains the string Removes_the_frontmost_element_in_this_queue: ";
    cout<<boolalpha<<newmap.containsKey("Removes_the_frontmost_element_in_this_queue")<<endl;


    cout<<"The map contains the value 4: ";
    cout<<boolalpha<<newmap.containsValue(4)<<endl;
    cout<<"The map contains the value 0: ";
    cout<<boolalpha<<newmap.containsValue(0)<<endl;

    cout<<"The map is empty: "<<boolalpha<<newmap.empty()<<endl<<endl;

    newmap["newentry"]=5;
    cout<<"The value of newentry is: "<<newmap.getValueOf("newentry")<<endl<<endl;










    return 0;
}
