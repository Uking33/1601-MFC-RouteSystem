// Data.cpp: implementation of the Data class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Map.h"
#include "Data.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// LineList
//////////////////////////////////////////////////////////////////////
LineList::LineList(Data* data){
	m_data=data;
	begin=false;
	CreateLinkList();
}

LineList::~LineList(){
}

void LineList::CreateLinkList(){
	//ɾ��֮ǰ�ڵ㣨��ֹ�ڴ�й©��
	if(begin)
		while(head->next!=NULL)
		{
			DeleteLinkList(1);
		}
	begin=true;
	head=(LineNode *)malloc(sizeof(LineNode)); 
	head->next=NULL;
	head->last=NULL;
}

int LineList::LenLinkList(){
	int n=0;
	LineNode *p=head;
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
bool LineList::InsertLinkList(int i,LineNode* x){
    LineNode *p=head,*s;
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
			//copy������·������
			s=(LineNode *)malloc(sizeof(LineNode));
			s->line=new NameList();
			s->carName=new NameList();
			*s=*x;
            s->next=p->next;
			s->last=p;
            p->next=s;
			if(s->next!=NULL)
				s->next->last=s;
            p=s;
	        return true;
        }
        p=p->next;
        index++;
	}
}
void LineList::DeleteLinkList(int i){
	LineNode *p=head,*s;
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
			if(p->next!=NULL)
				p->next->last=p;
			free(s);
			return;
		}
		p=p->next;
		index++;
	}
}
bool LineList::SwapLinkList(LineNode* x1,LineNode* x2){
    LineNode *p;
	p=x1->next;
	x1->next=x2->next;
	if(x1->next!=NULL)
		x1->next->last=x1;
	if(x2->next!=NULL)
		x2->next=p;
	if(p!=NULL)
		p->last=x2;

	p=x1->last;
	x1->last=x2->last;
	x1->last->next=x1;
	x2->last=p;
	p->next=x2;
	return true;
}

