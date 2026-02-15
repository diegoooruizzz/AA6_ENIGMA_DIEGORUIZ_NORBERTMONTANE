#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include <string>

class Enigma {
private:
    Rotor r1, r2, r3;

public:
    bool cargarRotores();
    void ponerPosiciones(char a, char b, char c);

    char encriptarCaracter(char c);
    char desencriptarCaracter(char c);

    std::string encriptarMensaje(const std::string& msg);
    std::string desencriptarMensaje(const std::string& msg);
};

#endif

