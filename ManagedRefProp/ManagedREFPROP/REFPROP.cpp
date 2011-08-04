#include "StdAfx.h"
#include "REFPROP.h"

// the following functions and routines are instantiated only once
// through the dll life time
// ------------------------------------------------------------------


// Definitions of the Refprop types
typedef void (__stdcall *fp_SETUPDLLTYPE)(long&,char*,char*,char*,long&,char*,long,long,long,long);
typedef void (__stdcall *fp_INFOdllTYPE)(long&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&);
typedef void (__stdcall *fp_SATdllTYPE)(double&,double*,long&,double&,double&,double&,double*,double*,long&,char*, long);
typedef void (__stdcall *fp_ENTROENTHALdllTYPE)(double&,double&,double*,double&);

typedef void (__stdcall *fp_MASSMOLEFRACTIONdllTYPE)(double*,double*,double&);
typedef void (__stdcall *fp_CRITPdllTYPE)(double*,double&,double&,double&,long&,char*, long);
typedef void (__stdcall *fp_PSFL1dllTYPE)(double&,double&,double*,long&,double&,double&,long&,char*, long);
typedef void (__stdcall *fp_TPRHOdllTYPE)(double&,double&,double*,long&,long&,double&,long&,char* HERR, long LengthHERR);
typedef void (__stdcall *fp_PRESSdllTYPE)(double&,double&,double*,double&);
typedef void (__stdcall *fp_GIBBSdllTYPE)(double&,double&,double*,double&,double& GR);
typedef void (__stdcall *fp_CVCPdllTYPE)(double&,double&,double*,double&,double&);
typedef void (__stdcall *fp_THERMdllTYPE)(double&,double&,double*,double&,double&,double&,double&,double&,double&,double&,double&);
typedef void (__stdcall *fp_THERM2dllTYPE)(double&,double&,double*,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&);
typedef void (__stdcall *fp_TRNPRPdllTYPE)(double&,double&,double*,double&,double&,long&,char*, long);
typedef void (__stdcall *fp_2IVdllTYPE)(double&,double&,double*,double&);
typedef void (__stdcall *fp_LIMITXdllTYPE)(char*,double&,double&,double&,double*,double&,double&,double&,double&,long&,char*,long,long);
typedef void (__stdcall *fp_SETKTVdllTYPE)(long&,long&,char*,double&,char*,long&,char*,long,long,long);
typedef void (__stdcall *fp_GETKTVdllTYPE)(long&,long&,char*,double&,char*,char*,char*,char*,long ln1,long ln2,long ln3,long ln4,long ln5);
typedef void (__stdcall *fp_GETFIJdllTYPE)(char*,char*,char*,char*,long,long,long);

// Definition of pointers to the Refprop functions...
void (__stdcall *SETUPdll)(long& NumberOfComponents, char* HFILES, char* HFMIX, char* HRF, long& ierr, char* HERR, long l1, long l2,long l3,long l4);
void (__stdcall *INFOdll)(long& icomp, double& wm,double& ttp,double& tnbp,double& tc,double& pc,double& dc,double& zc,double& acf,double& dip,double& rgas);
void (__stdcall *SATTdll)(double& TK,double* X, long& KPH, double& PkPa, double& RHOF, double& RHOG, double* XLIQ, double* XVAP,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *SATPdll)(double& PkPa,double* X, long& KPH, double& TK, double& RHOF, double& RHOG, double* XLIQ, double* XVAP,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *ENTROdll)( double& TK,double& RHOMOLL,double* X, double& SJMOLK);
void (__stdcall *ENTHALdll)(double& TK,double& RHOMOLL,double* X, double& HJMOL);

void (__stdcall *TDFLSHdll)(double&,double&,double*,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,double&,double&,long&,char*, long);
void (__stdcall *TPFLSHdll)(double&,double&,double*,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,double&,double&,long&,char*, long);
void (__stdcall *PDFLSHdll)(double&,double&,double*,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,double&,double&,long&,char*, long);
void (__stdcall *DSFLSHdll)(double& RHOMOLL,double& SJMOLK, double* Z,double& TK,     double& PKPA,   double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,double& UJMOL,double& HJMOL, double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *DEFLSHdll)(double& RHOMOLL,double& UJMOL,  double* Z,double& TK,     double& PKPA,   double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,double& HJMOL,double& SJMOL, double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);


