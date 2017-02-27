/*************************************************
Function:       void Field( char* InputSentence,char *OutBuf,UINT16 desired_field_number )

Description:    参数提取
Calls:          

Called By:     

Input:         
Output:         无
Return:         无
Others:         // 其它说明
*************************************************/ 

#define UART_RECV_FIELD_LENTH 512
UINT16 CComCommunicate::Field( char* InputSentence,char *OutBuf,UINT16 desired_field_number,bool bMSG )
{
	UINT16 index                = 1; 
	UINT16 index1               = 0;
	UINT16 current_field_number = 0;
	UINT16 string_length        = strlen(InputSentence);
	char return_string[UART_RECV_FIELD_LENTH] = {0};

	memset (OutBuf, 0, UART_RECV_FIELD_LENTH);

	//找到想要提取的参数位置
	while( current_field_number < desired_field_number && index < string_length )
	{
		// 判断字段分隔符及校验和定界符
		if ( InputSentence[ index ] == ',' || InputSentence[ index ] == '*' )
		{
			current_field_number++;
		}
		index++;
	}

	//提取参数字段
	if ( current_field_number == desired_field_number )
	{
		if (bMSG)
		{
			while( index < string_length      &&
				InputSentence[ index ] != '*' &&
				InputSentence[ index ] != 0x00 )
			{
				if(index1 >= UART_RECV_FIELD_LENTH)
				{
					return 0 ;
				}
				return_string[index1]= InputSentence[ index ];
				index++;
				index1++;
			}
		}
		else
		{

			while( index < string_length      &&
				InputSentence[ index ] != ',' &&
				InputSentence[ index ] != '*' &&
				InputSentence[ index ] != 0x00 )
			{
				if(index1 >= UART_RECV_FIELD_LENTH)
				{
					return 0 ;
				}
				return_string[index1]= InputSentence[ index ];
				index++;
				index1++;
			}
		}
	}

	memcpy(OutBuf,return_string,index1);
	return index1;
}