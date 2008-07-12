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
            
            //Console.WriteLine("Water Properties at 101.3 pascal" + Environment.NewLine);
            


            ManagedRefProp.PureFluid Water = new ManagedRefProp.PureFluid("Water");

            Water.CurrentUnitsBasis = ManagedRefProp.Common.UnitsBasis.Mass_Basis;

            Water.WarnEvent += new RefProp_Warning(Water_WarnEvent);



            Console.ForegroundColor = ConsoleColor.White;


            Console.WriteLine(Water.GetSaturatedTemperature(101.3)-273.15);

            
        }

        static void Water_WarnEvent(string WarningMessage)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(WarningMessage);
        }
    }
}
