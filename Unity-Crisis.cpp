#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <stdlib.h>
#include <cstring>

using std::endl;
using std::vector;
using std::cout;
using std::string;
using std::pair;
using std::map;


class FactionFilesClass
{
    public:
    vector<string> files = {"angels.txt","believe.txt","gaians.txt",/*"brian.txt",*/"caretake.txt","cyborg.txt","drone.txt","fungboy.txt","hive.txt","morgan.txt","peace.txt","pirates.txt",/*"sid.txt",*/"spartans.txt","univ.txt","usurper.txt"};
}FactionFiles;

class AlterLinesClass
{
    public:
          vector<string> namesLine;
          vector<string> socialLine;
          vector<string> proLine;
          vector<string> antiLine;
          vector<string> demonymLine;
          int whether;

}AlterLines;

class RandomVectorsClass
{
    public:
        vector<string> pacifist = {"-1","-1","-1","-1","-1","0","0","1"};
        vector<string> erratic = {"-1","0","0","0","0","0","1","1"};
        vector<string> aggressive = {"0","0","0","1","1","1","1","1"};
        vector<string> prioritiesYes = {"1","1","1","1","1","1","1","0"};
        vector<string> prioritiesNo = {"1","0","0","0","0","0","0","0"};

        vector<string> extraSocial =
            {
            "+ECONOMY",
            "+EFFIC",
            "+GROWTH",
            "+INDUSTRY",
            "+MORALE",
            "+PLANET",
            "+POLICE",
            "+PROBE",
            "+RESEARCH",
            "+SUPPORT",
            //"ROBUST, ECONOMY",
            //"ROBUST, EFFIC",
            //"ROBUST, GROWTH",
            //"ROBUST, INDUSTRY",
            //"ROBUST, MORALE",
            //"ROBUST, PLANET",
            //"ROBUST, POLICE",
            //"ROBUST, PROBE",
            //"ROBUST, RESEARCH",
            //"ROBUST, SUPPORT",
            "AQUATIC, 0, TECH, DocFlex",
            "TECH, 1",
            "PSI, -20"
            };

        vector<pair<string, string>> extraSocialEdit =
            {
                {"SOCIAL", "+ECONOMY"},
                {"SOCIAL", "+EFFIC"},
                {"SOCIAL", "+GROWTH"},
                {"SOCIAL", "+INDUSTRY"},
                {"SOCIAL", "+MORALE"},
                {"SOCIAL", "+PLANET"},
                {"SOCIAL", "+POLICE"},
                {"SOCIAL", "+PROBE"},
                {"SOCIAL", "+RESEARCH"},
                {"SOCIAL", "+SUPPORT"},
                //"ROBUST", "ECONOMY",
                //"ROBUST", "EFFIC",
                //"ROBUST", "GROWTH",
                //"ROBUST", "INDUSTRY",
                //"ROBUST", "MORALE",
                //"ROBUST", "PLANET",
                //"ROBUST", "POLICE",
                //"ROBUST", "PROBE",
                //"ROBUST", "RESEARCH",
                //"ROBUST", "SUPPORT",
                //AQUATIC, 0, TECH, DocFlex",
                {"SOCIAL", "TECH, 1"},
                {"SOCIAL", "PSI, -20"}
            };

        string randSocResult;
        string socialMark = "SOCIAL";
        string reversa;
        vector<pair<string, int>> dfgfTest;

}RandomVectors;


map<string,string> Techs()
{
    map<string,string> within;
    within["Biogen"] = "Biogenetics";
    within["Indust"] = "Industrial Base";
    within["InfNet"] = "Information Networks";
    within["Physic"] = "Applied Physics";
    within["Psych"] = "Social Psych";
    within["Mobile"] = "Doctrine: Mobility";
    within["Ecology"] = "Centauri Ecology";
    within["DocLoy"] = "Doctrine: Loyalty";
    return within;
}

map<string,string> quant()
{
    map<string,string> plusQuantity;
    plusQuantity["+++"] = "+3";
    plusQuantity["++"] = "+2";
    plusQuantity["+"] = "+1";
    plusQuantity["-"] = "-1";
    plusQuantity["--"] = "-2";
    plusQuantity["---"] = "-3";
    return plusQuantity;
}

