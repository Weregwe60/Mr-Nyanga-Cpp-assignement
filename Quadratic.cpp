#include<iostream>
#include<cmath>
using namespace std;

void findroots(double a, double b, double c) {
	if (a==0) {
		cout <<"Not a quadratic equation !" <<endl;
		return;
	}
	double D =b*b-4*a*c;
	if (D >0) {
		double r1 =(-b+sqrt(D)) /(2*a);
		double r2 =(-b-sqrt(D)) /(2*a);
		
		cout << "Two real roots: " << r1 << " and " <<r2 << endl;		
	}
	else if (D==0) {
		double r = -b /(2*a);
		cout << "One real root:" << r << endl;
	}
	else {
		double realPart =-b / (2*a);
		double imagPart = sqrt(-D ) / (2*a);
		
		cout << "Complex roots: "<<" + " << imagPart << "i and " << realPart << " - " << imagPart << " i " << endl;
	}
}

int main() {
	double a,b,c ;
	cout <<"Enter a,b,c:";
	cin >>a>>b>>c ;
	
	findroots(a,b,c);
	
	return 0;
}