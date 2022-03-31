// QAsystemView.h : interface of the CQAsystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QASYSTEMVIEW_H__2BD4FD56_ADBC_4054_850F_5E30A3A44061__INCLUDED_)
#define AFX_QASYSTEMVIEW_H__2BD4FD56_ADBC_4054_850F_5E30A3A44061__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "link-includes.h"
#include "path.h"
#include "Question.h"
#include "feedback.h"
#include "OleRichEditCtrl.h" 

class sortedChain;
class CQAsystemView;

class sortedChainNode
{
 int data;
 sortedChainNode* next;
 friend class sortedChain;
 friend class CQAsystemView;
 friend class chainIterator;
};

class sortedChain
{

friend class chainIterator;
public: 

sortedChain() { first=0;}
~sortedChain()
{
 sortedChainNode *  N;
while(first)
{
N=first->next;
delete first;
first=N;
}
}

bool search(int )const;
sortedChain & insert(const int & );

private:

sortedChainNode * first;

};



class CQAsystemView : public CFormView
{
protected: // create from serialization only
	CQAsystemView();
	DECLARE_DYNCREATE(CQAsystemView)

public:

int presentlabel(char* string);
int present(char* string,int in,int flag);
	//{{AFX_DATA(CQAsystemView)
	enum{ IDD = IDD_QASYSTEM_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CQAsystemDoc* GetDocument();
	void print_words_with_prep_phrases_marked(CNode *n);
	void Quest(char* keywords[10],char* othrkywd[10],char focus[100],
		char* question,int& k,int& t, int &Num_phrase, char Phrases [][50], Linkage & linkage);
	void EntityMatching(int count1[], int count2[]);
    void FindPresenceOfEntity();
//    Operations
public:


	int IsItAcronym(char * s);
	Dictionary    dict;
    Parse_Options opts;
    Sentence      sent, sent1, sent2;
    Linkage       linkage, linkage1, linkage2;
    char *        diagram, * diagram1, *diagram2;
    int           i, num_linkages, num_linkages1,num_linkages2 ;
	Cpath			pa;
	char*		  Entity[1000];
	char*        AcronymList[500];
	char*        AcExpansion[500];
	int			  length, lengthAc;
	CQuestion		qa;
	Cfeedback		fa;
	char phrases[5][50];
char phrases1[5][50];
char phrases2[5][50];	
int num_phrase;
int num_phrase1;
int num_phrase2;
sortedChain chain1[10], chain2[10];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQAsystemView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CQAsystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQAsystemView)
	afx_msg void OnEntity();
	afx_msg void OnButton3();
	afx_msg void OnSubmit();
	afx_msg void OnHindiQA();
	afx_msg void OnBUTTONp1();
	afx_msg void OnBUTTONp2();
	afx_msg void OnBUTTONp3();
	afx_msg void OnButton1();
	afx_msg void OnClickRichedit4(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickRichedit5(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in QAsystemView.cpp
inline CQAsystemDoc* CQAsystemView::GetDocument()
   { return (CQAsystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QASYSTEMVIEW_H__2BD4FD56_ADBC_4054_850F_5E30A3A44061__INCLUDED_)





bool sortedChain::search( int k) const
{
sortedChainNode* p= first;

for(; p&& p->data< k; p=p->next);

//verify match
if(p&&p->data == k)
 return true;

return false;
}


sortedChain & sortedChain:: insert(const int & e)
{
 sortedChainNode* p= first, *tp=0;

for(; p&& p->data< e; tp=p, p=p->next);

if(p && p->data==e) return *this;


sortedChainNode* q= new sortedChainNode;
q->data= e;
q->next=p;
if(tp) tp->next=q;
else first =q;

return *this;
}


class chainIterator
{
public:

int* Initialize( sortedChain & C)
  { location = C.first;
    if(location) return & location->data;
   return 0;
  }

int * Next()
{
 if(!location) return 0;
 location = location->next;
 if(location) return & location->data;
 return 0;
}
private:

sortedChainNode* location;
};

