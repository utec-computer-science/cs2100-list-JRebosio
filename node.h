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
}
