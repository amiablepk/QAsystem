// QAsystemView.cpp : implementation of the CQAsystemView class
//

#include "stdafx.h"
#include "QAsystem.h"
#include <io.h>
#include "QAsystemDoc.h"
#include "QAsystemView.h"
//#include "scandir.h"
# include "wn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CQAsystemView

IMPLEMENT_DYNCREATE(CQAsystemView, CFormView)

BEGIN_MESSAGE_MAP(CQAsystemView, CFormView)
	//{{AFX_MSG_MAP(CQAsystemView)
	ON_COMMAND(ID_Entity, OnEntity)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnSubmit)
	ON_BN_CLICKED(IDC_HindiQA, OnHindiQA)
	ON_BN_CLICKED(IDC_BUTTONp1, OnBUTTONp1)
	ON_BN_CLICKED(IDC_BUTTONp2, OnBUTTONp2)
	ON_BN_CLICKED(IDC_BUTTONp3, OnBUTTONp3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_NOTIFY(NM_CLICK, IDC_RICHEDIT4, OnClickRichedit4)
	ON_NOTIFY(NM_CLICK, IDC_RICHEDIT5, OnClickRichedit5)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQAsystemView construction/destruction

CQAsystemView::CQAsystemView()
	: CFormView(CQAsystemView::IDD)
{

_putenv("WNHOME=C:\\Program Files\\WordNet\\2.0" );
_putenv("WNSEARCHDIR =C:\\Program Files\\WordNet\\2.0\\dict");

	opts  = parse_options_create();	
	  dict  = dictionary_create("4.0.dict", "4.0.knowledge", 
			      "4.0.constituent-knowledge", "4.0.affix");

	FILE *ptr= fopen("e:/default.txt","r");        
	if(ptr)
	{
		int in=0;
		char line[100];
		while(fgets(line,100,ptr))
		{
			Entity[in]=new char [strlen(line)];
				strcpy(Entity[in],line);
				Entity[in][strlen(line)-1]='\0';
				in++;
		}
		length=in;
	}
	else AfxMessageBox("Default configuration not found \n Please configure the system",MB_OK);
				
FILE *ptr1= fopen("e:/Acronym.txt","r");   

     int in1=0;     
	if(ptr1)
	{
		
		char line[100];
		while(fgets(line,100,ptr1))
		{
			AcronymList[in1]=new char [strlen(line)];
				strcpy(AcronymList[in1],line);
				AcronymList[in1][strlen(line)-1]='\0';
				in1++;
		}
		
	}
	else AfxMessageBox("Acronym Expansions Not Employed ",MB_OK);

FILE *ptr2= fopen("e:/Expansion.txt","r");  
int in2=0;      
	if(ptr2)
	{
		
		char line[100];
		while(fgets(line,100,ptr2))
		{
			AcExpansion[in2]=new char [strlen(line)];
				strcpy(AcExpansion[in2],line);
				AcExpansion[in2][strlen(line)-1]='\0';
				in2++;
		}
		
	}
	else AfxMessageBox("Acronym Expansions Not Employed ",MB_OK);
if(in1!=in2)
AfxMessageBox("Acronyms and their Expansions Mismatch  ",MB_OK);
else
lengthAc=in1;
				

	//{{AFX_DATA_INIT(CQAsystemView)
		
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CQAsystemView::~CQAsystemView()
{
	dictionary_delete(dict);
    parse_options_delete(opts);

		
}

void CQAsystemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQAsystemView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CQAsystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CQAsystemView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


}

/////////////////////////////////////////////////////////////////////////////
// CQAsystemView printing

BOOL CQAsystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CQAsystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CQAsystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CQAsystemView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CQAsystemView diagnostics

#ifdef _DEBUG
void CQAsystemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CQAsystemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CQAsystemDoc* CQAsystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQAsystemDoc)));
	return (CQAsystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQAsystemView message handlers
char DELIM[]   = " ,.:\t\n1234567890/?()\"";
char DELIM1[]   = " ,.:\t\n/?()";

char* farzi[] = {"why","what","when","where","how","on","a","is","An","in","and","are", "the", "to","at","for","of","do","does","did","that","can","vs"};   //also change the total number
#define Arr_Len	23


char* FindSimilar(char* wd,int pos)
{

char* s=new char [100];
s[0]='\0';
int k=wninit();
int count=0;
Synset *next;
Synset *ptr;

//sample
if(!stricmp(wd,"difference"))
{
	sprintf(s,"%s","compare contrast unlike disagreement");
	return s;
}

SynsetPtr t= findtheinfo_ds(wd,pos,23,ALLSENSES);
if(t)
{	
	for(int i=0;i<t->wcount;i++)
	{ 
		if(strcmp(wd,t->words[i])) 
		{
			sprintf(s,"%s %s",s,t->words[i]);
			count++;
			if(count>4) return s;
		}
	}	
	next=t->nextss;

while(next)
{
	for(i=0;i<next->wcount;i++)
	{
		if(strcmp(wd,next->words[i]))
		{
			sprintf(s,"%s %s",s,next->words[i]);
			count++; 
			if(count>4) return s;
		}
	}
	ptr=next->ptrlist;
	while(ptr)
	{	
		for(i=0;i<ptr->wcount;i++)
		{ 
			if(strcmp(wd,ptr->words[i]))
			{
				sprintf(s," %s %s",s,ptr->words[i]); 
				count++; 
				if(count>4) return s;
			}
		}
		ptr=ptr->ptrlist;
	}
	next=next->nextss;
}

}
return s;
	
}

// various Functions required for CheckForCompare
char* initial[]=
{"What is the difference between",
 "What is difference between",
 "What are the differences between",
 "What are differences between",
 "Contrast between",
 "Compare between",
 "differentiate between",
 "distinguish between"
}; 

const int totfor=sizeof(initial)/sizeof(char*);

int IsCompare(char* quest, int length)
 {    char * location1=strstr(quest, "between");
   if(!location1) return false;
   
     for(int i=0;i<totfor;i++)
     {
         int le=strlen(initial[i]);
         if(!strnicmp(initial[i],quest,le))
         return i+1;
     }
     return -1;
 }

 bool getAB(char* Line, char * A, char * B)
 {
       char * location1=strstr(Line, "between");
       for(int i=1;i<=8;i++)
         location1++;
         
       char * location2=strstr(Line, " and ");
       int seLen= 5;
       if(!location2)
       { location2=strstr(Line, " & ");
          seLen=3;
        if(!location2)
          return false;
        
       }
       
        
        int i1=0;
        while((location1+i1)<location2)
        {A[i1]=location1[i1];
         i1++;
        }    
       A[i1]='\0';
       
       
       for(int j=1;j<=seLen;j++)
       location2++;
       
       strcpy(B, location2);
       return true;
}    
   
 //Removes Question Mark from the  question
 void RemoveQMark(char* line)
  {
      char * ptr= strstr(line, "?");
      if(!ptr) return;
      *ptr=' ';
  } 
 
  void ShiftLeftOnce(char* line)
  { int i;
      for(i=0;line[i]!='\0';i++)
      line[i]=line[i+1]; 
  }    
  
  //removes more than one spaces from the line if any
  void RemoveExtraSpaces(char* line)
  {  //Remove initial spaces
      while(1)
      {
         char * ExtraSpaceLocation= strstr(line, " ");
         if(!ExtraSpaceLocation)
          return;
         if(ExtraSpaceLocation==line)
          ShiftLeftOnce(ExtraSpaceLocation);
         else
          break;
     }
     
     //Remove any extra spaces in between
      while(1)
      {
         char * ExtraSpaceLocation= strstr(line, "  ");
         if(!ExtraSpaceLocation)
          return;
         ShiftLeftOnce(ExtraSpaceLocation);
     }
 }        

void RemoveNewLine(char*line)
 {  
	 while(1)
	 {
	 char * NewLineLocation= strchr(line, ((char)13));
    if(!NewLineLocation)
		return;
	ShiftLeftOnce(NewLineLocation);
	 }
 }

const int LengthOfQ=200;

//Whether the question looks for the comparison between two entities
bool CheckForCompare(char* line, char* first, char* second)
{    int NO;
	RemoveExtraSpaces(line);
    RemoveQMark(line);
    bool isOK=false;
    if((NO=IsCompare(line,LengthOfQ))!=-1)
    { 
       isOK= getAB(line, first,second);
         if(isOK)
         {
         return true;
         }
         else
		 {return false;}    
    }
	return false;
}


void copyAndShift(char *heading,char* mes, int lenToCopy, int offsetis)
{			  heading[0]='\n';
			  int cl;
			  for(cl=1;cl<offsetis;cl++)
				  heading[cl]=' ';
			
				
				int iii;
				for( iii=0;iii<lenToCopy;iii++)
				 heading[offsetis+iii]= mes[iii];

				heading[offsetis]=' ';
				heading[offsetis+1]=' ';
				heading[offsetis+iii]='\0';
}

//to improve the answer returned by seft
void improveCorners(char * data)
{
	char * spaceL= strchr(data, ' ');
	if(!spaceL) 
		return;
	char *spaceL2=strchr(spaceL+1,' ');
	int ToImprove=(spaceL2-data)/sizeof(char);
	for(int sp=1;sp<ToImprove;sp++)
		data[sp]='.';
}
			 
 
void ChangeToUpperCase( char * str)
{
	while(*str)
	{
		*str=toupper(*str);
		str++;
	}
}
#define Num_Pasg 10
//To give rank to the variables according to the count values
void GiveRank( int count[], int rank[])
{
 for( int p=0; p<Num_Pasg; p++)
for( int q=0; q<p; q++)
if(count[q]>=count[p]) 
  rank[p]++;
else
 rank[q]++;
}

int CQAsystemView::IsItAcronym(char * s)
{
	for(int l=0;l<lengthAc;l++)
		if(!stricmp(s, AcronymList[l]))
			return l;
  return -1;
}


#define Top 3

// Weights to be used for keywords, otherkeywords, focus and acronyms
int keywg=4;
int otherkeywg=2;
int focwg=1;
int acwg=1;

char message[Num_Pasg][10000];
int rank[Num_Pasg];

char message1[Num_Pasg][10000];
int rank1[Num_Pasg];

char message2[Num_Pasg][10000];
int rank2[Num_Pasg];
bool IsItCompare;

//function to  be called on finally submitting the question
void CQAsystemView::OnSubmit() 
{

CRichEditCtrl* pe=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT0);
pe->SetSel(0, -1);
pe->Clear();

CRichEditCtrl* pc=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT4)	;
pc->SetSel(0, -1);
pc->Clear();

