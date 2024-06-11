namespace DateServiceClassLibrary;

public class DateService
{ public string GetDay(DateTime date)
    {
        return date.DayOfWeek.ToString();
    }
    public double GetDaysSpan(DateTime inputDate)
    {
        DateTime currentDate = DateTime.Now;
        TimeSpan span = inputDate - currentDate; return span.Days;
    }
}