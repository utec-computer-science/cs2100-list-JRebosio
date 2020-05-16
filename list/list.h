#include <iostream>
#include <ostream>
#include "iterator.h"

using namespace std;
namespace cs2100 {



    template <typename Node>
    class List {
    protected:
        typedef Node node_t;
        typedef typename node_t::value_t value_t;

        node_t* head;

    public:
        List(const List&):head(nullptr){
        }

        List(value_t*):head(nullptr){
        }

        List(node_t*):head(nullptr){
        }

        List(int):head(nullptr){
        }

        List(void):head(nullptr){
        }

        ~List(void){
        }


        virtual void push_back(const value_t& element) = 0;
        virtual void push_front(const value_t& element) = 0;

        virtual value_t& front(void) = 0;
        virtual value_t& back(void) = 0;

        virtual node_t* pop_back(void) = 0;
        virtual node_t* pop_front(void) = 0;

        virtual value_t& operator[] (const int&) = 0;

        virtual bool empty(void){
            return head == nullptr;
        };

        virtual unsigned int size(void) = 0;
/*
        template<typename _T>
        inline friend ostream& operator << (ostream& out, const List<_T>&){
            out << "Nothing to print in father" << endl;
            return out;
        }
*/

        List& operator<< (const value_t& _value){
            this->push_back(_value);
            return *this;
        }

        List& operator>> (const value_t& _value){
            this->push_front(_value);
            return *this;
        }
    };


#define DEFAULT_NODE 0
#define FOWARD_NODE 1
#define DOUBLE_NODE 2
#define CIRCULAR_NODE 3
#define CIRCULAR_DOUBLE_NODE 4


    template <typename T, typename NT>
    struct NodeTraits{
        static const int nodeType = DEFAULT_NODE;
    };

    template <typename NT>
    struct NodeTraits< ForwardListNode<NT>, NT >{
        static const int nodeType = FOWARD_NODE;
    };

    template <typename NT>
    struct NodeTraits< DoubleListNode<NT>, NT >{
        static const int nodeType = DOUBLE_NODE;
    };

    template <typename NT>
    struct NodeTraits< CircularListNode<NT>, NT >{
        static const int nodeType = CIRCULAR_NODE;
    };


    template <typename NT>
    struct NodeTraits< CircularDoubleListNode<NT>, NT >{
        static const int nodeType = CIRCULAR_DOUBLE_NODE;
    };



    template <typename Node>
    class ForwardList : public List<Node>{
    public:
        typedef Node node_t;
        typedef typename node_t::value_t value_t;

        friend class ForwardIterator;
        class ForwardIterator: public Iterator<node_t> {
        public:
            typedef typename cs2100::Iterator<node_t>::node_t node;
            typedef typename Iterator<node_t>::value_t value_t;

        public:
            ForwardIterator (node* pointer = nullptr)
                    :Iterator<node>(pointer){
            }

            ~ForwardIterator (void){
            }
            bool operator== ( const ForwardIterator & rhs )
            { return this->pointer == rhs.pointer; }

            bool operator!= ( const ForwardIterator & rhs )
            { return !( *this == rhs ); }

            ForwardIterator& operator++ (void){
                Iterator<node>::pointer = Iterator<node>::pointer->next;
                return *this;
            }

        };

    protected:
        node_t *head= nullptr;
        node_t *tail;
        int thesize=0;

        template<int nodeType>
        void __add__(Node**,Node**,value_t);

        template<int nodeType>
        void __add_front__(Node**,Node**,value_t);

        template<int nodeType>
        void __remove__(Node**,Node**);

        template<int nodeType>
        void __remove_front__(Node**,Node**);


        template<int nodeType>
        void __print__(Node**,Node**,std::ostream &os);
    public:

        void push_back(const value_t& element){
            __add__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element);
            thesize++;
        }


        ForwardList(void)
                :List<node_t>(), head(nullptr), tail(nullptr){
        }

        ~ForwardList (void){
        }

        ForwardIterator begin() const{
            return ForwardIterator(head);
        }

        ForwardIterator end() const{
            return ForwardIterator(tail);
        }