CRichEditCtrl* pd=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT5);
pd->SetSel(0, -1);
pd->Clear();

char* argv[100];
char* keywords[10];
char* othrkywd[10];
char focus[100];
int i=1,k=0,t=0;
argv[0]="seft";

char* argv1[100];
char* keywords1[10];
char* othrkywd1[10];
char focus1[100];
int i1=1,k1=0,t1=0;
argv1[0]="seft";

char* argv2[100];
char* keywords2[10];
char* othrkywd2[10];
char focus2[100];
int i2=1,k2=0,t2=0;
argv2[0]="seft";


IsItCompare=false;
char first[LengthOfQ], second[LengthOfQ];


CEdit* p1=(CEdit*) GetDlgItem(IDC_QUERRY);

int len=p1->LineLength(0);
char* line=new char [len];
int r=p1->GetLine (0,line,200);
if(r>0)
{ 
	line[r]='\0';
	IsItCompare=CheckForCompare(line, first, second);
	if(!IsItCompare)
	{
			Quest(keywords,othrkywd,focus,line,k,t, num_phrase, phrases, linkage);
		
		argv[i]=new char [300];
		sprintf(argv[i]," ");
		//Include keyword in the query
		for(int ind=1;ind<=keywg;ind++)
		for(int f=0;f<k;f++)
			sprintf(argv[i],"%s %s ",argv[i],keywords[f]);
		
		//Include other keywords in the query
		for(int inde=1;inde<=otherkeywg;inde++)	
		for(int f1=0;f1<t;f1++)
			sprintf(argv[i],"%s %s ",argv[i],othrkywd[f1]);
		
		//Include focus in the query
		for(int index=1;index<=focwg;index++)
		sprintf(argv[i],"%s %s ",argv[i],focus);
		

		// Code For Acronym Expansion
 		int j=0,AcNo;
	   char temp[30][50];
           char* s1=strtok(line,DELIM);
			while(s1)
			{	strcpy(temp[j++],s1);
				s1=strtok(NULL,DELIM);
			}

			for(int ii=0;ii<j;ii++)
			if((AcNo=IsItAcronym(temp[ii]))!=-1)
			for(int ind_=1;ind_<=acwg;ind_++)
			sprintf(argv[i],"%s %s",argv[i],AcExpansion[AcNo]);
			
			i++;
	}
    
	else
    {
      
		Quest(keywords1,othrkywd1,focus1,first,k1,t1, num_phrase1, phrases1, linkage1);
		
		argv1[i1]=new char [300];
		sprintf(argv1[i1]," ");
		for(int ind=1;ind<=keywg;ind++)
		for(int f=0;f<k1;f++)
			sprintf(argv1[i1],"%s %s ",argv1[i1],keywords1[f]);
		
		for(int inde=1;inde<=otherkeywg;inde++)	
		for(int f1=0;f1<t1;f1++)
			sprintf(argv1[i1],"%s %s ",argv1[i1],othrkywd1[f1]);

		for(int index=1;index<=focwg;index++)
		sprintf(argv1[i1],"%s %s",argv1[i1],focus1);
		

        // Code For Acronym Expansion
		int j1=0,AcNo1;
	    char temp1[15][50];
           char* s11=strtok(first,DELIM);
			while(s11)
			{	strcpy(temp1[j1++],s11);
				s11=strtok(NULL,DELIM);
			}

			for(int ii1=0;ii1<j1;ii1++)
			{
			AcNo1=IsItAcronym(temp1[ii1]);
			if(AcNo1!=-1)
			for(int ind_=1;ind_<=acwg;ind_++)
			sprintf(argv1[i1],"%s %s",argv1[i1],AcExpansion[AcNo1]);
			}

	    i1++;

			Quest(keywords2,othrkywd2,focus2,second,k2,t2, num_phrase2, phrases2, linkage2);
		
		argv2[i2]=new char [300];
		sprintf(argv2[i2]," ");
		for(int ind1=1;ind1<=keywg;ind1++)
		for(int f2=0;f2<k2;f2++)
			sprintf(argv2[i2],"%s %s ",argv2[i2],keywords2[f2]);

		for(int inde1=1;inde1<=otherkeywg;inde1++)	
		for(int f2=0;f2<t2;f2++)
			sprintf(argv2[i2],"%s %s %s",argv2[i2],othrkywd2[f2]);
		
		for(int index1=1;index1<=focwg;index1++)
			sprintf(argv2[i2],"%s %s",argv2[i2],focus2);

		// Code For Acronym Expansion
		int j2=0,AcNo2;
	    char temp2[15][50];
           char* s12=strtok(second,DELIM);
			while(s12)
			{	strcpy(temp2[j2++],s12);
				s12=strtok(NULL,DELIM);
			}

			for(int ii2=0;ii2<j2;ii2++)
			if((AcNo2=IsItAcronym(temp2[ii2]))!=-1)
				for(int ind1_=1;ind1_<=acwg;ind1_++)
			sprintf(argv2[i2],"%s %s",argv2[i2],AcExpansion[AcNo2]);

	    i2++;
	}
}


