/*************************************************
Function:       void Field( char* InputSentence,char *OutBuf,UINT16 desired_field_number )

Description:    ������ȡ
Calls:          

Called By:     

Input:         
Output:         ��
Return:         ��
Others:         // ����˵��
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

	//�ҵ���Ҫ��ȡ�Ĳ���λ��
	while( current_field_number < desired_field_number && index < string_length )
	{
		// �ж��ֶηָ�����У��Ͷ����
		if ( InputSentence[ index ] == ',' || InputSentence[ index ] == '*' )
		{
			current_field_number++;
		}
		index++;
	}

	//��ȡ�����ֶ�
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