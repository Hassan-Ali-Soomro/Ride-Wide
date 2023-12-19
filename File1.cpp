#include <iostream>
#include <iomanip>
#include <fstream>
#include "ProjectFunctions.h"
using namespace std ;

int main(){
	
	console_adjustment() ;
	header();

	cout << "Kindly give the follwing information to continue\n" << endl ;
	

	UserInfo() ;
	system("CLS") ;


	DisplayVehicles() ;
	system ("CLS") ;

	title() ;
	mode() ;
	system ("CLS") ;

	Receipt();
	
	cout << endl << endl ;
	cout << setw(30) << "Have a safe trip" << endl << endl ;

	
	system ("Pause");
	return 0 ;
}

