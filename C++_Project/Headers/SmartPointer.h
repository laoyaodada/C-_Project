
#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

#include "Object.h"

namespace LYlib {

template <typename T>
class SmartPointer : public Object {
protected:
    T* m_pointer;

public:
    SmartPointer(T* object = NULL) {
        m_pointer = object;
    }
    SmartPointer(const SmartPointer<T>& object) {
        m_pointer                                      = object.m_pointer;
        const_cast<SmartPointer<T>&>(object).m_pointer = NULL;
    }
    SmartPointer<T>& operator=(const SmartPointer<T>& object) {
        if (this != &object) {
            delete m_pointer;
            m_pointer                                      = object.m_pointer;
            const_cast<SmartPointer<T>&>(object).m_pointer = NULL;
        }
        return *this;
    }

    T* operator->() {
        return m_pointer;
    }
    T& operator*() {
        return *m_pointer;
    }
    bool is_null() {
        return (NULL == m_pointer);
    }
    T* get_pointer() {
        return m_pointer;
    }
    ~SmartPointer() {
        delete m_pointer;
    }
};

}  // namespace LYlib

#endif
