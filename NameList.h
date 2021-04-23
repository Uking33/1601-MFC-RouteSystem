// NameList.h: interface for the NameList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMELIST_H__D33A5691_7503_41BA_B85F_FF0C26A93A3A__INCLUDED_)
#define AFX_NAMELIST_H__D33A5691_7503_41BA_B85F_FF0C26A93A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class NameList  
{
public:
	typedef char DataType[50];
	typedef struct node
	{
		DataType data;
		struct node *next;
	}LNode;
	NameList  ();
	virtual ~NameList  ();

	void Init();
	void CreatLinkList();
	int LenLinkList();
	bool InsertLinkList(int i,char x[]);
	void DeleteLinkList(int i);
	bool NameList::DeleteLinkList(DataType x);
	int SearchLinkList(DataType x);
	void GetfromLinkList(int i,char x[]);
	NameList& operator=(const NameList &rhs);

	LNode *head;
	bool begin;
};

#endif // !defined(AFX_NAMELIST_H__D33A5691_7503_41BA_B85F_FF0C26A93A3A__INCLUDED_)
