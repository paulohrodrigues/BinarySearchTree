#include <iostream>
#include <vector>
#include "string.h"
// #include "gasStation.h"
using namespace std;

class State {
private:
	vector <GasStation *> gasStation;
	string name;

public:
	State(string name) {
		this->name=name;
	}

	void setGasStation(GasStation *gasStation){
		this->gasStation.push_back(gasStation);
	}

	const char* getName(){
		return (this->name.c_str());
	}

	vector <GasStation *> getStations(){
		return gasStation;
	}
	void remove(string name){
		int i=0;
		for(GasStation *g : this->gasStation){
			if(name == g->getName()){
				this->gasStation.erase(this->gasStation.begin()+i);
				return ;
			}
			i++;
		}
		cout<<"Posto nao encontrado!";
	}
};