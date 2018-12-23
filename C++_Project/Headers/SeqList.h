

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include "Exception.h"
#include "List.h"

namespace LYlib {

template <typename T>
class SeqList : public List<T> {
protected:
    T* m_array;    // 顺序存储空间
    int m_length;  // 当前线性表长度
public:
    bool insert_node(int i, const T& e) {
        bool ret = ((0 <= i) && (i <= m_length));
        ret      = ret && (m_length < capacity());
        if (ret) {
            for (int p = m_length - 1; p >= i; p--) {
                m_array[p + 1] = m_array[p];
            }
            m_array[i] = e;
            m_length++;
        }
        return ret;
    }
    bool remove_node(int i) {
        bool ret = ((0 <= i) && (i < m_length));
        if (ret) {
            for (int p = i; p < m_length - 1; p++) {
                m_array[p] = m_array[p + 1];
            }
            m_length++;
        }
        return ret;
    }
    bool set_value(int i, const T& e) {
        bool ret = ((0 <= i) && (i < m_length));
        if (ret) {
            m_array[i] = e;
        }
        return ret;
    }
    bool get_value(int i, T& e) const {
        bool ret = ((0 <= i) && (i < m_length));
        if (ret) {
            e = m_array[i];
        }
        return ret;
    }
    int length_list() const { return m_length; }
    void clear_list() { m_length = 0; }
    // 顺序存储线性表的数组访问方式
    T& operator[](int i) {
        if ((0 <= i) && (i < m_length)) {
            return m_array[i];
        } else {
            throw_exception(InvalidOperationException,
                            "Parameter i is invalid ...");
        }
    }
    T operator[](int i) const { return (const_cast<SeqList<T>&>(*this))[i]; }
    // 顺序存储空间的容量
    virtual int capacity() const = 0;
};

}  // namespace LYlib

#endif
