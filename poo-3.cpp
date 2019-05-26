// poo-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Meniu.h"
#include "Pizzerie.h"
#include "Pizza.h"

using namespace std;

int main()
{
	Pizza p(1,0,15.0);
	p.print(); 
	cout<<"Pret "<<p.pret()<<endl;

	Meniu <Pizza*> m1;
	Meniu <float> m2;
	Meniu <int> m3;
	m1.print();
	m2.print();
	m3.print();

	
	m2+=new Pizza;
	return 0;
}

