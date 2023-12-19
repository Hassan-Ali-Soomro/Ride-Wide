#include<iostream>
#include<string>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

ofstream print ;

void title() ;
void header() ;
void console_adjustment() ;
void firstName() ;
void lastName() ;
void UserInfo() ;
void DisplayVehicles() ;
void selectcar() ;
void mode() ;
void location() ;
void destination() ;
void citiesNames() ;
void cities_Info() ;
int bill_for_Citytocity() ;
int bill_for_days(int days) ;
void Receipt() ;

int num , city1 , city_No=0 , car=0 , num1=0 , daily_charges; 
string first_Name , UserCity , last_Name ;

//#######################################################################################################//
// Console Adjustment

void console_adjustment()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); 
    MoveWindow(console, r.left, r.top, 475, 600, TRUE);

}

//#######################################################################################################//

// Title bar
void title()
{
	cout << "  ###################################################" << endl ;
	cout << "  #############   R I D E   W I D E     #############" << endl ;
	cout << "  ###################################################" << endl ;
	cout << endl ;
}


//#########################################################################################################//

// Heading Statements

void header() 
{
	title() ;
	cout << "WELCOME TO \"RIDEWIDE\" TAXI And Car Rental Service" << endl << endl ;
}

//#########################################################################################################//

//First Name

void firstName()
{
	cout << setw(16) << "First Name " << setw(4) << " : ";
	cin >> first_Name ;	
	for(int i=0 ; i<first_Name.length() ; i++){
		for(int j=0 ; j<first_Name.length() ; j++){		
			if(!(isalpha(first_Name[j]))){
				cout << "User name can contain only letters."<< endl ;
				first_Name = "0" ;
				firstName() ;
			}
		}
	}
}

//######################################################################################################//

//Last Name

void lastName()
{
	cout << setw(15) << "Last Name " << setw(5) << " : ";
	cin >> last_Name ;
		for(int i=0 ; i<last_Name.length() ; i++){
		for(int j=0 ; j<last_Name.length() ; j++){		
			if(!(isalpha(last_Name[j]))){
				cout << "User name can contain only letters."<< endl ;
				last_Name = "0" ;
				lastName() ;				
			}
		}
	}		
}

//#######################################################################################################//

// User Information

void UserInfo()
{	
	print.open("User-Receipt.txt") ;
	firstName() ;
	lastName() ;
	string Ph_No ;
	print << "User Name: " << first_Name << " " << last_Name << endl ;
	cout << setw(20) << "Phone Number : " ;
	cin >> Ph_No ;
	print << "Phone Number: " << Ph_No << endl;

}


//#######################################################################################################//

