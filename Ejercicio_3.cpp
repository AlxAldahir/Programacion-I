// Directivas necesarias a utilizar en el programa
#include <iostream>
#include <string>
#include <algorithm>

// Clase Empleado: esta clase se encarga de obtener los datos de un empleado y generar su RFC
class Empleado {

    // Atributos de la clase Empleado (privados), solo son accesibles dentro de la clase
    private:
        std::string nombre;
        std::string apellidoPaterno;
        std::string apellidoMaterno;
        std::string fechaNacimiento;


    /*Constructor, este se encarga de inicializar los atributos de la clase Empleado.
    Al llamar a esta función publica se asignan los valores de los parámetros a los
     atributos de la clase Empleado (Que son privados)  */
    public:
        Empleado(std::string nom, std::string paterno, std::string materno, std::string fecha)
            : nombre(nom), apellidoPaterno(paterno), apellidoMaterno(materno), fechaNacimiento(fecha) {}


    // Método para obtener la primera letra de una palabra
    std::string obtenerPrimeraLetra(const std::string& palabra) {
        if (!palabra.empty()) {
            return std::string(1, std::toupper(palabra[0]));
        }
        return "X";
    }

    // Método para obtener las vocales de un apellido
    std::string obtenerPrimeraVocal(const std::string& palabra) {
        std::string vocales = "AEIOU";
        for (size_t i = 1; i < palabra.length(); ++i) {
            char letraActual = std::toupper(palabra[i]);
            if (vocales.find(letraActual) != std::string::npos) {
                return std::string(1, letraActual);
            }
        }
        return "X";
    }

    // Método para generar el RFC
    std::string generarRFC() {
        // Validamos que no haya campos vacíos, solo se permite el apellido materno como campo opcional
        if (nombre.empty() || apellidoPaterno.empty() || fechaNacimiento.empty()) {
            return "Datos incompletos para generar RFC";
        }

        std::string rfc = ""; // Inicializar la variable RFC

        // Tomar las primeras letras de apellido paterno, materno y nombre
        rfc += obtenerPrimeraLetra(apellidoPaterno);
        rfc += obtenerPrimeraVocal(apellidoPaterno);
        rfc += obtenerPrimeraLetra(apellidoMaterno);
        rfc += obtenerPrimeraLetra(nombre);

        // Agregar fecha de nacimiento (AA-MM-DD)
        rfc += fechaNacimiento.substr(2, 2); // Año
        rfc += fechaNacimiento.substr(5, 2); // Mes
        rfc += fechaNacimiento.substr(8, 2); // Día

        // Convertir a mayúsculas
        std::transform(rfc.begin(), rfc.end(), rfc.begin(), ::toupper);

        // Agregar homoclave
        rfc += generarHomoclave();

        return rfc;
    }
    
    // Método ficticio para generar la homoclave
    std::string generarHomoclave() {
        return "AB5";
    }

    // Métodos para imprimir información
    void mostrarRFC() {
        std::cout << "RFC: " << generarRFC() << std::endl;
    }
};

int main() {
    // Declaramos variables para almacenar los datos 
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    // Solicitar datos al usuario
    std::cout << "Ingrese el nombre del empleado: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese el apellido paterno del empleado: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Ingrese el apellido materno del empleado: ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Ingrese la fecha de nacimiento del empleado (AAAA-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);

    // Crear objeto de la clase Empleado
    Empleado empleado1(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);

    // Mostrar RFC generado
    std::cout << "\n--- RFC del Empleado ---" << std::endl;
    empleado1.mostrarRFC();

    return 0;
}