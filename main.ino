#define EMPTY 0
#define HALF 1
#define FULL 2

#define LED1_PIN 8
#define LED2_PIN 9
#define SENSOR1_INPUT 7
#define SENSOR2_INPUT 2

int mapInputToState(int input1, int input2) {
  if (input1 == 1 && input2 == 0) return FULL;
  if (input1 == 1 && input2 == 1) return HALF;
  if (input1 == 0 && input2 == 1) return EMPTY;
  return EMPTY;
}

void mapStateToOutput(int state) {
  switch (state) {
    case EMPTY:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      return;
    case HALF:
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, LOW);
      return;
    case FULL:
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      return;
    default:
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      return;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(SENSOR1_INPUT, INPUT);
  pinMode(SENSOR2_INPUT, INPUT);
}

void loop() {
  int sensor1 = digitalRead(SENSOR1_INPUT);
  int sensor2 = digitalRead(SENSOR2_INPUT);
  int state = mapInputToState(sensor1, sensor2);
  mapStateToOutput(state);
  delay(1000);
}
