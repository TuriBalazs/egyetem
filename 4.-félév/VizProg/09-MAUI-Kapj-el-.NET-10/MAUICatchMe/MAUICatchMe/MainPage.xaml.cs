namespace MAUICatchMe
{
    public partial class MainPage : ContentPage
    {

        Random rnd = new Random();
        IDispatcherTimer timer;
        int Hits
        {
            get { return int.Parse(llHits.Text); }
            set { llHits.Text = value.ToString(); }
        }

        int Misses
        {
            get { return int.Parse(llMisses.Text); }
            set { llMisses.Text = value.ToString(); }
        }

        public MainPage()
        {
            InitializeComponent();
            timer = Dispatcher.CreateTimer();
            timer.Tick += Timer_Tick;
            timer.Interval = TimeSpan.FromMilliseconds(2000);
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            double x = rnd.NextDouble() *
            (alPlayground.Width - ibCasper.Width);
            double y = rnd.NextDouble() *
            (alPlayground.Height - ibCasper.Height);
            AbsoluteLayout.SetLayoutBounds(ibCasper,
            new Rect(x, y, ibCasper.Width, ibCasper.Height));
        }


        private void alPlayground_Tapped(object sender, TappedEventArgs e)
        {
            if (!timer.IsRunning) return;
            Misses++;
        }

        private void ibCasper_Clicked(object sender, EventArgs e)
        {
            if (!timer.IsRunning) return;
            Hits++;
        }

        private void btStart_Clicked(object sender, EventArgs e)
        {
            if (timer.IsRunning) return;
            llCaption.Text = "Game started!";
            timer.Start();
        }

        private void btReset_Clicked(object sender, EventArgs e)
        {
            Hits = 0;
            Misses = 0;
        }

        private void btStop_Clicked(object sender, EventArgs e)
        {
            llCaption.Text = "Game stopped!";
            timer.Stop();
        }

        private void slTime_ValueChanged(object sender, ValueChangedEventArgs e)
        {

        }
    }

}