map<string, vector<string>> relMods()

{
    map<string, vector<string>> aMap;
    aMap["+RESEARCH"] = {"ROBUST, RESEARCH", "+RESARCH"};
    aMap["+GROWTH"] = {"ROBUST, GROWTH", "+GROWTH"};
    return aMap;
}

map<string,string> bonusNames()
{
    map<string,string> inside;
    inside["+ECONOMY"] = ": {Contingent of Unity energy scientists}";
    inside["+EFFIC"] = ": {Sparse resources on Planetfall}";
    inside["+GROWTH"] = ": {Plentiful food on Planetfall}";
    inside["-GROWTH"] = ": {Genetic damage from Unity reactor leak}";
    inside["+INDUSTRY"] = ": {Contingent of Unity Engineers}";
    inside["+MORALE"] = ": {Martial tradition, escaped Unity by force}";
    inside["+PLANET"] = ": {Contingent of Unity ecologists}";
    inside["+POLICE"] = ": {Sparse living space on Planetfall}";
    inside["+PROBE"] = ": {Escaped Unity with subterfuge}";
    inside["+RESEARCH"] = ": {Contingent of Unity researchers}";
    inside["+SUPPORT"] = ": {Contingent of Unity technicians}";
    inside["AQUATIC, 0, TECH, DocFlex"] = "";
    inside["PSI, -20"] = "";
    inside["UNIT, 1"] = "";
    inside["TECH, 1"] = "";
    inside["ROBUST, ECONOMY"] = "";
    inside["ROBUST, EFFIC"] = "";
    inside["ROBUST, GROWTH"] = "";
    inside["ROBUST, INDUSTRY"] = "";
    inside["ROBUST, MORALE"] = "";
    inside["ROBUST, PLANET"] = "";
    inside["ROBUST, POLICE"] = "";
    inside["ROBUST, PROBE"] = "";
    inside["ROBUST, RESEARCH"] = "";
    inside["ROBUST, SUPPORT"] = "";
    return inside;
}


map<string,string> BonusText()
{
    map<string,string> interior;
    interior["+ECONOMY"] = "+1 ECONOMY";
    interior["+EFFIC"] = "+1 EFFICIENCY";
    interior["+GROWTH"] = "+1 GROWTH";
    interior["-GROWTH"] = "-1 GROWTH";
    interior["+INDUSTRY"] = "+1 INDUSTRY";
    interior["+MORALE"] = "+1 MORALE";
    interior["+PLANET"] = "+1 PLANET";
    interior["+POLICE"] = "+1 POLICE";
    interior["+PROBE"] = "+1 PROBE";
    interior["+RESEARCH"] = "+1 RESEARCH";
    interior["+SUPPORT"] = "+1 SUPPORT";
    interior["AQUATIC, 0, TECH, DocFlex"] = "Aquatic faction, pod landed in Planet's ocean";
    interior["PSI, -20"] = "-20% Psi combat- Traumatic crisis on Planetfall";
    interior["TECH, 1"] = "One BONUS TECH hacked from Unity databanks";
    interior["ROBUST, ECONOMY"] = "Penalties to ECONOMY halved";
    interior["ROBUST, EFFIC"] = "Penalties to EFFICIENCY halved";
    interior["ROBUST, GROWTH"] = "Penalties to GROWTH halved";
    interior["ROBUST, INDUSTRY"] = "Penalties to INDUSTRY halved";
    interior["ROBUST, MORALE"] = "Penalties to MORALE halved";
    interior["ROBUST, PLANET"] = "Penalties to PLANET halved";
    interior["ROBUST, POLICE"] = "Penalties to POLICE halved";
    interior["ROBUST, PROBE"] = "Penalties to PROBE halved";
    interior["ROBUST, RESEARCH"] = "Penalties to RESEARCH halved";
    interior["ROBUST, SUPPORT"] = "Penalties to SUPPORT halved";
    return interior;
}


string chooseString (vector<string> pickVec)
{
        int randomIndex = rand() % pickVec.size();
        string resultString;
        resultString = pickVec[randomIndex];
        return resultString;
}

