#include <stdio.h>

//֡��ʽ
/*
SOH     ��Ϣ������   ��Ϣ�����еķ���  ��������  ����У���
1���ֽ� 1���ֽ�      1���ֽ�           128�ֽ�   1�ֽ�
*/
struct xmodem
{
	char soh;
	char mesgseq;
	char revmesg;
	char data[128];
	char check;

} xmodem_mesg;
