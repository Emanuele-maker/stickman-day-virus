#include <windows.h>
#include "./progClock.h"

#ifndef CREATE_GOOGLE_SEARCHES
#define CREATE_GOOGLE_SEARCHES

void createGoogleSearches() {
    ShellExecute(NULL, "open", "https://www.google.com/search?q=what+is+a+malware", NULL, NULL, SW_SHOWNORMAL);
    progClock(15);
    ShellExecute(NULL, "open", "https://www.google.com/search?q=free+ram+download+no+scam", NULL, NULL, SW_SHOWNORMAL);
    progClock(30);
    ShellExecute(NULL, "open", "https://www.google.com/search?q=is+bitcoin+worth+it", NULL, NULL, SW_SHOWNORMAL);
    progClock(45);
    ShellExecute(NULL, "open", "https://www.google.com/search?q=free+vpn+no+virus+download+malavida", NULL, NULL, SW_SHOWNORMAL);
    progClock(62);
    // ShellExecute(NULL, "open", "https://www.google.com/search?q=donald+trump+kissing+kamala+harris", NULL, NULL, SW_SHOWNORMAL);
}

#endif