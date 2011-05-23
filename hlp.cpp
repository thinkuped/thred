#include <windows.h>
#include <stdio.h>
#include "tchar.h"
#include "lang.h"
#include "resource.h"
#include "thred.h"
#include <htmlhelp.h>
#include <locale.h>

extern void				shoMsg(TCHAR* str);
extern unsigned			chkMap(unsigned bPnt);
extern void				ispcdclp();
extern void				movStch();
extern void				rstAll();
extern void				okcan();

extern POINT			zum0;
extern HED				hed;
extern unsigned			delpnt;
extern TCHAR			homdir[MAX_PATH];
extern TCHAR			filnam[MAX_PATH];
extern unsigned			setMap(unsigned bPnt);
extern HWND				hStch;
extern HINSTANCE		hInst;
extern RECT				sRct;
extern HWND				hWnd;
extern TCHAR			msgbuf[MSGSIZ];
extern unsigned			buttonWid3;
extern MSG				msg;
extern unsigned			buttonHi;
extern POINT			stOrg;
extern unsigned			formpnt;
extern unsigned			fselpnt;
extern FRMHED*			frmpnt;
extern FRMHED			formlst[MAXFORMS];
extern unsigned			clofind;
extern HDC				rsdc;
extern RECT				scRct;
extern HWND				hVrt;
extern double			zumFct;
extern unsigned			rstMap(unsigned bPnt);
extern DRAWITEMSTRUCT	*ds;
extern FLPNT			oseq[OSEQLEN];
extern BSEQPNT			bseq[BSEQLEN];
extern INIFIL			ini;
extern HWND				hBar;
extern TCHAR*			phom;
extern TCHAR			thrnam[MAX_PATH];
extern HDC				sdc;
extern long				prfwid;
extern HWND				hbuts[9];
extern void				numWnd();

HANDLE					hlpfil;						//handle to the help file
TCHAR					hlpnam[MAX_PATH];			//help file name
unsigned				fhlplen;					//help file length
HWND					hlpwnd;						//help window
HWND					hMsg=0;						//message window

