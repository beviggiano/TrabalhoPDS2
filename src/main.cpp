#include "motorbusca.hpp"
#include <filesystem>

int main() {
    std::vector<std::string> nomesArquivos;
    std::string diretorio = "./documentos/";

    for (const auto& entrada : std::filesystem::directory_iterator(diretorio))
        nomesArquivos.push_back(entrada.path().string());

    MotorBusca motor(nomesArquivos);

    std::string consulta;
    std::getline(std::cin, consulta);
    motor.buscar(consulta);

    return 0;
}
