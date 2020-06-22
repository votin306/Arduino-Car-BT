int val;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  if(Serial.available()){
    val = Serial.read();
    if(val == '1'){ //Движение Вперёд
      digitalWrite( 2, HIGH );
      digitalWrite( 3, LOW );
      digitalWrite( 5, LOW );
      digitalWrite( 6, HIGH );
     
    }
    if(val == '4'){ //Движение Назад
      digitalWrite( 2, LOW );
      digitalWrite( 3, HIGH );
      digitalWrite( 5, HIGH );
      digitalWrite( 6, LOW );
    }
    if(val == '2'){ 
      digitalWrite( 2, HIGH );
      digitalWrite( 3, LOW );
      digitalWrite( 5, HIGH );
      digitalWrite( 6, LOW );
    }
    if(val == '3'){
      digitalWrite( 2, LOW );
      digitalWrite( 3, HIGH );
      digitalWrite( 5, LOW );
      digitalWrite( 6, HIGH );
    }
    if(val == '5'){
      digitalWrite( 2, LOW );
      digitalWrite( 3, LOW );
      digitalWrite( 5, LOW );
      digitalWrite( 6, LOW );
    }
  }
}
