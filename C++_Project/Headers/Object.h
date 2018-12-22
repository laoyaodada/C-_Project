#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <cstddef>

namespace LYlib {

class Object {
public:
    void *operator new(size_t size) throw();
    void operator delete(void *p);
    void *operator new[](size_t size) throw();
    void operator delete[](void *p);
    virtual ~Object() = 0;
};

}  // namespace LYlib

#endif
