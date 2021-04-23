// Graph.h: interface for the Graph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH_H__6CDF019D_8C7C_4CC2_87BD_3D5D786352AC__INCLUDED_)
#define AFX_GRAPH_H__6CDF019D_8C7C_4CC2_87BD_3D5D786352AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//图
class Graph{
public:
	typedef struct PassNode //通过结点
	{
		char carName[50];
		float time;
		float distance;
		struct PassNode *next;
	}PassNode;

	typedef struct PassList{//通过链表
		bool begin;
		PassNode* head;

		PassList();
		virtual ~PassList  ();
		void Init();
		void CreateLinkList();
		bool InsertLinkList(int i,PassNode* x);
		void DeleteLinkList(int i);
		int LenLinkList();
		int SearchLinkList(char x[]);
		PassNode* GetfromLinkList(int i);
	}PassList;

	typedef struct EdgeNode //表结点
	{
		char name[50];
		struct PassList *passList;
		struct EdgeNode *next;
	}EdgeNode;

	typedef struct VextexNode  //表头结点
	{
		bool begin;
		EdgeNode  *head;

		char name[50];
		struct VextexNode *next;
		
		VextexNode();
		virtual ~VextexNode  ();
		void Init();
		void CreateLinkList();
		bool InsertLinkList(int i,EdgeNode* x);
		void DeleteLinkList(int i);
		int LenLinkList();
		int SearchLinkList(char x[]);
		EdgeNode* GetfromLinkList(int i);
	}VextexNode;

	typedef struct AdjList{//邻接表
	public:
		bool begin;
		VextexNode* head;

		AdjList();
		virtual ~AdjList  ();
		void Init();
		void CreateLinkList();
		bool InsertLinkList(int i,VextexNode* x);
		void DeleteLinkList(int i);
		int LenLinkList();
		int SearchLinkList(char x[]);
		VextexNode* GetfromLinkList(int i);
		bool IsLineOpen(int i,int j);
	}AdjList;
public:
	AdjList m_map;
	Graph();
	virtual ~Graph();
	void InitLine(char stateName1[],char stateName2[],char name[],float distance,float time);
	bool DelLine(char stateName1[],char stateName2[],char carName[]);
};

#endif // !defined(AFX_GRAPH_H__6CDF019D_8C7C_4CC2_87BD_3D5D786352AC__INCLUDED_)
