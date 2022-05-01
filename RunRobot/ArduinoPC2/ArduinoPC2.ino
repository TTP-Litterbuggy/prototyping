// Example 5 - Receive with start- and end-markers combined with parsing
int M1_IN1 = 2;  //Low
int M1_IN2 = 3;  //HIGH
int M1_IN3 = 4;  //HIGH
int M1_IN4 = 5;  //LOW
int M1_ENA = 6;
int M1_ENB = 7;

int M2_IN1 = 8;   //HIGH
int M2_IN2 = 9;   //LOW
int M2_IN3 = 10;  //HIGH
int M2_IN4 = 11;  //LOW
int M2_ENA = 12;
int M2_ENB = 13;

int x;
int driveSpd = 140;
int turnSpd = 130;

// =======================
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

      // variables to hold the parsed data
char messageFromPC[numChars] = {0};
int integerFromPC = 0;
int driveTime = 0;
int turnTime = 0;
float floatFromPC = 0.0;

boolean newData = false;

//============

void setup() {
    Serial.begin(9600);
    Serial.println("This demo expects 3 pieces of data - text, an integer and a floating point value");
    Serial.println("Enter data in this style <HelloWorld, 12, 24.7>  ");
    Serial.println();
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

//============

void loop() {
    
    recvWithStartEndMarkers();
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
        showParsedData();
        newData = false;
        Left(turnTime);
        delay(3000);
        Forward(driveTime);
        delay(3000);
    }
}

//============

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//============

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index
    
    strtokIndx = strtok(tempChars,",");
    turnTime  = atoi(strtokIndx);
    
    strtokIndx = strtok(NULL,",");
    driveTime = atoi(strtokIndx);
    
    
//    strtokIndx = strtok(tempChars,",");      // get the first part - the string
//    strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
// 
//    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
//    integerFromPC = atoi(strtokIndx);     // convert this part to an integer
//
//    strtokIndx = strtok(NULL, ",");
//    floatFromPC = atof(strtokIndx);     // convert this part to a float

}

//============

void showParsedData() {
//    Serial.print("Message ");
//    Serial.println(messageFromPC);
//    Serial.print("Integer ");
//    Serial.println(integerFromPC);
//    Serial.print("Float ");
//    Serial.println(floatFromPC);
  Serial.print("turnTIme : ");
  Serial.println(turnTime);
  Serial.print("driveTime : ");
  Serial.println(driveTime);
}


void Forward(int x){                                                                                                                 
  analogWrite(M1_ENA,driveSpd);
  analogWrite(M1_ENB,driveSpd);
  analogWrite(M2_ENA,driveSpd);
  analogWrite(M2_ENB,driveSpd);
  
  digitalWrite(M1_IN1,LOW);
  digitalWrite(M1_IN2,HIGH);
  digitalWrite(M1_IN3,HIGH);
  digitalWrite(M1_IN4,LOW);
  
  digitalWrite(M2_IN1,HIGH);
  digitalWrite(M2_IN2,LOW);
  digitalWrite(M2_IN3,HIGH);
  digitalWrite(M2_IN4,LOW);
  
  delay(x*1000);
  digitalWrite(M1_IN1,LOW);
  digitalWrite(M1_IN2,LOW);
  digitalWrite(M1_IN3,LOW);
  digitalWrite(M1_IN4,LOW);
  digitalWrite(M2_IN1,LOW);
  digitalWrite(M2_IN2,LOW);
  digitalWrite(M2_IN3,LOW);
  digitalWrite(M2_IN4,LOW);
}

void Left(int x){                                                                                                                        
  analogWrite(M1_ENA,turnSpd);
  analogWrite(M1_ENB,turnSpd);
  analogWrite(M2_ENA,turnSpd);
  analogWrite(M2_ENB,turnSpd);
  
  digitalWrite(M1_IN1,HIGH);
  digitalWrite(M1_IN2,LOW);
  digitalWrite(M1_IN3,HIGH);
  digitalWrite(M1_IN4,LOW);
  
  digitalWrite(M2_IN1,LOW);
  digitalWrite(M2_IN2,HIGH);
  digitalWrite(M2_IN3,HIGH);
  digitalWrite(M2_IN4,LOW);
  
  delay(x*1000);
  digitalWrite(M1_IN1,LOW);
  digitalWrite(M1_IN2,LOW);
  digitalWrite(M1_IN3,LOW);
  digitalWrite(M1_IN4,LOW);
  digitalWrite(M2_IN1,LOW);
  digitalWrite(M2_IN2,LOW);
  digitalWrite(M2_IN3,LOW);
  digitalWrite(M2_IN4,LOW);
  
  
}

void Right(int x){
  
  analogWrite(M1_ENA,turnSpd);
  analogWrite(M1_ENB,turnSpd);
  analogWrite(M2_ENA,turnSpd);
  analogWrite(M2_ENB,turnSpd);
  
  digitalWrite(M1_IN1,LOW);
  digitalWrite(M1_IN2,HIGH);
  digitalWrite(M1_IN3,LOW);
  digitalWrite(M1_IN4,HIGH);
  
  digitalWrite(M2_IN1,HIGH);
  digitalWrite(M2_IN2,LOW);
  digitalWrite(M2_IN3,LOW);
  digitalWrite(M2_IN4,HIGH);
  
  delay(x*1000);
  digitalWrite(M1_IN1,LOW);
  digitalWrite(M1_IN2,LOW);
  digitalWrite(M1_IN3,LOW);
  digitalWrite(M1_IN4,LOW);
  digitalWrite(M2_IN1,LOW);
  digitalWrite(M2_IN2,LOW);
  digitalWrite(M2_IN3,LOW);
  digitalWrite(M2_IN4,LOW);
}
