#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


void fun0(char **pRead, char **pWrite);
void fun1(char **pRead, char **pWrite);
void fun2(char **pRead, char **pWrite);
void fun3(char **pRead, char **pWrite);

int whichCase(char **pRead, char **pWrite);

int main()
{
    FILE *fpRead = NULL, *fpWrite = NULL;
    char *pRead = NULL;
    char *pWrite = NULL;
    char *pTempWrite = NULL, *pTempRead = NULL;
    char fileReadName[20] = {0};
    int fileSize = 0, outFileSize = fileSize;
    void (*pFun[4])(char **pRead, char **pWrite) = {fun0, fun1, fun2, fun3};
    scanf("%s", fileReadName);
    if((fpRead = fopen(fileReadName, "rb")) == NULL)
    {
        printf("无法打开此文件\n");
        return 0;
    }
    fseek(fpRead, 0, 2);	//文件指针指向文件末尾
    fileSize = ftell(fpRead);	//计算文件大小
    fseek(fpRead, 0, 0);	//文件指针指向文件开头
    outFileSize = fileSize * 1.5;
    pRead = (char *)malloc(fileSize+1);
    pWrite = (char *)malloc(outFileSize);	//保存修改后的数据，初始大小为读入文件大小的1.5倍
    memset(pWrite,0,outFileSize);	memset(pRead,0,fileSize+1);
    pTempWrite = pWrite;
    pTempRead = pRead;
    fread(pRead, fileSize, 1, fpRead);

    while(*pRead != '\0')
    {
        pFun[whichCase(&pRead, &pWrite)](&pRead, &pWrite);

    }	
    *pWrite = '\0';
    if((fpWrite = fopen("result.txt", "wb")) == NULL)
    {
        printf("无法打开输出文件\n");
        return 0;
    }
    fputs(pTempWrite,fpWrite);
    //	fwrite(pTempWrite, outFileSize, 1, fpWrite);
    //	fwrite(pTempWrite, 20, 1, fpWrite);
    fclose(fpWrite);
    fclose(fpRead);
    fpWrite = NULL;
    fpRead = NULL;
    free(pTempRead);
    free(pTempWrite);
    pTempRead = NULL;
    pTempWrite = NULL;
    return 1;
}

int whichCase(char **pRead, char **pWrite)
{
    if(**pRead == '/')
    {
        if(*(*pRead + 1) == '/')
        {
            **pWrite = '/';
            *(*pWrite + 1) = '/';
            (*pWrite) += 2;
            (*pRead) += 2;

            return 0;
        }
        else if(*(*pRead + 1) == '*')
        {
            **pWrite = '/';
            *(*pWrite + 1) = '*';
            (*pWrite) += 2;
            (*pRead) += 2;
            return 2;
        }
        else
            return 3;
    }
    else if(**pRead == '"')
    {
        **pWrite = '"';
        (*pWrite) += 1;
        (*pRead) += 1;
        return 1;
    }
    else 
        return 3;
}

void fun3(char **pRead, char **pWrite)
{
    while(!((**pRead == '/' && (*(*pRead + 1) == '/' || *(*pRead + 1) == '*')) || (**pRead == '"')))
    {
        if(**pRead != '\0')
        {
            **pWrite = **pRead;
            (*pRead) += 1;
            (*pWrite) += 1;
        }
        else 
            return ;	
    }
}

void fun2(char **p1, char **p2)
{
    for(; **p1 != '*' || *((*p1)+1) != '/'; (*p1)++)
    {
        if(**p1 == '/' && (*(*p1 + 1) == '/' || *(* p1 + 1) == '*'))
        {
            *(*p2)++ = ' ';
            *(*p2)++ = ' ';
            (*p1)++;
        }
        else
        {
            **p2 = **p1;  
            (*p2)++;
        }
    }

    *(*p2)++ = *(*p1)++;
    *(*p2)++ = *(*p1)++;

}

void fun1(char **p1, char **p2)
{

    while(**p1 != '"')
    {
        if(**p1 == '\\' && *(*p1 + 1) == '"')
            *(*p2) ++ = *(*p1) ++;		

        *((*p2)++) = *((*p1)++);
    }
    *((*p2)++) = *((*p1)++);

}

void fun0(char **p1, char **p2)
{
    *((*p2)-1) = '*';

    while (**p1 != '\n'|| **p1 == EOF)
    { 
        if (**p1 == '/' && *((*p1)+1) == '/' )
        {
            *(*p2)++ = ' ';
            *(*p2)++ = ' ';
            (*p1)++;
            (*p1)++;
        }
        else if (**p1 == '/' && *((*p1)+1) == '*')
        {
            *(*p2)++ = ' ';
            *(*p2)++ = ' ';
            (*p1)++;
            (*p1)++;
        }
        else if (**p1 == '*' && *((*p1)+1) == '/')
        { 
            *(*p2)++ = ' ';
            *(*p2)++ = ' ';
            (*p1)++;
            (*p1)++;
        }
        else
            *(*p2)++ = *(*p1)++; 
    }  
    *(*p2)++ = '*';
    *(*p2)++ = '/';
    *(*p2)++ = '\n';
    if (**p1 == '\n')
        (*p1)++;
}
