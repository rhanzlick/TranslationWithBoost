# TranslationWithBoost

A project to get students starting to run with boost translation

To regenerate the po and mo file.

<path>\xgettext.exe --keyword=Localize:1,1t --keyword=Localize:1,2,3t --keyword=Localize:1,2,3t --keyword=Localize:1c,2,3,4t --keyword=Localize:2,1c,2t  translation.cpp

<path>\msgfmt.exe --o messages.mo messages.po

move messages.mo de\LC_MESSAGES\messages.mo

  
  And the finally in LocalizationUtils.cpp
  genPtr->add_messages_path("C:\\Users\\polek\\source\\repos\\boost_starting\\translation");
  
  Fix this line to be where the mo files are located at.
