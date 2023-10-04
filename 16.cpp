#include <iostream>
#include <vector>
using namespace std;

class Point
{
    double _x;
    double _y;
public:
    // Konstruktor mit Parametern
    Point(double x = 0.0, double y = 0.0)
        : _x(x), _y(y) {}

    // Verschiebt einen Punkt
    void move(double dx, double dy)
    {
        _x += dx;
        _y += dy;
    }

    // gibt den Punkt auf der Konsole aus
    void print(bool nl = true)
    {
        if (nl)
        {
            cout << "(" << _x << ", " << _y << ")" << endl;
        }
        else
        {
            cout << "(" << _x << ", " << _y << ")";
        }
    }
};

class Polygonline
{
    vector<Point> _points;
public:
    // Konstruktor
    Polygonline() {}

    // Konstruktor mit Parameter
    Polygonline(Point& p)
    {
        _points.push_back(p);
    }

    // gibt die Elemente des Polygons auf der Konsole aus
    void print(bool nl = true)
    {
        if (_points.empty())
        {
            cout << "||" << endl;
            return;
        }

        cout << "|";
        for (vector<Point>::iterator it = _points.begin(); it != _points.end(); ++it)
        {
            it->print(false);
            if (it != _points.end() - 1)
            {
                cout << " - ";
            }
        }
        cout << "|";
        if (nl)
        {
            cout << endl;
        }
    }

    // Hängt einen Punkt hinten an
    Polygonline& add_point(Point p)
    {
        _points.push_back(p);
        return *this;
    }

    // Hängt einen zusätzlichen Polygon hinten an
    void append_polygonline(Polygonline& pl)
    {
        _points.insert(_points.end(), pl._points.begin(), pl._points.end());
    }

    // Verschiebt den gesamten Polygon
    void move(double dx, double dy)
    {
        for (vector<Point>::iterator it = _points.begin(); it != _points.end(); ++it)
        {
            it->move(dx, dy);
        }
    }
};



int main(int argc, char *argv[]) 
{
	Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
	Polygonline l1;
	Polygonline l2(p3);
	cout << "Ausgabe 1:" << endl;
	l1.print();
	l2.print();
	l1.add_point(p1).add_point(p2);
	l2.add_point(p4).add_point(p5);
	cout << "Ausgabe 2:" << endl;
	l1.print();
	l2.print();
	p2.move(0.5, 0.5);
	cout << "Ausgabe 3:" << endl;
	p2.print();
	l1.print();
	l2.print();
	l1.append_polygonline(l2);
	cout << "Ausgabe 4:" << endl;
	l1.print();
	l2.print();
	l1.move(0, 0.5);
	cout << "Ausgabe 5:" << endl;
	l1.print();
	l2.print();
	return 0;
}