pair<string, string> choosePair (vector<pair<string, string>> pickVec)
{
        int randomIndex = rand() % pickVec.size();
        pair<string, string> resultString;
        resultString = pickVec[randomIndex];
        return resultString;
}

vector<string> spaceCleanerLeadingSpace(vector<string> vect, int lineNumber)
{
    string item_0 = vect[0];
    if (lineNumber > 13)
    {
        vect[0]=vect[0].erase(0,1);
    }

    for (int i = 0; i < vect.size(); i++)
    {
        string item = vect[i];
//        char first = item[0];
        if (item[0] == ' ')
            {
                vect[i] = item.erase(0,1);
        }
//        std::cout << "Space erased??:" << vect[i] << endl;
    }
//    std::cout << "Cleaned Space" << endl;
    return vect;
}

vector<string> fileSplitter(string stringFile)
{
    string token;
    vector<string> lineVect;
    while(token != stringFile)
    {
//        cout << n << ", ";
//        n++;
        token = stringFile.substr(0, stringFile.find_first_of("\n"));
        stringFile = stringFile.substr(stringFile.find_first_of("\n") + 1);
//changing to carriage return \r instead of \n  seems to get the string processed properly instead of looping over the start of the vector when iterator reaches there.
        lineVect.push_back(token);
    }
    //for (int i = 1; i<lineVect.size(); i++) {lineVect[i].erase(0,1);};
    //cout << "fileSplitter testing end, returning" << endl;
    //cout << "split file lines \\n to " << lineVect.size() << " tokens" << endl;
    return lineVect;
}


vector<string> lineSplitter(vector<string> all_lines, int index)
{
    string token;
    string line = all_lines[index];
    //"last char needs to be , for social splitter"
    vector<string> indiVect;
    while(token != line)
    {
        token = line.substr(0, line.find_first_of(","));
        line = line.substr(line.find_first_of(",") + 1);
        if (token != "\0" and token != "\n"/* and token !="\r"*/) {indiVect.push_back(token);/* std::cout << "Token: " << token << endl;*/};    }
    indiVect = spaceCleanerLeadingSpace(indiVect, index);
    return indiVect;
}


string joinLine(vector<string> to_join, string delimiter)
{
    string joinedUp;
    for (const auto &piece : to_join) joinedUp = joinedUp + delimiter + piece;
    joinedUp = joinedUp.erase(0,2);

    return joinedUp;
}

class LocateVarsClass
    {
        public:
            int i = 0;
            string eachLine;

    }LocateVars;

int locateInsert1(vector<string> lines, string toLocate)
{
    for (LocateVars.i; LocateVars.i<lines.size(); LocateVars.i++)
    {
        LocateVars.eachLine = lines[LocateVars.i];
        if (LocateVars.eachLine == toLocate) {break;}
    }
    LocateVars.i++;
    LocateVars.eachLine = lines[LocateVars.i];
    while (LocateVars.eachLine[0]=='^') {/*std::cout << LocateVars.i << LocateVars.eachLine << endl; */LocateVars.i++; LocateVars.eachLine = lines[LocateVars.i];}
//    std::cout << "HERE IT IS, index " << LocateVars.i << ": " << LocateVars.eachLine << endl;
    int indexValue = LocateVars.i-1;
    LocateVars.i = 0;
//    std::cout << "indexValue: " << indexValue << endl;
    return indexValue;
}

int locateInsertTech(vector<string> lines)
{
    for (LocateVars.i; LocateVars.i<lines.size(); LocateVars.i++)
    {
        LocateVars.eachLine = lines[LocateVars.i];

        if (LocateVars.eachLine[1] == 'T' and (LocateVars.eachLine[2] == 'E')) {break;}
    }
//    cout << "HERE IT IS, index " << LocateVars.i << ": " << LocateVars.eachLine << endl;
    int indexValue = LocateVars.i;
    LocateVars.i = 0;
    return indexValue;
}