// Cars availabe

	struct Vehicle{
	int Sr_No;
	string make;
	string model;
	string year;
	float rent_per_km;
	float rent_per_day;
};
Vehicle vehicles[10][6] ;
void DisplayVehicles()
{
	vehicles[0][0].Sr_No = 1 ;
	vehicles[0][1].make = "Toyota" ;
	vehicles[0][2].model = "GLI" ;
	vehicles[0][3].year = "2020" ;
	vehicles[0][4].rent_per_km = 35 ;
	vehicles[0][5].rent_per_day = 7000 ;
	
	vehicles[1][0].Sr_No = 2 ;
	vehicles[1][1].make = "Suzuki" ;
	vehicles[1][2].model = "Alto" ;
	vehicles[1][3].year = "2018" ;
	vehicles[1][4].rent_per_km = 30 ;
	vehicles[1][5].rent_per_day = 5500 ;

	vehicles[2][0].Sr_No = 3 ;
	vehicles[2][1].make = "Honda" ;
	vehicles[2][2].model = "City" ;
	vehicles[2][3].year = "2018" ;
	vehicles[2][4].rent_per_km = 35 ;
	vehicles[2][5].rent_per_day = 7000 ;

	vehicles[3][0].Sr_No = 4 ;
	vehicles[3][1].make = "Suzuki" ;
	vehicles[3][2].model = "Swift" ;
	vehicles[3][3].year = "2020" ;
	vehicles[3][4].rent_per_km = 35 ;
	vehicles[3][5].rent_per_day = 7000 ;

	vehicles[4][0].Sr_No = 5 ;
	vehicles[4][1].make = "Toyota" ;
	vehicles[4][2].model = "Vitz" ;
	vehicles[4][3].year = "2020" ;
	vehicles[4][4].rent_per_km = 35 ;
	vehicles[4][5].rent_per_day = 6000 ;

	vehicles[5][0].Sr_No = 6 ;
	vehicles[5][1].make = "Suzuki" ;
	vehicles[5][2].model = "Cultus" ;
	vehicles[5][3].year = "2020" ;
	vehicles[5][4].rent_per_km = 30 ;
	vehicles[5][5].rent_per_day = 6000 ;

	vehicles[6][0].Sr_No = 7 ;
	vehicles[6][1].make = "Honda" ;
	vehicles[6][2].model = "BRV" ;
	vehicles[6][3].year = "2020" ;
	vehicles[6][4].rent_per_km = 50 ;
	vehicles[6][5].rent_per_day = 9000 ;

	vehicles[7][0].Sr_No = 8 ;
	vehicles[7][1].make = "Changan" ;
	vehicles[7][2].model = "Karvan" ;
	vehicles[7][3].year = "2015" ;
	vehicles[7][4].rent_per_km = 50 ;
	vehicles[7][5].rent_per_day = 8500 ;

	vehicles[8][0].Sr_No = 9 ;
	vehicles[8][1].make = "Suzuki" ;
	vehicles[8][2].model = "Bolan" ;
	vehicles[8][3].year = "2011" ;
	vehicles[8][4].rent_per_km = 45 ;
	vehicles[8][5].rent_per_day = 8500 ;

	vehicles[9][0].Sr_No = 10 ;
	vehicles[9][1].make = "Suzuki" ;
	vehicles[9][2].model = "Ever Van" ;
	vehicles[9][3].year = "2015" ;
	vehicles[9][4].rent_per_km = 45 ;
	vehicles[9][5].rent_per_day =10000 ;
	
	title() ;
	cout << setw(40) << "#### Vehicles Store ####" << endl << endl ;
	cout<< "Sr.No | " << setw(6) << "MAKE" << setw(3)<<"|"<<setw(9)<<" MODEL"<<setw(9);
	cout<<"| YEAR "<< setw(6) << "| Rent/Km " << "| Rent/Day"<<endl;
		for (int i=0 ; i<10 ; i++)
		{
			cout << setw(4)<< vehicles[i][0].Sr_No << setw(4) << " | "<< setw(7) << vehicles[i][1].make ;
			cout << " | " << setw(8) << vehicles[i][2].model  << setw(3) << "|" << setw(5);
			cout << vehicles[i][3].year << setw(3) << "| " << setw(4) << vehicles[i][4].rent_per_km ;
			cout << setw(6) << "| " << setw(5) << vehicles[i][5].rent_per_day ;
			cout << endl ;
			}
	cout << endl << endl ;
	selectcar() ;
	
}


//######################################################################################################//

