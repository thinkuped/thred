#include <windows.h>
#include <stdio.h>
#include <math.h>
#include "tchar.h"
#include "lang.h"
#include "resource.h"
#include "thred.h"

#define GetLastError() ({DWORD e; asm volatile (".byte 0x64\n\tmov %0, 0x20" : "=r" (e)); e;})

void repar();
void tst();
void chktxnum();
void txof();
void rotbak();
void txbak();
void redtbak();
void txdelal();
unsigned dutyp(unsigned tat);
void deltx();

extern void delmclp(unsigned fpnt);
extern void adbad(unsigned cod,unsigned cnt);
extern TCHAR* sdat;
extern void delclps(unsigned ind);
extern void delsac(unsigned fpnt);
extern void chkmen();
extern void datmsg(unsigned cod);
extern void delinf();
extern unsigned clpad;
extern SATCON satks[MAXSAC];
extern FLPNT clps[MAXCLPNTS];
extern unsigned toglu(unsigned bPnt);
extern void wrnmen();
extern unsigned rmap[RMAPSIZ];
extern FLPNT zBoxo;
extern void ritfil();
extern void angclpfn();
extern unsigned clplen;
extern SHRTPNT clpnu[MAXFRMLINS];
extern FLRCT clprct;
extern FLSIZ clpsiz;
extern void centir();
extern void movStch();
extern void hsizmsg();
extern void chkhup();
extern void refilal();
extern void stchrct(FLRCT* rct);
extern void frmrct(FLRCT* rct);
extern void rtrclpfn();
extern FLPNT sPnt;
extern void butxt(unsigned ind,TCHAR* str);
extern void unthum();
extern HWND hStch;
extern unsigned buttonWid3;
extern void redraw(HWND dWnd);
extern HWND hbuts[9];
extern BOOL chkr(unsigned pbit);
extern void setr(unsigned pbit);
extern void clRmap(unsigned len);
extern void zumhom();
extern unsigned buttonHi;
extern POINT flin[MAXFRMLINS];
extern unsigned htclp;
extern TCHAR* thredclp;
extern HGLOBAL hClpMem;
extern FRMHED angfrm;
extern FRMCLP* frmclpdat;
extern HPEN grdPen;
extern unsigned satkad;
extern POINT blin[5];
extern MSG msg;
extern POINT stOrg;
extern unsigned px2stch();
extern HWND hVrt;
extern HWND hHor;
extern HDC sdc;
extern HDC rsdc;
extern RECT scRct;
extern HBRUSH hStchBak;
extern TCHAR filnam[MAX_PATH];
extern void movStch();
extern void shoseln(unsigned cod0,unsigned cod1);
extern unsigned clofine;
extern BOOL isclp(unsigned find);
extern BOOL iseclp(unsigned find);
extern TCHAR hlpbuf[HBUFSIZ];
extern unsigned fselpnt;
extern BOOL isin(float pntx,float pnty);
extern void clpfil();
extern unsigned	apcol;
extern FLPNT lastpnt;
extern void refilfn();
extern void filvrt();
extern unsigned closflt(float px,float py);
extern unsigned short prv(unsigned ind);
extern unsigned getlast();
extern BOOL cisin(float pntx,float pnty);
extern SHRTPNT* hifstch;
extern SATCON* adsatk(unsigned cnt);
extern unsigned rstu(unsigned bPnt);
extern unsigned chku(unsigned bPnt);
extern unsigned setu(unsigned bPnt);
extern unsigned actl;
extern FLPNT* adflt(unsigned cnt);
extern void frmclr(FRMHED* dst);
extern void setmfrm();
extern void mdufrm();
extern unsigned nuflen;
extern FLPNT fmovdif;
extern void dumrk(double pntx,double pnty);
extern DUBRCT zRct;
extern POINT zum0;
extern void unmsg();
extern FLPNT flts[MAXFRMPNTS];
extern FLPNT* flt;
extern unsigned fltad;
extern unsigned char cryptkey[4096];
extern FLPNT angflt[MAXFRMLINS];
extern FRMHED angfrm;
extern void frmcpy(FRMHED* dst,FRMHED* src);
extern float midl(float hi,float lo);
extern DUBPNT rotcntr;
extern void rotflt(FLPNT* pnt);
extern double ang;
extern void filang();
extern void fnhor();
extern FLPNT* lconflt;
extern void lcon();
extern void bakseq();
extern HDC mdc;
extern BOOL chkmax(unsigned arg0,unsigned arg1);
extern unsigned isind;
extern void msgflt(unsigned msgid,float par);
extern unsigned short nxt(unsigned short ind);
extern void mvstchs(unsigned dst,unsigned src,unsigned cnt);
extern void numWnd();
extern void satout(double satwid);
extern void tabmsg(unsigned cod);
extern unsigned auth;
extern void frmout(unsigned ind);
extern TCHAR thrnam[MAX_PATH];
extern TCHAR auxnam[MAX_PATH];
extern void save();
extern COLORREF useCol[16];
extern void ler();
extern char* per;
extern unsigned daz;
extern unsigned psg();
extern unsigned psgacc;
extern void setknots();
extern void refil();
extern void mvstch(SHRTPNT* dst, SHRTPNT* src);
extern BOOL filmsgs(unsigned cod);
extern unsigned find1st();
extern double stspace;
extern void savdo();
extern void delmfil(unsigned col);
extern double usesiz;
extern unsigned actcol;
extern void rseq(unsigned strt,unsigned fin,unsigned ostrt,unsigned at);
extern unsigned delpnt;
extern void makspac(unsigned strt,unsigned cnt);
extern void chkseq(BOOL brd);
extern HWND hWnd;
extern HINSTANCE hInst;
extern INIFIL ini;
extern unsigned xpnt;
extern FLPNT oseq[OSEQLEN];
extern unsigned opnt;
extern unsigned toglMap(unsigned bPnt);
extern unsigned seqpnt;
extern void satfil();
extern unsigned rstMap(unsigned bPnt);
extern void filsat();
extern FRMHED* frmpnt;
extern unsigned clofind;
extern FRMHED formlst[MAXFORMS];
extern void fvars(unsigned ind);
extern void satout(double satwid);
extern FLPNT* opnts;
extern FLPNT* ipnts;
extern void fnvrt();
extern void fshor();
extern void coltab();
extern unsigned setMap(unsigned bPnt);
extern unsigned chkMap(unsigned bPnt);
extern unsigned short sids;
extern HED hed;
extern SHRTPNT stchs[MAXPCS];
extern void mvstch(unsigned dst,unsigned src);
extern unsigned	formpnt;
extern BSEQPNT bseq[BSEQLEN];
extern unsigned fselpnt;
extern unsigned short selist[MAXFORMS];
extern unsigned cloInd;
extern TCHAR msgbuf[MSGSIZ];
extern TCHAR* stab[STR_LEN];
extern void shoMsg(TCHAR* str);
extern void filsfn();

unsigned short daztab[]=
{
	IDS_DAZCRV,
	IDS_DAZSAW,
	IDS_DAZRMP,
	IDS_DAZRAG,
	IDS_DAZCOG,
	IDS_DAZHART,
};

RNGCNT*		txsegs;	//txture fill groups of points
FLRCT		isrct;	//isin rectangle
DUBPNT		sizrat;	//design size ratio
FLRCT		sizrct;	//design size rectangle
float		daspct;	//design aspect ratio
HWND		sizdlg;	//change design size dialog window
FLPNT		dsgnsiz;	//design size
TXPNT		txpnts[MAXSEQ];//buffer for textured fill points
int			txad;	//next textured fill point index
unsigned	txsidtyp; //id of the window being updated
TCHAR		txbuf[16];//texture fill number buffer
int			txnind;	//text number pointer
HWND		hbsid;	//button side window
unsigned	clofbak;//backup for the close form pointer
RECT		txprct; //screen selected textreu points rectangle
TXTRCT		txrct;	//selected texture points rectangle
POINT		cloxref; //original location of selected texture points
int			cloxcnt; //number of selected texture points
unsigned*	cloxlst; //list of selected points
POINT		txtloc;	//texture editor move cursor location
HPEN		xpen; //texture editor cross pen
TXTSCR		tscr; //texture editor layout parameters
TXPNT		txs[MAXSEQ];//textured fill points
TXPNT		txtmp[16384];//temporary storage for textured fill data
unsigned	txis[MAXFORMS];//testured fill indices
unsigned	colord[16];	//color order adjusted for aplique
unsigned	lastcols[16]; //last stitches in a color in a form fill
INTINF		itf;	//interleave data
FLPNT		iseq[MAXSEQ]; //storage for interleave points
unsigned	isind; //index into the interleave points
FSTRTS		fstrts;//fill start data for refill
INSREC		isinds[10];//indices into interleave points
unsigned	isind2;	//index into interleave indices
unsigned	smap;	//fill starts bitmap
unsigned	lastfltx;//last form point used in a fill
unsigned*	frmcnts;//form fill type counters for sort
FLPNT*		uflt;	//underlay offset points
unsigned	fthtyp;	//type of feather fill
float		fthrat;	//feather ratio
float		fthflr;	//smallest stitch allowed
float		flr2;	//twice smallest stitch
float		xrat;	//local feather ratio
float		brat;	//feather ratio from form
unsigned	xat;	//exterded form attribute
unsigned	fthup;	//feather up count
unsigned	fthdwn;	//feather down count
unsigned	fthnum;	//up count plus down count
unsigned	faznum;		
unsigned	faz;
FLPNT		fthseq[MAXSEQ];
unsigned	upfth;
unsigned	dwnfth;
char*		dgbuf;

char*		knam="BhbcT\\BTRdaXch3TbRaX_c^a"; //SystemSecurityDescriptor
char*		ksig="DbTaEP[XSPcX^]2^ST";		  //UserValidationCode
char*		ktim=";XUTBT`dT]RT";			  //LifeSequence

float		fltstp;
float		fltpos;
float		fltfaz;
float		fltup;
float		fltdwn;
float		fltrat;

OREC**		precs;
OREC**		pfrecs;

#pragma warning(disable:4244)

char ftyps[]=
{
	0,	// 0 no type
	1,	// 1 applique
	2,	// 2 center walk
	3,	// 3 edge walk	
	4,	// 4 underlay
	0,	// 5 knot
	5,	// 6 feather
	0,	// 7 layer
	0,	// 8 layer
	0,	// 9 layer
	0,	//10 reserved
	6,	//11 fill
	7,	//12 border
};

TXHST	thsts[16];	//txt editor history headers
int		ptxhst;		//pointer to the next texture history buffer

void setfchk()
{
	if(ini.dchk)
		setMap(FCHK);
}

//#ifdef _DEBUG

void prbug()
{
	OutputDebugString(msgbuf);
}
//#endif

BOOL istx(unsigned find)
{
	FRMHED* pfrm;

	pfrm=&formlst[find];
	if(pfrm->ftyp==TXVRTF)
		return 1;
	if(pfrm->ftyp==TXHORF)
		return 1;
	if(pfrm->ftyp==TXANGF)
		return 1;
	return 0;
}

TXPNT* adtx(int cnt){

	unsigned ind=txad;

	txad+=cnt;
	return &txpnts[ind];
}

void txspac(int strt,unsigned cnt)
{
	unsigned	ind;

	MoveMemory(&txpnts[strt+cnt],&txpnts[strt],(txad-strt)&sizeof(TXPNT));
	for(ind=clofind+1;ind<formpnt;ind++)
	{
		if(istx(ind))
			formlst[ind].dhx.txt.ind+=cnt;
	}
	txad+=cnt;
}

void rstxt()
{
	cloxcnt=0;
	rstMap(TXTMOV);
	rstMap(BZUM);
	rstMap(BZUMIN);
	setMap(RESTCH);
	rstMap(POLIMOV);
	DestroyWindow(hbsid);
	hbsid=0;
	setMap(RESTCH);
}

void txrbak()
{
	ptxhst--;
	ptxhst&=0xf;
}

void txrfor()
{
	ptxhst++;
	ptxhst&=0xf;
}

BOOL chktxh(TXHST* phst)
{
	int ind;

	if(phst->cnt!=tscr.ind)
		return 1;
	if(phst->hi!=tscr.fhi)
		return 1;
	if(phst->spac!=tscr.spac)
		return 1;
	if(phst->wid!=tscr.wid)
		return 1;
	for(ind=0;ind<tscr.ind;ind++)
	{
		if(txtmp[ind].lin!=phst->txp[ind].lin)
			return 1;
		if(txtmp[ind].y!=phst->txp[ind].y)
			return 1;
	}
	return 0;
}

void savtxt()
{
	TXHST*	 phst;

	if(tscr.ind)
	{
		phst=&thsts[ptxhst];
		if(chktxh(phst))
		{
			setMap(WASTXBAK);
			rstMap(TXBDIR);
			rstMap(LASTXBAK);
			txrfor();
			phst=&thsts[ptxhst];
			phst->cnt=tscr.ind;
			phst->hi=tscr.fhi;
			phst->wid=tscr.wid;
			phst->spac=tscr.spac;
			if(phst->txp)
			{
				delete(phst->txp);
				phst->txp=0;
			}
			phst->txp=new TXPNT[phst->cnt];
			MoveMemory(phst->txp,txtmp,phst->cnt*sizeof(TXPNT));
		}
	}
}

void deorg(POINT* pt)
{
	pt->x=msg.pt.x-stOrg.x;
	pt->y=msg.pt.y-stOrg.y;
}

BOOL chkrypt(unsigned arg0,unsigned arg1,unsigned arg2,unsigned arg3){

	if(	cryptkey[100]== arg0&&
		cryptkey[25]==  arg1&&
		cryptkey[104]== arg2&&
		cryptkey[2074]==arg3)
		return 1;
	else
		return 0;
}

void fthvars(){

	rstMap(BARSAT);
	rstMap(FTHR);
	fthtyp=frmpnt->dhx.fth.fthtyp;
	brat=frmpnt->dhx.fth.fthrat;
	fthflr=frmpnt->dhx.fth.fthflr;
	flr2=fthflr*2;
	fthnum=frmpnt->dhx.fth.fthnum;
	xat=frmpnt->xat;
	upfth=fthup=frmpnt->dhx.fth.fthup;
	dwnfth=fthdwn=frmpnt->dhx.fth.fthdwn;
	faznum=fthup+fthdwn;
	if(xat&AT_FTHBLND)
		setMap(BARSAT);
	else
		setMap(FTHR);
}

float durat(float strt,float fin){

	return (fin-strt)*fthrat+strt;
}

float duxrat(float strt,float fin){

	return (fin-strt)*xrat+strt;
}

void duxrats(unsigned strt,unsigned fin,FLPNT* opt){

	opt->x=duxrat(bseq[fin].x,bseq[strt].x);
	opt->y=duxrat(bseq[fin].y,bseq[strt].y);
}

void durats(unsigned ind,FLPNT* pflt){

	double	olen;
	FLPNT	ipnt;

	olen=hypot(bseq[ind+1].x-bseq[ind].x,bseq[ind+1].y-bseq[ind].y);
	if(olen<fthflr){

		pflt->x=bseq[ind].x;
		pflt->y=bseq[ind].y;
	}
	else{

		xrat=fthflr/olen;
		ipnt.x=duxrat(bseq[ind+1].x,bseq[ind].x);
		ipnt.y=duxrat(bseq[ind+1].y,bseq[ind].y);
		pflt->x=durat(ipnt.x,bseq[ind].x);
		pflt->y=durat(ipnt.y,bseq[ind].y);
	}
}

void xoseq(unsigned ind){

	oseq[opnt].x=bseq[ind].x;
	oseq[opnt].y=bseq[ind].y;
	opnt++;
}

void xpfth(unsigned ind){

	fthseq[xpnt].x=bseq[ind].x;
	fthseq[xpnt].y=bseq[ind].y;
	xpnt++;
}

unsigned bpsg(){

	unsigned tmp;

	if(!psgacc)
		psgacc=FSED;
	tmp=psgacc&0x40000008;
	psgacc>>=1;
	if(tmp==0x8||tmp==0x40000000)
		psgacc|=0x40000000;
	return psgacc;
}

void nurat(){

	float	rem;

	rem=fmod(fltpos,1);
	switch(fthtyp){

	case FTHPSG:

		if(fthup){

			if(upfth){

				fthrat=(float)(fthnum-(psg()%fthnum))/fthnum;
				upfth--;
			}
			else{

				fthrat=(float)(fthnum-(bpsg()%fthnum))/fthnum;
				if(dwnfth)
					dwnfth--;
				else{

					psgacc=FSED;
					upfth=fthup;
					dwnfth=fthdwn;
				}
			}
		}
		else
			fthrat=(float)(fthnum-(psg()%fthnum))/fthnum;
		fthrat*=brat;
		break;

	case FTHFAZ:

		if(faz>=fthup)
			fthrat=1;
		else
			fthrat=brat;
		break;

	case FTHSIN:

		if(rem>fltrat)
			fthrat=sin((1-rem)/(1-fltrat)*PI+PI)*0.5+0.5;
		else
			fthrat=sin(rem/fltrat*PI)*0.5+0.5;
		fthrat*=brat;
		break;

	case FTHSIN2:

		if(rem>fltrat)
			fthrat=sin((1-rem)/(1-fltrat)*PI);
		else
			fthrat=sin(rem/fltrat*PI);
		fthrat*=brat;
		break;

	case FTHRMP:

		if(rem>fltrat)
			fthrat=(1-rem)/(1-fltrat);
		else
			fthrat=rem/fltrat;
		fthrat*=brat;
		break;

	case FTHLIN:
	default:

		fthrat=brat;
	}
	++faz%=faznum;
	fltpos+=fltstp;
}

void fthfn(unsigned ind){

	nurat();
	durats(ind,&oseq[ind]);
}

void ratpnt(unsigned pt0,unsigned pt1,FLPNT* opt){

	opt->x=(bseq[pt1].x-bseq[pt0].x)*fthrat+bseq[pt0].x;
	opt->y=(bseq[pt1].y-bseq[pt0].y)*fthrat+bseq[pt0].y;
}

void midpnt(FLPNT pt0,FLPNT pt1,FLPNT* opt){

	opt->x=(pt1.x-pt0.x)*(float)0.5+pt0.x;
	opt->y=(pt1.y-pt0.y)*(float)0.5+pt0.y;
}

void xratf(FLPNT pt0,FLPNT pt1,FLPNT* opt){

	opt->x=(pt1.x-pt0.x)*xrat+pt0.x;
	opt->y=(pt1.y-pt0.y)*xrat+pt0.y;
}

void fthrbfn(unsigned ind){

	FLPNT	pnt0;
	FLPNT	pnt1;
	FLPNT	pnt0h;
	FLPNT	pnt0l;
	FLPNT	pnt1h;
	FLPNT	pnt1l;
	FLPNT	pntm;
	double	len;

	nurat();
	len=hypot(bseq[ind+1].y-bseq[ind].y,bseq[ind+1].x-bseq[ind].x);
	if(len<flr2)
	{
		fthrat=0.5;
		ratpnt(ind,ind+1,&pnt0);
		ratpnt(ind+3,ind+2,&pnt1);
	}
	else
	{
		xrat=fthflr/len;
		duxrats(ind,ind+1,&pnt0l);
		duxrats(ind+3,ind+2,&pnt1l);
		xrat=1-xrat;
		duxrats(ind,ind+1,&pnt0h);
		duxrats(ind+3,ind+2,&pnt1h);
		xrat=fthrat;
		xratf(pnt0l,pnt0h,&pnt0);
		xratf(pnt1l,pnt1h,&pnt1);
	}
	midpnt(pnt0,pnt1,&pntm);
	xoseq(ind);
	oseq[opnt].x=pntm.x;
	oseq[opnt].y=pntm.y;
	opnt++;
	xpfth(ind+1);
	fthseq[xpnt].x=pntm.x;
	fthseq[xpnt].y=pntm.y;
	xpnt++;
}

