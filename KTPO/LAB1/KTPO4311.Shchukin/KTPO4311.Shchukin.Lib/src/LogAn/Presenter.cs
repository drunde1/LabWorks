namespace KTPO4311.Shchukin.Lib.src.LogAn;

public class Presenter
{
    public ILogAnalyze? logAnalyzer = null;
    public IView? view = null;

    public Presenter(ILogAnalyze logAnalyzer, IView view)
    {
        this.logAnalyzer = logAnalyzer;
        this.view = view;

        logAnalyzer.Analyzed += OnLogAnalyzed;
    }

    private void OnLogAnalyzed()
    {
        view.Render("Обработка завершена");
    }

}

