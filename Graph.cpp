// Graph.cpp: implementation of the Graph class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Map.h"
#include "Graph.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Graph()
//////////////////////////////////////////////////////////////////////

Graph::Graph(){
}

Graph::~Graph(){
}

void Graph::InitLine(char stateName1[],char stateName2[],char name[],float distance,float time){
	int indexVn,indexEn;
	VextexNode *vNode;
	EdgeNode *eNode;
	PassList *pList;
	PassNode *pNode;
	indexVn=m_map.SearchLinkList(stateName1);
	if(indexVn==-1){//有没有该起点
		pNode=(PassNode *)malloc(sizeof(PassNode));
		strcpy(pNode->carName,name);
		pNode->distance=distance;
		pNode->time=time;

		pList=new PassList();
		pList->InsertLinkList(1,pNode);

		eNode=(EdgeNode *)malloc(sizeof(EdgeNode));
		strcpy(eNode->name,stateName2);
		eNode->passList=pList;

		vNode=new VextexNode();
		strcpy(vNode->name,stateName1);
		vNode->InsertLinkList(1,eNode);

		m_map.InsertLinkList(m_map.LenLinkList()+1,vNode);
	}
	else{
		vNode=m_map.GetfromLinkList(indexVn);
		indexEn=vNode->SearchLinkList(stateName2);
		if(indexEn==-1){//有没有该终点
			pNode=(PassNode *)malloc(sizeof(PassNode));
			strcpy(pNode->carName,name);
			pNode->distance=distance;
			pNode->time=time;
			
			pList=new PassList();
			pList->InsertLinkList(1,pNode);

			eNode=(EdgeNode *)malloc(sizeof(EdgeNode));
			strcpy(eNode->name,stateName2);
			eNode->passList=pList;

			vNode->InsertLinkList(vNode->LenLinkList()+1,eNode);
		}
		else{//添加新路线
			eNode=vNode->GetfromLinkList(indexEn);
			pList=eNode->passList;

			pNode=(PassNode *)malloc(sizeof(PassNode));
			strcpy(pNode->carName,name);
			pNode->distance=distance;
			pNode->time=time;

			pList->InsertLinkList(pList->LenLinkList()+1,pNode);
		}
	}
}

bool Graph::DelLine(char stateName1[],char stateName2[],char carName[]){
	int indexVn,indexEn;
	VextexNode *vNode;
	EdgeNode *eNode;
	PassList *pList;
	indexVn=m_map.SearchLinkList(stateName1);
	if(indexVn==-1){//有没有该起点
		return false;
	}
	else{
		vNode=m_map.GetfromLinkList(indexVn);
		indexEn=vNode->SearchLinkList(stateName2);
		if(indexEn==-1){//有没有该终点
			return false;
		}
		else{
			//删除新路线
			eNode=vNode->GetfromLinkList(indexEn);
			pList=eNode->passList;
			pList->DeleteLinkList(pList->SearchLinkList(carName));
			//删除终点
			if(pList->LenLinkList()==0)
				vNode->DeleteLinkList(indexEn);
			//删除起点
			if(vNode->LenLinkList()==0)
				m_map.DeleteLinkList(indexVn);
		}
	}
	return true;
}
//////////////////////////////////////////////////////////////////////
// PassList
//////////////////////////////////////////////////////////////////////
Graph::PassList::PassList()
{
	begin=false;
	CreateLinkList();
}

Graph::PassList::~PassList()
{

}

void Graph::PassList::Init()
{
	begin=false;
	CreateLinkList();
}
void Graph::PassList::CreateLinkList()
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
		head=(PassNode *)malloc(sizeof(PassNode));  
		head->next=NULL;
	}
}

int Graph::PassList::LenLinkList()  //求表长
{
	int n=0;
	int z=1;
    PassNode *p=head;
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

bool Graph::PassList::InsertLinkList(int i,PassNode* x)
{
    PassNode *p=head,*s;
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
			s=x;
            s->next=p->next;
            p->next=s;
            p=s;
	        return true;
        }
        p=p->next;
        index++;
	}
	return false;
}

