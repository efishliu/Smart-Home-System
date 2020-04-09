#ifndef FM1702SL_H
#define FM1702SL_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include "ZComDef.h"

/*********************************************************************
 * CONSTANTS
 */

// These constants are only for example and should be changed to the
// device's needs
#define SERIALAPP_ENDPOINT           11

#define SERIALAPP_PROFID             0x0F05
#define SERIALAPP_DEVICEID           0x0001
#define SERIALAPP_DEVICE_VERSION     0
#define SERIALAPP_FLAGS              0

#define SERIALAPP_MAX_CLUSTERS       2
#define SERIALAPP_CLUSTERID1         1
#define SERIALAPP_CLUSTERID2         2

#define SERIALAPP_SEND_EVT           0x0001
#define PERIOD_EVT                   0x0002
#define RFID_EVT                     0x0004

// OTA Flow Control Delays
#define SERIALAPP_ACK_DELAY          1
#define SERIALAPP_NAK_DELAY          16

// OTA Flow Control Status
#define OTA_SUCCESS                  ZSuccess
#define OTA_DUP_MSG                 (ZSuccess+1)
#define OTA_SER_BUSY                (ZSuccess+2)
  
#define FM1702_RSTPD                P1_2
  
/*********************************************/
  
#define         PageSel            0x00	         //ҳд�Ĵ��� 
#define	        RFIDCommand	   0x01	         //��ʼ��ֹͣ�������ִ��
#define       	FIFODaTa           0x02	         //64�ֽ�FIFO���������
#define       	PrimaryStatus	   0x03	         //������/������/FIFO��״̬��־
#define       	FIFOLength	   0x04	         //FIFO�д洢���ݵ��ֽ���
#define       	SecondaryStatus	   0x05	         //��ͬ��״̬��־
#define       	InterruptEn        0x06	         //ʹ�������жϴ��͵Ŀ���λ
#define         InterruptRq        0x07	         //�ж������־
/*********��1ҳ,���ƺ�״̬********************/
#define         Control	           0x09	         //��ͬ�Ŀ��Ʊ�־�����磺��ʱ�����ĵ�
#define       	ErrorFlag          0x0A	         //��ʾ���һ��ִ�е�����Ĵ���״̬�ı�־
#define       	CollPos		   0x0B	         //��RF�ӿڼ�⵽�ĵ�һ����ͻλ��λ��
#define       	TimerValue         0x0C	         //��ʱ����ʵ��ֵ
#define       	CRCResultLSB       0x0D	         //CRCЭ�������Ĵ����������Ч�ֽ�
#define       	CRCResultMSB       0x0E	         //CRCЭ�������Ĵ����������Ч�ֽ�
#define         BitFraming         0x0F	         //����λ����֡
/*********��2ҳ,�������ͱ������**************/
#define         TxControl          0x11	         //����������������Tx1��Tx2���߼���Ϊ
#define       	CWConductance      0x12	         //ѡ��������������Tx1��Tx2�ĵ絼
#define       	PreSet13           0x13	         //��Щֵ�����Ըı�
#define       	PreSet14           0x14	         //��Щֵ�����Ըı�
#define       	ModWidth           0x15	         //ѡ���������Ŀ��
#define       	PreSet16           0x16	         //��Щֵ�����Ըı�
#define         PreSet17           0x17	         //��Щֵ�����Ըı�
/*********��3ҳ,���������������**************/
#define         RxControl1         0x19	         //���ƽ�������Ϊ
#define       	DecoderControl     0x1A	         //���ƽ�������Ϊ
#define       	BitPhase           0x1B	         //ѡ��������ʹ�����ʱ�Ӽ��λ��
#define       	RxThreshold        0x1C	         //ѡ��λ����������ֵ
#define       	PreSet1D           0x1D	         //��Щֵ�����Ըı�
#define       	RxControl2         0x1E	         //���ƽ�������Ϊ�����������������Դ 
#define         ClockQControl      0x1F	         //����ʱ�Ӳ���
/*********��4ҳ,��Ƶʱ���ͨ������*************/
#define         RxWait             0x21	         //ѡ���ڴ���֮�󣬽���������֮ǰ��ʱ����
#define       	ChannelRedundancy  0x22	         //ѡ����֤RFͨ�����������Ե����ͺ�ģʽ
#define       	CRCPresetLSB       0x23	         //CRC�Ĵ���Ԥ��ֵ�������Ч�ֽ�
#define       	CRCPresetMSB       0x24	         //CRC�Ĵ���Ԥ��ֵ�������Ч�ֽ�
#define       	PreSet25           0x25	         //��Щֵ�����Ըı�
#define       	MFOUTSelect        0x26	         //ѡ��Ӧ�õ�MFOUT���ŵ��ڲ��ź�
#define         PreSet27           0x27	         //��Щֵ�����Ըı�
/*********��5ҳ,FIFO����ʱ�����ж���������******/
#define         FIFOLevel          0x29	         //����FIFO�Ĵ�С����
#define       	TimerClock         0x2A	         //ѡ��ʱ�ӵķ�Ƶ
#define       	TimerControl       0x2B	         //ѡ��ʱ���Ŀ�ʼ�ͽ�������
#define       	TimerReload        0x2C	         //�嶨ʱ����Ԥ��ֵ
#define       	IRQPinConfig       0x2D	         //��������IRQ�����״̬
#define       	PreSet2E           0x2E	         //��Щֵ�����Ըı�
#define         PreSet2F           0x2F	         //��Щֵ�����Ըı�
/**************��6,7ҳ,Ԥ��***********************/
#define        	CryptoSelect       0x31	         //��֤ģʽѡ��,��ѡ������ѱ�׼���Ϻ���׼		
#define		PCD_IDLE           0x00          //ȡ����ǰָ��
#define        	PICC_BLOCK         0x08          //�Ե�8��Ų���,M1����ŷ�Χ��0-63,16������ͳһ��ַ��
//#define			BLOCK_N	           0x3D	         //3DH���Ҫ�����Ŀ�

  
  //FM1715������
