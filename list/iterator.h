
#include "node.h"


namespace cs2100 {

    template <typename Node>
    class Iterator{
    public:
        typedef Node node_t;
        typedef typename node_t::value_t value_t;

    protected:
        node_t * pointer;
    public:

        Iterator(node_t* _pointer = nullptr):pointer(_pointer){
        }

        ~Iterator(void){
        }

        virtual bool operator!= (Iterator it){
            return pointer != it.pointer;
        }

        virtual value_t& operator* (void) {
            return **pointer;
        }
    };
}