void Graph::PassList::DeleteLinkList(int i) //删除第i个元素
{
    PassNode *p=head,*s;
    int index=1; 
    int length=LenLinkList();
    if( i<1 || i>(length))
    {
	    return;
    }
	while(1)
	{
		if(p->next!=NULL)
			return;
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

int Graph::PassList::SearchLinkList(char x[])
{
    PassNode *p=head;
    int index=0;
    int length=LenLinkList();
	while(1)
	{
        if(!strcmp(p->carName,x))
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


Graph::PassNode* Graph::PassList::GetfromLinkList(int i)
{
    PassNode *p=head;
    int index=0;
    int length=LenLinkList();
    if( i<1 || i>length)
    {
		return p;
    }
	while(1)
	{
        if(index==i)
        {
            return p;
        }
        p=p->next;
        index++;
	}
	return NULL;
}


//////////////////////////////////////////////////////////////////////
// VextexNode表头结点
//////////////////////////////////////////////////////////////////////
Graph::VextexNode::VextexNode()
{
	begin=false;
	CreateLinkList();
}

Graph::VextexNode::~VextexNode()
{

}

void Graph::VextexNode::Init()
{
	begin=false;
	CreateLinkList();
}
void Graph::VextexNode::CreateLinkList()
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
		head=(EdgeNode *)malloc(sizeof(EdgeNode));  
		head->next=NULL;
	}
}

int Graph::VextexNode::LenLinkList()  //求表长
{
	int n=0;
	int z=1;
    EdgeNode *p=head;
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

bool Graph::VextexNode::InsertLinkList(int i,EdgeNode* x)
{
    EdgeNode *p=head,*s;
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
			s=x;
            s->next=p->next;
            p->next=s;
            p=s;
	        return true;
        }
        p=p->next;
        index++;
	}
	return false;
}

void Graph::VextexNode::DeleteLinkList(int i) //删除第i个元素
{
    EdgeNode *p=head,*s;
    int index=1; 
    int length=LenLinkList();
    if( i<1 || i>(length))
    {
	    return;
    }
	while(1)
	{
		if(p->next!=NULL)
			return;
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

int Graph::VextexNode::SearchLinkList(char x[])
{
    EdgeNode *p=head;
    int index=0;
    int length=LenLinkList();
	while(1)
	{
        if(!strcmp(p->name,x))
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


Graph::EdgeNode* Graph::VextexNode::GetfromLinkList(int i)
{
    EdgeNode *p=head;
    int index=0;
    int length=LenLinkList();
    if( i<1 || i>length)
    {
		return NULL;
    }
	while(1)
	{
        if(index==i)
        {
            return p;
        }
        p=p->next;
        index++;
	}
	return NULL;
}

//////////////////////////////////////////////////////////////////////
// AdjList
//////////////////////////////////////////////////////////////////////
Graph::AdjList::AdjList()
{
	begin=false;
	CreateLinkList();
}

Graph::AdjList::~AdjList()
{

}

void Graph::AdjList::Init()
{
	begin=false;
	CreateLinkList();
}
void Graph::AdjList::CreateLinkList()
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
		head=(VextexNode *)malloc(sizeof(VextexNode));  
		head->next=NULL;
	}
}

int Graph::AdjList::LenLinkList()  //求表长
{
	int n=0;
	int z=1;
    VextexNode *p=head;
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

bool Graph::AdjList::InsertLinkList(int i,VextexNode* x)
{
    VextexNode *p=head,*s;
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
			s=x;
            s->next=p->next;
            p->next=s;
            p=s;
	        return true;
        }
        p=p->next;
        index++;
	}
	return false;
}

void Graph::AdjList::DeleteLinkList(int i) //删除第i个元素
{
    VextexNode *p=head,*s;
    int index=1; 
    int length=LenLinkList();
    if( i<1 || i>(length))
    {
	    return;
    }
	while(1)
	{
		if(p->next!=NULL)
			return;
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

int Graph::AdjList::SearchLinkList(char x[])
{
    VextexNode *p=head;
    int index=0;
    int length=LenLinkList();
	while(1)
	{
        if(!strcmp(p->name,x))
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


Graph::VextexNode* Graph::AdjList::GetfromLinkList(int i)
{
    VextexNode *p=head;
    int index=0;
    int length=LenLinkList();
    if( i<1 || i>length)
    {
		return NULL;
    }
	while(1)
	{
        if(index==i)
        {
            return p;
        }
        p=p->next;
        index++;
	}
	return NULL;
}

bool Graph::AdjList::IsLineOpen(int i,int j){
	VextexNode* vn;
	EdgeNode *en;
	vn=GetfromLinkList(i);
	if(vn==NULL)
		return false;
	en=vn->GetfromLinkList(j);
	if(en==NULL)
		return false;
	return true;
}