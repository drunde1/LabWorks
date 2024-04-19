using Castle.Windsor;
namespace KTPO4311.Shchukin.Lib.src.Common;

public static class CastleFactory
{
    ///<summary> Контейнер</summary>
    public static IWindsorContainer container { get; private set; }

    static CastleFactory()
    {
        //Создать объект контейнер
        container = new WindsorContainer();
    }
}

