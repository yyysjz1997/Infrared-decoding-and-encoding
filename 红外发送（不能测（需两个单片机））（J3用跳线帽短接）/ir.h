	   
#define GET_TIME_MS   (gl_time_100us)

/*NECЭ��  �����룬8λ�Ŀͻ��룬8λ�ͻ���Ĳ��룬8λ�İ���ֵ��8λ����ֵ�Ĳ���*/
//�ɲο� http://www.cnblogs.com/openusb/archive/2010/01/07/1641357.html ��comment by TPX)
 
/*ʱ��궨��*/
/*
#define INFRARED_WAIT    0 //�½��ش��� ���µ�ǰʱ�� ֱ�ӽ�����һ�׶�
#define INFRARED_ACTIVE  1 //�ȴ���������������ص���ʱ��ʱΪ9ms�������һ�׶�  ����Ϊ�����ź� ����WAIT
#define INFRARED_START   2 //�ȴ��½�������½��ص���ʱ��ʱΪ4.5ms����ʽ��ʼ����   �����2.25ms ���ж�������Ľ�����ɵ�ʱ�̵�ʱ����Ƿ�С��һ��ֵ��40ms ��������Ϊ��һ���������� ���´˽�����ɴ�����������ʱ�� ���Ҫ������һ����ת��COUTINUE_WAIT  ����ת��COUTINUE  ����Ϊ�����ź�
*/
//ע�����ڸ�λʱ�����һ���жϣ����Գ�ʼ״̬����INFRARED_ACTIVE�����������յ���һ�������ź�ͷ���½���ʱ���жϲ���������������INFRARED_WAIT��������9ms��һ�������ص���ʱ�����봦��INFRARED_WAIT״̬��������9ms�������룬�������ڻ����������źŶ���ż�������أ�����ÿ���ź������뵽��ʱ���򶼴���INFRARED_ACTIVE��������Զ�޷�������루Ȼ��������㹻�������������п������ɽ��룩
//Ϊ�˱������������INFRARED_WAIT��INFRARED_ACTIVE�ϲ�Ϊһ��״̬�޸ĺ�����

#define INFRARED_WAIT    0 //˫���ش���  ������δ���ʱ�����ϴδ���ʱ����Ϊ9ms�����������ʶ�� ������µ�ǰʱ�̲��˳�
#define INFRARED_ACTIVE  1 //�ȴ��½�������½��ص���ʱ��ʱΪ4.5ms����ʽ��ʼ����   �����2.25ms ���ж�������Ľ�����ɵ�ʱ�̵�ʱ����Ƿ�С��һ��ֵ��40ms ��������Ϊ��һ���������� ���´˽�����ɴ�����������ʱ�� ���Ҫ������һ����ת��COUTINUE_WAIT  ����ת��COUTINUE  ����Ϊ�����ź�

#define INFRARED_DECODE1 3 //�ȴ������ؼ�ʱ �����ص���ʱ�����ʱΪ0.56ms�������һ����׶�  �������
#define INFRARED_DECODE2 4 //�ȴ��½��ؼ�ʱ �½��ص���ʱ�����ʱΪ0.56ms ��Ϊ0  �����1.68ms��Ϊ1 �������  �ж�����������򱣴����� ���ж��Ƿ񵽴�32λ ���������һ�׶� ���򷵻�DECODE1
#define INFRARED_CHECK     5 //�ȴ�������   У������ �����ȷ����±��ν�����ɿ̣������ص���ʱ��ʱ���Ϊ0.56ms����ȷ  ����WAIT    ��������������̿��ܳ���  ��NEC upd6121 �����ʽ�в�û�ж��ⲿ�ֵĹ涨��

#define COUTINUE_WAIT     6  //�ȴ��½���  ����ǰʱ��  �������һ�������������յ���ʱ��ԼΪ108-9-2.25-0.56=98ms������������Ч������һ�׶� �������������ͷ�  ����WAIT
#define CONTINUE_ACTIVE   7  //�ȴ���������������ص���ʱ��ʱΪ9ms�������һ�׶�   ����Ϊ�����ź� ����WAIT
#define CONTINUE_START    8  //�ȴ��½�������½��ص���ʱ��ʱΪ2.25ms  ȷ����Ч  ת����һ�׶�  ���򷵻�wait 
#define CONTINUE_CONFIRM  9  //�ȴ������� ȷ��һ���������� ���µ�ǰʱ�� ת����һ�����������ȴ�COUTINUE_WAIT�������ص���ʱ��ʱ���Ϊ0.56ms����ȷ ��NEC upd6121 �����ʽ�в�û�ж��ⲿ�ֵĹ涨��
#define CONTINUE_END1     10 //
#define CONTINUE_END2     11 //

#define BOOT_CODE_TIME1_MIN   85//9ms ��λ0.1ms
#define BOOT_CODE_TIME1_MAX   95
#define BOOT_CODE_TIME2_MIN   40//4.5ms
#define BOOT_CODE_TIME2_MAX   50
#define DATA_SHORT_TIME_MIN   1 //0.56ms
#define DATA_SHORT_TIME_MAX   8 //11
#define DATA_LONG_TIME_MIN    9//12//1.68ms
#define DATA_LONG_TIME_MAX    22 

#define FIRST_COUTINUE_TIME_MIN   510//45+9+2.25ms  ʵ��516   
#define FIRST_COUTINUE_TIME_MAX   520//45ms   
#define COUTINUE_TIME_MIN     968//98ms   ʵ��973����
#define COUTINUE_TIME_MAX     978
#define COUTINUE_BOOT_TIME_MIN 20//2.25ms
#define COUTINUE_BOOT_TIME_MAX 25

#define COUTINUE_NEXT_MIN     600//76-9-2.25-0.56=64.19ms   ʵ��632-642   ����һ�����ڲ�ͬ�������ϴ�  ����960-968֮��
#define COUTINUE_NEXT_MAX     968
#define COUTINUE_TIME_NUM     9

#define COUTINUE_TIME_THRESHOLD 5//����ʱ���趨 (0-9)     0 ���жϳ���  1����ʱ���趨Ϊ ԼԼ85.74+40+9+2.25+0.56=137.55ms   -  49.9++40+9+2.25+0.56=101.71ms  �Ժ�ÿ��һ����108ms