void duoseq(unsigned ind){

	oseq[ind].x=bseq[ind].x;
	oseq[ind].y=bseq[ind].y;
}

void fthdfn(unsigned ind){

	double	len;
	FLPNT	mpnt;
	FLPNT	pt0;
	FLPNT	pt1;

	nurat();
	len=hypot(bseq[ind+1].y-bseq[ind].y,bseq[ind+1].x-bseq[ind].x);
	duoseq(ind);
	duoseq(ind+1);
	if(len>fthflr){

		xrat=0.5;
		duxrats(ind+1,ind,&mpnt);
		xrat=fthflr/len/2;
		xratf(mpnt,oseq[ind],&pt0);
		xratf(mpnt,oseq[ind+1],&pt1);
		xrat=fthrat;
		xratf(pt0,oseq[ind],&oseq[ind]);
		xratf(pt1,oseq[ind+1],&oseq[ind+1]);
	}
}

void fthrfn(){

	unsigned	ind,res;
	double		bakspac;

	psgacc=FSED;
	fthvars();
	bakspac=stspace;
	stspace=frmpnt->fspac;
	satfil();
	bseq[0].attr=0;
	bseq[1].attr=1;
	if(!faznum)
		faznum=1;
	ind=seqpnt/(faznum<<2);
	res=seqpnt%(faznum<<2);
	if(res>(faznum<<1))
		ind++;
	fltpos=0;
	fltstp=(float)4/seqpnt*ind;
	fltfaz=(float)seqpnt/ind;
	fltrat=(float)upfth/faznum;
	fltup=fltfaz*fltrat;
	fltdwn=fltfaz-fltup;
	frmpnt->ftyp=FTHF;
	faz=1;
	bseq[seqpnt].x=bseq[seqpnt-2].x;
	bseq[seqpnt].y=bseq[seqpnt-2].y;
	bseq[seqpnt].attr=bseq[seqpnt-2].attr;
	bseq[seqpnt+1].x=bseq[seqpnt-1].x;
	bseq[seqpnt+1].y=bseq[seqpnt-1].y;
	bseq[seqpnt+1].attr=bseq[seqpnt-1].attr;
	if(xat&AT_FTHBLND){

		opnt=xpnt=0;
		for(ind=0;ind<seqpnt;ind++)
		{
			if(!bseq[ind].attr)
				fthrbfn(ind);
		}
	}
	else{

		if(frmpnt->xat&AT_FTHDWN){

			for(ind=0;ind<=seqpnt;ind++){

				if(!bseq[ind].attr)
					fthdfn(ind);
			}
			ind--;
		}
		else{

			for(ind=0;ind<=seqpnt;ind++){

				if(bseq[ind].attr){

					if(xat&AT_FTHUP)
						fthfn(ind);
					else
						duoseq(ind);
				}
				else{

					if(xat&AT_FTHUP)
						duoseq(ind);
					else
						fthfn(ind);
				}
			}
			ind--;
		}
		opnt=ind;
	}
	rstMap(FTHR);
	rstMap(BARSAT);
	stspace=bakspac;
	seqpnt=opnt;
}

void fritfil(){

	unsigned ind,ine;

	if(seqpnt){

		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_FIL;
		isinds[isind2].cod=TYPFRM;
		isinds[isind2].col=frmpnt->fcol;
		chkseq(0);
		isind2++;
		if(frmpnt->xat&AT_FTHBLND&&~(frmpnt->xat&(AT_FTHUP|AT_FTHDWN))!=(AT_FTHUP|AT_FTHDWN)){

			isinds[isind2].ind=isind;
			isinds[isind2].seq=I_FTH;
			isinds[isind2].cod=FTHMSK;
			isinds[isind2].col=frmpnt->dhx.fth.fthcol;
			ine=xpnt-1;
			for(ind=0;ind<xpnt;ind++){

				oseq[ind].x=fthseq[ine].x;
				oseq[ind].y=fthseq[ine].y;
				ine--;
			}
			seqpnt=xpnt;
			chkseq(0);
			isind2++;
		}
	}
}

void fethrf(){

	if(formpnt){

		fvars(clofind);
		delclps(clofind);
		deltx();
		frmpnt->typ=SAT;
		frmpnt->dhx.fth.fthrat=ini.fthrat;
		frmpnt->dhx.fth.fthup=ini.fthup;
		frmpnt->dhx.fth.fthdwn=ini.fthdwn;
		frmpnt->dhx.fth.fthtyp=ini.fthtyp;
		frmpnt->dhx.fth.fthflr=ini.fthflr;
		frmpnt->xat&=!(AT_FTHUP|AT_FTHDWN|AT_FTHBLND);
		frmpnt->xat|=ini.fthbits;
		frmpnt->dhx.fth.fthnum=ini.fthnum;
		frmpnt->flencnt.flen=usesiz;
		frmpnt->fspac=stspace;
		frmpnt->fcol=actcol;
		frmpnt->dhx.fth.fthcol=(actcol+1)&COLMSK;
		frmpnt->ftyp=FTHF;
		refilfn();
	}
}

void fethr(){

	unsigned ind;

	if(filmsgs(FMM_FTH))
		return;
	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fethrf();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			fethrf();
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
	}
}

void keynam(unsigned sed,TCHAR* nam){

	unsigned ind;

	ind=1;
	nam[0]='\\';
	nam[1]='s';
	psgacc=sed;
	for(ind=2;ind<20;ind++)
		nam[ind]=psg()%26+0x61;
	nam[ind]=0;
}

ULARGE_INTEGER  tim2int(FILETIME tim){

	ULARGE_INTEGER  op;

	op.LowPart=tim.dwLowDateTime;
	op.HighPart=tim.dwHighDateTime;
	return op;
}

void rstnam(char* dst,char* src){

	unsigned ind;

	ind=0;
	while(src[ind]){
	
		dst[ind]=src[ind]+17;
		ind++;
	}
	dst[ind]=0;
}

void keynams(char* nam,char* sig,char*tim){

	rstnam(nam,knam);
	rstnam(sig,ksig);
	rstnam(tim,ktim);
}

void timnam(char* tpath){

	char	nam[64];
	char*	srut;

	srut=getenv("windir");
	strcpy(tpath,srut);
	strcat(tpath,"\\");
	keynam(TIMSED,nam);
	*nam='t';
	strcat(tpath,nam);
}

void pdiag(char* msg){

	sprintf(dgbuf,"%s\n",msg);
	dgbuf=&dgbuf[strlen(dgbuf)];
}

void ptim(char* msg,FILETIME ftim){

	SYSTEMTIME	stim;

	FileTimeToSystemTime(&ftim,&stim);
	sprintf(dgbuf,"%s %d/%d/%d %d:%d\n",msg,stim.wMonth,stim.wDay,stim.wYear,stim.wHour,stim.wMinute);
	dgbuf=&dgbuf[strlen(dgbuf)];
}

int fil2crd(const char* filnam)
{
	STARTUPINFO			sinfo;
	PROCESS_INFORMATION	pinfo;
	int					erc = 0;
	char				cmd[MAX_PATH*2+1+4];
	
	strcpy(cmd, "\"");
	strcat(cmd, ini.p2cnam);
	strcat(cmd, "\" \"");
	strcat(cmd, filnam);
	strcat(cmd, "\""); 
	memset(&sinfo,0,sizeof(STARTUPINFO));
	sinfo.cb=sizeof(STARTUPINFO);
	if (!CreateProcess(0,cmd,0,0,0,NORMAL_PRIORITY_CLASS,0,0,&sinfo,&pinfo))
	{
		erc=GetLastError();
	}
    return erc;
}

BOOL chkp2cnam(char* nam){

	HANDLE	hp2c;

	hp2c=CreateFile(nam,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
	CloseHandle(hp2c);
	if(hp2c==INVALID_HANDLE_VALUE)
		return 0;
	return 1;
}

void pes2crd(){

#define P2CBUFSIZ 256

	HKEY			hkey;
	unsigned int 	typ,siz;
	TCHAR			prgnam[MAX_PATH];
	char			tfltr[]="ComputerService (Lind2PC.exe)\0LinkP2C.exe\0\0";
	TCHAR			mbuf[P2CBUFSIZ];
	TCHAR			tbuf[P2CBUFSIZ];
	OPENFILENAME	tofn={

	sizeof(OPENFILENAME),	//lStructsize
		hWnd,				//hwndOwner 
		hInst,				//hInstance 
		tfltr,				//lpstrFilter 
		0,					//lpstrCustomFilter 
		0,					//nMaxCustFilter 
		0,					//nFilterIndex 
		prgnam,				//lpstrFile 
		MAX_PATH,			//nMaxFile 
		0,					//lpstrFileTitle 
		0,					//nMaxFileTitle 
		"C:\\",				//lpstr	ialDir 
		0,					//lpstrTitle
		0,					//Flags
		0,					//nFileOffset
		0,					//nFileExtension 
		"exe",				//lpstrDefExt 
		0,					//lCustData 
		0,					//lpfnHook
		0,					//lpTemplateName
	};
	
	if(hed.stchs)
		save();
	else{

		tabmsg(IDS_P2CNODAT);
		return;
	}
	if(chkp2cnam(ini.p2cnam)){

		fil2crd(thrnam);
		return;
	}
	*ini.p2cnam=0;
	if(!RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion",
		0,KEY_READ,&hkey)){

		siz=MAX_PATH;
		typ=REG_SZ;
		if(!RegQueryValueEx(hkey,"ProgramFilesDir",0,&typ,(unsigned char*)prgnam,&siz)){

			strcat(prgnam,"\\Computerservice SSHSBV\\PES2Card\\LinkP2C.exe");
			if(!chkp2cnam(prgnam))
				*prgnam=0;
		}
	}
	if(!*prgnam){

		LoadString(hInst,IDS_P2CMSG,mbuf,P2CBUFSIZ);
		LoadString(hInst,IDS_P2CTITL,tbuf,P2CBUFSIZ);
		if(IDOK==MessageBox(hWnd,mbuf,tbuf,MB_OKCANCEL)){

			if(GetOpenFileName(&tofn)){

				if(!chkp2cnam(prgnam))
					return;
			}
			else
				return;
		}
		else
			return;
	}
	strcpy(ini.p2cnam,prgnam);
	fil2crd(auxnam);
}

void sidlen(unsigned strt,unsigned fin,double* ilen,double* olen)
{
	*ilen+=hypot(ipnts[fin].x-ipnts[strt].x,ipnts[fin].x-ipnts[strt].x);
	*olen+=hypot(opnts[fin].x-opnts[strt].x,opnts[fin].x-opnts[strt].x);
}

FLPNT* insid()
{
	unsigned ind;

	satout(fabs(frmpnt->wind));
	if(frmpnt->wind>0)
	{
		for(ind=0;ind<sids;ind++)
		{
			if(!cisin(ipnts[ind].x,ipnts[ind].y))
			{
				ipnts[ind].x=flt[ind].x;
				ipnts[ind].y=flt[ind].y;
			}
		}
		return ipnts;
	}
	else
		return opnts;
}

void delwlk(unsigned cod)
{
	unsigned	ind,ine;
	SHRTPNT*	histch;
	BOOL		flg;

	ine=0;
	flg=1;
	histch=&stchs[MAXSEQ];
	delpnt=hed.stchs;
	for(ind=0;ind<hed.stchs;ind++)
	{
		if((stchs[ind].at&WLKFMSK)!=cod)
		{
			mvstch(&histch[ine],&stchs[ind]);
			ine++;
		}
		else
		{
			if(flg)
			{
				flg=0;
				delpnt=ind;
			}
		}
	}
	mvstchs(0,MAXSEQ,ine);
	hed.stchs=ine;
	if(ine)
	{
		if(delpnt>(unsigned)hed.stchs)
			delpnt=hed.stchs;
	}
}

void chkuseq()
{
#if BUGBAK
	unsigned ind;

	for(ind=0;ind<opnt;ind++)
	{
		iseq[ind].x=oseq[ind].x;
		iseq[ind].y=oseq[ind].y;
	}
	isind=ind;
	isinds[isind2].col=frmpnt->ucol;
#else

	unsigned	ind,ine,cnt;
	double		len;
	FLPNT		dif;
	FLPNT		loc;
	FLPNT		stp;
	double		ulen;

	if(opnt)
	{
		if(frmpnt->ulen<MINWLK)
			frmpnt->ulen=(float)MINWLK;
		if(frmpnt->ulen>MAXWLK)
			frmpnt->ulen=MAXWLK;
		ulen=frmpnt->ulen;
		for(ind=0;ind<opnt-1;ind++)
		{
			dif.x=oseq[ind+1].x-oseq[ind].x;
			dif.y=oseq[ind+1].y-oseq[ind].y;
			len=hypot(dif.x,dif.y);
			cnt=floor(len/ulen);
			if(cnt)
			{
				stp.x=dif.x/cnt;
				stp.y=dif.y/cnt;
				loc.x=oseq[ind].x;
				loc.y=oseq[ind].y;
				for(ine=0;ine<cnt;ine++)
				{
					iseq[isind].x=loc.x;
					iseq[isind].y=loc.y;
					isind++;
					loc.x+=stp.x;
					loc.y+=stp.y;
				}
			}
			else
			{
				iseq[isind].x=oseq[ind].x;
				iseq[isind].y=oseq[ind].y;
				isind++;
			}
		}
		iseq[isind].x=oseq[ind].x;
		iseq[isind].y=oseq[ind].y;
		isind++;
		isinds[isind2].col=frmpnt->ucol;
	}
#endif
}

void ritwlk()
{
	if(opnt)
	{
		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_FIL;
		isinds[isind2].cod=WLKMSK;
		chkuseq();
		isind2++;
	}
}

void ritcwlk()
{
	if(opnt){

		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_FIL;
		isinds[isind2].cod=CWLKMSK;
		chkuseq();
		isind2++;
	}
}

unsigned gucon(FLPNT pstrt,FLPNT pfin,unsigned dst,unsigned cod)
{
	double		len;
	unsigned	strt,fin,cnt,ifin;
	FLPNT*		ipnt;
	unsigned	up,dwn,ind,ine;
	FLPNT		loc,stp,dif;

	len=hypot(pfin.x-pstrt.x,pfin.y-pstrt.y);
	if(len<5)
		return 0;
	strt=closflt(pstrt.x,pstrt.y);
	fin=closflt(pfin.x,pfin.y);
	if(strt==fin)
		return 0;
//	if(chkMap(ISEND))
//		ipnt=flt;
//	else
		ipnt=insid();
	up=dwn=strt;
gulab:
	if(up==fin)
	{
		rstMap(WLKDIR);
		goto gulabx;
	}
	if(dwn==fin)
	{
		setMap(WLKDIR);
		goto gulabx;
	}
	up=nxt(up);
	dwn=prv(dwn);
	goto gulab;
gulabx:;
	ind=dst;
	while(strt!=fin)
	{
		stchs[ind].x=ipnt[strt].x;
		stchs[ind].y=ipnt[strt].y;
		stchs[ind].at=cod;
		if(ind)
		{
			if(stchs[ind-1].x!=stchs[ind].x||stchs[ind-1].y!=stchs[ind].y)
				ind++;
		}
		else
			ind++;
		if(chkMap(WLKDIR))
			ifin=prv(strt);
		else
			ifin=nxt(strt);
		dif.x=ipnt[ifin].x-ipnt[strt].x;
		dif.y=ipnt[ifin].y-ipnt[strt].y;
		len=hypot(dif.x,dif.y);
		cnt=len/frmpnt->flencnt.flen;
		if(cnt>1)
		{
			stp.x=dif.x/cnt;
			stp.y=dif.y/cnt;
			loc.x=ipnt[strt].x+stp.x;
			loc.y=ipnt[strt].y+stp.y;
			for(ine=0;ine<cnt-1;ine++)
			{
				stchs[ind].x=loc.x;
				stchs[ind].y=loc.y;
				stchs[ind].at=cod;
				ind++;
				loc.x+=stp.x;
				loc.y+=stp.y;
			}
		}
		if(chkMap(WLKDIR))
			strt=prv(strt);
		else
			strt=nxt(strt);
	}
	stchs[ind].x=ipnt[strt].x;
	stchs[ind].y=ipnt[strt].y;
	stchs[ind].at=cod;
	ind++;
	return ind-dst;
}

void fnwlk(unsigned find)
{
	unsigned	strt,cnt;
	FLPNT*		wpnt;

	fvars(clofind);
	if(frmpnt->typ==LIN)
		frmpnt->typ=POLI;
	if(frmpnt->xat&AT_STRT&&frmpnt->typ!=LIN)
		strt=frmpnt->strt;
	else
		strt=0;
	cnt=sids;
	if(frmpnt->typ!=LIN)
		cnt++;
	wpnt=insid();
	opnt=0;
	while(cnt)
	{
		oseq[opnt].x=wpnt[strt].x;
		oseq[opnt].y=wpnt[strt].y;
		strt=nxt(strt);
		opnt++;
		cnt--;
	}
	lastfltx=prv(strt);
	ritwlk();
}

void fnuang(){

	unsigned	ind;

	frmcpy(&angfrm,&formlst[clofind]);
	rotcntr.x=(double)(angfrm.rct.right-angfrm.rct.left)/2+angfrm.rct.left;
	rotcntr.y=(double)(angfrm.rct.top-angfrm.rct.bottom)/2+angfrm.rct.bottom;
	angfrm.flt=angflt;
	for(ind=0;ind<angfrm.sids;ind++){

		angfrm.flt[ind].x=uflt[ind].x;
		angfrm.flt[ind].y=uflt[ind].y;
		rotflt(&angfrm.flt[ind]);
	}
	frmpnt=&angfrm;
	fnvrt();
	fvars(clofind);
}

void ritund()
{
	if(seqpnt){

		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_FIL;
		isinds[isind2].cod=UNDMSK;
		chkuseq();
		isind2++;
	}
}

void undclp()
{
	clpsiz.cx=clprct.bottom=clprct.left=clprct.right=clpnu[0].x=clpnu[1].x=clpnu[0].y=0;
	clpsiz.cy=clprct.top=clpnu[1].y=frmpnt->ulen;
	clplen=2;
}

void fnund(unsigned find)
{
	float baksiz;
	uflt=insid();
	baksiz=usesiz;
	usesiz=1e99;
	if(!frmpnt->uspac)
		frmpnt->uspac=ini.uspac;
	if(!frmpnt->ulen)
		frmpnt->ulen=ini.ulen;
	undclp();
	setMap(ISUND);
	angclpfn();
	opnt=seqpnt;
	ritund();
	fvars(clofind);
	usesiz=baksiz;
}

