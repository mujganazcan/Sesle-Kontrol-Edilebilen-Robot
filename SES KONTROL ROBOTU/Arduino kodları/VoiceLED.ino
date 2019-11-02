#include <ld3320.h>

VoiceRecognition Voice;                         //声明一个语音识别对象

#define Led 8                                   //定义LED控制引脚
                             //初始化VoiceRecognition模块   
#define Motor_sag_ileri 3
#define Motor_sag_geri 5
#define Motor_sol_ileri 6
#define Motor_sol_geri 7
    
void setup() 
{   
   
    pinMode(Led,OUTPUT);                        //初始化LED引脚为输出模式
    digitalWrite(Led,HIGH);                      //LED引脚低电平
    Serial.begin(9600);                        //配置9600
    Serial.print("Uart start!");                
    Voice.init();                               //初始化VoiceRecognition模块   
    Voice.addCommand("kai deng",0);             //添加指令，参数（指令内容，指令标签（可重复））
    Voice.addCommand("guan deng",1);            //添加指令，参数（指令内容，指令标签（可重复））
    Voice.addCommand("hello",2);               //添加垃圾词汇
    Voice.addCommand("ni hao",3);      //  ileri  ni hao  你好
    Voice.addCommand("wei wei",4);       //geri  vıy vıy-vıey vıey  伟伟
    Voice.addCommand("Wǒmen",5);         //sağ  Nín - vın  我们 
    Voice.addCommand("Zuǒ",6);         //sol  suo-suvo-zuo  剩下
    Voice.addCommand("deng",7);     //dur  deng-denk  停止
    
    Voice.start();//开始识别
  
    
}
void loop() {
 
  switch(Voice.read())                          //判断识别
  {
    case 0:                                     //若是指令“kai deng”
	digitalWrite(Led,HIGH);                 //点亮LED
        Serial.println("LED ON");
        break;
    case 1:                                     //若是指令“guan deng”
	digitalWrite(Led,LOW);//熄灭LED
        Serial.println("LED OFF");
        break;   
   case 2:                                     //若是指令“guan deng”
        Serial.println("hello");
        break; 
    case 3:
        Serial.println("ileri");
        digitalWrite(Motor_sag_ileri,HIGH);
        digitalWrite(Motor_sag_geri,LOW);
        digitalWrite(Motor_sol_ileri,HIGH);
        digitalWrite(Motor_sol_geri,LOW);
        break;   
    case 4:
        Serial.println("geri");
        digitalWrite(Motor_sag_ileri,LOW);
        digitalWrite(Motor_sag_geri,HIGH);
        digitalWrite(Motor_sol_ileri,LOW);
        digitalWrite(Motor_sol_geri,HIGH);
        break;   
    case 5:
        Serial.println("sağ");
        digitalWrite(Motor_sag_ileri,LOW);
        digitalWrite(Motor_sag_geri,LOW);
        digitalWrite(Motor_sol_ileri,HIGH);
        digitalWrite(Motor_sol_geri,LOW);
        break;   
    case 6:
        Serial.println("sol");
        digitalWrite(Motor_sag_ileri,HIGH);
        digitalWrite(Motor_sag_geri,LOW);
        digitalWrite(Motor_sol_ileri,LOW);
        digitalWrite(Motor_sol_geri,LOW);
        break;
    case 7:
        Serial.println("dur");
        digitalWrite(Motor_sag_ileri,LOW);
        digitalWrite(Motor_sag_geri,LOW);
        digitalWrite(Motor_sol_ileri,LOW);
        digitalWrite(Motor_sol_geri,LOW);
        break;      
   
    default:
    
        break;
  }
}