//Cars Selection
void selectcar(){

	cout << "Select a vehicle (1-10):"  ;
	cin >> num ;
	switch (num)
	{
		case 1: 
			print << "Car : " << vehicles[0][1].make << " " << vehicles[0][2].model << endl;
			car = vehicles[0][4].rent_per_km ;
			daily_charges = vehicles[0][5].rent_per_day ;
			break ;
		case 2: 
			print << "Car : " << vehicles[1][1].make << " " << vehicles[1][2].model << endl;
			car = vehicles[1][4].rent_per_km ;
			daily_charges = vehicles[1][5].rent_per_day ;
			break ;
		case 3: 
			print << "Car : " << vehicles[2][1].make << " " << vehicles[2][2].model << endl;
			car = vehicles[2][4].rent_per_km ;
			daily_charges = vehicles[2][5].rent_per_day ;
			break ;
		case 4: 
			print << "Car : " << vehicles[3][1].make << " " << vehicles[3][2].model << endl;
			car = vehicles[3][4].rent_per_km ;
			daily_charges = vehicles[3][5].rent_per_day ;
			break ;
		case 5: 
			print << "Car : " << vehicles[4][1].make << " " << vehicles[4][2].model << endl;
			car = vehicles[4][4].rent_per_km ;
			daily_charges = vehicles[4][5].rent_per_day ;
			break ;
		case 6: 
			print << "Car : " << vehicles[5][1].make << " " << vehicles[5][2].model << endl;
			car = vehicles[5][4].rent_per_km ;
			daily_charges = vehicles[5][5].rent_per_day ;
			break ;
		case 7: 
			print << "Car : " << vehicles[6][1].make << " " << vehicles[6][2].model << endl;
			car = vehicles[6][4].rent_per_km ;
			daily_charges = vehicles[6][5].rent_per_day ;
			break ;
		case 8: 
			print << "Car : " << vehicles[7][1].make << " " << vehicles[7][2].model << endl;
			car = vehicles[7][4].rent_per_km ;
			daily_charges = vehicles[7][5].rent_per_day ;
			break ;
		case 9: 
			print << "Car : " << vehicles[8][1].make << " " << vehicles[8][2].model << endl;
			car = vehicles[8][4].rent_per_km ;
			daily_charges = vehicles[8][5].rent_per_day ;
			break ;
		case 10: 
			print << "Car : " << vehicles[9][1].make << " " << vehicles[9][2].model << endl;
			car = vehicles[9][4].rent_per_km ;
			daily_charges = vehicles[9][5].rent_per_day ;
			break ;
		default:
			cout << "Invalid Choice" << endl ;
			cout << "Kindly select a car by its serial number (1-10)" << endl;
			selectcar()	;
	}
}

//#######################################################################################################################//

//City Names

    void citiesNames()
	{
	string cities[] = {"karachi", "hyderabad", "sukkur", "dadu", "kashmore", "larkana", "shikarpur", "jacobabad", "khairpur", "ghotki"};
	cout << "Currently our service is available for the following cities " << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "." << cities[i] << "\t" << i+2 << "." << cities[i+1] << endl;
        i++ ;
    }
    cout << endl ;
}


//########################################################################################################//

// Cities
struct Cities
{
	string customerLocation ;
	string customerDestination ;
	int distance ;
};

