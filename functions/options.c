#include "options.h"
#include <stdio.h>

void uninstallOneDrive() {
	   int result = system("taskkill /f /im OneDrive.exe && %SystemRoot%\\System32\\OneDriveSetup.exe /uninstall");

    if (result == 0) {
        printf("OneDrive desinstalado com sucesso.\n");
    } else {
        printf("Falha ao tentar desinstalar o OneDrive. Código: %d\n", result);
    }
    return 0;
}


