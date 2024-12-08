#include <iostream>
/*Incluimos la librería string para poder manejar cadenas de texto
Así podemos retornar un string en la función dividir realizando la 
conversión de un float a string*/
#include <string> 

// Función para sumar dos números
float sumar(float a, float b) {
    return a + b;
}

// Función para restar dos números
float restar(float a, float b) {
    return a - b;
}

// Función para multiplicar dos números
float multiplicar(float a, float b) {
    return a * b;
}

/*Función para dividir dos números, retorna un string para poder mostrar un mensaje de error
en caso de que se intente dividir por cero*/
std::string dividir(float a, float b) {
    // Verificación para evitar división por cero
    if (b != 0) {
        return std::to_string(a / b); // Convertimos el resultado de la división a string
    } else {
        return "Error: Division por cero";
    }
}

// Función principal
int main() {
    float numero1, numero2; // Declaramos dos variables para capturar los dos numeros
    
    std::cout << "Escribe el primer numero: "; // Pedimos ingresar el primer número
    std::cin >> numero1; // Guardamos el primer número ingresado 

    std::cout << "Escribe el segundo numero: "; // Pedimos ingresar el segundo número
    std::cin >> numero2; // Guardamos el segundo número ingresado 

    // Realizamos las operaciones usando las funciones
    float suma = sumar(numero1, numero2);
    float resta = restar(numero1, numero2);
    float multiplicacion = multiplicar(numero1, numero2);
    std::string division = dividir(numero1, numero2);

    // Imprimimos los resultados
    std::cout << "La suma es: " << suma << std::endl;
    std::cout << "La resta es: " << resta << std::endl;
    std::cout << "La multiplicacion es: " << multiplicacion << std::endl;
    std::cout << "La division es: " << division << std::endl;

    return 0;
}



