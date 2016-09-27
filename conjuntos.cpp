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
	void move_to(T , T );
	void move_by(T , T );

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

template<class T>
void point<T>::move_to(T x, T y)
{
	x_ = x;
	y_ = y;
}

template<class T>
void point<T>::move_by(T x, T y)
{
	x_ = x_ + x;
	y_ = y_ + y;
}

template<class U>
class conjunto
{
public:
	conjunto();
	conjunto(vector<U> const&, int const&);

	vector<U> get();
	void set(vector<U>, int);

	bool pertence(U const&);

	void diferenca(conjunto<U>, conjunto<U> );

	void uniao(conjunto<U>, conjunto<U> );

	void intersecao(conjunto<U>, conjunto<U> );

private:
	vector<U> elementos_;
	int n_;
};

template<class U>
conjunto<U>::conjunto()
: elementos_{}, n_{}
{}

template<class U>
conjunto<U>::conjunto(vector<U> const& v, int const& n)
: elementos_{v}, n_{n}
{}

template<class U>
vector<U> conjunto<U>::get()
{
	return vector<U> v;
}

template<class U>
void conjunto<U>::set(vector<U> v, int n)
{
	for(int i = 0, i < n; i++)
	{
		cin >> v[i];
	}
	/* Placeholder
	* É só para compilar */
}




/* FALTA FAZER OS MÉTODOS*/



int main()
{
	
}