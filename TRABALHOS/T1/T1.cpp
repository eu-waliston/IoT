// Trabalho 1 - Botão + cliques
// Waliston Euripedes

#include <stdint.h>
#define pin_button 12

uint8_t status_button;
unsigned long last_press_time = 0;
unsigned long last_loop_time = 0;
bool button_was_pressed = false;

void setup() {
  Serial.begin(115200);
  setup_button();
}

void loop() {
  loop_button();
}

void setup_button() {
  pinMode(pin_button, INPUT_PULLUP);
  status_button = HIGH;
}

void loop_button() {
  unsigned long current_time = millis();
  
  // Leitura do botão a cada 10ms (sem delay!)
  if (current_time - last_loop_time >= 10) {
    last_loop_time = current_time;
    
    uint8_t current_state = digitalRead(pin_button);
    
    // Detecta quando o botão é pressionado
    if (current_state == LOW && status_button == HIGH) {
      if (current_time - last_press_time > 50) { // Debouncing
        button_was_pressed = true;
        last_press_time = current_time;
      }
    }
    
    status_button = current_state;
    
    // Detecta cliques
    if (button_was_pressed && current_state == HIGH) {
      static unsigned long last_click_time = 0;
      static int click_count = 0;
      
      if (current_time - last_click_time < 400) {
        click_count++;
      } else {
        click_count = 1;
      }
      
      last_click_time = current_time;
      
      if (click_count == 1) {
        Serial.println("Clique simples!");
      } else if (click_count == 2) {
        Serial.println("Double clique!");
        click_count = 0;
      }
      
      button_was_pressed = false;
    }
    
    // Detecta botão pressionado
    if (current_state == LOW) {
      if (current_time - last_press_time > 1000) {
        Serial.println("Botão pressionado!");
        last_press_time = current_time; // Reset para não repetir
      }
    }
  }
}