unsigned short ldlst[]={	//strings to load into memory at init time

	IDS_PIKOL,
	IDS_UPON,
	IDS_UPOF,
	IDS_AUXTXT,
	IDS_HUP0,
	IDS_HUP1,
	IDS_HUP2,
	IDS_HUP3,
	IDS_HUP4,
	IDS_TRC0,
	IDS_TRC1S,
	IDS_TRC2,
	IDS_TRC3,
	IDS_TRC4,
	IDS_TRC1H,
	IDS_NUMPNT,
	IDS_NUMFRM,
	IDS_NUMSCH,
	IDS_NUMFORM,
	IDS_NUMSEL,
	IDS_BOXSEL,
	IDS_CLOS,
	IDS_TOT,
	IDS_LAYR,
	IDS_OVRLOK,
	IDS_OVRIT,
	IDS_THRED,
	IDS_NUFIL,
	IDS_TRIAL,
	IDS_EMB,
	IDS_ON,
	IDS_OFF,
	IDS_FMEN,
	IDS_TXT0,
	IDS_TXT1,
	IDS_TXT2,
	IDS_TXT3,
	IDS_TXT4,
	IDS_TXT5,
	IDS_TXT6,
	IDS_TXT7,
	IDS_TXT8,
	IDS_TXT9,
	IDS_TXT10,
	IDS_TXT11,
	IDS_TXT12,
	IDS_TXT13,
	IDS_TXT14,
	IDS_TXT15,
	IDS_TXT16,
	IDS_TXT17,
	IDS_TXT18,
	IDS_TXT19,
	IDS_TXT20,
	IDS_TXT21,
	IDS_TXT22,
	IDS_TXT23,
	IDS_FIL0,
	IDS_FIL1,
	IDS_FIL2,
	IDS_FIL3,
	IDS_FIL4,
	IDS_FIL5,
	IDS_FIL6,
	IDS_FIL7,
	IDS_FIL8,
	IDS_FIL9,
	IDS_FIL10,
	IDS_FIL11,
	IDS_FIL12,
	IDS_FIL13,
	IDS_EDG0,
	IDS_EDG1,
	IDS_EDG2,
	IDS_EDG3,
	IDS_EDG4,
	IDS_EDG5,
	IDS_EDG6,
	IDS_EDG7,
	IDS_EDG8,
	IDS_EDG9,
	IDS_EDG10,
	IDS_EDG11,
	IDS_EDG12,
	IDS_PRF0, 
	IDS_PRF1, 
	IDS_PRF2, 
	IDS_PRF3, 
	IDS_PRF4, 
	IDS_PRF5, 
	IDS_PRF6, 
	IDS_PRF7, 
	IDS_PRF8, 
	IDS_PRF9, 
	IDS_PRF10,
	IDS_PRF11,
	IDS_PRF12,
	IDS_PRF13,
	IDS_PRF14,
	IDS_PRF15,
	IDS_PRF16,
	IDS_PRF17,
	IDS_PRF18,
	IDS_PRF19,
	IDS_PRF20,
	IDS_PRF21,
	IDS_PRF22,
	IDS_PRF23,
	IDS_PRF24,
	IDS_PRF25,
	IDS_PRF26,
	IDS_PRF27,
	IDS_FRMPLUS,
	IDS_FRMINUS,
	IDS_OKENT,
	IDS_CANCEL,
	IDS_FREH,
	IDS_BLUNT,
	IDS_TAPR,
	IDS_PNTD,
	IDS_SQR,
	IDS_DELST2,
	IDS_THRDBY,
	IDS_STCHOUT,
	IDS_STCHS,
	IDS_FORMS,
	IDS_HUPWID,
	IDS_CREATBY,
	IDS_CUSTHUP,
	IDS_STCHP,
	IDS_FRMP,
	IDS_ENTROT,
	IDS_NUDG,
	IDS_ALLX,
	IDS_FTHCOL,
	IDS_FTHTYP,
	IDS_FTH0,
	IDS_FTH1,
	IDS_FTH2,
	IDS_FTH3,
	IDS_FTH4,
	IDS_FTH5,
	IDS_FTHBLND,
	IDS_FTHUP,
	IDS_FTHBOTH,
	IDS_FTHUPCNT,
	IDS_FTHDWNCNT,
	IDS_FTHSIZ,
	IDS_FTHNUM,
	IDS_FTHFLR,
	IDS_FSTRT,
	IDS_FEND,
	IDS_WALK,
	IDS_UWLKIND,
	IDS_UND,
	IDS_ULEN,
	IDS_FUANG,
	IDS_FUSPAC,
	IDS_CWLK,
	IDS_UNDCOL,
	IDS_FRMBOX,
	IDS_TXOF,
};

TCHAR*	stab[STR_LEN];		//memory string pointers
TCHAR*	sdat;				//string storage

#if PESACT

TCHAR*	shrtmsg=	"PES file header to short: %s\n";
#endif

TCHAR	hlpbuf[HBUFSIZ];	//message formatting buffer

void adbad(unsigned cod,unsigned cnt)
{
	LoadString(hInst,cod,sdat,HBUFSIZ);
	sdat=&sdat[strlen(sdat)];
	LoadString(hInst,IDS_NOTREP,hlpbuf,HBUFSIZ);
	sprintf(sdat,hlpbuf,cnt);
	sdat=&sdat[strlen(sdat)];
}

void hsizmsg()
{
	TCHAR buf[HBUFSIZ];

	LoadString(hInst,IDS_HSIZ,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,zum0.x/PFGRAN,zum0.y/PFGRAN);
	shoMsg(hlpbuf);
}

void msgflt(unsigned msgid,float par)
{
	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,msgid,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,par);
	shoMsg(hlpbuf);
	setMap(NUMIN);
	numWnd();
}

void tsizmsg(TCHAR* sizstr,double siz){

	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,IDS_SIZ,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,sizstr,siz);
	shoMsg(hlpbuf);
	setMap(NUMIN);
	numWnd();
}

void bfilmsg(){

	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,IDS_BADFIL,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,filnam);
	shoMsg(hlpbuf);
}

void filnopn(unsigned cod,TCHAR* nam){

	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,cod,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,nam);
	shoMsg(hlpbuf);
}

