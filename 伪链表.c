/*
Program's Author: Secant
Program's Name: Pseudo-Linked list
Program's Function: Add,delete,change,find the data in the list by nodes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
	int Vaule;
	struct Node* pNext;
};

void TraverseAllNodes(struct Node* pHead);
void PutDataBySubscript(struct Node* pNode);
void PutData(struct Node* pNode);
int RepeatedDataQuantity(struct Node* pHead, int data);
void RepeatedDataNode(struct Node* pHead, struct Node* Array[4], int data);
struct Node* FindByData(struct Node* pHead,int data);
struct Node* FindBySubscript(struct Node* pHead, int subscript);
struct Node* ChangeData(struct Node* pHead,int data,int change);

int main(void)
{
	struct Node num1 = { 3,NULL },
		num2 = { 5,NULL },
		num3 = { 9,NULL },
		num4 = { 11,NULL },
		AddHead = {1,NULL},		//Head
		AddBody = {7,&num3},		//Body
		AddTail = {13,NULL};		//Tail
	AddHead.pNext = &num1;		//how to add head
								/*	Before : num1 -> num2 -> num3 -> num4
								After : AddHead->num1->num2->AddBody->num3->num4->AddBody
								*/
	num1.pNext = &num2;						
	num2.pNext = &num3;
	num3.pNext = &num4;			
	num4.pNext = &AddTail;
	num2.pNext = &AddBody;		
	
	TraverseAllNodes(&AddHead);
	struct Node* Array[4] = { NULL };
	RepeatedDataNode(&num1,Array,9);
	for (int i = 0; i < 4 && Array[i] != NULL ; i++)
	{
		printf("%d ",Array[i]->Vaule);
	}
	printf("\n");
	//struct Node* pHead = &num1;			
	//printf("%d\n", num1.Vaule);
	//printf("%d\n", (&num1)->Vaule);
	//printf("%d\n", pHead->Vaule);
	//
	//printf("%d\n", num1.pNext->Vaule);
	//
	//printf("%d\n", num1.pNext->pNext->Vaule);
	//
	//printf("%d\n", num1.pNext->pNext->pNext->Vaule);		
	
	//while (pHead != NULL)			//�����������Ԫ��
	//{
	//    printf("%d\n",pHead->Vaule);
	//	pHead = pHead->pNext;
	//}
	
	
	struct Node* pData = FindByData(&AddHead,9);			//�ڵ������
	PutData(pData);
	pData = FindByData(&AddHead,7);
	PutData(pData);
	pData = ChangeData(&AddHead,6,7);
	TraverseAllNodes(&AddHead);
	pData = FindByData(&AddHead, 9);			//�ڵ������
	PutData(pData);
	pData = FindByData(&AddHead, 7);
	PutData(pData);
	struct Node* pSubscript = FindBySubscript(&AddHead, 0);			//�±�
	PutDataBySubscript(pSubscript);
	printf("��%d���ظ�������\n", RepeatedDataQuantity(&AddHead, 9));			//�������Ƿ��г��ֶ��
	
	
	system("pause");
	return 0;
}

void TraverseAllNodes(struct Node* pHead)
{
	while (pHead != NULL)			//�����������Ԫ��
	{
		printf("%d\n", pHead->Vaule);
		pHead = pHead->pNext;
	}
}

void PutDataBySubscript(struct Node* pNode) 
{
	if (NULL == pNode)
	{
		printf("�����ݲ�����\n");
	}
	else
	{
		printf("����ֵΪ%d������\n",pNode->Vaule);
	}
}

void PutData(struct Node* pNode)
{
	if (NULL == pNode)
	{
		printf("�����ݲ�����\n");
	}
	else
	{
		printf("����ֵΪ%d������\n", pNode->Vaule);
	}
}

int RepeatedDataQuantity(struct Node* pHead,int data)
{
	int cnt = 0;
	while (NULL != pHead)
	{
		if (pHead->Vaule == data)
		{
			cnt++;
		}
		pHead = pHead->pNext;
	}
	return cnt;
}

struct Node* FindByData(struct Node* pHead,int data) 
{
	while (pHead != NULL)
	{
		if (pHead->Vaule == data)
		{
			return pHead;
		}
		pHead = pHead->pNext;			//ָ����һ���ڵ�
	}
	return NULL;
}

struct Node* FindBySubscript(struct Node* pHead, int subscript)
{
	int num = 0;
	while (NULL != pHead)    
	{
		if (num == subscript)
		{
			return pHead;
		}
		num++;
		pHead = pHead->pNext;
	}
	return NULL;
}

void RepeatedDataNode(struct Node* pHead, struct Node* Array[4], int data)
{
	int subscript = 0;
	while (NULL != pHead)
	{
		if (data == pHead->Vaule)
		{
			Array[subscript++] = pHead;
		}
		pHead = pHead->pNext;
	}
}

struct Node* ChangeData(struct Node* pHead,int data,int change) 
{
	while (NULL != pHead)
	{
		if (pHead->Vaule == data)
		{
			pHead->Vaule = change;
		}
		pHead = pHead->pNext;
	}
}