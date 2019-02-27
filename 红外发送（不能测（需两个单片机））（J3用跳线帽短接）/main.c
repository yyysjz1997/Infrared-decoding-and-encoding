#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int
sbit out=P1^5;//����IO��

void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)		      //i=xms����ʱԼxms����
		for(j=112;j>0;j--);
}

void delay560us(void)	//560us�ӳٺ���
{
	uint j;
	for(j=63;j>0;j--);
}

void delay4500us(void)	   //4.5ms�ӳٺ���
{
  	uint j;
	for(j=516;j>0;j--);
}

void khz_2(uint num)		 //38KHZ���� ռ�ձ�1:2
{
    for(;num>0;num--)    //num�ǳ���ʱ��
	 {
//	  _nop_();
	  out=~out;
	 }
}

void send0_a(void)    //����0
{
   khz_2(42) ;   //0.56ms��38kHZ������
   //khz_3(21) ;
   out=1;
   delay560us();
}

void send1_a(void)		//����1
{
   khz_2(42) ;    //0.56ms��38kHZ������
   //khz_3(21) ;
   out=1;
   delay560us();
   delay560us();
   delay560us();
}

void leadcode_a(void)	//����������
{
     khz_2(690) ;     //9ms��38kHZ������
	 //	khz_2(345) ;
	 out=1;
   	 delay4500us();
	 //delay4500us();


}

const uchar TabHL1[12]={0x30,0x18,0x7a,0x10,0x38,0x5a,0x42,0x4a,0x52,0x00,0xff,0xa6};//���������1-9&2�ֽ��û���
const uchar TabHL2[12]={0xcf,0xe7,0x85,0xef,0xc7,0xa5,0xbd,0xb5,0xad,0xff,0x00,0x59};//���������1-9&2�ֽ��û���

void Send8Bit(uchar d)			  //����һ�ֽ�����
{
    if(d&0x80){	send1_a();}   //һλһλ���ж�
	else{		send0_a();}
	if(d&0x40){	send1_a();}
	else{		send0_a();}
	if(d&0x20){	send1_a();}
	else{		send0_a();}
	if(d&0x10){	send1_a();}
	else{		send0_a();}
	if(d&0x08){	send1_a();}
	else{		send0_a();}
	if(d&0x04){	send1_a();}
	else{		send0_a();}
	if(d&0x02){	send1_a();}
	else{		send0_a();}
	if(d&0x01){	send1_a();}
	else{		send0_a();}

}


void usercode_xuexiban()	  //�����û��� 00FF
{
     Send8Bit(TabHL1[9]);
	 Send8Bit(TabHL2[9]);
}

void xuexiban_1()	//00110000 		���͡�1����ȫ���ź�
 {
     leadcode_a();   //������
     usercode_xuexiban();   //�û���
     Send8Bit(TabHL1[0]);
	 Send8Bit(TabHL2[0]);//���ݷ��루У���ã���ֱ���õ�ԭ�룬��������򵥣������ȶ��Բ��ã�
	 //delay(1);
	 //khz_2(10) ;    //0.56ms��38kHZ������
 }

 void xuexiban_2()	//00011000
 {
     leadcode_a();
     usercode_xuexiban();
	 Send8Bit(TabHL1[1]);
	 Send8Bit(TabHL2[1]);
 }

 void xuexiban_3()	//01111010
 {
     leadcode_a();
     usercode_xuexiban();
	 Send8Bit(TabHL1[2]);
	 Send8Bit(TabHL2[2]);
 }

 void xuexiban_4()	//00010000
 {
     leadcode_a();
     usercode_xuexiban();
	 Send8Bit(TabHL1[3]);
	 Send8Bit(TabHL2[3]);
 }

 void xuexiban_5()	//00111000
 {
     leadcode_a();
     usercode_xuexiban();
	 Send8Bit(TabHL1[4]);
	 Send8Bit(TabHL2[4]);
 }

 void xuexiban_6()	//01011010
 {
     leadcode_a();
     usercode_xuexiban();
	 Send8Bit(TabHL1[5]);
	 Send8Bit(TabHL2[5]);
 }

 void xuexiban_7()	//01000010
 {
     leadcode_a();
     usercode_xuexiban();
	 Send8Bit(TabHL1[6]);
	 Send8Bit(TabHL2[6]);
 }

 void xuexiban_8()	//01001010
 {
     leadcode_a();
     usercode_xuexiban();
     Send8Bit(TabHL1[7]);
	 Send8Bit(TabHL2[7]);
 }

  void xuexiban_9()	//01010010
 {
     leadcode_a();
     usercode_xuexiban();
     Send8Bit(TabHL1[8]);
	 Send8Bit(TabHL2[8]);
 }

 void Remote_control()   //�������ͣ��������ǰ�Ÿ������ֱ���1-9
 {
    uchar temp;
 	P3 = 0xfe;
	temp = P3;
	temp = temp & 0xf0;
	if(temp != 0xf0)
	{
			delay(5);
			temp = P3;
			temp = temp & 0xf0;
			while(temp != 0xf0)
			{
				temp = P3;
				switch(temp)
				{
				 	case 0xee:xuexiban_1();
				 		break;
				 	case 0xde:xuexiban_2();
				 		break;
				 	case 0xbe:xuexiban_3();
				 		break;
				 	case 0x7e:xuexiban_4();
				 		break;
				}
				while (temp != 0xf0)
				{
					temp = P3;
					temp = temp & 0xf0;
				}
			}
	}

	P3 = 0xfd;
	temp = P3;
	temp = temp & 0xf0;
	if(temp != 0xf0)
	{
		delay(5);
		temp = P3;
		temp = temp & 0xf0;
		while(temp !=0xf0)
		{
			temp = P3;
			switch(temp)
			{
				 case 0xed:xuexiban_5();
				 	break;
				 case 0xdd:xuexiban_6();
				 	break;
				 case 0xbd:xuexiban_7();
				 	break;
				 case 0x7d:xuexiban_8();
				 	break;
			}
			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
		}
	}

	P3 = 0xfb;
	temp = P3;
	temp = temp & 0xf0;
	if(temp != 0xf0)
	{
		delay(5);
		temp = P3;
		temp = temp & 0xf0;
		while(temp !=0xf0)
		{
			temp = P3;
			switch(temp)
			{
				 case 0xeb:xuexiban_9();
				 	break;
			}
			while (temp != 0xf0)
			{
				temp = P3;
				temp = temp & 0xf0;
			}
		}
	}
 }

 void main()
 {
 	while(1)
	{
		Remote_control();
	}
 }

