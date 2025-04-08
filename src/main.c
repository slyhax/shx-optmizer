#include <stdio.h>
#include "functions/menu.h"
#include "functions/options.h"

int main() {
    int answer;

    exibirMenu();
    printf("> ");
    scanf("%d", &answer);
    
	switch(answer) {
          case 1: uninstallOneDrive(); break;
	  case 2: optmizeMemoryRam(); break;
	  case 0: printf('exited'); break;
	}

	return 0;
}

