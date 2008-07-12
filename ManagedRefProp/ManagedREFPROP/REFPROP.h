#pragma once
#include <string>
using namespace std;




//the class which will serve for REFPROP code
// this class will be instantiated in the managed class
// why am I doing this
// I noticed from another application that to prevent unexpected exceptions
// you should only host an umanaged pointer in managed class
// so that I am trying to solve it here


#define maxcomposition 20

class REFPROP
{
public:
	enum ThermoProperties
	{
		Temperature     = 1,		// 00000001
		Pressure        = 2,		// 00000010
		Density         = 4,		// 00000100
		InternalEnergy  = 8,		// 00001000
		Enthalpy		= 16,       // 00010000
		Entropy			= 32,       // 00100000
		Quality			= 64        // 01000000
	};	
	
	enum UnitsBasis
	{
		Molar_Basis = 1,
		Mass_Basis = 2
	};


public:
	char herr[255];
	long ierr;

	UnitsBasis CurrentUnitsBasis;

private:
	long nc;   // number of components
	double x[maxcomposition];    // this is array of components  x[nc]


	char hfld[10000]; // the full address of the fluid file
	char hfmix[255];
	char hrf[4];


	bool IsPureFluid;
	bool Reload;


	char* Fluid_Name;

public:
	//INFO variables  cached 
	double wm,ttp,tnbp,tc,pc,Dc,Zc,acf,dip,Rgas;

	//saturation variables
	double XLIQ[maxcomposition], XVAP[maxcomposition];

	double rhol, rhov;
//c     rhol--molar density [mol/L] of saturated liquid
//c     rhov--molar density [mol/L] of saturated vapor
//c     xliq--liquid phase composition [array of mol frac]
//c     xvap--vapor phase composition [array of mol frac]

	/*---------------------------------------------------------------------*/

	//for flash and other routines
	double t,p,D,q,e,h,s,cv,cp,w,hjt;


//	c  additional input--required for all routines
//c        z--overall (bulk) composition [array of mol frac]  which is our x in class

	//c  outputs--one, two, or all of the following, depending on the inputs:
	//c        t--temperature [K]
	//c        p--pressure [kPa]
	//c        D--overall (bulk) molar density [mol/L]
	//c
	//c  additional outputs--common to all routines
	//c       Dl--molar density [mol/L] of the liquid phase  ====   rhol
	//c       Dv--molar density [mol/L] of the vapor phase   ====   rhov
	//c           if only one phase is present, Dl = Dv = D
	//c        x--composition of liquid phase [array of mol frac]   ==== XLIQ
	//c        y--composition of vapor phase [array of mol frac]    ==== XVAP
	//c           if only one phase is present, x = y = z
	//c
	//c  additional output--common to all routines except TQFLSH and PQFLSH
	//c        q--vapor quality on a MOLAR basis [moles vapor/total moles]
	//c           q < 0 indicates subcooled (compressed) liquid
	//c           q = 0 indicates saturated liquid
	//c           q = 1 indicates saturated vapor
	//c           q > 1 indicates superheated vapor
	//c           q = 998 superheated vapor, but quality not defined (t > Tc)
	//c           q = 999 indicates supercritical state (t > Tc) and (p > Pc)
	//c
	//c  additional outputs--common to all routines, except that input
	//c                      quantities are not repeated
	//c        e--overall (bulk) internal energy [J/mol]
	//c        h--overall (bulk) enthalpy [J/mol]
	//c        s--overall (bulk) entropy [J/mol-K]
	//c       Cv--isochoric (constant V) heat capacity [J/mol-K]
	//c       Cp--isobaric (constant p) heat capacity [J/mol-K]
	//c        w--speed of sound [m/s]
	//c           Cp, w are not defined for 2-phase states
	//c           in such cases, a flag = -9.99998d6 is returned
	//c     ierr--error flag:  0 = successful
	//c                        1 = Tin < Tmin
	//c                        4 = Pin < 0
	//c                        5 = T and P out of range
	//c                        8 = x out of range (component and/or sum < 0
	//c                            or > 1)
	//c                        9 = x and T out of range
	//c                       12 = x out of range and P < 0
	//c                       13 = x and T and P out of range
	//c     herr--error string (character*255 variable if ierr<>0)





public:

	REFPROP(void);
	~REFPROP();


	void LoadPureFluid(char* FluidName); //result in nc=1
	//void LoadMixture();


	void EnsureCurrentFluid(void);


	/* Fluid INFO */

	double GetMolecularWeight(void);
	double GetTriplePointTemperature(void);
	double GetNormalBoilingPointTemperature(void);
	double GetCriticalTemperature(void);
	double GetCriticalPressure(void);
	double GetCriticalDensity(void);
	double GetCriticalPointCompressibility(void);
	double GetAccentricFactor(void);
	double GetDipoleMoment(void);
	double GetGasConstatnt_R(void);

	// saturation

	double GetSaturatedPressure(double Temperature);
	double GetSaturatedTemperature(double Pressure);

	//flash routines

		/*
	      subroutine TPFLSH (t,p,z,D,Dl,Dv,x,y,q,e,h,s,cv,cp,w,ierr,herr)
		  subroutine TDFLSH (t,D,z,p,Dl,Dv,x,y,q,e,h,s,cv,cp,w,ierr,herr)
		  subroutine TEFLSH (t,e,z,kr,p,D,Dl,Dv,x,y,q,h,s,cv,cp,w,ierr,herr)
		  subroutine THFLSH (t,h,z,kr,p,D,Dl,Dv,x,y,q,e,s,cv,cp,w,ierr,herr)
		  subroutine TSFLSH (t,s,z,kr,p,D,Dl,Dv,x,y,q,e,h,cv,cp,w,ierr,herr)

		  subroutine TQFLSH (t,q,z,kq,p,D,Dl,Dv,x,y,e,h,s,cv,cp,w,ierr,herr)



		  subroutine PDFLSH (p,D,z,t,Dl,Dv,x,y,q,e,h,s,cv,cp,w,ierr,herr)
		  subroutine PEFLSH (p,e,z,t,D,Dl,Dv,x,y,q,h,s,cv,cp,w,ierr,herr)
		  subroutine PHFLSH (p,h,z,t,D,Dl,Dv,x,y,q,e,s,cv,cp,w,ierr,herr)
		  subroutine PSFLSH (p,s,z,t,D,Dl,Dv,x,y,q,e,h,cv,cp,w,ierr,herr)
		  
		  subroutine PQFLSH (p,q,z,kq,t,D,Dl,Dv,x,y,e,h,s,cv,cp,w,ierr,herr)



		  subroutine DEFLSH (D,e,z,t,p,Dl,Dv,x,y,q,h,s,cv,cp,w,ierr,herr)
		  subroutine DHFLSH (D,h,z,t,p,Dl,Dv,x,y,q,e,s,cv,cp,w,ierr,herr)
		  subroutine DSFLSH (D,s,z,t,p,Dl,Dv,x,y,q,e,h,cv,cp,w,ierr,herr)

		  subroutine HSFLSH (h,s,z,t,p,D,Dl,Dv,x,y,q,e,cv,cp,w,ierr,herr)
	*/
	
	void GetFlashProperties(ThermoProperties Property_1, double Value_1, ThermoProperties Property_2, double Value_2);


	void ThermalProperties(double Temperature, double Density);

	
};
