#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <cstddef>

namespace LYlib {

class Object {
public:
    void *operator new(size_t heap_size) throw();
    void  operator delete(void *heap_space);
    void *operator new[](size_t heap_size) throw();
    void  operator delete[](void *heap_space);
    virtual ~Object() = 0;
};

}  // namespace LYlib

#endif
