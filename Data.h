// Data.h: interface for the Data class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATA_H__63779192_0569_462B_B518_56F9E7502FF0__INCLUDED_)
#define AFX_DATA_H__63779192_0569_462B_B518_56F9E7502FF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "List.h"
#include "StateList.h"
#include "Graph.h"
#include <string.h>

#define PATH "data.txt"

//��
enum CarType{sub,bus};
enum CarCostType{all,dis};
struct Car{
	CarType type;
	char name[50];
	char state[1000];
	float start;//��ʼ����
	float end;
	int twoway;
	int stateCount;	
	float costCount;	
	NameList stateLine;//վ��
};

class Data;
//·��
class LineList{	
public:
	struct LineNode{
		float time;
		float cost;
		float distance;
		int busNum;
		int subNum;
		int turnNum;
		NameList* carName;
		NameList* line;
		struct LineNode* next;
		struct LineNode* last;
		LineNode& LineNode::operator=(const LineNode& rhs);
	};
	LineList(Data* data);
	virtual ~LineList  ();
	void CreateLinkList();
	bool InsertLinkList(int i,LineNode* x);
	void DeleteLinkList(int i);
	bool SwapLinkList(LineNode* x1,LineNode* x2);
	int LenLinkList();
	LineNode* GetfromLinkList(int i);

	
	bool LineList::GetLine(char start[],char end[]);
	void DFSM (Graph::AdjList* G,char before[],char now[],int k,LineNode* path,char name[]);
	void LineSort(int c1,int c2);
	void LineSort2(int c2,int type);
	
	char m_start[50],m_end[50];
private:
	LineNode *head;
	bool begin;
	Data* m_data;
};

class Data  
{
public:
	Data();
	virtual ~Data();
	//���غ���
	void Load();
	void Init(int i,char type[],char name[],char stateLine[],float costCount,float start,float end,int stateCount,int twoway);
	//���Һ���
	void FindCar(int i,char type[],char re[]);
	void FindState(int i,char type[],char re[]);
	bool FindWayBegin(char start[],char end[]);
	void FindWay(int i,char type[],char re[]);
	int GetCarNum();	
	int GetStateNum();
	int GetWayNum();
	//�㷨����
	LineList* line;
	//Data
	int CarNum;
	Car car[50];
	StateList m_state;
	Graph m_graph;
	//�޸ĺ���
	bool DeleteCar(int index);
	bool Data::Save();
};

#endif // !defined(AFX_DATA_H__63779192_0569_462B_B518_56F9E7502FF0__INCLUDED_)
