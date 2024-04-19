using KTPO4311.Shchukin.Lib.src.LogAn;
using KTPO4311.Shchukin.Service.src.Views;
using Castle.Windsor;
using Castle.MicroKernel.Registration;
using Castle.MicroKernel.SubSystems.Configuration;

namespace KTPO4311.Shchukin.Service.src.WindsorInstallers;

public class ViewInstaller : IWindsorInstaller
{
    public void Install(IWindsorContainer container, IConfigurationStore store)
    {
        container.Register(
            Component.For<IView>().ImplementedBy<ConsoleView>().LifeStyle.Transient);
    }
}