#define Transceive              0x1E //���ͽ�������
#define Transmit                0x1a //��������
#define ReadE2                  0x03 //��FM1715 EEPROM����
#define WriteE2                 0x01 //дFM1715 EEPROM����
#define Authent1                0x0c //��֤������֤���̵�1��
#define Authent2                0x14 //��֤������֤���̵�2��
#define LoadKeyE2               0x0b //����Կ��EEPROM���Ƶ�KEY����
#define LoadKey                 0x19 //����Կ��FIFO���渴�Ƶ�KEY����
#define RF_TimeOut              0xfff //����������ʱʱ��
#define Req                     0x01
#define Sel                     0x02
  
  //��Ƭ���Ͷ��嶨��
#define TYPEA_MODE              0 //TypeAģʽ
#define TYPEB_MODE              1 //TypeBģʽ
#define SHANGHAI_MODE           2 //�Ϻ�ģʽ
  
#define TM0_HIGH                0xf0 //��ʱ��0��λ,4MS��ʱ
#define TM0_LOW                 0x60 //��ʱ��0��λ
#define TIMEOUT                 100 //��ʱ������4MS��100=0.4��
  
#define RF_CMD_REQUEST_STD      0x26
#define RF_CMD_REQUEST_ALL      0x52
#define RF_CMD_ANTICOL          0x93
#define RF_CMD_SELECT           0x93
#define RF_CMD_AUTH_LA          0x60
#define RF_CMD_AUTH_LB          0x61
#define RF_CMD_READ             0x30
#define RF_CMD_WRITE            0xa0
#define RF_CMD_INC              0xc1
#define RF_CMD_DEC              0xc0
#define RF_CMD_RESTORE          0xc2
#define RF_CMD_TRANSFER         0xb0
#define RF_CMD_HALT             0x50
//
  
  /* ����������붨�� ERR CODE  */
#define FM1702_OK		0		/* ��ȷ */
#define FM1702_NOTAGERR		1		/* �޿� */
#define FM1702_CRCERR		2		/* ��ƬCRCУ����� */
#define FM1702_EMPTY		3		/* ��ֵ������� */
#define FM1702_AUTHERR		4		/* ��֤���ɹ� */
#define FM1702_PARITYERR	5		/* ��Ƭ��żУ����� */
#define FM1702_CODEERR		6		/* ͨѶ����(BCCУ���) */
#define FM1702_SERNRERR		8		/* ��Ƭ���кŴ���(anti-collision ����) */
#define FM1702_SELECTERR	9		/* ��Ƭ���ݳ����ֽڴ���(SELECT����) */
#define FM1702_NOTAUTHERR	10		/* ��Ƭû��ͨ����֤ */
#define FM1702_BITCOUNTERR	11		/* �ӿ�Ƭ���յ���λ������ */
#define FM1702_BYTECOUNTERR	12		/* �ӿ�Ƭ���յ����ֽ����������������Ч */
#define FM1702_RESTERR		13		/* ����restore�������� */
#define FM1702_TRANSERR		14		/* ����transfer�������� */
#define FM1702_WRITEERR		15		/* ����write�������� */
#define FM1702_INCRERR		16		/* ����increment�������� */
#define FM1702_DECRERR		17		/* ����decrement�������� */
#define FM1702_READERR		18		/* ����read�������� */
#define FM1702_LOADKEYERR	19		/* ����LOADKEY�������� */
#define FM1702_FRAMINGERR	20		/* FM1702֡���� */
#define FM1702_REQERR		21		/* ����req�������� */
#define FM1702_SELERR		22		/* ����sel�������� */
#define FM1702_ANTICOLLERR	23		/* ����anticoll�������� */
#define FM1702_INTIVALERR	24		/* ���ó�ʼ���������� */
#define FM1702_READVALERR	25		/* ���ø߼�����ֵ�������� */
#define FM1702_DESELECTERR	26
#define FM1702_CMD_ERR		42		/* ������� */
/*********************************************************************
 * MACROS
 */
#define BEEP                     P0_0
  
#define SEND                     0x01
#define INCREASE                 0x02
#define REDUCE                   0x03  
/*********************************************************************
 * GLOBAL VARIABLES
 */
extern byte SerialApp_TaskID;

/*********************************************************************
 * FUNCTIONS
 */

/*
 * Task Initialization for the Serial Transfer Application
 */
extern void SerialApp_Init( byte task_id );

/*
 * Task Event Processor for the Serial Transfer Application
 */
extern UINT16 SerialApp_ProcessEvent( byte task_id, UINT16 events );

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif 
