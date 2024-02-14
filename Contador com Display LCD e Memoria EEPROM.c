// Bibliotecas utilizadas para o lcd e para salvar 
// informaçoes na memória
#include <EEPROM.h>
#include <Adafruit_LiquidCrystal.h>

// Define os pinos usados pelo botão e pelo LED
#define BUTTON_PIN 2
#define LED_PIN LED_BUILTIN


// Cria um objeto do tipo Adafruit_LiquidCrystal para controlar o display
Adafruit_LiquidCrystal lcd(0);

// Variáveis globais
int buttonState = 0; // verifica o estado do botão
int previousButtonState = 0; // verifica o estado anterior do botao
int count = 0; // contador
int peopleYesterday = 0; // contador de pessoas "ontem"

void setup() {
  // Configura o pino do botão como entrada e o LED como saída
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Inicializa o display com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Lê o valor armazenado na EEPROM e armazena em peopleYesterday
  peopleYesterday = EEPROM.read(0);

  // Imprime a diferença entre o valor atual e o valor do dia anterior no display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Diferenca: ");
  // imprime informação da diferença de pessoas em dois dias
  // na tela vindo da unidade de memória 1 chamada pelo
  // EEPROM.read(1)
  lcd.print(EEPROM.read(1));
}

void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(BUTTON_PIN);

  // Verifica se o botão foi pressionado e solto
  if (buttonState == LOW && previousButtonState == HIGH) {
    // Incrementa o contador e atualiza o display
    count++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Quantidade: ");
    lcd.print(count);

    // Aguarda um breve período de tempo
    delay(100);

    // Limpa o display e imprime a diferença de pessoas hoje
    // menos o numero de pessoas ontem
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Diferenca: ");
    lcd.print(count - peopleYesterday);
  }

  // Atualiza o estado anterior do botão
  previousButtonState = buttonState;

  // Grava o valor atual da contagem na EEPROM
  EEPROM.write(1, (count - peopleYesterday));
  
  // Grava o valor atual da contagem na EEPROM
  EEPROM.write(0, count);

  // Aguarda um breve período de tempo
  delay(100);
}