void (__stdcall *PEFLSHdll)(double& PKPA,   double& UJMOL,  double* Z,double& TK,     double& RHOMOL, double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,double& HJMOL,double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *DHFLSHdll)(double& RHOMOLL,double& HJMOL,  double* Z,double& TK,     double& PKPA,   double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,double& UJMOL,double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *PHFLSHdll)(double& PKPA,   double& HJMOL,  double* Z,double& TK,     double& RHOMOL, double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,double& UJMOL,double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *PSFLSHdll)(double& PKPA,   double& SJMOLK, double* Z,double& TK,     double& RHOMOL, double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,double& UJMOL,double& HJMOL, double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *THFLSHdll)(double& TK,     double& HJMOL,  double* Z,long& kr, double& PKPA,double& RHOMOL,double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,  double& U,    double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *TEFLSHdll)(double& TK,     double& HJMOL,  double* Z,long& kr, double& PKPA,double& RHOMOL,double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,  double& U,    double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *TSFLSHdll)(double& TK,     double& HJMOL,  double* Z,long& kr, double& PKPA,double& RHOMOL,double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& QUAL,  double& U,    double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *PQFLSHdll)(double& PKPA,   double& QUAL,   double* Z,long& kq, double& TK,  double& RHOMOL,double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& UJMOL, double& HJMOL,double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);
void (__stdcall *TQFLSHdll)(double& TK,     double& QUAL,   double* Z,long& kq, double& PKPA,double& RHOMOL,double& RHOFMOL,double& RHOGMOL,double* X,double* Y, double& UJMOL, double& HJMOL,double& SJMOLK,double& CV,double& CP,double& W,long& ierr, char* HERR, long LengthHERR);

//defining general flash routine
typedef void (__stdcall *fp_TDPFLSHdllTYPE)(double&,double&,double*,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,double&,double&,long&,char*, long);
typedef void (__stdcall *fp_DEHSFLSHdllTYPE)(double&,double&,double*,double&,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,double&,long&,char*, long);
typedef void (__stdcall *fp_TQHFLSHdllTYPE)(double&,double&,double*,long&,double&,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,double&,long&,char*, long);

typedef void (__stdcall *fp_HSFLSHdllTYPE)(double&,double&,double*,double&,double&,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,long&,char*, long);
void (__stdcall *HSFLSHdll) (double&,double&,double*,double&,double&,double&,double&,double&,double*,double*,double&,double&,double&,double&,double&,long&,char*, long);

void (__stdcall *XMASSdll)(double* X,       double* XKG,double& WMOL);
void (__stdcall *XMOLEdll)(double* X,       double* XKG,double& WMOL);
void (__stdcall *CRITPdll)(double* X,       double& TCRIT,  double& PCRIT,double& RHOCRIT, long& ierr,char* HERR, long LengthHERR);
void (__stdcall *PSFL1dll)(double& PKPA,    double& SJMOLK, double* Z,  long& KPH,   double& TK,  double& RHOMOL,long& ierr,char* HERR, long LengthHERR);
void (__stdcall *TPRHOdll)(double& TK,double& PKPA,double* X,long& KPH,long& KGUESS, double& RHO, long& ierr,char* HERR, long LengthHERR);
void (__stdcall *PRESSdll)(double& TK,      double& RHOMOLL,double* X, double& PKPA);
void (__stdcall *GIBBSdll)(double& TK,      double& RHOMOLL,double* X, double& AR,      double& GR);
void (__stdcall *CVCPdll)(double& TK,      double& RHOMOLL,double* X, double& CVJMOLK, double& CPJMOLK);
void (__stdcall *THERMdll)(double& TK,      double& RHOMOLL,double* X, double& PKPA,  double& UJMOL,double& HJMOL,double& SJMOLK, double& CVJMOLK, double& CPJMOLK, double& GAMMAMS, double& HJTKKPA);
void (__stdcall *THERM2dll)(double& TK,      double& RHOMOLL,double* X, double& PKPA,  double& UJMOL,double& HJMOL,double& SJMOLK, double& CVJMOLK, double& CPJMOLK, double& OMEGA, double& Z, double& HJTKKPA,double& aH,double& G,double& xkappa,double& beta,double& dPdD,double& d2PdD2,double& dPdT,double& dDdT,double& dDdP,double& spare1,double& spare2,double& spare3,double& spare4);
void (__stdcall *TRNPRPdll)(double& TK,      double& RHOMOLL,double* X, double& ETA,   double& TCX,  long& ierr,char* herr, long LengthHERR);

