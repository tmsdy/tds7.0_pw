// tds_pw.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "malloc.h"

unsigned char *
tds7_decrypt_pass(const unsigned char *crypt_pass, int len, unsigned char *clear_pass)
{
	int i;
	const unsigned char xormask = 0x5A;
	unsigned char hi_nibble, lo_nibble;

	for (i = 0; i < len; i++) {
		printf("%c is ", clear_pass[i] );
		lo_nibble = (crypt_pass[i] << 4) ^ (xormask & 0xF0);   
		hi_nibble = (crypt_pass[i] >> 4) ^ (xormask & 0x0F);  
		clear_pass[i] = hi_nibble | lo_nibble;
		printf("0x %02X \n",(int)clear_pass[i] );
	}
	return clear_pass;
}




int _tmain(int argc, _TCHAR* argv[])
{
	size_t unicode_len, password_len;
	unsigned char  unicode_string ='0';
	//char *unicode_string = &a;
	unsigned char  charter ='0';
	unicode_len =  1;
	//unicode_string = (char *) malloc(unicode_len);
	int i = 0;
	for(;i<128;i++)
	{	

		charter = unsigned char((int)charter + 1);
		unicode_string = charter;
		//printf("the %d time  unicode_string is  %c    \n",i,unicode_string);
		tds7_decrypt_pass((unsigned char *) &unicode_string, unicode_len, (unsigned char *) &unicode_string);
	}

	//printf("%c is 0x%h \n",*unicode_string, );
	
	getchar();  

	return 0;
}