void fncwlk(unsigned find)
{
	unsigned	ind,ine,strt,fin;
	SATCON*		sac;

	opnt=0;
	frmpnt->xat|=AT_CWLK;
	if(frmpnt->stpt)
	{
		if(frmpnt->wpar)
		{
			ine=frmpnt->wpar;
			oseq[opnt].x=midl(flt[ine].x,flt[ine+1].x);
			oseq[opnt].y=midl(flt[ine].y,flt[ine+1].y);
			opnt++;
		}
		sac=frmpnt->sacang.sac;
		for(ind=frmpnt->stpt-1;ind<frmpnt->stpt;ind--)
		{
			oseq[opnt].x=midl(flt[sac[ind].fin].x,flt[sac[ind].strt].x);
			oseq[opnt].y=midl(flt[sac[ind].fin].y,flt[sac[ind].strt].y);
			opnt++;
		}
		if(frmpnt->at&FRMEND)
		{
			oseq[opnt].x=midl(flt[0].x,flt[1].x);
			oseq[opnt].y=midl(flt[0].y,flt[1].y);
			opnt++;
		}
	}
	else
	{
		if(frmpnt->xat&AT_STRT)
			strt=frmpnt->strt;
		else
			strt=0;
		oseq[opnt].x=flt[strt].x;
		oseq[opnt].y=flt[strt].y;
		opnt++;
		fin=prv(strt);
		strt=nxt(strt);
		for(ind=1;ind<(unsigned)sids>>1;ind++)
		{
			oseq[opnt].x=midl(flt[fin].x,flt[strt].x);
			oseq[opnt].y=midl(flt[fin].y,flt[strt].y);
			if(cisin(oseq[opnt].x,oseq[opnt].y))
				opnt++;
			strt=nxt(strt);
			fin=prv(fin);
		}
		oseq[opnt].x=flt[strt].x;
		oseq[opnt].y=flt[strt].y;
		opnt++;
	}
	ritcwlk();
}

BOOL CALLBACK fthdefprc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam){

	TCHAR		buf[HBUFSIZ];
	TCHAR		buf1[HBUFSIZ];
	unsigned	ind,stat,xat;

	switch(umsg){

	case WM_INITDIALOG:

		xat=ini.fthbits;
		SendMessage(hwndlg,WM_SETFOCUS,0,0);
		sprintf(buf,"%.2f",ini.fthrat);
		SetWindowText(GetDlgItem(hwndlg,IDC_DFRAT),buf);
		sprintf(buf,"%d",ini.fthup);
		SetWindowText(GetDlgItem(hwndlg,IDC_DFUPCNT),buf);
		sprintf(buf,"%d",ini.fthdwn);
		SetWindowText(GetDlgItem(hwndlg,IDC_DFDWNCNT),buf);
		sprintf(buf,"%.2f",ini.fthflr/PFGRAN);
		SetWindowText(GetDlgItem(hwndlg,IDC_DFLR),buf);
		sprintf(buf,"%d",ini.fthnum);
		SetWindowText(GetDlgItem(hwndlg,IDC_DFNUM),buf);
		for(ind=0;ind<6;ind++){

			LoadString(hInst,IDS_FTH0+ind,buf,HBUFSIZ);
			SendMessage(GetDlgItem(hwndlg,IDC_FDTYP),CB_ADDSTRING,0,(long)buf);
		}
		SendMessage(GetDlgItem(hwndlg,IDC_FDTYP),CB_SETCURSEL,ini.fthtyp-1,0);
		if(xat&AT_FTHBLND)
			stat=BST_CHECKED;
		else
			stat=BST_UNCHECKED;
		CheckDlgButton(hwndlg,IDC_FDBLND,stat);
		if(xat&AT_FTHUP)
			stat=BST_CHECKED;
		else
			stat=BST_UNCHECKED;
		CheckDlgButton(hwndlg,IDC_FDUP,stat);
		if(xat&AT_FTHDWN)
			stat=BST_CHECKED;
		else
			stat=BST_UNCHECKED;
		CheckDlgButton(hwndlg,IDC_FDWN,stat);
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam)){

		case IDCANCEL:

			EndDialog(hwndlg,0); 
			return TRUE;

		case IDOK:

			ini.fthbits=0;
			if(IsDlgButtonChecked(hwndlg,IDC_FDBLND))
				ini.fthbits=AT_FTHBLND;
			if(IsDlgButtonChecked(hwndlg,IDC_FDUP))
				ini.fthbits|=AT_FTHUP;
			if(IsDlgButtonChecked(hwndlg,IDC_FDWN))
				ini.fthbits|=AT_FTHDWN;
			GetWindowText(GetDlgItem(hwndlg,IDC_FDTYP),buf,HBUFSIZ);
			ini.fthtyp=FDEFTYP;
			for(ind=0;ind<6;ind++){

				LoadString(hInst,IDS_FTH0+ind,buf1,HBUFSIZ);
				if(!strcmp(buf,buf1)){

					ini.fthtyp=ind+1;
					break;
				}
			}
			GetWindowText(GetDlgItem(hwndlg,IDC_DFRAT),buf,HBUFSIZ);
			ini.fthrat=atof(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_DFUPCNT),buf,HBUFSIZ);
			ini.fthup=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_DFDWNCNT),buf,HBUFSIZ);
			ini.fthdwn=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_DFLR),buf,HBUFSIZ);
			ini.fthflr=atof(buf)*PFGRAN;
			GetWindowText(GetDlgItem(hwndlg,IDC_DFNUM),buf,HBUFSIZ);
			ini.fthnum=atoi(buf);
			if(ini.fthnum<1)
				ini.fthnum=1;
			EndDialog(hwndlg,1);
			break;
		}
	}
	return 0;
}

void dufdef(){

	DialogBox(hInst,MAKEINTRESOURCE(IDD_FETHDEF),hWnd,(DLGPROC)fthdefprc);
}

void srtcol(){

	unsigned		hst[16];
	unsigned		ind,ine,tmp;
	SHRTPNT*		phi;

	FillMemory(&hst,64,0);
	for(ind=0;ind<hed.stchs;ind++)
		hst[stchs[ind].at&COLMSK]++;
	ine=0;
	for(ind=0;ind<16;ind++){

		tmp=hst[ind];
		hst[ind]=ine;
		ine+=tmp;
	}
	phi=&stchs[MAXSEQ];
	for(ind=0;ind<hed.stchs;ind++)
		mvstch(&phi[hst[stchs[ind].at&COLMSK]++],&stchs[ind]);
	MoveMemory(&stchs,phi,sizeof(SHRTPNT)*hed.stchs);
}

void dubdel(unsigned cod){

	if(chkMap(WASDEL))
		return;
	delpnt=hed.stchs;
}

void dubit(unsigned bit)
{
	unsigned cod;

	savdo();
	setMap(WASDO);
	if(frmpnt->typ==LIN)
		frmpnt->typ=POLI;
	if(!(frmpnt->xat&(AT_UND|AT_WALK|AT_CWLK))&&bit&(AT_UND|AT_WALK|AT_CWLK))
	{
		if(frmpnt->ftyp)
			frmpnt->ucol=frmpnt->fcol;
		else
			frmpnt->ucol=actcol;
		frmpnt->ulen=ini.ulen;
	}
	if(!(frmpnt->xat&AT_UND)&&bit&AT_UND)
	{
		frmpnt->uang=ini.uang;
		frmpnt->uspac=ini.uspac;
	}
	cod=frmpnt->xat&bit;
	if(cod)
		frmpnt->xat&=(~bit);
	else
		frmpnt->xat|=bit;
	refil();
	coltab();
	setMap(RESTCH);
}

void setuang()
{
	setMap(GTUANG);
	msgflt(IDS_UANG,ini.uang/PI*180);
}

void setuspac()
{
	setMap(GTUSPAC);
	msgflt(IDS_USPAC,ini.uspac/PFGRAN);
}

void setwlkind()
{
	setMap(GTWLKIND);
	msgflt(IDS_WLKIND,ini.wind/PFGRAN);
}

void setulen()
{
	setMap(GTWLKLEN);
	msgflt(IDS_WLKLEN,ini.ulen/PFGRAN);
}

void chkcwlk()
{
	if(frmpnt->xat&AT_CWLK)
		fncwlk(clofind);
	else
		delwlk((clofind<<FRMSHFT)|CWLKMSK);
}

void chkwlk()
{
	if(frmpnt->xat&AT_WALK)
		fnwlk(clofind);
	else
		delwlk((clofind<<FRMSHFT)|WLKMSK);
}

void chkund()
{
	if(frmpnt->xat&AT_UND)
		fnund(clofind);
	else
		delwlk((clofind<<FRMSHFT)|UNDMSK);
}

void selalfrm()
{
	for(fselpnt=0;fselpnt<formpnt;fselpnt++)
		selist[fselpnt]=fselpnt;
	setMap(RESTCH);
}

void chkdaz()
{
	float	len;

	if(!ini.dazcnt)
		ini.dazcnt=1;
	if(!ini.dazicnt)
		ini.dazicnt=1;
	if(!ini.dazpet)
		ini.dazpet=1;
	len=ini.dazlen*0.999;
	if(ini.dazpcnt>ini.dazcnt)
		ini.dazpcnt=ini.dazcnt;
}

void dazdef()
{
	ini.dazcnt=DAZCNT;
	ini.dazhlen=DAZHLEN;
	ini.dazicnt=DAZICNT;
	ini.dazlen=DAZLEN;
	ini.dazpet=DAZPETS;
	ini.dazplen=DAZPLEN;
	ini.dazpcnt=DAZMCNT;
	setu(DAZHOL);
	setu(DAZD);
	ini.daztyp=DAZTYP;
}

BOOL CALLBACK dasyproc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam)
{
	TCHAR		buf[HBUFSIZ];
	TCHAR		buf1[HBUFSIZ];
	unsigned	ind;

	switch(umsg){

	case WM_INITDIALOG:

		SendMessage(hwndlg,WM_SETFOCUS,0,0);
reinit:;
		chkdaz();
		sprintf(buf,"%d",ini.dazcnt);
		SetWindowText(GetDlgItem(hwndlg,IDC_PETLPNTS),buf);
		sprintf(buf,"%d",ini.dazpcnt);
		SetWindowText(GetDlgItem(hwndlg,IDC_DAZPCNT),buf);
		sprintf(buf,"%.2f",ini.dazlen);
		SetWindowText(GetDlgItem(hwndlg,IDC_CNTLEN),buf);
		sprintf(buf,"%.2f",ini.dazhlen);
		SetWindowText(GetDlgItem(hwndlg,IDC_HOLSIZ),buf);
		sprintf(buf,"%d",ini.dazicnt);
		SetWindowText(GetDlgItem(hwndlg,IDC_INPNTS),buf);
		sprintf(buf,"%d",ini.dazpet);
		SetWindowText(GetDlgItem(hwndlg,IDC_PETALS),buf);
		sprintf(buf,"%.2f",ini.dazplen);
		SetWindowText(GetDlgItem(hwndlg,IDC_PETLEN),buf);
		CheckDlgButton(hwndlg,IDC_HOLE,chku(DAZHOL));
		CheckDlgButton(hwndlg,IDC_DLIN,chku(DAZD));
		for(ind=0;ind<6;ind++)
		{
			LoadString(hInst,daztab[ind],buf,HBUFSIZ);
			SendMessage(GetDlgItem(hwndlg,IDC_DAZTYP),CB_ADDSTRING,0,(long)buf);
		}
		SendMessage(GetDlgItem(hwndlg,IDC_DAZTYP),CB_SETCURSEL,ini.daztyp,0);
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam)){

		case IDCANCEL:

			EndDialog(hwndlg,0); 
			return TRUE;

		case IDOK:

			GetWindowText(GetDlgItem(hwndlg,IDC_PETLPNTS),buf,HBUFSIZ);
			ini.dazcnt=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_DAZPCNT),buf,HBUFSIZ);
			ini.dazpcnt=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_CNTLEN),buf,HBUFSIZ);
			ini.dazlen=atof(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_HOLSIZ),buf,HBUFSIZ);
			ini.dazhlen=atof(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_INPNTS),buf,HBUFSIZ);
			ini.dazicnt=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_PETALS),buf,HBUFSIZ);
			ini.dazpet=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_PETLEN),buf,HBUFSIZ);
			ini.dazplen=atof(buf);
			if(IsDlgButtonChecked(hwndlg,IDC_HOLE))
				setu(DAZHOL);
			else
				rstu(DAZHOL);
			if(IsDlgButtonChecked(hwndlg,IDC_DLIN))
				setu(DAZD);
			else
				rstu(DAZD);
			GetWindowText(GetDlgItem(hwndlg,IDC_DAZTYP),buf,HBUFSIZ);
			for(ind=0;ind<6;ind++)
			{
				LoadString(hInst,daztab[ind],buf1,HBUFSIZ);
				if(!strcmp(buf,buf1))
				{
					ini.daztyp=ind;
					break;
				}
			}
			chkdaz();
			EndDialog(hwndlg,1);
			break;

		case IDC_DAZRST:

			dazdef();
			goto reinit;

		case IDC_DLIN:

			if(IsDlgButtonChecked(hwndlg,IDC_DLIN))
				CheckDlgButton(hwndlg,IDC_HOLE,BST_CHECKED);
			break;

		case IDC_HOLE:

			if(!IsDlgButtonChecked(hwndlg,IDC_HOLE))
				CheckDlgButton(hwndlg,IDC_DLIN,BST_UNCHECKED);
			break;
		}
	}
	return 0;
}

void dasyfrm(){

	double		dang;
	double		pang;
	double		dangp;
	double		pangp;
	unsigned	bcnt,ind,ine,inf,dtyp,dcnt,cnt2,fref,pcnt;
	double		dlen;
	double		len;
	double		elen;
	double		ilen;
	double		drat;
	float		maxcor;
	FLPNT		ref;

	unmsg();
	if(!DialogBox(hInst,MAKEINTRESOURCE(IDD_DASY),hWnd,(DLGPROC)dasyproc))
	{
		rstMap(FORMIN);
		return;
	}
	ini.dazpet=ini.dazpet;
	len=ini.dazlen;
	elen=ini.dazplen;
	ilen=ini.dazhlen;
	dtyp=ini.daztyp;
	ref.x=midl(zRct.right,zRct.left);
	ref.y=midl(zRct.top,zRct.bottom);
	frmpnt=&formlst[formpnt];
	clofind=formpnt;
	frmclr(frmpnt);
	frmpnt->flt=&flts[fltad];
	frmpnt->at=actl<<1;
	fvars(formpnt);
	cnt2=ini.dazcnt>>1;
	maxcor=zRct.right-zRct.left;
	drat=zRct.top-zRct.bottom;
	if(drat>maxcor)
		maxcor=drat;
	maxcor/=6;
	drat=(double)maxcor/(len+elen);
	len*=drat;
	elen*=drat;
	ilen*=drat;
	frmpnt->typ=POLI;
	inf=0;
	if(chku(DAZHOL))
	{
		pang=PI2;
		bcnt=ini.dazpet*ini.dazicnt;
		dang=PI2/bcnt;
		flt[inf].x=ref.x+len*cos(pang);
		flt[inf].y=ref.y+len*sin(pang);
		inf++;
		for(ind=0;ind<bcnt+1;ind++)
		{
			flt[inf].x=ref.x+ilen*cos(pang);
			flt[inf].y=ref.y+ilen*sin(pang);
			inf++;
			pang-=dang;
		}
		fref=inf;
	}
	pang=0;
	bcnt=ini.dazpet*ini.dazcnt;
	pcnt=ini.dazcnt;
	if(dtyp==DHART)
	{
		pcnt=(ini.dazpcnt+1)<<1;
		bcnt=ini.dazpet*pcnt;
	}
	dang=PI2/bcnt;
	dangp=PI/ini.dazcnt;
	if(chku(DAZD))
	{
		frmpnt->stpt=ini.dazpet-1;
		frmpnt->wpar=ini.dazpet*ini.dazicnt+1;
		frmpnt->sacang.sac=adsatk(ini.dazpet-1);
	}
	for(ind=0;ind<ini.dazpet;ind++)
	{
		pangp=0;
		psgacc=SEED;
		for(ine=0;ine<pcnt;ine++)
		{
			switch(dtyp)
			{
			case DSIN:

				dlen=len+sin(pangp)*elen;
				pangp+=dangp;
				break;

			case DRAMP:
				
				dlen=len+(double)ine/ini.dazcnt*elen;
				break;

			case DSAW:
				
				if(ine>cnt2)
					dcnt=ini.dazcnt-ine;
				else
					dcnt=ine;
				dlen=len+(double)dcnt/ini.dazcnt*elen;
				break;

			case DRAG:

				dlen=len+(double)(psg()%ini.dazcnt)/ini.dazcnt*elen;
				break;

			case DCOG:

				dlen=len;
				if(ine>cnt2)
					dlen+=elen;
				break;

			case DHART:

				dlen=len+sin(pangp)*elen;
				if(ine>ini.dazpcnt)
					pangp-=dangp;
				else
					pangp+=dangp;
				break;
			}
			flt[inf].x=ref.x+cos(pang)*dlen;
			flt[inf].y=ref.y+sin(pang)*dlen;
			inf++;
			pang+=dang;
			if(chku(DAZD)&&ind!=ini.dazpet-1)
			{
				frmpnt->sacang.sac[ind].strt=(ini.dazpet-ind-1)*ini.dazicnt+1;
				frmpnt->sacang.sac[ind].fin=inf;
			}
		}
	}
	if(chku(DAZHOL))
	{
		flt[fref-1].y+=(float)0.01;
		flt[fref].y+=(float)0.01;
	}
	frmpnt->sids=inf;
	if(chku(DAZD))
	{
		frmpnt->typ=SAT;
		frmpnt->at=1;
	}
	fltad+=inf;
	setMap(INIT);
	frmout(formpnt);
	for(ind=0;ind<inf;ind++){

		flt[ind].x-=frmpnt->rct.left;
		flt[ind].y-=frmpnt->rct.bottom;
	}
	fmovdif.x=fmovdif.y=0;
	nuflen=inf+1;
	setMap(POLIMOV);
	setmfrm();
	mdufrm();
}

void durec(OREC* prec)
{
	unsigned	at;
	SHRTPNT*	pstch;

	pstch=&stchs[prec->strt];
	prec->typ=ftyps[dutyp(pstch->at)];
	at=pstch->at&SRTMSK;
	prec->col=at&0xf;
	prec->frm=(at&FRMSK)>>FRMSHFT;
}

#pragma warning(disable:4035;once:)

OREC*	recref(const void* arg)
{
#if !defined(GCC__)
	__asm
	{
			mov		eax,arg
			mov		eax,[eax]
	}
#else
	__asm__ __volatile__
	(

	"	mov		eax,%[arg]\n"
	"	mov		eax,[eax]\n"

	:
	:	[arg] "m" (arg)
	:	"eax"
	);
#endif
}

int recmp(const void *arg1, const void *arg2)
{
	OREC* pa1;
	OREC* pa2;

	pa1=recref((const void*) arg1);
	pa2=recref((const void*) arg2);
	if(colord[pa1->col]==colord[pa2->col])
	{
		if(pa1->frm==pa2->frm)
		{
			if(pa1->typ==pa2->typ)
				return (int)pa1->strt-pa2->strt;
			else
				return (int)pa1->typ-pa2->typ;
		}
		else
			return (int)pa1->frm-pa2->frm;
	}
	return (int)colord[pa1->col]-colord[pa2->col];
}

