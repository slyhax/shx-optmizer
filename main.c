#include <stdio.h>
#include "functions/menu.h"
#include "functions/options.h"

int main() {
    int answer;

    exibirMenu();
    printf("> ");
    scanf("%d", &answer);
    
	printf("Selected: %d\n", answer);
    
	switch(answer) {

          case 1:
	uninstallOneDrive();
	  break;
	  
	  case 2:
	optmizeMemoryRam();
	  break;


	}

    return 0;
}

