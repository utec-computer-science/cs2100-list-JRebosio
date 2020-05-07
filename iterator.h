
#include "node.h"


namespace cs2100 {


    template <typename Object>
    class iterator
    {


    protected:
        using Node= cs2100::Node<Object>;


    public:
        Node *current;

        iterator( ) : current{ nullptr }
        { }

        Object & operator* ( )
        { return current->data; }

        iterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }


        iterator & operator-- ( )
        {
            current = current->prev;
            return *this;
        }

        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }


        friend iterator operator+ (const iterator &left, const int& n)
        {
            iterator temp=left;
            for(int i=0;i<n;i++) temp.current=(temp.current)->next;
            return temp;
        }

        bool operator== ( const iterator & rhs )
        { return current == rhs.current; }
        bool operator!= ( const iterator & rhs )
        { return !( *this == rhs ); }\


        iterator( Node *p ) : current{ p }
        { }



    };
}

