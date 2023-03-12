
int pinS0 = 2; 
int pinS1 = 3;
int pinS2 = 4;
int pinS3 = 5;
int pinEn = 6;

int S0 = 0;
int S1 = 0;
int S2 = 0;
int S3 = 0;
bool En = true;

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);
  pinMode(pinEn, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  printDataLocation();
  writeDataLocation();
  printSignal();
  incDataOut();
  delay(500);
}


void printSignal(){
  int Signal = analogRead(A0);
  Serial.print("Voltage Present: ");
  double Signal_Fitted = Signal * 0.004887585533;
  Serial.print(Signal_Fitted);
  Serial.print("\n");
  }

void writeDataLocation(){
  int DataOut[4] = {S0,S1,S2,S3};
  digitalWrite(pinEn, HIGH);

  digitalWrite(pinS0, LOW);
  digitalWrite(pinS1, LOW);
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, LOW);

  if(DataOut[0]==1){
    digitalWrite(pinS0, HIGH);
    }
  if(DataOut[1]==1){
    digitalWrite(pinS1, HIGH);
    }
  if(DataOut[2]==1){
    digitalWrite(pinS2, HIGH);
    }
  if(DataOut[3]==1){
    digitalWrite(pinS3, HIGH);
    }
    
  digitalWrite(pinEn, LOW);
  }

void printDataLocation(){
  int DataOut[4] = {S0,S1,S2,S3};
  Serial.print("Data Location: ");
  Serial.print(DataOut[0]);
  Serial.print(DataOut[1]);
  Serial.print(DataOut[2]);
  Serial.print(DataOut[3]);
  Serial.print("\n");
}

void incDataOut(){
  if(S3 == 0){
    S3 = 1;
    }
  else{
    S3 = 0;
    if(S2 == 0){
      S2 = 1;
      }
    else{
      S2 = 0;
      if(S1 == 0){
        S1 = 1;
        }
      else{
        S1 = 0;
        if(S0 == 0){
          S0 = 1;
          }
        else{
          S0 = 0;
          }  
        }  
      }  
    }  
  }
