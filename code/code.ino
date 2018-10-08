volatile int pwm_value = 0;
volatile int prev_time = 0;
volatile int pwm_value2 = 0;
volatile int prev_time2 = 0;

//1120-2005
 
void setup() {
  Serial.begin(115200);
  // when pin D2 goes high, call the rising function
  attachInterrupt(0, rising, RISING);
  attachInterrupt(1, rising2, RISING);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}
 
void loop() {
  int mapping = abs(map(pwm_value, 1100, 2005, 0, 255));
  int mapping2 = abs(map(pwm_value2, 1000, 1980, 0, 255));
  if(mapping > 255) {mapping = 255;}
  if(mapping <= 0) {mapping = 0;}
  if(mapping2 > 255) {mapping2 = 255;}
  if(mapping2 <= 0) {mapping2 = 0;}
  
  Serial.print(pwm_value2); Serial.print(" ");Serial.print(pwm_value); Serial.print(" ");Serial.print(mapping); Serial.print(" ");Serial.println(mapping2);
  analogWrite(9, mapping);
  analogWrite(11, mapping2);
}
 
void rising() {
  attachInterrupt(0, falling, FALLING);
  prev_time = micros();
}
void rising2() {
  attachInterrupt(1, falling2, FALLING);
  prev_time2 = micros();
}
 
void falling() {
  attachInterrupt(0, rising, RISING);
  pwm_value = micros()-prev_time;
  
}
void falling2() {
  attachInterrupt(1, rising2, RISING);
  pwm_value2 = micros()-prev_time2;
  
}
