# Exemplos ESP32 para Wokwi

## Descrição

Este repositório contém vários exemplos de códigos para ESP32 que podem ser executados no simulador Wokwi. Cada pasta neste repositório representa um projeto independente, demonstrando diferentes funcionalidades do ESP32, como servidores web e controle de hardware via Wi-Fi.

## Estrutura do Projeto

- **esp32-webserver-wokwi/**: Servidor web simples que permite controlar LEDs via interface web.
- **webserver-api/**: Servidor web com API REST (GET, POST).
- **esp32-http-client-weather/**: Cliente HTTP que consome API de clima e aciona LEDs com base na temperatura.

## Pré-requisitos

- **Arduino IDE**: Instale a versão mais recente do Arduino IDE (disponível em [arduino.cc](https://www.arduino.cc/en/software)).
- **Placa ESP32**: Certifique-se de que o suporte para ESP32 está instalado no Arduino IDE (via Gerenciador de Placas: ESP32 by Espressif Systems).
- **Wokwi para VS Code**: Instale a extensão Wokwi para VS Code para executar os projetos localmente direto do VS Code.

## Como Executar

### Passos Gerais

1. Certifique-se de que a extensão **Wokwi for VS Code** está instalada no VS Code (procure por "Wokwi" na aba de extensões).
2. Abra o projeto no **VS Code** (este repositório).
3. Se necessário, ative sua licença do Wokwi: Vá em **View > Command Palette** (ou Ctrl+Shift+P), digite "Wokwi: Activate License" e siga as instruções para obter e inserir a chave de licença.

### Compilando o Código no Arduino IDE (Para Gerar Binário)

Para que o código seja executado no Wokwi, é necessário compilar o código no Arduino IDE e exportar o binário. Isso gera os arquivos necessários para a simulação.

1. Abra o **Arduino IDE**.
2. Abra o arquivo `.ino` do projeto desejado.
3. No menu do Arduino IDE, selecione a placa apropriada:
   - Vá em **Ferramentas > Placa > ESP32 Arduino > DOIT ESP32 DEVKIT V1** (ou a placa ESP32 que você possui).
4. Configure a porta serial se necessário (para upload real, mas não é obrigatório para simulação).
5. Clique em **Verificar/Compilar** (ícone de marca de verificação) para compilar o código.
   - Certifique-se de que não há erros de compilação.
6. Após a compilação bem-sucedida, vá em **Sketch > Exportar Binário Compilado**.
   - Isso criará uma pasta chamada `build` no diretório do sketch, contendo os arquivos binários compilados (como `.bin`).
   - Esses arquivos são necessários para a execução no Wokwi.

### Executando um Projeto Específico no Wokwi

1. Navegue até a pasta do projeto desejado (ex: `esp32-webserver-wokwi/`, `webserver-api/` ou `esp32-http-client-weather/`).
2. Abra o arquivo `diagram.json` localizado na pasta do projeto.
3. Clique no botão **"Start Simulation"** na extensão Wokwi que aparecerá no editor.
   - Isso iniciará a simulação diretamente no VS Code, carregando o diagrama e o binário compilado da pasta `build` (se gerado).
4. O projeto selecionado estará rodando na simulacao, e voce podera interagir via navegador (nos exemplos de servidor) ou acompanhar o Serial Monitor (nos exemplos de cliente HTTP).

### Acessando Interface Web ou Logs Serial

- No simulador Wokwi, localize o endereco IP do ESP32 (geralmente exibido no console ou na interface do simulador).
- Para projetos de servidor, abra um navegador web e digite o endereco IP do ESP32 para acessar a pagina web ou API.
- Para projetos de cliente HTTP, acompanhe o Serial Monitor para ver requisicoes, respostas e regras aplicadas.

## Notas Adicionais

- Para upload real no ESP32 físico: Abra o arquivo `.ino` no Arduino IDE, compile, conecte o ESP32 via USB, selecione a porta correta em **Ferramentas > Porta** e clique em **Upload**.
- Cada projeto é independente e pode ser executado separadamente.
- Certifique-se de que o diagrama (`diagram.json`) está configurado corretamente para o projeto específico.
- Certifique-se de que as credenciais de Wi-Fi no código (`ssid` e `password`) estão corretas para o seu ambiente.
- Se houver problemas, verifique os logs no Arduino IDE ou no terminal do Wokwi CLI.

## Estrutura basica do Projetos

- `esp32-wokwi.ino`: Código principal do Arduino.
- `wokwi.toml`: Configuração do projeto para Wokwi.
- `diagram.json`: Diagrama do circuito para simulação.
- `build/`: Pasta gerada após compilação, contendo os binários.

Divirta-se explorando o ESP32!