void (__stdcall *DHDTdll)(double& TK,      double& RHOMOLL,double* X, double& dHdT);
void (__stdcall *DPDDdll)(double& TK,      double& RHOMOLL,double* X, double& DPDRHO);
void (__stdcall *DPDD2dll)(double& TK,      double& RHOMOLL,double* X, double& DP2DD2);
void (__stdcall *DPDTdll)(double& TK,      double& RHOMOLL,double* X, double& DPT);
void (__stdcall *DDDPdll)(double& TK,      double& RHOMOLL,double* X, double& DRHODP);
void (__stdcall *DDDTdll)(double& TK,      double& RHOMOLL,double* X, double& DRHODT);
void (__stdcall *FGCTYdll)(double& TK,      double& RHOMOLL,double* X, double& FUGACITY);// The following ifdef block is the standard way of creating macros which make exporting
void (__stdcall *LIMITXdll)(char* htyp,double& TinK,double& rhoin_Mol,double& PinkPa, double* X, double& TminK, double& TmaxK, double& rhomaxMol,double& PmaxkPa, long& ierr,char* herr,long lnhtyp,long lnherr);
void (__stdcall *SETKTVdll)(long& icomp, long& jcomp, char* hmodij,double& fij,char* hfmix,long& ierr,char* herr,long Lengthhmodij,long Lengthhfmix,long LengthHERR);
void (__stdcall *GETKTVdll)(long& icomp, long& jcomp,char* hmodij,double& fij,char*  hfmix,char* hfij,char* hbinp,char* hmxrul,long ln1,long ln2,long ln3,long ln4,long ln5);
void (__stdcall *GETFIJdll)(char* hmodij,char* fij,char* hfij,char* hmxrul,long ln1,long ln2,long ln3);



HINSTANCE RefpropdllInstance;
bool LibraryPrepared = false;  // when set to true the dll has been loaded and we know the locations of the functinos

//because the REFPROP Library is not OOP neither have a handle it is just one fluid or mixture
// and all of its function is working on this set
// so to workaround this I have to store the current mixture or fluid globally in the native heap
// and also evrey native class will have its copy of mixture or fluid
// when calling the class methods it will first compare its refregerant with 
// then one stored in heap and load the desired fluid maintain the state of this 
// refrigerant if necessary
char CurrentLibrary_Fluid_Name[10000];


//notes:
//	for simplicity i am assuming that fluid folder is always under 
//	the current dll library

char* Library_Fluids_Folder = "Fluids";

#pragma warning(disable:4482)   //to prevent warning of using full qualified name, I need it because I duplicate the names in native and managed code


