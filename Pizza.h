#pragma once
#include <iostream>
#include <vector>
#include "Pizzerie.h"


using namespace std;

typedef struct {
	char *denumire;
	double cantitate;
	double pret_unitar;
}ingredient;

class Pizza :
	public Pizzerie
{
	vector <ingredient> i;
	static const int manopera=10;
	double distanta;
	bool Online;
	bool vegetarian;
public:
	double pret() const
	{
		double suma=0;
		for(unsigned int j=0; j<i.size(); j++)
			suma=suma+ (i[j].pret_unitar * i[j].cantitate);
		suma=suma+manopera;
		if(Online==1)
			suma=suma+(5/100 *suma*(double)distanta)/10;
		return suma;
	}
	virtual void print()
	{
		cout<<"Manopera: "<<manopera<<endl;
		cout<<"Distanta: "<<distanta<<endl;
		cout<<"Comanda online: ";
		if(Online==0)
			cout<<"Nu"<<endl;
		else cout<<"Da"<<endl;
		cout<<"Vegetarian: ";
		if(vegetarian==0)
			cout<<"Nu"<<endl;
		else cout<<"Da"<<endl;
	}
	Pizza()
	{
		Online=0;
		vegetarian=0;
		distanta=0;
	}
	Pizza(bool Online, bool vegetarian, double dist)
	{
		vector <ingredient> i;
		distanta=dist;
		Online=Online;
		vegetarian=vegetarian;
		
		
		cout<<"nr ingrediente ";
		int nr;
		cin>>nr;
		cout<<endl;
		
		for(int j=0; j<nr; j++)
		{ingredient s;
		cout<<"cantitate ";
		cin>>s.cantitate;
		cout<<endl;
		cout<<"pret_unitar";
		cin>>s.pret_unitar;
		s.denumire= new char[7];
		strcpy_s(s.denumire,6,"pizza");
		i.push_back(s);
		}
	}
	~Pizza(void);
	

	double get_distanta()
	{
		return distanta;
	}
	bool get_Online()
	{
		return Online;
	}
	bool get_vegetarian()
	{
		return vegetarian;
	}
};


