// StateList.cpp: implementation of the StateList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Map.h"
#include "StateList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// StateList
//////////////////////////////////////////////////////////////////////
StateList::State& StateList::State::operator=(const State& rhs)
{
	strcpy(name,rhs.name);
	carNum=rhs.carNum;
	carPass=rhs.carPass;
	return *this;
}
StateList::StateList(){
	begin=false;
	CreateLinkList();
}

StateList::~StateList(){
}

void StateList::CreateLinkList(){
	//删除之前节点（防止内存泄漏）
	if(begin)
		while(head->next!=NULL)
		{
			DeleteLinkList(1);
		}
	begin=true;
	head=(LNode *)malloc(sizeof(LNode));  
	head->next=NULL;
}

int StateList::LenLinkList(){
	int n=0;
	LNode *p=head;
	int z=1;
	while(1)
	{
		if(p->next!=NULL)
		{
			p=p->next;
			n++;
		}
		else
			break;
	}
	return n;
}
bool StateList::InsertLinkList(int i,State* x){
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
			s->data.carPass.Init();
			s->data=*x;
            s->next=p->next;
            p->next=s;
            p=s;
	        return true;
        }
        p=p->next;
        index++;
	}
}
void StateList::DeleteLinkList(int i){
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
int StateList::SearchLinkList(State* x)
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
	if (length==0) return -1;
	while(1)
	{
        if(!strcmp(p->data.name,x->name))
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
	return -1;
}

int StateList::SearchLinkList(char x[])
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
	if (length==0) return -1;
	while(1)
	{
        p=p->next;
        index++;
        if(index>length)
        {
            return -1;
        }
        if(!strcmp(p->data.name,x))
        {
            return index;
        }
	}
	return -1;
}
StateList::State* StateList::GetfromLinkList(int i)
{
    LNode *p=head;
    int index=0;
    int length=LenLinkList();
    if( i<1 || i>length)
    {
		return &p->data;
    }
	while(1)
	{
        if(index==i)
        {
            return &p->data;
        }
        p=p->next;
        index++;
	}
	return NULL;
}

void StateList::InitState(char stateName[],char carName[]){
	int index;
	State *state;
	index=SearchLinkList(stateName);
	if(index==-1){//新建
		state=(State*)malloc(sizeof(State));	
		strcpy(state->name,stateName);
		state->carNum=0;
		state->carPass.Init();
		state->carPass.InsertLinkList(1,carName);
		state->carNum++;
		InsertLinkList(LenLinkList()+1,state);
	}
	else{
		state=GetfromLinkList(index);
		state->carNum++;
		state->carPass.InsertLinkList(state->carPass.LenLinkList()+1,carName);
	}
}

bool StateList::DelState(char stateName[],char carName[]){
	int index=SearchLinkList(stateName);
	State *state;
	NameList *carPass;	
	printf("%s %s\n",stateName,carName);
	if(index==-1){
		return false;
	}
	else{
		state=GetfromLinkList(index);
		carPass=&(state->carPass);
		if(!carPass->DeleteLinkList(carName))
			return false;
		state->carNum--;
		if(state->carNum==0)
			DeleteLinkList(index);
	}
	return true;
}