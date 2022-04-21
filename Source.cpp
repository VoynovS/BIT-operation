
#include <iostream> 
#include <string>
#include <fstream>
#include <cmath> //dlya bitovih znachenii
#include <cstdlib>
#include <ctime>
#define chui(u) (unsigned int)(u) //Umenshaem znachenie unsignet int do chui
using namespace std; 

int tobinary(char num);
string tobinary(short num);
string tobinary(int num);
//Task 2
int tohex(string str);
//Task 3
void fillArr(int Arr[], int length, int min, int max); 

int main() {
	setlocale(LC_ALL, "Russian");
	//Bitovie operacii
	/*
	//Bitovie sdvigi << 
	unsigned int n = 8 << 3;
	cout << "8 << 3 = " << n << endl;
	n = 35 >> 4;
	cout << "35 >> 4 = " << n << endl;

	//Dopolnenie ~ (inversiya) invertiruet dvoichnii kod

	unsigned char s = 154; //10011010
	unsigned char ds = ~s; //
	ds = 171;//10101011
	cout << "~ " << chui(s) << " = " << chui(ds) << endl;

	//Bitovoe i &
	cout << chui(s) << " & " << (unsigned int) ds << " = " << chui (s & ds) << endl;

	//Bitovoe ili |
	s = 152;//10011000
	ds = 43;//00101011
			    //10111011 - 187

	cout << chui(s) << " | " << chui(ds) << " = " << chui(s | ds) << endl;

	//Bitovoe iskluchaushee ili ^ (XOR) esli znacheniya = to 0 else 1
	s = 152;//10011000
	ds = 43;//00101011
			//10110011 - 179

	cout << chui(s) << " ^ " << chui(ds) << " = " << chui(s ^ ds) << endl;
	*/


	//Task 1
	/*cout << "Task 1.\n";
	char  z11 = 70;			//1000110
	short z12 = 15000;		//0011101010011000
	int   z13 = 123124123;  //00000111010101101011100110011011
	
	cout << "char " << z11 << " = " << tobinary(z11) << endl;
	cout << "short " << chui (z12) << " = " << tobinary(z12) << endl;
	cout << "int " << chui (z13) << " = " << tobinary(z13) << endl;*/
	
	//Task 2
	/*cout << "Task 2\nEnter 2 code: ";
	string str;
	cin >> str;

	try
	{
		cout << tohex(str) << "\n\n";
	}
	catch (const invalid_argument & ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	return 0;*/

	//Task 3
	cout << "Enter length array: ";
	int size;
	cin >> size;
	int* dArr = new int[size];
	cout << "Enter begin an finish diapazone: ";
	int a, b;
	cin >> a >> b;
	try
	{
		fillArr(dArr, size, a, b);
		cout << "Original Array: \n[";
		for (int i = 0; i < size; i++) 
			cout << dArr[i] << ", ";
			cout << "\b\b]\n";
		
	}
	catch (const std::range_error& ex)
	{
		cout << "Error diapazone: " << ex.what() << endl;
	}
	catch (const std::underflow_error& ex)
	{
		cout << "Error length: " << ex.what() << endl;
	}
	
}
//Task 3
void fillArr(int Arr[], int length, int min, int max) {
	if (min > max)
		throw range_error("min more than max");
	if (length <= 0)
		throw underflow_error("not positive length");

	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		Arr[i] = rand() % (max - min) + min;
	}


}


//Task 2 
int tohex(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '0' && str[i] != '1')
			throw invalid_argument("not binary");
	}
	int res = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		
		res += (int) (str[str.length() - i - 1] - '0') * pow(2, i);
	}

	return res;
}





//Task 1 Preobrazovanie 10 chisla v dvoichnoe
int tobinary(char num) {
	long int res = 0; //Hranit v sebe dvoichnoe chislo
	for (int i = 7; i >= 0; i--) {
		res += (num >> i & 1) * pow(10, i);
	}
	return res;
}

string tobinary(short num) {
	
	string res; //Hranit v sebe dvoichnoe chislo
	for (int i = 15; i >= 0; i--) { 
		res += to_string (num >> i & 1); //to_string chislo v stroku
	}
	return res;
}

string tobinary(int num) {
	string res; //Hranit v sebe dvoichnoe chislo
	for (int i = 31; i >= 0; i--) {
		
		res += to_string(num >> i & 1);
	}
	return res;
}

