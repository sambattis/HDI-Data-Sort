#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

struct Country {
    private:
    string name;
    double lifeExpectancy;
    double expectedSchooling;
    double averageSchooling;
    double GNIPerCapita;
    double HDI;
    
    public:
    Country(string name_, double lifeExpectancy_, double expectedSchooling_, double averageSchooling_, double GNIPerCapita_) {
        name = name_;
        lifeExpectancy = lifeExpectancy_;
        expectedSchooling = expectedSchooling_;
        averageSchooling = averageSchooling_;
        GNIPerCapita = GNIPerCapita_;
    }
    
    string GetName();
    double GetLifeExpectancy();
    double GetExpectedSchooling();
    double GetAverageSchooling();
    double GetGNIPerCapita();
    double GetHDI();
    void ReportBasicInfo();
    void ChangeHDI(double HDI_);
};

struct World {
    private:
    
    int numCountries;
    
    public:
    int GetNumCountries();
    vector<Country> countries;
    void AddCountriesVec(string name_, double lifeExpectancy_, double expectedSchooling_, double averageSchooling_, double GNIPerCapita_);
};


int World::GetNumCountries() {
    return numCountries;
}

void World::AddCountriesVec(string name_, double lifeExpectancy_, double expectedSchooling_, double averageSchooling_, double GNIPerCapita_) {
    countries.push_back(Country(name_, lifeExpectancy_, expectedSchooling_, averageSchooling_, GNIPerCapita_));
}

string Country::GetName() {
    return name;
}

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

void Country::ChangeHDI(double HDI_) {
    HDI = HDI_;
}

void Country::ReportBasicInfo() {
    cout << name << " " << lifeExpectancy << " " << expectedSchooling << " " <<averageSchooling << " " << GNIPerCapita << " " << HDI << endl;
}

void MakeHDIValues(World& world) {
    double minLife = 20;
    double maxLife = 85;
    double minSchool = 0;
    double maxExpSchool = 18;
    double maxAvgSchool = 15;
    double minGNI = 100;
    double maxGNI = 75000;
    double healthIndex;
    double expEducation;
    double avgEducation;
    double educationIndex;
    double incomeIndex;
    double result;
    
    
    for (int i = 0; i < world.countries.size(); i++) {
        double countryLife = world.countries[i].GetLifeExpectancy();
        double countryExp = world.countries[i].GetExpectedSchooling();
        double countryAvg = world.countries[i].GetAverageSchooling();
        double countryGNI = world.countries[i].GetGNIPerCapita();
        if (countryLife > 85.0) {
            countryLife = 85.0;
        }
        if (countryExp > 18.0) {
            countryExp = 18.0;
        }
        if (countryAvg > 15.0) {
            countryAvg = 15.0;
        }
        if (countryGNI > 75000) {
            countryGNI = 75000;
        }
        healthIndex = (countryLife - minLife)/(maxLife - minLife);
        expEducation = (countryExp - minSchool)/(maxExpSchool - minSchool);
        avgEducation = (countryAvg - minSchool)/(maxAvgSchool - minSchool);
        educationIndex = (expEducation + avgEducation)/2.0;
        incomeIndex = (log(countryGNI) - log(minGNI))/(log(maxGNI)-log(minGNI));
        result = healthIndex * educationIndex * incomeIndex;
        result = pow(result, 0.33333333);
        world.countries[i].ChangeHDI(result);
    }
}

