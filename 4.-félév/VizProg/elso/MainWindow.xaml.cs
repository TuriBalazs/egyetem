using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
namespace elso
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    
    public partial class MainWindow : Window
    {
        string CardBackName = "Abandoned_Deck.png";
        string[] ImageNames = { "Even_Steven.png", "Abstract_Joker.png", "Blueprint.png", "Constellation.png" };
        BitmapImage biCardBack;
        BitmapImage[] biImages = new BitmapImage[8];
        Image[] imImages;
        Random rnd = new Random();
        private DispatcherTimer dt;
        public MainWindow()
        {
            InitializeComponent();
            imImages = new Image[] { im10, im11, im12, im13, im20, im21, im22, im23};
            dt = new DispatcherTimer
            {
                Interval = new TimeSpan(0, 0, 0, 0, 3000),
                IsEnabled = false
            };
            dt.Tick += dt_Tick;
            LoadImages();
            ShowImages();
            dt.Start();

        }
        private void dt_Tick(object sender, EventArgs e)
        {
            ShowCardBack();
            dt.Stop();
        }
        private void ShowCardBack()
        {
            for (int i = 0; i < 8; i++)
            {
                imImages[i].Source = biCardBack;
            }
        }
        private void LoadImages()
        {
            try
            {
                biCardBack = new BitmapImage(new Uri("C:/Users/4-113-9/source/repos/elso/elso/Images/" + CardBackName, UriKind.Relative));
                for (int i = 0; i < 4; i++)
                {
                    biImages[i] = new BitmapImage(new Uri("C:/Users/4-113-9/source/repos/elso/elso/Images/" + ImageNames[i],
                    UriKind.Relative));
                    biImages[i + 4] = biImages[i];
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Images cannot be found!",
                "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void ShowImages()
        {
            for (int i = 0; i < 8; i++)
            {
                imImages[i].Source = biImages[i];
            }
        }
        private void miMix_Click(object sender, RoutedEventArgs e)
        {
            Randomize();
            ShowImages();
            dt.Start();
        }
        private void miGuess_Click(object sender, RoutedEventArgs e)
        {

        }
        private void Randomize()
        {
            List<BitmapImage> ImageList = new List<BitmapImage>();
            ImageList.AddRange(biImages);
            for (int i = 0; i < 8; i++)
            {
                int no = rnd.Next(0, ImageList.Count);
                biImages[i] = ImageList[no];
                ImageList.RemoveAt(no);
            }
        }
        private void miExit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }





    }
}