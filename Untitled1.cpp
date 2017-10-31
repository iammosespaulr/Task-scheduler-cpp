# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<time.h>
# include<math.h>
# include<stdlib.h>
# include<dos.h>
# include<stdio.h>
# include<fstream.h>
#include<windows.h>
#include<iomanip.h>
#include <mmsystem.h>
static string keyword;
static int a,b,cq,ap;
void speak(string apple){
    string command = "tts -v 8 \"" + apple + "\"";    
    const char* charCommand = command.c_str();      
    system(charCommand);   
}
using namespace std;

class  moses_clock
  {
    private:
    int mm,ss,hh,hh1,hh2,mm1,mm2,ss1,ss2;

    public:
    void get();
    void display();
    void pass(tm *a);
    void alarm( moses_clock &c);
  };

void  moses_clock::get()
  {
    e: cout<<"Enter The Time For The Alarm :\t";
		hh1=getch();
	hh1=hh1-48;
	hh2=getch();
	hh2=hh2-48;
	hh=(hh1*10)+hh2;
	cout<<hh<<":";
	
	mm1=getch();
	mm1=mm1-48;
	mm2=getch();
	mm2=mm2-48;
	mm=(mm1*10)+mm2;
	cout<<mm<<":";
	
	ss1=getch();
	ss1=ss1-48;
	ss2=getch();
	ss2=ss2-48;
	ss=(ss1*10)+ss2;
	cout<<ss<<":";
a=hh;b=mm;cq=ss;
   
    if(((hh>23)&&(hh<0))||((mm>59)&&(mm<0))||((ss>59)&&(ss<0)))
      {
        cout<<"\n you have entered invalid time ";
        cout<<"\n please try again";
        goto e;
      }
  }

void  moses_clock::display()
  {
    cout<<endl;
  }

void  moses_clock::pass(tm *a)
  {
     hh = a->tm_hour;
     mm = a->tm_min;
     ss = a->tm_sec;
  }


void  moses_clock::alarm( moses_clock &c)
  {
     moses_clock d;
    long int e;
    int i;
    d.hh = hh-c.hh;
    d.mm = mm-c.mm;
    d.ss = ss-c.ss;
    e = (d.hh*3600)+(d.mm*60)+(d.ss);
    ap = (hh*3600)+(mm*60)+(ss);
    
    for(i=e;i>=1;i--)
      {
      	 clrscr();
      
	moses_clock c1,c2;
    time_t t;
    tm *area;
      	
	   
     time(&t);
   area = localtime(&t);
   c2.pass(area);
   int da=c2.ss-cq;
      	cout<<"Time Selected to Excecute The Program is : "<<a<<":"<<b<<":"<<cq<<endl;
		  cout<<asctime(area)<<"\r";
		 
		  cout<<" Countdown : t"<<da<<" sec(s)";
        Sleep(1000);
        da=da-1;
    
        
        if(c2.ss==cq)
        {
        	clrscr();
        	cout<<"Hello World moses"<<endl;
        	system("notepad")//open exe here
   ;     	break;
        }
      }
   

  }
  
    int main()
{   
	int a;
	moses_clock c1,c2;
    time_t t;
    tm *area;
    clrscr();

    time(&t);
    area = localtime(&t);
    clrscr();
    cout<<endl<<"Program Initialization Time Is : "<<asctime(area)<<endl;
    c1.get();
    c1.display();
    c2.pass(area);
    c1.alarm(c2);
     return 0;
 }
