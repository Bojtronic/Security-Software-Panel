#define PIN_BOTON 25
#define PIN_SALIDA 26

bool salidaActiva = false;
unsigned long tiempoInicio = 0;
const unsigned long DURACION = 5000; // 5 segundos

bool estadoAnteriorBoton = LOW;

void setup() {
  pinMode(PIN_BOTON, INPUT);
  pinMode(PIN_SALIDA, OUTPUT);
  
  digitalWrite(PIN_SALIDA, LOW);
  Serial.begin(115200);
}

void loop() {
  bool estadoBoton = digitalRead(PIN_BOTON);

  // Detectar flanco de subida (cuando se presiona)
  if (estadoBoton == HIGH && estadoAnteriorBoton == LOW) {
    Serial.println("Botón presionado");

    digitalWrite(PIN_SALIDA, HIGH);
    salidaActiva = true;
    tiempoInicio = millis();
  }

  estadoAnteriorBoton = estadoBoton;

  // Control del tiempo sin bloquear
  if (salidaActiva && (millis() - tiempoInicio >= DURACION)) {
    digitalWrite(PIN_SALIDA, LOW);
    salidaActiva = false;
    Serial.println("Salida apagada");
  }
}
