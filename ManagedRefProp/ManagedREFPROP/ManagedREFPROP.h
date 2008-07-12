// ManagedREFPROP.h

#pragma once
#include "REFPROP.h"
#include "REFPROP_Code.h"

#pragma warning(disable:4482)   //to prevent warning of using full qualified name, I need it because I duplicate the names in native and managed code



using namespace System;
using namespace System::Runtime::InteropServices;

using namespace ManagedRefProp::Common;


namespace ManagedRefProp {

	public delegate void RefProp_Warning(String^ WarningMessage);
	public delegate void RefProp_Done();

	public ref class PureFluid sealed
	{

	private:
		REFPROP* MyREFPROP;

	public:
		int ErrorCode;
		String^ ErrorMessage;
		event RefProp_Warning^ WarnEvent;
		event RefProp_Done^ DoneEvent;

		property UnitsBasis CurrentUnitsBasis
		{
			UnitsBasis get()
			{
				if(MyREFPROP->CurrentUnitsBasis == REFPROP::UnitsBasis::Mass_Basis)
					return UnitsBasis::Mass_Basis;
				else
					return UnitsBasis::Molar_Basis;
			}

			void set(UnitsBasis value)
			{
				if(value == UnitsBasis::Mass_Basis)
					MyREFPROP->CurrentUnitsBasis =  REFPROP::UnitsBasis::Mass_Basis;
				else
					MyREFPROP->CurrentUnitsBasis =  REFPROP::UnitsBasis::Molar_Basis;

			}
		}

		
		PureFluid(String^ fluid_name)
		{

			fluid_name  = fluid_name+".FLD";
			IntPtr mb = Marshal::StringToHGlobalAnsi(fluid_name);


			MyREFPROP = new REFPROP();
			char* fld = (char*)mb.ToPointer();
			MyREFPROP->LoadPureFluid(fld);


			CheckError();

		}

		//Fluid Info Section
		/*
		      subroutine INFO (icomp,wm,ttp,tnbp,tc,pc,Dc,Zc,acf,dip,Rgas)
c
c  provides fluid constants for specified component
c
c  input:
c    icomp--component number in mixture; 1 for pure fluid
c  outputs:
c       wm--molecular weight [g/mol]
c      ttp--triple point temperature [K]
c     tnbp--normal boiling point temperature [K]
c       tc--critical temperature [K]
c       pc--critical pressure [kPa]
c       Dc--critical density [mol/L]
c       Zc--compressibility at critical point [pc/(Rgas*Tc*Dc)]
c      acf--accentric factor [-]
c      dip--dipole moment [debye]
c     Rgas--gas constant [J/mol-K]

		*/
		property double MolecularWeight
		{
			double get()
			{
			
				return MyREFPROP->GetMolecularWeight();
			}
		}
		property double TriplePointTemperature
		{
			double get()
			{
				return MyREFPROP->GetTriplePointTemperature();
			}
		}
		property double NormalBoilingPointTemperature
		{
			double get()
			{
				return MyREFPROP->GetNormalBoilingPointTemperature();
			}
		}
		property double CriticalTemperature
		{
			double get()
			{
				return MyREFPROP->GetCriticalTemperature();
			}
		}
		property double CriticalPressure
		{
			double get()
			{
				return MyREFPROP->GetCriticalPressure();
			}
		}
		property double CriticalDensity
		{
			double get()
			{
				return MyREFPROP->GetCriticalDensity();
			}
		}
		property double CriticalPointCompressibility
		{
			double get()
			{
				return MyREFPROP->GetCriticalPointCompressibility();
			}
		}
		property double AccentricFactor
		{
			double get()
			{
				return MyREFPROP->GetAccentricFactor();
			}
		}
		property double DipoleMoment
		{
			double get()
			{
				return MyREFPROP->GetDipoleMoment();
			}
		}
		property double GasConstatnt_R
		{
			double get()
			{
				return MyREFPROP->GetGasConstatnt_R();
			}
		}



		double GetSaturatedPressure(double temperature)
		{
			double p = MyREFPROP->GetSaturatedPressure(temperature);
			CheckError();
			return p;
		}


		double GetSaturatedTemperature(double pressure)
		{
			double t = MyREFPROP->GetSaturatedTemperature(pressure);
			CheckError();
			return t;
		}


		
		ThermoPropertiesValues^ GetFlashProperties(ThermoProperties property_1,double value_1,ThermoProperties property_2,double value_2)
		{


			REFPROP::ThermoProperties prop1,prop2;

			if(property_1== ThermoProperties::Density)
				prop1 = REFPROP::ThermoProperties::Density;
			if(property_1== ThermoProperties::Enthalpy)
				prop1 = REFPROP::ThermoProperties::Enthalpy;
			if(property_1== ThermoProperties::Entropy)
				prop1 = REFPROP::ThermoProperties::Entropy;
			if(property_1== ThermoProperties::InternalEnergy)
				prop1 = REFPROP::ThermoProperties::InternalEnergy;
			if(property_1== ThermoProperties::Pressure)
				prop1 = REFPROP::ThermoProperties::Pressure;
			if(property_1== ThermoProperties::Quality)
				prop1 = REFPROP::ThermoProperties::Quality;
			if(property_1== ThermoProperties::Temperature)
				prop1 = REFPROP::ThermoProperties::Temperature;

			if(property_2== ThermoProperties::Density)
				prop2 = REFPROP::ThermoProperties::Density;
			if(property_2== ThermoProperties::Enthalpy)
				prop2 = REFPROP::ThermoProperties::Enthalpy;
			if(property_2== ThermoProperties::Entropy)
				prop2 = REFPROP::ThermoProperties::Entropy;
			if(property_2== ThermoProperties::InternalEnergy)
				prop2 = REFPROP::ThermoProperties::InternalEnergy;
			if(property_2== ThermoProperties::Pressure)
				prop2 = REFPROP::ThermoProperties::Pressure;
			if(property_2== ThermoProperties::Quality)
				prop2 = REFPROP::ThermoProperties::Quality;
			if(property_2== ThermoProperties::Temperature)
				prop2 = REFPROP::ThermoProperties::Temperature;


			MyREFPROP->GetFlashProperties
				(prop1, value_1, prop2, value_2);


			CheckError();
			ThermoPropertiesValues^ VLS = gcnew ThermoPropertiesValues();



			VLS->Temperature = MyREFPROP->t;
			VLS->Pressure = MyREFPROP->p;
			VLS->Density = MyREFPROP->D;
			VLS->InternalEnergy = MyREFPROP->e;
			VLS->Enthalpy = MyREFPROP->h;
			VLS->Entropy = MyREFPROP->s;
			VLS->Quality = MyREFPROP->q;
			VLS->Isochoric_SpecificHeat = MyREFPROP->cv;
			VLS->Isobaric_SpecificHeat = MyREFPROP->cp;
			VLS->SoundSpeed = MyREFPROP->w;
			VLS->Density_LiquidPhase = MyREFPROP->rhol;
			VLS->Density_VaporPhase = MyREFPROP->rhov;
			VLS->XLIQ = gcnew array<double>(1);
				VLS->XLIQ[0] = MyREFPROP->XLIQ[0];
			VLS->XVAP = gcnew array<double>(1);
				VLS->XVAP[0] = MyREFPROP->XVAP[0];


			return VLS;

		}

		ThermoPropertiesValues^ ThermalProperties(double temperature, double density)
		{


			MyREFPROP->ThermalProperties(temperature,density);

			CheckError();
			ThermoPropertiesValues^ VLS = gcnew ThermoPropertiesValues();



			VLS->Temperature = MyREFPROP->t;
			VLS->Pressure = MyREFPROP->p;
			VLS->Density = MyREFPROP->D;
			VLS->InternalEnergy = MyREFPROP->e;
			VLS->Enthalpy = MyREFPROP->h;
			VLS->Entropy = MyREFPROP->s;
			VLS->Quality = MyREFPROP->q;
			VLS->Isochoric_SpecificHeat = MyREFPROP->cv;
			VLS->Isobaric_SpecificHeat = MyREFPROP->cp;
			VLS->SoundSpeed = MyREFPROP->w;
			VLS->Density_LiquidPhase = MyREFPROP->rhol;
			VLS->Density_VaporPhase = MyREFPROP->rhov;
			VLS->XLIQ = gcnew array<double>(1);
				VLS->XLIQ[0] = MyREFPROP->XLIQ[0];
			VLS->XVAP = gcnew array<double>(1);
				VLS->XVAP[0] = MyREFPROP->XVAP[0];


			return VLS;
		}


		private:
		void CheckError()
		{
			ErrorCode = MyREFPROP->ierr;

			if(ErrorCode>0)
			{
				ErrorMessage = Marshal::PtrToStringAnsi((IntPtr)MyREFPROP->herr);
				WarnEvent(ErrorMessage);
			}
			else if(ErrorCode<0)
			{

				throw gcnew Exception(ErrorMessage);
			}

			else
			{
				DoneEvent();
			}

			
		}

	};
}
