

#ifndef __LIST_H__
#define __LIST_H__

#include "Object.h"

namespace LYlib {
template <typename T>
class List : public Object {
public:
    virtual bool insert_node(int i, const T& e) = 0;
    virtual bool remove_node(int i)             = 0;
    virtual bool set_value(int i, const T& e)   = 0;
    virtual bool get_value(int i, T& e) const   = 0;
    virtual int  length_list() const            = 0;
    virtual void clear_list()                   = 0;
};

}  // namespace LYlib

#endif
