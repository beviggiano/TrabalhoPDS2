#include "motorbusca.hpp"

MotorBusca::MotorBusca(const std::vector<std::string>& nomesArquivos) {
    for (const auto& nome : nomesArquivos)
        documentos.push_back(Documento(nome));
}

void MotorBusca::buscar(std::string& consulta){
    std::vector<std::string> palavrasConsulta;
    std::istringstream fluxo(consulta);
    std::string palavra;

    while (fluxo >> palavra) {
        Documento::normalizar(palavra); // Use Documento::normalizar instead of documentos[0].normalizar
        palavrasConsulta.push_back(palavra);
    }

    std::vector<std::pair<std::string, int>> resultados;

    for (auto& doc : documentos) {
        if (todasPalavrasExistem(doc, palavrasConsulta)) {
            int frequenciaTotal = 0;
            for (const auto& palavra : palavrasConsulta)
                frequenciaTotal += doc.obterFrequenciaPalavra(palavra);
            resultados.push_back(std::make_pair(doc.obterNomeArquivo(), frequenciaTotal));
        }
    }

    std::sort(resultados.begin(), resultados.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  if (a.second != b.second)
                      return a.second > b.second;
                  else
                      return a.first < b.first;
              });

    if (resultados.empty()) {
        std::cout << "Infelizmente, não há nenhum arquivo com os parâmetros que você busca." << std::endl;
    }
    else {
        std::cout << "Aqui estão os arquivos relacionados a sua busca:" << std::endl;
        for (const auto& resultado : resultados)
            std::cout << resultado.first << std::endl;
    }
}

bool MotorBusca::todasPalavrasExistem(Documento& doc, const std::vector<std::string>& palavras) {
    for (const auto& palavra : palavras) {
        if (!doc.palavraExiste(palavra)) {
            return false;
        }
    }
    return true;
}    