if(!IsItCompare )
{
argv[i++]="-w5";
argv[i++]="-m10";

CEdit* p2=(CEdit*) GetDlgItem(IDC_QUERRY2);
len=p2->LineLength(0);
line=new char [len];
r=p2->GetLine (0,line,200);

if(r>0)
{
	line[r]='\0';
	char* temp=new char [r];
	strcpy(temp,line);
	char con[]="/*.*";
	strcat(line,con);
	strcat(temp,"/");
	struct _finddata_t fileinfo; 
    long hFile;
	if((hFile = _findfirst(line,&fileinfo))==-1)
		AfxMessageBox("NO files present",MB_OK);     
	else 
	{
		if(strcmp(".",fileinfo.name)&&strcmp("..",fileinfo.name))
		{
		 argv[i]=new char [r];
		 strcpy(argv[i],temp);
		 strcat(argv[i],fileinfo.name);
		 i++;
		}
	  while (_findnext(hFile,&fileinfo)==0)
	  {
		if(strcmp(".",fileinfo.name)&&strcmp("..",fileinfo.name))
		{
		 argv[i]=new char [r];
		 strcpy(argv[i],temp);
		 strcat(argv[i],fileinfo.name);
		 i++;
		}
	  }
	 	   
	  _findclose( hFile );
	}



	main_seft(i,argv,message);
	
	for(int l1=0;l1<Num_Pasg;l1++)
	{
		//RemoveNewLine(message[l1]); 
	  RemoveExtraSpaces(message[l1]);
	}

		
/*	sprintf(final," ");
	
int rank[Num_Pasg]; 
	int count[Num_Pasg] ; 
     
	
	for(int r=0; r< Num_Pasg; r++)
	{
	 count[r]=rank[r]=0;
	
	}
		
	//check Noun Phrase in the retrieved passages
	
for(k1=0;k1<Num_Pasg;k1++)
	{	
		int l=0;
		while(l<num_phrase)
		{
			char* s1=strstr(message[k1],phrases[l]);
			while(s1)
			{	
				count[k1]++;
				s1=strstr(s1+strlen(phrases[l]),phrases[l]);
			}	
			l++;
		}
  
	}*/
	
/*	GiveRank( count, rank);
	for (k1=0;k1<Num_Pasg;k1++)
	{  int z;
		for( z=0; z<Num_Pasg; z++)
			if(rank[z]==k1)
				break;
	sprintf(final,"%s %s",final,message[z]);
	}*/


CRichEditCtrl* p=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT0);
p->ShowWindow(SW_SHOW );
   

   COLORREF color7=RGB(233 ,255 , 158);
   p->SetBackgroundColor( false , color7 );
   
 
CRichEditCtrl* pp=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT4);
   pp->ShowWindow(SW_HIDE );
