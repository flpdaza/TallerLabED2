#include <iostream>
#include "Conecta4/Tablero.h"

using namespace std;


int menu();
void ejecutarOpcion(int);

int main(){
    ejecutarOpcion(menu());
    return 0;
}

int menu(){
    int opcion;
    cout<<"#### BIENVENIDO ####"<<endl;
    cout<<" "<<endl;
    cout<<"1) Jugar"<<endl;
    cout<<"9) Salir"<<endl;
    cout<<"Elija una opcion: ";
    cin>>opcion;
    return opcion;

};

void ejecutarOpcion(int opcion){
    Tablero *tablero = new Tablero();
    if(opcion == 1){
        tablero ->playAgainstAI();
    }else if(opcion == 9){
        cout<<"Hasta pronto"<<endl;
    }
}

