int PIR_pin1=9,PIR_pin2=10;
int MOTOR_pin1=7,MOTOR_pin2=6,MOTOR_pin3=5,MOTOR_pin4=4;
//
int c,InSen,outSen,save1,;
//오류 제거 최종 버전 
void setup(){
  pinMode(MOTOR_pin1,OUTPUT); pinMode(MOTOR_pin2,OUTPUT); 
  pinMode(MOTOR_pin3,OUTPUT); pinMode(MOTOR_pin4,OUTPUT); 
}
//
void loop(){
  while(1){ // 센서 입력 대기
    InSen =digitalRead(PIR_pin1);
    outSen=digitalRead(PIR_pin2);
    if(InSen || outSen)break; // 입력이 있으면 빠져나감
  }
  // delay(100);
  //
  c=0;
  if(InSen){ c=1; while(!digitalRead(PIR_pin2)); } // 두 번째 센서 대기
  if(outSen){ c=2; while(!digitalRead(PIR_pin1)); } // 첫 번째 센서 대기
  //
  switch(c){
    case  1: digitalWrite(MOTOR_pin1,1); digitalWrite(MOTOR_pin2,0); digitalWrite(MOTOR_pin3,0); digitalWrite(MOTOR_pin4,1); break;
    case  2: digitalWrite(MOTOR_pin1,0); digitalWrite(MOTOR_pin2,1); digitalWrite(MOTOR_pin3,1); digitalWrite(MOTOR_pin4,0); break;
  }
  // 
  delay(1000);
  // 
  while(1){
    InSen =digitalRead(PIR_pin1);
    outSen=digitalRead(PIR_pin2);
    if(InSen==0 && outSen==0)break; // 입력이 없으면 빠져나감
  }
  // delay(100);
  digitalWrite(MOTOR_pin1,0); digitalWrite(MOTOR_pin2,0); digitalWrite(MOTOR_pin3,0); digitalWrite(MOTOR_pin4,0);
}
