#include <iostream>
#include <estructuras.cpp>
using namespace std;

void inicializarListaProducto (ListaProductos *lPro){
    lPro->cab=NULL;
    lPro->nProd=0;
}
void InializarClienteTienda( listaClientes  *aux ){
    aux->nCli=0;
    aux->cab =NULL;
}
void incializarProducto (nodoProducto *nPro){
    nPro->pro->precio = 0.0;
}

void inicializar(listaTiendas *lTiendas){
            lTiendas->nTiendas = 0;
            lTiendas->cab=NULL;
}


tienda *leerInfoTienda (){
    system ("cls");
    tienda *tda = new tienda();
    gotoxy (40, 4); tda->nombre = leerTexto ("NOMBRE DE LA TIENDA: ");
    gotoxy (40, 5); tda->propietario = leerTexto ("PROPIETARIO: ");
    gotoxy (40, 6); tda->ruc = leerTexto ("Ruc: ");
    gotoxy (40, 7); tda->ubicacion = leerTexto("UBICACION: ");
    gotoxy (40, 8); tda->codigo = leerTexto ("Ingrese Codigo Tienda: ");

    return tda;
}

void insertarTienda(listaTiendas *lTiendas, tienda *tda){
    nodoTienda *aux=new nodoTienda();
    nodoTienda *temp=new nodoTienda();
    temp->dat=tda;
    aux=lTiendas->cab;
    if (aux){
        while (aux->sgte){
            aux=aux->sgte;
        }
        temp->sgte=aux->sgte;
        aux->sgte=temp;
        temp->ant=aux;
    }
    else{
        temp ->sgte=aux;
        temp->ant=NULL;
        lTiendas->cab=temp;
    }
    lTiendas->nTiendas++;
}
nodoTienda *BuscarTienda (listaTiendas *lTiendas, string busca){
    nodoTienda *aux = lTiendas->cab;
    while( aux ){
        if( aux->dat->codigo == busca){
            return aux ;
        }
        aux = aux->sgte;
    }
    return NULL;
}

void RegistrarTienda (listaTiendas *lTiendas){
    tienda *tda=new tienda();
    nodoTienda *pos ;
    tda=leerInfoTienda();
    pos = BuscarTienda(lTiendas,tda->codigo);
    if(pos ==NULL){
    insertarTienda(lTiendas,tda);
    }else{
        cout<<" tienda ya se registro con el mismo ID , no se puede registrar 2 veces "<<endl;
    }
}



void leerProducto(producto *pro){
    system("cls");
    gotoxy(40,5); cout << "RegistrarProducto";
    gotoxy(35,7); pro->codigo = leerTexto("CODIGO DE PRODUCTO : ");
    gotoxy(35,8); pro->nombre = leerTexto("NOMBRE REGISTRADO: ");
    gotoxy(35,9); pro->precio = leerReal("PRECIO: ");
    gotoxy(35,10); pro->stock = leerTexto("STOCK DISPONIBLE: ");
    gotoxy(35,11); pro->fechaCaducidad = leerTexto("VENCIMIENTO: ");
}
void insertarProducto (ListaProductos *lista, producto *pro){
    nodoProducto *aux=new(struct nodoProducto);
    nodoProducto *temp=new(struct nodoProducto);
    temp->pro = pro;
    temp->sgte = NULL;
    if (lista->cab == NULL )
        lista->cab = temp;
    else{
        aux = lista->cab;
        while( aux->sgte != NULL ){
            aux = aux->sgte;
        }
        aux->sgte = temp;
    }
    lista->nProd++;
}
void mostrarTienda (tienda *t){
    cout<<"-----------------------"<<endl;
    cout<<"Nombre "<<t->nombre<<endl;
    cout<<"Propietario : "<<t->propietario<<endl;
    cout<<"Ruc ; "<<t->ruc<<endl;
    cout<<"Ubucacion : "<<t->ubicacion<<endl;

}

void ListaTienda( listaTiendas *lt){
    nodoTienda *aux =lt->cab;
    while( aux ){
        mostrarTienda(aux->dat);
        aux = aux->sgte;
    }
}


