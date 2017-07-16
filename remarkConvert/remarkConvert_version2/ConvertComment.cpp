#include"utili.h"

extern "C" int ConvertComment(FILE *inputfile, FILE *outputfile);

typedef enum
{
	NO_COMMENT_STATE,
	C_COMMENT_STATE,
	CPP_COMMENT_STATE,
    QUOTATION_STATE,
	END_STATE
}ENUM_STATE;

typedef struct StateMachine
{
	FILE *inputfile;
	FILE *outputfile;
	ENUM_STATE state;
    ENUM_STATE pre_state;
}StateMachine;

/////////////////////////////////////////////////////
StateMachine g_state;

void EventPro(char ch);
void EventProAtNo(char ch);
void EventProAtC(char ch);
void EventProAtCpp(char ch);
void EventProAtQuotation(char ch);
/////////////////////////////////////////////////////

int ConvertComment(FILE *inputfile, FILE *outputfile)
{
	if(inputfile==NULL || outputfile==NULL)
	{
		cout<<"argument is invalid."<<endl;
		return -1;
	}

	///////////////////////////////////////////
	g_state.inputfile = inputfile;
	g_state.outputfile = outputfile;
	g_state.state = NO_COMMENT_STATE;

	char ch;
	while(g_state.state != END_STATE)
	{
		ch = fgetc(g_state.inputfile);
		EventPro(ch);
	}

	return 0;
}

void EventPro(char ch)
{
	switch(g_state.state)
	{
	case NO_COMMENT_STATE:
		EventProAtNo(ch);
		break;
	case C_COMMENT_STATE:
		EventProAtC(ch);
		break;
	case CPP_COMMENT_STATE:
		EventProAtCpp(ch);
		break;
    case QUOTATION_STATE:
        EventProAtQuotation(ch);
        break;
	//case END_STATE:
	//	break;
	}
}
void EventProAtNo(char ch)
{
	char nextch;
	switch(ch)
	{
	case '/':
		nextch = fgetc(g_state.inputfile);
		if(nextch == '/') // C++
		{
			fputc('/',g_state.outputfile);
			fputc('*',g_state.outputfile);
			g_state.state = CPP_COMMENT_STATE;
		}
		else if(nextch == '*') // C
		{
			fputc('/',g_state.outputfile);
			fputc('*',g_state.outputfile);
			g_state.state = C_COMMENT_STATE;
        }
		else
		{
           fputc(ch,g_state.outputfile); 
           fputc(nextch,g_state.outputfile);
		}
		break;
    case '\"':
        fputc('\"',g_state.outputfile);
        g_state.pre_state = g_state.state;
        g_state.state = QUOTATION_STATE;
        break;
    case EOF:
        g_state.state = END_STATE;
        break;
    default:
        fputc(ch, g_state.outputfile);
        break;
        }
}
void EventProAtC(char ch)
{
    char nextch;
    switch(ch)
    {
        case '/':
            nextch = fgetc(g_state.inputfile);
            if (nextch == '/' || nextch == '*')
            {
                fputc(' ', g_state.outputfile); 
                fputc(' ', g_state.outputfile); 
            }
            else
            {
                fputc(ch, g_state.outputfile);
                fputc(nextch, g_state.outputfile);
            }
            break;
        case '*':
            while(ch == '*')
            {
                nextch = fgetc(g_state.inputfile);
                if (nextch == '/')
                {
                    fputc('*', g_state.outputfile); 
                    fputc('/', g_state.outputfile); 
                    g_state.state = NO_COMMENT_STATE;
                    break;
                }
                else if(nextch == '*')
                {
                    fputc('*', g_state.outputfile); 
                    ch = nextch;
                }
                else 
                {
                    fputc('*', g_state.outputfile); 
                    fputc(nextch, g_state.outputfile);
                    break;
                }
            }
            break;
        case '\"':
            g_state.pre_state = g_state.state;
            g_state.state = QUOTATION_STATE;
            fputc('\"', g_state.outputfile);
            break;
        default:
            fputc(ch,g_state.outputfile);
            break;
    }
}
void EventProAtCpp(char ch)
{
    char nextch;
    switch(ch)
    {
        case EOF:
            fputc('*', g_state.outputfile); 
            fputc('/', g_state.outputfile); 
            g_state.state = END_STATE;
            break;
        case '\n':
            fputc('*', g_state.outputfile); 
            fputc('/', g_state.outputfile); 
            fputc('\n', g_state.outputfile);
            g_state.state = NO_COMMENT_STATE;
            break;

        case '/':
            nextch = fgetc(g_state.inputfile);
            if (nextch == '/' || nextch == '*')
            {
                fputc(' ', g_state.outputfile); 
                fputc(' ', g_state.outputfile); 
            }
            else
            {
                fputc(ch, g_state.outputfile);
                fputc(nextch, g_state.outputfile);
            }
            break;
        case '*':
            while(ch == '*')
            {
                nextch = fgetc(g_state.inputfile);
                if (nextch == '/')
                {
                    fputc(' ', g_state.outputfile); 
                    fputc(' ', g_state.outputfile); 
                    break;
                }
                else if(nextch == '*')
                {
                    fputc('*', g_state.outputfile); 
                    ch = nextch;
                }
                else 
                {
                    fputc('*', g_state.outputfile); 
                    fputc(nextch, g_state.outputfile);
                    break;
                }
            }
            break;
        case '\"':
            g_state.pre_state = g_state.state;
            g_state.state = QUOTATION_STATE;
            fputc('\"', g_state.outputfile);
            break;
        default:
            fputc(ch,g_state.outputfile);
            break;
    }
}
void EventProAtQuotation(char ch)
{
    char nextch;
    switch (ch)
    {
        case '\"':
            g_state.state = g_state.pre_state;
            fputc(ch, g_state.outputfile);
            break;
        case '*':
            while(ch == '*')
            {
                nextch = fgetc(g_state.inputfile);
                if (nextch == '/' && g_state.pre_state == CPP_COMMENT_STATE)
                {
                    fputc(' ', g_state.outputfile); 
                    fputc(' ', g_state.outputfile); 
                    break;
                }
                else if(nextch == '*')
                {
                    fputc('*', g_state.outputfile); 
                    ch = nextch;
                }
                else 
                {
                    fputc('*', g_state.outputfile); 
                    fputc(nextch, g_state.outputfile);
                    break;
                }
            }
            break;
        default :
            fputc(ch, g_state.outputfile);
            break;
    }
}
