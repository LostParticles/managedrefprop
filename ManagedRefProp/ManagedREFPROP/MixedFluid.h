
#pragma once
#include "RefProp.h"
#include "Common.h"
#include "RefPropException.h"

#include "IFluid.h"



using namespace System;
using namespace System::Runtime::InteropServices;

using namespace ManagedRefProp::Common;

namespace ManagedRefProp {

	public ref class MixedFluid sealed : public IFluid
	{

	private:
		RefProp* MyREFPROP;

		array<String^>^ Fluids; 
		array<double>^ Fractions;

		int MixturesCount;


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

		

		///
		/// fluids parameter is on the format  ("R12=0.5",R22=0.5")
		///
		MixedFluid(... array<String^>^ fluids)
		{
			//_fluidName = fluid_name;

			//fluid_name  = fluid_name+".FLD";
			//IntPtr mb = Marshal::StringToHGlobalAnsi(fluid_name);

			vector<string> _fluids;
			vector<double> _fractions;

			MyREFPROP = new RefProp();

			MixturesCount = fluids->Length;

			Fluids = gcnew array<String^>(MixturesCount);
			Fractions = gcnew array<double>(MixturesCount);
			

			for(int iy = 0; iy < MixturesCount; iy++)
			{
				array<String^>^ flds = fluids[iy]->Split('=');

				Fluids[iy] = flds[0]->Trim();

				Fractions[iy] = double::Parse(flds[1]);

				IntPtr flp = Marshal::StringToHGlobalAnsi(Fluids[iy]+".fld");

				_fluids.push_back((char*)flp.ToPointer());

				double frc = Fractions[iy];
				_fractions.push_back(frc);

			}
			

			MyREFPROP->LoadMixedFluid(_fluids, _fractions);


			CheckError();

		}

		~MixedFluid() // IDisposable
		{
			delete MyREFPROP;
		}


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

			
			VLS->XLIQ = gcnew array<double>(MixturesCount);
			
			for(int ix=0; ix < MixturesCount; ix++)
				VLS->XLIQ[ix] = MyREFPROP->XLIQ[ix];

			VLS->XVAP = gcnew array<double>(MixturesCount);

			for(int iy=0; iy < MixturesCount; iy++)
				VLS->XVAP[iy] = MyREFPROP->XVAP[iy];


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