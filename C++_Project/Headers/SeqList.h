

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include "Exception.h"
#include "List.h"

namespace LYlib {

template <typename T>
class SeqList : public List<T> {
protected:
    T*  m_array;   // 顺序存储空间
    int m_length;  // 当前线性表长度
public:
    bool insert_node(int location, const T& node) {
        bool ret = ((0 <= location) && (location <= m_length));
        ret      = ret && (m_length < capacity());
        if (ret) {
            for (int p = m_length - 1; p >= location; p--) { m_array[p + 1] = m_array[p]; }
            m_array[location] = node;
            m_length++;
        }
        return ret;
    }
    bool remove_node(int location) {
        bool ret = ((0 <= location) && (location < m_length));
        if (ret) {
            for (int p = location; p < m_length - 1; p++) { m_array[p] = m_array[p + 1]; }
            m_length++;
        }
        return ret;
    }
    bool set_value(int location, const T& node) {
        bool ret = ((0 <= location) && (location < m_length));
        if (ret) { m_array[location] = node; }
        return ret;
    }
    bool get_value(int location, T& node) const {
        bool ret = ((0 <= location) && (location < m_length));
        if (ret) { node = m_array[location]; }
        return ret;
    }
    int length_list() const {
        return m_length;
    }
    void clear_list() {
        m_length = 0;
    }
    // 顺序存储线性表的数组访问方式
    T& operator[](int location) {
        if ((0 <= location) && (location < m_length)) {
            return m_array[location];
        } else {
            throw_exception(InvalidOperationException, "Parameter i is invalid ...");
        }
    }
    T operator[](int location) const {
        return (const_cast<SeqList<T>&>(*this))[location];
    }
    // 顺序存储空间的容量
    virtual int capacity() const = 0;
};

}  // namespace LYlib

#endif
