#include "valueSet.h"
#include <math.h>


extern const double	eulerNr = 2.71828182845904523536;
extern const double	a = 1050;
extern const double	Lcb = 0.1;
extern const double	Lcc = 0.0021;
extern const double	Ncl = 3;
extern const double	R = 8.3144621;
extern const double	k0 = 6165;
extern const double	E = 32393;


ValueSet::ValueSet() {

}

ValueSet::ValueSet(double A0, double t, double um) {
	this->A0 = A0;
	this->t	= t;
	this->um = um;
}

double ValueSet::calculateAlpha() {
	alpha = 1 - calculateA() / A0;
	return alpha;
}

double ValueSet::calculateA() {
	A = A0 * pow(eulerNr, -(calculatek() / calculateb()));
	return A;
}

double ValueSet::calculatek() {
	 k = (k0*pow(eulerNr, -(E / (R*calculateTempKelv()))));
	 return k;
}

double ValueSet::calculateTempKelv() {
	T = (t + 273.15);
	return T;
}

double ValueSet::calculateb() {
	b = (a*Lcc*um) / (4 * Lcb*Ncl);
	return b;
}

double ValueSet::getA() {return A;}
double ValueSet::getalpha() {return alpha;}
double ValueSet::getT() { return T; }
double ValueSet::getb() { return b; }
double ValueSet::getk() { return k; }

ValueSet::~ValueSet()
{
}
