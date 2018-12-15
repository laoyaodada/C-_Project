#pragma once

#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

namespace LYlib {
template <typename T>
class SmartPointer {
protected:
    T* m_pointer;

public:
    SmartPointer(T* p = NULL) { m_pointer = p; }
    SmartPointer(const SmartPointer<T>& obj) {
        m_pointer                                   = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }
    SmartPointer<T>& operator=(const SmartPointer<T>& obj) {
        if (this != &obj) {
            delete m_pointer;
            m_pointer                                   = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
        }
        return *this;
    }

    T* operator->() { return m_pointer; }
    T& operator*() { return *m_pointer; }
    bool pointer_is_null() { return (NULL == m_pointer); }
    T* get_pointer() { return m_pointer; }
    ~SmartPointer() { delete m_pointer; }
};
}  // namespace LYlib

#endif
