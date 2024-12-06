int ledRed = 10;      // LED rojo conectado al pin 10
int ledGreen = 11;    // LED verde conectado al pin 11
int ledYellow = 12;   // LED amarillo conectado al pin 12

void setup() {
  // Inicializar los pines de los LEDs como salidas
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);

  // Iniciar la comunicación serial
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int data = Serial.read(); // Leer el dato recibido desde Python
    
    // Apagar todos los LEDs antes de cambiar los estados
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);

    // Determinar qué LEDs encender basado en el dato recibido
    switch (data) {
      case '0':
        // Encender todos los LEDs si es 0
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledGreen, HIGH);
        digitalWrite(ledYellow, HIGH);
        break;
      case '1':
        // Encender solo el LED rojo si es 1
        digitalWrite(ledRed, HIGH);
        break;
      case '2':
        // Encender el LED rojo y verde si es 2
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledGreen, HIGH);
        break;
      case '5':
        // Hacer parpadear todos los LEDs si es 3
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledGreen, HIGH);
        digitalWrite(ledYellow, HIGH);
        delay(200); // Encendido durante 200 milisegundos
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledYellow, LOW);
        delay(200); // Apagado durante 200 milisegundos
        break;
    }
  }
}
