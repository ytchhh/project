#include "BZDMX.h"
#ifndef GLOBALDATA_H
#define GLOBALDATA_H
class GlobalData
{
private:
    unsigned int heroStrength;
    unsigned int poetryNum;
    unsigned int boss1Strength;
    
    unsigned allWord;
    unsigned ownWord;
    
    int wordId;
    
public:
    GlobalData()
    {
        heroStrength = 0;
        poetryNum = 0;
        boss1Strength = 0;
        allWord = 0;
        ownWord = 0;
        wordId = -1;
    }
    
    ~GlobalData()
    {}
    
    int getWordId() {return wordId;}
    unsigned getHeroStrength() {return heroStrength;}
    unsigned getPoetryNum() {return poetryNum;}
    unsigned getBoss1Strength() {return boss1Strength;}
    unsigned getAllWord() {return allWord;}
    unsigned getOwnWord() {return ownWord;}
    unsigned getLeaveWord() {return allWord-ownWord;}
    
    void setHeroStrength(unsigned newData) {heroStrength = newData;}
    void setPoetryNum(unsigned newData) {poetryNum = newData;}
    void setBoss1Strength(unsigned newData) {boss1Strength = newData;}
    void setAllWord(unsigned allWordNum) {allWord = allWordNum;}
    void setOwnWord(unsigned ownWordNum) {ownWord = ownWordNum;}
    void setWordId(int newWordId) {wordId = newWordId;}
};
#endif