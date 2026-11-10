#include "DynamicArray.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

DynamicArray::DynamicArray() {
  _capacity = 1;
  _len = 0;
  m_data = new int[_capacity];
}

DynamicArray::~DynamicArray() {
  if (m_data != nullptr)
    delete[] m_data;
  m_data = nullptr;
  _len = 0;
  _capacity = 0;
}

DynamicArray::DynamicArray(const DynamicArray &other) {
  this->_capacity = (other._capacity > 0) ? other._capacity : 1;
  this->_len = other._len;
  this->m_data = new int[this->_capacity];
  for (int i = 0; i < other._len; i++)
    this->m_data[i] = other.m_data[i];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
  if (this != &other) {
    if (m_data != nullptr)
      delete[] m_data;
    _capacity = (other._capacity > 0) ? other._capacity : 1;
    _len = other._len;
    m_data = new int[_capacity];
    for (int i = 0; i < _len; i++)
      m_data[i] = other.m_data[i];
  }
  return *this;
}

void DynamicArray::PushBack(int value) {
  if (_len == _capacity) {
    _capacity = _capacity * 2;
    int *newarr = new int[_capacity];
    std::copy(m_data, m_data + _len, newarr);
    delete[] m_data;
    m_data = newarr;
  }
  m_data[_len++] = value;
}

int DynamicArray::Size() const { return _len; }

int DynamicArray::Capacity() const { return _capacity; }

int DynamicArray::GetAt(int idx) const {
  if (idx < 0 || idx >= _len)
    throw std::out_of_range("Index out of range");
  return m_data[idx];
}

std::string DynamicArray::ToString() const {
  if (_len == 0)
    return "Mang rong (Dung luong: " + std::to_string(_capacity) + ", So luong: 0)";
  std::string str = "Dung luong (Capacity): " + std::to_string(_capacity) + "\n" +
                    "So luong phan tu (Size): " + std::to_string(_len) + "\n" +
                    "Cac phan tu: ";
  for (int i = 0; i < _len; i++)
    str += std::to_string(m_data[i]) + (i == _len - 1 ? "" : " ");
  return str;
}

bool DynamicArray::setSize(int n) {
  if (n < 0)
    return false;
  if (m_data != nullptr) {
    delete[] m_data;
    m_data = nullptr;
  }
  _len = n;
  _capacity = (_len > 0) ? _len : 1;
  m_data = new int[_capacity]();
  return true;
}

std::istream &operator>>(std::istream &is, DynamicArray &arr) {
  int num = 0;
  while (true) {
    std::cout << "Nhap so luong phan tu: ";
    if (is >> num && num >= 0) {
      arr.setSize(num);
      break;
    }
    if (is.eof())
      return is;
    std::cout << "Nhap sai, vui long nhap lai so nguyen >= 0!" << std::endl;
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  for (int i = 0; i < arr._len; i++) {
    while (true) {
      std::cout << "Arr[" << i << "] = ";
      if (is >> arr.m_data[i]) {
        break;
      }
      if (is.eof())
        return is;
      std::cout << "Nhap sai, vui long nhap lai!" << std::endl;
      is.clear();
      is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const DynamicArray &arr) {
  os << arr.ToString();
  return os;
}