int locateInsertEndMod(vector<string> lines, string toLocate)
{
    //int i=0;
    //string eachLine;
    for (LocateVars.i; LocateVars.i<lines.size(); LocateVars.i++)
        {
            LocateVars.eachLine = lines[LocateVars.i];
            if (LocateVars.eachLine == toLocate) {break;}
        }
    LocateVars.i++;
    LocateVars.eachLine = lines[LocateVars.i];
    //cout << lines.size() << endl;
    //cout << "noprob" << endl;
    while (LocateVars.eachLine[0]=='^' and (LocateVars.eachLine[3]==' ') and (LocateVars.eachLine[1]=='+' or LocateVars.eachLine[1]=='-'))
        {
            //cout << "finding: " << LocateVars.i << LocateVars.eachLine << endl;
            LocateVars.i++; LocateVars.eachLine = lines[LocateVars.i];
        }
//    cout << 1 << endl;
//    std::cout << "HERE IT IS, index " << LocateVars.i << ": " << LocateVars.eachLine << endl;
    int indexValue = LocateVars.i-1;
//    cout << 1 << endl;
    LocateVars.i = 0;
//    cout << 1 << endl;
    //cout << "indexValue: " << indexValue << endl;
    return indexValue;
}
// need to do somesocialPair like this to detect existing mods.
string revers (string mod)
{
    if (mod[0] == '+') { mod[0] = '-'; }
    else if (mod[0] == '-') { mod[0] = '+'; }
    return mod;
}

string revers2 (string mod)
{
    if (mod[1] == '+') { mod[1] = '-'; }
    else if (mod[1] == '-') { mod[1] = '+'; }
    return mod;
}

string revers3 (string mod)
{
    if (mod[1] == '+') { mod[1] = '-'; }
    else if (mod[1] == '-') { mod[1] = '+'; }
    return mod;
}

int locateEras(vector<string> lines, string toLocate)
{
    toLocate = revers2(toLocate);
    //cout << toLocate << endl;

    int length = toLocate.size();
    for (LocateVars.i; LocateVars.i<lines.size(); LocateVars.i++)
        {

            LocateVars.eachLine = lines[LocateVars.i];
            string eacc = LocateVars.eachLine.substr(0, length);
            //cout << eacc << endl;
            if (eacc == toLocate) { break;}
        }
    int indexValue = LocateVars.i;
    LocateVars.i = 0;
   // cout << "indexValue: " << indexValue << endl;
    return indexValue;
}

string stripLead(string rull)
    {
        string outp;
        for (int i = 0; i<rull.size(); i++)
            if (rull[i] != '+' and rull[i] != '-')
            {
                outp = outp + rull[i];
            }
    return outp;
    }

string textify(string rule)
{

    string numberMod;
    string socialName;
    map<string,string> boni = bonusNames();
    map<string,string> bonust = BonusText();

    numberMod = /* pos_or_neg + interstring + " " + */bonust[rule] + boni[rule] ;

    return numberMod;
}

string reassemble(vector<string> stringFrom)
{
    string line13 = joinLine(AlterLines.namesLine, ", ");
    string line14 = "  " + joinLine(AlterLines.socialLine, ", ");
    string line15 = "  " + joinLine(AlterLines.proLine, ", ");
    string line16 = "  " + joinLine(AlterLines.antiLine, ", ");
    string line17 = "  " + joinLine(AlterLines.demonymLine, ", ");

    stringFrom[13] = line13;
    stringFrom[14] = line14;
    stringFrom[15] = line15;
    stringFrom[16] = line16;
    stringFrom[17] = line17;

    string reassembled;
    reassembled = joinLine(stringFrom, "\r\n");
//    std::cout << line14 << endl;
    return reassembled;
}

vector<string> randoAggress(vector<string> namesLine)
{
    string digit = namesLine[7];
    if (digit == "0"){namesLine[7] = chooseString(RandomVectors.erratic);}
    else if (digit == "-1"){namesLine[7] = chooseString(RandomVectors.pacifist);}
    else if (digit == "1"){namesLine[7] = chooseString(RandomVectors.aggressive);}
    return namesLine;
}

