#ifndef MOTORBUSCA_H
#define MOTORBUSCA_H

#include "documento.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

class MotorBusca {
private:
    std::vector<Documento> documentos;

    bool todasPalavrasExistem(Documento& doc, const std::vector<std::string>& palavras);

public:
    MotorBusca(const std::vector<std::string>& nomesArquivos);

    void buscar(std::string& consulta);
};

#endif //MOTORBUSCA_H