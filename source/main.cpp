#include <iostream>
#include "Conecta4/Tablero.h"
#include "Conecta4/Juego.h"

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
    Juego *juego = new Juego();
    if(opcion == 1){
        juego ->ejecutar();
    }else if(opcion == 9){
        cout<<"Hasta pronto"<<endl;
    }
}

