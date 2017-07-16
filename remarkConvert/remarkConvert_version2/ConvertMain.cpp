#include"utili.h"

#define     FILENAMESIZE    100

extern "C" int ConvertComment(FILE *inputfile, FILE *outputfile);

int main(int argc, char *argv[])
{
	FILE *fpIn = NULL;
	FILE *fpOut = NULL;
    char src_filename[FILENAMESIZE];
    char dest_filename[FILENAMESIZE];
    printf("please input the src_filename:");
    fgets(src_filename, FILENAMESIZE, stdin);
	fpIn = fopen(src_filename, "r");
	if(fpIn == NULL)
	{
		cout<<"Open input.c file Fail."<<endl;
		return -1;
	}
    fflush(stdin);
    printf("please input the dest_filename:");
    fgets(dest_filename, FILENAMESIZE, stdin);
	fpOut = fopen(dest_filename, "w");
	if(fpOut == NULL)
	{
		cout<<"Open output.c file Fail."<<endl;
		return -1;
	}

	ConvertComment(fpIn, fpOut);

	fclose(fpIn);
	fclose(fpOut);

	cout<<"finished......"<<endl;
}