Cities city[90][3] ;
void cities_Info()
{
	city[0][0].customerLocation = "karachi" ;
	city[0][1].customerDestination = "kashmore" ;
	city[0][2].distance = 645 ;
	 
	city[1][0].customerLocation = "karachi" ;
	city[1][1].customerDestination = "hyderabad" ;
	city[1][2].distance = 204 ;
	 
	city[2][0].customerLocation = "karachi" ;
	city[2][1].customerDestination = "dadu" ;
	city[2][2].distance = 291 ;
	 
	city[3][0].customerLocation = "karachi" ;
	city[3][1].customerDestination = "larkana" ;
	city[3][2].distance = 412 ;
	 
	city[4][0].customerLocation = "karachi" ;
	city[4][1].customerDestination = "shikarpur" ;
	city[4][2].distance = 542 ;
	 
	city[5][0].customerLocation = "karachi" ;
	city[5][1].customerDestination = "sukkur" ;
	city[5][2].distance = 511 ;
	 
	city[6][0].customerLocation = "karachi" ;
	city[6][1].customerDestination = "khairpur" ;
	city[6][2].distance = 477 ;
	 
	city[7][0].customerLocation = "karachi" ;
	city[7][1].customerDestination = "ghotki" ;
	city[7][2].distance = 572 ;
	 
	city[8][0].customerLocation = "karachi" ;
	city[8][1].customerDestination = "jacobabad" ;
	city[8][2].distance = 585 ;
	
// City 2

	city[9][0].customerLocation = "hyderabad" ;
	city[9][1].customerDestination = "kashmore" ;
	city[9][2].distance = 440 ;
	 
	city[10][0].customerLocation = "hyderabad" ;
	city[10][1].customerDestination = "ghotki" ;
	city[10][2].distance = 371 ;
	 
	city[11][0].customerLocation = "hyderabad" ;
	city[11][1].customerDestination = "dadu" ;
	city[11][2].distance = 193 ;
	 
	city[12][0].customerLocation = "hyderabad" ;
	city[12][1].customerDestination = "larkana" ;
	city[12][2].distance = 315 ;
	 
	city[13][0].customerLocation = "hyderabad" ;
	city[13][1].customerDestination = "shikarpur" ;
	city[13][2].distance = 340 ;
	 
	city[14][0].customerLocation = "hyderabad" ;
	city[14][1].customerDestination = "sukkur" ;
	city[14][2].distance = 309 ;
	 
	city[15][0].customerLocation = "hyderabad" ;
	city[15][1].customerDestination = "khairpur" ;
	city[15][2].distance = 275 ;
	 
	city[16][0].customerLocation = "hyderabad" ;
	city[16][1].customerDestination = "karachi" ;
	city[16][2].distance = 204 ;
	 
	city[17][0].customerLocation = "hyderabad" ;
	city[17][1].customerDestination = "jacobabad" ;
	city[17][2].distance = 384 ;

	// City 3
	
	city[18][0].customerLocation = "dadu" ;
	city[18][1].customerDestination = "kashmore" ;
	city[18][2].distance = 312 ;
	 
	city[19][0].customerLocation = "dadu" ;
	city[19][1].customerDestination = "ghotki" ;
	city[19][2].distance = 245 ;
	 
	city[20][0].customerLocation = "dadu" ;
	city[20][1].customerDestination = "hyderabad" ;
	city[20][2].distance = 193 ;
	 
	city[21][0].customerLocation = "dadu" ;
	city[21][1].customerDestination = "larkana" ;
	city[22][2].distance = 125 ;
	 
	city[23][0].customerLocation = "dadu" ;
	city[23][1].customerDestination = "shikarpur" ;
	city[23][2].distance = 194 ;
	 
	city[24][0].customerLocation = "dadu" ;
	city[24][1].customerDestination = "sukkur" ;
	city[24][2].distance = 183 ;
	 
	city[25][0].customerLocation = "dadu" ;
	city[25][1].customerDestination = "khairpur" ;
	city[25][2].distance = 158 ;
	 
	city[26][0].customerLocation = "dadu" ;
	city[26][1].customerDestination = "karachi" ;
	city[26][2].distance = 291 ;
	 
	city[27][0].customerLocation = "dadu" ;
	city[27][1].customerDestination = "jacobabad" ;
	city[27][2].distance = 214 ;

//City 4	

	city[28][0].customerLocation = "jacobabad" ;
	city[28][1].customerDestination = "kashmore" ;
	city[28][2].distance = 139 ;
	 
	city[29][0].customerLocation = "jacobabad" ;
	city[29][1].customerDestination = "ghotki" ;
	city[29][2].distance = 158 ;
	 
	city[30][0].customerLocation = "jacobabad" ;
	city[30][1].customerDestination = "hyderabad" ;
	city[30][2].distance = 384 ;
	
	city[31][0].customerLocation = "jacobabad" ;
	city[31][1].customerDestination = "larkana" ;
	city[31][2].distance = 113 ;
	 
	city[32][0].customerLocation = "jacobabad" ;
	city[32][1].customerDestination = "shikarpur" ;
	city[32][2].distance = 43 ;
	 
	city[33][0].customerLocation = "jacobabad" ;
	city[33][1].customerDestination = "sukkur" ;
	city[33][2].distance = 77 ;
	 
	city[34][0].customerLocation = "jacobabad" ;
	city[34][1].customerDestination = "khairpur" ;
	city[34][2].distance = 104 ;
	 
	city[35][0].customerLocation = "jacobabad" ;
	city[35][1].customerDestination = "karachi" ;
	city[35][2].distance = 585 ;
	 
	city[36][0].customerLocation = "jacobabad" ;
	city[36][1].customerDestination = "dadu" ;
	city[36][2].distance = 214 ;

//City 5	

	city[37][0].customerLocation = "khairpur" ;
	city[37][1].customerDestination = "kashmore" ;
	city[37][2].distance = 161 ;
	 
	city[38][0].customerLocation = "khairpur" ;
	city[38][1].customerDestination = "ghotki" ;
	city[38][2].distance = 87 ;
	 
	city[39][0].customerLocation = "khairpur" ;
	city[39][1].customerDestination = "hyderabad" ;
	city[39][2].distance = 275 ;
	
	city[40][0].customerLocation = "khairpur" ;
	city[40][1].customerDestination = "larkana" ;
	city[40][2].distance = 75 ;
	 
	city[41][0].customerLocation = "khairpur" ;
	city[41][1].customerDestination = "shikarpur" ;
	city[41][2].distance = 60 ;
	 
	city[42][0].customerLocation = "khairpur" ;
	city[42][1].customerDestination = "sukkur" ;
	city[42][2].distance = 33 ;
	 
	city[43][0].customerLocation = "khairpur" ;
	city[43][1].customerDestination = "jacobabad" ;
	city[43][2].distance = 104 ;

	city[44][0].customerLocation = "khairpur" ;
	city[44][1].customerDestination = "karachi" ;
	city[44][2].distance = 477 ;
	 
	city[45][0].customerLocation = "khairpur" ;
	city[45][1].customerDestination = "dadu" ;
	city[45][2].distance = 158 ;
	
	//City 6	

	city[46][0].customerLocation = "ghotki" ;
	city[46][1].customerDestination = "kashmore" ;
	city[46][2].distance = 90 ;
	 
	city[47][0].customerLocation = "ghotki" ;
	city[47][1].customerDestination = "jacobabad" ;
	city[47][2].distance = 158 ;
	 
	city[48][0].customerLocation = "ghotki" ;
	city[48][1].customerDestination = "hyderabad" ;
	city[48][2].distance = 371 ;
	
	city[49][0].customerLocation = "ghotki" ;
	city[49][1].customerDestination = "larkana" ;
	city[49][2].distance = 163 ;
	 
	city[50][0].customerLocation = "ghotki" ;
	city[50][1].customerDestination = "shikarpur" ;
	city[50][2].distance = 114 ;
	 
	city[51][0].customerLocation = "ghotki" ;
	city[51][1].customerDestination = "sukkur" ;
	city[51][2].distance = 78 ;
	 
	city[52][0].customerLocation = "ghotki" ;
	city[52][1].customerDestination = "khairpur" ;
	city[52][2].distance = 87 ;
	 
	city[53][0].customerLocation = "ghotki" ;
	city[53][1].customerDestination = "karachi" ;
	city[53][2].distance = 572 ;
	 
	city[54][0].customerLocation = "ghotki" ;
	city[54][1].customerDestination = "dadu" ;
	city[54][2].distance = 245 ;
	
	//City 7	

	city[55][0].customerLocation = "kashmore" ;
	city[55][1].customerDestination = "jacobabad" ;
	city[55][2].distance = 139 ;
	 
	city[56][0].customerLocation = "kashmore" ;
	city[56][1].customerDestination = "ghotki" ;
	city[56][2].distance = 90 ;
	 
	city[57][0].customerLocation = "kashmore" ;
	city[57][1].customerDestination = "hyderabad" ;
	city[57][2].distance = 440 ;
	
	city[58][0].customerLocation = "kashmore" ;
	city[58][1].customerDestination = "larkana" ;
	city[58][2].distance = 185 ;
	 
	city[59][0].customerLocation = "kashmore" ;
	city[59][1].customerDestination = "shikarpur" ;
	city[59][2].distance = 114 ;
	 
	city[60][0].customerLocation = "kashmore" ;
	city[60][1].customerDestination = "sukkur" ;
	city[60][2].distance = 133 ;
	 
	city[61][0].customerLocation = "kashmore" ;
	city[61][1].customerDestination = "khairpur" ;
	city[61][2].distance = 161 ;
	 
	city[62][0].customerLocation = "kashmore" ;
	city[62][1].customerDestination = "karachi" ;
	city[62][2].distance = 645 ;
	 
	city[63][0].customerLocation = "kashmore" ;
	city[63][1].customerDestination = "dadu" ;
	city[63][2].distance = 312 ;
	
	//City 8

	city[64][0].customerLocation = "sukkur" ;
	city[64][1].customerDestination = "kashmore" ;
	city[64][2].distance = 133 ;
	 
	city[65][0].customerLocation = "sukkur" ;
	city[65][1].customerDestination = "ghotki" ;
	city[65][2].distance = 78 ;
	 
	city[66][0].customerLocation = "sukkur" ;
	city[66][1].customerDestination = "hyderabad" ;
	city[66][2].distance = 309 ;
	
	city[67][0].customerLocation = "sukkur" ;
	city[67][1].customerDestination = "larkana" ;
	city[67][2].distance = 83 ;
	 
	city[68][0].customerLocation = "sukkur" ;
	city[68][1].customerDestination = "shikarpur" ;
	city[68][2].distance = 33 ;
	 
	city[69][0].customerLocation = "sukkur" ;
	city[69][1].customerDestination = "jacobabad" ;
	city[69][2].distance = 77 ;
	 
	city[70][0].customerLocation = "sukkur" ;
	city[70][1].customerDestination = "khairpur" ;
	city[70][2].distance = 33 ;
	 
	city[71][0].customerLocation = "sukkur" ;
	city[71][1].customerDestination = "karachi" ;
	city[71][2].distance = 511 ;

	city[72][0].customerLocation = "sukkur" ;
	city[72][1].customerDestination = "dadu" ;
	city[72][2].distance = 183 ;	
	
//City 9	

	city[73][0].customerLocation = "larkana" ;
	city[73][1].customerDestination = "kashmore" ;
	city[73][2].distance = 185 ;
	 
	city[73][0].customerLocation = "larkana" ;
	city[73][1].customerDestination = "ghotki" ;
	city[73][2].distance = 163 ;
	 
	city[74][0].customerLocation = "larkana" ;
	city[74][1].customerDestination = "hyderabad" ;
	city[74][2].distance = 315 ;
	
	city[75][0].customerLocation = "larkana" ;
	city[75][1].customerDestination = "jacobabad" ;
	city[75][2].distance = 113 ;
	 
	city[76][0].customerLocation = "larkana" ;
	city[76][1].customerDestination = "shikarpur" ;
	city[76][2].distance = 72 ;
	 
	city[77][0].customerLocation = "larkana" ;
	city[77][1].customerDestination = "sukkur" ;
	city[77][2].distance = 83 ;
	 
	city[78][0].customerLocation = "larkana" ;
	city[78][1].customerDestination = "khairpur" ;
	city[78][2].distance = 75 ;
	 
	city[79][0].customerLocation = "larkana" ;
	city[79][1].customerDestination = "karachi" ;
	city[79][2].distance = 412 ;
	 
	city[80][0].customerLocation = "larkana" ;
	city[80][1].customerDestination = "dadu" ;
	city[80][2].distance = 125 ;	

//City 10

	city[81][0].customerLocation = "shikarpur" ;
	city[81][1].customerDestination = "kashmore" ;
	city[81][2].distance = 114 ;
	 
	city[82][0].customerLocation = "shikarpur" ;
	city[82][1].customerDestination = "ghotki" ;
	city[82][2].distance = 114 ;
	 
	city[83][0].customerLocation = "shikarpur" ;
	city[83][1].customerDestination = "hyderabad" ;
	city[83][2].distance = 340 ;
	
	city[84][0].customerLocation = "shikarpur" ;
	city[84][1].customerDestination = "larkana" ;
	city[84][2].distance = 72 ;
	 
	city[85][0].customerLocation = "shikarpur" ;
	city[85][1].customerDestination = "jacobabad" ;
	city[85][2].distance = 43 ;
	 
	city[86][0].customerLocation = "shikarpur" ;
	city[86][5].customerDestination = "sukkur" ;
	city[86][5].distance = 33 ;
	 
	city[87][0].customerLocation = "shikarpur" ;
	city[87][1].customerDestination = "khairpur" ;
	city[87][2].distance = 60 ;
	 
	city[88][0].customerLocation = "shikarpur" ;
	city[88][1].customerDestination = "karachi" ;
	city[88][2].distance = 542 ;
	
	city[89][0].customerLocation = "shikarpur" ;
	city[89][1].customerDestination = "dadu" ;
	city[89][2].distance = 194 ;
	
	
	location() ;
	destination() ;
}

