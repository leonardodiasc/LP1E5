#include <iostream>

using namespace std;

template<class U>
class conjunto
{
public:
	conjunto();
	conjunto(vector<U> const&, int const&);

	vector<U> get_v();
	int get_n();

	void set(vector<U>, int);

	bool pertence(U const&);

	conjunto diferenca(conjunto<U>, conjunto<U> );

	conjunto uniao(conjunto<U>, conjunto<U> );

	conjunto intersecao(conjunto<U>, conjunto<U> );

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
vector<U> conjunto<U>::get_v()
{
	return vector<U> v;
}

template<class U>
int conjunto<U>::get_n()
{
	return n_;
}

template<class U>
void conjunto<U>::set(vector<U> v, int n)
{
	this->n_ = n;
	for(int i = 0, i < n; i++)
	{
		cin >> v[i];
		this->elementos_[i] = v[i];
	}

}

template<class U>
conjunto conjunto<U>::diferenca(conjunto<U>& a, conjunto<U>& b)
{
	vector<U> v_diff;
	int i_diff = 0;
	bool is_in_a_not_b{true};
	for(int i = 0; i < a.n_; i++)
	{
		for(int j = 0; j < b.n_; j++)
		{
			if(a.elementos_[i] == b.elementos_[j])
			{
				is_in_a_not_b = false;
			}
		}
		if(is_in_a_not_b)
		{
			v_diff[i_diff] = a.elementos_[i];
			i_diff++;
		}
	}
	int size = i_diff++;
	conjunto diff(v_diff,size);
	return diff;
}

template<class U>
conjunto conjunto<U>::uniao(conjunto<U>& a, conjunto<U>& b)
{
	vector<U> v_uni;
	int i_uni = 0;	
	bool already_exists{false};
	for(int i = 0; i < a.n_ ; i++)
	{
		v_uni[i] = a.elementos_[i];
		i_uni++;
	}
	for(int j = 0; j < b.n_; j++)
	{
		for(int k = 0; k < i_uni; k++)
		{
			if(b.elementos_[j] == v_uni[k])
			{
				already_exists = true;
			}
		}
		if(not(already_exists))
		{
			v_uni[i_uni] = b.elementos_[j];
			i_uni++;
		}
	}

template<class U>
conjunto conjunto<U>::intersecao(conjunto<U>& a, conjunto<U>& b)
{
	conjunto inter;
	for()
}



/* FALTA FAZER OS MÉTODOS*/



int main()
{
	
}
