#include <iostream>
using namespace std;

class GasStation {
private:
	string name;
	float price;		

public:
	GasStation(string name,float price) {
		this->name 	= name;
		this->price = price;
	}

	string getName(){
		return name;
	}
	float getPrice(){
		return price;
	}
};