RefProp::RefProp(void)
{
	CurrentUnitsBasis = Molar_Basis;
	Reload=false;

	bool UseIntelFortran = false;


	if(!LibraryPrepared)
	{
		if(UseIntelFortran)
		{
			RefpropdllInstance = LoadLibrary(L"intelRefProp.dll");

			SETUPdll = (fp_SETUPDLLTYPE) GetProcAddress(RefpropdllInstance,"SETUP");

			//Utility routines
			INFOdll = (fp_INFOdllTYPE) GetProcAddress(RefpropdllInstance,"INFO");

			//saturation routines
			SATTdll = (fp_SATdllTYPE) GetProcAddress(RefpropdllInstance,"SATT");
			SATPdll = (fp_SATdllTYPE) GetProcAddress(RefpropdllInstance,"SATP");

			//
			ENTROdll = (fp_ENTROENTHALdllTYPE) GetProcAddress(RefpropdllInstance,"ENTRO");
			ENTHALdll = (fp_ENTROENTHALdllTYPE) GetProcAddress(RefpropdllInstance,"ENTHAL");

			//flash routines
			TPFLSHdll = (fp_TDPFLSHdllTYPE) GetProcAddress(RefpropdllInstance,"TPFLSH");
			TDFLSHdll = (fp_TDPFLSHdllTYPE) GetProcAddress(RefpropdllInstance,"TDFLSH");
			THFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"THFLSH");
			TEFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"TEFLSH");
			TSFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"TSFLSH");
			TQFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"TQFLSH");

			PDFLSHdll = (fp_TDPFLSHdllTYPE) GetProcAddress(RefpropdllInstance,"PDFLSH");
			PEFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PEFLSH");
			PHFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PHFLSH");
			PSFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PSFLSH");
			PQFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PQFLSH");

			DHFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"DHFLSH");
			DSFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"DSFLSH");
			DEFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"DEFLSH");

			HSFLSHdll = (fp_HSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"HSFLSH");


			//
			XMASSdll =  (fp_MASSMOLEFRACTIONdllTYPE)GetProcAddress(RefpropdllInstance,"XMASS");
			XMOLEdll =  (fp_MASSMOLEFRACTIONdllTYPE)GetProcAddress(RefpropdllInstance,"XMOLE");
			CRITPdll =  (fp_CRITPdllTYPE)GetProcAddress(RefpropdllInstance,"CRITP");
			PSFL1dll =  (fp_PSFL1dllTYPE)GetProcAddress(RefpropdllInstance,"PSFL1");
			TPRHOdll = (fp_TPRHOdllTYPE)GetProcAddress(RefpropdllInstance,"TPRHO");
			PRESSdll = (fp_PRESSdllTYPE)GetProcAddress(RefpropdllInstance,"PRESS");
			GIBBSdll = (fp_GIBBSdllTYPE)GetProcAddress(RefpropdllInstance,"GIBBS");
			CVCPdll = (fp_CVCPdllTYPE)GetProcAddress(RefpropdllInstance,"CVCP");
			THERMdll = (fp_THERMdllTYPE)GetProcAddress(RefpropdllInstance,"THERM");
			THERM2dll = (fp_THERM2dllTYPE)GetProcAddress(RefpropdllInstance,"THERM2");
			TRNPRPdll = (fp_TRNPRPdllTYPE)GetProcAddress(RefpropdllInstance,"TRNPRP");
			DHDTdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DHDT");
			DPDDdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DPDD");
			DPDD2dll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DPDD2");
			DPDTdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DPDT");
			DDDPdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DDDP");
			DDDTdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DDDT");
			FGCTYdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"FGCTY");
			LIMITXdll = (fp_LIMITXdllTYPE)GetProcAddress(RefpropdllInstance,"LIMITX");
			SETKTVdll = (fp_SETKTVdllTYPE)GetProcAddress(RefpropdllInstance,"SETKTV");
			GETKTVdll = (fp_GETKTVdllTYPE)GetProcAddress(RefpropdllInstance,"GETKTV");
			GETFIJdll = (fp_GETFIJdllTYPE)GetProcAddress(RefpropdllInstance,"GETFIJ");


		}
		else
		{
			//use the standard library from refprop.dll
			//the only difference is that functions is having postfix "dll"

			RefpropdllInstance = LoadLibrary(L"refprop.dll");

			SETUPdll = (fp_SETUPDLLTYPE) GetProcAddress(RefpropdllInstance,"SETUPdll");

			//Utility routines
			INFOdll = (fp_INFOdllTYPE) GetProcAddress(RefpropdllInstance,"INFOdll");

			//saturation routines
			SATTdll = (fp_SATdllTYPE) GetProcAddress(RefpropdllInstance,"SATTdll");
			SATPdll = (fp_SATdllTYPE) GetProcAddress(RefpropdllInstance,"SATPdll");

			//
			ENTROdll = (fp_ENTROENTHALdllTYPE) GetProcAddress(RefpropdllInstance,"ENTROdll");
			ENTHALdll = (fp_ENTROENTHALdllTYPE) GetProcAddress(RefpropdllInstance,"ENTHALdll");

			//flash routines
			TPFLSHdll = (fp_TDPFLSHdllTYPE) GetProcAddress(RefpropdllInstance,"TPFLSHdll");
			TDFLSHdll = (fp_TDPFLSHdllTYPE) GetProcAddress(RefpropdllInstance,"TDFLSHdll");
			THFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"THFLSHdll");
			TEFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"TEFLSHdll");
			TSFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"TSFLSHdll");
			TQFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"TQFLSHdll");

			PDFLSHdll = (fp_TDPFLSHdllTYPE) GetProcAddress(RefpropdllInstance,"PDFLSHdll");
			PEFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PEFLSHdll");
			PHFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PHFLSHdll");
			PSFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PSFLSHdll");
			PQFLSHdll = (fp_TQHFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"PQFLSHdll");

			DHFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"DHFLSHdll");
			DSFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"DSFLSHdll");
			DEFLSHdll = (fp_DEHSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"DEFLSHdll");

			HSFLSHdll = (fp_HSFLSHdllTYPE)GetProcAddress(RefpropdllInstance,"HSFLSHdll");


			//
			XMASSdll =  (fp_MASSMOLEFRACTIONdllTYPE)GetProcAddress(RefpropdllInstance,"XMASSdll");
			XMOLEdll =  (fp_MASSMOLEFRACTIONdllTYPE)GetProcAddress(RefpropdllInstance,"XMOLEdll");
			CRITPdll =  (fp_CRITPdllTYPE)GetProcAddress(RefpropdllInstance,"CRITPdll");
			PSFL1dll =  (fp_PSFL1dllTYPE)GetProcAddress(RefpropdllInstance,"PSFL1dll");
			TPRHOdll = (fp_TPRHOdllTYPE)GetProcAddress(RefpropdllInstance,"TPRHOdll");
			PRESSdll = (fp_PRESSdllTYPE)GetProcAddress(RefpropdllInstance,"PRESSdll");
			GIBBSdll = (fp_GIBBSdllTYPE)GetProcAddress(RefpropdllInstance,"GIBBSdll");
			CVCPdll = (fp_CVCPdllTYPE)GetProcAddress(RefpropdllInstance,"CVCPdll");
			THERMdll = (fp_THERMdllTYPE)GetProcAddress(RefpropdllInstance,"THERMdll");
			THERM2dll = (fp_THERM2dllTYPE)GetProcAddress(RefpropdllInstance,"THERM2dll");
			TRNPRPdll = (fp_TRNPRPdllTYPE)GetProcAddress(RefpropdllInstance,"TRNPRPdll");
			DHDTdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DHDTdll");
			DPDDdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DPDDdll");
			DPDD2dll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DPDD2dll");
			DPDTdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DPDTdll");
			DDDPdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DDDPdll");
			DDDTdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"DDDTdll");
			FGCTYdll = (fp_2IVdllTYPE)GetProcAddress(RefpropdllInstance,"FGCTYdll");
			LIMITXdll = (fp_LIMITXdllTYPE)GetProcAddress(RefpropdllInstance,"LIMITXdll");
			SETKTVdll = (fp_SETKTVdllTYPE)GetProcAddress(RefpropdllInstance,"SETKTVdll");
			GETKTVdll = (fp_GETKTVdllTYPE)GetProcAddress(RefpropdllInstance,"GETKTVdll");
			GETFIJdll = (fp_GETFIJdllTYPE)GetProcAddress(RefpropdllInstance,"GETFIJdll");


		}

		LibraryPrepared = true;
		
	}

}

