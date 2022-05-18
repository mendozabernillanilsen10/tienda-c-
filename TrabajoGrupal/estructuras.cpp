#include <iostream>
#include <basicas.cpp>
using namespace std;

// Pila Productos

struct productoAlmacen{
   string Tienda;
   string codigo;
   string nombre;
   double precio;
   int cantidad;
};

struct nodoProductoAlmacen{
    productoAlmacen *pro;
    nodoProductoAlmacen *sgte;
};

struct pilaProductos{
    nodoProductoAlmacen *cab;
    unsigned short nProd;
};
struct producto{
    string IdTiendad;
   string codigo;
   string nombre;
   string stock;
   double precio;
   string fechaCaducidad;
};

struct nodoProducto{
    producto *pro;
    nodoProducto *sgte;
};

struct ListaProductos{
    nodoProducto *cab;
    unsigned short nProd;
};

// ///////////////////////////
struct clienteCola{
   int numeroAtencion;
   string apellidos;
   string nombres;
   string dni;
};

struct nodoColaCliente{
    clienteCola *info;
    nodoColaCliente *sgte;
};

struct colaClientes{
    nodoColaCliente *delante;
    nodoColaCliente *atras;
    unsigned short nCliCola;
};

struct cliente{
    string Idcliente;
    string idTienda;
    string nombres;
    string apellidos;
    string dni;
    string direccion;
    string telefono;
};
struct nodoCliente{
    cliente *dat;
    nodoCliente *sgte;
    nodoCliente *ant;
};

struct listaClientes{ // LED
    nodoCliente *cab;
    unsigned short nCli;
};

struct tienda{
    string codigo;
    string nombre;
    string ruc;
    string propietario;
    string ubicacion;
    colaClientes *cola;
    listaClientes *lCT;
    ListaProductos *lP;
    pilaProductos *pP;
};

struct nodoTienda{
    tienda *dat;
    nodoTienda *sgte;
    nodoTienda *ant;
};

struct listaTiendas{ // LED
    nodoTienda *cab;
    unsigned short nTiendas;
};

struct informacion{
    string nombre;
    string direccion;
    string ruc;
    string gerente;
};

struct centroComercial{
    informacion *info;
    listaTiendas *lT;
    listaClientes *lC;
};