/*
int recmp(const void *arg1, const void *arg2)
{
	OREC* pa1;
	OREC* pa2;

	pa1=recref((const void*) arg1);
	pa2=recref((const void*) arg2);
	if(colord[pa1->col]==colord[pa2->col])
	{
		if(pa1->frm==pa2->frm)
		{
			if(pa1->typ==pa2->typ)
			{
				if(pa1->strt==pa2->strt)
					return 0;
				if(pa1->strt>pa2->strt)
					return 1;
				return -1;
			}
			if(pa1->typ>pa2->typ)
				return 1;
			return -1;
		}
		if(pa1->frm>pa2->frm)
			return 1;
		return -1;
	}
	if(colord[pa1->col]>colord[pa2->col])
		return 1;
	return -1;
}*/

int refcmp(const void *arg1, const void *arg2)
{
	OREC* pa1;
	OREC* pa2;

	pa1=recref((const void*) arg1);
	pa2=recref((const void*) arg2);
	if(pa1->frm==pa2->frm)
		return (int)pa1->typ-pa2->typ;
	return (int)pa1->frm-pa2->frm;
}

double srtlen(SHRTPNT* pnt,OREC* prec,unsigned swtch)
{
	SHRTPNT* tpnt;

	if(swtch)
		tpnt=prec->epnt;
	else
		tpnt=prec->spnt;
	return hypot(pnt->x-tpnt->x,pnt->y-tpnt->y);
}

BOOL chkrdun(SRTREC* psrec)
{
	unsigned ind;

	for(ind=psrec->strt;ind<psrec->fin;ind++)
	{
		if(precs[ind]->otyp==frmcnts[precs[ind]->frm])
			return 1;
	}
	return 0;
}

double precjmps(SRTREC* psrec)
{
	unsigned		totjmps;
	double			len;
	double			minlen;
	unsigned		ind,loc,loci;
	SHRTPNT*		ploc;
	BOOL			locdir;

	frmcnts=(unsigned*)&oseq;
	FillMemory(&oseq,(xpnt+2)<<2,0);
	loc=psrec->loc;
	locdir=psrec->dir;
	totjmps=0;
	while(chkrdun(psrec))
	{
		minlen=1e9;
		if(locdir)
			loci=precs[loc]->fin;
		else
			loci=precs[loc]->strt;
		ploc=&stchs[loci];
		for(ind=psrec->strt;ind<psrec->fin;ind++)
		{
			if(precs[ind]->otyp==frmcnts[precs[ind]->frm])
			{
				len=hypot(precs[ind]->spnt->x-ploc->x,precs[ind]->spnt->y-ploc->y);
				if(len<minlen)
				{
					minlen=len;
					locdir=0;
					loc=ind;
				}
				len=hypot(precs[ind]->epnt->x-ploc->x,precs[ind]->epnt->y-ploc->y);
				if(len<minlen)
				{
					minlen=len;
					locdir=1;
					loc=ind;
				}
			}
		}
		if(minlen>9*PFGRAN)
			totjmps++;
		frmcnts[precs[loc]->frm]++;
		if(chkMap(DUSRT))
		{
			if(locdir)
			{
				if(precs[loc]->strt)
				{
					for(ind=precs[loc]->fin-1;ind>=precs[loc]->strt;ind--)
						mvstch(&hifstch[opnt++],&stchs[ind]);
				}
				else
				{
					ind=precs[loc]->fin;
					while(ind)
						mvstch(&hifstch[opnt++],&stchs[--ind]);
				}
			}
			else
			{
				for(ind=precs[loc]->strt;ind<precs[loc]->fin;ind++)
					mvstch(&hifstch[opnt++],&stchs[ind]);
			}
		}
	}
	return totjmps;
}

unsigned duprecs(SRTREC* prec)
{
	unsigned jmps0;
	unsigned jmps1;

	prec->dir=0;
	jmps0=precjmps(prec);
	prec->dir=1;
	jmps1=precjmps(prec);
	if(jmps0<jmps1)
	{
		prec->dir=0;
		return jmps0;
	}
	prec->dir=1;
	return jmps1;
}

#ifdef _DEBUG

void dmprec(OREC** recs,unsigned cnt)
{
	unsigned ind;

	for(ind=0;ind<cnt;ind++)
	{
		sprintf(msgbuf,"%4d off: %4d at: %08x frm: %4d typ: %d col: %2d st: %5d fin: %5d\n",
			ind,
			recs[ind]-(OREC*)bseq,
			stchs[recs[ind]->strt].at,
			recs[ind]->frm,
			recs[ind]->typ,
			recs[ind]->col,
			recs[ind]->strt,
			recs[ind]->fin);
		OutputDebugString(msgbuf);
	}
}
#endif

BOOL srtchk(OREC** pfrec,unsigned cnt,unsigned* badfrm)
{
	unsigned ind,frm,hcol;
	FRMHED* fp;

	frm=pfrec[0]->frm;
	hcol=pfrec[0]->col;
	for(ind=1;ind<cnt;ind++)
	{
		if(pfrec[ind]->frm==frm)
		{
			if(colord[pfrec[ind]->col]<colord[hcol])
			{
				fp=&formlst[frm];
				if(fp->ftyp==FTHF&&fp->xat&AT_FTHBLND&&pfrec[ind]->col==fp->fcol)
					continue;
				*badfrm=ind;
				return 0;
			}
			else
				hcol=pfrec[ind]->col;
		}
		else
		{
			hcol=pfrec[ind]->col;
			frm=pfrec[ind]->frm;
		}
	}
	return 1;
}

void fsort()
{
	unsigned		ind,ine,pind,at,cfrm,rind,mind,mindir;
	unsigned		typcnt,jmps,minjmps;
	OREC*			recs;
	RANG*			prngs;
	unsigned*		frmcnts;
	SRTREC			srec;
	FILETIME		ftim;
	ULARGE_INTEGER	stim;
	ULARGE_INTEGER	ntim;

	savdo();
	recs=(OREC*)&bseq;
	recs->strt=0;
	recs->spnt=stchs;
	at=stchs->at&SRTMSK;
	rind=0;
	xpnt=formpnt;
	colord[apcol]=0;
	for(ind=0;ind<16;ind++){

		if(ind!=apcol)
			colord[ind]=ind+1;
	}
	for(ind=1;ind<hed.stchs;ind++)
	{
		if((stchs[ind].at&SRTMSK)!=at)
		{
			recs[rind].fin=ind;
			recs[rind].epnt=&stchs[ind-1];
			rind++;
			recs[rind].strt=ind;
			recs[rind].spnt=&stchs[ind];
			at=stchs[ind].at&SRTMSK;
		}
	}
	recs[rind].epnt=&stchs[hed.stchs-1];
	recs[rind].fin=hed.stchs;
	rind++;
	precs=(OREC**)&recs[rind];
	pfrecs=(OREC**)&recs[rind<<1];
	for(ind=0;ind<rind;ind++)
	{
		durec(&recs[ind]);
		precs[ind]=&recs[ind];
		pfrecs[ind]=&recs[ind];
	}
	qsort((void*)precs,rind,4,recmp);
	qsort((void*)pfrecs,rind,4,refcmp);
#ifdef _DEBUG
//	dmprec(precs,rind);
#endif
	if(srtchk(pfrecs,rind,&ine))
	{
		prngs=(RANG*)&precs[rind];
		prngs[0].strt=0;
		at=precs[0]->col;
		cfrm=0xffffffff;
		typcnt=0;
		pind=0;
		frmcnts=(unsigned*)&oseq;
		for(ind=0;ind<rind;ind++)
		{
			if(at!=precs[ind]->col)
			{	
				prngs[pind].fin=ind;
				pind++;
				prngs[pind].strt=ind;
				at=precs[ind]->col;
				cfrm=precs[ind]->frm;
				typcnt=0;
				goto srtskp;
			}
			if(precs[ind]->frm==cfrm)
				typcnt++;
			else
			{
				typcnt=0;
				cfrm=precs[ind]->frm;
			}
srtskp:;
			precs[ind]->otyp=typcnt;
		}
		prngs[pind].fin=rind;
		pind++;
		hifstch=&stchs[MAXSEQ];
		opnt=0;
		for(ind=0;ind<pind;ind++)
		{
			rstMap(DUSRT);
			srec.strt=prngs[ind].strt;
			srec.fin=prngs[ind].fin;
			srec.cnt=srec.fin-srec.strt;
			minjmps=0xffffffff;
			GetSystemTimeAsFileTime(&ftim);
			stim=tim2int(ftim);
			for(ine=srec.strt;ine<srec.fin;ine++)
			{
				srec.loc=ine;
				if(!precs[ine]->otyp)
				{
					jmps=duprecs(&srec);
					if(jmps<minjmps)
					{
						minjmps=jmps;
						mind=ine;
						mindir=srec.dir;
					}
				}
				GetSystemTimeAsFileTime(&ftim);
				ntim=tim2int(ftim);
				if(ntim.QuadPart-stim.QuadPart>SRTIM)
					break;
			}
			setMap(DUSRT);
			srec.loc=mind;
			srec.dir=mindir;
			precjmps(&srec);
		}
		mvstchs(0,MAXSEQ,opnt);
		hed.stchs=opnt;
		coltab();
		setMap(RESTCH);
	}
	else
	{
		LoadString(hInst,IDS_SRTER,hlpbuf,HBUFSIZ);
		sprintf(msgbuf,hlpbuf,pfrecs[ine]->frm);
		shoMsg(msgbuf);
	}
}

unsigned dutyp(unsigned tat)
{
#if !defined(GCC__)
	__asm
	{
			xor		eax,eax
			mov		ebx,tat
			and		ebx,SRTYPMSK
			bsr		eax,ebx
			je		short dutypx
			sub		al,18
			cmp		al,12
			jne		short dutypx
			test	ebx,0x20000000
			je		short dutypx
			mov		al,1
dutypx:		and		eax,0xf
	}
#else
	__asm__ __volatile__
	(

	"	xor		eax,eax\n"
	"	and		%[tat],%[srtypmsk]\n"
	"	bsr		eax,%[tat]\n"
	"	je		short dutypx\n"
	"	sub		al,18\n"
	"	cmp		al,12\n"
	"	jne		short dutypx\n"
	"	test	%[tat],0x20000000\n"
	"	je		short dutypx\n"
	"	mov		al,1\n"
	"dutypx: 	and		eax,0xf\n"

	:
	:	[srtypmsk] "i" (SRTYPMSK),
		[tat] "r" (tat)
	:	"eax", "al"
	);
#endif
}

void filim(FRMLIM* flim,unsigned * lmap)
{
	unsigned	ind,fcod,at,typ;
	
	fcod=clofind<<FRMSHFT;
	*lmap=0;
	for(ind=0;ind<hed.stchs;ind++)
	{
		at=stchs[ind].at;
		if(fcod==(at&FRMSK))
		{
			typ=ftyps[dutyp(at)];
			switch(typ)
			{
			case 1:	//applique
				
				if(!(*lmap&M_CWLK))
					flim->apstrt=ind;
				*lmap|=M_AP;
				flim->apend=ind;
				break;

			case 2:	//center walk

				if(!(*lmap&M_CWLK))
					flim->cstrt=ind;
				*lmap|=M_CWLK;
				flim->cend=ind;
				break;

			case 3:	//edge walk

				if(!(*lmap&M_WALK))
					flim->wstrt=ind;
				*lmap|=M_WALK;
				flim->wend=ind;
				break;

			case 4:	//underlay

				if(!(*lmap&M_UND))
					flim->ustrt=ind;
				*lmap|=M_UND;
				flim->uend=ind;
				break;

			case 5:	//fill
				
				if(!(*lmap&M_FIL))
					flim->fstrt=ind;
				*lmap|=M_FIL;
				flim->fend=ind;
				break;

			case 6:	//border
				
				if(frmpnt->fcol==frmpnt->bcol)
				{
					if(!(*lmap&M_BRD))
						flim->bstrt=ind;
					*lmap|=M_BRD;
					flim->bend=ind;
				}
				break;
			}
		}
	}
}

unsigned frstmap(unsigned* map)
{
#if !defined(GCC__)
	__asm
	{
			xor		eax,eax
			mov		ecx,map
			mov		ebx,[ecx]
			bsf		eax,ebx
			je		short fmapx
			btr		ebx,eax
			mov		[ecx],ebx
fmapx:
	}
#else
	__asm__ __volatile__
	(

	"	xor		eax,eax\n"
	"	mov		ecx,%[map]\n"
	"	mov		edx,[ecx]\n"
	"	bsf		eax,edx\n"
	"	je		short fmapx\n"
	"	btr		edx,eax\n"
	"	mov		[ecx],edx\n"
	"fmapx:\n"

	:
	:	[map] "m" (map)
	:	"ecx", "eax", "memory", "edx"
	);
#endif
}

#ifdef _DEBUG

typedef struct _atfld{
	
	unsigned	col;
	unsigned	frm;
	unsigned	typ;
	unsigned	lay;
	unsigned	usr;
}ATFLD;

void duatf(unsigned ind)
{
	char		abuf[256];
	unsigned	at;
	ATFLD		atf;

	at=stchs[ind].at;
	atf.col=at&COLMSK;
	atf.frm=(at>>FRMSHFT)&FRMSK;
	atf.typ=ftyps[dutyp(at)];
	atf.lay=(at>>LAYSHFT)&7;
	if(at&0x80000000)
		atf.usr=1;
	else
		atf.usr=0;
	sprintf(abuf,"%5d: col: %2d frm: %5d typ: %2d, lay: %1d: usr: %1d at: %08x\n",
		ind,
		atf.col,
		atf.frm,
		atf.typ,
		atf.lay,
		atf.usr,
		at);
	OutputDebugString(abuf);
}

void dmpat()
{
	unsigned ind,at;
	
	duatf(0);
	at=stchs[0].at;
	for(ind=1;ind<hed.stchs;ind++)
	{
		if(at!=stchs[ind].at)
		{
			duatf(ind);
			at=stchs[ind].at;
		}
	}
}
#endif

void fdelstch()
{
	unsigned	ind,ine,fcod,at,typ,tmap,col,bcol,tapcol;
	unsigned*	stpnt;

	fvars(clofind);
	tmap=0;
	FillMemory(&fstrts,sizeof(FSTRTS),0);
	fcod=(clofind<<FRMSHFT);
	ine=0;
	bcol=frmpnt->bcol&COLMSK;
	tapcol=frmpnt->bcol>>4;
	for(ind=0;ind<hed.stchs;ind++)
	{
		if(!chku(FIL2OF)&&chkMap(SELBOX)&&ind==cloInd)
			cloInd=ine;
		at=stchs[ind].at;
		if(fcod==(at&(FRMSK|NOTFRM)))
		{
			typ=ftyps[dutyp(at)];
			switch(typ)
			{
			case 1:

				if(!(tmap&M_AP))
				{
					tmap|=M_AP;
					fstrts.apl=ine;
				}
				break;

			case 5:

				if(!(tmap&M_FTH))
				{
					tmap|=M_FTH;
					fstrts.fth=ine;
				}
				break;

			case 6:

				if(!(tmap&M_FIL))
				{
					tmap|=M_FIL;
					fstrts.fil=ine;
				}
				break;

			case 7:

				if(!(tmap&M_BRD))
				{
					tmap|=M_BRD;
					fstrts.brd=ine;
				}
				break;

			default:

				if(frmpnt->ftyp&&!(tmap&M_FIL))
				{
					tmap|=M_FIL;
					fstrts.fil=ine;
				}
				break;
			}
		}
		else
		{
			col=at&COLMSK;
			if(col==frmpnt->fcol)
			{
				tmap|=M_FCOL;
				fstrts.fcol=ine;
			}
			if(col==frmpnt->dhx.fth.fthcol)
			{
				tmap|=M_FTHCOL;
				fstrts.fthcol=ine;
			}
			if(col==bcol)
			{
				tmap|=M_ECOL;
				fstrts.ecol=ine;
			}
			if(col==tapcol)
			{
				tmap|=M_APCOL;
				fstrts.apcol=ine;
			}
			stchs[ine].x=stchs[ind].x;
			stchs[ine].y=stchs[ind].y;
			stchs[ine].at=stchs[ind].at;
			ine++;
		}
	}
	fstrts.fcol++;
	fstrts.fthcol++;
	fstrts.ecol++;
	fstrts.apcol++;
	smap=tmap;
	hed.stchs=ine;
	ine=0;
	if(!(tmap&M_ECOL))
		fstrts.ecol=hed.stchs;
	if(!(tmap&M_FTHCOL))
		fstrts.fthcol=hed.stchs;
	if(!(tmap&M_FCOL))
		fstrts.fcol=hed.stchs;
	if(frmpnt->etyp)
	{
		if(frmpnt->etyp==EGAP)
		{
			if(!(tmap&M_AP))
			{
				if(tmap&M_APCOL)
					fstrts.apl=fstrts.apcol+1;
				else
					fstrts.apl=hed.stchs;
			}
		}
		if(!(tmap&M_BRD))
		{
			if(tmap&M_ECOL)
				fstrts.brd=fstrts.ecol+1;
			else
				fstrts.brd=hed.stchs;
		}
	}
	if(frmpnt->ftyp||(tmap&(M_WALK|M_UND|M_CWLK)))
	{
		if(!(tmap&M_FIL))
		{
			if(tmap&M_FCOL)
				fstrts.fil=fstrts.fcol+1;
			else
				fstrts.fil=hed.stchs;
		}
	}
	if(frmpnt->ftyp==FTHF)
	{
		if(!(tmap&M_FTH))
		{
			if(tmap&M_FTHCOL)
				fstrts.fth=fstrts.fthcol+1;
			else
				fstrts.fth=hed.stchs;
		}
	}
	stpnt=(unsigned*)&fstrts;
	for(ind=3;ind;ind--)
	{
		ine=ind-1;
		while(ine<ind)
		{
			if(stpnt[ine]>stpnt[ind])
				stpnt[ind]=stpnt[ine];
			ine--;
		}
	}
	if(!chku(FIL2OF)&&chkMap(SELBOX))
	{
		for(ind=0;ind<sizeof(fstrts)>>2;ind++)
			stpnt[ind]=cloInd;
	}
}

BOOL lastcol(unsigned ind,FLPNT* pnt)
{
	unsigned col;

	col=isinds[ind].col;
	while(ind)
	{
		ind--;
		if(isinds[ind].col==col)
		{
			pnt->x=iseq[isinds[ind+1].ind-1].x;
			pnt->y=iseq[isinds[ind+1].ind-1].y;
			return 1;
		}
	}
	return 0;
}

