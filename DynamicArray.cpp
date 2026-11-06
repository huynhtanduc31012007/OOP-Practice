#include "DynamicArray.h"
#include <stdexcept>
#include <algorithm>

DynamicArray::DynamicArray(){
    _capacity = 1;
    _len = 0;
    m_data = new int[_capacity];
}

DynamicArray::~DynamicArray(){
    for (int i = 0; i < _len; i++)
        m_data[i] = 0;
    _len = 0;
    _capacity = 0;
    if (m_data != nullptr)
        delete [] m_data;
    m_data = nullptr;
}

DynamicArray::DynamicArray(const DynamicArray &other){
    this->_capacity = (other._capacity > 0) ? other._capacity : 1;
    this->_len = other._len;
    this->m_data = new int[this->_capacity];
    for (int i = 0; i < other._len; i++)
        this->m_data[i] = other.m_data[i];
}

void DynamicArray::PushBack(int value){
    if (_len == _capacity){
        _capacity = _capacity * 2;
        int *newarr = new int[_capacity];
        std::copy(m_data, m_data + _len, newarr);
        delete[] m_data;
        m_data = newarr;
    }
    m_data[_len++] = value;
}

int DynamicArray::Size(){
    return _len;
}

int DynamicArray::GetAt(int idx){
    if (idx < 0 || idx >= _len)
        throw std::out_of_range("Index out of range");
    return m_data[idx];
}

std::string DynamicArray::ToString(){
    if (_len = 0)
        return "NULL";
    std::string str = "";
    str = "Size : " + std::to_string(_len) + "\n";
    for (int i = 0; i < _len; i++)
        str += std::to_string(a[i]) + " ";
    return str;
}

std::istream& operator >> (std::istream &is, DynamicArray &arr){
    int num = 0;
    while (true){
        std::cout << "Nhap kich thuoc mang: ";
        if (is >> num && num >= 0){
            arr.setSize(num);
            break;
        }
    }

    for (int i = 0; i < arr._len; i++){
        while (true){
            std::cout << "Arr[" << i << "] = ";
        }
        
    }
    
}
std::ostream& operator << (std::ostream &os, const DynamicArray &arr);

