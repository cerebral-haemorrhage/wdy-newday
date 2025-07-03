#include <iostream>
using namespace std;

//模拟Vector类

template<typename T>
class Vector
{
public:
    Vector();
    explicit Vector(size_t initial_size);
    ~Vector();

    size_t size() const;
    size_t cap() const;
    bool empty() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t);
    T* begin();
    T* end();
    void reserve(size_t new_cap);
    void push_back(const T& v);
private:
    T* m_data;
    size_t m_size;
    size_t m_cap;
};

template<typename T>
Vector<T>::Vector():m_data(nullptr),m_size(0),m_cap(0){

}

template<typename T>
Vector<T>::Vector(size_t initial_size):m_data(new T[initial_size]),m_size(initial_size),m_cap(initial_size){

}

template<typename T>
Vector<T>::~Vector(){
    delete[] m_data;
}

template<typename T>
size_t Vector<T>::size() const{
    return m_size;
}

template<typename T>
size_t Vector<T>::cap() const{
    return m_cap;
}

template<typename T>
bool Vector<T>::empty() const{
    return m_size==0;
}

template<typename T>
T& Vector<T>::operator[](size_t index){
    return m_data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const{
    return m_data[index];
}

template<typename T>
T& Vector<T>::at(size_t index){
    if(index >= m_size)throw out_of_range("wdf");
    return m_data[index];
}

template<typename T>
T* Vector<T>::begin(){
    return m_data;
}

template<typename T>
T* Vector<T>::end(){
    return m_data+m_size;
}

template<typename T>
void Vector<T>::reserve(size_t new_cap){
    
}

template<typename T>
void Vector<T>::push_back(const T& v){
    
}


int main(){
    return 0;
}