RefProp::~RefProp()
{

}
void RefProp::LoadMixedFluid(vector<string> fluids, vector<double> fractions)
{
	
	if(!Reload)
	{
		if(fluids.size() != fractions.size()) throw "Number of fractions doesn't equal number of fluids";

		if(fluids.size()>20) throw "Number of mixtures exceeds the library limit > 20 fluid";

		nc = fluids.size();

		vector<string>::iterator fli = fluids.begin();


		_fluids = fluids;
		_fractions = fractions;

		char dfluid[10000] = ""; //temporary variable to store the fluid text

		
		// first fluid
		//strcat_s(dfluid,10000, ccd);
		//strcat_s(dfluid,10000, "\\");
		strcat_s(dfluid,10000, Library_Fluids_Folder);
		strcat_s(dfluid,10000, "\\");
		strcat_s(dfluid,10000, (*fli).c_str());

		// advance to rest of fluids
		++fli;
		for (; fli != fluids.end(); ++fli) {

			strcat_s(dfluid,10000, "|");
			//strcat_s(dfluid,10000, ccd);
			//strcat_s(dfluid,10000, "\\");
			strcat_s(dfluid,10000, Library_Fluids_Folder);
			strcat_s(dfluid,10000, "\\");
			strcat_s(dfluid,10000, (*fli).c_str());
		}
		strcat_s(dfluid,10000, "|");  // add | in the end because the library goes crazy when you don't append this to the latest fluid :)

		vector<double>::iterator fri = fractions.begin();
		int iy = 0;
		for(;fri != fractions.end(); ++fri){
			x[iy] = *fri;
			XLIQ[iy] = 0.0;
			XVAP[iy] = 0.0;
			iy++;
		}


		// setup the library
		strcpy_s(hfld, 10000, dfluid);

		//hfld = (char*) CurrentFluid.c_str();

		char bnc[255]="";
		//strcat_s(bnc,255, ccd);
		//strcat_s(bnc,255, "\\");
		strcat_s(bnc,255,Library_Fluids_Folder);
		strcat_s(bnc,255,"\\");
		strcat_s(bnc,255,"HMX.BNC");

		strcpy_s(hfmix,255,bnc);

		strcpy_s(hrf,4,"DEF");
		
		IsPureFluid = false;
		IsMixedFluid = true;

		SETUPdll(nc, hfld, hfmix, hrf, ierr, herr, 10000, 255, 3, 255);

		INFOdll(nc, wm, ttp, tnbp, tc, pc, Dc, Zc, acf, dip, Rgas);
		Reload = false;
	}
	else
	{
		SETUPdll(nc, hfld, hfmix, hrf, ierr, herr, 10000, 255, 3, 255);
	}

	strcpy_s(CurrentLibrary_Fluid_Name, 10000, hfld);

}

