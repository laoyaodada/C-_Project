
#ifndef __STATICLIST_H__
#define __STATICLIST_H__

#include "SeqList.h"

namespace LYlib {

template <typename T, int count>
class StaticList : public SeqList<T> {
protected:
    T m_space[count];  // 顺序存储空间，N为模版参数
public:
    StaticList() {
        this->m_array  = m_space;
        this->m_length = 0;
    }
    int capacity() const {
        return count;
    }
};
}  // namespace LYlib

#endif
