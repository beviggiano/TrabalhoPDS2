#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

class Documento {
private:
    std::string nomeArquivo;
    std::map<std::string, int> mapaPalavras;

public:
    Documento(const std::string& nomeArquivo);
    void carregarDocumento();
    const std::string& obterNomeArquivo();
    bool palavraExiste(const std::string& palavra);
    int obterFrequenciaPalavra(const std::string& palavra);
    static void normalizar(std::string& palavra);
};

#endif