        void push_front(const value_t& element){
            __add_front__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element);
            thesize++;

        }

        value_t& front(void){
            return head->value;
        };

        value_t& back(void){
            return tail->value;
        };

        node_t* pop_back(void){
            if(thesize==0){ head= nullptr; return head; }
            node_t* tmpRes = new node_t(tail->value);
            __remove__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
            thesize--;
            return  tmpRes;
        };

        node_t* pop_front(void){

            if(thesize==0){ head= nullptr; return head; }
            node_t* tmpRes = new node_t(head->value);
            __remove_front__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail);
            thesize--;
            return  tmpRes;

        };

        value_t& operator[] (const int& _position){
            node_t * tmp = head;
            for (int i = 0; i < _position; i++, tmp = tmp->next);
            return tmp->value;
        }

        bool empty(void){

            return head == nullptr;
        }

        unsigned int size(void){

            int i = 0;
            for (node_t * tmp = head; tmp != nullptr; i++, tmp = tmp->next);
            return i;
        }


        inline friend std::ostream& operator<< (std::ostream& os, ForwardList & l)
        {
            l.__print__<NodeTraits<node_t,value_t>::nodeType>(&l.head,&l.tail,os);
            /*
            ForwardIterator  it = l.begin();
            for(; it !=l.end(); ++it){
                os << *it << " -> ";
            }
            os << *it << " -> ";
            */

           return os;
        };