void registrarProducto(listaTiendas *lTiendas, ListaProductos *lp){
    nodoTienda *pos ;
    producto *p= new producto() ;
    string busca;
    ListaTienda (lTiendas);
    busca = leerTexto("ingrese Id  tienda :");
    pos = BuscarTienda(lTiendas,busca );
    if( pos !=NULL){
        leerProducto( p);
        p->codigo = pos->dat->codigo;
        insertarProducto( lp , p );

    }else{
        cout<<" TIENDA NO EXISTE "<<endl;
    }
}

nodoCliente  *buscarcliente(listaClientes *LT, string busca ){
  nodoCliente *pos = LT->cab;
   while( pos ){
       if( pos->dat->Idcliente ==busca){
           return pos;
       }
       pos = pos->sgte;
   }

}

cliente *leerCliente(string id){
    cliente *c = new cliente();
    c->apellidos = leerTexto(" ingrese apellido ;");
    c->direccion = leerTexto(" ingrese Direccion ;");
    c->dni = leerTexto(" ingrese Dni ;");
    c->idTienda =id;
    c->Idcliente = leerTexto(" ingrese Id Cliente ;");
    c->nombres = leerTexto(" ingrese Nombre ;");
    c->telefono = leerTexto(" ingrese Telefono ;");
  return c;
}

void insertarCliente(listaClientes *lista,cliente  *cli){
     nodoCliente *aux=new(struct  nodoCliente);
     nodoCliente *temp=new(struct  nodoCliente);
    temp->dat= cli;
    temp->sgte = NULL;
    if (lista->cab == NULL )
        lista->cab = temp;
    else{
        aux = lista->cab;
        while( aux->sgte != NULL ){
            aux = aux->sgte;
        }
        aux->sgte = temp;
    }
    lista->nCli++;
}


void registrarClientes(listaTiendas *lTiendas, listaClientes *cliT){
    string busca;
    nodoTienda *pos ;
    cliente *cli = new cliente();
    ListaTienda (lTiendas);
    busca = leerTexto("ingrese Id  tienda :");
    pos = BuscarTienda(lTiendas,busca );
    if( pos !=NULL){
         cli = leerCliente(pos->dat->codigo);
         insertarCliente (cliT,cli);
    }

}
void mostrarCliente(cliente *c){
    cout<<"*********************"<<endl;
    cout <<"cliente Name "<<c->nombres<<endl;
    cout <<"cliente apellido "<<c->apellidos<<endl;
    cout <<"cliente Dni "<<c->dni<<endl;
    cout <<"cliente number telefono "<<c->telefono<<endl;
    cout <<"cliente Date "<<c->direccion<<endl;

}

void recorrerCliente( listaClientes *lt ,string busca ){
    nodoCliente *aux =lt->cab;
    if(aux!=NULL){
    while( aux ){
        if( aux->dat->idTienda == busca ){
             mostrarCliente(aux->dat);
        }

        aux = aux->sgte;
    }
    }else{
        cout<<" lista vacia"<<endl;
    }
}

void MostrarClienteTienda(listaTiendas *lTiendas, listaClientes *cliT){
    string busca;
    nodoTienda *pos =new  nodoTienda();
    ListaTienda (lTiendas);

    busca = leerTexto("ingrese Id  tienda :");
    pos = BuscarTienda(lTiendas,busca );
   if( pos !=NULL) {
       system("cls");
       cout<<"-------------TIENDA ----------"<<endl;
      recorrerCliente(cliT,pos->dat->codigo);

   }
}

int main()
{
   unsigned short opc;
   listaTiendas *lTiendas =new listaTiendas();
   ListaProductos *pro = new ListaProductos();
   listaClientes *cliT = new listaClientes();
   inicializarListaProducto(pro);
   inicializar(lTiendas);
   InializarClienteTienda(cliT);


       do{
           opc = menu();
           switch (opc){
           case 1: RegistrarTienda(lTiendas); break;
           case 2: registrarProducto(lTiendas,pro) ;break;
           case 3:ListaTienda(lTiendas);break;
           case 4:registrarClientes(lTiendas,cliT);break;
           case 5:MostrarClienteTienda(lTiendas,cliT);break;

           }
           system("pause");
           system("cls");
       }while (!(opc==7));

    return 0;
}

