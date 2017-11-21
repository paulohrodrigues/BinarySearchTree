#include <iostream>
#include "gasStation.h"
#include "state.h"
#include "tree.h"
using namespace std;
class App{
private:
	Tree *states;
	void createState(){
		string code;
		cin.ignore();
		cout<<"Digite o Codigo do Estado"<<endl;
		getline(cin,code);
		this->states->insert(new State(code));
		system("cls");
	}
	void createGasStation(){
		string code;
		cout<<"Digite o Codigo do Estado"<<endl;
		cin>>code;
		State *stateLocal = this->states->search(code);
		string name;
		float price;


		if(stateLocal==NULL){
			cout<<"Estado nao encontrado!";
			return ;
		}

		while(1) {
			cout<<"Digite o nome do Posto de Gasolina (-1 para Sair)"<<endl;
			cin.ignore();
			getline(cin,name);
			if(name!="-1"){
				cout<<"Digite o preco da Gasolina"<<endl;
				cin>>price;
				stateLocal->setGasStation(new GasStation(name,price));
			}else{
				return;
			}
			system("cls");    
		}
	}
	void findState(){
		string code;
		cin.ignore();
		cout<<"Digite o Codigo do Estado"<<endl;
		getline(cin,code);
		State *gs = this->states->search(code);
		if(gs!=NULL){
			for(GasStation *g: gs->getStations()){
				cout<< "Nome: "<< g->getName() <<" Preco: "<< g->getPrice()<<endl;
			}
		}else{
			cout<<"Estado nao encontrado!";
			return ;
		}
		// system("cls");
	}
	void removeState(){
		string code;
		cin.ignore();
		cout<<"Digite o Codigo do Estado"<<endl;
		getline(cin,code);
		this->states->remove(code);
		system("cls");
	}
	void removeGasStation(){
		string code;
		// cin.ignore();
		cout<<"Digite o Codigo do Estado"<<endl;
		getline(cin,code);

		State *statesLocal = this->states->search(code);

		cin.ignore();
		cout<<"Digite o Nome do Posto"<<endl;
		getline(cin,code);

		statesLocal->remove(code);
		system("cls");
	}
	void creations(){
		int option=-1;
		while(1) {
			cout<< "1-Cadastrar Estado, 2-Cadastrar Posto, Outro-Sair"<<endl;
			cin >> option;
			switch (option){
				case 1:
			   		system("cls");
			   		this->createState();
			   	break;
			   	case 2:
			   		system("cls");
			   		this->createGasStation();
			   	break;
			   	default:
			   		return ;
			}		
		}
	}
	void finds(){
		int option=-1;
		while(1) {
			cout<< "1-Buscar Estado, Outro-Sair"<<endl;
			cin >> option;
			switch (option){
				case 1:
					system("cls");
			   		this->findState();
			   	break;
			   	default:
			   		return ;
			}	
		}
	}
	void removes(){
		int option=-1;
		while(1) {
			cout<< "1-Remover Estado, 2-Remover Posto, Outro-Sair"<<endl;
			cin >> option;
			switch (option){
				case 1:
					system("cls");
			   		this->removeState();
			   	break;
			   	case 2:
			   		system("cls");
			   		this->removeGasStation();
			   	break;
			   	default:
			   		return ;
			}	
		}
	}
	void menu(){
		int option=-1;
		while(1) {
			cout<< "1-Cadastrar, 2-Buscar, 3-Remover, Outro-Sair"<<endl;
			cin >> option;
			switch (option){
				case 1:
					system("cls");
			   		this->creations();
			   	break;
			   	case 2:
			   		system("cls");
			   		this->finds();
			   	break;
			   	case 3:
			   		system("cls");
			   		this->removes();
			   	break;
			   	default:
			   		return ;
			}
		}
	}
public:
	App(){
		this->states=new Tree();
		this->menu();
	}
};
int main(int argc, char const *argv[]){
	new App();
}