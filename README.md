# TrabalhoPDS2
Trabalho Prático de Programação e Desenvolvimento de Software

## Instruções de Compilação e Execução
Este arquivo README fornece instruções para compilar e executar o sistema de índice invertido implementado em C++.

### Pré-requisitos 📝
Compilador GCC: Para compilar o código-fonte, você precisa do compilador GCC. O código-fonte usa recursos do C++17, então certifique-se de ter uma versão do GCC que suporte o C++17. Você pode verificar a versão do seu GCC com o comando gcc --version.

Make: O programa make é usado para automatizar a compilação. Você pode verificar se o make está instalado em seu sistema com o comando make --version.

### Compilação  🔧
Navegue até o diretório raiz do projeto no terminal.

Execute o comando make para compilar o programa. Isso criará um executável chamado index.

### Execução 🚀
Para executar o programa, use o comando ./index.
O programa lê documentos de texto a partir da pasta "./documentos/". O nome do documento e a frequência de cada palavra dentro dos documentos são exibidos na saída padrão.

Por favor, note que a pasta "./documentos/" deve estar no mesmo diretório que o executável index e deve conter os documentos que você deseja indexar.

### Limpeza 🧹
Para limpar os arquivos compilados, execute make clean no diretório raiz do projeto.