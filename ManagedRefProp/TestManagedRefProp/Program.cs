using System;
using System.Collections.Generic;
using System.Text;

using ManagedRefProp;
using ManagedRefProp.Common;

namespace TestManagedRefProp
{
    class Program
    {
        static void Main(string[] args)
        {
            
            Console.WriteLine("Saturated Temperatures of Water and Ammonia" + Environment.NewLine);
            


            PureFluid Water = new PureFluid("Water");

            PureFluid Ammonia = new PureFluid("Ammonia");


            Water.CurrentUnitsBasis = UnitsBasis.Mass_Basis;
            Ammonia.CurrentUnitsBasis = UnitsBasis.Mass_Basis;




            Water.WarnEvent += new EventHandler<WarningEventArgs>(Fluid_WarnEvent);
            Ammonia.WarnEvent += new EventHandler<WarningEventArgs>(Fluid_WarnEvent);



            Console.WriteLine("{0}    {1}               {2}", "Pressure (Pa)", "Water (C)", "Ammonia (C)");
            Console.WriteLine("{0}    {1}               {2}", "-------------", "---------", "-----------");
            Console.WriteLine();

            for (int P = 100; P <= 600; P += 50)
            {

                Console.WriteLine("{0}              {1}        {2}",
                    P,
                    Water.GetSaturatedTemperature(P) - 273.15,
                    Ammonia.GetSaturatedTemperature(P) - 273.15
                    );
            }

            
        }

        static void  Fluid_WarnEvent(object sender, WarningEventArgs e)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(sender.ToString() + ": " + e.WarningMessage);
        }


        

      
    }
}

