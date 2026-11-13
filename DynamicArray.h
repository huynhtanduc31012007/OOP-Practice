#ifndef DynamicArray_h
#define DynamicArray_h
#include <iostream>
#include <string>

class DynamicArray {
private:
  int *m_data;
  int _len;
  int _capacity;

public:
  DynamicArray();
  DynamicArray(const DynamicArray &);
  ~DynamicArray();
  DynamicArray &operator=(const DynamicArray &);

  void PushBack(int value);
  int Size() const;
  int Capacity() const;
  int GetAt(int idx) const;
  bool setSize(int n);
  std::string ToString() const;

  friend std::istream &operator>>(std::istream &is, DynamicArray &arr);
  friend std::ostream &operator<<(std::ostream &os, const DynamicArray &arr);
  static DynamicArray* Parse(std::string);
};

#endif // DynamicArray_h