CRichEditCtrl* pq=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT5);
   pq->ShowWindow(SW_HIDE );
   

	CHARFORMAT cf;
	COLORREF color=RGB(255, 0, 0);
	COLORREF color1=RGB(0, 0, 0);
	cf.cbSize		= sizeof(CHARFORMAT);
    cf.dwMask		= CFM_COLOR | CFM_BOLD | CFM_SIZE;
	cf.yHeight	= 250;
	cf.dwEffects	= CFE_BOLD;	// To disable CFE_AUTOCOLOR
	cf.crTextColor	= color1;

        // Paragraph formatting options
		PARAFORMAT2 prf;
		prf.cbSize		= sizeof(PARAFORMAT2); 
		prf.dwMask=   PFM_ALIGNMENT  | PFM_STARTINDENT | PFM_OFFSET ;
		prf.wAlignment	= PFA_LEFT;
		prf.dxStartIndent=50;
		prf.dxOffset=50;
		prf.cTabCount=5;
		p->SetParaFormat(  prf );

	long nInsertionPoint;
	
	for(int numb=0; numb<10;numb++)
		{  
		   int ch=1;
			int i=0;
			char* final=new char [100000];

			char heading[300];
			
			  char * NewLineLocation= strchr(message[numb], ((char)13));
			  char * newl2= strchr(NewLineLocation+1, ((char)13));
			  int offsetis=55;
			  int lenToCopy= (newl2-message[numb])/sizeof(char);
			  copyAndShift(heading, message[numb], lenToCopy,offsetis);
			  
			  //Output the filename of the answer extracted  
			  nInsertionPoint = p->GetWindowTextLength();
				p->SetSel(nInsertionPoint, -1);
				cf.crTextColor	= color1;
				p->SetSelectionCharFormat(cf);
			    p->ReplaceSel(heading);

				improveCorners(newl2);
				strcpy(final,newl2);
			
			//Output the actual answer
			while(final[i])
			{
				char final1[10000];
				int k=0;
				while(final[i]!='\033')
				{	
					if(final[i]=='\0')
					{	ch=0;
						break;
					}
					final1[k]=final[i];
					i++;
					k++;
				}
				final1[k]='\0';
				nInsertionPoint = p->GetWindowTextLength();
				p->SetSel(nInsertionPoint, -1);
				cf.crTextColor	= color1;
				p->SetSelectionCharFormat(cf);
				p->ReplaceSel(final1);
				
				i++;
				int j=0;
				
				if(ch==0)
					break;
				ch=1;
				char key[100];
				while(final[i]!='\033')
				{	
					key[j]=final[i];
					i++;
					j++;
				}
				key[j]='\0';
				i++;
				cf.crTextColor	= color;
				nInsertionPoint = p->GetWindowTextLength();
				p->SetSel(nInsertionPoint, -1);
				p->SetSelectionCharFormat(cf);
				p->ReplaceSel(key);
			}
		}
	}
}

