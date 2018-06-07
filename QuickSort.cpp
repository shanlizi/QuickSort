

//C++  ¿ìËÙÅÅÐò
void run(int *pData,int left,int right)
{
	int i,j;
	int middle,iTemp;
	i=left;
	j=right;
	middle = pData[(left+right)/2]; //ÇóÖÐ¼äÖµ
	do
	{
		while((pData[i]<middle) && (i<right))
			i++:
		while((pData[j]>middle) && (j>left))
			j--;
		if(i<j)
		{
			iTemp=pData[i];
			pData[i]=pData[j];
			pData[j]=iTemp;	
		}
		i++;
		j--;
	}while(i<=j);

	if(left<j)
		run(pData,left,j);
	if(right>i)
		run(pData,i,right);
}
void QuickSort(int *pData,int count)
{
	run(pData,0,count-1);
}
