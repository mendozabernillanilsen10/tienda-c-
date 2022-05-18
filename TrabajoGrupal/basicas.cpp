#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}

unsigned short menu(){
    unsigned short opc;
    system("cls");
    gotoxy(25, 4); cout << "MENU DE OPCIONES";
    gotoxy(20, 5);cout << "1. Registrar Tienda";
    gotoxy(20, 6);cout << "2. Resgistrar Producto";
    gotoxy(20, 7);cout << "3. mostrar tienda con sus propietario";
    gotoxy(20, 8);cout << "4. Registrar clientes a una tienda : ";
    gotoxy(20, 9);cout << "5. mostrar clientes por tienda";
    do{
        gotoxy( 20, 11); cout << "Elija Opcion: ";
        cin >> opc;
    }while(!( opc > 0 && opc < 10));
    return opc;
}

string leerTexto(string mensaje){
    string nombre;
    cout << mensaje;
    fflush(stdin);
    getline(cin, nombre);
    return nombre;
}

unsigned short leerEdad(string mensaje){
    unsigned short valor;
    cout << mensaje;
    do{
        cin >> valor;
    }while(!( valor >1 && valor < 100));
    return valor;
}

double leerReal(string mensaje){
    double valor;
    cout << mensaje;
    do{
        cin >> valor;
    }while(!( valor > 0 ));
    return valor;
}

void encabezado(){
    system ("cls");
    gotoxy(10,3);cout <<"CODIGO";
    gotoxy(20,3);cout <<"APELLIDOS";
    gotoxy(30,3);cout <<"NOMBRES";
    gotoxy(40,3);cout <<"EDAD";
    gotoxy(50,3);cout <<"SUELDO";
    gotoxy(10,4);cout <<"------------------------------------------------------------------------";
}

