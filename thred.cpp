#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <byteswap.h>
#include <fenv.h>
#include "tchar.h"
#include "lang.h"
#include "resource.h"
#include "thred.h"
#include "bits.h"


#define ds drawstructthingie

void clrhbut(unsigned strt);
void delsfrms(unsigned cod);
void renam();
BOOL chkchksum();
void fthrfn();
void dufdef();
void delet();
void frmx(POINT cpnt,HDC dc);
void setpsel();
void unlin();
void redraw(HWND dWnd);
void duIns();
void cros(unsigned ind);
void shft(FLPNT shPnt);
void movStch();
void nuAct(unsigned ind);
void movbox();
void xlin();
unsigned pt2colInd(unsigned pInd);
void xlin1();
void delstchm();
void drwLin(unsigned ind,unsigned len,HPEN hPen);
void zRctAdj();
void lenCalc();
void ritnum(unsigned cod,unsigned num);
void ritot(unsigned num);
void endpnt();
void rstAll();
void shoMsg(TCHAR* str);
void delsmal(unsigned ind,unsigned fin);
void patdun();
void selRct(FLRCT* srct);
void thrsav();
void okcan();
void rstdu();
void unmsg();
void frmdel();
void unsid();
void unbsho();
void rngadj();
void rotfn();
void dusel(HDC dc);
void rSelbox();
void unsel();
void rotpix(POINT rpnt,POINT* tpnt);
BOOL cmpstch(unsigned ind0,unsigned ind1);
void duselrng();
void unthum();
void insfil();
void chkhup();
void stch2map(RECT* bitrct);
void ilin();
void clRmap(unsigned len);
void rotfns();
void nuslst(unsigned find);
void dstcurs();
void mvstch(unsigned dst,unsigned src);
void save();
void mvstchs(unsigned dst,unsigned src,unsigned cnt);
void fndknt();
COLORREF fswap(COLORREF tcol);
void dubuf();
unsigned bufref();
void hupfn();
unsigned setRmp(unsigned pbit);
void untrace();
void trcols(COLORREF col);
void dutrnum0(unsigned num);
void dutrnum1();
void trinit();
void trdif();
void blak();
void trcsel();
void fnamtabs();

extern void txsnap();
extern void dazdef();
extern void txof();
extern void rstxt();
extern void frmchkx();
extern unsigned clofinx;
extern void prbug();
extern void repar();
extern void setfchk();
extern void chgchk(int cod);
extern void lodchk();
extern void chgwrn();
extern void savtxt();
extern void redtx();
extern void txdun();
extern void deltx();
extern void clrstch();
extern void setclpspac();
extern void setshft();
extern void mvshft();
extern void dushft();
extern void dufind(float idnt);
extern void setfind();
extern void nudsiz();
extern void rtrclp();
extern void redtx();
extern TXPNT* adtx(int cnt);
extern BOOL istx(unsigned find);
extern void dutxtfil();
extern TXPNT txpnts[MAXSEQ];
extern int txad;
extern TCHAR hlpbuf[HBUFSIZ];
extern TXTSCR tscr;
extern void txtkey(unsigned cod);
extern int ptxhst;
extern TXHST thsts[16];
extern void txtlin();
extern void txtclp();
extern void rstxt();
extern void txtform();
extern int cloxcnt;
extern void txtrup();
extern void txtrmov();
extern void txtrbut();
extern void txtlbut();
extern void duauxnam();
extern void hsizmsg();
extern void drwtxtr();
extern void setfilstrt();
extern void setfilend();
extern void setfhi();
extern void dufhi(float len);
extern void setfwid();
extern void dufwid(float len);
extern void setfmin();
extern void setfmax();
extern void setbmin();
extern void setbmax();
extern void dufmin(float len);
extern void dufmax(float len);
extern void dubmin(float len);
extern void dubmax(float len);
extern void dubspac(float len);
extern void setbspac();
extern void setbcol();
extern void setfcol();
extern void setblen();
extern void dublen(float len);
extern void dufcol(unsigned col);
extern void dubcol(unsigned col);
extern void dundcol(unsigned col);
extern void setucol();
extern void setfang();
extern void dufspac(float spac);
extern void setfspac();
extern void setflen();
extern void duflen(float len);
extern void dufang(float ang);
extern void dufxang(float ang);
extern void sfuang();
extern void duspac(float spac);
extern void uspac();
extern void dusulen(float len);
extern void undlen();
extern void setund();
extern void setwlk();
extern void setcwlk();
extern void notund();
extern void notwlk();
extern void notcwlk();
#ifdef _DEBUG
extern void dmpat();
#endif
extern void ducod();
extern FLPNT iseq[MAXSEQ];
extern BOOL chkrypt(unsigned arg0,unsigned arg1,unsigned arg2,unsigned arg3);
extern void selalfrm();
extern void setuang();
extern void setuspac();
extern void setulen();
extern void setwlkind();
extern void dubit(unsigned bit);
extern void abstim();
extern char* dgbuf;
extern void pes2crd();
extern void fritfil();
extern void tst();
extern void fethrf();
extern void nufthcol(unsigned col);
extern void fethr();
extern void fltspac(FLPNT* strt,unsigned cnt);
extern unsigned fltind(FLPNT* pnt);
extern unsigned pdir(unsigned ind);
extern void unpsel();
extern void	sRct2px(FLRCT strct,RECT* pxrct);
extern void dupsel(HDC dc);
extern void fsizpar();
extern void bsizpar();
extern void form();
extern void duform(unsigned ind);
extern void drwfrm();
extern void dufrm();
extern void mdufrm();
extern void setfrm();
extern void unfrm();
extern void munfrm();
extern unsigned closfrm();
extern void frmovlin();
extern void setfpnt();
extern void ritfrct(unsigned ind,HDC dc);
extern void delfrms();
extern void filvrt();
extern void filhor();
extern void frmcpy(FRMHED* dst,FRMHED* src);
extern void filangl();
extern void satpnt0();
extern unsigned chkfrm();
extern void setmfrm();
extern void rstfrm();
extern void clrfills();
extern void drwsat();
extern void satpnt1();
extern void satfix();
extern void filsat();
extern void satsel();
extern void drwcon();
extern void satknkt();
extern void insat();
extern void delspnt();
extern void unfil();
extern void frmlin(FLPNT* scr,unsigned sidz);
extern void rats();
extern void satzum();
extern void frmpnts();
extern void frm0();
extern void infrm();
extern void duinsf();
extern void uninsf();
extern void setins();
extern void refil();
extern void frmout(unsigned ind);
extern void delcon(unsigned cpnt);
extern void satadj();
extern void fvars(unsigned ind);
extern void	bord();
extern void fclp();
extern void ispcdclp();
extern void	satbrd();
extern void	apliq();
extern void setap();
extern void refrm();
extern void strtchbox();
extern void unstrtch();
extern void setstrtch();
extern void setexpand();
extern void nufilcol(unsigned col);
extern void maxtsiz(TCHAR* str,POINT* pt);
extern void nubrdcol(unsigned col);
extern void nulapcol(unsigned col);
extern void sidwnd(HWND wnd);
extern void delmfil(unsigned col);
extern unsigned find1st();
extern void dubold();
extern void px2stchf(POINT pxpnt,FLPNT* stpnt);
extern void prfmsg();
extern void prfsid(HWND wnd);
extern void durpoli(unsigned sidz);
extern void fliph();
extern void flipv();
extern void savdisc();
extern void tomsg();
extern void	getfinfo(unsigned ind);
extern void prpbrd(double spac);
extern void tglfrm();
extern void frmon();
extern void frmclr(FRMHED* dst);
extern void flpord();
extern void rinfrm();
extern void clpfil();
extern void snap();
extern void fsort();
extern void dustar(unsigned nsids,double len);
extern void rotcmd();
extern void rotagain();
extern void rotdup();
extern void duprot();
extern void cpylayr(unsigned play);
extern void movlayr(unsigned play);
extern void duspir(unsigned nsids);
extern void sfCor2px(FLPNT stpnt,POINT* pxpnt);
extern void frmsqr(unsigned ind);
extern float midl(float hi,float lo);
extern void oclp(FLPNT* clp,unsigned nclp);
extern void join();
extern void refilal();
extern void nufsel();
extern void frmadj(unsigned find);
extern void ratsr();
extern void frmsadj();
extern void pxrct2stch(RECT pxr,FLRCT* str);
extern void fselrct(unsigned fpnt);
extern unsigned short nxt(unsigned short ind);
extern unsigned short prv(unsigned ind);
extern void setr(unsigned pbit);
extern BOOL chkr(unsigned pbit);
extern void selal();
extern void selfil(unsigned typ);
extern void	selalfil();
extern BOOL notfstch(unsigned at);
extern BOOL frmrng(unsigned fpnt,RANG* rng);
extern void refilfn();
extern void bhol();
extern void deleclp(unsigned fpnt);
extern void delmclp(unsigned fpnt);
extern void delsac(unsigned fpnt);
extern void delflt(unsigned fpnt);
extern void bholbrd();
extern void fcntr();
extern void savblen(float len);
extern void boxsel();
extern void picot();
extern void blunt();
extern void clpic(unsigned short strtlin);
extern unsigned getlast();
extern void ritbrd();
extern void savplen(float len);
extern void contfil();
extern void chkcont();
extern void grpmsg();
extern void grpmsg1();
extern void help();
extern void ribon();
extern void dubig();
extern unsigned psg();
extern void redup();
extern void bakdup();
extern void bakagain();
extern void shrnk();
extern void setrang();
extern void frmnum();
extern void frmnumfn(unsigned nunum);
extern void srtbyfrm();
extern void cntrx();
extern void centir();
extern BOOL notsel();
extern void dubean();
extern void debean();
extern void spltfrm();
extern void stchs2frm();
extern void stCor2px(SHRTPNT stpnt,POINT* pxpnt);
extern void	vrtclp();
extern void horclp();
extern void angclp();
extern void dubfil();
extern void horclpfn();
extern void horsclp();
extern void vrtsclp();
extern void angsclp();
extern void dubsfil();
extern void makspac(unsigned strt,unsigned cnt);
extern void	duhart(unsigned nsids);
extern void dulens(unsigned nsids);
extern void sethup();
extern void sizstch(FLRCT* rct);
extern void col2frm();
extern void rstr(unsigned pbit);
extern unsigned projh(double pnty,FLPNT pnt0,FLPNT pnt1,DUBPNT* ipnt);
extern void stchrct2px(FLRCT srct,RECT* prct);
extern void chan();
extern void crop();
extern void dueg(unsigned nsids);
extern void selsqr(POINT cpnt,HDC dc);
extern void shortr();
extern void msgstr(unsigned cod);
extern void shoseln(unsigned cod0,unsigned cod1);
extern void	tabmsg(unsigned cod);
extern void keydays(unsigned daz);
extern void lodstr();
extern TCHAR* stab[STR_LEN];
extern void butxt(unsigned ind,TCHAR* str);
extern void riter();
extern void crmsg(TCHAR* nam);
extern void filnopn(unsigned cod,TCHAR* nam);
extern void bfilmsg();
extern void tsizmsg(TCHAR* sizstr,double siz);
extern void setear();
extern void maxwid(unsigned strt,unsigned fin);
extern void	chain();
extern void duzig(unsigned nsids);
extern void dusat();
extern void filclpx();
extern void duxclp();
extern void fsclpx();
extern void wavfrm();
extern void srtfrm();
extern void rct2sel(RECT rct,POINT* lin);

#if PESACT

extern BOOL setrc(unsigned pbit);
#endif

extern POINT			pselin[9];
extern FLPNT			lastpnt;
extern unsigned			xpnt;
extern unsigned			formpnt;
extern unsigned			frmstrt;
extern unsigned			frmend;
extern unsigned			delpnt;
extern FRMHED			formlst[MAXFORMS];
extern POINT			flin[MAXFRMLINS];
extern unsigned			clofine;
extern unsigned			clofind;
extern unsigned			nuflen;
extern unsigned short	wpar;
extern double			stspace;
extern double			angl;
extern double			brdwid;
extern unsigned			cntrl;
extern double			xpct;
extern unsigned short	sids;
extern FLPNT			lolft;
extern HWND				thDat[LASTLIN];
extern FLPNT*			flt;
extern SATCON*			sac;
extern unsigned			satpt;
extern POINT			mvlin[3];
extern double			snplen;
extern double			starat;
extern double			spirwrap;
extern POINT			rctlin[10];
extern FLPNT			fmovdif;
extern unsigned			fselpnt;
extern unsigned			baksel;
extern POINT			biglin[9];
extern RECT				bigrct;
extern FLPNT			fmovdif;
extern unsigned short	selist[MAXFORMS];
extern double			hfrat;
extern double			vfrat;
extern BSEQPNT			bseq[BSEQLEN];
extern FLPNT			flts[MAXFRMPNTS];		//form points
extern unsigned			fltad;					//next index to append form points
extern FLPNT			clps[MAXCLPNTS];		//main clipboard fill points for forms
extern unsigned			clpad;					//next index to append main clipboard points
extern SATCON			satks[MAXSAC];			//satin form connects
extern unsigned			satkad;					//next index to append satin connect points
extern float			bfclen;
extern HWND				thTxt[LASTLIN];
extern float			picspac;
extern FLPNT			oseq[OSEQLEN];
extern HWND				hindx;
extern HWND				hnxt;
extern HWND				hsrch;
extern HWND				hlptxt;
extern TCHAR*			cpyrit;
extern unsigned			psgacc;
extern TCHAR*			laytxt[];
extern FRMHED*			finspnt;
extern unsigned			fgpnt0;
extern unsigned			opnt;
extern TCHAR*			shrtmsg;
extern FLRCT			rctal;
extern long				prfwid;
extern HWND				hMsg;

unsigned char			cryptkey[4096];

//select box
#define				NERCNT		4		//number of entries in the near array

unsigned short chk1loc[]=
{
	3632,
	3168,
	393,
	2246,
	802,
	1817,
	3175,
	2254
};

//main variables
HINSTANCE			hInst;			//main instance handle
HWND				hWnd;			//main window handle
MSG					msg;			//main message loop message
RECT				mRct;			//main window size
RECT				bRct;			//color bar rectangle
RECT				bcRct;			//color bar client rectangle
RECT				minLenRct;		//minimum length rectangle
RECT				maxLenRct;		//maximum length rectangle
unsigned			minpnt;			//pointer to the smallest stitch in the selected range
unsigned			maxpnt;			//pointer to the largest stitch in the selected range
unsigned			srchpnt;		//pointer to the current selection for length search
HDC					mdc;			//main device context handle
HDC					sdc;			//stitch window memory device context
HDC					rsdc;			//stitch window device context
HDC					bitdc;			//bitmap device context
HDC					bdc;			//color bar device context
HBITMAP				sbmp;			//bitmap for the memory stitch device context
POINT				morg;			//offset origin of the main window
POINT				stOrg;			//offset origin of the stitch window
SIZE				txSiz;			//used for measuring sizes of text items
SIZE				scrPix;			//screen size in pixels
SIZE				scrSiz;			//screen size in millimeters
DUBRCT				zRct;			//zoom rectangle
RECT				sRct;			//stitch window size,absolute
RECT				scRct;			//stitch window size,client
DRAWITEMSTRUCT		*ds;			//for owner-draw windows
POINT				pstch;			//stitch coordinates
double				zumFct=1;		//zoom factor
POINT				zum0;			//size of the unzoomed stitch window
POINT				pPnt;			//converted from stich to pixel
POINT				pxNer[NERCNT];	//selected points
POINT				boxPix;			//single select box point
double				cloSum;			//distance of closest point to a mouse click
unsigned			cloInd;			//index of closest point
unsigned			selclo;			//copy of index of closest point
unsigned			grpInd;			//last point selected in group
unsigned			gpnt0;			//lower end of selected stitches
unsigned			gpnt1;			//higher end of selected stitches
unsigned			opnt0;			//lower end of previous selection
unsigned			opnt1;			//higher end of previous selection
TCHAR				numbuf[5];		//stitch number entered by user
TCHAR				sidbuf[11];		//side window number for entering form data sheet numbers
unsigned			numpnt=0;		//pointer to the next number to be entered
unsigned			stchdigs;		//number of decimal digits in the number of stitches
POINT*				plin;			//for drawing lines on the screen
unsigned			drwpnt;			//line index for display routine
double				stchAspct;		//aspect ratio of the stitch window
double				minsiz=MINSIZ*PFAFGRAN;	//minimum stitch size
double				usesiz=USESIZ*PFAFGRAN;	//user selected stitch size
double				smalsiz=SMALSIZ*PFAFGRAN;//user can remove stitches smaller than this
unsigned			rmap[RMAPSIZ];	//bitmap to tell when stitches have been marked
TCHAR*				pcdClip="PMust_Format";
TCHAR*				thredclp="threditor";
CLPSTCH*			clpdat;			//for pcs clipboard data
FRMCLP*				frmclpdat;		//for thred form clipboard data
FRMSCLP*			frmsclpdat;		//multiple form clipboard header
FPCLP*				fpclpdat;		//form points clipboard header
void*				clpvoid;		//for memory allocation for clipboard data
void*				tclpvoid;		//for memory allocation for thred format clipboard data
FLSIZ				clpsiz;			//clipboard rectangle size
FLRCT				clprct;			//clipboard rectangle
unsigned			clplen;			//number of stitchs extracted from clipboard
POINT				clporg;			//origin of clipboard box in stitch coordinates
HGLOBAL				hClpMem;		//handle to the clipboard memory
SIZE				selsiz;			//size of the select box
POINT				selof;			//offset of the spot the user selected from the lower left of the select box
DUBPNT				zrat;			//zoom ratio used to draw stitch window
double				ang;			//rotation angle
double				hang;			//angle of the rotation handle
double				savang;			//saved rotation angle
FLRCT				rotrct;			//rotation rectangle
DUBPNT				bsrat;			//bitmap to stitch hoop ratios
DUBPNT				birat;			//stitch hoop to bitmap ratios
RECT				bsrct;			//bitmap sorce rectangle for zoomed view
RECT				bdrct;			//stitch window destination rectangle for zooomed view
unsigned			bwid;			//bitmap width
unsigned			bhi;			//bitmap height
DUBPNT				zumend;			//bitmap end points in stitch points
POINT				scend;			//stitch window end points
POINT				dstend;			//ends of the destination bitmap for bitmap drawing
unsigned*			bpnt;			//monochrome bitmap data
unsigned			bitCol=BITCOL;	//bitmap color
TCHAR				msgbuf[MSGSIZ];	//for user messages
unsigned			msgpnt;			//pointer to the message buffer
double				shopnts=SHOPNTS;//show stitch grid below this zoom level
double				tsiz30=TSIZ30;	//#30 thread size
double				tsiz40=TSIZ40;	//#40 thread size
double				tsiz60=TSIZ60;	//#40 thread size
unsigned			runpnt;			//point for animating stitchout
unsigned			runum;			//number of stitches to draw in each frame
int					delay;			//time delay for stitchout
double				stchboxs=STCHBOX;//threshold for drawing stitch boxes
//WARNING the size of the following array must be changed if the maximum movie speed is changed
POINT				movilin[100];	//line for movie stitch draw
RECT				msgRct;			//rectangle containing the text message
void*				bakdat[16];		//backup data
unsigned			dupnt0=0;		//undo storage pointer
unsigned			dupnt1=0;		//undo retrieval pointers
unsigned			apcol=15;		//underlay color
unsigned			lastcod=0xffff;	//last key code
unsigned			sidtyp=0;		//data type for form data form numerical entry
DUBPNT				mrkpnt;			//stitch coordinates of the zoom mark
unsigned			prfind=0;		//index to the active preference window
unsigned			fmenid[]={FM_ONAM0,FM_ONAM1,FM_ONAM2,FM_ONAM3};	//recently used file menu ID's
TCHAR				vernams[OLDVER][MAX_PATH];	//temporary storage for old file version names
unsigned			baknum;			//points to old version to be read
unsigned			actl=0;			//active layer
unsigned			laycod;			//active layer code
long				funscnt;		//number of forms the on the clipboard
unsigned*			finds;			//array of form indices for delete multiple forms
POINT				stchar[3];		//arrow for selected stitch
RANG				selfrng;		//first and last stitch for min/max stitch select
DUBPNT				bzrat;			//bitmap to hoop ratio
unsigned			menhi;			//menu height
unsigned			fnamord[50];	//file name order table
unsigned char		fnamcod[128];	//file name encoding
unsigned char		frencod[256];	//file name decode
TCHAR				fildes[50];		//file designer name in clear
HWND				fwnd;			//first window not destroyed for exiting enumerate loop
RANG				selrang;		//range of selected forms
unsigned			bakfrm;			//saved form index
unsigned char		amsk[128];			//cursor and mask
double				zumflor;		//minimum allowed zoom value
FLRCT				chkhuprct;		//for checking the hoop size
unsigned			daz;			//days untill a merchant key expires
BALSTCH*			pbal;			//balarad stitch pointer
FLPNT				balof;			//balarad offset
unsigned			clpmap=MCLPF|MVCLPF|MHCLPF|MANGCLPF; //for checking if a fill is a clipboard fill
unsigned			bakstch=0;		//stitch count for last message
SHRTPNT*			stchsr;			//rotated stitches for rotate and save
unsigned			sidloc;			//side message window location
POINT				sidsiz;			//size of the side message window
TCHAR**				sidstr;			//string array displayed in sidmsg
TCHAR*				per;			//pointer to the error string
unsigned			loksel;			//selection for lock list box
unsigned			unloksel;		//eslection for unlock list box
RANG				selrng;			//select range for locking
TCHAR				colnam[MAX_PATH];//.thw file name
TCHAR				rgbnam[MAX_PATH];//.rgb file name
DUBPNT				rcel;			//size of an rmap cell for drawing stitch boxes
unsigned			wcol;			//color being dragged
unsigned			prfsiz;			//size of the text part of the preference window
RNGC				pselrng;		//selected form points
FLRCT				pselrct;		//rectangle enclosing selected form points
RECT				pxselrct;		//display form point select rectangle
POINT*				fplin;			//form point clipboard paste into form line

#if	PESACT
unsigned char*		pescols;		//pes colors
TCHAR*				peschr;			//pes card data buffer
FLPNT				sof;			//offset fro writing pes files
PESTCH*				pestchs;		//pes stitch buffer
unsigned char		pescolrs[16];	//pes equivalent colors
unsigned char*		pestch;			//pes stitches
unsigned			pcolind;		//pes color index
#endif

POINT				pselfin;		//point to draw a the end cross for form select points
unsigned			fsizeof;		//size of form header divided by 4
HDC					tracedc;		//trace device context
HBITMAP				tracebit;		//trace bitmap
unsigned			sref;			//brightness of reference pixel
unsigned*			tracbits;		//trace bitmap data
POINT				tracpnt;		//current point being traced
unsigned			tracind;		//index of the next point in the traced line
unsigned			trmapsiz;		//size of the trace bitmap in double words
unsigned*			tracmap;		//bitmap of selected trace pixels
unsigned*			edgmap;			//detected edges of trace areas
long				tracmov[]={1,1,0,0,-1,-1,0,0};	//for moving the trace bits
TRCPNT*				trclin;			//collection of traced points
TRCPNT*				diflin;			//differenced collection of traced points
long				tracof;			//trace bitmap offset for landscap
unsigned			trcdir;			//trace direction
unsigned			inidir;			//initial trace direction
TRCPNT				trdif0;			//difference from one trace pixel to the next
TRCPNT				trdif1;			//difference from one trace pixel to the next
COLORREF			uref;			//color of the up reference pixel
COLORREF			dref;			//color of the down reference pixel
COLORREF			curef;			//complement color of the up reference pixel
COLORREF			cdref;			//complement color of the down reference pixel
POINT				trcmpnt;		//message point for trace parsing
RECT				hirct;			//high trace mask rectangle
RECT				midrct;			//midle trace mask rectangle
RECT				lorct;			//low trace mask rectangle
unsigned			hicols[3];		//separated upper reference colors
unsigned			pxcols[3];		//separated pixel reference colors
unsigned			locols[3];		//separated lower reference colors
unsigned			trbits[]={TRCRED,TRCGRN,TRCBLU};	//trace bits
unsigned			trmsks[]={REDMSK,GRNMSK,BLUMSK};	//trace masks
unsigned			trgb[]={BLUCOL,GRNCOL,REDCOL};		//trace colors
unsigned			tradj[9];		//seperated colors for ajacent pixels
unsigned*			difmap;			//difference bitmap
TCHAR				trbuf[4];		//for composing color numbers
TCHAR				trinbuf[4];		//for user input color numbers
unsigned			colm;			//trace color column
POINT				bitpnt;			//a point on the bitmap

//cursors
HCURSOR 			hAr;			//arrow
HCURSOR 			hCros;			//cross
HCURSOR 			hfrm;			//form
HCURSOR 			hdlin;			//dlin
HCURSOR				hnedu;			//upright needle
HCURSOR				hnedlu;			//left up needle 
HCURSOR				hnedld;			//left down needle 
HCURSOR				hnedru;			//right up needle 
HCURSOR				hnedrd;			//right down needle 
CURS				curs;			//cursor mask structure

HPEN				lPen;			//line pen for stitch move lines			
HPEN				bPen[4];		//box pens
HPEN				uPen[16];		//user color pens
HPEN				xPen;			//pen for crosses in color windows
HPEN				gPen;			//pen for group select
HPEN				grdPen;			//pen for stitch grid
HPEN				bakPen;			//background color pen
HPEN				bitPen;			//bitmap pen
HPEN				fPen;			//form pen
HPEN				ypen[5];		//layer pens
HPEN				fPen3;			//three-pixel form pen
HPEN				fsPen;			//form select pen
HPEN				mrkPen;			//zoom mark pen
HPEN				fmpen;			//multiple selected forms pen
HPEN				alpen;			//pen for drawing large boxes
HPEN				kpen;			//knot pen
HPEN				blakpen;		//black pen

unsigned			bakwid;			//width of the background pen

//brushes
HBRUSH				hStchBak;		//background color brush
HBRUSH				hbrDefCol[16];	//default color brushes
HBRUSH				hbrUseCol[16];	//user color brushes

//clipboard handle
unsigned			hClip=0;		//pcs format
unsigned			htclp=0;		//thred format

//for the choose color dialog box
CHOOSECOLOR			gCol;
COLORREF			custCol[16];
//for the bakground color dialog box
CHOOSECOLOR			bCol;
COLORREF			bakCust[16];
//for the bitmap color dialog box
CHOOSECOLOR			btCol;
COLORREF			bakBit[16];

TCHAR				thrdSiz[16][2];	//user selected thread sizes
unsigned			pixSiz[16];		//thread sizes in pixels
unsigned			sizInd[16];		//thread size indices

HMENU				hMen;			//main menu
HMENU				hfilMen;		//fill submenu
HMENU				hfileMen;		//file submenu
HMENU				hfilBrdMen;		//border fill submenu
HMENU				hvumen;			//view submenu
HMENU				hvsmen;			//view/set
HMENU				hedmen;			//edit submenu
HWND				hDef[16];		//default color windows
HWND				hCol[16];		//user color windows
HWND				hSiz[16];		//thread size windows
HWND				hSizChng[3];	//thread size change windows
HWND				hStch;			//stitch window
HWND				hVrt;			//vertical scroll bar
HWND				hHor;			//horizontal scroll bar
HWND				hbuts[9];		//button windows
HWND				hstep;			//trace step window
HWND				hBar;			//color bar
HWND				hok;			//ok button
HWND				hdsc;			//discard button
HWND				hcan;			//cancel button
HWND				hmin;			//minimum stitch text box
HWND				hgNum;			//general number input box
HWND				hSped;			//speed scroll bar for movie
HWND				hSid=0;			//main side message window
HWND				hsidWnd[16];	//side message windows
HWND				hPrf;			//preferences window
HWND				hfdat=0;		//form data sheet
HWND				hto;			//asking user if she wants delete the sitches associated with a form
HWND				hvu[OLDVER];	//handles of mulitple file viewing windows
HWND				htrup[3];		//trace up number windows
HWND				htrdwn[3];		//trace down number windows

HWND				hctrc[3];		//trace control windows
HWND				hstrc[3];		//trace select windows
unsigned			trshft[]={0,8,16};//trace shift values
HBRUSH				trbrsh[3];		//red,green,and blue brushes
HWND				htred;			//red trace window
HWND				htgrn;			//green trace window
HWND				htblu;			//blue trace window
HWND				hcred;			//red control window
HWND				hcgrn;			//green control window
HWND				hcblu;			//blue control window
HWND				htrnum;			//trace number input window
HBRUSH				hbred;			//red brush
HBRUSH				hbgrn;			//green brush
HBRUSH				hblu;			//blue brush
HBRUSH				hblk;			//black brush
HBRUSH				tbrsh;			//temporary brush

COLORREF			useCol[16];		//user colors
COLORREF			stchBak;		//stich window background
COLORREF			boxRef[]={0x404040,0x408040,0x804040,0x404080};
unsigned			actcol=0;		//active color selector
unsigned			buttonHi;		//button height
unsigned			buttonWid;		//button width
unsigned			buttonWid3;		//button width times 3
unsigned			numwid;			//width of 0
int					tPix[3];		//thread sizes in pixels
unsigned			cbit;			//color bitmap for recording colors on screen
double				ner[NERCNT];	//distances of the closest points
									//to a mouse click
long				nerInd[NERCNT];	//indices of the closest points
unsigned			selCnt;			//number of boxes selected
unsigned			slpnt=0;		//pointer for drawing stitch select lines
POINT				slin[MAXSEQ];	//stitch select line
FLRCT				rngrct;			//stitch range rectangle
FLPNT				rngsiz;			//from check ranges
FLPNT				bigsiz;			//size of multiple select rectangle
unsigned			movpnt;			//for resequencing stitches
double				pixang;			//angle for pixel rotate
SIZE				pcolsiz;		//size of the pick color message
POINT				inspnt;			//size of file insert window
FLPNT				inscntr;		//center point in inserted file
unsigned			numcod;			//keyboard numerical input
double				loang;			//low angle for angle from mark
double				organg;			//original angle for angle from mark
double				hiang;			//hi angle for angle from mark
unsigned			knotab[MAXKNOTS];//pointers to knots
unsigned			knotcnt;		//number of knots in the design
unsigned			knotat;			//knot stitch attribute
FLPNT				knotstp;		//knot step
TCHAR				kstrtdat[]={2,3,1,4,0};	//knot spacings
TCHAR				kendat[]={-2,-3,-1,-4,0};	//reverse knot spacings
TCHAR				klstdat[]={0,-4,-1,-3,-2};	//reverse knot spacings
FLRCT				clprcta;		//rectangle for adjsut range ends for clipboard fills
TCHAR*				balpnt;			//used in the balarad interface
HANDLE				balfil;			//balarad file handle

//graphics variables		
double				aspct=(double)LHUPX/LHUPY;	//aspect ratio of the stich window
SCROLLINFO			scrol;						//scrool bar i/o structure
POINT				stchSiz;					//size of the stich window in pixels
FLPNT				sPnt;						//for converting pixels coordinates
												// to stitch cordinates
POINT				cPnt;			//closest point to a mouse click
FLPNT				zBoxo;			//zoom box origin

COLORREF defCol[]={

	0x000000,
	0x800000,
	0xFF0000,
	0x808000,
	0xFFFF00,
	0x800080,
	0xFF00FF,
	0x000080,
	0x0000FF,
	0x008000,
	0x00FF00,
	0x008080,
	0x00FFFF,
	0x808080,
	0xC0C0C0,
	0xFFFFFF
};

long				selbox;
long				boxOff[4];

unsigned			defMap=0xaf;	//bitmap for color number colors
unsigned			vind;			//vertical index, calculated from mouse click
unsigned			thrdSel;		//thread selected for size change

//file open stuff

MENUITEMINFO filinfo={

	sizeof(MENUITEMINFO),
	MIIM_TYPE,			
	MFT_STRING,			
	0,					
	0,					
	0,					
	0,					
	0,					
	0,					
	msgbuf,			
	13,					
};

const TCHAR			fltr[MAX_PATH]=			"Thredworks (THR)\0*.thr\0Pfaff (PCS)\0*.pcs\0Tajima (DST)\0*.dst\0";
const TCHAR			bfltr[MAX_PATH]="Microsoft (BMP)\0*.bmp\0";
TCHAR				cstFltr[MAX_PATH]="Thredworks (THR)\0*.thr\0";
TCHAR				filnam[MAX_PATH]={0};
TCHAR				thrnam[MAX_PATH];
TCHAR				auxnam[MAX_PATH];
TCHAR				genam[MAX_PATH];
TCHAR				defDir[MAX_PATH]="c:\\";
TCHAR				defbmp[MAX_PATH]="c:\\";
TCHAR				balnam0[MAX_PATH]={0};	//balarad semaphore file
TCHAR				balnam1[MAX_PATH]={0};	//balarad data file
TCHAR				balnam2[MAX_PATH];
TCHAR				srchnam[MAX_PATH];
TCHAR				homdir[MAX_PATH];	//directory from which thred was executed
TCHAR*				phom;			//pointer to the home file name
PCSTCH*				filBuf;
HANDLE				hFil=0;
HANDLE				hPcs=0;
HANDLE				hIni=0;
HANDLE				hinsf;			//insert file handle
HANDLE				hBmp;			//bitmap handle
unsigned			siz;			//size of file
unsigned int 		red;			//bytes actually read from file
unsigned			colCnt;			//number of color changes
TCHAR				iniNam[MAX_PATH];	//.ini file name
unsigned			savcol;			//for saving files
TCHAR				bnam[16];		//bitmap file name from pcs file
TCHAR				lbnam[MAX_PATH];//bitmap file name from user load
OPENFILENAME		ofn={

	sizeof(OPENFILENAME),	//lStructsize
	hWnd,					//hwndOwner 
	hInst,					//hInstance 
	fltr,					//lpstrFilter 
	cstFltr,				//lpstrCustomFilter 
	MAX_PATH,				//nMaxCustFilter 
	0,						//nFilterIndex 
	filnam,					//lpstrFile 
	MAX_PATH,				//nMaxFile 
	0,						//lpstrFileTitle 
	0,						//nMaxFileTitle 
	defDir,					//lpstrInitialDir 
	0,						//lpstrTitle
	OFN_OVERWRITEPROMPT,	//Flags
	0,						//nFileOffset
	0,						//nFileExtension 
	"thr",					//lpstrDefExt 
	0,						//lCustData 
	0,						//lpfnHook
	0,						//lpTemplateName
	};
TCHAR*				thumnams;				//pointer to storage for thumbnail names
TCHAR**				pthums;					//pointers to the thumbnail names
TCHAR*				thumsel[4];				//pointers to thumbnails selectef for display
unsigned			thumcnt;				//number of thumbnail file names
unsigned			thumdcnt;				//number of thumbnail file names selected for display
unsigned			thumind;				//index into the thumbnail filname table
TCHAR				thumsrch[32];			//storage for the thumnail search string
TCHAR				insnam[MAX_PATH]={0};	//insert file name
unsigned			insflt;					//saved float pointer for inserting files
unsigned			insfpnt;				//saved form pointer for inserting files
unsigned			insfstch;				//saved stitch pointer for inserting files

OPENFILENAME obn={
	sizeof(OPENFILENAME),	//lStructsize
	hWnd,					//hwndOwner 
	hInst,					//hInstance 
	bfltr,					//lpstrFilter 
	cstFltr,				//lpstrCustomFilter 
	MAX_PATH,				//nMaxCustFilter 
	0,						//nFilterIndex 
	lbnam,					//lpstrFile 
	MAX_PATH,				//nMaxFile 
	0,						//lpstrFileTitle 
	0,						//nMaxFileTitle 
	defbmp,					//lpstr	ialDir 
	0,						//lpstrTitle
	OFN_OVERWRITEPROMPT,	//Flags
	0,						//nFileOffset
	0,						//nFileExtension 
	"bmp",					//lpstrDefExt 
	0,						//lCustData 
	0,						//lpfnHook
	0,						//lpTemplateName
};

BITMAPFILEHEADER	bhed;	//bitmap file header
BITMAPV4HEADER		b4hed;	//bitmap version4 file header
BITMAPINFO			binf;	//bitmap info
BITMAPINFOHEADER	binfh;	//bitmap info header

COLORREF defUseCol[]={

	0x00000000,
	0x002dffff,
	0x003f87e9,
	0x000762f8,
	0x000000ff,
	0x002f03af,
	0x007248b7,
	0x00ff0080,
	0x00920166,
	0x00a00000,
	0x00ff2424,
	0x006a4d15,
	0x00f5800a,
	0x004b7807,
	0x00156a1e,
	0x00dbe6e3,
};

COLORREF defCustCol[]={

	0x729674,
	0x1a1eb9,
	0x427347,
	0xbfff,
	0xd3c25f,
	0xc3ced0,
	0x4a8459,
	0x8cacd0,
	0x81aeb6,
	0x7243a5,
	0xbdadda,
	0x9976c5,
	0x96d9f5,
	0xe2ddd6,
	0x245322,
	0x7b60ae
};

COLORREF defBakCust[]={

	0xa3c5dc,
	0xadc7b6,
	0xd1fcfb,
	0xdcd7c0,
	0xebddcd,
	0xc6b3b3,
	0xdec9ce,
	0xd2d1e9,
	0xdfdffd,
	0xbee6ef,
	0x8fb8b1,
	0x85c2e0,
	0xabc1c9,
	0xd3d3c7,
	0x7c9c84,
	0x9acddc
};

COLORREF defBakBit[]={

	0xc0d5bf,
	0xc8dfee,
	0x708189,
	0xa5a97a,
	0xb8d6fe,
	0x8a8371,
	0x4b6cb8,
	0x9cdcc2,
	0x366d39,
	0xdcfcfb,
	0x3c4f75,
	0x95b086,
	0xc9dcba,
	0x43377b,
	0xb799ae,
	0x54667a
};

unsigned namloc[]={

	999,	//0
	1024,	//1
	2,		//2
	2051,	//3
	2050,	//4
	5,		//5
	7,		//6
	1,		//7
	17,		//8
	9,		//9
	2058,	//10
	11,		//11
	51,		//12
	6,		//13
	14,		//14
	2055,	//15
	8,		//16
	2056,	//17
	18,		//18
	2057,	//19
	10,		//20
	21,		//21
	22,		//22
	23,		//23
	99,		//24
	3075,	//25
	26,		//26
	2075,	//27
	28,		//28
	2062,	//29
	30,		//30
	63,		//31
	65,		//32
	132,	//33
	68,		//34
	2083,	//35
	36,		//36
	37,		//37
	311,	//38
	3081,	//39
	80,		//40
	41,		//41
	42,		//42
	43,		//43
	1035,	//44
	1547,	//45
	3800,	//46
	47,		//47
	96,		//48
	2054,	//49
};

POINT				mlin0[2];		//move point line
POINT				mlin1[2];		//move point line
POINT				inlin[3];		//the insert line
POINT				blin[5];		//the zoom box
POINT				clplin[5];		//for displaying clipboard insert rectangle
POINT				rlinb[5];		//for drawing the rotate rectangle
POINT				rlinv[2];		//vertical part of the rotate cross
POINT				rlinh[2];		//horizontal part of the rotate cross
POINT				rlinu[2];		//line from the cursor to the center of the rotate cross
POINT				sizlin[5];		//stretch and expand

COLCHNG				colch[MAXCHNG];
HED					hed;			//pcs file header
STREX				hedx;			//thred file header extension
INIFIL				ini;			//initialization file
DUBPNT				rotcntr;		//center of stitch rotation
POINT				pixcntr;		//center of pixel rotation

PCSTCH*				stind;			//stitch pointer
void sCor2px(DUBPNT stpnt,POINT* pxpnt);

typedef struct _dstdat{

	TCHAR	cor;
	TCHAR	val;
}DSTDAT;

#define XCOR 0
#define YCOR 1

DSTDAT	dstval[]={

	{XCOR,1},
	{XCOR,-1},
	{XCOR,9},
	{XCOR,-9},
	{YCOR,-9},
	{YCOR,9},
	{YCOR,-1},
	{YCOR,1},
	{XCOR,3},
	{XCOR,-3},
	{XCOR,27},
	{XCOR,-27},
	{YCOR,-27},
	{YCOR,27},
	{YCOR,-3},
	{YCOR,3},
	{XCOR,0},
	{XCOR,0},
	{XCOR,81},
	{XCOR,-81},
	{YCOR,-81},
	{YCOR,81},
};

unsigned char rencod[]={		//name decryption table

	0x40,
	0x61,
	0x2,
	0x1,
	0x4,
	0x5,
	0x6,
	0x3c,
	0x8,
	0x12,
	0x15,
	0xb,
	0x18,
	0xd,
	0x1d,
	0x3,
	0x10,
	0x23,
	0x9,
	0x13,
	0x28,
	0xa,
	0x16,
	0x2f,
	0x58,
	0x19,
	0x1a,
	0x1b,
	0x3b,
	0x11,
	0x1e,
	0xf,
	0x68,
	0x41,
	0x22,
	0x63,
	0x48,
	0x4a,
	0x26,
	0x27,
	0x14,
	0x29,
	0x55,
	0x57,
	0x2c,
	0x2d,
	0x6b,
	0x5f,
	0xe,
	0xc,
	0x59,
	0x33,
	0x34,
	0x5a,
	0x76,
	0x37,
	0x70,
	0x73,
	0x50,
	0x5d,
	0x1f,
	0x7b,
	0x7c,
	0x3e,
	0x71,
	0x20,
	0x42,
	0x43,
	0x62,
	0x45,
	0x31,
	0x46,
	0x24,
	0x49,
	0x25,
	0x65,
	0x66,
	0x4d,
	0x4e,
	0x67,
	0x21,
	0x74,
	0x69,
	0x53,
	0x54,
	0x2a,
	0x56,
	0x5c,
	0x30,
	0x32,
	0x35,
	0x6c,
	0x2e,
	0x6d,
	0x5e,
	0x17,
	0x0,
	0x7,
	0x44,
	0x1c,
	0x64,
	0x4b,
	0x4c,
	0x4f,
	0x51,
	0x52,
	0x6a,
	0x75,
	0x47,
	0x5b,
	0x6e,
	0x77,
	0x60,
	0x38,
	0x72,
	0x79,
	0x3a,
	0x2b,
	0x36,
	0x6f,
	0x7f,
	0x39,
	0x7d,
	0x3d,
	0x78,
	0x7a,
	0x3f,
	0x7e,
};

unsigned rdcurstrt[]={0x8,0x18,0x3c,0x7c};
unsigned rdcurfin[]={0x48000000,0x50000000,0xa0000000,0xc0000000,0x80000000};
unsigned rucurstrt[]={0x80000000,0xa0000000,0x48000000,0x24000000,0x12000000};
unsigned rucurfin[]={0x3c,0x1c,0xc};
unsigned ldcurstrt[]={0x20000000,0x60000000,0xf0000000,0xf8000000};
unsigned ldcurfin[]={0x44,0x24,0x14,0x6,0x4};
unsigned lucurstrt[]={0x2,0x6,0x14,0x24,0x44};
unsigned lucurfin[]={0x70000000,0x30000000,0x20000000};

unsigned xdst[]={

	0x090a0a,	//-121
	0x090a08,	//-120
	0x090a09,	//-119
	0x09080a,	//-118
	0x090808,	//-117
	0x090809,	//-116
	0x09090a,	//-115
	0x090908,	//-114
	0x090909,	//-113
	0x090a02,	//-112
	0x090a00,	//-111
	0x090a01,	//-110
	0x090802,	//-109
	0x090800,	//-108
	0x090801,	//-107
	0x090902,	//-106
	0x090900,	//-105
	0x090901,	//-104
	0x090a06,	//-103
	0x090a04,	//-102
	0x090a05,	//-101
	0x090806,	//-100
	0x090804,	//-99
	0x090805,	//-98
	0x090906,	//-97
	0x090904,	//-96
	0x090905,	//-95
	0x09020a,	//-94
	0x090208,	//-93
	0x090209,	//-92
	0x09000a,	//-91
	0x090008,	//-90
	0x090009,	//-89
	0x09010a,	//-88
	0x090108,	//-87
	0x090109,	//-86
	0x090202,	//-85
	0x090200,	//-84
	0x090201,	//-83
	0x090002,	//-82
	0x090000,	//-81
	0x090001,	//-80
	0x090102,	//-79
	0x090100,	//-78
	0x090101,	//-77
	0x090206,	//-76
	0x090204,	//-75
	0x090205,	//-74
	0x090006,	//-73
	0x090004,	//-72
	0x090005,	//-71
	0x090106,	//-70
	0x090104,	//-69
	0x090105,	//-68
	0x09060a,	//-67
	0x090608,	//-66
	0x090609,	//-65
	0x09040a,	//-64
	0x090408,	//-63
	0x090409,	//-62
	0x09050a,	//-61
	0x090508,	//-60
	0x090509,	//-59
	0x090602,	//-58
	0x090600,	//-57
	0x090601,	//-56
	0x090402,	//-55
	0x090400,	//-54
	0x090401,	//-53
	0x090502,	//-52
	0x090500,	//-51
	0x090501,	//-50
	0x090606,	//-49
	0x090604,	//-48
	0x090605,	//-47
	0x090406,	//-46
	0x090404,	//-45
	0x090405,	//-44
	0x090506,	//-43
	0x090504,	//-42
	0x090505,	//-41
	0x010a0a,	//-40
	0x010a08,	//-39
	0x010a09,	//-38
	0x01080a,	//-37
	0x010808,	//-36
	0x010809,	//-35
	0x01090a,	//-34
	0x010908,	//-33
	0x010909,	//-32
	0x010a02,	//-31
	0x010a00,	//-30
	0x010a01,	//-29
	0x010802,	//-28
	0x010800,	//-27
	0x010801,	//-26
	0x010902,	//-25
	0x010900,	//-24
	0x010901,	//-23
	0x010a06,	//-22
	0x010a04,	//-21
	0x010a05,	//-20
	0x010806,	//-19
	0x010804,	//-18
	0x010805,	//-17
	0x010906,	//-16
	0x010904,	//-15
	0x010905,	//-14
	0x01020a,	//-13
	0x010208,	//-12
	0x010209,	//-11
	0x01000a,	//-10
	0x010008,	//-9
	0x010009,	//-8
	0x01010a,	//-7
	0x010108,	//-6
	0x010109,	//-5
	0x010202,	//-4
	0x010200,	//-3
	0x010201,	//-2
	0x010002,	//-1
	0x010000,	//0
	0x010001,	//1
	0x010102,	//2
	0x010100,	//3
	0x010101,	//4
	0x010206,	//5
	0x010204,	//6
	0x010205,	//7
	0x010006,	//8
	0x010004,	//9
	0x010005,	//10
	0x010106,	//11
	0x010104,	//12
	0x010105,	//13
	0x01060a,	//14
	0x010608,	//15
	0x010609,	//16
	0x01040a,	//17
	0x010408,	//18
	0x010409,	//19
	0x01050a,	//20
	0x010508,	//21
	0x010509,	//22
	0x010602,	//23
	0x010600,	//24
	0x010601,	//25
	0x010402,	//26
	0x010400,	//27
	0x010401,	//28
	0x010502,	//29
	0x010500,	//30
	0x010501,	//31
	0x010606,	//32
	0x010604,	//33
	0x010605,	//34
	0x010406,	//35
	0x010404,	//36
	0x010405,	//37
	0x010506,	//38
	0x010504,	//39
	0x010505,	//40
	0x050a0a,	//41
	0x050a08,	//42
	0x050a09,	//43
	0x05080a,	//44
	0x050808,	//45
	0x050809,	//46
	0x05090a,	//47
	0x050908,	//48
	0x050909,	//49
	0x050a02,	//50
	0x050a00,	//51
	0x050a01,	//52
	0x050802,	//53
	0x050800,	//54
	0x050801,	//55
	0x050902,	//56
	0x050900,	//57
	0x050901,	//58
	0x050a06,	//59
	0x050a04,	//60
	0x050a05,	//61
	0x050806,	//62
	0x050804,	//63
	0x050805,	//64
	0x050906,	//65
	0x050904,	//66
	0x050905,	//67
	0x05020a,	//68
	0x050208,	//69
	0x050209,	//70
	0x05000a,	//71
	0x050008,	//72
	0x050009,	//73
	0x05010a,	//74
	0x050108,	//75
	0x050109,	//76
	0x050202,	//77
	0x050200,	//78
	0x050201,	//79
	0x050002,	//80
	0x050000,	//81
	0x050001,	//82
	0x050102,	//83
	0x050100,	//84
	0x050101,	//85
	0x050206,	//86
	0x050204,	//87
	0x050205,	//88
	0x050006,	//89
	0x050004,	//90
	0x050005,	//91
	0x050106,	//92
	0x050104,	//93
	0x050105,	//94
	0x05060a,	//95
	0x050608,	//96
	0x050609,	//97
	0x05040a,	//98
	0x050408,	//99
	0x050409,	//100
	0x05050a,	//101
	0x050508,	//102
	0x050509,	//103
	0x050602,	//104
	0x050600,	//105
	0x050601,	//106
	0x050402,	//107
	0x050400,	//108
	0x050401,	//109
	0x050502,	//110
	0x050500,	//111
	0x050501,	//112
	0x050606,	//113
	0x050604,	//114
	0x050605,	//115
	0x050406,	//116
	0x050404,	//117
	0x050405,	//118
	0x050506,	//119
	0x050504,	//120
	0x050505,	//121
};

unsigned ydst[]={

	0x115050,	//-121
	0x115010,	//-120
	0x115090,	//-119
	0x111050,	//-118
	0x111010,	//-117
	0x111090,	//-116
	0x119050,	//-115
	0x119010,	//-114
	0x119090,	//-113
	0x115040,	//-112
	0x115000,	//-111
	0x115080,	//-110
	0x111040,	//-109
	0x111000,	//-108
	0x111080,	//-107
	0x119040,	//-106
	0x119000,	//-105
	0x119080,	//-104
	0x115060,	//-103
	0x115020,	//-102
	0x1150a0,	//-101
	0x111060,	//-100
	0x111020,	//-99
	0x1110a0,	//-98
	0x119060,	//-97
	0x119020,	//-96
	0x1190a0,	//-95
	0x114050,	//-94
	0x114010,	//-93
	0x114090,	//-92
	0x110050,	//-91
	0x110010,	//-90
	0x110090,	//-89
	0x118050,	//-88
	0x118010,	//-87
	0x118090,	//-86
	0x114040,	//-85
	0x114000,	//-84
	0x114080,	//-83
	0x110040,	//-82
	0x110000,	//-81
	0x110080,	//-80
	0x118040,	//-79
	0x118000,	//-78
	0x118080,	//-77
	0x114060,	//-76
	0x114020,	//-75
	0x1140a0,	//-74
	0x110060,	//-73
	0x110020,	//-72
	0x1100a0,	//-71
	0x118060,	//-70
	0x118020,	//-69
	0x1180a0,	//-68
	0x116050,	//-67
	0x116010,	//-66
	0x116090,	//-65
	0x112050,	//-64
	0x112010,	//-63
	0x112090,	//-62
	0x11a050,	//-61
	0x11a010,	//-60
	0x11a090,	//-59
	0x116040,	//-58
	0x116000,	//-57
	0x116080,	//-56
	0x112040,	//-55
	0x112000,	//-54
	0x112080,	//-53
	0x11a040,	//-52
	0x11a000,	//-51
	0x11a080,	//-50
	0x116060,	//-49
	0x116020,	//-48
	0x1160a0,	//-47
	0x112060,	//-46
	0x112020,	//-45
	0x1120a0,	//-44
	0x11a060,	//-43
	0x11a020,	//-42
	0x11a0a0,	//-41
	0x015050,	//-40
	0x015010,	//-39
	0x015090,	//-38
	0x011050,	//-37
	0x011010,	//-36
	0x011090,	//-35
	0x019050,	//-34
	0x019010,	//-33
	0x019090,	//-32
	0x015040,	//-31
	0x015000,	//-30
	0x015080,	//-29
	0x011040,	//-28
	0x011000,	//-27
	0x011080,	//-26
	0x019040,	//-25
	0x019000,	//-24
	0x019080,	//-23
	0x015060,	//-22
	0x015020,	//-21
	0x0150a0,	//-20
	0x011060,	//-19
	0x011020,	//-18
	0x0110a0,	//-17
	0x019060,	//-16
	0x019020,	//-15
	0x0190a0,	//-14
	0x014050,	//-13
	0x014010,	//-12
	0x014090,	//-11
	0x010050,	//-10
	0x010010,	//-9
	0x010090,	//-8
	0x018050,	//-7
	0x018010,	//-6
	0x018090,	//-5
	0x014040,	//-4
	0x014000,	//-3
	0x014080,	//-2
	0x010040,	//-1
	0x010000,	//0
	0x010080,	//1
	0x018040,	//2
	0x018000,	//3
	0x018080,	//4
	0x014060,	//5
	0x014020,	//6
	0x0140a0,	//7
	0x010060,	//8
	0x010020,	//9
	0x0100a0,	//10
	0x018060,	//11
	0x018020,	//12
	0x0180a0,	//13
	0x016050,	//14
	0x016010,	//15
	0x016090,	//16
	0x012050,	//17
	0x012010,	//18
	0x012090,	//19
	0x01a050,	//20
	0x01a010,	//21
	0x01a090,	//22
	0x016040,	//23
	0x016000,	//24
	0x016080,	//25
	0x012040,	//26
	0x012000,	//27
	0x012080,	//28
	0x01a040,	//29
	0x01a000,	//30
	0x01a080,	//31
	0x016060,	//32
	0x016020,	//33
	0x0160a0,	//34
	0x012060,	//35
	0x012020,	//36
	0x0120a0,	//37
	0x01a060,	//38
	0x01a020,	//39
	0x01a0a0,	//40
	0x215050,	//41
	0x215010,	//42
	0x215090,	//43
	0x211050,	//44
	0x211010,	//45
	0x211090,	//46
	0x219050,	//47
	0x219010,	//48
	0x219090,	//49
	0x215040,	//50
	0x215000,	//51
	0x215080,	//52
	0x211040,	//53
	0x211000,	//54
	0x211080,	//55
	0x219040,	//56
	0x219000,	//57
	0x219080,	//58
	0x215060,	//59
	0x215020,	//60
	0x2150a0,	//61
	0x211060,	//62
	0x211020,	//63
	0x2110a0,	//64
	0x219060,	//65
	0x219020,	//66
	0x2190a0,	//67
	0x214050,	//68
	0x214010,	//69
	0x214090,	//70
	0x210050,	//71
	0x210010,	//72
	0x210090,	//73
	0x218050,	//74
	0x218010,	//75
	0x218090,	//76
	0x214040,	//77
	0x214000,	//78
	0x214080,	//79
	0x210040,	//80
	0x210000,	//81
	0x210080,	//82
	0x218040,	//83
	0x218000,	//84
	0x218080,	//85
	0x214060,	//86
	0x214020,	//87
	0x2140a0,	//88
	0x210060,	//89
	0x210020,	//90
	0x2100a0,	//91
	0x218060,	//92
	0x218020,	//93
	0x2180a0,	//94
	0x216050,	//95
	0x216010,	//96
	0x216090,	//97
	0x212050,	//98
	0x212010,	//99
	0x212090,	//100
	0x21a050,	//101
	0x21a010,	//102
	0x21a090,	//103
	0x216040,	//104
	0x216000,	//105
	0x216080,	//106
	0x212040,	//107
	0x212000,	//108
	0x212080,	//109
	0x21a040,	//110
	0x21a000,	//111
	0x21a080,	//112
	0x216060,	//113
	0x216020,	//114
	0x2160a0,	//115
	0x212060,	//116
	0x212020,	//117
	0x2120a0,	//118
	0x21a060,	//119
	0x21a020,	//120
	0x21a0a0,	//121
};

#if PESACT

unsigned pestrn[]={

	0xf0f0f0, //00 
	0x940a1a, //01 
	0xff750f, //02 
	0x4c9300, //03 
	0xfebdba, //04 
	0x0000ec, //05 
	0x5a99e4, //06 
	0xab48cc, //07 
	0xfac4fd, //08 
	0xcd84dd, //09 
	0x8ad36b, //10 
	0x45a9e4, //11 
	0x42bdff, //12 
	0x00e6ff, //13 
	0x00d96c, //14 
	0x41a9c1, //15 
	0x97adb5, //16 
	0x5f9cba, //17 
	0x9ef5fa, //18 
	0x808080, //19 
	0x000000, //20
	0xdf1c00, //21 
	0xb800df, //22 
	0x626262, //23 
	0x0d2669, //24 
	0x6000ff, //25 
	0x0082bf, //26 
	0x7891f3, //27 
	0x0568ff, //28 
	0xf0f0f0, //29 
	0xcd32c8, //30 
	0x9bbfb0, //31 
	0xebbf65, //32 
	0x04baff, //33 
	0x6cf0ff, //34 
	0x15cafe, //35 
	0x0181f3, //36 
	0x23a937, //37 
	0x5f4623, //38 
	0x95a6a6, //39 
	0xa6bfce, //40 
	0x02aa96, //41 
	0xc6e3ff, //42 
	0xd799ff, //43 
	0x047000, //44 
	0xfbcced, //45 
	0xd889c0, //46 
	0xb4d9e7, //47 
	0x860ee9, //48 
	0x2968cf, //49 
	0x158640, //50 
	0x9717db, //51 
	0x04a7ff, //52 
	0xffffb9, //53 
	0x278922, //54 
	0xcd12b6, //55 
	0x00aa00, //56 
	0xdca9fe, //57 
	0x10d5fe, //58 
	0xdf9700, //59 
	0x84ffff, //60 
	0x74e7cf, //61 
	0x42bdff, //62 
	0xb4d9e7  //63 
};
#endif

DSTREC*		drecs;		//pointer to dst stitch records
unsigned	dstcnt;		//number of dst stitch records
unsigned	trinum;		//for trinary/binary translation
POINT		dstplus;	//plus offset written into the dst file header
POINT		dstmin;		//minus offset written into the dst file header

//bitmap for upper case characters
unsigned upmap[]={

			//fedcba9876543210fedcba9876543210
0,			//00000000000000000000000000000000
			//?>=</:9876543210 /.-,+*)('&%$#"!
0,			//00000000000000000000000000000000
			//_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@
0x07fffffe,	//00000111111111111111111111111110
			// ~}|{zyxwvutsrqponmlkjihgfedcba'
0,			//00000000000000000000000000000000
};

unsigned			map[MAPLEN];	//bitmap
unsigned			umap=0;			//for storage of persistent binary variables set by the user

SHRTPNT				stchs[MAXPCS];	//main stitch buffer
SHRTPNT*			sind;			//stitch pointer for saving file
SHRTPNT				clpnu[MAXSEQ];	//for temporary copy of imported clipboard data
FRMHED*				frmpnt;			//pointer to selected form
unsigned			filtyps[]=		//fill type array for side window display
{0,VRTF,HORF,ANGF,SATF,CLPF,CONTF,VCLPF,HCLPF,ANGCLPF,FTHF,TXVRTF,TXHORF,TXANGF};
//edge fill type array for side window display
unsigned			egtyps[]={0,EGLIN,EGBLD,EGCLP,EGSAT,EGAP,EGPRP,EGHOL,EGPIC,EGDUB,EGCHNL,EGCHNH,EGCLPX}; 
//feather fill types
unsigned			fthtyps[]={FTHSIN,FTHSIN2,FTHLIN,FTHPSG,FTHRMP,FTHFAZ};

//bitmap functions
unsigned setMap(unsigned bPnt){
	return bts(map, bPnt) ? 0xffffffff : 0;
}

void clrMap(unsigned len){
	memset(map, 0, sizeof(*map) * len);
}

unsigned rstMap(unsigned bPnt){
	return btr(map, bPnt) ? 0xffffffff : 0;
}

unsigned toglMap(unsigned bPnt){
	return btc(map, bPnt) ? 0xffffffff : 0;
}

unsigned chkMap(unsigned bPnt){
	return bt(map, bPnt) ? 0xffffffff : 0;
}

void cpymap(unsigned dst,unsigned src){
	if (bt(map, src)) {
		bts(map, dst);
	} else {
		btr(map, dst);
	}
}

//user bitmap functions
unsigned setu(unsigned bPnt){
	return bts(&umap, bPnt) ? 0xffffffff : 0;
}

unsigned rstu(unsigned bPnt){
	return btr(&umap, bPnt) ? 0xffffffff : 0;
}

unsigned chku(unsigned bPnt){
	return bt(&umap, bPnt) ? 0xffffffff : 0;
}

unsigned toglu(unsigned bPnt){
	return btc(&umap, bPnt) ? 0xffffffff : 0;
}

unsigned dumsk(unsigned pnt){
	return bswap_32(0xffffffff << (32 - (pnt & 0x1F)));
}

BOOL CALLBACK dnamproc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam)
{
	HWND hwnd;
	switch(umsg)
	{
	case WM_INITDIALOG:

		hwnd=GetDlgItem(hwndlg,IDC_DESED);
		SetWindowText(hwnd,ini.desnam);
		SetFocus(hwnd);
		SendMessage(hwnd,EM_SETSEL,0,-1);
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam))
		{
		case IDCANCEL:

			EndDialog(hwndlg,0); 
			return TRUE;

		case IDOK:

			hwnd=GetDlgItem(hwndlg,IDC_DESED);
			GetWindowText(hwnd,ini.desnam,50);
			EndDialog(hwndlg,0);
			sprintf(msgbuf,stab[STR_THRED],ini.desnam);
			SetWindowText(hWnd,msgbuf);
			return TRUE;
		}
	}
	return 0;
}

void getdes()
{
 	DialogBox(hInst,MAKEINTRESOURCE(IDD_DESNAM),hWnd,(DLGPROC)dnamproc);
}

void ler(){

	per=strerror(GetLastError());
}

BOOL isclp(unsigned find){

	if((1<<formlst[find].ftyp)&clpmap)
		return 1;
	return 0;
}

BOOL isclpx(unsigned find){

	if(isclp(find)&&formlst[find].flencnt.nclp)
		return 1;
	return 0;
}

BOOL isfclp(){

	if(isclp(clofind)&&formlst[clofind].ftyp!=CLPF)
		return 1;
	return 0;
}

BOOL iseclp(unsigned find){

	if(formlst[find].etyp==EGCLP||formlst[find].etyp==EGPIC||formlst[find].etyp==EGCLPX)
		return 1;
	return 0;
}

BOOL iseclpx(unsigned find){

	if(iseclp(find)&&formlst[find].nclp)
		return 1;
	return 0;
}

double stlen(unsigned stind){

	return hypot(stchs[stind+1].x-stchs[stind].x,stchs[stind+1].y-stchs[stind].y);
}

void undat(){

	if(hfdat){

		DestroyWindow(hfdat);
		hfdat=0;
	}
}

void qchk(){

	if(chku(MARQ)){

		CheckMenuItem(hMen,ID_MARKESC,MF_CHECKED);
		CheckMenuItem(hMen,ID_MARKQ,MF_UNCHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_MARKESC,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_MARKQ,MF_CHECKED);
	}
	setMap(DUMEN);
}

void nedmen(){

	if(chku(NEDOF)){

		CheckMenuItem(hMen,ID_SETNEDL,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_RSTNEDL,MF_CHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_SETNEDL,MF_CHECKED);
		CheckMenuItem(hMen,ID_RSTNEDL,MF_UNCHECKED);
	}
	setMap(DUMEN);
}

void knotmen(){

	if(chku(KNOTOF)){

		CheckMenuItem(hMen,ID_KNOTON,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_KNOTOF,MF_CHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_KNOTON,MF_CHECKED);
		CheckMenuItem(hMen,ID_KNOTOF,MF_UNCHECKED);
	}
	setMap(DUMEN);
}

void bsavmen(){

	if(chku(BSAVOF)){

		CheckMenuItem(hMen,ID_BSAVON,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_BSAVOF,MF_CHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_BSAVON,MF_CHECKED);
		CheckMenuItem(hMen,ID_BSAVOF,MF_UNCHECKED);
	}
	setMap(DUMEN);
}

void linbmen(){

	if(chku(LINSPAC)){

		CheckMenuItem(hMen,ID_LINBEXACT,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_LINBEVEN,MF_CHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_LINBEXACT,MF_CHECKED);
		CheckMenuItem(hMen,ID_LINBEVEN,MF_UNCHECKED);
	}
	setMap(DUMEN);
}

void wrnmen()
{
	unsigned cod;

	cod=MF_CHECKED;
	if(chku(WRNOF))
		cod=MF_UNCHECKED;
	CheckMenuItem(hMen,ID_WARNOF,cod);
}

int datcod[]={ID_CHKOF,ID_CHKON,ID_CHKREP,ID_CHKREPMSG};

void chkmen()
{
	int ind,cod;

	for(ind=0;ind<(sizeof(datcod)/sizeof(int));ind++)
	{
		cod=MF_UNCHECKED;
		if(ind==ini.dchk)
			cod=MF_CHECKED;
		CheckMenuItem(hMen,datcod[ind],cod);
	}
}

void duzrat(){

	if(!zRct.right)
		zRct.right=LHUPX;
	if(!zRct.top)
		zRct.top=LHUPY;
	zrat.x=(double)(scRct.right)/(zRct.right-zRct.left);
	zrat.y=(double)(scRct.bottom/(zRct.top-zRct.bottom));
}

unsigned rsed(){

	SYSTEMTIME tim;

	GetLocalTime(&tim);
	return (tim.wSecond<<16)|tim.wMilliseconds;
}

void ritfnam(TCHAR* nam){

	unsigned		ind;
	unsigned char	tnam[50];

	if(*fnamord>50)
		fnamtabs();
	psgacc=rsed();
	for(ind=0;ind<50;ind++)
		tnam[ind]=psg()&0xff;
	for(ind=0;ind<50;ind++){

		if(nam[ind])
			tnam[ind]=fnamcod[nam[ind]];
		else{

			while(frencod[tnam[ind]])
				tnam[ind]=psg()&0xff;
			break;
		}
	}
	if(ind==50){

		while(frencod[tnam[49]])
			tnam[49]=psg()&0xff;
	}
	for(ind=0;ind<50;ind++)
		hedx.crtnam[fnamord[ind]]=tnam[ind];
}

void redfnam(TCHAR* nam){

	unsigned ind;
	unsigned char tnam[50];

	for(ind=0;ind<50;ind++)
		if(fnamord[ind]>50)
			tnam[ind]=111;
		else
			tnam[ind]=hedx.crtnam[fnamord[ind]];
	for(ind=0;ind<50;ind++){
	
		nam[ind]=frencod[tnam[ind]];
		if(!nam[ind])
			return;
	}
}

void fnamtabs(){

	unsigned		ind,tuns,src,dst;
	unsigned char	chr;
	unsigned*		puns;

	for(ind=0;ind<50;ind++)
		fnamord[ind]=ind;
	psgacc=NORDSED;
	for(ind=0;ind<100;ind++){

		src=psg()%50;
		dst=psg()%50;
		tuns=fnamord[dst];
		fnamord[dst]=fnamord[src];
		fnamord[src]=tuns;
	}
	for(ind=0;ind<128;ind++)
		fnamcod[ind]=(unsigned char)ind+NCODOF;
	psgacc=NCODSED;
	for(ind=0;ind<256;ind++){

		src=psg()&0x7f;
		dst=psg()&0x7f;
		chr=fnamcod[dst];
		fnamcod[dst]=fnamcod[src];
		fnamcod[src]=chr;
	}
	puns=(unsigned*)&frencod;
	for(ind=0;ind<64;ind++)
		puns[ind]=0;
	for(ind=32;ind<127;ind++)
		frencod[fnamcod[ind]]=(unsigned char)ind;
}

void dstin(unsigned num,POINT* pout){

	unsigned ind,shft;

	shft=1;
	pout->x=pout->y=0;
	for(ind=0;ind<22;ind++){

		if(num&shft){

			if(dstval[ind].cor)
				pout->y+=dstval[ind].val;
			else
				pout->x+=dstval[ind].val;
		}
		shft<<=1;
	}
}

FLPNT* adflt(unsigned cnt){

	unsigned ind=fltad;

	if(fltad+cnt>MAXFLT)
		tabmsg(IDS_FRMOVR);
	fltad+=cnt;
	return &flts[ind];
}

SATCON* adsatk(unsigned cnt){

	unsigned ind=satkad;

	satkad+=cnt;
	return &satks[ind];
}

FLPNT* adclp(unsigned cnt){

	unsigned ind=clpad;

	clpad+=cnt;
	return &clps[ind];
}

unsigned duthrsh(double var){

	unsigned	ind=0;
	double		tdub=1;

	if(var){

		while(tdub>var){

			tdub*=ZUMFCT;
			ind++;
		}
	}
	else
		return 0;
	return ind+1;
}

double unthrsh(unsigned lev){

	double		tdub=1;

	if(lev)
		lev--;
	else
		return 0;
	while(lev){

		tdub*=ZUMFCT;
		lev--;
	}
	return tdub;
}

void ritfcor(FLPNT* pnt){

	sprintf(msgbuf,"x%.0f y%.0f",pnt->x/PFGRAN,pnt->y/PFGRAN);
	butxt(HCOR,msgbuf);
}

void ritcor(SHRTPNT* pnt){

	FLPNT	tpnt;

	tpnt.x=pnt->x;
	tpnt.y=pnt->y;
	ritfcor(&tpnt);
}

void coltab(){

	unsigned	ind,col,tuns;
	unsigned	ocol;
	DUBRCT		rng;
	SHRTPNT*	ts;

	colCnt=0;
	if(hed.stchs)
	{
		stchs[0].at&=NCOLMSK;
		stchs[0].at|=(stchs[1].at&COLMSK);
		stchs[hed.stchs-1].at&=NCOLMSK;
		stchs[hed.stchs-1].at|=(stchs[hed.stchs-2].at&COLMSK);
		ocol=stchs[0].at&COLMSK;
		for(ind=1;ind<(unsigned)hed.stchs-1;ind++)
		{
			if((stchs[ind].at&COLMSK)!=ocol)
			{
				if((stchs[ind+1].at&COLMSK)==ocol)
				{
					stchs[ind].at&=NCOLMSK;
					stchs[ind].at|=ocol;
				}
				ocol=stchs[ind].at&COLMSK;
			}
		}
		col=0;
		ocol=0xffffffff;
		rng.left=-zum0.x;
		rng.right=zum0.x*2;
		rng.bottom=-zum0.y;
		rng.top=zum0.y*2;
		for(ind=0;ind<hed.stchs;ind++)
		{
			ts=&stchs[ind];
			if(ts->x<rng.left)
				ts->x=(float)rng.left;
			if(ts->x>rng.right)
				ts->x=(float)rng.right;
			if(ts->y>rng.top)
				ts->y=(float)rng.top;
			if(ts->y<rng.bottom)
				ts->y=(float)rng.bottom;
			tuns=ts->at&COLMSK;
			if(ocol!=tuns)
			{
				colch[col].colind=(unsigned char)tuns;
				colch[col++].stind=(unsigned short)ind;
				ocol=tuns;
			}
		}
		colCnt=col;
		colch[col].stind=(unsigned short)ind;
		if(cloInd>(unsigned)hed.stchs-1)
			cloInd=hed.stchs-1;
		fndknt();
	}
}

void ladj(){

	unsigned ind;

	for(ind=0;ind<5;ind++){

		if(ind==actl)
			EnableMenuItem(hMen,ind+M_ALL,MF_BYPOSITION|MF_GRAYED);
		else
			EnableMenuItem(hMen,ind+M_ALL,MF_BYPOSITION|MF_ENABLED);
	}
	setMap(DUMEN);
}

void stchcpy(unsigned siz,SHRTPNT* dst){
	memcpy(dst, stchs, siz * 4);
}

void deldu(){

	unsigned ind;

	for(ind=0;ind<16;ind++){

		if(bakdat[ind]){

			free(bakdat[ind]);
			bakdat[ind]=0;
		}
	}
	dupnt0=0;
	rstMap(BAKWRAP);
	rstMap(BAKACT);
}

TCHAR* mvflpnt(FLPNT* dst,FLPNT* src,unsigned cnt){
	memcpy(dst, src, cnt * sizeof(FLPNT));
	return (TCHAR *) (dst + cnt);
}

void mvsatk(SATCON* dst,SATCON* src,unsigned cnt){
	memcpy(dst, src, cnt * sizeof(SATCON));
}

void dudat(){

	unsigned	siz;
	BAKHED*		bdat;
//	unsigned	ind;
	unsigned	addr;
	unsigned	chksiz;

	if(bakdat[dupnt0])
		free(bakdat[dupnt0]);
	siz=sizeof(BAKHED)+sizeof(FRMHED)*formpnt+sizeof(SHRTPNT)*hed.stchs
		+sizeof(FLPNT)*(fltad+clpad)+sizeof(SATCON)*satkad+sizeof(COLORREF)*16+
		sizeof(TXPNT)*txad;
	bakdat[dupnt0]=malloc(siz);
	bdat=(BAKHED*)bakdat[dupnt0];
	if(bdat){

		bdat->zum0.x=zum0.x;
		bdat->zum0.y=zum0.y;
		bdat->fcnt=formpnt;
		bdat->frmp=(FRMHED*)&bdat[1];
//		for(ind=0;ind<formpnt;ind++)
//			frmcpy(&bdat->frmp[ind],&formlst[ind]);
		MoveMemory(bdat->frmp,&formlst,sizeof(FRMHED)*formpnt);
		bdat->scnt=hed.stchs;
		bdat->stch=(SHRTPNT*)&bdat->frmp[formpnt];
		if(hed.stchs)
			stchcpy((sizeof(SHRTPNT)*hed.stchs)>>2,bdat->stch);
		bdat->fltcnt=fltad;
		bdat->flt=(FLPNT*)&bdat->stch[hed.stchs];
		if(fltad)
			mvflpnt(bdat->flt,&flts[0],fltad);
		bdat->sacnt=satkad;
		bdat->sac=(SATCON*)&bdat->flt[fltad];
		if(satkad)
			mvsatk(bdat->sac,&satks[0],satkad);
		bdat->nclp=clpad;
		bdat->clp=(FLPNT*)&bdat->sac[satkad];
		if(clpad){

			if(clpad>MAXCLPNTS)
				clpad=MAXCLPNTS;
			mvflpnt(bdat->clp,&clps[0],clpad);
		}
		bdat->cols=(COLORREF*)&bdat->clp[clpad];
		MoveMemory(bdat->cols,&useCol,sizeof(COLORREF)*16);
		bdat->txp=(TXPNT*)&bdat->cols[16];
		bdat->ntx=txad;
		if(txad)
			MoveMemory(bdat->txp,&txpnts,sizeof(TXPNT)*txad);
	}
	addr=(unsigned)&bdat->txp[txad];
	chksiz=addr-(unsigned)bakdat[dupnt0];
}

void savdo(){

	setMap(WASDO);
	setMap(CMPDO);
	if(rstMap(SAVACT)){

		if(rstMap(BAKING)){

			rstMap(REDUSHO);
			EnableMenuItem(hMen,M_REDO,MF_BYPOSITION|MF_GRAYED);
		}
		setMap(BAKACT);
		EnableMenuItem(hMen,M_UNDO,MF_BYPOSITION|MF_ENABLED);
		setMap(DUMEN);
		dudat();
		dupnt0++;
		dupnt0&=0xf;
		if(!dupnt0)
			setMap(BAKWRAP);
	}
}

void redfils(){

	unsigned			ind;
	WIN32_FIND_DATA		fdat;
	HANDLE				hndl;

	for(ind=0;ind<OLDNUM;ind++) {
		if (GetMenuState(hfileMen, fmenid[ind], MF_BYCOMMAND) != -1)
			DeleteMenu(hfileMen,fmenid[ind],MF_BYCOMMAND);
	}
	for(ind=0;ind<OLDNUM;ind++){

		if(ini.oldnams[ind][0]){

			if(chkMap(SAVAS))
				AppendMenu(hfileMen,MF_BYCOMMAND|MF_STRING,fmenid[ind],ini.oldnams[ind]);
			else{

				hndl=FindFirstFile(ini.oldnams[ind],&fdat);
				if(hndl==INVALID_HANDLE_VALUE)
					ini.oldnams[ind][0]=0;
				else{

					AppendMenu(hfileMen,MF_BYCOMMAND|MF_STRING,fmenid[ind],ini.oldnams[ind]);
					FindClose(hndl);
				}
			}
		}
	}
	setMap(DUMEN);
}

void nunams(){

	TCHAR*		pext;
	unsigned	ind;
	TCHAR		tnam[MAX_PATH];

	_strlwr(filnam);
	pext=strrchr(filnam,'.');
	if(pext)
		pext++;
	else
		pext=&filnam[strlen(filnam)];
	ind=pext-filnam;
	strncpy(auxnam,filnam,ind);
	strncpy(thrnam,filnam,ind);
	strncpy(genam,filnam,ind);
	pext=auxnam+ind;
	switch(ini.auxfil){

	case AUXDST:

		strcpy(pext,"dst");
		break;

#if PESACT

	case AUXPES:

		strcpy(pext,"pes");
		break;

#endif

	default:

		strcpy(pext,"pcs");
	}
	pext=thrnam+ind;
	strcpy(pext,"thr");
	pext=genam+ind;
	strcpy(pext,"th*");
	for(ind=0;ind<OLDNUM;ind++){

		if(!strcmp(ini.oldnams[ind],thrnam)){

			if(ind){

				strcpy(tnam,ini.oldnams[0]);
				strcpy(ini.oldnams[0],ini.oldnams[ind]);
				strcpy(ini.oldnams[ind],tnam);
				goto mendun;
			}
			else
				goto nomen;
		}
	}
	for(ind=0;ind<OLDNUM;ind++){

		if(!ini.oldnams[ind][0]){

			strcpy(ini.oldnams[ind],thrnam);
			goto mendun;
		}
	}
	strcpy(ini.oldnams[3],ini.oldnams[2]);
	strcpy(ini.oldnams[2],ini.oldnams[1]);
	strcpy(ini.oldnams[1],ini.oldnams[0]);
	strcpy(ini.oldnams[0],thrnam);
mendun:;
	redfils();
nomen:;
}

void mvstch(SHRTPNT* dst, SHRTPNT* src){
	memcpy(dst, src, sizeof(SHRTPNT));
}

void duzero(){

	unsigned	ind,dst;
	double		len;
	SHRTPNT*	lpnt;

	if(fselpnt){

		clRmap(RMAPSIZ);
		for(ind=0;ind<fselpnt;ind++)
			setr(selist[ind]);
		rstMap(CONTIG);
		dst=0;
		lpnt=stchs;
		for(ind=0;ind<hed.stchs;ind++){

			if(stchs[ind].at&TYPMSK&&chkr((stchs[ind].at&FRMSK)>>FRMSHFT)){

				if(setMap(CONTIG)){

					len=hypot(stchs[ind].x-lpnt->x,stchs[ind].y-lpnt->y);
					if(len>minsiz){

						lpnt=&stchs[ind];
						mvstch(&stchs[dst++],&stchs[ind]);
					}
				}
				else
					lpnt=&stchs[ind];
			}
			else{

				mvstch(&stchs[dst++],&stchs[ind]);
				rstMap(CONTIG);
			}	
		}
		hed.stchs=dst;
		coltab();
		setMap(RESTCH);
		return;
	}
	if(chkMap(GRPSEL)){
		
		rngadj();
		delsmal(gpnt0,gpnt1);
	}
	else
		delsmal(0,hed.stchs);
}

void rshft(POINT shpnt){

	zRct.right-=shpnt.x;
	zRct.left-=shpnt.x;
	zRct.top-=shpnt.y;
	zRct.bottom-=shpnt.y;
	zRctAdj();
	setMap(RESTCH);
}

void pgdwn(){

	POINT scPnt;

	if(chkMap(ZUMED)){

#pragma warning(disable:4244;once:)
		scPnt.y=(zRct.top-zRct.bottom)*PAGSCROL;
		scPnt.x=0;
		rshft(scPnt);
	}
}

void pgup(){

	POINT scPnt;

	if(chkMap(ZUMED)){

#pragma warning(disable:4244;once:)
		scPnt.y=-(zRct.top-zRct.bottom)*PAGSCROL;
		scPnt.x=0;
		rshft(scPnt);
	}
}

void pglft(){

	POINT scPnt;

	if(chkMap(ZUMED)){

#pragma warning(disable:4244;once:)
		scPnt.x=(zRct.right-zRct.left)*PAGSCROL;
		scPnt.y=0;
		rshft(scPnt);
	}
}

void pgrit(){

	POINT scPnt;

	if(chkMap(ZUMED)){

#pragma warning(disable:4244;once:)
		scPnt.x=-(zRct.right-zRct.left)*PAGSCROL;
		scPnt.y=0;
		rshft(scPnt);
	}
}

void selin(unsigned strt,unsigned end,HDC dc){

	unsigned		ind;
	double			tcor;
	long			hi;

	SelectObject(dc,gPen);
	SetROP2(rsdc,R2_NOTXORPEN);
	if(slpnt)
		Polyline(dc,slin,slpnt);
	if(strt>end){

		ind=strt;
		strt=end;
		end=ind;
	}
	hi=scRct.bottom;
	ind=end-strt+1;
	if(ind<5)
		ind=5;
	slpnt=0;
	for(ind=strt;ind<=end;ind++){

		tcor=((stchs[ind].x-zRct.left)*zrat.x+0.5);
		slin[slpnt].x=(long)tcor;
		tcor=(hi-(stchs[ind].y-zRct.bottom)*zrat.y+0.5);
		slin[slpnt++].y=(long)tcor;
	}
	Polyline(dc,slin,slpnt);
	SetROP2(dc,R2_COPYPEN);
}

void uncros(){

	if(rstMap(SCROS))
		cros(gpnt0);
	if(rstMap(ECROS)){

		if(gpnt1!=gpnt0)
			cros(gpnt1);
		setMap(ELIN);
	}
}

void ducros(HDC dc){

	uncros();
	setMap(SCROS);
	cros(gpnt0);
	if(gpnt0!=gpnt1){
		
		cros(gpnt1);
		setMap(ECROS);
	}
	selin(gpnt0,gpnt1,dc);
}

void selRct(FLRCT* srct){

	unsigned ind;

	srct->left=srct->right=stchs[gpnt0].x;
	srct->top=srct->bottom=stchs[gpnt0].y;
	for(ind=gpnt0+1;ind<=gpnt1;ind++){

		if(stchs[ind].x>srct->right)
			srct->right=stchs[ind].x;
		if(stchs[ind].x<srct->left)
			srct->left=stchs[ind].x;
		if(stchs[ind].y<srct->bottom)
			srct->bottom=stchs[ind].y;
		if(stchs[ind].y>srct->top)
			srct->top=stchs[ind].y;
	}
	if(srct->right-srct->left==0){

		srct->right++;
		srct->left--;
	}
	if(srct->top-srct->bottom==0){

		srct->top++;
		srct->bottom--;
	}
}

void rngadj(){

	if(cloInd>(unsigned)hed.stchs-1)
		cloInd=hed.stchs-1;
	if(grpInd>hed.stchs)
		grpInd=cloInd;
	if(grpInd>cloInd){

		gpnt0=cloInd;
		gpnt1=grpInd;
	}
	else{

		gpnt0=grpInd;
		gpnt1=cloInd;
	}
}

void lenfn(unsigned strt,unsigned fin){

	unsigned	ind;
	double		maxlen=0;
	double		minlen=1e99;
	double		tdub;
	TCHAR		buf[50];

	minpnt=0;maxpnt=0;
	for(ind=strt;ind<fin;ind++){

		tdub=hypot(stchs[ind+1].x-stchs[ind].x,stchs[ind+1].y-stchs[ind].y);
		if(tdub>maxlen){

			maxlen=tdub;
			maxpnt=ind;
		}
		if(tdub<minlen){

			minlen=tdub;
			minpnt=ind;
		}
	}
	sprintf(buf,"max %.2f",maxlen/PFGRAN);
	butxt(HMAXLEN,buf);
	sprintf(buf,"min %.2f",minlen/PFGRAN);
	butxt(HMINLEN,buf);
}

void frmcalc(){

	unsigned	ind,cod;
	double		maxlen=0;
	double		minlen=1e99;
	double		len;

	if(formlst[clofind].ftyp||formlst[clofind].etyp){

		cod=clofind<<FRMSHFT;
		for(ind=0;ind<(unsigned)hed.stchs-1;ind++){

			if((stchs[ind].at&FRMSK)==cod&&!(stchs[ind].at&NOTFRM)&&(stchs[ind+1].at&FRMSK)==cod&&(stchs[ind+1].at&TYPMSK)){

				len=hypot(stchs[ind+1].x-stchs[ind].x,stchs[ind+1].y-stchs[ind].y);
				if(len>maxlen){

					maxlen=len;
					maxpnt=ind;
				}
				if(len<minlen){

					minlen=len;
					minpnt=ind;
				}
			}
		}
		if(fabs(maxlen<10000)){
		
			sprintf(msgbuf,"max %.2f",maxlen/PFGRAN);
			butxt(HMAXLEN,msgbuf);
		}
		if(fabs(minlen<10000)){

			sprintf(msgbuf,"min %.2f",minlen/PFGRAN);
			butxt(HMINLEN,msgbuf);
		}
	}
	else{

		butxt(HMAXLEN,"");
		butxt(HMINLEN,"");
	}
}

void lenCalc(){

	if(chkMap(LENSRCH)){

		sprintf(msgbuf,"%.2f",hypot(stchs[cloInd+1].x-stchs[cloInd].x,stchs[cloInd+1].y-stchs[cloInd].y)/PFGRAN);
		butxt(HMINLEN,msgbuf);
		msgstr(IDS_SRCH);
		butxt(HMAXLEN,msgbuf);
	}
	else{

		if(hed.stchs>1){

			if(chkMap(FORMSEL)){

				frmcalc();
				butxt(HCOR,"");
				return;
			}
			rngadj();
			if(chkMap(GRPSEL)&&gpnt0!=gpnt1)
				lenfn(gpnt0,gpnt1);
			else
				lenfn(0,hed.stchs-1);
		}
		else{

			butxt(HMAXLEN,"");
			butxt(HMINLEN,"");
		}
	}
}

void nuselrct(){

	FLPNT		rlin[9];
	unsigned	ind;

	unsel();
	rlin[0].x=rlin[6].x=rlin[7].x=rlin[8].x=rngrct.left;
	rlin[1].x=rlin[5].x=midl(rngrct.right,rngrct.left);
	rlin[0].y=rlin[1].y=rlin[2].y=rlin[8].y=rngrct.top;
	rlin[3].y=rlin[7].y=midl(rngrct.top,rngrct.bottom);
	rlin[4].y=rlin[5].y=rlin[6].y=rngrct.bottom;
	rlin[2].x=rlin[3].x=rlin[4].x=rngrct.right;
	for(ind=0;ind<9;ind++)
		sfCor2px(rlin[ind],&rctlin[ind]);
}

void grpAdj(){

	POINT		nusiz;
	double		tdub;

	uncros();
	unsel();
	rngadj();
	ducros(rsdc);
	lenCalc();
	selRct(&rngrct);
	if(chkMap(ZUMED)&&gpnt1!=gpnt0){

		if(rngrct.top>zRct.top-1||rngrct.bottom<zRct.bottom-1
			||rngrct.left<zRct.left+1||rngrct.right>zRct.right-1){

			nusiz.x=rngrct.right-rngrct.left;
			nusiz.y=rngrct.top-rngrct.bottom;
			if(nusiz.x<MINZUM){

				if(nusiz.x<TINY)
					nusiz.x=1;
				tdub=MINZUM/nusiz.x;
				nusiz.x=MINZUM;
				nusiz.y=tdub*nusiz.y;
			}
			if(nusiz.x>nusiz.y){

				tdub=nusiz.x*ZMARGIN;
				nusiz.x+=(long)tdub;
				tdub=nusiz.x/stchAspct;
				nusiz.y=(long)tdub;
			}
			else{

				tdub=nusiz.y*ZMARGIN;
				nusiz.y=(long)tdub;
				tdub=nusiz.y*stchAspct;
				nusiz.x=(long)tdub;
			}
			if(nusiz.x>zum0.x||nusiz.y>zum0.y){
				
				zRct.left=zRct.bottom=0;
				zRct.right=zum0.x;
				zRct.top=zum0.y;
				rstMap(ZUMED);
				zumFct=1;
				movStch();
			}
			else{
			
				zRct.right=zRct.left+(nusiz.x);
				zumFct=(double)nusiz.x/zum0.x;
				zRct.top=zRct.bottom+(nusiz.y);
				sPnt.x=((rngrct.right-rngrct.left)/2)+rngrct.left;
				sPnt.y=((rngrct.top-rngrct.bottom)/2)+rngrct.bottom;
				shft(sPnt);
			}
		}
	}
	setMap(RESTCH);
}

void lensadj(){

	uncros();
	unsel();
	cloInd=srchpnt;
	grpInd=srchpnt+1;
	rngadj();
	ducros(rsdc);
	lenCalc();
	selRct(&rngrct);
	if(rngrct.top>zRct.top-1||rngrct.bottom<zRct.bottom-1
		||rngrct.left<zRct.left+1||rngrct.right>zRct.right-1){

		sPnt.x=((rngrct.right-rngrct.left)/2)+rngrct.left;
		sPnt.y=((rngrct.top-rngrct.bottom)/2)+rngrct.bottom;
		shft(sPnt);
	}
	nuAct(gpnt0);
	setMap(RESTCH);
}

void ritot(unsigned num){

	TCHAR buf[64];

	sprintf(buf,stab[STR_TOT],num);
	stchdigs=strlen(buf);
	butxt(HTOT,buf);
}

void ritlayr(){

	TCHAR buf[12];
	unsigned layr;

	layr=0xffffffff;
	if(chkMap(SELBOX))
		layr=(stchs[cloInd].at&LAYMSK)>>LAYSHFT;
	else{

		if(chkMap(FORMSEL)||chkMap(FRMPSEL))
			layr=(formlst[clofind].at&FRMLMSK)>>1;
	}
	if(layr&0xffff0000)
		butxt(HLAYR,"");
	else{

		sprintf(buf,stab[STR_LAYR],layr);
		stchdigs=strlen(buf);
		butxt(HLAYR,buf);
	}
}

void nuRct(){

	GetClientRect(hWnd,&mRct);
	GetWindowRect(hBar,&bRct);
	GetClientRect(hBar,&bcRct);
	GetWindowRect(hbuts[HMINLEN],&minLenRct);
	GetWindowRect(hbuts[HMAXLEN],&maxLenRct);
	ReleaseDC(hBar,bdc);
	bdc=GetDC(hBar);
	DeleteDC(sdc);
	ReleaseDC(hStch,rsdc);
	DeleteObject(sbmp);
	ReleaseDC(hStch,rsdc);
	rsdc=GetDCEx(hStch,0,DCX_PARENTCLIP|DCX_CLIPSIBLINGS);
	DeleteDC(sdc);
	sdc=CreateCompatibleDC(rsdc);
	GetDCOrgEx(rsdc,&stOrg);
	ReleaseDC(hWnd,mdc);
	mdc=GetDC(hWnd);
	SetStretchBltMode(mdc,COLORONCOLOR);
	GetDCOrgEx(mdc,&morg);
	GetWindowRect(hStch,&sRct);
	GetClientRect(hStch,&scRct);
	sbmp=CreateCompatibleBitmap(rsdc,scRct.right,scRct.bottom);
	SelectObject(sdc,sbmp);
}

HPEN nuPen(HPEN pen,unsigned wid,COLORREF col){

	DeleteObject(pen);
	return CreatePen(PS_SOLID,wid,col);
}

void nuStchSiz(unsigned ind, unsigned wid){

	if(wid!=pixSiz[ind]){

		uPen[ind]=nuPen(uPen[ind],wid,useCol[ind]);
		pixSiz[ind]=wid;
	}
}

HBRUSH nuBrush(HBRUSH brsh,COLORREF col){

	DeleteObject(brsh);
	return CreateSolidBrush(col);
}

void box(unsigned ind,HDC dc){

	long pwid=boxOff[ind];
	POINT lin[5];

	lin[0].x=pxNer[ind].x-pwid;
	lin[0].y=pxNer[ind].y-pwid;
	lin[1].x=pxNer[ind].x+pwid;
	lin[1].y=pxNer[ind].y-pwid;
	lin[2].x=pxNer[ind].x+pwid;
	lin[2].y=pxNer[ind].y+pwid;
	lin[3].x=pxNer[ind].x-pwid;
	lin[3].y=pxNer[ind].y+pwid;
	lin[4].x=pxNer[ind].x-pwid;
	lin[4].y=pxNer[ind].y-pwid;
	Polyline(dc,lin,5);
}

void boxs(){

	unsigned	ind;

	SetROP2(rsdc,R2_NOTXORPEN); 
	for(ind=0;ind<selCnt;ind++){

		SelectObject(rsdc,bPen[ind]);
		box(ind,rsdc);
	}
	SetROP2(rsdc,R2_COPYPEN);
}

void dubx(){

	POINT lin[5];
	long pwid=boxOff[0];

	SelectObject(sdc,bPen[0]);
	SelectObject(rsdc,bPen[0]);
	SetROP2(sdc,R2_NOTXORPEN); 
	SetROP2(rsdc,R2_NOTXORPEN); 
	lin[0].x=boxPix.x-pwid;
	lin[0].y=boxPix.y-pwid;
	lin[1].x=boxPix.x+pwid;
	lin[1].y=boxPix.y-pwid;
	lin[2].x=boxPix.x+pwid;
	lin[2].y=boxPix.y+pwid;
	lin[3].x=boxPix.x-pwid;
	lin[3].y=boxPix.y+pwid;
	lin[4].x=boxPix.x-pwid;
	lin[4].y=boxPix.y-pwid;
	Polyline(sdc,lin,5);
	Polyline(rsdc,lin,5);
	SetROP2(sdc,R2_COPYPEN);
	SetROP2(rsdc,R2_COPYPEN);
}

void duar(){

	POINT rpnt;

	stchar[1].x=pPnt.x;
	stchar[1].y=pPnt.y;
	pixcntr.x=pPnt.x;
	pixcntr.y=pPnt.y;
	rpnt.x=pPnt.x-10;
	rpnt.y=pPnt.y+10;
	rotpix(rpnt,&stchar[0]);
	rpnt.y=pPnt.y-10;
	rotpix(rpnt,&stchar[2]);
	SelectObject(sdc,bPen[0]);
	SelectObject(rsdc,bPen[0]);
	SetROP2(sdc,R2_NOTXORPEN); 
	SetROP2(rsdc,R2_NOTXORPEN); 
	Polyline(sdc,stchar,3);
	Polyline(rsdc,stchar,3);
	SetROP2(sdc,R2_COPYPEN);
	SetROP2(rsdc,R2_COPYPEN);
}

void dubox(){

	pixang=atan2(stchs[cloInd+1].y-stchs[cloInd].y,stchs[cloInd+1].x-stchs[cloInd].x);
	duar();
	rstMap(ELIN);
	setMap(SELBOX);
	rstMap(FRMPSEL);
	redraw(hBar);
	if(!numpnt)
		ritnum(STR_NUMSEL,cloInd);
}

void unbox(){

	if(rstMap(SELBOX)){

		SelectObject(rsdc,bPen[0]);
		SetROP2(rsdc,R2_NOTXORPEN); 
		Polyline(rsdc,stchar,3);
		SetROP2(rsdc,R2_COPYPEN);
	}
}

void unboxs(){

	if(selCnt){

		boxs();
		selCnt=0;
	}
}

void redraw(HWND dWnd){

	unsigned ind;

	RedrawWindow(dWnd,NULL,NULL,RDW_INVALIDATE);
	if(dWnd==hStch){

		for(ind=0;ind<16;ind++){

			if(hDef[ind])
				RedrawWindow(hDef[ind],NULL,NULL,RDW_INVALIDATE);
		}
		RedrawWindow(hBar,NULL,NULL,RDW_INVALIDATE);
	}
}

unsigned stch2px(unsigned stind){

#pragma warning(disable:4244;once:)
	pPnt.x=(stchs[stind].x-zRct.left)*zrat.x+0.5;
#pragma warning(disable:4244;once:)
	pPnt.y=scRct.bottom-(stchs[stind].y-zRct.bottom)*zrat.y+0.5;
	if(	pPnt.x>=0&&
		pPnt.x<=scRct.right&&
		pPnt.y>=0&&
		pPnt.y<=scRct.bottom)

		return 1;
	else
		return 0;
}

void stch2px1(unsigned stind){

#pragma warning(disable:4244;once:)		
	pPnt.x=(stchs[stind].x-zRct.left)*zrat.x+0.5;
#pragma warning(disable:4244;once:)
	pPnt.y=scRct.bottom-(stchs[stind].y-zRct.bottom)*zrat.y+0.5;
}

void stch2pxr(FLPNT stpnt){

#pragma warning(disable:4244;once:)		
	pPnt.x=(stpnt.x-zRct.left)*zrat.x+0.5;
#pragma warning(disable:4244;once:)
	pPnt.y=scRct.bottom-(stpnt.y-zRct.bottom)*zrat.y+0.5;
}

void movins(){

	if(chkMap(INSRT)){

		if(chkMap(LIN1)){

			if(chkMap(BAKEND))
				stch2px1(hed.stchs-1);
			else
				stch2px1(0);
			endpnt();
		}
		else
			duIns();
	}
}

void defNam(TCHAR* fNam){

	TCHAR* last;

	if(fNam[0]){

		strcpy(defDir,fNam);
		last=strrchr(defDir,'\\');
		if(last-defDir==2)
			last[1]=0;
		else
			last[0]=0;
	}
}

void defbNam(){

	TCHAR* last;

	if(lbnam[0]){

		strcpy(defbmp,lbnam);
		last=strrchr(defbmp,'\\');
		if(last-defbmp==2)
			last[1]=0;
		else
			last[0]=0;
	}
}

void ritini(){

	unsigned	ind;
	RECT		wrct;

	strcpy(ini.defDir,defDir);
	for(ind=0;ind<16;ind++){

		ini.stchCols[ind]=	useCol[ind];
		ini.bakCol[ind]=	bakCust[ind];
		ini.selStch[ind]=	custCol[ind];
		ini.bakBit[ind]=	bakBit[ind];
	}
	ini.stchBak=stchBak;
	ini.bitCol=bitCol;
	ini.minsiz=minsiz;
	ini.shopnts=shopnts;
	ini.tsiz30=tsiz30;
	ini.tsiz40=tsiz40;
	ini.tsiz60=tsiz60;
	ini.usesiz=usesiz;
	ini.smalsiz=smalsiz;
	ini.stchboxs=stchboxs;
	ini.stspace=stspace;
	ini.umap=umap;
	ini.brdwid=brdwid;
	ini.apcol=apcol;
	ini.snplen=snplen;
	ini.starat=starat;
	ini.spirwrap=spirwrap;
	ini.bfclen=bfclen;
	ini.picspac=picspac;
	if(!chku(SAVMAX)){

		GetWindowRect(hWnd,&wrct);
		ini.irct.left=wrct.left;
		ini.irct.right=wrct.right;
		ini.irct.bottom=wrct.bottom;
		ini.irct.top=wrct.top;
	}
	hIni=CreateFile(iniNam,(GENERIC_WRITE|GENERIC_READ),0,NULL,
		CREATE_ALWAYS,0,NULL);
	if(hIni!=INVALID_HANDLE_VALUE)
		WriteFile(hIni,&ini,sizeof(INIFIL),&red,NULL);
	CloseHandle(hIni);
}

BOOL gcmp(void* pnt,unsigned cnt){
	return memcmp(bseq, pnt, cnt * 4) == 0 ? 0 : 1;
}

BOOL gcmpw(short wrd,unsigned ofst){
	char *ptr = ((char *) bseq) + ofst;
	return (*(short *)ptr == wrd) ? 0 : 1;
}

BOOL bufcmp(TCHAR* tbuf,unsigned siz){
	return memcpy(bseq, tbuf, siz) != 0 ? 1 : 0;
}

BOOL savcmp(){

#ifdef _DEBUG

	return 1;

#else

	return !chkMap(CMPDO);

#endif
}

void thr2bal(unsigned dst,unsigned src,unsigned cod){

#define BALRAT 1.6666666666667

	pbal[dst].flg=0;
	pbal[dst].cod=(unsigned char)cod;
	pbal[dst].x=(stchs[src].x-balof.x)*BALRAT;
	pbal[dst].y=(stchs[src].y-balof.y)*BALRAT;
}

unsigned coldis(COLORREF acol,COLORREF bcol){

	unsigned dis;

	dis=abs((acol&0xff)-(bcol&0xff));
	acol>>=8;
	bcol>>=8;
	dis+=abs((acol&0xff)-(bcol&0xff));
	acol>>=8;
	bcol>>=8;
	dis+=abs((acol&0xff)-(bcol&0xff));
	return dis;
}

void bal2thr(unsigned dst,unsigned src,unsigned cod){

#define IBALRAT 0.6

	stchs[dst].at=cod;
	stchs[dst].x=pbal[src].x*IBALRAT+balof.x;
	stchs[dst].y=pbal[src].y*IBALRAT+balof.y;
}

unsigned colmatch(COLORREF col){

	unsigned ind,dis,mindis,pdis;

	if(colCnt<16){

		for(ind=0;ind<colCnt;ind++){

			if(col==useCol[ind])
				return ind;
		}
		useCol[colCnt++]=col;
		return colCnt-1;
	}
	else{

		mindis=0xffffffff;
		for(ind=0;ind<colCnt;ind++){

			dis=coldis(col,useCol[ind]);
			if(!dis)
				return ind;
			pdis=0;
			if(dis<mindis){

				pdis=ind;
				mindis=dis;
			}
		}
		return pdis;
	}
}

void redbal(){

	HANDLE			btfil;
	BALHED			bhed;
	unsigned int 	red;
	unsigned		ind,ine,bcnt,pbcol,col;

	hed.stchs=0;
	formpnt=0;
	btfil=CreateFile(balnam2,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
	if(btfil!=INVALID_HANDLE_VALUE){

		ReadFile(btfil,(BALHED*)&bhed,sizeof(BALHED),&red,0);
		if(red==sizeof(BALHED)){

			pbal=(BALSTCH*)&bseq;
			ReadFile(btfil,(BALSTCH*)pbal,sizeof(bseq),&red,0);
			bcnt=red/sizeof(BALSTCH);
			ini.stchBak=stchBak=bhed.bcol;
			bakPen=nuPen(bakPen,1,stchBak);
			bakwid=1;
			DeleteObject(hStchBak);
			hStchBak=CreateSolidBrush(stchBak);
			zum0.x=ini.hupx=bhed.xhup*IBALRAT;
			zum0.y=ini.hupy=bhed.yhup*IBALRAT;
			balof.x=ini.hupx/2;
			balof.y=ini.hupy/2;
			ini.hup=hed.hup=CUSTHUP;
			useCol[0]=bhed.col[0];
			col=0;
			pbcol=1;
			ine=0;
			colCnt=1;
			for(ind=0;ind<bcnt;ind++){

				switch(pbal[ind].cod){

				case BALNORM:

					bal2thr(ine++,ind,col);	
					break;

				case BALSTOP:

					col=colmatch(bhed.col[pbcol++]);
					break;
				}
			}
			for(ind=0;ind<colCnt;ind++){

				uPen[ind]=CreatePen(PS_SOLID,1,useCol[ind]);
				hbrUseCol[ind]=nuBrush(hbrUseCol[ind],useCol[ind]);
			}
			hed.stchs=ine;
			coltab();
			redraw(hBar);
			setMap(INIT);
			setMap(RESTCH);
		}
	}
	CloseHandle(btfil);
}

void ritbal(){

	BALHED			bhed;
	unsigned*		phed;
	unsigned		ind,ine,col;
	HANDLE			bfil;
	TCHAR*			pbchr;
	TCHAR			onam[MAX_PATH];
	unsigned int	wrot;

	if(*balnam0&&*balnam1&&hed.stchs){

		if(!*filnam){

			strcpy(filnam,defDir);
			strcat(filnam,"\\balfil.thr");
		}
		strcpy(onam,filnam);
		pbchr=strrchr(onam,'.');
		if(pbchr)
			strcpy(pbchr,".thv");
		else
			strcat(pbchr,".thv");
		bfil=CreateFile(onam,GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
		if(bfil==INVALID_HANDLE_VALUE)
			return;
		phed=(unsigned*)&bhed;
		for(ind=0;ind<(sizeof(BALHED)>>2);ind++)
			phed[ind]=0;
		col=stchs[0].at&COLMSK;
		bhed.col[0]=useCol[col];
		ine=1;
		for(ind=1;ind<hed.stchs;ind++){

			if(col!=(stchs[ind].at&COLMSK)){

				col=stchs[ind].at&COLMSK;
				bhed.col[ine++]=useCol[col];
				if(ine&0xffffff00)
					break;
			}
		}
		bhed.sig='drbm';
		bhed.bcol=stchBak;
		bhed.xhup=ini.hupx*BALRAT;
		bhed.yhup=ini.hupy*BALRAT;
		WriteFile(bfil,(BALHED*)&bhed,sizeof(BALHED),&wrot,0);
		balof.x=ini.hupx/2;
		balof.y=ini.hupy/2;
		pbal=(BALSTCH*)&bseq;
		col=stchs[0].at&COLMSK;
		thr2bal(0,0,BALJUMP);
		pbal[1].flg=(unsigned char)col;
		ine=1;
		for(ind=0;ind<hed.stchs;ind++){

			thr2bal(ine++,ind,BALNORM);
			if((stchs[ind].at&COLMSK)!=col){

				thr2bal(ine,ind,BALSTOP);
				col=stchs[ind].at&COLMSK;
				pbal[ine++].flg=(unsigned char)col;
			}
		}
		WriteFile(bfil,(BALSTCH*)pbal,ine*sizeof(BALSTCH),&wrot,0);
		CloseHandle(bfil);
		bfil=CreateFile(balnam1,GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
		WriteFile(bfil,(TCHAR*)onam,strlen(onam)+1,&wrot,0);
		CloseHandle(bfil);
	}
	else{

		if(*balnam1){

			bfil=CreateFile(balnam1,GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
			CloseHandle(bfil);
		}
	}
	if(*balnam0)
		DeleteFile(balnam0);
}

void savmsg(){

	TCHAR	buf[HBUFSIZ];

	LoadString(hInst,IDS_SAVFIL,buf,HBUFSIZ);
	sprintf(msgbuf,buf,thrnam);
}

void reldun()
{
	txdun();
	ritbal();
	ritini();
	dstcurs();
	PostQuitMessage(0);
}

void dun(){

	savtxt();
	txof();
	rstxt();
	if(rstMap(PRFACT)){

		DestroyWindow(hPrf);
		rstMap(WASRT);
	}
	unsid();
	unbsho();
	rstAll();
//	if(savcmp()||(*balnam0&&*balnam1&&hed.stchs&&!formpnt))
	if(savcmp()||(*balnam0))
		reldun();
	else{

		if(scRct.right){

			savdisc();
			setMap(SAVEX);
		}
		else{

			savmsg();
			if(MessageBox(hWnd,msgbuf,stab[STR_CLOS],MB_YESNO)==IDYES)
				save();
			reldun();;
		}
	}
}

void dusid(unsigned str){

	hsidWnd[str]=CreateWindow(
		"STATIC",
		sidstr[str],
		SS_NOTIFY|WS_CHILD|WS_VISIBLE|WS_BORDER,
		3,
		sidloc*sidsiz.y+3,
		sidsiz.x+3,
		sidsiz.y,
		hSid,
		NULL,
		hInst,
		NULL);
	sidloc++;
}

void sidmsg(HWND hndl,TCHAR** pstr,unsigned cnt){

	RECT		chkrct;
	RECT		mrct;
	unsigned	ind,ine=0,cnt1=cnt;

	FillMemory(&thDat,sizeof(int)*LASTLIN,0);
	sidsiz.x=sidsiz.y=0;
	sidloc=0;
	sidstr=pstr;
	GetWindowRect(hndl,&chkrct);
	GetWindowRect(hfdat,&mrct);
	ispcdclp();
 	if(chkMap(FILTYP)){

		for(ind=0;ind<EDGETYPS+1;ind++){

			if((unsigned)(frmpnt->etyp&NEGUND)==egtyps[ind])
				cnt1--;
			else{

				if(egtyps[ind]==EGCLP||egtyps[ind]==EGPIC||egtyps[ind]==EGCLPX){

					if(chkMap(WASPCDCLP))
						maxtsiz(pstr[ind],&sidsiz);
					else
						cnt1--;
				}
				else
					maxtsiz(pstr[ind],&sidsiz);
			}
		}
		hSid=CreateWindow(
			"STATIC",
			0,
			WS_BORDER|WS_CHILD|WS_VISIBLE,
			mrct.right-morg.x+3,
			chkrct.top-morg.y-3,
			sidsiz.x+12,
			sidsiz.y*cnt1+12,
			hWnd,
			NULL,
			hInst,
			NULL);
		for(ind=0;ind<cnt;ind++){

			if((unsigned)(frmpnt->etyp&NEGUND)!=egtyps[ind]){
		
				if(egtyps[ind]==EGCLP||egtyps[ind]==EGPIC||egtyps[ind]==EGCLPX){

					if(chkMap(WASPCDCLP))
						dusid(ind);
				}
				else
					dusid(ind);
			}
		}
	}
	else{

		if(sidtyp==LLAYR)
			maxtsiz("0",&sidsiz);
		else{

			if(sidtyp==LFTHTYP){

				cnt1=5;
				sidsiz.x=buttonWid3;
				sidsiz.y=buttonHi;
			}
			else{

				for(ind=0;ind<cnt;ind++){

					if((1<<filtyps[ind])&clpmap){

						if(chkMap(WASPCDCLP))
							maxtsiz(pstr[ind],&sidsiz);
						else
							cnt1--;
					}
					else{

						if(filtyps[ind]==frmpnt->ftyp)
							cnt1--;
						else
							maxtsiz(pstr[ind],&sidsiz);
					}
				}
			}
		}
		hSid=CreateWindow(
			"STATIC",
			0,
			WS_BORDER|WS_CHILD|WS_VISIBLE,
			mrct.right-morg.x+3,
			chkrct.top-morg.y-3,
			sidsiz.x+12,
			sidsiz.y*cnt1+12,
			hWnd,
			NULL,
			hInst,
			NULL);
		if(sidtyp==LLAYR){

			for(ind=0;ind<cnt;ind++)
				dusid(ind);
		}
		else{

			if(sidtyp==LFTHTYP){

				for(ind=0;ind<6;ind++){

					if(fthtyps[ind]!=frmpnt->dhx.fth.fthtyp)
						dusid(ind);
				}
			}
			else{

				for(ind=0;ind<cnt;ind++){

					if(filtyps[ind]!=frmpnt->ftyp){

						if((1<<filtyps[ind])&clpmap){

							if(chkMap(WASPCDCLP))
								dusid(ind);
						}
						else
							dusid(ind);
					}
				}
			}
		}
	}
	setMap(SIDACT);
}


void stchPars(){

	aspct=(double)zum0.x/zum0.y;
#pragma warning(disable:4244;once:)
	if(chkMap(RUNPAT)||chkMap(WASPAT))
		stchSiz.x=(long)(mRct.bottom-(SCROLSIZ<<1))*aspct;
	else
		stchSiz.x=(long)(mRct.bottom-SCROLSIZ)*aspct;

	if((stchSiz.x+(long)buttonWid3+RIGHTSIZ)<mRct.right){
		
		if(chkMap(RUNPAT)||chkMap(WASPAT))
			stchSiz.y=mRct.bottom-(SCROLSIZ<<1);
		else
			stchSiz.y=mRct.bottom-SCROLSIZ;
	}
	else{

#pragma warning(disable:4244;once:)
		stchSiz.x=(mRct.right-buttonWid3-COLSIZ);
		stchSiz.y=mRct.bottom-mRct.top;
		if((double)stchSiz.x/stchSiz.y>aspct)
			stchSiz.x=stchSiz.y*aspct;
		else
			stchSiz.y=stchSiz.x/aspct;
	}
}

void movStch(){

	POINT		psiz;
	long		vof=0;
	long		tstchy=stchSiz.y;

	psiz.x=mRct.right-buttonWid3-RIGHTSIZ;
	psiz.y=mRct.bottom;
	unboxs();
	if(chkMap(RUNPAT)||chkMap(WASPAT)){

		vof=SCROLSIZ;
		psiz.y-=SCROLSIZ;
		tstchy-=SCROLSIZ;
	}
	if(chkMap(ZUMED)){

		psiz.y-=SCROLSIZ;
		MoveWindow(hStch,buttonWid3,vof,psiz.x,psiz.y,FALSE);
		MoveWindow(hVrt,buttonWid3+psiz.x,0,SCROLSIZ,psiz.y,TRUE);
		MoveWindow(hHor,buttonWid3,psiz.y+vof,psiz.x,SCROLSIZ,TRUE);
		stchAspct=(double)psiz.x/psiz.y;
		if(chkMap(RUNPAT)||chkMap(WASPAT))
			MoveWindow(hSped,buttonWid3,0,psiz.x,SCROLSIZ,TRUE);
		ShowWindow(hVrt,TRUE);
		ShowWindow(hHor,TRUE);
	}
	else{

		stchPars();
		tstchy=stchSiz.y+SCROLSIZ;
		MoveWindow(hStch,buttonWid3,vof,stchSiz.x,tstchy,TRUE);
		ShowWindow(hVrt,FALSE);
		ShowWindow(hHor,FALSE);
		stchAspct=(double)stchSiz.x/tstchy;
		if(chkMap(RUNPAT)||chkMap(WASPAT))
			MoveWindow(hSped,buttonWid3,0,stchSiz.x,SCROLSIZ,TRUE);
	}
	MoveWindow(hBar,mRct.right-COLSIZ,0,COLSIZ,mRct.bottom,TRUE);
	nuRct();
	redraw(hBar);
}

void zRctAdj(){

	double	tdub;

	if(zRct.top>zum0.y){

		tdub=zRct.top-zum0.y;
		zRct.top-=tdub;
		zRct.bottom-=tdub;
	}
	if(zRct.bottom<0){

		zRct.top-=zRct.bottom;
		zRct.bottom=0;
	}
	if(zRct.right>zum0.x){

		tdub=zRct.right-zum0.x;
		zRct.right-=tdub;
		zRct.left-=tdub;
	}
	if(zRct.left<0){
	
		zRct.right-=zRct.left;
		zRct.left=0;
	}
}

void shft(FLPNT shPnt){

	DUBPNT	tsiz;
	DUBPNT	centr;
	DUBPNT	mov;

	tsiz.x=zRct.right-zRct.left;
	tsiz.y=zRct.top-zRct.bottom;
	tsiz.x/=2;
	tsiz.y/=2;
	centr.x=zRct.left+tsiz.x;
	centr.y=zRct.bottom+tsiz.y;
	mov.x=centr.x-shPnt.x;
	mov.y=centr.y-shPnt.y;
	
	zRct.bottom-=mov.y;
	zRct.top-=mov.y;
	zRct.left-=mov.x;
	zRct.right-=mov.x;

	zRctAdj();
}

void centr(){

	POINT siz;

	siz.x=zRct.top-zRct.bottom;
	siz.y=zRct.right-zRct.left;
	siz.x>>=1;
	siz.y>>=1;
	sPnt.x=zRct.left+siz.x;
	sPnt.y=zRct.bottom+siz.y;
}

double pxchk(double dub){

	if(dub<0.2)
		return 1;
	if(dub>20)
		return 20;
	return dub;
}

void chknum(){

	double		tdub;
	unsigned	tuns;

	clrstch();
	tdub=atof(msgbuf);
	if(rstMap(ENTRDUP)){

		if(tdub){

			ang=tdub*PI/180;
			ini.rotang=ang;
		}
		else
			ang=ini.rotang;
		duprot();
		return;
	}
	if(rstMap(NUROT)){

		if(tdub){

			ang=tdub*PI/180;
			ini.rotang=ang;
		}
		else
			ang=ini.rotang;
		return;
	}
	if(rstMap(ENTRSEG)){

		if(tdub){

			ang=2*PI/tdub;
			ini.rotang=ang;
		}
		else
			ang=ini.rotang;
		return;
	}
	if(rstMap(ENTROT)){

		if(tdub){

			ang=tdub*PI/180;
			ini.rotang=ang;
		}
		else
			ang=ini.rotang;
		rotfns();
		return;
	}
	if(msgpnt)
	{
		if(sidtyp){

			tdub=atof(sidbuf)*PFGRAN;
			switch(sidtyp){

			case LTXOF:

				savdo();
				frmpnt->txof=tdub;
				break;

			case LUANG:

				savdo();
				frmpnt->uang=tdub/180*PI/PFGRAN;
				break;

			case LUSPAC:

				savdo();
				frmpnt->uspac=tdub;
				break;

			case LWLKIND:

				savdo();
				frmpnt->wind=tdub;
				break;

			case LULEN:

				savdo();
				frmpnt->ulen=tdub;
				break;

			case LDSTRT:

				savdo();
				frmpnt->strt=tdub/PFGRAN;
				frmpnt->strt%=sids;
				break;

			case LDEND:

				savdo();
				frmpnt->end=tdub/PFGRAN;
				frmpnt->end%=sids;
				break;

			case LFTHUPCNT:

				savdo();
				tdub/=PFGRAN;
				if(tdub>255)
					tdub=255;
				frmpnt->dhx.fth.fthup=tdub;
				break;

			case LFTHCOL:

				if(tdub){

					savdo();
					nufthcol((atoi(sidbuf)-1)&0xf);
					SetWindowText(thDat[LFRMCOL],sidbuf);
					coltab();
				}
				unsid();
				setMap(RESTCH);
				return;

			case LFRMCOL:

				if(tdub){

					savdo();
					nufilcol((atoi(sidbuf)-1)&0xf);
					SetWindowText(thDat[LFRMCOL],sidbuf);
					coltab();
				}
				unsid();
				setMap(RESTCH);
				return;

			case LUNDCOL:

				if(tdub){

					savdo();
					frmpnt->ucol=(atoi(sidbuf)-1)&0xf;
					SetWindowText(thDat[LUNDCOL],sidbuf);
					refilfn();
					coltab();
				}
				unsid();
				setMap(RESTCH);
				return;

			case LBRDCOL:

				if(tdub){

					savdo();
					nubrdcol((atoi(sidbuf)-1)&0xf);
					SetWindowText(thDat[LFRMCOL],sidbuf);
					coltab();
				}
				unsid();
				setMap(RESTCH);
				return;

			case LBRDPIC:

				savdo();
				frmpnt->espac=tdub;
				refil();
/*
				oclp(frmpnt->clp,frmpnt->nclp);
				clpic(getlast());
				unsid();
				ritbrd();
				coltab();
				setMap(RESTCH);*/
				return;

			case LFRMFAZ:

				savdo();
				frmpnt->wpar=floor(tdub)/PFGRAN;
				unsid();
				refil();
				return;

			case LBRDPOS:

				savdo();
				frmpnt->elen=tdub/PFGRAN;
				unsid();
				refil();
				return;

			case LMAXFIL:

				savdo();
				frmpnt->fmax=tdub;
				unsid();
				refil();
				return;

			case LMINFIL:

				savdo();
				frmpnt->fmin=tdub;
				unsid();
				refil();
				return;

			case LMAXBRD:

				savdo();
				frmpnt->emax=tdub;
				unsid();
				refil();
				return;

			case LMINBRD:

				savdo();
				frmpnt->emin=tdub;
				unsid();
				refil();
				return;
			}
			if(sidtyp==LBCSIZ){

				savdo();
				if(frmpnt->etyp==EGHOL)
					savblen((float)tdub);
				else
					savplen((float)tdub);
			}
			else{

				if(tdub){

					switch(sidtyp){

					case LFTHSIZ:

						savdo();
						frmpnt->dhx.fth.fthrat=tdub/PFGRAN;
						break;

					case LFTHNUM:

						savdo();
						frmpnt->dhx.fth.fthnum=tdub/PFGRAN;
						break;

					case LFTHFLR:

						savdo();
						frmpnt->dhx.fth.fthflr=tdub;
						break;

					case LFTHDWNCNT:

						savdo();
						tdub/=PFGRAN;
						if(tdub>255)
							tdub=255;
						frmpnt->dhx.fth.fthdwn=tdub;
						break;

					case LFRMSPAC:

						savdo();
						frmpnt->fspac=tdub;
						break;

					case LFRMLEN:

						savdo();
						frmpnt->flencnt.flen=tdub;
						break;

					case LBRDSPAC:

						savdo();
						tuns=frmpnt->etyp&NEGUND;
						switch(tuns){

						case EGPRP:

							frmpnt->espac=tdub;
							break;

						case EGCHNH:
						case EGCHNL:

							frmpnt->espac=tdub;
							break;

						default:

							frmpnt->espac=tdub/2;
						}
						break;

					case LBRDLEN:

						savdo();
						frmpnt->elen=tdub;
						break;

					case LBRDSIZ:

						savdo();
						frmpnt->esiz=tdub;
						break;

					case LFRMANG:

						savdo();
						frmpnt->angclp.fang=tdub/180*PI/PFGRAN;
						break;

					case LSACANG:

						savdo();
						frmpnt->sacang.ang=tdub/180*PI/PFGRAN;
						break;

					case LAPCOL:

						savdo();
						frmpnt->bcol&=0xf;
						tuns=tdub/6;
						if(tuns)
							tuns--;
						tuns&=0xf;
						frmpnt->bcol|=(tuns<<4);
						break;
					}
				}
				else{

					savdo();
					if(sidtyp==LFRMSPAC&&isfclp())
						frmpnt->fspac=0;
				}
			}
			unsid();
			refil();
		}
		else{

			if(prfind){

				tdub=atof(sidbuf);
				switch(prfind-1){

				case PEG:

					ini.egrat=tdub;
					sprintf(msgbuf,"%.2f",tdub);
					SetWindowText(thDat[PEG],msgbuf);
					break;

				case PNUDG:

					ini.nudg=tdub;
					ini.nudgpix=pxchk(tdub);
					sprintf(msgbuf,"%.2f",tdub);
					SetWindowText(thDat[PNUDG],msgbuf);
					break;

				case PPIC:

					picspac=tdub*PFGRAN;
					sprintf(msgbuf,"%.2f",tdub);
					SetWindowText(thDat[PPIC],msgbuf);
					break;

				case PCLPOF:

					ini.clpof=tdub*PFGRAN;
					sprintf(msgbuf,"%.2f mm",tdub);
					SetWindowText(thDat[PCLPOF],msgbuf);
					break;

				case PFAZ:

					ini.faz=floor(tdub);
					sprintf(msgbuf,"%d",ini.faz);
					SetWindowText(thDat[PFAZ],msgbuf);
					break;

				case PCHRAT:

					ini.chrat=tdub;
					sprintf(msgbuf,"%.2f",ini.chrat);
					SetWindowText(thDat[PCHRAT],msgbuf);
					break;

				case PMIN:

					minsiz=tdub*PFGRAN;
					sprintf(msgbuf,"%.2f",tdub);
					SetWindowText(thDat[PMIN],msgbuf);
					break;

				default:

					if(tdub){

						sprintf(msgbuf,"%.2f",tdub);
						switch(prfind-1){

						case PSPAC:

							stspace=tdub*PFGRAN;
							SetWindowText(thDat[PSPAC],msgbuf);
							break;

						case PANGL:

							ini.angl=tdub/180*PI;
							SetWindowText(thDat[PANGL],msgbuf);
							break;

						case PSAT:

							brdwid=tdub*PFGRAN;
							ini.brdwid=brdwid;
							SetWindowText(thDat[PSAT],msgbuf);
							break;

						case PMAX:

							ini.maxsiz=tdub*PFGRAN;
							SetWindowText(thDat[PMAX],msgbuf);
							break;

						case PUSE:

							usesiz=tdub*PFGRAN;
							SetWindowText(thDat[PUSE],msgbuf);
							break;

						case PSMAL:

							smalsiz=tdub*PFGRAN;
							SetWindowText(thDat[PSMAL],msgbuf);
							break;

						case PAP:

							apcol=(unsigned)(tdub-1)%16;
							sprintf(msgbuf,"%d",apcol+1);
							SetWindowText(thDat[PAP],msgbuf);
							break;

						case PSNP:

							snplen=tdub*PFGRAN;
							SetWindowText(thDat[PSNP],msgbuf);
							break;

						case PSTAR:

							starat=tdub;
							if(starat>1)
								starat=1;
							if(starat<0.05)
								starat=0.05;
							sprintf(msgbuf,"%.2f",starat);
							SetWindowText(thDat[PSTAR],msgbuf);
							break;

						case PSPIR:

							spirwrap=tdub;
							if(starat>20)
								starat=20.;
							if(starat<0.3)
								starat=0.3;
							sprintf(msgbuf,"%.2f",spirwrap);
							SetWindowText(thDat[PSPIR],msgbuf);
							break;

						case PBUT:

							bfclen=tdub*PFGRAN;
							sprintf(msgbuf,"%.2f",tdub);
							SetWindowText(thDat[PBUT],msgbuf);
							break;

						case PHUPX:

							ini.hupx=tdub*PFGRAN;
							sprintf(msgbuf,"%.0f mm",tdub);
							SetWindowText(thDat[PHUPX],msgbuf);
							sethup();
							prfmsg();
							chkhup();
							break;

						case PHUPY:

							ini.hupy=tdub*PFGRAN;
							sprintf(msgbuf,"%.0f mm",tdub);
							SetWindowText(thDat[PHUPY],msgbuf);
							sethup();
							prfmsg();
							chkhup();
							break;

						case PGRD:

							ini.grdsiz=tdub*PFGRAN;
							sprintf(msgbuf,"%.2f mm",tdub);
							SetWindowText(thDat[PGRD],msgbuf);
							break;

						case PCHN:

							ini.chspac=tdub*PFGRAN;
							sprintf(msgbuf,"%.2f",tdub);
							SetWindowText(thDat[PCHN],msgbuf);
							break;
						}
					}
				}
				unsid();
				prfind=0;
			}
			else{

				tdub=atof(msgbuf);
				if(rstMap(SCLPSPAC))
					ini.clpof=tdub*PFGRAN;
				if(rstMap(FSETFIND))
					dufind(tdub);
				if(rstMap(FSETFHI))
				{
					if(tdub)
						dufhi(tdub*PFGRAN);
				}
				if(rstMap(FSETFWID))
				{
					if(tdub)
						dufwid(tdub*PFGRAN);
				}
				if(rstMap(FSETFMAX))
				{
					if(tdub)
						dufmax(tdub*PFGRAN);
				}
				if(rstMap(FSETFMIN))
					dufmin(tdub*PFGRAN);
				if(rstMap(FSETBMAX))
				{
					if(tdub)
						dubmax(tdub*PFGRAN);
				}
				if(rstMap(FSETBMIN))
					dubmin(tdub*PFGRAN);
				if(rstMap(FSETBSPAC))
				{
					if(tdub)
						dubspac(tdub*PFGRAN);
				}
				if(rstMap(FSETFLEN))
				{
					if(tdub)
						dublen(tdub*PFGRAN);
				}
				if(rstMap(FSETBCOL))
					dubcol(tdub);
				if(rstMap(FSETFCOL))
					dufcol(tdub);
				if(rstMap(FSETUCOL))
					dundcol(tdub);
				if(rstMap(FSETFANG))
					dufxang(tdub);
				if(rstMap(FSETFSPAC))
				{
					if(tdub)
						dufspac(tdub*PFGRAN);
				}
				if(rstMap(FSETUANG))
					dufang(tdub);
				if(rstMap(FSETFLEN))
				{
					if(tdub)
						duflen(tdub*PFGRAN);
				}
				if(rstMap(FSETUSPAC))
				{
					if(tdub)
						duspac(tdub*PFGRAN);
				}
				if(rstMap(FSETULEN))
				{
					if(tdub)
						dusulen(tdub*PFGRAN);
				}
				if(rstMap(GTUANG))
					ini.uang=tdub/180*PI;
				if(rstMap(GTUSPAC))
				{
					if(tdub)	
						ini.uspac=tdub*PFGRAN;
				}
				if(rstMap(GTWLKIND))
					ini.wind=tdub*PFGRAN;
				if(rstMap(GTWLKLEN))
				{
					if(tdub)
						ini.ulen=tdub*PFGRAN;
				}
				if(rstMap(PIXIN))
					ini.nudgpix=pxchk(tdub);
				if(rstMap(STPXIN))
					ini.stchpix=pxchk(tdub);
				if(rstMap(FRMPXIN))
					ini.frmpix=tdub;
				if(rstMap(FRMBOXIN))
					ini.frmbpix=tdub;
				if(rstMap(GETMIN))
					smalsiz=tdub*PFGRAN;
				if(rstMap(ENTR30))
					tsiz30=tdub;
				if(rstMap(ENTR40))
					tsiz40=tdub;
				if(rstMap(ENTR60))
					tsiz60=tdub;
				if(rstMap(ENTRFNUM)){

					if(tdub<formpnt)
						frmnumfn(tdub);
					else
						tabmsg(IDS_FRMN1);
					return;
				}
				tdub=floor(tdub);
				if(rstMap(ENTRPOL))
					durpoli(tdub);
				if(rstMap(ENTRSTAR))
					dustar(tdub,250/tdub*zumFct*(zum0.x+zum0.y)/(LHUPX+LHUPY));
				if(rstMap(ENTRSPIR))
					duspir(tdub);
				if(rstMap(ENTRHART))
					duhart(tdub);
				if(rstMap(ENTRLENS))
					dulens(tdub);
				if(rstMap(ENTREG))
					dueg(tdub);
				if(rstMap(ENTRZIG))
					duzig(tdub);
			}
		}
	}
	setMap(RESTCH);
}

void noMsg(){

	if(DestroyWindow(hMsg))
		hMsg=0;
	DestroyWindow(hok);
	DestroyWindow(hdsc);
	DestroyWindow(hcan);
	DestroyWindow(hmin);
	DestroyWindow(hto);
	if(rstMap(NUMIN)||sidtyp||prfind)
		chknum();
	rstMap(MOVMSG);
	rstMap(DELFRM);
	rstMap(FILMSG);
	setMap(RESTCH);
}

void stchWnd(){

	stchPars();

	hStch=CreateWindow(
		"STATIC",
		0,
		SS_OWNERDRAW|WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3,
		0,
		stchSiz.x,
		stchSiz.y,
		hWnd,
		NULL,
		hInst,
		NULL);

	GetWindowRect(hStch,&sRct);

	hVrt=CreateWindow(
		"SCROLLBAR",
		0,
		SBS_VERT|WS_CHILD|WS_VISIBLE,
		stchSiz.x+buttonWid3,
		0,
		SCROLSIZ,
		stchSiz.y,
		hWnd,
		NULL,
		hInst,
		NULL);

	hHor=CreateWindow(
		"SCROLLBAR",
		0,
		SBS_HORZ|WS_CHILD|WS_VISIBLE,
		buttonWid3,
		stchSiz.y,
		stchSiz.x,
		SCROLSIZ,
		hWnd,
		NULL,
		hInst,
		NULL);
	ShowWindow(hVrt,FALSE);
	ShowWindow(hHor,FALSE);
}

//check if a click occurred in A veritcal set of 16 windows
// and calculate which window had the click
unsigned chkMsgs(POINT pt,HWND tWnd,HWND bWnd){

	RECT	tRct;
	RECT	bRct;

	GetWindowRect(tWnd,&tRct);
	GetWindowRect(bWnd,&bRct);

	if(pt.x>tRct.left&&pt.x<bRct.right&&pt.y>tRct.top&&pt.y<bRct.bottom){
	
		vind=15-(bRct.bottom-pt.y)/buttonHi;
		return 1;
	}
	else
		return 0;
}

HWND nuSiz(unsigned wndPnt){

	TCHAR*	str[]={"30","40","60"};

	return CreateWindow(
		"STATIC",
		str[wndPnt],
		WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3,
		buttonHi*(wndPnt+vind),
		buttonWid,
		buttonHi,
		hWnd,
		NULL,
		hInst,
		NULL);
}

void delstch1(unsigned ind){

	if(hed.stchs){

		while(ind<=hed.stchs){

			stchs[ind].at=stchs[ind+1].at;
			stchs[ind].x=stchs[ind+1].x;
			stchs[ind].y=stchs[ind+1].y;
			ind++;
		}
		hed.stchs--;
		if(cloInd>(unsigned)hed.stchs-1)
			cloInd=hed.stchs-1;
	}
}

void stchred(unsigned siz,SHRTPNT* src){
	memcpy(stchs, src, siz * 4);
}

void redbak(){

	BAKHED*		bdat;
	unsigned	ind;

	bdat=(BAKHED*)bakdat[dupnt0];
	hed.stchs=bdat->scnt;
	if(hed.stchs)
		stchred((sizeof(SHRTPNT)*hed.stchs)>>2,bdat->stch);
	zum0.x=bdat->zum0.x;
	zum0.y=bdat->zum0.y;
	formpnt=bdat->fcnt;
//	for(ind=0;ind<formpnt;ind++)
//		frmcpy(&formlst[ind],&bdat->frmp[ind]);
	MoveMemory(&formlst,bdat->frmp,sizeof(FRMHED)*formpnt);
	fltad=bdat->fltcnt;
	if(fltad)
		mvflpnt(&flts[0],&bdat->flt[0],fltad);
	satkad=bdat->sacnt;
	if(satkad)
		mvsatk(&satks[0],&bdat->sac[0],satkad);
	clpad=bdat->nclp;
	if(clpad)
		mvflpnt(&clps[0],&bdat->clp[0],clpad);
	MoveMemory(&useCol,bdat->cols,sizeof(COLORREF)*16);
	for(ind=0;ind<16;ind++){

		uPen[ind]=nuPen(uPen[ind],1,useCol[ind]);
		hbrUseCol[ind]=nuBrush(hbrUseCol[ind],useCol[ind]);
	}
	for(ind=0;ind<16;ind++)
		redraw(hCol[ind]);
	txad=bdat->ntx;
	if(txad)
		MoveMemory(&txpnts,bdat->txp,sizeof(TXPNT)*txad);
	coltab();
	setMap(RESTCH);
}

void redo(){

	unsigned ind;

	if(chkMap(BAKACT)&&chkMap(REDUSHO)){

		dupnt0++;
		dupnt0&=0xf;
		ind=(dupnt0+1)&0xf;
		if(ind==dupnt1){

			EnableMenuItem(hMen,M_REDO,MF_BYPOSITION|MF_GRAYED);
			rstMap(REDUSHO);
		}
		else{

			if(!setMap(REDUSHO))
				EnableMenuItem(hMen,M_REDO,MF_BYPOSITION|MF_ENABLED);
		}
		if(!setMap(UNDUSHO)){

			EnableMenuItem(hMen,M_UNDO,MF_BYPOSITION|MF_ENABLED);
		}
		redbak();
		setMap(DUMEN);
	}
}

void bak(){

	unsigned ind;

	unmsg();
	rstMap(FPSEL);
	rstMap(FRMPSEL);
	rstMap(BIGBOX);
	if(rstMap(PRFACT)){

		rstMap(WASRT);
		DestroyWindow(hPrf);
		prfind=0;
		unsid();
	}
	if(!setMap(BAKING)){

		dudat();
		dupnt1=dupnt0+1;
	}
	if(chkMap(BAKWRAP)){

		dupnt0--;
		dupnt0&=0xf;
		ind=dupnt0-1;
		if(ind==dupnt1){

			EnableMenuItem(hMen,M_UNDO,MF_BYPOSITION|MF_GRAYED);
			setMap(DUMEN);
			rstMap(UNDUSHO);
		}
	}
	else{

		if(dupnt0)
			dupnt0--;
		if(!dupnt0){

			EnableMenuItem(hMen,M_UNDO,MF_BYPOSITION|MF_GRAYED);
			setMap(DUMEN);
			rstMap(UNDUSHO);
		}
	}
	if(!setMap(REDUSHO)){

		EnableMenuItem(hMen,M_REDO,MF_BYPOSITION|MF_ENABLED);
		setMap(DUMEN);
	}
	rstMap(FORMSEL);
	rstMap(GRPSEL);
	redbak();
}

void bitsiz(){

	double				srat;
	double				brat;

	brat=(double)bwid/bhi;
	srat=(double)zum0.x/zum0.y;
	if(brat>srat){

		zumend.x=zum0.x;
		zumend.y=zum0.x/brat;
		scend.x=scRct.right;
		scend.y=scRct.right/brat;
	}
	else{

		zumend.y=zum0.y;
		zumend.x=zum0.y*brat;
		scend.y=scRct.bottom;
		scend.x=scRct.bottom*brat;
	}
	bsrat.x=(double)bwid/zumend.x;
	bsrat.y=(double)bhi/zumend.y;
	birat.x=(double)zumend.x/bwid;
	birat.y=(double)zumend.y/bhi;
}

BOOL binv(unsigned cnt){

	unsigned	ind,ine,icnt,ncnt,lcnt;
	TCHAR*		bcpnt;

	icnt=ncnt=0;
	lcnt=bwid>>3;
	for(ind=0;ind>bhi;ind++){

		bcpnt=(TCHAR*)&bpnt[cnt*ind];
		for(ine=0;ine<lcnt;ine++){

			if(!bcpnt[ine])
				ncnt++;
			else{

				if(bcpnt[ine]==0xff)
					icnt++;
			}
		}
	}
	if(icnt>ncnt)
		return 1;
	else
		return 0;
}

void bitlin(unsigned* src,unsigned* dst,COLORREF fgnd,COLORREF bgnd){
	for (unsigned i = 0; i < bwid; i++) {
		unsigned bit = i ^ 0x7;
		bit &= 31;

		*dst = (bt(src, bit)) ? fgnd : bgnd;

		dst++;
	}
}

COLORREF fswap(COLORREF tcol){
	return bswap_32(tcol) >> 8;
}

BOOL gudtyp(WORD bcnt){

	switch(bcnt){

	case 1:

		return 1;

	case 24:

		return 1;

	case 32:

		return 1;
	}
	return 0;
}

void movmap(unsigned cnt){
	unsigned *src = tracbits;
	char *dst = (char *) bseq;

	for (unsigned i = 0; i < cnt; i++) {
		*(unsigned *)dst = *(src++);

		dst+=3;
	}
}

void savmap(){

	unsigned int		rot;

	if(*bnam){

		if(chkMap(MONOMAP)){

			tabmsg(IDS_SAVMAP);
			return;
		}
		if(!chkMap(WASTRAC)){

			tabmsg(IDS_MAPCHG);
			return;
		}
		if(GetSaveFileName(&obn)){

			hBmp=CreateFile(lbnam,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
			if(hIni==INVALID_HANDLE_VALUE){

				crmsg(lbnam);
				return;
			}
			WriteFile(hBmp,(BITMAPFILEHEADER*)&bhed,14,&rot,NULL);
			WriteFile(hBmp,(BITMAPV4HEADER*)&b4hed,bhed.bfOffBits-14,&rot,NULL);
			movmap(bwid*bhi);
			WriteFile(hBmp,(BSEQPNT*)bseq,bwid*bhi*3,&rot,NULL);
			CloseHandle(hBmp);
		}
	}
	else
		tabmsg(IDS_SHOMAP);
}

void bfil(){

	unsigned			bwidw,bovr,bsiz,ind;
	unsigned*			pbits;
	HBITMAP				tbit;
	HDC					tdc;
	COLORREF			fgnd;
	COLORREF			bgnd;
	COLORREF			bitbak;

	bitbak=fswap(stchBak);
	hBmp=CreateFile(lbnam,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
	if(hBmp==INVALID_HANDLE_VALUE){

		sprintf(msgbuf,"Couldn't open bitmap file: %s\n",lbnam);
		shoMsg(msgbuf);
		CloseHandle(hBmp);
		hBmp=0;
		*bnam=0;
		return;
	}
	ReadFile(hBmp,(BITMAPFILEHEADER*)&bhed,14,&red,NULL);
	if(bhed.bfType=='MB'){

		bsiz=bhed.bfOffBits-14;
		if(bsiz>sizeof(BITMAPV4HEADER))
			bsiz=sizeof(BITMAPV4HEADER);
		ReadFile(hBmp,(BITMAPV4HEADER*)&b4hed,bsiz,&red,NULL);
	}
	else{

		sprintf(msgbuf,"%s is not a Windows Bitmap\n",lbnam);
		CloseHandle(hBmp);
		hBmp=0;
		*bnam=0;
		return;
	}
	if(gudtyp(b4hed.bV4BitCount)){

		if(!rstMap(WASESC))
			rstMap(TRSET);
		bwid=b4hed.bV4Width;
		bhi= b4hed.bV4Height;
		setMap(INIT);
		zRct.left=zRct.bottom=0;
		zRct.right=zum0.x;
		zRct.top=zum0.y;
		bitdc=CreateCompatibleDC(rsdc);
		if(b4hed.bV4BitCount==1){

			setMap(MONOMAP);
			bwidw=bwid>>5;
			bovr=bwid%32;
			if(bovr)
				bwidw++;
			bsiz=bwidw*bhi;
			bpnt=new unsigned[bsiz];
			ReadFile(hBmp,(unsigned*)bpnt,bsiz<<2,&red,NULL);
			CloseHandle(hBmp);
			if(binv(bwidw)){

				bgnd=bitCol;
				fgnd=bitbak;
			}
			else{

				fgnd=bitCol;
				bgnd=bitbak;
			}
			memset((BITMAPINFOHEADER*)&binfh,0,sizeof(BITMAPINFOHEADER));
			binfh.biSize=sizeof(BITMAPINFOHEADER);
			binfh.biWidth=bwid;
			binfh.biHeight=bhi;
			binfh.biPlanes=1;
			binfh.biBitCount=32;
			binfh.biCompression=BI_RGB;
			binf.bmiHeader=binfh;
			tbit=CreateDIBSection(bitdc,&binf,DIB_RGB_COLORS,(void**)&pbits,0,0);	
			for(ind=0;ind<bhi;ind++)
				bitlin(&bpnt[ind*bwidw],&pbits[ind*bwid],bgnd,fgnd);
			tdc=CreateCompatibleDC(rsdc);
			SelectObject(tdc,tbit);
			hBmp=CreateCompatibleBitmap(rsdc,bwid,bhi);
			SelectObject(bitdc,hBmp);
			BitBlt(bitdc,0,0,bwid,bhi,tdc,0,0,SRCCOPY);
			DeleteObject(tbit);
			ReleaseDC(hWnd,tdc);
			delete bpnt;
		}
		else{

			CloseHandle(hBmp);
			rstMap(MONOMAP);
			hBmp=(HBITMAP)LoadImage(hInst,lbnam,IMAGE_BITMAP,bwid,bhi,LR_LOADFROMFILE);
			SelectObject(bitdc,hBmp);
			setMap(RESTCH);
		}
		bitsiz();
		uref=0;
		dref=0x7f7f7f;
		curef=0xffffff;
		cdref=0x808080;
		rstMap(HIDMAP);
	}
	else{

		CloseHandle(hBmp);
		hBmp=0;
		*bnam=0;
		tabmsg(IDS_BMAP);
	}
}

void prtred(){
	
	CloseHandle(hFil);
	rstMap(INIT);
	formpnt=0;
	tabmsg(IDS_PRT);
	coltab();
	setMap(RESTCH);
}

unsigned dtrn(DSTREC* dpnt){
	return *(unsigned *)dpnt;
}

BOOL colfil(){

	TCHAR*	pext;

	strcpy(colnam,filnam);
	strcpy(rgbnam,filnam);
	pext=strrchr(colnam,'.');
	if(pext){

		pext++;
		strcpy(pext,"thw");
		pext=strrchr(rgbnam,'.');
		pext++;
		strcpy(pext,"rgb");
		return 1;
	}
	else
		return 0;
}

void dstran(){

	unsigned		ind,ine,col;
	POINT			loc;
	POINT			nu;
	FLPNT			max;
	FLPNT			min;
	FLPNT			siz;
	FLPNT			dif;
	HANDLE			hcol;
	unsigned*		pcol;
	unsigned		fsiz,colind;
	unsigned int 	hisiz;

	pcol=0;
	if(colfil()){

		hcol=CreateFile(colnam,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
		if(hcol!=INVALID_HANDLE_VALUE){

			fsiz=GetFileSize(hcol,&hisiz);
			pcol=new unsigned[fsiz];
			ReadFile(hcol,(unsigned*)pcol,fsiz,&hisiz,0);
			CloseHandle(hcol);
			if(hisiz&&pcol&&pcol[0]==COLVER){

				stchBak=pcol[1];
				colCnt=0;
			}
			else{

				if(pcol){
					
					delete pcol;
					pcol=0;
				}
			}
		}
	}
	ine=0;
	if(pcol)
		col=colmatch(pcol[2]);
	else
		col=0;
	colind=3;
	loc.x=loc.y=0;
	max.x=max.y=(float)-1e12;
	min.x=min.y=(float)1e12;
	for(ind=0;ind<dstcnt;ind++){

		if(drecs[ind].nd&0x40){

			if(pcol)
				col=colmatch(pcol[colind++]);
			else{

				col++;
				col&=0xf;
			}
		}
		else{

			dstin(dtrn(&drecs[ind]),&nu);
			loc.x+=nu.x;
			loc.y+=nu.y;
			if(!(drecs[ind].nd&0x80)){

				stchs[ine].at=col|NOTFRM;
				stchs[ine].x=loc.x*0.6;
				stchs[ine].y=loc.y*0.6;
				if(stchs[ine].x>max.x)
					max.x=stchs[ine].x;
				if(stchs[ine].y>max.y)
					max.y=stchs[ine].y;
				if(stchs[ine].x<min.x)
					min.x=stchs[ine].x;
				if(stchs[ine].y<min.y)
					min.y=stchs[ine].y;
				ine++;
			}
		}
	}
	if(pcol)
		delete pcol;
	hed.stchs=ine;
	siz.x=max.x-min.x;
	siz.y=max.y-min.y;
	ini.hup=CUSTHUP;
	zum0.x=ini.hupx;
	zum0.y=ini.hupy;
	if(siz.x>zum0.x||siz.y>zum0.y){

		ini.hupx=zum0.x=siz.x*1.1;
		ini.hupy=zum0.y=siz.y*1.1;
		hsizmsg();
	}
	dif.x=(zum0.x-siz.x)/2-min.x;
	dif.y=(zum0.y-siz.y)/2-min.y;
	for(ind=0;ind<hed.stchs;ind++){

 		stchs[ind].x+=dif.x;
		stchs[ind].y+=dif.y;
	}
}

BOOL chkdst(DSTHED* dsthed){

	if(strncmp(dsthed->desched,"LA:",3))
		return 0;
	return 1;
}

void auxmen(){

	switch(ini.auxfil){

	case AUXDST:

		sprintf(msgbuf,stab[STR_AUXTXT],"DST");
		CheckMenuItem(hMen,ID_AUXDST,MF_CHECKED);
		CheckMenuItem(hMen,ID_AUXPCS,MF_UNCHECKED);
		break;

	default:

		CheckMenuItem(hMen,ID_AUXDST,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_AUXPCS,MF_CHECKED);
		sprintf(msgbuf,stab[STR_AUXTXT],"PCS");
	}
	SetMenuItemInfo(hfileMen,ID_OPNPCD,MF_BYCOMMAND,&filinfo);
	setMap(DUMEN);
}

#if PESACT

unsigned tripl(TCHAR* dat){
	return (*(unsigned *)dat) & 0xffffff;
}

unsigned pesmtch(COLORREF rcol,unsigned char pcol){

	unsigned	rval,ind;
	COLORREF	tcol;

	tcol=pestrn[pcol];
	rval=0;
	for(ind=0;ind<3;ind++){

		rval+=abs((rcol&0xff)-(tcol&0xff));
		tcol>>=8;
		rcol>>=8;
	}
	return rval;
}

unsigned dupcol(){

	unsigned	ind;
	COLORREF	col;
	unsigned	mat,matm,pmatm;

	col=pestrn[pescols[pcolind++]];
	for(ind=0;ind<xpnt;ind++){

		if(useCol[ind]==col)
			return ind;
	}
	matm=0xffffff;
	for(ind=1;ind<xpnt;ind++){

		mat=pesmtch(col,pescols[ind]);
		if(mat<matm){

			matm=mat;
			pmatm=ind;
		}
	}
	return pmatm;
}


double dubl(unsigned char* pnt){

	unsigned tdat;

#if !defined(GCC__)
	__asm{

			mov		ecx,pnt
			mov		ecx,[ecx]
			movzx	ebx,ch
			test	cl,8
			je		short dubl1
			mov		ch,15
			and		cl,ch
			sub		ch,cl
			movzx	ecx,ch
			shl		ecx,8
			mov		eax,256
			sub		eax,ebx
			add		ecx,eax
			neg		ecx
			jmp		short dubl2
dubl1:		and		ecx,0x7
			shl		ecx,8
			add		ecx,ebx
dubl2:		mov		tdat,ecx
			fild	tdat
	}
#else
	__asm__ __volatile__
	(

	"	mov		ecx,%[pnt]\n"
	"	mov		ecx,[ecx]\n"
	"	movzx	ebx,ch\n"
	"	test	cl,8\n"
	"	je		short dubl1\n"
	"	mov		ch,15\n"
	"	and		cl,ch\n"
	"	sub		ch,cl\n"
	"	movzx	ecx,ch\n"
	"	shl		ecx,8\n"
	"	mov		eax,256\n"
	"	sub		eax,ebx\n"
	"	add		ecx,eax\n"
	"	neg		ecx\n"
	"	jmp		short dubl2\n"
	"dubl1: 	and		ecx,0x7\n"
	"	shl		ecx,8\n"
	"	add		ecx,ebx\n"
	"dubl2: 	mov		%[tdat],ecx\n"
	"	fild	%[tdat]\n"

	:	[tdat] "=m" (tdat)
	:	[pnt] "m" (pnt)
	:	"cl", "ebx", "ecx", "ch", "eax"
	);
#endif
}
#endif

void xofrm(){

	unsigned	ind;
	FRMHEDO*	frmlstx;

	frmlstx=(FRMHEDO*)&bseq;
	FillMemory(&bseq,0,sizeof(FRMHED)*formpnt);
	for(ind=0;ind<formpnt;ind++)
		MoveMemory(&formlst[ind],&frmlstx[ind],sizeof(FRMHEDO));
}

void nuFil(){

	unsigned		siz,stind;
	unsigned		vervar;
	unsigned int	sizh;
	unsigned		ind,inf,ing,inh,tcol;
	unsigned		cPnt;
	TCHAR*			pext;
	TCHAR			tchr;
	STRHED			sthed;
	TCHAR			buf[3];
	TCHAR*			tnam;
	DSTHED			dsthed;
	FLRCT			strct;
	FRMHEDO*		frmlstx;
	long			tred;

#if PESACT

	unsigned		ine;
	PESHED*			peshed;
	TCHAR*			peschr;
	unsigned		pecof;
	unsigned char*	pcolcnt;
	DUBPNT			loc;
	PESTCH*			pabstch;
	unsigned		pabind;
	double			locof;
#endif

	if(rstMap(REDOLD)||GetOpenFileName(&ofn)){
			
		fnamtabs();
		untrace();
		if(formpnt)
			delfrms();
		rstMap(ZUMED);
		rstMap(FRMOF);
		rstMap(HID);
		rstMap(BIGBOX);
		unthum();
		unbsho();
		if(bnam[0]){

			DeleteObject(hBmp);
			ReleaseDC(hWnd,bitdc);
			*bnam=0;
		}
		hFil=CreateFile(filnam,GENERIC_READ,0,NULL,
				OPEN_EXISTING,0,NULL);
		if(hFil==INVALID_HANDLE_VALUE){

			ind=GetLastError();
			if(GetLastError()==32)
				filnopn(IDS_FNOPNA,filnam);
			else
				filnopn(IDS_FNOPN,filnam);
			hFil=0;
		}
		else{

			rstMap(CMPDO);
			rstMap(SAVACT);
			rstMap(BAKING);
			rstMap(REDUSHO);
			txad=0;
			EnableMenuItem(hMen,M_REDO,MF_BYPOSITION|MF_GRAYED);
			deldu();
			strcpy(fildes,ini.desnam);
			unbsho();
			rstMap(MOVSET);
			frmon();
			fselpnt=0;
			if(rstMap(PRFACT)){

				DestroyWindow(hPrf);
				rstMap(WASRT);
				prfind=0;
			}
			bnam[0]=0;
			if(slpnt)
				slpnt=0;
			rstMap(SCROS);
			rstMap(ECROS);
			rstMap(BZUMIN);
			rstdu();
			unmsg();
			dupnt0=0;
			rstMap(BAKWRAP);
			zumFct=1;
			setMap(RESTCH);
			defNam(filnam);
			selCnt=0;
			if(rstMap(WASPAT))
				DestroyWindow(hSped);
			ind=0;
			if(chkMap(WASTXBAK))
				ind=1;
			clrMap(MAPLEN);
			if(ind)
				setMap(WASTXBAK);
			siz=GetFileSize(hFil,&sizh);
			pext=strrchr(filnam,'.');
			if(pext)
				pext++;
			else{

				strcat(filnam,".thr");
				pext=strrchr(filnam,'.')+1;
			}
			tchr=tolower(pext[0]);
			if(tchr=='t'){

				ReadFile(hFil,(STRHED*)&sthed,sizeof(STRHED),&red,NULL);
				if((sthed.led&0xffffff)==0x746872){

					if(red!=sizeof(STRHED)){

						tabmsg(IDS_SHRTF);
						return;
					}
					vervar=(sthed.led&0xff000000)>>24;
					switch(vervar){

					case 0:

						if(hed.hup==SMALHUP){

							zum0.x=ini.hupx=SHUPX;
							zum0.y=ini.hupy=SHUPY;
						}
						else{

							zum0.x=ini.hupx=LHUPX;
							zum0.y=ini.hupy=LHUPY;
							hed.hup=LARGHUP;
						}
						ritfnam(ini.desnam);
						strcpy(fildes,ini.desnam);
						strcpy(hedx.modnam,ini.desnam);
						break;

					case 1:
					case 2:

						ReadFile(hFil,(STREX*)&hedx,sizeof(STREX),&red,NULL);
						if(red!=sizeof(STREX)){

							tabmsg(IDS_SHRTF);
							return;
						}
						ini.hupx=zum0.x=hedx.xhup;
						ini.hupy=zum0.y=hedx.yhup;
						redfnam(fildes);
						break;
					
					default:

						tabmsg(IDS_NOTVER);
						return;
					}
					zRct.bottom=zRct.left=0;
					zRct.right=zum0.x=ini.hupx;
					zRct.top=zum0.y=ini.hupy;
					hed.stchs=sthed.stchs;
					ReadFile(hFil,(SHRTPNT*)stchs,hed.stchs*sizeof(SHRTPNT),&red,NULL);
					if(red!=hed.stchs*sizeof(SHRTPNT)){
				
						hed.stchs=red/sizeof(SHRTPNT);
						prtred();
						return;
					}
					ReadFile(hFil,(TCHAR*)bnam,16,&red,0);
					tred=red;
					if(red!=16){

						bnam[0]=0;
						prtred();
						return;
					}
					ReadFile(hFil,(COLORREF*)&stchBak,4,&red,0);
					tred+=red;
					if(red!=4){

						stchBak=ini.stchBak;
						prtred();
						return;
					}
					hStchBak=CreateSolidBrush(stchBak);
					ReadFile(hFil,(COLORREF*)useCol,64,&red,0);
					tred+=red;
					if(red!=64){

						prtred();
						return;
					}
					ReadFile(hFil,(COLORREF*)custCol,64,&red,0);
					tred+=red;
					if(red!=64){

						prtred();
						return;
					}
					ReadFile(hFil,(TCHAR*)msgbuf,16,&red,0);
					tred+=red;
					if(red!=16){

						prtred();
						return;
					}
					for(ind=0;ind<16;ind++)
						thrdSiz[ind][0]=msgbuf[ind];
					formpnt=sthed.fpnt;
					if(formpnt>MAXFORMS)
						formpnt=MAXFORMS;
					inf=0;ing=0,inh=0;
					if(formpnt){

						ind=fltad=satkad=clpad=0;
						msgbuf[0]=0;
						if(vervar<2){

							frmlstx=(FRMHEDO*)&bseq;
							ReadFile(hFil,(FRMHEDO*)frmlstx,formpnt*sizeof(FRMHEDO),&red,0);
							if(red!=formpnt*sizeof(FRMHEDO)){

								formpnt=red/sizeof(FRMHEDO);
								setMap(BADFIL);
							}
							xofrm();
						}
						else{

							ReadFile(hFil,(FRMHED*)formlst,formpnt*sizeof(FRMHED),&red,0);
							rstMap(BADFIL);
							if(red!=formpnt*sizeof(FRMHED)){

								formpnt=red/sizeof(FRMHED);
								setMap(BADFIL);
							}
						}
//						ind=SetFilePointer(hFil,0,0,FILE_CURRENT);  //bug
						ReadFile(hFil,(FLPNT*)flts,sthed.fcnt*sizeof(FLPNT),&red,0);
						if(red!=sizeof(FLPNT)*sthed.fcnt){

							fltad=red/sizeof(FLPNT);
							for(ind=fltad;ind<sthed.fcnt;ind++)
								flts[ind].x=flts[ind].y=0;
							setMap(BADFIL);
						}
						ReadFile(hFil,(SATCON*)satks,sthed.scnt*sizeof(SATCON),&red,0);
						if(red!=sthed.scnt*sizeof(SATCON)){

							satkad=red/sizeof(SATCON);
							setMap(BADFIL);
						}
						ReadFile(hFil,(FLPNT*)clps,sthed.ecnt*sizeof(FLPNT),&red,0);
						if(red!=sthed.ecnt*sizeof(FLPNT)){

							clpad=red/sizeof(FLPNT);
							setMap(BADFIL);
						}
						ReadFile(hFil,(TXPNT*)txpnts,hedx.txcnt*sizeof(TXPNT),&red,0);
						txad=red/sizeof(TXPNT);
						if(rstMap(BADFIL))
							bfilmsg();
						for(ind=0;ind<formpnt;ind++){

							formlst[ind].flt=adflt(formlst[ind].sids);
							if(formlst[ind].typ==SAT){
								
								if(formlst[ind].stpt)
									formlst[ind].sacang.sac=adsatk(formlst[ind].stpt);
							}
							if(isclp(ind))
								formlst[ind].angclp.clp=adclp(formlst[ind].flencnt.nclp);
							if(iseclpx(ind))
								formlst[ind].clp=adclp(formlst[ind].nclp);
						}
						setfchk();
					}
				}
				else
					tabmsg(IDS_NOTHR);
			}
			else{
				
				setMap(NOTHRFIL);
				if(tchr=='p'){

					if(tolower(pext[01])=='c'){

						ReadFile(hFil,(HED*)&hed,0x46,&red,NULL);
						if(!siz){

							filnopn(IDS_ZEROL,filnam);
							return;
						}
						if(hed.ledIn==0x32&&hed.fColCnt==16){

							for(ind=0;ind<16;ind++)
								useCol[ind]=hed.fCols[ind];
							siz-=0x46;
							inf=siz/sizeof(PCSTCH)+2;
							filBuf=new PCSTCH[inf];
							ReadFile(hFil,filBuf,siz,&red,NULL);
							stind=0;
							cPnt=0;
							tcol=0;
							ind=0;
							while(stind<hed.stchs&&ind<inf){

								if(filBuf[ind].typ==3){

									colch[cPnt].colind=filBuf[ind].fx;
									colch[cPnt++].stind=stind;
									tcol=NOTFRM|filBuf[ind++].fx;
								}
								else{

									stchs[stind].x=filBuf[ind].x+(float)filBuf[ind].fx/256;
									stchs[stind].y=filBuf[ind].y+(float)filBuf[ind].fy/256;
									stchs[stind++].at=tcol;
									ind++;
								}
							}
							hed.stchs=stind;
							tnam=(TCHAR*)&filBuf[ind];
							strcpy(bnam,tnam);
							delete filBuf;
							strcpy(pext,"thr");
							ini.auxfil=AUXPCS;
							if(hed.hup!=LARGHUP&&hed.hup!=SMALHUP)
								hed.hup=LARGHUP;
							sizstch(&strct);
							if(strct.left<0||strct.right>LHUPY||strct.bottom<0||strct.top>LHUPY){

								ini.hupx=LHUPX;
								ini.hupy=LHUPY;
								chkhup();
							}
							else{

								if(hed.hup==LARGHUP){

									ini.hup=LARGHUP;
									ini.hupx=LHUPX;
									ini.hupy=LHUPY;
								}
								else{

									if(strct.right>SHUPX||strct.top>SHUPY||hed.hup==LARGHUP){
								
										ini.hup=LARGHUP;
										ini.hupx=SHUPX;
										ini.hupy=SHUPY;
									}
									else{

										ini.hup=SMALHUP;
										ini.hupx=SHUPX;
										ini.hupy=SHUPY;
									}
								}
							}
						}
					}
#if PESACT
					else{

						ReadFile(hFil,(BSEQPNT*)&bseq,sizeof(bseq),&red,0);
						peshed=(PESHED*)&bseq;
						peschr=(TCHAR*)&bseq;
						if(strncmp(peshed->led,"#PES00",6)){

							sprintf(msgbuf,"Not a PES file: %s\n",filnam);
							shoMsg(msgbuf);
							return;
						}
						pecof=tripl(peshed->off);
						pestch=(unsigned char*)&peschr[pecof+532];
						xpnt=0;
						pcolcnt=(unsigned char*)&peschr[pecof+48];
						pescols=&pcolcnt[1];
						rmap[0]=rmap[1]=0;
						xpnt=0;
						for(ind=0;ind<(unsigned)(*pcolcnt+1);ind++){

							if(setRmp(pescols[ind])){

								useCol[xpnt++]=pestrn[pescols[ind]&PESCMSK];
								if(xpnt>=16)
									break;
							}
						}
						tcol=0;
						pcolind=1;
						loc.x=loc.y=0;
						pabind=ind=ine=0;
						rstMap(FILDIR);
						ind=0;
						pabstch=(PESTCH*)&peschr[sizeof(PESHED)+4];
						ind=0;
						ine=1;
						stchs[0].x=stchs[0].y;
						while(ind<red-pecof-529){

							if(pestch[ind]==0xff&&pestch[ind+1]==0)
								break;
							if(pestch[ind]==0xfe&&pestch[ind+1]==0xb0){

								tcol=dupcol();
								ind+=2;
							}
							else{

								if(pestch[ind]&0x80){

									locof=dubl(&pestch[ind]);
									ind++;
								}
								else{

									if(pestch[ind]&0x40)
										locof=pestch[ind]-128;
									else
										locof=pestch[ind];
								}
								locof*=0.6;
								if(toglMap(FILDIR)){

									loc.y-=locof;
									stchs[ine].x=loc.x;
									stchs[ine].y=loc.y;
									stchs[ine].at=tcol;
									ine++;
								}
								else
									loc.x+=locof;
							}
							ind++;
						}
						hed.stchs=ine;
						//ini.auxfil=AUXPES;
						hupfn();
					}
#endif
				}
				else{

					ReadFile(hFil,(DSTHED*)&dsthed,sizeof(DSTHED),&red,0);
					if(red==sizeof(DSTHED)){

						if(chkdst(&dsthed)){

							bnam[0]=0;
							siz=GetFileSize(hFil,&red)-sizeof(DSTHED);
							dstcnt=siz/sizeof(DSTREC);
							drecs=new DSTREC[dstcnt];
							ReadFile(hFil,(DSTREC*)drecs,sizeof(DSTREC)*dstcnt,&red,0);
							dstran();
							delete drecs;
							ini.auxfil=AUXDST;
						}
					}
					else{

						tabmsg(IDS_DST2S);
						CloseHandle(hFil);
						return;
					}
				}
			}
			if(bnam[0]){
						
				SetCurrentDirectory(defDir);
				strcpy(lbnam,bnam);
				bfil();
			}
			ritot(hed.stchs);
			numpnt=0;
			zRct.left=0;
			zRct.bottom=0;
			zRct.right=zum0.x=ini.hupx;
			zRct.top=zum0.y=ini.hupy;
			movStch();
			coltab();
			rstMap(ZUMED);
			buf[2]=0;
			for(ind=0;ind<16;ind++){

				uPen[ind]=nuPen(uPen[ind],1,useCol[ind]);
				hbrUseCol[ind]=nuBrush(hbrUseCol[ind],useCol[ind]);
				strncpy(buf,thrdSiz[ind],2);
				SetWindowText(hSiz[ind],buf);
			}
			for(ind=0;ind<16;ind++)
				redraw(hCol[ind]);
			redraw(hBar);
			if(hed.stchs)
				setMap(INIT);
			nuAct(0);
			setMap(RESTCH);
			nunams();
			ritini();
			butxt(HNUM,"");
 			if(hed.stchs)
				nuAct(stchs[0].at&COLMSK);
			else
				nuAct(0);
			auxmen();
		}
		lenCalc();
		sprintf(msgbuf,stab[STR_THRDBY],filnam,fildes);
		SetWindowText(hWnd,msgbuf);
		CloseHandle(hFil);
		setMap(INIT);
		rstMap(TRSET);
		if(chkMap(NOTHRFIL))
		{
			for(ind=0;ind<hed.stchs;ind++)
				stchs[ind].at|=NOTFRM;
		}	
		lodchk();
	}
}

void clrfbuf(unsigned siz){
	memset(filBuf, 0, siz * 4);
}

unsigned xbits(unsigned src,unsigned dst){
	unsigned bits = trinum;

	bits >>= src & 0xFF;
	bits &= 3;

	bits <<= dst & 0xFF;

	return bits;
}

unsigned dudbits(POINT dif){

	return xdst[dif.x+121]|ydst[dif.y+121];
}

void savdst(unsigned dat){
	union {
		unsigned dat;
		DSTREC drec;
	} x;

	x.dat = dat;

	drecs[dstcnt++] = x.drec;
}

void ritdst(){

#define DSTMAX 121

	unsigned		ind,styp,col,cnt,colind;
	POINT			loc,len,alen,dif,stp;
	FLRCT			trct;
	SHRTPNT*		histch;
	unsigned*		pcol;
	HANDLE			hcol;
	unsigned int	wrot;

	pcol=(unsigned*)&oseq;
	colind=3;
	pcol[0]=COLVER;
	pcol[1]=stchBak;
	pcol[2]=useCol[stchs[0].at&COLMSK];
	histch=&stchs[MAXSEQ];
	for(ind=0;ind<hed.stchs;ind++){

		histch[ind].x=stchsr[ind].x*5/3;
		histch[ind].y=stchsr[ind].y*5/3;
		histch[ind].at=stchsr[ind].at;
	}
	trct.left=trct.right=histch[0].x;
	trct.bottom=trct.top=histch[0].y;
	for(ind=1;ind<hed.stchs;ind++){
	
		if(histch[ind].x>trct.right)
			trct.right=histch[ind].x+0.5;
		if(histch[ind].x<trct.left)
			trct.left=histch[ind].x-0.5;
		if(histch[ind].y>trct.top)
			trct.top=histch[ind].y+0.5;
		if(histch[ind].y<trct.bottom)
			trct.bottom=histch[ind].y-0.5;
	}
 	drecs=(DSTREC*)&bseq;
	dstcnt=0;
	loc.x=(trct.right-trct.left)/2+trct.left;
	loc.y=(trct.top-trct.bottom)/2+trct.bottom;
	dstplus.x=trct.right-loc.x+1;
	dstplus.y=trct.top-loc.y+1;
	dstmin.x=loc.x-trct.left-1;
	dstmin.y=loc.y-trct.bottom-1;
	col=histch[0].at&0xf;
	for(ind=0;ind<hed.stchs;ind++){

		if(col!=(histch[ind].at&0xf)){

			savdst(0xc30000);
			col=histch[ind].at&0xf;
			pcol[colind++]=useCol[col];
		}
		len.x=histch[ind].x-loc.x;
		len.y=histch[ind].y-loc.y;
		alen.x=abs(len.x);
		alen.y=abs(len.y);
		if(abs(alen.x)>abs(alen.y))
			cnt=alen.x/DSTMAX+1;
		else
			cnt=alen.y/DSTMAX+1;
		stp.x=alen.x/cnt+1;
		stp.y=alen.y/cnt+1;
		while(len.x||len.y){

			styp=REGTYP;
			if(abs(len.x)>stp.x){

				styp=JMPTYP;
				if(len.x>0)
					dif.x=stp.x;
				else
					dif.x=-stp.x;
			}
			else
				dif.x=len.x;
			if(abs(len.y)>stp.y){

				styp=JMPTYP;
				if(len.y>0)
					dif.y=stp.y;
				else
					dif.y=-stp.y;
			}
			else
				dif.y=len.y;
			savdst(dudbits(dif)|styp);
			loc.x+=dif.x;
			loc.y+=dif.y;
			len.x-=dif.x;
			len.y-=dif.y;
		}
	}
	drecs[dstcnt].led=drecs[dstcnt].mid=0;
	drecs[dstcnt++].nd=(TCHAR)0xf3;

	if(colfil()){

		hcol=CreateFile(colnam,GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
		if(hcol!=INVALID_HANDLE_VALUE)
			WriteFile(hcol,&oseq,colind<<2,&wrot,0);
		CloseHandle(hcol);
		hcol=CreateFile(rgbnam,GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
		if(hcol!=INVALID_HANDLE_VALUE)
			WriteFile(hcol,&pcol[2],(colind-2)<<2,&wrot,0);
		CloseHandle(hcol);
	}
}

BOOL pcshup(){

	FLRCT		trct;
	FLPNT		siz;
	unsigned	ind;
	FLPNT		hupsiz;
	FLPNT		dif;

	trct.left=trct.right=stchsr[0].x;
	trct.bottom=trct.top=stchsr[0].y;
	for(ind=1;ind<hed.stchs;ind++){

		if(stchsr[ind].x<trct.left)
			trct.left=stchsr[ind].x;
		if(stchsr[ind].x>trct.right)
			trct.right=stchsr[ind].x;
		if(stchsr[ind].y<trct.bottom)
			trct.bottom=stchsr[ind].y;
		if(stchsr[ind].y>trct.top)
			trct.top=stchsr[ind].y;
	}
	siz.x=trct.right-trct.left;
	siz.y=trct.top-trct.bottom;
	if(siz.x>LHUPX||siz.y>LHUPY){

		tabmsg(IDS_PFAF2L);
		return 1;
	}
	if(siz.x>SHUPX||siz.y>SHUPY){

		hed.hup=LARGHUP;
		hupsiz.x=LHUPX;
		hupsiz.y=LHUPY;
	}
	else{

		if(ini.hupx==LHUPX&&ini.hupy==LHUPY){

			hed.hup=LARGHUP;
			hupsiz.x=LHUPX;
			hupsiz.y=LHUPY;
		}
		else{

			hed.hup=SMALHUP;
			hupsiz.x=SHUPX;
			hupsiz.y=SHUPY;
		}
	}
	dif.x=dif.y=0;
	if(trct.right>hupsiz.x)
		dif.x=hupsiz.x-trct.right;
	if(trct.top>hupsiz.y)
		dif.y=hupsiz.y-trct.top;
	if(trct.left<0)
		dif.x=-trct.left;
	if(trct.bottom<0)
		dif.y=-trct.bottom;
	if(dif.x||dif.y){

		for(ind=0;ind<hed.stchs;ind++){

			stchsr[ind].x+=dif.x;
			stchsr[ind].y+=dif.y;
		}
	}
	return 0;
}

#if PESACT

void ritpes(unsigned stind){

	pestchs[opnt].x=-stchsr[stind].x*3/5+sof.x;
	pestchs[opnt++].y=stchsr[stind].y*3/5-sof.y;
}

void ritpcol(unsigned char col){

#if !defined(GCC__)
	__asm{

			mov		ebx,opnt
			mov		eax,ebx
			inc		eax
			mov		opnt,eax
			shl		ebx,2
			add		ebx,pestchs
			xor		eax,eax
			mov		al,col
			mov		[ebx],eax
	}
#else
	__asm__ __volatile__
	(

	"	mov		ebx,%[opnt]\n"
	"	mov		eax,ebx\n"
	"	inc		eax\n"
	"	mov		%[opnt],eax\n"
	"	shl		ebx,2\n"
	"	add		ebx,%[pestchs]\n"
	"	xor		eax,eax\n"
	"	mov		al,%[col]\n"
	"	mov		[ebx],eax\n"

	:	[opnt] "=m" (opnt)
	:	[pestchs] "m" (pestchs),
		[col] "m" (col)
	:	"memory", "al", "ebx", "eax"
	);
#endif
}

unsigned pesnam(){

#if !defined(GCC__)
	__asm{
			mov		ebx,offset auxnam
			mov		ecx,MAX_PATH
			mov		edx,ebx
peslup0:	mov		al,[ebx]
			or		al,al
			je		short peslup1
			cmp		al,'\\'
			jne		short peslup0a
			mov		edx,ebx
peslup0a:	inc		ebx
			loop	peslup0
peslup1:	mov		ebx,edx
			cmp		byte ptr[ebx],'\\'
			jne		short peslup1a
			inc		ebx
peslup1a:	xor		ecx,ecx
			mov		cl,17
			mov		edi,offset bseq
			mov		dword ptr[edi],':AL'
			add		edi,3
peslup:		mov		al,[ebx]
			inc		ebx
			cmp		al,'.'
			je		pesnamx
			mov		[edi],al
			inc		edi
			loop	peslup
pesnamx:	mov		eax,edi
			sub		eax,offset bseq
	}
#else
	__asm__ __volatile__
	(
	"	mov		ebx,offset auxnam\n"
	"	mov		ecx,%[MAX_PATH]\n"
	"	mov		edx,ebx\n"
	"peslup0: 	mov		al,[ebx]\n"
	"	or		al,al\n"
	"	je		short peslup1\n"
	"	cmp		al,'\\'\n"
	"	jne		short peslup0a\n"
	"	mov		edx,ebx\n"
	"peslup0a: 	inc		ebx\n"
	"	loop	peslup0\n"
	"peslup1: 	mov		ebx,edx\n"
	"	cmp		byte ptr[ebx],'\\'\n"
	"	jne		short peslup1a\n"
	"	inc		ebx\n"
	"peslup1a: 	xor		ecx,ecx\n"
	"	mov		cl,17\n"
	"	mov		edi,offset bseq\n"
	"	mov		dword ptr[edi],':AL'\n"
	"	add		edi,3\n"
	"peslup: 	mov		al,[ebx]\n"
	"	inc		ebx\n"
	"	cmp		al,'.'\n"
	"	je		pesnamx\n"
	"	mov		[edi],al\n"
	"	inc		edi\n"
	"	loop	peslup\n"
	"pesnamx: 	mov		eax,edi\n"
	"	sub		eax,offset bseq\n"

	:
	:	[MAX_PATH] "m" (MAX_PATH)
	:	"cl", "memory", "al", "ebx", "ecx", "edx", "edi", "eax"
	);
#endif
}

void rpcrd(float dif){

	int idif;

	idif=dif*5/3;
	if(idif<0){

		if(idif>-64){

			peschr[opnt]=idif-128;
			opnt++;
		}
		else{

			peschr[opnt]=idif>>8;
			opnt++;
			peschr[opnt]=idif&0x8f;
			opnt++;
		}
	}
	else{

		if(idif<64){

			peschr[opnt]=idif;
			opnt++;
		}
		else{

			peschr[opnt]=(idif>>8)|0x80;
			opnt++;
			peschr[opnt]=idif&0xff;
			opnt++;
		}
	}
}

void pecdat(){

	unsigned	ind,col,pcol;

	opnt=532;
	pcol=1;
	col=stchs[0].at&COLMSK;
	peschr=(TCHAR*)&bseq;
	pescols=(unsigned char*)&peschr[49];
	rpcrd(stchs[0].x);
	rpcrd(-stchs[0].y);
	for(ind=0;ind<(unsigned)hed.stchs-1;ind++){

		if((stchs[ind].at&COLMSK)!=col){

			col=stchs[ind].at&COLMSK;
			peschr[opnt]=(TCHAR)254;
			opnt++;
			peschr[opnt]=(TCHAR)176;
			opnt++;
			peschr[opnt]=pcol;
			opnt++;
			pescols[pcol]=pescolrs[col];
			pcol++;
		}
		rpcrd(stchs[ind+1].x-stchs[ind].x);
		rpcrd(-stchs[ind+1].y+stchs[ind].y);
	}
	peschr[opnt++]=(TCHAR)0xff;
	peschr[opnt++]=0;
}

#endif

void chk1col(){

	unsigned ind,ine,col;

	coltab();
	setMap(RESTCH);
	for(ind=0;ind<colCnt;ind++){

		if(colch[ind+1].stind-colch[ind].stind==1){

			ine=colch[ind].stind;
			col=stchs[ine-1].at&COLMSK;
			stchs[ine].at&=NCOLMSK;
			stchs[ine].at|=col;
		}
	}
}

BOOL chkattr(TCHAR* nam){

	unsigned		attr,ind;
	TCHAR			driv[MAX_PATH];
	unsigned int 	sec;
	unsigned int 	byt;
	unsigned int 	fclst;
	unsigned int 	tclst;

	if(rstMap(NOTFREE))
		return 1;
	attr=GetFileAttributes(nam);
	if(attr&FILE_ATTRIBUTE_READONLY&&attr!=0xffffffff){

		sprintf(msgbuf,stab[STR_OVRLOK],nam);
		ind=MessageBox(hWnd,msgbuf,stab[STR_OVRIT],MB_YESNO);
		if(ind==IDYES)
			SetFileAttributes(nam,attr&(0xffffffff^FILE_ATTRIBUTE_READONLY));
		else
			return 1;
	}
	strcpy(driv,homdir);
	driv[3]=0;
	if(!GetDiskFreeSpace(driv,&sec,&byt,&fclst,&tclst)){

		setMap(NOTFREE);
		return 1;
	}
	return 0;
}

void sav(){

	unsigned		ind,stind;
	unsigned int wrot;
	double			frct,intg;
	DSTHED			dsthed;
	TCHAR*			pchr;
	POINT			loc;

#if PESACT

	PESHED			peshed;
	PESTCH*			pestch;
	unsigned		match;
	unsigned		mtchind;
	unsigned		mtchmin;
	unsigned char	pescol;
	FLRCT			srct;
	unsigned		tcol,ine;
	unsigned		pcolcnt;
	unsigned*		pesof;
	unsigned*		upnt;
	short*			psiz;
#endif

	duauxnam();
	if(chkattr(auxnam))
		return;
	if(!hed.stchs)
		return;
	chk1col();
	coltab();
	stchsr=(SHRTPNT*)&bseq;
	if(chku(ROTAUX)){

		for(ind=0;ind<hed.stchs;ind++){

			stchsr[ind].y=-stchs[ind].x;
			stchsr[ind].x=stchs[ind].y;
			stchsr[ind].at=stchs[ind].at;
		}
	}
	else{

		for(ind=0;ind<hed.stchs;ind++){

			stchsr[ind].x=stchs[ind].x;
			stchsr[ind].y=stchs[ind].y;
			stchsr[ind].at=stchs[ind].at;
		}
	}
	hPcs=CreateFile(auxnam,(GENERIC_WRITE|GENERIC_READ),0,NULL,
		CREATE_ALWAYS,0,NULL);
	if(hPcs==INVALID_HANDLE_VALUE){

		crmsg(auxnam);
		hPcs=0;
	}
	else{

		switch(ini.auxfil){

		case AUXDST:

			ritdst();
			ind=0;loc.x=loc.y=0;
			pchr=(TCHAR*)&dsthed;
			for(ind=0;ind<sizeof(DSTHED);ind++)
				pchr[ind]=' ';
			strcpy(dsthed.desched,"LA:");
			pchr=strrchr(auxnam,'\\')+1;
			for(ind=0;ind<sizeof(dsthed.desc);ind++){

				if(pchr[ind]&&pchr[ind]!='.')
					dsthed.desc[ind]=pchr[ind];
				else
					break;
			}
			dsthed.desc[16]=0xd;
			strncpy(dsthed.recshed,"ST:",3);
			sprintf(dsthed.recs,"%7d\r",dstcnt);
			strncpy(dsthed.cohed,"CO:  0",6);
			strncpy(dsthed.xplushed-1,"\xd+X:",4);
			sprintf(dsthed.xplus,"%5d\xd",dstmin.x);
			strncpy(dsthed.xminhed,"-X:",3);
			sprintf(dsthed.xmin,"%5d\xd",dstplus.x);
			strncpy(dsthed.yplushed,"+Y:",3);
			sprintf(dsthed.yplus,"%5d\xd",dstplus.y);
			strncpy(dsthed.yminhed,"-Y:",3);
			sprintf(dsthed.ymin,"%5d\xd",dstmin.y);
			strncpy(dsthed.axhed,"AX:-    0\r",10);
			strncpy(dsthed.ayhed,"AY:+    0\r",10);
			strncpy(dsthed.mxhed,"MX:+    0\r",10);
			strncpy(dsthed.myhed,"MY:+    0\r",10);
			strncpy(dsthed.pdhed,"PD******\r\x1a",10);
			pchr=(TCHAR*)&dsthed;
			WriteFile(hPcs,(DSTHED*)&dsthed,sizeof(DSTHED),&wrot,0);
			WriteFile(hPcs,(DSTREC*)drecs,sizeof(DSTREC)*dstcnt,&wrot,0);
			break;

#if PESACT

		case AUXPES:

			pchr=(TCHAR*)&peshed;
			for(ind=0;ind<sizeof(PESHED);ind++)
				pchr[ind]=0;
			strcpy(peshed.led,"#PES0001");
			strcpy(peshed.ce,"CEmbOne");
			strcpy(peshed.cs,"CSewSeg");
			pestch=(PESTCH*)&bseq;
			for(ind=0;ind<16;ind++){

				mtchmin=0xffffffff;
				for(ine=0;ine<sizeof(pestrn)>>2;ine++){

					match=pesmtch(useCol[ind],ine);
					if(match<mtchmin){

						mtchind=ine;
						mtchmin=match;
					}
				}
				pescolrs[ind]=(unsigned char)mtchind;
			}
			tcol=stchs[0].at&COLMSK;
			pescol=peshed.scol=pescolrs[stchs[0].at&COLMSK];
			sizstch(&srct);
			sof.x=midl(srct.right,srct.left);
			sof.y=midl(srct.top,srct.bottom);
			peshed.xsiz=srct.right-srct.left;
			peshed.ysiz=srct.top-srct.bottom;
			opnt=0;
			pestchs=(PESTCH*)&bseq;
			ritpes(0);
			pestchs[opnt].x=(short)0x8003;
			pestchs[opnt++].y=0;
			ritpcol(pescolrs[tcol]);
			ritpes(0);
			pcolcnt=0;
			for(ind=1;ind<hed.stchs;ind++){

				if(tcol==(stchs[ind].at&COLMSK))
					ritpes(ind);
				else{

					ritpes(ind);
					pestchs[opnt].x=(short)0x8001;
					pestchs[opnt++].y=0;
					ritpcol(pescolrs[tcol]);
					tcol=stchs[ind].at&COLMSK;
					ritpes(ind++);
					ritpes(ind);
					pestchs[opnt].x=(short)0x8003;
					pestchs[opnt++].y=0;
					ritpcol(pescolrs[tcol]);
					ritpes(ind);
					pcolcnt++;
				}
			}
			pestchs[opnt].x=ine;
			pestchs[opnt++].y=0;
			pesof=(unsigned*)&peshed.off;
			*pesof=(opnt<<2)+sizeof(PESHED);
			*peshed.m1=0x20;
			gpnt0=0;
			gpnt1=hed.stchs-1;
			peshed.xsiz=10000;
			peshed.ysiz=10000;
			WriteFile(hPcs,(PESHED*)&peshed,sizeof(PESHED),&wrot,0);
			WriteFile(hPcs,(PESTCH*)&bseq,opnt<<2,&wrot,0);
			ind=pesnam();
			pchr=(TCHAR*)&bseq;
			while(ind<512)
				pchr[ind++]=' ';
			pchr[19]=13;
			pchr[48]=(TCHAR)pcolcnt;
			pecdat();
			upnt=(unsigned*)&pchr[514];
			*upnt=opnt-512;
			pchr[517]=0x20;
			pchr[518]=-1;
			pchr[519]=-17;
			psiz=(short*)&pchr[520];
			*psiz=peshed.xsiz;
			psiz++;
			*psiz=peshed.ysiz;
			psiz++;
			*psiz=480;
			pesof=(unsigned*)psiz;
			*pesof=11534816;
//			pchr[527]=(TCHAR)0x0;
//			pchr[528]=(TCHAR)0x90;
//			pchr[529]=(TCHAR)0x0;
//			pchr[530]=(TCHAR)0x8f;
			pchr[527]=(TCHAR)0x00;
			pchr[528]=(TCHAR)0x80;	//hor	msb
			pchr[529]=(TCHAR)0x80; //hor lsb
			pchr[530]=(TCHAR)0x82; //vert msb
			pchr[531]=(TCHAR)0xff; //vert lsb
			WriteFile(hPcs,(TCHAR*)&bseq,opnt,&wrot,0);
			break;
#endif
		default:

			for(ind=0;ind<16;ind++)
				hed.fCols[ind]=useCol[ind];
			if(pcshup())
				return;
			if(!WriteFile(hPcs,&hed,0x46,&wrot,0)){

				riter();
				return;
			}
			filBuf=new PCSTCH[hed.stchs+colCnt+2];
			clrfbuf((sizeof(PCSTCH)*(hed.stchs+colCnt+1))>>2);
			stind=0;
			savcol=0xff;
			for(ind=0;ind<hed.stchs;ind++){

				if((stchsr[ind].at&COLMSK)!=savcol){

					savcol=stchsr[ind].at&COLMSK;
					filBuf[stind].typ=3;
					filBuf[stind++].fx=savcol;
				}
				frct=modf(stchsr[ind].x,&intg);
				filBuf[stind].fx=frct*256;
				filBuf[stind].x=intg;
				frct=modf(stchsr[ind].y,&intg);
				filBuf[stind].fy=frct*256;
				filBuf[stind++].y=intg;
			}
			if(!WriteFile(hPcs,filBuf,stind*sizeof(PCSTCH),&wrot,0)){

				riter();
				return;
			}
			if(chku(BSAVOF)){
		
				*msgbuf=0;
				if(!WriteFile(hPcs,msgbuf,15,&wrot,0)){

					riter();
					return;
				}
			}
			else{

				if(!WriteFile(hPcs,bnam,15,&wrot,0)){

					riter();
					return;
				}
			}
			delete filBuf;
		}
		defNam(filnam);
		CloseHandle(hPcs);
		if(chku(ROTAUX))
			filnopn(IDS_FILROT,auxnam);
	}
}

void savAs(){

	TCHAR*	pchr;

	if(hed.stchs||formpnt||*bnam){

		ofn.nFilterIndex=0;
		if(GetSaveFileName(&ofn)){

			_strlwr(filnam);
			pchr=strrchr(filnam,'.');
			if(!pchr)
				pchr=&filnam[strlen(filnam)];
			switch(ofn.nFilterIndex){

			case 1:

				strcpy(pchr,".thr");
				break;

			case 2:

				strcpy(pchr,".pcs");
				ini.auxfil=AUXPCS;
				auxmen();
				break;

			case 3:

				strcpy(pchr,".dst");
				ini.auxfil=AUXDST;
				auxmen();
				break;
			}
			setMap(SAVAS);
			nunams();
			ritini();
			rstMap(SAVAS);
			rstMap(CMPDO);
			thrsav();
			sav();
			SetWindowText(hWnd,thrnam);
		}
	}
}

void save(){

	TCHAR*	pchr;
	TCHAR	tchr;

	if(filnam[0]){

		pchr=strrchr(filnam,'.');
		if(pchr)
			pchr++;
		else{

			strcat(filnam,".thr");
			pchr=strrchr(filnam,'.')+1;
		}
		tchr=pchr[0]|0x20;
		thrsav();
		if(hed.stchs)
			sav();
	}
	else
		savAs();
}

COLORREF nuCol(COLORREF init){

	gCol.Flags=CC_ANYCOLOR|CC_RGBINIT;
	gCol.hwndOwner=hWnd;
	gCol.lCustData=0;
	gCol.lpCustColors=custCol;
	gCol.lpfnHook=0;
	gCol.lpTemplateName=0;
	gCol.rgbResult=init;
	gCol.lStructSize=sizeof(gCol);
	return ChooseColor(&gCol);
}

COLORREF nuBak(){

	bCol.Flags=CC_ANYCOLOR|CC_RGBINIT;
	bCol.hwndOwner=hWnd;
	bCol.lCustData=0;
	bCol.lpCustColors=bakCust;
	bCol.lpfnHook=0;
	bCol.lpTemplateName=0;
	bCol.rgbResult=stchBak;
	bCol.lStructSize=sizeof(bCol);
	return ChooseColor(&bCol);
}

COLORREF nuBit(){

	btCol.Flags=CC_ANYCOLOR|CC_RGBINIT;
	btCol.hwndOwner=hWnd;
	btCol.lCustData=0;
	btCol.lpCustColors=bakBit;
	btCol.lpfnHook=0;
	btCol.lpTemplateName=0;
	btCol.rgbResult=bitCol;
	btCol.lStructSize=sizeof(bCol);
	return ChooseColor(&btCol);
}

void pxCor2stch(POINT pnt){

	double	tdub;

	tdub=(double)(pnt.x-sRct.left)/scRct.right;
	sPnt.x=tdub*(zRct.right-zRct.left)+zRct.left;
	tdub=(double)(sRct.bottom-pnt.y)/scRct.bottom;
	sPnt.y=tdub*(zRct.top-zRct.bottom)+zRct.bottom;
}

/*
void pxCor2stch(POINT pnt){

	double	tdub;
	double	tx,ty;
	double	tr;

	tdub=(double)(pnt.x-sRct.left)/scRct.right;
	tx=tdub*(zRct.right-zRct.left)+zRct.left;
	sPnt.x=tx+0.5;
	tdub=(double)(sRct.bottom-pnt.y)/scRct.bottom;
	tr=(zRct.right-zRct.left)/stchAspct;
	ty=tdub*tr+zRct.bottom;
	sPnt.y=ty+0.5;
}*/

unsigned px2stch(){

	double	tdub;

	if(msg.pt.x>=sRct.left&&msg.pt.x<=sRct.right
		&&msg.pt.y>=sRct.top&&msg.pt.y<=sRct.bottom){

		tdub=(double)(msg.pt.x-sRct.left)/scRct.right;
		sPnt.x=tdub*(zRct.right-zRct.left)+zRct.left;
		tdub=(double)(sRct.bottom-msg.pt.y)/scRct.bottom;
		sPnt.y=tdub*(zRct.top-zRct.bottom)+zRct.bottom;
		return 1;
	}
	else
		return 0;
}

void shft2box(){

	sPnt.x=stchs[cloInd].x;
	sPnt.y=stchs[cloInd].y;
	shft(sPnt);
	stch2px1(cloInd);
}

void zumin(){

	DUBPNT		nusiz;
	FLRCT		srct;
	FLRCT*		trct;
	unsigned	ind;

	if(!rstMap(ZUMACT))
		zumFct*=ZUMFCT;
	if(zumFct<zumflor)
		zumFct=zumflor;
	if(!setMap(ZUMED))
		movStch();
	if(!rstMap(BZUMIN)){

		if(chkMap(GMRK)){

			sPnt.x=mrkpnt.x;
			sPnt.y=mrkpnt.y;
			goto gotc;
		}
		if(chkMap(FORMSEL)){

			trct=&formlst[clofind].rct;
			sPnt.x=((trct->right-trct->left)/2)+trct->left;
			sPnt.y=((trct->top-trct->bottom)/2)+trct->bottom;
			goto gotc;
		}
		if(chkMap(FRMPSEL)){

			sPnt.x=formlst[clofind].flt[clofine].x;
			sPnt.y=formlst[clofind].flt[clofine].y;
			goto gotc;
		}
		if(chkMap(SELBOX)){

			sPnt.x=stchs[cloInd].x;
			sPnt.y=stchs[cloInd].y;
			goto gotc;
		}
		if(chkMap(GRPSEL)){

			selRct(&srct);
			sPnt.x=((srct.right-srct.left)/2)+srct.left;
			sPnt.y=((srct.top-srct.bottom)/2)+srct.bottom;
			goto gotc;
		}
		if(chkMap(INSRT)){

			if(chkMap(LIN1)){

				if(chkMap(BAKEND)){

					sPnt.x=stchs[hed.stchs-1].x;
					sPnt.y=stchs[hed.stchs-1].y;
				}
				else{

					sPnt.x=stchs[0].x;
					sPnt.y=stchs[0].y;
				}
			}
			else{

				sPnt.x=(stchs[cloInd+1].x-stchs[cloInd].x)/2+stchs[cloInd].x;
				sPnt.y=(stchs[cloInd+1].y-stchs[cloInd].y)/2+stchs[cloInd].y;
			}
			goto gotc;
		}
		if(fselpnt){

			bigrct.bottom=formlst[selist[0]].rct.bottom;
			bigrct.top=formlst[selist[0]].rct.top;
			bigrct.left=formlst[selist[0]].rct.left;
			bigrct.right=formlst[selist[0]].rct.right;
			for(ind=1;ind<fselpnt;ind++){

				if(formlst[selist[ind]].rct.bottom<bigrct.bottom)
					bigrct.bottom=formlst[selist[ind]].rct.bottom;
				if(formlst[selist[ind]].rct.top>bigrct.top)
					bigrct.top=formlst[selist[ind]].rct.top;
				if(formlst[selist[ind]].rct.left<bigrct.left)
					bigrct.left=formlst[selist[ind]].rct.left;
				if(formlst[selist[ind]].rct.right>bigrct.right)
					bigrct.right=formlst[selist[ind]].rct.right;
			}
			sPnt.x=(bigrct.right-bigrct.left)/2+bigrct.left;
			sPnt.y=(bigrct.top-bigrct.bottom)/2+bigrct.bottom;
			goto gotc;
		}
		if(!px2stch())
			centr();
	}
gotc:;
	nusiz.x=zum0.x*zumFct;
	nusiz.y=nusiz.x/stchAspct;
	zRct.left=zRct.bottom=0;
	zRct.right=nusiz.x;
	zRct.top=nusiz.y;
	shft(sPnt);
	selCnt=0;
	if(!chkMap(GMRK)&&chkMap(SELBOX))
		shft2box();
	if(chkMap(RUNPAT)){

		FillRect(sdc,&scRct,hStchBak);
		runpnt=0;
	}
	duzrat();
	movins();
	setMap(RESTCH);
	ilin();
}

void zumhom(){

	zRct.bottom=0;
	zRct.left=0;
	zRct.right=zum0.x;
	zRct.top=zum0.y;
	zumFct=1;
	rstMap(ZUMED);
	movStch();
	selCnt=0;
	if(chkMap(RUNPAT)){

		FillRect(sdc,&scRct,hStchBak);
		runpnt=0;
	}
	setMap(RESTCH);
	if(chkMap(SELBOX))
		shft2box();
	duzrat();
	movins();
}

void zumshft(){

	POINT pnt;
	DUBPNT spnt;

	if(chkMap(ZUMED)){
	
		unboxs();
		if(px2stch()){
			selCnt=0;
			shft(sPnt);
			spnt.x=sPnt.x;
			spnt.y=sPnt.y;
			sCor2px(spnt,&pnt);
			if(chkMap(RUNPAT)){

				FillRect(sdc,&scRct,hStchBak);
				runpnt=0;
			}
			setMap(RESTCH);
		}
	}
	movins();
}

void zumout(){

	POINT	nusiz;
	FLRCT	srct;
	FLRCT*	trct;

	unboxs();
	if(chkMap(ZUMED)){

		if(chkMap(GMRK)){

			sPnt.x=mrkpnt.x;
			sPnt.y=mrkpnt.y;
			goto gots;
		}
		if(chkMap(FORMSEL)){

			trct=&formlst[clofind].rct;
			sPnt.x=((trct->right-trct->left)/2)+trct->left;
			sPnt.y=((trct->top-trct->bottom)/2)+trct->bottom;
			goto gots;
		}
		if(chkMap(FRMPSEL)){

			sPnt.x=formlst[clofind].flt[clofine].x;
			sPnt.y=formlst[clofind].flt[clofine].y;
			goto gots;
		}
		if(chkMap(SELBOX)||chkMap(INSRT)){

			sPnt.x=stchs[cloInd].x;
			sPnt.y=stchs[cloInd].y;
			goto gots;
		}
		if(chkMap(GRPSEL)){

			selRct(&srct);
			sPnt.x=((srct.right-srct.left)/2)+srct.left;
			sPnt.y=((srct.top-srct.bottom)/2)+srct.bottom;
			goto gots;
		}
		if(chkMap(SELBOX)){

			shft2box();
			goto gots;
		}
		if(!px2stch())
			centr();
gots:;
		zumFct/=ZUMFCT;
		if(zumFct>0.98){

			zumFct=1;
			rstMap(ZUMED);
			zRct.bottom=0;
			zRct.left=0;
			zRct.right=zum0.x;
			zRct.top=zum0.y;
			movStch();
			selCnt=0;
		}
		else{

			nusiz.x=zum0.x*zumFct;
			nusiz.y=nusiz.x/stchAspct;
			zRct.left=zRct.bottom=0;
			zRct.top=nusiz.y;
			zRct.right=nusiz.x;
			shft(sPnt);
		}
		if(chkMap(RUNPAT)){

			FillRect(sdc,&scRct,hStchBak);
			runpnt=0;
		}
		setMap(RESTCH);
		duzrat();
		movins();
	}
}

void duClos(unsigned strt,unsigned cnt){

	unsigned	ind,ine,tind0,tind1;
	double		sum,tsum;
	long		cx,cy;

	for(ind=strt;ind<strt+cnt;ind++){

		cx=abs(stchs[ind].x-sPnt.x);
		cy=abs(stchs[ind].y-sPnt.y);
		sum=hypot(cx,cy);
		tind0=ind;
		for(ine=0;ine<NERCNT;ine++){

			if(sum<ner[ine]){

				tsum=ner[ine];
				tind1=nerInd[ine];
				ner[ine]=sum;
				nerInd[ine]=tind0;
				sum=tsum;
				tind0=tind1;
			}
		}
	}
}

void closPnt(){

	unsigned	ind,sind0,sind1;

	unbox();
	unboxs();
	for(ind=0;ind<4;ind++){

		ner[ind]=1e99;
		nerInd[ind]=-1;
	}
	px2stch();
	for(ind=0;ind<colCnt;ind++){

		sind0=colch[ind].stind;
		sind1=colch[ind+1].stind;
		if(chkMap(HID)){

			if(colch[ind].colind==actcol)
				duClos(sind0,sind1-sind0);
		}
		else
			duClos(sind0,sind1-sind0);
	}
	GetClientRect(hStch,&scRct);
	for(ind=0;ind<NERCNT;ind++){

		if(stch2px(nerInd[ind])){
			
			nerInd[selCnt]=nerInd[ind];
			pxNer[selCnt].x=pPnt.x;
			pxNer[selCnt++].y=pPnt.y;
		}
	}
	boxs();
}

unsigned closPnt1(unsigned* clo){

	unsigned	ind,ine,tclo=0;
	unsigned	layr;
	long		nerSid;
	double		cx,cy;
	POINT		chkPnt;
	double		tsum=1e99;

	chkPnt.x=msg.pt.x-stOrg.x;
	chkPnt.y=msg.pt.y-stOrg.y;
	if(chkMap(SELBOX)&&stch2px(cloInd)){

		if(hypot(pPnt.x-chkPnt.x,pPnt.y-chkPnt.y)<CLOSENUF){

			*clo=cloInd;
			return 1;
		}
	}
	for(ind=0;ind<selCnt;ind++){

		nerSid=boxOff[ind];
		if(	chkPnt.x>=pxNer[ind].x-nerSid&&
			chkPnt.x<=pxNer[ind].x+nerSid&&
			chkPnt.y>=pxNer[ind].y-nerSid&&
			chkPnt.y<=pxNer[ind].y+nerSid){

			*clo=nerInd[ind];
			return 1;
		}
	}
	px2stch();
	cloSum=1e99;
	if(chkMap(HID)){

		for(ind=0;ind<colCnt;ind++){

			if(colch[ind].colind==actcol){

				for(ine=colch[ind].stind;ine<colch[ind+1].stind;ine++){

					if(	stchs[ine].x>=zRct.left&&
						stchs[ine].x<=zRct.right&&
						stchs[ine].y>=zRct.bottom&&
						stchs[ine].y<=zRct.top){

						cx=abs(stchs[ine].x-sPnt.x);
						cy=abs(stchs[ine].y-sPnt.y);
						tsum=hypot(cx,cy);
						if(tsum<cloSum){

							cloSum=tsum;
							tclo=ine;
						}
					}
				}
			}
		}
	}
	else{

		for(ind=0;ind<hed.stchs;ind++){

			layr=(stchs[ind].at&LAYMSK)>>LAYSHFT;
			if(!actl||!layr||layr==actl){

				if(	stchs[ind].x>=zRct.left&&
					stchs[ind].x<=zRct.right&&
					stchs[ind].y>=zRct.bottom&&
					stchs[ind].y<=zRct.top){

					cx=stchs[ind].x-sPnt.x;
					cy=stchs[ind].y-sPnt.y;
					tsum=hypot(cx,cy);
					if(tsum<cloSum){

						cloSum=tsum;
						tclo=ind;
					}
				}
			}
		}
	}
	if(cloSum==1e99)
		return 0;
	else{

		stch2px(tclo);
		if(chkMap(IGNTHR)){

			*clo=tclo;
			return 1;
		}
		else{

			if(hypot(chkPnt.x-pPnt.x,chkPnt.y-pPnt.y)<CLOSENUF){

				*clo=tclo;
				return 1;
			}
			else
				return 0;
		}
	}
}

unsigned pt2colInd(unsigned pInd){

	unsigned ind;

	for(ind=0;ind<colCnt;ind++){

		if(colch[ind].stind>pInd)
			break;
	}
	return ind;
}

void unthum(){

	unsigned ind;

	if(rstMap(THUMSHO)){

		for(ind=0;ind<4;ind++)
			DestroyWindow(hvu[ind]);
		if(chkMap(UPTO))
			butxt(HUPTO,stab[STR_UPON]);
		else
			butxt(HUPTO,stab[STR_UPOF]);
		butxt(HNUM,"");
		redraw(hbuts[HHID]);
		butxt(HBOXSEL,stab[STR_BOXSEL]);
	}
}

void toglup(){

	if(toglMap(UPTO))
		butxt(HUPTO,stab[STR_UPOF]);
	else{

		if(rstMap(GRPSEL)){

			rngadj();
			cloInd=gpnt0;
			setMap(SELBOX);
			rstMap(FRMPSEL);
		}
		else{

			if(!chkMap(SELBOX)){

				cloInd=0;
				if(rstMap(FORMSEL)){

					while(cloInd<hed.stchs&&notfstch(stchs[cloInd].at))
						cloInd++;
					setMap(SELBOX);
					rstMap(FRMPSEL);
				}
			}
		}
		butxt(HUPTO,stab[STR_UPON]);
	}
	setMap(RESTCH);
}

void toglHid(){

	if(toglMap(HID))
		rstMap(FRMOF);
	else
		setMap(FRMOF);
	unthum();
	redraw(hbuts[HHID]);
	setMap(RESTCH);
}

void dulin(){

	SelectObject(rsdc,lPen);
	SetROP2(rsdc,R2_NOTXORPEN);
	if(mlin0[0].x==mlin1[1].x&&mlin0[0].y==mlin1[1].y){

		if(chkMap(ISDWN)){
			
			Polyline(rsdc,mlin0,2);
			goto dux;
		}
		else{

			Polyline(rsdc,mlin1,2);
			goto dux;
		}
	}
	else{

		if(chkMap(ISDWN))
			Polyline(rsdc,mlin0,2);
		if(chkMap(ISUP))
			Polyline(rsdc,mlin1,2);
	}
dux:;
	SetROP2(rsdc,R2_COPYPEN);
	toglMap(WASLIN);
}

void unlin(){

	if(chkMap(WASLIN))
		dulin();
}

void movbox(){

	if(stch2px(cloInd)){

		unbox();
		dubox();
		if(chkMap(UPTO))
			setMap(RESTCH);
	}
	else{

		shft2box();
		setMap(SELBOX);
		rstMap(FRMPSEL);
		setMap(RESTCH);
	}
	nuAct(cloInd);
	ritcor(&stchs[cloInd]);
}

BOOL chkhid(unsigned cpnt){

	if(chkMap(HID)){

		if(colch[cpnt].colind==actcol)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

/*
This function attempts to find the stitch the user is trying to select.
A rectangle is created that is slightly larger than the stitch.
If the mouse position is outside this rectangle, the stitch is disqualified.
If the mouse position is inside the rectangle, the distance from the stitch
 to the select point (sPnt) is calculated.

Find the equation for the line by solving the linear parametric eauations

  stchs[ind].x+slop*stchs[ind].y=off
  stchs[ind+1].x+slop*stchs[ind+1].y=off

substituting:

  stchs[ind].x+slop*stchs[ind].y=stchs[ind+1].x+slop*stchs[ind+1].y

collecting terms:

  slop*stchs[ind].y-slop*stchs[ind-1].y=stchs[ind+1].x-stchs[ind].x
  slop*(stchs[ind].y-stchs[ind-1].y)=stchs[ind+1].x-stchs[ind].x
  slop=(stchs[ind+1].x-stchs[ind].x)/(stchs[ind].y-stchs[ind-1].y)

define xba=stchs[ind+1].x-stchs[ind].x
define yab=stchs[ind].y-stchs[ind+1].y

  slop=xba/yab;

back substituting into stchs[ind].x+slop*stchs[ind].y=off

  off=stchs[ind].x+slop*stchs[ind].y

The equation for a point vertical to the equation for the line and running
 through sPnt is:

  sPnt.x-sPnt.y/slop=poff

If ipnt is the intersections between the two lines then

  ipnt.x-slop*ipnt.y=off
  ipnt.x+ipnt.y/slop=poff

Subtracting the two equations

  slop*ipnt.y+ipnt.y/slop=off-poff

Multiply by slop

  slop*slop*ipnt.y+ipnt.y=slop(off-poff)
  ipnt.y(slop*slop+1)=slop(off-poff)
  ipnt.y=slop*(off-poff)/(slop*slop+1)

back substitute into ipnt.x+slop*ipnt.y=off

  ipnt.x=off-slop*ipnt.y

if dx=ipnt.x-spnt.x & dy=ipnt.y-spnt.y

the distance from the point to the line is given by

  sqrt(dx*dx+dy*dy)
*/

unsigned closlin(){

	unsigned	ind,ine,scnt,clos=0xffffffff;
	double		sum=1e99;
	long		xba,yab;
	double		tsum;
	FRCT		trct;
	double		slop,off,poff,tol,dx,dy;
	DUBPNT		ipnt;
	DUBPNT		chkpnt;
	SHRTPNT*	pstch;
	unsigned	layr;

#define		TOL	20

	unboxs();
 	off=(float)(msg.pt.x-sRct.left)/(sRct.right-sRct.left);
	chkpnt.x=off*(zRct.right-zRct.left)+zRct.left;
	off=(float)(sRct.bottom-msg.pt.y)/(sRct.bottom-sRct.top);
	chkpnt.y=(off*(zRct.top-zRct.bottom)+zRct.bottom);
	off=(double)(zRct.right-zRct.left)/scRct.right;
	tol=off*TOL;
	for(ine=0;ine<colCnt;ine++){

		scnt=colch[ine+1].stind-colch[ine].stind;
		pstch=&stchs[colch[ine].stind];
		if(chkhid(ine)){

			for(ind=0;ind<scnt;ind++){

				layr=(pstch[ine].at&LAYMSK)>>LAYSHFT;
				if(!actl||!layr||(layr==actl)){

					xba=pstch[ind+1].x-pstch[ind].x;
					yab=pstch[ind].y-pstch[ind+1].y;
					if(xba>0){

						trct.left=pstch[ind].x-tol;
						trct.right=pstch[ind+1].x+tol;
					}
					else{

						trct.left=pstch[ind+1].x-tol;
						trct.right=pstch[ind].x+tol;
					}
					if(yab<0){

						trct.bottom=pstch[ind].y-tol;
						trct.top=pstch[ind+1].y+tol;
					}
					else{
			
						trct.bottom=pstch[ind+1].y-tol;
						trct.top=pstch[ind].y+tol;
					}
					if(chkpnt.x>trct.left&&chkpnt.x<trct.right
						&&chkpnt.y>trct.bottom&&chkpnt.y<trct.top){

						if(yab==0){

							//stitch is horizontal
							ipnt.x=chkpnt.x;
							ipnt.y=pstch[ind].y;
							tsum=abs(pstch[ind].y-chkpnt.y);
							goto gotsum;
						}
						if(xba==0){
			
							//stitch is vertical
							dx=pstch[ind].x-chkpnt.x;
							trct.top-=tol;
							trct.bottom+=tol;
							if(chkpnt.y>trct.top){
			
								dy=chkpnt.y-trct.top;
								tsum=hypot(dx,dy);
								goto gotal;
							}
							if(chkpnt.y<trct.bottom){
			
								dy=chkpnt.y-trct.bottom;
								tsum=hypot(dx,dy);
								goto gotal;
							}
							tsum=fabs(dx);
							goto gotal;
						}
						slop=(double)xba/yab;
						off=pstch[ind].x+slop*pstch[ind].y;
						poff=chkpnt.x-chkpnt.y/slop;
						ipnt.y=slop*(off-poff)/(slop*slop+1);
						ipnt.x=off-slop*ipnt.y;
						dx=ipnt.x-chkpnt.x;
						dy=ipnt.y-chkpnt.y;
						tsum=hypot(dx,dy);
gotsum:;
						trct.bottom+=tol;
						trct.top-=tol;
						trct.left+=tol;
						trct.right-=tol;
						if(ipnt.x<trct.left){
			
							if(ipnt.y<trct.bottom)
								tsum=sqrt(abs(chkpnt.x-trct.left)+abs(chkpnt.y-trct.bottom));
							else
								tsum=sqrt(abs(chkpnt.x-trct.left)+abs(chkpnt.y-trct.top));
						}
						else{
						
							if(ipnt.x>trct.right){
			
								if(ipnt.y<trct.bottom)
									tsum=sqrt(abs(chkpnt.x-trct.right)+abs(chkpnt.y-trct.bottom));
								else
									tsum=sqrt(abs(chkpnt.x-trct.right)+abs(chkpnt.y-trct.top));
							}
						}
gotal:;
						if(tsum<sum){
							
							sum=tsum;
							clos=ind+colch[ine].stind;
						}
					}
				}
			}
		}
	}
	if(sum>tol)
		return 0xffffffff;
	else
		return clos;
}

void ilin(){

	SelectObject(rsdc,lPen);
	SetROP2(rsdc,R2_NOTXORPEN);
	Polyline(rsdc,inlin,2);
	SetROP2(rsdc,R2_XORPEN);
	Polyline(rsdc,&inlin[1],2);
	SetROP2(rsdc,R2_COPYPEN);
	SelectObject(sdc,lPen);
	SetROP2(sdc,R2_NOTXORPEN);
	Polyline(sdc,inlin,2);
	SetROP2(sdc,R2_XORPEN);
	Polyline(sdc,&inlin[1],2);
	SetROP2(sdc,R2_COPYPEN);
}

void xlin(){

	if(rstMap(ILIN))
		ilin();
}

void ilin1(){

	SelectObject(rsdc,lPen);
	SetROP2(rsdc, R2_NOTXORPEN);
	Polyline(rsdc,inlin,2);
	SetROP2(rsdc,R2_COPYPEN);
}

void xlin1(){

	if(rstMap(ILIN1))
		ilin1();
}

void duIns(){

	POINT tlin[2];

	inlin[1].x=msg.pt.x-stOrg.x;
	inlin[1].y=msg.pt.y-stOrg.y;
	stch2px1(cloInd);
	tlin[0].x=inlin[0].x=pPnt.x;
	tlin[0].y=inlin[0].y=pPnt.y;
	stch2px1(cloInd+1);
	tlin[1].x=inlin[2].x=pPnt.x;
	tlin[1].y=inlin[2].y=pPnt.y;
	xlin();
	setMap(ILIN);
	ilin();
}

void istch(){

	double angb,angf,angt;

	xlin();
	xlin1();
	if(chkMap(SELBOX)){

		if(cloInd&&cloInd!=(unsigned)hed.stchs-1){

			px2stch();
			angt=atan2(stchs[cloInd].y-sPnt.y,stchs[cloInd].x-sPnt.x);
			angb=atan2(stchs[cloInd].y-stchs[cloInd-1].y,stchs[cloInd].x-stchs[cloInd-1].x);
			angf=atan2(stchs[cloInd].y-stchs[cloInd+1].y,stchs[cloInd].x-stchs[cloInd+1].x);
			if(fabs(angf-angt)>fabs(angb-angt))
				cloInd--;
		}
		else{

			if(cloInd==(unsigned)hed.stchs-1)
				cloInd--;
		}
	}
	else
		cloInd=closlin();
	if(cloInd==-1)
		rstMap(INSRT);
	else{

		setMap(INSRT);
		duIns();
		SetCapture(hWnd);
		ritnum(STR_NUMSEL,cloInd);
		nuAct(cloInd);
	}
}

void cros(unsigned ind){

	long pwid=boxOff[0];

	stch2px1(ind);
	inlin[0].x=pPnt.x-pwid;
	inlin[1].y=inlin[0].y=pPnt.y;
	inlin[1].x=pPnt.x+pwid;
	SelectObject(rsdc,xPen);
	SetROP2(rsdc, R2_NOTXORPEN);		
	Polyline(rsdc,inlin,2);
	SelectObject(sdc,xPen);
	SetROP2(sdc, R2_NOTXORPEN);		
	Polyline(sdc,inlin,2);
	inlin[0].y=pPnt.y-pwid;
	inlin[0].x=inlin[1].x=pPnt.x;
	inlin[1].y=pPnt.y-1;
	Polyline(rsdc,inlin,2);
	Polyline(sdc,inlin,2);
	inlin[0].y=pPnt.y+2;
	inlin[1].y=pPnt.y+pwid;
	Polyline(rsdc,inlin,2);
	SetROP2(rsdc,R2_COPYPEN);
	Polyline(sdc,inlin,2);
	SetROP2(sdc,R2_COPYPEN);
}

void mark(){

	if(chkMap(SELBOX)||chkMap(INSRT)||closPnt1(&cloInd)){
	
		unbox();
		xlin();
		rstMap(CAPT);
		rstMap(SELBOX);
		rstMap(INSRT);
		rstMap(SCROS);
		rstMap(ECROS);
		grpInd=cloInd;
		setMap(GRPSEL);
	}
}

void selCol()
{
	unsigned ind,col;

	if(hed.stchs)
	{
		if(chkMap(SELBOX))
			ind=cloInd;
		else
		{
			if(chkMap(GRPSEL))
				ind=grpInd;
			else
				ind=0;
		}
		if(ind>(unsigned)hed.stchs-1)
			ind=hed.stchs-1;
		cloInd=grpInd=ind;
		col=stchs[ind].at&COLMSK;
		while(cloInd&&(stchs[cloInd].at&COLMSK)==col)
			cloInd--;
		if((stchs[cloInd].at&COLMSK)!=col)
			cloInd++;
		while(grpInd<hed.stchs&&(stchs[grpInd].at&COLMSK)==col)
			grpInd++;
		if((stchs[cloInd].at&COLMSK)!=col)
			cloInd--;
		if(grpInd>(unsigned)hed.stchs-1)
			grpInd=hed.stchs-1;
		setMap(GRPSEL);
		unbox();
		grpAdj();
		actcol=col;
		setMap(RESTCH);
	}
}

void nuAct(unsigned ind){

	unsigned tcol;

	tcol=actcol;
	actcol=stchs[ind].at&COLMSK;
	redraw(hCol[tcol]);
	redraw(hCol[actcol]);
}

void newFil(){

	unsigned ind;

	rstMap(CMPDO);
	if(bnam[0]){

		bnam[0]=0;
		DeleteObject(hBmp);
		ReleaseDC(hWnd,bitdc);
	}
	sprintf(msgbuf,stab[STR_THRED],ini.desnam);
	deldu();
	SetWindowText(hWnd,msgbuf);
	strcpy(thrnam,stab[STR_NUFIL]);
	ritfnam(ini.desnam);
	strcpy(hedx.modnam,ini.desnam);
	rstdu();
	rstAll();
	clrhbut(3);
	rstMap(MOVSET);
	hed.ledIn=0x32;
	hed.fColCnt=16;
	unbox();
	xlin();
	xlin1();
	rstMap(INIT);
	rstMap(INSRT);
	rstMap(LIN1);
	rstMap(FORMSEL);
	rstMap(BAKACT);
	rstMap(GMRK);
	hed.stchs=0;
	cbit=0;
	bnam[0]=0;
	hed.stchs=0;
	fltad=0;
	clpad=0;
	txad=0;
	satkad=0;
	formpnt=0;
	filnam[0]=0;
	colCnt=0;
	knotcnt=0;
	for(ind=0;ind<16;ind++){

		redraw(hDef[ind]);
		redraw(hCol[ind]);
		redraw(hSiz[ind]);
	}
	zumhom();
}

void bBox(){

	SetROP2(rsdc, R2_NOTXORPEN);
	SelectObject(rsdc,lPen);
	Polyline(rsdc,blin,5);
	SetROP2(rsdc,R2_COPYPEN);
}

void unbBox(){

	if(rstMap(BZUM))
		bBox();
}

void rebox(){

	unsigned ind;

	unbox();
	if(closPnt1(&cloInd)){

		nuAct(cloInd);
		if(stch2px(cloInd))
			dubox();
		if(rstMap(GRPSEL)){

			rstMap(SCROS);
			rstMap(ECROS);
			slpnt=0;
			setMap(RESTCH);
			for(ind=0;ind<16;ind++)
				redraw(hCol[ind]);
		}
		ritcor(&stchs[cloInd]);
	}
}

void endpnt(){

	unbox();
	xlin();
	xlin1();
	setMap(LIN1);
	setMap(INSRT);
	rstMap(GRPSEL);
	inlin[0].x=pPnt.x;
	inlin[0].y=pPnt.y;
	inlin[1].x=msg.pt.x-stOrg.x;
	inlin[1].y=msg.pt.y-stOrg.y;
}

void delstchm(){

	unsigned ind,dst;

	rngadj();
	dst=gpnt0;
	for(ind=gpnt1;ind<hed.stchs;ind++){

		stchs[dst].at=stchs[ind].at;
		stchs[dst].x=stchs[ind].x;
		stchs[dst++].y=stchs[ind].y;
	}
	hed.stchs=dst-1;
}

void unsid(){

	sidtyp=0;
	if(hSid){

		DestroyWindow(hSid);
		hSid=0;
	}
}

void unbsho(){

	unsigned ind;

	if(rstMap(BAKSHO)){

		for(ind=0;ind<OLDVER;ind++)
			DestroyWindow(hvu[ind]);
	}
}

BOOL oldwnd(HWND hwnd){

	unsigned ind;

	for(ind=0;ind<16;ind++){

		if(hDef[ind]==hwnd||hCol[ind]==hwnd||hSiz[ind]==hwnd)
			return 0;
	}
	for(ind=0;ind<9;ind++){

		if(hbuts[ind]==hwnd)
			return 0;
	}
	if(hStch==hwnd)
		return 0;
	if(hVrt==hwnd)
		return 0;
	if(hHor==hwnd)
		return 0;
	if(hBar==hwnd)
		return 0;
	if(hmin==hwnd)
		return 0;
	if(hSped==hwnd)
		return 0;
	return 1;
}

BOOL CALLBACK EnumChildProc(HWND hwnd,LPARAM lParam){

	if(oldwnd(hwnd))
		return DestroyWindow(hwnd);
	else{

		if(fwnd){

			if(fwnd==hwnd)
				return 0;
			else
				return TRUE;
		}
		else{

			fwnd=hwnd;
			return TRUE;
		}
	}
}

void insadj(){

	rstMap(PRELIN);
	fvars(clofind);
	refil();
	coltab();
	frmout(clofind);
}

void rstAll(){

	rstMap(WASFPNT);
	rstMap(WASFRMFRM);
	rstMap(FPUNCLP);
	rstMap(FPSEL);
	rstMap(CAPT);
	rstMap(INSRT);
	rstMap(SELBOX);
	rstMap(GRPSEL);
	rstMap(SCROS);
	rstMap(ECROS);
	rstMap(LIN1);
	rstMap(CLPSHO);
	rstMap(SELPNT);
	rstMap(ROTAT);
	rstMap(ROTCAPT);
	rstMap(FRMPMOV);
	rstMap(MOVFRM);
	rstMap(SATCNKT);
	rstMap(FRMPSEL);
	rstMap(SHOINSF);
	rstMap(STRTCH);
	rstMap(SHOSTRTCH);
	rstMap(EXPAND);
	rstMap(POLIMOV);
	rstMap(BZUMIN);
	rstMap(OSAV);
	rstMap(SAVEX);
	rstMap(MOVFRMS);
	rstMap(FRMROT);
	rstMap(DELSFRMS);
	rstMap(BIGBOX);
	rstMap(UPTO);
	rstMap(LENSRCH);
	rstMap(WASGRP);
	rstMap(BOXZUM);
	rstMap(HIDSTCH);
	rstMap(ENTRPOL);
	rstMap(ENTRSTAR);
	rstMap(ENTRSPIR);
	rstMap(ENTRHART);
	rstMap(FORMIN);
	rstMap(GTUANG);
	rstMap(GTUSPAC);
	rstMap(GTWLKIND);
	rstMap(GTWLKLEN);
	untrace();
	rstMap(WASEDG);
	butxt(HUPTO,stab[STR_UPOF]);
	if(zumFct==1)
		rstMap(ZUMED);
	movStch();
	ShowWindow(hStch,TRUE);
	unbsho();
	rstMap(SIDACT);
	unsid();
	rstMap(PRFACT);
	rstMap(WASRT);
	DestroyWindow(hPrf);
	undat();
	if(rstMap(INSFRM))
		insadj();
	rstMap(FUNCLP);
	if(rstMap(SATPNT))
		satfix();
	if(rstMap(RUNPAT))
		patdun();
	rstMap(FORMSEL);
	rstMap(FRMPSEL);
	unmsg();
	slpnt=fselpnt=0;
	fwnd=0;
	while(EnumChildWindows(hStch,EnumChildProc,0));
}

void rstdu(){

	deldu();	
	rstMap(REDUSHO);
	rstMap(UNDUSHO);
	EnableMenuItem(hMen,M_UNDO,MF_BYPOSITION|MF_GRAYED);
	EnableMenuItem(hMen,M_REDO,MF_BYPOSITION|MF_GRAYED);
	setMap(DUMEN);
}

CLPSTCH* deref(void* pnt){
	return *(CLPSTCH **)pnt;
}

void duclp(){

	SetROP2(rsdc,R2_NOTXORPEN);
	SelectObject(rsdc,lPen);
	Polyline(rsdc,clplin,5);
	SetROP2(rsdc,R2_COPYPEN);
}

void unclp(){

	if(rstMap(CLPSHO))
		duclp();
}

void dusel(HDC dc){

	unsigned ind;

	SetROP2(dc,R2_NOTXORPEN);
	SelectObject(dc,lPen);
	Polyline(dc,rctlin,9);
	for(ind=0;ind<8;ind++)
		selsqr(rctlin[ind],dc);
	SetROP2(dc,R2_COPYPEN);
}

void unsel(){

	if(rstMap(SELSHO))
		dusel(rsdc);
}

void clpbox(){

	SIZE	clpx;
	double	tdub;

	px2stch();
	if(sPnt.x+clpsiz.cx>zum0.x)
		sPnt.x=zum0.x-clpsiz.cx;
	if(sPnt.y+clpsiz.cy>zum0.y)
		sPnt.y=zum0.y-clpsiz.cy;
	clporg.x=sPnt.x;
	clporg.y=sPnt.y;
	tdub=(double)scRct.right/(zRct.right-zRct.left);
	clpx.cx=clpsiz.cx*tdub+0.5;
	clpx.cy=clpsiz.cy*tdub+0.5;
#pragma warning(disable:4244;once:)	
	pPnt.x=(sPnt.x-zRct.left)*tdub+0.5;
#pragma warning(disable:4244;once:)	
	pPnt.y=scRct.bottom-(sPnt.y-zRct.bottom)*tdub+0.5-clpx.cy;
	clplin[0].x=clplin[3].x=clplin[4].x=pPnt.x;
	clplin[0].y=clplin[1].y=clplin[4].y=pPnt.y;
	clplin[1].x=clplin[2].x=clplin[0].x+clpx.cx;
	clplin[2].y=clplin[3].y=clplin[0].y+clpx.cy;
	setMap(CLPSHO);
	duclp();
}

void lodclp(unsigned ind){

	FLPNT		padj;
	unsigned	src,dst;

	if(ind!=hed.stchs)
		ind++;
	padj.x=clporg.x-clprct.left;
	padj.y=clporg.y-clprct.bottom;
	if(ind<(unsigned)hed.stchs&&chkMap(INIT)){

		src=hed.stchs-1;
		dst=hed.stchs+clplen-1;
		while(src>=ind){

			stchs[dst].x=stchs[src].x;
			stchs[dst].y=stchs[src--].y;
			stchs[dst--].at=stchs[src].at;
		}
	}
	cloInd=ind;
	for(src=0;src<clplen;src++){

		stchs[ind].x=clpnu[src].x+padj.x;
		stchs[ind].y=clpnu[src].y+padj.y;
		stchs[ind++].at=clpnu[src].at&COLMSK|laycod|NOTFRM;
	}
	grpInd=ind-1;
	setMap(GRPSEL);
	hed.stchs+=clplen;
	if(hed.stchs)
		setMap(INIT);
}

void rSelbox(){

	SIZE	selx;
	double	tdub;

	unsel();
	px2stch();
	if(sPnt.x-selof.x+selsiz.cx>=zum0.x)
		sPnt.x=zum0.x-selsiz.cx+selof.x;
	if(sPnt.y-selof.y+selsiz.cy>=zum0.y)
		sPnt.y=zum0.y-selsiz.cy+selof.y;
	if(sPnt.x-selof.x<0)
		sPnt.x=selof.x;
	if(sPnt.y-selof.y<0)
		sPnt.y=selof.y;
	tdub=(double)scRct.right/(zRct.right-zRct.left);
	selx.cx=selsiz.cx*tdub+0.5;
	selx.cy=selsiz.cy*tdub+0.5;
#pragma warning(disable:4244;once:)	
	pPnt.x=(sPnt.x-zRct.left-selof.x)*tdub+0.5;
#pragma warning(disable:4244;once:)	
	pPnt.y=scRct.bottom-(sPnt.y-zRct.bottom-selof.y)*tdub+0.5-selx.cy;
	rctlin[0].x=rctlin[6].x=rctlin[7].x=rctlin[8].x=pPnt.x;
	rctlin[1].x=rctlin[5].x=pPnt.x+selx.cx/2;
	rctlin[0].y=rctlin[1].y=rctlin[2].y=rctlin[8].y=pPnt.y;
	rctlin[3].y=rctlin[7].y=pPnt.y+selx.cy/2;
	rctlin[4].y=rctlin[5].y=rctlin[6].y=pPnt.y+selx.cy;
	rctlin[2].x=rctlin[3].x=rctlin[4].x=pPnt.x+selx.cx;
	setMap(SELSHO);
	dusel(rsdc);
}

void duSelbox(){

	px2stch();
	selsiz.cx=rngrct.right-rngrct.left;
	selsiz.cy=rngrct.top-rngrct.bottom;
	selof.x=sPnt.x-rngrct.left;
	selof.y=sPnt.y-rngrct.bottom;
}

void setbak(unsigned wid){

	if(bakwid!=wid)
		bakPen=nuPen(bakPen,wid,stchBak);
}

void stchbox(unsigned ind,HDC dc){

	POINT		stlin[5];
	unsigned	layr;

	layr=(stchs[ind].at&LAYMSK)>>LAYSHFT;
	if(!actl||!layr||layr==actl){

		stch2px1(ind);
		stlin[0].x=stlin[3].x=stlin[4].x=pPnt.x-ini.stchpix;
		stlin[0].y=stlin[1].y=pPnt.y-ini.stchpix;
		stlin[1].x=stlin[2].x=pPnt.x+ini.stchpix;
		stlin[2].y=stlin[3].y=pPnt.y+ini.stchpix;
		stlin[4].y=pPnt.y-ini.stchpix;
		Polyline(dc,stlin,5);
	}
}

void sCor2px(DUBPNT stpnt,POINT* pxpnt){

#pragma warning(disable:4244;once:)		
	pxpnt->x=(stpnt.x-zRct.left)*zrat.x+0.5;
#pragma warning(disable:4244;once:)
	pxpnt->y=scRct.bottom+(zRct.bottom-stpnt.y)*zrat.y+0.5;
}

void sdCor2px(SHRTPNT stpnt,POINT* pxpnt){

#pragma warning(disable:4244;once:)		
	pxpnt->x=(stpnt.x-zRct.left)*zrat.x+0.5;
#pragma warning(disable:4244;once:)
	pxpnt->y=scRct.bottom+(zRct.bottom-stpnt.y)*zrat.y+0.5;
}

void durot(){

	SetROP2(rsdc,R2_NOTXORPEN);
	SelectObject(rsdc,lPen);
	Polyline(rsdc,rlinb,5);
	Polyline(rsdc,rlinv,2);
	Polyline(rsdc,rlinh,2);
	SetROP2(rsdc,R2_COPYPEN);
}

void unrot(){

	if(rstMap(ROTSHO))
		durot();
}

void durotu(){

	SetROP2(rsdc, R2_NOTXORPEN);
	SelectObject(rsdc,lPen);
	Polyline(rsdc,rlinu,2);
	SetROP2(rsdc,R2_COPYPEN);
}

void unrotu(){

	if(rstMap(ROTUSHO))
		durotu();
}

void rotang(DUBPNT rpnt,POINT* tpnt){

	double	len,ang0;
	DUBPNT	ipnt;
	long	dx,dy;

	dx=rpnt.x-rotcntr.x;
	dy=rpnt.y-rotcntr.y;
	if(dx){

		len=hypot(dx,dy);
		ang0=atan2(dy,dx);
		ang0+=ang;
	}
	else{

		len=abs(dy);
		if(dy>0)
			ang0=PI/2+ang;
		else
			ang0=ang-PI/2;
	}
	ipnt.y=rotcntr.y+len*sin(ang0);
	ipnt.x=rotcntr.x+len*cos(ang0);
	sCor2px(ipnt,tpnt);
}

void rotang1(SHRTPNT rpnt,FLPNT* tpnt){

	double	len,ang0;
	double	dx,dy;

	dx=rpnt.x-rotcntr.x;
	dy=rpnt.y-rotcntr.y;
	if(dx){

		len=hypot(dx,dy);
		ang0=atan2(dy,dx);
		ang0+=ang;
	}
	else{

		len=abs(dy);
		if(dy>0)
			ang0=PI/2+ang;
		else
			ang0=ang-PI/2;
	}
	tpnt->y=rotcntr.y+len*sin(ang0);
	tpnt->x=rotcntr.x+len*cos(ang0);
}

void rotangf(FLPNT rpnt,FLPNT* tpnt){

	double	len,ang0;
	double	dx,dy;

	dx=rpnt.x-rotcntr.x;
	dy=rpnt.y-rotcntr.y;
	if(dx){

		len=hypot(dx,dy);
		ang0=atan2(dy,dx);
		ang0+=ang;
	}
	else{

		len=abs(dy);
		if(dy>0)
			ang0=PI/2+ang;
		else
			ang0=ang-PI/2;
	}
	tpnt->y=rotcntr.y+len*sin(ang0);
	tpnt->x=rotcntr.x+len*cos(ang0);
}

void rotpix(POINT rpnt,POINT* tpnt){

	//won't handle vertical lines
	double	len,ang0;
	long	dx,dy;

	dx=rpnt.x-pixcntr.x;
	dy=rpnt.y-pixcntr.y;
	len=hypot(dx,dy);
	ang0=atan2(dy,dx);
	ang0-=pixang;
	tpnt->y=pixcntr.y+len*sin(ang0);
	tpnt->x=pixcntr.x+len*cos(ang0);
}

void rotflt(FLPNT* pnt){

	double	len,ang0;
	double	dx,dy;

	dx=pnt->x-rotcntr.x;
	dy=pnt->y-rotcntr.y;
	if(dx){

		len=hypot(dx,dy);
		ang0=atan2(dy,dx);
		ang0+=ang;
	}
	else{

		len=abs(dy);
		if(dy>0)
			ang0=PI/2+ang;
		else
			ang0=ang-PI/2;
	}
	pnt->y=rotcntr.y+len*sin(ang0);
	pnt->x=rotcntr.x+len*cos(ang0);
}

void rotstch(SHRTPNT* pnt){

	double	len,ang0;
	double	dx,dy;

	dx=pnt->x-rotcntr.x;
	dy=pnt->y-rotcntr.y;
	if(dx){

		len=hypot(dx,dy);
		ang0=atan2(dy,dx);
		ang0+=ang;
	}
	else{

		len=abs(dy);
		if(dy>0)
			ang0=PI/2+ang;
		else
			ang0=ang-PI/2;
	}
	pnt->y=rotcntr.y+len*sin(ang0);
	pnt->x=rotcntr.x+len*cos(ang0);
}

void ritrot(){

	POINT		tpnt;
	DUBPNT		rotpnt;

	rotpnt.x=rotrct.left;
	rotpnt.y=rotrct.top;
	rotang(rotpnt,&tpnt);
	rlinb[0].x=rlinb[4].x=tpnt.x;
	rlinb[0].y=rlinb[4].y=tpnt.y;
	rotpnt.x=rotcntr.x;
	rotang(rotpnt,&tpnt);
	rlinv[0].x=tpnt.x;
	rlinv[0].y=tpnt.y;
	rotpnt.x=rotrct.right;
	rotang(rotpnt,&tpnt);
	rlinb[1].x=tpnt.x;
	rlinb[1].y=tpnt.y;
	rotpnt.y=rotcntr.y;
	rotang(rotpnt,&tpnt);
	rlinh[1].x=tpnt.x;
	rlinh[1].y=tpnt.y;
	rotpnt.y=rotrct.bottom;
	rotang(rotpnt,&tpnt);
	rlinb[2].x=tpnt.x;
	rlinb[2].y=tpnt.y;
	rotpnt.x=rotcntr.x;
	rotang(rotpnt,&tpnt);
	rlinv[1].x=tpnt.x;
	rlinv[1].y=tpnt.y;
	rotpnt.x=rotrct.left;
	rotang(rotpnt,&tpnt);
	rlinb[3].x=tpnt.x;
	rlinb[3].y=tpnt.y;
	rotpnt.y=rotcntr.y;
	rotang(rotpnt,&tpnt);
	rlinh[0].x=tpnt.x;
	rlinh[0].y=tpnt.y;
	sCor2px(rotcntr,&rlinu[0]);
	setMap(ROTSHO);
	durot();
}

void durcntr(){

	rotcntr.x=midl(rotrct.right,rotrct.left);
	rotcntr.y=midl(rotrct.top,rotrct.bottom);
}

void rot(){

	if(chkMap(FPSEL)){

		MoveMemory(&rotrct,&pselrct,sizeof(FLRCT));
		goto rotskp;
	}
	if(chkMap(BIGBOX)){

		MoveMemory(&rotrct,&rctal,sizeof(FLRCT));
		goto rotskp;
	}
	if(fselpnt){

		pxrct2stch(bigrct,&rotrct);
		setMap(FRMSROT);
		goto rotskp;
	}
	if(chkMap(FORMSEL)){

		fvars(clofind);
		setMap(FRMROT);
		MoveMemory(&rotrct,&frmpnt->rct,sizeof(FLRCT));
		goto rotskp;
	}
	if(chkMap(GRPSEL)){

		rngadj();
		selRct(&rotrct);
		goto rotskp;
	}
	shoseln(IDS_FGRPF,IDS_ROT);
	return;
rotskp:;
	setMap(ROTAT);
	durcntr();
	ang=0;
	ritrot();
}

/*
	unsigned short	led;
	unsigned char	fx;
	unsigned short	x;
	unsigned char	spcx;
	unsigned char	fy;
	unsigned short	y;
	unsigned char	spcy;
	unsigned char	myst;
	unsigned char	typ;

  */
void savclp(unsigned dst,unsigned src){

	double	frct,intg;

	clpdat[dst].led=stchs[src].at&COLMSK;
	frct=modf((double)stchs[src].x-lolft.x,&intg);
	clpdat[dst].fx=frct*256;
	clpdat[dst].x=intg;
	clpdat[dst].spcx=0;
	frct=modf((double)stchs[src].y-lolft.y,&intg);
	clpdat[dst].fy=frct*256;
	clpdat[dst].y=intg;
	clpdat[dst].spcy=0;
	clpdat[dst].myst=1;
	clpdat[dst].typ=0x14;
}

void rtclpfn(unsigned dst,unsigned src){

	double	frct,intg;

	clpdat[dst].led=0;
	frct=modf(clpnu[src].x-lolft.x,&intg);
	clpdat[dst].fx=frct;
	clpdat[dst].x=intg;
	clpdat[dst].spcx=0;
	frct=modf(clpnu[src].y-lolft.y,&intg);
	clpdat[dst].fy=frct;
	clpdat[dst].y=intg;
	clpdat[dst].spcy=0;
	clpdat[dst].myst=1;
	clpdat[dst].typ=0x14;
}

FRMCLP* frmref(void* pnt){
	return *(FRMCLP **)pnt;
}

FRMSCLP* frmsref(void* pnt){
	return *(FRMSCLP **)pnt;
}

FPCLP* fpref(void* pnt){
	return *(FPCLP **)pnt;
}

unsigned sizfclp()
{
	unsigned siz;

	siz=sizeof(FRMCLP)+sids*sizeof(FLPNT);
	if(frmpnt->typ==SAT)
		siz+=frmpnt->stpt*sizeof(SATCON);
	if(iseclp(clofind))
		siz+=frmpnt->nclp*sizeof(FLPNT);
	if(isclpx(clofind))
		siz+=frmpnt->flencnt.nclp*sizeof(FLPNT);
	if(istx(clofind))
		siz+=frmpnt->dhx.txt.cnt*sizeof(TXPNT);
	return siz;
}

unsigned frmcnt(unsigned fpnt){

	unsigned	at,cnt=0,ind;

	lolft.x=lolft.y=(float)1e20;
	at=fpnt<<4;
	for(ind=0;ind<hed.stchs;ind++){

		if((stchs[ind].at&FRMSK)==at&&stchs[ind].at&TYPMSK)
			goto fskip;
	}
	return 0;
fskip:;
	frmstrt=ind;
	while(ind<hed.stchs){

		if((stchs[ind].at&FRMSK)==at&&stchs[ind].at&TYPMSK){

			if(stchs[ind].x<lolft.x)
				lolft.x=stchs[ind].x;
			if(stchs[ind].y<lolft.y)
				lolft.y=stchs[ind].y;
			cnt++;
		}
		ind++;
	}
	return cnt;
}

unsigned sizclp(){

	unsigned len=0;

	len=siz=sizeof(FRMCLP)+sids*sizeof(FLPNT);
	if(frmpnt->typ==SAT)
		siz+=frmpnt->stpt*sizeof(SATCON);
	if(frmpnt->ftyp||frmpnt->etyp){
		
		len+=frmcnt(clofind);
		siz+=len*sizeof(SHRTPNT);
	}
	if(iseclp(clofind))
		siz+=frmpnt->nclp*sizeof(FLPNT);
	if(isclpx(clofind))
		siz+=frmpnt->flencnt.nclp*sizeof(FLPNT);
	if(istx(clofind))
		siz+=frmpnt->dhx.txt.cnt*sizeof(TXPNT);
	return len;
}

unsigned lenclp()
{
	unsigned cod,ind,cnt;

	cnt=0;
	cod=clofind<<FRMSHFT;
	for(ind=0;ind<hed.stchs;ind++)
	{
		if((stchs[ind].at&(FRMSK|NOTFRM))==cod)
			cnt++;
	}
	return cnt;
}

void duclip(){

	unsigned	ind,ine,len=0,inf,at,msiz=0;
	SATCON*		sac;
	FLPNT*		clp;
	FLPNT*		mclp;
	TXPNT*		ptx;
	TXPNT*		ptxs;
	FRMHED*		tfrm;
	SHRTPNT*	astch;
	FPCLP*		pclp;
	FLPNT*		tflt;

	if(chkMap(FPSEL)){

		if(OpenClipboard(hWnd)){

			EmptyClipboard();
			htclp=RegisterClipboardFormat(thredclp);
			tclpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,(pselrng.cnt+1)*sizeof(FLPNT)+sizeof(FPCLP));
			pclp=fpref(tclpvoid);
			pclp->led=CLP_FRMPS;
			pclp->cnt=pselrng.cnt;
			if(chkMap(PSELDIR))
				pclp->dir=1;
			else
				pclp->dir=0;
			tflt=(FLPNT*)&pclp[1];
			fvars(clofind);
			ine=pselrng.strt;
			for(ind=0;ind<=pselrng.cnt;ind++){
				
				tflt[ind].x=flt[ine].x;
				tflt[ind].y=flt[ine].y;
				ine=pdir(ine);
			}
			SetClipboardData(htclp,tclpvoid);
			CloseClipboard();
		}
		return;
	}
	if(chkMap(BIGBOX))
		tabmsg(IDS_INSF);
	else{

		if(OpenClipboard(hWnd)){

			EmptyClipboard();
			htclp=RegisterClipboardFormat(thredclp);
			if(fselpnt){

				for(ind=0;ind<fselpnt;ind++){

					clofind=selist[ind];
					fvars(clofind);
					len+=sizfclp();
					msiz+=siz;
				}
				tclpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,msiz+len);
				frmsclpdat=frmsref(tclpvoid);
				frmsclpdat->led=CLP_FRMS;
				frmsclpdat->cnt=fselpnt;
				tfrm=(FRMHED*)&frmsclpdat[1];
				for(ind=0;ind<fselpnt;ind++){

					frmpnt=&formlst[selist[ind]];
					frmcpy(&tfrm[ind],&formlst[selist[ind]]);
				}
				flt=(FLPNT*)&tfrm[ind];
				inf=0;
				for(ind=0;ind<fselpnt;ind++){

					frmpnt=&formlst[selist[ind]];
					for(ine=0;ine<frmpnt->sids;ine++){

						flt[inf].x=frmpnt->flt[ine].x;
						flt[inf++].y=frmpnt->flt[ine].y;
					}
				}
				sac=(SATCON*)&flt[inf];
				inf=0;
				for(ind=0;ind<fselpnt;ind++){

					frmpnt=&formlst[selist[ind]];
					if(frmpnt->typ==SAT){

						for(ine=0;ine<frmpnt->stpt;ine++){

							sac[inf].strt=frmpnt->sacang.sac[ine].strt;
							sac[inf++].fin=frmpnt->sacang.sac[ine].fin;
						}
					}
				}
				clp=(FLPNT*)&sac[inf];
				inf=0;
				for(ind=0;ind<fselpnt;ind++){

					frmpnt=&formlst[selist[ind]];
					if(isclpx(selist[ind])){

						for(ine=0;ine<frmpnt->flencnt.nclp;ine++){

							clp[inf].x=frmpnt->angclp.clp[ine].x;
							clp[inf++].y=frmpnt->angclp.clp[ine].y;
						}
					}
					if(iseclp(selist[ind])){

						for(ine=0;ine<frmpnt->nclp;ine++){

							clp[inf].x=frmpnt->clp[ine].x;
							clp[inf++].y=frmpnt->clp[ine].y;
						}
					}
				}
				ptx=(TXPNT*)&clp[inf];
				ine=0;
				for(ind=0;ind<fselpnt;ind++)
				{
					frmpnt=&formlst[selist[ind]];
					if(istx(selist[ind]))
					{
						MoveMemory(&ptx[ine],&txpnts[frmpnt->dhx.txt.ind],frmpnt->dhx.txt.cnt*sizeof(TXPNT));
						tfrm[ind].dhx.txt.ind=ine;
						ine+=frmpnt->dhx.txt.cnt;
					}
				}
				SetClipboardData(htclp,tclpvoid);
				CloseClipboard();
				clRmap(RMAPSIZ);
				for(ind=0;ind<fselpnt;ind++)
					setr(selist[ind]);
				astch=&stchs[MAXSEQ];
				ine=0;
				lolft.x=lolft.y=(float)1e30;
				for(ind=0;ind<hed.stchs;ind++){

					if(!(stchs[ind].at&NOTFRM)&&chkr((stchs[ind].at&FRMSK)>>FRMSHFT)){

						if(stchs[ind].x<lolft.x)
							lolft.x=stchs[ind].x;
						if(stchs[ind].y<lolft.y)
							lolft.y=stchs[ind].y;
						astch[ine].x=stchs[ind].x;
						astch[ine].y=stchs[ind].y;
						astch[ine++].at=stchs[ind].at;
					}
				}
				if(hed.stchs&&ine){

					hClip=RegisterClipboardFormat(pcdClip);
					clpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,ine*sizeof(CLPSTCH)+2);
					clpdat=deref(clpvoid);
					ind=MAXSEQ;
					inf=0;
					savclp(0,ind);
					ind++;
					clpdat[0].led=ine;
					inf++;
					while(ind<ine+MAXSEQ)
						savclp(inf++,ind++);
					SetClipboardData(hClip,clpvoid);
					CloseClipboard();
				}
			}
			else{

				if(chkMap(FORMSEL)){

					len=sizclp();
					fvars(clofind);
					sac=0;at=clofind<<4;
					siz+=sizeof(FRMCLP);
					tclpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,siz);
					frmclpdat=frmref(tclpvoid);
					frmclpdat->led=CLP_FRM;
					frmcpy(&frmclpdat->frm,&formlst[clofind]);
					flt=(FLPNT*)&frmclpdat[1];
					for(ind=0;ind<frmpnt->sids;ind++){

						flt[ind].x=frmpnt->flt[ind].x;
						flt[ind].y=frmpnt->flt[ind].y;
					}
					sac=(SATCON*)&flt[sids];
					ind=0;
					if(frmpnt->typ==SAT){

						for(ind=0;ind<frmpnt->stpt;ind++){

							sac[ind].strt=frmpnt->sacang.sac[ind].strt;
							sac[ind].fin=frmpnt->sacang.sac[ind].fin;
						}
					}
					mclp=(FLPNT*)&sac[ind];
					if(isclpx(clofind)){

						for(ind=0;ind<frmpnt->flencnt.nclp;ind++){

							mclp[ind].x=frmpnt->angclp.clp[ind].x;
							mclp[ind].y=frmpnt->angclp.clp[ind].y;
						}
					}
					clp=(FLPNT*)&mclp[ind];
					if(iseclpx(clofind)){

						for(ind=0;ind<frmpnt->nclp;ind++){

							clp[ind].x=frmpnt->clp[ind].x;
							clp[ind].y=frmpnt->clp[ind].y;
						}
					}
					ptx=(TXPNT*)&clp[ind];
					if(istx(clofind))
					{
						ptxs=&txpnts[frmpnt->dhx.txt.ind];
						for(ind=0;ind<frmpnt->dhx.txt.cnt;ind++)
						{
							ptx[ind].lin=ptxs[ind].lin;
							ptx[ind].y=ptxs[ind].y;
						}
					}
					SetClipboardData(htclp,tclpvoid);
					if((frmpnt->ftyp||frmpnt->etyp))
					{
						len=lenclp();
						hClip=RegisterClipboardFormat(pcdClip);
						clpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,len*sizeof(CLPSTCH)+2);
						clpdat=deref(clpvoid);
						ind=frmstrt;
						savclp(0,ind);
						clpdat[0].led=len;
						ind++;
						inf=1;
						at=clofind<<4;
						while(ind<hed.stchs){

							if((stchs[ind].at&FRMSK)==at&&!(stchs[ind].at&NOTFRM))
								savclp(inf++,ind);
							ind++;
						}
						SetClipboardData(hClip,clpvoid);
						ispcdclp();
					}
					CloseClipboard();
				}
				else{

					if(hed.stchs&&chkMap(GRPSEL)){

						hClip=RegisterClipboardFormat(pcdClip);
						rngadj();
						lolft.x=lolft.y=(float)1e30;
						for(ind=gpnt0;ind<=gpnt1;ind++){

							if(stchs[ind].x<lolft.x)
								lolft.x=stchs[ind].x;
							if(stchs[ind].y<lolft.y)
								lolft.y=stchs[ind].y;
						}
						len=gpnt1-gpnt0+1;
						inf=gpnt0;
						clpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,len*sizeof(CLPSTCH)+2);
						clpdat=deref(clpvoid);
						savclp(0,inf);
						clpdat[0].led=len;
						inf++;
						for(ind=1;ind<len;ind++)
							savclp(ind,inf++);
						SetClipboardData(hClip,clpvoid);
						CloseClipboard();
					}
				}
			}
			CloseClipboard();
		}
	}
}

void delfstchs(){

	unsigned ind,ine=0;;

	for(ind=0;ind<hed.stchs;ind++){

		if(stchs[ind].at&NOTFRM){

			stchs[ine].at=stchs[ind].at;
			stchs[ine].x=stchs[ind].x;
			stchs[ine++].y=stchs[ind].y;
		}
		else{

			if(((stchs[ind].at&FRMSK)>>4)!=clofind){

				stchs[ine].at=stchs[ind].at;
				stchs[ine].x=stchs[ind].x;
				stchs[ine++].y=stchs[ind].y;
			}
		}
	}
	hed.stchs=ine;
}

void cut(){

	duclip();
	if(fselpnt)
	{
		setMap(DELTO);
		delsfrms('s');
	}
	else
	{
		if(chkMap(FORMSEL)){

			delfstchs();
			frmdel();
		}
		else{

			if(chkMap(GRPSEL))
				delstchm();
		}
	}
	coltab();
	rstAll();
	setMap(RESTCH);
}

void numWnd(){

	RECT msgRct;
	
	GetClientRect(hMsg,&msgRct);
	hgNum=CreateWindow(
		"STATIC",
		0,
		SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
		5,
		msgRct.bottom+15,
		buttonWid3,
		buttonHi,
		hStch,
		NULL,
		hInst,
		NULL);
	msgpnt=0;
	*msgbuf=0;
}

void unmsg(){

	if(hMsg)
		noMsg();
}

void unpat(){

	if(rstMap(WASPAT)){

		ShowWindow(hSped,FALSE);
		DestroyWindow(hSped);
		movStch();
		setMap(RESTCH);
	}
}
void delsmal(unsigned ind,unsigned fin){

	unsigned	ine,at=clofind<<4;
	unsigned	inf;
	long		dx,dy;
	double		siz=1e99;

	savdo();
	if(chkMap(FORMSEL)){

		ine=find1st();
		ind=ine+1;
		while(ind<(unsigned)hed.stchs-1&&siz>smalsiz){
			
			if(!(stchs[ind].at&NOTFRM)&&(stchs[ind].at&FRMSK)==at){

				if(stchs[ind].at&KNOTMSK)
					ine=ind;
				else{

					dx=stchs[ind].x-stchs[ine].x;
					dy=stchs[ind].y-stchs[ine].y;
					siz=hypot(dx,dy);
				}
				ind++;
			}
		}
		if(ind!=fin-2){

			ind--;
			ine=ind+2;
			while(ine<(unsigned)hed.stchs-1){

				do{

					if(!(stchs[ind].at&NOTFRM)&&(stchs[ind].at&FRMSK)==at&&!(stchs[ind].at&KNOTMSK)){

						dx=stchs[ine].x-stchs[ind].x;
						dy=stchs[ine++].y-stchs[ind].y;
						siz=hypot(dx,dy);
					}
					else
						ine++;
				}while(siz<smalsiz&&ine<hed.stchs);
				stchs[++ind].at=stchs[--ine].at;
				stchs[ind].x=stchs[ine].x;
				stchs[ind].y=stchs[ine++].y;
			}
			ind++;
			while(ine<hed.stchs){

				stchs[ind].at=stchs[ine].at;
				stchs[ind].x=stchs[ine].x;
				stchs[ind++].y=stchs[ine++].y;
			}
			hed.stchs=ind;
			coltab();
		}
	}
	else{

		ine=ind+1;
		sPnt.x=stchs[ind].x;
		sPnt.y=stchs[ind].y;
		for(inf=ine;inf<fin;inf++){

			if(stchs[ine].at&KNOTMSK){

				sPnt.x=stchs[ine].x;
				sPnt.y=stchs[ine].y;
				mvstch(ine++,inf);
			}
			else{

				dx=stchs[inf].x-sPnt.x;
				dy=stchs[inf].y-sPnt.y;
				siz=hypot(dx,dy);
				if(siz>smalsiz){

					mvstch(ine++,inf);
					sPnt.x=stchs[inf].x;
					sPnt.y=stchs[inf].y;
				}
			}
		}
		while(inf<hed.stchs)
			mvstch(ine++,inf++);
		hed.stchs=ine;
		coltab();
	}
	rstAll();
	ritot(hed.stchs);
	lenCalc();
	setMap(RESTCH);
}

BOOL cmpstch(unsigned ind0,unsigned ind1){
	if (stchs[ind0].x != stchs[ind1].x)
		return 0;
	
	return stchs[ind0].y == stchs[ind1].y;
}

void mvstch(unsigned dst,unsigned src){
	stchs[dst] = stchs[src];
}

void ofstch(unsigned ind,TCHAR of){

	stchs[opnt].x=stchs[ind].x+knotstp.x*of;
	stchs[opnt].y=stchs[ind].y+knotstp.y*of;
	stchs[opnt++].at=knotat;
}

void endknt(unsigned fin){

	double		len;
	DUBPNT		dif;
	unsigned	strt,ind;
	TCHAR*		tdat;

	strt=fin-1;
	knotat=stchs[strt].at|KNOTMSK;
	do{

		dif.x=stchs[fin].x-stchs[strt].x;
		dif.y=stchs[fin].y-stchs[strt].y;
		len=hypot(dif.x,dif.y);
		strt--;
	}while(!len);
	if(chkMap(FILDIR))
		tdat=klstdat;
	else
		tdat=kendat;
	if(!(strt&0x8000000)){

		knotstp.x=2/len*dif.x;
		knotstp.y=2/len*dif.y;
		for(ind=0;ind<5;ind++)
			ofstch(fin,tdat[ind]);
		if(chkMap(FILDIR))
			ofstch(fin,0);
	}
}

void strtknt(unsigned strt){

	double		len;
	DUBPNT		dif;
	unsigned	fin,ind;

	fin=strt+1;
	do{

		dif.x=stchs[fin].x-stchs[strt].x;
		dif.y=stchs[fin].y-stchs[strt].y;
		len=hypot(dif.x,dif.y);
		fin++;
	}while(len<2&&fin<hed.stchs);
	if(fin<hed.stchs){

		knotat=stchs[strt].at|KNOTMSK;
		knotstp.x=2/len*dif.x;
		knotstp.y=2/len*dif.y;
		for(ind=0;ind<5;ind++)
			ofstch(strt,kstrtdat[ind]);
	}
}

BOOL aprxlen(double flen, unsigned ulen){

#define KNER 0.05

	if(flen>ulen+KNER)
		return 1;
	if(flen<ulen-KNER)
		return 1;
	return 0;
}

void fndknt(){

	unsigned	ind;
	BOOL		flg;

	if(hed.stchs>4){

		flg=0;
		knotcnt=0;
		for(ind=0;ind<(unsigned)hed.stchs-4;ind++){

			if(stchs[ind].at&KNOTMSK){
				
				if(!flg)
					knotab[knotcnt++]=ind;
			}
			else
				flg=0;
		}
	}
	else knotcnt=0;
}

void delknt(){

	unsigned	ind,ine;

	ine=0;
	for(ind=0;ind<hed.stchs;ind++){

		if(!(stchs[ind].at&KNOTMSK))
			mvstch(ine++,ind);
	}
	hed.stchs=ine;
}

BOOL isknots(){

	unsigned ind;

	for(ind=0;ind<hed.stchs;ind++){

		if(stchs[ind].at&KNOTMSK)
			return 1;
	}
	return 0;
}

void delknot(){

	if(isknots()){

		savdo();
		delknt();
		coltab();
		setMap(RESTCH);
	}
}

unsigned kjmp(unsigned strt){

	while(strt<(unsigned)hed.stchs-1&&stlen(strt)>KNOTLEN)
		mvstch(opnt++,strt++);
	strtknt(strt);
	return strt;
}

void setknt(){

	unsigned	ind;
	
	opnt=MAXSEQ;
	mvstch(opnt++,0);
	strtknt(0);
	if(stlen(0)>KNOTLEN)
		ind=kjmp(1);
	else
		ind=1;
	rstMap(FILDIR);
	while(ind<(unsigned)hed.stchs-1){

		mvstch(opnt++,ind);
		if(stlen(ind)>KNOTLEN){

			endknt(ind);
			ind=kjmp(ind+1);
			mvstch(opnt++,ind);
		}
		ind++;
	}
	setMap(FILDIR);
	endknt(ind);
	stchs[opnt-1].at&=(~KNOTMSK);
	hed.stchs=opnt-MAXSEQ;
	mvstchs(0,MAXSEQ,hed.stchs);
}

unsigned srchknot(unsigned src){

	while(knotab[xpnt]<src&&xpnt<knotcnt)
		xpnt++;
	xpnt--;
	if(abs(knotab[xpnt]-src)<5){

		xpnt++;
		if(abs(knotab[xpnt]-src)<5)
			return 0;
		else
			return 2;
	}
	else{

		xpnt++;
		if(abs(knotab[xpnt]-src)<5)
			return 1;
		else
			return 3;
	}
}

void chkncol(){

	unsigned	src,col,tcol,cod;

	opnt=MAXSEQ;
	col=stchs[0].at&COLMSK;
	rstMap(FILDIR);
	for(src=0;src<hed.stchs;src++){

		tcol=stchs[src].at&COLMSK;
		if(tcol==col)
			mvstch(opnt++,src);
		else{

			col=stchs[src].at&COLMSK;
			cod=srchknot(src);
			if(cod&1){

				endknt(src-1);
			}
			mvstch(opnt++,src);
			if(cod&2)
				strtknt(src);
		}
	}
	hed.stchs=opnt-MAXSEQ;
	mvstchs(0,MAXSEQ,hed.stchs);
}

void setknots()
{
	if(hed.stchs)
	{
		savdo();
		delknt();
		setknt();
		fndknt();
		chkncol();
		coltab();
		setMap(RESTCH);
		ritot(hed.stchs);
	}
}

void lodbmp(){

	TCHAR*	pchr;

	if(bnam[0]){

		DeleteObject(hBmp);
		ReleaseDC(hWnd,bitdc);
	}
	if(GetOpenFileName(&obn)){
				
		untrace();
		pchr=strrchr(lbnam,'\\')+1;
		strcpy(bnam,pchr);
		defbNam();
		bfil();
		setMap(RESTCH);
	}
}

void duhbit(unsigned cod)
{
	CheckMenuItem(hMen,ID_HIDBIT,MF_BYCOMMAND|cod);
	CheckMenuItem(hMen,ID_HIDBITF,MF_BYCOMMAND|cod);
}

void hidbit(){

	if(toglMap(HIDMAP))
		duhbit(MF_UNCHECKED);
	else
		duhbit(MF_CHECKED);
	setMap(DUMEN);
	setMap(RESTCH);
}

void patdun(){

	rstMap(RUNPAT);
	KillTimer(hWnd,0);
	setMap(WASPAT);
	movStch();
	setMap(RESTCH);
	tabmsg(IDS_END);
}

void drwlstch(unsigned fin){

	unsigned	col,ind,prepnt;
	unsigned	flg;
	
	prepnt=runpnt;
	if(chkMap(HID)){

		while((stchs[runpnt].at&COLMSK)!=actcol&&runpnt<fin-1)
			runpnt++;
	}
	if(chkMap(ZUMED)){

		ind=1;
		while(runpnt<runum+1&&runpnt<fin-2&&!stch2px(runpnt))
			runpnt++;
		prepnt=runpnt-1;
		col=stchs[runpnt].at&COLMSK;
		flg=1;
		while(ind<runum+1&&runpnt<fin-2&&(stchs[runpnt].at&COLMSK)==col){
		
			if(stch2px(runpnt)){

				movilin[ind].x=pPnt.x;
				movilin[ind++].y=pPnt.y;
				if(flg){
					
					flg=0;
					if(stch2px(runpnt-1)){

						movilin[0].x=movilin[1].x;
						movilin[0].y=movilin[1].y;
					}
					else{

						movilin[0].x=pPnt.x;
						movilin[0].y=pPnt.y;
					}
				}
			}
			runpnt++;
		}
		if(prepnt==runpnt)
			runpnt++;
		if(!stch2px(runpnt)){

			if((stchs[runpnt].at&COLMSK)==col){

				movilin[ind].x=pPnt.x;
				movilin[ind++].y=pPnt.y;
				runpnt++;
			}
		}
		SelectObject(rsdc,uPen[col]);
		Polyline(rsdc,movilin,ind);
		if(!flg)
			runpnt--;
	}
	else{
		
		ind=0;
		col=stchs[runpnt].at&COLMSK;
		SelectObject(rsdc,uPen[col]);
		while(ind<runum&&(runpnt+1<fin-1)&&((stchs[runpnt].at&COLMSK)==col)){

			stch2px1(runpnt++);
			movilin[ind].x=pPnt.x;
			movilin[ind++].y=pPnt.y;
		}
		runpnt--;
		Polyline(rsdc,movilin,ind);
	}
	if((stchs[runpnt+1].at&0xf)!=col)
		runpnt++;
	ritnum(STR_NUMSEL,runpnt);
	if(runpnt+3>fin-1)
		patdun();
}

void stchout(){

	if(chkMap(GRPSEL))
		drwlstch(gpnt1);
	else
		drwlstch(hed.stchs-1);
}

unsigned duth(TCHAR* nam){

	unsigned ind=strlen(nam);

	do ind--;
	while(tolower(nam[ind])!='h'&&ind);
	if(nam[ind-1]=='t')
		return ind+1;
	else
		return 0;
}

void duver(TCHAR* nam){

	unsigned ind,chr;

	ind=duth(nam);
	if(ind){

		chr=tolower(nam[ind])-'r';
		nam[MAX_PATH-1]=0;
		if(chr>=0&&chr<=3)
			strcpy(vernams[chr],nam);
	}
}

void durit(void* src,unsigned cnt){
	memcpy((void *) opnt, src, cnt);
	opnt += cnt;
}

unsigned bufref(){
	return (unsigned)opnt - (unsigned)bseq;
}

void dubuf(){

	STRHED				sthed;
	unsigned			ind,ine,len,slen,elen;
	FRMHED*				theds;
	FLPNT*				tpnts;
	SATCON*				spnts;
	FLPNT*				epnts;
	unsigned			flind=0;
	unsigned			slind=0;
	unsigned			elind=0;

	opnt=(unsigned)&bseq;
	sthed.led=0x2746872;
	sthed.len=hed.stchs*sizeof(SHRTPNT)+sizeof(STRHED)+16;
	sthed.stchs=hed.stchs;
	sthed.hup=ini.hup;
	len=0;slen=0;elen=0;
	strcpy(hedx.modnam,ini.desnam);
	if(formpnt){
	
		for(ind=0;ind<formpnt;ind++){

			len+=formlst[ind].sids;
			if(formlst[ind].typ==SAT)
				slen+=formlst[ind].stpt;
			if(isclp(ind))
				elen+=formlst[ind].flencnt.nclp;
			if(iseclp(ind))
				elen+=formlst[ind].nclp;
		}
	}
	sthed.fpnt=formpnt;
	sthed.fcnt=len;
	sthed.scnt=slen;
	sthed.ecnt=elen;
	sthed.fpnts=sizeof(STRHED)+hed.stchs*sizeof(SHRTPNT)+164;
	sthed.spnts=sizeof(FLPNT)*len;
	sthed.epnts=sizeof(FLPNT)*elen;
	durit(&sthed,sizeof(STRHED));
	hedx.auxfmt=ini.auxfil;
	hedx.xhup=ini.hupx;
	hedx.yhup=ini.hupy;
	hedx.txcnt=txad;
	durit(&hedx,sizeof(STREX));
	durit(stchs,hed.stchs*sizeof(SHRTPNT));
	if(!bnam[0]){

		for(ind=0;ind<16;ind++)
			bnam[ind]=0;
	}
	durit(bnam,16);
	durit(&stchBak,4);
	durit(useCol,64);
	durit(custCol,64);
	for(ind=0;ind<16;ind++)
		msgbuf[ind]=thrdSiz[ind][0];
	durit(msgbuf,16);
	if(formpnt){

		theds=new FRMHED[formpnt];
		tpnts=new FLPNT[len];
		spnts=new SATCON[slen];
		epnts=new FLPNT[elen];
		for(ind=0;ind<formpnt;ind++){

			frmcpy(&theds[ind],&formlst[ind]);
			theds[ind].flt=(FLPNT*)(&tpnts[flind]-&tpnts[0]);
			for(ine=0;ine<formlst[ind].sids;ine++){

				tpnts[flind].x=formlst[ind].flt[ine].x;
				tpnts[flind++].y=formlst[ind].flt[ine].y;
			}
			if(formlst[ind].typ==SAT){

				theds[ind].sacang.sac=(SATCON*)(&spnts[slind]-&spnts[0]);
				theds[ind].stpt=formlst[ind].stpt;
				for(ine=0;ine<formlst[ind].stpt;ine++){
					
					spnts[slind].strt=formlst[ind].sacang.sac[ine].strt;
					spnts[slind++].fin=formlst[ind].sacang.sac[ine].fin;
				}
			}
			if(isclp(ind)){

				theds[ind].angclp.clp=(FLPNT*)(&epnts[elind]-&epnts[0]);
				for(ine=0;ine<formlst[ind].flencnt.nclp;ine++){

					epnts[elind].x=formlst[ind].angclp.clp[ine].x;
					epnts[elind++].y=formlst[ind].angclp.clp[ine].y;
				}
			}
			if(iseclpx(ind)){

				theds[ind].clp=(FLPNT*)(&epnts[elind]-&epnts[0]);
				for(ine=0;ine<formlst[ind].nclp;ine++){

					epnts[elind].x=formlst[ind].clp[ine].x;
					epnts[elind++].y=formlst[ind].clp[ine].y;
				}
			}
		}
		durit(theds,formpnt*sizeof(FRMHED));
		durit(tpnts,len*sizeof(FLPNT));
		durit(spnts,slen*sizeof(SATCON));
		durit(epnts,elen*sizeof(FLPNT));
		durit(txpnts,txad*sizeof(TXPNT));
		delete theds;
		delete tpnts;
		delete spnts;
		delete epnts;
	}
}

void thrsav(){

	unsigned			ind,len;
	int					tind;
	unsigned int		wrot;
	unsigned			flind=0;
	unsigned			slind=0;
	unsigned			elind=0;
	WIN32_FIND_DATA		fdat; 
	HANDLE				hndl;
	TCHAR				nunam[MAX_PATH];

	if(chkattr(filnam))
		return;
	if(!rstMap(IGNAM)){

		hndl=FindFirstFile(genam,&fdat);
		ind=0;
		if(hndl!=INVALID_HANDLE_VALUE){

			rstMap(CMPDO);
			for(ind=0;ind<OLDVER;ind++)
				vernams[ind][0]=0;
			duver(fdat.cFileName);
			while(FindNextFile(hndl,&fdat))
				duver(fdat.cFileName);
			FindClose(hndl);
			DeleteFile(vernams[OLDVER-1]);
			for(tind=OLDVER-2;tind>=0;tind--){

				if(vernams[tind][0]){

					vernams[tind][MAX_PATH-1]=0;
					strcpy(nunam,vernams[tind]);
					len=duth(nunam);
					nunam[len]=tind+'s';
					MoveFile(vernams[tind],nunam);
				}
			}
		}
	}
	hFil=CreateFile(thrnam,(GENERIC_WRITE),0,NULL,
		CREATE_ALWAYS,0,NULL);
	if(hFil==INVALID_HANDLE_VALUE){

		crmsg(thrnam);
		hFil=0;
	}
	else{

		dubuf();
		WriteFile(hFil,bseq,bufref(),&wrot,0);
		if(wrot!=(unsigned long)bufref()){

			sprintf(msgbuf,"File Write Error: %s\n",thrnam);
			shoMsg(msgbuf);
		}
		CloseHandle(hFil);
	}
}

void setsped(){

	unsigned	len;
	double		tdub;

	if(!delay)
		delay=1;
	tdub=(double)delay/10;
	if(tdub<10){

		len=100;
		runum=(unsigned)len/tdub;
		if(runum>99)
			runum=99;
	}
	else{

		len=(unsigned)tdub;
		runum=2;
	}
	if(runum<2)
		runum=2;
	SetTimer(hWnd,0,len,0);
}

void f1del(){

	unsigned cod,ind,ine;

	if(chkMap(DELTO)){

		cod=clofind<<FRMSHFT;
		ine=0;
		for(ind=0;ind<hed.stchs;ind++)
		{
			if((stchs[ind].at&(FRMSK|NOTFRM))!=cod)
			{
				stchs[ine].x=stchs[ind].x;
				stchs[ine].y=stchs[ind].y;
				stchs[ine].at=stchs[ind].at;
				ine++;
			}
		}
		hed.stchs=ine;
	}
	deleclp(clofind);
	delmclp(clofind);
	delsac(clofind);
	delflt(clofind);
	deltx();
}

void frmdel(){

	unsigned ind,ine;
	unsigned stfrm,tind;

	fvars(clofind);
	f1del();
	for(ind=clofind;ind<(unsigned)formpnt;ind++)
		frmcpy(&formlst[ind],&formlst[ind+1]);
	if(rstMap(DELTO)){

		ine=0;
		for(ind=0;ind<hed.stchs;ind++){

			if(!(stchs[ind].at&NOTFRM)){

				tind=(stchs[ind].at&FRMSK);
				stfrm=tind>>4;
				if(stfrm>clofind){

					stchs[ind].at&=NFRMSK;
					stchs[ind].at|=(tind-0x10);
				}
			}
		}
	}
	else{

		for(ind=0;ind<hed.stchs;ind++){

			if(!(stchs[ind].at&NOTFRM)){

				tind=(stchs[ind].at&FRMSK);
				stfrm=tind>>4;
				if(stfrm==clofind)
					stchs[ind].at&=(NFRMSK&NTYPMSK);
				if(stfrm>clofind){

					stchs[ind].at&=NFRMSK;
					stchs[ind].at|=(tind-0x10);
				}
			}
		}
	}
	formpnt--;
	rstMap(FORMSEL);
}
	
void deltot(){

	strcpy(fildes,ini.desnam);
	formpnt=hed.stchs=fltad=clpad=satkad=txad=0;
	rstMap(GMRK);
	rstAll();
	coltab();
	zumhom();
	strcpy(fildes,ini.desnam);
	sprintf(msgbuf,stab[STR_THRDBY],thrnam,fildes);
	SetWindowText(hWnd,msgbuf);
}

BOOL wastch(){

	unsigned ind;

	for(ind=0;ind<hed.stchs;ind++){

		if((stchs[ind].at&FRMSK)>>FRMSHFT==clofind)
			return 1;
	}
	return 0;
}

BOOL frmstch()
{
	unsigned ind,cod;

	clRmap((formpnt>>5)>>1);
	for(ind=0;ind<formpnt;ind++)
		setr(selist[ind]);
	for(ind=0;ind<hed.stchs;ind++)
	{
		cod=(stchs[ind].at&FRMSK)>>FRMSHFT;
		if(chkr(cod))
			return 1;
	}
	return 0;
}

void delet(){

	unsigned ind,ine;
	BOOL satflg;

	undat();
	satflg=0;
	if(rstMap(FPSEL)){

		savdo();
		fvars(clofind);
		clRmap((sids>>5)+1);
		ine=pselrng.strt;
		for(ind=0;ind<=pselrng.cnt;ind++){

			setr(ine);
			ine=pdir(ine);
		}
		ine=0;
		for(ind=0;ind<sids;ind++){

			if(!chkr(ind)){

				flt[ine].x=flt[ind].x;
				flt[ine].y=flt[ind].y;
				ine++;
			}
		}
		ine=fltind(&flt[ine]);
		ind=fltind(&flt[ind]);
		while(ind<fltad){

			flts[ine].x=flts[ind].x;
			flts[ine].y=flts[ind].y;
			ine++;
			ind++;
		}
		for(ind=clofind+1;ind<formpnt;ind++)
			formlst[ind].flt-=(pselrng.cnt+1);
		fltad-=(pselrng.cnt+1);
		frmpnt->sids-=(pselrng.cnt+1);
		frmout(clofind);
		if(frmpnt->typ==SAT)
			satadj();
		refil();
		fndknt();
		setMap(RESTCH);
		return;
	}
	if(GetKeyState(VK_CONTROL)&GetKeyState(VK_SHIFT)&0X8000)
		deltot();
	else{

		savdo();
		if(fselpnt){

			if(frmstch())
			{
				setMap(DELSFRMS);
				tabmsg(IDS_DELFRM);
				okcan();
				tomsg();
			}
			else
				delsfrms(1);
			return;
		}
		if(chkMap(FORMSEL)&&formpnt){

			if(wastch()){

				setMap(DELFRM);
				tabmsg(IDS_FDEL);
				okcan();
				tomsg();
			}
			else{

				if(formpnt){

					rstMap(DELTO);
					frmdel();
					setMap(RESTCH);
				}
			}
			fndknt();
			return;
		}
		if(chkMap(SELBOX)){

selab:;
			if(hed.stchs>2){

				delstch1(cloInd);
				if(!stch2px(cloInd))
					movbox();
			}
			else{

				hed.stchs=0;
				rstMap(SELBOX);
			}
			coltab();
			setfchk();
			fndknt();
			setMap(RESTCH);
			return;
		}
		if(chkMap(GRPSEL)){

			delstchm();
			coltab();
			rstAll();
			setfchk();
			fndknt();
			setMap(RESTCH);
			return;
		}
		if(chkMap(FRMPSEL)||closfrm()){

			frmpnt=&formlst[clofind];
			switch(frmpnt->typ){

			case LIN:

				if(frmpnt->ftyp==CONTF){

					if(clofine==frmpnt->angclp.sat.strt||clofine==frmpnt->angclp.sat.fin){

						delmfil(frmpnt->fcol);
						frmpnt->ftyp=0;
						coltab();
						setMap(RESTCH);
						return;
					}
					if(frmpnt->angclp.sat.strt>clofine)
						frmpnt->angclp.sat.strt--;
					if(frmpnt->angclp.sat.fin>clofine)
						frmpnt->angclp.sat.fin--;
				}
				break;

			case SAT:

				if(clofine<=1){

					if(frmpnt->at&FRMEND){

						if(frmpnt->wpar)
							frmpnt->wpar=0;
						else
							frmpnt->at&=0xfe;
						satflg=1;
						goto deldun;
					}
				}
				if(wpar){

					if(clofine==(unsigned)wpar||clofine==(unsigned)wpar+1){

						frmpnt->wpar=0;
						satflg=1;
						goto deldun;
					}
				}
				for(ind=0;ind<frmpnt->stpt;ind++){					

					if(frmpnt->sacang.sac[ind].strt==clofine||frmpnt->sacang.sac[ind].fin==clofine){
								
						delcon(ind);
						satflg=1;
						goto deldun;
					}
				}
			}
			delspnt();
deldun:;
		   if(clofind>formpnt-1)
			   clofind=formpnt-1;
			if(formpnt){

				frmout(clofind);
				fvars(clofind);
				refil();
			}
			coltab();
			setMap(RESTCH);
		}
		if(!satflg&&closPnt1(&cloInd))
			goto selab;
	}
	fndknt();
}

void movi(){

	double tdub;

	rstAll();
	if(hed.stchs){

		if(hMsg){

			DestroyWindow(hMsg);
			hMsg=0;
		}
		setMap(RUNPAT);
		if(chkMap(GRPSEL)){

			rngadj();
			runpnt=gpnt0;
		}
		else
			runpnt=0;
		movStch();
		if(!chkMap(WASPAT)){

			hSped=CreateWindow(
				"SCROLLBAR",
				0,
				SBS_HORZ|WS_CHILD|WS_VISIBLE,
				buttonWid3,
				0,
				stchSiz.x,
				SCROLSIZ,
				hWnd,
				NULL,
				hInst,
				NULL);
		}
		if(chkMap(ZUMED))
			tdub=hed.stchs*zumFct*zumFct;
		else
			tdub=hed.stchs;
		if(!chkMap(WASPAT))
			delay=MOVITIM*10000/tdub;
		if(delay<MINDELAY)
			delay=MINDELAY;
		if(delay>MAXDELAY)
			delay=MAXDELAY;
		scrol.cbSize=sizeof(scrol);
		scrol.fMask=SIF_ALL;
		scrol.nMax=MAXDELAY;
		scrol.nMin=MINDELAY;
		scrol.nPage=1;
		scrol.nPos=MAXDELAY-delay;
		SetScrollInfo(hSped,SB_CTL,&scrol,TRUE);
		FillRect(rsdc,&scRct,hStchBak);
		setsped();
	}
}

#define CLPBUG 0

void redclp(){

	int		ind,playcod;

	playcod=actl<<LAYSHFT;
	clpvoid=GlobalLock(hClpMem);
	clpdat=(CLPSTCH*)clpvoid;
	clplen=clpdat[0].led;
	clpnu[0].x=clpdat[0].x+(float)clpdat[0].fx/256;
	clpnu[0].y=clpdat[0].y+(float)clpdat[0].fy/256;
	clpnu[0].at=0;

#if CLPBUG

		sprintf(msgbuf,"ind: 0 x: %6.2f,y: %6.2f\n",clpnu[0].x,clpnu[0].y);
		OutputDebugString(msgbuf);
#endif
	clprct.left=clprct.right=clpnu[0].x;
	clprct.bottom=clprct.top=clpnu[0].y;
	for(ind=1;ind<(long)clplen;ind++){

		clpnu[ind].x=clpdat[ind].x+(float)clpdat[ind].fx/256;
		clpnu[ind].y=clpdat[ind].y+(float)clpdat[ind].fy/256;
		clpnu[ind].at=(clpdat[ind].led&0xf)|playcod;

#if CLPBUG

		sprintf(msgbuf,"ind: %d x: %6.2f,y: %6.2f\n",ind,clpnu[ind].x,clpnu[ind].y);
		OutputDebugString(msgbuf);
#endif
		if(clpnu[ind].x<clprct.left)
			clprct.left=clpnu[ind].x;
		if(clpnu[ind].x>clprct.right)
			clprct.right=clpnu[ind].x;
		if(clpnu[ind].y<clprct.bottom)
			clprct.bottom=clpnu[ind].y;
		if(clpnu[ind].y>clprct.top)
			clprct.top=clpnu[ind].y;
	}
	clpnu[0].at=actcol|playcod;
	clpsiz.cx=clprct.right-clprct.left;
	clpsiz.cy=clprct.top-clprct.bottom;
	GlobalUnlock(hClpMem);
	if(clprct.left||clprct.bottom){

		for(ind=0;ind<(int)clplen;ind++){

			clpnu[ind].x-=clprct.left;
			clpnu[ind].y-=clprct.bottom;
		}
		clprct.top-=clprct.bottom;
		clprct.right-=clprct.left;
		clprct.bottom=clprct.left=0;
	}
}

unsigned nxtcrnr(unsigned ind){
	return (ind + 1) & 3;
}

void drwmrk(HDC dc){

	POINT pxpnt;
	POINT mlin[2];

	sCor2px(mrkpnt,&pxpnt);
	SelectObject(dc,mrkPen);
	SetROP2(dc,R2_XORPEN);
	mlin[0].x=pxpnt.x-6;
	mlin[0].y=pxpnt.y-6;
	mlin[1].x=pxpnt.x+6;
	mlin[1].y=pxpnt.y+6;
	Polyline(dc,mlin,2);
	mlin[0].x=pxpnt.x-6;
	mlin[0].y=pxpnt.y+6;
	mlin[1].x=pxpnt.x+6;
	mlin[1].y=pxpnt.y-6;
	Polyline(dc,mlin,2);
	SetROP2(dc,R2_COPYPEN);
}

void vubak(){

	unsigned	ind;
	long		dx,dy,vloc;

	if(hFil||chkMap(THUMSHO)){

		setMap(ZUMED);
		movStch();
		FillRect(sdc,&scRct,hStchBak);
		dx=(scRct.right>>1);
		dy=(scRct.bottom>>1);
		for(ind=0;ind<OLDVER;ind++){

			if(ind&2)
				vloc=dy;
			else
				vloc=0;
			hvu[ind]=CreateWindow(
				"STATIC",
				"",
				SS_NOTIFY|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE|WS_BORDER,
				dx*(ind&1)+buttonWid3,
				vloc,
				dx,
				dy,
				hWnd,
				NULL,
				hInst,
				NULL);
		}
		setMap(BAKSHO);
	}
}

void getbak(){

	TCHAR*		pchr;
	
	if(chkMap(THUMSHO)){

		if(thumsel[baknum]){

			if(chkMap(RBUT)){

				strcpy(insnam,thumsel[baknum]);
				setMap(IGNORINS);
				unthum();
				setMap(FRMOF);
				insfil();
				if(GetKeyState(VK_SHIFT)&0X8000){

					rstMap(INSFIL);
					rstMap(FRMOF);
					setMap(INIT);
					coltab();
					setMap(RESTCH);
				}
			}
			else{

				strcpy(filnam,defDir);
				pchr=&filnam[strlen(filnam)-1];
				if(pchr[0]!='\\'){

					pchr[1]='\\';
					pchr[2]=0;
				}
				strcat(filnam,thumsel[baknum]);
				setMap(REDOLD);
				nuFil();
			}
		}
		else
			unthum();
	}
}

void rebak(){

	unsigned	ind;
	TCHAR		tnaml[MAX_PATH];
	TCHAR		tnamx[MAX_PATH];

	for(ind=0;ind<OLDVER;ind++)
		DestroyWindow(hvu[ind]);
	strcpy(tnaml,thrnam);
	strcpy(tnamx,thrnam);
	ind=duth(tnaml);
	tnaml[ind]=baknum+'s';
	tnamx[ind]='x';
	MoveFile(thrnam,tnamx);
	MoveFile(tnaml,thrnam);
	MoveFile(tnamx,tnaml);
	strcpy(filnam,thrnam);
	setMap(REDOLD);
	nuFil();
	DeleteFile(tnamx);
}

void thumbak(){

	unsigned ind;

	for(ind=0;ind<OLDVER;ind++)
		DestroyWindow(hvu[ind]);
	getbak();
}

void movbak(TCHAR src,TCHAR dst){

	TCHAR	strsrc[MAX_PATH];
	TCHAR	strdst[MAX_PATH];
	
	unsigned ind=duth(thrnam);

	strcpy(strsrc,thrnam);
	strcpy(strdst,thrnam);
	strsrc[ind]=(TCHAR)src;
	strdst[ind]=(TCHAR)dst;
	DeleteFile(strdst);
	MoveFile(strsrc,strdst);
}

void purg(){

	TCHAR		tnam[MAX_PATH];
	unsigned	pind,ind;

	if(hFil){

		strcpy(tnam,thrnam);
		pind=duth(tnam);
		for(ind=1;ind<6;ind++){

			tnam[pind]=(TCHAR)ind+'r';
			DeleteFile(tnam);
		}
	}
}

void purgdir(){

	setMap(PRGMSG);
	sprintf(msgbuf,"Delete all backups in %s\n",defDir);
	shoMsg(msgbuf);
	okcan();
}

void deldir(){

	unsigned			ind;
	TCHAR				tnam[MAX_PATH];
	TCHAR*				pchr;
	WIN32_FIND_DATA		fdat;
	HANDLE				hndl;

	unmsg();
	tabmsg(IDS_BAKDEL);
	strcpy(tnam,defDir);
	pchr=&tnam[strlen(tnam)];
	strcpy(pchr,"\\*.th0");
	for(ind=1;ind<6;ind++){

		pchr[5]=(TCHAR)ind+'r';
		hndl=FindFirstFile(tnam,&fdat);
		if(hndl!=INVALID_HANDLE_VALUE){
		
			DeleteFile(fdat.cFileName);
			while(FindNextFile(hndl,&fdat))
				DeleteFile(fdat.cFileName);
		}
		FindClose(hndl);
	}
	unmsg();
	tabmsg(IDS_BAKDT);
}

BOOL chkwnd(HWND hwind){

	RECT	trct;

	GetWindowRect(hwind,&trct);
	if(msg.pt.x>=trct.left&&msg.pt.x<=trct.right
			&&msg.pt.y>=trct.top&&msg.pt.y<=trct.bottom)
		return 1;
	else
		return 0;
}

BOOL chkok(){

	return chkwnd(hok);
}

void mv2f(){

	unsigned	at,lo,hi,ind;

	if(rstMap(FORMSEL)){

		savdo();
		lo=0;
		hi=MAXPCS>>1;
		at=clofind<<4;
		for(ind=0;ind<hed.stchs;ind++){

			if(!(stchs[ind].at&NOTFRM)&&(stchs[ind].at&FRMSK)==at){

				stchs[lo].at=stchs[ind].at;
				stchs[lo].x=stchs[ind].x;
				stchs[lo++].y=stchs[ind].y;
			}
			else{

				stchs[hi].at=stchs[ind].at;
				stchs[hi].x=stchs[ind].x;
				stchs[hi++].y=stchs[ind].y;
			}
		}
		ind=MAXPCS>>1;
		while(ind<hi){

			stchs[lo].at=stchs[ind].at;
			stchs[lo].x=stchs[ind].x;
			stchs[lo++].y=stchs[ind++].y;
		}
		coltab();
		setMap(RESTCH);
	}
	else{

		if(rstMap(GRPSEL)){

			savdo();
			rngadj();
			hi=MAXPCS>>1;
			lo=0;
			for(ind=0;ind<gpnt0;ind++){

				stchs[hi].at=stchs[ind].at;
				stchs[hi].x=stchs[ind].x;
				stchs[hi++].y=stchs[ind].y;
			}
			for(ind=gpnt1;ind<hed.stchs;ind++){

				stchs[hi].at=stchs[ind].at;
				stchs[hi].x=stchs[ind].x;
				stchs[hi++].y=stchs[ind].y;
			}
			for(ind=gpnt0;ind<gpnt1;ind++){

				stchs[lo].at=stchs[ind].at;
				stchs[lo].x=stchs[ind].x;
				stchs[lo++].y=stchs[ind].y;
			}
			for(ind=MAXPCS>>1;ind<hi;ind++){

				stchs[lo].at=stchs[ind].at;
				stchs[lo].x=stchs[ind].x;
				stchs[lo++].y=stchs[ind].y;
			}
			coltab();
			setMap(RESTCH);
		}
	}
}

void mv2b(){

	unsigned	at,lo,hi,ind;

	if(rstMap(FORMSEL)){

		savdo();
		lo=0;
		hi=MAXPCS>>1;
		at=clofind<<4;
		for(ind=0;ind<hed.stchs;ind++){

			if(!(stchs[ind].at&NOTFRM)&&(stchs[ind].at&FRMSK)==at){

				stchs[hi].at=stchs[ind].at;
				stchs[hi].x=stchs[ind].x;
				stchs[hi++].y=stchs[ind].y;
			}
			else{

				stchs[lo].at=stchs[ind].at;
				stchs[lo].x=stchs[ind].x;
				stchs[lo++].y=stchs[ind].y;
			}
		}
		ind=MAXPCS>>1;
		while(ind<hi){

			stchs[lo].at=stchs[ind].at;
			stchs[lo].x=stchs[ind].x;
			stchs[lo++].y=stchs[ind++].y;
		}
		coltab();
		setMap(RESTCH);
	}
	else{

		if(rstMap(GRPSEL)){

			savdo();
			rngadj();
			hi=MAXPCS>>1;
			for(ind=gpnt0;ind<gpnt1;ind++){

				stchs[hi].at=stchs[ind].at;
				stchs[hi].x=stchs[ind].x;
				stchs[hi++].y=stchs[ind].y;
			}
			lo=gpnt0;
			for(ind=gpnt1;ind<hed.stchs;ind++){

				stchs[lo].at=stchs[ind].at;
				stchs[lo].x=stchs[ind].x;
				stchs[lo++].y=stchs[ind].y;
			}
			for(ind=MAXPCS>>1;ind<hi;ind++){

				stchs[lo].at=stchs[ind].at;
				stchs[lo].x=stchs[ind].x;
				stchs[lo++].y=stchs[ind].y;
			}
			coltab();
			setMap(RESTCH);
		}
	}
}

void infadj(float* px,float* py){

	if(!_finite(*px)){

		if(*px>zum0.x)
			*px=zum0.x;
		else{

			if(*px<0)
				*px=0;
		}
	}
	if(!_finite(*py)){

		if(*py>zum0.y)
			*py=zum0.y;
		else{

			if(*py<0)
				*py=0;
		}
	}
}

void delinf(){

	unsigned ind;

	for(ind=0;ind<hed.stchs;ind++)
		infadj(&stchs[ind].x,&stchs[ind].y);
	for(ind=0;ind<fltad;ind++)
		infadj(&flts[ind].x,&flts[ind].y);
}

void chkrng(FLPNT* rsiz){

	unsigned	ind,ine=0;

	delinf();
	rsiz->x=zum0.x;
	rsiz->y=zum0.y;
	if(formpnt){

		for(ind=0;ind<hed.stchs;ind++){

			if(stchs[ind].at&NOTFRM
				||((stchs[ind].at&TYPMSK)&&((stchs[ind].at&FRMSK)>>FRMSHFT<formpnt))){
				stchs[ine].at=stchs[ind].at;
				stchs[ine].x=stchs[ind].x;
				stchs[ine].y=stchs[ind].y;
				if(stchs[ine].x>rsiz->x)
					stchs[ine].x=rsiz->x-1;
				if(stchs[ine].x<0)
					stchs[ine].x=0;
				if(stchs[ine].y>rsiz->y)
					stchs[ine].y=rsiz->y-1;
				if(stchs[ine].y<0)
					stchs[ine].y=0;
				ine++;
			}
		}
		hed.stchs=ine;
	}
	else{

		for(ind=0;ind<hed.stchs;ind++){

			if(stchs[ind].x>rsiz->x)
				stchs[ind].x=rsiz->x-1;
			if(stchs[ind].x<0)
				stchs[ind].x=0;
			if(stchs[ind].y>rsiz->y)
				stchs[ind].y=rsiz->y-1;
			if(stchs[ind].y<0)
				stchs[ind].y=0;
		}
	}
}

void ritmov(){

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	if(clofine){

		if(clofine==(unsigned)frmpnt->sids-1&&frmpnt->typ==LIN)
			Polyline(rsdc,mvlin,2);
		else
			Polyline(rsdc,mvlin,3);
	}
	else{
		
		mvlin[2].x=flin[1].x;
		mvlin[2].y=flin[1].y;
		if(frmpnt->typ==LIN)
			Polyline(rsdc,&mvlin[1],2);
		else
			Polyline(rsdc,mvlin,3);
	}
	SetROP2(rsdc,R2_COPYPEN);
}

void unmov(){

	if(rstMap(SHOMOV))
		ritmov();
}

void duprct(){

	unsigned ind,strt;

	strt=pselrng.strt;
	pselrct.left=pselrct.right=flt[strt].x;
	pselrct.top=pselrct.bottom=flt[strt].y;
	strt=pdir(strt);
	for(ind=0;ind<pselrng.cnt;ind++){

		if(flt[strt].x<pselrct.left)
			pselrct.left=flt[strt].x;
		if(flt[strt].x>pselrct.right)
			pselrct.right=flt[strt].x;
		if(flt[strt].y<pselrct.bottom)
			pselrct.bottom=flt[strt].y;
		if(flt[strt].y>pselrct.top)
			pselrct.top=flt[strt].y;
		strt=pdir(strt);
	}
}

void setpsel(){

	unpsel();
	duprct();
	sRct2px(pselrct,&pxselrct);
	rct2sel(pxselrct,pselin);
	sfCor2px(flt[pselrng.fin],&pselfin);
	setMap(SHOPSEL);
	dupsel(rsdc);
	setMap(FPSEL);
}

void rotfn(){

	unsigned	ind,ine;
	double		len;
	double		tang;
	DUBPNT		trot;
	unsigned	dst;

	savdo();
	if(chkMap(FPSEL)){

		fvars(clofind);
		ine=pselrng.strt;
		for(ind=0;ind<=pselrng.cnt;ind++){

			rotflt(&flt[ine]);
			ine=pdir(ine);
		}
		frmout(clofind);
		setpsel();
		refil();
		setMap(RESTCH);
		return;
	}
	if(chkMap(BIGBOX)){

		for(ind=0;ind<fltad;ind++)
			rotflt(&flts[ind]);
		for(ind=0;ind<hed.stchs;ind++)
			rotstch(&stchs[ind]);
		for(ind=0;ind<formpnt;ind++)
			frmout(ind);
		selal();
		return;
	}
	if(rstMap(FRMSROT)){

		tang=ang;
		trot.x=rotcntr.x;
		trot.y=rotcntr.y;
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			fvars(clofind);
			for(ine=0;ine<sids;ine++)
				rotflt(&flt[ine]);
			frmout(clofind);
			refilfn();
			ang=tang;
			rotcntr.x=trot.x;
			rotcntr.y=trot.y;
		}
		setMap(RESTCH);
	}
	else{

		if(rstMap(FRMROT)){

			fvars(clofind);
			for(ind=0;ind<sids;ind++)
				rotflt(&flt[ind]);
			frmout(clofind);
			refil();
			setMap(RESTCH);
		}
		else{
		
			len=gpnt1-gpnt0+1;
			dst=0;
			for(ind=gpnt0;ind<=gpnt1;ind++)
				rotstch(&stchs[ind]);
			rngadj();
			selin(gpnt0,gpnt1,rsdc);
			setMap(RESTCH);
		}
	}
}

void rotfns(){

	savdo();
	rotfn();
}

void nulayr(unsigned play){

	actl=play;
	laycod=play>>1;
	ladj();
	if(actl){
		
		if(chkMap(FORMSEL)&&((unsigned)((formlst[clofind].at&FRMLMSK)>>1)!=actl))
			rstMap(FORMSEL);
		rstMap(GRPSEL);
		if(chkMap(SELBOX)){

			if(actl!=((stchs[cloInd].at&LAYMSK)>>LAYSHFT)+1)
				rstMap(SELBOX);
		}
		fselpnt=0;
	}
	setMap(RESTCH);
}

BOOL iselpnt(){

	unsigned	ind,ine=0;
	double		len,minlen=1e99;
	POINT		tpnt;

	tpnt.x=msg.pt.x-stOrg.x;
	tpnt.y=msg.pt.y-stOrg.y;
	for(ind=0;ind<9;ind++){

		len=hypot(tpnt.x-rctlin[ind].x,tpnt.y-rctlin[ind].y);
		if(len<minlen){

			minlen=len;
			ine=ind;
		}
	}
	if(minlen<CLOSENUF){

		cntrl=ine;
		return 1;
	}
	else
		return 0;
}

void rtrclpfn(){

	unsigned ind,len=0;

	if(OpenClipboard(hWnd)){

		fvars(clofind);
		if(iseclp(clofind)){

			len=frmpnt->nclp;
			oclp(frmpnt->clp,len);
		}
		else{

			if(isclp(clofind)){

				len=frmpnt->flencnt.nclp;
				oclp(frmpnt->angclp.clp,len);
			}
		}
		if(len){
		
			lolft.x=lolft.y=0;
			EmptyClipboard();
			hClip=RegisterClipboardFormat(pcdClip);
			clpvoid=GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,len*sizeof(CLPSTCH)+2);
			clpdat=deref(clpvoid);
			rtclpfn(0,0);
			clpdat[0].led=len;
			for(ind=1;ind<len;ind++)
				rtclpfn(ind,ind);
			SetClipboardData(hClip,clpvoid);
			CloseClipboard();
		}
	}
}

BOOL chkbig(){

	unsigned	ind;
	double		len,minlen=1e99;
	POINT		tpnt;

	tpnt.x=msg.pt.x-stOrg.x;
	tpnt.y=msg.pt.y-stOrg.y;
	for(ind=0;ind<9;ind++){

		len=hypot(tpnt.x-biglin[ind].x,tpnt.y-biglin[ind].y);
		if(len<minlen){

			minlen=len;
			cntrl=ind;
		}
	}
	for(ind=0;ind<4;ind++){

		flin[ind].x=biglin[ind<<1].x;
		flin[ind].y=biglin[ind<<1].y;
	}
	flin[4].x=flin[0].x;
	flin[4].y=flin[0].y;
	if(minlen<CLOSENUF){

		for(ind=0;ind<4;ind++){

			sizlin[ind].x=biglin[ind<<1].x;
			sizlin[ind].y=biglin[ind<<1].y;
		}
		sizlin[4].x=sizlin[0].x;
		sizlin[4].y=sizlin[0].y;
		if(cntrl&1)
			setMap(STRTCH);
		else{

			setMap(EXPAND);
			xpct=(double)(bigrct.right-bigrct.left)/(bigrct.bottom-bigrct.top);
		}
		cntrl>>=1;
		setMap(SHOSTRTCH);
		strtchbox();
		return 1;
	}
	if(tpnt.x>=bigrct.left&&tpnt.x<=bigrct.right
		&&tpnt.y>=bigrct.top&&tpnt.y<=bigrct.bottom){

		bigsiz.x=bigrct.right-bigrct.left;
		bigsiz.y=bigrct.bottom-bigrct.top;
		setMap(MOVFRMS);
		fmovdif.x=tpnt.x-bigrct.left;
		fmovdif.y=tpnt.y-bigrct.top;
		setMap(SHOSTRTCH);
		strtchbox();
		return 1;
	}
	return 0;
}

void delfre(){

	unsigned ind,ine=0;

	savdo();
	for(ind=0;ind<hed.stchs;ind++){

		if(!(stchs[ind].at&NOTFRM)){

			stchs[ine].at=stchs[ind].at;
			stchs[ine].x=stchs[ind].x;
			stchs[ine++].y=stchs[ind].y;
		}
	}
	hed.stchs=ine;
	coltab();
	setMap(RESTCH);
}

void setmov(){

	if(chkMap(SELBOX)){

		movpnt=cloInd;
		setMap(MOVSET);
		setMap(RESTCH);
	}
}

void dufsel()
{
	unsigned strt,fin;

	if(clofinx>clofind)
	{
		strt=clofind;
		fin=clofinx;
	}
	else
	{
		strt=clofinx;
		fin=clofind;
	}
	fselpnt=0;
	while(strt<=fin)
	{
		selist[fselpnt]=strt;
		strt++;
		fselpnt++;
	}
}

void selup(){

	unsigned at;

	if(GetKeyState(VK_SHIFT)&0X8000){

		rstMap(SELBOX);
		if(rstMap(FORMSEL)){

			if(clofind<formpnt-1){

				selist[0]=clofind;
				clofinx=clofind+1;
				selist[1]=clofinx;
				fselpnt=2;
			}
			else
				return;
		}
		else{

			if(fselpnt)
			{
				if(clofinx<formpnt-1)
				{
					clofinx++;
					dufsel();
				}
			}
			else
				setMap(FORMSEL);
		}
		setMap(RESTCH);
	}
	else{

		if(chkMap(SELBOX)){

			unbox();
			at=stchs[cloInd].at&ATMSK;
			while(cloInd<(unsigned)hed.stchs-1&&(stchs[cloInd].at&ATMSK)==at)
				cloInd++;
			stch2px(cloInd);
			dubox();
		}
		else{

			if(formpnt){

				if(setMap(FORMSEL)){

					if(clofind<(unsigned)formpnt-1)
						clofind++;
				}
				else
					clofind=0;
				ritnum(STR_NUMFORM,clofind);
				setMap(RESTCH);
			}
		}
	}
}

void seldwn(){

	unsigned at;

	if(GetKeyState(VK_SHIFT)&0X8000){

		rstMap(SELBOX);
		if(rstMap(FORMSEL)){

			if(clofind){

				selist[0]=clofind;
				clofinx=clofind-1;
				selist[1]=clofinx;
				fselpnt=2;
			}
			else
				return;
		}
		else{

			if(fselpnt)
			{
				if(clofinx)
				{
					clofinx--;
					dufsel();
				}
			}
			else
				setMap(FORMSEL);
		}
		setMap(RESTCH);
	}
	else{

		if(chkMap(SELBOX)){

			unbox();
			at=stchs[cloInd].at&ATMSK;
			while(cloInd&&(stchs[cloInd].at&ATMSK)==at)
				cloInd--;
			stch2px(cloInd);
			dubox();
		}
		else{

			if(formpnt){

				if(setMap(FORMSEL)){

					if(clofind)
						clofind--;
				}
				else
					clofind=formpnt-1;
				ritnum(STR_NUMFORM,clofind);
				setMap(RESTCH);
			}
		}
	}
}

void mvstchs(unsigned dst,unsigned src,unsigned cnt){
	memcpy(stchs + dst, stchs + src, cnt * sizeof(*stchs));
}

BOOL movstchs(unsigned dst,unsigned strt,unsigned fin){

	unsigned cnt,ind;
	unsigned dind=MAXPCS>>1;

	if(dst<(unsigned)hed.stchs-1)
		dst++;
	if(strt>fin){

		ind=strt;
		strt=fin;
		fin=ind;
	}
	if(dst>=strt&&dst<fin){

		tabmsg(IDS_DST1);
		return 0;
	}
	if(dst<strt){

		cnt=fin-strt;
		mvstchs(dind,strt,cnt);
		dind+=cnt;
		cnt=strt-dst;
		mvstchs(dind,dst,cnt);
		dind+=cnt;
		mvstchs(dst,MAXPCS>>1,dind-(MAXPCS>>1));
	}
	else{

		cnt=dst-fin;
		mvstchs(dind,fin,cnt);
		dind+=cnt;
		cnt=fin-strt;
		mvstchs(dind,strt,cnt);
		dind+=cnt;
		mvstchs(strt,MAXPCS>>1,dind-(MAXPCS>>1));
	}
	return 1;
}

void movmrk(){

	if(chkMap(MOVSET)){

		if(chkMap(GRPSEL)){

			rngadj();
			if(movstchs(movpnt,gpnt0,gpnt1)){

				coltab();
				setMap(RESTCH);
			}
		}
		else{

			if(chkMap(SELBOX)){

				if(movstchs(movpnt,cloInd,cloInd+1)){

					setMap(RESTCH);
					coltab();
				}
			}
		}
	}
}

void vuthrds(){

	if(GetMenuState(hvumen,ID_VUTHRDS,MF_BYCOMMAND)&MF_CHECKED){

		CheckMenuItem(hMen,ID_VUTHRDS,MF_BYCOMMAND|MF_UNCHECKED);
		rstMap(THRDS);
	}
	else{

		CheckMenuItem(hMen,ID_VUTHRDS,MF_BYCOMMAND|MF_CHECKED);
		setMap(THRDS);
	}
	setMap(RESTCH);
}

void vuselthr(){

	if(GetMenuState(hvumen,ID_VUSELTHRDS,MF_BYCOMMAND)&MF_CHECKED){

		CheckMenuItem(hMen,ID_VUSELTHRDS,MF_BYCOMMAND|MF_UNCHECKED);
		rstMap(COL);
	}
	else{

		CheckMenuItem(hMen,ID_VUSELTHRDS,MF_BYCOMMAND|MF_CHECKED);
		setMap(COL);
	}
	setMap(RESTCH);
}

void colchk(){

	unsigned col,cind,ind;

	col=stchs[0].at&COLMSK;
	cind=0;
	for(ind=0;ind<hed.stchs;ind++){

		if(col!=(stchs[ind].at&COLMSK)){

			if(ind-cind==1)
				stchs[ind-1].at=stchs[ind].at&NCOLMSK|(stchs[cind-1].at&COLMSK);
			col=stchs[ind].at&COLMSK;
			cind=ind;
		}
	}
}

unsigned makbig(unsigned strt,unsigned fin){

	unsigned	dst,src,cnt,ine,adcnt=0,at;
	SHRTPNT*	tstchs0;
	SHRTPNT*	tstchs1;
	double		len;
	DUBPNT		dif,stp,pnt;

	dst=MAXPCS>>1;
	for(src=strt;src<(unsigned)fin-1;src++){

		dif.x=stchs[src+1].x-stchs[src].x;
		dif.y=stchs[src+1].y-stchs[src].y;
		len=hypot(dif.x,dif.y);
		mvstch(dst++,src);
		if(len>ini.maxsiz){
			
			cnt=ceil(len/usesiz);
			stp.x=dif.x/cnt;
			stp.y=dif.y/cnt;
			pnt.x=stchs[src].x+stp.x;
			pnt.y=stchs[src].y+stp.y;
			at=stchs[src].at;
			if(at!=stchs[src+1].at){

				if(!(at&NOTFRM)&&stchs[src+1].at&TYPMSK){

					if(!((at&FRMSK)==(stchs[src+1].at&FRMSK)))
						at&=NTYPMSK;	
				}
				else
					at&=NTYPMSK;
			}
			at&=(~KNOTMSK);
			for(ine=0;ine<cnt-1;ine++){

				stchs[dst].at=at;
				stchs[dst].x=pnt.x;
				stchs[dst++].y=pnt.y;
				pnt.x+=stp.x;
				pnt.y+=stp.y;
				adcnt++;
			}
		}
	}
	while(src<hed.stchs)
		mvstch(dst++,src++);
	tstchs0=&stchs[MAXPCS>>1];
	tstchs1=&stchs[strt];
	cnt=dst-(MAXPCS>>1);
	for(src=0;src<cnt;src++)
		tstchs1[src]=tstchs0[src];
	hed.stchs=strt+cnt;
	return adcnt;
}

void rembig(){

	RANG rng;
	unsigned ind;

	if(usesiz<ini.maxsiz){

		savdo();
		if(fselpnt){

			for(ind=0;ind<fselpnt;ind++){

				frmrng(selist[ind],&rng);
				makbig(rng.strt,rng.fin);	
			}
			goto bigdun;
		}
		if(chkMap(FORMSEL)){

			frmrng(clofind,&rng);
			makbig(rng.strt,rng.fin);
			goto bigdun;
		}
		if(chkMap(GRPSEL)){

			rngadj();
			if(gpnt1<hed.stchs)
				gpnt1++;
			if(cloInd<grpInd)
				grpInd+=makbig(gpnt0,gpnt1);
			else
				cloInd+=makbig(gpnt0,gpnt1);
			grpAdj();
			goto bigdun;
		}
		makbig(0,hed.stchs);

bigdun:;
		coltab();
		setMap(RESTCH);
	}
	else
		tabmsg(IDS_REM1);
}

void duselrng(){

	selfrng.strt=0;
	selfrng.fin=hed.stchs;
	if(chkMap(GRPSEL)){

		rngadj();
		selfrng.strt=gpnt0;
		selfrng.fin=gpnt1;
		return;
	}
}

void longer(){

	unsigned	ind,ine;
	double		len,minlen=1e99;
	double		curlen;

	if(cloInd==maxpnt)
		return;
	curlen=hypot(stchs[cloInd+1].x-stchs[cloInd].x,stchs[cloInd+1].y-stchs[cloInd].y);
	for(ind=cloInd+1;ind<selfrng.fin;ind++){

		len=hypot(stchs[ind+1].x-stchs[ind].x,stchs[ind+1].y-stchs[ind].y);
		if(len==curlen)
			goto long1;
	}
	for(ine=selfrng.strt;ine<selfrng.fin-1;ine++){

		len=hypot(stchs[ine+1].x-stchs[ine].x,stchs[ine+1].y-stchs[ine].y);
		if(len>curlen&&len<minlen){

			minlen=len;
			ind=ine;
		}
	}
	if(minlen==1e99)
		return;
long1:;
	srchpnt=ind;
	lensadj();
	ritnum(STR_NUMSCH,cloInd);
}

void shorter(){

	unsigned	ind,ine;
	double		len,maxlen=0;
	double		curmax;

	if(cloInd==minpnt)
		return;
	curmax=hypot(stchs[cloInd+1].x-stchs[cloInd].x,stchs[cloInd+1].y-stchs[cloInd].y);
	for(ine=cloInd-1;ine<selfrng.fin;ine--){

			len=hypot(stchs[ine+1].x-stchs[ine].x,stchs[ine+1].y-stchs[ine].y);
			if(len==curmax)
				goto short1;
	}
	for(ind=selfrng.strt;ind<selfrng.fin-1;ind++){

		len=hypot(stchs[ind+1].x-stchs[ind].x,stchs[ind+1].y-stchs[ind].y);
		if(len<curmax&&len>maxlen){

			maxlen=len;
			ine=ind;
		}
	}
	sprintf(msgbuf,"%.2f",hypot(stchs[ind+1].x-stchs[ind].x,stchs[ind+1].y-stchs[ind].y));
	butxt(HMINLEN,msgbuf);
short1:;
	srchpnt=ine;
	lensadj();
	ritnum(STR_NUMSCH,cloInd);
}

void setsrch(unsigned stind){

	srchpnt=stind;
	lensadj();
	ritnum(STR_NUMSCH,cloInd);
}

BOOL inrng(unsigned stind){

	if(   stchs[stind].x>=rngrct.left
		&&stchs[stind].x<=rngrct.right
		&&stchs[stind].y>=rngrct.bottom
		&&stchs[stind].y<=rngrct.top)

		return 1;
	else
		return 0;
}

BOOL finrng(unsigned find){

	unsigned cod;

	if(   formlst[find].rct.left>=rngrct.left
		&&formlst[find].rct.right<=rngrct.right
		&&formlst[find].rct.bottom>=rngrct.bottom
		&&formlst[find].rct.top<=rngrct.top){

		if(!actl)
			return 1;
		cod=(formlst[find].at&FRMLMSK)>>1;
		if(!cod||actl==cod)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void ungrplo(){

	unsigned ind;

	if(rstMap(GRPSEL)){

		rngadj();
		cloInd=gpnt0;
		setMap(SELBOX);
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			for(ind=0;ind<hed.stchs;ind++){

				if(!(stchs[ind].at&NOTFRM)&&((stchs[ind].at&FRMSK)>>FRMSHFT)==clofind){

					cloInd=ind;
					setMap(SELBOX);
					setMap(RESTCH);
					goto upgrpdun;
				}
			}
			grpmsg1();
		}
		else
			grpmsg();
	}
upgrpdun:;
}

void ungrphi(){

	unsigned ind;

	if(rstMap(GRPSEL)){

		rngadj();
		cloInd=gpnt1;
		setMap(SELBOX);
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			for(ind=hed.stchs-1;ind<hed.stchs;ind--){

				if(!(stchs[ind].at&NOTFRM)&&((stchs[ind].at&FRMSK)>>FRMSHFT)==clofind){

					cloInd=ind;
					setMap(SELBOX);
					setMap(RESTCH);
					goto dwngrpdun;
				}
			}
			grpmsg1();
		}
		else
			grpmsg();
	}
dwngrpdun:;
}

void sizstch(FLRCT* rct){

	unsigned ind;

	if(hed.stchs){

		rct->bottom=rct->top=stchsr[0].y;
		rct->left=rct->right=stchsr[0].x;
		for(ind=1;ind<hed.stchs;ind++){

			if(stchsr[ind].x<rct->left)
				rct->left=stchsr[ind].x;
			if(stchsr[ind].x>rct->right)
				rct->right=stchsr[ind].x;
			if(stchsr[ind].y<rct->bottom)
				rct->bottom=stchsr[ind].y;
			if(stchsr[ind].y>rct->top)
				rct->top=stchsr[ind].y;
		}
	}
	else
		rct->top=rct->bottom=rct->left=rct->right=0;
}

void hupfn(){

	unsigned	ind;
	DUBPNT		hupcntr;
	DUBPNT		descntr;
	DUBPNT		tsiz;
	DUBPNT		dif;
	
	rstMap(HUPCHNG);
	stchsr=stchs;
	sizstch(&chkhuprct);
	if(formpnt){

		if(!hed.stchs){

			chkhuprct.bottom=chkhuprct.top=flt[0].y;
			chkhuprct.left=chkhuprct.right=flt[0].x;
		}
		for(ind=0;ind<fltad;ind++){

			if(flts[ind].x<chkhuprct.left)
				chkhuprct.left=flts[ind].x;
			if(flts[ind].x>chkhuprct.right)
				chkhuprct.right=flts[ind].x;
			if(flts[ind].y<chkhuprct.bottom)
				chkhuprct.bottom=flts[ind].y;
			if(flts[ind].y>chkhuprct.top)
				chkhuprct.top=flts[ind].y;
		}
	}
	if(hed.stchs||fltad||chkMap(HUPEX)){

		if(	chkhuprct.left<0||
			chkhuprct.right>ini.hupx||
			chkhuprct.bottom<0||
			chkhuprct.top>ini.hupy){

			setMap(HUPEX);
		}
		if(chkMap(HUPEX)){

			tsiz.x=chkhuprct.right-chkhuprct.left;
			tsiz.y=chkhuprct.top-chkhuprct.bottom;
			if(tsiz.x>ini.hupx){

				ini.hupx=tsiz.x;
				setMap(HUPCHNG);
			}
			if(tsiz.y>ini.hupy){

				ini.hupy=tsiz.y;
				setMap(HUPCHNG);
			}
			descntr.x=tsiz.x/2+chkhuprct.left;
			descntr.y=tsiz.y/2+chkhuprct.bottom;
			hupcntr.x=ini.hupx/2;
			hupcntr.y=ini.hupy/2;
			dif.x=hupcntr.x-descntr.x;
			dif.y=hupcntr.y-descntr.y;
			for(ind=0;ind<hed.stchs;ind++){

				stchs[ind].x+=dif.x;
				stchs[ind].y+=dif.y;
			}
			for(ind=0;ind<fltad;ind++){

				flts[ind].x+=dif.x;
				flts[ind].y+=dif.y;
			}
			for(ind=0;ind<formpnt;ind++){

				formlst[ind].rct.left+=dif.x;
				formlst[ind].rct.right+=dif.x;
				formlst[ind].rct.top+=dif.y;
				formlst[ind].rct.bottom+=dif.y;
			}
			zum0.x=ini.hupx;
			zum0.y=ini.hupy;
			zumflor=(double)MINZUM/zum0.x;
			zumhom();
		}
	}
}

void chkhup(){

	setMap(HUPEX);
	hupfn();
	if(chkMap(INIT))
		prfmsg();
	setfchk();
}

int strcomp( const void *arg1, const void *arg2 ){

   return _stricmp(*(TCHAR**)arg1,*(TCHAR**)arg2);
}

void strlcpy(TCHAR* dst,TCHAR* src){
	for (;;) {
		TCHAR chr = *(dst++);

		if (chr == 0)
			break;

		chr &= 0x7f;

		if (bt(upmap, chr))
			chr |= 0x20;

		*(dst++) = chr;
	}

	*dst = 0;
}

TCHAR lchr(int op){
	TCHAR chr = op & 0x7f;

	return bt(upmap, chr) ? chr : chr | 0x20;
}

void barnam(HWND hndl,unsigned fpnt){

	TCHAR		buf[MAX_PATH];
	TCHAR*		pchr;

	if(fpnt<thumdcnt&&thumsel[fpnt]){

		strcpy(buf,thumsel[fpnt]);
		pchr=strrchr(buf,'.');
		if(pchr)
			pchr[0]=0;
		SetWindowText(hndl,buf);
	}
	else
		SetWindowText(hndl,"");
}

void rthumnam(unsigned ind){

	switch(ind){

	case 0:

		barnam(hbuts[HNUM],ind);
		break;

	case 1:

		barnam(hbuts[HTOT],ind);
		break;

	case 2:

		barnam(hbuts[HMINLEN],ind);
		break;

	case 3:

		barnam(hbuts[HMAXLEN],ind);
		break;
	}
}

void thumnail(){

	WIN32_FIND_DATA	fdat;
	unsigned		ind,ine;
	HANDLE			shndl;
	TCHAR*			pchr;

	unbsho();
	undat();
	untrace();
	thumnams=(TCHAR*)oseq;
	pthums=(TCHAR**)&oseq[MAXSEQ>>1];

	SetCurrentDirectory(defDir);
	strcpy(srchnam,defDir);
	pchr=&srchnam[strlen(srchnam)-1];
	if(pchr[0]!='\\'){

		pchr[1]='\\';
		pchr[2]=0;
	}
	strcat(srchnam,"*.thr");
	shndl=FindFirstFile(srchnam,&fdat);
	if(shndl==INVALID_HANDLE_VALUE){
		
		sprintf(msgbuf,"Can't find %s\n",srchnam);
		shoMsg(msgbuf);
		unthum();
	}
	else{

		ine=0;
		pthums[0]=thumnams;
		strcpy(pthums[0],fdat.cFileName);
		ine+=strlen(fdat.cFileName)+1;
		pthums[1]=&thumnams[ine];
		ind=1;
		while(FindNextFile(shndl,&fdat)){

			strcpy(pthums[ind],fdat.cFileName);
			ine+=strlen(fdat.cFileName)+1;
			pthums[++ind]=&thumnams[ine];
		}
		FindClose(shndl);
		thumcnt=ind;
		qsort((void*)&pthums[0],ind,4,strcomp);
		ind=thumind=0;
		while(ind<4&&thumind<thumcnt&&ind<thumcnt){

			thumsel[ind]=pthums[ind];
			ind++;
		}
		thumind=thumdcnt=ind;
		while(ind<4&&ind<thumcnt)
			rthumnam(ind++);
		setMap(THUMSHO);
		thumsrch[0]=0;
		SetWindowText(hbuts[HBOXSEL],"");
		butxt(HBOXSEL,"");
		vubak();
		setMap(RESTCH);
	}
}

void nuthsel(){

	unsigned ind,len,bakind;

	if(thumind<thumcnt){

		bakind=thumind;
		ind=0;
		len=strlen(thumsrch);
		setMap(RESTCH);
		if(len){

			while(ind<4&&thumind<thumcnt){

				if(!strncmp(thumsrch,pthums[thumind],len)){

					thumsel[ind]=pthums[thumind];
					redraw(hvu[ind++]);
				}
				thumind++;
			}
		}
		else{

			while(ind<4&&thumind<thumcnt){

				thumsel[ind]=pthums[thumind];
				redraw(hvu[ind++]);
				thumind++;
			}
		}
		if(ind){

			thumdcnt=ind;
			while(ind<4)
				rthumnam(ind++);
		}
		else
			thumind=bakind;
	}
}

void nuthbak(unsigned cnt){

	unsigned len;

	if(thumind){

		len=strlen(thumsrch);
		if(len){

			while(cnt&&thumind<MAXFORMS){

				if(thumind){

					thumind--;
					if(!strncmp(thumsrch,pthums[thumind],len))
						cnt--;
				}
				else
					break;
			}
		}
		else
			thumind-=cnt;
		if(thumind>MAXFORMS)
			thumind=0;
		nuthsel();
	}
}

void nuthum(TCHAR chr){

	unsigned ind;

	ind=strlen(thumsrch);
	if(ind<16){

		setMap(RESTCH);
		thumsrch[ind++]=chr;
		thumsrch[ind]=0;
		butxt(HBOXSEL,thumsrch);
		thumind=0;
		nuthsel();
	}
}

void bakthum(){

	unsigned ind;

	ind=strlen(thumsrch);
	if(ind){

		setMap(RESTCH);
		thumsrch[--ind]=0;
		thumind=0;
		butxt(HBOXSEL,thumsrch);
		nuthsel();
	}
}

void selalstch(){

	if(hed.stchs){
	
		cloInd=0;
		grpInd=hed.stchs-1;
		gpnt0=cloInd;
		gpnt1=grpInd;
		setMap(GRPSEL);
		setMap(SCROS);
		setMap(ECROS);
		grpAdj();
		setMap(RESTCH);
	}
}

void insflin(POINT ipnt){

	POINT off;

	off.x=inspnt.x>>1;
	off.y=inspnt.y>>1;

	flin[0].x=flin[3].x=flin[4].x=ipnt.x-off.x;
	flin[1].x=flin[2].x=ipnt.x+off.x;
	flin[0].y=flin[1].y=flin[4].y=ipnt.y-off.y;
	flin[2].y=flin[3].y=ipnt.y+off.y;
}

BOOL isthr(TCHAR* nam){

	TCHAR* pchr;

	pchr=strrchr(nam,'.');
	if(pchr){

		pchr++;
		if(!strnicmp(pchr,"th",2))
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

unsigned gethand(SHRTPNT* pstch,unsigned cnt){

	unsigned ind;
	unsigned ocnt;

	ocnt=0;
	for(ind=0;ind<cnt;ind++){

		if(pstch[ind].at&USMSK)
			ocnt++;
	}
	return ocnt;
}

void insfil(){

	OPENFILENAME oin={

		sizeof(OPENFILENAME),	//lStructsize
		hWnd,					//hwndOwner 
		hInst,					//hInstance 
		"THR files\0*.thr\0\0",	//lpstrFilter 
		cstFltr,				//lpstrCustomFilter 
		MAX_PATH,				//nMaxCustFilter 
		0,						//nFilterIndex 
		insnam,					//lpstrFile 
		MAX_PATH,				//nMaxFile 
		0,						//lpstrFileTitle 
		0,						//nMaxFileTitle 
		defDir,					//lpstr	ialDir 
		0,						//lpstrTitle
		OFN_EXPLORER|OFN_OVERWRITEPROMPT,//Flags
		0,						//nFileOffset
		0,						//nFileExtension 
		"thr",					//lpstrDefExt 
		0,						//lCustData 
		0,						//lpfnHook
		0,						//lpTemplateName
	};
	STRHED		thed;
	STREX		thedx;
	HED			tphed;
	unsigned	ind,ine,cod,codof;
	FLRCT		trct;
	FLPNT		tsiz;
	POINT		tpnt;
	PCSTCH*		tbuf;
	double		homscor;
	double		filscor;
	unsigned	vervar;
	FRMHEDO*	frmlstx;

	if(chkMap(IGNORINS)||GetOpenFileName(&oin)){
				
		hinsf=CreateFile(insnam,(GENERIC_READ),0,NULL,
				OPEN_EXISTING,0,NULL);
		if(hinsf==INVALID_HANDLE_VALUE){

			filnopn(IDS_FNOPN,insnam);
			hFil=0;
			CloseHandle(hinsf);
		}
		else{

			insfstch=hed.stchs;
			if(isthr(insnam)){

				ReadFile(hinsf,(STRHED*)&thed,sizeof(STRHED),&red,NULL);
				if((thed.led&0xffffff)!=0x746872)
					tabmsg(IDS_NOTHR);
				else{

					vervar=(thed.led&0xff000000)>>24;
					if(vervar){
#define FRMW 5
#define HANDW 4
#define FRMPW 2
#define STCHW 1			
						gethand(stchs,hed.stchs);
						homscor=(double)
							formpnt*FRMW+
							gethand(stchs,hed.stchs)*HANDW+
							fltad*FRMPW+
							hed.stchs*STCHW;
						ReadFile(hinsf,(STREX*)&thedx,sizeof(STREX),&red,0);
					}
					savdo();
					ReadFile(hinsf,(SHRTPNT*)&stchs[hed.stchs],thed.stchs*sizeof(SHRTPNT),&red,NULL);
					SetFilePointer(hinsf,164,0,FILE_CURRENT);
					trct.left=trct.bottom=(float)1e9;
					trct.top=trct.right=(float)1e-9;
					codof=formpnt<<FRMSHFT;
					insflt=fltad;insfpnt=formpnt;
					if(thed.fcnt){

						if(vervar<2){

							frmlstx=(FRMHEDO*)&bseq;
							ReadFile(hinsf,(FRMHEDO*)&bseq,thed.fpnt*sizeof(FRMHEDO),&red,0);
							if(red!=thed.fpnt*sizeof(FRMHEDO)){

								formpnt=red/sizeof(FRMHEDO);
								setMap(BADFIL);
							}
							if(formpnt+thed.fcnt<MAXFORMS){

								FillMemory(&formlst[formpnt],thed.fpnt*sizeof(FRMHED),0);
								ine=formpnt;
								for(ind=0;ind<thed.fpnt;ind++){

									MoveMemory(&formlst[ine],&frmlstx[ind],sizeof(FRMHEDO));
									ine++;
								}
							}
						}
						else
							ReadFile(hinsf,(FRMHED*)&formlst[formpnt],thed.fpnt*sizeof(FRMHED),&red,0);
						ReadFile(hinsf,(FLPNT*)&flts[fltad],thed.fcnt*sizeof(FLPNT),&red,0);
						ReadFile(hinsf,(SATCON*)&satks[satkad],thed.scnt*sizeof(SATCON),&red,0);
						ReadFile(hinsf,(FLPNT*)&clps[clpad],thed.ecnt*sizeof(FLPNT),&red,0);
						CloseHandle(hinsf);
						hinsf=0;
						for(ind=formpnt;ind<formpnt+thed.fpnt;ind++){

							formlst[ind].flt=adflt(formlst[ind].sids);
							if(formlst[ind].typ==SAT){
								
								if(formlst[ind].stpt)
									formlst[ind].sacang.sac=adsatk(formlst[ind].stpt);
								if(isclpx(ind))
									formlst[ind].angclp.clp=adclp(formlst[ind].flencnt.nclp);
							}
							if(isclp(ind))
								formlst[ind].angclp.clp=adclp(formlst[ind].flencnt.nclp);
							if(iseclpx(ind))
								formlst[ind].clp=adclp(formlst[ind].nclp);
						}
						formpnt+=thed.fpnt;
						if(thed.fpnt){

							trct.left=trct.right=flts[insflt].x;
							trct.bottom=trct.top=flts[insflt].y;
							for(ind=insflt+1;ind<fltad;ind++){

								if(flts[ind].x<trct.left)
									trct.left=flts[ind].x;
								if(flts[ind].x>trct.right)
									trct.right=flts[ind].x;
								if(flts[ind].y<trct.bottom)
									trct.bottom=flts[ind].y;
								if(flts[ind].y>trct.top)
									trct.top=flts[ind].y;
							}
						}
					}
					if(thed.stchs){

						for(ind=hed.stchs;ind<(unsigned)hed.stchs+thed.stchs;ind++){

							if(stchs[ind].at&ALTYPMSK){

								cod=(stchs[ind].at&FRMSK)+codof;
								stchs[ind].at&=NFRMSK;
								stchs[ind].at|=cod;
							}
							if(stchs[ind].x<trct.left)
								trct.left=stchs[ind].x;
							if(stchs[ind].x>trct.right)
								trct.right=stchs[ind].x;
							if(stchs[ind].y<trct.bottom)
								trct.bottom=stchs[ind].y;
							if(stchs[ind].y>trct.top)
								trct.top=stchs[ind].y;
						}
					}
					if(thed.led&0x1000000){
					
						filscor=(double)thed.fpnt*FRMW+
							gethand(&stchs[hed.stchs],thed.stchs)*HANDW+
							thed.fpnts*FRMPW+
							thed.stchs*STCHW;
						if(filscor>homscor){
						
							for(ind=0;ind<50;ind++)
								hedx.crtnam[ind]=thedx.crtnam[ind];
							redfnam(fildes);
							sprintf(msgbuf,stab[STR_THRDBY],thrnam,fildes);
							SetWindowText(hWnd,msgbuf);
						}
					}
					inscntr.x=(trct.right-trct.left)/2+trct.left;
					inscntr.y=(trct.top-trct.bottom)/2+trct.bottom;
					hed.stchs+=thed.stchs;
					tsiz.x=trct.right-trct.left;
					tsiz.y=trct.top-trct.bottom;
					ratsr();
					inspnt.x=tsiz.x*hfrat;
					inspnt.y=tsiz.y*hfrat;
					tpnt.x=scRct.right>>1;
					tpnt.y=scRct.bottom>>1;
					insflin(tpnt);
					nuflen=5;
					setMap(SHOFRM);
					setMap(INSFIL);
					dufrm();
				}
			}
			else{

				ReadFile(hinsf,(HED*)&tphed,0x46,&red,NULL);
				if(hed.ledIn==0x32&&hed.fColCnt==16){

					savdo();
					tbuf=(PCSTCH*)bseq;
					ReadFile(hinsf,(PCSTCH*)tbuf,tphed.stchs*sizeof(PCSTCH),&red,NULL);
					ine=hed.stchs;
					cod=0;
					for(ind=0;ind<tphed.stchs;ind++){

						if(tbuf[ind].typ==3)
							cod=tbuf[ind++].fx;
						else{

							stchs[ine].x=tbuf[ind].x+(float)tbuf[ind].fx/256;
							stchs[ine].y=tbuf[ind].y+(float)tbuf[ind].fy/256;
							stchs[ine++].at=cod;
						}
					}
					ind=hed.stchs;
					trct.left=trct.right=stchs[ind].x;
					trct.top=trct.bottom=stchs[ind++].y;
					while(ind<(unsigned)ine){

						if(stchs[ind].x<trct.left)
							trct.left=stchs[ind].x;
						if(stchs[ind].x>trct.right)
							trct.right=stchs[ind].x;
						if(stchs[ind].y<trct.bottom)
							trct.bottom=stchs[ind].y;
						if(stchs[ind].y>trct.top)
							trct.top=stchs[ind].y;
						ind++;
					}
					inscntr.x=(trct.right-trct.left)/2+trct.left;
					inscntr.y=(trct.top-trct.bottom)/2+trct.bottom;
					hed.stchs=ine;
					tsiz.x=trct.right-trct.left;
					tsiz.y=trct.top-trct.bottom;
					ratsr();
					inspnt.x=tsiz.x*hfrat;
					inspnt.y=tsiz.y*hfrat;
					tpnt.x=scRct.right>>1;
					tpnt.y=scRct.bottom>>1;
					insflin(tpnt);
					nuflen=5;
					setMap(SHOFRM);
					setMap(INSFIL);
					dufrm();
				}
			}
			if(hinsf)
				CloseHandle(hinsf);
		}
	}
}

void duinsfil(){

	FLPNT		off;
	unsigned	ind;
	FLRCT*		trct;

	px2stch();
	off.x=sPnt.x-inscntr.x;
	off.y=sPnt.y-inscntr.y;
	for(ind=insfpnt;ind<formpnt;ind++){

		trct=&formlst[ind].rct;
		trct->bottom+=off.y;
		trct->top+=off.y;
		trct->left+=off.x;
		trct->right+=off.x;
	}
	for(ind=insflt;ind<fltad;ind++){

		flts[ind].x+=off.x;
		flts[ind].y+=off.y;
	}
	for(ind=insfstch;ind<hed.stchs;ind++){

		stchs[ind].x+=off.x;
		stchs[ind].y+=off.y;
	}
	rstMap(FRMOF);
	setMap(INIT);
	coltab();
	setMap(RESTCH);
}

void gotbox(){

	rstMap(BZUMIN);
	rstMap(BOXSLCT);
	rstMap(FRMPSEL);
	grpAdj();
}

void rngal(){

	unsigned	ind,ine,in;
	unsigned	pmax,maxlen,len;
	RANG*		prng;

	if(!rstMap(WASFPNT)){

		rstMap(GRPSEL);
		ind=ine=in=0;
		prng=(RANG*)&bseq;
		rstMap(GRPSEL);
		while(ind<hed.stchs){

			if(inrng(ind)){

				if(!in){

					prng[ine].strt=ind;
					in=1;
				}
			}
			else{

				if(in){

					prng[ine].fin=ind-1;
					ine++;
					in=0;
				}
			}
			ind++;
		}
		if(in){

			prng[ine].fin=ind-1;
			ine++;
		}
		if(ine){

			maxlen=0;
			for(ind=0;ind<ine;ind++){

				len=prng[ind].fin-prng[ind].strt;
				if(len>maxlen){

					maxlen=len;
					pmax=ind;
				}
			}
			if(maxlen){

				cloInd=prng[pmax].strt;
				grpInd=prng[pmax].fin;
				setMap(GRPSEL);
			}
			gotbox();
		}
	}
}

void nucols(){

	unsigned ind;

	clRmap((formpnt<<5)+1);
	for(ind=0;ind<fselpnt;ind++){

		setr(selist[ind]);
		frmpnt=&formlst[ind];
		if(frmpnt->ftyp){

			frmpnt->fcol=actcol;
			frmpnt->dhx.fth.fthcol=actcol;
		}
		if(frmpnt->etyp)
			frmpnt->bcol=actcol;
		if(frmpnt->xat&(AT_UND|AT_WALK|AT_CWLK))
			frmpnt->ucol=actcol;
	}
	for(ind=0;ind<hed.stchs;ind++){

		if(chkr((stchs[ind].at&FRMSK)>>FRMSHFT)&&(stchs[ind].at&TYPMSK)!=TYPMSK){

			stchs[ind].at&=NCOLMSK;
			stchs[ind].at|=actcol;
		}
	}
}

BOOL dunum(unsigned cod){

	if(cod>='0'&&cod<='9'){

		numcod=cod;
		return 1;
	}
	if(cod>=VK_NUMPAD0&&cod<=VK_NUMPAD9){

		numcod=cod-'0';
		return 1;
	}
	return 0;
}

void stchrct(FLRCT* rct)
{
	unsigned ind;

	if(hed.stchs)
	{
		rct->bottom=rct->left=1e10;
		rct->top=rct->right=0;
		if(hed.stchs){

			for(ind=0;ind<hed.stchs;ind++){

				if(stchs[ind].x<rct->left)
					rct->left=stchs[ind].x;
				if(stchs[ind].x>rct->right)
					rct->right=stchs[ind].x;
				if(stchs[ind].y<rct->bottom)
					rct->bottom=stchs[ind].y;
				if(stchs[ind].y>rct->top)
					rct->top=stchs[ind].y;
			}
		}
	}
}

void frmrct(FLRCT* rct)
{
	unsigned ind;

	rct->left=rct->right=flts[0].x;
	rct->top=rct->bottom=flts[0].y;
	for(ind=0;ind<fltad;ind++){

		if(flts[ind].x<rct->left)
			rct->left=flts[ind].x;
		if(flts[ind].x>rct->right)
			rct->right=flts[ind].x;
		if(flts[ind].y>rct->top)
			rct->top=flts[ind].y;
		if(flts[ind].y<rct->bottom)
			rct->bottom=flts[ind].y;
	}
}

void desiz(){

	FLRCT		trct;
	FLOAT		sizx,sizy;
	TCHAR*		pmsg;

	pmsg=msgbuf;
	if(hed.stchs){

		stchrct(&trct);
		sizx=(trct.right-trct.left)/PFGRAN;
		sizy=(trct.top-trct.bottom)/PFGRAN;
		if((trct.left<0)||(trct.bottom<0)||(trct.right>ini.hupx)||(trct.top>ini.hupy)){
		
			strcpy(msgbuf,stab[STR_STCHOUT]);
			pmsg=&msgbuf[strlen(msgbuf)];
		}
#if LANG==ENG||LANG==HNG

		sprintf(pmsg,
			stab[STR_STCHS],
			hed.stchs,
			sizx,sizx/25.4,
			sizy,sizy/25.4);
#endif

#if LANG==GRM

		sprintf(pmsg,
			stab[STR_STCHS],
			hed.stchs,
			sizx,
			sizy);
#endif
		pmsg=&pmsg[strlen(pmsg)];
	}
	if(formpnt){

		frmrct(&trct);
		sizx=(trct.right-trct.left)/PFGRAN;
		sizy=(trct.top-trct.bottom)/PFGRAN;
#if LANG==ENG||LANG==HNG
		
		sprintf(pmsg,stab[STR_FORMS],
			formpnt,
			sizx,sizx/25.4,
			sizy,sizy/25.4);
#endif

#if LANG==GRM
		
		sprintf(pmsg,stab[STR_FORMS],
			formpnt,
			sizx,
			sizy);
#endif
		pmsg=&pmsg[strlen(pmsg)];
	}	
	sprintf(pmsg,stab[STR_HUPWID],
		   ini.hupx/PFGRAN,
		   ini.hupy/PFGRAN);
	pmsg=&pmsg[strlen(pmsg)];
	if(hed.stchs){

		sprintf(pmsg,stab[STR_CREATBY],
			 fildes,
			 hedx.modnam);
	}
	shoMsg(msgbuf);
}

void sidhup(){

	RECT		huprct;
	RECT		prfrct;
	unsigned	ind;

	setMap(HUPMSG);
	GetWindowRect(thDat[PHUP],&huprct);
	GetWindowRect(hPrf,&prfrct);
	hSid=CreateWindow(
		"STATIC",
		0,
		WS_BORDER|WS_CHILD|WS_VISIBLE,
		prfrct.right+3-morg.x,
		huprct.top-morg.y,
		buttonWid3+buttonWid*2+6,
		buttonHi*HUPS+6,
		hWnd,
		NULL,
		hInst,
		NULL);
	for(ind=0;ind<HUPS;ind++){

		hsidWnd[ind]=CreateWindow(
			"STATIC",
			stab[ind+STR_HUP0],
			SS_NOTIFY|SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
			3,
			buttonHi*ind+3,
			buttonWid3+buttonWid*2,
			buttonHi,
			hSid,
			NULL,
			hInst,
			NULL);
	}
}

void setpcs(){

	ini.auxfil=AUXPCS;
	auxmen();
}

void setdst(){

	ini.auxfil=AUXDST;
	auxmen();
}

void fop(){

	untrace();
	if(formpnt||hed.stchs){

		if(savcmp()){

			nuFil();
			nulayr(0);
		}
		else{

			savdisc();
			setMap(OSAV);
		}
	}
	else{

		nuFil();
		nulayr(0);
	}
}

void clpradj(SHRTPNT pnt){

	if(pnt.x<clprcta.left)
		clprcta.left=pnt.x;
	if(pnt.x>clprcta.right)
		clprcta.right=pnt.x;
	if(pnt.y<clprcta.bottom)
		clprcta.bottom=pnt.y;
	if(pnt.y>clprcta.top)
		clprcta.top=pnt.y;
}

void clpadj(){

	double		mid;
	unsigned	ind;

	if(chkMap(GRPSEL)){

		rngadj();
		ind=gpnt0;
		clprcta.left=clprct.right=stchs[ind++].x;
		clprcta.top=clprcta.bottom=stchs[ind].y;
		clpradj(stchs[ind]);
		while(ind<gpnt1)
			clpradj(stchs[ind++]);
		if(stchs[ind].x<clprcta.left)
			clprcta.left=stchs[ind].x;
		if(stchs[ind].x>clprcta.right)
			clprcta.right=stchs[ind].x;
		mid=(clprcta.right-clprcta.left)/2+clprcta.left;
		stchs[gpnt0].y=stchs[gpnt1].y=(clprcta.top-clprcta.bottom)/2+clprcta.bottom;
		if(stchs[gpnt0].x<mid){

			stchs[gpnt0].x=clprcta.left;
			stchs[gpnt1].x=clprcta.right;
		}
		else{

			stchs[gpnt1].x=clprcta.left;
			stchs[gpnt0].x=clprcta.right;
		}
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_GRPMSG,IDS_RNGEND);
}

void shftflt(FLPNT pnt){

	if(pnt.x<=zRct.left||pnt.x>=zRct.right||pnt.y<=zRct.bottom||pnt.y>=zRct.top)
		shft(pnt);
}

void fil2men(){

	if(chku(FIL2OF)){

		CheckMenuItem(hMen,ID_FIL2SEL_ON,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_FIL2SEL_OFF,MF_CHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_FIL2SEL_ON,MF_CHECKED);
		CheckMenuItem(hMen,ID_FIL2SEL_OFF,MF_UNCHECKED);
	}

}

void defpref(){

	unsigned ind;

	umap=0;
	for(ind=0;ind<16;ind++){

		useCol[ind]=defUseCol[ind];
		custCol[ind]=defCustCol[ind];
		bakCust[ind]=defBakCust[ind];
		bakBit[ind]=defBakBit[ind];
	}
	dazdef();
	apcol=15;
	brdwid=BRDWID;
	bfclen=IBFCLEN;
	ini.chspac=CHSDEF;
	ini.chrat=CHRDEF;
	ini.angl=DEFANG;
	rstu(SQRFIL);
	stspace=DEFSPACE*PFGRAN;
	shopnts=SHOPNTS;
	ini.grdsiz=12;
	ini.hup=LARGHUP;
	ini.hupx=LHUPX;
	ini.hupy=LHUPY;
	ini.nudg=NUGINI;
	ini.nudgpix=DEFPIX;
	setu(BLUNT);
	smalsiz=SMALSIZ*PFGRAN;
	snplen=SNPLEN*PFGRAN;
	spirwrap=SPIRWRAP;
	starat=STARAT;
	stchboxs=STCHBOX;
	ini.maxsiz=MAXSIZ*PFGRAN;
	usesiz=USESIZ*PFGRAN;
	minsiz=MINSIZ*PFGRAN;
	ini.clpof=0;
	ini.faz=0;
	bitCol=0xc8dfee;
	if(!ini.xcust)
		ini.xcust=LHUPX;
	if(ini.ycust)
		ini.ycust=LHUPY;
	picspac=IPICSPAC;
	setu(FIL2OF);
	fil2men();
	stchBak=0xa8c4b1;
	zum0.x=ini.hupx;
	zum0.y=ini.hupy;
	ini.wavend=IWAVEND;
	ini.wavpnts=IWAVPNTS;
	ini.wavs=IWAVS;
	ini.wavstrt=IWAVSTRT;
	ini.fthtyp=FDEFTYP;
	ini.fthup=FDEFUP;
	ini.fthdwn=FDEFDWN;
	ini.fthrat=(float)FDEFRAT;
	ini.fthflr=FDEFFLR;
	ini.fthnum=FDEFNUM;
	ini.ulen=DEFULEN;
	ini.uspac=DEFUSPAC;
	ini.frmbpix=DEFBPIX;
	ini.txthi=ITXHI;
	ini.txtwid=ITXWID;
	ini.txtspac=(float)ITXSPAC;
}

void dumrk(double pntx,double pnty){

	if(rstMap(GMRK))
		drwmrk(rsdc);
	mrkpnt.x=pntx;
	mrkpnt.y=pnty;
	setMap(INIT);
	setMap(GMRK);
	drwmrk(rsdc);
	setMap(WASMRK);
}

void gselrng(){

	unsigned ind;

	selrang.strt=selrang.fin=*selist;
	for(ind=1;ind<fselpnt;ind++){

		if(selist[ind]<selrang.strt)
			selrang.strt=selist[ind];
		if(selist[ind]>selrang.fin)
			selrang.fin=selist[ind];
	}
}

double nuang(double ydif,double xdif){

	double tang,rang;

	tang=atan2(ydif,xdif);
	rang=tang-organg;
	if(fabs(rang)>PI){

		if(rang>0)
			rang=2*PI-rang;
		else
			rang+=2*PI;
	}
	return rang;
}

void angdif(double ang){

	if(ang>hiang)
		hiang=ang;
	else{

		if(ang<loang)
			loang=ang;
	}
}

void rotmrk(){

	unsigned	ind,cnt,cod;
	double		tang;
	
	if(chkMap(GMRK)&&(chkMap(FORMSEL)||chkMap(GRPSEL))){

		if(chkMap(FORMSEL)){

			cod=clofind<<FRMSHFT;
			fvars(clofind);
			loang=hiang=0;
			organg=atan2(flt[0].y-mrkpnt.y,flt[0].x-mrkpnt.x);
			for(ind=1;ind<sids;ind++)
				angdif(nuang(flt[ind].y-mrkpnt.y,flt[ind].x-mrkpnt.x));
			for(ind=0;ind<hed.stchs;ind++){

				if((stchs[ind].at&FRMSK)==cod)
					angdif(nuang(stchs[ind].y-mrkpnt.y,stchs[ind].x-mrkpnt.x));
			}
		}
		else{

			rngadj();
			loang=hiang=0;
			organg=atan2(stchs[gpnt0].y-mrkpnt.y,stchs[gpnt0].x-mrkpnt.x);
			for(ind=gpnt0+1;ind<=gpnt1;ind++)
				angdif(nuang(stchs[ind].y-mrkpnt.y,stchs[ind].x-mrkpnt.x));
		}
		tang=hiang-loang;
		cnt=2*PI/tang;
		ini.rotang=2*PI/cnt;
		sprintf(msgbuf,	"Rotation Angle: %.2f\n"
						"Segmets: %d\n",ini.angl*180/PI,cnt);
		shoMsg(msgbuf);
	}
	else
		shoseln(IDS_FSZ,IDS_SETROTM);
}

void segentr(){

	if(!ang)
		ang=PI/180;
	sprintf(msgbuf,stab[STR_ENTROT],2*PI/ang);
	shoMsg(msgbuf);
	setMap(NUMIN);
	numWnd();
}

void rotseg(){

	ang=ini.rotang;
	segentr();
	setMap(ENTRSEG);
}

void pntmrk(){

	if(chkMap(SELBOX)){

		dumrk(stchs[cloInd].x,stchs[cloInd].y);
		goto mrkdun;
	}
	if(chkMap(FRMPSEL)){

		dumrk(formlst[clofind].flt[clofine].x,formlst[clofind].flt[clofine].y);
		goto mrkdun;
	}
	shoseln(IDS_STCH_FRM,IDS_SETMRK);

mrkdun:;
}

void filfrms(){

	unsigned ine;

	if(fselpnt){

		savdo();
		for(ine=0;ine<fselpnt;ine++){

			clofind=selist[ine];
			refilfn();
		}
		setMap(RESTCH);
	}
	else{

		if(chkMap(FORMSEL)){

			savdo();
			refil();
			setMap(RESTCH);
		}
	}
}

void nuslst(unsigned find){

	unsigned ind,ine;

	gselrng();
	ine=0;
	if(find<selrang.strt){

		for(ind=find;ind<selrang.fin;ind++)
			selist[ine++]=ind;
		goto gotsrng;
	}
	if(find>selrang.fin){

		for(ind=selrang.strt;ind<=find;ind++)
			selist[ine++]=ind;
		goto gotsrng;
	}
	for(ind=selrang.strt;ind<=find;ind++)
		selist[ine++]=ind;
gotsrng:;
	fselpnt=ine;
}

void srchk(){

	rstMap(FORMSEL);
	fselpnt=0;
	if(setMap(LENSRCH)){

		if(chkMap(WASGRP)){

			cloInd=gpnt0=opnt0;
			grpInd=gpnt1=opnt1;
		}
		else
			rstMap(GRPSEL);
	}
	else{

		if(chkMap(GRPSEL)){

			setMap(WASGRP);
			rngadj();
			opnt0=gpnt0;
			opnt1=gpnt1;
		}
		else
			rstMap(WASGRP);
	}
	duselrng();
}

unsigned duswap(unsigned dat){
	return bswap_32(dat);
}

void ritcur(){

	ICONINFO			ici;
	HCURSOR				tcur;
	POINT				cpos;
	unsigned			ind,ine;
	unsigned			amsk,binv;
	unsigned			bmsk;
	unsigned			tpix;

	tcur=GetCursor();
	GetIconInfo(tcur,&ici);
	GetCursorPos(&cpos);
	cpos.x-=(stOrg.x+ici.xHotspot);
	cpos.y-=(stOrg.y+ici.yHotspot);
	GetBitmapBits(ici.hbmMask,256,(unsigned char*)&rmap);
	if(tcur==hAr){

		for(ind=0;ind<32;ind++){

			amsk=duswap(rmap[ind]);
			binv=duswap(rmap[ind+32]);
			bmsk=0x80000000;
			for(ine=0;ine<32;ine++){

				if(!(bmsk&amsk)){

					if(binv&bmsk)
						tpix=0xffffff;
					else
						tpix=0;
					SetPixel(rsdc,cpos.x+ine,cpos.y+ind,tpix);
				}
				bmsk>>=1;
			}
		}
	}
	else{

		for(ind=0;ind<32;ind++){

			binv=duswap(rmap[ind+32]);
			bmsk=0x80000000;
			for(ine=0;ine<32;ine++){

				if(bmsk&binv)
					SetPixel(rsdc,cpos.x+ine,cpos.y+ind,GetPixel(rsdc,cpos.x+ine,cpos.y+ind)^0xffffff);
				bmsk>>=1;
			}
		}
	}
}

void delsfrms(unsigned cod){

	unsigned ind,ine,inf;

	if(cod){

		inf=(formpnt>>5)+1;
		for(ine=0;ine<inf;ine++)
			rmap[ine]=0;
		for(ind=0;(unsigned)ind<fselpnt;ind++){

			clofind=selist[ind];
			setr(clofind);
			fvars(clofind);
			f1del();
		}
		finds=(unsigned*)bseq;
		inf=0;ind=0;
		for(ine=0;ine<formpnt;ine++){

			if(!chkr(ine)){

				frmcpy(&formlst[inf],&formlst[ine]);
				finds[ine]=(ine-ind)<<4;
				inf++;
			}
			else
				ind++;
		}
		formpnt=inf;
		inf=0;
		if(chkMap(DELTO)){

			for(ind=0;ind<hed.stchs;ind++){

				if(stchs[ind].at&ALTYPMSK){

					cod=(stchs[ind].at&FRMSK)>>FRMSHFT;
					if(!chkr(cod)){

						stchs[inf].at=stchs[ind].at&=NFRMSK;
						stchs[inf].at|=finds[cod];
						stchs[inf].x=stchs[ind].x;
						stchs[inf++].y=stchs[ind].y;
					}
				}
				else{

					stchs[inf].at=stchs[ind].at;
					stchs[inf].x=stchs[ind].x;
					stchs[inf++].y=stchs[ind].y;
				}
			}
			hed.stchs=inf;
		}
		else{

			for(ind=0;ind<hed.stchs;ind++){
		
				if(!(stchs[ind].at&NOTFRM)){

					cod=(stchs[ind].at&FRMSK)>>FRMSHFT;
					if(chkr(cod))
						stchs[ind].at&=(NFRMSK&NTYPMSK);
				}
			}
		}
		fselpnt=0;
		rstMap(FORMSEL);
		coltab();
		setMap(RESTCH);
	}
}

void nedon(){

	rstu(NEDOF);
	nedmen();
}

void nedof(){

	setu(NEDOF);
	nedmen();
}

void shoknot(){

	rstu(KNOTOF);
	knotmen();
	setMap(RESTCH);
}

void hidknot(){

	setu(KNOTOF);
	knotmen();
	setMap(RESTCH);
}

void pcsbsavon(){

	rstu(BSAVOF);
	bsavmen();
	setMap(RESTCH);
}

void pcsbsavof(){

	setu(BSAVOF);
	bsavmen();
	setMap(RESTCH);
}

void tglhid(){

	if(!toglMap(HIDSTCH))
		rstMap(FRMOF);
	setMap(RESTCH);
}

void respac(){

	if(isclp(clofind)){

		frmpnt->fspac=stspace;
		fsizpar();
	}
}

BOOL chkminus(unsigned cod){

	if(cod==189||cod==109){

		if(prfind==PCLPOF+1)
			return 1;
		if(sidtyp==LFRMSPAC&&isfclp())
			return 1;
		if(sidtyp==LWLKIND)
			return 1;
	}
	return 0;
}

void retrac(){

	unsigned src,dst;

	if(chkMap(GRPSEL)){

		savdo();
		rngadj();
		if(!gpnt0)
			gpnt0++;
		makspac(gpnt1+1,gpnt1-gpnt0);
		src=gpnt1-1;
		dst=gpnt1+1;
		while(src>=gpnt0){

			stchs[dst].at=stchs[src].at;
			stchs[dst].x=stchs[src].x;
			stchs[dst++].y=stchs[src--].y;
		}
		coltab();
		setMap(RESTCH);
	}
	else
		shoseln(IDS_GRPMSG,IDS_RETRAC);
}

void setgrd(COLORREF col){

	unsigned	ind;
	GRDCOD		cods[]={

		ID_GRDHI,HIGRD,
		ID_GRDMED,MEDGRD,
		ID_GRDEF,DEFGRD,
		ID_GRDRED,REDGRD,
		ID_GRDBLU,BLUGRD,
		ID_GRDGRN,GRNGRD,
	};

	for(ind=0;ind<6;ind++){

		if(col==cods[ind].col)
			CheckMenuItem(hMen,cods[ind].id,MF_CHECKED);
		else
			CheckMenuItem(hMen,cods[ind].id,MF_UNCHECKED);
	}
	grdPen=nuPen(grdPen,1,col);
	ini.grdbak=col;
	setMap(RESTCH);
	setMap(DUMEN);
}

void ovrlay(){

	rstMap(IGNORINS);
	insfil();
	rstMap(INSFIL);
	rstMap(FRMOF);
	setMap(INIT);
	coltab();
	setMap(RESTCH);
}

void fil2sel(unsigned stat){

	setu(FIL2OF);
	if(stat)
		rstu(FIL2OF);
	fil2men();
}

void rotauxmen(){

	if(chku(ROTAUX)){

		CheckMenuItem(hMen,ID_ROTAUXON,MF_CHECKED);
		CheckMenuItem(hMen,ID_ROTAUXOFF,MF_UNCHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_ROTAUXON,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_ROTAUXOFF,MF_CHECKED);
	}
}

void rotauxsel(unsigned stat){

	setu(ROTAUX);
	if(!stat)
		rstu(ROTAUX);
	rotauxmen();
	setMap(DUMEN);
}

void frmcurmen(){

	if(chku(FRMX)){

		CheckMenuItem(hMen,ID_FRMX,MF_CHECKED);
		CheckMenuItem(hMen,ID_FRMBOX,MF_UNCHECKED);
	}
	else{

		CheckMenuItem(hMen,ID_FRMX,MF_UNCHECKED);
		CheckMenuItem(hMen,ID_FRMBOX,MF_CHECKED);
	}
}

void frmcursel(unsigned stat){

	setu(FRMX);
	if(!stat)
		rstu(FRMX);
	frmcurmen();
	setMap(DUMEN);
}

void stchsnap(unsigned strt,unsigned fin){
	SHRTPNT *pnt = stchs + strt;

	for (unsigned i = 0; i < fin - strt; i++) {
		pnt->x = __builtin_rintf(pnt->x / ini.grdsiz) * ini.grdsiz;
		pnt->y = __builtin_rintf(pnt->y / ini.grdsiz) * ini.grdsiz;

		pnt++;
	}
}

void frmsnap(FLPNT* strt,unsigned cnt){
	for (unsigned i = 0; i < cnt; i++) {
		strt->x = __builtin_rintf(strt->x / ini.grdsiz) * ini.grdsiz;
		strt->y = __builtin_rintf(strt->y / ini.grdsiz) * ini.grdsiz;

		strt++;
	}
}

void gsnap(){

	unsigned ind;

	if(chkMap(TXTRED))
	{
		txsnap();
		return;
	}
	if(fselpnt){

		savdo();
		for(ind=0;ind<fselpnt;ind++){

			clofind=selist[ind];
			frmsnap(formlst[clofind].flt,formlst[clofind].sids);
			frmout(clofind);
			refil();
		}
		setMap(RESTCH);
	}
	else{
	
		if(chkMap(FORMSEL)){

			savdo();
			frmsnap(formlst[clofind].flt,formlst[clofind].sids);
			frmout(clofind);
			refil();
			setMap(RESTCH);
		}
		else{

			if(chkMap(GRPSEL)){

				savdo();
				rngadj();
				stchsnap(gpnt0,gpnt1+1);
				setMap(RESTCH);
			}
			else
				shoseln(IDS_FGRPF,IDS_SNAP2GRD);
		}
	}
}

#if PESACT

void lodpes(){

	setMap(REDOLD);
	strcpy(filnam,"u:\\mrd\\t.pes");
	nuFil();
}

void savpes(){

	ini.auxfil=AUXPES;
	strcpy(filnam,"u:\\mrd\\t1.thr");
	nunams();
	sav();
}
#endif

void ritlock(HWND hwndlg){

	unsigned ind;
	WIN32_FIND_DATA*	pdat;

	pdat=(WIN32_FIND_DATA*)&bseq;
	SendMessage(GetDlgItem(hwndlg,IDC_LOCKED),LB_RESETCONTENT,0,0);
	SendMessage(GetDlgItem(hwndlg,IDC_UNLOCKED),LB_RESETCONTENT,0,0);
	for(ind=0;ind<xpnt;ind++){

		if(pdat[ind].dwFileAttributes&FILE_ATTRIBUTE_READONLY)
			SendMessage(GetDlgItem(hwndlg,IDC_LOCKED),LB_ADDSTRING,0,(long)pdat[ind].cFileName);
		else
			SendMessage(GetDlgItem(hwndlg,IDC_UNLOCKED),LB_ADDSTRING,0,(long)pdat[ind].cFileName);
	}
}

void rngord(unsigned rng0,unsigned rng1){

	if(rng1>rng0){

		selrng.strt=rng0;
		selrng.fin=rng1;
	}
	else{

		selrng.strt=rng1;
		selrng.fin=rng0;
	}
}

BOOL CALLBACK LockPrc(HWND hwndlg,UINT umsg,WPARAM wparam,LPARAM lparam){

	WIN32_FIND_DATA*	pdat;
	HANDLE				srch;
	TCHAR				snam[MAX_PATH];
	TCHAR				tnam[MAX_PATH];
	unsigned			ind,ine;
	HWND				hlok,hunlok;

	pdat=(WIN32_FIND_DATA*)&bseq;
	switch(umsg){

	case WM_INITDIALOG:

		loksel=unloksel=0xffffffff;
		SendMessage(hwndlg,WM_SETFOCUS,0,0);
		strcpy(snam,defDir);
		strcat(snam,"\\*.thr");
		srch=FindFirstFile(snam,&pdat[0]);
		if(srch==INVALID_HANDLE_VALUE){

			sprintf(msgbuf,"Directory: %s has no .thr files\n",defDir);
			shoMsg(msgbuf);
			EndDialog(hwndlg,wparam); 
			return TRUE;
		}
		xpnt=1;
		while(FindNextFile(srch,&pdat[xpnt++]));
		xpnt--;
		ritlock(hwndlg);
		break;

	case WM_COMMAND:

		switch(LOWORD(wparam)){

		case IDCANCEL:

			EndDialog(hwndlg,wparam); 
			return TRUE;

		case IDC_LOCKAL:

			for(ind=0;ind<xpnt;ind++)
				pdat[ind].dwFileAttributes|=FILE_ATTRIBUTE_READONLY;
			ritlock(hwndlg);
			break;

		case IDC_UNLOCKAL:

			for(ind=0;ind<xpnt;ind++)
				pdat[ind].dwFileAttributes&=0xffffffff^FILE_ATTRIBUTE_READONLY;
			ritlock(hwndlg);
			break;

		case IDC_LOCK:

			ine=0;
			hunlok=GetDlgItem(hwndlg,IDC_UNLOCKED);
			for(ind=0;ind<xpnt;ind++){

				if(!(pdat[ind].dwFileAttributes&FILE_ATTRIBUTE_READONLY)){

					if(SendMessage(hunlok,LB_GETSEL,ine,0))
						pdat[ind].dwFileAttributes|=FILE_ATTRIBUTE_READONLY;
					ine++;
				}
			}
			ritlock(hwndlg);
			break;

		case IDC_UNLOCK:

			ine=0;
			hlok=GetDlgItem(hwndlg,IDC_LOCKED);
			for(ind=0;ind<xpnt;ind++){

				if((pdat[ind].dwFileAttributes&FILE_ATTRIBUTE_READONLY)){

					if(SendMessage(hlok,LB_GETSEL,ine,0))
						pdat[ind].dwFileAttributes&=0xffffffff^FILE_ATTRIBUTE_READONLY;
					ine++;
				}
			}
			ritlock(hwndlg);
			break;

		case IDOK:

			strcpy(snam,defDir);
			strcat(snam,"\\");
			ine=0;
			for(ind=0;ind<xpnt;ind++){

				strcpy(tnam,snam);
				strcat(tnam,pdat[ind].cFileName);
				if(!SetFileAttributes(tnam,pdat[ind].dwFileAttributes))
					ine++;
			}
			if(ine){

				sprintf(msgbuf,"%d files could not be locked or unlocked\n",ine);
				shoMsg(msgbuf);
			}
			EndDialog(hwndlg,wparam); 
			return TRUE;
			break;
		}
	}
	return 0;
}

void lock(){

	DialogBox(hInst,MAKEINTRESOURCE(IDD_DLOCK),hWnd,(DLGPROC)LockPrc);
}

unsigned colsum(COLORREF col){

	unsigned colsum;
	unsigned ind;

	trcols(col);
	colsum=0;
	for(ind=0;ind<3;ind++){

		if(chkMap(trbits[ind]))
			colsum+=pxcols[ind];
	}
	return colsum;
}

unsigned icolsum(COLORREF col){

	unsigned colsum;
	unsigned ind;

	trcols(col);
	colsum=0;
	for(ind=0;ind<3;ind++){

		if(chkMap(trbits[ind]))
			colsum+=255-pxcols[ind];
	}
	return colsum;
}

COLORREF dwnshft(COLORREF col){
	return (col >> 1) & 0x3f3f3f;
}

void setrac(unsigned bpnt){
	bts((unsigned *) oseq, bpnt);
}

BOOL getrac(unsigned bpnt){
	return bt((unsigned *)oseq, bpnt) ? 0 : 1;
}

void shownd(HWND hwnd){

	ShowWindow(hwnd,SW_SHOW);
}

void hidwnd(HWND hwnd){

	ShowWindow(hwnd,SW_HIDE);
}

void untrace(){

	unsigned	ind;

	if(rstMap(WASTRAC)){

		DeleteObject(tracebit);
		ReleaseDC(hWnd,tracedc);
		rstMap(WASEDG);
		for(ind=0;ind<16;ind++){

			shownd(hDef[ind]);
			shownd(hCol[ind]);
			shownd(hSiz[ind]);
		}
		for(ind=0;ind<3;ind++){

			hidwnd(hctrc[ind]);
			hidwnd(hstrc[ind]);
			hidwnd(htrup[ind]);
			hidwnd(htrdwn[ind]);
		}
		for(ind=0;ind<9;ind++)
			shownd(hbuts[ind]);
		hidwnd(hstep);
	}
	else{

		if(chkMap(TRCUP))
			dref=0xffffff;
		else
			uref=0;
	}
}

void trcstpnum(){
	
	sprintf(msgbuf,"len: %.2f",ini.trlen/PFGRAN);
	SetWindowText(hstep,msgbuf);
}

void trcratnum(){

	sprintf(msgbuf,"pnts: %.2f",-log10(ini.trcrat-1));
	butxt(HLIN,msgbuf);
}

void clrhbut(unsigned strt)
{
	unsigned ind;

	for(ind=strt;ind<9;ind++)
		SetWindowText(hbuts[ind],"");
}

void tracwnd(){

	unsigned ind;

	for(ind=0;ind<16;ind++){

		hidwnd(hDef[ind]);
		hidwnd(hCol[ind]);
		hidwnd(hSiz[ind]);
	}
	for(ind=0;ind<3;ind++){

		shownd(hctrc[ind]);
		shownd(hstrc[ind]);
		shownd(htrup[ind]);
		shownd(htrdwn[ind]);
	}
	hidwnd(hbuts[HBOXSEL]);
	hidwnd(hbuts[HUPTO]);
	shownd(hstep);
	trcstpnum();
	trcratnum();
	clrhbut(4);
}

void trcols(COLORREF col){
	pxcols[0] = col & 0xff;
	pxcols[1] = (col & 0xff00) >> 8;
	pxcols[2] = (col & 0xff0000) >> 16;
}

BOOL trcin(COLORREF col){

	if(col){

		trcols(col);
		if(chkMap(TRCRED)){

			if(pxcols[0]>hicols[0])
				return 0;
			if(pxcols[0]<locols[0])
				return 0;
		}
		if(chkMap(TRCGRN)){

			if(pxcols[1]>hicols[1])
				return 0;
			if(pxcols[1]<locols[1])
				return 0;
		}
		if(chkMap(TRCBLU)){

			if(pxcols[2]>hicols[2])
				return 0;
			if(pxcols[2]<locols[2])
				return 0;
		}
		return 1;
	}
	return 0;
}

void getrmap(){

	BITMAPINFO			binf;
	BITMAPINFOHEADER	binfh;
	unsigned			ind;

	memset((BITMAPINFOHEADER*)&binfh,0,sizeof(BITMAPINFOHEADER));
	binfh.biSize=sizeof(BITMAPINFOHEADER);
	binfh.biWidth=bwid;
	binfh.biHeight=bhi;
	binfh.biPlanes=1;
	binfh.biBitCount=32;
	binfh.biCompression=BI_RGB;
	binf.bmiHeader=binfh;
	tracebit=CreateDIBSection(bitdc,&binf,DIB_RGB_COLORS,(void**)&tracbits,0,0);	
	tracedc=CreateCompatibleDC(rsdc);
	SelectObject(tracedc,tracebit);
	BitBlt(tracedc,0,0,bwid,bhi,bitdc,0,0,SRCCOPY);
	setMap(WASTRAC);
	tracmap=(unsigned*)oseq;
	trmapsiz=((bwid*bhi)>>5)+1;
	for(ind=0;ind<trmapsiz;ind++)
		tracmap[ind]=0;
	StretchBlt(sdc,bdrct.left,bdrct.top,bdrct.right-bdrct.left,bdrct.bottom-bdrct.top,
	   bitdc,bsrct.left,bsrct.top,bsrct.right-bsrct.left,bsrct.bottom-bsrct.top,SRCCOPY);
}

void trace(){

	unsigned			ind;

#if TRCMTH==0

	unsigned			usum,psum,dsum;
#endif

	if(*bnam){

		untrace();
		tracwnd();
		getrmap();
		if(px2stch()&&!rstMap(WASTRCOL)){

			if(chkMap(LANDSCAP))
				sPnt.y-=(zum0.y-zumend.y);
			bitpnt.x=bsrat.x*sPnt.x;
			bitpnt.y=bsrat.y*sPnt.y-1;
			ind=tracbits[bitpnt.y*bwid+bitpnt.x]^0xffffff;
			if(chkMap(TRCUP)){

				uref=ind;
				dref=0xffffff;
			}
			else{

				dref=ind;
				uref=0;
			}
			setMap(TRCRED);
			setMap(TRCGRN);
			setMap(TRCBLU);
		}
		sref=0xffffff;
		if(!chkMap(TRCRED))
			sref&=REDMSK;
		if(!chkMap(TRCGRN))
			sref&=GRNMSK;
		if(!chkMap(TRCBLU))
			sref&=BLUMSK;
		if(sref!=0xffffff){

			for(ind=0;ind<bwid*bhi;ind++)
				tracbits[ind]&=sref;
		}

#if TRCMTH==0

		usum=icolsum(uref);
		dsum=icolsum(dref);
		for(ind=0;ind<bwid*bhi;ind++){

			psum=colsum(tracbits[ind]);
			if(usum>psum&&dsum<psum)
				setrac(ind);
			else
				tracbits[ind]=0;
		}
#endif

#if TRCMTH==1
		curef=uref^0xffffff;
		cdref=dref^0xffffff;
		trcols(curef);
		for(ind=0;ind<3;ind++)
			hicols[ind]=pxcols[ind];
		trcols(cdref);
		for(ind=0;ind<3;ind++)
			locols[ind]=pxcols[ind];
		for(ind=0;ind<bwid*bhi;ind++){

			if(trcin(tracbits[ind]))
				setrac(ind);
			else
				tracbits[ind]=0;
		}
#endif
		setMap(TRSET);
		setMap(RESTCH);
	}
	else
		tabmsg(IDS_MAPLOD);
}

void setedg(unsigned bpnt){
	bts(edgmap, bpnt);
}

BOOL chkedg(unsigned bpnt){
	return bt(edgmap, bpnt) ? 1 : 0;
}

void tracedg(){

	unsigned	ind,ine,flg;
	long		bpnt;
	
	if(!chkMap(WASTRAC))
		trace();
	edgmap=(unsigned*)&oseq[trmapsiz];
	for(ind=0;ind<trmapsiz;ind++)
		edgmap[ind]=0;
	bpnt=0;
	for(ind=0;ind<bhi;ind++){

		flg=0;
		for(ine=0;ine<bwid;ine++){

			if(getrac(bpnt)){

				if(!flg){

					setedg(bpnt);
					flg=1;
				}
			}
			else{

				if(flg){

					setedg(bpnt-1);
					flg=0;
				}
			}
			bpnt++;
		}
		if(flg)
			setedg(bpnt-1);
	}
	for(ind=0;ind<bwid;ind++){

		bpnt=ind;
		flg=0;
		for(ine=0;ine<bhi;ine++){

			if(getrac(bpnt)){

				if(!flg){

					setedg(bpnt);
					flg=1;
				}
			}
			else{

				if(flg){

					setedg(bpnt-bwid);
					flg=0;
				}
			}
			bpnt+=bwid;
		}
		if(flg)
			setedg(bpnt-bwid);
	}
	for(ind=0;ind<bwid*bhi;ind++){

		if(chkedg(ind))
			tracbits[ind]=0xffffff;
		else
			tracbits[ind]=0;
	}
	setMap(RESTCH);
	setMap(WASEDG);
}

BOOL trcbit(){
	unsigned bpnt;

	bpnt=tracpnt.y*bwid+tracpnt.x;
	switch(trcdir){

	case TRCR:
		
		bpnt+=(1-bwid);
		if(tracpnt.x==(int)bwid-1)
			trcdir=TRCU;
		else{

			if(chkedg(bpnt)){

				tracpnt.x++;
				tracpnt.y--;
				trcdir=TRCD;
			}
			else{

				bpnt+=bwid;
				if(chkedg(bpnt))
					tracpnt.x++;
				else
					trcdir=TRCU;
			}
		}
		break;

	case TRCD:

		bpnt-=(bwid+1);
		if(!tracpnt.y)
			trcdir=TRCR;
		else{

			if(chkedg(bpnt)){

				tracpnt.x--;
				tracpnt.y--;
				trcdir=TRCL;
			}
			else{

				bpnt++;
				if(chkedg(bpnt))
					tracpnt.y--;
				else
					trcdir=TRCR;
			}
		}
		break;
	
	case TRCL:
		
		bpnt+=(bwid-1);
		if(!tracpnt.x)
			trcdir=TRCD;
		else{

			if(chkedg(bpnt)){

				tracpnt.x--;
				tracpnt.y++;
				trcdir=TRCU;
			}
			else{

				bpnt-=bwid;
				if(chkedg(bpnt))
					tracpnt.x--;
				else
					trcdir=TRCD;
			}
		}
		break;

	case TRCU:
		
		bpnt+=(1+bwid);
		if(tracpnt.y==(int)bhi-1)
			trcdir=TRCL;
		else{

			if(chkedg(bpnt)){

				tracpnt.x++;
				tracpnt.y++;
				trcdir=TRCR;
			}
			else{

				bpnt--;
				if(chkedg(bpnt))
					tracpnt.y++;
				else
					trcdir=TRCL;
			}
		}
		break;
	}
	if(trclin[xpnt-1].x!=tracpnt.x||trclin[xpnt-1].y!=tracpnt.y){
	
		trclin[xpnt].x=tracpnt.x;
		trclin[xpnt++].y=tracpnt.y;
		if(xpnt>=500000)
			return 0;
	}
	if(trcdir==inidir&&tracpnt.x==trclin[0].x&&tracpnt.y==trclin[0].y)
		return 0;
	else
		return 1;
}

void dutdif(TRCPNT* pnt){

	trdif0.x=pnt[1].x-pnt[0].x;
	trdif0.y=pnt[1].x-pnt[0].y;
}

void dutrac(){

	unsigned	flg;
	RECT		fndrct;
	long		bpnt,blim,bakpnt;
	long		dis,mdis;
	unsigned	ind;
	double		tlen;
	double		tlens;
	float		ratof;
	unsigned	ine;
	
	if(px2stch()){

		if(!chkMap(WASEDG)){

			tracedg();
			return;
		}
		savdo();
		if(chkMap(LANDSCAP))
			sPnt.y-=(zum0.y-zumend.y);
		tracpnt.x=bsrat.x*sPnt.x;
		tracpnt.y=bsrat.y*sPnt.y;
		if(tracpnt.x>(long)bwid)
			tracpnt.x=bwid;
		if(tracpnt.y>(long)bhi)
			tracpnt.y=bhi;
		bakpnt=bpnt=tracpnt.y*bwid+tracpnt.x;
		if(!chkedg(bpnt)){

			flg=20;
			bpnt=bakpnt;
			blim=(tracpnt.y+1)*bwid;
			while(bpnt<blim&&!chkedg(bpnt))
				bpnt++;
			if(bpnt<blim)
				fndrct.right=bpnt-tracpnt.y*bwid;
			else
				fndrct.right=bwid;
			bpnt=bakpnt;
			blim=tracpnt.y*bwid;
			while(bpnt>blim&&!chkedg(bpnt))
				bpnt--;
			if(bpnt==blim)
				fndrct.left=0;
			else
				fndrct.left=bpnt-blim;
			bpnt=bakpnt;
			while(bpnt>0&&!chkedg(bpnt))
				bpnt-=bwid;
			if(bpnt>0)
				fndrct.bottom=bpnt/bwid;
			else
				fndrct.bottom=0;
			bpnt=bakpnt;
			blim=bwid*bhi;
			while(bpnt<blim&&!chkedg(bpnt))
				bpnt+=bwid;
			if(bpnt<blim)
				fndrct.top=bpnt/bwid;
			else
				fndrct.top=bhi;
			flg=0;
			mdis=0x7fffffff;
			if(fndrct.left){

				mdis=tracpnt.x-fndrct.left;
				flg=TRCL;
			}
			if(fndrct.right<(long)bwid){

				dis=fndrct.right-tracpnt.x;
				if(dis<mdis){

					mdis=dis;
					flg=TRCR;
				}
			}
			if(fndrct.bottom){

				dis=tracpnt.y-fndrct.bottom;
				if(dis<mdis){

					mdis=dis;
					flg=TRCD;
				}
			}
			if(fndrct.top<(long)bhi){

				dis=fndrct.top-tracpnt.y;
				if(dis<mdis){

					mdis=dis;
					flg=TRCU;
				}
			}
			switch(flg){

			case TRCU:

				tracpnt.y=fndrct.top;
				trcdir=TRCR;
				break;

			case TRCR:

				tracpnt.x=fndrct.right;
				trcdir=TRCD;
				break;

			case TRCD:

				tracpnt.y=fndrct.bottom;
				trcdir=TRCL;
				break;

			case TRCL:

				tracpnt.x=fndrct.left;
				trcdir=TRCU;
				break;

			default:
				return;
			}
		}
		inidir=trcdir;
		bpnt=tracpnt.y*bwid+tracpnt.x;
		tracmov[2]=tracmov[3]=-(long)bwid;
		tracmov[6]=tracmov[7]=bwid;
		xpnt=1;
		trclin=(TRCPNT*)bseq;
		trclin[0].x=tracpnt.x;
		trclin[0].y=tracpnt.y;
		while(trcbit());
		if(xpnt>=500000){

			tabmsg(IDS_FRM2L);
			return;
		}
		diflin=&trclin[xpnt];
		diflin[0].x=trclin[0].x;
		diflin[0].y=trclin[0].y;
		dutdif(&trclin[0]);
		opnt=1;
		for(ind=1;ind<xpnt;ind++){

			trdif1.x=trdif0.x;
			trdif1.y=trdif0.y;
			dutdif(&trclin[ind]);
			if(trdif1.x!=trdif0.x||trdif1.y!=trdif0.y){

				diflin[opnt].x=trclin[ind].x;
				diflin[opnt++].y=trclin[ind].y;
			}
		}
		trclin[0].x=diflin[0].x;
		trclin[0].y=diflin[0].y;
		ine=0;
		xpnt=0;
		for(ind=1;ind<opnt;ind++){

			tlen=hypot(diflin[ind].x-diflin[ine].x,diflin[ind].y-diflin[ine].y);
			if(tlen>ini.trlen){

				trclin[xpnt].x=diflin[ine].x;
				trclin[xpnt].y=diflin[ine].y;
				ine=ind;
				xpnt++;
			}
		}
		for(ind=ine+1;ind<opnt;ind++){

			trclin[xpnt].x=diflin[ind].x;
			trclin[xpnt].y=diflin[ind].y;
			xpnt++;
		}
		frmpnt=&formlst[formpnt];
		frmclr(frmpnt);
		flt=&flts[fltad];
		flt[0].x=trclin[0].x*birat.x;
		flt[0].y=trclin[0].y*birat.y;
		ine=0;
		opnt=0;
		tlens=0;
		if(chkMap(LANDSCAP))
			ratof=zum0.y-zumend.y;
		else
			ratof=0;
		for(ind=1;ind<xpnt;ind++){

			tlens+=hypot(trclin[ind].x-trclin[ind-1].x,trclin[ind].y-trclin[ind-1].y);
			tlen=hypot(trclin[ind].x-trclin[ine].x,trclin[ind].y-trclin[ine].y);
			if(tlens>tlen*ini.trcrat){

				flt[opnt].x=trclin[ind-1].x*birat.x;
				flt[opnt].y=trclin[ind-1].y*birat.y+ratof;
				opnt++;
				ind--;
				ine=ind;
				tlens=0;
			}
		}
		if(fltad+opnt>MAXFLT){

			tabmsg(IDS_FRMOVR);
			return;
		}
		frmpnt->flt=adflt(opnt);
		frmpnt->sids=opnt;
		frmpnt->typ=POLI;
		frmpnt->at=actl<<1;
		frmout(formpnt);
		formlst[formpnt].stpt=0;
		formpnt++;
		setMap(RESTCH);
		setMap(FRMOF);
		tglfrm();
	}
}

unsigned ducolm(){

	if(trcmpnt.x<(int)buttonWid)
		return 0;
	if(trcmpnt.x<(int)buttonWid<<1)
		return 1;
	else
		return 2;
}

void chkref(){
	union {
		COLORREF cr;
		struct {
			unsigned char g;
			unsigned char r;
			unsigned char b;
			unsigned char x;
		} components;
	} u, d;

	u.cr = uref;
	d.cr = dref;

	unsigned char tmp;

	if (u.components.r < d.components.r) {
		tmp = u.components.r;

		u.components.r = d.components.r;
		d.components.r = tmp;
	}

	if (u.components.g < d.components.g) {
		tmp = u.components.g;

		u.components.g = d.components.g;
		d.components.g = tmp;
	}

	if (u.components.b < d.components.b) {
		tmp = u.components.b;

		u.components.b = d.components.b;
		d.components.b = tmp;
	}

	uref = u.cr;
	dref = d.cr;
}

void trnumwnd0(int pos){

	htrnum=CreateWindow(
		"STATIC",
		0,
		SS_OWNERDRAW|WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3,
		pos,
		buttonWid,
		buttonHi,
		hWnd,
		NULL,
		hInst,
		NULL);
}

void trnumwnd1(int pos){

	hgNum=CreateWindow(
		"STATIC",
		0,
		WS_CHILD|WS_VISIBLE|WS_BORDER,
		buttonWid3,
		pos,
		buttonWid3,
		buttonHi,
		hWnd,
		NULL,
		hInst,
		NULL);
}

void tracpar(){

	unsigned	pos;
	double		rat;
	COLORREF	tcol;
	COLORREF	tpos;

	if(chkMap(TRNIN0))
		dutrnum0(atoi(trinbuf));
	if(chkMap(TRNIN1))
		dutrnum1();
	trcmpnt.x=msg.pt.x-morg.x;
	trcmpnt.y=msg.pt.y-morg.y;
	if(trcmpnt.x>(int)buttonWid3)
		dutrac();
	else{

		colm=ducolm();
		if(trcmpnt.y<(int)buttonHi*15){

			if(GetKeyState(VK_SHIFT)&0X8000){

				uref&=trmsks[colm];
				dref|=trgb[2-colm];
				goto tracpar1;
			}
			rat=(float)trcmpnt.y/(buttonHi*15);
			pos=rat*255;
			tcol=uref&trgb[2-colm];
			tpos=pos<<trshft[colm];
			if(tpos<tcol){

				uref&=trmsks[colm];
				uref|=tpos;
				goto tracpar1;		
			}
			tcol=dref&trgb[2-colm];
			if(tpos>tcol){

				dref&=trmsks[colm];
				dref|=tpos;
				goto tracpar1;		
			}
			if(msg.message==WM_LBUTTONDOWN){

				uref&=trmsks[colm];
				uref|=pos<<trshft[colm];
			}
			else{

				dref&=trmsks[colm];
				dref|=pos<<trshft[colm];
			}
tracpar1:
			redraw(hctrc[colm]);
			trace();
		}
		else{

			pos=floor(trcmpnt.y/buttonHi);
			if(pos<16){

				toglMap(trbits[colm]);
				redraw(hstrc[colm]);
				trace();
			}
			else{

				if(pos<18){

					setMap(NUMIN);
					setMap(TRNIN0);
					msgpnt=0;
					*trinbuf=0;
					if(pos<17){

						trnumwnd0(buttonHi*16);
						setMap(TRNUP);
					}
					else{

						trnumwnd0(buttonHi*17);
						rstMap(TRNUP);
					}
				}
				else{

					if(pos<20){

						setMap(NUMIN);
						setMap(TRNIN1);
						msgpnt=0;
						*trinbuf=0;
						if(pos<19){

							trnumwnd1(buttonHi*18);
							setMap(TRNUP);
						}
						else{

							trnumwnd1(buttonHi*19);
							rstMap(TRNUP);
						}
					}
					else{

						switch(pos){

						case 20:

							trdif();
							break;

						case 21:

							hidbit();
							break;

						case 22:

							blak();
							break;

						case 23:

							trcsel();
							break;

						case 24:

							tracedg();
							break;
						}
					}
				}
			}
		}
	}
}

static inline void difsub(unsigned *bpnt, unsigned shft, unsigned *&dst) {
	*(dst++) = (*bpnt >> shft) & 0xff; 
}

void difbits(unsigned shft,unsigned* bpnt){
	unsigned *dst = tradj;

	difsub(bpnt, shft, dst);

	bpnt -= bwid;
	difsub(bpnt, shft, dst);

	bpnt -= 1;
	difsub(bpnt, shft, dst);

	bpnt += 2;
	difsub(bpnt, shft, dst);

	bpnt += bwid;
	difsub(bpnt, shft, dst);

	bpnt -= 2;
	difsub(bpnt, shft, dst);

	bpnt += bwid;
	difsub(bpnt, shft, dst);

	bpnt += 1;
	difsub(bpnt, shft, dst);

	bpnt += 1;
	difsub(bpnt, shft, dst);
}

void blanklin(unsigned bind){

	unsigned ind;

	for(ind=bind;ind<bind+bwid;ind++)
		difmap[ind]=0;
}

unsigned trsum(){

	unsigned rsum,ind;

	rsum=0;
	for(ind=1;ind<9;ind++)
		rsum+=abs(tradj[ind]-tradj[0]);
	return rsum;
}

void trdif(){

	unsigned	ind,ine,inf,bpnt,rsum,rmax,rmin;
	double		rat;

	if(!*bnam){

		tabmsg(IDS_MAPLOD);
		return;
	}
	rstMap(TRSET);
	rstMap(HIDMAP);
	untrace();
	difmap=(unsigned*)bseq;
	rmax=0;
	rmin=0xffffffff;
	if(!chkMap(WASTRAC))
		getrmap();
	ind=0;
	for(ind=0;ind<3;ind++){

		blanklin(0);
		for(ine=1;ine<(unsigned)bhi-1;ine++){

			bpnt=ine*bwid;
			difmap[bpnt++]=0;
			for(inf=1;inf<bwid-1;inf++){

				difbits(trshft[ind],&tracbits[bpnt]);
				rsum=difmap[bpnt]=trsum();
				bpnt++;
				if(rsum>rmax)
					rmax=rsum;
				if(rsum<rmin)
					rmin=rsum;
			}
			difmap[bpnt++]=0;
		}
		blanklin(bpnt);
		rat=(double)255/(rmax-rmin);
		for(ine=0;ine<bwid*bhi;ine++){

			tracbits[ine]&=trmsks[ind];
			if(difmap[ine]){

				inf=(difmap[ine]-rmin)*rat;
				tracbits[ine]|=inf<<trshft[ind];
			}
		}
	}
	BitBlt(bitdc,0,0,bwid,bhi,tracedc,0,0,SRCCOPY);
	setMap(WASDIF);
	setMap(RESTCH);
	tracwnd();
}

void delstch(){

	savdo();
	hed.stchs=0;
	clpad=0;
	txad=0;
	rstAll();
	clrfills();
	colCnt=0;
	butxt(HNUM,"");
	butxt(HTOT,"");
	setMap(RESTCH);
}

void chkbit(){

	if(*bnam&&(chkMap(WASDIF)||chkMap(WASDSEL)||chkMap(WASBLAK))){

		setMap(WASESC);
		bfil();
	}
}

void trcnum(unsigned shft,COLORREF col,unsigned ind){

	unsigned len;
	unsigned nwid;

	col>>=shft;
	col&=0xff;
	itoa(col,trbuf,10);
	len=strlen(trbuf);
	nwid=numwid*(3-len)+1;
	SetBkColor(ds->hDC,trgb[ind]);	
	TextOut(ds->hDC,nwid,1,trbuf,strlen(trbuf));
}

void upnum(unsigned ind){

	trcnum(trshft[ind],curef,ind);
}

void dwnum(unsigned ind){

	trcnum(trshft[ind],cdref,ind);
}

void ritrcol(COLORREF* tref,unsigned num){

	*tref&=trmsks[colm];
	num&=0xff;
	*tref|=(num<<trshft[colm]);
}

void dutrnum0(unsigned num){

	rstMap(NUMIN);
	rstMap(TRNIN0);
	if(chkMap(TRNUP)){

		ritrcol(&curef,num);
		uref=curef^0xffffff;
		redraw(htrup[colm]);
	}
	else{

		ritrcol(&cdref,num);
		dref=cdref^0xffffff;
		redraw(htrdwn[colm]);
	}
	redraw(hctrc[colm]);
	DestroyWindow(htrnum);
	setMap(WASTRCOL);
	trace();
}

void dutrnum1(){

	double	tdub;

	DestroyWindow(hgNum);
	rstMap(NUMIN);
	rstMap(TRNIN1);
	tdub=atof(msgbuf);
	sprintf(msgbuf,"%.2f",tdub);
	if(tdub>9)
		tdub=9;
	if(chkMap(TRNUP)){

		ini.trlen=tdub*PFGRAN;
		trcstpnum();
	}
	else{

		ini.trcrat=1+pow(0.1,tdub);
		trcratnum();
	}
}

void trcsel(){

	unsigned ind,max,xind;

	if(*bnam){

		setMap(WASTRCOL);
		setMap(TRCRED);
		setMap(TRCBLU);
		setMap(TRCGRN);
		dref=0xffffff;
		uref=0;
		trace();
		rstMap(HIDMAP);
		rstMap(TRSET);
		for(ind=0;ind<bwid*bhi;ind++){

			trcols(tracbits[ind]);
			max=pxcols[0];
			xind=2;
			if(pxcols[1]>max){
			
				max=pxcols[1];
				xind=1;
			}
			if(pxcols[2]>max)
				xind=0;
			tracbits[ind]&=trgb[xind];
		}
		BitBlt(bitdc,0,0,bwid,bhi,tracedc,0,0,SRCCOPY);
		setMap(WASDSEL);
		setMap(RESTCH);
		tracwnd();
	}
	else
		tabmsg(IDS_MAPLOD);
}

void trinit(){

	unsigned	ind,ine;
	unsigned	hst[3][256];
	unsigned*	phst;
	unsigned	hi[3];
	unsigned	col[3];
	COLORREF	tcol;
	
	if(*bnam){

		if(!chkMap(TRSET)){

			setMap(TRCRED);
			setMap(TRCGRN);
			setMap(TRCBLU);
			if(!chkMap(WASTRAC))
				getrmap();
			if(chkMap(MONOMAP)){

				tcol=tracbits[0];
				for(ind=0;ind<bwid*bhi;ind++){

					if(tracbits[ind]!=tcol)
						break;
				}
				if(ind<bwid*bhi){

					trcols(tracbits[ind]);
					hicols[0]=pxcols[0];
					hicols[1]=pxcols[1];
					hicols[2]=pxcols[2];
					trcols(tcol);
					for(ind=0;ind<3;ind++){

						if(pxcols[ind]>hicols[ind]){

							ine=pxcols[ind];
							pxcols[ind]=hicols[ind];
							hicols[ind]=ine;
						}
						col[ind]=((hicols[ind]-pxcols[ind])>>1)+pxcols[ind];
					}
				}
			}
			else{

				phst=(unsigned*)hst;
				for(ind=0;ind<768;ind++)
					phst[ind]=0;
				for(ind=0;ind<bwid*bhi;ind++){

					trcols(tracbits[ind]);
					for(ine=0;ine<3;ine++)
						hst[ine][pxcols[ine]]++;
				}
				for(ind=0;ind<3;ind++)
					hi[ind]=0;
				for(ind=0;ind<256;ind++){
				
					for(ine=0;ine<3;ine++){
					
						if(hst[ine][ind]>hi[ine]){

							hi[ine]=hst[ine][ind];
							col[ine]=ind;
						}
					}
				}
			}
			cdref=0;
			for(ind=0;ind<3;ind++){

				if(col[ind])
					col[ind]--;
				cdref|=col[ind]<<trshft[ind];
			}
			dref=cdref^0xffffff;
			curef=0xffffff;
			uref=0;
		}
		setMap(WASTRCOL);
		trace();
	}
	else
		tabmsg(IDS_MAPLOD);
}

void stch2bit(double px, double py){

	if(chkMap(LANDSCAP))
		py-=(zum0.y-zumend.y);
	bitpnt.x=bsrat.x*px;
	bitpnt.y=(bhi-bsrat.y*py);
}

void pxlin(unsigned strt,unsigned fin){

	POINT		lin[2];

	stch2bit(flt[strt].x,flt[strt].y);
	lin[0].x=bitpnt.x;
	lin[0].y=bitpnt.y;
	stch2bit(flt[fin].x,flt[fin].y);
	lin[1].x=bitpnt.x;
	lin[1].y=bitpnt.y;
	Polyline(bitdc,lin,2);
	Polyline(tracedc,lin,2);
}

void bfrm(){

	unsigned ind;

	if(sids){

		for(ind=0;ind<(unsigned)sids-1;ind++)
			pxlin(ind,ind+1);
		if(frmpnt->typ!=LIN)
			pxlin(ind,0);
	}
}

void blak(){

	unsigned ind;

	if(!*bnam){

		tabmsg(IDS_MAPLOD);
		return;
	}
	tracwnd();
	if(formpnt){

		blakpen=CreatePen(PS_SOLID,1,0);
		SelectObject(bitdc,blakpen);
		SelectObject(tracedc,blakpen);
		if(!chkMap(WASTRAC))
			getrmap();
		for(ind=0;ind<formpnt;ind++){

			fvars(ind);
			bfrm();
		}
		DeleteObject(blakpen);
		setMap(WASBLAK);
		setMap(RESTCH);
	}
	else
		tabmsg(IDS_FRMNO);
}

void delmap(){

	*bnam=0;
	setMap(RESTCH);
}

void closfn(){

	deltot();
	sprintf(msgbuf,stab[STR_THRED],ini.desnam);
	knotcnt=0;
	*filnam=0;
	*bnam=0;
	deldu();
	clrhbut(3);
	SetWindowText(hWnd,msgbuf);
}

void filclos(){

	if(savcmp())
		closfn();
	else{

		setMap(FCLOS);
		savdisc();
	}
}

void frmpos(float dx,float dy){

	unsigned ine;

	for(ine=0;ine<frmpnt->sids;ine++){

		frmpnt->flt[ine].x+=dx;
		frmpnt->flt[ine].y+=dy;
	}
	frmpnt->rct.bottom+=dy;
	frmpnt->rct.top+=dy;
	frmpnt->rct.left+=dx;
	frmpnt->rct.right+=dx;
}

void nudgfn(float dx,float dy){

	unsigned	ind,rcnt;
	POINT		pix;

	if(chkMap(BIGBOX)||fselpnt||chkMap(FORMSEL)||chkMap(GRPSEL)||chkMap(SELBOX))
		savdo();
	if(chkMap(BIGBOX)){

		for(ind=0;ind<formpnt;ind++){

			frmpnt=&formlst[ind];
			frmpos(dx,dy);
		}
		for(ind=0;ind<hed.stchs;ind++){

			stchs[ind].x+=dx;
			stchs[ind].y+=dy;
		}
		rctal.bottom+=dy;
		rctal.top+=dy;
		rctal.left+=dx;
		rctal.right+=dx;
		stchrct2px(rctal,&bigrct);
		setMap(RESTCH);
		return;
	}
	if(fselpnt){

		rcnt=(formpnt>>5)+1;
		clRmap(rcnt);
		for(ind=0;ind<fselpnt;ind++)
			setr(selist[ind]);
		for(ind=0;ind<hed.stchs;ind++){

			if(chkr((stchs[ind].at&FRMSK)>>FRMSHFT)){

				stchs[ind].x+=dx;
				stchs[ind].y+=dy;
			}
		}
		for(ind=0;ind<fselpnt;ind++){

			frmpnt=&formlst[selist[ind]];
			frmpos(dx,dy);
		}
		setMap(RESTCH);
		return;
	}
	if(chkMap(FORMSEL)){

		frmpnt=&formlst[clofind];
		frmpos(dx,dy);
		if(frmpnt->ftyp||frmpnt->etyp){

			for(ind=0;ind<hed.stchs;ind++){

				if((stchs[ind].at&FRMSK)>>FRMSHFT==clofind){

					stchs[ind].x+=dx;
					stchs[ind].y+=dy;
				}
			}
		}
		setMap(RESTCH);
		return;
	}
	if(chkMap(GRPSEL)){

		rngadj();
		for(ind=gpnt0;ind<=gpnt1;ind++){

			stchs[ind].x+=dx;
			stchs[ind].y+=dy;
		}
		grpAdj();
		setMap(RESTCH);
		return;
	}
	if(chkMap(SELBOX)){

		stchs[cloInd].x+=dx;
		stchs[cloInd].y+=dy;
		setMap(RESTCH);
		return;
	}
	pix.x=pix.y=0;
	if(dx){

		if(dx>0)
			pix.x=ini.nudgpix;
		else
			pix.x=-ini.nudgpix;
	}
	if(dy){

		if(dy>0)
			pix.y=-ini.nudgpix;
		else
			pix.y=+ini.nudgpix;
	}
	mouse_event(MOUSEEVENTF_MOVE,pix.x,pix.y,0,0);
}

void pixmsg(unsigned cod,unsigned pix){

	sprintf(msgbuf,stab[cod],pix);
	shoMsg(msgbuf);
}

void getnpix(){

	pixmsg(STR_NUDG,ini.nudgpix);
	setMap(NUMIN);
	setMap(PIXIN);
	numWnd();
}

void getstpix(){

	pixmsg(STR_STCHP,ini.stchpix);
	setMap(NUMIN);
	setMap(STPXIN);
	numWnd();
}

void getfrmpix(){

	pixmsg(STR_FRMP,ini.frmpix);
	setMap(NUMIN);
	setMap(FRMPXIN);
	numWnd();
}

void getfrmbox(){

	pixmsg(STR_FRMBOX,ini.frmbpix);
	setMap(NUMIN);
	setMap(FRMBOXIN);
	numWnd();
}

void bakmrk(){

	FLPNT	tpnt;

	if(chkMap(WASMRK)){

		if(mrkpnt.x>ini.hupx)
			mrkpnt.x=ini.hupy/2;
		if(mrkpnt.y>ini.hupy)
			mrkpnt.y=ini.hupy/2;
		dumrk(mrkpnt.x,mrkpnt.y);
		tpnt.x=mrkpnt.x;
		tpnt.y=mrkpnt.y;
		shft(tpnt);
		setMap(RESTCH);
	}
	else
		tabmsg(IDS_MRK);
}

void nuscol(unsigned ind){

	uPen[ind]=nuPen(uPen[ind],1,useCol[ind]);
	hbrUseCol[ind]=nuBrush(hbrUseCol[ind],useCol[ind]);
	redraw(hCol[ind]);
}

void movchk(){

	unsigned	ind,col,key,swtch;
	FRMHED*		pfrm;

	if(msg.wParam&MK_LBUTTON){

		if(!setMap(WASMOV)){
		
			if(chkMsgs(msg.pt,hDef[0],hDef[15])){

				wcol=vind&0xf;
				setMap(WASCOL);
			}
		}
	}
	else{

		if(rstMap(WASMOV)&&rstMap(WASCOL)){

			if(chkMsgs(msg.pt,hDef[0],hDef[15])){

				key=GetKeyState(VK_SHIFT)&0X8000;
				swtch=GetKeyState(VK_CONTROL)&0X8000;
				for(ind=0;ind<hed.stchs;ind++){

					col=stchs[ind].at&COLMSK;
					if(col==vind){

						stchs[ind].at&=NCOLMSK;
						stchs[ind].at|=wcol;
					}
					else{

						if(!key&&col==wcol){

							stchs[ind].at&=NCOLMSK;
							stchs[ind].at|=vind;
						}
					}
				}
				for(ind=0;ind<formpnt;ind++){

					pfrm=&formlst[ind];
					if(pfrm->ftyp){

						if(pfrm->fcol==vind)
							pfrm->fcol=wcol;
						else{

							if(!key&&pfrm->fcol==wcol)
								pfrm->fcol=vind;
						}
						if(pfrm->dhx.fth.fthcol==vind)
							pfrm->dhx.fth.fthcol=wcol;
						else{

							if(!key&&pfrm->dhx.fth.fthcol==wcol)
								pfrm->dhx.fth.fthcol=vind;
						}
					}
					if(pfrm->etyp){

						if(pfrm->bcol==vind)
							pfrm->bcol=wcol;
						else{

							if(!key&&pfrm->bcol==wcol)
								pfrm->bcol=vind;
						}
					}
				}
				if(!swtch){

					ind=useCol[vind];
					useCol[vind]=useCol[wcol];
					if(!key){

						useCol[wcol]=ind;
						nuscol(wcol);
					}
					nuscol(vind);
				}
				coltab();
				setMap(RESTCH);
			}
		}
	}
}

void inscol(){

	unsigned	ind,dcol,col;
	FRMHED*		tfrm;

	*rmap=0;
	if(chkMsgs(msg.pt,hDef[0],hCol[15])){

		vind&=COLMSK;
		for(ind=0;ind<hed.stchs;ind++)
			setr(stchs[ind].at&COLMSK);
		if(*rmap==COLSMSK)
			tabmsg(IDS_COLAL);
		else{

			dcol=15;
			while(chkr(dcol))
				dcol--;
			for(ind=0;ind<hed.stchs;ind++){

				col=stchs[ind].at&COLMSK;
				if(col>=vind&&col<dcol){

					stchs[ind].at&=NCOLMSK;
					stchs[ind].at|=col+1;
				}
			}
			for(ind=0;ind<formpnt;ind++){

				tfrm=&formlst[ind];
				if(tfrm->ftyp){

					if(tfrm->fcol>=vind&&tfrm->fcol<dcol)
						tfrm->fcol++;
					if(tfrm->dhx.fth.fthcol>=vind&&tfrm->dhx.fth.fthcol<dcol)
						tfrm->dhx.fth.fthcol++;
				}
				if(tfrm->etyp){

					if(tfrm->bcol>=vind&&tfrm->bcol<dcol)
						tfrm->bcol++;
				}
			}
			for(ind=dcol;ind>vind;ind--){

				useCol[ind]=useCol[ind-1];
				nuscol(ind);
			}
			coltab();
			setMap(RESTCH);
		}
	}
}

BOOL usedcol(){

	unsigned ind;

	for(ind=0;ind<hed.stchs;ind++){

		if((stchs[ind].at&COLMSK)==vind)
			return 1;
	}
	return 0;
}

void delcol(){

	unsigned	ind,col;
	FRMHED*		tfrm;

	if(chkMsgs(msg.pt,hDef[0],hCol[15])){

		vind&=0xf;
		if(usedcol())
			tabmsg(IDS_COLU);
		else{

			for(ind=0;ind<hed.stchs;ind++){

				col=stchs[ind].at&COLMSK;
				if(col>vind&&col){

					stchs[ind].at&=NCOLMSK;
					stchs[ind].at|=col-1;
				}
			}
			for(ind=0;ind<formpnt;ind++){

				tfrm=&formlst[ind];
				if(tfrm->ftyp){

					if(tfrm->fcol>vind)
						tfrm->fcol--;
					if(tfrm->dhx.fth.fthcol>vind)
						tfrm->dhx.fth.fthcol--;
				}
				if(tfrm->etyp){

					if(tfrm->bcol>vind)
						tfrm->bcol--;
				}
			}
			for(ind=vind;ind<15;ind++){

				useCol[ind]=useCol[ind+1];
				nuscol(ind);
			}
			coltab();
			setMap(RESTCH);
		}
	}
}

void set1knot(){

	unsigned src,dst;

	if(hed.stchs&&chkMap(SELBOX)){

		savdo();
		if(cloInd==(unsigned)hed.stchs-1){

			setMap(FILDIR);
			opnt=cloInd+1;
			endknt(cloInd);
		}
		else{

			src=hed.stchs-1;
			dst=hed.stchs+4;
			while(src&&src>=cloInd)
				mvstch(dst--,src--);
			opnt=cloInd+1;
			strtknt(cloInd);
		}
		hed.stchs+=5;
		coltab();
		setMap(RESTCH);
	}
	else{

		msgstr(IDS_NOSTCHSEL);
		shoMsg(msgbuf);
	}
}

void selfrm0(){

	rstMap(GRPSEL);
	if(rstMap(FORMSEL)){

		setMap(FRMPSEL);
		clofine=0;
	}
	setMap(RESTCH);
}

void selfrmx(){

	rstMap(GRPSEL);
	if(rstMap(FORMSEL)){

		setMap(FRMPSEL);
		clofine=formlst[clofind].sids-1;
	}
	setMap(RESTCH);
}

void setpclp(){

	POINT		tof;
	POINT		tpnt;
	unsigned	ind,ine;

	sfCor2px(iseq[0],&tpnt);
	fplin[0].x=tpnt.x;
	fplin[0].y=tpnt.y;
	sfCor2px(iseq[1],&tpnt);
	tof.x=msg.pt.x-stOrg.x-tpnt.x;
	tof.y=msg.pt.y-stOrg.y-tpnt.y;
	for(ind=0;ind<opnt-2;ind++){

		ine=ind+1;
		sfCor2px(iseq[ine],&tpnt);
		fplin[ine].x=tpnt.x+tof.x;
		fplin[ine].y=tpnt.y+tof.y;
	}
	ind++;
	sfCor2px(iseq[ind],&tpnt);
	fplin[ind].x=tpnt.x;
	fplin[ind].y=tpnt.y;
}

void dupclp(){

	SetROP2(rsdc,R2_XORPEN);
	SelectObject(rsdc,fPen);
	Polyline(rsdc,fplin,opnt);
	SetROP2(rsdc,R2_COPYPEN);
}

void unpclp(){

	if(rstMap(SHOP))
		dupclp();
}

void fixpclp(){

	POINT		tpnt;
	FLPNT		pof;
	unsigned	ind,ine,cnt;
	
	tpnt.x=msg.pt.x+fmovdif.x;
	tpnt.y=msg.pt.y+fmovdif.y;
	pxCor2stch(tpnt);
	pof.x=sPnt.x-iseq[1].x;
	pof.y=sPnt.y-iseq[1].y;
	ine=nxt(clofine);
	cnt=opnt-2;
	fltspac(&flt[ine],cnt);
	for(ind=1;ind<opnt-1;ind++){

		flt[ine].x=iseq[ind].x+pof.x;
		flt[ine].y=iseq[ind].y+pof.y;
		ine++;
	}
	frmpnt->sids+=cnt;
	refil();
	coltab();
	setMap(RESTCH);
}

BOOL sidclp(){

	fvars(clofind);
	if(OpenClipboard(hWnd)){

		hClip=RegisterClipboardFormat(pcdClip);
		hClpMem=GetClipboardData(hClip);
		if(hClpMem){

			redclp();
			CloseClipboard();
			return 1;
		}
	}
	CloseClipboard();
	return 0;
}

void selfpnt(){

	rstMap(FORMSEL);
	setMap(FRMPSEL);
	rstMap(FPSEL);
	rstMap(SELBOX);
	pselrng.strt=clofine;
	pselrng.frm=clofind;
	ritfcor(&formlst[clofind].flt[clofine]);
	setMap(RESTCH);
}

unsigned chkMsg(){

	unsigned		cod,dst;
	unsigned		ine,inf;
	long			ind;
	long			tlng;
	TCHAR			cmap[]={'3','4','6'};
	TCHAR			buf[20];
	double			tdub;
	FLPNT			nusiz;
	FLPNT			padj;
	RECT			trct;
	SATCON*			sac;
	FLPNT*			clp;
	POINT			tpnt;
	FRMHED*			tfrm;
	FLRCT			tbig;
	unsigned char*	pchr;
	TXPNT*			ptx;
	TXPNT*			pts;

	if(msg.message==WM_MOUSEMOVE){

		if(chkMap(TXTMOV))
		{
			txtrmov();
			return 1;
		}
		movchk();
		if(msg.pt.x>=sRct.left&&msg.pt.x<=sRct.right
			&&msg.pt.y>=sRct.top&&msg.pt.y<=sRct.bottom){

			if(GetKeyState(VK_SHIFT)&0x8000)
			{
				mvshft();
				return 1;
			}
			if(GetKeyState(VK_SHIFT)&0x8000&&px2stch())
				ritfcor(&sPnt);
			if(*map&(PRFACTB|FORMINB|POLIMOVB)||hfdat){

				SetCursor(hAr);
				goto gotcur;
			}
			if(!chkMap(INIT)){

				if(chku(NEDOF))
					SetCursor(hCros);
				else
					SetCursor(hnedu);
				goto gotcur;
			}
			if(chkMap(INSRT)){

				if(chku(NEDOF))
					SetCursor(hCros);
				else{

					if(chkMap(LIN1))
						SetCursor(hnedu);
					else{

						if(stchs[cloInd+1].x>stchs[cloInd].x){

							if(stchs[cloInd+1].y>stchs[cloInd].y)
								SetCursor(hnedlu);
							else
								SetCursor(hnedld);
						}
						else{

							if(stchs[cloInd+1].y>stchs[cloInd].y)
								SetCursor(hnedru);
							else
								SetCursor(hnedrd);
						}
					}
				}
				goto gotcur;
			}
			if(*map&(BZUMINB|BOXZUMB|SELPNTB)){

				SetCursor(hCros);
				goto gotcur;
			}
			if(*map&(SATINB|SATPNTB|INSFRMB)){

				if(chku(FRMX))
					SetCursor(hCros);
				else
					SetCursor(hfrm);
				goto gotcur;
			}
			if(*map&SATCNKTB)
				SetCursor(hdlin);
			else
				SetCursor(hAr);
gotcur:;
			if(chkMap(FPUNCLP)){

				unpclp();
				setpclp();
				setMap(SHOP);
				dupclp();
			}
			if(chkMap(INSFIL)){

				unfrm();
				tpnt.x=msg.pt.x-stOrg.x;
				tpnt.y=msg.pt.y-stOrg.y;
				insflin(tpnt);
				setMap(SHOFRM);
				dufrm();
				return 1;
			}
			if(chkMap(MOVFRMS)){

				unstrtch();
				sizlin[0].x=sizlin[3].x=sizlin[4].x=msg.pt.x-fmovdif.x-stOrg.x;
				sizlin[1].x=sizlin[2].x=msg.pt.x+bigsiz.x-fmovdif.x-stOrg.x;
				sizlin[0].y=sizlin[1].y=sizlin[4].y=msg.pt.y-fmovdif.y-stOrg.y;
				sizlin[2].y=sizlin[3].y=msg.pt.y+bigsiz.y-fmovdif.y-stOrg.y;
				setMap(SHOSTRTCH);
				strtchbox();
				return 1;
			}
			if(chkMap(POLIMOV)){

				munfrm();
				setmfrm();
				setMap(SHOFRM);
				mdufrm();
				return 1;
			}
			if(chkMap(EXPAND)){

				unstrtch();
				nusiz.x=msg.pt.x-stOrg.x;
				nusiz.y=msg.pt.y-stOrg.y;
				ind=(cntrl+2)%4;
				tdub=fabs((double)(nusiz.x-sizlin[ind].x)/(nusiz.y-sizlin[ind].y));
				if(ind&1){

					if(tdub<xpct)
						nusiz.x=(sizlin[ind].y-nusiz.y)*xpct+sizlin[ind].x;
					else
						nusiz.y=(sizlin[ind].x-nusiz.x)/xpct+sizlin[ind].y;
					ind=nxtcrnr(ind);
					sizlin[ind].y=nusiz.y;
					ind=nxtcrnr(ind);
					sizlin[ind].x=nusiz.x;
					sizlin[ind].y=nusiz.y;
					ind=nxtcrnr(ind);
					sizlin[ind].x=nusiz.x;
				}
				else{
				
					if(tdub<xpct)
						nusiz.x=(nusiz.y-sizlin[ind].y)*xpct+sizlin[ind].x;
					else
						nusiz.y=(nusiz.x-sizlin[ind].x)/xpct+sizlin[ind].y;
					ind=nxtcrnr(ind);
					sizlin[ind].x=nusiz.x;
					ind=nxtcrnr(ind);
					sizlin[ind].x=nusiz.x;
					sizlin[ind].y=nusiz.y;
					ind=nxtcrnr(ind);
					sizlin[ind].y=nusiz.y;
				}
				sizlin[4].x=sizlin[0].x;
				sizlin[4].y=sizlin[0].y;
				setMap(SHOSTRTCH);
				strtchbox();
				return 1;
			}
			if(chkMap(STRTCH)){

				unstrtch();
				if(cntrl&1)
					tlng=msg.pt.x-stOrg.x;
				else
					tlng=msg.pt.y-stOrg.y;
				dst=(cntrl+2)%4;
				cod=nxtcrnr(dst);
				for(ind=0;ind<4;ind++){

					if((unsigned)ind!=dst&&(unsigned)ind!=cod){

						if(cntrl&1)
							sizlin[ind].x=tlng;
						else
							sizlin[ind].y=tlng;
					}
				}
				sizlin[4].x=sizlin[0].x;
				sizlin[4].y=sizlin[0].y;
				setMap(SHOSTRTCH);
				strtchbox();
				return 1;
			}
			if(chkMap(INSFRM)){

				uninsf();
				inlin[1].x=msg.pt.x-stOrg.x;
				inlin[1].y=msg.pt.y-stOrg.y;
				setMap(SHOINSF);
				duinsf();
				return 1;
			}
			if(chkMap(FUNCLP)){

				unfrm();
				setmfrm();
				setMap(SHOFRM);
				dufrm();
				return 1;
			}
			if(chkMap(SATCNKT)){

				drwcon();
				return 1;
			}
			if(chkMap(SATPNT)){

				drwsat();
				return 1;
			}
			if(chkMap(FRMOV)){

				munfrm();
				setmfrm();
				setMap(SHOFRM);
				mdufrm();
				return 1;
			}
			if(chkMap(FRMPMOV)){

				unmov();
				mvlin[1].x=msg.pt.x-stOrg.x;
				mvlin[1].y=msg.pt.y-stOrg.y;
				setMap(SHOMOV);
				ritmov();
				if(px2stch())
					ritfcor(&sPnt);
				return 1;
			}
			if(chkMap(MOVCNTR)){

				unrot();
				px2stch();
				rotcntr.x=sPnt.x;
				rotcntr.y=sPnt.y;
				ritrot();
				return 1;
			}
			if(chkMap(ROTCAPT)){
			
				unrotu();
				unrot();
				rlinu[1].x=msg.pt.x-stOrg.x;
				rlinu[1].y=msg.pt.y-stOrg.y;
				padj.x=rlinu[0].x-rlinu[1].x;
				padj.y=rlinu[0].y-rlinu[1].y;
				if(padj.x)
					ang=-atan2(padj.y,padj.x);
				else{

					if(padj.y>0)
						ang=PI/2;
					else
						ang=-PI/2;		
				}
				ang-=hang;
				ritrot();
				setMap(ROTUSHO);
				durotu();
				return 1;
			}
			if(chkMap(SELPNT)){

				if(setMap(VCAPT))
					SetCapture(hWnd);
				unsel();
				rSelbox();
				return 1;
			}
			if(chkMap(CLPSHO)){
				
				unclp();
				clpbox();
				return 1;
			}
			if(chkMap(CAPT)){

				if(px2stch())
					ritfcor(&sPnt);
				unlin();
				mlin0[1].x=mlin1[0].x=msg.pt.x-stOrg.x;
				mlin0[1].y=mlin1[0].y=msg.pt.y-stOrg.y;
				dulin();
				return 1;
			}
			if(chkMap(INSRT)){

				if(px2stch())
					ritfcor(&sPnt);
				if(setMap(VCAPT))
					SetCapture(hWnd);
				if(chkMap(LIN1)){

					if(hed.stchs){

						xlin1();
						inlin[1].x=msg.pt.x-stOrg.x;
						inlin[1].y=msg.pt.y-stOrg.y;
						setMap(ILIN1);
						ilin1();
					}
					return 1;
				}
				xlin();
				inlin[1].x=msg.pt.x-stOrg.x;
				inlin[1].y=msg.pt.y-stOrg.y;
				setMap(ILIN);
				ilin();
				return 1;
			}
			if(chkMap(BOXZUM)&&setMap(VCAPT))
				SetCapture(hWnd);
			if(chkMap(BZUMIN)&&(msg.wParam&MK_LBUTTON)){

				if(setMap(VCAPT))
					SetCapture(hWnd);
				unbBox();
				blin[1].x=blin[2].x=msg.pt.x-stOrg.x;
				blin[2].y=blin[3].y=msg.pt.y-stOrg.y;
				setMap(BZUM);
				bBox();
				return 1;
			}
		}
		else{

			if(rstMap(VCAPT))
				ReleaseCapture();
		}
		return 1;
	}
	if(msg.message==WM_LBUTTONUP)
	{
		if(GetKeyState(VK_SHIFT)&0X8000&&px2stch())
		{
			setshft();
			return 1;
		}
		if(chkMap(TXTRED))
		{
			txtrup();
			return 1;
		}
		ReleaseCapture();
		movchk();
		if(rstMap(MOVFRMS)){

			savdo();
			tpnt.x=(msg.pt.x-fmovdif.x-stOrg.x)-bigrct.left;
			tpnt.y=(msg.pt.y-fmovdif.y-stOrg.y)-bigrct.top;
			ratsr();
			fmovdif.x=tpnt.x/hfrat;
			fmovdif.y=tpnt.y/vfrat;
			if(chkMap(FPSEL)){

				fvars(clofind);
				ine=pselrng.strt;
				for(ind=0;(unsigned)ind<=pselrng.cnt;ind++){

					flt[ine].x+=fmovdif.x;
					flt[ine].y-=fmovdif.y;
					ine=pdir(ine);
				}
				setpsel();
				frmout(clofind);
				refil();
				setMap(RESTCH);
			}
			else{

				if(chkMap(BIGBOX)){

					savdo();
					for(ind=0;ind<(long)formpnt;ind++)
						frmadj(ind);
					for(ind=0;ind<hed.stchs;ind++){

						stchs[ind].x+=fmovdif.x;
						stchs[ind].y-=fmovdif.y;
					}
					selal();
				}
				else{

					savdo();
					for(cod=0;cod<fselpnt;cod++)
						frmadj(selist[cod]);
					frmsadj();
					setMap(RESTCH);
				}
			}
			return 1;
		}
		if(rstMap(EXPAND)){

			setexpand();
			return 1;
		}
		if(rstMap(STRTCH)){

			setstrtch();
			return 1;
		}
		if(rstMap(FRMOV)){

			savdo();
			rstfrm();
			setMap(RESTCH);
			return 1;
		}
		if(rstMap(FRMPMOV)){

			savdo();
			setfpnt();
			return 1;
		}
		if(rstMap(MOVCNTR)){

			setMap(ROTAT);
			return 1;
		}
		if(rstMap(ROTCAPT)){

			rotfn();
			return 1;
		}
		if(rstMap(SELPNT)){

			savdo();
			ReleaseCapture();
			unsel();
			padj.x=(rngrct.left+selof.x)-sPnt.x;
			padj.y=(rngrct.bottom+selof.y)-sPnt.y;
			for(ind=gpnt0;ind<=(long)gpnt1;ind++){

				stchs[ind].x-=padj.x;
				stchs[ind].y-=padj.y;
			}
			setMap(RESTCH);
			return 1;
		}
		if(rstMap(CAPT)){

			unlin();
			ReleaseCapture();
			rstMap(CAPT);
			px2stch();
			stchs[cloInd].x=sPnt.x;
			stchs[cloInd].y=sPnt.y;
			stchs[cloInd].at|=USMSK;
			if(zumFct<STCHBOX){

				SetROP2(sdc,R2_NOTXORPEN);
				SelectObject(sdc,lPen);
				stchbox(cloInd-1,rsdc);
				stchbox(cloInd,rsdc);
				stchbox(cloInd+1,rsdc);
				SetROP2(sdc,R2_COPYPEN);
			}
			setMap(SELBOX);
			rstMap(FRMPSEL);
			setMap(RESTCH);
			return 1;
		}
		if(chkMap(BZUMIN)){

			px2stch();
			if(rstMap(BOXSLCT)){

				if(zBoxo.x>sPnt.x){

					rngrct.right=zBoxo.x;
					rngrct.left=sPnt.x;
				}
				else{

					rngrct.right=sPnt.x;
					rngrct.left=zBoxo.x;
				}
				if(zBoxo.y>sPnt.y){

					rngrct.top=zBoxo.y;
					rngrct.bottom=sPnt.y;
				}
				else{

					rngrct.top=sPnt.y;
					rngrct.bottom=zBoxo.y;
				}
				if(rstMap(GRPSEL)){

					rngadj();
					for(ine=gpnt0;ine<gpnt1;ine++){

						if(inrng(ine)){

							cloInd=ine;
							setMap(SELBOX);
							break;
						}
					}
				}
				if(rstMap(NOSEL)){

					fselpnt=0;
					rstMap(FORMSEL);
					for(ine=0;ine<formpnt;ine++){

						if(finrng(ine))
							selist[fselpnt++]=ine;
					}
					if(fselpnt){

						if(fselpnt==1){

							ReleaseCapture();
							gotbox();
							clofind=selist[0];
							clofine=0;
							fselpnt=0;
							ritnum(STR_NUMFORM,clofind);
							setMap(RESTCH);
							setMap(FORMSEL);
							return 1;
						}
					}
					if(fselpnt){

						gotbox();
						return 1;
					}
					rstMap(BZUMIN);
					rstMap(BOXSLCT);
					rstMap(FRMPSEL);
					setMap(RESTCH);
				}
				if(rstMap(SELBOX)){

					if(inrng(cloInd)){

						grpInd=cloInd+1;
						cloInd--;
						while(inrng(cloInd))
							cloInd--;
						cloInd++;
						while(inrng(grpInd))
							grpInd++;
						grpInd--;
						setMap(GRPSEL);
						gotbox();
						return 1;
					}
				}
				if(!chkMap(INSRT))
					rngal();
//				gotbox();
				return 1;
			}
			else{

				if(sPnt.x<zBoxo.x){

					tdub=zBoxo.x;
					zBoxo.x=sPnt.x;
					sPnt.x=tdub;
				}
				if(sPnt.y<zBoxo.y){

					tdub=zBoxo.y;
					zBoxo.y=sPnt.y;
					sPnt.y=tdub;
				}
				nusiz.x=sPnt.x-zBoxo.x;
				nusiz.y=sPnt.y-zBoxo.y;
				sPnt.x=zBoxo.x+nusiz.x/2;
				sPnt.y=zBoxo.y+nusiz.y/2;
				tdub=zumFct;
				if(nusiz.x>nusiz.y){

					nusiz.y=nusiz.x/stchAspct;
					zumFct=nusiz.x/zum0.x;
				}
				else{

					nusiz.x=nusiz.y*stchAspct;
					zumFct=nusiz.y/zum0.x;
				}
				if(zumFct<zumflor){

					zumFct=tdub;
					zumin();
					return 1;
				}
				zRct.left=zRct.bottom=0;
				zRct.right=nusiz.x;
				zRct.top=nusiz.y;
				shft(sPnt);
				rstMap(BZUMIN);
				setMap(RESTCH);
				if(!setMap(ZUMED))
					movStch();
				return 1;
			}
			rstMap(BZUMIN);
		}
	}
	if(msg.message==WM_RBUTTONDOWN||msg.message==WM_LBUTTONDOWN){

		if(rstMap(THUMON)){

			if(chkok()){

				save();
				thumbak();
				unmsg();
				return 1;
			}
			if(chkwnd(hdsc)){

				thumbak();
				unmsg();
				return 1;
			}
			setMap(BAKSHO);
			unbsho();
			rstMap(THUMSHO);
			unmsg();
			return 1;
		}
		if(rstMap(BAKSHO)){

			if(msg.message==WM_RBUTTONDOWN)
				setMap(RBUT);
			else
				rstMap(RBUT);
			for(ind=0;ind<OLDVER;ind++){

				if(msg.hwnd==hvu[ind]){

					baknum=ind;
					if(chkMap(THUMSHO)){

						if(savcmp())
							thumbak();
						else{

							if(chkMap(RBUT))
								thumbak();
							else{

								setMap(THUMON);
								savdisc();
							}
							return 1;
						}
					}
					else
						rebak();
					rstAll();
					setMap(RESTCH);
					return 1;
				}
			}
		}
		if(msg.pt.x>=bRct.left&&msg.pt.x<=bRct.right
			&&msg.pt.y>=bRct.top&&msg.pt.y<=bRct.bottom){

			unpat();
			tdub=(double)(msg.pt.y-bRct.top)/(bRct.bottom-bRct.top);
			if(msg.message==WM_RBUTTONDOWN){

				tdub=(double)(msg.pt.y-bRct.top)/(bRct.bottom-bRct.top);
				if(msg.wParam&MK_SHIFT&&(chkMap(SELBOX)||chkMap(GRPSEL))){

					unbox();
					grpInd=tdub*hed.stchs;
					setMap(GRPSEL);
					grpAdj();
					nuAct(grpInd);
					setMap(RESTCH);
				}
				else{

					cloInd=tdub*hed.stchs;
					nuAct(cloInd);
					movbox();
					if(rstMap(GRPSEL)){
						
						rstMap(SCROS);
						rstMap(ECROS);
						setMap(RESTCH);
					}
				}
			}
			else{

				cloInd=tdub*hed.stchs;
				nuAct(cloInd);
				rstAll();
				setMap(SELBOX);
				selCol();
			}
			redraw(hBar);
			return 1;
		}
	}
	if(msg.message==WM_RBUTTONDOWN){

		if(chkMap(TXTRED)&&!hMsg)
		{
			txtrbut();
			return 1;
		}
		if(GetKeyState(VK_SHIFT)&0X8000){

			if(closfrm()){

				if((chkMap(FRMPSEL)||chkMap(FPSEL))&&pselrng.frm==clofind){

					rstMap(FRMPSEL);
					setMap(FPSEL);
					pselrng.fin=clofine;
					ine=(pselrng.fin-pselrng.strt+sids)%sids;
					if(ine<(unsigned)sids>>1){

						pselrng.cnt=ine;
						setMap(PSELDIR);
					}
					else{

						pselrng.cnt=sids-ine;
						rstMap(PSELDIR);
					}
					setpsel();
					return 1;
				}
				rstMap(FPSEL);
				setMap(FRMPSEL);
				pselrng.strt=clofine;
				pselrng.frm=clofind;
				selfpnt();
				return 1;
			}
		}
		if(chkMap(WASTRAC)){

			if(chkMap(TRNIN0))
				dutrnum0(atoi(trinbuf));
			if(chkMap(TRNIN1))
				dutrnum1();
			if(!chkMap(WASEDG))
				tracpar();
			return 1;
		}
		unmsg();
		unboxs();
		unpat();
		numpnt=0;
		rstMap(SATIN);
		if(rstMap(SATPNT))
			satfix();
		if(chkMap(BAKSHO)){
		
			unbsho();
			return 1;
		}
		if(rstMap(BIGBOX))
			setMap(RESTCH);
		if(chkMap(PRFACT)){

			if(rstMap(HUPMSG))
				unsid();
			else{

				if(prfind){

					chknum();
					unsid();
					prfind=0;
				}
				else{

					DestroyWindow(hPrf);
					rstMap(PRFACT);
					if(rstMap(WASRT))
						setMap(INSRT);
				}
			}
			setMap(RESTCH);
			return 1;
		}
		else{

			if(sidtyp){

				chknum();
				sidtyp=0;
				setMap(RESTCH);
				return 1;
			}
		}
		if(rstMap(INSFRM)){

			insadj();
			rstMap(SHOINSF);
			setMap(RESTCH);
			return 1;
		}
		if(px2stch()&&!(chkMap(SIZSEL)&&chkMsgs(msg.pt,hSizChng[0],hSizChng[2]))){

			if(formpnt&&!chkMap(FRMOF)){
				
				if(msg.wParam&MK_SHIFT){

					bakfrm=clofind;
					if(closfrm()){

						ine=0;
						if(fselpnt){

							nuslst(clofind);
							setMap(RESTCH);
							return 1;
						}
						else{

							if(rstMap(FORMSEL)&&bakfrm!=clofind){

								if(bakfrm>clofind){

									ine=clofind;
									clofind=bakfrm;
									bakfrm=ine;
								}
								for(ind=bakfrm;ind<=(long)clofind;ind++)
									selist[ine++]=ind;
								fselpnt=ine;
								setMap(RESTCH);
								return 1;
							}
							else
								nufsel();
						}
					}
				}
				if(msg.wParam&MK_CONTROL){

					if(!fselpnt&&chkMap(FORMSEL)){

						setMap(WASEL);
						baksel=clofind;
					}
					if(closfrm())
						nufsel();
					if(fselpnt>1)
						butxt(HNUM,"");
					else
						ritnum(STR_NUMFORM,selist[0]+1);
					return 1;
				}
				if(chkMap(FORMSEL)){

					if(sidtyp){

						chknum();
						sidtyp=0;
						goto frmskip;
					}
					if(hfdat){

						undat();
						unsid();
						sidtyp=0;
						setMap(RESTCH);
						goto frmskip;
					}
					ritfrct(clofind,rsdc);
					lenCalc();
					if(!rstMap(ENTROT))
						rstMap(FORMSEL);
					setMap(DUMEN);
					if(!closPnt1(&cloInd))
						unbox();
frmskip:;
				}
				if(closfrm()){

					setMap(FORMSEL);
					rstMap(FPSEL);
					unpsel();
					fvars(clofind);
					ritfrct(clofind,rsdc);
					if(rstMap(FRMPSEL)||fselpnt){

						setMap(RESTCH);
						fselpnt=0;
					}
					ritnum(STR_NUMFORM,clofind);
					cod=(formlst[clofind].at&FRMLMSK)>>1;
					lenCalc();
					unrot();
					return 1;
				}
				if(fselpnt){

					fselpnt=0;
					setMap(RESTCH);
				}
				if(rstMap(FRMPSEL))
					setMap(RESTCH);
			}
			if(chkMap(INIT)||hFil){

				if(msg.wParam&MK_SHIFT){
					
					if(chkMap(SELBOX)){

						cod=cloInd;
						closPnt1(&cloInd);
						if(cloInd!=cod){

							unbox();
							grpInd=cloInd;
							cloInd=cod;
							setMap(GRPSEL);
							grpAdj();
						}
						nuAct(grpInd);
						redraw(hBar);
						return 1;
					}
					if(chkMap(GRPSEL)){

						cod=cloInd;
						closPnt1(&cloInd);
						grpInd=cloInd;
						cloInd=cod;
						grpAdj();
						nuAct(grpInd);
						redraw(hBar);
						return 1;
					}
					rebox();
				}
				else{

					rstMap(LENSRCH);
					rstMap(WASGRP);
					rstMap(FPSEL);
					rstMap(WASFRMFRM);
					rstMap(SIDACT);
					if(rstMap(INSRT)){

						ReleaseCapture();
						rstAll();
						setMap(RESTCH);
					}
					else{

						if(rstMap(GRPSEL))
							setMap(RESTCH);
						if(hed.stchs)
							rebox();
					}
				}
				clrstch();
				setMap(RESTCH);
			}
			return 1;
		}
		if(msg.pt.x>=minLenRct.left&&msg.pt.x<=minLenRct.right
			&&msg.pt.y>minLenRct.top&&msg.pt.y<=minLenRct.bottom){

			srchk();
			setsrch(minpnt);
			lensadj();
			setMap(GRPSEL);
			setMap(RESTCH);
			return 1;
		}
		if(msg.pt.x>=maxLenRct.left&&msg.pt.x<=maxLenRct.right
			&&msg.pt.y>maxLenRct.top&&msg.pt.y<=maxLenRct.bottom){

			srchk();
			setsrch(maxpnt);
			lensadj();
			setMap(GRPSEL);
			setMap(RESTCH);
		}
		return 1;
	}
	if(msg.message==WM_LBUTTONDOWN){

		if(GetKeyState(VK_SHIFT)&0X8000&&px2stch())
		{
			dushft();
			return 1;
		}
		if(chkMap(TXTRED)&&!chkMap(FORMIN))
		{
			txtlbut();
			return 1;
		}
		if(rstMap(FSETFCOL))
		{
			unsid();
			unmsg();
			if(chkMsgs(msg.pt,hDef[0],hDef[15]))
			{
				dufcol(vind+1);
				return 1;
			}
		}
		if(rstMap(FSETBCOL))
		{
			unsid();
			unmsg();
			if(chkMsgs(msg.pt,hDef[0],hDef[15]))
			{
				dubcol(vind+1);
				return 1;
			}
		}
		if(rstMap(FPUNCLP)){

			savdo();
			fixpclp();
			frmout(clofind);
			return 1;
		}
		if(chkMap(FPSEL)&&!chkMap(FUNCLP)&&!chkMap(ROTAT)){
		
			MoveMemory(&biglin,&pselin,sizeof(POINT)*9);
			MoveMemory(&bigrct,&pxselrct,sizeof(RECT));
			if(chkbig())
				return 1;
		}
		if(chkMap(WASTRAC)){

			tracpar();
			return 1;
		}
		if(rstMap(HUPMSG)){

			for(ind=0;ind<HUPS;ind++){

				if(msg.hwnd==hsidWnd[ind]){

					switch(ind+1){

					case SETCUST:

						ini.xcust=ini.hupx;
						ini.ycust=ini.hupy;
						setMap(MSGOF);
						sprintf(msgbuf,stab[STR_CUSTHUP],ini.hupx/PFGRAN,ini.hupy/PFGRAN);
						shoMsg(msgbuf);
						break;

					case SMALHUP:

						ini.hupx=SHUPX;
						ini.hupy=SHUPY;
						ini.hup=SMALHUP;
						break;

					case LARGHUP:

						ini.hupx=LHUPX;
						ini.hupy=LHUPY;
						ini.hup=LARGHUP;
						break;

					case CUSTHUP:

						ini.hupx=ini.xcust;
						ini.hupy=ini.ycust;
						ini.hup=CUSTHUP;
						break;

					case HUP100:

						ini.hupx=HUP100XY;
						ini.hupy=HUP100XY;
						ini.hup=CUSTHUP;
						break;
					}
					zum0.x=ini.hupx;
					zum0.y=ini.hupy;
					sethup();
					chkhup();
					break;
				}
			}
			unsid();
			prfmsg();
			return 1;
		}
		if(rstMap(INSFIL)){

			duinsfil();
			return 1;
		}
		if(chkMap(BIGBOX)&&chkbig())
			return 1;
		if(rstMap(DELSFRMS)){

			cod=0;
			if(chkok()){
					
				savdo();
				rstMap(DELTO);
				cod=1;
			}
			else{

				GetWindowRect(hto,&trct);
				if(msg.pt.x>=trct.left&&msg.pt.x<=trct.right
					&&msg.pt.y>=trct.top&&msg.pt.y<=trct.bottom){

					savdo();
					setMap(DELTO);
					cod=1;
				}
			}
			delsfrms(cod);
			unmsg();
			return 1;
		}
		if(rstMap(MOVMSG)){

			if(chkok()){
					
				savdo();
				refilfn();
			}
			unmsg();
			if(rstMap(WASFRMFRM))
				refrm();
			return 1;
		}
		if(rstMap(FUNSCLP)){

			savdo();
			rstMap(MOVFRMS);
			pxrct2stch(bigrct,&tbig);
			px2stch();
			fmovdif.x=sPnt.x-((tbig.right-tbig.left)/2+tbig.left);
			fmovdif.y=sPnt.y-((tbig.top-tbig.bottom)/2+tbig.bottom);
			for(ind=0;ind<funscnt;ind++){

				clofind=formpnt+ind;
				fvars(clofind);
				for(ine=0;ine<frmpnt->sids;ine++){

					frmpnt->flt[ine].x+=fmovdif.x;
					frmpnt->flt[ine].y+=fmovdif.y;
				}
				frmout(clofind);
				refil();
			}
			formpnt+=funscnt;
			setMap(RESTCH);
			return 1;
		}
		if(fselpnt&&!chkMap(ROTAT)&&chkbig())
			return 1;
		if(chkMap(SIDCOL)&&chkMsgs(msg.pt,hDef[0],hDef[15])){

			savdo();
			if(rstMap(FSETFCOL))
			{
				dufcol(vind+1);
				return 1;
			}
			if(rstMap(BRDSID))
			{
				nubrdcol(vind);
				goto chkcolx;
			}
			if(rstMap(APSID))
			{
				nulapcol(vind);
				goto chkcolx;
			}
			if(rstMap(FTHSID))
			{
				nufthcol(vind);
				goto chkcolx;
			}
			if(rstMap(UNDCOL))
			{
				frmpnt->ucol=vind&0xf;
				refilfn();
				coltab();
				goto chkcolx;
			}
			if(rstMap(FSETUCOL))
			{
				dundcol(vind+1);
				return 1;
			}
			nufilcol(vind);
chkcolx:;
			msgbuf[0]=(TCHAR)vind+0x30;
			msgbuf[1]=0;
			SetWindowText(thDat[LBRDCOL],msgbuf);
			unsid();
			coltab();
			setMap(RESTCH);
			rstMap(SIDCOL);
			sidtyp=0;
			return 1;
		}
		if(rstMap(OSAV)){

			if(chkok()){

				save();
				nuFil();
				unmsg();
				return 1;
			}
			if(chkwnd(hdsc)){

				nuFil();
				unmsg();
				return 1;
			}
			unmsg();
			return 1;
		}
		if(rstMap(FCLOS)){

			if(chkok())
				save();
			else{

				if(!chkwnd(hcan))
					closfn();
			}
			unmsg();
			return 1;
		}
		if(rstMap(SAVEX)){

			if(chkok()){

				save();
				reldun();
			}
			if(chkwnd(hdsc))
				reldun();
			unmsg();
			return 1;
		}
		if(chkMap(PRFACT)){

			chknum();
			if(msg.hwnd==thDat[PSQR]){

				if(toglu(SQRFIL))
					SetWindowText(thDat[PSQR],stab[STR_PNTD]);
				else
					SetWindowText(thDat[PSQR],stab[STR_SQR]);
				return 1;
			}
			if(msg.hwnd==thDat[PBLNT]){

				if(toglu(BLUNT))
					SetWindowText(thDat[PBLNT],stab[STR_TAPR]);
				else
					SetWindowText(thDat[PBLNT],stab[STR_BLUNT]);
				return 1;
			}
			if(msg.hwnd==thDat[PUND]){

				if(toglu(DUND))
					SetWindowText(thDat[PUND],stab[STR_OFF]);
				else
					SetWindowText(thDat[PUND],stab[STR_ON]);
				return 1;
			}
			if(msg.hwnd==thDat[PHUP]){

				sidhup();
				return 1;
			}
			for(ind=0;ind<PRFLINS;ind++){

				if(msg.hwnd==thDat[ind]){

					prfind=ind+1;
					prfsid(thDat[ind]);
					break;
				}
			}
			return 1;
		}
		if(!chkMap(ROTAT)&&chkMap(GRPSEL)){

			if(iselpnt()){

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
					xpct=(double)(rngrct.right-rngrct.left)/(rngrct.top-rngrct.bottom);
				}
				cntrl>>=1;
				setMap(SHOSTRTCH);
				strtchbox();
				return 1;
			}
			else{
				
				pPnt.x=msg.pt.x-stOrg.x;
				pPnt.y=msg.pt.y-stOrg.y;
				if(pPnt.x>=rctlin[0].x&&pPnt.x<=rctlin[2].x&&
					pPnt.y>=rctlin[0].y&&pPnt.y<=rctlin[4].y){

					duSelbox();
					setMap(SELPNT);
					SetCapture(hWnd);
					setMap(VCAPT);
					rSelbox();
					return 1;
				}
			}
		}
		if(rstMap(NEWBAK)){

			if(chkok()){

				unmsg();
				save();
				newFil();
				return 1;
			}
			if(chkwnd(hdsc)){

				unmsg();
				newFil();
				return 1;
			}
			unmsg();
			return 1;
		}
		if(rstMap(PRGMSG)){

			if(chkok()){

				deldir();
				return 1;
			}
		}
		if(rstMap(DUBAK)){

			if(chkMap(THUMSHO)){
				
				if(chkok())
					thrsav();
				getbak();
				rstMap(THUMSHO);
				return 1;
			}
			else{

				if(chkok()){

					ind=duth(thrnam);
					thrnam[ind]='t';
					setMap(IGNAM);
					thrsav();
					thrnam[ind]='r';
					if(baknum)
						filnam[ind]=baknum+0x2f;
					setMap(REDOLD);
					nuFil();
					filnam[ind]='r';
					switch(baknum){
					
					case 3:

						movbak('1','2');

					case 2:

						movbak('0','1');

					case 1:

						movbak('r','0');
					}
					movbak('t','r');
					thrnam[ind]='t';
					DeleteFile(thrnam);
					thrnam[ind]='r';
					hFil=CreateFile(thrnam,(GENERIC_WRITE|GENERIC_READ),0,NULL,
						OPEN_EXISTING,0,NULL);
					if(hFil==INVALID_HANDLE_VALUE)
						hFil=0;
					return 1;
				}
				GetWindowRect(hcan,&trct);
				if(msg.pt.x>=trct.left&&msg.pt.x<=trct.right
					&&msg.pt.y>=trct.top&&msg.pt.y<=trct.bottom){

					getbak();
					return 1;
				}
			}
		}
		if(chkMap(DELFRM)){

			cod=0;
			if(chkok()){
					
				savdo();
				rstMap(DELTO);
				cod=1;
			}
			else{

				GetWindowRect(hto,&trct);
				if(msg.pt.x>=trct.left&&msg.pt.x<=trct.right
					&&msg.pt.y>=trct.top&&msg.pt.y<=trct.bottom){

					savdo();
					setMap(DELTO);
					cod=1;
				}
			}
			if(cod){

				frmdel();
				coltab();
				setMap(RESTCH);
			}
			unmsg();
			return 1;
		}
		if(chkMap(FILMSG)){

			if(chkok()){
					
				savdo();
				unfil();
				coltab();
				setMap(RESTCH);
				unmsg();
				return 1;
			}
		}
		if(rstMap(SIZSEL)){
			
			if(chkMsgs(msg.pt,hSizChng[0],hSizChng[2])){

				vind-=13;
				thrdSiz[thrdSel][0]=cmap[vind];
				sizInd[thrdSel]=vind;
				strncpy(buf,thrdSiz[thrdSel],2);
				buf[2]=0;
				SetWindowText(hSiz[thrdSel],buf);
				setMap(RESTCH);
				for(ind=0;ind<3;ind++)
					DestroyWindow(hSizChng[ind]);
				return 1;
			}
			else{
			
				for(ind=0;ind<3;ind++)
					DestroyWindow(hSizChng[ind]);
			}
		}
		if(rstMap(POLIMOV)){

			savdo();
			setfrm();
			return 1;
		}
		if(rstMap(FORMIN)){

			GetWindowRect(hMsg,&trct);
			if(msg.pt.x>=trct.left&&msg.pt.x<=trct.right
				&&msg.pt.y>=trct.top&&msg.pt.y<=trct.bottom){

				ind=(msg.pt.y-trct.top-1)/(buttonHi-4);
				if(rstMap(FENDIN)){

					if(ind==3)
						rstu(SQRFIL);
					if(ind==4)
						setu(SQRFIL);
				}
				else
					duform(ind);
				switch(ind){

				case RPOLI-1:
				case STAR-1:
				case SPIR-1:
				case HART-2:
				case LENS-2:
				case EGG-2:
				case ZIG-2:

					return 1;
				}
			}
			unmsg();
			return 1;
		}
		if(prfind==PAP+1&&chkMsgs(msg.pt,hDef[0],hDef[15])){

			sprintf(msgbuf,"%d",vind);
			apcol=vind;
			SetWindowText(thDat[PAP],msgbuf);
			unsid();
			return 1;
		}
		if(rstMap(SIDACT)){

			savdo();
			if(sidtyp==LFTHTYP){

				for(ind=0;ind<6;ind++){

					if(msg.hwnd==hsidWnd[ind]){

						frmpnt->dhx.fth.fthtyp=ind+1;
						refil();
						refrm();
						break;
					}
				}
				return 1;
			}
			if(sidtyp==LLAYR){

				for(ind=0;ind<5;ind++){

					if(msg.hwnd==hsidWnd[ind])
						break;
				}
				if(ind<5){

					movlayr(ind<<1);
					setMap(FORMSEL);
				}
				return 1;
			}
			frmpnt->bcol&=0xf;
			if(rstMap(BRDACT)){

				if(iseclp(clofind))
					deleclp(clofind);
				if(msg.hwnd==hsidWnd[0]){

					frmpnt->etyp=0;
					refilfn();
					coltab();
					unsid();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[1]){

					if(frmpnt->etyp){

						cod=frmpnt->etyp&NEGUND;
						if(cod==EGCLP||cod==EGSAT||cod==EGAP)
							bsizpar();
						frmpnt->etyp=EGLIN;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						bord();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[2]){

					if(frmpnt->etyp){

						cod=frmpnt->etyp&NEGUND;
						if(cod==EGCLP||cod==EGSAT||cod==EGAP)
							bsizpar();
						frmpnt->etyp=EGBLD;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						dubold();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[3]){

					unmsg();
					unsid();
					fclp();
					return 1;
				}
				if(msg.hwnd==hsidWnd[4]){

					if(frmpnt->etyp){

						switch(frmpnt->etyp){

						case EGCLP:

							bsizpar();

						case EGLIN:
						case EGBLD:

							frmpnt->esiz=brdwid;
							frmpnt->espac=stspace;
							break;

						case EGPRP:

							frmpnt->espac/=2;
							break;
						}
						frmpnt->etyp=EGSAT;
						if(chku(DUND))
							frmpnt->etyp|=EGUND;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						satbrd();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[5]){

					if(frmpnt->ftyp){

						delmfil(frmpnt->fcol);
						frmpnt->ftyp=0;
					}
					if(frmpnt->etyp){

						if(frmpnt->etyp==EGLIN||frmpnt->etyp==EGBLD||frmpnt->etyp==EGCLP){

							frmpnt->esiz=brdwid;
							frmpnt->espac=stspace;
							if(frmpnt->etyp==EGCLP)
								bsizpar();
						}
						frmpnt->etyp=EGAP;
						if(chku(DUND))
							frmpnt->etyp|=EGUND;
						frmpnt->bcol|=(apcol<<4);
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						apliq();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[6]){

					if(frmpnt->etyp){

						switch(frmpnt->etyp){

						case EGCLP:

							bsizpar();
						case EGLIN:
						case EGBLD:

							frmpnt->esiz=brdwid;
							frmpnt->espac=stspace;
							break;

						case EGSAT:

							frmpnt->espac*=2;
						}
						frmpnt->etyp=EGPRP;
						if(chku(DUND))
							frmpnt->etyp|=EGUND;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						prpbrd(stspace);
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[7]){

					if(frmpnt->etyp){

						if(frmpnt->etyp==EGLIN||frmpnt->etyp==EGBLD||frmpnt->etyp==EGCLP){

							frmpnt->esiz=brdwid;
							frmpnt->espac=stspace;
							if(frmpnt->etyp==EGCLP)
								bsizpar();
						}
						frmpnt->etyp=EGHOL;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						bhol();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[8]){

					if(frmpnt->etyp){

						if(frmpnt->etyp==EGLIN||frmpnt->etyp==EGBLD||frmpnt->etyp==EGCLP){

							frmpnt->esiz=brdwid;
							frmpnt->espac=stspace;
							if(frmpnt->etyp==EGCLP)
								bsizpar();
						}
						picot();
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						picot();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[9]){

					if(frmpnt->etyp){

						cod=frmpnt->etyp&NEGUND;
						if(cod==EGCLP||cod==EGSAT||cod==EGAP)
							bsizpar();
						frmpnt->etyp=EGDUB;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						dubsfil();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[10]){

					setMap(LINCHN);
					unmsg();
					unsid();
					chan();
					coltab();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[11]){

					rstMap(LINCHN);
					unmsg();
					unsid();
					chan();
					coltab();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[12]){

					unmsg();
					unsid();
					filclpx();
					return 1;
				}
			}
			else{

				if(frmpnt->ftyp==SAT&&frmpnt->stpt)
					delsac(clofind);
				if((frmpnt->etyp&NEGUND)==EGAP){

					frmpnt->etyp=EGSAT;
					if(chku(DUND))
						frmpnt->etyp|=EGUND;
				}
				if(msg.hwnd==hsidWnd[0]){

					frmpnt->typ=POLI;
					delmfil(frmpnt->fcol);
					frmpnt->ftyp=0;
					coltab();
					unsid();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[1]){

					savdo();
					frmpnt->typ=POLI;
					if(frmpnt->ftyp){

						respac();
						frmpnt->ftyp=VRTF;
						frmpnt->typ=POLI;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						filvrt();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[2]){

					frmpnt->typ=POLI;
					if(frmpnt->ftyp){

						respac();
						frmpnt->ftyp=HORF;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						filhor();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[3]){

					frmpnt->typ=POLI;
					if(frmpnt->ftyp){

						respac();
						frmpnt->ftyp=ANGF;
						frmpnt->angclp.fang=ini.angl;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						filangl();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[4]){

					frmpnt->typ=SAT;
					if(frmpnt->ftyp){

						respac();
						frmpnt->ftyp=SATF;
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						rstMap(FTHR);
						filsat();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[5]){

					frmpnt->typ=SAT;
					unmsg();
					unsid();
					clpfil();
					return 1;
				}
				if(msg.hwnd==hsidWnd[6]){

					if(frmpnt->ftyp){

						if(frmpnt->ftyp==CLPF)
							frmpnt->fspac=stspace;
						chkcont();
						goto didfil;
					}
					else{

						unmsg();
						unsid();
						contfil();
						return 1;
					}
				}
				if(msg.hwnd==hsidWnd[7]){

					unmsg();
					unsid();
					if(sidclp())
						vrtsclp();
					rstMap(CLPSHO);
					coltab();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[8]){

					unmsg();
					unsid();
					if(sidclp())
						horsclp();
					rstMap(CLPSHO);
					coltab();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[9]){

					unmsg();
					unsid();
					if(sidclp())
						angsclp();
					rstMap(CLPSHO);
					coltab();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[10]){

					unmsg();
					unsid();
					if(frmpnt->ftyp==FTHF){

						fthrfn();
						fritfil();
					}
					else
						fethrf();
					setMap(INIT);
					coltab();
					setMap(RESTCH);
					return 1;
				}
				if(msg.hwnd==hsidWnd[11])	//vertical texture
				{
					if(istx(clofind))
					{
						frmpnt->ftyp=TXVRTF;
						goto didfil;
					}
					dutxtfil();
				}
				if(msg.hwnd==hsidWnd[12])	//horizontal texture
				{
					if(istx(clofind))
					{
						frmpnt->ftyp=TXHORF;
						goto didfil;
					}
					dutxtfil();
				}
				if(msg.hwnd==hsidWnd[13])	//angle texture
				{
					if(istx(clofind))
					{
						frmpnt->ftyp=TXANGF;
						frmpnt->angclp.fang=ini.angl;
						goto didfil;
					}
					dutxtfil();
				}
didfil:;
				refrm();
				refil();
				unsid();
				setMap(RESTCH);
				return 1;
			}
		}
		if(hfdat){

			chknum();
			unsid();
			if(msg.hwnd==thDat[LTXOF])
			{
				sidtyp=LTXOF;
				sidwnd(thDat[LTXOF]);
				goto didat;
			}
			if(msg.hwnd==thDat[LUSPAC])
			{
				sidtyp=LUSPAC;
				sidwnd(thDat[LUSPAC]);
				goto didat;
			}
			if(msg.hwnd==thDat[LUANG])
			{
				sidtyp=LUANG;
				sidwnd(thDat[LUANG]);
				goto didat;
			}
			if(msg.hwnd==thDat[LULEN])
			{
				sidtyp=LULEN;
				sidwnd(thDat[LULEN]);
				goto didat;
			}
			if(msg.hwnd==thDat[LWLKIND])
			{
				sidtyp=LWLKIND;
				sidwnd(thDat[LWLKIND]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHSIZ]){

				sidtyp=LFTHSIZ;
				sidwnd(thDat[LFTHSIZ]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHNUM]){

				sidtyp=LFTHNUM;
				sidwnd(thDat[LFTHNUM]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHFLR]){

				sidtyp=LFTHFLR;
				sidwnd(thDat[LFTHFLR]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHUPCNT]){

				sidtyp=LFTHUPCNT;
				sidwnd(thDat[LFTHUPCNT]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHDWNCNT]){

				sidtyp=LFTHDWNCNT;
				sidwnd(thDat[LFTHDWNCNT]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHBLND]){

				setMap(FLPBLND);
				goto didfil;
			}
			if(msg.hwnd==thDat[LFTHUP]){

				frmpnt->xat^=AT_FTHUP;
				goto didfil;
			}
			if(msg.hwnd==thDat[LFTHDWN]){

				frmpnt->xat^=AT_FTHDWN;
				goto didfil;
			}
			if(msg.hwnd==thDat[LFTHTYP]){

				sidtyp=LFTHTYP;
				sidmsg(thDat[LFTHTYP],&stab[STR_FTH0],6);
				goto didat;		
			}
			if(msg.hwnd==thDat[LFRM]){

				savdo();
				unfil();
				if(frmpnt->typ==LIN)
					frmpnt->typ=POLI;
				else
					frmpnt->typ=LIN;
				coltab();
				delsac(clofind);
				setMap(RESTCH);
				goto didat;
			}
			if(msg.hwnd==thDat[LLAYR]){

				sidtyp=LLAYR;
				rstMap(FILTYP);
				sidmsg(thDat[LLAYR],laytxt,5);
				goto didat;
			}
			if(msg.hwnd==thDat[LFRMFIL]){

				rstMap(FILTYP);
				sidtyp=LFRMFIL;
				sidmsg(thDat[LFRMFIL],&stab[STR_FIL0],14);
				goto didat;		
			}
			if(msg.hwnd==thDat[LFRMCOL]){

				sidtyp=LFRMCOL;
				sidwnd(thDat[LFRMCOL]);
				setMap(SIDCOL);
				goto didat;
			}
			if(msg.hwnd==thDat[LUNDCOL]){

				sidtyp=LUNDCOL;
				sidwnd(thDat[LUNDCOL]);
				setMap(SIDCOL);
				setMap(UNDCOL);
				goto didat;
			}
			if(msg.hwnd==thDat[LFTHCOL]){

				sidtyp=LFTHCOL;
				sidwnd(thDat[LFTHCOL]);
				setMap(SIDCOL);
				setMap(FTHSID);
				goto didat;
			}
			if(msg.hwnd==thDat[LFRMSPAC]){

				sidtyp=LFRMSPAC;
				sidwnd(thDat[LFRMSPAC]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFRMLEN]){

				sidtyp=LFRMLEN;
				sidwnd(thDat[LFRMLEN]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRD]){

				setMap(FILTYP);
				sidmsg(thDat[LBRD],&stab[STR_EDG0],EDGETYPS+1);
				setMap(BRDACT);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDCOL]){

				sidtyp=LBRDCOL;
				sidwnd(thDat[LBRDCOL]);
				setMap(SIDCOL);
				setMap(BRDSID);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDSPAC]){

				sidtyp=LBRDSPAC;
				sidwnd(thDat[LBRDSPAC]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDLEN]){

				sidtyp=LBRDLEN;
				sidwnd(thDat[LBRDLEN]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDSIZ]){

				sidtyp=LBRDSIZ;
				sidwnd(thDat[LBRDSIZ]);
				goto didat;
			}
			if(msg.hwnd==thDat[LAPCOL]){

				sidtyp=LAPCOL;
				setMap(SIDCOL);
				setMap(APSID);
				sidwnd(thDat[LAPCOL]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBCSIZ]){

				sidtyp=LBCSIZ;
				sidwnd(thDat[LBCSIZ]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBSTRT]){

				cod=frmpnt->at&SBLNT;
				if(cod)
					frmpnt->at&=NSBLNT;
				else
					frmpnt->at|=SBLNT;
				refil();
				coltab();
				setMap(RESTCH);
				return 1;
			}
			if(msg.hwnd==thDat[LBFIN]){

				cod=frmpnt->at&FBLNT;
				if(cod)
					frmpnt->at&=NFBLNT;
				else
					frmpnt->at|=FBLNT;
				refil();
				coltab();
				setMap(RESTCH);
				return 1;
			}
			if(msg.hwnd==thDat[LFRMANG]){

				sidtyp=LFRMANG;
				sidwnd(thDat[LFRMANG]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDPIC]){

				sidtyp=LBRDPIC;
				sidwnd(thDat[LBRDPIC]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDUND]){

				frmpnt->etyp^=EGUND;
				refil();
				goto didat;
			}
			if(msg.hwnd==thDat[LSACANG]){

				sidtyp=LSACANG;
				sidwnd(thDat[LSACANG]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFRMFAZ]){

				sidtyp=LFRMFAZ;
				sidwnd(thDat[LFRMFAZ]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBRDPOS]){

				sidtyp=LBRDPOS;
				sidwnd(thDat[LBRDPOS]);
				goto didat;
			}
			if(msg.hwnd==thDat[LBFILSQR]){

				dubit(AT_SQR);
				return 1;
			}
			if(msg.hwnd==thDat[LFSTRT]){

				dubit(AT_STRT);
				return 1;
			}
			if(msg.hwnd==thDat[LDSTRT])
			{
				sidtyp=LDSTRT;
				sidwnd(thDat[LDSTRT]);
				goto didat;
			}
			if(msg.hwnd==thDat[LFEND]){

				dubit(AT_END);
				return 1;
			}
			if(msg.hwnd==thDat[LDEND])
			{
				sidtyp=LDEND;
				sidwnd(thDat[LDEND]);
				goto didat;
			}
			if(msg.hwnd==thDat[LWALK])
			{
				dubit(AT_WALK);
				return 1;
			}
			if(msg.hwnd==thDat[LCWLK])
			{
				dubit(AT_CWLK);
				return 1;
			}
			if(msg.hwnd==thDat[LUND])
			{
				dubit(AT_UND);
				return 1;
			}
			if(msg.hwnd==thDat[LMAXFIL]){

				sidtyp=LMAXFIL;
				sidwnd(thDat[LMAXFIL]);
				goto didat;
			}
			if(msg.hwnd==thDat[LMINFIL]){

				sidtyp=LMINFIL;
				sidwnd(thDat[LMINFIL]);
				goto didat;
			}
			if(msg.hwnd==thDat[LMAXBRD]){

				sidtyp=LMAXBRD;
				sidwnd(thDat[LMAXBRD]);
				goto didat;
			}
			if(msg.hwnd==thDat[LMINBRD]){

				sidtyp=LMINBRD;
				sidwnd(thDat[LMINBRD]);
				goto didat;
			}
			undat();
			goto didskip;
didat:;
			return 1;
didskip:;
		}
		if(chkMap(INSFRM)){

			savdo();
			setins();
			return 1;
		}
		if(chkMap(FUNCLP)){

			savdo();
			formpnt++;
			setMap(INIT);
			rstfrm();
			fvars(clofind);
			refil();
			rstMap(FUNCLP);
			if(rstMap(FPSEL))
				frmout(formpnt-1);
			setMap(RESTCH);
			return 1;
		}
		if(chkMap(SATCNKT)){

			savdo();
			satknkt();
			return 1;
		}
		if(chkMap(SATPNT)){

			satpnt1();
			return 1;
		}
		if(rstMap(SATIN)){

			satpnt0();
			return 1;
		}
		if(chkMap(FORMSEL)){

			if(!chkMap(FRMROT)&&chkfrm())
				return 1;
		}
		if(rstMap(MOVFRM)){

			savdo();
			setfrm();
			return 1;
		}
		unmsg();
		if(px2stch()&&!(chkMap(SIZSEL)&&chkMsgs(msg.pt,hSizChng[0],hSizChng[2]))){

			unpat();
			if(rstMap(ROTAT)){

				rlinu[1].x=msg.pt.x-stOrg.x;
				rlinu[1].y=msg.pt.y-stOrg.y;
				padj.x=rlinu[0].x-rlinu[1].x;
				padj.y=rlinu[0].y-rlinu[1].y;
				if(hypot(padj.x,padj.y)<CLOSENUF){

					px2stch();
					rotcntr.x=sPnt.x;
					rotcntr.y=sPnt.y;
					setMap(MOVCNTR);
					unrot();
					ritrot();
				}
				else{

					if(padj.x)
						hang=-atan2(padj.y,padj.x);
					else{

						if(padj.y>0)
							hang=PI/2;
						else
							hang=-PI/2;		
					}
					setMap(ROTUSHO);
					durotu();
					setMap(ROTCAPT);
				}
				return 1;
			}
			if(rstMap(CLPSHO)){

				savdo();
				if((rstMap(SELBOX)||rstMap(INSRT))&&cloInd!=(unsigned)hed.stchs-1)
					lodclp(cloInd);
				else
					lodclp(hed.stchs);
				rngadj();
				selRct(&tbig);
				rctlin[0].x=rctlin[6].x=rctlin[7].x=rctlin[8].x=trct.left;
				rctlin[1].x=rctlin[5].x=midl(trct.right,trct.left);
				rctlin[0].y=rctlin[1].y=rctlin[2].y=rctlin[8].y=trct.top;
				rctlin[3].y=rctlin[7].y=midl(trct.top,trct.bottom);
				rctlin[4].y=rctlin[5].y=rctlin[6].y=trct.bottom;
				rctlin[2].x=rctlin[3].x=rctlin[4].x=trct.right;
				coltab();
				setMap(RESTCH);
				return 1;
			}
			if(rstMap(BOXZUM)){

				setMap(BZUMIN);
				blin[0].x=blin[3].x=blin[4].x=msg.pt.x-stOrg.x;
				blin[0].y=blin[1].y=msg.pt.y-stOrg.y;
				blin[4].y=blin[0].y-1;
				px2stch();
				zBoxo.x=sPnt.x;
				zBoxo.y=sPnt.y;
				setMap(VCAPT);
				return 1;
			}
			if(formpnt&&!chkMap(FRMOF)){

				if(!chkMap(INSRT)){
					
					if(rstMap(FORMSEL))
						ritfrct(clofind,rsdc);
					if(closfrm()){

						setMap(FRMPMOV);
						fvars(clofind);
						frmovlin();
						return 1;
					}
				}
			}
			if(chkMap(INIT)){

				unlin();
				savdo();
				if(chkMap(INSRT)&&hed.stchs<MAXSEQ){
			
					px2stch();
					cod=(actcol|USMSK|(actl<<LAYSHFT)|NOTFRM)&NKNOTMSK;
					if(chkMap(LIN1)){

						if(chkMap(BAKEND)){

							xlin1();
							ind=hed.stchs;
							stchs[ind].x=sPnt.x;
							stchs[ind].y=sPnt.y;
							stchs[ind].at=cod;
							duzrat();
							stch2px1(ind);
							inlin[0].x=pPnt.x;
							inlin[0].y=pPnt.y;
							inlin[1].x=msg.pt.x-stOrg.x;
							inlin[1].y=msg.pt.y-stOrg.y;
							hed.stchs++;
							coltab();
							setMap(RESTCH);
							return 1;
						}
						else{

							xlin1();
							for(ind=hed.stchs;ind;ind--){

								stchs[ind].at=stchs[ind-1].at;
								stchs[ind].x=stchs[ind-1].x;
								stchs[ind].y=stchs[ind-1].y;
							}
							stchs[0].at=cod;
							stchs[ind].at&=(~KNOTMSK);
							stchs[0].x=sPnt.x;
							stchs[0].y=sPnt.y;
							stch2px1(ind);
							inlin[0].x=pPnt.x;
							inlin[0].y=pPnt.y;
							inlin[1].x=msg.pt.x-stOrg.x;
							inlin[1].y=msg.pt.y-stOrg.y;
							hed.stchs++;	
							coltab();
							setMap(RESTCH);
							return 1;
						}
					}
					else{
						
						xlin();
						if(stchs[cloInd].at&ALTYPMSK&&stchs[cloInd+1].at&ALTYPMSK)
						{
							if((stchs[cloInd].at&FRMSK)==(stchs[cloInd+1].at&FRMSK))
								cod=stchs[cloInd].at|USMSK;
						}
						ind=hed.stchs;
						do{

							stchs[ind].x=stchs[ind-1].x;
							stchs[ind].y=stchs[ind-1].y;
							stchs[ind].at=stchs[ind-1].at;
							ind--;
						}while(ind>(long)cloInd);
						hed.stchs++;
						cloInd++;
						stchs[cloInd].x=sPnt.x;
						stchs[cloInd].y=sPnt.y;
						stchs[cloInd].at=cod;
						xlin();
						inlin[1].x=msg.pt.x-stOrg.x;
						inlin[1].y=msg.pt.y-stOrg.y;
						stch2px1(cloInd);
						inlin[0].x=pPnt.x;
						inlin[0].y=pPnt.y;
						stch2px1(cloInd+1);
						inlin[2].x=pPnt.x;
						inlin[2].y=pPnt.y;
						coltab();
						setMap(RESTCH);
						ritnum(STR_NUMSEL,cloInd);
						return 1;
					}
				}
				if((!chkMap(HIDSTCH))&&closPnt1(&selclo)){

					cloInd=selclo;
					unbox();
					unboxs();
					setbak(pixSiz[stchs[cloInd].at&0xf]+3);
					plin=new POINT[3];
					drwpnt=0;
					SetROP2(rsdc,R2_NOTXORPEN);
					if(cloInd==0){

						if(zumFct<STCHBOX){

							SelectObject(rsdc,lPen);
							stchbox(0,rsdc);
							stchbox(1,rsdc);
						}
						SetROP2(rsdc,R2_COPYPEN);
						drwLin(0,2,bakPen);
					}
					else{

						if(cloInd==(unsigned)hed.stchs-1){

							if(zumFct<STCHBOX){

								SelectObject(rsdc,lPen);
								stchbox(hed.stchs-1,rsdc);
								stchbox(hed.stchs-2,rsdc);
							}
							SetROP2(rsdc,R2_COPYPEN);
							drwLin(hed.stchs-2,2,bakPen);
						}
						else{

							if(zumFct<STCHBOX){

								SelectObject(rsdc,lPen);
								stchbox(cloInd-1,rsdc);
								stchbox(cloInd,rsdc);
								stchbox(cloInd+1,rsdc);
							}
							SetROP2(rsdc,R2_COPYPEN);
							drwLin(cloInd-1,3,bakPen);
						}
					}
					delete plin;
					mlin0[1].x=mlin1[0].x=msg.pt.x-stOrg.x;
					mlin0[1].y=mlin1[0].y=msg.pt.y-stOrg.y;
					if(cloInd<=0)
						rstMap(ISDWN);
					else{
				
						setMap(ISDWN);
						stch2px1(cloInd-1);
						mlin0[0].x=pPnt.x;
						mlin0[0].y=pPnt.y;
					}
					tlng=hed.stchs-1;
					if(cloInd>=(unsigned)tlng)
						rstMap(ISUP);
					else{

						setMap(ISUP);
						stch2px1(cloInd+1);
						mlin1[1].x=pPnt.x;
						mlin1[1].y=pPnt.y;
					}
					dulin();
					SetCapture(hWnd);
					setMap(CAPT);
					ritnum(STR_NUMSEL,cloInd);
				}
			}
			else{

				if(px2stch()){

					savdo();
					hed.stchs=1;
					inlin[0].x=msg.pt.x-stOrg.x;
					inlin[0].y=msg.pt.y-stOrg.y;
					stchs[0].at=USMSK|actcol|laycod|NOTFRM;
					stchs[0].x=sPnt.x;
					stchs[0].y=sPnt.y;
					colCnt=1;
					colch[0].colind=actcol;
					colch[0].stind=0;
					colch[1].stind=1;
					setMap(LIN1);
					setMap(INSRT);
					SetCapture(hWnd);
					cloInd=1;
					setMap(INIT);
					setMap(BAKEND);
				}
			}
			ritot(hed.stchs);
			setMap(BOXSLCT);
			setMap(BZUMIN);
			setMap(NOSEL);
			blin[0].x=blin[3].x=blin[4].x=msg.pt.x-stOrg.x;
			blin[0].y=blin[1].y=msg.pt.y-stOrg.y;
			blin[4].y=blin[0].y-1;
			px2stch();
			zBoxo.x=sPnt.x;
			zBoxo.y=sPnt.y;
			setMap(VCAPT);
			return 1;
		}
		if(msg.hwnd==hbuts[HBOXSEL]){

			boxsel();
			return 1;
		}
		if(msg.hwnd==hbuts[HUPTO]){

			toglup();
			return 1;
		}
		if(msg.hwnd==hbuts[HHID]){

			toglHid();
			return 1;
		}
		if(chkMsgs(msg.pt,hDef[0],hDef[15])){

			if(msg.message==WM_LBUTTONDOWN){

				savdo();
				cod=actcol;
				actcol=vind&0xf;
				redraw(hCol[cod]);
				redraw(hCol[actcol]);
				if(chkMap(HID)){

					rstMap(SELBOX);
					rstMap(GRPSEL);
					rstMap(SCROS);
					rstMap(ECROS);
					setMap(RESTCH);
					redraw(hbuts[HHID]);
				}
				else{

					if(fselpnt){

						nucols();
						coltab();
						setMap(RESTCH);
						return 1;
					}
					else{

						if(chkMap(FORMSEL)){

							frmpnt=&formlst[clofind];
							if(frmpnt->ftyp||frmpnt->etyp||frmpnt->xat&(AT_UND|AT_WALK|AT_CWLK)){

								if(formlst[clofind].ftyp){

									formlst[clofind].fcol=actcol;
									if(formlst[clofind].ftyp==FTHF)
										formlst[clofind].dhx.fth.fthcol=actcol;
								}
								if(formlst[clofind].etyp)
								{
									if(formlst[clofind].etyp==EGAP)
									{
										formlst[clofind].bcol&=0xf0;
										formlst[clofind].bcol|=actcol;
									}
									else
										formlst[clofind].bcol=actcol;
								}
								if(frmpnt->xat&(AT_UND|AT_WALK|AT_CWLK))
									formlst[clofind].ucol=actcol;
								cod=clofind<<FRMSHFT;
								for(ind=0;ind<hed.stchs;ind++){
									
									ine=stchs[ind].at;
									if(ine&ALTYPMSK&&(ine&FRMSK)==cod&&(ine&TYPMSK)!=TYPMSK)
									{
										ine&=NCOLMSK;
										ine|=actcol;
										stchs[ind].at=ine;
									}
								}
								coltab();
								setMap(RESTCH);
							}
						}
						else{

							if(chkMap(GRPSEL)){

								for(ind=gpnt0+1;ind<=(long)gpnt1;ind++){

									stchs[ind].at&=0xfffffff0;
									stchs[ind].at|=actcol;
								}
								coltab();
								setMap(RESTCH);
							}
							else{

								if(chkMap(COL))
									setMap(RESTCH);
							}
						}
					}
				}
			}
			return 1;
		}
		if(chkMsgs(msg.pt,hCol[0],hCol[15])){

			if(msg.message==WM_LBUTTONDOWN&&nuCol(useCol[vind])){

				savdo();
				useCol[vind]=gCol.rgbResult;
				uPen[vind]=nuPen(uPen[vind],1,useCol[vind]);
				hbrUseCol[vind]=nuBrush(hbrUseCol[vind],useCol[vind]);
				redraw(hCol[vind]);
				setMap(RESTCH);
			}
			return 1;
		}
		if(chkMsgs(msg.pt,hSiz[0],hSiz[15])){

			if(msg.message==WM_LBUTTONDOWN){

				savdo();
				thrdSel=vind;
				for(ind=0;ind<3;ind++)
					hSizChng[ind]=nuSiz(ind);
				setMap(SIZSEL);
			}
			return 1;
		}
	}
	switch(msg.message){

	case WM_TIMER:

		if(chkMap(RUNPAT)&&!msg.wParam)
			stchout();
		break;

	case WM_CHAR:

		if(isgraph(msg.wParam))
			nuthum(lchr(msg.wParam));
		break;

	case WM_KEYDOWN:

		cod=msg.wParam&0xffff;
		if(chkMap(TXTRED))
		{
			txtkey(cod);
			return 1;
		}
		fvars(clofind);

#if LANG==GRM
		if(cod>=0x30&&cod<=0x39){

			if(GetKeyState(VK_SHIFT)&0X8000){

				switch(cod){

				case 0x38:

					selfrm0();
					break;

				case 0x39:

					selfrmx();
					break;
				}
			}
		}
#endif
		if(chkMap(FORMIN)){

			if(GetKeyState(VK_CONTROL)&0X8000)
				return 1;

			switch(cod){

			case 'E':

				rstMap(FORMIN);
				unmsg();
				duform(LIN-1);
				return 1;

			case 'F':

				rstMap(FORMIN);
				unmsg();
				duform(POLI-1);
				return 1;
				
			case 'R':

				duform(RPOLI-1);
				return 1;

			case 'S':

				duform(STAR-1);
				return 1;

			case 'A':

				duform(SPIR-1);
				return 1;

			case 'H':

				duform(HART-2);
				return 1;

			case 'L':

				duform(LENS-2);
				return 1;

			case 'G':

				duform(EGG-2);
				return 1;

			case 'T':

				duform(TEAR-2);
				return 1;

			case 'Z':

				duform(ZIG-2);
				return 1;

			case 'W':

				duform(WAV-2);
				return 1;

			case 'D':

				duform(DASY-2);
				return 1;
			}
		}
		if(chkMap(FILMSG)){

			if(cod=VK_RETURN||cod==0xc0){
					
				savdo();
				unfil();
				coltab();
				setMap(RESTCH);
				unmsg();
				return 1;
			}
		}
		if(rstMap(MOVMSG)){

			if(cod==VK_RETURN||cod==0xc0){
					
				savdo();
				refilfn();
				unmsg();
			}
			else
				unmsg();
			if(rstMap(WASFRMFRM))
				refrm();
			return 1;
		}
		if(rstMap(PRGMSG)){

			if(cod==VK_RETURN||cod==0xc0){

				deldir();
				return 1;
			}
		}
		if(rstMap(DELSFRMS)){

			if(cod=='S'||cod==VK_RETURN||cod==0xc0){
			
				savdo();
				if(cod=='S')
					setMap(DELTO);
				else
					rstMap(DELTO);
				delsfrms(cod);
				coltab();
				setMap(RESTCH);
				unmsg();
				return 1;
			}
		}
		if(rstMap(DELFRM)){

			if(cod=='S'||cod==VK_RETURN||cod==0xc0){
			
				savdo();
				if(cod=='S')
					setMap(DELTO);
				else
					rstMap(DELTO);
				frmdel();
				fndknt();
				coltab();
				setMap(RESTCH);
				unmsg();
				return 1;
			}
		}
		if(chkMap(THUMSHO)){
			
			switch(cod){

			case VK_ESCAPE:

				unthum();
				rstMap(BAKSHO);
				goto thumout;

			case VK_DOWN:
			case 0x22:		//page down

				nuthsel();
				break;

			case VK_UP:
			case 0x21:		//page up

				nuthbak(8);			
				break;

			case VK_HOME:

				thumind=0;
				nuthsel();
				break;

			case VK_END:

				thumind=thumcnt;
				nuthbak(4);
				break;

			case 8:			//backspace
			case VK_LEFT:

				bakthum();
				break;

			default:

				TranslateMessage(&msg);
			}
			return 1;
		}
		if(chkMap(FSETFSPAC)||chkMap(GTWLKIND))
		{
			if(cod==189||cod==109)
			{
				*msgbuf='-';
				msgpnt=1;
				msgbuf[1]=0;
				SetWindowText(hgNum,msgbuf);
				return 1;
			}
		}
		if(sidtyp||prfind){
			
			if(chkminus(cod)){

				msgpnt=1;
				sidbuf[0]='-';
				SetWindowText(hSid,sidbuf);
				return 1;
			}
			if(dunum(cod)){

				if(prfind==PSHO+1||prfind==PBOX+1){

					msgbuf[0]=(TCHAR)numcod;
					msgbuf[1]=0;
					if(prfind==PSHO+1){

						shopnts=unthrsh(numcod-0x30);
						SetWindowText(thDat[PSHO],msgbuf);
					}
					else{

						stchboxs=unthrsh(numcod-0x30);
						SetWindowText(thDat[PBOX],msgbuf);
					}
					unsid();
				}
				else{
					
					sidbuf[msgpnt++]=numcod;
					sidbuf[msgpnt]=0;
					SetWindowText(hSid,sidbuf);
				}
				return 1;
			}
			switch(cod){

			case 0x6e://numpat period
			case 0xbe://period

				sidbuf[msgpnt++]='.';
				sidbuf[msgpnt]=0;
				SetWindowText(hSid,sidbuf);
				return 1;

			case 8:	//backspace

				if(msgpnt){

					sidbuf[--msgpnt]=0;
					SetWindowText(hSid,sidbuf);
				}
				return 1;

			case VK_RETURN:

				chknum();
				sidtyp=0;
				prfind=0;
				return 1;
			}
		}
		if(cod=='I'){
			
			movi();
			lastcod='I';
			return 1;
		}
		if(cod=='Q'&&lastcod=='Q')
			unpat();
		lastcod=cod;
		if(chkMap(NUMIN)){

			if(chkMap(SCLPSPAC)&&cod==0xbd&&!msgpnt)
			{
				msgbuf[0]='-';
				msgbuf[1]=0;
				msgpnt=1;
				SetWindowText(hgNum,msgbuf);
				return 1;
			}
			if(dunum(cod)){

				if(chkMap(TRNIN0)){
			
					trinbuf[msgpnt++]=numcod;
					trinbuf[msgpnt]=0;
					ind=atoi(trinbuf);
					switch(msgpnt){

					case 2:

						if(ind>25)
							dutrnum0(ind);
						break;

					case 3:

						if(ind>255)
							ind=255;
						dutrnum0(ind);
						break;
					}
					redraw(htrnum);
				}
				else{

					msgbuf[msgpnt++]=numcod;
					msgbuf[msgpnt]=0;
					SetWindowText(hgNum,msgbuf);
				}
				return 1;
			}
			switch(cod){

			case 0x6e://numpad period
			case 0xbe://period

				msgbuf[msgpnt++]='.';
				msgbuf[msgpnt]=0;
				SetWindowText(hgNum,msgbuf);
				return 1;

			case 8:	//backspace

				if(msgpnt){

					msgpnt--;
					if(chkMap(TRNIN0)){

						trinbuf[msgpnt]=0;
						redraw(htrnum);
					}
					else{

						msgbuf[msgpnt]=0;
						SetWindowText(hgNum,msgbuf);
					}
				}
				return 1;

			case VK_RETURN:

				if(chkMap(TRNIN0))
					dutrnum0(atoi(trinbuf));
				else{

					if(chkMap(TRNIN1))
						dutrnum1();
				}
				break;
			}
		}
		if(cod==8&&numpnt){
		
			numbuf[--numpnt]=0;
			butxt(HNUM,numbuf);
			cloInd=atoi(numbuf);
			movbox();
			return 1;
		}
		if(!chkMap(WASTRAC)&&dunum(cod)){
		
			if(numpnt>stchdigs-1)
				numpnt=0;
			if(numbuf[0]=='0'&&numpnt)
				numpnt--;
			numbuf[numpnt++]=numcod;
			numbuf[numpnt]=0;
			cloInd=atoi(numbuf);
			if(cloInd>(unsigned)hed.stchs-1){

				sprintf(numbuf,"%d",hed.stchs-1);
				cloInd=hed.stchs-1;
			}
			butxt(HNUM,numbuf);
			movbox();
			rstMap(NUMIN);
			return 1;
		}
		numpnt=0;
		unmsg();
		switch(cod){

		case VK_ESCAPE:

thumout:;
			chkbit();
			duhbit(MF_UNCHECKED);
			unthum();
			rstMap(MOVSET);
			rstMap(HID);
			rstMap(FRMOF);
			rstMap(THRDS);
			redraw(hbuts[HHID]);
			CheckMenuItem(hMen,ID_VUTHRDS,MF_BYCOMMAND|MF_UNCHECKED);
			rstMap(COL);
			CheckMenuItem(hMen,ID_VUSELTHRDS,MF_BYCOMMAND|MF_UNCHECKED);
			setMap(DUMEN);
			rstMap(RUNPAT);
			rstMap(WASPAT);
			rstMap(WASBLAK);
			rstMap(GTUANG);
			rstMap(GTUSPAC);
			rstMap(GTWLKIND);
			rstMap(GTWLKLEN);
			DestroyWindow(hSped);
			rstMap(GMRK);

		case 'Q':

			if(GetKeyState(VK_SHIFT)&0x8000){
				
				ritcur();
				return 1;
			}
			untrace();
			rstMap(HIDMAP);
			rstMap(FILDIR);
			ReleaseCapture();
			if(hed.stchs==1)
				hed.stchs=0;
			if(!chku(MARQ))
				rstMap(GMRK);
			if(rstMap(PRFACT)){

				if(rstMap(WASRT)){

					setMap(INSRT);
					setMap(RESTCH);
					return 1;
				}
				else
					rstAll();
			}
			else
				rstAll();
			setMap(RESTCH);
			if(numpnt){
			
				numpnt=0;
				numbuf[0]=0;
				cloInd=0;
				movbox();
			}
			butxt(HNUM,"");
			return 1;

		case 0xc0:		//`

			if(GetKeyState(VK_CONTROL)&0x8000&&GetKeyState(VK_MENU)&0x8000){

				stchBak=0x505050;
				bakPen=nuPen(bakPen,1,stchBak);
				bakwid=1;
				DeleteObject(hStchBak);
				hStchBak=CreateSolidBrush(stchBak);
				if(*bnam)
					bfil();
				setMap(RESTCH);
			}
			else{
#if PESACT
//				ini.auxfil=AUXPES;
//				strcpy(filnam,"u:\\mrd\\t.thr");
//				setMap(REDOLD);
//				nuFil();
//				lodpes();
//				savpes();
#endif

				tst();
			}
			break;

		case VK_INSERT:

			inscol();
			break;

		case 0x6d:		//keypad -

			toglup();
			break;

		case 0xbd:		//-

			rstMap(CNTRH);
			rstMap(CNTRV);
			if(GetKeyState(VK_SHIFT)&0X8000)
				setMap(CNTRV);
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					setMap(CNTRH);
			}
			cntrx();
			break;

		case 0xbf:		///forward slash /

			frmnum();
			break;

		case 0xbb:		//=

			shrnk();
			break;

		case 0x21:		//page up

			if(GetKeyState(VK_SHIFT)&0X8000)
				redup();
			else
				rotagain();
			break;

		case 0x22:		//page down

			if(GetKeyState(VK_SHIFT)&0X8000)
				bakdup();
			else
				bakagain();
			break;

		case 0xde:	//'

			desiz();
			break;

		case 0xdb:		//[

#if LANG==ENG||LANG==HNG

			if(GetKeyState(VK_SHIFT)&0X8000)
				selfrm0();
			else
#endif
				ungrplo();
			break;

		case 0xdd:		//]

#if LANG==ENG||LANG==HNG

			if(GetKeyState(VK_SHIFT)&0X8000)
				selfrmx();
			else
#endif
				ungrphi();
			break;

		case 0xba:		//semicolon

			movmrk();
			break;

		case VK_DOWN:

			if(GetKeyState(VK_CONTROL)&0X8000)
				nudgfn(0,-ini.nudg);
			else
				seldwn();
			break;

		case VK_UP:

			if(GetKeyState(VK_CONTROL)&0X8000)
				nudgfn(0,ini.nudg);
			else
				selup();
			break;

		case 0xbe:		//period

			if(GetKeyState(VK_SHIFT)&0X8000)
				setfilend();
			else
				setmov();
			break;

		case 'W':

			if(GetKeyState(VK_SHIFT)&0X8000)
				crop();
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					pes2crd();
				else
					insat();
			}
			break;

		case 'E':

			if(GetKeyState(VK_SHIFT)&0X8000)
				dutxtfil();
			else
				infrm();
			break;

		case VK_F2:

			snap();
			break;

		case VK_F1:

			help();
			break;

		case VK_F3:

			if(GetKeyState(VK_CONTROL)&0X8000)
				srtfrm();
			else{

				if(GetKeyState(VK_SHIFT)&0X8000)
					srtbyfrm();
				else
					fsort();
			}
			break;

		case VK_F4:

			rtrclp();
			break;

		case VK_F5:

			filfrms();
			break;

		case VK_F6:

			vuthrds();
			break;

		case VK_F7:

			save();
			break;

		case VK_F8:
			
			savAs();
			break;

		case VK_F9:

			selCol();
			break;

		case VK_F11:

			if(GetKeyState(VK_SHIFT)&0X8000)
				rembig();
			else
				duzero();
			break;

		case VK_F12:

			if(GetKeyState(VK_CONTROL)&GetKeyState(VK_MENU)&0X8000)
				reldun();
			else
			{
#ifdef _DEBUG
				if(GetKeyState(VK_SHIFT)&0X8000)
					dmpat();
				else
#endif
					dun();
			}
			break;

		case 'Y':

			if(closfrm())
				selfpnt();
			break;

		case 'O':

			fop();
			break;

		case 'Z':

			if(GetKeyState(VK_SHIFT)&0X8000){

				zumFct=zumflor;
				zumin();
			}
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					bak();
				else
					zumin();
			}
			break;

		case 'X':

			if(GetKeyState(VK_CONTROL)&0X8000)
				cut();
			else{

				if(GetKeyState(VK_SHIFT)&0X8000)
					hidbit();
				else
					zumhom();
			}
			break;

		case 'P':

			prfmsg();
			break;

		case 'N':

		if(GetKeyState(VK_CONTROL)&0X8000)
			nudsiz();
		else
		{
			if(GetKeyState(VK_SHIFT)&0X8000)
				pgdwn();
			else
			{
				setMap(TRCUP);
				trace();
			}
		}
		break;

		case 'U':

			if(GetKeyState(VK_SHIFT)&0X8000)
				pgup();
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					trdif();
				else{

					rstMap(TRCUP);
					trace();
				}
			}
			break;

		case 'H':

			if(GetKeyState(VK_SHIFT)&0X8000)
				pglft();
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					trcsel();
				else
					blak();
			}
			break;

		case 'J':

			if(GetKeyState(VK_SHIFT)&0X8000)
				pgrit();
			else
				refilal();
			break;

		case 0xbc:		//comma

			if(GetKeyState(VK_SHIFT)&0X8000)
				setfilstrt();
			else
			{
				savdo();
				join();
			}
			break;

		case 'B':

			if(GetKeyState(VK_CONTROL)&0X8000)
				redo();
			else{

				if(GetKeyState(VK_SHIFT)&0X8000)
					bakmrk();
				else
					bak();
			}
			break;

		case 'D':

			if(GetKeyState(VK_SHIFT)&0X8000)
			{
				if(chkMap(FORMSEL))
				{
					PostMessage(hWnd,WM_SYSCOMMAND,SC_KEYMENU,'E');
					keybd_event('F',0,0,0);
				}
			}
			else
				satsel();
			break;

		case 'K':

			if(GetKeyState(VK_MENU)&GetKeyState(VK_CONTROL)&0X8000)
				setknots();
			else
			{
				if(GetKeyState(VK_SHIFT)&0X8000)
					tglhid();
				else{

					if(GetKeyState(VK_CONTROL)&0X8000)
						set1knot();
					else
						tglfrm();
				}
			}
			break;

		case 'A':

			if(GetKeyState(VK_CONTROL)&0X8000)
				selalstch();
			else{

				if(GetKeyState(VK_SHIFT)&0X8000)
					selal();
				else
					zumout();
			}
			break;

		case VK_SPACE:

			if(toglMap(INSRT)){
			
				ReleaseCapture();
				setMap(RESTCH);
			}
			else
				istch();
			unbox();
			if(rstMap(GRPSEL)||rstMap(FORMSEL))
				setMap(RESTCH);
			break;

		case 'T':

			if(GetKeyState(VK_SHIFT)&0x8000)
				retrac();
			else{

				if(GetKeyState(VK_CONTROL)&0x8000)
					trinit();
				else
					thumnail();
			}
			break;

		case 'R':
			
			if(GetKeyState(VK_CONTROL)&GetKeyState(VK_SHIFT)&0x8000){

				movStch();
				unbox();
				setMap(RESTCH);
			}
			else{

				if(GetKeyState(VK_CONTROL)&0x8000){

					setrang();
					return 1;
				}
				if(GetKeyState(VK_SHIFT)&0x8000){

					rotmrk();
					return 1;
				}
				else
					rotseg();
			}
			break;

		case VK_TAB:

			rot();
			break;

		case 'S':

			if(GetKeyState(VK_CONTROL)&0X8000){

				colchk();
				save();
			}
			else{

				if(GetKeyState(VK_SHIFT)&0X8000)
					gsnap();
				else
					zumshft();
			}
			break;

		case 'F':

			if(fselpnt)
			{
				PostMessage(hWnd,WM_SYSCOMMAND,SC_KEYMENU,'E');
				keybd_event('F',0,0,0);
			}
			else{

				if(GetKeyState(VK_SHIFT)&0X8000){

					setMap(CNV2FTH);
					ribon();
				}
				else{

					frmon();
					if(chkMap(FORMSEL))
						refrm();
					else
						form();
				}
			}
			break;

		case 'V':

			if(GetKeyState(VK_CONTROL)&0X8000&&OpenClipboard(hWnd)){

				htclp=RegisterClipboardFormat(thredclp);
				hClpMem=GetClipboardData(htclp);
				if(hClpMem){

					clpvoid=GlobalLock(hClpMem);
					fpclpdat=(FPCLP*)clpvoid;
					if(fpclpdat->led==CLP_FRMPS){

						duzrat();
						ind=sizeof(FPCLP)+(fpclpdat->cnt+1)*sizeof(FLPNT);
						MoveMemory(&bseq,clpvoid,ind);
						GlobalUnlock(hClpMem);
						fpclpdat=(FPCLP*)&bseq;
						if(chkMap(FRMPSEL)){

							pchr=(unsigned char*)&bseq;
							fvars(clofind);
							iseq[0].x=flt[clofine].x;
							iseq[0].y=flt[clofine].y;
							clp=(FLPNT*)&fpclpdat[1];
							for(ind=0;ind<=fpclpdat->cnt;ind++){

								iseq[ind+1].x=clp[ind].x;
								iseq[ind+1].y=clp[ind].y;
							}
							ine=nxt(clofine);
							ind++;
							iseq[ind].x=flt[ine].x;
							iseq[ind].y=flt[ine].y;
							opnt=ind+1;
							fplin=(POINT*)&iseq[opnt];
							setpclp();
							setMap(FPUNCLP);
							setMap(SHOP);
							dupclp();
						}
						else{

							fmovdif.x=fmovdif.y=0;
							setMap(FUNCLP);
							clofind=formpnt;
							frmpnt=&formlst[formpnt];
							FillMemory(frmpnt,sizeof(FRMHED),0);
							frmpnt->typ=LIN;
							frmpnt->sids=fpclpdat->cnt+1;
							frmpnt->flt=adflt(frmpnt->sids);
							fvars(clofind);
							MoveMemory(frmpnt->flt,&fpclpdat[1],sizeof(FLPNT)*frmpnt->sids);
							setMap(INIT);
							nuflen=frmpnt->sids;
							unfrm();
							setmfrm();
							setMap(SHOFRM);
							dufrm();
						}
						return 1;
					}
					frmsclpdat=(FRMSCLP*)clpvoid;
					if(frmsclpdat->led==CLP_FRMS){

						funscnt=frmsclpdat->cnt;
						tfrm=(FRMHED*)&frmsclpdat[1];
						for(ind=0;ind<funscnt;ind++){

							frmcpy(&formlst[formpnt+ind],&tfrm[ind]);
							formlst[formpnt+ind].at=(formlst[formpnt+ind].at&NFRMLMSK)|(actl<<1);
						}
						flt=(FLPNT*)&tfrm[ind];
						inf=0;
						for(ind=0;ind<funscnt;ind++){

							frmpnt=&formlst[formpnt+ind];
							frmpnt->flt=adflt(frmpnt->sids);
							for(ine=0;ine<frmpnt->sids;ine++){

								frmpnt->flt[ine].x=flt[inf].x;
								frmpnt->flt[ine].y=flt[inf++].y;
							}
						}
						sac=(SATCON*)&flt[inf];
						inf=0;
						for(ind=0;ind<funscnt;ind++){

							frmpnt=&formlst[formpnt+ind];
							if(frmpnt->typ==SAT&&frmpnt->stpt){

								frmpnt->sacang.sac=adsatk(frmpnt->stpt);
								for(ine=0;ine<frmpnt->stpt;ine++){

									frmpnt->sacang.sac[ine].strt=sac[inf].strt;
									frmpnt->sacang.sac[ine].fin=sac[inf++].fin;
								}
							}
						}
						clp=(FLPNT*)&sac[inf];
						inf=0;
						for(ind=0;ind<funscnt;ind++){

							frmpnt=&formlst[formpnt+ind];
							if(isclpx(formpnt+ind)){

								frmpnt->angclp.clp=adclp(frmpnt->flencnt.nclp);
								for(ine=0;(unsigned)ine<frmpnt->flencnt.nclp;ine++){

									frmpnt->angclp.clp[ine].x=clp[inf].x;
									frmpnt->angclp.clp[ine].y=clp[inf++].y;
								}
							}
							if(iseclpx(formpnt+ind)){

								frmpnt->clp=adclp(frmpnt->nclp);
								for(ine=0;ine<frmpnt->nclp;ine++){

									frmpnt->clp[ine].x=clp[inf].x;
									frmpnt->clp[ine].y=clp[inf++].y;
								}
							}
						}
						pts=(TXPNT*)&clp[inf];
						ptx=&txpnts[txad];
						ine=0;
						for(ind=0;ind<funscnt;ind++)
						{
							if(istx(formpnt+ind))
							{
								frmpnt=&formlst[formpnt+ind];
								ine+=frmpnt->dhx.txt.cnt;
								frmpnt->dhx.txt.ind+=txad;
								MoveMemory(ptx,pts,(frmpnt->dhx.txt.ind+frmpnt->dhx.txt.cnt-txad)*sizeof(TXPNT));
							}
						}
						txad+=ine;
						GlobalUnlock(hClpMem);
						bigrct.top=bigrct.left=0x7fffffff;
						bigrct.bottom=bigrct.right=0;
						ratsr();
						for(opnt=0;opnt<(unsigned)funscnt;opnt++){

							fselrct(opnt+formpnt);
							selist[opnt]=opnt+formpnt;
						}
						fselpnt=funscnt;
						bigsiz.x=bigrct.right-bigrct.left;
						bigsiz.y=bigrct.bottom-bigrct.top;
						setMap(INIT);
						flin[0].x=flin[3].x=flin[4].x=bigrct.left;
						flin[1].x=flin[2].x=bigrct.right;
						flin[0].y=flin[1].y=flin[4].y=bigrct.top;
						flin[2].y=flin[3].y=bigrct.bottom;
						setMap(SHOSTRTCH);
						strtchbox();
						fmovdif.x=((bigrct.right-bigrct.left)>>1);
						fmovdif.y=((bigrct.bottom-bigrct.top)>>1);
						setMap(MOVFRMS);
						setMap(FUNSCLP);
					}
					else{

						frmclpdat=(FRMCLP*)clpvoid;
						if(frmclpdat->led==CLP_FRM){
						
							fmovdif.x=fmovdif.y=0;
							setMap(FUNCLP);
							clofind=formpnt;
							fvars(formpnt);
							frmcpy(&formlst[formpnt],&frmclpdat->frm);
							formlst[formpnt].at=(formlst[formpnt].at&NFRMLMSK)|(actl<<1);
							frmpnt->flt=adflt(formlst[formpnt].sids);
							flt=(FLPNT*)&frmclpdat[1];
							mvflpnt(&frmpnt->flt[0],&flt[0],frmpnt->sids);
							sac=(SATCON*)&flt[frmpnt->sids];
							ind=0;
							if(frmpnt->typ==SAT&&frmpnt->stpt){

								frmpnt->sacang.sac=adsatk(frmpnt->stpt);
								mvsatk(&frmpnt->sacang.sac[0],&sac[0],frmpnt->stpt);
							}
							clp=(FLPNT*)&sac[ind];
							inf=0;
							if(isclpx(formpnt)){

								frmpnt->angclp.clp=adclp(frmpnt->flencnt.nclp);
								mvflpnt(frmpnt->angclp.clp,clp,frmpnt->flencnt.nclp);
								inf+=frmpnt->flencnt.nclp;
							}
							if(iseclpx(formpnt)){

								clp=(FLPNT*)&clp[inf];
								frmpnt->clp=adclp(frmpnt->nclp);
								mvflpnt(frmpnt->clp,clp,frmpnt->nclp);
								inf+=frmpnt->nclp;
							}
							pts=(TXPNT*)&clp[inf];
							if(istx(formpnt))
							{
								frmpnt->dhx.txt.ind=txad;
								ptx=adtx(frmpnt->dhx.txt.cnt);
								MoveMemory(ptx,pts,frmpnt->dhx.txt.cnt*sizeof(TXPNT));
							}
						}
						GlobalUnlock(hClpMem);
						setMap(INIT);
						nuflen=frmpnt->sids;
						if(frmpnt->typ!=LIN)
							nuflen++;
						unfrm();
						duzrat();
						setmfrm();
						setMap(SHOFRM);
						dufrm();
					}
				}
				else{

					hClip=RegisterClipboardFormat(pcdClip);
					hClpMem=GetClipboardData(hClip);
					if(hClpMem){

						redclp();
						clpbox();
						setMap(CLPSHO);
					}
				}
				CloseClipboard();
			}
			else
				closPnt();
			break;

		case 'C':

			if(GetKeyState(VK_CONTROL)&0X8000)
				duclip();
			else{

				if(GetKeyState(VK_SHIFT)&0X8000){

					rstMap(CNV2FTH);
					ribon();
				}
				else{
				
					rstMap(HIDSTCH);
					setMap(IGNTHR);
					rebox();
					rstMap(IGNTHR);
					setMap(RESTCH);
				}
			}
			break;

		case VK_HOME:

			if(GetKeyState(VK_SHIFT)&0X8000&&GetKeyState(VK_CONTROL)&0X8000){

				if(rstMap(SELBOX)){

					grpInd=0;
					dubx();
					setMap(GRPSEL);
				}
				else{

					if(chkMap(GRPSEL)){

						if(grpInd>cloInd)
							cloInd=0;
						else
							grpInd=0;
					}
					else{

						setMap(SELBOX);
						setMap(RESTCH);
					}
				}
				grpAdj();
				redraw(hBar);
				return 1;
			}
			if(GetKeyState(VK_SHIFT)&0X8000){
	
				if(rstMap(SELBOX)){

					dubx();
					setMap(GRPSEL);
					ind=pt2colInd(cloInd);
				}
				else
					ind=pt2colInd(grpInd);
				ind--;
				grpInd=colch[ind].stind;
				grpAdj();
				redraw(hBar);
			}
			else{

				if(GetKeyState(VK_CONTROL)&0X8000){

					stch2px1(0);
					endpnt();
					rstMap(BAKEND);
					setMap(RESTCH);
				}
				else{

					if(chkMap(SELBOX)){

						ind=pt2colInd(cloInd);
						if(ind)
							ind--;
						cloInd=colch[ind].stind;
					}
					else{

						if(chkMap(LENSRCH)){

							setsrch(minpnt);
							return 1;
						}
						else
							cloInd=0;
					}
					movbox();
				}
			}
			break;

		case VK_END:

			if(GetKeyState(VK_SHIFT)&0X8000&&GetKeyState(VK_CONTROL)&0X8000){

				if(rstMap(SELBOX)){

					grpInd=hed.stchs-1;
					dubx();
					setMap(GRPSEL);
				}
				else{

					if(chkMap(GRPSEL)){

						if(grpInd>cloInd)
							grpInd=hed.stchs-1;
						else
							cloInd=hed.stchs-1;
					}
					else{

						setMap(SELBOX);
						cloInd=hed.stchs-1;
						setMap(RESTCH);
						return 1;
					}
				}
				grpAdj();
				redraw(hBar);
				break;
			}
			if(GetKeyState(VK_SHIFT)&0X8000){
	
				if(rstMap(SELBOX)){

					dubx();
					setMap(GRPSEL);
					ind=pt2colInd(cloInd);
				}
				else
					ind=pt2colInd(grpInd);
				grpInd=colch[ind].stind-1;
				grpAdj();
				redraw(hBar);
			}
			else{

				if(GetKeyState(VK_CONTROL)&0X8000){

					stch2px1(hed.stchs-1);
					endpnt();
					setMap(BAKEND);
					setMap(RESTCH);
				}
				else{
							
					if(chkMap(SELBOX)){

						ind=pt2colInd(cloInd);
						cloInd=colch[ind].stind-1;
					}
					else{

						if(chkMap(LENSRCH)){

							setsrch(maxpnt);
							return 1;
						}
						else
							cloInd=hed.stchs-1;
					}
					movbox();
				}
			}
			break;

		case VK_RIGHT:

			fvars(clofind);
			if(GetKeyState(VK_SHIFT)&0X8000){

				if(chkMap(FPSEL)){

					if(chkMap(PSELDIR)){

						++pselrng.cnt%=sids;
						pselrng.fin=(pselrng.strt+pselrng.cnt)%sids;
					}
					else{

						if(pselrng.cnt){

							pselrng.cnt--;
							pselrng.fin=(pselrng.strt+sids-pselrng.cnt)%sids;
						}
						else{

							pselrng.cnt=1;
							setMap(PSELDIR);
							pselrng.fin=(pselrng.strt+1)%sids;
						}
					}
					setpsel();
				}
				else{

					if(rstMap(FRMPSEL)){
				
						unpsel();
						pselrng.strt=clofine;
						pselrng.frm=clofind;
						pselrng.cnt=1;
						pselrng.fin=(pselrng.strt+1)%sids;
						setMap(PSELDIR);
						setpsel();
					}
					else{
					
						rstMap(LENSRCH);
						rstMap(FORMSEL);
						if(rstMap(SELBOX)){

							dubx();
							if(cloInd<(unsigned)hed.stchs-1){
								
								setMap(GRPSEL);
								grpInd=cloInd+1;
							}
						}
						else{

							if(grpInd<(unsigned)hed.stchs-1){

								grpInd++;
								nuAct(grpInd);
							}
						}
						grpAdj();
						redraw(hBar);
					}
				}
			}
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					nudgfn(ini.nudg,0);
				else{

					if(chkMap(LENSRCH)){

						longer();
						setMap(RESTCH);
					}
					else{

						if(chkMap(FRMPSEL)){

							fvars(clofind);
							clofine=nxt(clofine);
							ritnum(STR_NUMPNT,clofine);
							ritfcor(&formlst[clofind].flt[clofine]);
							shftflt(formlst[clofind].flt[clofine]);
							setMap(RESTCH);
						}
						else{

							if(chkMap(SELBOX)){

								if(cloInd<(unsigned)hed.stchs-1)
									cloInd++;
								movbox();
								return 1;
							}
							if(chkMap(GRPSEL)){

								if(grpInd<(unsigned)hed.stchs-1){

									grpInd++;
									grpAdj();
									redraw(hBar);
								}
							}
						}
					}
				}
			}
			break;

		case VK_LEFT:

			if(GetKeyState(VK_SHIFT)&0X8000){

				if(chkMap(FPSEL)){

					if(!chkMap(PSELDIR)){

						++pselrng.cnt%=sids;
						pselrng.fin=(pselrng.strt+sids-pselrng.cnt)%sids;
					}
					else{

						if(pselrng.cnt){

							pselrng.cnt--;
							pselrng.fin=(pselrng.strt+sids-pselrng.cnt)%sids;
						}
						else{

							pselrng.cnt=1;
							pselrng.fin=(pselrng.strt+sids-1)%sids;
							rstMap(PSELDIR);
						}
					}
					setpsel();
				}
				else{

					if(rstMap(FRMPSEL)){
				
						unpsel();
						pselrng.strt=clofine;
						pselrng.cnt=1;
						rstMap(PSELDIR);
						setpsel();
					}
					else{

						rstMap(LENSRCH);
						rstMap(FORMSEL);
						if(rstMap(SELBOX)){

							dubx();
							setMap(GRPSEL);
							grpInd=cloInd-1;
						}
						else
							if(grpInd){

								grpInd--;
								nuAct(grpInd);
							}
						grpAdj();
						redraw(hBar);
					}
				}
			}
			else{

				if(GetKeyState(VK_CONTROL)&0X8000)
					nudgfn(-ini.nudg,0);
				else{

					if(chkMap(LENSRCH)){

						shorter();
						setMap(RESTCH);
					}
					else{

						if(chkMap(FRMPSEL)){

							fvars(clofind);
							clofine=prv(clofine);
							ritnum(STR_NUMPNT,clofine);
							ritfcor(&formlst[clofind].flt[clofine]);
							shftflt(formlst[clofind].flt[clofine]);
							setMap(RESTCH);
						}
						else{

							if(chkMap(SELBOX)){

								if(cloInd)
									cloInd--;
								movbox();
								return 1;
							}
							if(chkMap(GRPSEL)){

								if(grpInd){

									grpInd--;
									grpAdj();
									redraw(hBar);
								}
							}
						}
					}
				}
			}
			break;

		case 'G':

			mark();
			break;

		case 'M':

			if(GetKeyState(VK_CONTROL)&0x8000)
				pntmrk();
			else{

				if(GetKeyState(VK_SHIFT)&0X8000)
					dumrk(zum0.x/2,zum0.y/2);
				else{
					
					if(px2stch())
						dumrk(sPnt.x,sPnt.y);
				}
				setMap(RESTCH);
			}
			break;

		case 'L':

			if(GetKeyState(VK_SHIFT)&0x8000)
				delstch();
			else
				fcntr();
			break;

		case VK_DELETE:

			if(chkMsgs(msg.pt,hDef[0],hDef[15]))
				delcol();
			else
				delet();
			break;
		}
		break;

	case WM_COMMAND:

		unmsg();
		if(chkMap(FORMSEL))
			fvars(clofind);
		for(ind=0;ind<OLDNUM;ind++){

			if(msg.wParam==fmenid[ind]){

				strcpy(filnam,ini.oldnams[ind]);
				setMap(REDOLD);
				nuFil();
			}
		}
		ind=LOWORD(msg.wParam);
		if(ind>40000&&ind<40400)
			undat();
		switch(LOWORD(msg.wParam)){

		case ID_CHKOF:

			chgchk(0);
			break;

		case ID_CHKON:

			chgchk(1);
			break;

		case ID_CHKREP:

			chgchk(2);
			break;

		case ID_CHKREPMSG:

			chgchk(3);
			break;

		case ID_REPAIR:

			repar();
			break;

		case ID_WARNOF:

			chgwrn();
			break;

		case ID_CLPSPAC:

			setclpspac();
			break;

		case ID_FRMIND:

			setfind();
			break;

		case ID_SETSIZ:

			nudsiz();
			break;

		case ID_TXFIL:

			dutxtfil();
			break;

		case ID_FRMHI:

			setfhi();
			break;

		case ID_FRMWID:

			setfwid();
			break;

		case ID_MAXFLEN:

			setfmax();
			break;

		case ID_MINFLEN:

			setfmin();
			break;

		case ID_MAXBLEN:

			setbmax();
			break;

		case ID_MINBLEN:

			setbmin();
			break;

		case ID_SETBSPAC:

			setbspac();
			break;

		case ID_SETBLEN:

			setblen();
			break;

		case ID_SETBCOL:

			setbcol();
			break;

		case ID_SETFCOL:

			setfcol();
			break;

		case ID_SETUCOL:

			setucol();
			break;

		case ID_SETFANG:

			setfang();
			break;

		case ID_SETFSPAC:

			setfspac();
			break;

		case ID_SETFLEN:

			setflen();
			break;

		case ID_SETUANG:

			sfuang();
			break;

		case ID_SETUSPAC:

			uspac();
			break;

		case ID_UNDLEN:

			undlen();
			break;

		case ID_SETCWLK:

			setcwlk();
			break;

		case ID_SETWLK:

			setwlk();
			break;

		case ID_SETUND:

			setund();
			break;

		case ID_NOTCWLK:

			notcwlk();
			break;

		case ID_NOTWLK:

			notwlk();
			break;

		case ID_NOTUND:

			notund();
			break;

		case ID_SELUND:

			selfil(UNDMSK);
			break;

		case ID_SELWLK:

			selfil(WLKMSK);
			break;

		case ID_ALFRM:

			selalfrm();
			break;

		case ID_USPAC:

			setuspac();
			break;

		case ID_UANG:

			setuang();
			break;

		case ID_USTCH:

			setulen();
			break;

		case ID_WIND:

			setwlkind();
			break;

		case ID_FILSTRT:

			setfilstrt();
			break;

		case ID_FILEND:

			setfilend();
			break;

		case ID_PES2CRD:
		
			pes2crd();
			break;

		case ID_2FTHR:

			setMap(CNV2FTH);
			ribon();
			break;

		case ID_FETHR:

			fethr();
			break;

		case ID_FTHDEF:

			dufdef();
			break;

		case ID_SRTF:

			srtfrm();
			break;

		case ID_FILCLPX:

			filclpx();
			break;

		case ID_FRMX:

			frmcursel(1);
			break;

		case ID_FRMBOX:

			frmcursel(0);
			break;

		case ID_KNOTAT:

			set1knot();
			break;

		case ID_STCHPIX:

			getstpix();;
			break;

		case ID_FRMPIX:

			getfrmpix();
			break;

		case ID_FRMPBOX:

			getfrmbox();
			break;

		case ID_CROP:

			crop();
			break;

		case ID_BAKMRK:

			bakmrk();
			break;

		case ID_MARKESC:

			setu(MARQ);
			qchk();
			break;

		case ID_MARKQ:

			rstu(MARQ);
			qchk();
			break;

		case ID_NUDGPIX:

			getnpix();
			break;

		case ID_LINCHN:

			setMap(LINCHN);
			chain();
			break;

		case ID_OPNCHN:

			rstMap(LINCHN);
			chain();
			break;

		case ID_CLOSE:

			filclos();
			break;

		case ID_DELMAP:

			delmap();
			break;

		case ID_BLAK:

			blak();
			break;

		case ID_SAVMAP:

			savmap();
			break;

		case ID_TRDIF:

			trdif();
			break;

		case ID_TRACEDG:

			tracedg();
			break;

		case ID_TRCSEL:

			trcsel();
			break;

		case ID_TRACE:

			trinit();
			break;

		case ID_FLOK:

			lock();			
			break;

		case ID_ROTAUXON:

			rotauxsel(1);
			break;

		case ID_ROTAUXOFF:

			rotauxsel(0);
			break;

		case ID_FRM2COL:

			col2frm();
			break;

		case ID_SNAP2GRD:

			gsnap();
			break;

		case ID_FIL2SEL_ON:

			fil2sel(1);
			break;

		case ID_FIL2SEL_OFF:

			fil2sel(0);
			break;

		case ID_OVRLAY:

			ovrlay();
			break;

		case ID_GRDHI:

			setgrd(HIGRD);
			break;

		case ID_GRDMED:

			setgrd(MEDGRD);
			break;

		case ID_GRDEF:

			setgrd(DEFGRD);
			break;

		case ID_GRDRED:

			setgrd(REDGRD);
			break;

		case ID_GRDBLU:

			setgrd(BLUGRD);
			break;

		case ID_GRDGRN:

			setgrd(GRNGRD);
			break;

		case ID_RETRACE:

			retrac();
			break;

		case ID_DUBFIL:

			dubfil();
			break;

		case ID_HORCLP:

			if(chkMap(FORMSEL)||fselpnt)
				savdo();
			horclp();
			break;

		case ID_ANGCLP:

			if(chkMap(FORMSEL)||fselpnt)
				savdo();
			angclp();
			break;

		case ID_VRTCLP:

			if(chkMap(FORMSEL)||fselpnt)
				savdo();
			vrtclp();
			break;

		case ID_LINBEXACT:

			rstu(LINSPAC);
			linbmen();
			break;

		case ID_LINBEVEN:

			setu(LINSPAC);
			linbmen();
			break;

		case ID_BSAVON:

			pcsbsavon();			
			break;

		case ID_BSAVOF:

			pcsbsavof();
			break;

		case ID_KNOTON:

			shoknot();
			break;

		case ID_KNOTOF:

			hidknot();
			break;

		case ID_DELKNOT:

			delknot();
			break;

		case ID_RSTNEDL:

			nedof();
			break;

		case ID_SETNEDL:

			nedon();
			break;

		case ID_STCHS2FRM:

			stchs2frm();
			break;

		case ID_SPLTFRM:

			spltfrm();
			break;

		case ID_UNBEAN:

			debean();
			break;

		case ID_DUBEAN:

			dubean();
			break;

		case ID_SRTBF:

			srtbyfrm();
			break;

		case ID_CENTIRE:

			centir();
			break;

		case ID_CNTRX:

			rstMap(CNTRH);
			rstMap(CNTRV);
			cntrx();
			break;

		case ID_CNTRH:

			rstMap(CNTRH);
			setMap(CNTRV);
			cntrx();
			break;

		case ID_CNTRV:

			setMap(CNTRH);
			rstMap(CNTRV);
			cntrx();
			break;

		case ID_FRMNUM:

			frmnum();
			break;

		case ID_REFILF:

			filfrms();
			break;

		case ID_MRKPNT:

			pntmrk();
			break;

		case ID_ROTSEG:

			rotseg();
			break;

		case ID_ROTMRK:

			rotmrk();
			break;

		case ID_MRKCNTR:

			dumrk(zum0.x/2,zum0.y/2);
			setMap(RESTCH);
			break;

		case ID_SETROT:

			setrang();
			break;

		case ID_SETPREF:

			defpref();
			break;

		case ID_SHRINK:

			shrnk();
			break;

		case ID_DUPAGAIN:

			redup();
			break;

		case ID_CLPADJ:

			clpadj();
			break;

		case ID_DELTOT:

			deltot();
			break;

		case ID_AUXPCS:

			setpcs();
			break;

		case ID_AUXDST:

			setdst();
			break;

		case ID_ABOUT:

			tabmsg(IDS_CPYRIT);
			break;

		case ID_RIBON:

			rstMap(CNV2FTH);
			ribon();
			break;

		case ID_DESIZ:

			desiz();
			break;

		case ID_HLP:

			help();
			break;

		case ID_CNTR:

			fcntr();
			break;

		case ID_INSFIL:

			rstMap(IGNORINS);
			insfil();
			break;

		case ID_SELALSTCH:

			selalstch();
			break;

		case ID_UNGRPLO:

			ungrplo();
			break;

		case ID_UNGRPHI:

			ungrphi();
			break;

		case ID_CONTF:

			contfil();
			break;

		case ID_THUM:

			thumnail();
			break;

		case ID_PICOT:

			picot();
			break;

		case ID_FILBUT:

			bhol();
			break;

		case ID_REMBIG:

			rembig();
			break;

		case ID_VUSELTHRDS:

			vuselthr();
			break;

		case ID_VUTHRDS:

			vuthrds();
			break;

		case ID_MOVMRK:

			movmrk();
			break;

		case ID_SELFIL:

			selfil(FRMFIL);
			break;

		case ID_SELBRD:

			selfil(FRMBFIL);
			break;

		case ID_SELAP:

			selfil(FRMAPFIL);
			break;

		case ID_SELFSTCHS:

			selalfil();
			break;

		case ID_SETMRK:

			setmov();
			break;

		case ID_DELFRE:

			delfre();
			break;

		case ID_SELAL:

			selal();
			break;

		case ID_REFILAL:

			refilal();
			break;

		case ID_CHK:

			chkrng(&rngsiz);
			setMap(RESTCH);
			break;

		case ID_RTRVCLP:

			rtrclp();
			break;

		case ID_SORT:

			fsort();
			break;

		case ID_LAYMOV0:

			movlayr(0);
			break;

		case ID_LAYMOV1:

			movlayr(2);
			break;

		case ID_LAYMOV2:

			movlayr(4);
			break;

		case ID_LAYMOV3:

			movlayr(6);
			break;

		case ID_LAYMOV4:

			movlayr(8);
			break;

		case ID_LAYCPY0:

			cpylayr(0);
			break;

		case ID_LAYCPY1:

			cpylayr(2);
			break;

		case ID_LAYCPY2:

			cpylayr(4);
			break;

		case ID_LAYCPY3:

			cpylayr(6);
			break;

		case ID_LAYCPY4:

			cpylayr(8);
			break;

		case ID_LA:

			nulayr(0);
			break;

		case ID_L1:

			nulayr(1);
			break;

		case ID_L2:

			nulayr(2);
			break;

		case ID_L3:

			nulayr(3);
			break;

		case ID_L4:

			nulayr(4);
			break;

		case ID_ROTDUP:

			rotdup();
			break;

		case ID_ROTAGAIN:

			rotagain();
			break;

		case ID_ROTCMD:

			rotcmd();
			break;

		case ID_DELFRMS:

			delfrms();
			rstAll();
			setMap(RESTCH);
			break;

		case ID_SNAP2:

			snap();
			break;

		case ID_CLPFIL:

			clpfil();
			break;

		case ID_FLPORD:

			flpord();
			break;

		case ID_FRMOF:

			if(GetKeyState(VK_SHIFT)&0X8000)
				tglhid();				
			else
				tglfrm();
			break;

		case ID_MV2BAK:

			mv2b();
			break;

		case ID_MV2FRNT:

			mv2f();
			break;

		case ID_PERP:

			if(chkMap(FORMSEL)||fselpnt)
				savdo();
			prpbrd(stspace);
			break;

		case ID_PURGDIR:

			purgdir();
			break;

		case ID_PURG:

			purg();
			break;

		case ID_VUBAK:

			vubak();
			break;

		case ID_DELETE:

			delet();
			break;

		case ID_FLIPH:

			fliph();
			break;

		case ID_FLIPV:

			flipv();
			break;

		case ID_FILANG:

			if(chkMap(FORMSEL))
				savdo();
			filangl();
			break;

		case ID_PREF:

			prfmsg();
			break;

		case ID_BOLD:

			if(chkMap(FORMSEL)||fselpnt)
				savdo();
			dubold();
			break;

		case ID_ADEND:

			stch2px1(hed.stchs-1);
			endpnt();
			setMap(BAKEND);
			setMap(RESTCH);
			break;

		case ID_SETAP:

			setap();
			break;

		case ID_APLIQ:

			if(chkMap(FORMSEL))
				savdo();
			apliq();
			break;

		case ID_SATBRD:

			if(chkMap(FORMSEL))
				savdo();
			satbrd();
			break;

		case ID_FILCLP:

			fclp();
			break;

		case ID_FILIN:

			if(chkMap(FORMSEL))
				savdo();
			bord();
			break;

		case ID_FRM0:

			frm0();
			break;

		case ID_REDO:

			redo();
			break;

		case ID_UNFIL:

			savdo();
			unfil();
			coltab();
			setMap(RESTCH);
			break;

		case ID_FORM:

			frmon();
			if(chkMap(FORMSEL))
				refrm();
			else
				form();
			break;

		case ID_FILSAT:

			rstMap(FTHR);
			filsat();
			break;

		case ID_OPNPCD:

			switch(ini.auxfil){

			case AUXDST:

				ofn.nFilterIndex=3;
				break;

			default:

				ofn.nFilterIndex=2;
			}
			nuFil();
			nulayr(0);
			break;

		case ID_DELSTCH:

			delstch();
			break;

		case ID_FILL_VERT:

			if(chkMap(FORMSEL)||fselpnt)
				savdo();
			filvrt();
			break;

		case ID_FILL_HOR:

			if(chkMap(FORMSEL))
				savdo();
			filhor();
			break;

		case ID_RUNPAT:

			movi();
			break;

		case ID_LENDEF:

			ini.maxsiz=MAXSIZ*PFGRAN;
			usesiz=USESIZ*PFGRAN;
			minsiz=MINSIZ*PFGRAN;
			break;

		case ID_TSIZDEF:

			tsiz30=TSIZ30;
			tsiz40=TSIZ40;
			tsiz60=TSIZ60;
			break;

		case ID_SIZ30:

			tsizmsg("30",tsiz30);
			setMap(ENTR30);
			break;

		case ID_SIZ40:

			tsizmsg("40",tsiz40);
			setMap(ENTR40);
			break;

		case ID_SIZ60:

			tsizmsg("60",tsiz60);
			setMap(ENTR60);
			break;
	
		case ID_HIDBITF:
		case ID_HIDBIT:

			hidbit();
			break;

		case ID_LODBIT:

			lodbmp();
			break;

		case ID_KNOTS:

			setknots();
			break;
		
		case ID_REMZERO:

			duzero();
			break;

		case ID_ROT:

			rot();
			break;

		case ZUMIN:

			if(chkMap(GMRK)||chkMap(SELBOX)||chkMap(INSRT)||chkMap(GRPSEL)||chkMap(FORMSEL))
				zumin();
			else{

				rstMap(BZUM);
				setMap(BOXZUM);
				rstMap(BZUMIN);
				setMap(VCAPT);
				SetCapture(hWnd);
			}
			break;

		case ID_ZUMOUT:

			zumout();
			break; 

		case ID_FILE_OPEN1:

			fop();
			break;

		case ID_VIEW_STCHBAK:

			if(nuBak()){

				stchBak=bCol.rgbResult;
				bakPen=nuPen(bakPen,1,stchBak);
				bakwid=1;
				DeleteObject(hStchBak);
				hStchBak=CreateSolidBrush(stchBak);
				if(*bnam)
					bfil();
				zumhom();
			}
			break;

		case ID_BITCOL:

			if(nuBit()){

				bitCol=fswap(btCol.rgbResult);
				if(*bnam)
					bfil();
				bitPen=nuPen(bitPen,1,bitCol);
				zumhom();
			}
			break;

		case ID_FILE_SAVE3:

			colchk();
			savAs();
			break;

		case ID_EDIT_RESET_COL:

			for(ind=0;ind<16;ind++){

				useCol[ind]=defCol[ind];
				hbrUseCol[ind]=nuBrush(hbrUseCol[ind],useCol[ind]);
				uPen[ind]=nuPen(uPen[ind],1,useCol[ind]);
				redraw(hCol[ind]);
			}
			setMap(RESTCH);
			break;

		case ID_FILE_SAVE2:

			colchk();
			save();
			break;

		case VU_ZUMFUL:

			zumhom();
			break;

		case ID_EDIT_SELECTCOLOR:

			selCol();
			break;

		case ID_FILE_NEW1:

			if(!savcmp()){

				savdisc();
				setMap(NEWBAK);
				rstMap(PRFACT);
				undat();
			}
			else{

				newFil();
				nulayr(0);
			}
			break;

		case ID_BACK:

			bak();
			break;

		case ID_DESNAM:

			getdes();
			break;
		}
		break;
	}
	return 0;
}

//return the width of a text item
int txtWid(TCHAR* str){

	GetTextExtentPoint32(mdc,str,strlen(str),&txSiz);
	return txSiz.cx;
}

void makCol(){

	unsigned	ind;
	TCHAR		buf[3];

	buf[1]='0';
	buf[2]=0;
	for(ind=0;ind<16;ind++){

		hDef[ind]=CreateWindow(
			"STATIC",
			0,
			SS_OWNERDRAW|WS_CHILD|WS_VISIBLE|WS_BORDER,
			0,
			buttonHi*ind,
			buttonWid,
			buttonHi,
			hWnd,
			NULL,
			hInst,
			NULL);

		hCol[ind]=CreateWindow(
			"STATIC",
			0,
			SS_OWNERDRAW|WS_CHILD|WS_VISIBLE|WS_BORDER,
			buttonWid,
			buttonHi*ind,
			buttonWid,
			buttonHi,
			hWnd,
			NULL,
			hInst,
			NULL);

		buf[0]=thrdSiz[ind][0];
		hSiz[ind]=CreateWindow(
			"STATIC",
			buf,
			SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER,
			buttonWid<<1,
			buttonHi*ind,
			buttonWid,
			buttonHi,
			hWnd,
			NULL,
			hInst,
			NULL);
	}
}

void int2tim(ULARGE_INTEGER num,FILETIME* tim){

	tim->dwHighDateTime=num.HighPart;
	tim->dwLowDateTime=num.LowPart;
}

void ritloc(){

	TCHAR*			penv;
	TCHAR			locnam[MAX_PATH];
	HANDLE			hloc;
	unsigned int 	rot;

	penv=getenv("COMSPEC");
	if(penv)
		strcpy(locnam,penv);
	else
		return;
	penv=strrchr(locnam,'\\')+1;
	strcpy(penv,"thredloc.txt");
	hloc=CreateFile(locnam,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
	*phom=0;
	WriteFile(hloc,(TCHAR*)homdir,strlen(homdir)+1,&rot,0);
	CloseHandle(hloc);
}

void renam(){

	unsigned	ind;
	TCHAR		chr;
	
	for(ind=0;ind<50;ind++){

		chr=rencod[(unsigned char)cryptkey[namloc[ind]]-120];
		if(chr)
			ini.desnam[ind]=chr;
		else
			break;
	}
	ini.desnam[ind]=0;
}

static inline void delsubl (unsigned *&dst,
                            unsigned val,
			    unsigned cnt) {
	for (unsigned i = 0; i < cnt; i++) {
		*(dst++) = bswap_32(val);

		val <<= 1;
	}
}
static inline void delsubr (unsigned *&dst,
                            unsigned val,
			    unsigned cnt) {
	for (unsigned i = 0; i < cnt; i++) {
		*(dst++) = bswap_32(val);

		val >>= 1;
	}
}

static inline void delsubt (unsigned *&dst, 
			    unsigned *src, 
			    unsigned cnt) {

	for (unsigned i = 0; i < cnt; i++) {
		*(dst++) = bswap_32(*(src++));
	}
}

void ducurs(unsigned char* z){
	unsigned *pnt = (unsigned *) z;
	unsigned *dst = pnt;
	for (int i = 0; i < 32; i++) {
		*(dst++) = 0x100;
	}
	

	dst = pnt + 16;

	*dst = 0xffffffff;

	dst += 8;

	*dst = 0x00ffff00;

	dst -= 16;

	*dst = 0x00ffff00;

	for (int i = 0; i < 16; i++) {
		*(dst++) |= 0x00018000;
	}

	pnt += 32;
	dst = pnt;

	unsigned ltor = 0x80000000;
	unsigned rtol = 0x00000001;

	for (int i = 0; i < 32; i++) {
		*(dst++) = bswap_32(ltor | rtol | 0x80000001);

		rtol <<=1;
		ltor >>=1;
	}

	*(--dst) = 0xffffffff;
	*pnt = 0xffffffff;

	pnt += 32;
	dst = pnt;

	for (int i = 0; i < 24; i++) {
		*(dst++) = bswap_32(0x0003c000);
	}

	for (int i = 0; i < 5; i++) {
		*(dst++) = bswap_32(0x00024000);
	}

	for (int i = 0; i < 2; i++) {
		*(dst++) = bswap_32(0x00018000);
	}


	pnt += 32;
	dst = pnt;

	delsubt(dst, lucurstrt, 5);

	delsubl(dst, 0x88, 4);
	delsubl(dst, 0x1f00, 19);

	delsubt(dst, lucurfin, 3);


	pnt += 32;
	dst = pnt;

	delsubt(dst, ldcurstrt, 4);

	delsubr(dst, 0x7c000000, 19);
	delsubr(dst, 0x440, 4);

	delsubt(dst, ldcurfin, 5);

	pnt += 32;
	dst = pnt;

	delsubt(dst, rucurstrt, 5);

	delsubr(dst, 0x9000000, 4);
	delsubr(dst, 0x1f00000, 19);

	delsubt(dst, rucurfin, 3);


	pnt += 32;
	dst = pnt;

	delsubt(dst, rdcurstrt, 4);

	delsubl(dst, 0xf8, 19);
	delsubl(dst, 0x8400000, 4);

	delsubt(dst, rdcurfin, 5);
}

void duamsk(){
	memset(amsk, 0xff, 128);
}

void crtcurs(){

	duamsk();
	ducurs(curs.frm);
	hfrm=CreateCursor(hInst,16,16,32,32,(void*)amsk,(void*)&curs.frm);
	hdlin=CreateCursor(hInst,16,16,32,32,(void*)amsk,(void*)&curs.dlin);
	hnedu=CreateCursor(hInst,16,32,32,32,(void*)amsk,(void*)&curs.uned);
	hnedrd=CreateCursor(hInst,1,31,32,32,(void*)amsk,(void*)&curs.rdned);
	hnedru=CreateCursor(hInst,1,1,32,32,(void*)amsk,(void*)&curs.runed);
	hnedld=CreateCursor(hInst,30,30,32,32,(void*)amsk,(void*)&curs.ldned);
	hnedlu=CreateCursor(hInst,32,1,32,32,(void*)amsk,(void*)&curs.luned);
}

void dstcurs(){

	DestroyCursor(hfrm);
	DestroyCursor(hdlin);
	DestroyCursor(hnedu);
	DestroyCursor(hnedrd);
	DestroyCursor(hnedru);
	DestroyCursor(hnedld);
	DestroyCursor(hnedlu);
}

/* workaround for wine bug */
#ifdef __WINE__
extern char **__wine_main_argv;
extern int    __wine_main_argc;
#endif

void duhom(){

	unsigned ind;

#ifdef __WINE__
	char **argv = __wine_main_argv;
#else
	char **argv = __argv;
#endif

	strcpy(homdir,argv[0]);
	phom=strrchr(homdir,'\\');
	if(phom)
		phom++;
	else{

		ind=GetCurrentDirectory(MAX_PATH,homdir);
		homdir[ind++]='\\';
		phom=&homdir[ind];
	}
	*phom=0;
}

void bcpy(TCHAR* dst,TCHAR* src){
	strcpy(dst, src);
}

void ducmd(){

	unsigned int 	red;
	int				ind;

#ifdef __WINE__
	char **argv = __wine_main_argv;
	int    argc = __wine_main_argc;
#else
	char **argv = __argv;
	int    argc = __argc;
#endif

	if(argc>1){

		bcpy(filnam,argv[1]);
		if(!strncmp(filnam,"/F1:",4)){
 
			balpnt=&filnam[4];
			balfil=CreateFile(balpnt,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
			CloseHandle(balfil);
			if(balfil!=INVALID_HANDLE_VALUE){

				bcpy(balnam0,balpnt);
				if(argc>2){

					bcpy(filnam,argv[2]);
					if(!strncmp(filnam,"/F2:",4)){

						balpnt=&filnam[4];
						balfil=CreateFile(balpnt,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
						if(balfil!=INVALID_HANDLE_VALUE){

							bcpy(balnam1,balpnt);
							balpnt=(TCHAR*)&bseq;
							ReadFile(balfil,(void*)&balnam2,10000,&red,0);
							strcat(balnam2,"");
							if(red)
								redbal();
						}
					}
				}
				SetWindowText(hWnd,stab[STR_EMB]);
			}
			*filnam=0;
			CloseHandle(balfil);
			DeleteFile(balnam1);
		}
		else{

			for(ind=2;ind<argc;ind++){

				strcat(filnam," ");
				strcat(filnam,argv[ind]);
			}
			setMap(REDOLD);
			nuFil();
		}
	}
}

void redini(){

	unsigned		ind;
	unsigned int	wrot;
	HDC				tdc;

	for(ind=0;ind<16;ind++)
		bakdat[ind]=0;
	for(ind=0;ind<OLDNUM;ind++)
		ini.oldnams[ind][0]=0;
	duhom();
	strcpy(iniNam,homdir);
	strcat(iniNam,"thred.ini");
	hIni=CreateFile(iniNam,GENERIC_READ,0,NULL,
				OPEN_EXISTING,0,NULL);
	if(hIni==INVALID_HANDLE_VALUE)
		defpref();
	else{

		ReadFile(hIni,&ini,sizeof(ini),&wrot,0);
		if(wrot<2061)
			ini.frmbpix=DEFBPIX;
		strcpy(defDir,ini.defDir);
		strcpy(defbmp,ini.defDir);
		for(ind=0;ind<16;ind++){

			useCol[ind]=	ini.stchCols[ind];
			custCol[ind]=	ini.selStch[ind];
			bakCust[ind]=	ini.bakCol[ind];
			bakBit[ind]=	ini.bakBit[ind];
		}
		stchBak=ini.stchBak;
		bitCol=ini.bitCol;
		minsiz=ini.minsiz;
		shopnts=ini.shopnts;
		if(ini.tsiz30)
			tsiz30=ini.tsiz30;
		if(ini.tsiz40)
			tsiz40=ini.tsiz40;
		if(ini.tsiz60)
			tsiz60=ini.tsiz60;
		if(ini.usesiz)
			usesiz=ini.usesiz;
		if(!ini.maxsiz)
			ini.maxsiz=MAXSIZ*PFGRAN;
		if(ini.smalsiz)
			smalsiz=ini.smalsiz;
		stchboxs=ini.stchboxs;
		if(ini.stspace)
			stspace=ini.stspace;
		umap=ini.umap;
		if(ini.brdwid)
			brdwid=ini.brdwid;
		if(ini.apcol)
			apcol=ini.apcol&0xf;
		if(ini.snplen)
			snplen=ini.snplen;
		if(ini.starat)
			starat=ini.starat;
		if(ini.spirwrap)
			spirwrap=ini.spirwrap;
		if(ini.bfclen)
			bfclen=ini.bfclen;
		if(!ini.grdsiz)
			ini.grdsiz=12;
		if(!ini.wavpnts)
			ini.wavpnts=IWAVPNTS;
		if(!ini.wavstrt)
			ini.wavstrt=IWAVSTRT;
		if(!ini.wavend)
			ini.wavend=IWAVEND;
		if(!ini.wavs)
			ini.wavs=IWAVS;
		if(!ini.fthtyp)
			ini.fthtyp=FDEFTYP;
		if(!ini.fthup)
			ini.fthup=FDEFUP;
		if(!ini.fthdwn)
			ini.fthdwn=FDEFDWN;
		if(!ini.fthrat)
			ini.fthrat=(float)FDEFRAT;
		if(!ini.fthflr)
			ini.fthflr=FDEFFLR;
		if(!ini.fthnum)
			ini.fthnum=FDEFNUM;
		if(!ini.dazhlen)
			ini.dazhlen=DAZHLEN;
		if(!ini.dazcnt)
			ini.dazcnt=DAZCNT;
		if(!ini.dazicnt)
			ini.dazicnt=DAZICNT;
		if(!ini.dazlen)
			ini.dazlen=DAZLEN;
		if(!ini.dazpet)
			ini.dazpet=DAZPETS;
		if(!ini.dazplen)
			ini.dazplen=DAZPLEN;

		switch(ini.hup){

			case SMALHUP:

				ini.hupx=SHUPX;
				ini.hupy=SHUPY;
				break;

			case LARGHUP:

				ini.hupx=LHUPX;
				ini.hupy=LHUPY;
				break;

			case CUSTHUP:

				if(!ini.hupx)
					ini.hupx=LHUPX;
				if(!ini.hupy)
					ini.hupy=LHUPY;
				break;

			case HUP100:

				if(!ini.hupx)
					ini.hupx=HUP100XY;
				if(!ini.hupy)
					ini.hupy=HUP100XY;
				break;

			default:

				ini.hup=LARGHUP;
				ini.hupx=LHUPX;
				ini.hupy=LHUPY;
		}
		zum0.x=ini.hupx;
		zum0.y=ini.hupy;
		picspac=ini.picspac;
	}
	if(!ini.grdbak)
		ini.grdbak=DEFGRD;
	CloseHandle(hIni);
	if(!ini.angl)
		ini.angl=PI/6;
	tdc=GetDC(0);
	scrPix.cx=GetDeviceCaps(tdc,HORZRES);
	scrPix.cy=GetDeviceCaps(tdc,VERTRES);
	if(ini.irct.left<0)
		ini.irct.left=0;
	if(ini.irct.top<0)
		ini.irct.top=0;
	ind=scrPix.cx-30;
	if(ini.irct.right>(int)ind)
		ini.irct.right=ind;
	if(ini.irct.bottom>scrPix.cy)
		ini.irct.bottom=scrPix.cy;
}

void trcsub(HWND* hwnd,unsigned xloc,unsigned yloc,unsigned hi){

	*hwnd=CreateWindow(
		"STATIC",
		"",
		SS_OWNERDRAW|WS_CHILD|WS_BORDER,
		xloc,
		yloc,
		buttonWid,
		hi,
		hWnd,
		NULL,
		hInst,
		NULL);
}

void chkirct(){

	POINT lim;

	lim.x=scrPix.cx-1;
	lim.y=scrPix.cy-1;
	if(ini.irct.left>lim.x)
		ini.irct.left=lim.x;
	if(ini.irct.right>lim.x)
		ini.irct.right=lim.x;
	if(ini.irct.left<0)
		ini.irct.left=0;
	if(ini.irct.right<0)
		ini.irct.right=0;
	if(ini.irct.top>lim.y)
		ini.irct.top=lim.y;
	if(ini.irct.bottom>lim.y)
		ini.irct.bottom=lim.y;
	if(ini.irct.top<0)
		ini.irct.top=0;
	if(ini.irct.bottom<0)
		ini.irct.bottom=0;
	if(ini.irct.right-ini.irct.left<300){

		ini.irct.left=0;
		ini.irct.right=lim.x>>1;
	}
	if(ini.irct.bottom-ini.irct.top<300){

		ini.irct.top=0;
		ini.irct.bottom=lim.y>>1;
	}
}

void init(){

	unsigned		ind,flg;
	unsigned long	thwid,mwid;
	RECT			tRct;
	RECT			wrct;
	HDC				totdc;
	TCHAR*			pchr;

	txad=0;
	fsizeof=sizeof(FRMHED)>>2;
	LoadMenu(hInst,MAKEINTRESOURCE(IDR_MENU1));
	hMen=GetMenu(hWnd);
	totdc=GetDC(NULL);
	mwid=GetDeviceCaps(totdc,HORZRES);
	ReleaseDC(NULL,totdc);
	GetWindowRect(hWnd,&wrct);
	GetMenuItemRect(hWnd,hMen,0,&tRct);
	menhi=tRct.bottom-tRct.top;
	wrct.left=tRct.left;
	wrct.right=tRct.right;
	for(ind=0;ind<=M_HELP;ind++){

		GetMenuItemRect(hWnd,hMen,ind,&tRct);
		wrct.right+=(tRct.right-tRct.left);
	}
	wrct.right+=20;
	thwid=wrct.right-wrct.left;
	mwid>>=1;
	if(thwid<mwid)
		wrct.right=wrct.left+=mwid;
	hfilMen=GetSubMenu(hMen,M_FIL);
	hfileMen=GetSubMenu(hMen,M_FILE);
	hedmen=GetSubMenu(hMen,M_EDIT);
	hfilBrdMen=GetSubMenu(hfilMen,MFIL_BORD);
	hvumen=GetSubMenu(hMen,M_VIEW);
	hvsmen=GetSubMenu(hvumen,M_VIEW);
	qchk();
	hAr=LoadCursor(0,IDC_ARROW);
	hCros=LoadCursor(0,IDC_CROSS);
	crtcurs();
	redfils();
	clrMap(MAPLEN);						//clear the bitmap
	//set up the size variables
	mdc=GetDC(hWnd);
	SetStretchBltMode(mdc,COLORONCOLOR);
	rsdc=GetDCEx(hStch,0,DCX_PARENTCLIP|DCX_CLIPSIBLINGS);
	sdc=CreateCompatibleDC(rsdc);
	scrSiz.cx=GetDeviceCaps(mdc,HORZSIZE);
	scrSiz.cy=GetDeviceCaps(mdc,VERTSIZE);
	chkirct();
	if(!chku(SAVMAX))
		MoveWindow(hWnd,ini.irct.left,ini.irct.top,ini.irct.right-ini.irct.left,ini.irct.bottom-ini.irct.top,0);
	buttonWid=txtWid("MM")+TXTSIDS;
	buttonWid3=buttonWid*3;
	buttonHi=txSiz.cy+4;
	numwid=txtWid("0");
	selbox=txtWid("0");
	for(ind=0;ind<NERCNT;ind++)
		boxOff[ind]=selbox+selbox*ind;
#pragma warning(disable:4244;once:)
	GetClientRect(hWnd,&mRct);
	stchWnd();
	lodstr();
	maxwid(STR_PRF0,STR_PRF27);
	if(!hIni){

		//initialize the user color and thread size arrays
		for(ind=0;ind<16;ind++)
			useCol[ind]=defCol[ind];
	}
	for(ind=0;ind<16;ind++){

		thrdSiz[ind][0]='4';
		thrdSiz[ind][1]='0';
	}
	if(!ini.trlen)
		ini.trlen=TRACLEN;
	if(!ini.trcrat)
		ini.trcrat=TRACRAT;
	if(!ini.chspac)
		ini.chspac=CHSDEF;
	if(!ini.chrat)
		ini.chrat=CHRDEF;
	if(!ini.nudg)
		ini.nudg=NUGINI;
	if(!ini.nudgpix)
		ini.nudgpix=DEFPIX;
	if(!ini.egrat)
		ini.egrat=DEFEGRAT;
	if(!ini.stchpix)
		ini.stchpix=DEFPNTPIX;
	if(!ini.frmpix)
		ini.frmpix=DEFPNTPIX;
	if(!ini.nsids)
		ini.nsids=24;
	if(!ini.tearat)
		ini.tearat=(float)1.4;
	if(!ini.ulen)
		ini.ulen=DEFULEN;
	if(!ini.uspac)
		ini.uspac=DEFUSPAC;
	setgrd(ini.grdbak);
	makCol();		//make the color change windows
	for(ind=0;ind<9;ind++){
		
		switch(ind){

		case HBOXSEL:

			flg=SS_NOTIFY|SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER;
			pchr=stab[STR_BOXSEL];
			break;

		case HUPTO:

			flg=SS_NOTIFY|SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER;
			pchr=stab[STR_UPOF];
			break;

		case HHID:

			flg=SS_OWNERDRAW|SS_NOTIFY|WS_CHILD|WS_VISIBLE|WS_BORDER;
			pchr=stab[STR_PIKOL];
			break;

		default:

			pchr="";
			flg=SS_NOTIFY|SS_CENTER|WS_CHILD|WS_VISIBLE|WS_BORDER;
		}
		hbuts[ind]=CreateWindow(
			"STATIC",
			pchr,
			flg,
			0,
			buttonHi*(16+ind),
			buttonWid3,
			buttonHi,
			hWnd,
			NULL,
			hInst,
			NULL);
	}
	hstep=CreateWindow(
	
		"STATIC",
		"",
		SS_NOTIFY|SS_CENTER|WS_CHILD|WS_BORDER,
		0,
		buttonHi*18,
		buttonWid3,
		buttonHi,
		hWnd,
		NULL,
		hInst,
		NULL);

	hBar=CreateWindow(
		"STATIC",
		"",
		SS_OWNERDRAW|WS_CHILD|WS_VISIBLE|WS_BORDER,
		mRct.right-COLSIZ,
		0,
		COLSIZ,
		mRct.bottom,
		hWnd,
		NULL,
		hInst,
		NULL);

	for(ind=0;ind<3;ind++){

		trcsub(&hctrc[ind],buttonWid*ind,0,buttonHi*15);
		trcsub(&hstrc[ind],buttonWid*ind,buttonHi*15,buttonHi);
		trcsub(&htrup[ind],buttonWid*ind,buttonHi*16,buttonHi);
		trcsub(&htrdwn[ind],buttonWid*ind,buttonHi*17,buttonHi);
		trbrsh[ind]=CreateSolidBrush(trgb[ind]);
	}

	nuRct();
	//create pens
	for(ind=0;ind<4;ind++)
		bPen[ind]=CreatePen(PS_SOLID,1,boxRef[ind]);
	lPen=CreatePen(PS_SOLID,1,0x404040);
	xPen=CreatePen(PS_SOLID,5,0x804080);
	gPen=CreatePen(PS_SOLID,1,0x804080);
	grdPen=CreatePen(PS_SOLID,1,ini.grdbak);
	bakPen=CreatePen(PS_SOLID,3,stchBak);
	bitPen=CreatePen(PS_SOLID,1,bitCol);
	fPen=CreatePen(PS_SOLID,1,0xc0c0c0);
	fmpen=CreatePen(PS_SOLID,1,0xc0c080);
	fPen3=CreatePen(PS_SOLID,3,0xc0c0c0);
	fsPen=CreatePen(PS_SOLID,1,0x80c080);
	mrkPen=CreatePen(PS_SOLID,3,0x40c040);
	alpen=CreatePen(PS_SOLID,1,0xc08080);
	kpen=CreatePen(PS_SOLID,1,0xffffff);
	ypen[0]=CreatePen(PS_SOLID,1,0xc0c0c0);
	ypen[1]=CreatePen(PS_SOLID,1,0x80c0c0);
	ypen[2]=CreatePen(PS_SOLID,1,0xc080c0);
	ypen[3]=CreatePen(PS_SOLID,1,0xc0c080);
	ypen[4]=CreatePen(PS_SOLID,1,0x40c0c0);
	ypen[5]=CreatePen(PS_SOLID,1,0xc0c040);
	bakwid=1;
	for(ind=0;ind<16;ind++){

		pixSiz[ind]=1;
		sizInd[ind]=1;
		uPen[ind]=CreatePen(PS_SOLID,1,useCol[ind]);
	}
	hStchBak=CreateSolidBrush(stchBak);
	//create brushes
	for(ind=0;ind<16;ind++){

		hbrDefCol[ind]=CreateSolidBrush(defCol[ind]);
		hbrUseCol[ind]=CreateSolidBrush(useCol[ind]);
	}
	hblk=CreateSolidBrush(0);
	zumFct=1;
	hed.ledIn=0x32;
	hed.fColCnt=16;
	hed.stchs=0;
	GetDCOrgEx(rsdc,&stOrg);
	ladj();
	GetTextExtentPoint(sdc,stab[STR_PIKOL],strlen(stab[STR_PIKOL]),&pcolsiz);
	auxmen();
	fnamtabs();
	ritfnam(ini.desnam);
	strcpy(hedx.modnam,ini.desnam);
	hedx.stgran=0;
	for(ind=0;ind<31;ind++)
		hedx.res[ind]=0;
	chkhup();
	nedmen();
	fil2men();
	knotmen();
	bsavmen();
	rotauxmen();
	linbmen();
	wrnmen();
	ritloc();
	frmcurmen();
	redtx();
	setMap(HIDMAP);
	hidbit();
	chkmen();
	//check command line-should be last item in init
	ducmd();
	sprintf(msgbuf,stab[STR_THRED],ini.desnam);
	SetWindowText(hWnd,msgbuf);
}

COLORREF defTxt(unsigned colInd){
	return bt(&defMap, colInd) ? 0xffffff : 0;
}

void setCol(unsigned ind){
	bts(&cbit, ind & 31);
}

void relin(){

	stch2px1(cloInd-1);
	mlin0[0].x=pPnt.x;
	mlin0[0].y=pPnt.y;
	stch2px1(cloInd+1);
	mlin1[1].x=pPnt.x;
	mlin1[1].y=pPnt.y;
	rstMap(WASLIN);
	dulin();
}

unsigned setRmp(unsigned pbit){
	return bts(rmap, pbit) ? 0 : 0xffffffff;
}

void drwLin(unsigned ind,unsigned len,HPEN hPen){

	unsigned	ine,layr;
	SHRTPNT*	pstch=&stchs[ind];

	if(actl)
		drwpnt=0;
	for(ine=0;ine<len;ine++){
	
		layr=(pstch[ine].at&LAYMSK)>>LAYSHFT;
		if(!actl||!layr||(layr==actl)){

			plin[drwpnt].x=(pstch[ine].x-zRct.left)*zrat.x;
			plin[drwpnt++].y=scRct.bottom-(pstch[ine].y-zRct.bottom)*zrat.y;
		}
	}
	SelectObject(sdc,hPen);
	if(drwpnt<16000)
		Polyline(sdc,plin,drwpnt);
	else{

		ine=0;
		while(drwpnt){

			if(drwpnt>16000){

				Polyline(sdc,&plin[ine],16000);
				ine+=15999;
				drwpnt-=15999;
			}
			else{

				Polyline(sdc,&plin[ine],drwpnt);
				break;
			}
		}
	}
	drwpnt=1;
	layr=(pstch[ine].at&LAYMSK)>>LAYSHFT;
	if(!actl||!layr||layr==actl){
	
		plin[0].x=(pstch[ine-1].x-zRct.left)*zrat.x;
		plin[0].y=scRct.bottom-(pstch[ine-1].y-zRct.bottom)*zrat.y;
	}
}

void dumov(){

	SHRTPNT*	tstch;
	POINT		arlin[8];
	POINT		trot;

	pixang=atan2(stchs[movpnt+1].y-stchs[movpnt].y,stchs[movpnt+1].x-stchs[movpnt].x);
	tstch=&stchs[movpnt];
	if(tstch->x>=zRct.left&&tstch->x<=zRct.right
		&&tstch->y>=zRct.bottom&&tstch->y<=zRct.top){

		sdCor2px(stchs[movpnt],&pixcntr);
		arlin[0].x=arlin[6].x=pixcntr.x;
		arlin[0].y=arlin[6].y=pixcntr.y;
		trot.x=pixcntr.x+12;
		trot.y=pixcntr.y+2;
		rotpix(trot,&arlin[1]);
		trot.y=pixcntr.y-2;
		rotpix(trot,&arlin[5]);
		trot.y=pixcntr.y+6;
		rotpix(trot,&arlin[2]);
		trot.y=pixcntr.y-6;
		rotpix(trot,&arlin[4]);
		trot.x=pixcntr.x+20;
		trot.y=pixcntr.y;
		rotpix(trot,&arlin[3]);
		SelectObject(sdc,fPen);
		SetROP2(sdc,R2_XORPEN);
		Polyline(sdc,arlin,7);
		SetROP2(sdc,R2_COPYPEN);
	}
}

unsigned chkup(unsigned cnt,unsigned ind){

	if(chkMap(UPTO)&&cloInd){

		if(colch[ind].stind<cloInd){

			if(colch[ind+1].stind<cloInd)
				return cnt;
			else
				return cloInd-colch[ind].stind+1;
		}
		else
			return 0;
	}
	else
		return cnt;
}

BOOL bitar(){

	DUBRCT	bakrct;
	DUBRCT	difrct;
	DUBPNT	bsdrat;
	DUBRCT	zirct;

	zirct.bottom=zum0.y-zRct.bottom;
	zirct.top=zum0.y-zRct.top;
	zirct.left=zRct.left;
	zirct.right=zRct.right;
	if(zirct.top>zumend.y||zirct.left>zumend.x)
		return 0;
	else{

		bsrct.top=ceil(zirct.top*bsrat.y);
		bsrct.left=ceil(zRct.left*bsrat.x);
		bsrct.right=floor(zRct.right*bsrat.x);
		bsrct.bottom=floor(zirct.bottom*bsrat.y);
		if(bsrct.right>(long)bwid){

			bsrct.right=bwid;
			rstMap(LANDSCAP);
		}
		if(bsrct.bottom>(long)bhi){

			bsrct.bottom=bhi;
			setMap(LANDSCAP);
		}
		bakrct.top=bsrct.top*birat.y;
		bakrct.left=bsrct.left*birat.x;
		bakrct.right=bsrct.right*birat.x;
		bakrct.bottom=bsrct.bottom*birat.y;
		difrct.top=bakrct.top-zirct.top;
		difrct.left=bakrct.left-zirct.left;
		difrct.right=zirct.right-bakrct.right;
		difrct.bottom=zirct.bottom-bakrct.bottom;
		bsdrat.x=(double)scRct.right/(zRct.right-zRct.left);
		bsdrat.y=(double)scRct.bottom/(zRct.top-zRct.bottom);
		bdrct.top=difrct.top*bsdrat.y;
		bdrct.left=difrct.left*bsdrat.x;
		bdrct.right=scRct.right-difrct.right*bsdrat.x;
		bdrct.bottom=scRct.bottom-difrct.bottom*bsdrat.y;
		return 1;
	}
}

void drwknot(){

#define			KSIZ 5
#define			KLSIZ 10

	unsigned	ind;
	POINT		pnt;
	POINT		tlin[5];

	if(!chku(KNOTOF)&&knotcnt&&hed.stchs){

		for(ind=0;ind<knotcnt;ind++){

			stCor2px(stchs[knotab[ind]],&pnt);
			SelectObject(sdc,kpen);
			SetROP2(sdc,R2_XORPEN);
			tlin[0].x=tlin[3].x=tlin[4].x=pnt.x-KSIZ;
			tlin[1].x=tlin[2].x=pnt.x+KSIZ;
			tlin[0].y=tlin[1].y=tlin[4].y=pnt.y+KSIZ;
			tlin[2].y=tlin[3].y=pnt.y-KSIZ;
			Polyline(sdc,tlin,5);
			tlin[0].x=pnt.x-KLSIZ;
			tlin[1].x=pnt.x+KLSIZ;
			tlin[0].y=tlin[1].y=pnt.y;
			Polyline(sdc,tlin,2);
			SetROP2(sdc,R2_COPYPEN);
		}
	}
}

void dugrid(){

	POINT		tlin[2];
	RECT		grdrct;
	unsigned	ind;

	if(zumFct<shopnts||!shopnts){

		SetROP2(sdc,R2_XORPEN);
		SelectObject(sdc,grdPen);
		grdrct.left=ceil(zRct.left/ini.grdsiz);
		grdrct.right=floor(zRct.right/ini.grdsiz);
		grdrct.bottom=ceil(zRct.bottom/ini.grdsiz);
		grdrct.top=floor(zRct.top/ini.grdsiz);
		tlin[0].x=0;
		tlin[1].x=scRct.right;
		for(ind=grdrct.bottom;ind<=(unsigned)grdrct.top;ind++){

			tlin[0].y=tlin[1].y=scRct.bottom-(ind*ini.grdsiz-zRct.bottom)*zrat.y+0.5;
			Polyline(sdc,tlin,2);
		}
		tlin[0].y=0;
		tlin[1].y=scRct.bottom;
		for(ind=grdrct.left;ind<=(unsigned)grdrct.right;ind++){

			tlin[0].x=tlin[1].x=(ind*ini.grdsiz-zRct.left)*zrat.x+0.5;
			Polyline(sdc,tlin,2);
		}
		SetROP2(sdc,R2_COPYPEN);
	}
}

void rint(){

	unsigned siz;

	rcel.x=(zRct.right-zRct.left)/scRct.right;
	rcel.y=(zRct.top-zRct.bottom)/scRct.bottom;
	siz=scRct.right*scRct.bottom;
	if(siz>RMAPBITS){

		rcel.x*=siz/RMAPBITS;
		rcel.y*=siz/RMAPBITS;
	}
}

unsigned setRmap(SHRTPNT sPnt){

	unsigned bpnt;

	bpnt=floor((sPnt.x-zRct.left)/rcel.x)*floor((sPnt.y-zRct.bottom)/rcel.y);
	if(bpnt<RMAPBITS)
		return setRmp(bpnt);
	return 0;
}

void drwStch(){

	unsigned	ind,ine,scnt,pwid,wascol;
	unsigned	layr;
	double		slop,off;
	double		dub6;
	SHRTPNT*	pstch;
	POINT		tlin[2];
	long		hi=ds->rcItem.bottom;
	long		xba,yab,tlng;
	HDC			tdc;

	setMap(RELAYR);
	rstMap(SELSHO);
	rstMap(ILIN1);
	rstMap(BZUM);
	unboxs();
	unrotu();
	unrot();
	rstMap(ILIN);
	uncros();
	rstMap(SHOFRM);
	scnt=0;
	for(ind=0;ind<colCnt;ind++){
	
		drwpnt=colch[ind+1].stind-colch[ind].stind;
		if(drwpnt>scnt)
			scnt=drwpnt;
	}
	plin=new POINT[scnt+2];
	FillRect(sdc,&scRct,hStchBak);
	duzrat();
	if(*bnam&&!chkMap(HIDMAP)&&!chkMap(UPTO)){
	
		if(chkMap(WASTRAC))
			tdc=tracedc;
		else
			tdc=bitdc;
		if(bitar())
			StretchBlt(sdc,  bdrct.left,bdrct.top,bdrct.right-bdrct.left,bdrct.bottom-bdrct.top,
					   tdc,bsrct.left,bsrct.top,bsrct.right-bsrct.left,bsrct.bottom-bsrct.top,SRCCOPY);
	}
	dugrid();
	if(chkMap(INIT)){

		if(chkMap(ZUMED)){

			scrol.cbSize=sizeof(scrol);
			scrol.fMask=SIF_ALL;
			scrol.nMax=zum0.y;
			scrol.nMin=0;
			scrol.nPage=zRct.top-zRct.bottom;
			scrol.nPos=zum0.y-zRct.top;
			SetScrollInfo(hVrt,SB_CTL,&scrol,TRUE);
			scrol.nMax=zum0.x;
			scrol.nPage=zRct.right-zRct.left;
			scrol.nPos=zRct.left;
			SetScrollInfo(hHor,SB_CTL,&scrol,TRUE);
			ShowWindow(hHor,TRUE);
			ShowWindow(hVrt,TRUE);
		}
		else{

			ShowWindow(hVrt,FALSE);
			ShowWindow(hHor,FALSE);
		}
		duzrat();
		dub6=zrat.x*6;
		tPix[0]=dub6*TSIZ30;
		tPix[1]=dub6*TSIZ40;
		tPix[2]=dub6*TSIZ60;
		for(ind=0;ind<16;ind++){

			if(chkMap(THRDS))
				nuStchSiz(ind,tPix[sizInd[ind]]);
			else{
				if(chkMap(COL)){

					if(ind==actcol)
						nuStchSiz(ind,tPix[sizInd[ind]]);
					else
						nuStchSiz(ind,1);
				}
				else
					nuStchSiz(ind,1);
			}
		}
		drwpnt=0;cbit=0;
		if(chkMap(ZUMED)){
	
			drwpnt=0;
			rstMap(LINED);
			rstMap(LININ);
			for(ind=0;ind<colCnt;ind++){
				
				if(chkMap(HID)){
	
					if(colch[ind].colind!=actcol){
	
						scnt=colch[ind+1].stind-colch[ind].stind;
						pstch=&stchs[colch[ind].stind];
						for(ine=0;ine<scnt;ine++){
					
							if(pstch[ine].x>=zRct.left
								&&pstch[ine].x<=zRct.right
								&&pstch[ine].y>=zRct.bottom
								&&pstch[ine].y<=zRct.top){
	
								setCol(colch[ind].colind);
								goto skip;
							}
						}
						goto skip;
					}
					else
						goto skip1;
				}
				else{
skip1:;

					wascol=0;
				}
				SelectObject(sdc,uPen[colch[ind].colind]);
				scnt=colch[ind+1].stind-colch[ind].stind;
				pstch=&stchs[colch[ind].stind];
				scnt=chkup(scnt,ind);
				for(ine=0;ine<scnt;ine++){
				
					layr=(pstch[ine].at&LAYMSK)>>LAYSHFT;
					if(!actl||!layr||(layr==actl)){
					
						if(pstch[ine].x>=zRct.left
							&&pstch[ine].x<=zRct.right
							&&pstch[ine].y>=zRct.bottom
							&&pstch[ine].y<=zRct.top){
				
							wascol=1;
							if(setMap(LINED)){
			
								if(setMap(LININ)){
			
									plin[drwpnt].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
									plin[drwpnt++].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
				
								}
								else{
				
									plin[drwpnt].x=(pstch[ine-1].x-zRct.left)*zrat.x+0.5;
									plin[drwpnt++].y=hi-(pstch[ine-1].y-zRct.bottom)*zrat.y+0.5;
									plin[drwpnt].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
									plin[drwpnt++].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
								}
							}
							else{
				
								if(ine==0&&ind==0){
						
									plin[0].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
									plin[0].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
									drwpnt=1;
								}
								else{
				
									plin[0].x=(pstch[ine-1].x-zRct.left)*zrat.x+0.5;
									plin[0].y=hi-(pstch[ine-1].y-zRct.bottom)*zrat.y+0.5;
									plin[1].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
									plin[1].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
									drwpnt=2;
								}
								setMap(LININ);
							}
						}
						else{
				
							if(rstMap(LININ)){
				
								plin[drwpnt].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
								plin[drwpnt++].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
								Polyline(sdc,plin,drwpnt);
								drwpnt=0;
							}
							else{

								if(ine){
			
									//write an equation for this line
									xba=pstch[ine].x-pstch[ine-1].x;
									yab=pstch[ine-1].y-pstch[ine].y;
									slop=(double)xba/yab;
									off=pstch[ine].x+slop*pstch[ine].y;
									//does the line intersect with the top of the screen?
									tlng=off-slop*zRct.top;
									if(tlng>=zRct.left&&tlng<=zRct.right){
				
										tlin[0].x=(pstch[ine-1].x-zRct.left)*zrat.x+0.5;
										tlin[0].y=hi-(pstch[ine-1].y-zRct.bottom)*zrat.x+0.5;
										tlin[1].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
										tlin[1].y=hi-(pstch[ine].y-zRct.bottom)*zrat.x+0.5;
										Polyline(sdc,tlin,2);
										goto rotlin;
									}
									//does the line intersect the bottom of the screen?
									tlng=off-slop*zRct.bottom;
									if(tlng>=zRct.left&&tlng<=zRct.right){
				
										tlin[0].x=(pstch[ine-1].x-zRct.left)*zrat.x+0.5;
										tlin[0].y=hi-(pstch[ine-1].y-zRct.bottom)*zrat.y+0.5;
										tlin[1].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
										tlin[1].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
										Polyline(sdc,tlin,2);
										goto rotlin;
									}							
									//does the line intersect the left side of the screen?
									if(slop){

										tlng=(off-zRct.left)/slop;
										if(tlng>=zRct.bottom&&tlng<=zRct.top){
					
											tlin[0].x=(pstch[ine-1].x-zRct.left)*zrat.x+0.5;
											tlin[0].y=hi-(pstch[ine-1].y-zRct.bottom)*zrat.y+0.5;
											tlin[1].x=(pstch[ine].x-zRct.left)*zrat.x+0.5;
											tlin[1].y=hi-(pstch[ine].y-zRct.bottom)*zrat.y+0.5;
											Polyline(sdc,tlin,2);
										}
									}
								}
rotlin:;

							}
						}
					}
				}
				if(drwpnt){
		
					Polyline(sdc,plin,drwpnt);
					plin[0].x=plin[drwpnt-1].x;
					plin[0].y=plin[drwpnt-1].y;
					drwpnt=1;
				}
				if(wascol)
					setCol(colch[ind].colind);
skip:;
			}
		}
		else{
		
			pwid=chkMap(HID);
			for(ind=0;ind<colCnt;ind++){

				setCol(colch[ind].colind);
				scnt=colch[ind+1].stind-colch[ind].stind;
				scnt=chkup(scnt,ind);
				if(!pwid||(pwid&&colch[ind].colind==actcol))
					drwLin(colch[ind].stind,scnt,uPen[colch[ind].colind]);
			}
		}
		if(chkMap(SELBOX)){

			ritcor(&stchs[cloInd]);		
			if(stch2px(cloInd))
				dubox();
		}
		if(chkMap(FRMPSEL))
			ritfcor(&formlst[clofind].flt[clofine]);
		if(!chkMap(SELBOX)&&!chkMap(FRMPSEL))
			butxt(HCOR,"");
		if(chkMap(WASLIN))
			relin();
		if(chkMap(GRPSEL)){
	
			if(cmpstch(cloInd,grpInd))
				cros(cloInd);
			else{

				slpnt=0;
				ducros(sdc);
			}
			selRct(&rngrct);
			nuselrct();
			setMap(SELSHO);
			dusel(sdc);
		}
		if(zumFct<stchboxs){

			clRmap(RMAPSIZ);
			SelectObject(sdc,lPen);
			SetROP2(sdc,R2_NOTXORPEN);
			rint();
			if(chkMap(HID)){

				for(ind=0;ind<colCnt;ind++){

					if(colch[ind].colind==actcol){

						for(ine=colch[ind].stind;ine<colch[ind+1].stind;ine++){

							if(stchs[ine].x>=zRct.left&&stchs[ine].x<=zRct.right
								&&stchs[ine].y>=zRct.bottom&&stchs[ine].y<=zRct.top
								&&setRmap(stchs[ine]))

								stchbox(ine,sdc);
						}
					}
				}
			}
			else{

				for(ind=0;ind<hed.stchs;ind++){

					if(stchs[ind].x>=zRct.left&&stchs[ind].x<=zRct.right
						&&stchs[ind].y>=zRct.bottom&&stchs[ind].y<=zRct.top
						&&setRmap(stchs[ind]))

						stchbox(ind,sdc);
				}
			}
			SetROP2(sdc,R2_COPYPEN);
		}
		if(chkMap(CLPSHO))
			duclp();
		if(chkMap(ROTAT)||chkMap(ROTCAPT)||chkMap(MOVCNTR))
			ritrot();
		delete[] plin;
	}
	if(formpnt&&!chkMap(FRMOF))
		drwfrm();
	if(chkMap(INSFRM))
		rinfrm();
	if(chkMap(BIGBOX))
		dubig();
	if(chkMap(MOVFRM)){

		setMap(SHOFRM);
		dufrm();
	}
	if(chkMap(SATPNT))
		satzum();
	if(hfdat)
		refrm();
	if(chkMap(GMRK))
		drwmrk(sdc);
	if(chkMap(PRFACT))
		redraw(hPrf);
	if(chkMap(SELBOX))
		ritnum(STR_NUMSEL,cloInd);
	ritot(hed.stchs);
	if(chkMap(INIT))
		lenCalc();
	if(chkMap(MOVSET))
		dumov();
	drwknot();
}
	
unsigned chkCol(unsigned ind){
	return bt(&cbit, ind) ? -1 : 0;
}

void dubar(){

	unsigned	ind;
	RECT		tRct;
	double		tdub;
	POINT		lin[2];
	
	tRct.left=ds->rcItem.left;
	tRct.right=ds->rcItem.right;
	tRct.top=0;
	tRct.bottom=ds->rcItem.bottom;
	for(ind=0;ind<colCnt;ind++){

		tdub=(double)colch[ind+1].stind/hed.stchs;
		tRct.bottom=tdub*ds->rcItem.bottom;
		FillRect(ds->hDC,&tRct,hbrUseCol[colch[ind].colind]);
		tRct.top=tRct.bottom;
	}
	if(chkMap(SELBOX)||chkMap(GRPSEL)){

		tdub=(double)cloInd/hed.stchs;
		lin[0].y=lin[1].y=tRct.bottom*tdub+0.5;
		lin[0].x=tRct.left;
		lin[1].x=tRct.right;
		SelectObject(ds->hDC,xPen);
		SetROP2(sdc, R2_NOTXORPEN);		
		Polyline(ds->hDC,lin,2);
		if(chkMap(GRPSEL)){

			tdub=(double)grpInd/hed.stchs;
			lin[0].y=lin[1].y=tRct.bottom*tdub+0.5;
			lin[0].x=tRct.left;
			lin[1].x=tRct.right;
			Polyline(ds->hDC,lin,2);
		}
		SetROP2(sdc,R2_COPYPEN);
	}
}

void ritbak(TCHAR* nam,DRAWITEMSTRUCT* ds){

	unsigned	ind,ine,inf,col,lind,redsiz;
	HANDLE		thfil;
	POINT		siz;
	SHRTPNT*	tstch;
	POINT*		plin;
	STRHED		sthed;
	FLPNT		rsiz;
	double		rat;
	double		ratx,raty;
	COLORREF	tbak;
	COLORREF	tcol[16];
	HBRUSH		tbr;
	HPEN		pen;
	FRMHED*		flst;
	FLPNT*		tflt;
	STREX		thedx;
	unsigned	vervar;
	FRMHEDO*	frmlstx;

	thfil=CreateFile(nam,GENERIC_READ,0,0,
		OPEN_EXISTING,0,0);
	siz.x=ds->rcItem.right-ds->rcItem.left;
	siz.y=ds->rcItem.bottom-ds->rcItem.top;
	if(thfil!=INVALID_HANDLE_VALUE){

		ReadFile(thfil,(STRHED*)&sthed,sizeof(STRHED),&red,NULL);
		if(red==sizeof(STRHED)){

			if((sthed.led&0xffffff)==0x746872){

				vervar=(sthed.led&0xff000000)>>24;
				switch(vervar){

				case 0:

					if(hed.hup==SMALHUP){

						rsiz.x=ini.hupx=SHUPX;
						rsiz.y=ini.hupy=SHUPY;
					}
					else{

						rsiz.x=ini.hupx=LHUPX;
						rsiz.y=ini.hupy=LHUPY;
					}
					break;

				case 1:
				case 2:

					ReadFile(thfil,(STREX*)&thedx,sizeof(STREX),&red,NULL);
					if(red!=sizeof(STREX))
						return;
					rsiz.x=thedx.xhup;
					rsiz.y=thedx.yhup;

					break;

				default:

					return;
				}
			}
			ratx=(double)siz.x/rsiz.x;
			raty=(double)siz.y/rsiz.y;
			if(ratx<raty)
				rat=ratx;
			else
				rat=raty;
			if(sthed.stchs){

				tstch=new SHRTPNT[sthed.stchs];
				plin=new POINT[sthed.stchs];
				redsiz=sthed.stchs*sizeof(SHRTPNT);
				ReadFile(thfil,(SHRTPNT*)tstch,redsiz,&red,0);
				if(redsiz==red){

					SetFilePointer(thfil,16,0,FILE_CURRENT);
					ReadFile(thfil,(COLORREF*)&tbak,4,&red,0);
					ReadFile(thfil,(COLORREF*)tcol,64,&red,0);
					tbr=CreateSolidBrush(tbak);
					SelectObject(ds->hDC,tbr);
					FillRect(ds->hDC,&ds->rcItem,tbr);
					col=tstch[0].at&0xf;
					pen=CreatePen(PS_SOLID,1,tcol[col]);
					lind=0;
					for(ine=0;ine<sthed.stchs;ine++){

						if((tstch[ine].at&0xf)==col){

							plin[lind].x=tstch[ine].x*rat;
							plin[lind++].y=siz.y-tstch[ine].y*rat;
						}
						else{

							pen=nuPen(pen,1,tcol[col]);
							SelectObject(ds->hDC,pen);
							Polyline(ds->hDC,plin,lind);
							lind=0;
							col=tstch[ine].at&0xf;
						}
					}
					if(lind){

						pen=nuPen(pen,1,tcol[col]);
						SelectObject(ds->hDC,pen);
						Polyline(ds->hDC,plin,lind);
					}
					DeleteObject(tbr);
					DeleteObject(pen);
					delete tstch;
					delete plin;
				}
				else{

					delete tstch;
					delete plin;
					CloseHandle(thfil);
					return;
				}
			}
			else
				SetFilePointer(thfil,84,0,FILE_CURRENT);
			if(sthed.fpnt){

				plin=new POINT[MAXFRMLINS];
				SetFilePointer(thfil,80,0,FILE_CURRENT);
				flst=new FRMHED[sthed.fpnt];
				tflt=new FLPNT[sthed.fcnt];
				if(vervar<2){

					frmlstx=(FRMHEDO*)&bseq;
					ReadFile(thfil,(FRMHEDO*)frmlstx,sthed.fpnt*sizeof(FRMHEDO),&red,0);
					if(red!=sthed.fcnt*sizeof(FRMHEDO))
						goto bakskp;
					FillMemory(&bseq,0,sizeof(FRMHED)*formpnt);
					for(ind=0;ind<sthed.fpnt;ind++){

						frmpnt=&flst[ind];
						MoveMemory(frmpnt,&frmlstx[ind],sizeof(FRMHEDO));
					}
				}
				else{

					redsiz=sthed.fpnt*sizeof(FRMHED);
					ReadFile(thfil,(FRMHED*)flst,redsiz,&red,0);
					if(red!=redsiz)
						goto bakskp;
				}
				redsiz=sthed.fcnt*sizeof(FLPNT);
				ReadFile(thfil,(FLPNT*)tflt,redsiz,&red,0);
				if(red!=redsiz)
					goto bakskp;
				inf=0;
				for(ind=0;ind<sthed.fpnt;ind++){

					lind=inf;
					for(ine=0;ine<flst[ind].sids;ine++){

						plin[ine].x=tflt[inf].x*rat;
						plin[ine].y=siz.y-tflt[inf++].y*rat;
					}
					plin[ine].x=tflt[lind].x*rat;
					plin[ine].y=siz.y-tflt[lind].y*rat;
					SelectObject(ds->hDC,fPen);
					SetROP2(ds->hDC,R2_XORPEN);
					if(formlst[ind].typ==LIN)
						Polyline(ds->hDC,plin,flst[ind].sids);
					else
						Polyline(ds->hDC,plin,flst[ind].sids+1);
					SetROP2(sdc,R2_COPYPEN);
				}
bakskp:;
				delete flst;
				delete tflt;
				delete plin;
			}
		}
		CloseHandle(thfil);
	}
}

void durct(unsigned shft,RECT irct){

	unsigned	lo,hi,len;
	double		rat;

	lo=(uref>>shft)&0xff;
	hi=(dref>>shft)&0xff;
	hirct.left=lorct.left=midrct.left=irct.left;
	hirct.right=lorct.right=midrct.right=irct.right;
	len=irct.bottom-irct.top;
	rat=(double)lo/255;
	midrct.top=len*rat+irct.top;
	rat=(double)hi/255;
	midrct.bottom=len*rat+irct.top;
	rstMap(DUHI);
	rstMap(DULO);
	if(lo){

		setMap(DULO);
		lorct.bottom=midrct.top;
		lorct.top=0;
	}
	if(hi!=255){

		setMap(DUHI);
		hirct.top=midrct.bottom;
		hirct.bottom=irct.bottom;
	}
}

void dublk(HDC dc){

	if(chkMap(DUHI))
		FillRect(dc,&hirct,hblk);
	if(chkMap(DULO))
		FillRect(dc,&lorct,hblk);
}

BOOL chkchksum(){

	unsigned		ind;
	__int64			chkacc;
	__int64			chksum;
	__int64*		pchk;
	unsigned char*	pkchr;
	unsigned char*	ptchr;
	unsigned char*	pchr;

	pkchr=(unsigned char*)&cryptkey;
	pchr=(unsigned char*)&chksum;
	for(ind=0;ind<8;ind++)
	{
		ptchr=&pkchr[chk1loc[ind]];
		pchr[ind]=*ptchr;
		*ptchr=0;
	}
	pchk=(__int64*)&cryptkey;
	chkacc=0;
	for(ind=0;ind<512;ind++)
		chkacc+=pchk[ind];
	if(chkacc==chksum)
		return 0;
	else
		return 1;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam){

	unsigned			ind,ine;
	TCHAR				buf[10];		//for integer to string conversion
	unsigned			len;			//string length
	SIZE				txSiz;			//for measuring text items
	POINT				scPnt;			//for scroll bar functions
	POINT				lin[2];
	long				twid;
	double				tdub;
	TCHAR				nam[MAX_PATH];

	switch(message){

	case WM_INITMENU:

		if(rstMap(PRFACT)){

			DestroyWindow(hPrf);
			rstMap(WASRT);
		}
		unmsg();
		undat();
		rstMap(FORMIN);
		setMap(RESTCH);
		break;

	case WM_HSCROLL:

		switch((long)(LOWORD(wParam))){
 
		case SB_LINELEFT:

			if(chkMap(RUNPAT)||chkMap(WASPAT)){

				delay+=SPEDLIN;
				if(delay>MAXDELAY)
					delay=MAXDELAY;
				setsped();
				SetScrollPos(hSped,SB_CTL,MAXDELAY-delay,TRUE);
			}
			else{

				scPnt.x=(zRct.right-zRct.left)*LINSCROL;
				if(!scPnt.x)
					scPnt.x=1;
				scPnt.y=0;
				rshft(scPnt);
			}
			return 1;

		case SB_LINERIGHT:

			if(chkMap(RUNPAT)||chkMap(WASPAT)){

				delay-=SPEDLIN;
				if(delay<MINDELAY)
					delay=MINDELAY;
				setsped();
				SetScrollPos(hSped,SB_CTL,MAXDELAY-delay,TRUE);
			}
			else{

				scPnt.x=-(zRct.right-zRct.left)*LINSCROL;
				if(!scPnt.x)
					scPnt.x=-1;
				scPnt.y=0;
				rshft(scPnt);
			}
			return 1;

		case SB_PAGELEFT:
			
			if(chkMap(RUNPAT)||chkMap(WASPAT)){

				delay+=SPEDPAG;
				if(delay<MINDELAY)
					delay=MINDELAY;
				setsped();
				SetScrollPos(hSped,SB_CTL,MAXDELAY-delay,TRUE);
			}
			else
				pglft();
			return 1;

		case SB_PAGERIGHT:

			if(chkMap(RUNPAT)||chkMap(WASPAT)){

				delay-=SPEDPAG;
				if(delay<MINDELAY)
					delay=MINDELAY;
				setsped();
				SetScrollPos(hSped,SB_CTL,MAXDELAY-delay,TRUE);
			}
			else
				pgrit();
			return 1;

		case SB_THUMBPOSITION:

			if(chkMap(RUNPAT)||chkMap(WASPAT)){

				if((HWND)lParam==hSped){

					ind=(unsigned)HIWORD(wParam);
					delay=MAXDELAY-ind;
					setsped();
					SetScrollPos(hSped,SB_CTL,ind,TRUE);
				}
			}
			else{

				if((HWND)lParam==hHor){

					scPnt.x=zRct.right-zRct.left;
					zRct.left=(long)HIWORD(wParam);
					zRct.right=zRct.left+scPnt.x;
					if(zRct.right>zum0.x){

						zRct.right=zum0.x;
						zRct.left=zum0.x-scPnt.x;
					}
					setMap(RESTCH);
				}
			}
			return 1;
		}
		break;

	case WM_VSCROLL:

		switch((int)LOWORD(wParam)){

		unpat();
		case SB_LINEDOWN:

			scPnt.y=(zRct.top-zRct.bottom)*LINSCROL;
			if(!scPnt.y)
				scPnt.y=1;
			scPnt.x=0;
			rshft(scPnt);
			return 1;
		
		case SB_LINEUP:

			scPnt.y=-(zRct.top-zRct.bottom)*LINSCROL;
			if(!scPnt.y)
				scPnt.y=-1;
			scPnt.x=0;
			rshft(scPnt);
			return 1;
		
		case SB_PAGEDOWN:

			pgdwn();
			return 1;
		
		case SB_PAGEUP:

			pgup();
			return 1;
		
		case SB_THUMBPOSITION:

			scPnt.y=zRct.top-zRct.bottom;
			zRct.top=zum0.y-(long)HIWORD(wParam);
			zRct.bottom=zRct.top-scPnt.y;
			if(zRct.bottom<0){

				zRct.bottom=0;
				zRct.top=scPnt.y;
			}
			setMap(RESTCH);
			return 1;
		}
		break;

	case WM_DRAWITEM:

		//owner draw windows
		ds=(LPDRAWITEMSTRUCT)lParam;
		if(ds->hwndItem==hStch&&ds->itemAction==ODA_DRAWENTIRE){

			if(chkMap(TXTRED))
			{
				drwtxtr();
				return 1;
			}
			if(!chkMap(RUNPAT)){

				if(!chkMap(HIDSTCH)&&(hFil||chkMap(INIT)||formpnt||chkMap(SATPNT))&&!chkMap(BAKSHO))
					drwStch();
				else{

					FillRect(sdc,&scRct,hStchBak);
					duzrat();
					dugrid();
					if(chkMap(HIDSTCH)){

						drwfrm();
						if(chkMap(SATPNT))
							satzum();
					}
					if(chkMap(PRFACT))
						redraw(hPrf);
					else{

						if(chkMap(MOVFRM)){

							unfrm();
							setMap(SHOFRM);
							dufrm();
						}
						if(chkMap(POLIMOV)){

							setMap(SHOFRM);
							mdufrm();
						}
					}
				}
				BitBlt(
				  rsdc,			// handle to destination DC
				  0,			// x-coord of destination upper-left corner
				  0,			// y-coord of destination upper-left corner
				  scRct.right,	// width of destination rectangle
				  scRct.bottom,	// height of destination rectangle
				  sdc,			// handle to source DC
				  0,			// x-coordinate of source upper-left corner
				  0,			// y-coordinate of source upper-left corner
				  SRCCOPY		// raster operation code
				);
				if(chkMap(ROTSHO))
					durot();
				if(chkMap(SHOSAT))
					dusat();
				if(chkMap(SHOINSF))
					duinsf();
			}
			return 1;
		}
		if(ds->hwndItem==hBar&&ds->itemAction==ODA_DRAWENTIRE){

			if(hed.stchs)
				dubar();
			else
				FillRect(ds->hDC,&ds->rcItem,(HBRUSH)(COLOR_WINDOW+1));
			return 1;
		}
		if(ds->hwndItem==hbuts[HHID]&&ds->itemAction==ODA_DRAWENTIRE){

			ind=(buttonWid3-pcolsiz.cx)>>1;
			if(chkMap(HID)){

				FillRect(ds->hDC,&ds->rcItem,hbrUseCol[actcol]);
				SetBkColor(ds->hDC,useCol[actcol]);
			}
			else
				FillRect(ds->hDC,&ds->rcItem,(HBRUSH)(COLOR_BTNFACE+1));
			if(chkMap(TXTRED))
			{
				LoadString(hInst,IDS_TXWID,nam,MAX_PATH);
				sprintf(hlpbuf,nam,tscr.wid/PFGRAN);
				TextOut(ds->hDC,ind,1,hlpbuf,strlen(hlpbuf));;
			}
			else
				TextOut(ds->hDC,ind,1,stab[STR_PIKOL],strlen(stab[STR_PIKOL]));;
			return 1;
		}
		if(chkMap(WASTRAC)){

			for(ind=0;ind<3;ind++){

				if(ds->hwndItem==htrup[ind]){

					FillRect(ds->hDC,&ds->rcItem,trbrsh[ind]);
					upnum(ind);
					return 1;
				}
				if(ds->hwndItem==htrdwn[ind]){

					FillRect(ds->hDC,&ds->rcItem,trbrsh[ind]);
					dwnum(ind);
				}
				if(ds->hwndItem==hctrc[ind]){

					durct(trshft[ind],ds->rcItem);
					FillRect(ds->hDC,&midrct,trbrsh[ind]);
					dublk(ds->hDC);
					return 1;
				}
				if(ds->hwndItem==hstrc[ind]){

					tbrsh=hblk;
					strcpy(buf,stab[STR_OFF]);
					SetBkColor(ds->hDC,0);
					SetTextColor(ds->hDC,trgb[ind]);
					if(chkMap(trbits[ind])){

						tbrsh=trbrsh[ind];
						strcpy(buf,stab[STR_ON]);
						SetTextColor(ds->hDC,0);
						SetBkColor(ds->hDC,trgb[ind]);	
					}
					FillRect(ds->hDC,&ds->rcItem,tbrsh);
					TextOut(ds->hDC,1,1,buf,strlen(buf));
					return 1;
				}
				if(ds->hwndItem==htrnum){

					FillRect(ds->hDC,&ds->rcItem,trbrsh[colm]);
					SetBkColor(ds->hDC,trgb[colm]);	
					TextOut(ds->hDC,1,1,trinbuf,strlen(trinbuf));
					return 1;
				}
			}
		}
		else{

			for(ind=0;ind<16;ind++){

				if(ds->hwndItem==hDef[ind]){

					FillRect(ds->hDC,&ds->rcItem,hbrDefCol[ind]);
					if(chkCol(ind)){

						SetBkColor(ds->hDC,defCol[ind]);
						SetTextColor(ds->hDC,defTxt(ind));
						sprintf(buf,"%d",ind+1);
						len=strlen(buf);
						GetTextExtentPoint32(ds->hDC,buf,len,&txSiz);
						TextOut(ds->hDC,(buttonWid-txSiz.cx)>>1,0,buf,len);
					}
					return 1;
				}
				if(ds->hwndItem==hCol[ind]){

					FillRect(ds->hDC,&ds->rcItem,hbrUseCol[ind]);
					if(ind==actcol){

						SelectObject(ds->hDC,xPen);
						SetROP2(sdc, R2_NOTXORPEN);
						lin[0].x=lin[1].x=ds->rcItem.right>>1;
						lin[0].y=0;
						lin[1].y=ds->rcItem.bottom;
						Polyline(ds->hDC,lin,2);
						lin[0].y=lin[1].y=ds->rcItem.bottom>>1;
						lin[0].x=0;
						lin[1].x=ds->rcItem.right;
						Polyline(ds->hDC,lin,2);
						SetROP2(sdc,R2_COPYPEN);
					}
					return 1;
				}
			}
		}
		if(chkMap(BAKSHO)&&ds->itemAction==ODA_DRAWENTIRE){

			if(chkMap(THUMSHO)){

				for(ind=0;ind<4;ind++){

					if(ds->hwndItem==hvu[ind]&&ind<thumdcnt){

						ritbak(thumsel[ind],ds);
						rthumnam(ind);
						return 1;
					}
				}
			}
			else{
			
				for(ind=0;ind<OLDVER;ind++){

					if(ds->hwndItem==hvu[ind]){

						strcpy(nam,thrnam);
						ine=duth(nam);
						nam[ine]=(TCHAR)ind+'s';
						ritbak(nam,ds);
						return 1;
					}
				}
			}
		}
		break;

	case WM_SIZE:

		GetClientRect(hWnd,&mRct);
		switch(wParam){
		
		case SIZE_MAXIMIZED:

			setu(SAVMAX);
			break;

		case SIZE_MINIMIZED:

			rstu(SAVMAX);
			break;

		case SIZE_RESTORED:

			rstu(SAVMAX);
			chkirct();
			if(setMap(SIZED)){

				ine=0;
				ind=(double)scrPix.cx-30;
				if((unsigned)(mRct.right-mRct.left)>ind){

					ine=(scrPix.cx-ind)>>1;
					mRct.left=ine;
					mRct.right=scrPix.cx-ine;
				}
				ind=(double)scrPix.cy-30;
				if((unsigned)(mRct.bottom-mRct.top)>ind){

					ine=(scrPix.cy-ind)>>1;
					mRct.top=ine;
					mRct.bottom=scrPix.cy-ine;
				}
				if(ine)
					MoveWindow(hWnd,mRct.left,mRct.top,mRct.right-mRct.left,mRct.bottom-mRct.top,TRUE);
			}
			else{

				MoveWindow(hWnd,ini.irct.left,ini.irct.top,ini.irct.right-ini.irct.left,ini.irct.bottom-ini.irct.top,TRUE);
			}
			ShowWindow(hWnd,SW_SHOW);
			break;
		}
		GetClientRect(hWnd,&mRct);
		movStch();
		if(chkMap(ZUMED)){
		
			tdub=(double)scRct.bottom/(zRct.top-zRct.bottom);
			twid=scRct.right/tdub;
			if(twid+zRct.left>zum0.x){

				zRct.right=zum0.x;
				zRct.left=zum0.x-twid;
			}
			else
				zRct.right=twid+zRct.left;
		}
		else{

			zRct.left=zRct.bottom=0;
			zRct.right=zum0.x;
			zRct.top=zum0.y;
		}
		selCnt=0;
		setMap(RESTCH);
		if(chkMap(SELBOX))
			shft2box();
		if(chkMap(RUNPAT)){

			FillRect(sdc,&scRct,hStchBak);
			if(chkMap(ZUMED))
				runpnt=gpnt0;
			else
				runpnt=0;
		}
		return 1;

	case WM_MOVE:

		GetClientRect(hWnd,&mRct);
		if((mRct.right-mRct.left)<20){

			mRct.left=0;
			mRct.right=300;
		}
		if((mRct.bottom-mRct.top)<20){

			mRct.top=0;
			mRct.bottom=300;
		}
		movStch();
		if(chkMap(RUNPAT)){

			duzrat();
			runpnt=0;
			FillRect(rsdc,&scRct,hStchBak);
		}
		return 1;

	case WM_CLOSE:

		dun();
		if(chkMap(SAVEX))
			return 1;
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void sachk(){

	unsigned	ind,ine,bakclo;
	SATCON*		ts;
	TCHAR*		pchr;
	FRMHED*		tfrm;
	
	pchr=msgbuf;
	for(ind=0;ind<formpnt;ind++){

		tfrm=&formlst[ind];
		if(tfrm->typ==SAT&&tfrm->stpt){

			ts=tfrm->sacang.sac;
			for(ine=0;ine<tfrm->stpt;ine++){
			
				if(ts[ine].strt>tfrm->sids||ts[ine].fin>tfrm->sids){

					bakclo=clofind;
					clofind=ind;
					delsac(ind);
					clofind=bakclo;
				}
			}
		}
	}
	if(pchr!=msgbuf)
		shoMsg(msgbuf);
}

int	fltex(int cod){
	if (cod != 0x10) 
		return 0;

	feenableexcept(FE_ALL_EXCEPT);
	fesetround(FE_TONEAREST);

	return -1;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow){

	WNDCLASSEX		wc;
	LOGBRUSH		br;

	br.lbColor=COLOR_BACKGROUND+1;
	br.lbHatch=0;
	br.lbStyle=BS_SOLID;
	
	hInst=hInstance;
	wc.cbSize=			sizeof(WNDCLASSEX);
	wc.style=			CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW|CS_OWNDC;
	wc.lpfnWndProc=		(WNDPROC)WndProc;
	wc.cbClsExtra=		0;
	wc.cbWndExtra=		0;
	wc.hInstance=		hInst;
	wc.hIcon=			(HICON)LoadImage(hInst,MAKEINTRESOURCE(IDI_ICON1),IMAGE_ICON,
							32,32,LR_SHARED);
	wc.hCursor=			LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground=	(HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName=	MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName=	"thred";
	wc.hIconSm=			NULL;

	//to keep the compiler from complaining
	hPrevInstance;
	lpCmdLine;

	if(RegisterClassEx(&wc)){
		
		redini();
		if(ini.irct.right){

			hWnd=CreateWindow(
				"thred",
				"",
				WS_OVERLAPPEDWINDOW,
				ini.irct.left,
				ini.irct.right,
				ini.irct.right-ini.irct.left,
				ini.irct.bottom-ini.irct.top,
				0,
				0,
				hInstance,
				0);
		}
		else{

			hWnd=CreateWindow(
				"thred",
				"",
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				0,
				0,
				hInstance,
				0);
			GetClientRect(hWnd,&mRct);
			ini.irct.left=mRct.left;
			ini.irct.right=mRct.right;
			ini.irct.top=mRct.top;
			ini.irct.bottom=mRct.bottom;
		}
		init();
		if(chku(SAVMAX))
			ShowWindow(hWnd,SW_SHOWMAXIMIZED);
		else
			ShowWindow(hWnd,SW_SHOW);
		if(!*ini.desnam)
		{
			LoadString(hInst,IDS_UNAM,ini.desnam,50);
			getdes();
		}
		while(GetMessage(&msg,NULL,0,0)){

			setMap(SAVACT);
			if(!chkMsg())
				DispatchMessage(&msg);
			if(rstMap(FCHK))
				frmchkx();
			if(rstMap(RESTCH))
				redraw(hStch);
			if(rstMap(RELAYR))
				ritlayr();
			if(!chkMap(TXTRED))
				sachk();
			if(rstMap(DUMEN))
				DrawMenuBar(hWnd);
		}
		return 0;
	}
	return -1;
}
