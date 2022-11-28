#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Windows::Foundation;
using namespace std;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::time1picker2::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}

hstring intToTime(INT_PTR time) {
    int hour = time / 36000000000;
    int min = (time % 36000000000) / 600000000;
    int sec = time % 60;

    hstring t = to_hstring(hour) + L"hour(s) " + to_hstring(min) + L"minute(s)";
    return t;
}

void winrt::time1picker2::implementation::MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    INT_PTR a = checkTimePicker().SelectedTime().Value().count();
    hstring b = intToTime(a);
    resultText().Text(b);
}
