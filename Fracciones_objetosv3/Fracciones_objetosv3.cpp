#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <stdexcept>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int, int);
    void suma(const Fraccion&);
    int getNumerador() const { return numerador; }
    int getDenominador() const { return denominador; }
};

Fraccion::Fraccion(int num, int dem) : numerador(num), denominador(dem) {}

void Fraccion::suma(const Fraccion& otraFraccion) {

    int mcd = denominador * otraFraccion.denominador;
    p1 = //aqui ke sigo


    int nuevoNumerador = numerador * otraFraccion.denominador + otraFraccion.numerador * denominador;
    int nuevoDenominador = denominador * otraFraccion.denominador;
    cout << "Resultado de la suma: " << nuevoNumerador << "/" << nuevoDenominador << endl;
}

bool validarInput(string fraccion, int& numerador, int& denominador) {
    int posicionSlash = fraccion.find('/');
    if (posicionSlash == string::npos || posicionSlash == 0 || posicionSlash == fraccion.length() - 1) {
        cout << "Formato de fracción inválido. Debe estar en el formato 'numerador/denominador'." << endl;
        return false;
    }
    try {
        numerador = stoi(fraccion.substr(0, posicionSlash));
        denominador = stoi(fraccion.substr(posicionSlash + 1));
        if (denominador == 0) {
            cout << "El denominador no puede ser cero." << endl;
            return false;
        }
        return true;
    }
    catch (const std::invalid_argument&) {
        cout << "Formato de fracción inválido. Debe estar en el formato 'numerador/denominador'." << endl;
        return false;
    }
}

int main() {
    cout << "FRACCIONES CON OBJETOS" << endl << endl;
    cout << "Seleccione una operación" << endl;
    cout << "1. Suma" << endl << "2. Resta" << endl << "3. Multiplicación" << endl << "4. División" << endl;

    int tipoOperacion;
    cin >> tipoOperacion;

    int numerador1, denominador1, numerador2, denominador2;
    string primeraFraccion;  // Mueve la declaración fuera del switch

    switch (tipoOperacion) {
    case 1:
        cout << endl << "Suma" << endl;
        cout << "Ingrese la primera fracción (por ejemplo: 7/2): ";
        cin >> primeraFraccion;
        if (validarInput(primeraFraccion, numerador1, denominador1)) {
            cout << "Ingrese la segunda fracción: ";
            string segundaFraccion;
            cin >> segundaFraccion;
            if (validarInput(segundaFraccion, numerador2, denominador2)) {
                Fraccion fraccion1(numerador1, denominador1);
                Fraccion fraccion2(numerador2, denominador2);
                fraccion1.suma(fraccion2);
            }
        }
        break;

    case 2:
        cout << endl << "Resta" << endl;
        // Implementa la resta aquí
        break;

    case 3:
        cout << endl << "Multiplicación" << endl;
        // Implementa la multiplicación aquí
        break;

    case 4:
        cout << endl << "División" << endl;
        // Implementa la división aquí
        break;

    default:
        cout << "Operación no válida." << endl;
        break;
    }
}
