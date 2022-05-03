#include <iostream>//LIBRERIAS A USAR 
#include <stdlib.h>//DE MEMORIA DINAMICA
#include <string>//DE STRINGS Y GETLINE
#include <stdio.h>// DE PRINTF
#include <algorithm>//PARA LAMBDAS Y MAS
#include <fstream>//PARA ESCRIBIR ARCHIVOS
#include <sstream>//PARA LEER ARCHIVOS
#include <Windows.h>//PARA LA CONSOLA
#include "ListaDoblementeEnlazada.h"//NUESTRA LISTA DOBLEMENTE ENLAZADA
#include "Fecha.h"
#include "Plato.h"
#include "Persona.h"
#include "Cliente.h"
#include "Motorizado.h"
#include "Restaurante.h"
using namespace std;
//FUNCION PARA CARGAR LAS PERSONAS Y LE PASAMOS LA LISTA POR REFERENCIA
//PARA QUE SE EFECTUEN LOS CAMBIOS
void cargarPersona(DoubleLinkedList<Cliente>& lista_clientes)
{
    fstream archivo_clientes("clientes.txt", ios::in); //ios::in sirve para entrada al archivo (ingresar clientes al archivo)
    while (!archivo_clientes.eof()) { //mientras el archivo no esta vacio...
        string str;
        getline(archivo_clientes, str); //leer cadenas del archivo clientes

        if (str.empty()) //si la cadena esta vacia, continua
            continue;

        stringstream abc(str);
        string token;
        DoubleLinkedList<string> separador;
        while (getline(abc, token, ',')) {
            separador.agregar(token);
        }
        Cliente auxiliar;
        auxiliar.nombre = separador.at(0);
        auxiliar.apellido = separador.at(1);
        auxiliar.edad = stoi(separador.at(2));
        auxiliar.dni = separador.at(3);
        auxiliar.nacimiento.dia = stoi(separador.at(4));
        auxiliar.nacimiento.mes = stoi(separador.at(5));
        auxiliar.nacimiento.anio = stoi(separador.at(6));
        auxiliar.direccionCompleta = separador.at(7);

        lista_clientes.agregar(auxiliar);
    }
    archivo_clientes.close();
}
