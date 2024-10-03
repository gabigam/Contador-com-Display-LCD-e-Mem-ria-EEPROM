# Contador com Display LCD e Memória EEPROM

Este é um programa para Arduino que utiliza um display LCD e a memória EEPROM para contar e armazenar informações sobre quantas vezes um botão é pressionado. O objetivo deste projeto é contar e exibir a quantidade de eventos registrados e a diferença em relação ao dia anterior.

## Funcionalidades

- **Contagem de eventos**: Um botão conectado ao Arduino é utilizado para contar eventos. Cada vez que o botão é pressionado, o contador é incrementado e a quantidade atual é exibida no display LCD.

- **Armazenamento na memória EEPROM**: As informações sobre a quantidade atual de eventos e a diferença em relação ao dia anterior são armazenadas na memória EEPROM do Arduino. Isso permite que as informações sejam mantidas mesmo após o desligamento do dispositivo.

- **Exibição no display LCD**: O display LCD é utilizado para exibir a quantidade atual de eventos registrados e a diferença em relação ao dia anterior.

## Instruções de Uso

1. Monte o circuito conforme o esquema de conexões fornecido no código.

2. Carregue o código para o seu Arduino utilizando o ambiente de desenvolvimento Arduino IDE ou outro software compatível.

3. Conecte o Arduino a uma fonte de alimentação e observe a contagem de eventos no display LCD.

4. Pressione o botão conectado ao Arduino para registrar eventos e visualizar a contagem atual no display.

5. As informações sobre a quantidade atual de eventos e a diferença em relação ao dia anterior serão mantidas na memória EEPROM mesmo após o desligamento do dispositivo.

## Esquema de Conexões

- **Botão**: Conecte um terminal do botão ao pino 2 (ou outro pino de sua escolha) do Arduino e o outro terminal a GND.
- **Display LCD**: Conecte o display LCD ao Arduino conforme as especificações do seu modelo.

## Dependências

Este projeto depende das bibliotecas `EEPROM.h` e `Adafruit_LiquidCrystal.h`. Certifique-se de instalá-las no seu ambiente de desenvolvimento Arduino IDE antes de carregar o código para o Arduino.


