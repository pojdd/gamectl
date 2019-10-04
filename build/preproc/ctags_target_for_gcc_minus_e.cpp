# 1 "e:\\temp\\gamectl\\gamectl.ino"
# 1 "e:\\temp\\gamectl\\gamectl.ino"
# 2 "e:\\temp\\gamectl\\gamectl.ino" 2
# 3 "e:\\temp\\gamectl\\gamectl.ino" 2
//移动加xy数据。
//右击或者左击
//敲击键盘
//按住键盘
//松开键盘
//获取串口第几位信息
byte data; //收到的数据
bool ctrl=false;
static unsigned long startT;
static unsigned long endT;
void setup()
{
  startT=millis();
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();
}
void mouseMove()
{
  waitFor();
  signed char x = data;
  waitFor();
  signed char y = data;
  Mouse.move(x, y);
  SendEnd();
}
void mouseMoveW()
{
  waitFor();
  signed char w = data;
  Mouse.move(0, 0, w);
  SendEnd();
}
void mouseMoveA()
{
  waitFor();
  signed char x = data;
  waitFor();
  signed char y = data;
  waitFor();
  signed char z = data;
  Mouse.move(x, y, z);
  SendEnd();
}
void handles(){
  if(!ctrl)return;
  endT=millis();
  if(endT-startT>20){
    startT=millis();
    Keyboard.press(0x80);
    Keyboard.release(0x80);
  }
}
void waitFor()
{
  Serial.write(0xe0);
  while (!Serial.available()){
    //handles();
    Keyboard.press(0x80);
    Keyboard.release(0x80);
    delay(100);
  }
  data = Serial.read();
}
void SendOk()
{
  //Serial.write(0xee);
}
void SendEnd()
{
  //Serial.write(0xe1);
}
void loop()
{
  waitFor();
  switch (data)
  {
  case 0xc9: //请求cf自动蹲跳服务
    // Keyboard.write(KEY_LEFT_CTRL);
    SendOk();
    ctrl=true;
    break;
  case 0xc8:
    SendOk();
    ctrl=false;
    break;
  case 0xb1: //请求鼠标移动
    SendOk();
    mouseMove();
    break;
  case 0xb2: //请求鼠标左击
    Mouse.click(1);
    SendOk();
    break;
  case 0xb3: //请求鼠标右击
    Mouse.click(2);
    SendOk();
    break;
  case 0xb4: //请求鼠标按住左键
    Mouse.press(1);
    SendOk();
    break;
  case 0xb5: //请求鼠标按住右键
    Mouse.press(2);
    SendOk();
    break;
  case 0xb6: //请求鼠标松开左键
    Mouse.release(1);
    SendOk();
    break;
  case 0xb7: //请求鼠标松开右键
    Mouse.release(2);
    SendOk();
    break;

  case 0xb8:
    Mouse.click(4);
    SendOk();
    break;
  case 0xb9:
    Mouse.release(4);
    SendOk();
    break;
  case 0xbA:
    Mouse.press(4);
    SendOk();
    break;

  case 0xbb: //请求滚动鼠标滚轮
    SendOk();
    mouseMoveW();
    break;

  case 0xbc: //请求带鼠标滚轮的移动
    SendOk();
    mouseMoveA();
    break;
  case 0x15:
    Serial.write(0x71); //请求确认设备身份
    break;
  default:
    Serial.write(0x87); //错误请求
    break;
  }
  /*

  Keyboard.write('u');

  Mouse.move(0, -100);

  */
# 151 "e:\\temp\\gamectl\\gamectl.ino"
}
