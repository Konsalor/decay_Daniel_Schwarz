#pragma once
class ValueSet
{
public:
	
	double			A;
	double			alpha;
	double			k;
	double			b;
	double			T;

	double			A0;
	double			t;
	double			um;

	//static const double	eulerNr;
	//static const double	a;
	//static const double	Lcb;
	//static const double	Lcc;
	//static const double	Ncl;
	//static const double	R;
	//static const double	k0;
	//static const double	E;

	ValueSet();
	ValueSet(double A0, double t, double um);
	~ValueSet();

	double calculateAlpha();

	double calculateA();

	double calculatek();

	double calculateTempKelv();

	double calculateb();

	double getA();
	double getalpha();
	double getT();
	double getb();
	double getk();


	
};
