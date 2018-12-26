

#ifndef __LIST_H__
#define __LIST_H__

#include "Object.h"

namespace LYlib {

template <typename T>
class List : public Object {
public:
    virtual bool insert_node(int location, const T& node) = 0;
    virtual bool remove_node(int location)                = 0;
    virtual bool set_value(int location, const T& node)   = 0;
    virtual bool get_value(int location, T& node) const   = 0;
    virtual int  length_list() const                      = 0;
    virtual void clear_list()                             = 0;
};

}  // namespace LYlib

#endif
