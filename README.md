# TranslationWithBoost

A project to get students starting to run with boost translation

To regenerate the po and mo file.  You will need to get a copy of gettext-tools (this demo uses gettext-tools-static-0.18.1.1)

Consider making a backup of the po file, as when you run the next command it will re-generate it.

PATH_TO_XGETTEXT_TOOL_YOU_NEED_TO_USE_RIGHT_PATH\xgettext.exe --keyword=Localize:1,1t --keyword=Localize:1,2,3t --keyword=Localize:1,2,3t --keyword=Localize:1c,2,3,4t --keyword=Localize:2,1c,2t  translation.cpp

Make edits to po file.  Be aware you need to change header to overwrite the following lines in the newly outputted po file.
```
"Language: de \n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=UTF-8\n"
"Content-Transfer-Encoding: 8bit\n"
"Plural-Forms: nplurals=INTEGER; plural=EXPRESSION;\n"
```

Also be aware when running xgettext it will blank out all translations that existed beforehand (hence the reason to backup the po file)  Either provide new ones, or use the ones in the older version of the file.  I'd suggest slightly changing the translation just to prove it is picking up your chagnes to the po file.

<path>\msgfmt.exe --o messages.mo messages.po

move messages.mo de\LC_MESSAGES\messages.mo

  
To add in more mo files to  in LocalizationUtils.cpp
  genPtr->add_messages_domain("messages");

  However, there is a bug I need to address, as to retrieve a translation from a mo you do some things.  https://www.boost.org/doc/libs/1_48_0/libs/locale/doc/html/messages_formatting.html#multiple_gettext_domain
  

