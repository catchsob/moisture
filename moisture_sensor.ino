#define PIN A1
#define BLINK_INTERVAL 200
#define DETECT_INTERVAL 5000
#define THRESHOLD 200

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("start moisture sensor");
}

void loop() {
  int value = analogRead(PIN);
  Serial.print(value);
  if (value < int(THRESHOLD)) {
    Serial.print(", under threshold ");
    Serial.print(THRESHOLD);
    Serial.println(", alert!!!");
    blink(int(DETECT_INTERVAL), int(BLINK_INTERVAL));
  }
  else {
    Serial.print(", meet threshold ");
    Serial.println(THRESHOLD);
    delay(int(DETECT_INTERVAL));
  }
}

void blink(int dur, int blint) {
  for(int i = 0, led = 0; i < dur; i += blint) {
    if (!led) {
      digitalWrite(LED_BUILTIN, HIGH);
      led = 1;
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
      led = 0;
    }
    delay(blint);
  }

  digitalWrite(LED_BUILTIN, LOW);
}
