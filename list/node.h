#include<iostream>
using namespace std;

namespace cs2100 {

     template <typename T>
     class Node {
     public:
         typedef T value_t;
         typedef unsigned int size_t;

     public:
         value_t value;

     public:
         Node(const value_t& _value):value(_value){
         }

         size_t size(){
             return 0;
         }

         ~Node(void){
         }

         value_t& operator*(void){
             return value;
         }

         template <typename _T>
         inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
             _out << "Nodo: " <<  _node.value;
             return _out;
         }
     };

     template <typename T>
     class ForwardListNode : public Node<T> {
     public:
         typedef typename Node<T>::value_t value_t;

     public:
         ForwardListNode<T>* next;

     public:
         ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
         }

         ~ForwardListNode(void){
         }

         template <typename _T>
         inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
             _out << "Nodo: [ v: " <<  _node.value << " , Next address: " << _node.next<< " ]";
             return _out;
         }
     };





     template <typename T>
     class DoubleListNode : public Node<T> {
     public:
         typedef typename Node<T>::value_t value_t;

     public:
         DoubleListNode<T>* next;
         DoubleListNode<T>* prev;

     public:
         DoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
         }

         ~DoubleListNode(void){
         }

         template <typename _T>
         inline friend ostream& operator<< (ostream& _out, const DoubleListNode<_T>& _node){
             _out << "Nodo: [ v: " <<  _node.value << " , p_prev: " << _node.prev << ", p_next: " << _node.next << " ]";
             return _out;
         }
     };


    template <typename T>
    class CircularListNode : public Node<T>{


    public:
        typedef typename Node<T>::value_t value_t;

    public:
        CircularListNode<T>* next;

    public:
        CircularListNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~CircularListNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const CircularListNode<_T>& _node){
            _out << "Nodo: [ v: " <<  _node.value << " ,  Next address: " << _node.next<< " ]";
            return _out;
        }


    };



    template <typename T>
    class CircularDoubleListNode : public Node<T> {
    public:
        typedef typename Node<T>::value_t value_t;

    public:
        CircularDoubleListNode<T>* next;
        CircularDoubleListNode<T>* prev;

    public:
        CircularDoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~CircularDoubleListNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const CircularDoubleListNode<_T>& _node){
            _out << " Nodo:[ v: " <<  _node.value << ", p_prev: " << _node.prev << ", p_next: " << _node.next << " ] ";
            return _out;
        }
    };




}



