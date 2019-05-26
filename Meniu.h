#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Pizza.h"

using namespace std;

template <class T>
class Meniu
{
	T index;
	T total;
	T total_vegetarian;
	vector <Pizza *> v;
public:
	void operator +=(Pizza* p)
	{
		index++;
		v.push_back(p);
		total=total+(T)p->pret();
		if(p->get_vegetarian()==1)
			total_vegetarian=total_vegetarian+(T)p->pret();
	}
	void print()
	{
		cout<<"Template T"<<endl;
		cout<<"Specificari Pizza:"<<endl;
		for(unsigned int i=0; i<v.size(); i++)
			v[i]->print();
	}
	Meniu(void)
	{
		T index=0;
		T total=0;
		T total_vegetarian=0;
	}
	~Meniu(void)
	{
		cout<<"Destructor Meniu"<<endl;
		for(unsigned int i=0; i<v.size(); i++)
			delete v[i];
	}
};

template <>
class Meniu <int>
{
	int index;
	int total;
	int total_vegetarian;
	vector <Pizza *> v;
public:
	void operator +=(Pizza* p)
	{
		try
		{
			if(p->get_distanta()<0)
				throw "Valoare negativa!";
			if(p->pret()<0)
				throw "Valoare negativa!";
		}
		catch(char *s)
		{
			for(unsigned int i=0; i<strlen(s); i++)
			cout<<s[i]<<endl;
		}
	}
	virtual void print()
	{
		cout<<"Template specializat int"<<endl;
		cout<<"Specificari Pizza:"<<endl;
		for(unsigned int i=0; i<v.size(); i++)
			v[i]->print();
	}
	Meniu(void)
	{
		int index=0;
		int total=0;
		int total_vegetarian=0;
	}
	~Meniu(void)
	{
		for(unsigned int i=0; i<v.size(); i++)
			delete v[i];
	}
};