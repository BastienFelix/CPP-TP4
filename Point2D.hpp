#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
using namespace std;

template <typename T>
class Point2D {
private:
    T x;
    T y;

public:
    // Constructeurs
    Point2D(T x, T y);
    Point2D();
    Point2D(const Point2D<T>& p);

    // Constructeur par conversion
    template <typename U>
    Point2D(const Point2D<U>& p);

    // Accesseurs
    T getX() const;
    T getY() const;

    // Mutateurs
    void setX(T x);
    void setY(T y);

    // Méthode de translation
    void translate(T dx, T dy);

    // Opérateur << en tant qu'ami
    template <typename U>
    friend ostream& operator<<(ostream& os, const Point2D<U>& point);
};

// Constructeurs
template <typename T>
Point2D<T>::Point2D(T x, T y) : x(x), y(y) {}

template <typename T>
Point2D<T>::Point2D() : x(0), y(0) {}

template <typename T>
Point2D<T>::Point2D(const Point2D<T>& p) : x(p.x), y(p.y) {}

// Constructeur par conversion
template <typename T>
template <typename U>
Point2D<T>::Point2D(const Point2D<U>& p) : x(static_cast<T>(p.getX())), y(static_cast<T>(p.getY())) {}

// Accesseurs
template <typename T>
T Point2D<T>::getX() const {
    return x;
}

template <typename T>
T Point2D<T>::getY() const {
    return y;
}

// Mutateurs
template <typename T>
void Point2D<T>::setX(T x) {
    this->x = x;
}

template <typename T>
void Point2D<T>::setY(T y) {
    this->y = y;
}

// Méthode de translation
template <typename T>
void Point2D<T>::translate(T dx, T dy) {
    x += dx;
    y += dy;
}

// Opérateur << (fonction externe)
template <typename T>
ostream& operator<<(ostream& os, const Point2D<T>& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

#endif
