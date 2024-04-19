using KTPO4311.Shchukin.Lib.src.LogAn;
using KTPO4311.Shchukin.Service.src.Views;
using KTPO4311.Shchukin.Lib.src.SampleCommands;
using Castle.Windsor;
using Castle.MicroKernel.Registration;
using Castle.MicroKernel.SubSystems.Configuration;

namespace KTPO4311.Shchukin.Service.src.WindsorInstallers;

public class SampleCommandInstaller : IWindsorInstaller
{
    public void Install(IWindsorContainer container, IConfigurationStore store)
    {
        container.Register(
            Component.For<ISampleCommand>().ImplementedBy<SampleCommandDecorator>().LifeStyle.Singleton,
            Component.For<ISampleCommand>().ImplementedBy<ExceptionCommandDecorator>().LifeStyle.Singleton,
            Component.For<ISampleCommand>().ImplementedBy<SecondCommand>().LifeStyle.Singleton);
    }
}