void MakeCustomHDIValues(World& world) {
    double healthWeight;
    double educationWeight;
    double incomeWeight;
    cout << "Type weights 0.0 < 1.0 for health index, education index, and income index respectively. Weights must sum to 1, although note that this is not representing an actual X% Y% Z% weighting, but rather a vague approximation. Use extreme weights (0.9 on the stat with desired emphasis) to see a noticeable difference. Note that life expectancy, education, and income maxes will not change." << endl;
    cin >> healthWeight;
    cin >> educationWeight;
    cin >> incomeWeight;
    healthWeight = healthWeight - 0.3333333;
    educationWeight = educationWeight - 0.3333333;
    incomeWeight = incomeWeight - 0.33333333333;
    double minLife = 20;
    double maxLife = 85;
    double minSchool = 0;
    double maxExpSchool = 18;
    double maxAvgSchool = 15;
    double minGNI = 100;
    double maxGNI = 75000;
    double healthIndex;
    double expEducation;
    double avgEducation;
    double educationIndex;
    double incomeIndex;
    double result;
    
    
    for (int i = 0; i < world.countries.size(); i++) {
        double countryLife = world.countries[i].GetLifeExpectancy();
        double countryExp = world.countries[i].GetExpectedSchooling();
        double countryAvg = world.countries[i].GetAverageSchooling();
        double countryGNI = world.countries[i].GetGNIPerCapita();
        if (countryLife > 85.0) {
            countryLife = 85.0;
        }
        if (countryExp > 18.0) {
            countryExp = 18.0;
        }
        if (countryAvg > 15.0) {
            countryAvg = 15.0;
        }
        if (countryGNI > 75000) {
            countryGNI = 75000;
        }
        healthIndex = (countryLife - minLife)/(maxLife - minLife);
        expEducation = (countryExp - minSchool)/(maxExpSchool - minSchool);
        avgEducation = (countryAvg - minSchool)/(maxAvgSchool - minSchool);
        educationIndex = (expEducation + avgEducation)/2.0;
        incomeIndex = (log(countryGNI) - log(minGNI))/(log(maxGNI)-log(minGNI));
        healthIndex += 1 - healthWeight;
        educationIndex += 1 - educationWeight;
        incomeIndex += 1 - incomeWeight;
        result = (healthIndex) * (educationIndex) * (incomeIndex);
        result = pow(result, 0.33333333);
        world.countries[i].ChangeHDI(result/2);
    }
}


vector<Country> BucketSortByLifeExpectancy(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetLifeExpectancy() > max) {
            max = world.countries[i].GetLifeExpectancy();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetLifeExpectancy() < min) {
            min = world.countries[i].GetLifeExpectancy();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetLifeExpectancy() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetLifeExpectancy() > buckets[l][j].GetLifeExpectancy()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByExpectedSchooling(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetExpectedSchooling() > max) {
            max = world.countries[i].GetExpectedSchooling();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetExpectedSchooling() < min) {
            min = world.countries[i].GetExpectedSchooling();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetExpectedSchooling() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetExpectedSchooling() > buckets[l][j].GetExpectedSchooling()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByAverageSchooling(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetAverageSchooling() > max) {
            max = world.countries[i].GetAverageSchooling();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetAverageSchooling() < min) {
            min = world.countries[i].GetAverageSchooling();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetAverageSchooling() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetAverageSchooling() > buckets[l][j].GetAverageSchooling()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByGNI(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetGNIPerCapita() > max) {
            max = world.countries[i].GetGNIPerCapita();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetGNIPerCapita() < min) {
            min = world.countries[i].GetGNIPerCapita();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetGNIPerCapita() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetGNIPerCapita() > buckets[l][j].GetGNIPerCapita()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByHDI(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetHDI() > max) {
            max = world.countries[i].GetHDI();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetHDI() < min) {
            min = world.countries[i].GetHDI();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetHDI() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetHDI() > buckets[l][j].GetHDI()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

void ReadFile(string filename, World& world) {
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
         world.AddCountriesVec(name, lifeExpectancy, expectedSchooling, averageSchooling, GNIPerCapita);
      } else {
         break;  
      }
   }
}

int main()
{
    World world;
    string filename;
    cin >> filename;
    ReadFile(filename, world);
    cout << "For custom HDI, type yes. For normal HDI, type anything else and press enter." << endl;
    string mode;
    cin >> mode;
    if (mode == "yes") {
        MakeCustomHDIValues(world);
    } else {
        MakeHDIValues(world);
    }
    cout << "1 for Life Expectancy, 2 for Expected Schooling, 3 for Average Schooling, 4 for GNI/capita, 5 for HDI, 6 for custom HDI" << endl;
    int choice;
    cin >> choice;
    vector<Country> report;
    switch(choice) {
        case 1:
        report = BucketSortByLifeExpectancy(world);
        break;
        case 2:
        report = BucketSortByExpectedSchooling(world);
        break;
        case 3:
        report = BucketSortByAverageSchooling(world);
        break;
        case 4:
        report = BucketSortByGNI(world);
        break;
        case 5:
        report = BucketSortByHDI(world);
        break;
    }
    for (int i = 0; i < report.size(); i++) {
        report[i].ReportBasicInfo();
    }
    /*for (int i = 0; i < world.countries.size(); i++) {
        world.countries[i].ReportBasicInfo();
    }*/
    return 0;
}
