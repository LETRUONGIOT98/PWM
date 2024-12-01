#define nutnhan D7
#define OUT D6
int x = 10;//Cài đặt thời gian xuất xung 
int y = 70; ///Cài đặt độ rộng xung từ 0-100% max
int maxx = 100;//Thời gian xuất xung tối đa
void setup() {
  // put your setup code here, to run once:
pinMode(nutnhan, INPUT_PULLUP);
pinMode(OUT, OUTPUT);
analogWrite(OUT,0);
}

void loop() {
  if(y >= 100) y=100;
  if(y<=0) y=0;
  int PWM = map(y,0,100,0,255);
  if(x >= maxx) x = maxx;
if(digitalRead(nutnhan) == HIGH){
  delay(100); //Giá trị delay chống dội nút nhấn không thay đổi giá trị này
  if(digitalRead(nutnhan) == LOW){
    analogWrite(OUT, PWM);
    delay(x);
    analogWrite(OUT,0);
  }
}
analogWrite(OUT,0);
}
