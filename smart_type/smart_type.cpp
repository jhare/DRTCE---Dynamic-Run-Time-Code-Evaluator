

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>

template <typename T>
class _T
{

public:
	const char *Name;
	std::set <const char *> Depends;
	
	T t;

//constructors

	_T () : Name ("intermediate compiler variable")
	{
	}

	_T (const char *_name) : Name (_name)
	{
	}

	_T (T _t, const char *_name) : Name (_name)
	{
		t = _t;
	}

	void _ (const char *_varname)
	{
		Depends.insert (_varname);
	}

	void print_depends ()
	{
		std::cout << Name << " at address 0x" << std::hex << (int) this << " depends on: ";

		for (std::set <const char *>::iterator pos = Depends.begin (); pos != Depends.end (); ++pos)
		{
			std::cout << *pos << "; ";
		}

		std::cout << std::endl;
	}

//destructor

	~_T ()
	{
		print_depends ();
	}


//conversion operators
		
	virtual operator T (void)
	{
		return t;
	}

//assignment operators
	virtual T operator = (T _t)
	{
		t = _t;
	}


	virtual T operator = (_T <T> _t)
	{
		_ (_t.Name);
		t = _t.t;
	}

	virtual T operator += (T _t)
	{
		t += _t;
	}


	virtual T operator += (_T <T> _t)
	{
		Depends.insert (_t.Depends.begin (), _t.Depends.end ());
		_ (_t.Name);
		t += _t.t;
	}

	virtual T operator -= (T _t)
	{
		t -= _t;
	}


	virtual T operator -= (_T <T> _t)
	{
		_ (_t.Name);
		t -= _t.t;
	}

	virtual T operator *= (T _t)
	{
		t *= _t;
	}


	virtual T operator *= (_T <T> _t)
	{
		_ (_t.Name);
		t *= _t.t;
	}

	virtual T operator /= (int _t)
	{
		t /= _t;
	}


	virtual T operator /= (_T <T> _t)
	{
		_ (_t.Name);
		t /= _t.t;
	}

	virtual T operator &= (int _t)
	{
		t = (int) t & _t;
	}


	virtual T operator &= (_T <int> _t)
	{
		_ (_t.Name);
		t = (int) t & _t.t;
	}

	virtual T operator |= (int _t)
	{
		t = (int ) t | _t;
	}


	virtual T operator |= (_T <int> _t)
	{
		_ (_t.Name);
		t = (int) t | _t.t;
	}

	virtual T operator ^= (int _t)
	{
		t = (int) t ^ _t;
	}


	virtual T operator ^= (_T <int> _t)
	{
		_ (_t.Name);
		t = (int) t ^ _t.t;
	}

	virtual T operator <<= (int _t)
	{
		t = (int) t << _t;
	}


	virtual T operator <<= (_T <int> _t)
	{
		_ (_t.Name);
		t = (int) t << _t.t;
	}

	virtual T operator >>= (int _t)
	{
		t = (int) t >> _t;
	}


	virtual T operator >>= (_T <int> _t)
	{
		_ (_t.Name);
		t = (int) t >> _t.t;
	}

	virtual T operator %= (int _t)
	{
		t = (int) t >> _t;
	}


	virtual T operator %= (_T <int> _t)
	{
		_ (_t.Name);
		t = (int) t % _t.t;
	}


//memory allocation operators

	void *operator new (size_t _n)
	{
		return new T [_n];
	}

	void operator delete (void *_p)
	{
		delete (T *) _p;
	}

	void operator delete [] (void *_p)
	{
		delete [] (T *) _p;
	}


//additive operators

	virtual _T <T> operator + (_T <T> _a)
	{
		_T <T> t_;
		t_.t = t + _a.t;
		Depends.insert (_a.Depends.begin (), _a.Depends.end ());
		Depends.insert (_a.Name);
		t_.Depends = Depends;
		t_.Depends.insert (Name);

		return t_;
	}

	virtual T operator - (T _a)
	{
		return t - _a;
	}


//multiplicative operators

	virtual T operator * (T _a)
	{
		return t * _a;
	}

	virtual T operator / (T _a)
	{
		return t * _a;
	}

	virtual int operator % (int _i)
	{
		return static_cast <int> (t) % _i;
	}


//bitwise operators

	virtual T operator & (int _i)
	{
		return static_cast <int> (t) & _i;
	}

	virtual T operator | (int _i)
	{
		return static_cast <int> (t) | _i;
	}

	virtual T operator ^ (int _i)
	{
		return static_cast <int> (t) ^ _i;
	}

	virtual bool operator ~ ()
	{
		return ~static_cast <int> (t);
	}


//logic operators

	virtual bool operator && (T _a)
	{
		return t && _a;
	}

	virtual bool operator || (T _a)
	{
		return t || _a;
	}

	virtual bool operator ! ()
	{
		return !t;
	}


//comparative operators

	virtual bool operator == (T _a)
	{
		return t == _a;
	}

	virtual bool operator != (T _a)
	{
		return t != _a;
	}

	virtual bool operator > (T _a)
	{
		return t > _a;
	}

	virtual bool operator < (T _a)
	{
		return t < _a;
	}

	virtual bool operator >= (T _a)
	{
		return t >= _a;
	}

	
	virtual bool operator <= (T _a)
	{
		return t <= _a;
	}


//referential operators

	virtual T *operator & ()
	{
		return &t;
	}

	virtual T *operator -> ()
	{
		return &t;
	}

	_T <T> operator * (_T <T> _p);

	

//unary operators

	virtual T operator - ()
	{
		return -t;
	}

	virtual T operator + ()
	{
		return +t;
	}


//prefix operators

	virtual T operator ++ ()
	{

		return ++t;
	}

	virtual T operator -- ()
	{
		return --t;
	}


//postfix operators

	virtual T operator ++ (int)
	{
		return t++;
	}

	virtual T operator -- (int)
	{
		return t--;
	}

};


int main ()
{
	typedef _T <int> _int;
	typedef _T <unsigned int> _unsigned_int;
	typedef _T <long> _long;
	typedef _T <unsigned long> _unsigned_long;
	typedef _T <float> _float;
	typedef _T <double> _double;
	typedef _T <char> _char;
	typedef _T <unsigned char> _unsigned_char;
	typedef _T <void> _void;

	{_int a;}
	{_unsigned_int a;}
	{_float a;}
	{_double a;}
	{_long a;}
	{_unsigned_long a;}
	{_char a;}
	{_unsigned_char a;}

	{
		_float f (1.0f, "f");
		_float g (2.0f, "g");
		_float a (3.0f, "a");

		f += g + a;

		printf ("%f\n", (float) f);
	}


	return 0;
}
