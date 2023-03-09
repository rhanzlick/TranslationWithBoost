// PatrickLocal.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "LocalizationUtils.h"
#include "LocalizationUtilsInternal.h"
#include <boost/locale.hpp>

using namespace boost::locale;

static generator* genPtr = nullptr;

static bool isInitialized = false;

static bool determinedBasePath = false;
static std::string basePath;

static std::string RemoveLastDirectory(const std::string& dirPath);
static std::string BasePath();

static std::string BasePath() {
    if (!determinedBasePath)
    {
        TCHAR buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        std::wstring wStr = std::wstring(buffer).substr(0, pos);

        std::string tmp = std::string(wStr.begin(), wStr.end());

        std::string tmp1 = RemoveLastDirectory(tmp);
        basePath = RemoveLastDirectory(tmp1);
    }

    return basePath;
}

static std::string RemoveLastDirectory(const std::string& dirPath)
{
    auto pos = dirPath.find_last_of("\\");
    std::string retVal = dirPath.substr(0, pos);

    return retVal;
}

void LocalizeUtilsInit()
{
    
    // Specify location of dictionaries
    genPtr = new generator();

    // THe assumption is the directory where the de\LC_MESSAGES is located is at
    // boost_starting\translation\de\LC_MESSAGES
    // So to make this more portable I have taken out the hardcoded path
    std::string basePath = BasePath();
    genPtr->add_messages_path(basePath +"\\translation");
    genPtr->add_messages_domain("messages");

    std::locale::global(( *genPtr)("de_DE.UTF - 8"));

    std::cout.imbue(std::locale());

    isInitialized = true;

}


std::string Localize(const std::string & msg)
{
    if (!isInitialized)
    {
        LocalizeUtilsInit();
    }

    // Display a message using current system locale
    std::string  retval = translate(msg);
    return retval;

}

std::string Localize(const std::string& msgSing, const std::string& msgPlural, int count)
{

    std::string  retval = translate(msgSing, msgPlural, count);
    return retval;
}

std::string Localize(const std::string& ctx, const std::string& msg)
{

    if (!isInitialized)
    {
        LocalizeUtilsInit();
    }


    std::string  retval = translate(ctx, msg);
    return retval;
}