void RefProp::LoadPureFluid(char* FluidName)
{

	if(!Reload)
	{
		//try to load this fluid and then set the current library to it after 
		//successful load

		Fluid_Name = FluidName;

		nc=1;

		//preparing variables that depend on number of components


		char dfluid[10000]="";
		strcat_s(dfluid,10000, Library_Fluids_Folder);
		strcat_s(dfluid,10000, "\\");
		strcat_s(dfluid,10000, FluidName);

		x[0] = 1.0;
		XLIQ[0] = 0.0;
		XVAP[0] = 0.0;

		strcpy_s(hfld, 10000, dfluid);

		//hfld = (char*) CurrentFluid.c_str();

		char bnc[255]="";
		strcat_s(bnc,255,Library_Fluids_Folder);
		strcat_s(bnc,255,"\\");
		strcat_s(bnc,255,"HMX.BNC");

		strcpy_s(hfmix,255,bnc);

		strcpy_s(hrf,4,"DEF");
		
		IsPureFluid = true;
		IsMixedFluid = false;

		SETUPdll(nc, hfld, hfmix, hrf, ierr, herr, 10000, 255, 3, 255);

		INFOdll(nc,wm,ttp,tnbp,tc,pc,Dc,Zc,acf,dip,Rgas);

		Reload = false;
	}
	else
	{
		SETUPdll(nc, hfld, hfmix, hrf, ierr, herr, 10000, 255, 3, 255);
	}

	strcpy_s(CurrentLibrary_Fluid_Name,10000,hfld);
}







void RefProp::EnsureCurrentFluid(void)
{
	//compare the instance fluid with the library fluid and load this
	// instance if required

	if (strcmp(CurrentLibrary_Fluid_Name, hfld) != 0)
	{
		Reload = true;   //don't allocate memory again for allocated ones
		if(IsPureFluid)
		{
			this->LoadPureFluid(Fluid_Name);
		}
		else if(IsMixedFluid)
		{
			this->LoadMixedFluid(_fluids, _fractions);
		}
	}
}

double RefProp::GetMolecularWeight(void)
{
	return wm;
}

double RefProp::GetTriplePointTemperature(void)
{
	return ttp;
}

double RefProp::GetNormalBoilingPointTemperature(void)
{
	return tnbp;
}

double RefProp::GetCriticalTemperature(void)
{
	return tc;
}

double RefProp::GetCriticalPressure(void)
{
	return pc;
}

double RefProp::GetCriticalDensity(void)
{
	return Dc;
}

double RefProp::GetCriticalPointCompressibility(void)
{
	return Zc;
}

double RefProp::GetAccentricFactor(void)
{
	return acf;
}

double RefProp::GetDipoleMoment(void)
{
	return dip;
}

double RefProp::GetGasConstatnt_R(void)
{
	return Rgas;
}

double RefProp::GetSaturatedPressure(double Temperature)
{

	EnsureCurrentFluid(); // must be called before any code

	long kph = 2;  //Vapor

	SATTdll(Temperature, x,kph,p,rhol,rhov,XLIQ,XVAP,ierr,herr,255);	

	t=Temperature;

	return p;
}

double RefProp::GetSaturatedTemperature(double Pressure)
{
	EnsureCurrentFluid(); // must be called before any code

	long kph = 2; // Vapor
	
	SATPdll(Pressure, x,kph,t,rhol,rhov,XLIQ,XVAP,ierr,herr,255);	
	p = Pressure;
	return t;
}

