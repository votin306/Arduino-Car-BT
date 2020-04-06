/* Проект "Простая машинка с управлением по блютузу "
 * Разаботан : Вотинцевым Иваном
 */

int trigPin = 11; 
int echoPin = 12; 
 
int val;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58;
  if(distance < 6){
    digitalWrite( 2, LOW );
    digitalWrite( 3, HIGH );
    delay(2300);
    digitalWrite( 2, LOW );
    digitalWrite( 3, LOW );
    digitalWrite( 5, LOW );
    digitalWrite( 5, LOW );
  }
  
  if(Serial.available()){
    val = Serial.read();
    if(val == '1'){ //Движение Вперёд
      digitalWrite( 2, HIGH );
      digitalWrite( 3, LOW );
      digitalWrite( 5, LOW );
      digitalWrite( 6, HIGH );
      digitalWrite( 9, LOW );
      digitalWrite( 8, LOW );
     
    }
    if(val == '4'){ //Движение Назад
      digitalWrite( 2, LOW );
      digitalWrite( 3, HIGH );
      digitalWrite( 5, HIGH );
      digitalWrite( 6, LOW );
      digitalWrite( 9, HIGH );
      digitalWrite( 8, HIGH );
    }
    if(val == '2'){ 
      digitalWrite( 2, HIGH );
      digitalWrite( 3, LOW );
      digitalWrite( 5, HIGH );
      digitalWrite( 6, LOW );
      digitalWrite( 9, HIGH );
      digitalWrite( 8, LOW );
    }
    if(val == '3'){
      digitalWrite( 2, LOW );
      digitalWrite( 3, HIGH );
      digitalWrite( 5, LOW );
      digitalWrite( 6, HIGH );
      digitalWrite( 9, LOW );
      digitalWrite( 8, HIGH );
    }
    if(val == '5'){
      digitalWrite( 2, LOW );
      digitalWrite( 3, LOW );
      digitalWrite( 5, LOW );
      digitalWrite( 6, LOW );
      digitalWrite( 8, LOW );
      digitalWrite( 9, LOW );
    }
  }
}