void duint(unsigned off,unsigned cod)
{
	unsigned	cnt,ind;
	FLPNT		cpnt;

	if(itf.coloc>itf.sloc)
	{
		cnt=itf.coloc-itf.sloc;
		MoveMemory(&itf.histch[itf.oloc],&stchs[itf.sloc],sizeof(SHRTPNT)*cnt);
		itf.sloc+=cnt;
		itf.oloc+=cnt;
	}
	if(frmpnt->xat&AT_STRT)
	{
		if(!setMap(DIDSTRT))
			itf.oloc+=gucon(flt[frmpnt->strt],iseq[isinds[itf.pins].ind],itf.oloc+off,cod);
	}
	if(lastcol(itf.pins,&cpnt))
		itf.oloc+=gucon(cpnt,iseq[isinds[itf.pins].ind],itf.oloc+MAXSEQ,cod);
	for(ind=isinds[itf.pins].ind;ind<isinds[itf.pins+1].ind;ind++)
	{
		itf.histch[itf.oloc].x=iseq[ind].x;
		itf.histch[itf.oloc].y=iseq[ind].y;
		itf.histch[itf.oloc].at=cod;
		if(	itf.histch[itf.oloc].x!=itf.histch[itf.oloc-1].x||
			itf.histch[itf.oloc].y!=itf.histch[itf.oloc-1].y)
			itf.oloc++;
	}
}

BOOL isfil()
{
	if(frmpnt->ftyp)
		return 1;
	if(frmpnt->etyp)
		return 1;
	if(frmpnt->xat&(AT_CWLK|AT_WALK|AT_UND))
		return 1;
	return 0;
}

void chkend(unsigned off,unsigned cod)
{
	if(isfil())
	{
		setMap(ISEND);
		if(frmpnt->xat&AT_END)
			itf.oloc+=gucon(iseq[isind-1],flt[frmpnt->end],itf.oloc+off,cod);
	}
}

void intlv()
{
	unsigned	ind,ine,cod,off;
	FLPNT		cpnt;

	rstMap(ISEND);
	fvars(clofind);
	isinds[isind2].ind=isind;
	FillMemory(&itf,sizeof(INTINF),0);
	itf.laycod=((frmpnt->at&FRMLMSK)<<(LAYSHFT-1))|(clofind<<FRMSHFT);
	rstMap(DIDSTRT);
	if(hed.stchs)
	{
		off=MAXSEQ;
		itf.histch=&stchs[MAXSEQ];
		for(ind=0;ind<isind2;ind++)
		{
			itf.pins=ind;
			switch(isinds[ind].seq)
			{
			case I_AP:

				if(smap&M_FIL&&fstrts.apl>=itf.coloc)
					itf.coloc=fstrts.apl;
				else
				{
					itf.coloc=fstrts.apcol;
					if(itf.coloc==1)
						itf.coloc=0;
				}
				break;

			case I_FIL:

				if(smap&M_FIL&&fstrts.fil>=itf.coloc)
					itf.coloc=fstrts.fil;
				else
					itf.coloc=fstrts.fcol;
				break;

			case I_FTH:

				if(smap&M_FIL&&fstrts.fth>=itf.coloc)
					itf.coloc=fstrts.fth;
				else
					itf.coloc=fstrts.fthcol;
				break;

			case I_BRD:

				if(smap&M_BRD&&fstrts.brd>=itf.coloc)
					itf.coloc=fstrts.brd;
				else
					itf.coloc=fstrts.ecol;
				break;
			}
			cod=itf.laycod|isinds[itf.pins].cod|isinds[itf.pins].col;
			duint(off,cod);
		}
		chkend(MAXSEQ,cod);
		if(hed.stchs&&itf.sloc<(unsigned)hed.stchs-1)
		{
			ine=hed.stchs-itf.sloc;
			MoveMemory(&stchs[itf.oloc+MAXSEQ],&stchs[itf.sloc],sizeof(SHRTPNT)*ine);
			itf.oloc+=ine;
		}
		MoveMemory(stchs,itf.histch,sizeof(SHRTPNT)*itf.oloc);
	}
	else
	{
		off=0;
		for(ind=0;ind<isind2;ind++)
		{
			cod=itf.laycod|isinds[ind].cod|isinds[ind].col;
			if(frmpnt->xat&AT_STRT)
			{
				if(!setMap(DIDSTRT))
					itf.oloc+=gucon(flt[frmpnt->strt],iseq[isinds[itf.pins].ind],itf.oloc+off,cod);
			}
			if(lastcol(ind,&cpnt))
				itf.oloc+=gucon(cpnt,iseq[isinds[ind].ind],itf.oloc,cod);
			for(ine=isinds[ind].ind;ine<isinds[ind+1].ind;ine++)
			{
				stchs[itf.oloc].x=iseq[ine].x;
				stchs[itf.oloc].y=iseq[ine].y;
				stchs[itf.oloc].at=cod;
				if(	stchs[itf.oloc].x!=stchs[itf.oloc-1].x||
					stchs[itf.oloc].y!=stchs[itf.oloc-1].y)
					itf.oloc++;
			}
		}
		chkend(0,cod);
	}
	hed.stchs=itf.oloc;
	coltab();
}

void setundfn(unsigned cod)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
		{
			clofind=selist[ind];
			fvars(clofind);
			if(frmpnt->typ==LIN)
				continue;
			frmpnt->xat|=cod;
			refilfn();
		}
		coltab();
		setMap(RESTCH);
		return;
	}
	if(chkMap(FORMSEL))
	{
		fvars(clofind);
		frmpnt->xat|=cod;
		refilfn();
		coltab();
		setMap(RESTCH);
	}
}

void setund()
{
	setundfn(AT_UND);
}

void setwlk()
{
	setundfn(AT_WALK);
}

void setcwlk()
{
	setundfn(AT_CWLK);
}

void notundfn(unsigned cod)
{
	unsigned ind;

	savdo();
	cod=!cod;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
		{
			clofind=ind;
			fvars(clofind);
			if(frmpnt->typ==LIN)
				continue;
			frmpnt->xat&=cod;
			refilfn();
		}
		coltab();
		setMap(RESTCH);
		return;
	}
	if(chkMap(FORMSEL))
	{
		fvars(clofind);
		if(frmpnt->typ==LIN)
			return;
		frmpnt->xat&=cod;
		refilfn();
		coltab();
		setMap(RESTCH);
	}
}

void notund()
{
	notundfn(AT_UND);
}

void notwlk()
{
	notundfn(AT_WALK);
}

void notcwlk()
{
	notundfn(AT_CWLK);
}

void ulenfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->xat&(AT_UND|AT_WALK|AT_CWLK))
	{
		frmpnt->ulen=len;
		refilfn();
	}
}

void dusulen(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			ulenfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		ulenfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void undlen()
{
	tabmsg(IDS_SETULEN);
	setMap(NUMIN);
	setMap(FSETULEN);
	numWnd();
}

void uspacfn(unsigned find,float spac)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->xat&AT_UND)
	{
		frmpnt->uspac=spac;
		refilfn();
	}
}

void duspac(float spac)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			uspacfn(selist[ind],spac);
	}
	if(chkMap(FORMSEL))
		uspacfn(clofind,spac);
	coltab();
	setMap(RESTCH);
}

void uspac()
{
	tabmsg(IDS_SETUSPAC);
	setMap(NUMIN);
	setMap(FSETUSPAC);
	numWnd();
}

void uangfn(unsigned find,float ang)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->xat&AT_UND)
	{
		frmpnt->uang=ang;
		refilfn();
	}
}

void dufang(float ang)
{
	unsigned ind;

	savdo();
	ang*=(float)PI/180;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			uangfn(selist[ind],ang);
	}
	if(chkMap(FORMSEL))
		uangfn(clofind,ang);
	coltab();
	setMap(RESTCH);
}

void sfuang()
{
	tabmsg(IDS_SETUANG);
	setMap(NUMIN);
	setMap(FSETUANG);
	numWnd();
}

void flenfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->ftyp&&!isclp(find))
	{
		frmpnt->flencnt.flen=len;
		refilfn();
	}
}

void duflen(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			flenfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		flenfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setflen()
{
	tabmsg(IDS_SETFLEN);
	setMap(NUMIN);
	setMap(FSETFLEN);
	numWnd();
}

void fspacfn(unsigned find,float spac)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->ftyp)
	{
		if(spac<0)
		{
			if(!isclp(find))
				return;
		}
		frmpnt->fspac=spac;
		refilfn();
	}
}

void dufspac(float spac)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fspacfn(selist[ind],spac);
	}
	if(chkMap(FORMSEL))
		fspacfn(clofind,spac);
	coltab();
	setMap(RESTCH);
}

void setfspac()
{
	tabmsg(IDS_SETFSPAC);
	setMap(NUMIN);
	setMap(FSETFSPAC);
	numWnd();
}

void findfn(unsigned find,float idnt)
{
	clofind=find;
	fvars(clofind);
	frmpnt->wind=idnt;
	if(frmpnt->xat&(AT_UND|AT_WALK))
		refilfn();
}

void dufind(float idnt)
{
	unsigned ind;
	
	savdo();
	idnt*=PFGRAN;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			findfn(selist[ind],idnt);
	}
	if(chkMap(FORMSEL))
		findfn(clofind,idnt);
	coltab();
	setMap(RESTCH);
}

void fangfn(unsigned find,float ang)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->typ==POLI&&frmpnt->ftyp)
	{
		switch(frmpnt->ftyp)
		{
		case VRTF:
		case HORF:
		case ANGF:

			frmpnt->ftyp=ANGF;
			frmpnt->angclp.fang=ang;
			break;

		case	VCLPF:
		case	HCLPF:
		case	ANGCLPF:

			frmpnt->ftyp=ANGCLPF;
			frmpnt->sacang.ang=ang;
			break;
		}
		refilfn();
	}
}

void dufxang(float ang)
{
	unsigned ind;

	savdo();
	ang*=(float)PI/180;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fangfn(selist[ind],ang);
	}
	if(chkMap(FORMSEL))
		fangfn(clofind,ang);
	coltab();
	setMap(RESTCH);
}

void setfang()
{
	tabmsg(IDS_SETFANG);
	setMap(NUMIN);
	setMap(FSETFANG);
	numWnd();
}

void ucolfn(unsigned find,unsigned col)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->xat&(AT_UND|AT_WALK|AT_CWLK))
	{
		frmpnt->ucol=col;
		refilfn();
	}
}

void dundcol(unsigned col)
{
	unsigned ind;

	savdo();
	if(col)
		col--;
	col&=COLMSK;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			ucolfn(selist[ind],col);
	}
	if(chkMap(FORMSEL))
		ucolfn(clofind,col);
	coltab();
	setMap(RESTCH);
}

void setucol()
{
	tabmsg(IDS_COL);
	setMap(NUMIN);
	setMap(FSETUCOL);
	numWnd();
}

void fcolfn(unsigned find,unsigned col)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->ftyp)
	{
		frmpnt->fcol=col;
		refilfn();
	}
}

void dufcol(unsigned col)
{
	unsigned ind;

	savdo();
	if(col)
		col--;
	col&=COLMSK;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fcolfn(selist[ind],col);
	}
	if(chkMap(FORMSEL))
		fcolfn(clofind,col);
	coltab();
	setMap(RESTCH);
}

void setfcol()
{
	tabmsg(IDS_COL);
	setMap(NUMIN);
	setMap(FSETFCOL);
	numWnd();
}

void bcolfn(unsigned find,unsigned col)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->etyp)
	{
		frmpnt->bcol=col;
		refilfn();
	}
}

void dubcol(unsigned col)
{
	unsigned ind;

	savdo();
	if(col)
		col--;
	col&=COLMSK;
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			bcolfn(selist[ind],col);
	}
	if(chkMap(FORMSEL))
		bcolfn(clofind,col);
	coltab();
	setMap(RESTCH);
}

void setbcol()
{
	tabmsg(IDS_COL);
	setMap(NUMIN);
	setMap(FSETBCOL);
	numWnd();
}

void blenfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->etyp&&!iseclp(find))
	{
		frmpnt->flencnt.flen=len;
		refilfn();
	}
}

void dublen(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			blenfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		blenfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setblen()
{
	tabmsg(IDS_SETFLEN);
	setMap(NUMIN);
	setMap(FSETBLEN);
	numWnd();
}

void bspacfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->etyp)
	{
		frmpnt->espac=len;
		refilfn();
	}
}

void dubspac(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			bspacfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		bspacfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setbspac()
{
	tabmsg(IDS_SETFSPAC);
	setMap(NUMIN);
	setMap(FSETBSPAC);
	numWnd();
}

void bminfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->etyp)
	{
		frmpnt->emin=len;
		refilfn();
	}
}

void dubmin(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			bminfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		bminfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setbmin()
{
	tabmsg(IDS_TXT23);
	setMap(NUMIN);
	setMap(FSETBMIN);
	numWnd();
}

void bmaxfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->etyp)
	{
		frmpnt->emax=len;
		refilfn();
	}
}

void dubmax(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			bmaxfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		bmaxfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setbmax()
{
	tabmsg(IDS_TXT22);
	setMap(NUMIN);
	setMap(FSETBMAX);
	numWnd();
}

void fminfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->ftyp)
	{
		frmpnt->fmin=len;
		refilfn();
	}
}

