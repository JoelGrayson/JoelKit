const int kGrowAmount=10;

template <typename T>
JStack<T>::JStack(size_t allocatedSize) {
    logicalSize_=0;
    this->allocatedSize_=allocatedSize;
    elems_=new T[allocatedSize_];
}

template <typename T>
void JStack<T>::push(T newElem) {
    elems_[logicalSize_]=newElem;
    logicalSize_++;
}

template <typename T>
T JStack<T>::peek() const {
    if (logicalSize_==0) {
        throw std::out_of_range("Stack is empty");
    }
    return elems_[logicalSize_-1];
}

template <typename T>
T JStack<T>::pop() {
    if (logicalSize_==0) {
        throw std::out_of_range("Stack is empty");
    }
    auto out=peek();
    logicalSize_--;
    return out;
}

template <typename T>
bool JStack<T>::isEmpty() const {
    return logicalSize_==0;
}

template <typename T>
size_t JStack<T>::size() const {
    return allocatedSize_;
}

template <typename T>
void JStack<T>::grow() {
    // allocatedSize_+=kGrowAmount;
    allocatedSize_*=2;
    int* helper=new int[allocatedSize_];
    // Move
    for (int i=0; i<logicalSize_; i++) {
        helper[i]=elems_[i];
    }
    delete[] elems_;
    elems_=helper;
}

template <typename T>
std::string JStack<T>::toString() const {
    std::string out="";
    for (int i=0; i<logicalSize_; i++) {
        out+=std::to_string(elems_[i]);
        if (i!=logicalSize_-1) {
            out+=", ";
        }
    }
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const JStack<T>& js) {
    os << js.toString();
    return os;
}
