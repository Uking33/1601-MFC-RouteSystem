// StateList.h: interface for the StateList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATELIST_H__DF058083_953D_447B_9133_56BBE9204C03__INCLUDED_)
#define AFX_STATELIST_H__DF058083_953D_447B_9133_56BBE9204C03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//Õ¾µã
class StateList{
public:
	class State{
	public:
		char name[50];
		int carNum;	
		NameList carPass;
		State& operator=(const State &rhs);
	};
public:
	typedef State DataType;
	typedef struct node
	{
		DataType data;
		struct node *next;
	}LNode;
	StateList();
	virtual ~StateList  ();
	void CreateLinkList();
	void InitState(char stateName[],char carName[]);
	bool DelState(char stateName[],char carName[]);
	bool InsertLinkList(int i,DataType* x);
	void DeleteLinkList(int i);
	int LenLinkList();
	int SearchLinkList(DataType* x);
	int SearchLinkList(char x[]);
	State* GetfromLinkList(int i);
private:
	LNode *head;
	bool begin;
};

#endif // !defined(AFX_STATELIST_H__DF058083_953D_447B_9133_56BBE9204C03__INCLUDED_)
