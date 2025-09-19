#pragma region

template <typename T>
Array<T>::Array()
:arr(nullptr), sz(0){}

template <typename T>
Array<T>::Array(size_t size)
:arr(new T[size]), sz(size) {}

template <typename T>
Array<T>::Array(const Array& other)
:arr(new T[other.sz]), sz(other.sz) {
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
        this.sz = other.sz;
        arr = new T[other.sz];
        for(size_t i = 0; i < other.sz; i++){
            arr[i] = other.arr[i];
        }
    }
    return (*this);
}

