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

        again:


            Console.WriteLine("1: Pure Fluid");
            Console.WriteLine("2: Mixed Fluid");
            Console.WriteLine("X: Exit"); 
            Console.WriteLine("--------------");
            Console.Write("Choice ? ");


            string g = Console.ReadLine();
            if (g.ToUpper() == "X") return;

            if (string.IsNullOrEmpty(g)) goto again;

            int choice = int.Parse(g);
            if (choice == 2)
            {

                IFluid mf = new MixedFluid("R32 = 0.69762", "R125 = 0.30238");
                

                mf.CurrentUnitsBasis = UnitsBasis.Mass_Basis;
                mf.WarnEvent += new EventHandler<WarningEventArgs>(Fluid_WarnEvent);

                Console.WriteLine("Sat Temp at 400 Pascal = {0}<K>", mf.GetSaturatedTemperature(400));

                var mf2 = new MixedFluid("R22=0.5", "Nitrogen=0.5");
                mf2.CurrentUnitsBasis = UnitsBasis.Mass_Basis;
                mf2.WarnEvent+=new EventHandler<WarningEventArgs>(Fluid_WarnEvent);


                var f = mf2.GetFlashProperties(ThermoProperties.Pressure, 100, ThermoProperties.Temperature,300);
                f.ShowValues();

                Console.WriteLine();

                var c = mf.GetFlashProperties(ThermoProperties.Pressure, 100, ThermoProperties.Density, 40);
                c.ShowValues();


                Console.WriteLine();


                Console.WriteLine("{0}    {1}               {2}", "Pressure (Pa)", "R32 R125 (K)", "R22 N (K)");
                Console.WriteLine("{0}    {1}               {2}", "-------------", "------------", "---------");
                Console.WriteLine();


                for (var P = 100; P <= 600; P += 10)
                {

                    Console.WriteLine("{0}    {1}               {2}",
                        P.ToString().PadRight(13, ' '),
                        mf.GetSaturatedTemperature(P).ToString(),
                        mf2.GetSaturatedTemperature(P).ToString()
                        );
                }

            }
            else if (choice == 1)
            {

                Console.WriteLine("Saturated Temperatures of Water and Ammonia" + Environment.NewLine);


                PureFluid Water = new PureFluid("Water");

                PureFluid Ammonia = new PureFluid("Ammonia");



                Water.CurrentUnitsBasis = UnitsBasis.Mass_Basis;
                Ammonia.CurrentUnitsBasis = UnitsBasis.Mass_Basis;



                Water.WarnEvent += new EventHandler<WarningEventArgs>(Fluid_WarnEvent);
                Ammonia.WarnEvent += new EventHandler<WarningEventArgs>(Fluid_WarnEvent);



                Console.WriteLine("{0}    {1}               {2}", "Pressure (Pa)", "Water (K)", "Ammonia (K)");
                Console.WriteLine("{0}    {1}               {2}", "-------------", "---------", "-----------");
                Console.WriteLine();


                for (var P = 100; P <= 600; P += 10)
                {

                    Console.WriteLine("{0}    {1}               {2}",
                        P.ToString().PadRight(13, ' '),
                        Water.GetSaturatedTemperature(P).ToString(),
                        Ammonia.GetSaturatedTemperature(P).ToString()
                        );
                }
            }
            else
            {
                Console.WriteLine("Please choose among available options.");
                Console.WriteLine();
            }

            goto again;
        }

        static void  Fluid_WarnEvent(object sender, WarningEventArgs e)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(sender.ToString() + ": " + e.WarningMessage);
            Console.ForegroundColor = ConsoleColor.White;
        }      
    }
}