else
{
//  For first

//argv[i++]="-w10";
argv1[i1++]="-m10";

CEdit* p2=(CEdit*) GetDlgItem(IDC_QUERRY2);
len=p2->LineLength(0);
line=new char [len];
r=p2->GetLine (0,line,200);

if(r>0)
{
	line[r]='\0';
	char* temp=new char [r];
	strcpy(temp,line);
	char con[]="/*.*";
	strcat(line,con);
	strcat(temp,"/");
	struct _finddata_t fileinfo; 
    long hFile;
	if((hFile = _findfirst(line,&fileinfo))==-1)
		AfxMessageBox("NO files present",MB_OK);     
	else 
	{
	  //AfxMessageBox(fileinfo.name,MB_OK);
		if(strcmp(".",fileinfo.name)&&strcmp("..",fileinfo.name))
		{
		 argv1[i1]=new char [r];
		 strcpy(argv1[i1],temp);
		 strcat(argv1[i1],fileinfo.name);
		 i1++;
		}
	  while (_findnext(hFile,&fileinfo)==0)
	  {
		if(strcmp(".",fileinfo.name)&&strcmp("..",fileinfo.name))
		{
		 argv1[i1]=new char [r];
		 strcpy(argv1[i1],temp);
		 strcat(argv1[i1],fileinfo.name);
		 i1++;
		}
	  }
	 		//sprintf(ch," %s \n", fileinfo.name);
		//AfxMessageBox(fileinfo.name,MB_OK);
   
	  _findclose( hFile );
	}



	main_seft(i1,argv1,message1);
	
	//for( int l=0;l<5;l++)
	//AfxMessageBox(message[l],MB_OK);
		
	char* final=new char [100000];
	sprintf(final," ");
	



	// For second

//argv[i++]="-w10";
argv2[i2++]="-m10";

CEdit* p2=(CEdit*) GetDlgItem(IDC_QUERRY2);
len=p2->LineLength(0);
line=new char [len];
r=p2->GetLine (0,line,200);

if(r>0)
{
	line[r]='\0';
	char* temp=new char [r];
	strcpy(temp,line);
	char con[]="/*.*";
	strcat(line,con);
	strcat(temp,"/");
	struct _finddata_t fileinfo; 
    long hFile;
	if((hFile = _findfirst(line,&fileinfo))==-1)
		AfxMessageBox("NO files present",MB_OK);     
	else 
	{
	  //AfxMessageBox(fileinfo.name,MB_OK);
		if(strcmp(".",fileinfo.name)&&strcmp("..",fileinfo.name))
		{
		 argv2[i2]=new char [r];
		 strcpy(argv2[i2],temp);
		 strcat(argv2[i2],fileinfo.name);
		 i2++;
		}
	  while (_findnext(hFile,&fileinfo)==0)
	  {
		if(strcmp(".",fileinfo.name)&&strcmp("..",fileinfo.name))
		{
		 argv2[i2]=new char [r];
		 strcpy(argv2[i2],temp);
		 strcat(argv2[i2],fileinfo.name);
		 i2++;
		}
	  }
	 		//sprintf(ch," %s \n", fileinfo.name);
		//AfxMessageBox(fileinfo.name,MB_OK);
   
	  _findclose( hFile );
	}



	main_seft(i2,argv2,message2);
	
	//for( int l=0;l<5;l++)
	//AfxMessageBox(message[l],MB_OK);
		
	char* final=new char [100000];
	sprintf(final," ");
	
    
	  
   	int rank1[Num_Pasg], rank2[Num_Pasg]; 
	int count1[Num_Pasg], count2[Num_Pasg]; 
     
	
	for(int r=0; r< Num_Pasg; r++)
	{
	 count1[r]=rank1[r]=0;
	 count2[r]=rank2[r]=0;
	}
	FindPresenceOfEntity();
    EntityMatching(count1, count2);

	//check Noun Phrase in the retrieved passages
	
	
	for(k1=0;k1<Num_Pasg;k1++)
	{	
		int l=0;
		while(l<num_phrase1)
		{
			char* s1=strstr(message1[k1],phrases1[l]);
			while(s1)
			{	
				count1[k1]++;
				s1=strstr(s1+strlen(phrases1[l]),phrases1[l]);
			}	
			l++;
		}
	}
	
	GiveRank( count1, rank1);
	for (k1=0;k1<Top;k1++)
	{  int z;
		for( z=0; z<Num_Pasg; z++)
			if(rank1[z]==k1)
				break;
	sprintf(final,"%s %s",final,message1[z]);
	}


// Code For Printing answers in the boxes
	//For First

 ChangeToUpperCase(first);
	 strcat(first, ":-\n");

  CRichEditCtrl* p4=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT0);
   p4->ShowWindow(SW_HIDE );

   CRichEditCtrl* p=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT4);
    p->ShowWindow(SW_SHOW );
	   
	CHARFORMAT cf1;
	COLORREF color1=RGB(255, 0, 0);
	COLORREF color11=RGB(0, 0, 0);
    COLORREF color21=RGB(0, 0, 128);
	cf1.cbSize		= sizeof(CHARFORMAT);
	cf1.dwMask		= CFM_COLOR | CFM_BOLD  | CFM_SIZE | CFM_UNDERLINE;
    
  cf1.crTextColor	= color11;
	long nInsertionPoint1;
	  nInsertionPoint1 = p->GetWindowTextLength();
		p->SetSel(nInsertionPoint1, -1);

        cf1.crTextColor	= color21;
			cf1.dwEffects	= CFE_UNDERLINE | CFE_BOLD;
			cf1.yHeight = 325;
			p->SetSelectionCharFormat(cf1);
			cf1.dwEffects	= CFE_BOLD;	// To disable CFE_AUTOCOLOR
			cf1.yHeight = 225;
			p->ReplaceSel(first);

		int i=0;
		int ch=1;
		while(final[i])
		{
			char final1[10000];
			int k=0;
			while(final[i]!='\033')
			{	
				if(final[i]=='\0')
				{	ch=0;
					break;
				}
				final1[k]=final[i];
				i++;
				k++;
			}
			final1[k]='\0';
			nInsertionPoint1 = p->GetWindowTextLength();
			p->SetSel(nInsertionPoint1, -1);
			cf1.crTextColor	= color11;
			p->SetSelectionCharFormat(cf1);
			p->ReplaceSel(final1);
			
			i++;
			int j=0;
			
			if(ch==0)
				break;
			ch=1;
			char key[100];
			while(final[i]!='\033')
			{	
				key[j]=final[i];
				i++;
				j++;
			}
			key[j]='\0';
			i++;
			cf1.crTextColor	= color1;
			nInsertionPoint1 = p->GetWindowTextLength();
			p->SetSel(nInsertionPoint1, -1);
			p->SetSelectionCharFormat(cf1);
			p->ReplaceSel(key);
		}
			
	for(k2=0;k2<Num_Pasg;k2++)
	{	
		int l=0;
		while(l<num_phrase2)
		{
			char* s1=strstr(message2[k2],phrases2[l]);
			while(s1)
			{	
				count2[k2]++;
				s1=strstr(s1+strlen(phrases2[l]),phrases2[l]);
			}	
			l++;
		}
	}
	
	char* final2=new char [100000];
	sprintf(final2," ");

GiveRank( count2, rank2);
	for (k2=0;k2<Top;k2++)
	{  int z;
		for( z=0; z<Num_Pasg; z++)
			if(rank2[z]==k2)
				break;
	sprintf(final2,"%s %s",final2,message2[z]);
	}

	
	//for (k2=0;k2<Top;k2++)
	//sprintf(final2,"%s %s",final2,message2[rank2[k2]]);	

       ChangeToUpperCase(second);
	 strcat(second, ":-\n");
  

 CRichEditCtrl* p3=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT4);
  p3->ShowWindow(SW_SHOW  );
    
   //  p2->SetRect(CRect(200,200,400,400));
   
   COLORREF color6=RGB(255 , 249 , 151);
   p3->SetBackgroundColor( false , color6 );
   

 CRichEditCtrl* p2=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT5);
  p2->ShowWindow(SW_SHOW  );
    
   //  p2->SetRect(CRect(200,200,400,400));
   
   COLORREF color5=RGB(156 , 235 , 255);
   p2->SetBackgroundColor( false , color5 );




	CHARFORMAT cf2;
	COLORREF color2=RGB(255, 0, 0);
	COLORREF color12=RGB(0, 0, 0);
	 COLORREF color22=RGB(0, 0, 128);
	cf2.cbSize		= sizeof(CHARFORMAT);
	cf2.dwMask		= CFM_COLOR | CFM_BOLD  | CFM_SIZE  | CFM_UNDERLINE;
	
	cf2.crTextColor	= color12;
	long nInsertionPoint2;
		nInsertionPoint1 = p2->GetWindowTextLength();
	   p2->SetSel(nInsertionPoint2, -1);
			cf2.crTextColor	= color22;
			cf2.dwEffects	= CFE_UNDERLINE | CFE_BOLD;
			cf2.yHeight = 325;
			p2->SetSelectionCharFormat(cf2);
            cf2.dwEffects	= CFE_BOLD;	// To disable CFE_AUTOCOLOR
			cf2.yHeight = 225;
			p2->ReplaceSel(second);


		i=0;
		 ch=1;
		while(final2[i])
		{
			char final1[10000];
			int k=0;
			while(final2[i]!='\033')
			{	
				if(final2[i]=='\0')
				{	ch=0;
					break;
				}
				final1[k]=final2[i];
				i++;
				k++;
			}
			final1[k]='\0';
			nInsertionPoint2 = p2->GetWindowTextLength();
			p2->SetSel(nInsertionPoint2, -1);
			cf2.crTextColor	= color12;
			p2->SetSelectionCharFormat(cf2);
			p2->ReplaceSel(final1);
			
			i++;
			int j=0;
			
			if(ch==0)
				break;
			ch=1;
			char key[100];
			while(final2[i]!='\033')
			{	
				key[j]=final2[i];
				i++;
				j++;
			}
			key[j]='\0';
			i++;
			cf2.crTextColor	= color2;
			nInsertionPoint2 = p2->GetWindowTextLength();
			p2->SetSel(nInsertionPoint2, -1);
			p2->SetSelectionCharFormat(cf2);
			p2->ReplaceSel(key);
		}
			
}	

}



}
CProgressCtrl* pBar=(CProgressCtrl*) GetDlgItem(IDC_PROGRESS2);
	pBar->SetPos(100);
return;

}



