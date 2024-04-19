using System;
using KTPO4311.Shchukin.Lib.src.Common;
using KTPO4311.Shchukin.Lib.src.LogAn;
using KTPO4311.Shchukin.Lib.src.SampleCommands;
using KTPO4311.Shchukin.Service.src.WindsorInstallers;

namespace KTPO4311.Shchukin.Service
{
    internal class Program
    {
        static void Main(string[] args)
        {
            CastleFactory.container.Install(
                new SampleCommandInstaller(),
                new ViewInstaller()
                );
            for (int i = 0; i < 3; i++)
            {
                ISampleCommand someCommand = CastleFactory.container.Resolve<ISampleCommand>();
                someCommand.Execute();
            }
        }
    }
}