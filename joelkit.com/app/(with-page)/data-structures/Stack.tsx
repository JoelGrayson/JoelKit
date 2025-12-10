import Yt from "@/components/Yt";
import videos from "../../videos";
import Toggle from "../Toggle";
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism';

export default function Stack() {
    return <>
        <Toggle title="Stack">
            <Yt>{videos.stack}</Yt>

            <p>Stack supports push, pop, and peek. It&apos;s a last in first out (LIFO) data structure.</p>

            <h4>C++</h4>
            <h5>Header File</h5>
            <SyntaxHighlighter language="cpp" style={oneDark}>
                {stackCppH}
            </SyntaxHighlighter>
            <h5>Implementation File</h5>
            <SyntaxHighlighter language="cpp" style={oneDark}>
                {stackCpp}
            </SyntaxHighlighter>
        </Toggle>
    </>;
}

const stackCppH = `#include <cstddef>
#include <iostream>

template <typename T>
class Stack {
private:
    T* elems_;
    size_t size_ = 0;
    size_t capacity_ = 100;

    /**
     * when capacity is exceeded, double capacity
     */
    void grow();

public:
    Stack();
    Stack(size_t capacity);
    ~Stack();

    void push(T el);
    T pop();
    T peek() const;
    
    size_t size() const;
    bool is_empty() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U>& s);
};`;

const stackCpp = `template <typename T>
Stack<T>::Stack() {
    elems_ = new T[capacity_];
}

template <typename T>
Stack<T>::Stack(size_t capacity) {
    capacity_ = capacity;
    elems_ = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elems_;
}

template <typename T>
void Stack<T>::push(T elem) {
    if (capacity_ == size_) {
        grow();
    }
    elems_[size_] = elem;
    size_++;
}

template <typename T>
T Stack<T>::pop() {
    T elem = elems_[size_ - 1];
    size_--;
    return elem;
}

template <typename T>
T Stack<T>::peek() const {
    return elems_[size_ - 1];
}

template <typename T>
size_t Stack<T>::size() const {
    return size_;
}

template <typename T>
bool Stack<T>::is_empty() const {
    return size_ == 0;
}

template <typename T>
void Stack<T>::grow() {
    size_t new_capacity_ = capacity_ * 2;
    T* new_elems_ = new T[new_capacity_];

    // Insert the old elements
    for (int i = 0; i < capacity_; i++) {
        new_elems_[i] = elems_[i];
    }
    
    delete[] elems_;
    elems_ = new_elems_;
    capacity_ = new_capacity_;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
    for (int i = 0; i < s.size_; i++) {
        std::cout << s.elems_[i] << " ";
    }
    return os;
}`;

