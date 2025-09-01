# Explicação Simplificada:

1. Debouncing Básico:
cpp
if (current_time - last_press_time > 50) {
Espera 50ms entre leituras para evitar leituras falsas do botão

2. Detecção de Cliques:
cpp
if (current_state == LOW && status_button == HIGH) {
Detecta quando o botão muda de solto (HIGH) para pressionado (LOW)

3. Contador de Cliques:
cpp
if (current_time - last_click_time < 400) {
  click_count++;
}
Se outro clique acontecer em menos de 400ms, conta como double click

4. Detecção de Pressão:
cpp
if (current_time - last_press_time > 1000) {
Se o botão ficar pressionado por mais de 1 segundo, detecta como "pressionado"

Por que esta versão é mais fácil:
Menos estados: Não usa máquina de estados complexa

Lógica simples: if/else fáceis de entender

Variáveis familiares: usa millis() de forma simples

Debouncing básico: suficiente para o propósito

Código linear: mais fácil de seguir o fluxo

Como funciona na prática:
Clique rápido: → "Clique simples!"

Dois cliques rápidos: → "Double clique!"

Segurar pressionado: → "Botão pressionado!"

# Instruções

✅ Vantagens do ESP32:
Mais rápido que Arduino Uno

Mais memória para programas complexos

Pinos GPIO flexíveis - pode usar quase qualquer pino

Serial mais rápido - pode usar 115200 baud rate

⚠️ Atenção com ESP32:
Pinos de 3.3V (não 5V como Arduino)

Cuidado com corrente - alguns pinos têm limitações

PULLUP interno funciona igual ao Arduino

🔍 Para testar no ESP32:
Conecte o botão entre o pino 12 e GND

O resistor pullup interno já cuida do resto

Abra o Serial Monitor em 115200 baud

📊 Se encontrar problemas:
Verifique se a velocidade do Serial está em 115200

Confirme a ligação do botão (um lado no pino, outro no GND)

Teste com Serial.println("Teste") para ver se a comunicação funciona

