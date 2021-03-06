// ManagedREFPROP.h

#pragma once
#include "RefProp.h"
#include "Common.h"
#include "RefPropException.h"

#include "IFluid.h"

//#pragma warning(disable:4482)   //to prevent warning of using full qualified name, I need it because I duplicate the names in native and managed code



using namespace System;
using namespace System::Runtime::InteropServices;

using namespace ManagedRefProp::Common;


namespace ManagedRefProp {

	public ref class PureFluid sealed : public IFluid
	{

	private:
		RefProp* MyREFPROP;

		String^ _fluidName;
	public:
		int ErrorCode;
		String^ ErrorMessage;
		virtual event EventHandler<WarningEventArgs^>^ WarnEvent;
		virtual event EventHandler^ DoneEvent;

		virtual property UnitsBasis CurrentUnitsBasis
		{
			UnitsBasis get()
			{
				if(MyREFPROP->CurrentUnitsBasis == RefProp::UnitsBasis::Mass_Basis)
					return UnitsBasis::Mass_Basis;
				else
					return UnitsBasis::Molar_Basis;
			}

			void set(UnitsBasis value)
			{
				if(value == UnitsBasis::Mass_Basis)
					MyREFPROP->CurrentUnitsBasis =  RefProp::UnitsBasis::Mass_Basis;
			
				else
					MyREFPROP->CurrentUnitsBasis =  RefProp::UnitsBasis::Molar_Basis;

			}
		}

		
		PureFluid(String^ fluid_name)
		{
			_fluidName = fluid_name;

			fluid_name  = fluid_name+".FLD";
			IntPtr mb = Marshal::StringToHGlobalAnsi(fluid_name);


			MyREFPROP = new RefProp();
			char* fld = (char*)mb.ToPointer();
			MyREFPROP->LoadPureFluid(fld);


			CheckError();

		}

		~PureFluid() // IDisposable
		{
			delete MyREFPROP;
		}




		property String^ FluidName
		{
			String^ get()
			{
				return _fluidName;
			}
		}

		virtual String^ ToString() override
		{
			return FluidName::get();
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

		virtual property double MolecularWeight
		{
			double get()
			{
			
				return MyREFPROP->GetMolecularWeight();
			}
		}

		virtual property double TriplePointTemperature
		{
			double get()
			{
				return MyREFPROP->GetTriplePointTemperature();
			}
		}

		virtual property double NormalBoilingPointTemperature
		{
			double get()
			{
				return MyREFPROP->GetNormalBoilingPointTemperature();
			}
		}

		virtual property double CriticalTemperature
		{
			double get()
			{
				return MyREFPROP->GetCriticalTemperature();
			}
		}

		virtual property double CriticalPressure
		{
			double get()
			{
				return MyREFPROP->GetCriticalPressure();
			}
		}

		virtual property double CriticalDensity
		{
			double get()
			{
				return MyREFPROP->GetCriticalDensity();
			}
		}

		virtual property double CriticalPointCompressibility
		{
			double get()
			{
				return MyREFPROP->GetCriticalPointCompressibility();
			}
		}

		virtual property double AccentricFactor
		{
			double get()
			{
				return MyREFPROP->GetAccentricFactor();
			}
		}

		virtual property double DipoleMoment
		{
			double get()
			{
				return MyREFPROP->GetDipoleMoment();
			}
		}

		virtual property double GasConstatnt_R
		{
			double get()
			{
				return MyREFPROP->GetGasConstatnt_R();
			}
		}



		virtual double GetSaturatedPressure(double temperature)
		{
			double p = MyREFPROP->GetSaturatedPressure(temperature);
			CheckError();
			return p;
		}



		///
		/// Get the saturated temperature of the fluid based on the pressure.
		///
		virtual double GetSaturatedTemperature(double pressure)
		{
			double t = MyREFPROP->GetSaturatedTemperature(pressure);
			CheckError();
			return t;
		}


		
		virtual ThermoPropertiesValues^ GetFlashProperties(ThermoProperties property_1,double value_1,ThermoProperties property_2,double value_2)
		{


			RefProp::ThermoProperties prop1,prop2;

			if(property_1== ThermoProperties::Density)
				prop1 = RefProp::ThermoProperties::Density;
			if(property_1== ThermoProperties::Enthalpy)
				prop1 = RefProp::ThermoProperties::Enthalpy;
			if(property_1== ThermoProperties::Entropy)
				prop1 = RefProp::ThermoProperties::Entropy;
			if(property_1== ThermoProperties::InternalEnergy)
				prop1 = RefProp::ThermoProperties::InternalEnergy;
			if(property_1== ThermoProperties::Pressure)
				prop1 = RefProp::ThermoProperties::Pressure;
			if(property_1== ThermoProperties::Quality)
				prop1 = RefProp::ThermoProperties::Quality;
			if(property_1== ThermoProperties::Temperature)
				prop1 = RefProp::ThermoProperties::Temperature;

			if(property_2== ThermoProperties::Density)
				prop2 = RefProp::ThermoProperties::Density;
			if(property_2== ThermoProperties::Enthalpy)
				prop2 = RefProp::ThermoProperties::Enthalpy;
			if(property_2== ThermoProperties::Entropy)
				prop2 = RefProp::ThermoProperties::Entropy;
			if(property_2== ThermoProperties::InternalEnergy)
				prop2 = RefProp::ThermoProperties::InternalEnergy;
			if(property_2== ThermoProperties::Pressure)
				prop2 = RefProp::ThermoProperties::Pressure;
			if(property_2== ThermoProperties::Quality)
				prop2 = RefProp::ThermoProperties::Quality;
			if(property_2== ThermoProperties::Temperature)
				prop2 = RefProp::ThermoProperties::Temperature;


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
				WarnEvent(this, gcnew WarningEventArgs(ErrorMessage));
			}
			else if(ErrorCode<0)
			{

				throw gcnew RefPropException(ErrorMessage);
			}

			else
			{
				DoneEvent(this, gcnew EventArgs());
			}

			
		}

	};

}