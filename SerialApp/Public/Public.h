#ifndef PUBLIC_H
#define PUBLIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#define    MSG_PERIOD    0xAA
#define    MSG_RSP       0xDD
  
typedef enum
{
  Coor = 0,   //����
  Hall,       //����
  PhotoRes,   //����
  TempAndHum, //��ʪ��
  Shake,      //��
  Reed,       //�ɻɹ�
  Accele,     //���ٶ�
  Smoke,      //����
  Doppler,    //������
  Motor,      //���
  LED_PWM,    //LED����
  Sound,      //����
  Voltage,    //��ѹ  ����
  Current,    //����  ����
  Touch,      //����
  Ultrasound, //������
  RFID_1356,  //13.56M��Ƶ��
  RFID_125K,  //125K��Ƶ��
  Flame,      //����
  Particle,   //΢��
  Color,      //��ɫ
  Gyroscope,  //������
  IR_Code,    //��������
  Alcohol,     //�ƾ�
  Relay,
  RFID_900M
}DeviceAddrList;

typedef struct
{
  uint8 Header_1;
  uint8 Header_2;
  uint8 NodeSeq;
  uint8 NodeID;
  uint8 Command;
  uint8 Data[10];
  uint8 Tailer;
}UART_Format;


#ifdef __cplusplus
}
#endif

#endif 
