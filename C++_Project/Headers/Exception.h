#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <cstddef>
#include "Object.h"

namespace LYlib {
#define throw_exception(exception, message) \
    (throw exception(message, __FILE__, __LINE__))
class Exception : public Object {
protected:
    char *m_message;
    char *m_location;
    void init(const char *message, const char *file, int line);

public:
    Exception(const char *message);
    Exception(const char *file, int line);
    Exception(const char *message, const char *file, int line);
    Exception(const Exception &e);
    Exception &operator=(const Exception &e);
    virtual const char *get_message() const;
    virtual const char *get_location() const;
    virtual ~Exception() = 0;
};

class ArithmeticException : public Exception {
public:
    ArithmeticException() : Exception(NULL) {}
    ArithmeticException(const char *message) : Exception(message) {}
    ArithmeticException(const char *file, int line) : Exception(file, line) {}
    ArithmeticException(const char *message, const char *file, int line)
        : Exception(message, file, line) {}
    ArithmeticException(const ArithmeticException &e) : Exception(e) {}
    ArithmeticException &operator=(const ArithmeticException &e) {
        Exception::operator=(e);
        return *this;
    }
};

class NoEnoughMemoryException : public Exception {
public:
    NoEnoughMemoryException() : Exception(NULL) {}
    NoEnoughMemoryException(const char *message) : Exception(message) {}
    NoEnoughMemoryException(const char *file, int line)
        : Exception(file, line) {}
    NoEnoughMemoryException(const char *message, const char *file, int line)
        : Exception(message, file, line) {}
    NoEnoughMemoryException(const NoEnoughMemoryException &e) : Exception(e) {}
    NoEnoughMemoryException &operator=(const NoEnoughMemoryException &e) {
        Exception::operator=(e);
        return *this;
    }
};

class InvalidParameterException : public Exception {
public:
    InvalidParameterException() : Exception(NULL) {}
    InvalidParameterException(const char *message) : Exception(message) {}
    InvalidParameterException(const char *file, int line)
        : Exception(file, line) {}
    InvalidParameterException(const char *message, const char *file, int line)
        : Exception(message, file, line) {}
    InvalidParameterException(const InvalidParameterException &e)
        : Exception(e) {}
    InvalidParameterException &operator=(const InvalidParameterException &e) {
        Exception::operator=(e);
        return *this;
    }
};

class InvalidOperationException : public Exception {
public:
    InvalidOperationException() : Exception(NULL) {}
    InvalidOperationException(const char *message) : Exception(message) {}
    InvalidOperationException(const char *file, int line)
        : Exception(file, line) {}
    InvalidOperationException(const char *message, const char *file, int line)
        : Exception(message, file, line) {}
    InvalidOperationException(const InvalidOperationException &e)
        : Exception(e) {}
    InvalidOperationException &operator=(const InvalidOperationException &e) {
        Exception::operator=(e);
        return *this;
    }
};

}  // namespace LYlib

#endif
