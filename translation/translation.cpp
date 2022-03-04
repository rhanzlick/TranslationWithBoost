#include <boost/locale.hpp>
#include <iostream>

using namespace std;
using namespace boost::locale;

static void function1(int files)
{
    cout << format(translate("You have {1} file in the directory",
        "You have {1} files in the directory",
        files)) % files << endl;
}

static void function2(int n)
{
    cout << format(translate("Option1 {1} file in the directory",
        "Option2 {1} files in the directory",
        n)) % n << endl;
}

int main()
{
    generator gen;

    // Specify location of dictionaries
    gen.add_messages_path(".");
    gen.add_messages_domain("hello");

    // Generate locales and imbue them to iostream
    locale::global(gen("de_DE.UTF - 8"));
    cout.imbue(locale());

    // Display a message using current system locale
    cout << translate("Hello World") << endl;

    cout << translate("file", "open") << endl;

    int files = 1;

    function1(1);
    function1(4);

    function2(1);
    function2(2);
    function2(15);


}

