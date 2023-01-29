#include "Money.h" 
#include "vector"
#include <iostream> 
#include <conio.h>
#include <algorithm> 
using namespace std;
typedef vector<Money> TVector;
//формирование вектора 
TVector make_vector(int n)
{
	Money a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
//печать вектора 
void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}

Money s;
Money p;

Money minmax(TVector v)
{
	TVector::iterator x;
	//поставили итератор x на минимальный элемент 
	x = min_element(v.begin(), v.end());
	cout << "min=" << *(x) << endl;
	Money g = *(x);

	TVector::iterator y;
	y = max_element(v.begin(), v.end());
	cout << "max=" << *(y) << endl;
	Money h = *(y);
	Money p = h + g;
	cout << "min+max=" << p << endl;
	return p;
}


struct Greater_s //больше, чем s 
{
	bool operator()(Money t)
	{
		if (t > s) return true; else return false;
	}
};

struct Comp_less // для сортировки по убыванию 
{
public:
	bool operator()(Money t1, Money t2)
	{

		if (t1 > t2)return true;
		else return false;
	}
};


struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

void del(Money& t)
{
	t = t + p;
}


void main()
{
	int n;
	cout << "N?";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);

	TVector::iterator i;
	//поставили итератор i на минимальный элемент 
	i = min_element(v.begin(), v.end());
	cout << "min=" << *(i) << endl;
	Money m = *(i);
	v.push_back(m);
	print_vector(v);


	cin >> s;
	//поиск элементов, удовлетворяющих условию предиката  
	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())//если нет конца вектора 
	{
		cout << "Element nomer:" << *(i) << endl << "Udalenie" << endl;
		s = *i;
		//переместили элемент
		i = remove_if(v.begin(), v.end(), Equal_s());
		//удалили элементы, начиная с i и до конца вектора  
		v.erase(i, v.end());
		print_vector(v);
	}
	else
		cout << "Not such element!" << endl;

	cout << "pribavlenie" << endl;

	/*TVector::iterator x;
	//поставили итератор x на минимальный элемент
	x=min_element(v.begin(),v.end());
	cout<<"min="<<*(x)<<endl;
	Money g=*(x);

	TVector::iterator y;
	y=max_element(v.begin(),v.end());
	cout<<"max="<<*(y)<<endl;
	Money h=*(y);
	Money p = h+g;
	cout<<"min+max="<<p<<endl;*/

	p = minmax(v);
	//для каждого элемента вектора вызывается функция del 
	for_each(v.begin(), v.end(), del);
	print_vector(v);

	_getch();
}

/*// Лабораторная работа №13(1), Вариант 3 (2 семестр).
//

//#include "C:\Users\typakek\Desktop\2 СЕМЕСТР ПНИПУ\ПРОГРАММИРОВАНИЕ\11_Lab\11_Lab_04\11_Lab_04\Time.h"
#include "Time.h"
#include "vector"
#include <iostream> 
#include <conio.h>
#include <algorithm> 
using namespace std;

typedef vector<Time> TVector;
//формирование вектора 
TVector make_vector(int n)
{
	Time a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
//печать вектора 
void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}

Time s;
Time p;

Time minmax(TVector v)
{
	TVector::iterator x;
	//поставили итератор x на минимальный элемент 
	x = min_element(v.begin(), v.end());
	cout << "min=" << *(x) << endl;
	Time g = *(x);

	TVector::iterator y;
	y = max_element(v.begin(), v.end());
	cout << "max=" << *(y) << endl;
	Time h = *(y);
	Time p = h + g;
	cout << "min+max=" << p << endl;
	return p;
}


struct Greater_s //больше, чем s 
{
	bool operator()(Time t)
	{
		if (t > s) return true; else return false;
	}
};

struct Comp_less // для сортировки по убыванию 
{
public:
	bool operator()(Time t1, Time t2)
	{

		if (t1 > t2)return true;
		else return false;
	}
};


//struct Equal_s
//{
//	//bool operator()(Time t)
//	//{
//	//	//return t == s;
//	//}
//};

void del(Time& t)
{
	t = t + p;
}


void main()
{
	int n;
	cout << "N?";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);

	TVector::iterator i;
	//поставили итератор i на минимальный элемент 
	i = min_element(v.begin(), v.end());
	cout << "min=" << *(i) << endl;
	Time m = *(i);
	v.push_back(m);
	print_vector(v);


	cin >> s;
	//поиск элементов, удовлетворяющих условию предиката  
	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())//если нет конца вектора 
	{
		cout << "Element nomer:" << *(i) << endl << "Udalenie" << endl;
		s = *i;
		//переместили элемент
		i = remove_if(v.begin(), v.end(), Equal_s());
		//удалили элементы, начиная с i и до конца вектора  
		v.erase(i, v.end());
		print_vector(v);
	}
	else
		cout << "Not such element!" << endl;

	cout << "pribavlenie" << endl;

	p = minmax(v);
	//для каждого элемента вектора вызывается функция del 
	for_each(v.begin(), v.end(), del);
	print_vector(v);

	_getch();
}*/
