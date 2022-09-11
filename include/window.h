#ifndef WINDOW_H
#define WINDOW_H

template <class T> class Window {
public:
  T minX, maxX, minY, maxY;
  Window(T minX, T maxX, T minY, T maxY)
      : minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}
  T Width() { return maxX - minX; }
  T Height() { return maxY - minY; }
  T Size() { return Width() * Height(); }
  void resize(T minX, T maxX, T minY, T maxY) {
    this->minX = minX;
    this->maxX = maxX;
    this->minY = minY;
    this->maxY = maxY;
  }
  void  resizeLimited (double dx, double dy, double r){
    T x = minX + dx * Width();
    T y = minY + dy * Height();
    T w = Width() *r;
    T h = Height() *r;
    T t = x -  w/2;
    minX = (t < minX)? minX : t ;
    t = x +  w/2;
    maxX = (t > maxX)? maxX : t ;
    t = y -  h/2;
    minY = (t < minY)? minY : t ;
    t = y + h/2;
    maxY = (t > maxY)? maxY : t ;
  }
  void  resize (double dx, double dy, double r){
    T x = minX + dx * Width();
    T y = minY + dy * Height();
    T w = Width() *r;
    T h = Height() *r;
    minX = x -  w/2;
    maxX = x +  w/2;
    minY = y -  h/2;
    maxY = y + h/2;
  }
};

#endif