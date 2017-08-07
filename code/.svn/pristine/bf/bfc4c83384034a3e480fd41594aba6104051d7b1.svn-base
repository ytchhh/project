#ifndef __51CC__
#define __51CC__


#include <string>

//server side 
int nfsstart();
int nfsstop();
int nfsstatus();

int confignfs(string sharedir, string nfsopts);

//client side 
int mountnfs(string nfsloc, string sharedir, 
        string mpt, string mountopts="");
int ismounted(string nfsloc, string sharedir, string mpt);
int umount(string mpt, int isforce);

#endif
