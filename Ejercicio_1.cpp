#include <iostream> //Libreria para poder usar las funciones de entrada y salida de datos
#define MAYORIA_EDAD 18 //Definimos una constante global para la mayoria de edad

int main() {
    int edad; //Declaramos una variable para capturar la edad.
    std::cout << "Ingrese su edad: "; //Pedimos al usuario que ingrese su edad
    std::cin >> edad; //Guardamos la edad ingresada por el usuario

    //Comparamos la edad ingresada por el usuario con la constante definida
    if (edad >= MAYORIA_EDAD) {
        //Si la edad es mayor o igual a la mayoria de edad, imprimimos que es mayor de edad
        std::cout << "Eres mayor de edad." << std::endl; 
    } else {
        //Si la edad es menor a la mayoria de edad, imprimimos que es menor de edad
        std::cout << "Eres menor de edad." << std::endl; 
    }

    return 0;
}