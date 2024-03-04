#include "AssignmentTranslator.h"
#include <boost/locale.hpp>
#include <iostream>

#include "..\LocalizationUtils\LocalizationUtils.h"

using namespace std;
using namespace boost::locale;

void AssignmentTranslator::TranslateFunc() {

    cout << Localize("r", "sky") << endl;
    cout << Localize("r", "thought experiment") << endl;
    //as::domain("sample") <<

    cout << Localize("file", "open2") << endl;
    cout << Localize("internet connection", "open2") << endl;
};

//int main()
//{
//
//#pragma warning(suppress : 4996)
//    AssignmentTranslator::TranslateFunc();
//
//}