void CQAsystemView::OnEntity() 
{

int in=0,len=0;
int ret=pa.DoModal();
if(ret==IDOK)
{

CString f=pa.m_pa;

FILE *ptr,*ptr1;
ptr = fopen(f,"r");        


if(ptr)
{
    
  char line[100];
  while(fgets(line,100,ptr))
  {
	char temp[100];
	strcpy(temp,line);
	char* tok=strtok(temp,DELIM);
	if(tok)
	{
	sent = sentence_create(line, dict);
	
	int l=sentence_length(sent);
	char *cha=new char[5];

		
	num_linkages = sentence_parse(sent, opts);
	if (num_linkages > 0) {
	    linkage = linkage_create(0, sent, opts);
		char * entity;
		for (i=0; i<l; ++i)
		{
			entity=linkage_get_word(linkage,i);
			len=strlen(entity);
			if(entity[len-2]=='.' &&(entity[len-1]=='n'||entity[len-1]=='a'|| entity[len-1]=='v'||entity[len-1]=='g'))
			{	char* final=sentence_get_word(sent,i); 
			    Entity[in]=new char [strlen(final)];
				if(!present(final,in,1)) 
				{	//AfxMessageBox(final,MB_OK);
					strcpy(Entity[in++],final);
				}
			}
		}
		linkage_delete(linkage);
	
		    
	}
	else { 
			//AfxMessageBox(line,MB_OK);
			int flag=0,j=0;
			char temp[10][50];
			char line1[100];
			strcpy(line1,line);
			char* s1=strtok(line,DELIM);
			while(s1)
			{	strcpy(temp[j++],s1);
				s1=strtok(NULL,DELIM);
			}
			
			for(int l=0;l<j;l++)
			{	for(int k=0;k<Arr_Len;k++)
				{	if(strstr(farzi[k],temp[l]))
						break;
				}
					if(k==10&&!present(temp[l],in,1)) 
					{	Entity[in]=new char [strlen(temp[l])];
						strcpy(Entity[in++],temp[l]); 
					}
					else if(k<10) flag=1;
			}

			if(flag==0&&!present(line1,in,1)&&(j>1)) 
			{
				Entity[in]=new char [100];
				strcpy(Entity[in],temp[0]); 
				for(int i=1;i<j;i++)
					sprintf(Entity[in],"%s %s",Entity[in],temp[i]); 
				in++;
			}
		}

	 sentence_delete(sent);
	}

	}
	 if( ferror(ptr) )  
       perror( "Read error" );
   

	ptr1=fopen("d:/enitity.txt","a+");
	for(int i=0;i<in;i++)
	{
		fputs(Entity[i],ptr1);
		fputs("\n",ptr1);

    
	} // end of file
	fclose(ptr1);
	length=in;
	


}
else 
{ 
	AfxMessageBox(" Path is not valid ",MB_OK);
	OnEntity();
}
    
	
}

}   



void CQAsystemView::Quest(char* keywords[10],char* othrkywd[10],char focus[100]
	,char* question,int& k,int& t , int & num_phrase_, char  Phrases [][50], Linkage & linkage_) 
{

int j=0,len=0,pos=1;
char input[200];
strcpy(input,question);
char* string,*string1,*string2,*sim;
num_phrase_=0;
CNode *	cn;
for(j=0;j<5;j++)
	Phrases[j][0]='\0';
Sentence      sent;
int num_linkages;
char* qfocus=new char [10];
//sprintf(keywords," ");
//sprintf(othrkywd," ");


	// for finding the subject (focus) of verb in question

	sent = sentence_create(input, dict); 
	num_linkages=sentence_parse(sent, opts);
   if (num_linkages) 
   { linkage_ = linkage_create(0, sent, opts); 
     int length = linkage_get_num_links(linkage_);
  
     for(int ij=0;ij<length;++ij) 
     {           
			int lword= linkage_get_link_lword(linkage_,ij);
			int rword= linkage_get_link_rword(linkage_,ij); 
			string1 = linkage_get_word( linkage_,lword); 
			string2 = linkage_get_word( linkage_,rword); 
			int len_left=strlen(string1);
			int len_right=strlen(string2);
			if(string1[len_left-2]=='.' && string2[len_right-2]=='.')
			{
				if(string1[len_left-1] =='v'||string1[len_left-1] =='g')      // do not consider is  , are , this, the 
				{	string = sentence_get_word(sent,rword); 
					if(!present(string,0,0))
					{
						if(string2[len_right-1]=='n') pos=1;
						else if(string2[len_right-1]=='v') pos=2;
						else if(string2[len_right-1]=='a') pos=3;
						//AfxMessageBox(string,MB_OK);
						qfocus=new char [strlen(string)];
						strcpy(qfocus,string);
						break;
					}
				}
				else if(string2[len_right-1] =='v'||string2[len_right-1] =='g')      // do not consider is  , are , this, the 
				{	string = sentence_get_word(sent,lword);
					if(!present(string,0,0))
					{
						if(string1[len_left-1]=='n') pos=1;
						else if(string1[len_left-1]=='v') pos=2;
						else if(string1[len_left-1]=='a') pos=3;
						//AfxMessageBox(string,MB_OK);
						qfocus=new char [strlen(string)];
						strcpy(qfocus,string);
						break;
					}
				}
			}
			

	 }
     linkage_delete(linkage_);          
  } 
  
 
	
    if (num_linkages) 
	{
	linkage_ = linkage_create(0, sent, opts);
	cn = linkage_constituent_tree(linkage_);
	print_words_with_prep_phrases_marked(cn);
	linkage_free_constituent_tree(cn);
	linkage_delete(linkage_);
    }
    

sentence_delete(sent);

int ch=0;
char* tok=strtok(input,DELIM1);

while(tok)
{
	/* use hash list afterwards */

	for(int i=0;i<length;i++)
	{	if(!_stricmp(Entity[i],tok))
		{	
			keywords[k]=new char [strlen(tok)];
			strcpy(keywords[k],tok);
			k++;
			break;
		}
	}
		if(i==length&&!present(tok,0,0))
        {	
			if(!strcmp(qfocus,tok))
			 ch=1;			
			else
			{
				othrkywd[t]=new char [strlen(tok)];
				strcpy(othrkywd[t],tok);
				t++;
			}
			
		}
		
	tok=strtok(NULL,DELIM1);

	//sprintf(othrkywd,"%s %s ",othrkywd,tok);
}


if(ch)
{
sim=FindSimilar(qfocus,pos);
sprintf(focus," ");
for(int p=0;p<4;p++)
	sprintf(focus,"%s %s",focus,qfocus);
if(sim) sprintf(focus,"%s %s",focus,sim);

}
else { focus[0]='\0';}

ch=0;


}

