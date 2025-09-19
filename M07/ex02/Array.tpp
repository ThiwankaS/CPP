#pragma region

template <typename T>
Array<T>::Array()
:sz(0), arr(nullptr){}

template <typename T>
Array<T>::Array(size_t size)
:sz(size), arr(new T[size]) {}

template <typename T>
Array<T>::Array(const Array& other)
:sz(other.sz), arr(new T[other.sz]) {
    for(size_t i = 0; i < other.sz; i++){
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>::~Array(){
    delete [] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if(this != &other){
        delete [] arr;
        this->sz = other.sz;
        arr = new T[other.sz];
        for(size_t i = 0; i < other.sz; i++){
            arr[i] = other.arr[i];
        }
    }
    return (*this);
}

template <typename T>
size_t Array<T>::size(void) const {
    return (sz);
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if(index >= sz)
        throw OutOfBoundsException();
    return (arr[index]);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if(index >= sz)
        throw OutOfBoundsException();
    return (arr[index]);
}
