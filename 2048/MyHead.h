#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

void showIntPointerTwo(int *(*p)[4], int n, int m)
{
	int i, j;
	printf("\n");
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < m; j ++)
			printf("%d ", *p[i][j]);
		printf("\n");
	}
	printf("\n");
}
int getch(void)
{
     int c = 0;
     struct termios org_opts, new_opts;
     int res = 0;
  
     res = tcgetattr(STDIN_FILENO, &org_opts);
     assert(res == 0);
  
     memcpy(&new_opts, &org_opts, sizeof(new_opts));
     new_opts.c_lflag &= ~(ICANON|ECHO|ECHOE|ECHOK|ECHONL|ECHOPRT|ECHOKE|ICRNL);
     tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
     c = getchar();
  
     res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
     assert(res == 0);
     return c;
}

