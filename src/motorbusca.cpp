#include "motorbusca.hpp"

MotorBusca::MotorBusca(const std::vector<std::string>& nomesArquivos) {
    for (const auto& nome : nomesArquivos)
        documentos.push_back(Documento(nome));
}

