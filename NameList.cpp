// NameList.cpp: implementation of the NameList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Map.h"
#include "NameList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameList::NameList()
{
	begin=false;
	CreatLinkList();
}

NameList::~NameList()
{

}
void NameList::Init()
{
	begin=false;
	CreatLinkList();
}
void NameList::CreatLinkList()
{
	//删除之前节点（防止内存泄漏）
	if(begin){
        while(head->next!=NULL)
        {
            DeleteLinkList(1);
        }
	}
	else{
		begin=true;
		head=(LNode *)malloc(sizeof(LNode));  
		head->next=NULL;
	}
}

int NameList::LenLinkList()  //求表长
{
	int n=0;
	int z=1;
    LNode *p=head;
	while(1)
	{
	    if(p->next!=NULL)
        {
			p=p->next;
			n++;
        }
        else
			return n;
	}
	return n;
}

bool NameList::InsertLinkList(int i,char x[])
{
    LNode *p=head,*s;
    int index=1;
    int length=LenLinkList();
    if( i<1 || i>(length+1))
    {
	    return false;
    }
	while(1)
	{
        if(i==index)
        {
            s=(LNode *)malloc(sizeof(LNode));
			strcpy(s->data,x);
            s->next=p->next;
            p->next=s;
	        return true;
        }
        p=p->next;
        index++;
	}
	return false;
}

void NameList::DeleteLinkList(int i) //删除第i个元素
{
    LNode *p=head,*s;
    int index=1; 
    int length=LenLinkList();
    if( i<1 || i>(length))
    {
	    return;
    }
	while(1)
	{
        if(i==index)
        {
            s=p->next;
            p->next=s->next;
            free(s);
	        return;
        }
        p=p->next;
        index++;
	}
}
bool NameList::DeleteLinkList(DataType x) //删除
{
    LNode *p=head;
    int index=this->SearchLinkList(x);
	if(index==-1)
		return false;
	DeleteLinkList(index);
	return true;
}

int NameList::SearchLinkList(DataType x)
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
	while(1)
	{
        if(!strcmp(p->data,x))
        {
            return index;
        }
        p=p->next;
        index++;
        if(index>length)
        {
            return -1;
        }
	}
}


void NameList::GetfromLinkList(int i,char x[])
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
    if( i<1 || i>length)
    {
		strcpy(x,NULL);
        return;
    }
	if(p->next==NULL)
		return;
	while(1)
	{
        if(index==i)
        {
			strcpy(x,p->data);
            return;
        }
        p=p->next;
        index++;
	}
}


NameList& NameList::operator=(const NameList &rhs)
{
	int index=0;
    LNode *p=rhs.head;
	CreatLinkList();
	while(p->next)
	{
        p=p->next;
		index++;
		InsertLinkList(LenLinkList()+1,p->data);
	}
	return *this;
}