//####################################################################################################//

// Location & Destination Information and Verification

void location(){
	title() ;
	
    cout << "Your City: ";
    cin >> UserCity;
    for (int i = 0; i < UserCity.length(); i++) {
        UserCity[i] = tolower(UserCity[i]);
    }
    
	int city_no ;
    
    bool isLocationValid = false;
    for (int i = 0; i < 1; i++) {
        for (int j = 0 ; j < 90 ; j++)
		{
		if (UserCity == city[j][0].customerLocation) {
            isLocationValid = true;		
            city1 = j ;
            UserCity[0] = toupper(UserCity[0]) ;
			print << "From: " <<UserCity << endl;
            
			break;
        }
    }
}
    if (!isLocationValid) {
        cout << "Sorry sir, our taxi service is not currently available for this city." << endl;
        citiesNames();
        cout << "\nIf you want to change your city Press y: " ;
    	char check ;
		cin >> check ;
			if (check == 'y' || check == 'Y'){
				system("CLS") ;
				location() ;
    		}
    		else {
    			system ("CLS") ;
    			cout << "\n\nThank you very much for visiting us." << endl ;
    			cout << "See you next time." ;
    			exit(0) ;
			}		
		}
	}
//####################################################################################################//

void destination(){
	string UserDestination ;
    cout << "Your Destination: ";
    cin >> UserDestination ;
	num1 = city1 ;
    for (int i = 0; i < UserDestination.length(); i++) {
        UserDestination[i] = tolower(UserDestination[i]);
    }
    bool isDestinationValid = false;
    for (int i = 0; i < 1; i++) {
    	for (int j = 0 ; j < 90 ; j++)
		{
    	if (UserDestination == city[city1][1].customerLocation)
    	{
    		cout << "We currently don't have service within a city." << endl ;
    		cout << "\nIf you want to change your city Press y: " ;
    		char check ;
			cin >> check ;
			if (check == 'y' || check == 'Y'){
				destination() ;
    		}
    		else{
    			system ("CLS") ;
    			title() ;
    			cout << "\nThank you very much for visiting us." << endl ;
    			cout << "See you next time." ;
    			exit(0) ;
			}
    	}
	
	    if (UserDestination == city[city1][1].customerDestination) {
            isDestinationValid = true;
            UserDestination[0] = toupper(UserDestination[0]) ;
            print << "To: " << UserDestination << endl ;
            city_No = city[city1][2].distance ;
            break;
        }
        city1++ ;
    }
		city1=num1  ;
    if (isDestinationValid == false) 
	{
        cout << "Sorry sir, our taxi service is not currently available for this city." << endl;
        citiesNames();
        cout << "\nIf you want to change your city Press y: " ;
    	char check ;
		cin >> check ;
			if (check == 'y' || check == 'Y'){
				destination() ;
    		}
    		else{
    			system ("CLS") ;
    			title() ;
    			cout << "\n\nThank you very much for visiting us." << endl ;
    			cout << "See you next time." ;
    			exit(0) ;
			}
		}	
	}
}

