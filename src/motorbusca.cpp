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
    
}