int CQAsystemView::presentlabel(char* string)
{   
	int len =strlen(string);
	char s1[50];
	strcpy(s1,string);
	s1[len-2] = '\0';  
	for(int i=0; i<Arr_Len;i++)
	 	if(_stricmp(farzi[i],s1))
			 return 1;
	return 0;
}

int CQAsystemView::present(char* string,int in,int flag)
{   
	if(flag&&in)
	{for(int i=0; i<in;i++)
	 	if(!_stricmp(string,Entity[i]))
			 return 1;
	}
		
	for(i=0; i<Arr_Len;i++)
	 	if(!_stricmp(string,farzi[i]))
			 return 1;
	
	return 0;
}


void CQAsystemView::OnButton3() 
{


char feedb[1000];
sprintf(feedb," ");
for(int k=Top;k<Num_Pasg;k++)
{	
	//for(int m=0;m<Num_Pasg;m++)
	//	if(rank[m]==k) break;
	//AfxMessageBox(message[k],MB_OK);
	
	for(int i=0;i<length;i++)
		{	
		
			if(strstr(message[k],Entity[i]))
			{
				if(!strstr(feedb,Entity[i]))
				sprintf(feedb,"%s %s \r\n",feedb,Entity[i]);
			}
		}
}


fa.m_suggest=feedb;
fa.DoModal();

}


/*char suggest[300];
int l=0;
while(l<5)
{

if(f[l]==0)
{
	for(int i=0;i<length;i++)
		if(strstr(phrase[l],Entity[i]))
		sprintf(suggest,"%s %s",Entity[i]);
}

l++;

}

Csuggest c1;
c1.m_s1=suggest;
int ret=c1.DoModal();
if(ret==IDOK)
	suggest=c1.m_s1;
	
*/


int flag=0;
int stack=0;
void CQAsystemView::print_words_with_prep_phrases_marked(CNode *n) 
{
    CNode * m;
    
    if (n == NULL) return;
    if (strcmp(n->label, "NP")==0) 	{flag=1; stack++;}
	
    for (m=n->child; m!=NULL; m=m->next) 
	{
	if (m->child == NULL) {
		if(flag)    {	
					strcat(phrases[num_phrase]," ");
					strcat(phrases[num_phrase],m->label);
					}
	    
	}
	else {
	    print_words_with_prep_phrases_marked(m);
		}
    }
    if (strcmp(n->label, "NP")==0) 
	{	
		stack--;
		if(!stack)
		{flag=0;num_phrase++;}
	}
    
}



void CQAsystemView::OnHindiQA() 
{
	
	LPCTSTR lpfile="D:/works/HindiQAsystem.exe";
	LPCTSTR lpDirectory ="D:";
	HINSTANCE ret=ShellExecute((HWND)this, "Open",lpfile, NULL,NULL, SW_MAXIMIZE);
	if((int)ret<=32) AfxMessageBox("could not open HindiQAsystem.exe",MB_OK);

}


void CQAsystemView::OnBUTTONp1() 
{
	if(!IsItCompare)
	{
		char* tok=strtok(message[0],"=");
		tok=strtok(NULL,"=");
		tok=strtok(NULL,"=");
		char* dir=strtok(tok,": ");
		char* filepath=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy=new char [strlen(filepath)];
				strcpy(cpy,filepath);
				strcat(dir,":");
				strcat(dir,cpy);
				int len=strlen(dir);
				dir[len]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile=dir;
		HINSTANCE ret=ShellExecute((HWND)this, "Open",lpfile, NULL,NULL, SW_MAXIMIZE);
		if((int)ret<=32) AfxMessageBox("could not open the linked document",MB_OK);
	}
	else
    {
		// For first 
      char* tok1=strtok(message1[0],"=");
		tok1=strtok(NULL,"=");
		tok1=strtok(NULL,"=");
		char* dir1=strtok(tok1,": ");
		char* filepath1=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy1=new char [strlen(filepath1)];
				strcpy(cpy1,filepath1);
				strcat(dir1,":");
				strcat(dir1,cpy1);
				int len1=strlen(dir1);
				dir1[len1]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile1=dir1;
		HINSTANCE ret1=ShellExecute((HWND)this, "Open",lpfile1, NULL,NULL, SW_MAXIMIZE);
		if((int)ret1<=32) AfxMessageBox("could not open the linked document",MB_OK);


		// For second
      char* tok2=strtok(message2[0],"=");
		tok2=strtok(NULL,"=");
		tok2=strtok(NULL,"=");
		char* dir2=strtok(tok2,": ");
		char* filepath2=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy2=new char [strlen(filepath2)];
				strcpy(cpy2,filepath2);
				strcat(dir2,":");
				strcat(dir2,cpy2);
				int len2=strlen(dir2);
				dir2[len2]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile2=dir2;
		HINSTANCE ret2=ShellExecute((HWND)this, "Open",lpfile2, NULL,NULL, SW_MAXIMIZE);
		if((int)ret2<=32) AfxMessageBox("could not open the linked document",MB_OK);


	}

}

void CQAsystemView::OnBUTTONp2() 
{
if(!IsItCompare)
	{
		char* tok=strtok(message[1],"=");
		tok=strtok(NULL,"=");
		tok=strtok(NULL,"=");
		char* dir=strtok(tok,": ");
		char* filepath=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy=new char [strlen(filepath)];
				strcpy(cpy,filepath);
				strcat(dir,":");
				strcat(dir,cpy);
				int len=strlen(dir);
				dir[len]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile=dir;
		HINSTANCE ret=ShellExecute((HWND)this, "Open",lpfile, NULL,NULL, SW_MAXIMIZE);
		if((int)ret<=32) AfxMessageBox("could not open the linked document",MB_OK);
	}
	else
    {
		// For first 
      char* tok1=strtok(message1[1],"=");
		tok1=strtok(NULL,"=");
		tok1=strtok(NULL,"=");
		char* dir1=strtok(tok1,": ");
		char* filepath1=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy1=new char [strlen(filepath1)];
				strcpy(cpy1,filepath1);
				strcat(dir1,":");
				strcat(dir1,cpy1);
				int len1=strlen(dir1);
				dir1[len1]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile1=dir1;
		HINSTANCE ret1=ShellExecute((HWND)this, "Open",lpfile1, NULL,NULL, SW_MAXIMIZE);
		if((int)ret1<=32) AfxMessageBox("could not open the linked document",MB_OK);


		// For second
      char* tok2=strtok(message2[1],"=");
		tok2=strtok(NULL,"=");
		tok2=strtok(NULL,"=");
		char* dir2=strtok(tok2,": ");
		char* filepath2=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy2=new char [strlen(filepath2)];
				strcpy(cpy2,filepath2);
				strcat(dir2,":");
				strcat(dir2,cpy2);
				int len2=strlen(dir2);
				dir2[len2]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile2=dir2;
		HINSTANCE ret2=ShellExecute((HWND)this, "Open",lpfile2, NULL,NULL, SW_MAXIMIZE);
		if((int)ret2<=32) AfxMessageBox("could not open the linked document",MB_OK);


	}
	
}

