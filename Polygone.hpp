    #ifndef POLYGONE_H
    #define POLYGONE_H

    #include <vector>
    #include "Point2D.hpp"

    using namespace std;

    template <typename T>
    class Polygone {

    private:
        vector<Point2D<T>> sommets; 

    public:
    
        Polygone();                                  
        Polygone(const vector<Point2D<T>>& listeSommets); 
        Polygone(const Polygone<T>& poly);           

    
        vector<Point2D<T>> getSommets() const;

    
        void setSommets(const vector<Point2D<T>>& listeSommets);

    
        void addPoint(const Point2D<T>& point);

        
        void translate(T x, T y);

        
        template <typename U>
        friend ostream& operator<<(ostream& os, const Polygone<U>& poly);
    };

    template <typename T>
    Polygone<T>::Polygone() : sommets() {}

    template <typename T>
    Polygone<T>::Polygone(const vector<Point2D<T>>& listeSommets) : sommets(listeSommets) {}


    template <typename T>
    Polygone<T>::Polygone(const Polygone<T>& poly) : sommets(poly.sommets) {}

    template <typename T>
    vector<Point2D<T>> Polygone<T>::getSommets() const {
        return sommets;
    }


    template <typename T>
    void Polygone<T>::setSommets(const vector<Point2D<T>>& listeSommets) {
        sommets = listeSommets;
    }


    template <typename T>
    void Polygone<T>::addPoint(const Point2D<T>& point) {
        sommets.push_back(point);
    }

    template <typename T>
    void Polygone<T>::translate(T x, T y) {
        for (auto& sommet : sommets) {
            sommet.translate(x, y);
        }
    }

    template <typename T>
    ostream& operator<<(ostream& os, const Polygone<T>& poly) {
        os << "Polygone: ";
        for (const auto& sommet : poly.sommets) {
            os << sommet << " ";
        }
        return os;
    }

    #endif 
