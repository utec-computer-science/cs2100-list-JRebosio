
#include "list.h"
typedef cs2100::ForwardListNode<float> forward_node_t;
typedef cs2100::ForwardList<forward_node_t> list_t;
typedef list_t::ForwardIterator iterator_t;

typedef cs2100::DoubleListNode<float> double_node_t;
typedef cs2100::ForwardList<double_node_t> dlist_t;

typedef cs2100::CircularListNode<float> circular_node_t;
typedef cs2100::ForwardList<circular_node_t> clist_t;

typedef cs2100::CircularDoubleListNode<float> circular_double_node_t;
typedef cs2100::ForwardList<circular_double_node_t> cdlist_t;


int main (int, char *[]){


    list_t list;
    list << 10 << 12 << 3 << 6 >> 5 >> 7 >> 8 << 9 << 10;
    list >> 25 >> 23;
    list.pop_back();

    cout<<"\nlist with forward node :\n\n"<<list<<"\n";



    dlist_t dlist;
    dlist << 10 << 12 << 6 << 7 >> 87 >> 99;
    dlist >> 11 >> 18;
    dlist.pop_back();
    dlist.pop_back();
    dlist.pop_front();
    dlist.push_front(1);
    cout<<"\nlist with doubly list node :\n\n"<<dlist<<endl;



    clist_t clist;
    clist << 10 << 12 << 5<<7<<8<<9;
    clist >> 5 >> 7 >> 8 << 60 << 100 << 400 ;
    clist.pop_front();

    cout<<"\nlist with circular list node :\n\n"<<clist<<endl;


    cdlist_t cdlist;
    cdlist << 10 << 12 << 5 << 20 << 30<< 40 >> 50 >> 60 >> 70 >> 80 >> 100>> 120>> 140>>150 >>123>> 167>>187;
    cdlist.pop_back();
    cdlist.pop_back();
    cdlist.pop_front();

    cout<<"\nlist with circular doubly list node :\n\n"<<clist<<endl;

    return 0;
}