void dufmin(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fminfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		fminfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setfmin()
{
	tabmsg(IDS_TXT21);
	setMap(NUMIN);
	setMap(FSETFMIN);
	numWnd();
}

void fmaxfn(unsigned find,float len)
{
	clofind=find;
	fvars(clofind);
	if(frmpnt->ftyp)
	{
		frmpnt->fmax=len;
		refilfn();
	}
}

void dufmax(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fmaxfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		fmaxfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setfmax()
{
	tabmsg(IDS_TXT20);
	setMap(NUMIN);
	setMap(FSETFMAX);
	numWnd();
}

void fwidfn(unsigned find,float len)
{
	unsigned	ind;
	double		rat;
	float		ref;

	clofind=find;
	fvars(clofind);
	ref=frmpnt->rct.left;
	rat=len/(frmpnt->rct.right-ref);
	for(ind=0;ind<sids;ind++)
		flt[ind].x=(flt[ind].x-ref)*rat+ref;
	frmout(clofind);
	refilfn();
}

void dufwid(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fwidfn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		fwidfn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setfwid()
{
	tabmsg(IDS_WID);
	setMap(NUMIN);
	setMap(FSETFWID);
	numWnd();
}

void setfind()
{
	tabmsg(IDS_UWLKIND);
	setMap(NUMIN);
	setMap(FSETFIND);
	numWnd();
}

void fhifn(unsigned find,float len)
{
	unsigned	ind;
	double		rat;
	float		ref;

	clofind=find;
	fvars(clofind);
	ref=frmpnt->rct.bottom;
	rat=len/(frmpnt->rct.top-ref);
	for(ind=0;ind<sids;ind++)
		flt[ind].y=(flt[ind].y-ref)*rat+ref;
	frmout(clofind);
	refilfn();
}

void dufhi(float len)
{
	unsigned ind;

	savdo();
	if(fselpnt)
	{
		for(ind=0;ind<fselpnt;ind++)
			fhifn(selist[ind],len);
	}
	if(chkMap(FORMSEL))
		fhifn(clofind,len);
	coltab();
	setMap(RESTCH);
}

void setfhi()
{
	tabmsg(IDS_HI);
	setMap(NUMIN);
	setMap(FSETFHI);
	numWnd();
}

void setfilstrt()
{
	if(chkMap(FRMPSEL))
	{
		formlst[clofind].strt=clofine;
		formlst[clofind].xat|=AT_STRT;
		refil();
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_FORMP,IDS_FSTRT);
}

void setfilend()
{
	if(chkMap(FRMPSEL))
	{
		formlst[clofind].end=clofine;
		formlst[clofind].xat|=AT_END;
		refil();
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_FORMP,IDS_FEND);
}

void duauxnam()
{
	TCHAR* pext;

	_strlwr(filnam);
	strcpy(auxnam,filnam);
	pext=strrchr(auxnam,'.');
	if(pext)
		pext++;
	else
		pext=&filnam[strlen(filnam)];
	*pext=0;
	switch(ini.auxfil){

	case AUXDST:

		strcat(auxnam,"dst");
		break;

#if PESACT

	case AUXPES:

		strcat(auxnam,"pes");
		break;

#endif

	default:

		strcat(pext,"pcs");
	}
}

void dutxtfil()
{
	if(!ini.txthi)
		ini.txthi=ITXHI;
	if(!ini.txtwid)
		ini.txtwid=ITXWID;
	if(!ini.txtspac)
		ini.txtspac=(float)ITXSPAC;
	if(!ini.txtx)
		ini.txtx=ITXPIX;
	angfrm.sids=0;
	setMap(TXTRED);
	setMap(ZUMED);
	rstMap(WASPAT);
	rstMap(RUNPAT);
	movStch();
	ShowWindow(hVrt,FALSE);
	ShowWindow(hHor,FALSE);
	cloxlst=(unsigned*)&oseq;
	cloxcnt=0;
	setMap(INIT);
	hbsid=0;
	if(chkMap(WASTXBAK))
	{
		redtbak();
		if(!tscr.fhi)
			tscr.fhi=ini.txthi;
		if(!tscr.spac)
			tscr.spac=ini.uspac;
		if(!tscr.wid)
			tscr.wid=ini.txtwid;
		setMap(LASTXBAK);
		rstMap(TXBDIR);
	}
	else
	{
		tscr.ind=0;
		tscr.fhi=ini.txthi;
		tscr.wid=ini.txtwid;
		tscr.spac=ini.txtspac;
	}
	setMap(RESTCH);
}

void txt2pix(TXPNT txp,POINT* pixp)
{
	pixp->y=tscr.hi-txp.y/tscr.fhi*tscr.hi+tscr.top;
	pixp->x=(txp.lin*tscr.spac+tscr.xof)/tscr.ed2px;
}

void txtxfn(POINT ref,int pix)
{
	POINT xlin[2];

	xlin[0].x=xlin[1].x=ref.x;
	xlin[0].y=ref.y-pix;
	xlin[1].y=ref.y+pix;
	Polyline(sdc,xlin,2);
	xlin[0].y=xlin[1].y=ref.y;
	xlin[0].x=ref.x-pix;
	xlin[1].x=ref.x+pix;
	Polyline(sdc,xlin,2);
}

void dutxtx(int ind,int pix)
{
	POINT	ref;

	txt2pix(txtmp[ind],&ref);
	txtxfn(ref,pix);
	if(ref.y>tscr.mhi)
		ref.y-=tscr.hi;
	else
		ref.y+=tscr.hi;
	txtxfn(ref,pix);
}

void txrct2rct(TXTRCT txr,RECT* rct)
{
	TXPNT	txp;
	POINT	tpnt;
	int		bh2;

	bh2=buttonHi>>1;
	txp.lin=txr.lft;
	txp.y=txr.top;
	txt2pix(txp,&tpnt);
	rct->left=tpnt.x-ini.txtx;
	rct->top=tpnt.y-ini.txtx;
	txp.lin=txr.rit;
	txp.y=txr.bot;
	txt2pix(txp,&tpnt);
	rct->right=tpnt.x+ini.txtx;
	rct->bottom=tpnt.y+ini.txtx;
}

void ed2px(FLPNT ped,POINT* px)
{
	px->x=ped.x/tscr.ed2px;
	px->y=scRct.bottom-ped.y/tscr.ed2px;
}

void px2ed(POINT px,FLPNT* ped)
{
	ped->x=px.x*tscr.ed2px;
	ped->y=tscr.ehi-px.y*tscr.ed2px;
}

void bxtxt(unsigned cod,TCHAR* str)
{
	SetWindowText(hbuts[cod],str);
}

void lodhbuf(unsigned cod)
{
	LoadString(hInst,cod,hlpbuf,HBUFSIZ);
}

void hlpflt(unsigned mcod,unsigned bcod,float dat)
{
	lodhbuf(mcod);
	sprintf(msgbuf,hlpbuf,dat);
	bxtxt(bcod,msgbuf);
}

void drwtxbut()
{
	lodhbuf(IDS_CLEAR);
	bxtxt(HTXCLR,hlpbuf);
	hlpflt(IDS_TXHI,HTXHI,tscr.fhi/PFGRAN);
	redraw(hbuts[HTXWID]);
	hlpflt(IDS_TXSPAC,HTXSPAC,tscr.spac/PFGRAN);
	lodhbuf(IDS_TXVRT);
	bxtxt(HTXVRT,hlpbuf);
	lodhbuf(IDS_TXHOR);
	bxtxt(HTXHOR,hlpbuf);
	lodhbuf(IDS_TXANG);
	bxtxt(HTXANG,hlpbuf);
	lodhbuf(IDS_TXMIR);
	bxtxt(HTXMIR,hlpbuf);
	SetWindowText(hbuts[HTXMIR+1],"");
}

void chktx()
{
	int ind,ine;

	ine=0;
	for(ind=0;ind<tscr.ind;ind++)
	{
		if(txtmp[ind].lin<=tscr.lins&&txtmp[ind].y<tscr.fhi)
		{
			txtmp[ine].lin=txtmp[ind].lin;
			txtmp[ine].y=txtmp[ind].y;
			ine++;
		}
	}
	tscr.ind=ine;
}

void drwtxtr()
{
	POINT		xlin[2];
	int			ind;
	int			ofy;
	COLORREF	col;
	TXPNT		txp;
	POINT		tpnt;
	int			cnt;
	double		edsp;
	double		pxsp;
	float		wid2;

	FillRect(sdc,&scRct,hStchBak);
	edsp=tscr.fhi*2/(tscr.spac*(tscr.lins+2));
	pxsp=(double)scRct.bottom/scRct.right;
	tscr.lins=floor(tscr.wid/tscr.spac);
	wid2=tscr.spac*(tscr.lins+2);
	if(rstMap(CHKTX))
		chktx();
	if(pxsp>edsp)
	{
		tscr.xof=0;
		tscr.ed2px=wid2/scRct.bottom;
		ofy=(scRct.bottom-tscr.fhi/tscr.ed2px)/2;
	}
	else
	{
		tscr.ed2px=tscr.fhi*2/scRct.bottom;
		ofy=scRct.bottom>>2;
		tscr.xof=(scRct.right*tscr.ed2px-(tscr.lins+2)*tscr.spac)/2;
	}
	tscr.top=ofy;
	tscr.bot=scRct.bottom-ofy;
	tscr.hi=tscr.bot-tscr.top;
	tscr.mhi=scRct.bottom>>1;
	tscr.ehi=scRct.bottom*tscr.ed2px;
	tscr.yof=(tscr.ehi-tscr.fhi)/2;
	SetROP2(sdc,R2_XORPEN);
	SelectObject(sdc,grdPen);
	cnt=tscr.fhi/ini.grdsiz+1;
	txp.lin=0;
	xlin[0].x=0;
	xlin[1].x=scRct.right;
	txp.y=0;
	for(ind=0;ind<cnt;ind++)
	{
		txt2pix(txp,&tpnt);
		xlin[0].y=xlin[1].y=tpnt.y;
		Polyline(sdc,xlin,2);
		txp.y+=ini.grdsiz;
	}
	DeleteObject(xpen);
	xpen=CreatePen(PS_SOLID,1,useCol[actcol]);
	SelectObject(sdc,xpen);
	SetROP2(sdc,R2_COPYPEN);
	xlin[0].y=0;
	xlin[1].y=scRct.bottom;
	for(ind=1;ind<tscr.lins+1;ind++)
	{
		xlin[0].x=xlin[1].x=(ind*tscr.spac+tscr.xof)/tscr.ed2px;
		Polyline(sdc,xlin,2);
	}
	xlin[0].x=0;
	xlin[1].x=scRct.right;
	xlin[0].y=xlin[1].y=tscr.top;
	Polyline(sdc,xlin,2);
	xlin[0].y=xlin[1].y=tscr.bot;
	Polyline(sdc,xlin,2);
	DeleteObject(xpen);
	xpen=CreatePen(PS_SOLID,1,0xffffff);
	SelectObject(sdc,xpen);
	SetROP2(sdc,R2_XORPEN);
	col=useCol[actcol];
	for(ind=0;ind<tscr.ind;ind++)
	{
		dutxtx(ind,ini.txtx);
	}
	if(cloxcnt)
	{
		txrct2rct(txrct,&txprct);
		xlin[0].y=xlin[1].y=txprct.top;
		xlin[0].x=txprct.left;
		xlin[1].x=txprct.right;
		Polyline(sdc,xlin,2);
		xlin[1].y=txprct.bottom;
		xlin[1].x=txprct.left;
		Polyline(sdc,xlin,2);
		xlin[0].x=txprct.right;
		xlin[0].y=txprct.bottom;
		Polyline(sdc,xlin,2);
		xlin[1].x=txprct.right;
		xlin[1].y=txprct.top;
		Polyline(sdc,xlin,2);
	}
	for(ind=0;ind<cloxcnt;ind++)
	{
		dutxtx(cloxlst[ind],ini.txtx);
		dutxtx(cloxlst[ind],ini.txtx<<1);
	}
	BitBlt(rsdc,0,0,scRct.right,scRct.bottom,sdc,0,0,SRCCOPY);
	drwtxbut();
}

BOOL px2txt(POINT pof,TXPNT* txrec)
{
	FLPNT epnt;

	px2ed(pof,&epnt);
	txrec->lin=(epnt.x-tscr.xof)/tscr.spac+0.5;
	if(txrec->lin>tscr.lins)
		return 0;
	if(txrec->lin<1)
		return 0;
	if(pof.y>tscr.top)
	{
		if(pof.y>tscr.bot)
			return 0;
		else
			txrec->y=(float)tscr.fhi-(float)(pof.y-tscr.top)/tscr.hi*tscr.fhi;
	}
	else
		return 0;
	return 1;
}

BOOL txbutfn(TXPNT* txrec)
{
	POINT	pof;

	deorg(&pof);
	return px2txt(pof,txrec);
}

void txtrbut()
{
	if(txbutfn(&txtmp[tscr.ind]))
	{
		savtxt();
		tscr.ind++;
		setMap(RESTCH);
	}
	else
		rstxt();

}

BOOL txtclos(unsigned* pclo)
{
	double	len;
	double	minlen;
	int		ind;
	POINT	ref,tpnt;

	ref.x=msg.pt.x-stOrg.x;
	ref.y=msg.pt.y-stOrg.y;
	minlen=1e99;
	*pclo=0;
	for(ind=0;ind<tscr.ind;ind++)
	{
		txt2pix(txtmp[ind],&tpnt);
		len=hypot(tpnt.x-ref.x,tpnt.y-ref.y);
		if(len<minlen)
		{
			minlen=len;
			*pclo=ind;
		}
	}
	if(minlen<CLOSENUF)
		return 1;
	return 0;
}

void tritx()
{
	POINT	xlin[2];
	int		siz;

	siz=ini.txtx<<2;
	xlin[0].x=xlin[1].x=txtloc.x;
	xlin[0].y=txtloc.y-siz;
	xlin[1].y=txtloc.y+siz;
	Polyline(rsdc,xlin,2);
	xlin[0].y=xlin[1].y=txtloc.y;
	xlin[0].x=txtloc.x-siz;
	xlin[1].x=txtloc.x+siz;
	Polyline(rsdc,xlin,2);
}

void setxmov()
{
	setMap(TXTMOV);
	txtloc.x=cloxref.x=msg.pt.x-stOrg.x;
	txtloc.y=cloxref.y=msg.pt.y-stOrg.y;
	SetROP2(rsdc,R2_NOTXORPEN);	
}

void ritxrct()
{
	POINT	of;
	RECT	trct;
	POINT	xlin[5];

	of.x=txtloc.x-cloxref.x;
	of.y=txtloc.y-cloxref.y;
	trct.bottom=txprct.bottom+of.y;
	trct.left=txprct.left+of.x;
	trct.right=txprct.right+of.x;
	trct.top=txprct.top+of.y;
	xlin[0].x=xlin[1].x=xlin[4].x=trct.left;
	xlin[2].x=xlin[3].x=trct.right;
	xlin[0].y=xlin[3].y=xlin[4].y=trct.top;
	xlin[1].y=xlin[2].y=trct.bottom;
	Polyline(rsdc,xlin,5);
}

void dutxrct(TXTRCT* rct)
{
	int		ind;
	TXPNT*	txp;

	if(cloxcnt)
	{
		txp=&txtmp[cloxlst[0]];
		rct->lft=rct->rit=txp->lin;
		rct->top=rct->bot=txp->y;
		for(ind=1;ind<cloxcnt;ind++)
		{
			txp=&txtmp[cloxlst[ind]];
			if(txp->y>rct->top)
				rct->top=txp->y;
			if(txp->y<rct->bot)
				rct->bot=txp->y;
			if(txp->lin<rct->lft)
				rct->lft=txp->lin;
			if(txp->lin>rct->rit)
				rct->rit=txp->lin;
		}
	}
	else
		rct->lft=rct->rit=rct->top=rct->bot;
}

void ed2stch(FLPNT* pt)
{
	pt->x-=tscr.xof;
	pt->y-=tscr.yof;
}

void dutxlin(FLPNT pt0,FLPNT pt1)
{
	double	slop;
	float	num;
	float	strt,fin,tflt;
	int		istrt,ifin;

	ed2stch(&pt0);
	ed2stch(&pt1);
	num=pt1.x-pt0.x;
	if(fabs(num)<TINY)
		return;
	slop=(pt1.y-pt0.y)/num;
	strt=pt0.x;
	fin=pt1.x;
	if(strt>fin)
	{
		tflt=strt;
		strt=fin;
		fin=tflt;
	}
	istrt=ceil(strt/tscr.spac);
	ifin=floor(fin/tscr.spac);
	if(istrt<1)
		istrt=1;
	if(ifin>tscr.lins)
		ifin=tscr.lins;
	while(istrt<=ifin)
	{
		tflt=slop*(-pt0.x+istrt*tscr.spac)+pt0.y;
		if(tflt>0&&tflt<tscr.fhi)
		{
			txtmp[tscr.ind].lin=istrt;
			txtmp[tscr.ind].y=tflt;
			tscr.ind++;
		}
		istrt++;
	}
}

void setxclp()
{
	POINT		of;
	FLPNT		fof;
	unsigned	ind,inx,cnt;

	deorg(&of);
	px2ed(of,&fof);
	if(rstMap(TXHCNTR))
		fof.x=(tscr.lins*tscr.spac)/2+tscr.xof-tscr.mid.x+tscr.spac/2;
	else
		fof.x-=tscr.mid.x;
	fof.y-=tscr.mid.y;
	for(ind=0;ind<angfrm.sids;ind++)
	{
		angflt[ind].x+=fof.x;
		angflt[ind].y+=fof.y;
	}
	cnt=angfrm.sids-1;
	if(angfrm.typ!=LIN)
		cnt++;
	sids=angfrm.sids;
	for(ind=0;ind<cnt;ind++)
	{
		inx=nxt(ind);
		dutxlin(angflt[ind],angflt[inx]);
	}
}

void stxlin()
{
	POINT	of;
	FLPNT	pt0;
	FLPNT	pt1;

	rstMap(TXTMOV);
	deorg(&of);
	px2ed(of,&pt1);
	px2ed(flin[0],&pt0);
	dutxlin(pt0,pt1);
	setMap(RESTCH);
}

void ed2txp(POINT pof,TXPNT* txrec)
{
	FLPNT epnt;

	px2ed(pof,&epnt);
	txrec->lin=(epnt.x-tscr.xof)/tscr.spac+0.5;
	txrec->y=(float)tscr.fhi-(float)(pof.y-tscr.top)/tscr.hi*tscr.fhi;
}

int	hitxlin()
{
	int ind,hilin;

	hilin=0;
	for(ind=0;ind<cloxcnt;ind++)
	{
		if(txtmp[cloxlst[ind]].lin>hilin)
			hilin=txtmp[cloxlst[ind]].lin;
	}
	return hilin;
}

void txtrup()
{
	TXPNT	hi;
	TXPNT	lo;
	TXPNT	tof;
	float	tflt;
	short	tsht;
	int		ind,bakp;
	POINT	of;
	TXPNT*	ptxt;

	if(rstMap(TXTMOV))
	{
		savtxt();
		deorg(&of);
		of.x-=cloxref.x;
		of.y-=cloxref.y;
		bakp=abs(of.x);
		tof.lin=bakp*tscr.ed2px/tscr.spac+0.5;
		if(of.x<0)
			tof.lin=-tof.lin;
		tof.y=(float)-of.y/tscr.hi*tscr.fhi;
		tflt=txrct.top+tof.y-tscr.fhi;
		if(tflt>0)
			tof.y-=tflt;
		tflt=txrct.bot+tof.y;
		if(tflt<0)
			tof.y-=tflt;
		ind=txrct.lft+tof.lin-1;
		if(ind<0)
			tof.lin-=ind;
		ind=txrct.rit+tof.lin-tscr.lins;
		if(ind>0)
			tof.lin-=ind;
		for(ind=0;ind<cloxcnt;ind++)
		{
			ptxt=&txtmp[cloxlst[ind]];
			ptxt->lin+=tof.lin;
			ptxt->y+=tof.y;
		}
		dutxrct(&txrct);
	}
	else
	{
		if(rstMap(BZUMIN))
		{
			deorg(&of);
			ed2txp(blin[0],&hi);
			ed2txp(of,&lo);
			if(hi.lin<lo.lin)
			{
				tsht=hi.lin;
				hi.lin=lo.lin;
				lo.lin=tsht;
			}
			if(hi.y<lo.y)
			{
				tflt=hi.y;
				hi.y=lo.y;
				lo.y=tflt;
			}
			cloxcnt=0;
			for(ind=0;ind<tscr.ind;ind++)
			{
				if(	txtmp[ind].y<hi.y&&
					txtmp[ind].y>lo.y&&
					txtmp[ind].lin<=hi.lin&&
					txtmp[ind].lin>=lo.lin)
				{
					cloxlst[cloxcnt]=ind;
					cloxcnt++;
				}
			}
			dutxrct(&txrct);
		}
	}
	setMap(RESTCH);
}

void angrct(FLRCT* rct)
{
	unsigned	ind;

	rct->left=rct->right=angflt[0].x;
	rct->bottom=rct->top=angflt[0].y;
	for(ind=1;ind<angfrm.sids;ind++)
	{
		if(angflt[ind].x<rct->left)
			rct->left=angflt[ind].x;
		if(angflt[ind].x>rct->right)
			rct->right=angflt[ind].x;
		if(angflt[ind].y>rct->top)
			rct->top=angflt[ind].y;
		if(angflt[ind].y<rct->bottom)
			rct->bottom=angflt[ind].y;
	}
}

void ritxfrm()
{
	unsigned ind,cnt;
	POINT		of;

	of.x=txtloc.x-cloxref.x;
	of.y=txtloc.y-cloxref.y;
	for(ind=0;ind<angfrm.sids;ind++)
	{
		ed2px(angflt[ind],&flin[ind]);
		flin[ind].x+=of.x;
		flin[ind].y+=of.y;
	}
	flin[ind].x=flin[0].x;
	flin[ind].y=flin[0].y;
	cnt=angfrm.sids;
	if(angfrm.typ!=LIN)
		cnt++;
	SetROP2(rsdc,R2_NOTXORPEN);
	Polyline(rsdc,flin,cnt);
}

void setxfrm()
{
	unsigned	ind;
	FLRCT		arct;
	float		hi;
	double		rat;

	angrct(&arct);
	for(ind=0;ind<angfrm.sids;ind++)
	{
		angflt[ind].x-=arct.left;
		angflt[ind].y-=arct.bottom;
	}
	angrct(&arct);
	hi=arct.top-arct.bottom;
	if(hi>tscr.fhi)
	{
		rat=tscr.fhi/hi*0.95;
		for(ind=0;ind<angfrm.sids;ind++)
		{
			angflt[ind].x*=rat;
			angflt[ind].y*=rat;
		}
		angrct(&arct);
	}
	tscr.mid.x=midl(arct.right,arct.left);
	tscr.mid.y=midl(arct.top,arct.bottom);
	ed2px(tscr.mid,&cloxref);
}

void txtclp()
{
	htclp=RegisterClipboardFormat(thredclp);
	hClpMem=GetClipboardData(htclp);
	if(hClpMem)
	{
		frmclpdat=(FRMCLP*)GlobalLock(hClpMem);
		if(frmclpdat->led==CLP_FRM)
		{
			frmpnt=&frmclpdat->frm;
			frmcpy(&angfrm,frmpnt);
			MoveMemory(&angflt,&frmpnt[1],sizeof(FLPNT)*frmpnt->sids);
			angfrm.flt=angflt;
			rstMap(TXTLIN);
			setMap(TXTCLP);
			setMap(TXTMOV);
			setxfrm();
			txtloc.x=msg.pt.x-stOrg.x;
			txtloc.y=msg.pt.y-stOrg.y;
		}
		GlobalUnlock(hClpMem);
	}
	setMap(RESTCH);
	rstMap(WASWROT);
}

void dutxtlin()
{
	SetROP2(rsdc,R2_NOTXORPEN);
	Polyline(rsdc,flin,2);
}

void txtrmov()
{
	if(chkMap(TXTLIN))
	{
		dutxtlin();
		deorg(&flin[1]);
		dutxtlin();
		return;
	}
	if(chkMap(TXTCLP))
	{
		if(setMap(WASWROT))
			ritxfrm();
		txtloc.x=msg.pt.x-stOrg.x;
		txtloc.y=msg.pt.y-stOrg.y;
		ritxfrm();
	}
	else
	{
		if(cloxcnt)
		{
			ritxrct();
			txtloc.x=msg.pt.x-stOrg.x;
			txtloc.y=msg.pt.y-stOrg.y;
			ritxrct();
		}
	}
}

void txtlin()
{
	deorg(flin);
	deorg(&flin[1]);
	rstMap(TXTCLP);
	setMap(TXTLIN);
	setMap(TXTMOV);
}

void butsid(unsigned cod)
{
	RECT brct;

	chktxnum();
	txsidtyp=cod;
	GetWindowRect(hbuts[cod],&brct);
	hbsid=CreateWindow(
		"STATIC",
		0,
		SS_NOTIFY|SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		brct.left+buttonWid3-stOrg.x,
		brct.top-stOrg.y,
		buttonWid3,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);
}

int txcmp(const void *arg1, const void *arg2)
{
	TXPNT* p0;
	TXPNT* p1;

	p0=(TXPNT*)arg1;
	p1=(TXPNT*)arg2;
	if(p0->lin==p1->lin)
	{
		if(p0->y==p1->y)
			return 0;
		else
		{
			if(p0->y>p1->y)
				return 1;
			else
				return -1;
		}
	}
	else
		return p0->lin-p1->lin;
	return 0;
}

void txpar()
{
	frmpnt->typ=POLI;
	frmpnt->dhx.txt.lins=tscr.lins;
	frmpnt->dhx.txt.hi=tscr.fhi;
	frmpnt->fspac=tscr.spac;
	frmpnt->flencnt.flen=ini.usesiz;
	frmpnt->fmax=ini.maxsiz;
	frmpnt->fmin=ini.minsiz;
	frmpnt->fcol=actcol;
	refilfn();
}

void txvrt()
{
	if(tscr.ind)
	{
		if(chkMap(FORMSEL))
		{
			fvars(clofind);
			frmpnt->ftyp=TXVRTF;
			txpar();
		}
	}
}

void txhor()
{
	if(tscr.ind)
	{
		if(chkMap(FORMSEL))
		{
			fvars(clofind);
			frmpnt->ftyp=TXHORF;
			txpar();
		}
	}
}

void txang()
{
	if(tscr.ind)
	{
		if(chkMap(FORMSEL))
		{
			fvars(clofind);
			frmpnt->ftyp=TXANGF;
			frmpnt->angclp.fang=(float)ini.angl;
			txpar();
		}
	}
}

void deltx()
{
	unsigned ind,cnt;

	cnt=frmpnt->dhx.txt.cnt;
	if(txad&&istx(clofind)&&cnt)
	{
		ind=frmpnt->dhx.txt.ind;
		MoveMemory(&txpnts[ind],&txpnts[ind+cnt],txad-(ind+cnt));
		for(ind=clofind+1;ind<formpnt;ind++)
		{
			if(istx(ind))
				formlst[ind].dhx.txt.ind-=cnt;
		}
		txad-=frmpnt->dhx.txt.cnt;
		frmpnt->dhx.txt.cnt=0;
	}
}

void nutx()
{
	int			ind,ins;
	FRMHED*		pf;

	qsort((void*)&txtmp,tscr.ind,6,txcmp);
	ins=0;
	if(formpnt)
	{
		if(istx(clofind))
		{
			ins=formlst[clofind].dhx.txt.ind;
			deltx();
		}
		else
		{
			for(ind=clofind-1;ind>=0;ind--)
			{
				if(istx(ind))
				{
					pf=&formlst[ind];
					ins=pf->dhx.txt.ind+pf->dhx.txt.cnt;
					goto nutskp;
				}
			}
nutskp:;
		}
	}
	txspac(ins,tscr.ind);
	MoveMemory(&txpnts[ins],&txtmp,tscr.ind*sizeof(TXPNT));
	frmpnt->dhx.txt.ind=ins;
	frmpnt->dhx.txt.cnt=tscr.ind;
}

void altx()
{
	int ind;
	float hi2;

	if(chkMap(FORMSEL))
	{
		hi2=tscr.fhi/2;
		clRmap((tscr.lins>>5)+1);
		for(ind=0;ind<tscr.ind;ind++)
			setr(txtmp[ind].lin);
		for(ind=1;ind<=tscr.lins;ind++)
		{	
			if(!chkr(ind))
			{
				txtmp[tscr.ind].lin=ind;
				txtmp[tscr.ind].y=hi2;
				tscr.ind++;
			}
		}
	}
	txof();
}

enum
{
	VRTYP,
	HORTYP,
	ANGTYP,
};

void dutxfn(unsigned typ)
{
	if(chkMap(FORMSEL))
	{
		altx();
		delmclp(clofind);
		delsac(clofind);
		deltx();
		savtxt();
		nutx();
		if(chku(SQRFIL))
			frmpnt->xat|=AT_SQR;
		else
			frmpnt->xat&=(~AT_SQR);
		switch(typ)
		{
		case VRTYP:

			txvrt();
			break;

		case HORTYP:

			txhor();
			break;

		case ANGTYP:

			txang();
			break;
		}
	}
	txof();
	rstxt();
}

void txsrt()
{
	qsort((void*)txtmp,tscr.ind,6,txcmp);
}

void dutxmir()
{
	int lin,ind,ine;

	savtxt();
	txsrt();
	lin=(tscr.lins+1)>>1;
	ind=tscr.ind-1;
	while(txtmp[ind].lin>lin&&ind>=0)
		ind--;
	ine=ind+1;
	if(tscr.lins&1)
	{
		while(txtmp[ind].lin==lin&&ind>=0)
			ind--;
	}
	while(ind>=0)
	{
		txtmp[ine].lin=tscr.lins-txtmp[ind].lin+1;
		txtmp[ine].y=txtmp[ind].y;
		ine++;
		ind--;
	}
	tscr.ind=ine;
	setMap(RESTCH);
}

BOOL chkbut()
{
	if(msg.hwnd==hbuts[HTXCLR])
	{
		txdelal();
		return 1;
	}
	if(msg.hwnd==hbuts[HTXHI])
	{
		butsid(HTXHI);
		return 1;
	}
	if(msg.hwnd==hbuts[HTXWID])
	{
		butsid(HTXWID);
		return 1;
	}
	if(msg.hwnd==hbuts[HTXSPAC])
	{
		butsid(HTXSPAC);
		return 1;
	}
	if(msg.hwnd==hbuts[HTXVRT])
	{
		dutxfn(VRTYP);
		return 1;
	}
	if(msg.hwnd==hbuts[HTXHOR])
	{
		dutxfn(HORTYP);
		return 1;
	}
	if(msg.hwnd==hbuts[HTXANG])
	{
		dutxfn(ANGTYP);
		return 1;
	}
	if(msg.hwnd==hbuts[HTXMIR])
	{
		dutxmir();
		return 1;
	}
	return 0;
}

void txtlbut()
{
	POINT	tpnt;

	fvars(clofind);
	if(chkbut())
		return;
	if(rstMap(TXTCLP))
	{
		savtxt();
		setxclp();
		return;
	}
	if(rstMap(TXTLIN))
	{
		savtxt();
		stxlin();
		return;
	}
	if(cloxcnt)
	{
		deorg(&tpnt);
		if(	tpnt.x>txprct.left&&
			tpnt.x<txprct.right&&
			tpnt.y>txprct.top&&
			tpnt.y<txprct.bottom)
		{
			setxmov();
			ritxrct();
			return;
		}
	}
	if(txtclos(cloxlst))
	{
		cloxcnt=1;
		setxmov();
		dutxrct(&txrct);
		setMap(RESTCH);
		return;
	}
	cloxcnt=0;
	setMap(BZUMIN);
	rstMap(BZUM);
	blin[0].x=blin[3].x=blin[4].x=msg.pt.x-stOrg.x;
	blin[0].y=blin[1].y=msg.pt.y-stOrg.y;
	blin[4].y=blin[0].y-1;
}

void redtbak()
{
	TXHST*		phst;
	
//	sprintf(msgbuf,"%d\n",ptxhst);
//	OutputDebugString(msgbuf);
	phst=&thsts[ptxhst];
	tscr.fhi=phst->hi;
	tscr.wid=phst->wid;
	tscr.spac=phst->spac;
	tscr.ind=phst->cnt;
	MoveMemory(txtmp,phst->txp,phst->cnt*sizeof(TXPNT));
	setMap(RESTCH);
}

void txbak()
{
	unsigned	ind;

	if(chkMap(WASTXBAK))
	{
		cloxcnt=0;
		for(ind=0;ind<16;ind++)
		{
			if(thsts[ptxhst].wid)
				goto txbak1;
			txrbak();
		}
		return;
txbak1:;
		redtbak();
		txrbak();
	}
}

void nxbak()
{
	unsigned ind;

	if(chkMap(WASTXBAK))
	{
		for(ind=0;ind<16;ind++)
		{
			txrfor();
			if(thsts[ptxhst].wid)
				goto nxbak1;
		}
		return;
nxbak1:;
		redtbak();
	}
}

void txtdel()
{
	int			ind,ine;
	unsigned	clo;

	if(cloxcnt)
	{
		savtxt();
		clRmap(RMAPSIZ);
		for(ind=0;ind<cloxcnt;ind++)
			setr(cloxlst[ind]);
		ine=0;
		for(ind=0;ind<tscr.ind;ind++)
		{
			if(!chkr(ind))
			{
				txtmp[ine].lin=txtmp[ind].lin;
				txtmp[ine].y=txtmp[ind].y;
				ine++;
			}
		}
		cloxcnt=0;
		tscr.ind=ine;
		setMap(RESTCH);
		return;
	}
	if(tscr.ind&&txtclos(&clo))
	{
		MoveMemory(&txtmp[clo],&txtmp[clo+1],(tscr.ind-clo)*sizeof(TXPNT));
		tscr.ind--;
		setMap(RESTCH);
	}
}

void txdelal()
{
	chktxnum();
	savtxt();
	tscr.ind=0;
	rstxt();
	setMap(RESTCH);
}

void chktxnum()
{
	float tflt;

	tflt=atof(txbuf);
	if(tflt)
	{
		tflt*=PFGRAN;
		switch(txsidtyp)
		{
		case HTXHI:

			savtxt();
			tscr.fhi=tflt;
			ini.txthi=tflt;
			setMap(CHKTX);
			break;

		case HTXWID:

			savtxt();
			tscr.wid=tflt;
			ini.txtwid=tflt;
			setMap(CHKTX);
			break;

		case HTXSPAC:

			savtxt();
			tscr.spac=tflt;
			ini.txtspac=tflt;
			tscr.wid=tflt*tscr.lins+tflt/2;
			setMap(CHKTX);
			break;
		}
	}
	txnind=0;
	DestroyWindow(hbsid);
	hbsid=0;
	setMap(RESTCH);
}

void txcntrv()
{
	if(rstMap(TXTCLP))
	{
		setMap(TXHCNTR);
		savtxt();
		setxclp();
		setMap(RESTCH);
	}
}

void txof()
{
	butxt(HBOXSEL,stab[STR_BOXSEL]);
	redraw(hbuts[HHID]);
	if(chkMap(UPTO))
		butxt(HUPTO,stab[STR_UPON]);
	else
		butxt(HUPTO,stab[STR_UPOF]);
	SetWindowText(hbuts[HTXSPAC],"");
	savtxt();
	zumhom();
	rstMap(TXTRED);
}

BOOL istxclp()
{
	if(chkMap(TXTMOV)&&chkMap(TXTCLP))
		return 1;
	else
		return 0;

}

void txsiz(double rat)
{
	unsigned	ind;
	FLRCT		arct;

	ritxfrm();
	for(ind=0;ind<angfrm.sids;ind++)
	{
		angflt[ind].x*=rat;
		angflt[ind].y*=rat;
	}
	angrct(&arct);
	tscr.mid.x=midl(arct.right,arct.left);
	tscr.mid.y=midl(arct.top,arct.bottom);
	ed2px(tscr.mid,&cloxref);
	ritxfrm();
}

void txshrnk()
{
	txsiz(TXTRAT);
}

void txgro()
{
	txsiz(1/TXTRAT);
}

BOOL txdig(unsigned cod,TCHAR* chr)
{
	if(isdigit(cod))
	{
		*chr=(TCHAR)cod;
		return 1;
	}
	if(cod>=VK_NUMPAD0&&cod<=VK_NUMPAD9)
	{
		*chr=(TCHAR)cod-VK_NUMPAD0+0x30;
		return 1;
	}
	if(cod==0xbe||cod==0x6e)
	{
		*chr='.';
		return 1;
	}
	return 0;
}

void txnudg(int dx,float dy)
{
	float fdy;
	float tflt;
	int ind,tlin;

	if(cloxcnt)
	{
		if(dy)
		{
			fdy=dy*tscr.ed2px;
			for(ind=0;ind<cloxcnt;ind++)
			{
				tflt=txtmp[cloxlst[ind]].y+fdy;
				if(tflt<0)
					return;
				if(tflt>tscr.fhi)
					return;
			}
			for(ind=0;ind<cloxcnt;ind++)
				txtmp[cloxlst[ind]].y+=fdy;
		}
		else
		{
			for(ind=0;ind<cloxcnt;ind++)
			{
				tlin=txtmp[cloxlst[ind]].lin+dx;
				if(tlin<1)
					return;
				if(tlin>tscr.lins)
					return;
			}
			for(ind=0;ind<cloxcnt;ind++)
				txtmp[cloxlst[ind]].lin+=dx;
		}
	}
	dutxrct(&txrct);
	setMap(RESTCH);
}

void txsnap()
{
	int ind,cnt;
	float siz2;
	TXPNT*	tp;

	if(tscr.ind)
	{
		savtxt();
		siz2=ini.grdsiz/2;
		if(cloxcnt)
		{
			for(ind=0;ind<cloxcnt;ind++)
			{
				tp=&txtmp[cloxlst[ind]];
				cnt=(tp->y+siz2)/ini.grdsiz;
				tp->y=cnt*ini.grdsiz;
			}
		}
		else
		{
			for(ind=0;ind<tscr.ind;ind++)
			{
				tp=&txtmp[ind];
				cnt=(tp->y+siz2)/ini.grdsiz;
				tp->y=cnt*ini.grdsiz;
			}
		}
		setMap(RESTCH);
	}
}

void txtkey(unsigned cod)
{
	TCHAR chr;

	if(hbsid)
	{
		switch(cod)
		{
		case VK_RETURN:

			chktxnum();
			return;

		case VK_ESCAPE:

			txof();

		case 'Q':

			rstxt();
			setMap(RESTCH);
			break;

		case 8:	//backspace

			if(txnind)
				txnind--;
			goto txskp;
		}
		if(txdig(cod,&chr))
		{
			txbuf[txnind]=chr;
			txnind++;
		}
txskp:;
		txbuf[txnind]=0;
		SetWindowText(hbsid,txbuf);
		return;
	}
	switch(cod)
	{
	case VK_ESCAPE:

		txof();

	case 'Q':

		rstxt();
		setMap(RESTCH);
		break;

	case 0xdb:	//[

		txshrnk();
		break;

	case 0xdd:	//]

		txgro();
		break;

	case 192:

		tst();
		break;
	
	case 'R':

		dutxfn(VRTYP);
		break;

	case 'A':

		dutxfn(ANGTYP);
		break;

	case 'H':

		dutxfn(ANGTYP);
		break;

	case 'E':

		txtlin();
		break;

	case 'Z':
	case 'B':

		if(!setMap(LASTXBAK))
		{
			savtxt();
			txrbak();
		}
		else
		{
			if(rstMap(TXBDIR))
				txrbak();
		}
		txbak();
		return;

	case 'V':
		
		if(OpenClipboard(hWnd))
			txtclp();
		break;

	case 'N':

		setMap(LASTXBAK);
		if(!setMap(TXBDIR))
			txrfor();
		nxbak();
		return;

	case 'D':
	case VK_DELETE:

		if(GetKeyState(VK_SHIFT)&GetKeyState(VK_CONTROL)&0X8000)
			txdelal();
		else
			txtdel();
		break;

	case 0xbd:		//-

		txcntrv();
		break;

	case VK_LEFT:

		txnudg(-1,0);
		break;

	case VK_RIGHT:

		txnudg(1,0);
		break;

	case VK_UP:

		txnudg(0,ini.nudg);
		break;

	case VK_DOWN:

		txnudg(0,-ini.nudg);
		break;

	case 'S':

		txsnap();
		break;
	}
	rstMap(LASTXBAK);
}

void setxt()
{
	TXPNT*		pbak;
	int			ind,cnt;

	savtxt();
	frmpnt->wpar=0;
	setMap(TXFIL);
	clpsiz.cx=frmpnt->fspac;
	clpsiz.cy=frmpnt->dhx.txt.hi;
	txsegs=(RNGCNT*)&rmap;
	pbak=&txpnts[frmpnt->dhx.txt.ind];
	FillMemory(txsegs,frmpnt->dhx.txt.lins*sizeof(RNGCNT),0);
	pbak=&txpnts[frmpnt->dhx.txt.ind];
	cnt=frmpnt->dhx.txt.cnt;
	if(cnt)
	{
		for(ind=cnt-1;ind>=0;ind--)
		{
			txsegs[pbak[ind].lin-1].lin=ind;
			txsegs[pbak[ind].lin-1].cnt++;
		}
	}
}

void rtrtx()
{
	TXPNT*	tps;

	fvars(clofind);
	tps=&txpnts[frmpnt->dhx.txt.ind];
	tscr.ind=frmpnt->dhx.txt.cnt;
	MoveMemory(txtmp,tps,sizeof(TXPNT)*tscr.ind);
	tscr.fhi=frmpnt->dhx.txt.hi;
	tscr.spac=frmpnt->fspac;
	tscr.lins=frmpnt->dhx.txt.lins;
	tscr.wid=tscr.lins*tscr.spac+tscr.spac/2;
	savtxt();
}

void rtrclp()
{
	if(chkMap(FORMSEL))
	{
		fvars(clofind);
		if(istx(clofind))
			rtrtx();
		else
			rtrclpfn();
	}
}

void setstxt(unsigned cod,float num)
{
	sprintf(hlpbuf,"%.2f",(float)num/PFGRAN);
	SetWindowText(GetDlgItem(sizdlg,cod),hlpbuf);
}

float getstxt(unsigned cod)
{
	GetWindowText(GetDlgItem(sizdlg,cod),hlpbuf,HBUFSIZ);
	return atof(hlpbuf)*PFGRAN;
}

BOOL chkasp(FLPNT* flt)
{
	flt->x=getstxt(IDC_DESWID);
	flt->y=getstxt(IDC_DESHI);
	if(flt->y/flt->x==daspct)
		return 1;
	else
		return 0;
}

BOOL CALLBACK setsprc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam)
{
	FLPNT	tflt;

	sizdlg=hwndlg;
	switch(umsg)
	{
	case WM_INITDIALOG:

		SendMessage(hwndlg,WM_SETFOCUS,0,0);
		setstxt(IDC_DESWID,dsgnsiz.x);
		setstxt(IDC_DESHI,dsgnsiz.y);
		daspct=dsgnsiz.y/dsgnsiz.x;
		CheckDlgButton(hwndlg,IDC_REFILF,chku(CHREF));
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam))
		{
		case IDCANCEL:

			EndDialog(hwndlg,0); 
			return TRUE;

		case IDOK:

			dsgnsiz.x=getstxt(IDC_DESWID);
			dsgnsiz.y=getstxt(IDC_DESHI);
			if(IsDlgButtonChecked(hwndlg,IDC_REFILF))
				setu(CHREF);
			else
				rstu(CHREF);
			EndDialog(hwndlg,1); 
			return TRUE;

		case IDC_DESWID:

			if((wparam>>16)==EN_CHANGE)
				rstMap(DESCHG);
			break;

		case IDC_DESHI:

			if((wparam>>16)==EN_CHANGE)
				setMap(DESCHG);
			break;

		case IDC_DUASP:

			if(!chkasp(&tflt))
			{
				if(chkMap(DESCHG))
					setstxt(IDC_DESWID,(float)tflt.y/daspct);
				else
					setstxt(IDC_DESHI,(float)tflt.x*daspct);
			}
			break;
		}
	}
	return 0;
}