void crmsg(TCHAR* nam){

	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,IDS_CREAT,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,nam);
	shoMsg(hlpbuf);
}

void butxt(unsigned ind,TCHAR* str){

	if(chkMap(WASTRAC)&&ind>HNUM){

		if(ind==5){

			if(chkMap(HIDMAP))
				SetWindowText(hbuts[ind],stab[STR_TRC1H]);
			else
				SetWindowText(hbuts[ind],stab[STR_TRC1S]);
		}
		else
			SetWindowText(hbuts[ind],stab[ind-4+STR_TRC0]);
	}
	else
		SetWindowText(hbuts[ind],str);
}

void ritnum(unsigned cod,unsigned num){

	sprintf(hlpbuf,"%s %d",stab[cod],num);
	butxt(HNUM,hlpbuf);
}

void msgstr(unsigned cod){

	LoadString(hInst,cod,msgbuf,MSGSIZ);
}

void lodstr(){

	unsigned	ind,ine,cnt;
	TCHAR*		pchr;
	
	stab[0]=pchr=(TCHAR*)bseq;
	for(ind=0;ind<STR_LEN;ind++){

		cnt=LoadString(hInst,ldlst[ind],pchr,1000)+1;
		pchr+=cnt;
	}
	cnt=pchr-stab[0];
	sdat=new TCHAR[cnt];
	MoveMemory(sdat,stab[0],cnt);
	stab[0]=sdat;
	ine=1;
	for(ind=0;ind<=cnt;ind++){

		if(!sdat[ind]){

			ind++;
			stab[ine]=&sdat[ind];
			ine++;
		}
	}
}

void shoMsg(TCHAR* str){

	SIZE		tsiz,msgsiz;
	TCHAR**		strs;
	unsigned*	lens;
	unsigned	cnt=0,ind=0,ine=0,bak=0;
	long		off;

	while(str[ind]){

		if(str[ind++]==10)
			cnt++;
	}
	cnt++;
	strs=new TCHAR*[cnt+1];
	lens=new unsigned[cnt+1];
	ind=0;
	strs[0]=str;
	while(str[ind]){

		if(str[ind]==10){

			lens[ine]=ind-bak;
			strs[++ine]=&str[ind++];
			bak=ind;
		}
		else
			ind++;
	}
	lens[ine]=ind-bak;
	ine++;
	tsiz.cx=tsiz.cy=msgsiz.cy=msgsiz.cx=0;
	for(ind=0;ind<ine;ind++){

		GetTextExtentPoint32(sdc,strs[ind],lens[ind],&tsiz);
		if(tsiz.cx>msgsiz.cx)
			msgsiz.cx=tsiz.cx;
		if(tsiz.cy>msgsiz.cy)
			msgsiz.cy=tsiz.cy;
	}
	msgsiz.cy*=cnt;
	if(rstMap(MSGOF))
		off=prfwid+6;
	else
		off=3;
	hMsg=CreateWindow(
		"STATIC",
		str,
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		off,
		3,
		msgsiz.cx+20,
		msgsiz.cy+6,
		hStch,
		NULL,
		hInst,
		NULL);
	delete strs;
	delete lens;
}

void keydays(unsigned daz){

	TCHAR buf[HBUFSIZ];
	TCHAR keybuf[HBUFSIZ];
	TCHAR setbuf[HBUFSIZ];
	TCHAR badkbuf[HBUFSIZ];

	if(rstMap(BADVER))
		LoadString(hInst,IDS_KEYVER,badkbuf,HBUFSIZ);
	else
		*badkbuf=0;
	LoadString(hInst,IDS_DAYKEY,buf,HBUFSIZ);
	LoadString(hInst,IDS_KEY,keybuf,HBUFSIZ);
	LoadString(hInst,IDS_SETSTCH,setbuf,HBUFSIZ);

	sprintf(msgbuf,buf,badkbuf,keybuf,daz,setbuf);
	shoMsg(msgbuf);
}

void tabmsg(unsigned cod){

	LoadString(hInst,cod,hlpbuf,HBUFSIZ);
	shoMsg(hlpbuf);
}

void riter(){

	tabmsg(IDS_RITER);
}

