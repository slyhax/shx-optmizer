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


void optmizeMemoryRam() {

    SetProcessWorkingSetSize(GetCurrentProcess(), -1, -1);
    printf("[+] Memória do processo atual otimizada.\n");

    DWORD processes[1024], cbNeeded, cProcesses;
    if (!EnumProcesses(processes, sizeof(processes), &cbNeeded)) {
        printf("[-] Falha ao enumerar processos.\n");
        return 1;
    }

    cProcesses = cbNeeded / sizeof(DWORD);

    for (unsigned int i = 0; i < cProcesses; i++) {
        if (processes[i] == 0)
            continue;

        HANDLE hProcess = OpenProcess(PROCESS_SET_QUOTA | PROCESS_QUERY_INFORMATION, FALSE, processes[i]);
        if (hProcess) {
            if (SetProcessWorkingSetSize(hProcess, -1, -1)) {
                printf("[+] Limpando memória do processo PID %lu\n", processes[i]);
            }
            CloseHandle(hProcess);
        }
    }

    printf("[✔] Otimização de RAM finalizada.\n");
    return 0;

}
