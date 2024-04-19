using KTPO4311.Shchukin.Lib.src.LogAn;
using System.Data;

namespace KTPO4311.Shchukin.Lib.src.SampleCommands;

public class SecondCommand : ISampleCommand
{
    public readonly IView view;
    private int iExecute = 0;

    public SecondCommand(IView view)
    {
        this.view = view;
    }

    public void Execute()
    {
        iExecute++;
        view.Render(this.GetType().ToString() + "\niExecute = " + iExecute);

        throw new DataException();
    }
}

