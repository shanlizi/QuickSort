

//C++  快速排序
void run(int *pData,int left,int reght)
{
	int i,j;
	int middle,iTemp;
	i=left;
	j=right;
	middle = pData[(left+right)/2]; //求中间值
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
			i++;
			j--;
		}
	}while(i<=j);

	if(left<i)
		run(pData,left,j);
	if(right>i)
		run(pData,i,right);
}
void QuickSort(int *pData,int count)
{
	run(pData,0,count-1);
}