//##########################################################################################################//

// To check whether user wants car to travel from city to city or for days

void mode(){

	string choice ;
	cout << "Do you want car for:" << endl ;
	cout << "1.Taxi \n2.On rent" << endl ;
	cin >> choice ;
	system("CLS") ;
	if(choice=="1")
	{	
		cities_Info() ;
		print << "Fair: Rs " << bill_for_Citytocity() << endl ;
	}
	else if(choice=="2")
	{
		title() ;
		cout << "Enter the number of days you want car on rent: " ;
		cin >> num ;
		while(num>10)
		{
			cout << "Sir you can get car on rent for only upto 10 days." << endl ;
			cout << "Days: " ;
			cin >> num ;
		}
		print << "For: " << num << " days" << endl ;
		print << "Rent: Rs " << bill_for_days(num) << endl ;
	}
	else {
		title() ;
		cout << "Invalid Choice" << endl ;
		cout << "Kindly select the choice by its serial number(1/2)" << endl ;
		mode() ;		
	}

}

//#####################################################################################################//


// Bill Calculation

int bill_for_Citytocity()
	{
		return city_No * car ;
	}


int bill_for_days(int days)
{
	return daily_charges * days ;
}

//#########################################################################################################//

// Receipt

void Receipt(){
	string receipt ;
	ifstream userData ;
	title() ;
	cout << "\"RIDE WIDE\" RECEIPT" << endl ;
	userData.open("User-Receipt.txt") ;
	while(getline(userData, receipt))
	{
		cout << receipt << endl ;
	}
	userData.close() ;
}
