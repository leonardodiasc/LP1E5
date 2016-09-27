#include <iostream>

using namespace std;

template<class T>
class point
{
public:
	point(T const& x, T const& y)
	: x_{x}, y_{y}
	{}

	point()
	: x_{}, y_{}
	{}

	T const& x()
	const
	{
		return x_;
	}

	T const& y()
	const
	{
		return y_;
	}

private:
	T x_;
	T y_;
};

int main()
{

}