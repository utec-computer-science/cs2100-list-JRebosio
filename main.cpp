#include <iostream>
#include "list.h"

using std::cout;
using std::endl;



int main(){


    cs2100::LinkedList<int>l;
    l.push_back(3);l.push_back(4);l.push_back(5);l.push_back(6);
    l.push_back(7);l.push_back(8);l.push_back(9);l.push_back(10);
    l.push_back(11);l.push_back(12);l.push_back(13);
    cout<<"Linked List :\n\n\t\t\t\t"<<l<<"\n\n";

    l.erase(l.begin()+5);

    cout<<"Erase sixth element:\t\t\t"<<l<<"\n\n";


    l.insert(l.begin()+5,69);

    cout<<"Insert number 69 in sixth position: "<<l<<"\n\n\n";



    cout<<"\nOriginal Container :"<<"\n\n";
    cout<<l<<endl;

    cout<<"\nReverse O(n):"<<"\n\n";
    l.reverse();
    cout<<l<<endl;

	

	
    cout<<"\nSort O(n^2):"<<"\n\n";
    l.sort();
    cout<<l<<endl;	

	
}

