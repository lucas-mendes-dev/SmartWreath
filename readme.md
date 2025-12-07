![VSCode](https://img.shields.io/badge/IDE-VSCode-007ACC?logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIyMDAiIGhlaWdodD0iMjAwIiB2aWV3Qm94PSIwIDAgMjQgMjQiIGZpbGw9IiMyMkEzRjEiPjxwYXRoIGZpbGw9Im5vbmUiIHN0cm9rZT0iIzIyQTNGMSIgc3Ryb2tlLWxpbmVqb2luPSJyb3VuZCIgc3Ryb2tlLXdpZHRoPSIxLjUiIGQ9Ik0xNS42OTUgMTYuMzE4TDEwLjMzMyAxMm01LjM2MiA0LjMxOFY3LjY4Mm0wIDguNjM2djIuMThjMCAuNjgtLjI3IDEuMzMyLS43NSAxLjgxM00xMC4zMzIgMTJsNS4zNjItNC4zMThNMTAuMzMzIDEyTDcuODI4IDkuOTgzbTcuODY3LTIuM3YtMi4xOGMwLS42OC0uMjctMS4zMzMtLjc1LTEuODE0TTcuODI3IDE0LjAxN2wtMy41MTYgMi44MzFhLjYxLjYxIDAgMCAxLS44MTMtLjA0NGwtMS4wNzEtMS4wNzZhLjYxLjYxIDAgMCAxIC4wMjItLjg4MUw1LjU5OCAxMm0yLjIzIDIuMDE3bDYuNDU2IDUuODRxLjMwNC4yNzMuNjYuNDU0bS03LjExNi02LjI5NEw1LjU5OCAxMm0wIDBMMi40NSA5LjE1M2EuNjEuNjEgMCAwIDEtLjAyMi0uODgxbDEuMDcxLTEuMDc2Yy4yMi0uMjIuNTctLjI0LjgxMy0uMDQ0bDMuNTE2IDIuODNtMCAwbDYuNDU2LTUuODM5cS4zMDQtLjI3My42Ni0uNDU0bTAgMTYuNjIyYTMuMDQgMy4wNCAwIDAgMCAyLjUxNy4xMTNsMi4zMzQtLjkzN2MuNTc3LS4yMzIuOTU1LS43OTEuOTU1LTEuNDEzVjUuOTI2YzAtLjYyMi0uMzc4LTEuMTgxLS45NTUtMS40MTNsLTIuMzM0LS45MzdhMy4wNCAzLjA0IDAgMCAwLTIuNTE3LjExMyIvPjwvc3ZnPg==) ![PlatformIO](https://img.shields.io/badge/SDK-PlatformIO-2bbc8a?logo=platformio)

# Guirlanda Smart

Projeto de firmware para uma guirlanda inteligente: controla buzzer e dois LEDs para tocar melodias pré-programadas e indicar visualmente o estado. 

Desenvolvido com foco no **Arduino Uno** (ATmega328P).

## Hardware (componentes e pinos)

- Buzzer passivo: conectado ao pino `D4` (`PIN_BUZZER`).
- LED 1: conectado ao pino `D6` (`PIN_LED1`).
- LED 2: conectado ao pino `D7` (`PIN_LED2`).
- Botão 1: conectado ao pino `D8` (`PIN_BTN1`) — configurado com `INPUT_PULLUP`.
- Botão 2: conectado ao pino `D9` (`PIN_BTN2`) — configurado com `INPUT_PULLUP`.

Observações:

- Os botões usam pull-up interno; pressione contra o GND.
- Ajuste os pinos no `src/main.cpp` se necessário.

## Como configurar o ambiente

1. Instale o Visual Studio Code.
2. Instale a extensão PlatformIO IDE (ou use PlatformIO CLI).
3. Abra a pasta do projeto no VSCode.
4. Consulte a documentação do PlatformIO se precisar de mais informações: https://docs.platformio.org

## Build e Upload (pela IDE)

- Abra o projeto no Visual Studio Code.
- Clique no ícone do PlatformIO (barra lateral esquerda) para abrir o painel do PlatformIO.
- Use os botões rápidos do painel/toolbar: **Build**, **Upload** e **Monitor** para compilar, enviar e monitorar a serial — sem necessidade de linha de comando.

- Alternativamente, use os botões de atalho na barra inferior do VSCode que o PlatformIO adiciona (Build / Upload / Monitor).

## Notas rápidas

- Arquivo de configuração: `platformio.ini` (verifique o `board` definido).

## Permissões serial (Linux)

Se houver problema de permissão com a porta serial (`/dev/ttyUSB0`), adicione seu usuário ao grupo `dialout`:

```bash
sudo usermod -aG dialout $USER
```

> Nota: Depois de adicionar seu usuário ao grupo `dialout`, encerre a sessão e faça login novamente (ou reinicie o sistema) para que a mudança de grupo passe a valer.

## Melodias disponíveis

- **Bate o Sino**: Versão simplificada da música natalina.
- **Carol of the Bells**: Melodia clássica com arranjo simplificado para o projeto.
