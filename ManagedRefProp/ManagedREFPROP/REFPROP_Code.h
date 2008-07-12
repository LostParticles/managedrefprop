namespace ManagedREFPROP 
{

	public enum class SaturationPoint
	{
		Bubble_Point = 1,	//liquid composition (bubble point)
		Dew_Point = 2,			//vapor composition (dew point)
		Freezing_Point = 3,
		Sublimation_Point = 4 //it is the melting point in case of solid-liquid phase change 

	};

	public enum class SubstancePhase
	{
		Solid,
		Subcooled,
		Saturated_Liquid,
		Saturated_Vapor,
		Superheated = 998,
		Superheated_T_Over_Critical,
		Superheated_SuperCritical
		
	};

	public ref struct SaturatedProperties
	{
		double Temperature;
		double Pressure;
		double Density_SaturatedLiquid;							//rhol--molar density [mol/L] of saturated liquid
		double Density_SaturatedVapor;						//rhov--molar density [mol/L] of saturated vapor
	};

/*
      T = temperature [K]
      P = pressure [kPa]
      D = density [mol/L]  L=dm^3
      E = internal energy [J/mol]
      H = enthalpy [J/mol]
      S = entropy [J/mol-K]
      Q = vapor quality [moles vapor/total moles]
          or [kg vapor/total kg] depending on the
          value of the input flag kq

*/
	public enum class ThermoProperties
	{
		Temperature     = 1,		// 00000001
		Pressure        = 2,		// 00000010
		Density         = 4,		// 00000100
		InternalEnergy  = 8,		// 00001000
		Enthalpy		= 16,       // 00010000
		Entropy			= 32,       // 00100000
		Quality			= 64        // 01000000
	};

	public ref struct ThermoPropertiesValues
	{
		double Temperature;
		double Pressure;
		double Density;
		double InternalEnergy;
		double Enthalpy;
		double Entropy;
		double Quality;
		double Isochoric_SpecificHeat;
		double Isobaric_SpecificHeat;
		double SoundSpeed;
		double Density_LiquidPhase;							//molar density [mol/L] of the liquid phase
		double Density_VaporPhase;							//molar density [mol/L] of the vapor phase
		array <double>^ XLIQ;							//composition of liquid phase [array of mol frac]
		array <double>^ XVAP;							//composition of vapor phase [array of mol frac]

		property double Specific_Volume
		{
			double get()
			{
				return 1/Density;
			}
		}
		void ShowValues()
		{
			System::Console::WriteLine("Temperature = "+Temperature.ToString());
			System::Console::WriteLine("Pressure = "+Pressure.ToString());
			System::Console::WriteLine("Density = "+Density.ToString());
			System::Console::WriteLine("Enthalpy = "+Enthalpy.ToString());
			System::Console::WriteLine("Entropy = "+Entropy.ToString());
			System::Console::WriteLine("Internal Energy = "+InternalEnergy.ToString());
			System::Console::WriteLine("Quality = "+Quality.ToString());

		}
	};
/*
	
temperature                     K
pressure, fugacity              kPa
density                         mol/L
composition                     mole fraction
quality                         mole basis (moles vapor/total moles)
enthalpy, internal energy       J/mol
Gibbs, Helmholtz free energy    J/mol
entropy, heat capacity          J/(mol.K)
speed of sound                  m/s
Joule-Thompson coefficient      K/kPa
d(p)/d(rho)                     kPa.L/mol
d2p)/d(rho)2                    kPa.(L/mol)^2
viscosity                       microPa.s (10^-6 Pa.s)
thermal conductivity            W/(m.K)
dipole moment                   debye
surface tension                 N/m
	*/

	public enum class UnitsBasis
	{
		Molar_Basis = 1,
		Mass_Basis = 2
	};
	
}