vector<string> randoPriorities(vector<string> namesLine)
{
    string conquer = namesLine[8];
    string discover = namesLine[9];
    string build = namesLine[10];
    string explore = namesLine[11];

    if (conquer == "1"){namesLine[8] = chooseString(RandomVectors.prioritiesYes);}
    else {namesLine[8] = chooseString(RandomVectors.prioritiesNo);}
    if (discover == "1"){namesLine[9] = chooseString(RandomVectors.prioritiesYes);}
    else {namesLine[9] = chooseString(RandomVectors.prioritiesNo);}
    if (build == "1"){namesLine[10] = chooseString(RandomVectors.prioritiesYes);}
    else {namesLine[10] = chooseString(RandomVectors.prioritiesNo);}
    if (explore == "1"){namesLine[11] = chooseString(RandomVectors.prioritiesYes);}
    else {namesLine[11] = chooseString(RandomVectors.prioritiesNo);}

    return namesLine;
}


vector<string> randoSocialEdit(vector<string> socialLine)
{
    pair<string, string> socialPair = choosePair(RandomVectors.extraSocialEdit);

    string plusRan = "+" + RandomVectors.randSocResult;
    string nusRan = "-" + RandomVectors.randSocResult;
    string dubRan = RandomVectors.randSocResult[0] + RandomVectors.randSocResult;
    string reversa = revers(RandomVectors.randSocResult);

    string reversMore = reversa[0] + reversa;

    AlterLines.whether = 0;
    if ( RandomVectors.randSocResult[0] == '+' or RandomVectors.randSocResult[0] == '+')
    {
        //cout << "+- found" << endl;
        for (int n = 0; n<socialLine.size(); n++)
        {
            //cout << n << ":" << socialLine[n] << endl;
            string varOnLine = socialLine[n];
            if (varOnLine == reversa)
                {
                    socialLine.erase (socialLine.begin() + n);
                    //cout << "n=" << n << endl;
                    socialLine.erase (socialLine.begin() + n - 1 );
                    //cout << "n=" << n << endl;
                    //need to delete datalinks entry too
                    //cout << varOnLine << " found reversed " << revers << " is the reverse of " << RandomVectors.randSocResult << endl;
                    //RandomVectors.randSocResult = "";//nosocialPair, remove the other too
                    AlterLines.whether = 1;
                    break;
                    //eg c = 0
                    }
            else if (varOnLine == RandomVectors.randSocResult)
                {
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n);
                    //need to delete datalinks entry too
                    //cout << varOnLine << " found exact dupe before push_back of random value " << RandomVectors.randSocResult << endl;
                    RandomVectors.randSocResult = dubRan;
                    socialLine.push_back(RandomVectors.socialMark);
                    socialLine.push_back(RandomVectors.randSocResult);
                    AlterLines.whether = 2;
                    //need to exit from here- otherwise it will iterate to the end and find the newly added.
                    //eg c = 1
                    break;
                    }
            else if (varOnLine == dubRan)
                {
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n);
                    //need to delete datalinks entry too
                    //cout << varOnLine << dubRan << "found double dupe before push_back of random value " << RandomVectors.randSocResult << endl;
                    RandomVectors.randSocResult = dubRan[0] + dubRan;
                    socialLine.push_back(RandomVectors.socialMark);
                    socialLine.push_back(RandomVectors.randSocResult);
                    AlterLines.whether = 3;
                    break;
                    }
            else if (varOnLine == reversMore)
                {
                    //cout << varOnLine << " found reversed double " << reversMore << " is the reverse of " << RandomVectors.randSocResult << endl;
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n);
                    //need to delete datalinks entry too
                    RandomVectors.randSocResult = reversa;
                    socialLine.push_back(RandomVectors.socialMark);
                    socialLine.push_back(RandomVectors.randSocResult);
                    AlterLines.whether = 4;
                    break;
                }

        }
        if (AlterLines.whether == 0)
            {
                socialLine.push_back(RandomVectors.socialMark);
                socialLine.push_back(RandomVectors.randSocResult);
            }
    }
    else
    {
                //adding another loop to prevent adding two of the same
                for (int n = 0; n<socialLine.size(); n++)
                {
                    string varOnLine = socialLine[n];
                    if (varOnLine == RandomVectors.randSocResult)
                    {
                        socialLine.erase (socialLine.begin() + n);
                        socialLine.erase (socialLine.begin() + n);
                    }
                    //cout << n << ":" << socialLine[n] << endl;

                }
        socialLine.push_back(RandomVectors.randSocResult);
    }

    return socialLine;
}


