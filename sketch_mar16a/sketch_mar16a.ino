byte WheelSpeed = 0; // Wheel Speed


int M1_IN1 = 2;
int M1_IN2 = 3;
int M1_IN3 = 4;
int M1_IN4 = 5;
int M1_ENA = 6;
int M1_ENB = 7;

int M2_IN1 = 8;
int M2_IN2 = 9;
int M2_IN3 = 10;
int M2_IN4 = 11;
int M2_ENA = 12;
int M2_ENB = 13;


void setup() {
  // put your setup code here, to run once:

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT); 
  pinMode(M1_IN3, OUTPUT); 
  pinMode(M1_IN4, OUTPUT); 
  pinMode(M1_ENA,OUTPUT);
  pinMode(M1_ENB,OUTPUT);
   
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT); 
  pinMode(M2_IN3, OUTPUT); 
  pinMode(M2_IN4, OUTPUT);
  pinMode(M2_ENA, OUTPUT);
  pinMode(M2_ENB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  WheelSpeed = 125;
  analogWrite(M1_ENA, 255);
  analogWrite(M1_ENB, 0);
  analogWrite(M2_ENA, 0);
  analogWrite(M2_ENB, 0);

  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  
  digitalWrite(M1_IN3, HIGH);
  digitalWrite(M1_IN4, LOW);
  
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  
  digitalWrite(M2_IN3, LOW);
  digitalWrite(M2_IN4, HIGH);
  

}
