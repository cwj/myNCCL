#include <stdio.h>

//帧格式
/*
SOH     信息包序列   信息包序列的反码  数据区段  算术校验和
1个字节 1个字节      1个字节           128字节   1字节
*/
struct xmodem
{
	char soh;
	char mesgseq;
	char revmesg;
	char data[128];
	char check;

} xmodem_mesg;