vector<string> randoSocial(vector<string> socialLine)
{
    RandomVectors.randSocResult = chooseString(RandomVectors.extraSocial);
    //RandomVectors.randSocResult = "TECH, 1";//testing
    string plusRan = "+" + RandomVectors.randSocResult;
    string nusRan = "-" + RandomVectors.randSocResult;
    string dubRan = RandomVectors.randSocResult[0] + RandomVectors.randSocResult;
    string reversa = revers(RandomVectors.randSocResult);
    //case??

    string reversMore = reversa[0] + reversa;
    //cout << "here?? not yet loop " << RandomVectors.randSocResult << endl;
    AlterLines.whether = 0;
    if ( RandomVectors.randSocResult[0] == '+' or RandomVectors.randSocResult[0] == '+')
    {
        //cout << "+- found" << endl;
        for (int n = 0; n<socialLine.size(); n++)
        {
            //cout << n << ":" << socialLine[n] << endl;
            string varOnLine = socialLine[n];
            if (varOnLine == reversa)
                {
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n - 1 );
                    AlterLines.whether = 1;
                    break;
                    }
            else if (varOnLine == RandomVectors.randSocResult)
                {
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n);
                    RandomVectors.randSocResult = dubRan;
                    socialLine.push_back(RandomVectors.socialMark);
                    socialLine.push_back(RandomVectors.randSocResult);
                    AlterLines.whether = 2;

                    break;
                    }
            else if (varOnLine == dubRan)
                {
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n);
                    RandomVectors.randSocResult = dubRan[0] + dubRan;
                    socialLine.push_back(RandomVectors.socialMark);
                    socialLine.push_back(RandomVectors.randSocResult);
                    AlterLines.whether = 3;
                    break;
                    }
            else if (varOnLine == reversMore)
                {
                    socialLine.erase (socialLine.begin() + n);
                    socialLine.erase (socialLine.begin() + n);
                    //need to delete datalinks entry too
                    RandomVectors.randSocResult = reversa;
                    socialLine.push_back(RandomVectors.socialMark);
                    socialLine.push_back(RandomVectors.randSocResult);
                    AlterLines.whether = 4;
                    break;
                }
        }
        if (AlterLines.whether == 0)
            {
                socialLine.push_back(RandomVectors.socialMark);
                socialLine.push_back(RandomVectors.randSocResult);
            }
    }
    else
    {
                //adding another loop to prevent adding two of the same. atm this doesn't work because ones that aren't SOCIAL include commas for their other part
                for (int n = 0; n<socialLine.size(); n++)
                {
                    string varOnLine = socialLine[n];
                    if (varOnLine == RandomVectors.randSocResult)
                    {
                        socialLine.erase (socialLine.begin() + n);
                        socialLine.erase (socialLine.begin() + n);
                    }

                }
        socialLine.push_back(RandomVectors.randSocResult);
    }
    return socialLine;
}

