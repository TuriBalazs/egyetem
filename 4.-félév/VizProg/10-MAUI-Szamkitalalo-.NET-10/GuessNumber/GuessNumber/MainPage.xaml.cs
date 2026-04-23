using System.Collections.ObjectModel;
namespace GuessNumber
{
    public partial class MainPage : ContentPage
    {
        Random rnd = new Random();
        int TargetNumber;
        ObservableCollection<Result> GuessLog;
        public MainPage()
        {
            InitializeComponent();
            TargetNumber = rnd.Next(1000, 10000);
            GuessLog = new ObservableCollection<Result>();
            lvResults.ItemsSource = GuessLog;
        }

        private void btOK_Clicked(object sender, EventArgs e)
        {
            string UserGuess = enNumber.Text;
            if (UserGuess.Length != 4 || !UserGuess.All(char.IsDigit))
            {
                llResult.Text = "Nem megfelelő érték!";
                return;
            }
            int CorrectDigits = 0;
            int CorrectPositions = 0;
            string TN = TargetNumber.ToString();
            for (int i = 0; i < 4; i++)
            {
                if (TN.Contains(UserGuess[i]))
                    CorrectDigits++;
                if (UserGuess[i] == TN[i])
                    CorrectPositions++;
            }
            llResult.Text = $"Az általad megadott számból {CorrectDigits} számjegy szerepel a számban, amit kitaláltam, és ebből {CorrectPositions} számjegy volt a helyén"; // ({TargetNumber})
            var nr = new Result
            {
                Guess = UserGuess,
                CorrectDigits = CorrectDigits,
                CorrectPositions = CorrectPositions
            };
            GuessLog.Insert(0, nr);
        }
        private void btNewGame_Clicked(object sender, EventArgs e)
        {
            GuessLog.Clear();
            TargetNumber = rnd.Next(1000, 10000);
        }
    }
    public class Result
    {
        public string Guess { get; set; }
        public int CorrectDigits { get; set; }
        public int CorrectPositions { get; set; }
    }
}
