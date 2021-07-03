int enable_A = 13;
int inp1 = 12;
int inp2 = 11;
int enable_B = 5;
int inp3 = 6;
int inp4 = 7;

void setup() {
  pinMode(enable_A, OUTPUT);
  pinMode(enable_B, OUTPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(inp3, OUTPUT);
  pinMode(inp4, OUTPUT);
  
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, LOW);
}

void loop() {
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
}

void directionControl() {
  analogWrite(enable_A, 255);
  analogWrite(enable_B, 255);

  digitalWrite(inp1, HIGH);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, HIGH);
  digitalWrite(inp4, LOW);
  delay(1000);

  digitalWrite(inp1, LOW);
  digitalWrite(inp2, HIGH);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, HIGH);
  delay(1000);
  
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, LOW);
}
void speedControl() {
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, HIGH);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, HIGH);
  
  for (int i = 0; i < 256; i++) {
    analogWrite(enable_A, i);
    analogWrite(enable_B, i);
    delay(20);
  }
  
  for (int i = 255; i >= 0; --i) {
    analogWrite(enable_A, i);
    analogWrite(enable_B, i);
    delay(20);
  }
  
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, LOW);
}
