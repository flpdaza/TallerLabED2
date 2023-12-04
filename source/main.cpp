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
    cout<<"1) Jugar facil"<<endl;
    cout<<"2) Jugar intermedio"<<endl;
    cout<<"3) Jugar dificil"<<endl;
    cout<<"9) Salir"<<endl;
    cout<<"Elija una opcion: ";
    cin>>opcion;
    return opcion;

};

void ejecutarOpcion(int opcion){
    if(opcion == 1){
        Tablero *tablero = new Tablero(1);
        tablero ->jugarContraPC();
    }else if(opcion == 2){
        Tablero *tablero = new Tablero(4);
        tablero ->jugarContraPC();
    }else if(opcion == 3){
        Tablero *tablero = new Tablero(6);
        tablero ->jugarContraPC();
    }else if(opcion == 9){
        cout<<"Hasta pronto"<<endl;
    }
}

