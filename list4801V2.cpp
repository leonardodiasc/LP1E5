#include <iostream>

using namespace std;

template<class T>
class point
{
public:
	point(T const&, T const&);
	point();
	T const& x() const;
	T const& y() const;
private:
	T x_;
	T y_;
};

template<class T>
point<T>::point(T const& x, T const& y)
: x_{x}, y_{y}
{}

template<class T>
point<T>::point()
: x_{}, y_{}
{}

template<class T>
T const& point<T>::y()
const
{
	return y_;
}

int main()
{
	
}