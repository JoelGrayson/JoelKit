#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class JStack {
public:
    JStack(size_t allocatedSize);
    void push(T newElem);
    T peek() const;
    T pop();
    bool isEmpty() const;

    size_t size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const JStack<U>&);
    std::string toString() const;
    
private:
    T* elems_;
    size_t allocatedSize_;
    size_t logicalSize_;
    void grow();
};

#include "JStack.tpp"