void CQAsystemView::OnBUTTONp3() 
{
if(!IsItCompare)
	{
		char* tok=strtok(message[2],"=");
		tok=strtok(NULL,"=");
		tok=strtok(NULL,"=");
		char* dir=strtok(tok,": ");
		char* filepath=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy=new char [strlen(filepath)];
				strcpy(cpy,filepath);
				strcat(dir,":");
				strcat(dir,cpy);
				int len=strlen(dir);
				dir[len]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile=dir;
		HINSTANCE ret=ShellExecute((HWND)this, "Open",lpfile, NULL,NULL, SW_MAXIMIZE);
		if((int)ret<=32) AfxMessageBox("could not open the linked document",MB_OK);
	}
	else
    {
		// For first 
      char* tok1=strtok(message1[2],"=");
		tok1=strtok(NULL,"=");
		tok1=strtok(NULL,"=");
		char* dir1=strtok(tok1,": ");
		char* filepath1=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy1=new char [strlen(filepath1)];
				strcpy(cpy1,filepath1);
				strcat(dir1,":");
				strcat(dir1,cpy1);
				int len1=strlen(dir1);
				dir1[len1]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile1=dir1;
		HINSTANCE ret1=ShellExecute((HWND)this, "Open",lpfile1, NULL,NULL, SW_MAXIMIZE);
		if((int)ret1<=32) AfxMessageBox("could not open the linked document",MB_OK);


		// For second
      char* tok2=strtok(message2[2],"=");
		tok2=strtok(NULL,"=");
		tok2=strtok(NULL,"=");
		char* dir2=strtok(tok2,": ");
		char* filepath2=strtok(NULL,": ");
				//AfxMessageBox(dir,MB_OK);
				//AfxMessageBox(filepath,MB_OK);
				char* cpy2=new char [strlen(filepath2)];
				strcpy(cpy2,filepath2);
				strcat(dir2,":");
				strcat(dir2,cpy2);
				int len2=strlen(dir2);
				dir2[len2]='\0';
				//AfxMessageBox(dir,MB_OK);

		LPCTSTR lpfile2=dir2;
		HINSTANCE ret2=ShellExecute((HWND)this, "Open",lpfile2, NULL,NULL, SW_MAXIMIZE);
		if((int)ret2<=32) AfxMessageBox("could not open the linked document",MB_OK);


	}
	
}

void CQAsystemView::OnButton1() 
{

	char final [10000];
	 
	sprintf(final,"this is a test \n =======80%:===== \n what is \033 internet \033 for \n dfgfdg");

	CRichEditCtrl* p=(CRichEditCtrl*) GetDlgItem(IDC_RICHEDIT1);
	CHARFORMAT cf;
	COLORREF color=RGB(255, 0, 0);
	COLORREF color1=RGB(0, 0, 0);
	cf.cbSize		= sizeof(CHARFORMAT);
	cf.dwMask		= CFM_COLOR;
	cf.dwEffects	= 0;	// To disable CFE_AUTOCOLOR
	cf.crTextColor	= color1;
	long nInsertionPoint;
	

	
/*	int t,ch=1;
	char* tok=strtok(final," ");
	
	while(tok)
	{
		
		sprintf(final1," ");
		while(tok&&ch)
		{
			 
			
			t=strlen(tok);
			char temp[20];
			for(int i=0;i<=t-1;i++)
				temp[i]=tok[i];
			//strncpy(temp,tok,t);
			int y=strlen("\033");
			if(strnicmp("\033",temp,y))
			{	ch=0;
				tok=strtok(NULL," ");
				break;}

			else
			{	
				sprintf(final1,"%s %s",final1,temp);
				tok=strtok(NULL," ");}
		}
	*/
		int i=0;
		int ch=1;
		while(final[i])
		{
			char final1[10000];
			int k=0;
			while(final[i]!='\033')
			{	
				if(final[i]=='\0')
				{	ch=0;
					break;
				}
				final1[k]=final[i];
				i++;
				k++;
			}
			final1[k]='\0';
			nInsertionPoint = p->GetWindowTextLength();
			p->SetSel(nInsertionPoint, -1);
			cf.crTextColor	= color1;
			p->SetSelectionCharFormat(cf);
			p->ReplaceSel(final1);
			
			i++;
			int j=0;
			
			if(ch==0)
				break;
			ch=1;
			char key[100];
			while(final[i]!='\033')
			{	
				key[j]=final[i];
				i++;
				j++;
			}
			key[j]='\0';
			i++;
			cf.crTextColor	= color;
			nInsertionPoint = p->GetWindowTextLength();
			p->SetSel(nInsertionPoint, -1);
			p->SetSelectionCharFormat(cf);
			p->ReplaceSel(key);
		}
			
	

}

void CQAsystemView::OnClickRichedit4(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	
	*pResult = 0;
}

void CQAsystemView::OnClickRichedit5(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	
	*pResult = 0;
}


void CQAsystemView::EntityMatching(int count1[], int count2[])
{

for(int j=0;j < Num_Pasg; j++)

{
int *x;
chainIterator c;
x= c.Initialize(chain1[j]);

while(x)
{

for( int p=0; p<Num_Pasg; p++)
	if( chain2[p].search(*x))
	{
	  count1[j]++;
	  count2[p]++;
	}

x= c.Next();
}

}

}

void CQAsystemView::FindPresenceOfEntity()
{
	
for(int i=0; i<length; i++)
{

  for( int k=0; k< Num_Pasg; k++)
 {
	  
  if(strstr(message1[k], Entity[i]))
   chain1[k].insert(i);
  if(strstr(message2[k], Entity[i]))
   chain2[k].insert(i);

 }
}
}

