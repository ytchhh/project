#include <stdlib.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#include "command.h"
#include "nfsutils.h"
#include "fsutils.h"
#include "strutils.h"
#include "miscutils.h"
#include "netutils.h"
#include "logutils.h"
#include "configparser.h"

static string LAMPT(".lampt");
static string IPKGFILE(".ipkgs");
static string RPKGFILE(".rpkgs");
static string UPKGFILE(".upkgs");

SyncCommand::SyncCommand(string host, string sharedir)
{
    this->host = host;
    this->sharedir = sharedir;
}

int SyncCommand::execute()
{
    int ret = 0;
    char buff[1024];
    ret = fsutils::abspath(LAMPT.c_str(), buff);
    if(!ret)
    {
        return -1;
    }

    string mppath(buff);

    ret = nfsutils::ismounted(host, sharedir, mppath);
    glogger << "here!!!!" << endl;
    glogger << "ret ismounted: " << ret << endl;

    if(!ret)
    {
        ret = nfsutils::mountnfs(host, sharedir, mppath);
        glogger << "ret mount: " << ret << endl;

        if(ret)
        {
            cerr << "nfs mount error" << endl;
            return -1;
        }
    }

    string cmd("cp ");
    string src, dest, opts;
    src = mppath + "/. " ;
    string syncdir;
    ret = gparser->getvalue("syncdir", syncdir);
    ret = fsutils::abspath(syncdir.c_str(), buff);

    glogger << "abspath: " << ret << endl;
    if(!ret)
    {
        nfsutils::umount(mppath);
        return -1;
    }
    dest = buff; 
    opts = " -r  --preserve=mode ";
    cmd += src + dest + opts;
    glogger << "cmd: " << cmd << endl;
    ret = system(cmd.c_str());
    nfsutils::umount(mppath, 1);

    return miscutils::getexitcode(ret);
}

SyncCommand::~SyncCommand()
{
}

SyncCommand* SyncCommand::createcmd(string host, string sharedir)
{
    SyncCommand* toret = new SyncCommand(host, sharedir);
    return toret;
}

PkgCommand::PkgCommand(string ipkgfile, string rpkgfile)
{
    this->ipkg = ipkgfile;
    this->rpkg = rpkgfile;
}

int PkgCommand::execute()
{
    string syncdir;
    int ret = gparser->getvalue("syncdir", syncdir);
    string ipkgpath(syncdir + "/" + IPKGFILE);
    string rpkgpath(syncdir + "/" + RPKGFILE);

    ifstream ipfile(ipkgpath.c_str());
    ifstream rpfile(rpkgpath.c_str());

    vector<string> ipkgs; 
    vector<string> rpkgs; 

    string line;
    while(!ipfile.eof())
    {
        getline(ipfile, line);
        ipkgs.push_back(line);
    }

    while(!rpfile.eof())
    {
        getline(rpfile, line);
        rpkgs.push_back(line);
    }

    copy(ipkgs.begin(), ipkgs.end(), ostream_iterator<string>(cout, " "));
    glogger << endl;
    copy(rpkgs.begin(), rpkgs.end(), ostream_iterator<string>(cout, " "));
    glogger << endl;

    ret = 0;
    string ipkgstr;
    string rpkgstr;

    strutils::join(ipkgs, " ", ipkgstr);
    strutils::join(rpkgs, " ", rpkgstr);

    glogger << "ipkgstr:" << ipkgstr << endl;
    glogger << "rpkgstr:" << rpkgstr << endl;

    string cmd;
    if(!ipkgs.empty())
    {
#ifdef RHEL
        cmd = "yum -y install " + ipkgstr;
#endif

#ifdef UBUNTU
        cmd = "apt-get -y --allow-unauthenticated --force-yes install " + ipkgstr;
#endif
    }

    if(!cmd.empty())
    {
        cmd += ";" ;
    }

    if(!rpkgs.empty())
    {
#ifdef RHEL
        cmd += "yum -y remove " + rpkgstr;
#endif

#ifdef UBUNTU
        cmd = "apt-get -y purge " + ipkgstr;
#endif

    }

    glogger << "pkg cmd:" << cmd << endl;
    ret = system(cmd.c_str());

    glogger << "pkgcmd ret:" << ret << endl;

    return miscutils::getexitcode(ret);
}

PkgCommand* PkgCommand::createcmd(string ipkgfile, string rpkgfile)
{
    PkgCommand * toret = new PkgCommand(IPKGFILE, RPKGFILE);
    return toret;
}

UpdateCommand::UpdateCommand(string upkgfile)
{
    this->upkgfile = upkgfile;

}

int UpdateCommand::execute()
{
    string syncdir;
    int ret = gparser->getvalue("syncdir", syncdir);
    string upkgpath(syncdir + "/" + UPKGFILE);

    ifstream upfile(upkgpath.c_str());

    vector<string> upkgs; 

    string line;
    while(!upfile.eof())
    {
        getline(upfile, line);
        upkgs.push_back(line);
    }

    copy(upkgs.begin(), upkgs.end(), ostream_iterator<string>(cout, " "));
    glogger << endl;

    ret = 0;
    string upkgstr;

    strutils::join(upkgs, " ", upkgstr);

    glogger << "upkgstr:" << upkgstr << endl;

    string cmd;
#ifdef RHEL
    cmd = "yum -y update " + upkgstr;
#endif

#ifdef UBUNTU
    cmd = "apt-get -y upgrade " + upkgstr;
#endif

    ret = system(cmd.c_str());

    return miscutils::getexitcode(ret);

    return 0;
}

