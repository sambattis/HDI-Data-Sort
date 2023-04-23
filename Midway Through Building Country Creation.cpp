#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <map>

using namespace std;

struct Country {
    private:
    double lifeExpectancy;
    double expectedSchooling;
    double averageSchooling;
    double GNIPerCapita;
    double HDI;
    
    public:
    double GetLifeExpectancy();
    double GetExpectedSchooling();
    double GetAverageSchooling();
    double GetGNIPerCapita();
    double GetHDI();
};

double Country::GetLifeExpectancy() {
    return lifeExpectancy;
}

double Country::GetExpectedSchooling() {
    return expectedSchooling;
}

double Country::GetAverageSchooling() {
    return averageSchooling;
}

double Country::GetGNIPerCapita() {
    return GNIPerCapita;
}

double Country::GetHDI() {
    return HDI;
}


void ReadFile(string filename) {
   fstream file(filename);
   string unParsed;
   double lifeExpectancy;
   double expectedSchooling;
   double averageSchooling;
   double GNIPerCapita;
   while (true) {
      if (getline(file, unParsed)) {
         int firstNum = 0;
         int start = 0;
         int tracker = 0;
         while (true) {
             if (isdigit(unParsed[tracker])) {
                 firstNum = tracker;
                 break;
             }
             tracker++;
         }
         string name = unParsed.substr(start, firstNum - 1);
         start = firstNum;
         int spacePos = unParsed.find(' ', start);
         lifeExpectancy = stod(unParsed.substr(start, spacePos-1));
         start = spacePos+1;
         spacePos = unParsed.find(' ', start);
         expectedSchooling = stod(unParsed.substr(start, spacePos-1));
         start = spacePos+1;
         spacePos = unParsed.find(' ', start);
         averageSchooling = stod(unParsed.substr(start, spacePos-1));
         start = spacePos+1;
         GNIPerCapita = stod(unParsed.substr(start));
         cout << name << " " << lifeExpectancy << " " << expectedSchooling << " " <<averageSchooling << " " << GNIPerCapita << endl;
      } else {
         break;  
      }
   }
}

int main()
{
    string filename;
    cin >> filename;
    ReadFile(filename);
    return 0;
}
