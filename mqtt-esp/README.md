# ESP32 MQTT

## Descrição

Este projeto demonstra um servidor web no ESP32 que expõe endpoints HTTP para controlar dois LEDs e retornar status via API. Ele é projetado para execução no simulador Wokwi e utiliza o ESP32 para responder a requisições GET.

## Funcionalidades

- Conexão Wi-Fi automática na rede de simulação.
- Endpoints REST JSON para consultar o status e controlar LEDs.
- Endereço `/api/status` que retorna o estado atual dos dois LEDs.
- Endereço `/api/led/{led}/{action}` que liga ou desliga os LEDs.

## Como Executar

Para instruções gerais de configuração e uso do Wokwi, consulte o [README principal](../../README.md) do repositório.

### Passos Específicos deste Projeto

1. Abra a pasta `webserver-api/` no VS Code.
2. Verifique o arquivo `webserver-api.ino` e, se necessário, ajuste o SSID e a senha Wi-Fi.
3. Compile o código no Arduino IDE e exporte o binário:
   - Abra `webserver-api.ino` no Arduino IDE.
   - Selecione a placa **DOIT ESP32 DEVKIT V1**.
   - Clique em **Verificar/Compilar**.
   - Em seguida, use **Sketch > Exportar Binário Compilado** para gerar a pasta `build`.
4. Abra o `diagram.json` no VS Code.
5. Inicie a simulação no Wokwi.
6. No console do simulador, identifique o IP do ESP32 e use o navegador para consultar `/api/status`.

## Endpoints da API

- `GET /api/status`: Retorna o estado atual dos LEDs em JSON.
- `POST /api/led/1/on`: Liga o LED 1.
- `POST /api/led/1/off`: Desliga o LED 1.
- `POST /api/led/2/on`: Liga o LED 2.
- `POST /api/led/2/off`: Desliga o LED 2.

> Use o navegador para verificar `/api/status` ou ferramentas como Postman/cURL para chamar os endpoints de controle.

## Estrutura do Projeto

- `webserver-api.ino`: Código do Arduino com o servidor e rotas de controle.
- `diagram.json`: Diagrama Wokwi com ESP32 e LEDs.
- `wokwi.toml`: Configuração do projeto para Wokwi.
- `build/`: Pasta com binários gerados pelo Arduino IDE.
