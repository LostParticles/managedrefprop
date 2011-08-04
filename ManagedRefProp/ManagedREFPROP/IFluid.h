namespace ManagedRefProp
{

	namespace Common
	{

		
		public interface class IFluid
		{


			property double MolecularWeight { double get(); }
			property double TriplePointTemperature { double get(); }
			property double NormalBoilingPointTemperature { double get(); }
			property double CriticalTemperature { double get(); }
			property double CriticalPressure { double get(); }
			property double CriticalDensity { double get(); }
			property double CriticalPointCompressibility { double get(); }
			property double AccentricFactor { double get(); }
			property double DipoleMoment { double get(); }
			property double GasConstatnt_R { double get(); }


			ThermoPropertiesValues^ 
				GetFlashProperties(
					  ThermoProperties property_1, double value_1
					, ThermoProperties property_2, double value_2
				);

			double GetSaturatedPressure(double temperature);
			double GetSaturatedTemperature(double pressure);

			property UnitsBasis CurrentUnitsBasis;

			event EventHandler<WarningEventArgs^>^ WarnEvent;
			event EventHandler^ DoneEvent;

		};
	}
}