void pntmsg(unsigned cod){

	TCHAR	temp[HBUFSIZ];
	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,IDS_PNT,temp,HBUFSIZ);
	LoadString(hInst,cod,buf,HBUFSIZ);
	sprintf(hlpbuf,temp,buf);
	shoMsg(hlpbuf);
}

void shosel(TCHAR* seltxt,TCHAR* selfun){

	sprintf(hlpbuf,"Select %s\n to use %s",seltxt,selfun);
	shoMsg(hlpbuf);
}

void shoseln(unsigned cod0,unsigned cod1){

	TCHAR	temp[HBUFSIZ];
	TCHAR	buf0[HBUFSIZ];
	TCHAR	buf1[HBUFSIZ];

	LoadString(hInst,IDS_SHOSEL,temp,HBUFSIZ);
	LoadString(hInst,cod0,buf0,HBUFSIZ);
	LoadString(hInst,cod1,buf1,HBUFSIZ);
	sprintf(hlpbuf,temp,buf0,buf1);
	shoMsg(hlpbuf);
}

BOOL clpmsgs(unsigned cod){

	ispcdclp();
	if((cod==FML_CLP||cod==FMM_CLP||cod==FML_PIC)&&!chkMap(WASPCDCLP)){

		tabmsg(IDS_CLPS);
		return 1;
	}
	return 0;
}

void frm1pnt(){

	if(formpnt==1){

		setMap(FORMSEL);
		clofind=0;
	}
}

BOOL filmsgs(unsigned cod){

	if(fselpnt)
		return clpmsgs(cod);
	if(formpnt){

		delpnt=hed.stchs;
		frm1pnt();
		if(chkMap(FORMSEL)){

			frmpnt=&formlst[clofind];
			if(frmpnt->sids==2){

				if(cod<FML_LIN){

					tabmsg(IDS_FRM3X);
					return 1;
				}
				else{

					if(cod==FML_PRPS){

						tabmsg(IDS_ANGS);
						return 1;
					}
				}
			}
			return clpmsgs(cod);
		}
		else{

			tabmsg(IDS_FILSEL);
			return 1;
		}
	}
	else{

		tabmsg(IDS_FILCR);
		return 1;
	}
}

void grpmsg(){

	shoseln(IDS_FGRPS,IDS_UNGRP);
}

void grpmsg1(){

	tabmsg(IDS_NOGRP);
}

void help(){

#if LANG==ENG||LANG==HNG
	strcpy(phom,"thred.chm");
#endif
#if LANG==GRM
	strcpy(phom,"aladin.chm");
#endif
	strcpy(hlpnam,homdir);
	hlpwnd=HtmlHelp(hWnd,hlpnam,HH_DISPLAY_TOPIC,0);
	if(!hlpwnd)
		tabmsg(IDS_NOHLP);
}

void sdmsg(){

	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,IDS_SAVDISC,buf,HBUFSIZ);
	sprintf(hlpbuf,buf,thrnam);
	shoMsg(hlpbuf);
}

void alrotmsg(){

	shoseln(IDS_ALLX,IDS_ROTAGIN);
}

void shord(){

	shoseln(IDS_FGRPF,IDS_ROTDUP);
}

void spltmsg(){

	shoseln(IDS_FRMGUID,IDS_SPLT);
}

void datmsg(unsigned cod)
{
	TCHAR*	pchr;

	pchr=msgbuf;
	if(cod&BADFLT)
	{
		LoadString(hInst,IDS_BADFLT,pchr,HBUFSIZ);
		pchr=&pchr[strlen(pchr)];
	}
	if(cod&BADCLP)
	{
		LoadString(hInst,IDS_BADCLP,pchr,HBUFSIZ);
		pchr=&pchr[strlen(pchr)];
	}
	if(cod&BADSAT)
	{
		LoadString(hInst,IDS_BADSAT,pchr,HBUFSIZ);
		pchr=&pchr[strlen(pchr)];
	}
	if(cod&BADTX)
	{
		LoadString(hInst,IDS_BADTX,pchr,HBUFSIZ);
		pchr=&pchr[strlen(pchr)];
	}
	pchr--;
	*pchr=0;
	shoMsg(msgbuf);

}