void RefProp::GetFlashProperties(ThermoProperties Property_1,double Value_1,ThermoProperties Property_2,double Value_2)
{

	//specify the required function


	//double z[1] = {1.0}; //replace with x  it is composition array
	//double x[1] = {0.0}; //replace with xliq
	//double y[1] = {0.0}; //replace with xvap


	EnsureCurrentFluid();

	double mw = GetMolecularWeight();

	long kq=(long)CurrentUnitsBasis;  // should be driven from class mass/molar basis
	long kr=1;



	//First T  with all variants
	if(Property_1 == Temperature)
	{
		t=Value_1;

		if(Property_2 == Pressure)
		{
			p=Value_2;
			TPFLSHdll(t, p, x,D,rhol,rhov,XLIQ,XVAP,q,e,h,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Density)
		{
			D=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) D = D / mw;
			TDFLSHdll (t,D,x,p,rhol,rhov,XLIQ,XVAP,q,e,h,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == InternalEnergy)
		{
			e=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) e = e * mw;
			TEFLSHdll (t,e,x,kr,p,D,rhol,rhov,XLIQ,XVAP,q,h,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Enthalpy)
		{
			h=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) h = h * mw;
			THFLSHdll (t,h,x,kr,p,D,rhol,rhov,XLIQ,XVAP,q,e,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Entropy)
		{
			s=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) s = s * mw;
			TSFLSHdll (t,s,x,kr,p,D,rhol,rhov,XLIQ,XVAP,q,e,h,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Quality)
		{
			q=Value_2;
			TQFLSHdll (t,q,x,kq,p,D,rhol,rhov,XLIQ,XVAP,e,h,s,cv,cp,w,ierr,herr,255);
		}
	}
	if(Property_1 == Pressure && Property_2 == Temperature)
	{
		t=Value_2;
		p=Value_1;
		TPFLSHdll(t, p, x,D,rhol,rhov,XLIQ,XVAP,q,e,h,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Density && Property_2 == Temperature)
	{
		t=Value_2;
		D=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) D = D / mw;
		TDFLSHdll (t,D,x,p,rhol,rhov,XLIQ,XVAP,q,e,h,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == InternalEnergy && Property_2 == Temperature)
	{
		t=Value_2;
		e=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) e = e * mw;
		TEFLSHdll (t,e,x,kr,p,D,rhol,rhov,XLIQ,XVAP,q,h,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Enthalpy && Property_2 == Temperature)
	{
		t=Value_2;
		h=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) h = h * mw;
		THFLSHdll (t,h,x,kr,p,D,rhol,rhov,XLIQ,XVAP,q,e,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Entropy && Property_2 == Temperature)
	{
		t=Value_2;
		s=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) s = s * mw;
		TSFLSHdll (t,s,x,kr,p,D,rhol,rhov,XLIQ,XVAP,q,e,h,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Quality && Property_2 == Temperature)
	{
		t=Value_2;
		q=Value_1;
		TQFLSHdll (t,q,x,kq,p,D,rhol,rhov,XLIQ,XVAP,e,h,s,cv,cp,w,ierr,herr,255);
	}

	//Second all P Variants
	if(Property_1 == Pressure)
	{
		p=Value_1;

		if(Property_2 == Density)
		{
			D=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) D = D / mw;
			PDFLSHdll (p,D,x,t,rhol,rhov,XLIQ,XVAP,q,e,h,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == InternalEnergy)
		{
			e=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) e = e * mw;
			PEFLSHdll (p,e,x,t,D,rhol,rhov,XLIQ,XVAP,q,h,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Enthalpy)
		{
			h=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) h = h * mw;
			PHFLSHdll (p,h,x,t,D,rhol,rhov,XLIQ,XVAP,q,e,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Entropy)
		{
			s=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) s = s * mw;
			PSFLSHdll (p,s,x,t,D,rhol,rhov,XLIQ,XVAP,q,e,h,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Quality)
		{
			q=Value_2;
			PQFLSHdll (p,q,x,kq,t,D,rhol,rhov,XLIQ,XVAP,e,h,s,cv,cp,w,ierr,herr,255);
		}
	}
	
	if(Property_1 == Density && Property_2 == Pressure)
	{
		p=Value_2;
		D=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) D = D / mw;
		PDFLSHdll (p,D,x,t,rhol,rhov,XLIQ,XVAP,q,e,h,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == InternalEnergy && Property_2 == Pressure)
	{
		p=Value_2;
		e=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) e = e * mw;
		PEFLSHdll (p,e,x,t,D,rhol,rhov,XLIQ,XVAP,q,h,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Enthalpy && Property_2 == Pressure)
	{
		p=Value_2;
		h=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) h = h * mw;
		PHFLSHdll (p,h,x,t,D,rhol,rhov,XLIQ,XVAP,q,e,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Entropy && Property_2 == Pressure)
	{
		p=Value_2;
		s=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) s = s * mw;
		PSFLSHdll (p,s,x,t,D,rhol,rhov,XLIQ,XVAP,q,e,h,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Quality && Property_2 == Pressure)
	{
		p=Value_2;
		q=Value_1;
		PQFLSHdll (p,q,x,kq,t,D,rhol,rhov,XLIQ,XVAP,e,h,s,cv,cp,w,ierr,herr,255);
	}

	//Third all Density rotines
	if(Property_1 == Density)
	{
		D=Value_1;
		if(CurrentUnitsBasis == Mass_Basis) D = D / mw;
		if(Property_2 == InternalEnergy)
		{
			e=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) e = e * mw;
			DEFLSHdll (D,e,x,t,p,rhol,rhov,XLIQ,XVAP,q,h,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Enthalpy)
		{
			h=Value_2;
			if(CurrentUnitsBasis == Mass_Basis) h = h * mw;
			DHFLSHdll (D,h,x,t,p,rhol,rhov,XLIQ,XVAP,q,e,s,cv,cp,w,ierr,herr,255);
		}

		if(Property_2 == Entropy)
		{
			s = Value_2;
			if(CurrentUnitsBasis == Mass_Basis) s = s * mw; 
			DSFLSHdll (D,s,x,t,p,rhol,rhov,XLIQ,XVAP,q,e,h,cv,cp,w,ierr,herr,255);
		}
	}

	if(Property_1 == InternalEnergy && Property_2 == Density)
	{
		D=Value_2;
		e=Value_1;
		if(CurrentUnitsBasis == Mass_Basis)
		{
			D = D / mw;
			e = e * mw;
		}
		DEFLSHdll (D,e,x,t,p,rhol,rhov,XLIQ,XVAP,q,h,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Enthalpy && Property_2 == Density)
	{
		D=Value_2;
		h=Value_1;
		if(CurrentUnitsBasis == Mass_Basis)
		{
			D = D / mw;
			h = h * mw;
		}
		DHFLSHdll (D,h,x,t,p,rhol,rhov,XLIQ,XVAP,q,e,s,cv,cp,w,ierr,herr,255);
	}

	if(Property_1 == Entropy && Property_2 == Density)
	{
		D=Value_2;
		s=Value_1;
		if(CurrentUnitsBasis == Mass_Basis)
		{
			D = D / mw;
			s = s * mw;
		}
		DSFLSHdll (D,s,x,t,p,rhol,rhov,XLIQ,XVAP,q,e,h,cv,cp,w,ierr,herr,255);
	}

	//Fourth H-S routine
	if(Property_1 == Enthalpy && Property_2 == Entropy)
	{
		h=Value_1;
		s=Value_2;
		if(CurrentUnitsBasis == Mass_Basis)
		{
			h = h * mw;
			s = s * mw;
		}
		HSFLSHdll (h,s,x,t,p,D,rhol,rhov,XLIQ,XVAP,q,e,cv,cp,w,ierr,herr,255);
	}
	if(Property_1 == Entropy && Property_2 == Enthalpy)
	{
		h=Value_2;
		s=Value_1;
		if(CurrentUnitsBasis == Mass_Basis)
		{
			h = h * mw;
			s = s * mw;
		}
		HSFLSHdll (h,s,x,t,p,D,rhol,rhov,XLIQ,XVAP,q,e,cv,cp,w,ierr,herr,255);
	}

	

	//check current basis and calculate
	//if mass basis do conversion

	if(CurrentUnitsBasis == Mass_Basis)
	{
		D = D * mw;
		e = e / mw;
		h = h / mw;
		s = s / mw;
		cv = cv / mw;
		cp = cp / mw;
		rhol = rhol * mw;
		rhov = rhov * mw;

	}

}


void RefProp::ThermalProperties(double Temperature, double Density)
{

	EnsureCurrentFluid();

	double mw = GetMolecularWeight();


	if(CurrentUnitsBasis == UnitsBasis::Mass_Basis) 
	{
		Density = Density / mw; // back to molar basis
	}

	THERMdll(Temperature, Density,x,p,e,h,s,cv,cp,w,hjt);

	t = Temperature;
	D = Density;


	if(CurrentUnitsBasis == UnitsBasis::Mass_Basis)
	{
		Density = Density * mw;
		e = e / mw;
		h = h / mw;
		s = s / mw;
		cv = cv / mw;
		cp = cp / mw;
	}
}
