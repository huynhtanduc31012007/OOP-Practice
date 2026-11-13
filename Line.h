#ifndef Line_h
#define Line_h
#include "Tokenizer.h"
#include "Point.h"
#include <iostream>
#include <string>

class Line {
public:
  static int InstanceCount;

private:
  Point *_start;
  Point *_end;

public:
  Line();
  Line(Point *, Point *);
  Line(const Line &);
  ~Line();
  Line &operator=(const Line &);

  void setStart(Point *);
  void setEnd(Point *);
  Point getStart() const { return *_start; }
  Point getEnd() const { return *_end; }
  double Length() const;
  std::string ToString() const;

  static Line* Parse(std::string);

  friend std::istream &operator >>(std::istream &is, Line &L);
  friend std::ostream &operator <<(std::ostream &os, const Line &L);
};

#endif
