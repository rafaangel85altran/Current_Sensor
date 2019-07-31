/*
SCT-013 Current sensor reader

Lee la señal analógica A0:

	* SCT-013-50 -> 50A @ 1V
		- Con 3 vueltas es capaz de leer 16.67A
		- Con la señal pasando por un amplificador no inversor G=4.8 es capaz de recibir hasta 4.8V

	* Señal de entrada 16.67 A @ 4.8v
		-  P = V * I ;  P = 3.834 kW
			 # Resolucion (potencia) =  P / (2^10-1) ; Resolucion = 3.75 W
			# Resolucion  (corriente) = 16.67 /  (2^10-1) ; Resolucion = 16mA
*/

float current, power = 0;
 int SCT_raw = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
	SCT_raw = analogRead(A0);
    current = SCT_raw*0.01629;
    power = current * 230;

  Serial.println(current, power);
  delay(1000);
}