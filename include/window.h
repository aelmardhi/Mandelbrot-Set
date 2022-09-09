#ifndef WINDOW_H
#define WINDOW_H

template <class T>
class Window{
    public:
    T minX, maxX, minY, maxY;
    Window(T minX, T maxX, T minY, T maxY): minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}
    T Width(){
        return maxX - minX;
    }
    T Height(){
        return maxY - minY;
    }
    T Size(){
        return Width() * Height();
    }
    void resize(T minX, T maxX, T minY, T maxY){
        this->minX = minX;
        this->maxX = maxX;
        this->minY = minY;
        this->maxY = maxY;
    }
};

#endif