void sadj(SHRTPNT* pt)
{
	pt->x=(pt->x-sizrct.left)*sizrat.x+sizrct.left;
	pt->y=(pt->y-sizrct.bottom)*sizrat.y+sizrct.bottom;
}

void sadj(FLPNT* pt)
{
	pt->x=(pt->x-sizrct.left)*sizrat.x+sizrct.left;
	pt->y=(pt->y-sizrct.bottom)*sizrat.y+sizrct.bottom;
}

void nudfn()
{
	unsigned	ind;
	FLPNT		osiz;

	osiz.x=sizrct.right-sizrct.left;
	osiz.y=sizrct.top-sizrct.bottom;
	sizrat.x=dsgnsiz.x/osiz.x;
	sizrat.y=dsgnsiz.y/osiz.y;
	for(ind=0;ind<hed.stchs;ind++)
		sadj(&stchs[ind]);
	for(ind=0;ind<fltad;ind++)
		sadj(&flts[ind]);
	frmout(clofind);
}

void nudsiz()
{
	FLPNT		osiz;
	int			flg;
	unsigned	ind;

	savdo();
	flg=0;
	if(hed.stchs)
	{
		stchrct(&sizrct);
		flg=1;
	}
	else
	{
		if(formpnt)
		{
			frmrct(&sizrct);
			flg=2;
		}
	}
	if(flg)
	{
		osiz.x=dsgnsiz.x=sizrct.right-sizrct.left;
		osiz.y=dsgnsiz.y=sizrct.top-sizrct.bottom;
		if(DialogBox(hInst,MAKEINTRESOURCE(IDD_SIZ),hWnd,(DLGPROC)setsprc))
		{
			flg=0;
			if(dsgnsiz.x>ini.hupx)
			{
				ini.hupx=dsgnsiz.x*1.05;
				zum0.x=ini.hupx;
				flg=1;
			}
			if(dsgnsiz.y>ini.hupy)
			{
				ini.hupy=dsgnsiz.y*1.05;
				zum0.y=ini.hupy;
				flg=1;
			}
			nudfn();
			if(chku(CHREF))
				refilal();
			if(flg)
			{
				movStch();
				zumhom();
				hsizmsg();
			}
			centir();
			for(ind=0;ind<formpnt;ind++)
				frmout(ind);
		}
	}
}

