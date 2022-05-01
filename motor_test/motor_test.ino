int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;
int ENA1 = 6;
int ENB1 = 7;

int motor3pin1 = 8;
int motor3pin2 = 9;

int motor4pin1 = 10;
int motor4pin2 = 11;
int ENA2 = 12;
int ENB2 = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

  pinMode(ENA1, OUTPUT); //ENA1
  pinMode(ENB1, OUTPUT); //ENB1
  pinMode(ENA2, OUTPUT); //ENA2
  pinMode(ENB2, OUTPUT); //ENB2
}

void loop() {
  // put your main code here, to run repeatedly:   
//  analogWrite(12, 0); //ENA pin
//  analogWrite(13, 200); //ENB pin
  

  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);


  for (int i = 0; i < 256; i++)

  {
    analogWrite(ENA1, i);
    analogWrite(ENB1, i);
    analogWrite(ENA2, i);
    analogWrite(ENB2, i);

    delay(20);

  } 

  // Decelerate from maximum speed to zero

  for (int i = 255; i >= 0; --i)

  {

    analogWrite(ENA1, i);
    analogWrite(ENB1, i);
    analogWrite(ENA2, i);
    analogWrite(ENB2, i);

    delay(20);
  }


  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
//  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);


  


  //Controlling speed (0 = off and 255 = max speed):
  

//  digitalWrite(motor1pin1, LOW);
//  digitalWrite(motor1pin2, HIGH);
//
//  digitalWrite(motor2pin1, LOW);
//  digitalWrite(motor2pin2, HIGH);
//  delay(1000);
}
