#include "Enigma.h"

bool Enigma::cargarRotores() {
    return r1.cargardesdearchivo("Rotor1.txt") &&
        r2.cargardesdearchivo("Rotor2.txt") &&
        r3.cargardesdearchivo("Rotor3.txt");
}

void Enigma::ponerPosiciones(char a, char b, char c) {
    r1.ponerposicion(a);
    r2.ponerposicion(b);
    r3.ponerposicion(c);
}

char Enigma::encriptarCaracter(char c) {
    r1.siguienteposicionrotor();
    if (r1.girorotor()) r2.siguienteposicionrotor();
    if (r2.girorotor()) r3.siguienteposicionrotor();

    c = r1.encriptar(c);
    c = r2.encriptar(c);
    c = r3.encriptar(c);

    return c;
}

char Enigma::desencriptarCaracter(char c) {
    r1.siguienteposicionrotor();
    if (r1.girorotor()) r2.siguienteposicionrotor();
    if (r2.girorotor()) r3.siguienteposicionrotor();

    c = r3.desencriptar(c);
    c = r2.desencriptar(c);
    c = r1.desencriptar(c);

    return c;
}

std::string Enigma::encriptarMensaje(const std::string& msg) {
    std::string result;
    for (char c : msg)
        result += encriptarCaracter(c);
    return result;
}

std::string Enigma::desencriptarMensaje(const std::string& msg) {
    std::string result;
    for (char c : msg)
        result += desencriptarCaracter(c);
    return result;
}
