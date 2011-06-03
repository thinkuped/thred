#include <windows.h>
#include <stdio.h>
#include <strings.h>
#include <math.h>
#include "tchar.h"
#include "lang.h"
#include "resource.h"
#include "thred.h"
#include "bits.h"

void flipv();
void duangs();
void dufxlen();
void duxclp();
void dulast();
void wavfrm();
BOOL cisin(float pntx,float pnty);

extern			void		insadj();
extern			void		setfchk();
extern			int			txad;
extern			void		setangf(double tang);
extern			TXPNT		txpnts[MAXSEQ];
extern			RNGCNT*		txsegs;
extern			void		setxt();
extern			void		angrct(FLRCT* rct);
extern			FLRCT		isrct;
extern			void		deltx();
extern			BOOL		istx(unsigned find);
//extern			void		txseq();
extern			void		fntxvrt();
extern			void		txtfrm();
extern			void		intlv();
extern			INSREC		isinds[10];
extern			unsigned	isind2;
extern			unsigned	isind;
extern			unsigned	smap;
extern			FSTRTS		fstrts;
extern			FLPNT		iseq[MAXSEQ];
extern			void		fdelstch();
extern			void		chkcwlk();
extern			void		undcon();
extern			FLPNT*		insid();
extern			void		dasyfrm();
extern			FLPNT*		uflt;
extern			void		chkwlk();
extern			void		chkund();
extern			void		dubdel(unsigned cod);
extern			void		srtcol();
extern			void*		bakdat[16];
extern			unsigned	dupnt0;
extern			void		fritfil();
extern			void		fthrfn();
extern			void		setpsel();
extern			void		shoMsg(TCHAR* str);
extern			unsigned	setMap(unsigned bPnt);
extern			unsigned	rstMap(unsigned bPnt);
extern			void		centr();
extern			unsigned	chkMap(unsigned bPnt);
extern			void		rstAll();
extern			unsigned	px2stch();
extern			void		redraw(HWND dWnd);
extern			unsigned	toglMap(unsigned bPnt);
extern			void		coltab();
extern			void		pxCor2stch(POINT pnt);
extern			unsigned	chku(unsigned bPnt);
extern			void		savdo();
extern			void		redclp();
extern			void		rotang1(SHRTPNT rpnt,FLPNT* tpnt);
extern			void		unmsg();
extern			void		unsid();
extern			void		ritot(unsigned num);
extern			unsigned	duthrsh(double var);
extern			void		numWnd();
extern			void		stch2px1(unsigned stind);
extern			void		rngadj();
extern			void		clRmap(unsigned len);
extern			unsigned	setRmp(POINT* sPnt);
extern			void		chkrng(FLPNT* rsiz);
extern			unsigned	setRmap(SHRTPNT sPnt);
extern			void		selRct(FLRCT* srct);
extern			void		rotfn();
extern			void		unsel();
extern			void		uncros();
extern			void		unlin();
extern			void		ritmov();
extern			void		frmdel();
extern			void		zumhom();
extern			void		movStch();
extern			BOOL		filmsgs(unsigned cod);
extern			void		grpAdj();
extern			void		nfilmsg(TCHAR* str);
extern			FLPNT*		adflt(unsigned cnt);
extern			SATCON*		adsatk(unsigned cnt);
extern			void		ritnum(unsigned cod,unsigned num);
extern			void		shft(FLPNT shPnt);
extern			void		ritfcor(FLPNT* pnt);
extern			void		nuRct();
extern			void		stch2pxr(FLPNT stpnt);
extern			void		duzrat();
extern			void		rotangf(FLPNT rpnt,FLPNT* tpnt);
extern			FLPNT*		adclp(unsigned cnt);
extern			TCHAR*		mvflpnt(FLPNT* dst,FLPNT* src,unsigned cnt);
extern			void		mvsatk(SATCON* dst,SATCON* src,unsigned cnt);
extern			void		mvstchs(unsigned dst,unsigned src,unsigned cnt);
extern			void		unbsho();
extern			void		mvstch(unsigned dst,unsigned src);
extern			void		delstchm();
extern			void		undat();
extern			BOOL		isclp(unsigned find);
extern			BOOL		isclpx(unsigned find);
extern			void		delinf();
extern			void		pntmsg(unsigned cod);
extern			void		sdmsg();
extern			void		alrotmsg();
extern			void		grpselmsg();
extern			void		shortr();
extern			void		shord();
extern			void		spltmsg();
extern			void		shocent();
extern			void		stchun();
extern			void		stchremsg();
extern			void		tabmsg(unsigned cod);
extern			void		frm1pnt();
extern			void		shoseln(unsigned cod0,unsigned cod1);
extern			void		durpoli(unsigned nsids);
extern			void		ler();
extern			void		clpxadj();

extern			POINT		pselfin;
extern			unsigned	fsizeof;
extern			RNGC		pselrng;
extern			HWND		hStch;
extern			HWND		hMsg;
extern			HWND		hsidWnd[11];
extern			HWND		hPrf;
extern			HWND		hfdat;
extern			HWND		hto;
extern			RECT		mRct;
extern			HED			hed;
extern			RECT		scRct;
extern			RECT		sRct;
extern			DUBRCT		zRct;

extern			HDC			sdc;
extern			HDC			rsdc;

extern			HPEN		fPen;
extern			HPEN		fPen3;
extern			HPEN		fsPen;
extern			HPEN		ypen[5];

extern			FLPNT		sPnt;
extern			POINT		zum0;
extern			POINT		stOrg;
extern			POINT*		plin;
extern			DUBPNT		rotcntr;
extern			POINT		inlin[3];

double			hfrat;
extern			double		stchAspct;

extern			MSG			msg;

extern			double		usesiz;
extern			double		minsiz;
extern			double		smalsiz;
extern			double		ang;
extern			double		shopnts;
extern			double		stchboxs;
extern			double		zumFct;
extern			double		savang;
extern			unsigned	buttonWid;
extern			unsigned	actcol;
extern			unsigned	map[MAPLEN];
extern			unsigned	cloInd;
extern			unsigned	gpnt0;
extern			unsigned	gpnt1;
extern			unsigned	hClip;
extern			unsigned	apcol;
extern			unsigned	msgpnt;
extern			unsigned	prfind;
extern			unsigned	sidtyp;
extern			unsigned	slpnt;
extern			unsigned	selCnt;
extern			unsigned	grpInd;
extern			DUBPNT		zrat;
extern			HWND		hWnd;
extern			HMENU		hMen;
extern			HMENU		hfilMen;
extern			HWND		hok;
extern			HWND		hcan;
extern			HWND		hdsc;
extern			RECT		msgRct;
extern			HGLOBAL		hClpMem;
extern			unsigned	buttonWid3;
extern			unsigned	buttonHi;
extern			HINSTANCE	hInst;
extern			void		mvstch(SHRTPNT* dst, SHRTPNT* src);
extern			void		delfstchs();
extern			BOOL		isfclp();
extern			FLRCT		pselrct;
extern			RECT		pxselrct;

extern			DUBPNT		mrkpnt;
extern			SHRTPNT		stchs[MAXPCS];
extern			SHRTPNT		clpnu[MAXFRMLINS];
extern			unsigned	clplen;			//number of stitchs extracted from clipboard
extern			HCURSOR 	hCros;
extern			HCURSOR 	hAr;
extern			TCHAR		msgbuf[MSGSIZ];
extern			TCHAR		sidbuf[11];	
extern			TCHAR*		pcdClip;
extern			void		sCor2px(DUBPNT stpnt,POINT* pxpnt);
extern			void*		clpvoid;
extern			CLPSTCH*	clpdat;
extern			FLRCT		clprct;
extern			FLSIZ		clpsiz;
extern			FRMHED*		frmpnt;			//pointer to selected form
extern			HWND		hSid;
extern			unsigned	numpnt;
extern			unsigned	rmap[RMAPSIZ];
extern			POINT		stchSiz;
extern			HPEN		uPen[16];
extern			HPEN		fmpen;
extern			HPEN		alpen;
extern			FLRCT		rotrct;
extern			unsigned	actl;
extern			unsigned	laycod;
extern			FLRCT		rngrct;	
extern			unsigned	dunmap[MAXFRMLINS/32+1];
extern			void		rotflt(FLPNT* pnt);
extern			FLPNT		bigsiz;
extern			unsigned	toglu(unsigned bPnt);
extern			TCHAR		thrnam[MAX_PATH];
extern			POINT		sizlin[5];
extern			INIFIL		ini;
extern			POINT		pPnt;
extern			POINT		morg;
extern			POINT		scend;
extern			DUBPNT		zumend;
extern			unsigned	bwid;
extern			unsigned	bhi;
extern			HDC			bitdc;
extern			TCHAR*		stab[STR_LEN];
extern			unsigned	prfsiz;

void			lcon();
void			filvrt();
void			filang();
void			fnvrt();
void			satfil();
void			frmsqr(unsigned ind);
void			uncon();
void			uninsf();
void			rotfrm(unsigned nu0);
void			brdfil(double siz);
void			clpbrd(unsigned short slin);
void			fnhor();
void			oclp(FLPNT* clp,unsigned nclp);
unsigned short	nxt(unsigned short ind);
void			bdrlin(unsigned strt,unsigned fin,double siz);
void			rbrd();
void			satout(double satwid);
void			slbrd();
void			clpout();
void			sbrd();
void			lapbrd();
void			apbrd();
void			bold(double siz);
void			plbrd(double spac);
void			prpbrd(double spac);
void			pbrd(double spac);
unsigned short	prv(unsigned ind);
void			fmclp();
unsigned		setdun(unsigned bpnt);
void			bakseq();
void			setr(unsigned pbit);
BOOL			chkr(unsigned pbit);
void			selal();
void			blbrd(double spac);
void			bhbrd(double spac);
void			clpic(unsigned short strtlin);
void			contf();
void			filinsb(DUBPNT pnt);
void			fvars(unsigned ind);
unsigned		psg();
void			frmpnts(unsigned typ);
void			clpcon();
void			horsclp();
void			angsclp();
void			dubfn();
void			horclpfn();
void			angclpfn();
void			duhart(unsigned nsids);
BOOL			iseclp(unsigned find);
BOOL			iseclpx(unsigned find);
void			deleclp(unsigned ind);
void			delmclp(unsigned ind);
void			dufcntr(DUBPNT* cntr);
void			chnfn();
void			chan();
void			sRct2px(FLRCT strct,RECT* pxrct);

unsigned		refmcnt;				//lines in the form-form
float			maxs;					//maximum stitch length
float			uslen;					//user stitch length
double*			sins;					//a list if sins of form angles
double*			cosins;					//a list if cosins of form angles
double			adjspac;				//adjusted space
unsigned		nxstrt;					//index of the endpoint of the line segment being processed
FLPNT*			chpnts;					//end points of chain stiches
unsigned		chseq[]={0,1,2,3,0,1,4,3,0,3};//chain stich sequence
double			div4;					//chain space divided by four
unsigned		chncnt;					//number of elements of the chain sequence to process

unsigned		clofind;				//closest form to the cursor
unsigned		clofinx;				//end point of selected range of forms
unsigned		clofine;				//point closest to the cursor
double			vfrat;					//vertical ratio between the zoom window
										// and the entire stitch space
POINT			flin[MAXFRMLINS];		//used in the form drawing routines
unsigned		nuflen;					//points in the new form
FRMINFO			finfo;					//form info used in drawing forms
FRMHED			formlst[MAXFORMS];		//a list of pointers to forms
unsigned		formpnt=0;				//index into the list of forms
double			stspace=DEFSPACE*PFGRAN;//stitch spacing in stitch units
double			angl=DEFANG;			//fill rotation angle
unsigned		frmtyp;					//user is creating a new form of this type
FLPNT*			lin;					//pointer to the line of the polygon being filled
FLPNT*			filclp;					//data for clipboard fills
FLPNT*			clprev;					//data for clipboard fills
unsigned		spnt;					//count of stitch lines
SMALPNTL*		lins;					//pairs of fill line endpoints
unsigned		dpnt;					//pointer to the active line in the sequencing algorithm
unsigned		xpnt;					//pointer to the active point in the sequencing algorithm
unsigned		maxlins;				//maximum angle fill lines for any adjusted y cordinate
unsigned		grpind;					//pointer for groups of fill line segments
SMALPNTL**		seq;					//sorted pointers to lins
unsigned short	sids;					//sides of the selected form to fill
unsigned		lpnt;					//for connecting fill lines
unsigned		seqpnt;					//sequencing pointer
BSEQPNT			bseq[BSEQLEN];			//reverse sequence for polygon fills
FLPNT			oseq[OSEQLEN];			//temporary storage for sequencing
double			slop;					//slope of line in angle fills
unsigned		satpt;					//pointer to next satin point to enter
FLPNT			fmovdif;				//offset for moving forms
unsigned		frmstrt;				//points to the first stitch in a form
unsigned		frmend;					//points to one past the last stitch in a form
POINT			bakpnt;					//user moved a form point to here
FLPNT			tpoly[MAXFRMLINS];		//temporary storage when user is entering a polygon;
unsigned short	lin0,lin1;				//from and to lines in angle fill
unsigned		opnt;					//output pointer for sequencing
double*			lens;					//array of cumulative lengths used in satin fills
FLPNT*			flt;					//points in the currently selected form
SATCON*			sac;					//connections in the currently selecteed form
unsigned short	stpt;					//number of connections in the currently selected form
unsigned short	wpar;					//word paramater from the currently selected form
unsigned*		chkmap;					//bitmap used by satin fill to delete illegal lines
unsigned short	xstrt;					//starting point for a sating stitch guide-line
FLPNT*			clp;					//pointer to the clipboard data for clipboard fills
unsigned short	nclp;					//number of clipboard data points
double			plen;					//horizontal length of a clipboard fill/2
double			plen2;					//horizontal length of a clipboard fill		
FLPNT			lastpnt;				//last point written by lin connect routine
double			bac;					//border accumular for filling
FLPNT			opntlst[MAXFRMLINS];	//list of outside outline points for satin or clipboard fills
FLPNT			ipntlst[MAXFRMLINS];	//list of inside outline points for satin or clipboard fills
FLPNT*			opnts;					//pointer to the list of outside outline points
FLPNT*			ipnts;					//pointer to the list of inside outline points
FLPNT			clpref;					//clipboard reference point
double			brdwid=BRDWID;			//border width for satin borders
unsigned		delpnt;					//points to deleted stitches for refilling
unsigned short	lastflt;				//last form point to be filled
unsigned		cntrl;					//user selected form control point
POINT			rctlin[10];				//form control rectangle in pixel coordinates
unsigned		fixed;					//part of form rectangle that is fixed during stretching or expanding
double			xpct;					//expand form aspect ratio
HWND			thDat[LASTLIN];			//data handles for the form data sheet
HWND			thTxt[LASTLIN];			//text handles for the form data sheet
RECT			loc0;					//location of left windows in the form data sheet
RECT			loc1;					//location of right windoww in the form data sheet
POINT			siz0;					//size of the left windows in the form data sheet
POINT			siz1;					//size of the right windows in the form data sheet
FLPNT			lolft;					//lower left point in a form
VRCT2*			pvrct;					//fill points for vertical satin fill
VRCT2*			uvrct;					//underlay fill points for vertical satin fill
POINT			mvlin[3];					//points to form points to be moved
unsigned*		xhst;					//x histogram for snap together
FLPNT			rsiz;					//hoop size
double			snplen=SNPLEN*PFGRAN;		//snap together length
unsigned*		xpnts;					//stitch indices sorted according to x values
unsigned		colmap;					//bitmap of colors in a design for sort
unsigned		dunmap[MAXFRMLINS/32+1];	//bitmap of sorted segments
double			starat=STARAT;			//star point to body ratio
double			spirwrap=SPIRWRAP;		//number of revolutions in a spiral
unsigned		srtmsk=(1<<EGSAT)|(1<<EGAP)|(1<<EGPRP);  //mask for switchable fill types
RCON*			pmap;					//path map for sequencing
unsigned		cpnt;					//number of entries in the path map
TCHAR*			visit;					//visited character map for sequencing
unsigned		vispnt;					//next unvisited region for sequencing
unsigned		rgcnt;					//number of regions to be sequenced
RGN*			rgns;					//a list of regions for sequencing
unsigned		dunrgn;					//last region sequenced
double			rgclos;					//region close enough threshold for sequencing
unsigned*		minds;					//pointers to sets of adjacent regions
RGSEQ*			rgpth;					//path to a region
unsigned		pthlen;					//length of the path to the region
unsigned		grindpnt;				//number of group indices
unsigned*		grinds;					//array of group indices for sequencing
unsigned		lastgrp;				//group of the last line written in the previous region;
FSEQ*			mpath;					//path of sequenced regions
RGSEQ*			tmpath;					//temporary path connections
unsigned		mpathi;					//index to path of sequenced regions
unsigned		nxtgrp;					//group that connects to the next region
unsigned*		seqmap;					//a bitmap of sequenced lines
unsigned*		srgns;					//an array of subregion starts
RGN*			durpnt;					//region currently being sequenced
FLPNT			dunpnts[4];				//corners of last region sequenced
FRMHED			angfrm;					//a temporary rotated form for angle fills
unsigned short	selist[MAXFORMS];		//a list of selected forms
unsigned		fselpnt=0;				//number of selected forms
unsigned		baksel;					//previously selected form
RECT			bigrct;					//for multiple selections;
POINT			biglin[9];				//line derived from the big rectangle
POINT			pselin[9];				//line derived from the point select rectangle
FLRCT			rctal;					//rectangle enclosing all forms and stitches
double			angs[MAXFRMLINS];		//angles of a form for satin border fills
FLPNT			flts[MAXFRMPNTS];		//form points
unsigned		fltad;					//next index to append form points
FLPNT			clps[MAXCLPNTS];		//main clipboard fill points for forms
unsigned		clpad;					//next index to append main clipboard points
SATCON			satks[MAXSAC];			//satin form connects
unsigned		satkad;					//next index to append satin connect points
float			bfclen=IBFCLEN;			//buttonhole corner length
float			picspac=IPICSPAC;		//space between border picots
unsigned		psgacc;					//pseudo-random sequence register
SECNDS*			preg;					//segments for sorting colors and forms
unsigned		prgind;					//segment sorting index;
DUBPNT			filbak[8];				//backup stitches in satin fills
unsigned		pfbak;					//pointer for backup stitches in satin fills
double			clpang;					//for clipboard border fill
DUBPNT			mvpnt;					//moving point for clipboard fill
SHRTPNT			rclpnt;					//for rotating clipboard fill
double			cosang;					//cosine for clipboard fill
double			sinang;					//sine for clipboard fill
FLPNT			rclpref;				//reference for clipboard line border
unsigned		clpstrt;				//active form point for line clipboard fill
DUBPNT			vct0;					//x size of the clipbord fill at the fill angle
FRMHED*			rfrmlst;				//temporary form header storage for reordering forms
FLPNT*			rflts;					//temporary form point storage for reording forms
SATCON*			rsats;					//temporary satin guidline storage for reording forms					
FLPNT*			rclps;					//temporary clipboard point storage for reording forms
unsigned		frepnt;					//form relocator pointer
SHRTPNT*		hifstch;				//pointer to high stitch area for form sort
unsigned		beancnt;				//number of stitches added by convert to bean
FRMHED*			finspnt;				//insert form points in this form
unsigned		fgpnt0;					//form point storage for form point insert
unsigned		fgpnt1;					//form point storage for form point insert
SMALPNTL*		seqlin;					//line for vertical/horizontal/angle fills
unsigned		mpath0;					//point to the next path element for vertical fill sequencint
FLPNT*			lconflt;				//form points for angle fills
FLPNT			angflt[MAXFRMLINS];		//form point data for angle fills
FLPNT*			clpseq;					//pointer to vertucal clipboard fill data
double			minot;					//minimum distance from a line
unsigned		minotl;					//index to the minimum distance line
CLPSEG*			clpsegs;				//clipboard segments for virtual clipboard fill
unsigned		pcseg;					//clipboard segment pointer
unsigned		pcseg2;					//clipboard segment pointer * 2
unsigned short	vclpsid;				//clipboard intersect sid;
float**			plens;					//array of sorted side lengths for verticoal clipboard fill
FLPNT			vpnt0;					//vertical clipboard line segement start
FLPNT			vpnt1;					//vertical clipboard line segement end
double*			clplens;				//lengths of form sides for vertical clipboard fill
CLIPSORT*		clpsrt;					//intersect points for vertical clipboard fill
CLIPSORT**		pclpsrt;				//pointers to line intersect points
CLIPNT*			clipnts;				//points for vertical clipboard fills
VCLPX*			vclpx;					//region crossing data for vertical clipboard fills
unsigned*		iclpx;					//indices into region crossing data for vertical clipboard fills
unsigned		vlim;					//wrap limit for vertical clipboard fills
unsigned		clplim;					//vertical clipboard search limit
float			clpcirc;				//circumference of the vertical clipboard fill form
float			clpcirc2;				//circumference of the vertical clipboard fill form / 2
float			strtlen;				//distance from zero point of first vertical clipboard segment
unsigned		vstrt;					//start of region crossing data for a particular region
unsigned		vfin;					//end of region crossing data for a particular region
float			clpwid;					//horizontal spacing for vertical clipboard fill
unsigned		regof;					//starting region for vertical clipboard fill
HWND			htim;					//prograss bar
HDC				timdc;					//progress bar device context
double			timstp;					//progress bar step
double			timpos;					//progress bar postiion
FLOAT			fltof;					//form offset for clipbaord fills
long			prfwid;					//width of the preference window
double			egrat;					//ratio for shrinking eggs

TCHAR*		laytxt[]={

	"0",
	"1",
	"2",
	"3",
	"4"
};

TCHAR		oftxt[16];

MENUITEMINFO meninfo={

	sizeof(MENUITEMINFO),
	MIIM_TYPE,			
	MFT_STRING,			
	0,					
	0,					
	0,					
	0,					
	0,					
	0,					
	oftxt,			
	16,					
};

unsigned short egaray[]={

	MEGLIN,
	MEGBLD,
	MEGCLP,
	MEGSAT,
	MEGAP,
	MEGPRP,
	MEGHOL,
	MEGPIC,
	MEGDUB,
	MEGCHNH,
	MEGCHNL,
	MEGCLPX,
};

unsigned char lvl00=0;
unsigned char lvl01=1;
unsigned char lvl02[]={0,1};
unsigned char lvl03[]={1,0,2};
unsigned char lvl04[]={1,3,0,2};
unsigned char lvl05[]={2,0,3,1,4};
unsigned char lvl06[]={3,0,2,4,1,5};
unsigned char lvl07[]={3,0,4,1,6,2,5};
unsigned char lvl08[]={4,0,5,1,3,6,2,7};
unsigned char lvl09[]={4,0,5,1,6,2,7,3,8};
unsigned char lvl10[]={5,0,6,1,7,2,8,3,9,4};
unsigned char lvl11[]={5,0,6,1,7,2,8,3,9,10};
unsigned char lvl12[]={6,0,7,1,8,2,9,3,10,4,11};
unsigned char lvl13[]={6,0,1,7,2,8,3,9,4,10,5,11,6,12};
unsigned char lvl14[]={7,0,8,1,9,2,10,3,11,4,12,5,13,6};
unsigned char lvl15[]={7,0,8,1,9,2,10,3,11,4,12,5,13,6,14,7,15};

unsigned char* lvls[]={

&lvl00,&lvl01,&lvl02[0],&lvl03[0],&lvl04[0],&lvl05[0],&lvl06[0],&lvl07[0],&lvl08[0],
&lvl09[0],&lvl10[0],&lvl11[0],&lvl12[0],&lvl13[0],&lvl14[0],&lvl15[0]
};

#pragma warning(disable:4244)

void frmcpy(FRMHED* dst,FRMHED* src){
	memcpy(dst, src, sizeof(FRMHED));
}

void frmclr(FRMHED* dst){
	memset(dst, 0, sizeof(FRMHED));
}

//Copies type, attributes, and sids from hed to finfo
void duinf(FRMHED* hed){
	finfo.typ = hed->typ; 
	finfo.at = hed->at;
	finfo.sids = hed->sids;
}

//Compares DUPNTS, by y then by x.
int comp(const void *arg1, const void *arg2){
	const DUBPNTL **pnts1 = (const DUBPNTL **) arg1, **pnts2 = (const DUBPNTL **) arg2;

	if ((*pnts2)->y < (*pnts1)->y)
		return 1;
	if ((*pnts2)->y > (*pnts1)->y)
		return -1;

	if ((*pnts2)->x < (*pnts1)->x) 
		return 1;
	if ((*pnts2)->x > (*pnts1)->x)
		return -1;

	return 0;
}

void getfinfo(unsigned ind){

	duinf(&formlst[ind]);
}

//which idx is pnt in satks
unsigned satind(SATCON* pnt){
	return pnt - satks;
}

void dusqr(){

	if(chku(SQRFIL))
		frmpnt->xat|=AT_SQR;
	else
		frmpnt->xat&=(~AT_SQR);
}

void sacspac(SATCON* strt,unsigned cnt){

	int			strti,cnti;
	int			src,dst;
	unsigned	ind;

	strti=satind(strt);
	cnti=satkad-strti;
	src=satkad-1;
	dst=satkad+cnt-1;
	while(src>=strti){

		satks[dst].strt=satks[src].strt;
		satks[dst--].fin=satks[src--].fin;
	}
	for(ind=clofind+1;ind<formpnt;ind++){

		if(formlst[ind].typ==SAT)
			formlst[ind].sacang.sac+=cnt;
	}
	satkad+=cnt;
}

SATCON* nusac(unsigned pfrm,unsigned cnt){

	unsigned ind,ine;

	ine=0;
	for(ind=0;ind<pfrm;ind++){

		if(formlst[ind].typ==SAT)
			ine+=formlst[ind].stpt;
	}
	formlst[pfrm].sacang.sac=&satks[ine];
	sacspac(formlst[pfrm].sacang.sac,cnt);
	return formlst[pfrm].sacang.sac;
}

void delclps(unsigned ind){

	deleclp(ind);
	delmclp(ind);
}

unsigned findclp(unsigned fpnt){

	int ind;

	for(ind=clofind-1;ind>=0;ind--){

		if(iseclp(ind))
			return formlst[ind].clp-clps+formlst[ind].nclp;
		if(isclp(ind))
			return formlst[ind].angclp.clp-clps+formlst[ind].flencnt.nclp;
	}
	return 0;
}

BOOL chkmax(unsigned arg0,unsigned arg1){

	if(arg0&MAXMSK)
		return 1;
	if(arg1&MAXMSK)
		return 1;
	if((arg1+arg0)&MAXMSK)
		return 1;
	return 0;
}

void clpsub(unsigned fpnt,unsigned cnt){

	unsigned ind;

	for(ind=fpnt+1;ind<formpnt;ind++){

		if(isclpx(ind))
			formlst[ind].angclp.clp-=cnt;
		if(iseclpx(fpnt))
			formlst[ind].clp-=cnt;
	}
}

void delmclp(unsigned fpnt){

	unsigned	src,dst;

	if(clpad){

		if(isclp(fpnt)){

			dst=findclp(fpnt);
			src=dst+formlst[fpnt].flencnt.nclp;
			MoveMemory(&clps[dst],&clps[src],sizeof(FLPNT)*(clpad-src));
			if(iseclp(fpnt))
				formlst[fpnt].clp-=formlst[fpnt].flencnt.nclp;
			clpsub(fpnt,formlst[fpnt].flencnt.nclp);
			if(clpad>formlst[fpnt].flencnt.nclp)
				clpad-=formlst[fpnt].flencnt.nclp;
			else
				clpad=0;
			formlst[fpnt].flencnt.nclp=0;
		}
	}
}

void deleclp(unsigned fpnt){

	unsigned	src,dst;

	if(clpad){

		if(iseclpx(fpnt)){

			dst=findclp(fpnt);
			src=dst+formlst[fpnt].nclp;
			while(src<clpad){

				clps[dst].x=clps[src].x;
				clps[dst++].y=clps[src++].y;
			}
			clpsub(fpnt,formlst[fpnt].nclp);
			if(clpad>formlst[fpnt].nclp)
				clpad-=formlst[fpnt].nclp;
			else
				clpad=0;
			formlst[fpnt].nclp=0;
		}
	}
}

FLPNT* nueclp(unsigned pfrm,unsigned cnt){

	int			find;
	int			src,dst;
	unsigned	ind;

	find=findclp(clofind);
	if(isclp(clofind))
		find+=formlst[clofind].flencnt.nclp;
	src=clpad-1;
	dst=clpad+cnt-1;
	while(src>=find){

		clps[dst].x=clps[src].x;
		clps[dst--].y=clps[src--].y;
	}
	formlst[find].clp=&clps[find];
	for(ind=pfrm;ind<formpnt;ind++){

		if(iseclpx(ind))
			formlst[ind].clp+=cnt;
	}
	for(ind=pfrm+1;ind<formpnt;ind++){

		if(isclp(ind))
			formlst[ind].angclp.clp+=cnt;		
	}
	clpad+=cnt;
	return &clps[find];
}

FLPNT* numclp(){

	int			find;
	int			src,dst;
	unsigned	ind;

	find=findclp(clofind);
	src=clpad-1;
	dst=clpad+clplen-1;
	while(src>=find){

		clps[dst].x=clps[src].x;
		clps[dst--].y=clps[src--].y;
	}
	formlst[clofind].angclp.clp=&clps[find];
	if(iseclpx(clofind))
		formlst[clofind].clp+=clplen;
	for(ind=clofind+1;ind<formpnt;ind++){

		if(isclpx(ind))
			formlst[ind].angclp.clp+=clplen;
		if(iseclpx(ind))
			formlst[ind].clp+=clplen;
	}
	clpad+=clplen;
	return &clps[find];
}

unsigned fltind(FLPNT* pnt){
	return pnt - flts;
}

unsigned sacind(SATCON* pnt){
	return pnt - satks;
}

unsigned clpind(FLPNT* pnt){
	return pnt - clps;
}

void fltspac(FLPNT* strt,unsigned cnt){

	int			strti;
	int			src,dst;
	unsigned	ind;

	strti=fltind(strt);
	src=fltad-1;
	dst=fltad+cnt-1;
	while(src>=strti){

		flts[dst].x=flts[src].x;
		flts[dst--].y=flts[src--].y;
	}
	for(ind=clofind+1;ind<formpnt;ind++)
		formlst[ind].flt+=cnt;
	fltad+=cnt;
}

void delsac(unsigned fpnt){

	unsigned	ind;
	unsigned	src,dst;

	if(satkad){

		if(formlst[clofind].typ==SAT&&formlst[clofind].stpt){

			dst=satind(formlst[clofind].sacang.sac);
			src=dst+formlst[clofind].stpt;
			while(src<satkad){

				satks[dst].strt=satks[src].strt;
				satks[dst++].fin=satks[src++].fin;
			}
			for(ind=clofind+1;ind<formpnt;ind++){

				if(formlst[ind].typ==SAT&&formlst[ind].stpt)
					formlst[ind].sacang.sac-=formlst[clofind].stpt;
			}
			satkad-=formlst[clofind].stpt;
		}
	}
	formlst[clofind].stpt=0;
}

void delflt(unsigned fpnt){

	unsigned	ind;
	unsigned	src,dst;

	if(formlst[clofind].sids){

		dst=fltind(formlst[clofind].flt);
		src=dst+formlst[clofind].sids;
		while(src<fltad){

			flts[dst].x=flts[src].x;
			flts[dst++].y=flts[src++].y;
		}
		for(ind=clofind+1;ind<formpnt;ind++)
			formlst[ind].flt-=formlst[clofind].sids;
		fltad-=formlst[clofind].sids;
		if(fltad&0x8000000)
			fltad=0;
	}
}

BOOL chk2of(){

	if(!chkMap(SELBOX))
		return 0;
	if(chku(FIL2OF))
		return 0;
	return 1;
}

void rotbak(){

	unsigned ind;

	for(ind=0;ind<seqpnt;ind++)
		rotflt(&oseq[ind]);
}

void delfil(unsigned at){

	unsigned ind,ine;

	at&=TYPMSK|FRMSK;
	ine=ind=0;
	rstMap(WASDEL);
	while((stchs[ind].at&(TYPMSK|FRMSK))!=at&&ind<hed.stchs)
		ind++;
	ine=ind;
	if(ind<hed.stchs){

		delpnt=ind;
		setMap(WASDEL);
	}
	while(ind<hed.stchs){
		
		if((stchs[ind].at&(TYPMSK|FRMSK))!=at){

			stchs[ine].at=stchs[ind].at;
			stchs[ine].x=stchs[ind].x;
			stchs[ine++].y=stchs[ind].y;
		}
		ind++;
	}
	hed.stchs=ine;
}

void delmfil(unsigned col){

	unsigned at,sat;
	unsigned ind,ine;

	if(istx(clofind))
		deltx();
	delmclp(clofind);
	col&=0xf;
	at=clofind<<FRMSHFT;
	ine=0;
	for(ind=0;ind<hed.stchs;ind++)
	{
		sat=stchs[ind].at;
		if(!(sat&NOTFRM))
		{
			if(!((sat&FRMSK)==at&&(sat&(TYPFRM|FTHMSK))))
				mvstch(ine++,ind);
		}
		else
			mvstch(ine++,ind);
	}
	hed.stchs=ine;
}

void fsizpar(){

	frmpnt->fmax=ini.maxsiz;
	frmpnt->flencnt.flen=usesiz;
	frmpnt->fmin=minsiz;
}

void chkcont(){

	unsigned ind,ine,len,minlen=10000;

	delmclp(clofind);
	deleclp(clofind);
	fsizpar();
	if(frmpnt->ftyp!=CONTF){

		if(stpt){

			for(ind=0;ind<frmpnt->stpt;ind++){

				len=frmpnt->sacang.sac[ind].fin-frmpnt->sacang.sac[ind].strt;
				if(len<minlen){

					minlen=len;
					ine=ind;
				}
			}
			frmpnt->angclp.sat.strt=frmpnt->sacang.sac[ine].strt;
			frmpnt->angclp.sat.fin=frmpnt->sacang.sac[ine].fin;
			delsac(clofind);
		}
		else{

			frmpnt->angclp.sat.strt=1;
			frmpnt->angclp.sat.fin=frmpnt->sids-2;
		}
	}
	frmpnt->typ=LIN;
	frmpnt->ftyp=CONTF;
	frmpnt->at|=FRECONT;
}

unsigned find1st(){

	unsigned ind=0,at;

	if(chk2of())
		return cloInd;
	else{

		at=clofind<<4;
		while(ind<hed.stchs){

			if((stchs[ind].at&FRMSK)==at){

				if(!(stchs[ind].at&NOTFRM))
					return ind;
			}
			ind++;
		}
		return ind;
	}
}

void ispcdclp(){

	rstMap(WASPCDCLP);
	if(OpenClipboard(hWnd)){

		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem)
			setMap(WASPCDCLP);
	}
	CloseClipboard();
}
		
void frmout(unsigned ind){

	FLRCT*		trct;
	unsigned	ine;
	float		off;

	if(formlst[ind].sids){

		trct=&formlst[ind].rct;
		flt=formlst[ind].flt;
		trct->left=trct->right=flt[0].x;
		trct->bottom=trct->top=flt[0].y;
		for(ine=1;ine<formlst[ind].sids;ine++){

			if(flt[ine].x>trct->right)
				trct->right=flt[ine].x;
			if(flt[ine].x<trct->left)
				trct->left=flt[ine].x;
			if(flt[ine].y<trct->bottom)
				trct->bottom=flt[ine].y;
			if(flt[ine].y>trct->top)
				trct->top=flt[ine].y;
		}
		if(trct->top-trct->bottom<MINRCT){

			off=(MINRCT-(trct->top-trct->bottom))/2;
			trct->top+=off;
			trct->bottom-=off;
		}
		if(trct->right-trct->left<MINRCT){

			off=(MINRCT-(trct->right-trct->left))/2;
			trct->left-=off;
			trct->right+=off;
		}
	}
}

void sfCor2px(FLPNT stpnt,POINT* pxpnt){

	pxpnt->x=(stpnt.x-zRct.left)*zrat.x+0.5;
	pxpnt->y=scRct.bottom-(stpnt.y-zRct.bottom)*zrat.y+0.5;
}

void stCor2px(SHRTPNT stpnt,POINT* pxpnt){

	pxpnt->x=(stpnt.x-zRct.left)*zrat.x+0.5;
	pxpnt->y=scRct.bottom-(stpnt.y-zRct.bottom)*zrat.y+0.5;
}

void px2stchf(POINT pxpnt,FLPNT* stpnt){

	double	tdub;

	tdub=(double)(pxpnt.x-scRct.left)/scRct.right;
	stpnt->x=tdub*(zRct.right-zRct.left)+zRct.left;
	tdub=(double)(scRct.bottom-pxpnt.y)/scRct.bottom;
	stpnt->y=tdub*(zRct.top-zRct.bottom)+zRct.bottom;
}

void frmlin(FLPNT* scr,unsigned sidz){

	unsigned ind;

	if(sids){

		for(ind=0;ind<sidz;ind++){

			flin[ind].x=(scr[ind].x-zRct.left)*zrat.x;
			flin[ind].y=scRct.bottom-(scr[ind].y-zRct.bottom)*zrat.y;
		}
		flin[ind].x=(scr[0].x-zRct.left)*zrat.x;
		flin[ind].y=scRct.bottom-(scr[0].y-zRct.bottom)*zrat.y;
	}
}

void dufrm(){

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	Polyline(rsdc,flin,nuflen);
	SetROP2(rsdc,R2_COPYPEN);
}

void unfrm(){

	if(rstMap(SHOFRM))
		dufrm();
}

void mdufrm(){

	SetROP2(rsdc, R2_XORPEN);
	SelectObject(rsdc,fPen);
	if(formlst[clofind].typ==LIN)
		Polyline(rsdc,flin,nuflen-1);
	else
		Polyline(rsdc,flin,nuflen);
	SetROP2(sdc,R2_COPYPEN);
}

void munfrm(){

	if(rstMap(SHOFRM))
		mdufrm();
}

void rats(){

	if(chkMap(ZUMED)){

		hfrat=(double)(zRct.right-zRct.left)/scRct.right;
		vfrat=(double)(zRct.top-zRct.bottom)/scRct.bottom;
	}
	else{

		hfrat=(double)zum0.x/scRct.right;
		vfrat=(double)zum0.y/scRct.bottom;
	}
}

void setfrm(){

	unsigned	ind;
	FLPNT		tpnt;
	FLPNT		dif;

	rats();
	clofind=formpnt;
	fvars(clofind);
	px2stchf(flin[0],&tpnt);
	dif.x=tpnt.x-flt[0].x;
	dif.y=tpnt.y-flt[0].y;
	frmpnt->rct.left=frmpnt->rct.bottom=(float)1e30;
	frmpnt->rct.right=frmpnt->rct.top=0;
	for(ind=0;ind<nuflen-1;ind++){

		flt[ind].x+=dif.x;
		flt[ind].y+=dif.y;
		if(flt[ind].x<frmpnt->rct.left)
			frmpnt->rct.left=flt[ind].x;
		if(flt[ind].x>frmpnt->rct.right)
			frmpnt->rct.right=flt[ind].x;
		if(flt[ind].y>frmpnt->rct.top)
			frmpnt->rct.top=flt[ind].y;
		if(flt[ind].y<frmpnt->rct.bottom)
			frmpnt->rct.bottom=flt[ind].y;
	}
	formpnt++;
	rstMap(FORMIN);
	setMap(INIT);
	setMap(RESTCH);
}

void form(){

	shoMsg(stab[STR_FMEN]);
	setMap(FORMIN);
	rstMap(INSRT);
	duzrat();
}

void frmsqr(unsigned ind){

	double	lang;
	double	rat;
	float	len;
	FLPNT	off;
	FLPNT	fpnt;
	FLPNT	dpnt;
	DUBPNT	dif;
	POINT	sqlin[4];

	stch2pxr(flt[ind]);
	sqlin[1].x=pPnt.x;
	sqlin[1].y=pPnt.y;
	rat=(double)ini.frmpix/scRct.right;
	len=(zRct.right-zRct.left)*rat*2;
	dif.x=flt[ind-1].x-flt[ind].x;
	dif.y=flt[ind-1].y-flt[ind].y;
	lang=atan2(dif.y,dif.x);
	off.x=len*cos(lang);
	off.y=len*sin(lang);
	fpnt.x=flt[ind].x+off.x;
	fpnt.y=flt[ind].y+off.y;
	lang=atan2(-dif.x,dif.y);
	len/=2;
	off.x=len*cos(lang);
	off.y=len*sin(lang);
	dpnt.x=fpnt.x+off.x;
	dpnt.y=fpnt.y+off.y;
	stch2pxr(dpnt);
	sqlin[0].x=sqlin[3].x=pPnt.x;
	sqlin[0].y=sqlin[3].y=pPnt.y;
	dpnt.x=fpnt.x-off.x;
	dpnt.y=fpnt.y-off.y;
	stch2pxr(dpnt);
	sqlin[2].x=pPnt.x;
	sqlin[2].y=pPnt.y;
	Polyline(sdc,sqlin,4);
}

void selsqr(POINT cpnt,HDC dc){

	POINT	sqlin[5];

	sqlin[0].x=sqlin[3].x=sqlin[4].x=cpnt.x-ini.frmpix;
	sqlin[0].y=sqlin[1].y=cpnt.y-ini.frmpix;
	sqlin[1].x=sqlin[2].x=cpnt.x+ini.frmpix;
	sqlin[2].y=sqlin[3].y=cpnt.y+ini.frmpix;
	sqlin[4].y=cpnt.y-ini.frmpix;
	Polyline(dc,sqlin,5);
}

void frmsqr0(POINT cpnt){

	POINT		sqlin[5];
	unsigned	pix;

	pix=ini.frmbpix;
	if(pix)
	{
		sqlin[0].x=sqlin[3].x=sqlin[4].x=cpnt.x-pix;
		sqlin[0].y=sqlin[1].y=cpnt.y-pix;
		sqlin[1].x=sqlin[2].x=cpnt.x+pix+1;
		sqlin[2].y=sqlin[3].y=cpnt.y+pix+1;
		sqlin[4].y=cpnt.y-1;
		Polyline(sdc,sqlin,5);
	}
}

void frmx(POINT cpnt,HDC dc){

	POINT	xlin[2];

	SelectObject(dc,fsPen);
	xlin[0].x=xlin[1].x=cpnt.x;
	xlin[0].y=cpnt.y+8;
	xlin[1].y=cpnt.y-8;
	Polyline(dc,xlin,2);
	xlin[0].y=xlin[1].y=cpnt.y;
	xlin[0].x=cpnt.x-8;
	xlin[1].x=cpnt.x+8;
	Polyline(dc,xlin,2);
	SelectObject(dc,fPen);
}

void ratsr(){

	if(chkMap(ZUMED)){

		hfrat=(double)scRct.right/(zRct.right-zRct.left);
		vfrat=(double)scRct.bottom/(zRct.top-zRct.bottom);
	}
	else{
	
		hfrat=(double)scRct.right/zum0.x;
		vfrat=(double)scRct.bottom/zum0.y;
	}
}

float midl(float hi,float lo){

	return (hi-lo)/2+lo;
}

void fvars(unsigned ind){

	frmpnt=&formlst[ind];
	flt=formlst[ind].flt;
	sids=formlst[ind].sids;
	sac=formlst[ind].sacang.sac;
	stpt=formlst[ind].stpt;
	wpar=formlst[ind].wpar;
	clp=formlst[ind].clp;
	nclp=formlst[ind].nclp;
}

void ritfrct(unsigned ind,HDC dc){

	unsigned	ine;
	POINT		sqrlin[10];
	FLRCT*		trct;
	FLPNT		rlin[10];

	ratsr();
	SelectObject(rsdc,fPen);
	SetROP2(rsdc,R2_XORPEN);
	getfinfo(ind);
	trct=&formlst[ind].rct;
	SelectObject(dc,fsPen);
	rlin[0].x=rlin[6].x=rlin[7].x=rlin[8].x=trct->left;
	rlin[1].x=rlin[5].x=midl(trct->right,trct->left);
	rlin[0].y=rlin[1].y=rlin[2].y=rlin[8].y=trct->top;
	rlin[3].y=rlin[7].y=midl(trct->top,trct->bottom);
	rlin[4].y=rlin[5].y=rlin[6].y=trct->bottom;
	rlin[2].x=rlin[3].x=rlin[4].x=trct->right;
	for(ind=0;ind<8;ind++)
		sfCor2px(rlin[ind],&sqrlin[ind]);
	sfCor2px(rlin[0],&sqrlin[ind]);
	Polyline(dc,sqrlin,9);
	for(ine=0;ine<8;ine++)
		selsqr(sqrlin[ine],dc);
	SetROP2(rsdc,R2_COPYPEN);
	if(rstMap(GRPSEL)){

		rstMap(SELSHO);
		slpnt=0;
		setMap(RESTCH);
	}
}

void delfrms(){

	unsigned ind;

	savdo();
	formpnt=fltad=satkad=clpad=0;
	for(ind=0;ind<hed.stchs;ind++)
	{
		stchs[ind].at&=NFRM_NTYP;
		stchs[ind].at|=NOTFRM;
	}
}

void fselrct(unsigned fpnt){

	FRMHED*		tpnt=&formlst[fpnt];
	FLPNT		tlin[5];
	POINT		sqrlin[5];
	unsigned	ind;

	tlin[0].x=tlin[3].x=tlin[4].x=tpnt->rct.left;
	tlin[1].x=tlin[2].x=tpnt->rct.right;
	tlin[0].y=tlin[1].y=tlin[4].y=tpnt->rct.top;
	tlin[2].y=tlin[3].y=tpnt->rct.bottom;
	for(ind=0;ind<5;ind++){

		sqrlin[ind].x=(tlin[ind].x-zRct.left)*hfrat;
		sqrlin[ind].y=(zRct.top-tlin[ind].y)*vfrat;
		if(sqrlin[ind].x<bigrct.left)
			bigrct.left=sqrlin[ind].x;
		if(sqrlin[ind].x>bigrct.right)
			bigrct.right=sqrlin[ind].x;
		if(sqrlin[ind].y<bigrct.top)
			bigrct.top=sqrlin[ind].y;
		if(sqrlin[ind].y>bigrct.bottom)
			bigrct.bottom=sqrlin[ind].y;
	}
	sqrlin[5].x=(tlin[0].x-zRct.left)*hfrat;
	sqrlin[5].y=(zRct.top-tlin[0].y)*vfrat;
	if(sqrlin[5].x<bigrct.left)
		bigrct.left=sqrlin[5].x;
	if(sqrlin[5].x>bigrct.right)
		bigrct.right=sqrlin[5].x;
	if(sqrlin[5].y<bigrct.top)
		bigrct.top=sqrlin[5].y;
	if(sqrlin[5].y>bigrct.bottom)
		bigrct.bottom=sqrlin[5].y;
	Polyline(sdc,sqrlin,5);
}

void rct2sel(RECT rct,POINT* lin){

	lin[0].x=lin[6].x=lin[7].x=lin[8].x=rct.left;
	lin[1].x=lin[5].x=((rct.right-rct.left)>>1)+rct.left;
	lin[2].x=lin[3].x=lin[4].x=rct.right;
	lin[0].y=lin[1].y=lin[2].y=lin[8].y=rct.top;
	lin[3].y=lin[7].y=((rct.bottom-rct.top)>>1)+rct.top;
	lin[4].y=lin[5].y=lin[6].y=rct.bottom;
}

void dubig(){

	unsigned ind;

	rct2sel(bigrct,biglin);
	SelectObject(sdc,alpen);
	Polyline(sdc,biglin,9);
	for(ind=0;ind<8;ind++)
		selsqr(biglin[ind],sdc);
}

void frmpoly(POINT* lin,unsigned cnt){

	unsigned ind;

	if(cnt){

		for(ind=0;ind<cnt-1;ind++)
			Polyline(sdc,&lin[ind],2);
	}
}

void dupsel(HDC dc){

	unsigned ind;

	SelectObject(dc,fPen);
	SetROP2(dc,R2_XORPEN); 
	Polyline(dc,pselin,9);
	ind=pselrng.strt;
	for(ind=0;ind<8;ind++)
		selsqr(pselin[ind],dc);
	frmx(pselfin,dc);
}

void unpsel(){

	if(rstMap(SHOPSEL))
		dupsel(rsdc);
}

void drwfrm(){

	unsigned	ind,ine,inf,layr;
	POINT		lin[2];
	DUBPNT		tpnt;

	rstMap(SHOMOV);
	rstMap(SHOPSEL);
	lin[0].x=lin[0].y=lin[1].x=lin[1].y=0;
	Polyline(sdc,lin,2);
	SetROP2(sdc,R2_XORPEN);
	ratsr();
	duzrat();
	for(ind=0;ind<formpnt;ind++){

		fvars(ind);
		frmlin(frmpnt->flt,sids);
		inf=0;
		layr=((frmpnt->at&FRMLMSK)>>1);
		if(!actl||!layr||layr==actl){

			if(frmpnt->typ==SAT){
				
				if(frmpnt->at&FRMEND){

					SelectObject(sdc,fPen3);
					Polyline(sdc,flin,2);
					inf=1;
				}
				if(frmpnt->wpar){

					SelectObject(sdc,fPen);
					frmpoly(&flin[1],frmpnt->wpar);
					SelectObject(sdc,fPen3);
					Polyline(sdc,&flin[frmpnt->wpar],2);
					SelectObject(sdc,ypen[layr]);
					inf=frmpnt->wpar+1;
				}
				for(ine=0;ine<formlst[ind].stpt;ine++){

					sfCor2px(flt[sac[ine].strt],&lin[0]);
					sfCor2px(flt[sac[ine].fin],&lin[1]);
					SelectObject(sdc,fPen);
					Polyline(sdc,lin,2);
				}
			}
			SelectObject(sdc,ypen[layr]);
			if(frmpnt->typ==LIN){

				frmpoly(flin,sids);
				if(frmpnt->ftyp==CONTF){

					tpnt.x=flt[frmpnt->angclp.sat.strt].x;
					tpnt.y=flt[frmpnt->angclp.sat.strt].y;
					sCor2px(tpnt,&lin[0]);
					tpnt.x=flt[frmpnt->angclp.sat.fin].x;
					tpnt.y=flt[frmpnt->angclp.sat.fin].y;
					sCor2px(tpnt,&lin[1]);
					Polyline(sdc,lin,2);
				}
			}
			else
				frmpoly(&flin[inf],sids+1-inf);
			if(clofind==ind&&chkMap(FRMPSEL)){

				for(ine=1;ine<sids;ine++){

					if(ine==clofine)
						frmx(flin[ine],sdc);
					else
						frmsqr(ine);
				}
				if(clofine)
					frmsqr0(flin[0]);
				else
					frmx(flin[0],sdc);
				ritnum(STR_NUMPNT,clofine);
			}
			else{

				for(ine=1;ine<sids;ine++)
					frmsqr(ine);
				SelectObject(sdc,fsPen);
				frmsqr0(flin[0]);
			}
			if(chkMap(FPSEL)&&clofind==ind){

				sRct2px(pselrct,&pxselrct);
				rct2sel(pxselrct,pselin);
				setMap(SHOPSEL);
				dupsel(sdc);
			}
		}
	}
	if(fselpnt){

		SelectObject(sdc,fmpen);
		ratsr();
		bigrct.top=bigrct.left=0x7fffffff;
		bigrct.bottom=bigrct.right=0;
		for(ind=0;ind<fselpnt;ind++)
			fselrct(selist[ind]);
		bigsiz.x=bigrct.right-bigrct.left;
		bigsiz.y=bigrct.bottom-bigrct.top;
		dubig();
	}
	else{

		if(chkMap(FORMSEL))
			ritfrct(clofind,sdc);
		if(chkMap(FRMPMOV)){

			ritmov();
			mvlin[1].x=msg.pt.x-stOrg.x;
			mvlin[1].y=msg.pt.y-stOrg.y;
			setMap(SHOMOV);
			ritmov();
		}
	}
	SetROP2(sdc,R2_COPYPEN);
}

void setpoli(){

	frmclr(&formlst[formpnt]);
	formlst[formpnt].typ=POLI;
	frmtyp=POLI;
	formlst[formpnt].at=actl<<1;
	formlst[formpnt].wind=ini.wind;
	setMap(SATIN);
	setMap(INIT);
}

void setlin(){

	frmclr(&formlst[formpnt]);
	formlst[formpnt].typ=LIN;
	frmtyp=LIN;
	formlst[formpnt].at=actl<<1;
	setMap(SATIN);
	setMap(INIT);
}

void setrpoli(){

	unmsg();
	pntmsg(IDS_REGP);
	setMap(NUMIN);
	setMap(ENTRPOL);
	numWnd();
}

void setstar(){

	unmsg();
	pntmsg(IDS_STAR);
	setMap(NUMIN);
	setMap(ENTRSTAR);
	numWnd();
}

void setspir(){

	unmsg();
	pntmsg(IDS_SPIR);
	setMap(NUMIN);
	setMap(ENTRSPIR);
	numWnd();
}

void sethart(){

	unmsg();
	pntmsg(IDS_HEART);
	setMap(NUMIN);
	setMap(ENTRHART);
	numWnd();
}

void setlens(){

	unmsg();
	pntmsg(IDS_LENS);
	setMap(NUMIN);
	setMap(ENTRLENS);
	numWnd();
}

void seteg(){

	unmsg();
	pntmsg(IDS_EGG);
	setMap(NUMIN);
	setMap(ENTREG);
	numWnd();
}

void setzig(){

	unmsg();
	pntmsg(IDS_ZIG);
	setMap(NUMIN);
	setMap(ENTRZIG);
	numWnd();
}

BOOL CALLBACK tearprc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam){

	TCHAR		buf[HBUFSIZ];

	switch(umsg){

	case WM_INITDIALOG:

		SendMessage(hwndlg,WM_SETFOCUS,0,0);
reinit:;
		sprintf(buf,"%d",ini.nsids);
		SetWindowText(GetDlgItem(hwndlg,IDC_TEARSIDS),buf);
		sprintf(buf,"%.3f",ini.tearat);
		SetWindowText(GetDlgItem(hwndlg,IDC_TEARAT),buf);
		sprintf(buf,"%.3f",ini.twststp/PFGRAN);
		SetWindowText(GetDlgItem(hwndlg,IDC_TWSTSTP),buf);
		sprintf(buf,"%.3f",ini.twstrat);
		SetWindowText(GetDlgItem(hwndlg,IDC_TWSTRAT),buf);
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam)){

		case IDCANCEL:

			EndDialog(hwndlg,0); 
			return TRUE;

		case IDOK:

			GetWindowText(GetDlgItem(hwndlg,IDC_TEARSIDS),buf,HBUFSIZ);
			ini.nsids=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_TEARAT),buf,HBUFSIZ);
			ini.tearat=atof(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_TWSTSTP),buf,HBUFSIZ);
			ini.twststp=atof(buf)*PFGRAN;
			GetWindowText(GetDlgItem(hwndlg,IDC_TWSTRAT),buf,HBUFSIZ);
			ini.twstrat=atof(buf);
			EndDialog(hwndlg,1);
			break;

		case IDC_DEFTEAR:

			ini.nsids=20;
			ini.tearat=(float)1.1;
			ini.twststp=(float)0.0;
			ini.twstrat=(float)1.6;
			goto reinit;

		case IDC_DEFPAIS:

			ini.nsids=24;
			ini.tearat=(float)1.15;
			ini.twststp=(float)0.3*PFGRAN;
			ini.twstrat=(float)1.8;
			goto reinit;
		}
	}
	return 0;
}

void setear(){

	unsigned	ind,cnt,rind,lind;
	double		mid;
	double		vpos;
	double		len;
	double		stp;
	double		hrat;
	double		vrat;
	float		xstp;
	FLPNT		siz;

	unmsg();
	ind=DialogBox(hInst,MAKEINTRESOURCE(IDD_TEAR),hWnd,(DLGPROC)tearprc);
	if(ind>0){

		xstp=ini.twststp;
		durpoli(ini.nsids);
		fvars(formpnt);
		cnt=sids/4;
		mid=(flt[1].x-flt[0].x)/2+flt[0].x;
		len=flt[cnt].y-flt[0].y;
		stp=flt[cnt+1].y-flt[cnt].y;
		vpos=flt[cnt+1].y;
		lind=sids-cnt;
		rind=cnt+1;
		for(ind=0;ind<(unsigned)cnt;ind++){

			flt[rind].y=flt[lind].y=vpos;
			flt[rind].x+=xstp;
			flt[lind].x+=xstp;
			xstp*=ini.twstrat;
			vpos-=stp;
			stp*=ini.tearat;
			rind--;
			lind++;
		}
		flt[0].y=flt[1].y=vpos;
		flt[0].x+=xstp;
		flt[1].x+=xstp;
		vpos-=stp/2;
		flt[sids].x=flt[0].x;
		flt[sids].y=flt[0].y;
		if(xstp)
			flt[0].x=flt[1].x+xstp/4;
		else
			flt[0].x=mid;
		flt[0].y=vpos;
		frmpnt->sids++;
		nuflen++;
		fltad++;
		setMap(FORMSEL);
		fvars(formpnt);
		frmout(formpnt);
		flipv();
		rstMap(FORMSEL);
		siz.x=frmpnt->rct.right-frmpnt->rct.left;
		siz.y=frmpnt->rct.top-frmpnt->rct.bottom;
		hrat=zum0.x/4/siz.x;
		if(hrat>1)
			hrat=1;
		vrat=zum0.y/4/siz.y;
		if(vrat<hrat)
			hrat=vrat;
		if(hrat<1){

			for(ind=0;ind<sids;ind++){

				flt[ind].x=(flt[ind].x-flt[0].x)*hrat+flt[0].x;
				flt[ind].y=(flt[ind].y-flt[0].y)*hrat+flt[0].y;
			}
		}
		frmout(formpnt);
		for(ind=0;ind<sids;ind++){

			flt[ind].x-=frmpnt->rct.left;
			flt[ind].y-=frmpnt->rct.bottom;
		}
	}
}

void duform(unsigned ind){

	frmclr(&formlst[formpnt]);
	switch(ind+1){

	case LIN:

		setlin();
		break;

	case POLI:

		setpoli();
		break;

	case RPOLI:

		setrpoli();
		break;

	case STAR:

		setstar();
		break;

	case SPIR:

		setspir();
		break;

	case HART-1:

		sethart();
		break;

	case LENS-1:

		setlens();
		break;

	case EGG-1:

		seteg();
		break;

	case TEAR-1:

		setear();
		break;

	case ZIG-1:

		setzig();
		break;

	case WAV-1:

		wavfrm();
		break;

	case DASY-1:

		dasyfrm();
		break;
	}
}

unsigned closfrm(){

	unsigned	ind,ine,tind,tine,playcod,frmcod;
	FLPNT*		pdat;
	FLPNT		tpnt;
	POINT		stchpx;
	double		len,minlen=1e99;

	if(formpnt){

		stchpx.x=msg.pt.x-stOrg.x;
		stchpx.y=msg.pt.y-stOrg.y;
		rats();
		tind=tine=0;
		px2stchf(stchpx,&tpnt);
		playcod=actl<<1;
		for(ind=0;ind<formpnt;ind++){

			if(chkMap(FRMSAM)&&ind==clofind)
				continue;

			frmcod=formlst[ind].at&FRMLMSK;
			if(!actl||!frmcod||frmcod==playcod){

				getfinfo(ind);
				pdat=formlst[ind].flt;
				for(ine=0;ine<finfo.sids;ine++){

					len=hypot(tpnt.x-pdat[ine].x,tpnt.y-pdat[ine].y);
					if(len<minlen&&len>=0){

						minlen=len;
						tind=ind;
						tine=ine;
					}
				}
			}
		}
		stch2pxr(formlst[tind].flt[tine]);
		minlen=hypot(pPnt.x-stchpx.x,pPnt.y-stchpx.y);
		if(minlen<CLOSENUF){

			clofind=tind;
			clofine=tine;
			fvars(clofind);
			setMap(RELAYR);
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

void frmovlin(){

	unsigned ind,ine;

	fvars(clofind);
	ratsr();
	if(frmpnt->typ==LIN)
		nuflen=frmpnt->sids;
	else
		nuflen=frmpnt->sids+1;
	frmlin(frmpnt->flt,frmpnt->sids);
	ine=prv(clofine);
	for(ind=0;ind<3;ind++)
	{
		mvlin[ind].x=flin[ine].x;
		mvlin[ind].y=flin[ine].y;
		ine++;
	}
	ritmov();
}

/*
void makspac(unsigned strt,unsigned cnt){

	unsigned src,dst,tcnt;

	if(!chkmax(hed.stchs,cnt)){

		src=hed.stchs-1;
		dst=src+cnt;
		tcnt=hed.stchs-strt;
		while(tcnt&&dst<MAXFLT){

			stchs[dst].at=stchs[src].at;
			stchs[dst].x=stchs[src].x;
			stchs[dst--].y=stchs[src--].y;
			tcnt--;
		}
		hed.stchs+=cnt;
	}
}*/

void makspac(unsigned strt,unsigned cnt){

	if(!chkmax(hed.stchs,cnt))
	{
		MoveMemory(&stchs[strt+cnt],&stchs[strt],sizeof(SHRTPNT)*(hed.stchs-strt));
		hed.stchs+=cnt;
	}
}

void rseq(unsigned strt,unsigned fin,unsigned ostrt,unsigned at){

	while(strt<fin){

		stchs[strt].at=at;
		stchs[strt].x=iseq[ostrt].x;
		stchs[strt++].y=iseq[ostrt++].y;
	}
	ostrt--;
	lastpnt.x=iseq[ostrt].x;
	lastpnt.y=iseq[ostrt].y;
}

BOOL ritlin(FLPNT strt,FLPNT fin)
{
	DUBPNT		dif,stp,pnt;
	double		len;
	unsigned	ine,cnt;
	
	dif.x=fin.x-strt.x;
	dif.y=fin.y-strt.y;
	len=hypot(dif.x,dif.y);
	iseq[isind].x=strt.x;
	iseq[isind++].y=strt.y;
	if(len>maxs){
		
		cnt=ceil(len/uslen);
		if(!cnt)
			cnt=1;
		while(len/cnt>maxs)
			cnt++;
		if(!chkmax(isind,cnt)){
	
			stp.x=dif.x/cnt;
			stp.y=dif.y/cnt;
			pnt.x=strt.x+stp.x;
			pnt.y=strt.y+stp.y;
			for(ine=0;ine<cnt-1;ine++){

				if(isind&MAXMSK){

					isind=MAXSEQ-2;
					return 0;
				}
				iseq[isind].x=pnt.x;
				iseq[isind++].y=pnt.y;
				pnt.x+=stp.x;
				pnt.y+=stp.y;
			}
		}
		else{

			seqpnt=MAXSEQ-2;
			return 0;
		}
	}
	return 1;
}

BOOL minrng(unsigned strt,unsigned fin)
{
	if(abs(fin-strt)<sids>>1||frmpnt->typ==LIN)
		return 0;
	else
		return 1;
}

unsigned closflt(float px,float py)
{
	double		len,minlen;
	unsigned	ind,ine;

	minlen=1e99;
	for(ind=0;ind<sids;ind++)
	{
		len=hypot(px-flt[ind].x,py-flt[ind].y);
		if(len<minlen)
		{
			ine=ind;
			minlen=len;
		}
	}
	return ine;
}

void chkseq(BOOL brd){

#if BUGBAK

	unsigned ind;

	for(ind=0;ind<seqpnt;ind++)
	{
		iseq[ind].x=oseq[ind].x;
		iseq[ind].y=oseq[ind].y;
	}
	isind=seqpnt;
#else

	double		len;
	unsigned	ind,ine,bakind;
	float		mins;

	bakind=isind;
	if(brd){
	
		if(!frmpnt->emax)
			frmpnt->emax=ini.maxsiz;
		maxs=frmpnt->emax;
		if(frmpnt->etyp==EGCHNL||frmpnt->etyp==EGCHNH)
			uslen=9*PFGRAN;
		else
			uslen=frmpnt->elen;
		mins=frmpnt->emin;
	}
	else{

		if(!frmpnt->fmax)
			frmpnt->fmax=ini.maxsiz;
		maxs=frmpnt->fmax;
		if(isclp(clofind))
			uslen=maxs;
		else
			uslen=frmpnt->flencnt.flen;
		mins=frmpnt->fmin;
	}
	if(uslen>maxs)
		uslen=maxs;
	ine=0;
	for(ind=0;ind<seqpnt-1;ind++)
	{
		if(!ritlin(oseq[ind],oseq[ind+1]))
			goto seqskp;
	}
	iseq[isind].x=oseq[ind].x;
	iseq[isind++].y=oseq[ind].y;
seqskp:;
	if(!mins)
		return;
	ine=bakind+1;
	for(ind=bakind+1;ind<isind;ind++){

		len=hypot(iseq[ind].x-iseq[ind-1].x,iseq[ind].y-iseq[ind-1].y);
		if(len>mins){

			iseq[ine].x=iseq[ind].x;
			iseq[ine].y=iseq[ind].y;
			ine++;
		}
	}
	isind=ine;
#endif
}

void ritbrd(){

	if(seqpnt)
	{
		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_BRD;
		isinds[isind2].cod=TYPBRD;
		isinds[isind2].col=frmpnt->bcol&COLMSK;
		chkseq(1);
		isind2++;
	}
}

void ritapbrd(){

	if(seqpnt)
	{
		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_AP;
		isinds[isind2].cod=TYPMSK;
		isinds[isind2].col=frmpnt->bcol>>4;
		chkseq(1);
		isind2++;
	}
}

void ritfil(){

	if(seqpnt)
	{
		isinds[isind2].ind=isind;
		isinds[isind2].seq=I_FIL;
		isinds[isind2].cod=TYPFRM;
		isinds[isind2].col=frmpnt->fcol;
		chkseq(0);
		isind2++;
	}
}

void okcan(){

	GetClientRect(hMsg,&msgRct);
		
	hok=CreateWindow(
		"STATIC",
		stab[STR_OKENT],
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		5,
		msgRct.bottom+15,
		buttonWid<<2,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);

	hcan=CreateWindow(
		"STATIC",
		stab[STR_CANCEL],
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid*5,
		msgRct.bottom+15,
		buttonWid3,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);
}

void savdisc(){

	TCHAR	buf[HBUFSIZ];

	sdmsg();
	rstMap(BIGBOX);
	
	GetClientRect(hMsg,&msgRct);
		
	LoadString(hInst,IDS_SAV,buf,HBUFSIZ);
	hok=CreateWindow(
		"STATIC",
		buf,
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		5,
		msgRct.bottom+15,
		buttonWid3,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);

	LoadString(hInst,IDS_DISC,buf,HBUFSIZ);
	hdsc=CreateWindow(
		"STATIC",
		buf,
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3+15,
		msgRct.bottom+15,
		buttonWid3,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);

	hcan=CreateWindow(
		"STATIC",
		stab[STR_CANCEL],
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		2*buttonWid3+25,
		msgRct.bottom+15,
		buttonWid3,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);
}

BOOL lastch(){

	if(isind)
	{
		lastpnt.x=iseq[isind-1].x;
		lastpnt.y=iseq[isind-1].y;
		return 1;
	}
	else
		return 0;

/*	unsigned	ind,at;

	ind=0xffffffff;
	if(frmpnt->typ!=LIN&&frmpnt->ftyp){

		at=TYPATMSK|(clofind<<FRMSHFT);
		for(ind=hed.stchs-1;ind<hed.stchs;ind--){

			if((stchs[ind].at&LASTMSK)==at){

				lastpnt.x=stchs[ind].x;
				lastpnt.y=stchs[ind].y;
				return 1;
			}
		}
	}
	lastpnt.x=flt[0].x;
	lastpnt.y=flt[0].y;
	return 0;*/
}

unsigned getlast(){

	unsigned		ind;
	unsigned		tclos=0;
	double			len,dx,dy,min=1e99;

	if(frmpnt->ftyp){

		lastch();
		for(ind=0;ind<sids;ind++){

			dx=lastpnt.x-flt[ind].x;
			dy=lastpnt.y-flt[ind].y;
			len=hypot(dx,dy);
			if(len<min){

				min=len;
				tclos=ind;
			}
		}
		return tclos;
	}
	else
		return 0;
}

void flt2dub(FLPNT ipnt,DUBPNT* opnt){

	opnt->x=ipnt.x;
	opnt->y=ipnt.y;
}

void linrutf(unsigned strt){

	double		tspac;
	unsigned	ind;
	DUBPNT		tpnt;

	tspac=stspace;
	sPnt.x=flt[strt].x;
	sPnt.y=flt[strt].y;
	for(ind=strt-1;ind<sids;ind--){

		flt2dub(flt[ind],&tpnt);
		filinsb(tpnt);
	}
	stspace=tspac;
}

void linrutb(unsigned strt){

	double		tspac;
	unsigned	ind;
	DUBPNT		tpnt;

	tspac=stspace;
	sPnt.x=flt[strt].x;
	sPnt.y=flt[strt].y;
	for(ind=strt+1;ind<sids;ind++){

		flt2dub(flt[ind],&tpnt);
		filinsb(tpnt);
	}
	flt2dub(flt[0],&tpnt);
	filinsb(tpnt);
	stspace=tspac;
}

void oclp(FLPNT* clp,unsigned nclp){

	unsigned	ind;

	if(!chkMap(NOCLP))
	{
		for(ind=0;ind<nclp;ind++){

			clpnu[ind].x=clp[ind].x;
			clpnu[ind].y=clp[ind].y;
		}
		clprct.left=clprct.right=clpnu[0].x;
		clprct.bottom=clprct.top=clpnu[0].y;
		for(ind=1;ind<(unsigned)nclp;ind++){

			if(clpnu[ind].x<clprct.left)
				clprct.left=clpnu[ind].x;
			if(clpnu[ind].x>clprct.right)
				clprct.right=clpnu[ind].x;
			if(clpnu[ind].y<clprct.bottom)
				clprct.bottom=clpnu[ind].y;
			if(clpnu[ind].y>clprct.top)
				clprct.top=clpnu[ind].y;
		}
		clpsiz.cx=clprct.right-clprct.left;
		clpsiz.cy=clprct.top-clprct.bottom;
		clplen=nclp;
	}
}

float getblen(){
	union {
		float		len;
		unsigned	tlen;
	} x;

	x.tlen=(formlst[clofind].nclp<<16)|formlst[clofind].res;
	return x.len;
}

void savblen(float len){
	union {
		unsigned int i;
		float f;
	} x;

	x.f = len;

	formlst[clofind].nclp = x.i >> 16;
	formlst[clofind].res = x.i & 0xFFFF;
}

float getplen(){

	unsigned num=frmpnt->res;

	return((float)(num>>8)+(num&0xff)/256);
}

void savplen(float len){

	unsigned	num,fr;
	double		fnum,frf;

	if(len>255)
		len=255;
	frf=modf(len,&fnum);
	fr=(unsigned)floor(frf*256);
	num=fnum;
	formlst[clofind].res=(unsigned short)(num<<8)|fr;
}

void chkbrd(){

	float	tlen;

	fvars(clofind);
	if(frmpnt->etyp){

		lastflt=getlast();
		switch(frmpnt->etyp&NEGUND){

		case EGLIN:

			brdfil(frmpnt->elen);
			break;

		case EGBLD:

			bold(frmpnt->elen);
			break;

		case EGCLP:

			oclp(frmpnt->clp,frmpnt->nclp);
			clpbrd(getlast());
			break;

		case EGCLPX:

			oclp(frmpnt->clp,frmpnt->nclp);
			duxclp();
			break;

		case EGSAT:

			plen=frmpnt->esiz;
			sbrd();
			break;

		case EGPRP:

			plen=frmpnt->esiz;
			pbrd(frmpnt->espac);
			break;

		case EGAP:

			seqpnt=0;
			apbrd();
			ritapbrd();
			plen=frmpnt->esiz;
			sbrd();
			break;

		case EGHOL:

			plen=frmpnt->esiz*2;
			tlen=bfclen;
			bfclen=getblen();
			satout(20);
			bhbrd(frmpnt->espac);
			bfclen=tlen;
			break;

		case EGPIC:

			oclp(frmpnt->clp,frmpnt->nclp);
			clpic(0);
			break;

		case EGDUB:

			dubfn();
			break;

		case EGCHNL:

			setMap(LINCHN);
			chnfn();
			break;

		case EGCHNH:

			rstMap(LINCHN);
			chnfn();
			break;
		}
		ritbrd();
	}
}

void boldlin(unsigned strt,unsigned fin,double siz){

	DUBPNT		dif,stp,pnt0,pnt1;
	double		len;
	unsigned	cnt;

	dif.x=flt[fin].x-flt[strt].x;
	dif.y=flt[fin].y-flt[strt].y;
	len=hypot(dif.x,dif.y);
	cnt=len/siz;
	if(cnt){

		stp.x=dif.x/cnt;
		stp.y=dif.y/cnt;
		pnt0.x=flt[strt].x;
		pnt0.y=flt[strt].y;
		pnt1.x=pnt0.x+stp.x;
		pnt1.y=pnt0.y+stp.y;
		while(cnt){

			oseq[seqpnt].x=pnt1.x;
			oseq[seqpnt++].y=pnt1.y;
			oseq[seqpnt].x=pnt0.x;
			oseq[seqpnt++].y=pnt0.y;
			oseq[seqpnt].x=pnt1.x;
			oseq[seqpnt++].y=pnt1.y;
			pnt0.x+=stp.x;
			pnt0.y+=stp.y;
			pnt1.x+=stp.x;
			pnt1.y+=stp.y;
			cnt--;
		}
		oseq[seqpnt].x=flt[fin].x;
		oseq[seqpnt++].y=flt[fin].y;
	}
	else{

		oseq[seqpnt].x=flt[fin].x;
		oseq[seqpnt++].y=flt[fin].y;
		oseq[seqpnt].x=flt[strt].x;
		oseq[seqpnt++].y=flt[strt].y;
		oseq[seqpnt].x=flt[fin].x;
		oseq[seqpnt++].y=flt[fin].y;
	}
}

void bold(double siz){

	unsigned		ind,ine=0;
	unsigned short	nlin,tlin;
	double			len;

	tlin=getlast();
	seqpnt=0;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	for(ind=0;ind<(unsigned)sids-1;ind++){

		nlin=nxt(tlin);
		boldlin(tlin,nlin,siz);
		tlin=nlin;
	}
	if(frmpnt->typ!=LIN){

		nlin=nxt(tlin);
		boldlin(tlin,nlin,siz);
	}
	for(ind=0;ind<seqpnt-1;ind++){

		len=hypot(oseq[ind+1].x-oseq[ind].x,oseq[ind+1].y-oseq[ind].y);
		if(len>TINY){

			oseq[ine].x=oseq[ind].x;
			oseq[ine++].y=oseq[ind].y;
		}
	}
	oseq[ine].x=flt[nlin].x;
	oseq[ine++].y=flt[nlin].y;
	seqpnt=ine;
}

void refilfn(){

	double		tspac;
	double		tsiz=usesiz;
	float		tlen;

	rstMap(TXFIL);
	fvars(clofind);
	if(frmpnt->typ==LIN)
		frmpnt->wind=0;
	savdo();
	fdelstch();
	setMap(WASREFIL);
	delpnt=hed.stchs;
	if(frmpnt->fspac<0.5&&!isclp(clofind))
		frmpnt->fspac=0.5;
	if(frmpnt->espac<0.5)
		frmpnt->espac=0.5;
	usesiz=frmpnt->flencnt.flen;
	if(!chkMap(WASDO))
		savdo();
	rstMap(WASDO);
	if(frmpnt->xat&(AT_UND|AT_WALK)&&frmpnt->typ==LIN&&frmpnt->ftyp!=CONTF)
		frmpnt->typ=POLI;
	isind=isind2=0;
	rstMap(ISUND);
	switch(frmpnt->typ){

	case LIN:

		plen=frmpnt->esiz;
		switch(frmpnt->etyp&NEGUND){

		case EGLIN:

			lastflt=0;
			brdfil(frmpnt->elen);
			ritbrd();
			break;

		case EGBLD:

			lastflt=0;
			bold(frmpnt->elen);
			ritbrd();
			break;

		case EGCLP:

			oclp(frmpnt->clp,frmpnt->nclp);
			clpout();
			seqpnt=0;
			clpbrd(0);
			ritbrd();
			break;

		case EGSAT:

			rstMap(SAT1);
			slbrd();
			ritbrd();
			break;

		case EGPRP:

			if(frmpnt->sids>2){

				rstMap(SAT1);
				plbrd(frmpnt->espac);
				ritbrd();
			}
			break;

		case EGAP:

			lapbrd();
			ritapbrd();
			rstMap(SAT1);
			slbrd();
			ritbrd();
			break;

		case EGHOL:

			plen=frmpnt->esiz*2;
			tlen=bfclen;
			bfclen=getblen();
			satout(20);
			blbrd(frmpnt->espac);
			bfclen=tlen;
			ritbrd();
			break;

		case EGPIC:

			oclp(frmpnt->clp,frmpnt->nclp);
			seqpnt=0;
			tlen=bfclen;
			bfclen=getplen();
			clpic(0);
			bfclen=tlen;
			ritbrd();
			break;

		case EGDUB:

			lastflt=0;
			dubfn();
			ritbrd();
			break;

		case EGCHNL:

			setMap(LINCHN);
			chnfn();
			ritbrd();
			break;

		case EGCHNH:

			rstMap(LINCHN);
			chnfn();
			ritbrd();
			break;

		case EGCLPX:

			oclp(frmpnt->clp,frmpnt->nclp);
			duxclp();
			ritbrd();
			break;
		}
		if(frmpnt->ftyp==CONTF&&frmpnt->at&FRECONT){

			contf();
			ritfil();
		}
		break;

	case POLI:

		chkcwlk();
		chkwlk();
		chkund();
		rstMap(ISUND);
		if(frmpnt->ftyp){

			tspac=stspace;
			stspace=frmpnt->fspac;
			switch((unsigned)frmpnt->ftyp){

			case VRTF:

				fnvrt();
				lconflt=frmpnt->flt;
				break;

			case HORF:

				fnhor();
				lconflt=angfrm.flt;
				break;

			case ANGF:

				ang=PI/2-frmpnt->angclp.fang;
				filang();
				lconflt=angfrm.flt;
				break;

			case VCLPF:

				oclp(frmpnt->angclp.clp,frmpnt->flencnt.nclp);
				setangf(0);
				fvars(clofind);
				clpcon();
				goto skpfil;

			case HCLPF:

				oclp(frmpnt->angclp.clp,frmpnt->flencnt.nclp);
				horclpfn();
				goto skpfil;

			case ANGCLPF:

				oclp(frmpnt->angclp.clp,frmpnt->flencnt.nclp);
				rstMap(ISUND);
				angclpfn();
				goto skpfil;

			case TXVRTF:

				setangf(0);
				setxt();
				clpcon();
				goto skpfil;

			case TXHORF:

				setxt();
				horclpfn();
				goto skpfil;

			case TXANGF:

				setxt();
				rstMap(ISUND);
				angclpfn();
				goto skpfil;
			}
			lcon();
			bakseq();
			if(frmpnt->ftyp!=VRTF&&frmpnt->ftyp!=TXVRTF){

				ang=-ang;
				rotbak();
			}
skpfil:;
			ritfil();
			stspace=tspac;
		}
		chkbrd();
		break;

	case SAT:

		chkcwlk();
		chkwlk();
		chkund();
		rstMap(ISUND);
		switch(frmpnt->ftyp){

		case SATF:

			tspac=stspace;
			stspace=frmpnt->fspac;
			usesiz=frmpnt->flencnt.flen;
			satfil();
			stspace=tspac;
			ritfil();
			break;

		case CLPF:

			oclp(frmpnt->angclp.clp,frmpnt->flencnt.nclp);
			fmclp();
			ritfil();
			break;

		case FTHF:

			if(rstMap(FLPBLND))
				frmpnt->xat^=AT_FTHBLND;
			setMap(CNV2FTH);
			fthrfn();
			fritfil();
			break;
		}
		chkbrd();
	}
	usesiz=tsiz;
	intlv();
	ritot(hed.stchs);
	setfchk();
}

void refil(){

	unsigned trg,ind,at;

	if(!chku(WRNOF))
	{
		trg=(clofind<<FRMSHFT)|USMSK;
		for(ind=0;ind<hed.stchs;ind++){

			at=stchs[ind].at;
			if(!(at&NOTFRM)&&(at&(USMSK|FRMSK))==trg){

				if(hfdat)
					setMap(WASFRMFRM);
				undat();
				tabmsg(IDS_REFIL);
				setMap(MOVMSG);
				okcan();
				return;
			}
		}
	}
	refilfn();
}

void setfpnt(){

	POINT		stchpx;
	FLPNT*		dpnt;

	unfrm();
	fvars(clofind);
	dpnt=&frmpnt->flt[0];
	stchpx.x=msg.pt.x-stOrg.x;
	stchpx.y=msg.pt.y-stOrg.y;
	rats();
	px2stchf(stchpx,&dpnt[clofine]);
	frmout(clofind);
	refil();
	setMap(WASFPNT);
	rstMap(SELBOX);
	setMap(FRMPSEL);
	ritfcor(&flt[clofine]);
	setMap(RESTCH);
}

unsigned short nxt(unsigned short ind){

	ind++;
	if(ind>(unsigned)sids-1)
		ind=0;
	return ind;
}

unsigned short prv(unsigned ind){

	if(ind)
		ind--;
	else
		ind=sids-1;
	return ind;
}

unsigned proj(DUBPNT pnt,double slop,FLPNT pnt0,FLPNT pnt1,DUBPNT* ipnt){

	DUBPNT	difl;
	double	slopl,con,conl,xmin,xmax,ymin,ymax,tdub;

	difl.x=pnt1.x-pnt0.x;
	if(difl.x){

		difl.y=pnt1.y-pnt0.y;
		slopl=difl.y/difl.x;
		conl=pnt0.y-slopl*pnt0.x;
		con=pnt.y-slop*pnt.x;
		ipnt->x=(conl-con)/(slop-slopl);
		ipnt->y=ipnt->x*slop+con;
	}
	else{

		ipnt->x=pnt0.x;
		con=pnt.y-slop*pnt.x;
		ipnt->y=ipnt->x*slop+con;
	}
	xmin=pnt0.x;
	xmax=pnt1.x;
	if(xmin>xmax){

		tdub=xmin;
		xmin=xmax;
		xmax=tdub;
	}
	if(difl.y){

		ymin=pnt0.y;
		ymax=pnt1.y;
		if(ymin>ymax){

			tdub=ymin;
			ymin=ymax;
			ymax=tdub;
		}
		if(ipnt->x<xmin||ipnt->x>xmax||ipnt->y<ymin||ipnt->y>ymax)
			return 0;
		else
			return 1;
	}
	else{

		if(ipnt->x<xmin||ipnt->x>xmax)
			return 0;
		else
			return 1;
	}
}

unsigned projv(double pntx,FLPNT pnt0,FLPNT pnt1,DUBPNT* ipnt){

	double tdub,slop,dx;

	ipnt->x=pntx;
	dx=pnt1.x-pnt0.x;
	if(dx){

		slop=(pnt1.y-pnt0.y)/dx;
		ipnt->y=(pntx-pnt0.x)*slop+pnt0.y;
		if(pnt0.x>pnt1.x){
			tdub=pnt0.x;
			pnt0.x=pnt1.x;
			pnt1.x=tdub;
		}
		if(pntx<pnt0.x||pntx>pnt1.x)
			return 0;
		else
			return 1;
	}
	else
		return 0;
}

unsigned projh(double pnty,FLPNT pnt0,FLPNT pnt1,DUBPNT* ipnt){

	double tdub,slop,dx,dy;

	ipnt->y=pnty;
	dx=pnt1.x-pnt0.x;
	if(dx){

		dy=pnt1.y-pnt0.y;
		if(dy){

			slop=dy/dx;
			ipnt->x=(pnty-pnt0.y)/slop+pnt0.x;
		}
		else
			return 0;
	}
	else
		ipnt->x=pnt0.x;
	if(pnt0.y>pnt1.y){
		tdub=pnt0.y;
		pnt0.y=pnt1.y;
		pnt1.y=tdub;
	}
	if(pnty<pnt0.y||pnty>pnt1.y)
		return 0;
	else
		return 1;
}

void filang(){

	unsigned	ind;

	frmcpy(&angfrm,&formlst[clofind]);
	rotcntr.x=(double)(angfrm.rct.right-angfrm.rct.left)/2+angfrm.rct.left;
	rotcntr.y=(double)(angfrm.rct.top-angfrm.rct.bottom)/2+angfrm.rct.bottom;
	angfrm.flt=angflt;
	for(ind=0;ind<angfrm.sids;ind++){

		angfrm.flt[ind].x=frmpnt->flt[ind].x;
		angfrm.flt[ind].y=frmpnt->flt[ind].y;
		rotflt(&angfrm.flt[ind]);
	}
	frmpnt=&angfrm;
	fnvrt();
	frmpnt=&formlst[clofind];
}

void makpoli(){

	if(frmpnt->typ==SAT){

		if(frmpnt->stpt)
			delsac(clofind);
	}
	frmpnt->typ=POLI;
}

void filinu(float pntx,float pnty){

	unsigned	cnt;
	double		len;
	DUBPNT		ipnt,stp,dif;

	ipnt.x=sPnt.x;
	ipnt.y=sPnt.y;
	dif.x=pntx-sPnt.x;
	dif.y=pnty-sPnt.y;
	len=hypot(dif.x,dif.y);
	cnt=len/usesiz;
	if(chkmax(cnt,seqpnt)||cnt+seqpnt>MAXSEQ-3)
		return;
	if(cnt){

		if(chkMap(FILDIR))
			cnt++;
		stp.x=dif.x/cnt;
		stp.y=dif.y/cnt;
		while(cnt>0){

			ipnt.x+=stp.x;
			ipnt.y+=stp.y;
			oseq[seqpnt].x=ipnt.x;
			oseq[seqpnt++].y=ipnt.y;
			cnt--;
		}
	}
	else{

		oseq[seqpnt].x=pntx;
		oseq[seqpnt++].y=pnty;
	}
	sPnt.x=pntx;
	sPnt.y=pnty;
}

void filin(DUBPNT pnt){

	DUBPNT dif,stp,ipnt;
	double len;
	int cnt;

	dif.x=pnt.x-sPnt.x;
	dif.y=pnt.y-sPnt.y;
	len=hypot(dif.x,dif.y);
	ipnt.x=sPnt.x;
	ipnt.y=sPnt.y;
	cnt=len/usesiz;
	if(chkmax(cnt,seqpnt)||(cnt+seqpnt)>MAXSEQ-3)
		return;
	if(cnt){

		if(chkMap(FILDIR))
			cnt++;
		stp.x=dif.x/cnt;
		stp.y=dif.y/cnt;
		while(cnt>0){

			ipnt.x+=stp.x;
			ipnt.y+=stp.y;
			oseq[seqpnt].x=ipnt.x;
			oseq[seqpnt++].y=ipnt.y;
			cnt--;
		}
	}
	else{

		oseq[seqpnt].x=pnt.x;
		oseq[seqpnt++].y=pnt.y;
	}
	sPnt.x=pnt.x;
	sPnt.y=pnt.y;
}

unsigned short isclos(SMALPNTL* pnt0,SMALPNTL* pnt1){

	float		lo0,hi0,lo1,hi1;

	hi0=pnt0[1].y+rgclos;
	lo0=pnt0[0].y-rgclos;
	hi1=pnt1[1].y+rgclos;
	lo1=pnt1[0].y-rgclos;
	if(hi0<lo1)
		return 0;
	if(hi1<lo0)
		return 0;
	return 1;
}

BOOL lnclos(unsigned gp0,unsigned ln0,unsigned gp1,unsigned ln1){

	unsigned	ind0,ind1,cnt0,cnt1;
	SMALPNTL*	pnt0;
	SMALPNTL*	pnt1;

	if(gp1>grindpnt-2)
		return 0;
	if(!gp0)
		return 0;
	cnt0=(grinds[gp0+1]-grinds[gp0])>>1;
	ind0=0;
	pnt0=&lins[grinds[gp0]];
	while(cnt0&&pnt0[ind0].lin!=ln0){

		cnt0--;
		ind0+=2;
	}
	if(cnt0){

		cnt1=(grinds[gp1+1]-grinds[gp1])>>1;
		ind1=0;
		pnt1=&lins[grinds[gp1]];
		while(cnt1&&pnt1[ind1].lin!=ln1){

			cnt1--;
			ind1+=2;
		}
		if(cnt1){

			if(isclos(&pnt0[ind0],&pnt1[ind1]))
				return 1;
			else
				return 0;
		}
	}
	return 0;
}

unsigned short regclos(unsigned rg0,unsigned rg1){
	
	SMALPNTL*	pnt0s;
	SMALPNTL*	pnt0e;
	SMALPNTL*	pnt1s;
	SMALPNTL*	pnt1e;
	unsigned 	grp0s;
	unsigned 	grp0e;
	unsigned 	grp1s;
	unsigned 	grp1e;
	unsigned	grps;
	unsigned	grpe;
	unsigned	lins,line;
	unsigned	prlin,polin;

	pnt0s=&*seq[rgns[rg0].strt];
	pnt1s=&*seq[rgns[rg1].strt];
	grp1s=pnt1s->grp;
	grp0s=pnt0s->grp;
	if(grp0s>grp1s){

		grps=grp0s;
		lins=pnt0s->lin;
		prlin=pnt1s->lin;
	}
	else{

		grps=grp1s;
		lins=pnt1s->lin;
		prlin=pnt0s->lin;
	}
	if(grps&&lnclos(grps-1,prlin,grps,lins)){

		nxtgrp=grps;
		return 1;
	}
	else{

		pnt0e=&*seq[rgns[rg0].end];
		pnt1e=&*seq[rgns[rg1].end];
		grp1e=pnt1e->grp;
		grp0e=pnt0e->grp;
		if(grp0e<grp1e){

			grpe=grp0e;
			line=pnt0e->lin;
			polin=pnt1e->lin;
		}
		else{

			grpe=grp1e;
			line=pnt1e->lin;
			polin=pnt0e->lin;
		}
		if(lnclos(grpe,line,grpe+1,polin)){

			nxtgrp=grpe;
			return 1;
		}
	}
	if(abs(grp0s-grp1s)<2){

		if(isclos(pnt0s,pnt1s)){

			nxtgrp=grp0s;
			return 1;
		}
	}
	if(abs(grp0s-grp1e)<2){

		if(isclos(pnt0s,pnt1e)){

			nxtgrp=grp0s;
			return 1;
		}
	}
	if(abs(grp0e-grp1s)<2){

		if(isclos(pnt0e,pnt1s)){

			nxtgrp=grp0e;
			return 1;
		}
	}
	if(abs(grp0e-grp1e)<2){

		if(isclos(pnt0e,pnt1e)){

			nxtgrp=grp0e;
			return 1;
		}
	}
	return 0;
}

BOOL unvis(){

	for(vispnt=0;vispnt<rgcnt;vispnt++){

		if(!visit[vispnt])
			return 1;
	}
	return 0;
}

unsigned setseq(unsigned bpnt){
	return bts(seqmap, bpnt) ? 0 : 1;
}

void rspnt(float fx,float fy){

	bseq[opnt].x=fx;
	bseq[opnt].y=fy;
	bseq[opnt++].attr=0;
}

void dunseq(unsigned strt,unsigned fin){

	SMALPNTL*	lin0;
	SMALPNTL*	lin1;
	unsigned	ind;
	double		dy,miny;

	miny=1e30;
	for(ind=strt;ind<=fin;ind++){

		lin0=&*seq[ind];
		dy=lin0[1].y-lin0->y;
		if(dy<miny)
			miny=dy;
	}
	miny/=2;
	lin0=&*seq[strt];
	lin1=&*seq[fin];
	if(miny=1e30/2)
		miny=0;
	rspnt(lin0->x,lin0->y+miny);
	rspnt(lin1->x,lin1->y+miny);
	lastgrp=lin1->grp;
}

void movseq(unsigned ind){

	SMALPNTL* lin;

	lin=&*seq[ind];
	bseq[opnt].attr=SEQBOT;
	bseq[opnt].x=lin->x;
	bseq[opnt].y=lin->y;
	opnt++;
	lin++;
	bseq[opnt].attr=SEQTOP;
	bseq[opnt].x=lin->x;
	bseq[opnt].y=lin->y;
	opnt++;
}

void duseq2(unsigned ind){

	seqlin=&*seq[ind];	
	rspnt((seqlin[1].x-seqlin[0].x)/2+seqlin[0].x,(seqlin[1].y-seqlin[0].y)/2+seqlin[0].y);
}

void duseq1(){

	rspnt((seqlin[1].x-seqlin[0].x)/2+seqlin[0].x,(seqlin[1].y-seqlin[0].y)/2+seqlin[0].y);
}

void duseq(unsigned strt,unsigned fin){

	unsigned	ind,topbak;

	seqlin=0;
	rstMap(SEQDUN);
	topbak=seq[strt][1].lin;
	if(strt>fin){

		for(ind=strt;(int)ind>=(int)fin;ind--){

			if(setseq(ind)){
				
				if(!setMap(SEQDUN))
					duseq2(ind);
				else{

					if(topbak!=seq[ind][1].lin){

						if(ind)
							duseq2(ind+1);
						duseq2(ind);
						topbak=seqlin[1].lin;
					}
				}
			}
			else{

				if(rstMap(SEQDUN))
					duseq2(ind+1);
				seqlin=&*seq[ind];
				movseq(ind);
			}
		}
		if(rstMap(SEQDUN))
			duseq2(ind+1);
		lastgrp=seqlin->grp;
	}
	else{
	
		for(ind=strt;ind<=fin;ind++){

			if(setseq(ind)){

				if(!setMap(SEQDUN))
					duseq2(ind);
				else{

					if(topbak!=seq[ind][1].lin){

						if(ind)
							duseq2(ind-1);
						duseq2(ind);
						topbak=seqlin[1].lin;
					}
				}
			}
			else{

				if(rstMap(SEQDUN)){

					if(ind)
						duseq2(ind-1);
				}
				seqlin=&*seq[ind];
				movseq(ind);
			}
		}
		if(rstMap(SEQDUN)){

			if(ind)
				duseq2(ind-1);
		}
		lastgrp=seqlin->grp;
	}
}

void brkseq(unsigned strt,unsigned fin){

	SMALPNTL*	lin=0;
	unsigned	ind,bgrp=0;

	rstMap(SEQDUN);
	if(strt>fin){

		bgrp=seq[strt]->grp+1;
		for(ind=strt;(int)ind>=(int)fin;ind--){

			bgrp--;
			if(seq[ind]->grp!=bgrp){

				rspnt(seqlin[0].x,seqlin[0].y);
				seqlin=&*seq[ind];
				rspnt(seqlin[0].x,seqlin[0].y);
				bgrp=seqlin[0].grp;
			}
			else
				seqlin=&*seq[ind];
			if(setseq(ind)){

				if(!setMap(SEQDUN))
					duseq1();
			}
			else
				movseq(ind);
		}
		lastgrp=seqlin->grp;
	}
	else{
	
		bgrp=seq[strt]->grp-1;
		for(ind=strt;ind<=fin;ind++){

			bgrp++;
			if(seq[ind]->grp!=bgrp){

				rspnt(seqlin[0].x,seqlin[0].y);
				seqlin=&*seq[ind];
				rspnt(seqlin[0].x,seqlin[0].y);
				bgrp=seqlin[0].grp;
			}
			else
				seqlin=&*seq[ind];
			if(setseq(ind)){

				if(!setMap(SEQDUN))
					duseq1();
			}
			else
				movseq(ind);
		}
		lastgrp=seqlin->grp;
	}
	if(rstMap(SEQDUN))
		duseq1();
}

void brkdun(unsigned strt,unsigned fin){

	rspnt(seq[strt]->x,seq[strt]->y);
	rspnt(seq[fin]->x,seq[fin]->y);
	rspnt(lconflt[seq[strt]->lin].x,lconflt[seq[strt]->lin].y);
	setMap(BRKFIX);
}

void durgn(unsigned pthi){

	unsigned	dun,gdif,mindif,ind,fdif,bdif;
	unsigned	seql,seqn;
	unsigned	seqs,seqe;
	unsigned	grpn,grps,grpe;
	unsigned	rgind;
	SMALPNTL*	pnts;
	SMALPNTL*	pnte;
	double		len,minlen;
	BSEQPNT*	bpnt;

	rgind=mpath[pthi].vrt;
	durpnt=&rgns[rgind];
	grpn=mpath[pthi].grpn;
	seqs=durpnt->strt;
	seqe=durpnt->end;
	if(mpath[pthi].skp||rstMap(BRKFIX)){

		if(bseq[opnt-1].attr!=SEQBOT)
			rspnt(bseq[opnt-2].x,bseq[opnt-2].y);
		pnts=&*seq[rgind];
		dun=seq[seqs]->lin;
		bpnt=&bseq[opnt-1];
		minlen=1e99;
		for(ind=0;ind<sids;ind++){

			len=hypot(bpnt->x-lconflt[ind].x,bpnt->y-lconflt[ind].y);
			if(len<minlen){

				minlen=len;
				mindif=ind;
			}
		}
		if(minlen)
			rspnt(lconflt[mindif].x,lconflt[mindif].y);
		fdif=(sids+dun-mindif)%sids;
		bdif=(sids-dun+mindif)%sids;
		if(fdif<bdif){

			ind=nxt(mindif);
			while(ind!=dun){

				rspnt(lconflt[ind].x,lconflt[ind].y);
				ind=nxt(ind);
			}
			rspnt(lconflt[ind].x,lconflt[ind].y);
		}
		else{

			ind=prv(mindif);
			while(ind!=dun){

				rspnt(lconflt[ind].x,lconflt[ind].y);
				ind=prv(ind);
			}
			rspnt(lconflt[ind].x,lconflt[ind].y);
		}
	}
	if(visit[rgind])
		dun=1;
	else{

		dun=0;
		visit[rgind]++;
	}
	pnts=&*seq[durpnt->strt];
	pnte=&*seq[durpnt->end];
	grps=pnts->grp;
	grpe=pnte->grp;
	if(grpe!=grps)
		seql=(double)(lastgrp-grps)/(grpe-grps)*(seqe-seqs)+seqs;
	else
		seql=0;
	if(seql>lpnt)
		seql=0;
	len=(double)(grpe-grps)*(seqe-seqs);
	if(len)
		seqn=(double)(grpn-grps)/len+seqs;
	else
		seqn=seqe;
	if(seql<seqs)
		seql=seqs;
	if(seql>seqe)
		seql=seqe;
	if(seqn<seqs)
		seqn=seqs;
	if(seqn>seqe)
		seqn=seqe;
	if(seq[seql]->grp!=lastgrp){

		if(seql<seqe&&seq[seql+1]->grp==lastgrp)
			seql++;
		else{

			if(seql>seqs&&seq[seql-1]->grp==lastgrp)
				seql--;
			else{

				mindif=0xffffffff;
				for(ind=seqs;ind<=seqe;ind++){

					gdif=abs(seq[ind]->grp-lastgrp);
					if(gdif<mindif){

						mindif=gdif;
						seql=ind;
					}
				}
			}
		}
	}
	if(seq[seqn]->grp!=grpn){

		if(seqn<seqe&&seq[seqn+1]->grp==grpn)
			seqn++;
		else{

			if(seqn>seqs&&seq[seqn-1]->grp==grpn)
				seqn--;
			else{

				mindif=0xffffffff;
				for(ind=seqs;ind<=seqe;ind++){

					gdif=abs(seq[ind]->grp-grpn);
					if(gdif<mindif){

						mindif=gdif;
						seqn=ind;
					}
				}
			}
		}
	}
	if(durpnt->cntbrk){

		if(dun){

			brkdun(seql,seqn);
		}
		else{

			if(lastgrp>=grpe){

				brkseq(seqe,seqs);
				if(pthi<mpathi-1&&seqe!=seqn)
					brkseq(seqs,seqn);
			}
			else{

				if(grps<=grpn){

					if(seql!=seqs)
						brkseq(seql,seqs);
					brkseq(seqs,seqe);
					if(pthi<mpathi-1&&seqe!=seqn)
						brkseq(seqe,seqn);
				}
				else{

					if(seql!=seqe)
						brkseq(seql,seqe);
					brkseq(seqe,seqs);
					if(pthi<mpathi-1&&seqs!=seqn)
						brkseq(seqs,seqn);
				}
			}
		}
	}
	else{

		if(dun)
			dunseq(seql,seqn);
		else{

			if(lastgrp>=grpe){

				duseq(seqe,seqs);
				duseq(seqs,seqn);
			}
			else{

				if(grps<=grpn){

					if(seql!=seqs)
						duseq(seql,seqs);
					duseq(seqs,seqe);
					if(pthi<mpathi-1&&seqe!=seqn)
						duseq(seqe,seqn);
				}
				else{

					if(seql!=seqe)
						duseq(seql,seqe);
					duseq(seqe,seqs);
					if(pthi<mpathi-1&&seqs!=seqn)
						duseq(seqs,seqn);
				}
			}
		}
	}
}

unsigned notdun(unsigned lvl){

	unsigned	ind;
	int			tpiv,pivot=lvl-1;

	rgpth=&tmpath[mpathi];
	rgpth[0].pcon=minds[dunrgn];
	rgpth[0].cnt=minds[dunrgn+1]-rgpth[0].pcon;
	for(ind=1;ind<lvl;ind++){

		rgpth[ind].pcon=minds[pmap[rgpth[ind-1].pcon].vrt];
		rgpth[ind].cnt=minds[pmap[rgpth[ind-1].pcon].vrt+1]-rgpth[ind].pcon;
	}
	while(visit[pmap[rgpth[pivot].pcon].vrt]&&pivot>=0){

		if(--rgpth[pivot].cnt>0)
			rgpth[pivot].pcon++;
		else{

			tpiv=pivot;
			do{
				
				tpiv--;
				if(tpiv<0)
					return 1;
				rgpth[tpiv].cnt--;
				rgpth[tpiv].pcon++;
			}while(!rgpth[tpiv].cnt);
			if(tpiv<0)
				return 1;
			tpiv++;
			while(tpiv<=pivot){

				if(tpiv){

					rgpth[tpiv].pcon=minds[pmap[rgpth[tpiv-1].pcon].vrt];
					rgpth[tpiv].cnt=minds[pmap[rgpth[tpiv-1].pcon].vrt+1]-rgpth[tpiv].pcon;
				}
				else{

					if(--rgpth[0].cnt)
						rgpth[0].pcon++;
					else
						return 1;
				}
				tpiv++;
			}
		}
	}
	return 0;
}

double reglen(unsigned reg){

	double		len,minlen=1e99;
	unsigned	ind,ine;
	SMALPNTL*	pnts[4];

	pnts[0]=seq[rgns[reg].strt];
	pnts[1]=&seq[rgns[reg].strt][1];
	pnts[2]=seq[rgns[reg].end];
	pnts[3]=&seq[rgns[reg].end][1];
	for(ind=0;ind<4;ind++){

		for(ine=0;ine<4;ine++){

			len=hypot(dunpnts[ind].x-pnts[ine]->x,dunpnts[ind].y-pnts[ine]->y);
			if(len<minlen)
				minlen=len;
		}
	}
	return minlen;
}

void nxtrgn(){

	unsigned	ind,nureg;;
	SMALPNTL*	tpnt;
	double		len,minlen=1e99;

	pthlen=1;
	while(notdun(pthlen)){

		pthlen++;
		if(pthlen>8){

			tpnt=&*seq[rgns[dunrgn].strt];
			dunpnts[0].x=tpnt[0].x;
			dunpnts[0].y=tpnt[0].y;
			dunpnts[1].x=tpnt[1].x;
			dunpnts[1].y=tpnt[1].y;
			tpnt=&*seq[rgns[dunrgn].end];
			dunpnts[2].x=tpnt[0].x;
			dunpnts[2].y=tpnt[0].y;
			dunpnts[3].x=tpnt[1].x;
			dunpnts[3].y=tpnt[1].y;
			nureg=0;
			for(ind=0;ind<rgcnt;ind++){

				if(!visit[ind]){

					len=reglen(ind);
					if(len<minlen){

						minlen=len;
						nureg=ind;
					}
				}
			}
			tmpath[mpathi].skp=1;
			for(ind=0;ind<cpnt;ind++){

				if(pmap[ind].vrt==nureg){

					tmpath[mpathi++].pcon=ind;
					visit[nureg]=1;
					dunrgn=nureg;
					return;
				}
			}
			tmpath[mpathi].cnt=vispnt;
			tmpath[mpathi++].pcon=0xffffffff;
			visit[vispnt]=1;
			dunrgn=vispnt;
			return;
		}
	}
	for(ind=0;ind<pthlen;ind++){

		tmpath[mpathi].skp=0;
		tmpath[mpathi++].pcon=rgpth[ind].pcon;
		visit[pmap[rgpth[ind].pcon].vrt]=1;
	}
	dunrgn=pmap[rgpth[ind-1].pcon].vrt;
}

int sqcomp(const void *arg1, const void *arg2){

	SMALPNTL* pnt0;
	SMALPNTL* pnt1;

	pnt0 = (SMALPNTL*) arg1;
	pnt1 = (SMALPNTL*) arg2;

	if(pnt0->lin==pnt1->lin){

		if(pnt0->grp==pnt1->grp){

			if(pnt0->y==pnt1->y)return 0;
			else{

				if(pnt0->y>pnt1->y)
					return 1;
				else
					return -1;
			}
		}
		else{

			if(pnt0->grp>pnt1->grp)
				return 1;
			else
				return -1;
		}
	}
	else{

		if(pnt0->lin>pnt1->lin)
			return 1;
		else
			return -1;
	}
}

void nxtseq(unsigned pthi){

	unsigned nxtvrt,ind;

	ind=minds[mpath[pthi].vrt];
	nxtvrt=mpath[pthi+1].vrt;
	while(ind<minds[mpath[pthi].vrt+1]&&pmap[ind].vrt!=nxtvrt){

		ind++;
	}
	mpath[mpath0++].grpn=pmap[ind].grpn;
}

#define BUGSEQ 0

void lcon(){

	unsigned		ind,ine,blin,cnt,sgrp;
	RGN*			trgns;
	short			tcon;
	RCON*			pcon;
	RCON*			tmap;
	SMALPNTL*		tpnt;
	unsigned*		tsrgns;
	unsigned		sind;

#if BUGSEQ

	unsigned		bugcol;
#endif
		
	if(spnt){

		seq=new SMALPNTL*[spnt>>1];
		lpnt=0;
		for(ind=0;ind<spnt;ind+=2)
			seq[lpnt++]=&lins[ind];
		qsort((void*)seq,lpnt,4,sqcomp);
		rgcnt=0;
		trgns=(RGN*)oseq;
		trgns[0].strt=0;
		blin=seq[0]->lin;
		for(ind=0;ind<lpnt;ind++){

			if(blin!=seq[ind]->lin){

				trgns[rgcnt++].end=ind-1;
				trgns[rgcnt].strt=ind;
				blin=seq[ind]->lin;
			}
		}
		trgns[rgcnt++].end=ind-1;
		rgns=new RGN[rgcnt];
		visit=new char[rgcnt];
		for(ind=0;ind<rgcnt;ind++){

			rgns[ind].strt=trgns[ind].strt;
			rgns[ind].end=trgns[ind].end;
			visit[ind]=0;
			rgns[ind].cntbrk=0;
		}
		tsrgns=(unsigned*)oseq;
		sind=0;
		for(ind=0;ind<rgcnt;ind++){

			cnt=0;
			if((rgns[ind].end-rgns[ind].strt)>1){

				sgrp=seq[rgns[ind].strt]->grp;
				for(ine=rgns[ind].strt+1;ine<=rgns[ind].end;ine++){

					sgrp++;
					if(seq[ine]->grp!=sgrp){

						if(!cnt)
							rgns[ind].brk=sind;
						cnt++;
						sgrp=seq[ine]->grp;
						tsrgns[sind++]=ine;
					}
				}
			}
			rgns[ind].cntbrk=cnt;				
		}
		srgns=new unsigned[sind];
		for(ind=0;ind<sind;ind++)
			srgns[ind]=tsrgns[ind];
		tmap=(RCON*)bseq;
		minds=new unsigned[rgcnt+1];

#if BUGSEQ
		bugcol=0;seqpnt=0;
		for(ind=0;ind<rgcnt;ind++){

			for(ine=rgns[ind].strt;ine<=rgns[ind].end;ine++){

				tpnt=&*seq[ine];
				stchs[seqpnt].at=bugcol;
				stchs[seqpnt].x=tpnt[0].x;
				stchs[seqpnt++].y=tpnt[0].y;
				stchs[seqpnt].at=bugcol;
				stchs[seqpnt].x=tpnt[1].x;
				stchs[seqpnt++].y=tpnt[1].y;
			}
			bugcol++;
			bugcol&=0xf;
		}
		hed.stchs=seqpnt;
		goto seqskip;
#endif
		opnt=0;
		if(rgcnt>1){

			ine=0;cpnt=0;
			for(ind=0;ind<rgcnt;ind++){

				pcon=&tmap[cpnt];
				minds[ind]=cpnt;
				cnt=0;rgclos=0;
				for(ine=0;ine<rgcnt;ine++){

					if(ind!=ine){

						tcon=regclos(ind,ine);
						if(tcon){

							tmap[cpnt].con=tcon;
							tmap[cpnt].grpn=nxtgrp;
							tmap[cpnt++].vrt=ine;
							cnt++;
						}
					}
				}
				while(!cnt){

					rgclos+=stspace;
					cnt=0;
					for(ine=0;ine<rgcnt;ine++){

						if(ind!=ine){

							tcon=regclos(ind,ine);
							if(tcon){

								tmap[cpnt].con=tcon;
								tmap[cpnt].grpn=nxtgrp;
								tmap[cpnt++].vrt=ine;
								cnt++;
							}
						}
					}
				}
			}
			minds[ind]=cpnt;
			pmap=new RCON[cpnt+1];
			for(ind=0;ind<cpnt;ind++){

				pmap[ind].con=tmap[ind].con;
				pmap[ind].vrt=tmap[ind].vrt;
				pmap[ind].grpn=tmap[ind].grpn;
			}
			//find the leftmost region
			sgrp=0xffffffff;ine=0;
			for(ind=0;ind<rgcnt;ind++){

				tpnt=&*seq[rgns[ind].strt];
				if(tpnt->grp<sgrp){

					sgrp=tpnt->grp;
					ine=ind;
				}
			}
			opnt=0;
			tmpath=(RGSEQ*)oseq;
			//find the leftmost region in pmap
			mpathi=1;
			for(ind=0;ind<cpnt;ind++){

				if(pmap[ind].vrt==ine)
					goto lconskip;
			}
			pmap[cpnt].vrt=ine;
			pmap[cpnt].grpn=0;
			ind=cpnt;
lconskip:;
			//set the first entry in the temporary path to the leftmost region
			tmpath[0].pcon=ind;
			tmpath[0].cnt=1;
			tmpath[0].skp=0;
			visit[ine]=1;
			dunrgn=ine;
			while(unvis())
				nxtrgn();
			ine=0;
			cnt=0xffffffff;
			mpath=(FSEQ*)&oseq[OSEQLEN>>1];
			for(ind=0;ind<mpathi;ind++){

				mpath[ine].skp=tmpath[ind].skp;
				if(tmpath[ind].pcon==0xffffffff){

					mpath[ine++].vrt=tmpath[ind].cnt;
					cnt=tmpath[ind].cnt;
				}
				else{

					if(tmpath[ind].pcon!=cnt){

						cnt=tmpath[ind].pcon;
						mpath[ine++].vrt=pmap[tmpath[ind].pcon].vrt;
					}
				}
			}
			mpathi=ind;mpath0=0;
			for(ind=0;ind<mpathi;ind++)
				nxtseq(ind);
			ine=(lpnt>>5)+1;
			seqmap=new unsigned[ine];
			for(ind=0;ind<ine;ind++)
				seqmap[ind]=0;
			for(ind=0;ind<rgcnt;ind++)
				visit[ind]=0;
			lastgrp=0;
			for(ind=0;ind<mpath0;ind++){

//				sprintf(msgbuf,"ind %d,vrt %d,grpn %d\n",ind,pmap[ind].vrt,pmap[ind].grpn);
//				OutputDebugString(msgbuf);
				if(!unvis())
					break;
				durgn(ind);
			}
		}
		else{

			pmap=new RCON[1];
			mpath=new FSEQ[1];
			ine=(lpnt>>5)+1;
			seqmap=new unsigned[ine];
			for(ind=0;ind<ine;ind++)
				seqmap[ind]=0;
			lastgrp=0;
			mpath[0].vrt=0;
			mpath[0].grpn=seq[rgns[0].end]->grp;
			mpath[0].skp=0;
			durgn(0);
			delete mpath;
		}
//skip:;

#if BUGSEQ

seqskip:;
#endif
		delete seq;
		delete lins;
		delete rgns;
		delete minds;
		delete visit;
		delete pmap;
		delete grinds;
		delete seqmap;
		delete srgns;
	}
}

BOOL notin(unsigned ond){

	DUBPNT		pnt;
	unsigned	ind,cnt;
	DUBPNT		ipnt;
	double		len;

	cnt=0;minot=1e99;
	pnt.x=(oseq[ond+1].x-oseq[ond].x)/2+oseq[ond].x;
	pnt.y=(oseq[ond+1].y-oseq[ond].y)/2+oseq[ond].y;
	for(ind=0;ind<frmpnt->sids;ind++){

		if(projv(pnt.x,lin[ind],lin[ind+1],&ipnt)){

			if(ipnt.y>pnt.y)
				cnt++;
			len=fabs(ipnt.y-pnt.y);
			if(len<minot){

				minot=len;
				minotl=ind;
			}
		}
	}
	if(projv(pnt.x,lin[ind],lin[0],&ipnt)){

		if(ipnt.y>pnt.y)
			cnt++;
		len=fabs(ipnt.y-pnt.y);
		if(len<minot){

			minot=len;
			minotl=ind;
		}
	}
	return !(cnt&1);
}

unsigned seqtab[]=
{
	12,7,15,11,13,17,
};

#define RITSIZ 6

void bakseq(){

#if BUGBAK

	for(seqpnt=0;seqpnt<opnt;seqpnt++)
	{
		oseq[seqpnt].x=bseq[seqpnt].x;
		oseq[seqpnt].y=bseq[seqpnt].y;
	}
	frmpnt->fmax=6000;
#else

	int			cnt,rcnt;
	int			ind,rit;
	DUBPNT		dif,pnt,stp;
	double		len,rslop;
	double		usesiz2=usesiz*2;
	double		usesizh=usesiz/2;
	double		usesiz9=usesiz/9;
	double		stspac2=stspace*2;

	seqpnt=0;
	rstMap(FILDIR);
	ind=opnt-1;
	oseq[seqpnt].x=bseq[ind].x;
	oseq[seqpnt].y=bseq[ind].y;
	seqpnt++;
	sPnt.x=bseq[ind].x;
	sPnt.y=bseq[ind].y;
	ind--;
	while(ind>0){

		rcnt=ind%RITSIZ;
		if(seqpnt>MAXSEQ){

			seqpnt=MAXSEQ-1;
			return;
		}
		rit=bseq[ind].x/stspac2;
		dif.x=bseq[ind].x-bseq[ind+1].x;
		dif.y=bseq[ind].y-bseq[ind+1].y;
		if(dif.y)
			rslop=dif.x/dif.y;
		else
			rslop=1e99;
		switch(bseq[ind].attr){

		case SEQTOP:

			if(frmpnt->xat&AT_SQR){

				if(toglMap(FILDIR)){

					oseq[seqpnt].x=bseq[ind-1].x;
					oseq[seqpnt++].y=bseq[ind-1].y;
					cnt=ceil(bseq[ind].y/usesiz);
blntop:;
					oseq[seqpnt].y=cnt*usesiz+(rit%seqtab[rcnt])*usesiz9;
					if(oseq[seqpnt].y>bseq[ind].y)
						goto blntopx;
					dif.y=oseq[seqpnt].y-bseq[ind].y;
					oseq[seqpnt++].x=bseq[ind].x;
					cnt++;
					goto blntop;
blntopx:;
					oseq[seqpnt].x=bseq[ind].x;
					oseq[seqpnt++].y=bseq[ind].y;
				}
				else{

					oseq[seqpnt].x=bseq[ind].x;
					oseq[seqpnt++].y=bseq[ind].y;
					cnt=floor(bseq[ind].y/usesiz);
blntbot:;
					oseq[seqpnt].y=cnt*usesiz-((rit+2)%seqtab[rcnt])*usesiz9;
					if(oseq[seqpnt].y<bseq[ind-1].y)
						goto blntbotx;
					dif.y=oseq[seqpnt].y-bseq[ind-1].y;
					oseq[seqpnt++].x=bseq[ind].x;
					cnt--;
					goto blntbot;
blntbotx:;
					oseq[seqpnt].x=bseq[ind-1].x;
					oseq[seqpnt++].y=bseq[ind-1].y;
				}
			}
			else{

				cnt=ceil(bseq[ind+1].y/usesiz);
toplab:;
				oseq[seqpnt].y=cnt*usesiz+(rit%seqtab[rcnt])*usesiz9;
				if(oseq[seqpnt].y>bseq[ind].y)
					goto toplabx;
				dif.y=oseq[seqpnt].y-bseq[ind+1].y;
				dif.x=rslop*dif.y;
				oseq[seqpnt++].x=bseq[ind+1].x+dif.x;
				cnt++;
				goto toplab;
toplabx:;
				oseq[seqpnt].x=bseq[ind].x;
				oseq[seqpnt++].y=bseq[ind].y;
			}
			break;

		case SEQBOT:

			if(!(frmpnt->xat&AT_SQR)){

				cnt=floor(bseq[ind+1].y/usesiz);
botlab:;
				oseq[seqpnt].y=cnt*usesiz-((rit+2)%seqtab[rcnt])*usesiz9;
				if(oseq[seqpnt].y<bseq[ind].y)
					goto botlabx;
				dif.y=oseq[seqpnt].y-bseq[ind+1].y;
				dif.x=rslop*dif.y;
				oseq[seqpnt++].x=bseq[ind+1].x+dif.x;
				cnt--;
				goto botlab;
botlabx:;
				oseq[seqpnt].x=bseq[ind].x;
				oseq[seqpnt++].y=bseq[ind].y;
			}
			break;

		case 0:

			dif.x=bseq[ind].x-bseq[ind+1].x;
			dif.y=bseq[ind].y-bseq[ind+1].y;
			rstMap(FILDIR);
			len=hypot(dif.x,dif.y);
			if(len){

				if(len>usesiz2){

					pnt.x=bseq[ind+1].x;
					pnt.y=bseq[ind+1].y;
					cnt=len/usesiz-1;
					if(chkmax(cnt,seqpnt)||(cnt+seqpnt)>MAXSEQ-3)
						return;
					stp.x=dif.x/cnt;
					stp.y=dif.y/cnt;
					while(cnt){

						pnt.x+=stp.x;
						pnt.y+=stp.y;
						oseq[seqpnt].x=pnt.x;
						oseq[seqpnt++].y=pnt.y;
						cnt--;
					}
				}
			}
			oseq[seqpnt].x=bseq[ind].x;
			oseq[seqpnt++].y=bseq[ind].y;
		}
		ind--;
	}
#endif
}

void fnvrt(){

	unsigned	ind,ine,inf,cnt,lincnt=0,tind;
	int			tcnt;
	DUBPNTL*	jpts;
	DUBPNTL**	pjpts;
	double		lox,hix,mx0,mstp;
	DUBPNT		tpnt;
	unsigned*	tgrinds;

	lin=frmpnt->flt;
	sids=frmpnt->sids;
	lox=hix=lin[0].x;
	for(ind=1;ind<sids;ind++){

		if(lin[ind].x>hix)
			hix=lin[ind].x;
		if(lin[ind].x<lox)
			lox=lin[ind].x;
	}
	tcnt=lox/stspace;
	lox=stspace*tcnt;
	cnt=(hix-lox)/stspace+1;
	jpts=new DUBPNTL[sids+2];
	pjpts=new DUBPNTL*[sids+2];
	mstp=(hix-lox)/cnt;
	mx0=lox;
	maxlins=0;
	for(ind=0;ind<cnt;ind++){

		inf=0;
		lox+=mstp;
		for(ine=0;ine<(unsigned)sids-1;ine++){
			
			if(projv(lox,lin[ine],lin[ine+1],&tpnt))
				inf++;
		}
		if(projv(lox,lin[ine],lin[0],&tpnt))
			inf++;
		lincnt+=inf;
		if(inf>maxlins)
			maxlins=inf;
	}
	maxlins=(maxlins>>1);
	lins=new SMALPNTL[lincnt];
	spnt=0;grpind=0;
	tgrinds=(unsigned*)bseq;
	grindpnt=0;
	for(ind=0;ind<cnt;ind++){

		mx0+=mstp;
		inf=0;
		for(ine=0;ine<(unsigned)sids-1;ine++){

			if(projv(mx0,lin[ine],lin[ine+1],&tpnt)){

				pjpts[inf]=&jpts[inf];
				jpts[inf].lin=ine;
				jpts[inf].x=tpnt.x;
				jpts[inf++].y=tpnt.y;
				
			}
		}
		if(projv(mx0,lin[ine],lin[0],&tpnt)){

			pjpts[inf]=&jpts[inf];
			jpts[inf].lin=ine;
			jpts[inf].x=tpnt.x;
			jpts[inf++].y=tpnt.y;
		}
		if(inf>1){

			inf&=0xfffffffe;
			tgrinds[grindpnt++]=spnt;
			qsort((void*)pjpts,inf,4,comp);
			ine=0;
			tind=spnt;
			while(ine<inf){

				lins[spnt].lin=pjpts[ine]->lin;
				lins[spnt].grp=grpind;
				lins[spnt].x=pjpts[ine]->x;
				lins[spnt++].y=pjpts[ine++]->y;
				lins[spnt].lin=pjpts[ine]->lin;
				lins[spnt].grp=grpind;
				lins[spnt].x=pjpts[ine]->x;
				lins[spnt++].y=pjpts[ine++]->y;
			}
			if(spnt!=tind)
				grpind++;
		}
	}
	tgrinds[grindpnt++]=spnt;
	grinds=new unsigned[grindpnt];
	for(ind=0;ind<grindpnt;ind++)
		grinds[ind]=tgrinds[ind];
	grpind--;
	delete jpts;
	delete pjpts;
}

void fnhor(){

	unsigned	ind;

	frmcpy(&angfrm,&formlst[clofind]);
	rotcntr.x=(double)(angfrm.rct.right-angfrm.rct.left)/2+angfrm.rct.left;
	rotcntr.y=(double)(angfrm.rct.top-angfrm.rct.bottom)/2+angfrm.rct.bottom;
	ang=PI/2;
	angfrm.flt=angflt;
	for(ind=0;ind<angfrm.sids;ind++){

		angfrm.flt[ind].x=frmpnt->flt[ind].x;
		angfrm.flt[ind].y=frmpnt->flt[ind].y;
		rotflt(&angfrm.flt[ind]);
	}
	frmpnt=&angfrm;
	fnvrt();
	frmpnt=&formlst[clofind];
}

void fsvrt(){

	delmclp(clofind);
	deltx();
	makpoli();
	frmpnt->ftyp=VRTF;
	frmpnt->typ=POLI;
	frmpnt->fcol=actcol;
	fsizpar();
	frmpnt->fspac=stspace;
	frmpnt->typ=POLI;
	dusqr();
	refilfn();
}

void filvrt(){

	unsigned ind;;

	if(filmsgs(FMM_VRT))
		return;
	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			if(frmpnt->typ!=LIN)
				fsvrt();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			fsvrt();
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
	}
}

void fshor(){

	delmclp(clofind);
	deltx();
	makpoli();
	frmpnt->ftyp=HORF;
	frmpnt->fcol=actcol;
	fsizpar();
	frmpnt->fspac=stspace;
	frmpnt->angclp.fang=(float)PI/2;
	frmpnt->typ=POLI;
	dusqr();
	refil();
}

void filhor(){

	unsigned ind;

	if(filmsgs(FMM_HOR))
		return;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			if(frmpnt->typ!=LIN)
				fshor();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}	
	else{

		if(chkMap(FORMSEL)){

			fshor();
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
	}
}

void fsangl(){

	double bang;

	bang=ang;
	delmclp(clofind);
	deltx();
	makpoli();
	frmpnt->ftyp=ANGF;
	ang=PI/2-ang;
	frmpnt->angclp.fang=(float)ini.angl;
	frmpnt->fcol=actcol;
	fsizpar();
	frmpnt->fspac=stspace;
	frmpnt->typ=POLI;
	dusqr();
	refil();
	ang=bang;
}

void filangl(){

	unsigned ind;

	if(filmsgs(FMM_ANG))
		return;
	ang=ini.angl;
	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			if(frmpnt->typ!=LIN)
				fsangl();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			fsangl();
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
	}
}

void sRct2px(FLRCT strct,RECT* pxrct){

	pxrct->left=(strct.left-zRct.left)*zrat.x+0.5;
	pxrct->right=(strct.right-zRct.left)*zrat.x+0.5;
	pxrct->top=(scRct.bottom)-(strct.top-zRct.bottom)*zrat.y+0.5;
	pxrct->bottom=(scRct.bottom)-(strct.bottom-zRct.bottom)*zrat.y+0.5;
}

void setmfrm(){

	unsigned	ind;
	POINT		tpnt;
	POINT		tof;
	
//	formlst[formpnt].wind=ini.wind;
	sfCor2px(formlst[clofind].flt[0],&tpnt);
	tof.x=msg.pt.x-stOrg.x-tpnt.x+fmovdif.x;
	tof.y=msg.pt.y-stOrg.y-tpnt.y+fmovdif.y;
	for(ind=0;ind<formlst[clofind].sids;ind++){

		sfCor2px(formlst[clofind].flt[ind],&tpnt);
		flin[ind].x=tpnt.x+tof.x;
		flin[ind].y=tpnt.y+tof.y;
	}
	flin[ind].x=flin[0].x;
	flin[ind].y=flin[0].y;
}

void strtchbox(){

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	Polyline(rsdc,sizlin,5);
	SetROP2(rsdc,R2_COPYPEN);
}

void unstrtch(){

	if(rstMap(SHOSTRTCH))
		strtchbox();
}

unsigned chkfrm(){

	POINT		tpnt0,tpnt1;
	RECT		trct;
	unsigned	ind;
	double		len,mlen=1e99;

	fvars(clofind);
	tpnt0.x=msg.pt.x-stOrg.x;
	tpnt0.y=msg.pt.y-stOrg.y;
	nuflen=frmpnt->sids+1;
	duzrat();
	sRct2px(frmpnt->rct,&trct);
	rctlin[0].x=rctlin[6].x=rctlin[7].x=rctlin[8].x=trct.left;
	rctlin[1].x=rctlin[5].x=midl(trct.right,trct.left);
	rctlin[0].y=rctlin[1].y=rctlin[2].y=rctlin[8].y=trct.top;
	rctlin[3].y=rctlin[7].y=midl(trct.top,trct.bottom);
	rctlin[4].y=rctlin[5].y=rctlin[6].y=trct.bottom;
	rctlin[2].x=rctlin[3].x=rctlin[4].x=trct.right;
	for(ind=0;ind<10;ind++){

		len=hypot(rctlin[ind].x-tpnt0.x,rctlin[ind].y-tpnt0.y);
		if(len<mlen){

			mlen=len;
			cntrl=ind;
		}
		if(mlen<CLOSENUF){

			ritfrct(clofind,rsdc);
			for(ind=0;ind<4;ind++){

				sizlin[ind].x=rctlin[ind<<1].x;
				sizlin[ind].y=rctlin[ind<<1].y;
			}
			sizlin[4].x=sizlin[0].x;
			sizlin[4].y=sizlin[0].y;
			if(cntrl&1)
				setMap(STRTCH);
			else{

				setMap(EXPAND);
				xpct=(double)(frmpnt->rct.right-frmpnt->rct.left)/(frmpnt->rct.top-frmpnt->rct.bottom);
			}
			cntrl>>=1;
			setMap(SHOSTRTCH);
			strtchbox();
			return 1;
		}
	}
	if(tpnt0.x>=trct.left&&tpnt0.x<=trct.right&&
		tpnt0.y>=trct.top&&tpnt0.y<=trct.bottom){

		sfCor2px(frmpnt->flt[0],&tpnt1);
		fmovdif.x=tpnt1.x-tpnt0.x;
		fmovdif.y=tpnt1.y-tpnt0.y;
		setMap(FRMOV);
		return 1;
	}
	else
		return 0;
}

void rstfrm(){

	FLPNT		pof;
	unsigned	ind;
	POINT		tpnt;
	unsigned	tat=(clofind<<4);

	setmfrm();
	rstMap(FRMOV);
	tpnt.x=msg.pt.x+fmovdif.x;
	tpnt.y=msg.pt.y+fmovdif.y;
	pxCor2stch(tpnt);
	pof.x=sPnt.x-frmpnt->flt[0].x;
	pof.y=sPnt.y-frmpnt->flt[0].y;
	for(ind=0;ind<frmpnt->sids;ind++){

		frmpnt->flt[ind].x+=pof.x;
		frmpnt->flt[ind].y+=pof.y;
	}
	frmpnt->rct.bottom+=pof.y;
	frmpnt->rct.top+=pof.y;
	frmpnt->rct.left+=pof.x;
	frmpnt->rct.right+=pof.x;
	for(ind=0;ind<hed.stchs;ind++){

		if((stchs[ind].at&FRMSK)==tat&&stchs[ind].at&ALTYPMSK&&!(stchs[ind].at&NOTFRM)){

			stchs[ind].x+=pof.x;
			stchs[ind].y+=pof.y;
		}
	}
}

void clrfills(){

	unsigned ind;

	for(ind=0;ind<formpnt;ind++){

		formlst[ind].nclp=0;
		formlst[ind].flencnt.nclp=0;
		formlst[ind].etyp=0;
		formlst[ind].ftyp=0;
		formlst[ind].at&=NFRECONT;
		formlst[ind].xat&=!(AT_UND|AT_WALK);
	}
	clpad=0;
}

void dusat(){

	POINT* plin=&flin[satpt-1];

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	Polyline(rsdc,plin,2);
	SetROP2(rsdc,R2_COPYPEN);
//	SetROP2(sdc,R2_XORPEN);
//	SelectObject(sdc,fPen);
//	Polyline(sdc,plin,2);
//	SetROP2(sdc,R2_COPYPEN);
}

void unsat(){

	if(rstMap(SHOSAT))
		dusat();
}

void drwsat(){

	unsat();
	px2stch();
	flin[satpt].x=msg.pt.x-stOrg.x;
	flin[satpt].y=msg.pt.y-stOrg.y;
	setMap(SHOSAT);
	dusat();
}

void satpnt0(){

	px2stch();
	flin[0].x=msg.pt.x-stOrg.x;
	flin[0].y=msg.pt.y-stOrg.y;
	tpoly[0].x=sPnt.x;
	tpoly[0].y=sPnt.y;
	satpt=1;
	setMap(SATPNT);
}

void satpnt1(){

	unsat();
	px2stch();
	flin[satpt].x=msg.pt.x-stOrg.x;
	flin[satpt].y=msg.pt.y-stOrg.y;
	dusat();
	tpoly[satpt].x=sPnt.x;
	tpoly[satpt].y=sPnt.y;
	satpt++;
	setMap(RESTCH);
}

void satfix(){

	unsigned ind;

	if(satpt>1){

		formlst[formpnt].flt=adflt(satpt);
		for(ind=0;ind<satpt;ind++){

			formlst[formpnt].flt[ind].x=tpoly[ind].x;
			formlst[formpnt].flt[ind].y=tpoly[ind].y;
		}
		formlst[formpnt].sids=satpt;
		frmout(formpnt);
		formlst[formpnt].stpt=0;
		formpnt++;
		setMap(INIT);
	}
	rstMap(SHOSAT);
	setMap(RESTCH);
}

void delcon(unsigned cpnt)
{
	unsigned ind;
	unsigned loc;
	SATCON* tp;
	FRMHED* fp;

	tp=&frmpnt->sacang.sac[cpnt];
	loc=&frmpnt->sacang.sac[cpnt]-satks;
	if(satkad>loc)
		MoveMemory(tp,&tp[1],(satkad-loc+1)*sizeof(SATCON));
	for(ind=clofind+1;ind<formpnt;ind++)
	{
		fp=&formlst[ind];
		if(fp->typ==SAT&&fp->stpt)
			fp->sacang.sac--;
	}
	if(clofine<wpar)
		wpar--;
	frmpnt->stpt--;
	satkad--;
	stpt=frmpnt->stpt;
	if(frmpnt->ftyp==SATF)
		refil();
	coltab();
	setMap(RESTCH);
}

BOOL satselfn(){

	unsigned ind,ine,playcod;
	double		tlen,len=1e99;
	double		dx,dy;

	px2stch();
	for(ind=0;ind<formpnt;ind++){

		playcod=(formlst[ind].at&FRMLMSK)>>1;
		if(!actl||!playcod||playcod==actl){

			for(ine=0;ine<formlst[ind].sids;ine++){

				dx=sPnt.x-formlst[ind].flt[ine].x;
				dy=sPnt.y-formlst[ind].flt[ine].y;
				tlen=hypot(dx,dy);
				if(tlen<len){

					len=tlen;
					clofind=ind;
					clofine=ine;
				}
			}
		}
	}
	if(len<CLOSENUF)
		return 1;
	else
		return 0;
}

void satsel(){

	if(satselfn()){

		fvars(clofind);
		duzrat();
		xstrt=clofine;
		sfCor2px(frmpnt->flt[clofine],&flin[0]);
		rstMap(SHOCON);
		setMap(SATCNKT);
		if(frmpnt->typ==POLI)
			frmpnt->typ=SAT;
	}
}

void ducon(){

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	Polyline(rsdc,flin,2);
	SetROP2(rsdc,R2_COPYPEN);
}

void uncon(){

	if(rstMap(SHOCON))
		ducon();
}

void drwcon(){

	uncon();
	flin[1].x=msg.pt.x-stOrg.x;
	flin[1].y=msg.pt.y-stOrg.y;
	setMap(SHOCON);
	ducon();
}

int scomp(const void *arg1, const void *arg2){
	unsigned short **s1 = (unsigned short **) arg1, **s2 = (unsigned short **) arg2;
	if (**s2 == **s1) return 0;
	if (**s2 < **s1) return 1;
	return -1;
}

unsigned setchk(unsigned bPnt){
	return bts(chkmap, bPnt) ? 0xFFFFFFFF : 0;
}

unsigned chkchk(unsigned ind){
	return bt(chkmap, ind) ? 0xFFFFFFFF : 0;
}

unsigned nxtchk(unsigned ind){
	int bit = ffs(chkmap[ind]);

	if (bit == 0)
		 return 0xffffffff;

	btr(chkmap+ind, --bit);

	return bit;
}

unsigned prvchk(unsigned ind){
	if (chkmap[ind] == 0)
		 return 0xffffffff;

	int bit = __builtin_clz(chkmap[ind]) ^ 31;

	btr(chkmap+ind, bit);

	return bit;
}

void satadj()
{
	unsigned	ind,ine,inf,psac,mapsiz,prstpt;
	SATCON*		spnt;
	SATCON*		dpnt;
	unsigned short bstpt;
	FRMHED*		fp;

	fvars(clofind);
	bstpt=frmpnt->stpt;
	for(ind=0;ind<frmpnt->stpt;ind++)
	{
		if(sac[ind].fin>sids-1)
			sac[ind].fin=sids-1;
		if(sac[ind].strt>sids-1)
			sac[ind].strt=sids-1;
	}
	spnt=(SATCON*)bseq;
	mapsiz=(sids>>5)+1;
	chkmap=(unsigned*)oseq;
	psac=0;
	prstpt=stpt;
	for(ind=0;ind<stpt;ind++)
	{
		if(sac[ind].strt!=sac[ind].fin)
		{
			sac[psac].strt=sac[ind].strt;
			sac[psac].fin=sac[ind].fin;
			psac++;
		}
	}
	stpt=frmpnt->stpt=ind;
	if(wpar||frmpnt->at&FRMEND)
	{
		for(ind=0;ind<mapsiz;ind++)
			chkmap[ind]=0;
		if(frmpnt->at&FRMEND)
		{
			setchk(0);
			setchk(1);
		}
		if(wpar)
		{
			setchk(wpar);
			setchk(wpar+1);
		}
		ine=0;
		for(ind=0;ind<stpt;ind++)
		{
			if(chkchk(sac[ind].strt)&&chkchk(sac[ind].fin))
			{
				spnt[ine].strt=sac[ind].strt;
				spnt[ine].fin=sac[ind].fin;
				ine++;
			}
		}
		stpt=frmpnt->stpt=ine;
		if(wpar)
		{
			ine=0;
			for(ind=0;ind<stpt;ind++)
			{
				if(sac[ind].strt<wpar)
				{
					spnt[ine].strt=sac[ind].strt;
					spnt[ine++].fin=sac[ind].fin;
				}
			}
			stpt=frmpnt->stpt=ine;
		}
	}
	else
	{
		for(ind=0;ind<stpt;ind++)
		{
			spnt[ind].strt=sac[ind].strt;
			spnt[ind].fin=sac[ind].fin;
		}
	}
	if(stpt)
	{
		for(ind=0;ind<mapsiz;ind++)
			chkmap[ind]=0;
		for(ind=0;ind<stpt;ind++)
		{
			ine=sac[ind].strt;
			if(ine>(unsigned)wpar-1)
				ine=wpar-1;
			if(setchk(ine))
			{
				inf=ine;
				if(inf)
					inf--;
				while(!chkchk(ine)&&ine<(unsigned)wpar-1)
					ine++;
				while(inf&&(!chkchk(inf)))
					inf--;
				if(!chkchk(ine)&&!chkchk(inf))
					break;
				if(chkchk(ine)&&chkchk(inf))
				{
					if(ine-sac[ind].strt>sac[ind].strt-inf)
						setchk(inf);
					else
						setchk(ine);
				}
				else{

					if(chkchk(ine))
						setchk(inf);
					else
						setchk(ine);
				}

			}
		}
		inf=0;
		for(ind=0;ind<mapsiz;ind++)
		{
			do
			{
				ine=nxtchk(ind);
				if(ine<sids)
					sac[inf++].strt=ine+(ind<<5);
			}while(ine<sids);
		}
		stpt=frmpnt->stpt=inf;
		for(ind=0;ind<mapsiz;ind++)
			chkmap[ind]=0;
		for(ind=0;ind<stpt;ind++)
		{
			ine=inf=sac[ind].fin;
			if(ine>(unsigned)sids-1)
				ine=sids-1;
			if(setchk(ine))
			{
				if(ine<(unsigned)sids-1)
					ine++;
				if(inf>(unsigned)wpar+1)
					inf--;
				while(!chkchk(ine)&&ine<(unsigned)sids-1)
					ine++;
				while(inf>(unsigned)wpar-1&&(!chkchk(inf)))
					inf--;
				if(!chkchk(ine)&&!chkchk(inf))
					break;
				if(chkchk(ine)&&chkchk(inf))
				{
					if(ine-sac[ind].fin>sac[ind].fin-inf)
						setchk(inf);
					else
						setchk(ine);
				}
				else
				{
					if(chkchk(ine))
						setchk(ine);
					else
						setchk(inf);
				}
			}
		}
		inf=0;
		for(ind=mapsiz-1;ind<mapsiz;ind--)
		{
			do
			{
				ine=prvchk(ind);
				if(ine<sids)
					sac[inf++].fin=ine+(ind<<5);
			}while(ine<sids);
		}
		if(inf<stpt)
			inf=stpt;
		stpt=frmpnt->stpt=inf;
		if(wpar)
		{
			if(stpt>sids-wpar-2)
				stpt=sids-wpar-2;
			if(stpt>wpar-2)
				stpt=wpar-2;
			frmpnt->stpt=stpt;
		}
	}
	if(frmpnt->stpt<bstpt)
	{
		ine=bstpt-stpt;
		spnt=dpnt=frmpnt->sacang.sac;
		dpnt+=frmpnt->stpt;
		spnt+=bstpt;
		MoveMemory(dpnt,spnt,sizeof(SATCON)*(&satks[satkad]-spnt+1));
		for(ind=clofind+1;ind<formpnt;ind++)
		{
			fp=&formlst[ind];
			if(fp->typ==SAT)
				fp->sacang.sac-=ine;
		}
		satkad-=ine;
	}
}

void satclos(){

	unsigned	ind,clos,psac;
	double		dx,dy,tlen,len=1e99;
	SATCON*		tsac;

	uninsf();
	px2stch();
	psac=frmpnt->stpt;
	tsac=frmpnt->sacang.sac;
	clos=xstrt;
	for(ind=0;ind<frmpnt->sids;ind++){

		dx=sPnt.x-frmpnt->flt[ind].x;
		dy=sPnt.y-frmpnt->flt[ind].y;
		tlen=hypot(dx,dy);
		if(tlen<len){

			len=tlen;
			clofine=ind;
		}
	}
	rstMap(SATCNKT);
	if(frmpnt->typ==LIN){

		frmpnt->ftyp=CONTF;
		clos=clofine;
		if(xstrt>clos){

			psac=clos;
			clos=xstrt;
			xstrt=psac;
		}
		if(!xstrt)
			xstrt++;
		if(xstrt==frmpnt->sids-2&&clos==(unsigned)frmpnt->sids-1){

			xstrt=1;
			clos=frmpnt->sids-2;
		}
		if(clos>=(unsigned)frmpnt->sids-2){

			clos=frmpnt->sids-2;
			if(xstrt>=(unsigned)frmpnt->sids-2)
				xstrt=frmpnt->sids-2;
		}
		if(clos-xstrt<2){

			clos=xstrt+2;
			if(clos>(unsigned)frmpnt->sids-2){

				clos=clos-frmpnt->sids-2;
				clos-=clos;
				xstrt-=clos;
			}
		}
		frmpnt->angclp.sat.strt=xstrt;
		frmpnt->angclp.sat.fin=clos;
	}
	else{

		if(clofine<clos){

			ind=clofine;
			clofine=clos;
			clos=ind;
		}
		if(clos==0&&clofine==(unsigned)sids-1){

			clos=sids-1;
			clofine=sids;
		}
		if(clos==1&&clofine==(unsigned)sids){

			clos=0;
			clofine=1;
		}
		if(clofine-clos==1){

			if(frmpnt->at&FRMEND)
				frmpnt->wpar=clos;
			else{

				if(clos)
					rotfrm(clos);
				frmpnt->at|=FRMEND;
			}
			satadj();
		}
		else{
		
			if(stpt){

				sacspac(&frmpnt->sacang.sac[frmpnt->stpt],1);
				frmpnt->sacang.sac[frmpnt->stpt].strt=clos;
				frmpnt->sacang.sac[frmpnt->stpt++].fin=clofine;
				satadj();
			}
			else{
			
				frmpnt->sacang.sac=nusac(clofind,1);
				frmpnt->sacang.sac[psac].strt=clos;
				frmpnt->sacang.sac[psac].fin=clofine;
				frmpnt->stpt=1;
			}
		}
	}
}

void satknkt(){

	satclos();
	fvars(clofind);
	refil();
	setMap(RESTCH);
}

void ritseq1(unsigned ind){

	bseq[seqpnt].x=flt[ind].x;
	bseq[seqpnt].y=flt[ind].y;
	seqpnt++;
}

void satfn(unsigned astrt,unsigned afin,unsigned bstrt,unsigned bfin){

	unsigned	anxt,bprv,cnt,ind,acnt,bcnt,ine,inf,tcnt,acind,bcind,pacnt=0,pbcnt=0;
	unsigned	asegs,bsegs;
	unsigned*	acnts;
	unsigned*	bcnts;
	double		alen,blen;
	DUBPNT		apnt,bpnt,adif,bdif,astp,bstp;

	if(astrt!=afin&&bstrt!=bfin){

		if(!setMap(SAT1)){

			if(chkMap(FTHR)){

				bseq[seqpnt].attr=0;
				ritseq1(astrt%sids);
			}
			else{

				if(chkMap(BARSAT)){

					ritseq1(astrt%sids);
					ritseq1(bstrt%sids);
				}
				else{

					sPnt.x=flt[astrt].x;
					sPnt.y=flt[astrt].y;
					oseq[seqpnt].x=sPnt.x;
					oseq[seqpnt++].y=sPnt.y;
				}
			}
		}
		alen=lens[afin]-lens[astrt];
		blen=lens[bstrt]-lens[bfin];
		if(fabs(alen)>fabs(blen))
			cnt=fabs(blen)/stspace;
		else
			cnt=fabs(alen)/stspace;
		asegs=abs(afin-astrt);
		bsegs=abs(bstrt-bfin);
		acnts=new unsigned[asegs];
		bcnts=new unsigned[bsegs];
		ine=astrt;
		tcnt=0;
		for(ind=0;ind<asegs-1;ind++){

			inf=nxt(ine);
			acnts[ind]=((lens[inf]-lens[ine])/alen)*cnt+0.5;
			tcnt+=acnts[ind];
			ine++;
		}
		acnts[ind]=cnt-tcnt;
		ind=bstrt;
		ine=prv(ind);
		inf=0;
		tcnt=0;
		while(ine>bfin){

			bcnts[inf]=((lens[ind]-lens[ine])/blen)*cnt+0.5;
			tcnt+=bcnts[inf++];
			ine=prv(--ind);
		}
		bcnts[inf]=cnt-tcnt;
		apnt.x=flt[astrt].x;
		apnt.y=flt[astrt].y;
		anxt=nxt(astrt);
		bprv=prv(bstrt);
		acnt=acnts[pacnt++];
		bcnt=bcnts[pbcnt++];
		acind=astrt;
		bcind=bstrt;
		adif.x=flt[anxt].x-flt[acind].x;
		adif.y=flt[anxt].y-flt[acind].y;
		if(bcind==sids){

			bdif.x=flt[bprv].x-flt[0].x;
			bdif.y=flt[bprv].y-flt[0].y;
			bpnt.x=flt[0].x;
			bpnt.y=flt[0].y;
		}
		else{

			bdif.x=flt[bprv].x-flt[bcind].x;
			bdif.y=flt[bprv].y-flt[bcind].y;
			bpnt.x=flt[bcind].x;
			bpnt.y=flt[bcind].y;
		}
		acind=nxt(acind);
		bcind=prv(bcind);
		astp.x=adif.x/acnt;
		astp.y=adif.y/acnt;
		bstp.x=bdif.x/bcnt;
		bstp.y=bdif.y/bcnt;
nuseg:;
	  
		if(chkMap(FTHR)){

			while(acnt&&bcnt){
				
				apnt.x+=astp.x;
				apnt.y+=astp.y;
				bpnt.x+=bstp.x;
				bpnt.y+=bstp.y;
				if(toglMap(FILDIR)){

					bseq[seqpnt].attr=0;
					bseq[seqpnt].x=apnt.x;
					bseq[seqpnt++].y=apnt.y;
				}
				else{

					bseq[seqpnt].attr=1;
					bseq[seqpnt].x=bpnt.x;
					bseq[seqpnt++].y=bpnt.y;
				}
				if(seqpnt>MAXSEQ-6){

					seqpnt=MAXSEQ-6;
					return;
				}
				acnt--;
				bcnt--;
			}
		}
		else{

			if(chkMap(BARSAT)){

				while(acnt&&bcnt){
					
					apnt.x+=astp.x;
					apnt.y+=astp.y;
					bpnt.x+=bstp.x;
					bpnt.y+=bstp.y;
					if(toglMap(FILDIR)){

						bseq[seqpnt].attr=0;
						bseq[seqpnt].x=apnt.x;
						bseq[seqpnt++].y=apnt.y;
						bseq[seqpnt].attr=1;
						bseq[seqpnt].x=bpnt.x;
						bseq[seqpnt++].y=bpnt.y;
					}
					else{

						bseq[seqpnt].attr=2;
						bseq[seqpnt].x=bpnt.x;
						bseq[seqpnt++].y=bpnt.y;
						bseq[seqpnt].attr=3;
						bseq[seqpnt].x=apnt.x;
						bseq[seqpnt++].y=apnt.y;
					}
					if(seqpnt>MAXSEQ-6){

						seqpnt=MAXSEQ-6;
						return;
					}
					acnt--;
					bcnt--;
				}
			}
			else{

				while(acnt&&bcnt){
					
					apnt.x+=astp.x;
					apnt.y+=astp.y;
					bpnt.x+=bstp.x;
					bpnt.y+=bstp.y;
					if(toglMap(FILDIR)){

						if(chku(SQRFIL))
							filinu(bpnt.x,bpnt.y);
						filin(apnt);
					}
					else{

						if(chku(SQRFIL))
							filinu(apnt.x,apnt.y);
						filin(bpnt);
					}
					acnt--;
					bcnt--;
				}
			}
		}
		if((pacnt<asegs||pbcnt<bsegs)){

			if(!acnt){

				acnt=acnts[pacnt++];
				anxt=nxt(acind);
				adif.x=flt[anxt].x-flt[acind].x;
				adif.y=flt[anxt].y-flt[acind].y;
				acind=nxt(acind);
				astp.x=adif.x/acnt;
				astp.y=adif.y/acnt;
			}
			if(!bcnt){

				bcnt=bcnts[pbcnt++];
				bprv=prv(bcind);
				bdif.x=flt[bprv].x-flt[bcind].x;
				bdif.y=flt[bprv].y-flt[bcind].y;
				bcind=prv(bcind);
				bstp.x=bdif.x/bcnt;
				bstp.y=bdif.y/bcnt;
			}
			if((acnt||bcnt)&&acnt<MAXSEQ&&bcnt<MAXSEQ)
				goto nuseg;
		}
		delete acnts;
		delete bcnts;
	}
}

void satmf(){

	unsigned	ind,ine;
	double		len,dx,dy;

	ind=0;
	if(frmpnt->at&FRMEND)
		ind=1;
	satfn(ind,sac[0].strt,sids,sac[0].fin);
	for(ind=0;ind<(unsigned)stpt-1;ind++)
		satfn(sac[ind].strt,sac[ind+1].strt,sac[ind].fin,sac[ind+1].fin);
	if(wpar)
		satfn(sac[ind].strt,wpar,sac[ind].fin,wpar+1);
	else{

		if(sac[ind].fin-sac[ind].strt>2){

			len=(lens[sac[ind].fin]-lens[sac[ind].strt])/2+lens[sac[ind].strt];
			ine=sac[ind].strt;
			while(len>lens[ine])
				ine++;
			dx=lens[ine]-len;
			dy=len-lens[ine-1];
			if(dy>dx)
				ine--;
			satfn(sac[ind].strt,ine,sac[ind].fin,ine);
		}
		else
			satfn(sac[ind].strt,sac[ind].strt+1,sac[ind].fin,sac[ind].strt+1);
	}
}

extern void prbug();

void satfil(){

	unsigned		ind;
	double			len,dx,dy;
	double			tspac;

	fvars(clofind);
	satadj();
	tspac=stspace;
	stspace/=2;
	seqpnt=0;
	rstMap(SAT1);
	rstMap(FILDIR);
	frmpnt->ftyp=SATF;
	lens=new double[sids+1];
	len=0;
	for(ind=0;ind<(unsigned)sids-1;ind++){

		lens[ind]=len;
		dx=flt[ind+1].x-flt[ind].x;
		dy=flt[ind+1].y-flt[ind].y;
		len+=hypot(dx,dy);
	}
	lens[ind]=len;
	dx=flt[0].x-flt[ind].x;
	dy=flt[0].y-flt[ind].y;
	len+=hypot(dx,dy);
	lens[ind+1]=len;
	if(wpar){

		if(stpt){

			satmf();
			goto satdun;
		}
		else{

			satfn(1,wpar,sids,wpar+1);
			goto satdun;
		}
	}
	if(frmpnt->at&FRMEND){

		if(stpt){

			satmf();
			goto satdun;
		}
		else{

			if(sids==3&&formlst[clofind].at&1){

				satfn(2,3,2,1);
				goto satdun;
			}
			else{

				len=(len-lens[1])/2;
				ind=1;
				if(!chkMap(BARSAT)){

					oseq[0].x=sPnt.x=flt[1].x;
					oseq[0].y=sPnt.y=flt[1].y;
					seqpnt=1;
				}
				while(len>lens[ind])
					ind++;
				dx=lens[ind]-len;
				dy=len-lens[ind-1];
				if(dy>dx)
					ind--;
				satfn(1,ind,sids,ind);
			}
			goto satdun;
		}
	}
	if(stpt){

		satmf();
		goto satdun;
	}
	len/=2;
	ind=0;
	if(!chkMap(BARSAT)&&!chkMap(FTHR)){

		oseq[0].x=sPnt.x=flt[0].x;
		oseq[0].y=sPnt.y=flt[0].y;
		seqpnt=1;
	}
	while(len>lens[ind])
		ind++;
	dx=lens[ind]-len;
	dy=len-lens[ind-1];
	if(dy>dx)
		ind--;
	satfn(0,ind,sids,ind);
satdun:;

	delete lens;
	stspace=tspac;
}

void filsfn(){

	delmclp(clofind);
	deltx();
	frmpnt->typ=SAT;
	fsizpar();
	frmpnt->ftyp=SATF;
	frmpnt->fcol=actcol;
	frmpnt->fspac=stspace;
	frmpnt->typ=SAT;
	refilfn();
}

void filsat(){

	unsigned ind;

	if(filmsgs(FMM_FAN))
		return;
	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			if(frmpnt->typ!=LIN)
				filsfn();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			filsfn();
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
	}
}

unsigned closat(){

	unsigned	ind,ine;
	double		len=1e99,tlen,dx,dy;

	px2stch();
	for(ind=0;ind<formpnt;ind++){

		if(!actl||(unsigned)((formlst[ind].at&FRMLMSK)>>1)==actl||!(formlst[ind].at&FRMLMSK)){

			flt=formlst[ind].flt;
			for(ine=0;ine<formlst[ind].sids;ine++){

				dx=sPnt.x-flt[ine].x;
				dy=sPnt.y-flt[ine].y;
				tlen=hypot(dx,dy);
				if(tlen<len){

					len=tlen;
					clofind=ind;
					clofine=ine;
				}
			}
		}
	}
	if(len==1e99)
		return 0;
	else
		return 1;
}

void nufpnt(unsigned pnu){

	unsigned ind;

	pnu++;
	fltspac(&finspnt->flt[pnu],1);
	finspnt->flt[pnu].x=sPnt.x;
	finspnt->flt[pnu].y=sPnt.y;
	finspnt->sids++;
	for(ind=0;ind<finspnt->stpt;ind++){

		if(finspnt->sacang.sac[ind].strt>pnu-1)
			finspnt->sacang.sac[ind].strt++;
		if(finspnt->sacang.sac[ind].fin>pnu-1)
			finspnt->sacang.sac[ind].fin++;
	}
	if(finspnt->wpar>=pnu){

		finspnt->wpar++;
		finspnt->wpar%=sids;
	}
	if(finspnt->ftyp==CONTF){

		if(finspnt->angclp.sat.strt>pnu-1)
			finspnt->angclp.sat.strt++;
		if(finspnt->angclp.sat.fin>pnu-1)
			finspnt->angclp.sat.fin++;
	}
	frmlin(finspnt->flt,finspnt->sids);
}

double p2p(FLPNT pnt0,FLPNT pnt1){

	return hypot(pnt0.x-pnt1.x,pnt0.y-pnt1.y);
}

unsigned upsat(){

	unsigned	ind;
	double		dwnlen,uplen,p2clos,p2up,p2dwn;

	sids=finspnt->sids;
	flt=finspnt->flt;
	p2clos=p2p(sPnt,flt[clofine]);
	ind=prv(clofine);
	dwnlen=p2p(flt[ind],flt[clofine]);
	p2dwn=p2p(flt[ind],sPnt);
	ind=nxt(clofine);
	uplen=p2p(flt[ind],flt[clofine]);
	p2up=p2p(flt[ind],sPnt);
	if((p2dwn+p2clos)/dwnlen>(p2up+p2clos)/uplen)
		return 0;
	else{

		return 1;
	}
}

void insat(){

	if(closat()){

		savdo();
		frmpnt=&formlst[clofind];
		finspnt=frmpnt;
		fvars(clofind);
		if(upsat()){

			if(!clofine&&finspnt->typ==LIN)
				setMap(PRELIN);
			else
				clofine=prv(clofine);
			nufpnt(clofine);
			if(rstMap(PRELIN)){

				sPnt.x=finspnt->flt[0].x;
				sPnt.y=finspnt->flt[0].y;
				finspnt->flt[0].x=finspnt->flt[1].x;
				finspnt->flt[0].y=finspnt->flt[1].y;
				finspnt->flt[1].x=sPnt.x;
				finspnt->flt[1].y=sPnt.y;
			}
		}
		else
			nufpnt(clofine);
		refil();
	}
	setMap(RESTCH);
}

BOOL chkdel(){

	if(frmpnt->typ==LIN){

		if(frmpnt->sids>2)
			return 0;
		else
			return 1;
	}
	else{

		if(frmpnt->sids>3)
			return 0;
		else
			return 1;
	}
}

void delspnt(){

	unsigned	ind,ine;
	SATCON*		sac;
	FLPNT*		tflt;
	FRMHED*	fp;

	fvars(clofind);
	if(chkdel()){

		setMap(DELTO);
		frmdel();
		rstMap(FRMPSEL);
		coltab();
		setMap(RESTCH);
		return;
	}
	if(frmpnt->typ==SAT){
	
		if(clofine<frmpnt->wpar)
			frmpnt->wpar--;
		if(frmpnt->stpt){

			sac=frmpnt->sacang.sac;
			ind=0;
			while(sac[ind].strt!=clofine&&sac[ind].fin!=clofine&&ind<frmpnt->stpt)
				ind++;
			if(ind<frmpnt->stpt&&(sac[ind].strt==clofine||sac[ind].fin==clofine)){

				while(ind<frmpnt->stpt){

					sac[ind].strt=sac[ind+1].strt;
					sac[ind].fin=sac[ind+1].fin;
					ind++;
				}
				frmpnt->stpt--;
				satkad--;
				for(ine=clofind+1;ine<formpnt;ine++)
				{
					fp=&formlst[ine];
					if(fp->typ==SAT&&fp->stpt)
						fp->sacang.sac++;
				}
			}
			for(ind=0;ind<frmpnt->stpt;ind++){

				if(sac[ind].strt>clofine)
					sac[ind].strt--;
				if(sac[ind].fin>clofine)
					sac[ind].fin--;
			}
		}
	}
	MoveMemory(&frmpnt->flt[clofine],&frmpnt->flt[clofine+1],(fltad-clofine)*sizeof(SHRTPNT));
	frmpnt->sids--;
	fltad--;
	fvars(clofind);
	if(clofine>(unsigned)frmpnt->sids-1)
		clofine=frmpnt->sids-1;
	setMap(FRMPSEL);
	for(ind=clofind+1;ind<formpnt;ind++)
		formlst[ind].flt--;
	ritfcor(&flt[clofine]);
	ritnum(STR_NUMPNT,clofine);
	frmout(clofind);
	tflt=&frmpnt->flt[clofine];
	if(tflt->x<zRct.left||tflt->x>zRct.right||tflt->y<zRct.bottom||tflt->y>zRct.top)
		shft(frmpnt->flt[clofine]);
	refil();
}

void unfil(){

	unsigned src,dst,trg,at;
	unsigned mlen;

	if(filmsgs(FMX_UNF))
		return;
	if(fselpnt){

		mlen=(fselpnt>>5)+1;
		for(src=0;src<mlen;src++)
			rmap[src]=0;
		for(src=0;src<fselpnt;src++){

			frmpnt=&formlst[selist[src]];
			if(frmpnt->ftyp||frmpnt->etyp){

				delclps(selist[src]);
				deltx();
				setr(selist[src]);
				frmpnt->ftyp=0;
				frmpnt->etyp=0;
				frmpnt->xat&=!(AT_UND|AT_CWLK|AT_WALK);
			}
		}
		dst=0;
		for(src=0;src<hed.stchs;src++){

			if(!chkr((stchs[src].at&FRMSK)>>FRMSHFT)){

				stchs[dst].at=stchs[src].at;
				stchs[dst].x=stchs[src].x;
				stchs[dst++].y=stchs[src].y;
			}
		}
		hed.stchs=dst;
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			if(!rstMap(IGNOR)&&!chku(WRNOF)){

				trg=(clofind<<FRMSHFT)|USMSK;
				mlen=stchs[0].at&(FRMSK|USMSK);
				for(src=0;src<hed.stchs;src++){

					at=stchs[src].at;
					if(!(at&NOTFRM)&&(at&(USMSK|FRMSK))==trg){

						tabmsg(IDS_UNFIL);
						setMap(FILMSG);
						okcan();
						setMap(IGNOR);
						bakpnt.x=msg.pt.x;
						bakpnt.y=msg.pt.y;
						return;
					}
				}
			}
			trg=clofind<<FRMSHFT;
			dst=0;
			for(src=0;src<hed.stchs;src++){

				if((stchs[src].at&FRMSK)!=trg||(stchs[src].at&NOTFRM)){

					stchs[dst].at=stchs[src].at;
					stchs[dst].x=stchs[src].x;
					stchs[dst++].y=stchs[src].y;
				}
			}
			delclps(clofind);
			deltx();
			frmpnt->ftyp=0;
			frmpnt->etyp=0;
			frmpnt->xat&=!(AT_UND|AT_CWLK|AT_WALK);
			hed.stchs=dst;
			ritot(hed.stchs);
		}
	}
}

void satzum(){

	rstMap(SHOSAT);
	duzrat();
	sids=satpt;
	frmlin(tpoly,satpt);
	SetROP2(sdc,R2_XORPEN);
	SelectObject(sdc,fPen);
	Polyline(sdc,flin,satpt);
	SetROP2(sdc,R2_COPYPEN);
	drwsat();	
}

void rotfrm(unsigned nu0){

	FLPNT*			flt0;
	FLPNT*			flt1;
	SATCON*			nsac;
	SATCON**		psac;
	unsigned		ind,ine,xpnt=nu0;
	unsigned short	tlin;

	fvars(clofind);
	flt0=frmpnt->flt;
	sids=frmpnt->sids;
	flt1=new FLPNT[sids];
	for(ind=0;ind<sids;ind++){

		flt1[ind].x=flt0[ind].x;
		flt1[ind].y=flt0[ind].y;
	}
	for(ind=0;ind<sids;ind++){

		flt0[ind].x=flt1[xpnt].x;
		flt0[ind].y=flt1[xpnt].y;
		xpnt=nxt(xpnt);
	}
	ine=0;
	if(frmpnt->typ==SAT){

		if(frmpnt->wpar)
			frmpnt->wpar=(frmpnt->wpar+frmpnt->sids
				-nu0)%frmpnt->sids;
		for(ind=0;ind<frmpnt->stpt;ind++){

			if(sac[ind].strt!=nu0&&sac[ind].fin!=nu0){

				sac[ine].strt=(sac[ind].strt+sids-nu0)%sids;
				sac[ine].fin=(sac[ind].fin+sids-nu0)%sids;
				if(sac[ine].strt>sac[ine].fin){

					tlin=sac[ine].strt;
					sac[ine].strt=sac[ine].fin;
					sac[ind].fin=tlin;
				}
				ine++;
			}
		}
	}
	frmpnt->stpt=ine;
	psac=new SATCON*[ine];
	nsac=new SATCON[ine];
	for(ind=0;ind<ine;ind++){

		psac[ind]=&nsac[ind];
		nsac[ind].strt=sac[ind].strt;
		nsac[ind].fin=sac[ind].fin;
	}
	qsort((void*)psac,ine,4,scomp);
	for(ind=0;ind<ine;ind++){

		sac[ind].strt=psac[ind]->strt;
		sac[ind].fin=psac[ind]->fin;
	}
	if(frmpnt->xat&AT_STRT)
		frmpnt->strt=(frmpnt->strt+sids-nu0)%sids;
	if(frmpnt->xat&AT_END)
		frmpnt->end=(frmpnt->end+sids-nu0)%sids;
	delete flt1;
	delete nsac;
	delete psac;
}


void frm0(){

	if(chkMap(FRMPSEL)){

		savdo();
		rotfrm(clofine);
		clofine=0;
		satadj();
		refil();
		coltab();
		setMap(RESTCH);
	}
}

void duinsf(){

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	Polyline(rsdc,inlin,2);	
	SetROP2(rsdc,R2_COPYPEN);
}

void uninsf(){

	if(rstMap(SHOINSF))
		duinsf();
}

void rinfrm(){

	frmlin(finspnt->flt,finspnt->sids);
	SelectObject(sdc,fPen);
	SetROP2(sdc,R2_XORPEN);
	if(fgpnt1||finspnt->typ!=LIN)
		Polyline(sdc,&flin[fgpnt0],2);
	inlin[0].x=flin[fgpnt0].x;
	inlin[0].y=flin[fgpnt0].y;
	inlin[1].x=msg.pt.x-stOrg.x;
	inlin[1].y=msg.pt.y-stOrg.y;
	setMap(SHOINSF);
	duinsf();
}

void infrm(){

	if(closat()){

		finspnt=&formlst[clofind];
		fvars(clofind);
		if(upsat()){

			if(!clofine&&finspnt->typ==LIN){

				fgpnt0=0;
				setMap(PRELIN);
			}
			else{

				fgpnt0=prv(clofine);
				fgpnt1=clofine;
			}
		}
		else{
			
			fgpnt0=clofine;
			fgpnt1=nxt(clofine);
		}
		setMap(INSFRM);
		setMap(INIT);
		rinfrm();
	}
}

void setins(){

	px2stch();
	nufpnt(fgpnt0);
	if(chkMap(PRELIN)){

		sPnt.x=finspnt->flt[0].x;
		sPnt.y=finspnt->flt[0].y;
		finspnt->flt[0].x=finspnt->flt[1].x;
		finspnt->flt[0].y=finspnt->flt[1].y;
		finspnt->flt[1].x=sPnt.x;
		finspnt->flt[1].y=sPnt.y;
	}
	else{

		sids=finspnt->sids;
		fgpnt0=nxt(fgpnt0);
		fgpnt1=nxt(fgpnt0);
	}
	frmlin(finspnt->flt,finspnt->sids);
	inlin[0].x=flin[fgpnt0].x;
	inlin[0].y=flin[fgpnt0].y;
	inlin[1].x=msg.pt.x-stOrg.x;
	inlin[1].y=msg.pt.y-stOrg.y;
	setMap(INSFRM);
	duinsf();
	setMap(RESTCH);
}

void bdrlin(unsigned strt,unsigned fin,double siz){

	DUBPNT		dif,stp,pnt;
	double		len,tang;
	unsigned	cnt;

	dif.x=flt[fin].x-flt[strt].x;
	dif.y=flt[fin].y-flt[strt].y;
	len=hypot(dif.x,dif.y);
	if(chku(LINSPAC)){

		cnt=len/siz+0.5;
		if(cnt){

			stp.x=dif.x/cnt;
			stp.y=dif.y/cnt;
		}
	}
	else{

		cnt=(len-siz/2)/siz+1;
		tang=atan2(dif.y,dif.x);
		stp.x=cos(tang)*siz;
		stp.y=sin(tang)*siz;
	}
	if(cnt){

		pnt.x=flt[strt].x+stp.x;
		pnt.y=flt[strt].y+stp.y;
		cnt--;
		while(cnt){

			oseq[seqpnt].x=pnt.x;
			oseq[seqpnt++].y=pnt.y;
			pnt.x+=stp.x;
			pnt.y+=stp.y;
			cnt--;
		}
	}
	oseq[seqpnt].x=flt[fin].x;
	oseq[seqpnt++].y=flt[fin].y;
}

void brdfil(double siz){

	unsigned		ind;
	unsigned short	nlin,tlin;

	if(frmpnt->xat&AT_STRT)
		tlin=frmpnt->strt;
	else
		tlin=getlast();
	seqpnt=0;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	for(ind=0;ind<(unsigned)sids-1;ind++){
		
		nlin=nxt(tlin);
		bdrlin(tlin,nlin,siz);
		tlin=nlin;
	}
	if(frmpnt->typ!=LIN){

		nlin=nxt(tlin);
		bdrlin(tlin,nlin,siz);
	}
}

void bsizpar(){

	frmpnt->emax=ini.maxsiz;
	frmpnt->elen=usesiz;
	frmpnt->emin=minsiz;
}

void sbord(){

	fvars(clofind);
	deleclp(clofind);
	frmpnt->etyp=EGLIN;
	bsizpar();
	refilfn();
}

void bord(){

	unsigned ind;

	if(filmsgs(FML_LIN))
		return;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			frmpnt->bcol=actcol;
			sbord();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			frmpnt->bcol=actcol;
			sbord();
			coltab();
			setMap(INIT);
			setMap(RESTCH);
		}
	}
}

BOOL ritclp(FLPNT pnt){

	FLPNT		adj;
	unsigned	ind;

	if(chkmax(clplen,seqpnt))
		return 1;
	adj.x=pnt.x-clpref.x;
	adj.y=pnt.y-clpref.y;
	for(ind=0;ind<clplen;ind++){

		oseq[seqpnt].x=filclp[ind].x+adj.x;
		oseq[seqpnt++].y=filclp[ind].y+adj.y;
	}
	return 0;
}

BOOL clpsid(unsigned strt,unsigned fin){

	unsigned		ind,cnt;
	FLPNT			dif,stp,pnt;
	double			len,tdub;
	SHRTPNT			rpnt;

	rpnt.x=clprct.left;
	rpnt.y=clprct.bottom;
	pnt.x=flt[strt].x;
	pnt.y=flt[fin].y;
	dif.x=flt[fin].x-flt[strt].x;
	dif.y=flt[fin].y-flt[strt].y;
	len=hypot(dif.x,dif.y);
	ang=atan2(dif.y,dif.x);
	rotang1(rpnt,&clpref);
	cnt=len/clpsiz.cx;
	if(cnt){

		if(cnt>1)
			tdub=((len-cnt*clpsiz.cx)/(cnt-1)+clpsiz.cx)/len;
		else
			tdub=(len-clpsiz.cx)/2;
		stp.x=dif.x*tdub;
		stp.y=dif.y*tdub;
		pnt.x=flt[strt].x;
		pnt.y=flt[strt].y;
		ang=atan2(dif.y,dif.x);
		for(ind=0;ind<clplen;ind++)
			rotangf(clprev[ind],&filclp[ind]);
		for(ind=0;ind<cnt;ind++){

			if(ritclp(pnt))
				break;
			pnt.x+=stp.x;
			pnt.y+=stp.y;
		}
		return 1;
	}
	return 0;
}

void linsid(){

	FLPNT		dif;
	unsigned	cnt,ind;
	double		len;

	dif.x=flt[clpstrt+1].x-sPnt.x;
	dif.y=flt[clpstrt+1].y-sPnt.y;
	len=hypot(dif.x,dif.y);
	cnt=len/clpsiz.cx;
	if(cnt){

		ang=clpang;
		rotangf(rclpref,&clpref);
		for(ind=0;ind<clplen;ind++)
			rotangf(clprev[ind],&filclp[ind]);
		for(ind=0;ind<cnt;ind++){

			ritclp(sPnt);
			sPnt.x+=vct0.x;
			sPnt.y+=vct0.y;
		}
	}
}

BOOL nupnt(){

	double		len,dif;
	unsigned	ind;
	
	mvpnt.x=flt[clpstrt+2].x;
	mvpnt.y=flt[clpstrt+2].y;
	len=hypot(mvpnt.x-sPnt.x,mvpnt.y-sPnt.y);
	if(len>clpsiz.cx){

		for(ind=0;ind<10;ind++){

			len=hypot(mvpnt.x-sPnt.x,mvpnt.y-sPnt.y);
			dif=clpsiz.cx-len;
			mvpnt.x+=dif*cosang;
			mvpnt.y+=dif*sinang;
			if(fabs(dif)<0.01)
				break;
		}
		return 1;
	}
	return 0;
}

void lincrnr(){

	DUBPNT		dif;
	unsigned	ind;

	sinang=sin(clpang);
	cosang=cos(clpang);
	if(nupnt()){

		dif.x=mvpnt.x-sPnt.x;
		dif.y=mvpnt.y-sPnt.y;
		ang=atan2(dif.y,dif.x);
		rotangf(rclpref,&clpref);
		for(ind=0;ind<clplen;ind++)
			rotangf(clprev[ind],&filclp[ind]);
		ritclp(sPnt);
		sPnt.x=mvpnt.x;
		sPnt.y=mvpnt.y;
	}
}

void durev(){

	unsigned	ind;
	double		mid;

	mid=(clprct.right-clprct.left)/2+clprct.left;
	if(clpnu[0].x>mid){

		for(ind=0;ind<clplen;ind++){

			clprev[ind].x=clprct.right-clpnu[ind].x;
			clprev[ind].y=clpnu[ind].y;
		}
	}
	else{

		for(ind=0;ind<clplen;ind++){

			clprev[ind].x=clpnu[ind].x;
			clprev[ind].y=clpnu[ind].y;
		}
	}
}

void setvct(unsigned strt,unsigned fin){

	clpang=atan2(flt[fin].y-flt[strt].y,flt[fin].x-flt[strt].x);
	vct0.x=clpsiz.cx*cos(clpang);
	vct0.y=clpsiz.cx*sin(clpang);
}

void clpbrd(unsigned short strtlin){

	unsigned		ind,ref;
	unsigned short	nlin;

	bac=0;
	seqpnt=0;
	rstMap(CLPBAK);
	plen=clpsiz.cx/2;
	plen2=clpsiz.cx;
	filclp=new FLPNT[clplen];
	clprev=new FLPNT[clplen];
	rotcntr.x=(clprct.right-clprct.left)/2+clprct.left;
	clpref.y=rotcntr.y=(clprct.top-clprct.bottom)/2+clprct.bottom;
	clpref.x=clprct.left;
	durev();
	ref=0;
	if(frmpnt->typ==LIN){

		sPnt.x=flt[0].x;
		sPnt.y=flt[0].y;
		setvct(0,1);
		rclpref.y=(clprct.top-clprct.bottom)/2+clprct.bottom;
		rclpref.x=(clprct.top=clprct.left)/2+clprct.left;
		for(clpstrt=0;clpstrt<(unsigned)sids-2;clpstrt++){

			linsid();
			setvct(clpstrt+1,clpstrt+2);
			lincrnr();
		}
		linsid();
	}
	else{

		clpout();
		ref=strtlin;
		for(ind=0;ind<sids;ind++){

			nlin=prv(strtlin);
			if(clpsid(ref,nlin))
				ref=nlin;
			strtlin=nlin;
		}
	}
	delete filclp;
	delete clprev;
}

void outfn(unsigned strt,unsigned fin,double satwid){

	double		ang;
	double		len;
	double		xof,yof;

	if(fabs(angs[strt])<TINY&&fabs(angs[fin])<TINY){

		xof=0;
		yof=satwid;
	}
	else{

#define SATHRESH 10

		ang=(angs[fin]-angs[strt])/2;
		len=satwid/cos(ang);
		if(len<-satwid*SATHRESH)
			len=-satwid*SATHRESH;
		if(len>satwid*SATHRESH)
			len=satwid*SATHRESH;
		ang+=angs[strt]+PI/2;
		xof=len*cos(ang);
		yof=len*sin(ang);
	}
	ipnts[fin].x=flt[fin].x-xof;
	ipnts[fin].y=flt[fin].y-yof;
	opnts[fin].x=flt[fin].x+xof;
	opnts[fin].y=flt[fin].y+yof;
}

void duangs(){

	unsigned ind;

	for(ind=0;ind<(unsigned)sids-1;ind++)
		angs[ind]=atan2(flt[ind+1].y-flt[ind].y,flt[ind+1].x-flt[ind].x);
	angs[ind]=atan2(flt[0].y-flt[ind].y,flt[0].x-flt[ind].x);
}

void satout(double satwid){

	unsigned	ind;
	unsigned	cnt;

	if(sids){

		duangs();
		opnts=opntlst;
		ipnts=ipntlst;
		for(ind=0;ind<(unsigned)sids-1;ind++)
			outfn(ind,ind+1,0.1);
		cnt=0;
		for(ind=0;ind<sids;ind++)
		{
			if(cisin(ipnts[ind].x,ipnts[ind].y))
				cnt++;
		}
		satwid/=2;
		for(ind=0;ind<(unsigned)sids-1;ind++)
			outfn(ind,ind+1,satwid);
		outfn(ind,0,satwid);
		rstMap(INDIR);
		if(cnt<(unsigned)sids>>1)
		{
			setMap(INDIR);
			opnts=ipntlst;
			ipnts=opntlst;
		}
	}
//	bugdraw
/*	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	frmlin(opnts,sids);
	Polyline(rsdc,flin,sids+1);
	frmlin(ipnts,sids);
	Polyline(rsdc,flin,sids+1);
	SetROP2(rsdc,R2_COPYPEN);
	_asm nop;*/
}

void clpout(){

	if(frmpnt->typ==LIN)
		satout(plen);
	else{
			
		satout(clpsiz.cy);
		ipnts=frmpnt->flt;
	}
}

void fsclp(){

	unsigned	ind;

	deleclp(clofind);
	frmpnt->etyp=EGCLP;
	frmpnt->nclp=clplen;
	frmpnt->clp=nueclp(clofind,clplen);
	frmpnt->esiz=clpsiz.cy;
	frmpnt->espac=clpsiz.cx;
	frmpnt->bcol=actcol;
	bsizpar();
	for(ind=0;ind<clplen;ind++){

		frmpnt->clp[ind].x=clpnu[ind].x;
		frmpnt->clp[ind].y=clpnu[ind].y;
	}
	plen=clpsiz.cy/2;
	clpout();
	refilfn();
}

void fclp(){

	unsigned ind;

	if(filmsgs(FML_CLP))
		return;
	if(OpenClipboard(hWnd)){

		fvars(clofind);
		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			savdo();
			redclp();
			CloseClipboard();
			if(clpsiz.cx>CLPMIN){

				if(fselpnt){

					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						fsclp();
					}
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						fsclp();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else
			CloseClipboard();
	}
}

void filinsb(DUBPNT pnt){

	double		len;
	DUBPNT		dif,stp;
	unsigned	cnt;

	dif.x=pnt.x-sPnt.x;
	dif.y=pnt.y-sPnt.y;
	len=hypot(dif.x,dif.y);
	if(len>MAXSTCH){

		cnt=len/MAXSTCH+1;
		stp.x=dif.x/cnt;
		stp.y=dif.y/cnt;
		cnt--;
		if(chkmax(cnt,seqpnt))
			return;
		while(cnt){

			sPnt.x+=stp.x;
			sPnt.y+=stp.y;
			oseq[seqpnt].x=sPnt.x;
			oseq[seqpnt++].y=sPnt.y;
			cnt--;
		}
	}
	if(seqpnt&0xffff0000)
		return;
	oseq[seqpnt].x=pnt.x;
	oseq[seqpnt++].y=pnt.y;
	sPnt.x=pnt.x;
	sPnt.y=pnt.y;
}

BOOL chkbak(DUBPNT pnt){

	unsigned ind;
	double		len;

	for(ind=0;ind<8;ind++){

		len=hypot(filbak[ind].x-pnt.x,filbak[ind].y-pnt.y);
		if(len<stspace)
			return 1;
	}
	return 0;
}

BOOL linx(FLPNT* flt,unsigned strt,unsigned fin,DUBPNT* npnt){

	DUBPNT	dif;
	DUBPNT	tdub;

	dif.x=opnts[strt].x-flt[strt].x;
	dif.y=opnts[strt].y-flt[strt].y;
	if(!dif.x&&!dif.y)
		return 0;
	tdub.x=flt[strt].x;
	tdub.y=flt[strt].y;
	if(dif.x){

		if(proj(tdub,dif.y/dif.x,opnts[fin],flt[fin],npnt))
			return 1;
		else
			return 0;
	}
	else{

		if(projv(tdub.x,flt[fin],opnts[fin],npnt))
			return 1;
		else
			return 0;
	}
}

void filinsbw(DUBPNT pnt){

	filbak[pfbak].x=pnt.x;
	filbak[pfbak++].y=pnt.y;
	pfbak&=0x7;
	filinsb(pnt);
}

void sbfn(FLPNT* flt,unsigned strt,unsigned fin){

	DUBPNT		idif,odif,istp,ostp,opnt,ipnt;
	DUBPNT		bdif,bstp,bpnt;
	DUBPNT		npnt;
	double		ilen,olen,blen;
	unsigned	cnt,iflg,oflg,bcnt,ind,xflg;

	if(!setMap(SAT1)){

		sPnt.x=flt[strt].x;
		sPnt.y=flt[strt].y;
	}
	idif.x=flt[fin].x-flt[strt].x;
	idif.y=flt[fin].y-flt[strt].y;
	odif.x=opnts[fin].x-opnts[strt].x;
	odif.y=opnts[fin].y-opnts[strt].y;
	ilen=hypot(idif.x,idif.y);
	olen=hypot(odif.x,odif.y);
	ipnt.x=flt[strt].x;
	ipnt.y=flt[strt].y;
	opnt.x=opnts[strt].x;
	opnt.y=opnts[strt].y;
	xflg=pfbak=iflg=oflg=bcnt=0;
	for(ind=0;ind<8;ind++){

		filbak[ind].x=(float)1e12;
		filbak[ind].y=(float)1e12;
	}
	if(olen>ilen){

		cnt=olen/stspace;
		iflg=1;
		if(linx(flt,strt,fin,&npnt)){

			xflg=1;
			idif.x=idif.y=ilen=0;
			ipnt.x=npnt.x;
			ipnt.y=npnt.y;
		}
	}
	else{

		cnt=ilen/stspace;
		oflg=1;
		if(linx(flt,strt,fin,&npnt)){

			xflg=1;
			odif.x=odif.y=olen=0;
			opnt.x=npnt.x;
			opnt.y=npnt.y;
		}
	}
	if(!cnt)
		cnt=1;
	if(chkmax(cnt,seqpnt))
		return;
	istp.x=idif.x/cnt;
	istp.y=idif.y/cnt;
	ostp.x=odif.x/cnt;
	ostp.y=odif.y/cnt;
	for(ind=0;ind<cnt;ind++){

		ipnt.x+=istp.x;
		ipnt.y+=istp.y;
		opnt.x+=ostp.x;
		opnt.y+=ostp.y;
		if(toglMap(FILDIR)){

			if(iflg){

				bdif.x=ipnt.x-sPnt.x;
				bdif.y=ipnt.y-sPnt.y;
				blen=hypot(bdif.x,bdif.y);
				bcnt=blen/stspace;
				bstp.x=bdif.x/bcnt;
				bstp.y=bdif.y/bcnt;
				bpnt.x=ipnt.x;
				bpnt.y=ipnt.y;
				while(chkbak(bpnt)){

					bpnt.x-=bstp.x;
					bpnt.y-=bstp.y;
				}
				filinsbw(bpnt);
			}
			else
				filinsb(ipnt);
		}
		else{

			if(oflg){

				bdif.x=opnt.x-sPnt.x;
				bdif.y=opnt.y-sPnt.y;
				blen=hypot(bdif.x,bdif.y);
				bcnt=blen/stspace;
				bstp.x=bdif.x/bcnt;
				bstp.y=bdif.y/bcnt;
				bpnt.x=opnt.x;
				bpnt.y=opnt.y;
				while(chkbak(bpnt)){

					bpnt.x-=bstp.x;
					bpnt.y-=bstp.y;
				}
				filinsbw(bpnt);
			}
			else
				filinsb(opnt);
		}
	}
}

void sfn(unsigned short strtlin){

	unsigned ind;
	unsigned short nlin;

	for(ind=0;ind<frmpnt->sids;ind++){

		nlin=nxt(strtlin);
		sbfn(ipnts,strtlin,nlin);
		strtlin=nlin;
	}
	oseq[0].x=oseq[seqpnt-1].x;
	oseq[0].y=oseq[seqpnt-1].y;
	if(seqpnt>MAXSEQ-2)
		seqpnt=MAXSEQ-2;
}

void sbrd(){

	double			tspac;
	unsigned		strt;

	strt=getlast();
	tspac=stspace;
	rstMap(SAT1);
	rstMap(FILDIR);
	seqpnt=1;
	if(frmpnt->etyp&EGUND){

		stspace=USPAC;
		satout(plen*URAT);
		sfn(strt);
		setMap(FILDIR);
		sfn(strt);
	}
	fvars(clofind);
	satout(plen);
	stspace=frmpnt->espac;
	sfn(strt);
	stspace=tspac;
}

void rfn(unsigned tlin){

	unsigned ind,nlin;

	for(ind=0;ind<frmpnt->sids;ind++){

		nlin=nxt(tlin);
		sbfn(ipnts,tlin,nlin);
		tlin=nlin;
	}
}

void rbrd(){

	unsigned short	tlin=getlast();
	double			tspac;

	rstMap(SAT1);
	rstMap(FILDIR);
	tspac=stspace;
	stspace=USPAC;
	rfn(tlin);
	setMap(FILDIR);
	rfn(tlin);
	satout(plen);
	stspace=tspac;
	rfn(tlin);
}

void satends(unsigned blnt){

	FLPNT		stp;

	if(blnt&SBLNT){

		stp.x=sin(angs[0])*plen/2;
		stp.y=cos(angs[0])*plen/2;
		if(chkMap(INDIR))
		{
			stp.x=-stp.x;
			stp.y=-stp.y;
		}
		ipnts[0].x=frmpnt->flt[0].x+stp.x;
		ipnts[0].y=frmpnt->flt[0].y-stp.y;
		opnts[0].x=frmpnt->flt[0].x-stp.x;
		opnts[0].y=frmpnt->flt[0].y+stp.y;
	}
	else{

		ipnts[0].x=opnts[0].x=flt[0].x;
		ipnts[0].y=opnts[0].y=flt[0].y;
	}
	if(blnt&FBLNT){

		stp.x=sin(angs[sids-2])*plen/2;
		stp.y=cos(angs[sids-2])*plen/2;
		if(chkMap(INDIR))
		{
			stp.x=-stp.x;
			stp.y=-stp.y;
		}
		ipnts[sids-1].x=frmpnt->flt[sids-1].x+stp.x;
		ipnts[sids-1].y=frmpnt->flt[sids-1].y-stp.y;
		opnts[sids-1].x=frmpnt->flt[sids-1].x-stp.x;
		opnts[sids-1].y=frmpnt->flt[sids-1].y+stp.y;
	}
	else{

		ipnts[sids-1].x=opnts[sids-1].x=flt[sids-1].x;
		ipnts[sids-1].y=opnts[sids-1].y=flt[sids-1].y;
	}
}

void slbrd(){

	unsigned	ind;
	double		tspac=stspace;

	seqpnt=0;
	if(frmpnt->etyp&EGUND){

		plen=frmpnt->esiz*URAT;
		satout(plen);
		satends(frmpnt->at);
		rstMap(SAT1);
		rstMap(FILDIR);
		stspace=USPAC;
		for(ind=0;ind<(unsigned)frmpnt->sids-1;ind++)
			sbfn(ipnts,ind,ind+1);
		toglMap(FILDIR);
		for(ind=frmpnt->sids-1;ind;ind--)
			sbfn(ipnts,ind,ind-1);
	}
	plen=frmpnt->esiz;
	satout(plen);
	satends(frmpnt->at);
	stspace=frmpnt->espac;
	rstMap(SAT1);
	for(ind=0;ind<(unsigned)frmpnt->sids-1;ind++)
		sbfn(ipnts,ind,ind+1);
	stspace=tspac;
}

void satsbrd(){

	deleclp(clofind);
	frmpnt->etyp=EGSAT;
	if(chku(DUND))
		frmpnt->etyp|=EGUND;
	bsizpar();
	frmpnt->esiz=brdwid;
	frmpnt->espac=stspace/2;
	frmpnt->bcol=actcol;
	refilfn();
}

void satbrd(){

	unsigned ind;

	if(filmsgs(FML_ANGS))
		return;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			if(chku(BLUNT))
				frmpnt->at|=(SBLNT|FBLNT);
			else
				frmpnt->at&=NOBLNT;
			satsbrd();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			fvars(clofind);
			if(chku(BLUNT))
				frmpnt->at|=(SBLNT|FBLNT);
			else
				frmpnt->at&=NOBLNT;
			satsbrd();
			setMap(INIT);
			coltab();
			ritot(hed.stchs);
			setMap(RESTCH);
		}
	}
}

void lapbrd(){

	double		tsiz;
	unsigned	ind;
	
	seqpnt=0;
	tsiz=usesiz;
	usesiz=APSPAC;
	for(ind=0;ind<(unsigned)sids-1;ind++)
		bdrlin(ind,ind+1,APSPAC);
	for(ind=sids-1;ind;ind--)
		bdrlin(ind,ind-1,APSPAC);
	usesiz=tsiz;
}

void apbrd(){

	unsigned		ind;
	unsigned short	nlin,tlin=0;

	seqpnt=0;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	for(ind=0;ind<(unsigned)sids<<1;ind++){

		nlin=nxt(tlin);
		bdrlin(tlin,nlin,APSPAC);
		tlin=nlin;
	}
}

void sapliq()
{
	fvars(clofind);
	deleclp(clofind);
	frmpnt->etyp=EGAP;
	if(chku(DUND))
		frmpnt->etyp|=EGUND;
	frmpnt->espac=stspace/2;
	frmpnt->esiz=ini.brdwid;
	bsizpar();
	frmpnt->bcol=actcol|(apcol<<4);
	if(frmpnt->typ!=LIN)
	{
		if(frmpnt->ftyp=SAT&&frmpnt->stpt)
			delsac(clofind);
	}
	frmpnt->ftyp=0;
	frmpnt->typ=POLI;
	refilfn();
}

void apliq(){

	unsigned ind;

	if(filmsgs(FML_APLQ))
		return;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			if(chku(BLUNT))
				frmpnt->at|=(SBLNT|FBLNT);
			else
				frmpnt->at&=NOBLNT;
			sapliq();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			if(chku(BLUNT))
				frmpnt->at|=(SBLNT|FBLNT);
			else
				frmpnt->at&=NOBLNT;
			sapliq();
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
	}
}

void setap(){

	TCHAR	buf[HBUFSIZ];

	apcol=actcol;
	LoadString(hInst,IDS_APCOL,buf,HBUFSIZ);
	sprintf(msgbuf,buf,apcol+1);
	shoMsg(msgbuf);
}

void maxtsiz(TCHAR* str,POINT* pt){

	SIZE	tsiz;

	GetTextExtentPoint32(sdc,str,strlen(str),&tsiz);
	pt->y=tsiz.cy;
	if(tsiz.cx>pt->x)
		pt->x=tsiz.cx;
}

void maxwid(unsigned strt,unsigned fin){

	POINT	pnt;

	pnt.x=0;
	pnt.y=0;
	while(strt<=fin)
		maxtsiz(stab[strt++],&pnt);
	prfsiz=pnt.x+6;
}

HWND txtwin(TCHAR* str,RECT loc){

	if(chkMap(REFCNT))
	{
		maxtsiz(str,&siz0);
		return 0;
	}
	return CreateWindow(
		"STATIC",
		str,
		WS_CHILD|WS_VISIBLE,
		loc.left,
		loc.top,
		loc.right-loc.left,
		loc.bottom-loc.top,
		hfdat,
		NULL,
		hInst,
		NULL);
}

HWND txtrwin(TCHAR* str,RECT loc){

	if(chkMap(REFCNT))
	{
		maxtsiz(str,&siz1);
		return 0;
	}
	return CreateWindow(
		"STATIC",
		str,
		SS_NOTIFY|WS_BORDER|WS_CHILD|WS_VISIBLE,
		loc.left,
		loc.top,
		loc.right-loc.left,
		loc.bottom-loc.top,
		hfdat,
		NULL,
		hInst,
		NULL);
}

HWND numwin(TCHAR* str,RECT loc){

	if(chkMap(REFCNT))
	{
		maxtsiz(str,&siz1);
		return 0;
	}
	return CreateWindow(
		"STATIC",
		str,
		SS_NOTIFY|SS_RIGHT|WS_BORDER|WS_CHILD|WS_VISIBLE,
		loc.left,
		loc.top,
		loc.right-loc.left,
		loc.bottom-loc.top,
		hfdat,
		NULL,
		hInst,
		NULL);
}

void nxtlin(){

	refmcnt++;
	loc0.top+=siz0.y;
	loc0.bottom+=siz0.y;
	loc1.top+=siz1.y;
	loc1.bottom+=siz1.y;;
}

BOOL CALLBACK chenum(HWND hwnd,LPARAM lParam){

	return DestroyWindow(hwnd);
}

void refrmfn()
{
	char*		pchr;
	unsigned	cod,fpnt;

	cod=frmpnt->etyp&NEGUND;
	fpnt=cod-1;
	loc0.top=loc1.top=3;
	loc0.bottom=loc1.bottom=3+siz0.y;
	loc0.left=3;
	loc0.right=3+siz0.x;
	loc1.left=6+siz0.x;
	loc1.right=6+siz0.x+siz1.x+6;
	thTxt[LFRM]=txtwin(stab[STR_TXT0],loc0);
	if(frmpnt->typ==LIN)
		thDat[LFRM]=txtrwin(stab[STR_EDG1],loc1);
	else
		thDat[LFRM]=txtrwin(stab[STR_FREH],loc1);
	nxtlin();
	thTxt[LLAYR]=txtwin(stab[STR_TXT1],loc0);
	sprintf(msgbuf,"%d",(frmpnt->at&FRMLMSK)>>1);
	thDat[LLAYR]=txtrwin(msgbuf,loc1);
	nxtlin();
	if(frmpnt->typ!=LIN)
	{
		thTxt[LCWLK]=txtwin(stab[STR_CWLK],loc0);
		if(frmpnt->xat&AT_CWLK)
			thDat[LCWLK]=txtrwin(stab[STR_ON],loc1);
		else
			thDat[LCWLK]=txtrwin(stab[STR_OFF],loc1);
		nxtlin();
		thTxt[LWALK]=txtwin(stab[STR_WALK],loc0);
		if(frmpnt->xat&AT_WALK)
			thDat[LWALK]=txtrwin(stab[STR_ON],loc1);
		else
			thDat[LWALK]=txtrwin(stab[STR_OFF],loc1);
		nxtlin();
		thTxt[LUND]=txtwin(stab[STR_UND],loc0);
		if(frmpnt->xat&AT_UND)
			thDat[LUND]=txtrwin(stab[STR_ON],loc1);
		else
			thDat[LUND]=txtrwin(stab[STR_OFF],loc1);
		nxtlin();
		if(frmpnt->xat&(AT_WALK|AT_UND|AT_CWLK))
		{
			thTxt[LUNDCOL]=txtwin(stab[STR_UNDCOL],loc0);
			sprintf(msgbuf,"%d",frmpnt->ucol+1);
			thDat[LUNDCOL]=txtrwin(msgbuf,loc1);
			nxtlin();
			thTxt[LULEN]=txtwin(stab[STR_ULEN],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->ulen/PFGRAN);
			thDat[LULEN]=txtrwin(msgbuf,loc1);
			nxtlin();
		}
		thTxt[LWLKIND]=txtwin(stab[STR_UWLKIND],loc0);
		sprintf(msgbuf,"%.2f",frmpnt->wind/PFGRAN);
		thDat[LWLKIND]=txtrwin(msgbuf,loc1);
		nxtlin();
		if(frmpnt->xat&AT_UND)
		{
			thTxt[LUSPAC]=txtwin(stab[STR_FUSPAC],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->uspac/PFGRAN);
			thDat[LUSPAC]=txtrwin(msgbuf,loc1);
			nxtlin();
			thTxt[LUANG]=txtwin(stab[STR_FUANG],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->uang*180/PI);
			thDat[LUANG]=txtrwin(msgbuf,loc1);
			nxtlin();
		}
	}
	thTxt[LFRMFIL]=txtwin(stab[STR_TXT2],loc0);
	thDat[LFRMFIL]=txtrwin(stab[STR_FIL0+frmpnt->ftyp],loc1);
	nxtlin();
	if(frmpnt->ftyp){

		thTxt[LFRMCOL]=txtwin(stab[STR_TXT3],loc0);
		sprintf(msgbuf,"%d",frmpnt->fcol+1);
		thDat[LFRMCOL]=numwin(msgbuf,loc1);
		nxtlin();
		if(frmpnt->ftyp==FTHF){

			thTxt[LFTHCOL]=txtwin(stab[STR_FTHCOL],loc0);
			sprintf(msgbuf,"%d",frmpnt->dhx.fth.fthcol+1);
			thDat[LFTHCOL]=numwin(msgbuf,loc1);
			nxtlin();
			thTxt[LFTHTYP]=txtwin(stab[STR_FTHTYP],loc0);
			thDat[LFTHTYP]=numwin(stab[STR_FTH0+frmpnt->dhx.fth.fthtyp-1],loc1);
			nxtlin();
			thTxt[LFTHBLND]=txtwin(stab[STR_FTHBLND],loc0);
			if(frmpnt->xat&AT_FTHBLND)
				pchr=stab[STR_ON];
			else
				pchr=stab[STR_OFF];
			thDat[LFTHBLND]=txtrwin(pchr,loc1);
			nxtlin();
			if(!(frmpnt->xat&AT_FTHBLND)){

				thTxt[LFTHDWN]=txtwin(stab[STR_FTHDWN],loc0);
				if(frmpnt->xat&(AT_FTHDWN))
					pchr=stab[STR_ON];
				else
					pchr=stab[STR_OFF];
				thDat[LFTHDWN]=txtrwin(pchr,loc1);
				nxtlin();
				if(!(frmpnt->xat&AT_FTHDWN)){

					thTxt[LFTHUP]=txtwin(stab[STR_FTHUP],loc0);
					if(frmpnt->xat&AT_FTHUP)
						pchr=stab[STR_ON];
					else
						pchr=stab[STR_OFF];
					thDat[LFTHUP]=txtrwin(pchr,loc1);
					nxtlin();
				}
			}
			thTxt[LFTHUPCNT]=txtwin(stab[STR_FTHUPCNT],loc0);
			sprintf(msgbuf,"%d",frmpnt->dhx.fth.fthup);
			thDat[LFTHUPCNT]=numwin(msgbuf,loc1);
			nxtlin();
			thTxt[LFTHDWNCNT]=txtwin(stab[STR_FTHDWNCNT],loc0);
			sprintf(msgbuf,"%d",frmpnt->dhx.fth.fthdwn);
			thDat[LFTHDWNCNT]=numwin(msgbuf,loc1);
			nxtlin();
			thTxt[LFTHSIZ]=txtwin(stab[STR_FTHSIZ],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->dhx.fth.fthrat);
			thDat[LFTHSIZ]=numwin(msgbuf,loc1);
			nxtlin();
			if(frmpnt->dhx.fth.fthtyp==FTHPSG){

				thTxt[LFTHNUM]=txtwin(stab[STR_FTHNUM],loc0);
				sprintf(msgbuf,"%d",frmpnt->dhx.fth.fthnum);
				thDat[LFTHNUM]=numwin(msgbuf,loc1);
				nxtlin();
			}
			thTxt[LFTHFLR]=txtwin(stab[STR_FTHFLR],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->dhx.fth.fthflr/PFGRAN);
			thDat[LFTHFLR]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(frmpnt->ftyp!=CLPF){

			thTxt[LFRMSPAC]=txtwin(stab[STR_TXT4],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->fspac/PFGRAN);
			thDat[LFRMSPAC]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(istx(clofind))
		{
			thTxt[LTXOF]=txtwin(stab[STR_TXOF],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->txof/PFGRAN);
			thDat[LTXOF]=numwin(msgbuf,loc1);
			nxtlin();
		}
		thTxt[LMAXFIL]=txtwin(stab[STR_TXT20],loc0);
		sprintf(msgbuf,"%.2f",frmpnt->fmax/PFGRAN);
		thDat[LMAXFIL]=numwin(msgbuf,loc1);
		nxtlin();
		if(!isclp(clofind)&&!istx(clofind)){

			thTxt[LFRMLEN]=txtwin(stab[STR_TXT5],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->flencnt.flen/PFGRAN);
			thDat[LFRMLEN]=numwin(msgbuf,loc1);
			nxtlin();
		}
		thTxt[LMINFIL]=txtwin(stab[STR_TXT21],loc0);
		sprintf(msgbuf,"%.2f",frmpnt->fmin/PFGRAN);
		thDat[LMINFIL]=numwin(msgbuf,loc1);
		nxtlin();
		if(frmpnt->ftyp==ANGF||frmpnt->ftyp==TXANGF){

			thTxt[LFRMANG]=txtwin(stab[STR_TXT6],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->angclp.fang*180/PI);
			thDat[LFRMANG]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(frmpnt->ftyp==ANGCLPF){

			thTxt[LSACANG]=txtwin(stab[STR_TXT6],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->sacang.ang*180/PI);
			thDat[LSACANG]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(frmpnt->ftyp==VCLPF||frmpnt->ftyp==HCLPF||frmpnt->ftyp==ANGCLPF){

			thTxt[LFRMFAZ]=txtwin(stab[STR_TXT18],loc0);
			sprintf(msgbuf,"%d",frmpnt->wpar);
			thDat[LFRMFAZ]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(frmpnt->ftyp==VRTF||frmpnt->ftyp==HORF||frmpnt->ftyp==ANGF||istx(clofind)){

			thTxt[LBFILSQR]=txtwin(stab[STR_PRF2],loc0);
			if(frmpnt->xat&AT_SQR)
				strcpy(msgbuf,stab[STR_SQR]);
			else
				strcpy(msgbuf,stab[STR_PNTD]);
			thDat[LBFILSQR]=txtrwin(msgbuf,loc1);
			nxtlin();
		}
	}
	thTxt[LFSTRT]=txtwin(stab[STR_FSTRT],loc0);
	if(frmpnt->xat&AT_STRT)
		strcpy(msgbuf,stab[STR_ON]);
	else
		strcpy(msgbuf,stab[STR_OFF]);
	thDat[LFSTRT]=txtrwin(msgbuf,loc1);
	nxtlin();
	if(frmpnt->xat&AT_STRT)
	{
		thTxt[LDSTRT]=txtwin(stab[STR_FSTRT],loc0);
		sprintf(msgbuf,"%d",frmpnt->strt);
		thDat[LDSTRT]=numwin(msgbuf,loc1);
		nxtlin();
	}
	thTxt[LFEND]=txtwin(stab[STR_FEND],loc0);
	if(frmpnt->xat&AT_END)
		strcpy(msgbuf,stab[STR_ON]);
	else
		strcpy(msgbuf,stab[STR_OFF]);
	thDat[LFEND]=txtrwin(msgbuf,loc1);
	nxtlin();
	if(frmpnt->xat&AT_END)
	{
		thTxt[LDEND]=txtwin(stab[STR_FEND],loc0);
		sprintf(msgbuf,"%d",frmpnt->end);
		thDat[LDEND]=numwin(msgbuf,loc1);
		nxtlin();
	}
	thTxt[LBRD]=txtwin(stab[STR_TXT7],loc0);
	thDat[LBRD]=txtrwin(stab[STR_EDG0+cod],loc1);
	nxtlin();
	if(cod){

		thTxt[LBRDCOL]=txtwin(stab[STR_TXT8],loc0);
		sprintf(msgbuf,"%d",(frmpnt->bcol&0xf)+1);
		thDat[LBRDCOL]=numwin(msgbuf,loc1);
		nxtlin();
		if(egaray[fpnt]&BESPAC){

			thTxt[LBRDSPAC]=txtwin(stab[STR_TXT9],loc0);
			if(cod==EGPRP||cod==EGCHNH||cod==EGCHNL)
				sprintf(msgbuf,"%.2f",frmpnt->espac/PFGRAN);
			else
				sprintf(msgbuf,"%.2f",frmpnt->espac/PFGRAN*2);
			thDat[LBRDSPAC]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BPICSPAC){

			thTxt[LBRDPIC]=txtwin(stab[STR_TXT16],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->espac/PFGRAN);
			thDat[LBRDPIC]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BEMAX){

			thTxt[LMAXBRD]=txtwin(stab[STR_TXT22],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->emax/PFGRAN);
			thDat[LMAXBRD]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BELEN){

			thTxt[LBRDLEN]=txtwin(stab[STR_TXT10],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->elen/PFGRAN);
			thDat[LBRDLEN]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BEMIN){

			thTxt[LMINBRD]=txtwin(stab[STR_TXT23],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->emin/PFGRAN);
			thDat[LMINBRD]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BESIZ){

			thTxt[LBRDSIZ]=txtwin(stab[STR_TXT11],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->esiz/PFGRAN);
			thDat[LBRDSIZ]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BRDPOS){

			thTxt[LBRDPOS]=txtwin(stab[STR_TXT18],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->elen);
			thDat[LBRDPOS]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(egaray[fpnt]&CHNPOS){

			thTxt[LBRDPOS]=txtwin(stab[STR_TXT19],loc0);
			sprintf(msgbuf,"%.2f",frmpnt->elen);
			thDat[LBRDPOS]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(cod==EGAP){

			thTxt[LAPCOL]=txtwin(stab[STR_TXT12],loc0);
			sprintf(msgbuf,"%d",(frmpnt->bcol>>4)+1);
			thDat[LAPCOL]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(cod==EGSAT||cod==EGAP||cod==EGPRP){

			thTxt[LBRDUND]=txtwin(stab[STR_TXT17],loc0);
			if(frmpnt->etyp&EGUND)
				thDat[LBRDUND]=numwin(stab[STR_ON],loc1);
			else
				thDat[LBRDUND]=numwin(stab[STR_OFF],loc1);
			nxtlin();
		}
		if(egaray[fpnt]&BCNRSIZ){

			if(frmpnt->etyp==EGHOL)
				sprintf(msgbuf,"%.2f",getblen()/PFGRAN);
			else
				sprintf(msgbuf,"%.2f",getplen()/PFGRAN);
			thTxt[LBCSIZ]=txtwin(stab[STR_TXT13],loc0);
			thDat[LBCSIZ]=numwin(msgbuf,loc1);
			nxtlin();
		}
		if(frmpnt->typ==LIN&&egaray[fpnt]&BRDEND){

			thTxt[LBSTRT]=txtwin(stab[STR_TXT14],loc0);
			if(frmpnt->at&SBLNT)
				thDat[LBSTRT]=numwin(stab[STR_BLUNT],loc1);
			else
				thDat[LBSTRT]=numwin(stab[STR_TAPR],loc1);
			nxtlin();
			thTxt[LBFIN]=txtwin(stab[STR_TXT15],loc0);
			if(frmpnt->at&FBLNT)
				thDat[LBFIN]=numwin(stab[STR_BLUNT],loc1);
			else
				thDat[LBFIN]=numwin(stab[STR_TAPR],loc1);
			nxtlin();
		}
	}
}

void refrm(){

	frmpnt=&formlst[clofind];
	if(rstMap(PRFACT)){

		DestroyWindow(hPrf);
		rstMap(WASRT);
	}
	siz0.x=siz0.y=siz1.x=siz1.y=0;
	setMap(REFCNT);
	refmcnt=0;
	refrmfn();
	if(hfdat){

		while(EnumChildWindows(hfdat,chenum,0));
		MoveWindow(hfdat,buttonWid3+3,3,siz0.x+siz1.x+18,siz0.y*refmcnt+12,TRUE);
		redraw(hfdat);
	}
	else{
	
		hfdat=CreateWindow(
			"STATIC",
			0,
			WS_CHILD|WS_VISIBLE|WS_BORDER,
			buttonWid3+3,
			3,
			siz0.x+siz1.x+18,
			siz0.y*refmcnt+12,
			hWnd,
			NULL,
			hInst,
			NULL);
	}
	rstMap(REFCNT);
	refrmfn();
}

void pxrct2stch(RECT pxr,FLRCT* str){

	POINT	tpnt;

	tpnt.x=pxr.left+stOrg.x;
	tpnt.y=pxr.top+stOrg.y;
	pxCor2stch(tpnt);
	str->left=sPnt.x;
	str->top=sPnt.y;
	tpnt.x=pxr.right+stOrg.x;
	tpnt.y=pxr.bottom+stOrg.y;
	pxCor2stch(tpnt);
	str->right=sPnt.x;
	str->bottom=sPnt.y;
}

unsigned pdir(unsigned ind){

	if(chkMap(PSELDIR))
		return nxt(ind);
	else
		return prv(ind);
}

void setstrtch(){

	FLOAT		ref=0;
	double		rat=1;
	unsigned	ind,ine;
	FLRCT		trct;
	long		tlng;

	savdo();
	if(chkMap(FPSEL))
		MoveMemory(&trct,&pselrct,sizeof(FLRCT));
	else{

		if(fselpnt||chkMap(BIGBOX))
			pxrct2stch(bigrct,&trct);
		else{

			fvars(clofind);
			px2stch();
			trct.bottom=trct.left=trct.right=trct.top=0;
		}
	}
	switch(cntrl){

	case 0:

		if(fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

			ref=trct.bottom;
			tlng=msg.pt.y-stOrg.y;
			rat=(double)(bigrct.bottom-tlng)/(bigrct.bottom-bigrct.top);
		}
		else{

			if(chkMap(FORMSEL)){

				ref=frmpnt->rct.bottom;
				rat=(double)(sPnt.y-ref)/(frmpnt->rct.top-ref);
				frmpnt->rct.top=sPnt.y;
			}
			else{

				ref=rngrct.bottom;
				rat=(double)(sPnt.y-ref)/(rngrct.top-ref);
			}
		}
		break;

	case 1:

		if(fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

			ref=trct.left;
			tlng=msg.pt.x-stOrg.x;
			rat=(double)(tlng-bigrct.left)/(bigrct.right-bigrct.left);
		}
		else{

			if(chkMap(FORMSEL)){

				ref=frmpnt->rct.left;
				rat=(double)(sPnt.x-ref)/(frmpnt->rct.right-ref);
				frmpnt->rct.right=sPnt.x;
			}
			else{

				ref=rngrct.left;
				rat=(double)(sPnt.x-ref)/(rngrct.right-ref);
			}
		}
		break;

	case 2:

		if(fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

			ref=trct.top;
			tlng=msg.pt.y-stOrg.y;
			rat=(double)(tlng-bigrct.top)/(bigrct.bottom-bigrct.top);
		}
		else{

			if(chkMap(FORMSEL)){

				ref=frmpnt->rct.top;
				rat=(double)(sPnt.y-ref)/(frmpnt->rct.bottom-ref);
				frmpnt->rct.bottom=sPnt.y;
			}
			else{

				ref=rngrct.top;
				rat=(double)(sPnt.y-ref)/(rngrct.bottom-ref);
			}
		}
		break;

	case 3:

		if(fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

			ref=trct.right;
			tlng=msg.pt.x-stOrg.x;
			rat=(double)(bigrct.right-tlng)/(bigrct.right-bigrct.left);
		}
		else{

			if(chkMap(FORMSEL)){

				ref=frmpnt->rct.right;
				rat=(double)(sPnt.x-ref)/(frmpnt->rct.left-ref);
				frmpnt->rct.left=sPnt.x;
			}
			else{

				ref=rngrct.right;
				rat=(double)(sPnt.x-ref)/(rngrct.left-ref);
			}
		}
		break;
	}
	if(cntrl&1){

		if(chkMap(FPSEL)){

			fvars(clofind);
			ine=pselrng.strt;
			for(ind=0;ind<=pselrng.cnt;ind++){

				flt[ine].x=(flt[ine].x-ref)*rat+ref;
				ine=pdir(ine);
			}
			frmout(clofind);
			setpsel();
			setMap(RESTCH);
			return;
		}
		if(chkMap(BIGBOX)){

			for(ind=0;ind<formpnt;ind++){

				flt=formlst[ind].flt;
				for(ine=0;ine<formlst[ind].sids;ine++)
					flt[ine].x=(flt[ine].x-ref)*rat+ref;
				frmout(ind);
			}
			for(ind=0;ind<hed.stchs;ind++)
				stchs[ind].x=(stchs[ind].x-ref)*rat+ref;
			selal();
			return;
		}
		else{

			if(fselpnt){

				for(ind=0;ind<fselpnt;ind++){

					flt=formlst[selist[ind]].flt;
					for(ine=0;ine<formlst[selist[ind]].sids;ine++)
						flt[ine].x=(flt[ine].x-ref)*rat+ref;
				}
			}
			else{

				if(chkMap(FORMSEL)){

					for(ind=0;ind<sids;ind++)
						flt[ind].x=(flt[ind].x-ref)*rat+ref;
				}
				else{

					for(ind=gpnt0;ind<=gpnt1;ind++)
						stchs[ind].x=(stchs[ind].x-ref)*rat+ref;
				}
			}
		}
	}
	else{

		if(chkMap(FPSEL)){

			fvars(clofind);
			ine=pselrng.strt;
			for(ind=0;ind<=pselrng.cnt;ind++){

				flt[ine].y=(flt[ine].y-ref)*rat+ref;
				ine=pdir(ine);
			}
			frmout(clofind);
			setpsel();
			refil();
			setMap(RESTCH);
			return;
		}
		if(chkMap(BIGBOX)){

			for(ind=0;ind<formpnt;ind++){

				flt=formlst[ind].flt;
				for(ine=0;ine<formlst[ind].sids;ine++)
					flt[ine].y=(flt[ine].y-ref)*rat+ref;
				frmout(ind);
			}
			for(ind=0;ind<hed.stchs;ind++)
				stchs[ind].y=(stchs[ind].y-ref)*rat+ref;
			selal();
			return;
		}
		else{

			if(fselpnt){

				for(ind=0;ind<fselpnt;ind++){

					flt=formlst[selist[ind]].flt;
					for(ine=0;ine<formlst[selist[ind]].sids;ine++)
						flt[ine].y=(flt[ine].y-ref)*rat+ref;
				}
			}
			else{

				if(chkMap(FORMSEL)){

					for(ind=0;ind<sids;ind++)
						flt[ind].y=(flt[ind].y-ref)*rat+ref;
				}
				else{

					for(ind=gpnt0;ind<=gpnt1;ind++)
						stchs[ind].y=(stchs[ind].y-ref)*rat+ref;
				}
			}
		}
	}
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			ine=selist[ind];
			frmout(ine);
			clofind=ine;
			refil();
		}
	}
	else
		if(chkMap(FORMSEL))
			refil();
	setMap(RESTCH);
}

void setexpand(){

	DUBPNT		ref;
	POINT		tref;
	FLPNT		sref;
	DUBPNT		siz0;
	DUBPNT		siz1;
	DUBPNT		rat;
	double		aspect;
	unsigned	ind,ine;
	FLRCT		rct;

	savdo();
	if(fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

		rct.bottom=bigrct.bottom;
		rct.left=bigrct.left;
		rct.right=bigrct.right;
		rct.top=bigrct.top;
		sPnt.x=msg.pt.x-stOrg.x;
		sPnt.y=msg.pt.y-stOrg.y;
		siz0.y=rct.bottom-rct.top;
	}
	else{

		px2stch();
		fvars(clofind);
		if(chkMap(FORMSEL))
			rct=frmpnt->rct;
		else{

			rct.bottom=rngrct.bottom;
			rct.top=rngrct.top;
			rct.right=rngrct.right;
			rct.left=rngrct.left;
		}
		siz0.y=rct.top-rct.bottom;
	}
	rat.x=rat.y=1;
	ref.x=ref.y=0;
	siz0.x=rct.right-rct.left;
	switch(cntrl){

	case 0:

		ref.x=rct.right;
		ref.y=rct.bottom;
		siz1.x=fabs(sPnt.x-ref.x);
		siz1.y=fabs(sPnt.y-ref.y);
		aspect=siz1.x/siz1.y;
		if(aspect<xpct)
			siz1.x=siz1.y*xpct;
		else
			siz1.y=siz1.x/xpct;
		rat.x=siz1.x/siz0.x;
		rat.y=siz1.y/siz0.y;
		if(!fselpnt&&chkMap(FORMSEL)){

			frmpnt->rct.left=rct.right-siz1.x;
			frmpnt->rct.top=rct.bottom+siz1.y;
		}
		break;

	case 1:
		
		ref.x=rct.left;
		ref.y=rct.bottom;
		siz1.x=fabs(sPnt.x-ref.x);
		siz1.y=fabs(sPnt.y-ref.y);
		aspect=siz1.x/siz1.y;
		if(aspect<xpct)
			siz1.x=siz1.y*xpct;
		else
			siz1.y=siz1.x/xpct;
		rat.x=siz1.x/siz0.x;
		rat.y=siz1.y/siz0.y;
		if(!fselpnt&&chkMap(FORMSEL)){

			frmpnt->rct.right=rct.left+siz1.x;
			frmpnt->rct.top=rct.bottom+siz1.y;
		}
		break;

	case 2:

		ref.x=rct.left;
		ref.y=rct.top;
		siz1.x=fabs(sPnt.x-ref.x);
		siz1.y=fabs(sPnt.y-ref.y);
		aspect=siz1.x/siz1.y;
		if(aspect<xpct)
			siz1.x=siz1.y*xpct;
		else
			siz1.y=siz1.x/xpct;
		rat.x=siz1.x/siz0.x;
		rat.y=siz1.y/siz0.y;
		if(!fselpnt&&chkMap(FORMSEL)){
		
			frmpnt->rct.right=rct.left+siz1.x;
			frmpnt->rct.bottom=rct.top-siz1.y;
		}
		break;

	case 3:

		ref.x=rct.right;
		ref.y=rct.top;
		siz1.x=fabs(sPnt.x-ref.x);
		siz1.y=fabs(sPnt.y-ref.y);
		aspect=siz1.x/siz1.y;
		if(aspect<xpct)
			siz1.x=siz1.y*xpct;
		else
			siz1.y=siz1.x/xpct;
		rat.x=siz1.x/siz0.x;
		rat.y=siz1.y/siz0.y;
		if(!fselpnt&&chkMap(FORMSEL)){

			frmpnt->rct.left=rct.right-siz1.x;
			frmpnt->rct.bottom=rct.top-siz1.y;
		}
		break;
	}
	tref.x=ref.x;
	tref.y=ref.y;
	px2stchf(tref,&sref);
	if(chkMap(FPSEL)){

		fvars(clofind);
		ine=pselrng.strt;
		for(ind=0;ind<=pselrng.cnt;ind++){

			flt[ine].x=(flt[ine].x-sref.x)*rat.x+sref.x;
			flt[ine].y=(flt[ine].y-sref.y)*rat.y+sref.y;
			ine=pdir(ine);
		}
		setpsel();
		frmout(clofind);
		refil();
		setMap(RESTCH);
		return;
	}
	if(chkMap(BIGBOX)){

		for(ind=0;ind<formpnt;ind++){

			fvars(ind);
			for(ine=0;ine<frmpnt->sids;ine++){

				flt[ine].x=(flt[ine].x-sref.x)*rat.x+sref.x;
				flt[ine].y=(flt[ine].y-sref.y)*rat.y+sref.y;
			}
			frmout(ind);
		}
		for(ind=0;ind<hed.stchs;ind++){

			stchs[ind].x=(stchs[ind].x-sref.x)*rat.x+sref.x;
			stchs[ind].y=(stchs[ind].y-sref.y)*rat.y+sref.y;
		}
		selal();
		return;
	}
	else{

		if(fselpnt){

			for(ind=0;ind<fselpnt;ind++){

				fvars(selist[ind]);
				for(ine=0;ine<frmpnt->sids;ine++){

					flt[ine].x=(flt[ine].x-sref.x)*rat.x+sref.x;
					flt[ine].y=(flt[ine].y-sref.y)*rat.y+sref.y;
				}
				frmout(selist[ind]);
				clofind=selist[ind];
				refil();
			}
		}
		else{

			if(chkMap(FORMSEL)){

				for(ind=0;ind<sids;ind++){

					flt[ind].x=(flt[ind].x-ref.x)*rat.x+ref.x;
					flt[ind].y=(flt[ind].y-ref.y)*rat.y+ref.y;
				}
				refil();
			}
			else{

				for(ind=gpnt0;ind<=gpnt1;ind++){

					stchs[ind].x=(stchs[ind].x-ref.x)*rat.x+ref.x;
					stchs[ind].y=(stchs[ind].y-ref.y)*rat.y+ref.y;
				}
			}
		}
		setMap(RESTCH);
	}
}

void nufilcol(unsigned col){

	unsigned at,ind;

	if(frmpnt->fcol!=col){
	
		frmpnt->fcol=col;
		at=(clofind<<4)|FRMFIL;
		for(ind=0;ind<hed.stchs;ind++){

			if((stchs[ind].at&(FRMSK|TYPMSK|FTHMSK))==at){

				stchs[ind].at&=0xfffffff0;
				stchs[ind].at|=col;
			}
		}
	}
}

void nufthcol(unsigned col){

	unsigned at,ind;

	if(frmpnt->dhx.fth.fthcol!=col){
	
		frmpnt->dhx.fth.fthcol=col;
		at=(clofind<<4)|FTHMSK;
		for(ind=0;ind<hed.stchs;ind++){

			if((stchs[ind].at&(FRMSK|FTHMSK))==at){

				stchs[ind].at&=0xfffffff0;
				stchs[ind].at|=col;
			}
		}
	}
}

void nubrdcol(unsigned col){

	unsigned at,ind;

	frmpnt->bcol=col;
	at=(clofind<<4)|FRMBFIL;
	for(ind=0;ind<hed.stchs;ind++){

		if((stchs[ind].at&(FRMSK|TYPMSK))==at){

			stchs[ind].at&=0xfffffff0;
			stchs[ind].at|=col;
		}
	}
}

void nulapcol(unsigned col){

	unsigned at,ind;

	if((unsigned)(frmpnt->bcol>>4)!=col){
	
		frmpnt->bcol&=0xf;
		frmpnt->bcol|=col<<4;
		at=(clofind<<4)|TYPMSK;
		for(ind=0;ind<hed.stchs;ind++){

			if((stchs[ind].at&(TYPMSK|FRMSK))==at){

				stchs[ind].at&=0xfffffff0;
				stchs[ind].at|=col;
			}
		}
	}
}

void sidwnd(HWND wnd){

	RECT		wrct;
	unsigned	baksid;

	msgpnt=0;
	sidbuf[0]=0;
	baksid=sidtyp;
	unsid();
	sidtyp=baksid;
	GetWindowRect(wnd,&wrct);
	GetWindowRect(hfdat,&msgRct);
	hSid=CreateWindow(
		"STATIC",
		0,
		WS_BORDER|WS_CHILD|WS_VISIBLE,
		msgRct.right-morg.x+3,
		wrct.top-morg.y-3,
		buttonWid3,
		wrct.bottom-wrct.top+3,
		hWnd,
		NULL,
		hInst,
		NULL);
}

void prfsid(HWND wnd){

	RECT	wrct;

	msgpnt=0;
	sidbuf[0]=0;
	unsid();
	GetWindowRect(wnd,&wrct);
	GetClientRect(hPrf,&msgRct);
	hSid=CreateWindow(
		"STATIC",
		0,
		WS_BORDER|WS_CHILD|WS_VISIBLE,
		wrct.right-morg.x+6,
		wrct.top-morg.y-3,
		siz1.x,
		wrct.bottom-wrct.top+3,
		hWnd,
		NULL,
		hInst,
		NULL);
}

void sbold(){

	fvars(clofind);
	deleclp(clofind);
	frmpnt->etyp=EGBLD;
	frmpnt->bcol=actcol;
	refilfn();
}

void dubold(){

	unsigned ind;

	if(filmsgs(FML_BLD))
		return;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			sbold();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			sbold();
			coltab();
			setMap(INIT);
			setMap(RESTCH);
			ritot(hed.stchs);
		}
	}
}

void prftwin(TCHAR* str){

	CreateWindow(
		"STATIC",
		str,
		WS_CHILD|WS_VISIBLE,
		loc0.left,
		loc0.top,
		loc0.right-loc0.left,
		loc0.bottom-loc0.top,
		hPrf,
		NULL,
		hInst,
		NULL);
}

HWND prfnwin(TCHAR* str){

	return CreateWindow(
		"STATIC",
		str,
		SS_NOTIFY|SS_RIGHT|WS_BORDER|WS_CHILD|WS_VISIBLE,
		loc1.left,
		loc1.top,
		loc1.right-loc1.left,
		loc1.bottom-loc1.top,
		hPrf,
		NULL,
		hInst,
		NULL);
}

void prflin(unsigned lin){

	prftwin(stab[lin]);
	thDat[lin-STR_PRF0]=prfnwin(msgbuf);
	nxtlin();
}

void sethup(){

	if(ini.hupx==LHUPX&&ini.hupy==LHUPY){

		ini.hup=LARGHUP;
		return;
	}
	if(ini.hupx==SHUPX&&ini.hupy==SHUPY){

		ini.hup=SMALHUP;
		return;
	}
	if(ini.hupx==HUP100XY&&ini.hupy==HUP100XY){

		ini.hup=HUP100;
		return;
	}
	ini.hup=CUSTHUP;
}

#if LANG==ENG||LANG==HNG

void prfmsg(){

	HDC		prfdc;
	RECT	prfrct;

	if(rstMap(INSRT))
		setMap(WASRT);
	rstMap(BIGBOX);
	fselpnt=0;
	if(hfdat){

		undat();
		unsid();
		sidtyp=0;
	}
	siz0.x=siz0.y=0;
	siz1.x=siz1.y=0;
	maxtsiz(stab[STR_PRF0+4],&siz0);
	maxtsiz(stab[STR_TAPR],&siz1);
	siz0.x=prfsiz;
	siz0.x+=4;
#if LANG==HNG
	siz0.x+=10;
#endif
	DestroyWindow(hPrf);
	prfwid=siz0.x+siz1.x+18;
	hPrf=CreateWindow(
		"STATIC",
		0,
		WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3+3,
		3,
		prfwid,
		siz0.y*PRFLINS+12,
		hWnd,
		NULL,
		hInst,
		NULL);
	prfdc=GetDC(hPrf);
	GetClientRect(hPrf,&prfrct);
	FillRect(prfdc,&prfrct,(HBRUSH)(COLOR_WINDOW+1));
	loc0.top=loc1.top=3;
	loc0.bottom=loc1.bottom=3+siz0.y;
	loc0.left=3;
	loc0.right=3+siz0.x;
	loc1.left=6+siz0.x;
	loc1.right=6+siz0.x+siz1.x+6;
	sprintf(msgbuf,"%d",apcol+1);
	prflin(STR_PRF10);
	sprintf(msgbuf,"%.2f",brdwid/PFGRAN);
	prflin(STR_PRF3);
	sprintf(msgbuf,"%.2f",bfclen/PFGRAN);
	prflin(STR_PRF14);
	sprintf(msgbuf,"%.2f",ini.chspac/PFGRAN);
	prflin(STR_PRF23);
	sprintf(msgbuf,"%.2f",ini.chrat);
	prflin(STR_PRF24);
	sprintf(msgbuf,"%.2f mm",ini.clpof/PFGRAN);
	prflin(STR_PRF21);
	sprintf(msgbuf,"%d",ini.faz);
	prflin(STR_PRF22);
	sprintf(msgbuf,"%.2f",ini.egrat);
	prflin(STR_PRF26);
	sprintf(msgbuf,"%.2f",ini.angl/PI*180);
	prflin(STR_PRF1);
	if(chku(SQRFIL))
		strcpy(msgbuf,stab[STR_SQR]);
	else
		strcpy(msgbuf,stab[STR_PNTD]);
	prflin(STR_PRF2);
	sprintf(msgbuf,"%.2f",stspace/PFGRAN);
	prflin(STR_PRF0);
	sprintf(msgbuf,"%d",duthrsh(shopnts));
	prflin(STR_PRF7);
	sprintf(msgbuf,"%.2f mm",ini.grdsiz/PFGRAN);
	prflin(STR_PRF20);
	sethup();
	sprintf(msgbuf,stab[STR_HUP0+ini.hup-1]);
	prflin(STR_PRF17);
	sprintf(msgbuf,"%.0f mm",ini.hupy/PFGRAN);
	prflin(STR_PRF27);
	sprintf(msgbuf,"%.0f mm",ini.hupx/PFGRAN);
	prflin(STR_PRF18);
	sprintf(msgbuf,"%.2f",ini.nudg);
	prflin(STR_PRF25);
	sprintf(msgbuf,"%.2f",picspac/PFGRAN);
	prflin(STR_PRF16);
	if(chku(BLUNT))
		strcpy(msgbuf,stab[STR_BLUNT]);
	else
		strcpy(msgbuf,stab[STR_TAPR]);
	prflin(STR_PRF15);
	if(chku(DUND))
		strcpy(msgbuf,stab[STR_ON]);
	else
		strcpy(msgbuf,stab[STR_OFF]);
	prflin(STR_PRF19);
	sprintf(msgbuf,"%.2f",smalsiz/PFGRAN);
	prflin(STR_PRF9);
	sprintf(msgbuf,"%.2f",snplen/PFGRAN);
	prflin(STR_PRF11);
	sprintf(msgbuf,"%.2f",spirwrap);
	prflin(STR_PRF13);
	sprintf(msgbuf,"%.2f",starat);
	prflin(STR_PRF12);
	sprintf(msgbuf,"%d",duthrsh(stchboxs));
	prflin(STR_PRF8);
	sprintf(msgbuf,"%.2f",ini.maxsiz/PFGRAN);
	prflin(STR_PRF4);
	sprintf(msgbuf,"%.2f",usesiz/PFGRAN);
	prflin(STR_PRF5);
	sprintf(msgbuf,"%.2f",minsiz/PFGRAN);
	prflin(STR_PRF6);
	setMap(PRFACT);
	ReleaseDC(hWnd,prfdc);
}
#endif

#if LANG==GRM

void prfmsg(){

	HDC		prfdc;
	RECT	prfrct;

	if(rstMap(INSRT))
		setMap(WASRT);
	rstMap(BIGBOX);
	fselpnt=0;
	if(hfdat){

		undat();
		unsid();
		sidtyp=0;
	}
	siz0.x=siz0.y=0;
	siz1.x=siz1.y=0;
	maxtsiz(stab[STR_PRF0+4],&siz0);
	maxtsiz(stab[STR_BLUNT],&siz1);
	siz0.x=prfsiz;
	siz1.x+=4;	
	DestroyWindow(hPrf);
	prfwid=siz0.x+siz1.x+18;
	hPrf=CreateWindow(
		"STATIC",
		0,
		WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3+3,
		3,
		prfwid,
		siz0.y*PRFLINS+12,
		hWnd,
		NULL,
		hInst,
		NULL);
	prfdc=GetDC(hPrf);
	GetClientRect(hPrf,&prfrct);
	FillRect(prfdc,&prfrct,(HBRUSH)(COLOR_WINDOW+1));
	loc0.top=loc1.top=3;
	loc0.bottom=loc1.bottom=3+siz0.y;
	loc0.left=3;
	loc0.right=3+siz0.x;
	loc1.left=6+siz0.x;
	loc1.right=6+siz0.x+siz1.x+6;
	sprintf(msgbuf,"%.2f",usesiz/PFGRAN);
	prflin(STR_PRF5);
	sprintf(msgbuf,"%.2f",ini.maxsiz/PFGRAN);
	prflin(STR_PRF4);
	sprintf(msgbuf,"%.2f",minsiz/PFGRAN);
	prflin(STR_PRF6);
	sprintf(msgbuf,"%.2f",smalsiz/PFGRAN);
	prflin(STR_PRF9);
	sprintf(msgbuf,"%.2f",ini.angl/PI*180);
	prflin(STR_PRF1);
	sprintf(msgbuf,"%.2f",stspace/PFGRAN);
	prflin(STR_PRF0);
	if(chku(SQRFIL))
		strcpy(msgbuf,stab[STR_SQR]);
	else
		strcpy(msgbuf,stab[STR_PNTD]);
	prflin(STR_PRF2);
	sprintf(msgbuf,"%.2f",brdwid/PFGRAN);
	prflin(STR_PRF3);
	if(chku(BLUNT))
		strcpy(msgbuf,stab[STR_BLUNT]);
	else
		strcpy(msgbuf,stab[STR_TAPR]);
	prflin(STR_PRF15);
	if(chku(DUND))
		strcpy(msgbuf,stab[STR_ON]);
	else
		strcpy(msgbuf,stab[STR_OFF]);
	prflin(STR_PRF19);
	sprintf(msgbuf,"%.2f",bfclen/PFGRAN);
	prflin(STR_PRF14);
	sprintf(msgbuf,"%.2f",ini.chspac/PFGRAN);
	prflin(STR_PRF23);
	sprintf(msgbuf,"%.2f",ini.chrat);
	prflin(STR_PRF24);
	sprintf(msgbuf,"%.2f mm",ini.clpof/PFGRAN);
	prflin(STR_PRF21);
	sprintf(msgbuf,"%d",ini.faz);
	prflin(STR_PRF22);
	sprintf(msgbuf,"%.2f",picspac/PFGRAN);
	prflin(STR_PRF16);
	sethup();
	sprintf(msgbuf,stab[STR_HUP0+ini.hup-1]);
	prflin(STR_PRF17);
	sprintf(msgbuf,"%.0f mm",ini.hupy/PFGRAN);
	prflin(STR_PRF27);
	sprintf(msgbuf,"%.0f mm",ini.hupx/PFGRAN);
	prflin(STR_PRF18);
	sprintf(msgbuf,"%.2f mm",ini.grdsiz/PFGRAN);
	prflin(STR_PRF20);
	sprintf(msgbuf,"%d",duthrsh(shopnts));
	prflin(STR_PRF7);
	sprintf(msgbuf,"%.2f",ini.nudg);
	prflin(STR_PRF25);
	sprintf(msgbuf,"%.2f",snplen/PFGRAN);
	prflin(STR_PRF11);
	sprintf(msgbuf,"%d",duthrsh(stchboxs));
	prflin(STR_PRF8);
	sprintf(msgbuf,"%.2f",ini.egrat);
	prflin(STR_PRF26);
	sprintf(msgbuf,"%.2f",spirwrap);
	prflin(STR_PRF13);
	sprintf(msgbuf,"%.2f",starat);
	prflin(STR_PRF12);
	sprintf(msgbuf,"%d",apcol+1);
	prflin(STR_PRF10);
	setMap(PRFACT);
	ReleaseDC(hWnd,prfdc);
}
#endif

void durpoli(unsigned nsids){

	double		dang;
	double		ang=0;
	double		len;
	unsigned	ind;
	DUBPNT		pnt;
	
	if(nsids<3)
		nsids=3;
	if(nsids>100)
		nsids=100;
	dang=PI*2/nsids;
	len=500/nsids*zumFct*(zum0.x+zum0.y)/(LHUPX+LHUPY);
	frmpnt=&formlst[formpnt];
	clofind=formpnt;
	frmclr(frmpnt);
	frmpnt->flt=adflt(nsids);
	frmpnt->sids=nsids;
	frmpnt->at=actl<<1;
	fvars(formpnt);
	px2stch();
	pnt.x=sPnt.x;
	pnt.y=sPnt.y;
	for(ind=0;ind<sids;ind++){

		flt[ind].x=pnt.x;
		flt[ind].y=pnt.y;
		pnt.x+=len*cos(ang);
		pnt.y+=len*sin(ang);
		ang+=dang;
	}
	frmpnt->typ=POLI;
	clofind=formpnt;
	frmout(formpnt);
	fmovdif.x=fmovdif.y=0;
	nuflen=nsids+1;
	setMap(POLIMOV);
	setmfrm();
	setMap(SHOFRM);
	mdufrm();
}

void dustar(unsigned nsids,double len){

	double		dang;
	double		ang;
	unsigned	ind,tsid;
	DUBPNT		pnt,cntr;
	
	if(nsids<3)
		nsids=3;
	if(nsids>100)
		nsids=100;
	dang=PI/nsids;
	ang=dang/2+PI;
	tsid=nsids<<1;
	frmpnt=&formlst[formpnt];
	clofind=formpnt;
	frmclr(frmpnt);
	frmpnt->flt=adflt(tsid);
	frmpnt->sids=tsid;
	frmpnt->at=(actl<<1);
	fvars(formpnt);
	px2stch();
	pnt.x=sPnt.x;
	pnt.y=sPnt.y;
	setMap(FILDIR);
	for(ind=0;ind<tsid;ind++){

		flt[ind].x=pnt.x;
		flt[ind].y=pnt.y;
		pnt.x+=len*cos(ang);
		pnt.y+=len*sin(ang);
		ang+=dang;
	}
	cntr.x=(flt[nsids].x-flt[0].x)/2+flt[0].x;
	cntr.y=(flt[nsids].y-flt[0].y)/2+flt[0].y;
	for(ind=1;ind<tsid;ind+=2){

		flt[ind].x=(flt[ind].x-cntr.x)*starat+cntr.x;
		flt[ind].y=(flt[ind].y-cntr.y)*starat+cntr.y;
	}
	frmpnt->typ=POLI;
	frmout(formpnt);
	fmovdif.x=fmovdif.y=0;
	nuflen=tsid+1;
	setMap(POLIMOV);
	setmfrm();
	setMap(SHOFRM);
	mdufrm();
}

void duspir(unsigned nsids){

	double		dang;
	double		ang=0;
	double		len,drat,rat;
	unsigned	ind,ine,num;
	DUBPNT		pnt;
	DUBPNT		cntr;
	FLPNT*		tflt;
	FLPNT*		tdif;
	
	if(nsids<3)
		nsids=3;
	if(nsids>100)
		nsids=100;
	dang=PI*2/nsids;
	len=800/nsids*zumFct*(zum0.x+zum0.y)/(LHUPX+LHUPY);
	frmpnt=&formlst[formpnt];
	clofind=formpnt;
	frmclr(frmpnt);
	num=nsids*spirwrap;
	frmpnt->flt=adflt(num);
	tflt=new FLPNT[nsids];
	tdif=new FLPNT[nsids];
	frmpnt->sids=num;
	frmpnt->at=(actl<<1);
	fvars(formpnt);
	px2stch();
	pnt.x=sPnt.x;
	pnt.y=sPnt.y;
	for(ind=0;ind<nsids;ind++){

		tflt[ind].x=pnt.x;
		tflt[ind].y=pnt.y;
		pnt.x+=len*cos(ang);
		pnt.y+=len*sin(ang);
		ang+=dang;
	}
	cntr.x=(tflt[nsids>>1].x-tflt[0].x)/2+tflt[0].x;
	cntr.y=(tflt[nsids>>1].y-tflt[0].y)/2+tflt[0].y;
	for(ind=0;ind<nsids;ind++){

		tdif[ind].x=tflt[ind].x-cntr.x;
		tdif[ind].y=tflt[ind].y-cntr.y;
	}
	drat=(double)1/num;
	rat=drat;ine=0;
	for(ind=0;ind<num;ind++){

		frmpnt->flt[ine].x=tdif[ine%nsids].x*rat+cntr.x;
		frmpnt->flt[ine].y=tdif[ine%nsids].y*rat+cntr.y;
		rat+=drat;
		ine++;
	}
	frmpnt->typ=LIN;
	frmout(formpnt);
	fmovdif.x=fmovdif.y=0;
	nuflen=num+1;
	setMap(POLIMOV);
	setmfrm();
	setMap(SHOFRM);
	mdufrm();
	delete tflt;
	delete tdif;
}

void duhart(unsigned nsids){

	double		dang;
	double		ang;
	double		len;
	unsigned	ind,ine,bind;
	float		av;
	DUBPNT		pnt;
	double		rat;
	
	if(nsids>100)
		nsids=100;
	if(nsids<6)
		nsids=6;
	frmpnt=&formlst[formpnt];
	frmclr(frmpnt);
	frmpnt->at=actl<<1;
	flt=&flts[fltad];
	px2stch();
	pnt.x=sPnt.x;
	pnt.y=sPnt.y;
	dang=PI*2/nsids;
	len=300/nsids*zumFct*(zum0.x+zum0.y)/(LHUPX+LHUPY);
	ang=PI*0.28;
	ind=0;
	av=0;
	while(ang>-PI*0.7){

		if(pnt.x>av)
			av=pnt.x;
		flt[ind].x=pnt.x;
		flt[ind++].y=pnt.y;
		pnt.x+=len*cos(ang);
		pnt.y+=len*sin(ang);
		ang-=dang;
	}
	dang/=4.5;
	bind=ind;
	while(pnt.x>flt[0].x&&ind<200){

		flt[ind].x=pnt.x;
		flt[ind++].y=pnt.y;
		pnt.x+=len*cos(ang);
		pnt.y+=len*sin(ang);
		ang-=dang;
	}
	bind--;
	rat=(flt[bind].x-flt[0].x)/(flt[bind].x-flt[ind-1].x);
	for(ine=bind+1;ine<ind;ine++)
		flt[ine].x=(flt[ine].x-flt[bind].x)*rat+flt[bind].x;
	bind=ine;
	for(ind=bind-2;ind;ind--){

		flt[ine].y=flt[ind].y;
		flt[ine].x=av+av-flt[ind].x-2*(av-flt[0].x);
		ine++;
	}
	nuflen=ine+1;
	frmpnt->flt=adflt(ine);
	frmpnt->sids=ine;
	frmpnt->typ=POLI;
	clofind=formpnt;
	frmout(formpnt);
	fmovdif.x=fmovdif.y=0;
	setMap(POLIMOV);
	setmfrm();
	setMap(SHOFRM);
	mdufrm();
}

void dulens(unsigned nsids){

	double		dang;
	double		ang;
	double		len;
	unsigned	ind,ine,bind,cnt;
	float		av;
	DUBPNT		pnt;
	
	if(nsids<6)
		nsids=6;
	if(nsids>48)
		nsids=48;
	nsids<<=1;
	dang=PI*2/nsids;
	cnt=nsids/2*0.3;
	ang=cnt*dang;
	len=500/nsids*zumFct*(zum0.x+zum0.y)/(LHUPX+LHUPY);
	frmpnt=&formlst[formpnt];
	clofind=formpnt;
	frmclr(frmpnt);
	frmpnt->flt=&flts[fltad];
	frmpnt->at=actl<<1;
	fvars(formpnt);
	px2stch();
	pnt.x=sPnt.x;
	pnt.y=sPnt.y;
	ind=0;
	sPnt.x-=(float)0.0001;
	while(pnt.x>=sPnt.x){

		flt[ind].x=pnt.x;
		flt[ind++].y=pnt.y;
		pnt.x+=len*cos(ang);
		pnt.y+=len*sin(ang);
		ang+=dang;
	}
	bind=ind-2;
	ine=ind;
	av=flt[0].x;
	for(ind=bind;ind<nsids-3;ind--){

		flt[ine].y=flt[ind].y;
		flt[ine].x=av+av-flt[ind].x;
		ine++;
	}
	nuflen=ine;
	frmpnt->flt=adflt(ine-1);
	frmpnt->sids=ine-1;
	frmpnt->typ=POLI;
	clofind=formpnt;
	frmout(formpnt);
	fmovdif.x=fmovdif.y=0;
	setMap(POLIMOV);
	setmfrm();
	setMap(SHOFRM);
	mdufrm();
}

float shreg(float hi,float ref){

	return (hi-ref)*egrat+ref;
}

void dueg(unsigned nsids){

	double		ref,hi;
	unsigned	ind;

	if(nsids<8)
		nsids=8;
	fvars(formpnt);
	durpoli(nsids);
	ref=midl(flt[nsids/2].y,flt[0].y);
	hi=flt[nsids>>2].y-flt[0].y;
	for(ind=0;ind<nsids;ind++){

		if(flt[ind].y<ref)
			flt[ind].y=ref-(ref-flt[ind].y)*ini.egrat;
	}
	egrat=hi/(flt[nsids>>2].y-flt[0].y);
	for(ind=1;ind<sids;ind++){

		flt[ind].x=shreg(flt[ind].x,flt[0].x);
		flt[ind].y=shreg(flt[ind].y,flt[0].y);
	}
}

void duzig(unsigned nsids){

	FLPNT		off;
	unsigned	ind;

	if(nsids<3)
		nsids=3;
	if(nsids>100)
		nsids=100;
	frmpnt=&formlst[formpnt];
	clofind=formpnt;
	frmclr(frmpnt);
	frmpnt->flt=adflt(nsids);
	frmpnt->sids=nsids;
	frmpnt->at=actl<<1;
	fvars(formpnt);
	px2stch();
	sPnt.x;
	sPnt.y;
	off.x=zum0.x/6;
	off.y=zum0.y/(6*nsids);
	for(ind=0;ind<nsids;ind++){
	
		flt[ind].x=sPnt.x;
		flt[ind].y=sPnt.y;
		sPnt.y-=off.y;
		if(ind&1)
			sPnt.x+=off.x;
		else
			sPnt.x-=off.x;
	}
	frmpnt->typ=LIN;
	clofind=formpnt;
	frmout(formpnt);
	fmovdif.x=fmovdif.y=0;
	nuflen=nsids+1;
	setMap(POLIMOV);
	setmfrm();
	setMap(SHOFRM);
	mdufrm();
}
	
void fliph(){

	unsigned	ind,ine;
	float		av=0;
	FLRCT		trct;

	fvars(clofind);
	if(chkMap(FPSEL)){

		savdo();
		av=(pselrct.right-pselrct.left)*0.5+pselrct.left;
		ine=pselrng.strt;
		for(ind=0;ind<=pselrng.cnt;ind++){

			flt[ine].x=av+av-flt[ine].x;
			ine=pdir(ine);
		}
		setMap(RESTCH);
		return;
	}
	if(chkMap(BIGBOX)){

		av=(rctal.right-rctal.left)/2+rctal.left;
		for(ind=0;ind<fltad;ind++)
			flts[ind].x=av+av-flts[ind].x;
		for(ind=0;ind<hed.stchs;ind++)
			stchs[ind].x=av+av-stchs[ind].x;
		for(ind=0;ind<formpnt;ind++){

			formlst[ind].rct.left=av+av-formlst[ind].rct.left;
			formlst[ind].rct.right=av+av-formlst[ind].rct.right;
		}
		setMap(RESTCH);
		return;
	}
	if(fselpnt){

		savdo();
		clRmap((formpnt>>5)+1);
		pxrct2stch(bigrct,&trct);
		av=(trct.right-trct.left)/2+trct.left;
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			setr(clofind);
			fvars(clofind);
			for(ine=0;ine<frmpnt->sids;ine++)
				flt[ine].x=av+av-flt[ine].x;
			frmout(clofind);
		}
		for(ind=0;ind<hed.stchs;ind++){

			ine=(stchs[ind].at&FRMSK)>>FRMSHFT;
			if(chkr(ine)&&!(stchs[ind].at&NOTFRM))
				stchs[ind].x=av+av-stchs[ind].x;
		}
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			av=(frmpnt->rct.right-frmpnt->rct.left)/2+frmpnt->rct.left;
			for(ind=0;ind<sids;ind++)
				flt[ind].x=av+av-flt[ind].x;
			for(ind=0;ind<hed.stchs;ind++){
		
				if((stchs[ind].at&FRMSK)>>FRMSHFT==clofind&&!(stchs[ind].at&NOTFRM))
					stchs[ind].x=av+av-stchs[ind].x;
			}
			frmout(clofind);
			setMap(RESTCH);
		}
		else{

			if(chkMap(GRPSEL)){

				savdo();
				rngadj();
				selRct(&trct);
				av=(trct.right-trct.left)/2+trct.left;
				for(ind=gpnt0;ind<=gpnt1;ind++)
					stchs[ind].x=av+av-stchs[ind].x;
				setMap(RESTCH);
			}
		}
	}
}

void flipv(){

	unsigned	ind,ine;
	float		av=0;
	FLRCT		trct;

	fvars(clofind);
	if(chkMap(FPSEL)){

		savdo();
		av=(pselrct.top-pselrct.bottom)*0.5+pselrct.bottom;
		ine=pselrng.strt;
		for(ind=0;ind<=pselrng.cnt;ind++){

			flt[ine].y=av+av-flt[ine].y;
			ine=pdir(ine);
		}
		setMap(RESTCH);
		return;
	}
	if(chkMap(BIGBOX)){

		savdo();
		av=(rctal.top-rctal.bottom)/2+rctal.bottom;
		for(ind=0;ind<fltad;ind++)
			flts[ind].y=av+av-flts[ind].y;
		for(ind=0;ind<hed.stchs;ind++)
			stchs[ind].y=av+av-stchs[ind].y;
		for(ind=0;ind<formpnt;ind++){

			formlst[ind].rct.bottom=av+av-formlst[ind].rct.bottom;
			formlst[ind].rct.top=av+av-formlst[ind].rct.top;
		}
		setMap(RESTCH);
		return;
	}
	if(fselpnt){

		savdo();
		clRmap((formpnt>>5)+1);
		pxrct2stch(bigrct,&trct);
		av=(trct.top-trct.bottom)/2+trct.bottom;
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			setr(clofind);
			fvars(clofind);
			for(ine=0;ine<frmpnt->sids;ine++)
				flt[ine].y=av+av-flt[ine].y;
			frmout(clofind);
		}
		for(ind=0;ind<hed.stchs;ind++){

			ine=(stchs[ind].at&FRMSK)>>FRMSHFT;
			if(chkr(ine)&&!(stchs[ind].at&NOTFRM))
				stchs[ind].y=av+av-stchs[ind].y;
		}
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			av=(frmpnt->rct.top-frmpnt->rct.bottom)/2+frmpnt->rct.bottom;
			for(ind=0;ind<sids;ind++)
				flt[ind].y=av+av-flt[ind].y;
			for(ind=0;ind<hed.stchs;ind++){
		
				if((stchs[ind].at&FRMSK)>>FRMSHFT==clofind&&!(stchs[ind].at&NOTFRM))
					stchs[ind].y=av+av-stchs[ind].y;
			}
			frmout(clofind);
			setMap(RESTCH);
		}
		else{

			if(chkMap(GRPSEL)){

				savdo();
				rngadj();
				selRct(&trct);
				av=(trct.top-trct.bottom)/2+trct.bottom;
				for(ind=gpnt0;ind<=gpnt1;ind++)
					stchs[ind].y=av+av-stchs[ind].y;
				setMap(RESTCH);
			}
		}
	}
}

void tomsg(){

	RECT	okrct;
	SIZE	tsiz;

	GetWindowRect(hok,&okrct);
	GetTextExtentPoint32(sdc,stab[STR_DELST2],strlen(stab[STR_DELST2]),&tsiz);
	hto=CreateWindow(
		"STATIC",
		stab[STR_DELST2],
		SS_NOTIFY|WS_CHILD|WS_VISIBLE|WS_BORDER,
		3,
		okrct.bottom-stOrg.y+6+tsiz.cy,
		tsiz.cx+6,
		tsiz.cy+6,
		hStch,
		NULL,
		hInst,
		NULL);
}

void sprct(unsigned strt,unsigned fin){

	DUBPNT	dif,tpnt;
	VRCT2*	tvrct;
	
	tvrct=&pvrct[strt];
	dif.x=opnts[fin].x-opnts[strt].x;
	dif.y=opnts[fin].y-opnts[strt].y;
	if(dif.x&&dif.y){

		slop=-dif.x/dif.y;
		tpnt.x=flt[fin].x;
		tpnt.y=flt[fin].y;
		proj(tpnt,slop,opnts[strt],opnts[fin],&tvrct->dopnt);
		proj(tpnt,slop,ipnts[strt],ipnts[fin],&tvrct->dipnt);
		tpnt.x=flt[strt].x;
		tpnt.y=flt[strt].y;
		proj(tpnt,slop,opnts[strt],opnts[fin],&tvrct->aopnt);
		proj(tpnt,slop,ipnts[strt],ipnts[fin],&tvrct->aipnt);
		tpnt.x=ipnts[strt].x;
		tpnt.y=ipnts[strt].y;
		if(proj(tpnt,slop,opnts[strt],opnts[fin],&tvrct->bopnt)){

			tvrct->bipnt.x=ipnts[strt].x;
			tvrct->bipnt.y=ipnts[strt].y;
		}
		else{

			tvrct->bopnt.x=opnts[strt].x;
			tvrct->bopnt.y=opnts[strt].y;
			tpnt.x=opnts[strt].x;
			tpnt.y=opnts[strt].y;
			proj(tpnt,slop,ipnts[strt],ipnts[fin],&tvrct->bipnt);
		}
		tpnt.x=ipnts[fin].x;
		tpnt.y=ipnts[fin].y;
		if(proj(tpnt,slop,opnts[strt],opnts[fin],&tvrct->copnt)){

			tvrct->cipnt.x=ipnts[fin].x;
			tvrct->cipnt.y=ipnts[fin].y;
		}
		else{

			tvrct->copnt.x=opnts[fin].x;
			tvrct->copnt.y=opnts[fin].y;
			tpnt.x=opnts[fin].x;
			tpnt.y=opnts[fin].y;
			proj(tpnt,slop,ipnts[strt],ipnts[fin],&tvrct->cipnt);
		}
	}
	else{

		if(dif.x){

			tpnt.x=flt[fin].x;
			projv(tpnt.x,opnts[strt],opnts[fin],&tvrct->dopnt);
			projv(tpnt.x,ipnts[strt],ipnts[fin],&tvrct->dipnt);
			tpnt.x=flt[strt].x;
 			projv(tpnt.x,opnts[strt],opnts[fin],&tvrct->aopnt);
			projv(tpnt.x,ipnts[strt],ipnts[fin],&tvrct->aipnt);
			tpnt.x=ipnts[strt].x;
			if(projv(tpnt.x,opnts[strt],opnts[fin],&tvrct->bopnt)){

				tvrct->bipnt.x=ipnts[strt].x;
				tvrct->bipnt.y=ipnts[strt].y;
			}
			else{

				tvrct->bopnt.x=opnts[strt].x;
				tvrct->bopnt.y=opnts[strt].y;
				tpnt.x=opnts[strt].x;
				projv(tpnt.x,ipnts[strt],ipnts[fin],&tvrct->bipnt);
			}
			tpnt.x=ipnts[fin].x;
			if(projv(tpnt.x,opnts[strt],opnts[fin],&tvrct->copnt)){

				tvrct->cipnt.x=ipnts[fin].x;
				tvrct->cipnt.y=ipnts[fin].y;
			}
			else{

				tvrct->copnt.x=opnts[fin].x;
				tvrct->copnt.y=opnts[fin].y;
				tpnt.x=opnts[fin].x;
				projv(tpnt.x,ipnts[strt],ipnts[fin],&tvrct->cipnt);
			}
		}
		else{

			tpnt.y=flt[fin].y;
			projh(tpnt.y,opnts[strt],opnts[fin],&tvrct->dopnt);
			projh(tpnt.y,ipnts[strt],ipnts[fin],&tvrct->dipnt);
			tpnt.y=flt[strt].y;
			projh(tpnt.y,opnts[strt],opnts[fin],&tvrct->aopnt);
			projh(tpnt.y,ipnts[strt],ipnts[fin],&tvrct->aipnt);
			tpnt.y=ipnts[strt].y;
			if(projh(tpnt.y,opnts[strt],opnts[fin],&tvrct->bopnt)){

				tvrct->bipnt.x=ipnts[strt].x;
				tvrct->bipnt.y=ipnts[strt].y;
			}
			else{

				tvrct->bopnt.x=opnts[strt].x;
				tvrct->bopnt.y=opnts[strt].y;
				tpnt.y=opnts[strt].y;
				projh(tpnt.y,ipnts[strt],ipnts[fin],&tvrct->bipnt);
			}
			tpnt.y=ipnts[fin].y;
			if(projh(tpnt.y,opnts[strt],opnts[fin],&tvrct->copnt)){

				tvrct->cipnt.x=ipnts[fin].x;
				tvrct->cipnt.y=ipnts[fin].y;
			}
			else{

				tvrct->copnt.x=opnts[fin].x;
				tvrct->copnt.y=opnts[fin].y;
				tpnt.y=opnts[fin].y;
				projh(opnts[fin].y,ipnts[strt],ipnts[fin],&tvrct->cipnt);
			}
		}
	}
}

void spurfn(DUBPNT* ipnt,DUBPNT* opnt,DUBPNT* uipnt,DUBPNT* uopnt){

	DUBPNT	dif;

	dif.x=opnt->x-ipnt->x;
	dif.y=opnt->y-ipnt->y;
	uipnt->x=dif.x*DIURAT+ipnt->x;
	uipnt->y=dif.y*DIURAT+ipnt->y;
	uopnt->x=dif.x*DOURAT+ipnt->x;
	uopnt->y=dif.y*DOURAT+ipnt->y;
}

void spurct(unsigned ind){

	spurfn(&pvrct[ind].aipnt,&pvrct[ind].aopnt,&uvrct[ind].aipnt,&uvrct[ind].aopnt);
	spurfn(&pvrct[ind].bipnt,&pvrct[ind].bopnt,&uvrct[ind].bipnt,&uvrct[ind].bopnt);
	spurfn(&pvrct[ind].cipnt,&pvrct[ind].copnt,&uvrct[ind].cipnt,&uvrct[ind].copnt);
	spurfn(&pvrct[ind].dipnt,&pvrct[ind].dopnt,&uvrct[ind].dipnt,&uvrct[ind].dopnt);
}

unsigned psg(){

	unsigned tmp;

	if(!psgacc)
		psgacc=SEED;
	tmp=psgacc&0x48000000;
	psgacc<<=1;
	if(tmp==0x40000000||tmp==0x8000000)
		psgacc++;
	return psgacc;
}

void duromb(DUBPNT strt0,DUBPNT fin0,DUBPNT strt1,DUBPNT fin1){

	DUBPNT		dif0,dif1,stp0,stp1;
	double		len0,len1;
	unsigned	cnt,ind;

	if(!chkMap(UND)){

		dif0.x=sPnt.x-strt0.x;
		dif0.y=sPnt.y-strt0.y;
		dif1.x=sPnt.x-strt1.x;
		dif1.y=sPnt.y-strt1.y;
		len0=hypot(dif0.x,dif0.y);
		len1=hypot(dif1.x,dif1.y);
		if(len0>len1)
			setMap(FILDIR);
		else
			rstMap(FILDIR);
	}
	dif0.x=fin0.x-strt0.x;
	dif0.y=fin0.y-strt0.y;
	dif1.x=fin1.x-strt1.x;
	dif1.y=fin1.y-strt1.y;
	len0=hypot(dif0.x,dif0.y);
	cnt=len0/(stspace/2);
	if(!cnt)
		cnt++;
	stp0.x=dif0.x/cnt;
	stp0.y=dif0.y/cnt;
	stp1.x=dif1.x/cnt;
	stp1.y=dif1.y/cnt;
	for(ind=0;ind<cnt;ind++){

		if(toglMap(FILDIR))
			filinsb(strt0);
		else
			filinsb(strt1);
		strt0.x+=stp0.x;
		strt0.y+=stp0.y;
		strt1.x+=stp1.x;
		strt1.y+=stp1.y;
	}
}

void spend(unsigned strt,unsigned fin){

	double		ilen,olen;
	DUBPNT		idif,odif;
	double		sang,fang,dang,stang;
	DUBPNT		sdif,fdif;
	DUBPNT		piv;
	double		rad,arc,irad;
	unsigned	ind,cnt,lvl;
	DUBPNT		ipnt,opnt;

	idif.x=pvrct[fin].cipnt.x-pvrct[strt].bipnt.x;
	idif.y=pvrct[fin].cipnt.y-pvrct[strt].bipnt.y;
	odif.x=pvrct[fin].copnt.x-pvrct[strt].bopnt.x;
	odif.y=pvrct[fin].copnt.y-pvrct[strt].bopnt.y;
	ilen=hypot(idif.x,idif.y);
	olen=hypot(odif.x,odif.y);
	if(olen>ilen){

		piv.x=pvrct[strt].cipnt.x;
		piv.y=pvrct[strt].cipnt.y;
		sdif.x=pvrct[strt].copnt.x-piv.x;
		sdif.y=pvrct[strt].copnt.y-piv.y;
		fdif.x=pvrct[fin].bopnt.x-piv.x;
		fdif.y=pvrct[fin].bopnt.y-piv.y;
	}
	else{

		piv.x=pvrct[strt].copnt.x;
		piv.y=pvrct[strt].copnt.y;
		sdif.x=pvrct[strt].cipnt.x-piv.x;
		sdif.y=pvrct[strt].cipnt.y-piv.y;
		fdif.x=pvrct[fin].bipnt.x-piv.x;
		fdif.y=pvrct[fin].bipnt.y-piv.y;
	}
	if(hypot(sPnt.x-piv.x,sPnt.y-piv.y)>2*PI)
		filinsb(piv);
	sang=atan2(sdif.y,sdif.x);
	fang=atan2(fdif.y,fdif.x);
	dang=fang-sang;
	if(dang>PI)
		dang-=2*PI;
	if(dang<-PI)
		dang+=2*PI;
	rad=hypot(sdif.x,sdif.y);
	arc=fabs(rad*dang);
	cnt=arc/stspace;
	stang=dang/cnt;
	if(!cnt)
		cnt=1;
	for(ind=0;ind<cnt;ind++){

		opnt.x=piv.x+cos(sang)*rad;
		opnt.y=piv.y+sin(sang)*rad;
		filinsb(opnt);
		if(cnt&0xfffffff0)
			lvl=psg()%cnt;
		else
			lvl=lvls[cnt][ind];
		irad=rad*lvl/cnt*0.4;
		ipnt.x=piv.x+cos(sang)*irad;
		ipnt.y=piv.y+sin(sang)*irad;
		filinsb(ipnt);
		sang+=stang;
	}
}

void duspnd(unsigned strt,unsigned fin){

	double	len,tang;
	DUBPNT	tpnt,dif;

	if(chkMap(UND)){

		if(chkMap(UNDPHAS)){

			filinsb(uvrct[strt].copnt);
			filinsb(uvrct[strt].cipnt);
			dif.x=uvrct[fin].bipnt.x-uvrct[strt].cipnt.x;
			dif.y=uvrct[fin].bipnt.y-uvrct[strt].cipnt.y;
			len=hypot(dif.x,dif.y);
			if(len>frmpnt->elen){

				tang=atan2(ipnts[fin].y-opnts[fin].y,ipnts[fin].x-opnts[fin].x);
				tpnt.x=uvrct[fin].bopnt.x+cos(tang)*plen;
				tpnt.y=uvrct[fin].bopnt.y+sin(tang)*plen;
				filinsb(tpnt);
			}
			filinsb(uvrct[fin].bipnt);
			filinsb(uvrct[fin].bopnt);
		}
		else{

			filinsb(uvrct[strt].cipnt);
			filinsb(uvrct[strt].copnt);
			dif.x=uvrct[fin].bopnt.x-uvrct[strt].copnt.x;
			dif.y=uvrct[fin].bopnt.y-uvrct[strt].copnt.y;
			len=hypot(dif.x,dif.y);
			if(len>frmpnt->elen){

				tang=atan2(opnts[fin].y-ipnts[fin].y,opnts[fin].x-ipnts[fin].x);
				tpnt.x=uvrct[fin].bipnt.x+cos(tang)*plen;
				tpnt.y=uvrct[fin].bipnt.y+sin(tang)*plen;
				filinsb(tpnt);
			}
			filinsb(uvrct[fin].bopnt);
			filinsb(uvrct[fin].bipnt);
		}
	}
	else
		spend(strt,fin);
}

void pfn(unsigned strtlin,VRCT2* vrct){

	unsigned		ind;
	unsigned short	nlin;

	sPnt.x=flt[strtlin].x;
	sPnt.y=flt[strtlin].y;
	nlin=nxt(strtlin);
	for(ind=0;ind<frmpnt->sids;ind++){

		duromb(vrct[strtlin].bipnt,vrct[strtlin].cipnt,vrct[strtlin].bopnt,vrct[strtlin].copnt);
		duspnd(strtlin,nlin);
		strtlin=nlin;
		nlin=nxt(nlin);
	}
}

/*
void plfn(double spac,VRCT2* prct){

	unsigned	ind;

	duromb(prct[0].aipnt,prct[0].cipnt,prct[0].aopnt,prct[0].copnt);
	duspnd(0,1);
	for(ind=1;ind<(unsigned)sids-2;ind++){

		duromb(prct[ind].bipnt,prct[ind].cipnt,prct[ind].bopnt,prct[ind].copnt);
		duspnd(ind,ind+1);
	}
	duromb(prct[sids-2].bipnt,prct[sids-2].dipnt,prct[sids-2].bopnt,prct[sids-2].dopnt);
}*/

void plfn(double spac,VRCT2* prct){

	unsigned	ind;

	duromb(prct[1].aipnt,prct[1].cipnt,prct[1].aopnt,prct[1].copnt);
	duspnd(1,2);
	for(ind=2;ind<(unsigned)sids-4;ind++){

		duromb(prct[ind].bipnt,prct[ind].cipnt,prct[ind].bopnt,prct[ind].copnt);
		duspnd(ind,ind+1);
	}
	duromb(prct[sids-4].bipnt,prct[sids-4].dipnt,prct[sids-4].bopnt,prct[sids-4].dopnt);
}

void prsmal(){

	unsigned	ind,ine,ref;
	double		siz,len;
	DUBPNT		dif;

	ref=0;ine=0;
	siz=USPAC*0.8;
	if(siz>plen)
		siz=plen*0.9;
	for(ind=1;ind<seqpnt;ind++){

		dif.x=oseq[ind].x-oseq[ref].x;
		dif.y=oseq[ind].y-oseq[ref].y;
		len=hypot(dif.x,dif.y);
		if(len>siz){

			oseq[ine].x=oseq[ind].x;
			oseq[ine++].y=oseq[ind].y;
			ref=ind;
		}
	}
	seqpnt=ine;
}

void plbak(unsigned bpnt){

	unsigned	ind=seqpnt-1;
	FLPNT		tflt;

	while(ind>bpnt){

		tflt.x=oseq[ind].x;
		tflt.y=oseq[ind].y;
		oseq[ind].x=oseq[bpnt].x;
		oseq[ind].y=oseq[bpnt].y;
		oseq[bpnt].x=tflt.x;
		oseq[bpnt].y=tflt.y;
		ind--;bpnt++;
	}
}

void plvct(unsigned pind,DUBPNT* vp0,DUBPNT* vp1,double len)
{
	double angl;
	double len2;
	FLPNT vct;

	len2=len/2;
	angl=atan2(flt[pind+1].y-flt[pind].y,flt[pind+1].x-flt[pind].x)+PI/2;
	vct.x=cos(angl)*len2;
	vct.y=sin(angl)*len2;
	vp0->x=flt[pind].x+vct.x;
	vp0->y=flt[pind].y+vct.y;
	vp1->x=flt[pind].x-vct.x;
	vp1->y=flt[pind].y-vct.y;
}

void prebrd()
{
	FLPNT dif;
	double rat;

	MoveMemory(&angflt[1],flt,sizeof(FLPNT)*sids);
	dif.x=flt[1].x-flt[0].x;
	dif.y=flt[1].y-flt[0].y;
	if(fabs(dif.x)>fabs(dif.y))
		rat=fabs(0.1/dif.x);
	else
		rat=fabs(0.1/dif.y);
	angflt[0].x=flt[0].x-dif.x*rat;
	angflt[0].y=flt[0].y-dif.y*rat;
	MoveMemory(&angfrm,frmpnt,sizeof(FRMHED));
	angfrm.flt=angflt;
	angfrm.sids+=3;
	dif.x=flt[sids-1].x-flt[sids-2].x;
	dif.y=flt[sids-1].y-flt[sids-2].y;
	if(dif.x>dif.y)
		rat=0.1/dif.x;
	else
		rat=0.1/dif.y;
	angflt[angfrm.sids-1].x=flt[sids-1].x+dif.x*rat;
	angflt[angfrm.sids-1].y=flt[sids-1].y+dif.y*rat;
	frmpnt=&angfrm;
	sids=angfrm.sids;
	flt=angfrm.flt;
}

void plbrd(double spac){

	double			tspac;
	unsigned short	slin=getlast();
	unsigned bpnt;
	unsigned ind;

	prebrd();
	tspac=stspace;
	pvrct=(VRCT2*)bseq;
	uvrct=&pvrct[sids];
	satout(frmpnt->esiz);
	ipnts[sids].x=ipnts[0].x;
	ipnts[sids].y=ipnts[0].y;
	opnts[sids].x=opnts[0].x;
	opnts[sids].y=opnts[0].y;
	for(ind=0;ind<(unsigned)sids-1;ind++)
	{
		sprct(ind,ind+1);
		spurct(ind);
	}
	sprct(ind,0);
	spurct(ind);
	if(!(frmpnt->at&SBLNT))
	{
		pvrct[1].aipnt.x=pvrct[1].aopnt.x=uvrct[1].aipnt.x=uvrct[1].aopnt.x=frmpnt->flt[1].x;
		pvrct[1].aipnt.y=pvrct[1].aopnt.y=uvrct[1].aipnt.y=uvrct[1].aopnt.y=frmpnt->flt[1].y;
	}
	if(!(frmpnt->at&FBLNT))
	{
		pvrct[sids-4].dipnt.x=pvrct[sids-4].dopnt.x=uvrct[sids-4].dipnt.x=uvrct[sids-4].dopnt.x=frmpnt->flt[sids-1].x;
		pvrct[sids-4].dipnt.y=pvrct[sids-4].dopnt.y=uvrct[sids-4].dipnt.y=uvrct[sids-4].dopnt.y=frmpnt->flt[sids-1].y;
	}
	seqpnt=0;
	sPnt.x=flt[0].x;
	sPnt.y=flt[0].y;
	if(frmpnt->etyp&EGUND){

		stspace=USPAC;
		setMap(UND);
		plen=frmpnt->esiz*URAT;
		setMap(UNDPHAS);
		rstMap(FILDIR);
		plfn(USPAC,&uvrct[0]);
		bpnt=seqpnt;
		rstMap(UNDPHAS);
		sPnt.x=flt[0].x;
		sPnt.y=flt[0].y;
		setMap(FILDIR);
		plfn(USPAC,&uvrct[0]);
		plbak(bpnt);
		prsmal();
		sPnt.x=oseq[seqpnt-1].x;
		sPnt.y=oseq[seqpnt-1].y;
	}
	rstMap(UND);
	stspace=frmpnt->espac;
	plfn(stspace,&pvrct[0]);
	stspace=spac;
	fvars(clofind);
}

void pbrd(double spac){

	double			tspac;
	unsigned		ind;
	unsigned		strt;

	tspac=stspace;
	stspace=frmpnt->espac;
	seqpnt=0;
	pvrct=(VRCT2*)bseq;
	uvrct=&pvrct[sids];
	strt=getlast();
	satout(frmpnt->esiz);
	for(ind=0;ind<(unsigned)sids-1;ind++){

		sprct(ind,ind+1);
		spurct(ind);
	}
	sprct(ind,0);
	spurct(ind);
	if(frmpnt->etyp&EGUND){

		rstMap(SAT1);
		stspace=USPAC;
		setMap(UND);
		plen=frmpnt->esiz*URAT;
		satout(plen);
		setMap(UNDPHAS);
		setMap(FILDIR);
		pfn(strt,&uvrct[0]);
		rstMap(UNDPHAS);
		rstMap(FILDIR);
		pfn(strt,&uvrct[0]);
		stspace=spac;
		prsmal();
		plen=frmpnt->esiz;
		rstMap(UND);
	}
	pfn(strt,&pvrct[0]);
	stspace=tspac;
}
	
void prpsbrd(){

	if(frmpnt->sids>2){

		deleclp(clofind);
		frmpnt->etyp=EGPRP;
		if(chku(DUND))
			frmpnt->etyp|=EGUND;
		bsizpar();
		frmpnt->esiz=brdwid;
		frmpnt->espac=stspace;
		frmpnt->bcol=actcol;
		refilfn();
	}
}

void prpbrd(double spac){

	double		tspac=stspace;
	unsigned	ind;

	if(filmsgs(FML_PRPS))
		return;
	stspace=spac;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			frmpnt->esiz=stspace;
			if(chku(BLUNT))
				frmpnt->at|=(SBLNT|FBLNT);
			else
				frmpnt->at&=NOBLNT;
			prpsbrd();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			fvars(clofind);
			if(chku(BLUNT))
				frmpnt->at|=(SBLNT|FBLNT);
			else
				frmpnt->at&=NOBLNT;
			prpsbrd();
			setMap(INIT);
			coltab();
			ritot(hed.stchs);
			setMap(RESTCH);
		}
	}
	stspace=tspac;
}

void tglfrm(){

	if(rstMap(SATPNT))
		satfix();
	rstMap(HIDSTCH);
	if(toglMap(FRMOF))
		strcpy(oftxt,stab[STR_FRMPLUS]);
	else{

		strcpy(oftxt,stab[STR_FRMINUS]);
		rstMap(FORMSEL);
		rstMap(FORMIN);
		rstMap(MOVFRM);
		rstMap(FRMPMOV);
		rstMap(FRMOV);
		rstMap(SATIN);
		rstMap(SATPNT);		
		rstMap(SATCNKT);	
		rstMap(FENDIN);		
		rstMap(DELFRM);		
		rstMap(FRMPSEL);
		rstMap(INSFRM);
	}
	SetMenuItemInfo(hMen,ID_FRMOF,FALSE,&meninfo);
	setMap(DUMEN);
	setMap(RESTCH);
}

void frmon(){

	unbsho();
	rstMap(FRMOF);
	strcpy(oftxt,stab[STR_FRMPLUS]);
	SetMenuItemInfo(hMen,ID_FRMOF,FALSE,&meninfo);
	setMap(DUMEN);
}

void fnord(){

	int			ind;
	SHRTPNT		tpnt;

	fvars(clofind);
	frmpnt=&formlst[clofind];
	for(ind=0;ind<frmpnt->sids>>1;ind++){

		tpnt.x=frmpnt->flt[ind].x;
		tpnt.y=frmpnt->flt[ind].y;
		frmpnt->flt[ind].x=frmpnt->flt[frmpnt->sids-ind-1].x;
		frmpnt->flt[ind].y=frmpnt->flt[frmpnt->sids-ind-1].y;
		frmpnt->flt[frmpnt->sids-ind-1].x=tpnt.x;
		frmpnt->flt[frmpnt->sids-ind-1].y=tpnt.y;
	}
	refil();
}

void flpord(){

	int			ind;
	unsigned	uind,strt,fin;
	SHRTPNT		tpnt;

	fvars(clofind);
	if(chkMap(FPSEL)){

		savdo();
		strt=pselrng.strt;
		fin=(pselrng.strt+pselrng.cnt)%sids;
		for(uind=0;uind<=pselrng.cnt>>1;uind++){

			tpnt.x=frmpnt->flt[strt].x;
			tpnt.y=frmpnt->flt[strt].y;
			frmpnt->flt[strt].x=frmpnt->flt[fin].x;
			frmpnt->flt[strt].y=frmpnt->flt[fin].y;
			frmpnt->flt[fin].x=tpnt.x;
			frmpnt->flt[fin].y=tpnt.y;
			strt=pdir(strt);
			toglMap(PSELDIR);
			fin=pdir(fin);
			toglMap(PSELDIR);
		}
		refil();
		return;
	}
	if(fselpnt){

		savdo();
		for(uind=0;uind<fselpnt;uind++){

			clofind=selist[uind];
			fnord();
		}
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			fnord();
			coltab();
			setMap(RESTCH);
		}
		else{

			if(chkMap(GRPSEL)){

				savdo();
				rngadj();
				uind=gpnt0;
				for(ind=0;ind<((signed)(gpnt1-gpnt0)>>1)+1;ind++){

					tpnt.at=stchs[uind].at;
					tpnt.x=stchs[uind].x;
					tpnt.y=stchs[uind].y;
					stchs[uind].at=stchs[gpnt1-ind].at;
					stchs[uind].x=stchs[gpnt1-ind].x;
					stchs[uind].y=stchs[gpnt1-ind].y;
					stchs[gpnt1-ind].at=tpnt.at;
					stchs[gpnt1-ind].x=tpnt.x;
					stchs[gpnt1-ind].y=tpnt.y;
					uind++;
				}
				coltab();
				setMap(RESTCH);
			}
		}
	}
}

void dudif(DUBPNT strt,DUBPNT fin,DUBPNT* dif){

	dif->x=fin.x-strt.x;
	dif->y=fin.y-strt.y;
}

void trfrm(DUBPNT lpnt0,DUBPNT lpnt1,DUBPNT rpnt0,DUBPNT rpnt1){

	unsigned	ind;
	DUBPNT		tdif,bdif,ldif,rdif;
	DUBPNT		clprat,tmid,bmid,mdif;

	dudif(lpnt1,rpnt1,&tdif);
	dudif(lpnt0,rpnt0,&bdif);
	dudif(lpnt0,lpnt1,&ldif);
	dudif(rpnt0,rpnt1,&rdif);
	for(ind=0;ind<clplen;ind++){

		clprat.x=clpnu[ind].x/clpsiz.cx;
		clprat.y=clpnu[ind].y/clpsiz.cy;
		tmid.x=clprat.x*(tdif.x)+lpnt1.x;
		tmid.y=clprat.x*(tdif.y)+lpnt1.y;
		bmid.x=clprat.x*(bdif.x)+lpnt0.x;
		bmid.y=clprat.x*(bdif.y)+lpnt0.y;
		dudif(bmid,tmid,&mdif);
		oseq[xpnt].x=clprat.y*mdif.x+bmid.x;
		oseq[xpnt].y=clprat.y*mdif.y+bmid.y;
		xpnt++;
	}
}

void clpfm(){

	unsigned	ind,ine,cnt;
	double		lsiz,rsiz;
	DUBPNT		ldif,rdif;
	DUBPNT		lstp,rstp;
	DUBPNT		lpnt0,rpnt0;
	DUBPNT		lpnt1,rpnt1;

	xpnt=0;
	for(ind=0;ind<seqpnt-2;ind+=2){

		lsiz=hypot(bseq[ind+1].x-bseq[ind].x,bseq[ind+1].y-bseq[ind].y);
		rsiz=hypot(bseq[ind+3].x-bseq[ind+2].x,bseq[ind+3].y-bseq[ind+2].y);
		ldif.x=bseq[ind+1].x-bseq[ind].x;
		ldif.y=bseq[ind+1].y-bseq[ind].y;
		rdif.x=bseq[ind+2].x-bseq[ind+3].x;
		rdif.y=bseq[ind+2].y-bseq[ind+3].y;
		if(rsiz>lsiz)
			cnt=lsiz/clpsiz.cy;
		else
			cnt=rsiz/clpsiz.cy;
		if(!cnt)
			cnt=1;
		lstp.x=ldif.x/cnt;
		lstp.y=ldif.y/cnt;
		rstp.x=rdif.x/cnt;
		rstp.y=rdif.y/cnt;
		lpnt1.x=bseq[ind].x;
		lpnt1.y=bseq[ind].y;
		rpnt1.x=bseq[ind+3].x;
		rpnt1.y=bseq[ind+3].y;
		for(ine=0;ine<cnt;ine++){

			lpnt0.x=lpnt1.x;
			lpnt0.y=lpnt1.y;
			rpnt0.x=rpnt1.x;
			rpnt0.y=rpnt1.y;
			lpnt1.x+=lstp.x;
			lpnt1.y+=lstp.y;
			rpnt1.x+=rstp.x;
			rpnt1.y+=rstp.y;
			if(xpnt>MAXSEQ-clplen-1)
				return;
			trfrm(lpnt0,lpnt1,rpnt0,rpnt1);		
		}
	}
}

void fmclp(){

	double		tspac=stspace;

	stspace=clpsiz.cx;
	setMap(BARSAT);
	satfil();
	rstMap(BARSAT);
	clpfm();
	frmpnt->ftyp=CLPF;
	seqpnt=xpnt;
	stspace=tspac;
}

void filsclp(){

	unsigned ind;

	deltx();
	fvars(clofind);
	if(frmpnt->typ!=SAT)
		frmpnt->wpar=0;
	frmpnt->typ=SAT;
	frmpnt->ftyp=CLPF;
	frmpnt->angclp.clp=numclp();
	frmpnt->flencnt.nclp=clplen;
	for(ind=0;ind<clplen;ind++){

		frmpnt->angclp.clp[ind].x=clpnu[ind].x;
		frmpnt->angclp.clp[ind].y=clpnu[ind].y;
	}
	refilfn();
}

void clpfil(){

	unsigned ind;

	if(filmsgs(FMM_CLP))
		return;
	if(OpenClipboard(hWnd)){

		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			redclp();
			CloseClipboard();
			if(clpsiz.cx>CLPMIN&&clpsiz.cy>CLPMIN){

				if(fselpnt){

					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						if(frmpnt->typ!=LIN)
							filsclp();
					}
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						filsclp();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else
			CloseClipboard();
	}
}

void snpfn(unsigned xind,unsigned len){

	unsigned	ind,ine,fin,ref,chk;
	double		tlen;

	fin=xhst[xind+len];
	ind=xhst[xind];
	if(fin-ind){

		for(ind=xhst[xind];ind<xhst[xind+1];ind++){

			ref=xpnts[ind];
			for(ine=ind+1;ine<fin;ine++){

				chk=xpnts[ine];
				tlen=hypot(stchs[chk].x-stchs[ref].x,stchs[chk].y-stchs[ref].y);	
				if(tlen<snplen){

					stchs[chk].x=stchs[ref].x;
					stchs[chk].y=stchs[ref].y;
				}
			}
		}
	}
}

void nutim(double siz){

	htim=CreateWindow(
		"STATIC",
		0,
		WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3,
		0,
		stchSiz.x,
		buttonHi,
		hWnd,
		NULL,
		hInst,
		NULL);
	timdc=GetDC(htim);
	timstp=(double)stchSiz.x/siz;
	timpos=0;
	flin[0].y=0;
	flin[1].y=buttonHi;
	flin[0].x=flin[1].x=0;
	SelectObject(timdc,uPen[0]);
}

void nxtim(){

	Polyline(timdc,flin,2);
	timpos+=timstp;
	flin[0].x=flin[1].x=timpos;
}

void snp(unsigned strt,unsigned fin){

	unsigned	ind,tuns,acc,chklen,at=0;
	FLPNT		rsiz;
	unsigned*	txhst;

	chkrng(&rsiz);
	xpnts=(unsigned*)bseq;
	ZeroMemory(bseq,65536*sizeof(unsigned));
	xhst=txhst=new unsigned[(int)rsiz.x+1];
	for(ind=0;ind<rsiz.x;ind++)
		xhst[ind]=0;
	if(chkMap(FORMSEL)){

		at=(clofind<<4)&FRMSK;
		for(ind=strt;ind<fin;ind++){

			if(!(stchs[ind].at&NOTFRM)&&(stchs[ind].at&FRMSK)==at){
		
				tuns=stchs[ind].x;
				xhst[tuns]++;
			}
		}
	}
	else{

		for(ind=strt;ind<fin;ind++){

			tuns=stchs[ind].x;
			xhst[tuns]++;
		}
	}
	acc=0;
	for(ind=0;ind<rsiz.x;ind++){

		tuns=xhst[ind];
		xhst[ind]=acc;
		acc+=tuns;
	}
	xhst[ind]=acc;
	if(chkMap(FORMSEL)){

		for(ind=0;ind<hed.stchs;ind++){

			if(!(stchs[ind].at&NOTFRM)&&(stchs[ind].at&FRMSK)==at){
			
				tuns=stchs[ind].x;
				xpnts[xhst[tuns]++]=ind;
			}
		}
	}
	else{

		for(ind=0;ind<hed.stchs;ind++){

			tuns=stchs[ind].x;
			xpnts[xhst[tuns]++]=ind;
		}
	}
	xhst=&xhst[1];
	chklen=snplen*2+1;
	nutim(rsiz.x);
	for(ind=0;ind<rsiz.x-chklen;ind++){

		snpfn(ind,chklen);
		nxtim();
	}
	DestroyWindow(htim);
	delete txhst;
}

void snap(){

	savdo();
	if(chkMap(GRPSEL)){

		rngadj();
		snp(gpnt0,gpnt1);
	}
	else
		snp(0,hed.stchs);
	coltab();
	setMap(RESTCH);
}

void setcmap(unsigned bpnt){
	bts(&colmap, bpnt);
}

unsigned nxtcol(){
	unsigned col;
	if (bt(&colmap, apcol)) {
		col = apcol;
	} else {
		col = ffs(colmap);

		if (col-- == 0) {
			return 0xffffffff;
		}  
	}

	btc(&colmap, col);

	return col;
}

unsigned chkdun(unsigned bpnt){
	return bt(dunmap, bpnt) ? 0 : 1;
}

unsigned isrt(unsigned bpnt){
	return bt(&srtmsk, bpnt) ? 1 : 0;
}

unsigned prgflg(unsigned ind){

	if((stchs[ind].at&TYPMSK)==FRMBFIL)
		return isrt(formlst[(stchs[ind].at&FRMSK)>>4].etyp&NEGUND);
	else
		return 0;
}

BOOL preced(unsigned stind){

	unsigned fpnt,fcol,ind,ine;

	if((stchs[stind].at&TYPMSK)==FRMBFIL){

		fpnt=(stchs[stind].at&FRMSK)>>FRMSHFT;
		fcol=stchs[stind].at&COLMSK;
		for(ind=0;ind<prgind;ind++){

			if(chkdun(ind)){
			
				ine=preg[ind].ind;
				if((stchs[ine].at&COLMSK)==fcol&&
					((stchs[ine].at&FRMSK)>>FRMSHFT)==fpnt&&
					(stchs[ine].at&TYPMSK)==FRMFIL)

					return 0;
			}
		}
		return 1;
	}
	else
		return 1;
}

void rotpar(){

	if(ini.rotang<(PI/180))
		tabmsg(IDS_ROTIN);
	if(chkMap(FPSEL)){

		rotcntr.x=midl(pselrct.right,pselrct.left);
		rotcntr.y=midl(pselrct.top,pselrct.bottom);
		return;
	}
	if(chkMap(BIGBOX)){

		rotcntr.x=midl(rctal.right,rctal.left);
		rotcntr.y=midl(rctal.top,rctal.bottom);
		return;
	}
	if(fselpnt){

		if(chkMap(GMRK)){

			rotcntr.x=mrkpnt.x;
			rotcntr.y=mrkpnt.y;
		}
		else
			dufcntr(&rotcntr);
		setMap(FRMSROT);
		return;
	}
	if(chkMap(FORMSEL)){

		rotrct.left=frmpnt->rct.left;
		rotrct.right=frmpnt->rct.right;
		rotrct.top=frmpnt->rct.top;
		rotrct.bottom=frmpnt->rct.bottom;
		if(!chkMap(GMRK)){

			rotcntr.x=(double)(rotrct.right-rotrct.left)/2+rotrct.left;
			rotcntr.y=(double)(rotrct.top-rotrct.bottom)/2+rotrct.bottom;
		}
		setMap(FRMROT);
	}
	else{

		if(chkMap(GRPSEL)){

			rngadj();
			selRct(&rotrct);
		}
	}
	if(chkMap(GMRK)){

		rotcntr.x=mrkpnt.x;
		rotcntr.y=mrkpnt.y;
	}
	else{

		rotcntr.x=(double)(rotrct.right-rotrct.left)/2+rotrct.left;
		rotcntr.y=(double)(rotrct.top-rotrct.bottom)/2+rotrct.bottom;
	}
}

void rotentr(){

	TCHAR buf[HBUFSIZ];

	LoadString(hInst,IDS_ROTA,buf,HBUFSIZ);
	sprintf(msgbuf,buf,ang/PI*180);
	shoMsg(msgbuf);
	setMap(NUMIN);
	numWnd();
}

void setrang(){

	ang=ini.rotang;
	rotentr();
	setMap(NUROT);
}

void rotcmd(){

	if(chkMap(FORMSEL)||chkMap(GRPSEL)||fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

		ang=ini.rotang;
		rotpar();
		rotentr();
		setMap(ENTROT);
	}
	else
		shoseln(IDS_ALLX,IDS_ROTCMD);
}

void fnagain(){

	if(chkMap(FORMSEL)||chkMap(GRPSEL)||fselpnt||chkMap(BIGBOX)||chkMap(FPSEL)){

		rotpar();
		rotfn();
	}
	else
		alrotmsg();
}

void rotagain(){

	ang=ini.rotang;
	fnagain();
}

void bakagain(){

	ang=2*PI-ini.rotang;
	fnagain();
}

void rotdup(){

	if(chkMap(FORMSEL)||chkMap(GRPSEL)||fselpnt){

		ang=ini.rotang;
		rotpar();
		rotentr();
		setMap(ENTRDUP);
	}
	else
		shord();
}

void adfrm(unsigned fpnt){

	FRMHED*		nupnt;

	frmpnt=&formlst[fpnt];
	nupnt=&formlst[formpnt];
	frmcpy(nupnt,frmpnt);
	clofind=formpnt;
	nupnt->flt=adflt(frmpnt->sids);
	mvflpnt(nupnt->flt,frmpnt->flt,frmpnt->sids);	
	if(nupnt->typ==SAT&&nupnt->stpt){

		nupnt->sacang.sac=adsatk(nupnt->stpt);
		mvsatk(nupnt->sacang.sac,frmpnt->sacang.sac,frmpnt->stpt);
	}
	if(iseclpx(formpnt)){

		nupnt->clp=adclp(nupnt->nclp);
		mvflpnt(nupnt->clp,frmpnt->clp,frmpnt->nclp);
	}
	if(isclpx(formpnt)){

		nupnt->angclp.clp=adclp(nupnt->flencnt.nclp);
		mvflpnt(nupnt->angclp.clp,frmpnt->angclp.clp,frmpnt->flencnt.nclp);
	}
	formpnt++;
}

void duprot(){

	adfrm(clofind);
	rotfn();
	refil();
	setMap(FORMSEL);
	setMap(RESTCH);
}

void duprotfs(){

	unsigned	bakpnt,ind;

	bakpnt=formpnt;
	rotpar();
	for(ind=0;ind<fselpnt;ind++)
		adfrm(selist[ind]);
	formpnt=bakpnt;
	for(ind=0;ind<fselpnt;ind++)
		selist[ind]=formpnt++;
	fnagain();
}

void duprots(){

	unsigned src,dst;

	rngadj();
	dst=hed.stchs;
	for(src=gpnt0;src<=gpnt1;src++){

		stchs[dst].x=stchs[src].x;
		stchs[dst].y=stchs[src].y;
		stchs[dst++].at=stchs[src].at&(~(FRMSK|TYPMSK));
	}
	cloInd=hed.stchs;
	hed.stchs+=(gpnt1-gpnt0);
	grpInd=hed.stchs;
	hed.stchs++;
	rngadj();
	rotfn();
	coltab();
	setMap(RESTCH);
}

void cplayfn(unsigned fpnt,unsigned play){

	FRMHED*		spnt;

	spnt=&formlst[fpnt];
	fvars(formpnt);
	frmcpy(frmpnt,spnt);
	fvars(formpnt);
	frmpnt->flt=adflt(frmpnt->sids);
	MoveMemory(frmpnt->flt,spnt->flt,sids*sizeof(FLPNT));
	if(frmpnt->typ==SAT&&frmpnt->stpt)
	{
		frmpnt->sacang.sac=adsatk(frmpnt->stpt);
		MoveMemory(frmpnt->sacang.sac,spnt->sacang.sac,frmpnt->stpt*sizeof(SATCON));
	}
	frmpnt->nclp=0;
	frmpnt->ftyp=0;
	frmpnt->flencnt.nclp=0;;
	frmpnt->etyp=0;
	frmpnt->dhx.txt.ind=0;
	frmpnt->at=formlst[formpnt].at&NFRMLMSK;
	frmpnt->at|=play;
	formpnt++;
}

void cpylayr(unsigned play){

	unsigned ind,ine,playcod;

	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++)
			cplayfn(selist[ind],play);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			cplayfn(clofind,play);
		}
		else{

			if(chkMap(GRPSEL)){

				savdo();
				playcod=play<<(LAYSHFT-1);
				rngadj();
				ine=hed.stchs;
				for(ind=gpnt0;ind<gpnt1;ind++){

					stchs[ine].at=stchs[ind].at&NLAYMSK|playcod;
					stchs[ine].x=stchs[ind].x;
					stchs[ine++].y=stchs[ind].y;
				}
				hed.stchs=ine;
				coltab();
				setMap(RESTCH);
			}
		}
	}
}

void movlayr(unsigned play){

	unsigned slay,ind,ine;
	unsigned stchcod;
	
	stchcod=play<<(LAYSHFT-1);
	if(fselpnt){

		savdo();
		clRmap((formpnt>>5)+1);
		for(ind=0;ind<fselpnt;ind++){

			ine=selist[ind];
			slay=(formlst[ine].at&FRMLMSK)>>1;
			formlst[ine].at=(TCHAR)(formlst[ine].at&NFRMLMSK)|play;
			setr(ine);
		}
		for(ind=0;ind<hed.stchs;ind++){

			if(stchs[ind].at&ALTYPMSK){

				ine=(stchs[ind].at&FRMSK)>>FRMSHFT;
				if(chkr(ine))
					stchs[ind].at=stchs[ind].at&NLAYMSK|stchcod;
			}
		}
		fselpnt=0;
		rstMap(FORMSEL);
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			slay=(formlst[clofind].at&FRMLMSK)>>1;
			formlst[clofind].at=(TCHAR)(formlst[clofind].at&NFRMLMSK)|play;
			rstMap(FORMSEL);
			for(ind=0;ind<hed.stchs;ind++){

				if(stchs[ind].at&ALTYPMSK&&((stchs[ind].at&FRMSK)>>FRMSHFT)==clofind)
					stchs[ind].at=stchs[ind].at&NLAYMSK|stchcod;
			}
			setMap(RESTCH);
		}
		else{

			if(chkMap(GRPSEL)){

				savdo();
				rngadj();
				for(ind=gpnt0;ind<gpnt1;ind++)
					stchs[ind].at=stchs[ind].at&NLAYMSK|stchcod;
				setMap(RESTCH);
			}
		}
	}
}

void join(){

	unsigned	bakpnt,ind,sids;
	FLPNT*		tflt;
	FLPNT*		ipnt;

	bakpnt=clofind;
	setMap(FRMSAM);
	if(formpnt>1&&chkMap(FORMSEL)&&closfrm()){

		sids=formlst[clofind].sids;
		tflt=(FLPNT*)&bseq;
		for(ind=0;ind<sids;ind++){

			tflt[ind].x=formlst[clofind].flt[clofine].x;
			tflt[ind].y=formlst[clofind].flt[clofine].y;
			clofine=nxt(clofine);
		}
		setMap(DELTO);
		frmdel();
		if(bakpnt>clofind)
			clofind=bakpnt-1;
		else
			clofind=bakpnt;
		ipnt=&formlst[clofind].flt[formlst[clofind].sids];
		fltspac(ipnt,sids);
		for(ind=0;ind<sids;ind++){

			ipnt[ind].x=tflt[ind].x;
			ipnt[ind].y=tflt[ind].y;
		}
		frmpnt=&formlst[clofind];
		frmpnt->sids+=sids;
		frmpnt->rct.left=frmpnt->rct.right=frmpnt->flt[0].x;
		frmpnt->rct.top=frmpnt->rct.bottom=frmpnt->flt[0].y;
		for(ind=1;ind<frmpnt->sids;ind++){

			if(frmpnt->flt[ind].x<frmpnt->rct.left)
				frmpnt->rct.left=frmpnt->flt[ind].x;
			if(frmpnt->flt[ind].x>frmpnt->rct.right)
				frmpnt->rct.right=frmpnt->flt[ind].x;
			if(frmpnt->flt[ind].y>frmpnt->rct.top)
				frmpnt->rct.top=frmpnt->flt[ind].y;
			if(frmpnt->flt[ind].y<frmpnt->rct.bottom)
				frmpnt->rct.bottom=frmpnt->flt[ind].y;
		}
		refil();
		coltab();
		setMap(RESTCH);
	}
	rstMap(FRMSAM);
}

BOOL chkbfil(){

	switch(frmpnt->etyp){

	case EGLIN:
	case EGBLD:
	case EGSAT:
	case EGAP:
	case EGPRP:
	case EGHOL:
	case EGPIC:
	case EGCLP:
		return 1;
	}
	return 0;
}

void refilal(){

	unsigned bakpnt;

	savdo();
	bakpnt=clofind;
	for(clofind=0;clofind<formpnt;clofind++)
		refilfn();
	clofind=bakpnt;
	fvars(clofind);
	coltab();
	setMap(RESTCH);
}

BOOL notsel(){

	unsigned ind;
	
	for(ind=0;ind<fselpnt;ind++){

		if((unsigned)selist[ind]==clofind)
			return 0;
	}
	return 1;
}

void nufsel(){

	if(formpnt){

		rstMap(FORMSEL);
		if(rstMap(WASEL))
			selist[fselpnt++]=baksel;
		if(notsel())
			selist[fselpnt++]=(unsigned short)clofind;
		setMap(RESTCH);
	}
}

void frmadj(unsigned find){

	unsigned ind;

	fvars(find);
	for(ind=0;ind<frmpnt->sids;ind++){

		flt[ind].x+=fmovdif.x;
		flt[ind].y-=fmovdif.y;
	}
	frmout(find);
}

void setr(unsigned pbit){
	bts(rmap, pbit);
}

void clRmap(unsigned len){
	memset(rmap, 0, len * sizeof(*rmap));
}

#if PESACT

BOOL setrc(unsigned pbit){
	return bts(rmap, pbit) ? 1 : 0;
}
#endif

BOOL chkr(unsigned pbit){
	return bt(rmap, pbit) ? 1 : 0;
}

void frmsadj(){

	unsigned ind;

	clRmap(RMAPSIZ);
	for(ind=0;ind<fselpnt;ind++)
		setr(selist[ind]);
	for(ind=0;ind<hed.stchs;ind++){

		if(stchs[ind].at&ALTYPMSK&&chkr((stchs[ind].at&FRMSK)>>FRMSHFT)){

			stchs[ind].x+=fmovdif.x;
			stchs[ind].y-=fmovdif.y;
		}
	}
}

void stchrct2px(FLRCT srct,RECT* prct){

	DUBPNT	ipnt;
	POINT	opnt;

	ipnt.x=srct.left;
	ipnt.y=srct.top;
	sCor2px(ipnt,&opnt);
	prct->left=opnt.x;
	prct->top=opnt.y;
	ipnt.x=srct.right;
	ipnt.y=srct.bottom;
	sCor2px(ipnt,&opnt);
	prct->right=opnt.x;
	prct->bottom=opnt.y;
}

void getbig(){
	
	unsigned	ind;
	FLRCT*		trct;

	rctal.bottom=rctal.left=1e9;
	rctal.top=rctal.right=0;
	for(ind=0;ind<formpnt;ind++){

		trct=&formlst[ind].rct;
		if(trct->bottom<rctal.bottom)
			rctal.bottom=trct->bottom;
		if(trct->left<rctal.left)
			rctal.left=trct->left;
		if(trct->right>rctal.right)
			rctal.right=trct->right;
		if(trct->top>rctal.top)
			rctal.top=trct->top;
	}
	for(ind=0;ind<hed.stchs;ind++){

		if(stchs[ind].x<rctal.left)
			rctal.left=stchs[ind].x;
		if(stchs[ind].x>rctal.right)
			rctal.right=stchs[ind].x;
		if(stchs[ind].y<rctal.bottom)
			rctal.bottom=stchs[ind].y;
		if(stchs[ind].y>rctal.top)
			rctal.top=stchs[ind].y;
	}
}

void selal(){

	rstMap(FORMSEL);
	fselpnt=0;
	rstMap(SELBOX);
	rstMap(GRPSEL);
	getbig();
	zRct.bottom=0;
	zRct.left=0;
	zRct.right=zum0.x;
	zRct.top=zum0.y;
	zumFct=1;
	rstMap(ZUMED);
	movStch();
	selCnt=0;
	rstMap(RUNPAT);
	duzrat();
	stchrct2px(rctal,&bigrct);
	setMap(BIGBOX);
	setMap(RESTCH);
}

void frmpnts(unsigned typ){

	unsigned ind=0;
	unsigned trg=(clofind<<4)|typ;

	while(ind<hed.stchs&&(stchs[ind].at&(ALTYPMSK|FRMSK))!=trg)
		ind++;
	cloInd=ind;
	ind=hed.stchs-1;
	while(ind>cloInd&&(stchs[ind].at&(ALTYPMSK|FRMSK))!=trg)
		ind--;
	grpInd=ind;
}

void selfil(unsigned typ){

	frm1pnt();
	if(chkMap(FORMSEL)){

		if(typ==FRMFIL&&!formlst[clofind].ftyp){

			tabmsg(IDS_FSELF);
			return;
		}
		if(typ==FRMBFIL&&!formlst[clofind].etyp){

			tabmsg(IDS_FSELB);
			return;
		}
		if(typ==FRMAPFIL&&(formlst[clofind].etyp&NEGUND)!=EGAP){

			tabmsg(IDS_FSELA);
			return;
		}
		frmpnts(typ);
		setMap(GRPSEL);
		rstMap(FORMSEL);
		rngadj();
		setMap(RESTCH);
	}
	else
		tabmsg(IDS_SEL1FRM);
}

/*
BOOL notfstch(unsigned at){

#if !defined(GCC__)
	__asm{
			xor		eax,eax
			mov		ebx,at
			test	ebx,TYPMSK
			je		short notf1
			mov		ecx,clofind
			shl		ecx,4
			and		ebx,FRMSK
			cmp		ecx,ebx
			je		short notfx
notf1:		inc		eax
notfx:
	}
#else
       __asm__ __volatile__
       (
       "       xor             eax,eax\n"
       "       mov             ebx,%[at]\n"
       "       test    ebx,%[TYPMSK]\n"
       "       je              short notf1\n"
       "       mov             ecx,%[clofind]\n"
       "       shl             ecx,4\n"
       "       and             ebx,%[FRMSK]\n"
       "       cmp             ecx,ebx\n"
       "       je              short notfx\n"
       "notf1:         inc             eax\n"
       "notfx:\n"

       :
       :       [FRMSK] "m" (FRMSK),
               [clofind] "m" (clofind),
               [at] "m" (at),
               [TYPMSK] "m" (TYPMSK)
       :       "ecx", "eax", "ebx"
       );
#endif

}*/

BOOL notfstch(unsigned at)
{
	if(at&NOTFRM)
		return 1;
	if(((at&FRMSK)>>FRMSHFT)==clofind)
		return 0;
	return 1;
}

void selalfil(){

	frm1pnt();
	if(chkMap(FORMSEL)){
	
		cloInd=0;
		while(cloInd<hed.stchs&&notfstch(stchs[cloInd].at))
			cloInd++;
		if(cloInd!=hed.stchs)
		{
			if(cloInd)
				cloInd--;
			grpInd=hed.stchs-1;
			while(grpInd>cloInd&&notfstch(stchs[grpInd].at))
				grpInd--;
			setMap(GRPSEL);
			rstMap(FORMSEL);
			rngadj();
			setMap(RESTCH);
		}
		else
			tabmsg(IDS_FSELM);
	}
	else
		tabmsg(IDS_SEL1FRM);
}

BOOL frmrng(unsigned fpnt,RANG* rng){

	rng->strt=0;
	rng->fin=hed.stchs;
	if(formlst[fpnt].ftyp||formlst[fpnt].etyp){

		while(rng->strt<hed.stchs&&notfstch(stchs[rng->strt].at))
			rng->strt++;
		rng->fin=hed.stchs-1;
		while(rng->fin>rng->strt&&notfstch(stchs[rng->fin].at))
			rng->fin--;
		if(rng->fin>rng->strt)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void bhfn(unsigned strt,unsigned fin,double spac){

	double		len;
	DUBPNT		dif,stp,ostp,pnti,pntf,pnto;
	unsigned	cnt,ind;

	dif.x=flt[fin].x-flt[strt].x;
	dif.y=flt[fin].y-flt[strt].y;
	ang=atan2(-dif.x,dif.y);
	ostp.x=frmpnt->esiz*cos(ang);
	ostp.y=frmpnt->esiz*sin(ang);
	len=hypot(dif.x,dif.y);
	cnt=len/spac;
	stp.x=dif.x/cnt;
	stp.y=dif.y/cnt;
	pnti.x=flt[strt].x;
	pnti.y=flt[strt].y;
	if(cnt){

		for(ind=0;ind<cnt-1;ind++){

			pntf.x=pnti.x+stp.x;
			pntf.y=pnti.y+stp.y;
			pnto.x=pntf.x+ostp.x;
			pnto.y=pntf.y+ostp.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			oseq[seqpnt].x=pnti.x;
			oseq[seqpnt++].y=pnti.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			oseq[seqpnt].x=pnto.x;
			oseq[seqpnt++].y=pnto.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			oseq[seqpnt].x=pnto.x;
			oseq[seqpnt++].y=pnto.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			pnti.x+=stp.x;
			pnti.y+=stp.y;
		}
		pntf.x=pnti.x+stp.x;
		pntf.y=pnti.y+stp.y;
		oseq[seqpnt].x=pntf.x;
		oseq[seqpnt++].y=pntf.y;
		oseq[seqpnt].x=pnti.x;
		oseq[seqpnt++].y=pnti.y;
	}
}

void bhcrnr(unsigned lin){

	unsigned	tlin=nxt(lin);
	DUBPNT		dif,pnt;
	double		len,rat;

	if(chkMap(INDIR))
	{
		dif.x=opnts[tlin].x-flt[tlin].x;
		dif.y=opnts[tlin].y-flt[tlin].y;
	}
	else
	{
		dif.x=ipnts[tlin].x-flt[tlin].x;
		dif.y=ipnts[tlin].y-flt[tlin].y;
	}
	len=hypot(dif.x,dif.y);
	rat=bfclen/len;
	dif.x*=rat;
	dif.y*=rat;
	pnt.x=flt[tlin].x+dif.x;
	pnt.y=flt[tlin].y+dif.y;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	oseq[seqpnt].x=pnt.x;
	oseq[seqpnt++].y=pnt.y;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	oseq[seqpnt].x=pnt.x;
	oseq[seqpnt++].y=pnt.y;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
}

void bhbrd(double spac){

	unsigned short	slin;
	unsigned short	nlin,ind;

	slin=getlast();
	seqpnt=0;
	oseq[seqpnt].x=flt[slin].x;
	oseq[seqpnt++].y=flt[slin].y;
	for(ind=0;ind<sids;ind++){

		nlin=nxt(slin);
		bhfn(slin,nlin,spac);
		bhcrnr(slin);
		slin=nlin;
	}
}

void blbrd(double spac){

	unsigned ind;

	seqpnt=0;
	oseq[seqpnt].x=flt[0].x;
	oseq[seqpnt++].y=flt[0].y;
	for(ind=0;ind<(unsigned)sids-2;ind++){

		bhfn(ind,ind+1,spac);
		bhcrnr(ind);
	}
	bhfn(ind,ind+1,spac);
	oseq[seqpnt].x=flt[sids-1].x;
	oseq[seqpnt++].y=flt[sids-1].y;
}

void bholbrd(){

	deleclp(clofind);
	frmpnt->esiz=brdwid;
	bsizpar();
	frmpnt->etyp=EGHOL;
	frmpnt->espac=stspace;
	frmpnt->bcol=actcol;
	savblen(bfclen);
	refilfn();
}

void bhol(){

	double		tspac=stspace;
	unsigned	ind;

	if(filmsgs(FML_BHOL))
		return;
	stspace=tspac;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			bholbrd();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			fvars(clofind);
			bholbrd();
			setMap(INIT);
			coltab();
			ritot(hed.stchs);
			setMap(RESTCH);
		}
	}
	stspace=tspac;
}

void fcntr(){

	unsigned	ind,ine,inf,tat;
	FRCT		avrct;
	DUBPNT		avcntr;
	DUBPNT		cntr;
	DUBPNT		dif;

	avrct.bottom=avrct.left=avrct.right=avrct.top=0;
	if(fselpnt){

		savdo();
		ine=selist[0];
		avcntr.x=(formlst[ine].rct.right-formlst[ine].rct.left)/2+formlst[ine].rct.left;
		avcntr.y=(formlst[ine].rct.top-formlst[ine].rct.bottom)/2+formlst[ine].rct.bottom;
		for(ind=1;ind<fselpnt;ind++){

			ine=selist[ind];
			cntr.x=(formlst[ine].rct.right-formlst[ine].rct.left)/2+formlst[ine].rct.left;
			cntr.y=(formlst[ine].rct.top-formlst[ine].rct.bottom)/2+formlst[ine].rct.bottom;
			dif.x=avcntr.x-cntr.x;
			dif.y=avcntr.y-cntr.y;
			frmpnt=&formlst[ine];
			for(inf=0;inf<frmpnt->sids;inf++){

				frmpnt->flt[inf].x+=dif.x;
				frmpnt->flt[inf].y+=dif.y;
			}
			frmout(ine);
			tat=(ine<<4);
			for(inf=0;inf<hed.stchs;inf++){

				if((stchs[inf].at&FRMSK)==tat&&!(stchs[ind].at&NOTFRM)){

					stchs[inf].x+=dif.x;
					stchs[inf].y+=dif.y;
				}
			}
		}
		setMap(RESTCH);
	}
	else
		tabmsg(IDS_SELC);
}

void boxsel(){

	rstMap(INSRT);
	if(!chkMap(THUMSHO)){

		rstMap(BZUM);
		rstMap(BZUMIN);
		setMap(VCAPT);
		SetCapture(hWnd);
		setMap(RESTCH);
	}
}

void clpcrnr(unsigned lin){

	unsigned	tlin=nxt(lin);
	unsigned	ind;
	DUBPNT		dif,pnt;
	FLPNT		tpnt;
	double		len,rat;
	SHRTPNT		rpnt;

	rpnt.x=(clprct.right-clprct.left)/2+clprct.left;
	rpnt.y=clprct.top;
	if(chkMap(INDIR))
	{
		dif.x=opnts[tlin].x-flt[tlin].x;
		dif.y=opnts[tlin].y-flt[tlin].y;
	}
	else
	{
		dif.x=ipnts[tlin].x-flt[tlin].x;
		dif.y=ipnts[tlin].y-flt[tlin].y;
	}
	ang=atan2(dif.y,dif.x)+PI/2;
	rotang1(rpnt,&clpref);
	for(ind=0;ind<clplen;ind++)
		rotang1(clpnu[ind],&filclp[ind]);
	len=hypot(dif.x,dif.y);
	rat=getplen()/len;
	dif.x*=rat;
	dif.y*=rat;
	pnt.x=flt[tlin].x+dif.x;
	pnt.y=flt[tlin].y+dif.y;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	oseq[seqpnt].x=pnt.x;
	oseq[seqpnt++].y=pnt.y;
	oseq[seqpnt].x=flt[tlin].x;
	oseq[seqpnt++].y=flt[tlin].y;
	oseq[seqpnt].x=pnt.x;
	oseq[seqpnt++].y=pnt.y;
	tpnt.x=pnt.x;
	tpnt.y=pnt.y;
	if(!ritclp(tpnt)){

		oseq[seqpnt].x=pnt.x;
		oseq[seqpnt++].y=pnt.y;
		oseq[seqpnt].x=flt[tlin].x;
		oseq[seqpnt++].y=flt[tlin].y;
	}
}

void picfn(unsigned strt,unsigned fin,double spac){

	double		len,tdub;
	DUBPNT		dif,stp,ostp,pnti,pntf,pnto;
	FLPNT		tpnt;
	SHRTPNT		rpnt;
	unsigned	cnt,ind;

	dif.x=flt[fin].x-flt[strt].x;
	dif.y=flt[fin].y-flt[strt].y;
	ang=atan2(-dif.x,dif.y);
	ostp.x=frmpnt->esiz*cos(ang);
	ostp.y=frmpnt->esiz*sin(ang);
	len=hypot(dif.x,dif.y);
	spac+=clpsiz.cx;
	cnt=len/spac;
	rpnt.x=(clprct.right-clprct.left)/2+clprct.left;
	rpnt.y=clprct.top;
	ang=atan2(dif.y,dif.x);
	rotang1(rpnt,&clpref);
	pnti.x=flt[strt].x;
	pnti.y=flt[strt].y;
	if(cnt){

		stp.x=0;
		stp.y=0;
		if(cnt>1){
	
			tdub=((len-cnt*spac)/(cnt-1)+spac)/len;
			stp.x=dif.x*tdub;
			stp.y=dif.y*tdub;
		}
		for(ind=0;ind<clplen;ind++)
			rotang1(clpnu[ind],&filclp[ind]);
		for(ind=0;ind<cnt-1;ind++){

			pntf.x=pnti.x+stp.x;
			pntf.y=pnti.y+stp.y;
			pnto.x=pntf.x+ostp.x;
			pnto.y=pntf.y+ostp.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			oseq[seqpnt].x=pnti.x;
			oseq[seqpnt++].y=pnti.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			oseq[seqpnt].x=pnto.x;
			oseq[seqpnt++].y=pnto.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			oseq[seqpnt].x=pnto.x;
			oseq[seqpnt++].y=pnto.y;
			tpnt.x=pnto.x;
			tpnt.y=pnto.y;
			if(ritclp(tpnt))
				goto picfnx;
			oseq[seqpnt].x=pnto.x;
			oseq[seqpnt++].y=pnto.y;
			oseq[seqpnt].x=pntf.x;
			oseq[seqpnt++].y=pntf.y;
			pnti.x+=stp.x;
			pnti.y+=stp.y;
		}
		oseq[seqpnt].x=flt[fin].x;
		oseq[seqpnt++].y=flt[fin].y;
		oseq[seqpnt].x=pnti.x;
		oseq[seqpnt++].y=pnti.y;
	}
picfnx:;
}

void clpic(unsigned short strtlin){

	unsigned		ind;
	unsigned short	nlin;

	bac=0;
	seqpnt=0;
	rstMap(CLPBAK);
	plen=clpsiz.cx/2;
	plen2=clpsiz.cx;
	filclp=new FLPNT[clplen];
	rotcntr.x=(clprct.right-clprct.left)/2+clprct.left;
	clpref.y=rotcntr.y=(clprct.top-clprct.bottom)/2+clprct.bottom;
	clpref.x=clprct.left;
	satout(20);
	if(frmpnt->typ==LIN){

		for(ind=0;ind<(unsigned)sids-2;ind++){

			picfn(ind,ind+1,frmpnt->espac);
			clpcrnr(ind);
		}
		picfn(ind,ind+1,frmpnt->espac);
	}
	else{

		if(!frmpnt->ftyp){

			oseq[seqpnt].x=flt[strtlin].x;
			oseq[seqpnt++].y=flt[strtlin].y;
		}
		for(ind=0;ind<sids;ind++){

			nlin=nxt(strtlin);
			picfn(strtlin,nlin,frmpnt->espac);
			clpcrnr(strtlin);
			strtlin=nlin;
		}
		oseq[seqpnt].x=flt[strtlin].x;
		oseq[seqpnt++].y=flt[strtlin].y;
	}
	delete filclp;
}

void fspic(){

	unsigned	ind;

	deleclp(clofind);
	frmpnt->etyp=EGPIC;
	frmpnt->nclp=clplen;
	frmpnt->clp=nueclp(clofind,clplen);
	frmpnt->esiz=clpsiz.cy;
	frmpnt->espac=picspac;
	frmpnt->bcol=actcol;
	bsizpar();
	savplen(bfclen);
	for(ind=0;ind<clplen;ind++){

		frmpnt->clp[ind].x=clpnu[ind].x;
		frmpnt->clp[ind].y=clpnu[ind].y;
	}
	plen=clpsiz.cy/2;
	refilfn();
}

void picot(){

	unsigned ind;

	if(filmsgs(FML_PIC))
		return;
	if(OpenClipboard(hWnd)){

		savdo();
		fvars(clofind);
		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			redclp();
			CloseClipboard();
			if(clpsiz.cx>CLPMIN){

				if(fselpnt){

					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						fspic();
					}
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						fspic();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else
			CloseClipboard();
	}
}

void contf(){

	unsigned	ind,loind,hind,selind,lolins,hilins,selins,strt,fin;
	double		lolen,hilen,len,lospac,hispac;
	unsigned	hicnt,locnt,cnt;
	unsigned*	locnts;
	unsigned*	hicnts;
	double*		lolens;
	double*		hilens;
	DUBPNT*		lodifs;
	DUBPNT*		hidifs;
	DUBPNT*		lostps;
	DUBPNT*		histps;
	FLPNT*		loflts;
	DUBPNT*		hiflts;
	DUBPNT		lostp,lopnt;
	DUBPNT		histp,hipnt;
	DUBPNT		dif;
	FLPNT*		sels;
	FLPNT*		his;
	PVEC*		pols;
	PVEC		polref,polin,poldif;

	seqpnt=0;
	strt=frmpnt->angclp.sat.strt;
	fin=frmpnt->angclp.sat.fin;
	hilins=sids-strt-1;
	lolins=strt;
	selins=fin-strt;
	sels=&flt[strt];
	his=&flt[fin];
	lolen=hilen=0;

	locnts=(unsigned*)bseq;
	hicnts=&locnts[lolins];

	lolens=(double*)&hicnts[hilins];
	hilens=&lolens[lolins];

	lodifs=(DUBPNT*)&hilens[hilins];
	hidifs=&lodifs[lolins];
	lostps=&hidifs[hilins];
	histps=&lostps[lolins];
	hiflts=&histps[hilins];

	pols=(PVEC*)&hiflts[hilins];
	loflts=(FLPNT*)&pols[selins];

	lolen=loind=0;
	for(ind=lolins;ind;ind--){

		loflts[loind].x=flt[ind].x;
		loflts[loind].y=flt[ind].y;
		lodifs[loind].x=flt[ind-1].x-flt[ind].x;
		lodifs[loind].y=flt[ind-1].y-flt[ind].y;
		lolens[loind]=hypot(lodifs[loind].x,lodifs[loind].y);
		lolen+=lolens[loind];
		loind++;
	}
	selind=0;
	for(ind=strt+1;ind<=fin;ind++){

		dif.x=flt[ind].x-sels[0].x;
		dif.y=flt[ind].y-sels[0].y;
		pols[selind].len=hypot(dif.x,dif.y);
		pols[selind].ang=atan2(dif.y,dif.x);
		selind++;
	}
	hind=0;hilen=0;
	for(ind=fin;ind<(unsigned)sids-1;ind++){

		hiflts[hind].x=flt[ind].x;
		hiflts[hind].y=flt[ind].y;
		hidifs[hind].x=flt[ind+1].x-flt[ind].x;
		hidifs[hind].y=flt[ind+1].y-flt[ind].y;
		hilens[hind]=hypot(hidifs[hind].x,hidifs[hind].y);
		hilen+=hilens[hind];
		hind++;
	}
	if(hilen>lolen)
		len=lolen;
	else
		len=hilen;
	cnt=len/frmpnt->fspac;
	if(hilen<lolen){
		
		lospac=frmpnt->fspac;
		hispac=frmpnt->fspac*hilen/lolen;
	}
	else{

		hispac=frmpnt->fspac;
		lospac=frmpnt->fspac*lolen/hilen;
	}
	for(ind=0;ind<lolins;ind++){

		locnts[ind]=lolens[ind]/lospac;
		lostps[ind].x=lodifs[ind].x/locnts[ind];
		lostps[ind].y=lodifs[ind].y/locnts[ind];	
	}
	for(ind=0;ind<hilins;ind++){

		hicnts[ind]=hilens[ind]/hispac;
		histps[ind].x=hidifs[ind].x/hicnts[ind];
		histps[ind].y=hidifs[ind].y/hicnts[ind];	
	}
	loind=hind=0;
	rstMap(FILDIR);
	locnt=hicnt=0;
	dif.x=flt[fin].x-flt[strt].x;
	dif.y=flt[fin].y-flt[strt].y;
	polref.len=hypot(dif.x,dif.y);
	polref.ang=atan2(dif.y,dif.x);
	while(locnt||(loind<lolins&&hind<hilins)){

		if(locnt)
			locnt--;
		else{

			if(loind<lolins){

				locnt=locnts[loind];
				lostp.x=lostps[loind].x;
				lostp.y=lostps[loind].y;
				lopnt.x=loflts[loind].x;
				lopnt.y=loflts[loind].y;
				loind++;
			}
		}
		if(hicnt)
			hicnt--;
		else{

			if(hind<hilins){

				hicnt=hicnts[hind];
				histp.x=histps[hind].x;
				histp.y=histps[hind].y;
				hipnt.x=hiflts[hind].x;
				hipnt.y=hiflts[hind].y;
				hind++;
			}
		}
		dif.x=hipnt.x-lopnt.x;
		dif.y=hipnt.y-lopnt.y;
		polin.ang=atan2(dif.y,dif.x);
		polin.len=hypot(dif.x,dif.y);
		poldif.ang=polin.ang-polref.ang;
		if(polref.len>0.9*stspace){

			poldif.len=polin.len/polref.len;
			if(toglMap(FILDIR)){

				oseq[seqpnt].x=lopnt.x;
				oseq[seqpnt].y=lopnt.y;
				seqpnt++;
				for(ind=0;ind<(selins-1);ind++){

					ang=pols[ind].ang+poldif.ang;
					len=pols[ind].len*poldif.len;
					oseq[seqpnt].x=lopnt.x+cos(ang)*len;
					oseq[seqpnt].y=lopnt.y+sin(ang)*len;
					seqpnt++;
				}
			}
			else{

				oseq[seqpnt].x=hipnt.x;
				oseq[seqpnt].y=hipnt.y;
				seqpnt++;
				for(ind=selins-2;ind<=selins;ind--){

					ang=pols[ind].ang+poldif.ang;
					len=pols[ind].len*poldif.len;
					oseq[seqpnt].x=lopnt.x+cos(ang)*len;
					oseq[seqpnt].y=lopnt.y+sin(ang)*len;
					seqpnt++;
				}
			}
		}
		lopnt.x+=lostp.x;
		lopnt.y+=lostp.y;
		hipnt.x+=histp.x;
		hipnt.y+=histp.y;
	}
	if(chkMap(FILDIR)){

		oseq[seqpnt].x=flt[0].x;
		oseq[seqpnt++].y=flt[0].y;
	}
	else{

		oseq[seqpnt].x=flt[sids-1].x;
		oseq[seqpnt++].y=flt[sids-1].y;
	}
	if(frmpnt->flencnt.flen<minsiz)
		frmpnt->flencnt.flen=minsiz;
}

BOOL contsf(unsigned find)
{
	clofind=find;
	fvars(find);
	if(frmpnt->sids>4)
	{
		delclps(clofind);
		deltx();
		chkcont();
		frmpnt->fspac=stspace;
		frmpnt->fcol=actcol;
		fsizpar();
		frmpnt->at|=(actl<<1);
		refilfn();
		return 1;
	}
	return 0;
}

void contfil(){

	unsigned ind;

	if(filmsgs(FML_CONT))
		return;
	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++)
			contsf(selist[ind]);
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		fvars(clofind);
		savdo();
		if(contsf(clofind))
		{
			setMap(INIT);
			coltab();
			setMap(RESTCH);
		}
		else
			tabmsg(IDS_CONT);
	}
}

BOOL cmpflt(FLPNT* flt0,FLPNT* flt1){

	if(flt0->x!=flt1->x)
		return 0;
	if(flt0->y==flt1->y)
		return 1;
	else
		return 0;
}

void ribon(){

	FRMHED*		tfrm;
	unsigned	ind,fpnt,clobak;
	
	frm1pnt();
	if(chkMap(FORMSEL)){

		fvars(clofind);
		if(sids>2){

			savdo();
			clobak=clofind;
			satout(brdwid);

			plen=brdwid/2;
			tfrm=&formlst[formpnt];
			frmclr(tfrm);
			fpnt=0;
			tfrm->fmax=9*PFGRAN;
			tfrm->fmin=minsiz;
			maxs=9*PFGRAN;
			if(frmpnt->typ==LIN){

				if(chku(BLUNT))
					ind=0xffffffff;
				else
					ind=0;
				satends(ind);
				tfrm->flt=adflt(sids<<1);
				tfrm->flt[0].x=opnts[0].x;
				tfrm->flt[fpnt++].y=opnts[0].y;
				for(ind=0;ind<sids;ind++){

					tfrm->flt[fpnt].x=ipnts[ind].x;
					tfrm->flt[fpnt++].y=ipnts[ind].y;
				}
				for(ind=sids-1;ind;ind--){

					tfrm->flt[fpnt].x=opnts[ind].x;
					tfrm->flt[fpnt++].y=opnts[ind].y;
				}
			}
			else{

				tfrm->flt=adflt((sids<<1)+2);
				tfrm->flt[0].x=opnts[0].x;
				tfrm->flt[fpnt++].y=opnts[0].y;
				tfrm->wind=ini.wind;
				for(ind=0;ind<sids;ind++){

					tfrm->flt[fpnt].x=ipnts[ind].x;
					tfrm->flt[fpnt++].y=ipnts[ind].y;
				}
				tfrm->flt[fpnt].x=ipnts[0].x;
				tfrm->flt[fpnt++].y=ipnts[0].y;
				tfrm->flt[fpnt].x=opnts[0].x;
				tfrm->flt[fpnt++].y=opnts[0].y;
				for(ind=sids-1;ind;ind--){

					tfrm->flt[fpnt].x=opnts[ind].x;
					tfrm->flt[fpnt++].y=opnts[ind].y;
				}
			}
			tfrm->typ=SAT;
			tfrm->fcol=actcol;
			tfrm->fspac=stspace;
			tfrm->flencnt.flen=ini.maxsiz;
			tfrm->sids=fpnt;
			tfrm->at=1;
			tfrm->wpar=fpnt>>1;
			tfrm->stpt=tfrm->wpar-2;
			tfrm->sacang.sac=adsatk(tfrm->stpt);
			if(chkMap(CNV2FTH)){

				tfrm->ftyp=FTHF;
				tfrm->dhx.fth.fthrat=ini.fthrat;
				tfrm->dhx.fth.fthup=ini.fthup;
				tfrm->dhx.fth.fthdwn=ini.fthdwn;
				tfrm->dhx.fth.fthtyp=ini.fthtyp;
				tfrm->dhx.fth.fthflr=ini.fthflr;
				tfrm->xat=ini.fthbits;
				tfrm->dhx.fth.fthnum=ini.fthnum;
				tfrm->dhx.fth.fthcol=(actcol+1)&COLMSK;
			}
			else
				tfrm->ftyp=SATF;
			for(ind=0;ind<tfrm->stpt;ind++){

				tfrm->sacang.sac[ind].strt=ind+2;
				tfrm->sacang.sac[ind].fin=tfrm->sids-ind-1;
			}
			formpnt++;
			frmout(formpnt-1);
			clofind=formpnt-1;
			refilfn();
			clofind=clobak;
			setMap(DELTO);
			frmdel();
			clofind=formpnt-1;
			setMap(FORMSEL);
			setMap(INIT);
			setMap(RESTCH);
		}
		else
			tabmsg(IDS_FRM2);
	}
	else
		shoseln(IDS_FRM1MSG,IDS_CONVRIB);
}

void dupfn(){

	savdo();
	rotpar();
	if(ini.rotang){

		if(chkMap(FORMSEL))
			duprot();
		else{
			
			if(chkMap(GRPSEL))
				duprots();
			else{

				if(fselpnt)
					duprotfs();
				else
					shord();
			}
		}
	}
	else{

		rotentr();
		setMap(ENTRDUP);
	}
}

void redup(){

	ang=ini.rotang;
	dupfn();
}

void bakdup(){

	ang=2*PI-ini.rotang;
	dupfn();
}

void shrnks(unsigned find){

	unsigned	ind,ine,cnt;
	DUBPNT		dif;
	double		len,rat,dlen,adif;

	oclp(frmpnt->clp,frmpnt->nclp);	
	for(ind=0;ind<(unsigned)sids-1;ind++){
		
		dif.x=flt[ind+1].x-flt[ind].x;
		dif.y=flt[ind+1].y-flt[ind].y;
		len=hypot(dif.x,dif.y);
		cnt=len/clpsiz.cx+0.5;
		rat=(clpsiz.cx*cnt+0.004)/len;
		flt[ind+1].x=flt[ind].x+dif.x*rat;
		flt[ind+1].y=flt[ind].y+dif.y*rat;
	}
	dif.x=flt[0].x-flt[1].x;
	dif.y=flt[0].y-flt[1].y;
	len=hypot(dif.x,dif.y);
	ang=atan2(dif.y,dif.x);
	for(ine=0;ine<5;ine++){

		dif.x=flt[0].x-flt[ind].x;
		dif.y=flt[0].y-flt[ind].y;
		dlen=hypot(dif.x,dif.y);
		cnt=dlen/clpsiz.cx;
		adif=dlen-cnt*clpsiz.cx;
		ang-=adif/len;
		dif.x=cos(ang)*len;
		dif.y=sin(ang)*len;
		flt[0].x=flt[1].x+dif.x;
		flt[0].y=flt[1].y+dif.y;
	}
	refil();
}

void shrnk(){

	fvars(clofind);
	if(chkMap(FORMSEL)&&frmpnt->etyp==EGCLP){

		shrnks(clofind);
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_FRMCLP,IDS_SHRNK);
}

void mvfrms(FRMHED* dst,FRMHED* src,unsigned cnt){
	memcpy(dst, src, cnt * fsizeof * 4);
}

void dufdat(unsigned find){

	FRMHED*	dst;
	FRMHED* src;

	dst=&rfrmlst[frepnt++];
	src=&formlst[find];
	mvfrms(dst,src,1);
	mvflpnt(&rflts[fltad],dst->flt,dst->sids);
	dst->flt=&flts[fltad];
	fltad+=dst->sids;
	if(dst->stpt){

		mvsatk(&rsats[satkad],dst->sacang.sac,dst->stpt);
		dst->sacang.sac=&satks[satkad];
		satkad+=dst->stpt;
	}
	if(iseclpx(find))
	{
		mvflpnt(&rclps[clpad],dst->clp,dst->nclp);
		dst->clp=&clps[clpad];
		clpad+=dst->nclp;
	}
	if(isclpx(find))
	{
		mvflpnt(&rclps[clpad],dst->angclp.clp,dst->flencnt.nclp);
		dst->angclp.clp=&clps[clpad];
		clpad+=dst->flencnt.nclp;
	}
}

void stchfrm(unsigned fnum,unsigned* at){
	*at &= NFRMSK;
	*at |= fnum << FRMSHFT;
}

void frmnumfn(unsigned nunum){

	unsigned	ind,srcpnt,strt,fin,cod;

	if(nunum!=clofind){

		if(clofind>nunum){

			strt=nunum;
			fin=clofind;
		}
		else{

			strt=clofind;
			fin=nunum;
		}
		srcpnt=frepnt=0;
		rfrmlst=(FRMHED*)&bseq;
		rflts=(FLPNT*)&rfrmlst[formpnt];
		rsats=(SATCON*)&oseq;
		rclps=(FLPNT*)&rsats[satkad];
		fltad=satkad=clpad=0;
		for(ind=0;ind<formpnt;ind++){

			if(ind==nunum)
				dufdat(clofind);
			else{

				if(srcpnt==clofind)
					srcpnt++;
				dufdat(srcpnt++);
			}
		}
		mvfrms(formlst,rfrmlst,formpnt);
		mvflpnt(flts,rflts,fltad);
		mvsatk(satks,rsats,satkad);	
		mvflpnt(clps,rclps,clpad);
		for(ind=0;ind<hed.stchs;ind++){

			if(stchs[ind].at&TYPMSK){

				cod=(stchs[ind].at&FRMSK)>>FRMSHFT;
				if(cod==clofind)
						stchfrm(nunum,&stchs[ind].at);
				else{

					if(cod>=strt&&cod<=fin){

						if(nunum<clofind)						
							stchfrm(cod+1,&stchs[ind].at);
						else
							stchfrm(cod-1,&stchs[ind].at);
					}
				}
			}
		}
		clofind=nunum;
		ritnum(STR_NUMFRM,clofind);
	}
}

void frmnum(){

	TCHAR	buf[HBUFSIZ];
	
	if(formpnt&&chkMap(FORMSEL)){

		LoadString(hInst,IDS_FRML,buf,HBUFSIZ);
		sprintf(msgbuf,buf,formpnt);
		shoMsg(msgbuf);
		setMap(NUMIN);
		setMap(ENTRFNUM);
		numWnd();
	}
	else
		shoseln(IDS_FRM1MSG,IDS_SETFRM);
}

unsigned duat(unsigned at){
	unsigned typ = ((at >> TYPSHFT) + 1) & 3;
	unsigned frm = (at & FRMSK) >> 2;

	return typ | frm;
}

void srtf(unsigned strt,unsigned fin){

	unsigned*	frmhst;
	unsigned	ind,ine,tmp;

	if(strt!=fin){

		frmhst=(unsigned*)&bseq;
		for(ind=0;ind<formpnt<<2;ind++)
			frmhst[ind]=0;
		for(ind=strt;ind<fin;ind++)
			frmhst[duat(hifstch[ind].at)]++;
		ine=strt;
		for(ind=0;ind<formpnt<<2;ind++){

			tmp=frmhst[ind];
			frmhst[ind]=ine;
			ine+=tmp;
		}
		for(ind=strt;ind<fin;ind++)
			mvstch(&stchs[frmhst[duat(hifstch[ind].at)]++],&hifstch[ind]);
	}
}

void srtbyfrm(){

	unsigned	ind,ine,tmp;
	unsigned	colhst[16];
	unsigned	colr[16];

	if(formpnt){

		savdo();
		colr[apcol]=0;
		for(ind=0;ind<16;ind++){

			if(ind!=apcol)
				colr[ind]=ind+1;
		}
		hifstch=&stchs[MAXSEQ];
		for(ind=0;ind<16;ind++)
			colhst[ind]=0;
		for(ind=0;ind<hed.stchs;ind++)
			colhst[colr[stchs[ind].at&0xf]]++;
		ine=0;
		for(ind=0;ind<16;ind++){

			tmp=colhst[ind];
			colhst[ind]=ine;
			ine+=tmp;
		}
		for(ind=0;ind<hed.stchs;ind++)
			mvstch(&hifstch[colhst[colr[stchs[ind].at&0xf]]++],&stchs[ind]);
		srtf(0,colhst[0]);
		for(ind=0;ind<15;ind++)
			srtf(colhst[ind],colhst[ind+1]);
	}
	else
		srtcol();
	coltab();
	setMap(RESTCH);
}

void dufcntr(DUBPNT* cntr){

	unsigned	ind;
	FLRCT*		trct;
	FLRCT		brct;

	trct=&formlst[selist[0]].rct;
	brct.left=trct->left;
	brct.right=trct->right;
	brct.top=trct->top;
	brct.bottom=trct->bottom;
	for(ind=1;ind<fselpnt;ind++){

		trct=&formlst[selist[ind]].rct;
		if(trct->left<brct.left)
		brct.left=trct->left;
		if(trct->right>brct.right)
		brct.right=trct->right;
		if(trct->bottom<brct.bottom)
		brct.bottom=trct->bottom;
		if(trct->top>brct.top)
		brct.top=trct->top;
	}
	cntr->x=(brct.right-brct.left)/2+brct.left;
	cntr->y=(brct.top-brct.bottom)/2+brct.bottom;
}

void cntrx(){

	DUBPNT		mrkcntr;
	DUBPNT		selcntr;
	unsigned	ind,flg;
	FLRCT*		trct;
	FLRCT		grct;

	if(chkMap(GMRK)){

		mrkcntr.x=mrkpnt.x;
		mrkcntr.y=mrkpnt.y;
	}
	else{

		mrkcntr.x=zum0.x/2;
		mrkcntr.y=zum0.y/2;
	}
	flg=0;
	if(fselpnt){

		flg=1;
		savdo();
		dufcntr(&selcntr);
		fmovdif.x=mrkcntr.x-selcntr.x;
		fmovdif.y=-mrkcntr.y+selcntr.y;
		if(chkMap(CNTRV))
			fmovdif.y=0;
		if(chkMap(CNTRH))
			fmovdif.x=0;
		for(ind=0;ind<fselpnt;ind++)
			frmadj(selist[ind]);
		frmsadj();
	}
	else{

		if(chkMap(FORMSEL)){

			flg=1;
			savdo();
			trct=&formlst[clofind].rct;
			selcntr.x=(trct->right-trct->left)/2+trct->left;
			selcntr.y=(trct->top-trct->bottom)/2+trct->bottom;
			fmovdif.x=mrkcntr.x-selcntr.x;
			fmovdif.y=-mrkcntr.y+selcntr.y;
			if(chkMap(CNTRV))
				fmovdif.y=0;
			if(chkMap(CNTRH))
				fmovdif.x=0;
			frmadj(clofind);
			for(ind=0;ind<hed.stchs;ind++){

				if(stchs[ind].at&ALTYPMSK&&(stchs[ind].at&FRMSK)>>FRMSHFT==clofind){

					stchs[ind].x+=fmovdif.x;
					stchs[ind].y-=fmovdif.y;
				}
			}
		}
		else{

			if(chkMap(GRPSEL)){

				flg=1;
				savdo();
				rngadj();
				grct.right=grct.left=stchs[gpnt0].x;
				grct.top=grct.bottom=stchs[gpnt0].y;
				for(ind=gpnt0+1;ind<=gpnt1;ind++){

					if(stchs[ind].x<grct.left)
						grct.left=stchs[ind].x;
					if(stchs[ind].x>grct.right)
						grct.right=stchs[ind].x;
					if(stchs[ind].y<grct.bottom)
						grct.bottom=stchs[ind].y;
					if(stchs[ind].y>grct.top)
						grct.top=stchs[ind].y;
				}
				selcntr.x=(grct.right-grct.left)/2+grct.left;
				selcntr.y=(grct.top-grct.bottom)/2+grct.bottom;
				fmovdif.x=mrkcntr.x-selcntr.x;
				fmovdif.y=-mrkcntr.y+selcntr.y;
				if(chkMap(CNTRV))
					fmovdif.y=0;
				if(chkMap(CNTRH))
					fmovdif.x=0;
				for(ind=gpnt0;ind<=gpnt1;ind++){

					stchs[ind].x+=fmovdif.x;
					stchs[ind].y-=fmovdif.y;
				}
			}
			else
				shoseln(IDS_FGRPF,IDS_CENT);
		}
	}
	if(flg)
		setMap(RESTCH);
}

void centir(){

	DUBPNT		scntr;
	DUBPNT		dcntr;
	DUBPNT		dif;
	unsigned	ind;

	rstMap(BIGBOX);
	getbig();
	dcntr.x=(rctal.right-rctal.left)/2+rctal.left;
	dcntr.y=(rctal.top-rctal.bottom)/2+rctal.bottom;
	scntr.x=zum0.x/2;
	scntr.y=zum0.y/2;
	dif.x=scntr.x-dcntr.x;
	dif.y=scntr.y-dcntr.y;
	for(ind=0;ind<hed.stchs;ind++){

		stchs[ind].x+=dif.x;
		stchs[ind].y+=dif.y;
	}
	for(ind=0;ind<fltad;ind++){

		flts[ind].x+=dif.x;
		flts[ind].y+=dif.y;
	}
	for(ind=0;ind<formpnt;ind++)
		frmout(ind);
	setfchk();
	setMap(RESTCH);
}

void bean(unsigned strt,unsigned fin){

	unsigned ind,ine,inf;

	ine=MAXSEQ;
	ind=strt;
	beancnt=0;
	mvstch(ine++,ind);
	if(stchs[ind+2].x!=stchs[ind].x||stchs[ind+2].y!=stchs[ind].y){

			mvstch(ine++,ind+1);
			mvstch(ine++,ind);
			beancnt+=2;
	}
	ind++;
	mvstch(ine++,ind);
	if(stchs[ind+2].x!=stchs[ind].x||stchs[ind+2].y!=stchs[ind].y){

			mvstch(ine++,ind+1);
			mvstch(ine++,ind);
			beancnt+=2;
	}
	ind++;
	while(ind<(unsigned)fin-2){

		mvstch(ine++,ind);
		if(	(stchs[ind+2].x!=stchs[ind].x||stchs[ind+2].y!=stchs[ind].y)&&
			(stchs[ind-2].x!=stchs[ind].x||stchs[ind-2].y!=stchs[ind].y)){

			mvstch(ine++,ind+1);
			mvstch(ine++,ind);
			beancnt+=2;
		}
		ind++;
	}
	mvstch(ine++,ind);
	if((stchs[ind-2].x!=stchs[ind].x||stchs[ind-2].y!=stchs[ind].y)){

		mvstch(ine++,ind+1);
		mvstch(ine++,ind);
		beancnt+=2;
	}
	ind++;
	while(ind<hed.stchs)
		mvstch(ine++,ind++);
	inf=strt;
	for(ind=MAXSEQ;ind<ine;ind++)
		mvstch(inf++,ind);
	hed.stchs=inf;
}

void dubean(){

	if(hed.stchs){

		savdo();
		if(chkMap(GRPSEL)){

			rngadj();
			bean(gpnt0,gpnt1);
			if(cloInd>grpInd)
				cloInd+=beancnt;
			else
				grpInd+=beancnt;
			grpAdj();
		}
		else
			bean(0,hed.stchs-1);
		coltab();
		setMap(RESTCH);
	}
}

void unbean(unsigned strt,unsigned fin){

	unsigned ind,ine;

	ine=MAXSEQ;
	beancnt=0;
	for(ind=strt;ind<=fin;ind++){

		mvstch(ine++,ind);
		if(stchs[ind].x==stchs[ind+2].x&&stchs[ind].y==stchs[ind+2].y){

			ind+=2;
			beancnt+=2;
		}
	}
	if(beancnt)
		beancnt-=2;;
	if(ind>(unsigned)hed.stchs-1)
		ind=hed.stchs-1;
	while(ind<hed.stchs)
		mvstch(ine++,ind++);
	mvstchs(strt,MAXSEQ,ine);
	hed.stchs=strt+ine;
}

void debean(){

	savdo();
	if(chkMap(GRPSEL)){

		rngadj();
		unbean(gpnt0,gpnt1);
		if(cloInd>grpInd)
			cloInd-=beancnt;
		else
			grpInd-=beancnt;
		if(cloInd>(unsigned)hed.stchs-1)
			cloInd=hed.stchs-1;
		if(grpInd>(unsigned)hed.stchs-1)
			grpInd=hed.stchs-1;
		grpAdj();
	}
	else
		unbean(0,hed.stchs-1);
	coltab();
	setMap(RESTCH);
}

void mvfrmsb(FRMHED* dst,FRMHED* src,unsigned cnt){
	memmove(dst, src, cnt * sizeof(FRMHED));
}

inline static void mvfltsb(FLPNT* dst,FLPNT* src,unsigned cnt){
	memmove(dst, src, cnt * sizeof(FLPNT));
}

void clpspac(FLPNT* pins,unsigned cnt){

	mvfltsb(&clps[clpad+cnt-1],&clps[clpad-1],clpad-clpind(pins));
}

void stchadj(){

	unsigned ind,lo,hi;

	for(ind=0;ind<hed.stchs;ind++){

		hi=stchs[ind].at&FRMSK;
		lo=hi>>FRMSHFT;
		if(lo>clofind){

			stchs[ind].at&=NFRMSK;
			hi+=1<<FRMSHFT;
			stchs[ind].at|=hi;
		}
	}
	refilfn();
	lo=clofind<<FRMSHFT;
	for(ind=hed.stchs-1;ind<hed.stchs;ind--){

		hi=stchs[ind].at&FRMSK;
		if((stchs[ind].at&FRMSK)==lo){

			delpnt=ind+1;
			break;
		}
	}
	clofind++;
	refilfn();
	rstMap(FRMPSEL);
}

void spltsat(SATCON tsac){

	FLPNT*		hiflt;
	unsigned	ind,lo,hi,hibak;

	hiflt=(FLPNT*)&oseq;
	mvfrmsb(&formlst[formpnt],&formlst[formpnt-1],formpnt-clofind);
	formpnt++;
	if(clofind<(unsigned)formpnt-2)
		mvfltsb(&flts[fltad+1],&flts[fltad-1],fltad-fltind(formlst[clofind+2].flt));
	fltad+=2;
	for(ind=clofind+2;ind<formpnt;ind++)
		formlst[ind].flt+=2;
	lo=0;
	hibak=tsac.strt+(sids-tsac.fin)+1;
	hi=hibak+1;
	for(ind=0;ind<sids;ind++){
	
		if(ind==tsac.strt||ind==tsac.fin){

			hiflt[lo].x=flt[ind].x;
			hiflt[lo++].y=flt[ind].y;
			if(ind==tsac.strt){

				hiflt[hi].x=flt[ind].x;
				hiflt[hi++].y=flt[ind].y;
			}
			else{

				hiflt[hibak].x=flt[ind].x;
				hiflt[hibak].y=flt[ind].y;
			}
		}
		else{

			if(ind<tsac.strt){

				hiflt[lo].x=flt[ind].x;
				hiflt[lo++].y=flt[ind].y;
			}
			else{

				if(ind<tsac.fin){

					hiflt[hi].x=flt[ind].x;
					hiflt[hi++].y=flt[ind].y;
				}
				else{

					hiflt[lo].x=flt[ind].x;
					hiflt[lo++].y=flt[ind].y;
				}
			}
		}
	}
	for(ind=0;ind<hi;ind++){

		flt[ind].x=hiflt[ind].x;
		flt[ind].y=hiflt[ind].y;
	}
	frmpnt->sids=lo;
	formlst[clofind+1].sids=hi-lo;
	formlst[clofind+1].flt=&flt[lo];
	frmout(clofind);
	frmout(clofind+1);
	lo=tsac.strt+1-tsac.fin;
	for(ind=0;ind<xpnt;ind++)
		frmpnt->sacang.sac[ind].fin+=lo;
	if(frmpnt->wpar)
		frmpnt->wpar=tsac.strt;
	lo=ind+1;
	while(ind<(unsigned)frmpnt->stpt){

		frmpnt->sacang.sac[ind].strt-=(tsac.strt-1);
		frmpnt->sacang.sac[ind].fin-=(tsac.strt-1);
		ind++;
	}
	if(formlst[clofind+1].wpar)
		formlst[clofind+1].wpar-=(tsac.strt-1);
	mvsatk(&frmpnt->sacang.sac[lo-1],&frmpnt->sacang.sac[lo],satkad-sacind(&frmpnt->sacang.sac[lo]));
	satkad--;
	formlst[clofind+1].sacang.sac=&frmpnt->sacang.sac[xpnt];
	formlst[clofind+1].stpt=frmpnt->stpt-xpnt-1;
	frmpnt->stpt=xpnt;
	for(ind=clofind+2;ind<formpnt;ind++)
		formlst[ind].sacang.sac--;
	if(iseclp(clofind)){

		clpspac(frmpnt->clp,frmpnt->nclp);
		for(ind=clofind+1;ind<formpnt;ind++)
			formlst[ind].clp+=frmpnt->nclp;
	}
	stchadj();
}

BOOL spltlin(){

	unsigned ind;

	if(clofine<2||frmpnt->sids-clofine<2)
		return 0;
	mvfrmsb(&formlst[formpnt],&formlst[formpnt-1],formpnt-clofind);
	formpnt++;
	frmpnt->sids=clofine;
	formlst[clofind+1].sids-=clofine;
	formlst[clofind+1].flt=&frmpnt->flt[clofine];
	frmout(clofind);
	frmout(clofind+1);
	if(iseclp(clofind)){

		clpspac(frmpnt->clp,frmpnt->nclp);
		for(ind=clofind+1;ind<formpnt;ind++)
			formlst[ind].clp+=frmpnt->nclp;
	}
	stchadj();
	return 1;
}

void spltfrm(){

	if(chkMap(FRMPSEL)){

		savdo();
		fvars(clofind);
		if(frmpnt->typ==SAT){

			if(frmpnt->stpt){

				delfstchs();
				frmpnt->ftyp=0;
				frmpnt->etyp=0;
				for(xpnt=0;xpnt<frmpnt->stpt;xpnt++){

					if(frmpnt->sacang.sac[xpnt].strt==clofine||frmpnt->sacang.sac[xpnt].fin==clofine){

						spltsat(frmpnt->sacang.sac[xpnt]);
						return;
					}
				}
				spltmsg();
			}
			else
				spltmsg();
		}
		else{

			if(frmpnt->typ=LIN){

				if(spltlin()){
				
					coltab();
					setMap(RESTCH);
				}
				else
					tabmsg(IDS_FRM3);
				return;
			}
			else
				spltmsg();
		}
	}
	spltmsg();
}

void stchs2frm(){

	unsigned ind,ine,len;

	if(chkMap(GRPSEL)){

		rngadj();
		if((gpnt1-gpnt0)>12000){

			tabmsg(IDS_STMAX);
			return;
		}
		len=gpnt1-gpnt0+1;
		frmpnt=&formlst[formpnt];
		frmclr(frmpnt);
		frmpnt->typ=LIN;
		frmpnt->sids=len;
		frmpnt->flt=adflt(len);
		ine=0;
		for(ind=gpnt0;ind<=gpnt1;ind++){
		
			frmpnt->flt[ine].x=stchs[ind].x;
			frmpnt->flt[ine++].y=stchs[ind].y;
		}
		frmout(formpnt);
		formpnt++;
		if(cloInd>grpInd){

			if(cloInd<(unsigned)hed.stchs-1)
				cloInd++;
		}
		else{

			if(grpInd<(unsigned)hed.stchs-1)
				grpInd++;
		}
		delstchm();
		rstMap(GRPSEL);
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_GRPMSG,IDS_STCH2FRM);
}

int lencmp(const void *arg1,const void *arg2){
	double double1 = **(double **)arg1, double2 = **(double **)arg2;
	
	if (double1 == double2)
		return 0;

	if (double2 < double1)
		return 1;

	return -1;
}

void chksid(unsigned find){

	unsigned ind,lim;

	if(vclpsid!=find){
	
		if((find-vclpsid+sids)%sids<(unsigned)(sids>>1)){

			ind=nxt(vclpsid);
			lim=nxt(find);
			while(ind!=lim){

				oseq[seqpnt].x=flt[ind].x;
				oseq[seqpnt++].y=flt[ind].y;
				ind=nxt(ind);
			}
		}
		else{

			ind=vclpsid;
			while(ind!=find){

				oseq[seqpnt].x=flt[ind].x;
				oseq[seqpnt++].y=flt[ind].y;
				ind=prv(ind);
			}
		}
	}
}

void ritseg(){

	unsigned	ind;
	BOOL		pntd;

	pntd=1;
	if(frmpnt->xat&AT_SQR)
		pntd=0;
	if(chkMap(FILDIR)){

		ind=clpsegs[xpnt].strt;
		if(chkMap(TXFIL)&&pntd)
			ind++;
		chksid(clpsegs[xpnt].asid);
		while(ind<=clpsegs[xpnt].fin){

			oseq[seqpnt].x=clipnts[ind].x;
			oseq[seqpnt++].y=clipnts[ind++].y;
		}
		vclpsid=clpsegs[xpnt].zsid;
	}
	else{

		ind=clpsegs[xpnt].fin;
		if(chkMap(TXFIL)&&pntd)
			ind--;
		chksid(clpsegs[xpnt].zsid);
		if(clpsegs[xpnt].strt){

			while(ind>=clpsegs[xpnt].strt){

				oseq[seqpnt].x=clipnts[ind].x;
				oseq[seqpnt++].y=clipnts[ind--].y;
			}
		}
		else{

			while(ind<clpsegs[xpnt].strt){

				oseq[seqpnt].x=clipnts[ind].x;
				oseq[seqpnt++].y=clipnts[ind--].y;
			}
		}
		vclpsid=clpsegs[xpnt].asid;
	}
	clpsegs[xpnt].dun=1;
}

unsigned lenref(float* pflt){
	unsigned eax = (unsigned) pflt - (unsigned) clpsegs;

	unsigned edx = eax / 29;
	eax %= 29;

	eax <<= 1;

	if ((edx & 0xFF) == 18)
		eax++;

	return eax;
}

BOOL clpnxt(unsigned sind){

	unsigned ind;

	ind=1;
	rstMap(FILDIR);
	while(ind<pcseg){

		if(toglMap(FILDIR)){

			opnt=(sind+ind)%pcseg2;
			if(!clpsegs[lenref(plens[opnt])>>1].dun)
				return 0;
			ind++;
		}
		else{

			opnt=(sind+pcseg2-ind)%pcseg2;
			if(!clpsegs[lenref(plens[opnt])>>1].dun)
				return 0;
		}
	}
	return 1;
}

BOOL nucseg(){

	unsigned	ind;

	if(chkMap(FILDIR))
		ind=clpsegs[xpnt].eind;
	else
		ind=clpsegs[xpnt].bind;
	if(clpnxt(ind))
		return 0;
	ind=lenref(plens[opnt]);
	if(ind&1)
		rstMap(FILDIR);
	else
		setMap(FILDIR);
	xpnt=ind>>1;
	return 1;
}

void mvpclp(unsigned dst,unsigned src){
	memcpy(pclpsrt[dst], pclpsrt[src], 20);
}

float getlen(unsigned ind){

	clipnts[ind].sid%=sids;
	return	lens[clipnts[ind].sid]+
			hypot(flt[clipnts[ind].sid].x-clipnts[ind].x,
			flt[clipnts[ind].sid].y-clipnts[ind].y);
}

unsigned leftsid(){

	unsigned	ind,sid;
	float		minx;

	minx=1e9;
	sid=0;
	for(ind=0;ind<sids;ind++){

		if(flt[ind].x<minx){

			minx=flt[ind].x;
			sid=ind;
		}
	}
	return sid;
}

int clpcmp(const void* arg1,const void* arg2){
	VCLPX *vclpx1 = (VCLPX *) arg1, *vclpx2 = (VCLPX *) arg2;
	if (vclpx1->seg < vclpx2->seg)
		return -1;

	if (vclpx1->seg > vclpx2->seg)
		return 1;

	if (vclpx1->sid == vclpx2->sid)
		return 0;

	if (vclpx1->sid < vclpx2->sid)
		return -1;

	return 1;
}

BOOL isect(unsigned find0,unsigned find1,FLPNT* ipnt,float* len){

	DUBPNT		dif;
	DUBPNT		tpnt;
	DUBPNT		tipnt;
	unsigned	flg;
	float		lft;
	float		rit;

	dif.x=vpnt1.x-vpnt0.x;
	dif.y=vpnt1.y-vpnt0.y;
	tpnt.x=vpnt0.x;
	tpnt.y=vpnt0.y;
	flg=0;
	if(dif.x&&dif.y)
		flg=proj(tpnt,dif.y/dif.x,flt[find0],flt[find1],&tipnt);
	else{

		if(dif.y)
			flg=projv(tpnt.x,flt[find0],flt[find1],&tipnt);
		else{

			if(dif.x)
				flg=projh(tpnt.y,flt[find0],flt[find1],&tipnt);
			else
				if(flt[find0].y==vpnt0.y&&flt[find1].y==vpnt0.y)
				{
					if(flt[find0].x<flt[find1].x)
					{
						lft=flt[find0].x;
						rit=flt[find1].x;
					}
					else
					{
						lft=flt[find1].x;
						rit=flt[find0].x;
					}
					if(vpnt0.x>lft&&vpnt0.x<rit)
					{
						ipnt->x=vpnt0.x;
						ipnt->y=vpnt0.y;
						*len=0;
						return 1;
					}
					return 0;
				}
				else
					return 0;
		}
	}
	if(tipnt.x<TINY)
		tipnt.x=0;
	if(tipnt.y<TINY)
		tipnt.y=0;
	ipnt->x=(float)tipnt.x;
	ipnt->y=(float)tipnt.y;
	*len=hypot(tipnt.x-vpnt0.x,tipnt.y-vpnt0.y);
		 hypot(tipnt.x-vpnt1.x,tipnt.y-vpnt1.y);
	return flg;
}

unsigned insect(){

	unsigned	ind,ine,cnt;
	unsigned	svrt,nvrt;
	FLRCT		lrct;
	FLPNT*		ipnt;

	if(vpnt1.x>vpnt0.x){

		lrct.left=vpnt0.x;
		lrct.right=vpnt1.x;
	}
	else{

		lrct.left=vpnt1.x;
		lrct.right=vpnt0.x;
	}
	if(vpnt1.y>vpnt0.y){

		lrct.top=vpnt1.y;
		lrct.bottom=vpnt0.y;
	}
	else{

		lrct.top=vpnt0.y;
		lrct.bottom=vpnt1.y;
	}
	ine=cnt=0;
	for(ind=vstrt;ind<vfin;ind++){

		svrt=vclpx[ind].sid;
		nvrt=nxt(svrt);
		if(isect(svrt,nvrt,&clpsrt[ine].pnt,&clpsrt[ine].sidlen)){

			ipnt=&clpsrt[ine].pnt;
			if(	ipnt->x>=lrct.left&&
				ipnt->x<=lrct.right&&
				ipnt->y>=lrct.bottom&&
				ipnt->y<=lrct.top){

				clpsrt[ine].seglen=hypot(clpsrt[ine].pnt.x-vpnt0.x,clpsrt[ine].pnt.y-vpnt0.y);
				clpsrt[ine].lin=svrt;
				pclpsrt[ine]=&clpsrt[ine];
				ine++;
				cnt++;
			}
		}
	}
	if(cnt>1){

		qsort((void*)pclpsrt,cnt,4,lencmp);
		ine=1;
		for(ind=0;ind<cnt-1;ind++){

			if(fabs(pclpsrt[ind]->seglen-pclpsrt[ind+1]->seglen)>TINY)
				mvpclp(ine++,ind+1);
		}
		cnt=ine;
	}
	return cnt;
}

BOOL isin(float pntx,float pnty){

	unsigned	ind,acnt;
	unsigned	svrt,nvrt;
	DUBPNT		ipnt;

	if(pntx<isrct.left)
		return 0;
	if(pntx>isrct.right)
		return 0;
	if(pnty<isrct.bottom)
		return 0;
	if(pnty>isrct.top)
		return 0;
	acnt=0;
	for(ind=vstrt;ind<vfin;ind++)
	{
		svrt=vclpx[ind].sid;
		nvrt=nxt(svrt);
		if(projv(pntx,flt[svrt],flt[nvrt],&ipnt))
		{
			if(ipnt.y>pnty)
			{
				if(flt[svrt].x!=pntx&&flt[nvrt].x!=pntx)
					acnt++;
				else
				{
					if(flt[svrt].x<flt[nvrt].x)
					{
						if(flt[nvrt].x!=pntx)
							acnt++;
					}
					else
					{
						if(flt[svrt].x!=pntx)
							acnt++;
					}
				}
			}
		}
	}
	return acnt&1;
}

unsigned clpnseg(unsigned strt,unsigned fin){
	
	clpsegs[pcseg].strt=strt;
	clpsegs[pcseg].blen=getlen(strt);
	clpsegs[pcseg].asid=clipnts[strt].sid;
	clpsegs[pcseg].elen=getlen(fin);
	clpsegs[pcseg].zsid=clipnts[fin].sid;
	clpsegs[pcseg].fin=fin;
	clpsegs[pcseg++].dun=0;
	return fin+1;
}

unsigned vclpfor(unsigned ind){

	while(!clipnts[ind].flg&&ind<xpnt)
		ind++;
	return ind;
}
					
unsigned vclpbak(unsigned ind){

	while(!clipnts[ind].flg&&ind)
		ind--;
	return ind;
}

BOOL vscmp(unsigned ind,unsigned ine){
	if (oseq[ind].x != oseq[ine].x)
		return 1;

	return oseq[ind].y != oseq[ine].y ? 1 : 0;
}

void duflt(){

	unsigned	ind;
	float		lft;

	lft=1e9;
	for(ind=0;ind<sids;ind++){

		if(flt[ind].x<lft)
			lft=flt[ind].x;
	}
	if(lft<clpsiz.cx){

		setMap(WASNEG);
		fltof=clpsiz.cx+fabs(lft)+.05;
		for(ind=0;ind<sids;ind++)
			flt[ind].x+=fltof;
		frmpnt->rct.left+=fltof;
		frmpnt->rct.right+=fltof;
	}
	else
		rstMap(WASNEG);
}

void inspnt()
{
	clipnts[xpnt+1].x=clipnts[xpnt].x;
	clipnts[xpnt+1].y=clipnts[xpnt].y;
	clipnts[xpnt].x=midl(clipnts[xpnt+1].x,clipnts[xpnt-1].x);
	clipnts[xpnt].y=midl(clipnts[xpnt+1].y,clipnts[xpnt-1].y);
	clipnts[xpnt].flg=1;
	xpnt++;
}

void clpcon(){

	RECT		nrct;
	unsigned	ind,ine,inf,ing,nof,clpneg;
	unsigned	strt,fin,segxs,segps,seg,clrnum;
	unsigned	cnt;
	int			tine;
	FLPNT		ploc;
	double		tlen,minx;
	float		fnof;
	unsigned	clpnof;
	double		clpvof;
	TXPNT*		ptx;

	duflt();
	clpwid=clpsiz.cx+frmpnt->fspac;
	if(chkMap(ISUND))
		clpwid=frmpnt->uspac;
	if(frmpnt->fspac<0)
		clpneg=1;
	else
		clpneg=0;
	if(clpwid<CLPMINAUT)
		clpwid=(float)CLPMINAUT;
	if(chkMap(TXFIL))
	{
		if(txad&&frmpnt->dhx.txt.ind+frmpnt->dhx.txt.cnt<=txad)
			clpwid=frmpnt->fspac;
		else
			return;
	}
	lens=new double[sids+1];
	clplens=new double[sids];
	clpsrt=new CLIPSORT[sids];
	pclpsrt=new CLIPSORT*[sids];
	ine=leftsid();
	tlen=0;
	lens[ine]=0;
	ine=nxt(ine);
	for(ind=0;ind<=sids;ind++){
	
		inf=nxt(ine);
		lens[ine]=tlen;
		clplens[ine]=hypot(flt[inf].x-flt[ine].x,flt[inf].y-flt[ine].y);
		tlen+=clplens[ine];
		ine=inf;
	}
	clpcirc=tlen;
	clpcirc2=tlen/2;
	clpseq=(FLPNT*)&stchs[MAXSEQ];
//	clpsegs=(CLPSEG*)&bseq;
	clpsegs=(CLPSEG*)&stchs[MAXSEQ];
	nrct.left=floor(frmpnt->rct.left/clpwid);
	nrct.right=ceil(frmpnt->rct.right/clpwid);
	nrct.bottom=floor(frmpnt->rct.bottom/clpsiz.cy-1);
	nrct.top=ceil(frmpnt->rct.top/clpsiz.cy+1)+2;
	nof=0;
	if(frmpnt->wpar>1)
		clpnof=frmpnt->wpar;
	else
		clpnof=0;
	if(clpnof){

		nrct.top++;
		if(frmpnt->fspac<0){

			nrct.bottom--;
			nrct.left-=(float)clpsiz.cx/clpwid;
			nrct.right+=(float)clpsiz.cx/clpwid;
		}
	}
	if(clpneg&&!clpnof)
		nrct.left-=(float)clpsiz.cx/clpwid;
	if(nrct.bottom<0){

		nof=1-nrct.bottom;
		nrct.bottom+=nof;
		nrct.top+=nof;
		fnof=clpsiz.cy*nof;
		for(ind=0;ind<sids;ind++)
			flt[ind].y+=fnof;
	}
/*
	ing=0;
	for(ind=nrct.left;ind<=(unsigned)nrct.right;ind++){

		ploc.x=ind*clpwid;
		for(ine=nrct.bottom;ine<=(unsigned)nrct.top;ine++){

			ploc.y=ine*clpsiz.cy;
			for(inf=0;inf<clplen;inf++){

				stchs[ing].x=ploc.x+clpnu[inf].x;
				stchs[ing].y=ploc.y+clpnu[inf].y;
				stchs[ing].at=0;
				ing++;

			}
		}
	}
	hed.stchs=ing;
	return;*/

//	clipnts=(CLIPNT*)&stchs[MAXSEQ];
	clipnts=(CLIPNT*)&bseq;
	vclpx=(VCLPX*)&opnt;
	segxs=0;
	for(ind=0;ind<sids;ind++){

		strt=floor(flt[ind].x/clpwid);
		fin=floor((flt[nxt(ind)].x)/clpwid);
		if(strt>fin){

			ine=strt;
			strt=fin;
			fin=ine;
		}
		if(frmpnt->fspac<0)
			fin+=clpsiz.cx/clpwid;
		if(fin>(unsigned)nrct.right)
			fin=nrct.right;
		if(clpneg)
			strt-=(float)clpsiz.cx/clpwid;
		for(ine=strt;ine<=fin;ine++){
			vclpx[segxs].sid=ind;
			vclpx[segxs++].seg=ine;
		}
	}
	qsort((void*)vclpx,segxs,8,clpcmp);
	iclpx=(unsigned*)&vclpx[segxs];
	ine=1;inf=vclpx[0].seg;
	iclpx[0]=0;
	for(ind=1;ind<segxs;ind++){

		if(vclpx[ind].seg!=inf){

			iclpx[ine++]=ind;
			inf=vclpx[ind].seg;
		}
	}
	iclpx[ine]=ind;
	isrct.left=isrct.right=flt[0].x;
	isrct.top=isrct.bottom=flt[0].y;
	for(ind=1;ind<sids;ind++)
	{
		if(flt[ind].x>isrct.right)
			isrct.right=flt[ind].x;
		if(flt[ind].x<isrct.left)
			isrct.left=flt[ind].x;
		if(flt[ind].y>isrct.top)
			isrct.top=flt[ind].y;
		if(flt[ind].y<isrct.bottom)
			isrct.bottom=flt[ind].y;
	}
	segps=ine;
	ind=vstrt=cnt=0;
	seg=vclpx[0].seg;
	clrnum=(nrct.top>>5)+1;
	xpnt=0;
	for(ind=0;ind<segps;ind++){

		vstrt=iclpx[ind];
		vfin=iclpx[ind+1];
		ploc.x=clpwid*(ind+nrct.left);
		clpvof=0;
		if(chkMap(TXFIL))
		{
			tine=(ind+nrct.left)%frmpnt->dhx.txt.lins;
			clplen=txsegs[tine].cnt;
			ptx=&txpnts[frmpnt->dhx.txt.ind+txsegs[tine].lin];
			vpnt0.x=ploc.x;
			if(frmpnt->txof)
			{
				inf=(ind+nrct.left)/frmpnt->dhx.txt.lins;
				clpvof=fmod(frmpnt->txof*inf,frmpnt->dhx.txt.hi);
			}
		}
		else
		{
			if(clpnof)
				clpvof=(float)(ind%clpnof)/clpnof*clpsiz.cy;
			vpnt0.x=ploc.x+clpnu[0].x;
		}
		vpnt0.y=nrct.bottom*clpsiz.cy;
		if(clpnof)
			clpvof=(float)(ind%clpnof)/clpnof*clpsiz.cy;
		for(tine=nrct.bottom;tine<nrct.top;tine++){

			ploc.y=tine*clpsiz.cy-clpvof;
			vpnt1.x=ploc.x+clpnu[0].x;
			vpnt1.y=ploc.y+clpnu[0].y;
			if(!xpnt){

				vpnt0.x=vpnt1.x;
				vpnt0.y=vpnt1.y;
			}
			for(inf=0;inf<clplen;inf++){

				if(chkMap(TXFIL))
				{
					vpnt1.x=ploc.x;
					vpnt1.y=ploc.y+ptx[inf].y;
				}
				else
				{
					vpnt1.x=ploc.x+clpnu[inf].x;
					vpnt1.y=ploc.y+clpnu[inf].y;
				}
				clipnts[xpnt].x=vpnt0.x;
				clipnts[xpnt].y=vpnt0.y;
				if(isin(vpnt0.x,vpnt0.y))
				{
					if(xpnt&&clipnts[xpnt-1].flg==2)
						inspnt();
					clipnts[xpnt].flg=0;
				}
				else
				{
					if(xpnt&&!clipnts[xpnt-1].flg)
						inspnt();
					clipnts[xpnt].flg=2;
				}
				xpnt++;
				cnt=insect();
				if(cnt)
				{
					for(ing=0;ing<cnt;ing++){

						clipnts[xpnt].sid=pclpsrt[ing]->lin;
						clipnts[xpnt].x=pclpsrt[ing]->pnt.x;
						clipnts[xpnt].y=pclpsrt[ing]->pnt.y;
						clipnts[xpnt].flg=1;
						xpnt++;
						if(xpnt>MAXSEQ<<2)
							goto clpskp;
					}
				}
				vpnt0.x=vpnt1.x;
				vpnt0.y=vpnt1.y;
			}
		}
		clipnts[xpnt-1].flg=2;
	}
clpskp:;

	clipnts[xpnt].flg=2;
	if(nof){

		fnof=nof*clpsiz.cy;
		for(ind=0;ind<xpnt;ind++)
			clipnts[ind].y-=fnof;
		for(ind=0;ind<sids;ind++)
			flt[ind].y-=fnof;
	}
#define CLPVU 0
#define CLPNOP 0

#if CLPVU==1

	goto clp1skp;

#endif

	pcseg=0;
	regof=vclpx[0].seg;
	rstMap(FILDIR);
	ine=0;
	if(xpnt)
	{
		for(ind=0;ind<xpnt-1;ind++){

			switch(clipnts[ind].flg)
			{
			case 0:		//inside

				setMap(FILDIR);
				break;

			case 1:		//line

				if(toglMap(FILDIR))
					clpnseg(ine,ind);
				else
					ine=ind;
				break;

			case 2:		//outside

				rstMap(FILDIR);
				break;
			}
		}
	}

#if CLPVU==1

clp1skp:;

#endif

	delete lens;
	delete clplens;
	delete clpsrt;
	delete pclpsrt;

	if(pcseg){

		clplim=pcseg>>3;
		clplim=pcseg>>1;
		if(!clplim)
			clplim=1;
		if(clplim>12)
			clplim=12;
		plens=(float**)&clpsegs[pcseg];
		ine=0;
		for(ind=0;ind<pcseg;ind++){

			plens[ine++]=&clpsegs[ind].blen;
			plens[ine++]=&clpsegs[ind].elen;
		}
		qsort((void*)plens,ine,4,lencmp);
		ind=sizeof(CLPSEG);
		for(ind=0;ind<ine;ind++){

			inf=lenref(plens[ind]);
			ing=inf>>1;
			if(inf&1)
				clpsegs[ing].eind=ind;
			else
				clpsegs[ing].bind=ind;
		}

#if CLPVU==1

		for(ind=0;ind<xpnt;ind++){

			stchs[ind].x=clipnts[ind].x;
			stchs[ind].y=clipnts[ind].y;
			stchs[ind].at=0;
		}
		hed.stchs=xpnt;
#endif

#if	CLPVU==2

		inf=0;
		for(ind=0;ind<pcseg;ind++){

			for(ine=clpsegs[ind].strt;ine<=clpsegs[ind].fin;ine++){

				stchs[inf].x=clipnts[ine].x;
				stchs[inf].y=clipnts[ine].y;
				stchs[inf++].at=ind&0xf;
			}
		}
		hed.stchs=inf;

#endif

		minx=1e99;

#if CLPVU==0

		xpnt=0;
		setMap(FILDIR);
		seqpnt=0;
		pcseg2=pcseg<<1;
		vclpsid=clpsegs[0].asid;
		strtlen=clpsegs[0].elen;
		ritseg();
		while(nucseg()){

			if(seqpnt>MAXSEQ-3)
				break;
			ritseg();
		}
		chksid(0);
		if(seqpnt>MAXSEQ-100)
			seqpnt=MAXSEQ-100;
		ine=0;inf=0;
		for(ind=0;ind<seqpnt;ind++){

			if(vscmp(ind,ine)){

				ine++;
				oseq[ine].x=oseq[ind].x;
				oseq[ine].y=oseq[ind].y;
			}
			else
				inf++;
		}
		seqpnt=ine;
		if(chkMap(WASNEG)){

			for(ind=0;ind<seqpnt;ind++)
				oseq[ind].x-=fltof;
			for(ind=0;ind<sids;ind++)
				flt[ind].x-=fltof;
			frmpnt->rct.left-=fltof;
			frmpnt->rct.right-=fltof;
		}
#endif
	}
}

void vrtsclp(){

	unsigned ind;

	fvars(clofind);
	delmclp(clofind);
	deltx();
	frmpnt->flencnt.nclp=clplen;
	frmpnt->angclp.clp=numclp();
	frmpnt->wpar=ini.faz;
	makpoli();
	frmpnt->fspac=ini.clpof;
	for(ind=0;ind<clplen;ind++){

		frmpnt->angclp.clp[ind].x=clpnu[ind].x;
		frmpnt->angclp.clp[ind].y=clpnu[ind].y;
	}
	frmpnt->ftyp=VCLPF;
	frmpnt->fcol=actcol;
	frmpnt->typ=POLI;
	refilfn();
}

void vrtclp(){

	unsigned ind;

	if(filmsgs(FMM_CLP))
		return;
	if(OpenClipboard(hWnd)){

		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			redclp();
			CloseClipboard();
			if(clpsiz.cy>CLPMIN){

				if(fselpnt){

					setMap(NOCLP);
					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						if(frmpnt->typ!=LIN)
							vrtsclp();
					}
					rstMap(NOCLP);
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						fvars(clofind);
						vrtsclp();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else
			CloseClipboard();
	}
}

void angout(){

	FLRCT*		trct;
	unsigned	ine;

	if(angfrm.sids){

		trct=&angfrm.rct;
		flt=angfrm.flt;
		trct->left=trct->right=flt[0].x;
		trct->bottom=trct->top=flt[0].y;
		for(ine=1;ine<angfrm.sids;ine++){

			if(flt[ine].x>trct->right)
				trct->right=flt[ine].x;
			if(flt[ine].x<trct->left)
				trct->left=flt[ine].x;
			if(flt[ine].y<trct->bottom)
				trct->bottom=flt[ine].y;
			if(flt[ine].y>trct->top)
				trct->top=flt[ine].y;
		}
	}
}

void horclpfn(){

	unsigned ind;

	frmcpy(&angfrm,&formlst[clofind]);
	rotcntr.x=(double)(angfrm.rct.right-angfrm.rct.left)/2+angfrm.rct.left;
	rotcntr.y=(double)(angfrm.rct.top-angfrm.rct.bottom)/2+angfrm.rct.bottom;
	angfrm.flt=angflt;
	ang=PI/2;
	for(ind=0;ind<angfrm.sids;ind++){

		angfrm.flt[ind].x=frmpnt->flt[ind].x;
		angfrm.flt[ind].y=frmpnt->flt[ind].y;
		rotflt(&angfrm.flt[ind]);
	}
	angout();
	frmpnt=&angfrm;
	flt=angfrm.flt;
	clpcon();
	ang=-PI/2;
	rotbak();
	fvars(clofind);
}

void horsclp(){

	unsigned ind;

	fvars(clofind);
	delmclp(clofind);
	deltx();
	frmpnt->flencnt.nclp=clplen;
	frmpnt->angclp.clp=numclp();
	frmpnt->flencnt.nclp=clplen;
	frmpnt->wpar=ini.faz;
	makpoli();
	frmpnt->fspac=ini.clpof;
	for(ind=0;ind<clplen;ind++){

		frmpnt->angclp.clp[ind].x=clpnu[ind].x;
		frmpnt->angclp.clp[ind].y=clpnu[ind].y;
	}
	frmpnt->ftyp=HCLPF;
	frmpnt->fcol=actcol;
	frmpnt->typ=POLI;
	flt=frmpnt->flt;
	refilfn();
}

void horclp(){

	unsigned ind;

	if(filmsgs(FMM_CLP))
		return;
	if(OpenClipboard(hWnd)){

		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			redclp();
			CloseClipboard();
			if(clpsiz.cy>CLPMIN){

				if(fselpnt){
			
					setMap(NOCLP);
					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						if(frmpnt->typ!=LIN)
							horsclp();
					}
					setMap(NOCLP);
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						fvars(clofind);
						horsclp();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else
			CloseClipboard();
	}
}

void angclpfn()
{
	unsigned	ind;
	FLPNT*		tflt;

	frmcpy(&angfrm,&formlst[clofind]);
	rotcntr.x=(double)(angfrm.rct.right-angfrm.rct.left)/2+angfrm.rct.left;
	rotcntr.y=(double)(angfrm.rct.top-angfrm.rct.bottom)/2+angfrm.rct.bottom;
	angfrm.flt=angflt;
	if(chkMap(ISUND))
	{
		ang=PI/2-frmpnt->uang;
		tflt=insid();
		for(ind=0;ind<angfrm.sids;ind++)
		{
			angflt[ind].x=tflt[ind].x;
			angflt[ind].y=tflt[ind].y;
			rotflt(&angflt[ind]);
		}
	}
	else
	{
		if(chkMap(TXFIL))
			ang=PI/2-frmpnt->angclp.fang;
		else
			ang=PI/2-frmpnt->sacang.ang;
		for(ind=0;ind<angfrm.sids;ind++)
		{
			angflt[ind].x=frmpnt->flt[ind].x;
			angflt[ind].y=frmpnt->flt[ind].y;
			rotflt(&angflt[ind]);
		}
	}
	angout();
	frmpnt=&angfrm;
	flt=angflt;
	clpcon();
	ang=-ang;
	rotbak();
	fvars(clofind);
}

void angsclp(){

	unsigned ind;

	fvars(clofind);
	delmclp(clofind);
	deltx();
	frmpnt->angclp.clp=numclp();
	frmpnt->flencnt.nclp=clplen;
	frmpnt->wpar=ini.faz;
	makpoli();
	frmpnt->sacang.ang=ini.angl;
	frmpnt->fspac=ini.clpof;
	for(ind=0;ind<clplen;ind++){

		frmpnt->angclp.clp[ind].x=clpnu[ind].x;
		frmpnt->angclp.clp[ind].y=clpnu[ind].y;
	}
	frmpnt->ftyp=ANGCLPF;
	frmpnt->fcol=actcol;
	frmpnt->typ=POLI;
	refilfn();
}

void angclp(){

	unsigned ind;

	if(filmsgs(FMM_CLP))
		return;
	if(OpenClipboard(hWnd)){

		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			redclp();
			CloseClipboard();
			if(clpsiz.cy>CLPMIN){

				if(fselpnt){

					setMap(NOCLP);
					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						if(frmpnt->typ!=LIN)
							angsclp();
					}
					rstMap(NOCLP);
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						frmpnt=&formlst[clofind];
						angsclp();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else
			CloseClipboard();
	}
}

void dubfn(){

	unsigned ind,ine;

	brdfil(frmpnt->elen);
	ine=seqpnt;
	for(ind=seqpnt-1;ind<seqpnt;ind--){

		oseq[ine].x=oseq[ind].x;
		oseq[ine++].y=oseq[ind].y;
	}
	seqpnt=ine;
}

void dubsfil(){

	fvars(clofind);
	deleclp(clofind);
	frmpnt->etyp=EGDUB;
	seqpnt=0;
	frmpnt->bcol=actcol;
	dubfn();
	bsizpar();
	refilfn();
}

void dubfil(){

	unsigned ind;

	if(filmsgs(FML_LIN))
		return;
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			dubsfil();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			dubsfil();
			coltab();
			setMap(INIT);
			setMap(RESTCH);
		}
	}
}

void col2frm(){

	unsigned*	fcnts;
	unsigned*	bcnts;
	unsigned*	fthcnts;
	unsigned*	ucnts;
	unsigned	ind,ine,cod,cnt,maxcol;
	unsigned	strt,fin,chngcnt,fp16;
	TCHAR		buf[HBUFSIZ];

	chngcnt=0;
	fp16=formpnt<<4;
	if(formpnt){

		fcnts=(unsigned*)&oseq;
		bcnts=(unsigned*)&bseq;
		fthcnts=&bcnts[fp16];
		ucnts=&fthcnts[fp16];
		for(ind=0;ind<fp16;ind++){

			fcnts[ind]=0;
			bcnts[ind]=0;
			fthcnts[ind]=0;
			ucnts[ind]=0;
		}
		for(ind=0;ind<hed.stchs;ind++){

			cod=stchs[ind].at&0x3fff;
			if(stchs[ind].at&(WLKMSK|CWLKMSK|UNDMSK))
				ucnts[cod]++;
			else
			{
				if(stchs[ind].at&FTHMSK)
					fthcnts[cod]++;
				else{

					switch(stchs[ind].at&TYPMSK){

						case FRMFIL:

							fcnts[cod]++;
							break;

						case FRMBFIL:

							bcnts[cod]++;
							break;
					}
				}
			}
		}
		strt=0;fin=16;
		for(ind=0;ind<formpnt;ind++){

			if(formlst[ind].ftyp){

				cnt=maxcol=0;
				for(ine=strt;ine<fin;ine++){

					if(fcnts[ine]>cnt){

						cnt=fcnts[ine];
						maxcol=ine;
					}
				}
				maxcol&=0xf;
				if(formlst[ind].fcol!=maxcol){

					chngcnt++;
					formlst[ind].fcol=maxcol;
				}
				if(formlst[ind].ftyp==FTHF&&formlst[ind].xat&AT_FTHBLND){

					cnt=maxcol=0;
					for(ine=strt;ine<fin;ine++){

						if(fthcnts[ine]>cnt){

							cnt=fcnts[ine];
							maxcol=ine;
						}
					}
					maxcol&=0xf;
					if(formlst[ind].dhx.fth.fthcol!=maxcol){

						chngcnt++;
						formlst[ind].dhx.fth.fthcol=maxcol;
					}
				}
			}
			if(formlst[ind].etyp){

				cnt=maxcol=0;
				for(ine=strt;ine<fin;ine++){

					if(bcnts[ine]>cnt){

						cnt=bcnts[ine];
						maxcol=ine;
					}
				}
				maxcol&=0xf;
				if(formlst[ind].bcol!=maxcol){

					chngcnt++;
					formlst[ind].bcol=maxcol;
				}
			}
			if(formlst[ind].xat&(AT_WALK|AT_CWLK|AT_UND)){

				cnt=maxcol=0;
				for(ine=strt;ine<fin;ine++){

					if(ucnts[ine]>cnt){

						cnt=bcnts[ine];
						maxcol=ine;
					}
				}
				maxcol&=0xf;
				if(formlst[ind].ucol!=maxcol){

					chngcnt++;
					formlst[ind].ucol=maxcol;
				}
			}
			strt+=16;
			fin+=16;
		}
	}
	LoadString(hInst,IDS_NCOLCHG,buf,HBUFSIZ);
	sprintf(msgbuf,buf,chngcnt);
	shoMsg(msgbuf);
}

BOOL fxpnt(){

	double		len,dif;
	unsigned	ind;
	
	mvpnt.x=flt[nxstrt].x;
	mvpnt.y=flt[nxstrt].y;
	len=hypot(mvpnt.x-sPnt.x,mvpnt.y-sPnt.y);
	if(len>adjspac){

		for(ind=0;ind<10;ind++){

			len=hypot(mvpnt.x-sPnt.x,mvpnt.y-sPnt.y);
			dif=adjspac-len;
			mvpnt.x+=dif*cosins[clpstrt];
			mvpnt.y+=dif*sins[clpstrt];
			if(fabs(dif)<0.2)
				break;
		}
		return 1;
	}
	return 0;
}

void fxlit(){

	double		len;
	unsigned	cnt;
	DUBPNT		dif;

	if(fxpnt()){

		sPnt.x=mvpnt.x;
		sPnt.y=mvpnt.y;
		beancnt++;
		len=hypot(flt[nxstrt].x-sPnt.x,flt[nxstrt].y-sPnt.y);
		cnt=floor(len/adjspac);
		dif.x=adjspac*cosins[clpstrt];
		dif.y=adjspac*sins[clpstrt];
		sPnt.x+=dif.x*cnt;
		sPnt.y+=dif.y*cnt;
		beancnt+=cnt;
	}
}

void fxlin(){

	double		len;
	unsigned	cnt;
	unsigned	ind;
	DUBPNT		dif;

	if(fxpnt()){

		chpnts[xpnt].x=sPnt.x=mvpnt.x;
		chpnts[xpnt].y=sPnt.y=mvpnt.y;
		xpnt++;
		len=hypot(flt[nxstrt].x-sPnt.x,flt[nxstrt].y-sPnt.y);
		cnt=floor(len/adjspac);
		dif.x=adjspac*cosins[clpstrt];
		dif.y=adjspac*sins[clpstrt];
		for(ind=0;ind<cnt;ind++){

			sPnt.x+=dif.x;
			sPnt.y+=dif.y;
			chpnts[xpnt].x=sPnt.x;
			chpnts[xpnt].y=sPnt.y;
			xpnt++;
		}
	}
}

void fxlen(){

	double		ter;
	double		minter;
	double		minspac;
	double		hival;
	double		loval;
	double		spac2;
	unsigned	inicnt;
	unsigned	lupcnt;
	unsigned	ind,mind;
	double		len;

	chpnts=(FLPNT*)bseq;
	adjspac=0;
	for(ind=1;ind<(unsigned)sids;ind++){
	
		len=hypot(flt[ind].x-flt[0].x,flt[ind].y-flt[0].y);
		if(len>frmpnt->espac)
			goto fxlab;
		else{

			if(len>adjspac){

				adjspac=len;
				mind=ind;
			}
		}
	}
	chpnts[0].x=flt[0].x;
	chpnts[0].y=flt[0].y;
	chpnts[1].x=flt[1].x;
	chpnts[1].y=flt[1].y;
	xpnt=2;
	return;
fxlab:;
	adjspac=frmpnt->espac;
	spac2=adjspac/2;
	ter=1e9;
	lupcnt=inicnt=0;
	loval=0;
	hival=1;
	while(lupcnt<100&&(hival-loval)>TINY){

		beancnt=0;
		sPnt.x=flt[0].x;
		sPnt.y=flt[0].y;
		xpnt=1;
		chpnts[0].x=sPnt.x;
		chpnts[0].y=sPnt.y;
		for(clpstrt=0;clpstrt<(unsigned)sids-1;clpstrt++){

			nxstrt=clpstrt+1;
			fxlit();
		}
		if(frmpnt->typ!=LIN){

			nxstrt=0;
			fxlit();
		}
		else
			nxstrt=sids-1;
		if(!inicnt){

			inicnt=beancnt;
			loval=adjspac;
			minter=ter=(double)hypot(flt[nxstrt].x-sPnt.x,flt[nxstrt].y-sPnt.y);
			minspac=adjspac;
			ter/=inicnt;
			adjspac+=ter/2;
			hival=loval+ter;
		}
		else{

			ter=hypot(flt[nxstrt].x-sPnt.x,flt[nxstrt].y-sPnt.y);
			if(ter>spac2)
				ter=frmpnt->espac-ter;
			if(ter<minter){

				minter=ter;
				minspac=adjspac;
			}
			if(inicnt==beancnt)
				loval=adjspac;
			else{

				if(beancnt>inicnt)
					hival=adjspac;
				else
					loval=adjspac;
			}
			adjspac=loval+(hival-loval)/2;
		}
		lupcnt++;
	}
	sPnt.x=flt[0].x;
	sPnt.y=flt[0].y;
	opnt=1;
	adjspac=minspac;
	for(clpstrt=0;clpstrt<(unsigned)sids-1;clpstrt++){

		nxstrt=clpstrt+1;
		fxlin();
	}
	if(frmpnt->typ!=LIN){

		nxstrt=0;
		fxlin();
	}
	ter=hypot(flt[nxstrt].x-sPnt.x,flt[nxstrt].y-sPnt.y);
	if(ter<spac2)
		xpnt--;
	chpnts[xpnt].x=flt[nxstrt].x;
	chpnts[xpnt].y=flt[nxstrt].y;
	xpnt++;
/*	for(opnt=0;opnt<xpnt;opnt++){

		stchs[opnt].x=chpnts[opnt].x;
		stchs[opnt].y=chpnts[opnt].y;
		stchs[opnt++].at=0;
	}
	hed.stchs=opnt;
	coltab();
	setMap(RESTCH);*/
}

void duchfn(unsigned strt,unsigned fin){

	FLPNT		pnts[5];
	float		midx;
	float		midy;
	DUBPNT		dif;
	DUBPNT		difrat;
	DUBPNT		off;
	unsigned	ine;
	double		tang;

	dif.x=chpnts[fin].x-chpnts[strt].x;
	dif.y=chpnts[fin].y-chpnts[strt].y;
	difrat.x=dif.x*frmpnt->elen;
	difrat.y=dif.y*frmpnt->elen;
	pnts[0].x=chpnts[strt].x;
	pnts[0].y=chpnts[strt].y;
	pnts[4].x=chpnts[fin].x;
	pnts[4].y=chpnts[fin].y;
	tang=atan2(dif.y,dif.x)+PI/2;
	off.x=cos(tang)*frmpnt->esiz;
	off.y=sin(tang)*frmpnt->esiz;
	midx=chpnts[strt].x+difrat.x;
	midy=chpnts[strt].y+difrat.y;
	pnts[1].x=midx+off.x;
	pnts[1].y=midy+off.y;
	pnts[3].x=midx-off.x;
	pnts[3].y=midy-off.y;
	dif.x=chpnts[fin+1].x-chpnts[fin].x;
	dif.y=chpnts[fin+1].y-chpnts[fin].y;
	pnts[2].x=chpnts[fin].x+dif.x/4;
	pnts[2].y=chpnts[fin].y+dif.y/4;
	for(ine=0;ine<chncnt;ine++){
	
		oseq[seqpnt].x=pnts[chseq[ine]].x;
		oseq[seqpnt].y=pnts[chseq[ine]].y;
		seqpnt++;
	}
}

void duch(){

	unsigned ind,bak;

	div4=adjspac/4;
	seqpnt=0;
	if(xpnt>1){

		for(ind=0;ind<(unsigned)xpnt-2;ind++)
			duchfn(ind,ind+1);
		if(frmpnt->typ==LIN){

			duchfn(ind,ind+1);
			bak=8;
			if(chkMap(LINCHN))
				bak--;
			oseq[seqpnt-bak].x=chpnts[ind+1].x;
			oseq[seqpnt-bak].y=chpnts[ind+1].y;
			oseq[seqpnt].x=chpnts[ind+1].x;
			oseq[seqpnt++].y=chpnts[ind+1].y;
		}
		else{

			duchfn(ind,0);
			oseq[seqpnt].x=chpnts[xpnt-1].x;
			oseq[seqpnt].y=chpnts[xpnt-1].y;
			seqpnt++;
		}
	}
	else
		tabmsg(IDS_CHANSMAL);
}

void dufxlen(){

	unsigned ind;

	duangs();
	sins=(double*)angflt;
	cosins=(double*)tpoly;
	for(ind=0;ind<(unsigned)sids;ind++){

		sins[ind]=sin(angs[ind]);
		cosins[ind]=cos(angs[ind]);
	}
	sins[ind]=sin(abs(angs[0]-angs[ind]));
	fxlen();
}

void chnfn(){

	chncnt=10;
	if(chkMap(LINCHN))
		chncnt--;
	fvars(clofind);
	deleclp(clofind);
	dufxlen();
	dulast();
	seqpnt=0;
	duch();
}

void chan(){

	frmpnt->bcol=actcol;
	frmpnt->espac=ini.chspac;
	frmpnt->esiz=brdwid;
	frmpnt->elen=ini.chrat;
	frmpnt->emax=ini.maxsiz;
	frmpnt->emin=minsiz;
	if(chkMap(LINCHN))
		frmpnt->etyp=EGCHNL;
	else
		frmpnt->etyp=EGCHNH;
	refilfn();
}

void chain(){

	unsigned ind;

	if(filmsgs(FML_CHAIN))
		return;
	savdo();
	if(fselpnt){

		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			chan();
		}
		setMap(INIT);
		coltab();
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			fvars(clofind);
			chan();
			setMap(INIT);
			coltab();
			ritot(hed.stchs);
			setMap(RESTCH);
		}
	}
}

BOOL cisin(float pntx,float pnty){

	unsigned	ind,acnt;
	unsigned	nvrt;
	DUBPNT		ipnt;
	FLRCT*		trct;

	trct=&frmpnt->rct;
	if(pntx>=trct->right)
		return 0;
	if(pntx<=trct->left)
		return 0;
	if(pnty>=trct->top)
		return 0;
	if(pnty<=trct->bottom)
		return 0;
	acnt=0;
	for(ind=0;ind<sids;ind++)
	{
		nvrt=nxt(ind);
		if(projv(pntx,flt[ind],flt[nvrt],&ipnt))
		{
			if(ipnt.y>=pnty)
			{
				if(flt[ind].x!=pntx&&flt[nvrt].x!=pntx)
					acnt++;
				else
				{
					if(flt[ind].x<flt[nvrt].x)
					{
						if(flt[nvrt].x!=pntx)
							acnt++;
					}
					else
					{
						if(flt[ind].x!=pntx)
							acnt++;
					}
				}
			}
		}
	}
	return acnt&1;
}

void crop(){

	unsigned ind,ine;

	frm1pnt();
	if(chkMap(FORMSEL)){

		savdo();
		fvars(clofind);
		ine=0;
		vstrt=0;
		vfin=sids;
		for(ind=0;ind<hed.stchs;ind++){

			if(cisin(stchs[ind].x,stchs[ind].y)){

				stchs[ine].x=stchs[ind].x;
				stchs[ine].y=stchs[ind].y;
				stchs[ine++].at=stchs[ind].at;
			}
		}
		hed.stchs=ine;
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_FRM1MSG,IDS_CROP);
}

void xclpfn(unsigned strt,unsigned fin){

	unsigned	ind;
	DUBPNT		dif;
	double		len;
	double		rat;
	FLPNT*		tflt;

	tflt=(FLPNT*)&stchs[MAXPCS];
	dif.x=chpnts[fin].x-chpnts[strt].x;
	dif.y=chpnts[fin].y-chpnts[strt].y;
	len=hypot(dif.x,dif.y);
	rat=len/clpsiz.cx;
	ang=atan2(dif.y,dif.x);
	for(ind=0;ind<clplen;ind++){

		tflt[ind].x=rclps[ind].x*rat;
		tflt[ind].y=rclps[ind].y;
		rotflt(&tflt[ind]);
		oseq[seqpnt].x=chpnts[strt].x+tflt[ind].x;
		oseq[seqpnt++].y=chpnts[strt].y+tflt[ind].y;
	}
}

void duxclp(){

	unsigned ind;

	duangs();
	dufxlen();
	clpxadj();
	seqpnt=0;
	rotcntr.x=rotcntr.y=0;
	for(ind=1;ind<xpnt;ind++)
		xclpfn(ind-1,ind);
	if(frmpnt->typ!=LIN){

		oseq[seqpnt].x=chpnts[0].x;
		oseq[seqpnt++].y=chpnts[0].y;
	}
}

void dulast(){

	unsigned	ind,ine,mind;
	double		minlen;
	double		len;

	rclps=(FLPNT*)&chpnts[xpnt];
	if(lastch()){

		minlen=1e99;
		mind=0;
		for(ind=0;ind<xpnt;ind++){

			len=hypot(lastpnt.x-chpnts[ind].x,lastpnt.y-chpnts[ind].y);
			if(len<minlen){

				minlen=len;
				mind=ind;
			}
		}
		if(mind){

			ine=0;
			for(ind=mind;ind<xpnt-1;ind++){

				rclps[ine].x=chpnts[ind].x;
				rclps[ine++].y=chpnts[ind].y;
			}
			for(ind=0;ind<=mind;ind++){

				rclps[ine].x=chpnts[ind].x;
				rclps[ine++].y=chpnts[ind].y;
			}
			MoveMemory(chpnts,rclps,sizeof(FLPNT)*ine);
		}
	}
}

void clpxadj(){

	unsigned	ind;
	double		pivot;

	dulast();
	if(frmpnt->typ==LIN){

		pivot=clpsiz.cy/2;
		for(ind=0;ind<clplen;ind++){

			rclps[ind].x=clpnu[ind].x;
			rclps[ind].y=-clpnu[ind].y+pivot;
		}
	}
	else{

		for(ind=0;ind<clplen;ind++){

			rclps[ind].x=clpnu[ind].x;
			rclps[ind].y=-clpnu[ind].y;
		}
	}
}

void fsclpx(){

	unsigned	ind;

	deleclp(clofind);
	frmpnt->etyp=EGCLPX;
	frmpnt->nclp=clplen;
	frmpnt->clp=nueclp(clofind,clplen);
	frmpnt->esiz=clpsiz.cy;
	frmpnt->espac=clpsiz.cx;
	frmpnt->bcol=actcol;
	bsizpar();
	for(ind=0;ind<clplen;ind++){

		frmpnt->clp[ind].x=clpnu[ind].x;
		frmpnt->clp[ind].y=clpnu[ind].y;
	}
	rotcntr.x=rotcntr.y=0;
	duxclp();
	refilfn();
}

void filclpx(){

	unsigned	ind;

	if(filmsgs(FML_CLP))
		return;
	if(OpenClipboard(hWnd)){

		fvars(clofind);
		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
 		if(hClpMem){

			savdo();
			redclp();
			CloseClipboard();
			if(clpsiz.cx>CLPMIN){

				if(fselpnt){

					for(ind=0;ind<fselpnt;ind++){

						clofind=selist[ind];
						fvars(clofind);
						fsclpx();
					}
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
				else{

					if(chkMap(FORMSEL)){

						fsclpx();
						setMap(INIT);
						coltab();
						setMap(RESTCH);
					}
				}
			}
			else
				tabmsg(IDS_CLP);
		}
		else{

			shoMsg("no clipboard data");
			CloseClipboard();
		}
	}
}

BOOL CALLBACK wavprc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam){

	TCHAR	buf[HBUFSIZ];

	switch(umsg){

	case WM_INITDIALOG:

		SendMessage(hwndlg,WM_SETFOCUS,0,0);
reinit:;
		sprintf(buf,"%d",ini.wavpnts);
		SetWindowText(GetDlgItem(hwndlg,IDC_WAVPNTS),buf);
		sprintf(buf,"%d",ini.wavstrt);
		SetWindowText(GetDlgItem(hwndlg,IDC_WAVSTRT),buf);
		sprintf(buf,"%d",ini.wavend);
		SetWindowText(GetDlgItem(hwndlg,IDC_WAVEND),buf);
		sprintf(buf,"%d",ini.wavs);
		SetWindowText(GetDlgItem(hwndlg,IDC_WAVS),buf);
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam)){

		case IDCANCEL:

			EndDialog(hwndlg,0); 
			return TRUE;

		case IDOK:

			GetWindowText(GetDlgItem(hwndlg,IDC_WAVPNTS),buf,HBUFSIZ);
			ini.wavpnts=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_WAVSTRT),buf,HBUFSIZ);
			ini.wavstrt=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_WAVEND),buf,HBUFSIZ);
			ini.wavend=atoi(buf);
			GetWindowText(GetDlgItem(hwndlg,IDC_WAVS),buf,HBUFSIZ);
			ini.wavs=atoi(buf);
			if(ini.wavpnts>100)
				ini.wavpnts=100;
			if(ini.wavpnts<3)
				ini.wavpnts=3;
			if(ini.wavstrt==ini.wavend)
				ini.wavend+=(ini.wavpnts>>2);
			ini.wavstrt%=ini.wavpnts;
			ini.wavend%=ini.wavpnts;
			EndDialog(hwndlg,1);
			break;

		case IDC_DEFWAV:

			ini.wavpnts=IWAVPNTS;
			ini.wavstrt=IWAVSTRT;
			ini.wavend=IWAVEND;
			ini.wavs=IWAVS;
			goto reinit;
		}
	}
	return 0;
}

void wavfrm(){

	unsigned	ind,ine,inf;
	unsigned	end;
	unsigned	cnt;
	FLPNT*		tflt;
	FLPNT		pos;
	double		hrat;
	double		vrat;
	FLPNT		siz;

	unmsg();
	if(DialogBox(hInst,MAKEINTRESOURCE(IDD_WAV),hWnd,(DLGPROC)wavprc)){

		ind=fltad;
		end=ini.wavend+1;
		durpoli(ini.wavpnts);
		mdufrm();
		fltad=ind;
		tflt=(FLPNT*)&bseq;
		ine=0;
		ind=ini.wavstrt;
		while(ind!=ini.wavend){

			inf=(ind+1)%ini.wavpnts;
			tflt[ine].x=-flt[inf].x+flt[ind].x;
			tflt[ine].y=-flt[inf].y+flt[ind].y;
			ine++;
			ind=inf;
		}
		cnt=ine;
		ine=0;
		pos.x=pos.y=0;
		for(inf=0;inf<ini.wavs;inf++){

			if(inf&1){

				for(ind=0;ind<cnt;ind++){

					flt[ine].x=pos.x;
					flt[ine].y=pos.y;
					ine++;
					pos.x+=tflt[ind].x;
					pos.y+=tflt[ind].y;
				}
			}
			else{

				for(ind=cnt-1;ind<cnt;ind--){

					flt[ine].x=pos.x;
					flt[ine].y=pos.y;
					ine++;
					pos.x+=tflt[ind].x;
					pos.y+=tflt[ind].y;
				}
			}
		}
		flt[ine].x=pos.x;
		flt[ine].y=pos.y;
		ine++;
		ang=-atan2(flt[ine-1].y-flt[0].y,flt[ine-1].x-flt[0].x);
		for(ind=0;ind<ine;ind++)
			rotflt(&flt[ind]);
		frmpnt->typ=LIN;
		frmpnt->sids=ine;
		fltad+=ine;
		frmout(formpnt);
		rstMap(FORMSEL);
		siz.x=frmpnt->rct.right-frmpnt->rct.left;
		siz.y=frmpnt->rct.top-frmpnt->rct.bottom;
		hrat=zum0.x/4/siz.x;
		if(hrat>1)
			hrat=1;
		vrat=zum0.y/4/siz.y;
		if(vrat<hrat)
			hrat=vrat;
		if(hrat<1){

			for(ind=0;ind<ine;ind++){

				flt[ind].x=(flt[ind].x-flt[0].x)*hrat+flt[0].x;
				flt[ind].y=(flt[ind].y-flt[0].y)*hrat+flt[0].y;
			}
		}
		frmout(formpnt);
		for(ind=0;ind<ine;ind++){

			flt[ind].x-=frmpnt->rct.left;
			flt[ind].y-=frmpnt->rct.bottom;
		}
		fmovdif.x=fmovdif.y=0;
		nuflen=ine+1;
		setmfrm();
		mdufrm();
	}
}

void srtfrm(){

	unsigned	ind,ine,inf,tot,sav;
	unsigned	hst[MAXFORMS];
	SHRTPNT*	hstch;

	if(hed.stchs){

		savdo();
		FillMemory(hst,sizeof(unsigned)*MAXFORMS,0);
		for(ind=0;ind<hed.stchs;ind++)
			hst[(stchs[ind].at&FRMSK)>>FRMSHFT]++;
		tot=0;
		for(ind=0;ind<MAXFORMS;ind++){

			sav=hst[ind];
			hst[ind]=tot;
			tot+=sav;
		}
		hstch=&stchs[MAXSEQ];
		for(ind=0;ind<hed.stchs;ind++){

			ine=(stchs[ind].at&FRMSK)>>FRMSHFT;
			inf=hst[ine]++;
			hstch[inf].x=stchs[ind].x;
			hstch[inf].y=stchs[ind].y;
			hstch[inf].at=stchs[ind].at;
		}
		MoveMemory(stchs,hstch,sizeof(SHRTPNT)*hed.stchs);
		coltab();
		setMap(RESTCH);
	}
}

#pragma warning(default:4244)
