// Лабораторная работа №13(1), Вариант 3 (2 семестр).

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
		std::cout << v[i] << endl;
	std::cout << endl;
}

Time s;
Time p;

Time minmax(TVector v)
{
	TVector::iterator x;
	//поставили итератор x на минимальный элемент 
	x = min_element(v.begin(), v.end());
	std::cout << "min=" << *(x) << endl;
	Time g = *(x);

	TVector::iterator y;
	y = max_element(v.begin(), v.end());
	std::cout << "max=" << *(y) << endl;
	Time h = *(y);
	Time p = h - g;
	std::cout << "min-max=" << p << endl;
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


struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

void del(Time& t)
{
	t = t + p;
}


void main()
{
	int n;
	cout << "kolvo elemntov: ";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);

	TVector::iterator i;
	TVector::iterator pos; //Позиция по индексу для итератора
	//поставили итератор i на минимальны
	int num;
	cout << "Add object! (3 zadanie)" << endl;
	cin >> s;
	cout << "Pos for add: " << endl; cin >> num;
	//поиск элементов, удовлетворяющих условию предиката  
	i = find_if(v.begin(), v.end(), Equal_s());
	//i = find_if(v.begin(), v.end(), s);
	pos = next(v.begin(), num);
	if (i != v.end())//если нет конца вектора 
	{
		cout << "Object: " << *(i) << endl << "Added for " << num << "pos" << endl;
		v.insert(pos, s);
		print_vector(v);		
	}
	else
		cout << "Not such element!" << endl;

	cout << "Delete object! (4 zadanie)" << endl;
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

	cout << "Raznica min and max elementov" << endl;

	p = minmax(v);
	//для каждого элемента вектора вызывается функция del 
	for_each(v.begin(), v.end(), del);
	print_vector(v);

	_getch();
}