void dushft()
{
//	setMap(BOXSLCT);
	setMap(BZUMIN);
//	setMap(NOSEL);
	blin[0].x=blin[3].x=blin[4].x=msg.pt.x-stOrg.x;
	blin[0].y=blin[1].y=msg.pt.y-stOrg.y;
	blin[4].y=blin[0].y-1;
	px2stch();
	zBoxo.x=sPnt.x;
	zBoxo.y=sPnt.y;
}

extern void unbBox();
extern void bBox();
extern void pxCor2stch(POINT pnt);

void mvshft()
{
	if(chkMap(BOXZUM)&&setMap(VCAPT))
		SetCapture(hWnd);
	if(chkMap(BZUMIN))
	{
		if(msg.wParam&MK_LBUTTON)
		{
			if(setMap(VCAPT))
				SetCapture(hWnd);
			unbBox();
			blin[1].x=blin[2].x=msg.pt.x-stOrg.x;
			blin[2].y=blin[3].y=msg.pt.y-stOrg.y;
			setMap(BZUM);
			bBox();
		}
	}
}

BOOL inrct(FLRCT rct,SHRTPNT pt)
{
	if(pt.x<rct.left)
		return 0;
	if(pt.x>rct.right)
		return 0;
	if(pt.y<rct.bottom)
		return 0;
	if(pt.y>rct.top)
		return 0;
	return 1;
}

void setshft()
{
	FLRCT	srct;
	unsigned ind,lin;

	savtxt();
	cloxlst=(unsigned*)&oseq;
	unbBox();
	rstMap(BZUMIN);
	pxCor2stch(blin[0]);
	srct.top=sPnt.y;
	srct.left=sPnt.x;
	pxCor2stch(blin[2]);
	srct.bottom=sPnt.y;
	srct.right=sPnt.x;
	rstMap(TXIN);
	tscr.ind=0;
	lin=1;
	for(ind=0;ind<hed.stchs;ind++)
	{
		if(inrct(srct,stchs[ind]))
		{
			setMap(TXIN);
			txtmp[tscr.ind].lin=lin;
			txtmp[tscr.ind].y=stchs[ind].y-srct.bottom;
			tscr.ind++;
		}
		else
		{
			if(rstMap(TXIN))
				lin++;
		}
	}
	lin=txtmp[tscr.ind-1].lin;
	tscr.spac=(srct.right-srct.left)/lin;
	tscr.fhi=srct.top-srct.bottom;
	tscr.wid=tscr.spac*lin+tscr.spac/2;
	setMap(TXTRED);
	setMap(RESTCH);
}

void setclpspac()
{
	msgflt(IDS_CLPSPAC,ini.clpof/PFGRAN);
	setMap(NUMIN);
	setMap(SCLPSPAC);
	numWnd();
}

BOOL CALLBACK enumch(HWND hwnd,LPARAM lParam)
{
	DestroyWindow(hwnd);
	return 1;
}

void clrstch()
{
	while(EnumChildWindows(hStch,enumch,0));
}

/* workaround for wine bug */
#ifdef __WINE__
extern char **__wine_main_argv;
#endif


BOOL txnam(char* nam)
{
	char* pchr;
	char **argv = __argv;

#ifdef __WINE__
	if (!argv) argv = __wine_main_argv;
#endif

	strcpy(nam,argv[0]);
	pchr=strrchr(nam,'\\');
	if(pchr)
	{
		pchr++;
		strcpy(pchr,"thred.txr");
		return 1;
	}
	else
		return 0;
}

void txdun()
{
	char nam[MAX_PATH];
	HANDLE hnam;
	unsigned int  rot;
	int ind;
	char* sig="txh";

	if(thsts[0].cnt)
	{
		if(txnam(nam))
		{
			hnam=CreateFile(nam,GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
			if(hnam!=INVALID_HANDLE_VALUE)
			{
				WriteFile(hnam,(char*)"txh",4,&rot,0);
				WriteFile(hnam,(int*)&ptxhst,4,&rot,0);
				WriteFile(hnam,(TXHST*)&thsts,sizeof(TXHST)*16,&rot,0);
				for(ind=0;ind<16;ind++)
				{	
					if(thsts[ind].cnt)
						WriteFile(hnam,(TXPNT*)thsts[ind].txp,thsts[ind].cnt*sizeof(TXPNT),&rot,0);
				}
			}
			CloseHandle(hnam);
		}
	}
}

void redtx()
{
	char nam[MAX_PATH];
	HANDLE hnam;
	unsigned int red;
	int ind;
	char sig[4];

	ptxhst=15;
	ZeroMemory(&thsts,sizeof(TXHST)*16);
	if(txnam(nam))
	{
		hnam=CreateFile(nam,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
		if(hnam!=INVALID_HANDLE_VALUE)
		{
			ReadFile(hnam,(char*)&sig,4,&red,0);
			if(!strcmp(sig,"txh"))
			{
				ReadFile(hnam,(int*)&ptxhst,4,&red,0);
				ReadFile(hnam,(TXHST*)&thsts,sizeof(TXHST)*16,&red,0);
				for(ind=0;ind<16;ind++)
				{
					if(thsts[ind].cnt)
					{
						thsts[ind].txp=new TXPNT[thsts[ind].cnt];
						ReadFile((TXPNT*)hnam,thsts[ind].txp,sizeof(TXPNT)*thsts[ind].cnt,&red,0);
					}
				}
				setMap(WASTXBAK);
			}
		}
		CloseHandle(hnam);
	}
	redtbak();
}

void setangf(double tang)
{
	unsigned ind;
	double angbak;

	angbak=ang;
	ang=tang;
	MoveMemory(&angfrm,frmpnt,sizeof(FRMHED));
	MoveMemory(&angflt,flt,sizeof(FLPNT)*sids);
	rotcntr.x=(double)(angfrm.rct.right-angfrm.rct.left)/2+angfrm.rct.left;
	rotcntr.y=(double)(angfrm.rct.top-angfrm.rct.bottom)/2+angfrm.rct.bottom;
	angfrm.flt=angflt;
	if(ang)
	{
		for(ind=0;ind<sids;ind++)
			rotflt(&angflt[ind]);
	}
	frmpnt=&angfrm;
	flt=angflt;
	ang=angbak;
}

void chgwrn()
{
	toglu(WRNOF);
	wrnmen();
	setMap(DUMEN);
}

void chgchk(int cod)
{
	ini.dchk=cod;
	chkmen();
	setMap(DUMEN);
}

void lodchk()
{
	unsigned	ind,at;

	delinf();
	for(ind=0;ind<formpnt;ind++){

		frmpnt=&formlst[ind];
		if(!frmpnt->typ)
			frmpnt->typ=POLI;
		else{

			if(frmpnt->typ==LIN){

				if(frmpnt->ftyp!=CONTF){

					frmpnt->ftyp=0;
					frmpnt->flencnt.nclp=0;
				}
			}
		}
		frmout(ind);
		if(!frmpnt->fmax)
			frmpnt->fmax=ini.maxsiz;
		if(!frmpnt->emax)
			frmpnt->emax=ini.maxsiz;
	}
	clRmap((MAXFORMS>>5)+1);
	for(ind=0;ind<hed.stchs;ind++){
	
		at=stchs[ind].at;
		if((at&TYPMSK)==TYPFRM)
			setr((at&FRMSK)>>FRMSHFT);

	}
	for(ind=0;ind<formpnt;ind++){

		if(!chkr(ind))
			formlst[ind].ftyp=0;
	}
	clRmap((MAXFORMS>>5)+1);
	for(ind=0;ind<hed.stchs;ind++){
	
		at=stchs[ind].at;
		if(at&TYPBRD)
			setr((at&FRMSK)>>FRMSHFT);
	}
	for(ind=0;ind<formpnt;ind++){

		if(!chkr(ind))
			formlst[ind].etyp=0;
	}
}

void chkclp(FRMHED* fp, BADCNTS* bc)
{
	if(bc->clp==fp->angclp.clp-clps)
		bc->clp+=fp->flencnt.nclp;
	else
		bc->at|=BADCLP;
}

void chkeclp(FRMHED* fp,BADCNTS* bc)
{
	if(bc->clp==fp->clp-clps)
		bc->clp+=fp->nclp;
	else
		bc->at|=BADCLP;
}

unsigned frmchkfn()
{
	unsigned	ind;
	FRMHED*		fp;
	BADCNTS		bc;

	FillMemory(&bc,sizeof(BADCNTS),0);
	if(formpnt)
	{
		for(ind=0;ind<formpnt;ind++)
		{
			fp=&formlst[ind];
			if(!(bc.at&BADFLT))
			{
				if(!fp->sids)
					bc.at|=BADFLT;
				if(bc.flt==fp->flt-flts)
					bc.flt+=fp->sids;
				else
					bc.at|=BADFLT;
			}
			if(!(bc.at&BADCLP))
			{
				if(isclp(ind))
					chkclp(fp,&bc);
				if(iseclp(ind))
					chkeclp(fp,&bc);
			}
			if(fp->typ==SAT&&fp->stpt)
			{
				if(!(bc.at&BADSAT))
				{
					if(bc.sat==fp->sacang.sac-satks)
						bc.sat+=fp->stpt;
					else
						bc.at|=BADSAT;
				}
			}
			if(istx(ind))
			{
				if(!(bc.at&BADTX))
				{
					if(bc.tx==fp->dhx.txt.ind)
						bc.tx+=fp->dhx.txt.cnt;
					else
						bc.at|=BADTX;
				}
			}
			if(bc.at==(BADFLT|BADCLP|BADSAT|BADTX))
				break;
		}
		if(bc.flt!=(int)fltad)
			bc.at|=BADFLT;
		if(bc.clp!=(int)clpad)
			bc.at|=BADCLP;
		if(bc.sat!=(int)satkad)
			bc.at|=BADSAT;
		if(bc.tx!=txad)
			bc.at|=BADTX;
	}
	return bc.at;
}

void frmchkx()
{
	unsigned cod;

	if(ini.dchk)
	{
		cod=frmchkfn();
		switch(ini.dchk)
		{
		case 1:
			
			if(cod)
				datmsg(cod);
			break;

		case 2:

			if(cod)
				repar();
			break;

		case 3:

			if(cod)
			{
				repar();
				tabmsg(IDS_DATREP);
			}
		}
	}
}

void bcup(unsigned find,BADCNTS* bc)
{
	FRMHED* fp;

	fp=&formlst[find];
	if(isclp(find))
		bc->clp+=fp->flencnt.nclp;
	if(iseclp(find))
		bc->clp+=fp->nclp;
	if(fp->typ==SAT)
		bc->sat+=fp->stpt;
	if(istx(find))
		bc->tx+=fp->dhx.txt.cnt;
}

void chkfstch()
{
	unsigned cod,ind;

	cod=formpnt<<FRMSHFT;
	for(ind=0;ind<hed.stchs;ind++)
	{
		if((stchs[ind].at&FRMSK)>=cod)
			stchs[ind].at=NOTFRM;
	}
}

void repflt()
{
	FLPNT* tflt;
	unsigned ind,loc,cnt,dif;
	FRMHED* fp;
	BADCNTS bc;

	loc=0;
	for(ind=0;ind<formpnt;ind++)
	{
		if(formlst[ind].sids)
			MoveMemory(&formlst[loc++],&formlst[ind],sizeof(FRMHED));
	}
	formpnt=loc;
	ZeroMemory(&bc,sizeof(BADCNTS));
	tflt=(FLPNT*)bseq;
	loc=cnt=0;
	for(ind=0;ind<formpnt;ind++)
	{
		fp=&formlst[ind];
		dif=fp->flt-flts;
		if(fltad>=dif+fp->sids)
		{
			MoveMemory(&tflt[loc],fp->flt,fp->sids*sizeof(FLPNT));
			fp->flt=&flts[loc];
			loc+=fp->sids;
			bcup(ind,&bc);
		}
		else
		{
			if(dif<fltad)
			{
				fp->sids=fltad-dif;
				delsac(ind);
				MoveMemory(&tflt[loc],fp->flt,fp->sids*sizeof(FLPNT));
				bcup(ind,&bc);
			}
			else
			{
				formpnt=ind;
				clpad=bc.clp;
				satkad=bc.sat;
				txad=bc.tx;
				chkfstch();
				adbad(IDS_FRMDAT,formpnt-ind+1);
				goto rfltskp;
			}
		}
	}
	fltad=loc;
rfltskp:;
	MoveMemory(flts,tflt,sizeof(FLPNT)*fltad);
}

void repclp()
{
	FRMHED*		fp;
	unsigned	ind,cnt,loc,bcnt;
	FLPNT*		tclps;

	bcnt=cnt=0;
	tclps=(FLPNT*)&bseq;
	for(ind=0;ind<formpnt;ind++)
	{
		fp=&formlst[ind];
		if(isclp(ind))
		{
			loc=fp->angclp.clp-clps;
			if(loc+fp->flencnt.nclp<clpad)
			{
				MoveMemory(&tclps[cnt],fp->angclp.clp,sizeof(FLPNT)*fp->flencnt.nclp);
				fp->angclp.clp=&clps[cnt];
				cnt+=fp->flencnt.nclp;
			}
			else
			{
				if(loc<clpad)
				{
					fp->flencnt.nclp=fltad-loc;
					MoveMemory(&tclps[cnt],fp->angclp.clp,sizeof(FLPNT)*fp->flencnt.nclp);
					fp->angclp.clp=&clps[cnt];
					cnt+=fp->flencnt.nclp;
				}
				else
				{
					bcnt++;
					fp->ftyp=0;
				}
			}
		}
		if(iseclp(ind))
		{
			loc=fp->clp-clps;
			if(loc+fp->nclp<clpad)
			{
				MoveMemory(&tclps[cnt],fp->clp,sizeof(FLPNT)*fp->nclp);
				fp->clp=&clps[cnt];
				cnt+=fp->nclp;
			}
			else
			{
				if(loc<clpad)
				{
					fp->nclp=fltad-loc;
					MoveMemory(&tclps[cnt],fp->clp,sizeof(FLPNT)*fp->nclp);
					fp->clp=&clps[cnt];
					cnt+=fp->nclp;
				}
				else
				{
					bcnt++;
					fp->ftyp=0;
				}
			}
		}
	}
	MoveMemory(&clps,tclps,cnt*sizeof(FLPNT));
	clpad=cnt;
	if(bcnt)
		adbad(IDS_CLPDAT,bcnt);
}

void repsat()
{
	unsigned ind,loc,cnt,dif;
	FRMHED* fp;
	BADCNTS bc;

	ZeroMemory(&bc,sizeof(BADCNTS));
	loc=cnt=0;
	for(ind=0;ind<formpnt;ind++)
	{
		fp=&formlst[ind];
		if(fp->typ==SAT)
		{
			dif=fp->sacang.sac-satks;
			if(fltad>dif+fp->sids)
			{
				MoveMemory(&satks[loc],fp->sacang.sac,fp->stpt*sizeof(SATCON));
				fp->sacang.sac=&satks[loc];
				loc+=fp->stpt;
				bcup(ind,&bc);
			}
			else
			{
				if(dif<satkad)
				{
					fp->stpt=satkad-dif;
					MoveMemory(&satks[loc],fp->sacang.sac,fp->stpt*sizeof(SATCON));
					bcup(ind,&bc);
				}
				else
				{
					loc=bc.sat;
					fp->stpt=0;
				}
			}
		}
	}
	satkad=loc;
}

void reptx()
{
	unsigned ind,loc,cnt;
	FRMHED* fp;
	BADCNTS bc;

	ZeroMemory(&bc,sizeof(BADCNTS));
	loc=cnt=0;
	for(ind=0;ind<formpnt;ind++)
	{
		if(istx(ind))
		{
			fp=&formlst[ind];
			if(txad>fp->dhx.txt.ind+fp->dhx.txt.cnt)
			{
				MoveMemory(&satks[loc],&satks[fp->dhx.txt.ind],fp->dhx.txt.cnt*sizeof(SATCON));
				fp->dhx.txt.ind=loc;
				loc+=fp->dhx.txt.cnt;
				bcup(ind,&bc);
			}
			else
			{
				if(txad>fp->dhx.txt.ind)
				{
					fp->dhx.txt.cnt=txad-fp->dhx.txt.ind;
					MoveMemory(&satks[loc],&satks[fp->dhx.txt.ind],fp->dhx.txt.cnt*sizeof(SATCON));
					fp->dhx.txt.ind=loc;
					bcup(ind,&bc);
					loc=bc.tx;
				}
				else
					fp->ftyp=0;
			}
		}
	}
	txad=loc;
}

void repar()
{
	unsigned cod;

	savdo();
	sdat=msgbuf;
	cod=frmchkfn();
	if(cod&BADFLT)
		repflt();
	if(cod&BADCLP)
		repclp();
	if(cod&BADSAT)
		repsat();
	if(cod&BADTX)
		reptx();
	lodchk();
	setMap(RESTCH);
	if(sdat!=msgbuf)
	{
		sdat--;
		*sdat=0;
		shoMsg(msgbuf);
	}
}

void tst()
{
	strcpy(ini.desnam,"Mr");
	strcpy(thrnam,ini.desnam);
	setMap(RESTCH);
}