string editBuild (string stringFiled)
{
    vector<string> fileLines = fileSplitter(stringFiled);
    if ( fileLines[13].substr(fileLines[13].length() -1 ) != ",")
        {
            //cout << "Adding comma to end of line 13" << endl;
            fileLines[13] += ",";
        }
//    cout << "added comma" << endl;
    AlterLines.namesLine = lineSplitter(fileLines, 13);
    AlterLines.socialLine = lineSplitter(fileLines, 14);
    AlterLines.proLine = lineSplitter(fileLines, 15);
    AlterLines.antiLine = lineSplitter(fileLines, 16);
    AlterLines.demonymLine = lineSplitter(fileLines, 17);
    AlterLines.namesLine = randoAggress(AlterLines.namesLine);
    AlterLines.namesLine = randoPriorities(AlterLines.namesLine);
    AlterLines.socialLine = randoSocial(AlterLines.socialLine);
    fileLines[13] = joinLine(AlterLines.namesLine, ", ");
    fileLines[14] = "  " + joinLine(AlterLines.socialLine, ", ");
    fileLines[15] = "  " + joinLine(AlterLines.proLine, ", ");
    fileLines[16] = "  " + joinLine(AlterLines.antiLine, ", ");
    fileLines[17] = "  " + joinLine(AlterLines.demonymLine, ", ");

    map<string,string> techsMap = Techs();
    int dataL1Index = locateInsertTech(fileLines);
    string techCode = AlterLines.socialLine[1];
    fileLines[dataL1Index] = "^TECH: {" + techsMap[techCode] + "}";
    int dataL2Index = 0;

    // if these are going to be with commas the iterator needs to search for both elements
    map<string, string> tempMap = BonusText();
    if (AlterLines.whether == 0)
        {
            dataL2Index = locateInsertEndMod(fileLines, "#DATALINKS2")+1;
            fileLines.insert(fileLines.begin()+dataL2Index, "^" + textify(RandomVectors.randSocResult));
            //cout << "Added datalinx" << endl;
        }
    else if (AlterLines.whether == 1)
        {
            dataL2Index = locateEras(fileLines, "^" + tempMap[RandomVectors.randSocResult]);
            fileLines[dataL2Index].erase();
        }
    else if (AlterLines.whether == 2)
        {
            dataL2Index = locateEras(fileLines, "^" + tempMap[RandomVectors.randSocResult]);
            fileLines[dataL2Index] = fileLines[dataL1Index].replace(3, 3, "2");
        }
    else if (AlterLines.whether == 3)
        {
            dataL2Index = locateEras(fileLines, "^" + tempMap[RandomVectors.randSocResult]);
            fileLines[dataL2Index] = fileLines[dataL1Index].replace(2, 3, "+3");
        }
    else if (AlterLines.whether == 4)
        {
            dataL2Index = locateEras(fileLines, "^" + tempMap[RandomVectors.randSocResult]);
            fileLines[dataL2Index] = fileLines[dataL1Index].replace(2, 3, "-1");
        }
    string remade = reassemble(fileLines);
    return remade;
}

string getCurrentDirectoryOnWindows()
{
    /*const*/ unsigned long maxDir = 260;
    char currentDir[maxDir];
    GetCurrentDirectory(maxDir, currentDir);
    return string(currentDir);
}

int main()
{
  string folderPath = getCurrentDirectoryOnWindows() + "\\";
  string randomiserFiles = folderPath + "original_";
  srand(time(NULL));
  string fileName;
  string joined;
  vector<std::ifstream> allOfThem;
  string itfiPath;
  string randiPath;
  std::ifstream streem;
  std::ifstream orig;
  std::ifstream writ;

  for ( string x : FactionFiles.files )
    {
        //cout << "===========" << x << "===========" << endl;
        itfiPath = folderPath + x;
        randiPath = randomiserFiles + x;
        streem.open(randiPath, std::ifstream::in);
        if ( streem.good() )
                {
                    //cout << "found backup file" << endl;
                }
        else
                {
                    orig.open(folderPath + x, std::ifstream::in);

                    std::ofstream desti(randomiserFiles + x, std::ios::binary);
                    desti << orig.rdbuf();
                    orig.close();
                    //cout << "saved" << endl;
                }
        streem.close();
    }

    cout << "UNITY Datanet 2.1" << endl;
    for ( string facf : FactionFiles.files )
        {
            //cout << endl << "===========" << facf << "===========" << endl << endl;
            string joined = folderPath+"original_"+facf;
            //cout << joined << endl;
            string joinedOut = folderPath+facf;
            //cout << joinedOut << endl;
            //std::cout << joined << endl;
            std::ifstream inFile (joined, std::ifstream::binary);
            //cout << 1 << endl;
            string stringFiled((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
            //cout << "stringFiled size " << stringFiled.size() << endl;
            //cout << stringFiled << endl;
            //cout << "before editBuild" << endl;
            string outString = editBuild(stringFiled);
            //cout << "after editBuild" << endl;
            std::ofstream outfile (joinedOut,std::ofstream::binary);
            //cout << 4 << endl;
            outfile << outString;
            //cout << 5 << endl;
            inFile.close();
        }
    //cout << "Disengage pod bay interlocks Y/N?" << endl;
    cout << endl << "Faction profiles updated." << endl;

    return 0;
}
