#ifndef WINDOW_H
#define WINDOW_H

template <class T>
class Window{
    public:
    T minX_, maxX_, minY_, maxY_;
    Window(T minX, T maxX, T minY, T maxY): minX_(minX), maxX_(maxX), minY_(minY), maxY_(maxY) {}
    T Width(){
        return maxX_ - minX_;
    }
    T Height(){
        return maxY_ - minY_;
    }
    T Size(){
        return Width() * Height();
    }
    void resize(T minX, T maxX, T minY, T maxY){
        minX_ = minX;
        maxX_ = maxX;
        minY_ = minY;
        maxY_ = maxY;
    }
};

#endif