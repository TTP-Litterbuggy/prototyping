byte WheelSpeed = 0; // Wheel Speed


int M1_IN1 = 2;
int M1_ENA = 3;
int M1_IN2 = 4;
int M1_ENB = 5;
int M1_IN3 = 6;
int M1_IN4 = 7;
int M2_IN1 = 8;
int M2_ENA = 9;
int M2_IN2 = 10;
int M2_ENB = 11;
int M2_IN3 = 12;
int M2_IN4 = 13;


void setup() {
  // put your setup code here, to run once:

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT); 
  pinMode(M1_IN3, OUTPUT); 
  pinMode(M1_IN4, OUTPUT);  
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT); 
  pinMode(M2_IN3, OUTPUT); 
  pinMode(M2_IN4, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  WheelSpeed = 255;
  analogWrite(M1_ENA, WheelSpeed);
  analogWrite(M1_ENB, WheelSpeed);
  analogWrite(M2_ENA, WheelSpeed);
  analogWrite(M2_ENB, WheelSpeed);

  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  
  digitalWrite(M1_IN3, HIGH);
  digitalWrite(M1_IN4, LOW);
  
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  
  digitalWrite(M2_IN3, LOW);
  digitalWrite(M2_IN4, HIGH);
  

}
