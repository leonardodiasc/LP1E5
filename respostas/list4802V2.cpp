#include <iostream>

using namespace std;

template<class T>
class rational
{
public:
	typedef T value_type;
	rational() : rational{0} {}
	rational(T num) : numerator_{num}, denominator_{1}{}
	rational(T num, T den);

	void assign(T num, T den);

	template<class U>
	U convert()
	const
	{
		return static_cast<U>(numerator()) / static_cast<U>(denominator()) ; 
	}
	T numerator() const { return numerator_;}
	T denominator() const {return denominator_;}

private:
	int mdc();
	void reduce();
	T numerator_;
	T denominator_;
	
};

template<class T>
void rational<T>::assign(T num, T den)
{
	numerator_ = num;
	denominator_ = den;
	rational<T>::reduce();
}

template<class T>
void rational<T>::reduce(){
	numerator_ = numerator_/(mdc(numerator_,denominator_));
	denominator_ = denominator_/(mdc(numerator_,denominator_));
}

template<class T>
int rational<T>::mdc(int a, int b){
	if(b == 0)  
  		return a;  
 	else  
  		return mdc(b,a%b);
}

template<class T>
bool operator==(rational<T> const& a, rational<T> const& b)
{
	return a.numerator() == b.numerator() and
	a.denominator() == b.denominator();
}

template<class T>
inline bool operator!=(rational<T> const& a, rational<T> const& b)
{
	return not (a==b);
}


int main()
{
	rational<short> zero{};
	rational<int> pi1{355,113}, x{1,2}, y{2,4};
	rational<long> pi2 {80143857L, 25510582L};

	if(x==y)
	{
		cout << "1/2 == 2/4" << endl;
	}
	else
	{
		cout << "1/2 != 2/4" << endl;
	}
}