/*

        template<typename _T>
        inline friend std::ostream& operator<< (std::ostream& out, ForwardList<_T>& _list){
            typename ForwardList<_T>::ForwardIterator it = _list.begin();
            for(; it != _list.end(); ++it){
                out << *it << " -> ";
            }
            out << *it << " -> ";

            if (!_list.head) return out;
            ForwardListNode<T> *tmp = _list.head;
            while(tmp){
                out << *tmp << " -> ";
                tmp = tmp->next;
            }

            return out;
        }
    */





    };

    template <typename Node, typename ValueNode, int nodeType>
    class ListHelper{
    public:
        static void add(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;

        }

        static void add_front(Node** head, Node** tail, ValueNode element){
            cout << "Hola no tengo trait definido" << endl;

        }

        static void remove(Node** head, Node** tail){
            cout << "Hola no tengo trait definido" << endl;

        }

        static void remove_front(Node** head, Node** tail){
            cout << "Hola no tengo trait definido" << endl;

        }
        static void print(Node** head, Node** tail,std::ostream& os){
          //  cout << "Hola no tengo trait definido" << endl;
            os<<"Hola no tengo trait definido";

        }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,FOWARD_NODE>{
    public:
        static void add(Node** head, Node** tail, ValueNode element){

            Node *new_node = new Node(element);

            if (*head== nullptr){
                *tail = *head = new_node;
            } else {
                (*tail)->next = new_node;
                *tail = (*tail)->next;
            }
        }


        static void add_front(Node** head, Node** tail, ValueNode element) {
            Node *new_node = new Node(element);

            if (*head == nullptr) {
                *tail = *head = new_node;
            } else {
                (new_node)->next = *head;
                *head = new_node;
            }
        }

        static void remove(Node** head, Node** tail){

            Node * tmpPointer = *head;
            while(tmpPointer->next!=*tail && tmpPointer->next!= nullptr ){
                tmpPointer = tmpPointer->next;
            }
            if((*head)->next== nullptr){
                delete (*head);
                (*head)=nullptr;
                (*tail)=nullptr;
                return;
            }
            *tail = tmpPointer;
            delete (*tail)->next;
            (*tail)->next = nullptr;
        }
        static void remove_front(Node** head, Node** tail){
            Node * tmpPointer = *head;
            *head = (*head)->next;
            delete tmpPointer;

        }
        static void print(Node** head, Node** tail,std::ostream& os){
            while(*head!= *tail){
                os<<**head<<"->";
                head=&((*head)->next);
            }
            os<<**head<<"->";
        }


    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,DOUBLE_NODE>{
    public:
        static void add(Node** head, Node** tail, ValueNode element){

            Node *new_node = new Node(element);
            if (*head== nullptr){
                *tail = *head = new_node;
            } else {
                (*tail)->next = new_node;
                new_node->prev= (*tail);
                *tail = (*tail)->next;
            }
        }

        static void add_front(Node** head, Node** tail, ValueNode element){

            Node *new_node = new Node(element);

            if (*head == nullptr) {
                *tail = *head = new_node;
            } else {
                (new_node)->next = *head;
                new_node->next->prev= *head = new_node;
            }

        }

        static void remove(Node** head, Node** tail){
            Node * tmpPointer = (*tail)->prev;

            if((*head)->next== nullptr){
                delete (*head);
                (*head)=nullptr;
                (*tail)=nullptr;
                return;
            }
            *tail = tmpPointer;
            delete (*tail)->next;
            (*tail)->next = nullptr;

        }


        static void remove_front(Node** head, Node** tail){
            Node * tmpPointer = *head;
            if((*head)->next== nullptr){
                delete (*head);
                (*head)=nullptr;
                (*tail)=nullptr;
                return;
            }
            *head = (*head)->next;
            delete tmpPointer;
            (*head)->prev= nullptr;
        }

        static void print(Node** head, Node** tail,std::ostream& os){
            while(*head!= *tail){
                os<<**head<<"->";
                head=&((*head)->next);
            }
            os<<**head<<"->";
        }
    };


    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,CIRCULAR_NODE> {
    public:
        static void add(Node **head, Node **tail, ValueNode element) {

            Node *new_node = new Node(element);
            if (*head == nullptr) {
                *tail = *head = new_node;
            } else {
                *tail = (*tail)->next = new_node;
            }
            (*tail)->next = (*head);
        }

        static void add_front(Node** head, Node** tail, ValueNode element){
            Node *new_node = new Node(element);
            if (*head == nullptr) {
                *tail = *head = new_node;
            } else {
                (new_node)->next = *head;
                *head = new_node;
            }
            (*tail)->next = (*head);
        }

        static void remove(Node** head, Node** tail){
            Node * tmpPointer = *head;
            while(tmpPointer->next!=*tail && tmpPointer->next!= nullptr ){
                tmpPointer = tmpPointer->next;
            }
            if((*head)->next== nullptr){
                delete (*head);
                (*head)=nullptr;
                (*tail)=nullptr;
                return;
            }
            *tail = tmpPointer;
            delete (*tail)->next;
            (*tail)->next = (*head);

        }

        static void remove_front(Node** head, Node** tail){
            Node * tmpPointer = *head;
            *head = (*head)->next;
            delete tmpPointer;
            tmpPointer= nullptr;
          //  (*tail)->next=(*head);
        }

        static void print(Node** head, Node** tail,std::ostream& os){
            while(*head!= *tail){
                os<<**head<<"->";
                head=&((*head)->next);
            }
            os<<**head<<"->";
        }

    };


    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,CIRCULAR_DOUBLE_NODE> {
    public:
        static void add(Node **head, Node **tail, ValueNode element) {

            Node *new_node = new Node(element);
            if (*head == nullptr) {
                *tail = *head = new_node;
            } else {
                (*tail)->next = new_node;
                new_node->prev= (*tail);
                *tail = (*tail)->next;
            }

            (*tail)->next = (*head);
            (*head)->prev = (*tail);
        }

        static void add_front(Node** head, Node** tail, ValueNode element){
            Node *new_node = new Node(element);

            if (*head == nullptr) {
                *tail = *head = new_node;
            } else {
                (new_node)->next = *head;
                new_node->next->prev= *head = new_node;
            }
            (*tail)->next = (*head);
            (*head)->prev = (*tail);

        }

        static void remove(Node** head, Node** tail){
            Node * tmpPointer = (*tail)->prev;

            if((*head)->next== nullptr){
                delete (*head);
                (*head)=nullptr;
                (*tail)=nullptr;
                return;
            }
            *tail = tmpPointer;
            delete (*tail)->next;
            (*tail)->next = (*head);
            (*head)->prev=(*tail);
        }

        static void remove_front(Node** head, Node** tail){
            Node * tmpPointer = *head;
            if((*head)->next== nullptr){
                delete (*head);
                (*head)=nullptr;
                (*tail)=nullptr;
                return;
            }
            *head = (*head)->next;
            delete tmpPointer;
            tmpPointer=nullptr;
            (*head)->prev= (*tail);

        }

        static void print(Node** head, Node** tail,std::ostream& os){
            while(*head!= *tail){
                os<<**head<<"->";
                head=&((*head)->next);
            }
            os<<**head<<"->";
        }

    };



    template< typename Node>  template <int nodeType>
    void ForwardList<Node>::__add__(
            typename ForwardList<Node>::node_t ** head,
            typename ForwardList<Node>::node_t ** tail,
            typename ForwardList<Node>::value_t element){

        ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::add(head,tail,element);
    };

    template< typename Node>  template <int nodeType>
    void ForwardList<Node>::__remove__(
            typename ForwardList<Node>::node_t ** head,
            typename ForwardList<Node>::node_t ** tail){
        ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::remove(head,tail);
    };


    template< typename Node>  template <int nodeType>
    void ForwardList<Node>::__remove_front__(
            typename ForwardList<Node>::node_t ** head,
            typename ForwardList<Node>::node_t ** tail){
        ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::remove_front(head,tail);
    };

    template< typename Node>  template <int nodeType>
    void ForwardList<Node>::__add_front__(
            typename ForwardList<Node>::node_t ** head,
            typename ForwardList<Node>::node_t ** tail,
            typename ForwardList<Node>::value_t element){
        ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::add_front(head,tail,element);
    };

    template< typename Node>  template <int nodeType>
    void ForwardList<Node>::__print__(
            typename ForwardList<Node>::node_t ** head,
            typename ForwardList<Node>::node_t ** tail,
            std::ostream& os
           ){
        ListHelper<ForwardList<Node>::node_t,ForwardList<Node>::value_t,nodeType>::print(head,tail,os);
    };




}

