// ARDUINO FUN PROJECT #4 //
int segment4 = 4; //D4
int segment3 = 3;//D3
int segment2 = 2;//D2
int segment1 = 7;//D1

int A = 5;
int B = 6;
int C = 8;
int D = 9;
int E = 10;
int F = 11;
int G = 12;
int dp = 13;
int currentSegment;


int readvoltage = A3;
float voltage;
float Vol;
void setup() {

  Serial.begin(9600);
  pinMode(segment1, OUTPUT);
  pinMode(segment2, OUTPUT);
  pinMode(segment3, OUTPUT);
  pinMode(segment4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(dp, OUTPUT);

}

void loop() {
  Vol = analogRead(readvoltage);
  voltage = ((5.0 / 1023.0) * Vol);
  clear_display();
  currentSegment = 1;
  print_numbers(voltage);
}

void clear_display() {
  digitalWrite(segment1, HIGH);
  digitalWrite(segment2, HIGH);
  digitalWrite(segment3, HIGH);
  digitalWrite(segment4, HIGH);
}

void display1() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.print(1);
}
void display2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  Serial.print(2);
}
void display3() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  Serial.print(3);
}
void display4() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(4);
}
void display5() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(5);
}
void display6() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(6);
}
void display7() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.print(7);
}
void display8() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(8);
}
void display9() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.print(9);
}
void display0() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  Serial.print(0);
}

void change_segment(int d) {
  if (d == 1) {
    digitalWrite(segment1, LOW);
    digitalWrite(segment2, HIGH);
    digitalWrite(segment3, HIGH);
    digitalWrite(segment4, HIGH);
    digitalWrite(dp, HIGH);
  }
  if (d == 2) {
    digitalWrite(segment1, HIGH);
    digitalWrite(segment2, LOW);
    digitalWrite(segment3, HIGH);
    digitalWrite(segment4, HIGH);
    digitalWrite(dp, LOW);
  }
  if (d == 3) {
    digitalWrite(segment1, HIGH);
    digitalWrite(segment2, HIGH);
    digitalWrite(segment3, LOW);
    digitalWrite(segment4, HIGH);
    digitalWrite(dp, LOW);
  }
  if (d == 4) {
    digitalWrite(segment1, HIGH);
    digitalWrite(segment2, HIGH);
    digitalWrite(segment3, HIGH);
    digitalWrite(segment4, LOW);
    digitalWrite(dp, LOW);
  }
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  //digitalWrite(p, LOW);
}

void print_numbers(float num) {
  
  
  String numStr = String(num);                  
  int strlength = numStr.length() + 1;          
  char numStrArray[strlength];                 
  numStr.toCharArray(numStrArray, strlength);  

  // displaying the voltage values
  for (int i = 0; i < strlen(numStrArray); i++) {
    char current_char = numStrArray[i];
    if (current_char != '.') {
      change_segment(currentSegment);
      if (current_char == '1') {
        display1();
        delay(5);
      }
      else if(current_char == '2') {
        display2();
        delay(5);
      }
      else if (current_char == '3') {
        display3();
        delay(5);
      }
      else if (current_char == '4') {
        display4();
        delay(5);
      }
      else if (current_char == '5') {
        display5();
        delay(5);
      }
      else if (current_char == '6') {
        display6();
        delay(5);
      }
      else if (current_char == '7') {
        display7();
        delay(5);
      }
      else if (current_char == '8') {
        display8();
        delay(5);
      }
      else if (current_char == '9') {
        display9();
        delay(5);
      }
      else if (current_char == '0') {
        display0();
        delay(5);
      }
      
      currentSegment += 1;
    }
  }
  Serial.println();
}
