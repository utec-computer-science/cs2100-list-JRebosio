#include <iostream>
#include <ostream>


namespace cs2100 {

    template <typename Object>
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;

        Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
                : data{ d }, prev{ p }, next{ n } { }

    };




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





    template <typename Object>
    class LinkedList
    {
    protected:

        using iterator= cs2100::iterator<Object>;
        using Node= cs2100::Node<Object>;
    public:



        LinkedList( )
        { init( ); }

        LinkedList( const LinkedList & rhs )
        {
            init( );
            for( auto & x : rhs )
                push_back( x );
        }
        ~LinkedList( )
        {
            clear( );
            delete head;
            delete tail;
        }
        LinkedList & operator= ( const LinkedList & rhs )
        {
            LinkedList copy = rhs;
            std::swap( *this, copy );
            return *this;
        }



        iterator begin( ) const
        { return {head->next} ; }

        iterator end( ) const
        { return { tail }; }


        int size( ) const
        { return theSize; }
        bool empty( ) const
        { return size( ) == 0; }

        void clear( )
        {
            while( !empty( ) )
                pop_front( );
        }


        Object & front( )
        { return *begin( ); }

        Object & back( )
        { return *--end( ); }

        void push_front( const Object & x )
        { insert( begin( ), x ); }

        void push_back( const Object & x )
        { insert( end( ), x ); }

        void pop_front( )
        { erase( begin( ) ); }

        void pop_back( )
        { erase( --end( ) ); }

        iterator insert( iterator itr, const Object & x)
        {
            Node *p = itr.current;
            theSize++;
            return { p->prev = p->prev->next = new Node{ x, p->prev, p } };
        }

        iterator erase( iterator itr )
        {
            Node *p = itr.current;
            iterator retVal{ p->next };
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            theSize--;
            return retVal;
        }



        iterator erase( iterator from, iterator to )
        {
            for( iterator itr = from; itr != to; )
                itr = erase( itr );
            return to;
        }


        Object& operator[] (const int& x)
        {
            Node* temp = head->next;
            for(int i=0;i<x;i++)
                temp=temp->next;
            return temp->data;
        };


        LinkedList& reverse()
        {
            for(int i=0;i<theSize/2;i++)
            {
                Object temp=(*this)[i];
                (*this)[i]=(*this)[theSize-1-i];
                (*this)[theSize-1-i]=temp;

            }
            return *this;
        };


        LinkedList& sort()
        {
            for (int i = 1; i < theSize; i++)
            {
                Object key = (*this)[i];
                int j=i-1;
                while (j >= 0 && (*this)[j] > key)
                {
                    (*this)[j + 1] = (*this)[j];
                    j = j - 1;
                }
                (*this)[j + 1] = key;
            }

            return *this;

        };




	void remove(const Object& x) 
        {
              iterator temp(head);
              while(temp!=end())
              {
                  iterator temp2=temp+1;
                  if(*(temp)==x)                  
                    erase(temp);
                  temp=temp2;
              }
        };






        inline friend std::ostream& operator<< (std::ostream& os, const LinkedList & l)
        {
            iterator temp=l.begin();
            while(temp.current->next!=nullptr){
                os<<*temp<<"->";
                ++temp;
            }
            return os;
        };

    protected:
        int theSize;
        Node *head;
        Node *tail;

        void init( )
        {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }




    };

}

