#include "documento.hpp"

Documento::Documento(const std::string& nomeArquivo) {
    this->nomeArquivo = nomeArquivo;
    carregarDocumento();
}

void Documento::normalizar(std::string& palavra) {
    palavra.erase(std::remove_if(palavra.begin(), palavra.end(), [](char c) { return !isalpha(c); }), palavra.end());
    std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
}