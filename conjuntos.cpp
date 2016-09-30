#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class conjunto{
public:
	conjunto(int);
	conjunto(conjunto<T> const&);
	~conjunto();

	void read();
	void read(int);
	void print();
	bool belongsTo(T) const;
	conjunto<T> difference(conjunto<T> const&);
	conjunto<T> set_union(conjunto<T> const&);
	conjunto<T> intersection(conjunto<T> const&);

	int current_size() const { return ncurrent_;}
	int max_size() const {return max_;}

private:
	void insert(T);
	T get_element(int i) const {return elementos_[i];}
	int max_;
	int ncurrent_;
	T* elementos_;
};

template<class T>
conjunto<T>::conjunto(int max)
{
	max_ = max;
	ncurrent_ = 0;

	elementos_ = new (nothrow) T[max_];
}

template<class T>
conjunto<T>::conjunto(conjunto<T> const& that)
{
	max_ = that.max_size();
	ncurrent_ = that.current_size();

	elementos_ = new (nothrow) T[max_];

	for(int i = 0; i < ncurrent_; i++)
	{
		elementos_[i] = that.get_element(i);
	}
}

template<class T>
conjunto<T>::~conjunto()
{
	delete [] elementos_;
	elementos_ = nullptr;
}

template<class T>
void conjunto<T>::insert(T elemento)
{
	if(not(current_size() == max_size()))
	{
		if(not(belongsTo(elemento)))
		{
		  elementos_[ncurrent_] = elemento;
		  ncurrent_++;
		}
		
	}
	else
	{
		cout << "O set está cheio!" << endl;
	}
	
}

template<class T>
void conjunto<T>::read()
{
	read(max_);
}

template<class T>
void conjunto<T>::read(int n)
{
	T elemento;
	for(int i = 0; i < n; i++)
	{
		cout << "Elemento " << i + 1 << ": ";
		cin >> elemento;
		insert(elemento);
	}
}

template<class T>
void conjunto<T>::print()
{
	for(int i = 0; i < ncurrent_; i++)
	{
		cout << " " << get_element(i);
	}
	cout << endl;
}

template<class T>
bool conjunto<T>::belongsTo(T e) const
{ 
	for(int i = 0; i < ncurrent_; i++)
	{
		if(elementos_[i] == e)
		{
			return true;
		}
	}
	return false;
}

template<class T>
conjunto<T> conjunto<T>::difference(conjunto<T> const& b)
{
	conjunto<T> c(ncurrent_);

	for(int i = 0; i < ncurrent_; i++)
	{
		if(not(b.belongsTo(get_element(i))))
		{
			c.insert(get_element(i));
		}
	}

	return c;
}

template<class T>
conjunto<T> conjunto<T>::set_union(conjunto<T> const& b)
{
	conjunto<T> c (ncurrent_ + b.current_size());

	for(int i = 0; i < ncurrent_; i++)
	{
		c.insert(elementos_[i]);
	}
	for (int i = 0; i < b.current_size(); ++i)
	{
		c.insert(b.get_element(i));
	}
	return c;
}

template<class T>
conjunto<T> conjunto<T>::intersection(conjunto<T> const& b)
{
	conjunto<T> c (ncurrent_);

	for(int i = 0; i < ncurrent_; i++)
	{
		if(belongsTo(b.get_element(i)))
		{
			c.insert(b.get_element(i));
		}
	}
	return c;
}

int main()
{
	int na, nb;
	cout << "Digite o número máximo de elementos do conjunto A: ";
	cin >> na;
	conjunto<int> a(na);
	a.read();
	a.print();
	cout << "Digite o número máximo de elementos do conjunto B: ";
	cin >> nb;
	conjunto<int> b(nb);
	b.read();
	b.print();

	a.intersection(b).print();

}