LineList::LineNode* LineList::GetfromLinkList(int i)
{
    LineNode *p=head;
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

LineList::LineNode& LineList::LineNode::operator=(const LineNode& rhs)
{
	time=rhs.time;
	cost=rhs.cost;
	distance=rhs.distance;
	busNum=rhs.busNum;
	subNum=rhs.subNum;
	turnNum=rhs.turnNum;
	*line=*rhs.line;
	*carName=*rhs.carName;
	return *this;
}

void LineList::LineSort(int c1,int c2){
    int i,j,n;
	int max,maxI;
	n=this->LenLinkList();
	switch(c1){
		case 0:		
			LineSort2(c2,0);
			break;
		case 1:
			for(i=1;i<=n-1;i++)
			{
				max=i;
				maxI=this->GetfromLinkList(i)->busNum-this->GetfromLinkList(i)->subNum;
				for(j=i+1;j<=n;j++)
					if(maxI<this->GetfromLinkList(j)->busNum-this->GetfromLinkList(j)->subNum){
						max=j;
						maxI=this->GetfromLinkList(j)->busNum-this->GetfromLinkList(j)->subNum;
					}
				if(max!=i)
				{
					SwapLinkList(this->GetfromLinkList(max),this->GetfromLinkList(i));
				}
			}
			LineSort2(c2,1);
			break;
		case 2:
			for(i=1;i<=n-1;i++)
			{
				max=i;
				maxI=this->GetfromLinkList(i)->subNum-this->GetfromLinkList(i)->busNum;
				for(j=i+1;j<=n;j++)
					if(maxI<this->GetfromLinkList(j)->subNum-this->GetfromLinkList(j)->busNum){
						max=j;
						maxI=this->GetfromLinkList(j)->subNum-this->GetfromLinkList(j)->busNum;
					}
				
				if(max!=i)
				{
					SwapLinkList(this->GetfromLinkList(max),this->GetfromLinkList(i));
				}
			}
			LineSort2(c2,2);
			break;
	}
}
void LineList::LineSort2(int c2,int type){
    int i,j,n,n1;
	int min,minI;
	float minF;
	n=this->LenLinkList();
	switch(type){
		case 0:
			n1=1;
			break;
		case 1:
			for(n1=1;n1<=n;n1++)
				if(this->GetfromLinkList(n1)->busNum<=this->GetfromLinkList(n1)->subNum)
					break;
			break;
		case 2:
			for(n1=1;n1<=n;n1++)
				if(this->GetfromLinkList(n1)->subNum<=this->GetfromLinkList(n1)->busNum)
					break;
			break;
	}
	//��һ������
	if(n1>1 && n1<n){
		switch(c2){
		case 0:
			for(i=1;i<n1-1;i++)
			{
				min=i;
				minI=this->GetfromLinkList(i)->turnNum;
				for(j=i+1;j<n1;j++)
					if(minI>this->GetfromLinkList(j)->turnNum){
						min=j;
						minI=this->GetfromLinkList(j)->turnNum;
					}
				if(min!=i)
					SwapLinkList(this->GetfromLinkList(min),this->GetfromLinkList(i));
			}
			break;
		case 1:
			for(i=1;i<n1-1;i++)
			{
				min=i;
				minF=this->GetfromLinkList(i)->time;
				for(j=i+1;j<n1;j++)
					if(minF>this->GetfromLinkList(j)->time){
						min=j;
						minF=this->GetfromLinkList(j)->time;
					}
				if(min!=i)
					SwapLinkList(this->GetfromLinkList(min),this->GetfromLinkList(i));
			}
			break;
		case 2:
			for(i=1;i<n1-1;i++)
			{
				min=i;
				minF=this->GetfromLinkList(i)->cost;
				for(j=i+1;j<n1;j++)
					if(minF>this->GetfromLinkList(j)->cost){
						min=j;
						minF=this->GetfromLinkList(j)->cost;
					}
				if(min!=i)
					SwapLinkList(this->GetfromLinkList(min),this->GetfromLinkList(i));
			}
			break;
		}
	}
	//�ڶ�������
	switch(c2){
		case 0:
			for(i=n1;i<=n-1;i++)
			{
				min=i;
				minI=this->GetfromLinkList(i)->turnNum;
				for(j=i+1;j<=n;j++)
					if(minI>this->GetfromLinkList(j)->turnNum){
						min=j;
						minI=this->GetfromLinkList(j)->turnNum;
					}
				if(min!=i)
					SwapLinkList(this->GetfromLinkList(min),this->GetfromLinkList(i));
			}
			break;
		case 1:
			for(i=n1;i<=n-1;i++)
			{
				min=i;
				minF=this->GetfromLinkList(i)->time;
				for(j=i+1;j<=n;j++)
					if(minF>this->GetfromLinkList(j)->time){
						min=j;
						minF=this->GetfromLinkList(j)->time;
					}
				if(min!=i)
					SwapLinkList(this->GetfromLinkList(min),this->GetfromLinkList(i));
			}
			break;
		case 2:
			for(i=n1;i<=n-1;i++)
			{
				min=i;
				minF=this->GetfromLinkList(i)->cost;
				for(j=i+1;j<=n;j++)
					if(minF>this->GetfromLinkList(j)->cost){
						min=j;
						minF=this->GetfromLinkList(j)->cost;
					}
				if(min!=i)
					SwapLinkList(this->GetfromLinkList(min),this->GetfromLinkList(i));
			}
			break;
	}
}

bool LineList::GetLine(char start[],char end[])
{
	LineNode *path;
	strcpy(m_start,start);
	strcpy(m_end,end);
	
	this->CreateLinkList();

    path=new LineNode();
	path->next=NULL;
	path->last=NULL;
	path->line=new NameList();
	path->carName=new NameList();
	path->time=0;
	path->distance=0;
	path->cost=0;
	path->busNum=0;
	path->subNum=0;
	path->turnNum=0;

	DFSM(&m_data->m_graph.m_map,
		start,
		start,
		m_data->m_graph.m_map.SearchLinkList(start),
		path,"");
	delete path;
	return true;
}
void LineList::DFSM (Graph::AdjList* G,char before[],char now[],int k,LineNode* path,char name[]){
	int i,j;
	int x,y;
	float time;
	float cost;
	float distance;
	int busNum;
	int subNum;
	int turnNum;
	char carName[50];
	Graph::VextexNode* vNode;
	Graph::EdgeNode* eNode;
	//�ڵ��ʼ��
	if(!strcmp(now,m_start)){
		strcpy(carName,"");
		time=0;
		distance=0;
		cost=0;
		busNum=0;
		subNum=0;
		turnNum=0;
		i=1;
	}
	else{
		i=G->SearchLinkList(before);
		j=G->GetfromLinkList(i)->SearchLinkList(now);
		strcpy(carName,G->GetfromLinkList(i)->GetfromLinkList(j)->passList->GetfromLinkList(k)->carName);
		time=G->GetfromLinkList(i)->GetfromLinkList(j)->passList->GetfromLinkList(k)->time;
		distance=G->GetfromLinkList(i)->GetfromLinkList(j)->passList->GetfromLinkList(k)->distance;
		cost=0;
		busNum=0;
		subNum=0;
		turnNum=0;
		if(strcmp(carName,name)){//����
			turnNum=1;
			//���ҳ���ȡ����
			for(x=0;x<m_data->GetCarNum();x++){
				if(!strcmp(carName,m_data->car[x].name)){
					if(m_data->car[x].type==sub)
						subNum=1;
					else if(m_data->car[x].type==bus)
						busNum=1;
					cost=m_data->car[x].costCount;
					break;
				}
			}
		}

		path->time+=time;
		path->distance+=distance;
		path->cost+=cost;
		path->busNum+=busNum;
		path->subNum+=subNum;
		path->turnNum+=turnNum;
	}
	//���뵽·��
	j=G->SearchLinkList(now);
	vNode=G->GetfromLinkList(j);
	path->carName->InsertLinkList(path->carName->LenLinkList()+1,carName);
	path->line->InsertLinkList(path->line->LenLinkList()+1,vNode->name);
	//�����յ�
	if(!strcmp(vNode->name,m_end)){
		InsertLinkList(LenLinkList()+1,path);//copy������·������
	}
	//��һ�ڵ�
	else {
		for (x=1; x<=vNode->LenLinkList(); x++){
			if(strcmp(vNode->GetfromLinkList(x)->name,G->GetfromLinkList(i)->name)){
				eNode=vNode->GetfromLinkList(x);
				if (path->line->SearchLinkList(eNode->name)==-1)//����ͨ·�Ҳ���·����G->IsLineOpen(j,x)
					for(y=1;y<=eNode->passList->LenLinkList();y++)//���������·��
					{
						//i=G->SearchLinkList(now);
						//j=G->GetfromLinkList(i)->SearchLinkList(eNode->name);
						if(path->turnNum<3 || (path->turnNum==3 && !strcmp(eNode->passList->GetfromLinkList(y)->carName,carName)))//�����λ��˲��߸�·��
							DFSM(G,now,eNode->name,y,path,carName);
					}
			}
		}
	}
	//ɾ���ڵ�
	path->line->DeleteLinkList(path->line->LenLinkList());
	path->carName->DeleteLinkList(path->carName->LenLinkList());
	//�ӽڵ�����
	path->time-=time;
	path->distance-=distance;
	path->cost-=cost;
	path->busNum-=busNum;
	path->subNum-=subNum;
	path->turnNum-=turnNum;
}
//////////////////////////////////////////////////////////////////////
// Data
//////////////////////////////////////////////////////////////////////

Data::Data()
{
}

Data::~Data()
{

}

/*��·ͼ�ĳ�ʼ��*/
void Data::Load(){
	FILE *fp;
	char ch;

	char type[10],name[50],stateLine[1000];
	float costCount, start, end;
	int stateCount, twoway;

	fp=fopen(PATH,"r+");
	if(fp==NULL)
	{
		fp=fopen(PATH,"w+");
		if(fp==NULL)
		{
			printf("can not open '%s'",PATH);
			exit(1);
		}
	}
	else
	{
		ch=fgetc(fp);
		if(ch!=EOF)
		{
			fseek(fp,0,SEEK_SET);
			CarNum=0;
			while(!feof(fp))
			{
				fscanf(fp,"%s %s %f %f %d %d %f %s\n",type,name,&start,&end,&stateCount,&twoway,&costCount,stateLine);
				CarNum++;
				Init(CarNum-1,type,name,stateLine,costCount,start,end,stateCount,twoway);
			}
		}
	}
	fclose(fp);
	line=new LineList(this);
	return;
	

}

bool Data::Save(){
	FILE *fp;
	fp=fopen(PATH,"w+");
	int i;
	char str[50];
	if(fp==NULL)
	{
		printf("can not open '%s'",PATH);
		fclose(fp);
		return false;
	}
	for(i=0;i<CarNum;i++)
	{
		if(car[i].type==bus)
			strcpy(str,"bus");
		else if(car[i].type==sub)
			strcpy(str,"sub");
		fprintf(fp,"%3s %20s %3.1f %3.1f %d %d %3.1f %s\n",str,car[i].name,car[i].start,car[i].end,car[i].stateCount,car[i].twoway,car[i].costCount,car[i].state);
	}
	fclose(fp);
	return true;
}

void Data::Init(int i,char type[],char name[],char stateLine[],float costCount,float start,float end,int stateCount,int twoway){
	int state;//��ȡ״̬
	char *ch;//��ʱ���ַ�
	char str[50]="";//��ʱ���ַ���
	char stateName1[50];//��ʱ��վ����
	char stateName2[50];//��ʱ��վ����
	float tempf;//��ʱ��float
	int j,z;
	//����
	if(!strcmp(type,"bus"))
		car[i].type=bus;
	else if(!strcmp(type,"sub"))
		car[i].type=sub;

	//����
	strcpy(car[i].name,name);

	//����ʱ��
	car[i].start=start;

	car[i].end=end;

	//��վ��
	car[i].stateCount=stateCount;

	//˫��
	car[i].twoway=twoway;

	//�շѼ۸�
	car[i].costCount=costCount;
	//��վ
	strcpy(car[i].state,stateLine);

	state=1;
	j=0;
	z=0;
	for(ch=stateLine;*ch!='\0';ch++){
		if(*ch=='#' || *ch=='-'){
			switch(state){
				case 1://����
					//���ݴ���
					str[z]='\0';
					//��������
					car[i].stateLine.InsertLinkList(j+1,str);
					m_state.InitState(str,name);
					//���ݳ�ʼ��
					if(j!=0){
						if(j!=1)
							strcpy(stateName1,stateName2);
						strcpy(stateName2,str);
						state=2;
					}
					if(j==0){
						strcpy(stateName1,str);
						j++;
					}
					z=0;
					break;
				case 2://·��ǧ��
					//���ݴ���
					str[z]='\0';
					//��������
					tempf=(float)(atof(str));
					//���ݳ�ʼ��
					state=3;
					z=0;
					break;
				case 3://ʱ�����
					//���ݴ���
					str[z]='\0';
					//��������
					m_graph.InitLine(stateName1,stateName2,name,tempf,(float)(atof(str)));
					if(car[i].twoway)
						m_graph.InitLine(stateName2,stateName1,name,tempf,(float)(atof(str)));
					//���ݳ�ʼ��
					state=1;
					z=0;
					j++;
					break;
			}
		}
		else{
			str[z]=*ch;
			z++;
		}
	}
}


int Data::GetCarNum(){
	return CarNum;
}

int Data::GetStateNum(){
	return m_state.LenLinkList();
}
int Data::GetWayNum(){
	return line->LenLinkList();
}


bool Data::DeleteCar(int i){
	int state;//��ȡ״̬
	char *ch;//��ʱ���ַ�
	char str[50]="";//��ʱ���ַ���
	char stateName1[50];//��ʱ��վ����
	char stateName2[50];//��ʱ��վ����
	int j,z;
	//Խ���ж�
	if(i>CarNum)
		return false;
	//ɾ��-վ�㡢ͼ
	state=1;
	j=0;
	z=0;
	for(ch=(char*)&car[i-1].state;*ch!='\0';ch++){
		if(*ch=='#' || *ch=='-'){
			switch(state){
				case 1://����
					//���ݴ���
					str[z]='\0';
					//ɾ������
					if(!m_state.DelState(str,car[i-1].name))
						return false;
					//���ݳ�ʼ��
					if(j!=0){
						if(j!=1)
							strcpy(stateName1,stateName2);
						strcpy(stateName2,str);
						state=2;
					}
					if(j==0){
						strcpy(stateName1,str);
						j++;
					}
					z=0;
					break;
				case 2://·��ǧ��
					//���ݳ�ʼ��
					state=3;
					z=0;
					break;
				case 3://ʱ�����
					//��������
					if(!m_graph.DelLine(stateName1,stateName2,car[i-1].name))
						return false;
					if(car[i-1].twoway)
						if(!m_graph.DelLine(stateName2,stateName1,car[i-1].name))
							return false;
					//���ݳ�ʼ��
					state=1;
					z=0;
					j++;
					break;
			}
		}
		else{
			str[z]=*ch;
			z++;
		}
	}
	//ɾ��-��
	for(j=0;j<CarNum-1;j++){
		if(j>=i-1){
			car[j].type=car[j+1].type;
			car[j].start=car[j+1].start;
			car[j].end=car[j+1].end;
			car[j].twoway=car[j+1].twoway;
			car[j].stateCount=car[j+1].stateCount;
			car[j].costCount=car[j+1].costCount;
			car[j].stateLine=car[j+1].stateLine;
			strcpy(car[j].name,car[j+1].name);
			strcpy(car[j].state,car[j+1].state);
		}
	}
	CarNum--;
	//����
	if (!Save())
		return false;
	return true;
}


//��ѯ��
void Data::FindCar(int i,char type[],char re[]){	
	char str[50];
	int j;
	if(!strcmp("����",type)){
		if(car[i].type==bus)
			strcpy(re,"����");
		else if(car[i].type==sub)
			strcpy(re,"����");
	}
	else if(!strcmp("����",type)){
		strcpy(re,car[i].name);
	}
	else if(!strcmp("����ʱ��",type)){
		sprintf(re,"%.0f:00-%.0f:00",car[i].start,car[i].end);
	}
	else if(!strcmp("˫��",type)){
		if(car[i].twoway)
			strcpy(re,"��");
		else
			strcpy(re,"��");
	}
	else if(!strcmp("�շ�",type)){
		sprintf(re,"%.1fԪ",car[i].costCount);
	}
	else if(!strcmp("��վ",type)){
		car[i].stateLine.GetfromLinkList(1,str);
		strcpy(re,str);
		for(j=2;j<=car[i].stateLine.LenLinkList();j++){
			if(car[i].twoway)
				strcat(re,"-");
			else
				strcat(re,"->");
			car[i].stateLine.GetfromLinkList(j,str);
			strcat(re,str);
		}
	}
	else if(!strcmp("�޸�ʼ��",type)){
		sprintf(re,"%.0f",car[i].start);
	}
	else if(!strcmp("�޸��շ�",type)){
		sprintf(re,"%.0f",car[i].end);
	}
	else if(!strcmp("�޸�˫��",type)){
		sprintf(re,"%d",car[i].twoway);
	}
	else if(!strcmp("�޸��շ�",type)){
		sprintf(re,"%.1f",car[i].costCount);
	}
	else if(!strcmp("�޸ĳ�վ",type)){
		strcpy(re,car[i].state);
	}
	else
		strcpy(re,"error");
	return;
}

//��ѯվ��
void Data::FindState(int i,char type[],char re[]){
	char str[50];
	int j;
	StateList::State* state;
	state=m_state.GetfromLinkList(i+1);
	if(!strcmp("��վ",type)){
		strcpy(re,state->name);
	}
	else if(!strcmp("������·",type)){
		m_state.GetfromLinkList(i+1)->carPass.GetfromLinkList(1,str);
		strcpy(re,str);
		for(j=2;j<=state->carPass.LenLinkList();j++){
			strcat(re,"��");
			state->carPass.GetfromLinkList(j,str);
			strcat(re,str);
		}
	}
	else if(!strcmp("������·��",type)){
		sprintf(re,"%d��",state->carNum);
	}
	else
		strcpy(re,"error");
	return;
}


//��ѯ·��
bool Data::FindWayBegin(char start[],char end[]){
	if(!strcmp(start,end) || m_state.SearchLinkList(start)==-1 || m_state.SearchLinkList(end)==-1){
		return false;
	}
	line->GetLine(start,end);	
	return true;
}
void Data::FindWay(int i,char type[],char re[]){		
	int j;
	char str1[50],str2[50];
	char str3[50],str4[50];
	if(!strcmp("·��1",type)){
		line->GetfromLinkList(i)->line->GetfromLinkList(1,str1);
		line->GetfromLinkList(i)->carName->GetfromLinkList(2,str2);
		strcat(re,str1);
		strcat(re,str2);
		strcat(re,"->");
		for(j=2;j<=line->GetfromLinkList(i)->line->LenLinkList();j++){
			line->GetfromLinkList(i)->line->GetfromLinkList(j,str1);
			line->GetfromLinkList(i)->carName->GetfromLinkList(j,str2);
			strcat(re,str1);
			strcat(re,str2);
			strcat(re,"->");
		}
	}
	else if(!strcmp("���˴���",type)){
		if(line->GetfromLinkList(i)==0)
			sprintf(re,"��");
		else if(line->GetfromLinkList(i)->turnNum==1)
			sprintf(re,"ֱ��");
		else
			sprintf(re,"����%d��",line->GetfromLinkList(i)->turnNum-1);
	}
	else if(!strcmp("����",type)){
		if(line->GetfromLinkList(i)==0)
			sprintf(re,"��");
		else 
			sprintf(re,"%.1fԪ",line->GetfromLinkList(i)->cost);
	}
	else if(!strcmp("����",type)){
		if(line->GetfromLinkList(i)==0)
			sprintf(re,"��");
		else 
			sprintf(re,"%.1fǧ��",line->GetfromLinkList(i)->distance);
	}
	else if(!strcmp("��ʱ",type)){
		if(line->GetfromLinkList(i)==0)
			sprintf(re,"��");
		else 
			sprintf(re,"%.1f����",line->GetfromLinkList(i)->time);
	}
	else if(!strcmp("·��",type)){
		if(line->GetfromLinkList(i)==0){
			sprintf(re,"��");
			return;
		}
		line->GetfromLinkList(i)->line->GetfromLinkList(1,str1);
		line->GetfromLinkList(i)->carName->GetfromLinkList(2,str2);
		sprintf(re,"��%s��%s",str1,str2);
		for(j=2;j<=line->GetfromLinkList(i)->line->LenLinkList();j++){
			line->GetfromLinkList(i)->line->GetfromLinkList(j,str3);
			line->GetfromLinkList(i)->carName->GetfromLinkList(j,str4);
			if(strcmp(str2,str4)){//����
				strcpy(str1,str3);
				strcpy(str2,str4);
				strcat(re,"��");
				line->GetfromLinkList(i)->line->GetfromLinkList(j-1,str3);
				strcat(re,str3);
				strcat(re,"->��");
				strcat(re,str3);
				strcat(re,"��");
				strcat(re,str2);
				if(j==line->GetfromLinkList(i)->line->LenLinkList()){
					strcat(re,"��");
					strcat(re,str1);
				}
			}
			else if(j==line->GetfromLinkList(i)->line->LenLinkList()){
				strcat(re,"��");
				strcat(re,str3);
			}
		}
	}
	else
		strcpy(re,"error");
	return;
}