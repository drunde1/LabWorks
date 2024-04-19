namespace KTPO4311.Shchukin.Lib.src.LogAn;

public interface ILogAnalyze
{
    event LogAnalyzerAction? Analyzed;
    bool IsValidLogFileName(string fileName);
    void Analyze(string fileName);
    void RaiseAnalyzedEvent();
}