UpdateCommand* UpdateCommand::createcmd(string upkgfile)
{
    UpdateCommand* toret = new UpdateCommand(upkgfile);
    return toret;
}

ScriptCommand::ScriptCommand(string scriptdir)
{
    this->plugindir = scriptdir;
}

void ScriptCommand::initscripts() 
{
    DIR *pdir = opendir(plugindir.c_str());

    string script;

    dirent* pent = NULL;
    while(NULL != (pent = readdir(pdir)))
    {
        switch(pent->d_type)
        {
            case DT_REG :
                script = pent->d_name;
                if(strutils::endswith(script, ".sh"))
                {
                    shellscripts.push_back(script);
                }
                if(strutils::endswith(script, ".py"))
                {
                    pythonscripts.push_back(script);
                }
                break;

            default:
                cerr << "unknow" << endl;
                break;
        }
    }

    sort(shellscripts.begin(), shellscripts.end());
    sort(pythonscripts.begin(), pythonscripts.end());

    glogger << "shell: ";

    copy(shellscripts.begin(), shellscripts.end(),
            ostream_iterator<string>(cout, " "));
    glogger<< endl; 

    glogger << "python: ";
    copy(pythonscripts.begin(), pythonscripts.end(),
            ostream_iterator<string>(cout, " "));
    glogger<< endl; 
}

int ScriptCommand::execute()
{
    initscripts();
    for(vector<string>::iterator it = shellscripts.begin();
            it != shellscripts.end(); ++it)
    {
        string cmd("cd plugins; sh ");
        cmd += *it;
        int ret = system( cmd.c_str());
        int rcode = miscutils::getexitcode(ret);
        if(rcode)
        {
            cerr << "script: " << *it << " gets error, "
                << "exitcode: " << rcode << endl;
        }
    }

    for(vector<string>::iterator it = pythonscripts.begin();
            it != pythonscripts.end(); ++it)
    {
        string cmd("cd plugins; python ");
        cmd += *it;
        int ret = system( cmd.c_str());
        int rcode = miscutils::getexitcode(ret);
        if(rcode)
        {
            cerr << "script: " << *it << " gets error, "
                << "exitcode: " << rcode << endl;
        }
    }
    return 0;
}

ScriptCommand* ScriptCommand::createcmd(string scriptdir)
{
    ScriptCommand* toret = new ScriptCommand(scriptdir);
    return toret;
}

pthread_mutex_t CommandExecuter::lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t CommandExecuter::cond = PTHREAD_COND_INITIALIZER;
int CommandExecuter::runningflag = 1;
deque<Command*> CommandExecuter::commands = deque<Command*>();

void CommandExecuter::extractmsg(char* recvbuf, int bufflen, sockaddr_in& saddr, string& myname)
{
    string serveraddr(inet_ntoa(saddr.sin_addr));
    glogger << "serveraddr:" << serveraddr << endl;

    Message* pmsg = (Message*)recvbuf;
    glogger << "cmd:" << pmsg->cmd << endl;
    glogger << "sdlen:" << pmsg->sdlen << endl;
    glogger << "tag:" << pmsg->tag << endl;

    char buff[256];

    buff[pmsg->sdlen] = '\0';
    memcpy(buff, pmsg->tag, pmsg->sdlen);
    string sharedir(buff);

    strcpy(buff, pmsg->tag + pmsg->sdlen);
    string mstr(buff);

    glogger << "share dir:" << sharedir << endl;
    glogger << "machines:"  << mstr << endl;
    
    if(!mstr.empty())
    {
        vector<string> machines;
        strutils::split(mstr, ",", machines);
        glogger << "machines:" << endl;

        if(!strutils::inlist(machines, myname))
        {
            return;
        }
    }

    deque<Command*> tempqueue;
    Command* pcmd = NULL;
    int cmd = pmsg->cmd;
    int temp = 1 ;
    if(cmd & temp)
    {
        pcmd = SyncCommand::createcmd(serveraddr, sharedir);
        tempqueue.push_back(pcmd);
    }
    temp = temp << 1;

    if(cmd & temp)
    {
        pcmd = PkgCommand::createcmd();
        tempqueue.push_back(pcmd);
    }

    temp = temp << 1;
    if(cmd & temp)
    {
        pcmd = UpdateCommand::createcmd();
        tempqueue.push_back(pcmd);
    }

    string plugindir;
    int ret = gparser->getvalue("plugindir", plugindir);
    glogger << "plugindir: " << plugindir << endl;
    pcmd = ScriptCommand::createcmd(plugindir);
    tempqueue.push_back(pcmd);

    pthread_mutex_lock(&lock);
    copy(tempqueue.begin(), tempqueue.end(), back_inserter(commands));
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
}

void* CommandExecuter::executecmd(void* args)
{
    while(runningflag)
    {
        if(commands.empty())
        {
            pthread_mutex_lock(&lock);
            if(commands.empty())
            {
                pthread_cond_wait(&cond, &lock);
                pthread_mutex_unlock(&lock);
            }
            else
            {
                pthread_mutex_unlock(&lock);
                continue;
            }
        }
        else
        {
            while(!commands.empty())
            {
                Command* pcmd = commands[0];

                pthread_mutex_lock(&lock);
                commands.pop_front();
                pthread_mutex_unlock(&lock);

                pcmd->execute();
                delete pcmd;
                pcmd = NULL;
            }
        }
    }
    pthread_exit(0);
}
