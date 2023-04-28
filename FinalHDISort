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
#include <chrono>

using namespace std;
using chrono::nanoseconds;
using chrono::duration_cast;

struct Country {
    private:
    string name;
    double lifeExpectancy;
    double expectedSchooling;
    double averageSchooling;
    double GNIPerCapita;
    double HDI;
    
    public:
    Country() {
        
    }
    
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
    
    
    cout << name;
    for(int i = 0; i < 37 - name.length(); i++) {
        cout << " ";
    }
    
    cout << fixed << showpoint;
    cout << setprecision(1);
    cout << lifeExpectancy;
    cout << "    ";
    
    if(expectedSchooling >= 10.0) {
        cout << expectedSchooling << "    ";
    }
    else {
        cout << expectedSchooling << "     ";
    }   
    
    if(averageSchooling >= 10.0) {
        cout << averageSchooling << "    ";
    }
    else {
        cout << averageSchooling << "     ";
    }
    
    if(GNIPerCapita < 1000.0) {
        cout << GNIPerCapita << "      ";
    }
    else if(GNIPerCapita < 10000.0) {
        cout << GNIPerCapita << "     ";
    }   
    else if(GNIPerCapita < 100000.0) {
        cout << GNIPerCapita << "    ";
    }
    else {
        cout << GNIPerCapita << "   ";
    }
    
    cout << fixed << showpoint;
    cout << setprecision(4);
    cout << HDI << endl;
    
    //cout << HDI << endl;
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

int FindIndex(World& world, string name) {
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetName() == name) {
            return i;
        }
    }
    return -1;
}

void ComparisonReport(World& world) {
    string nameA;
    string nameB;
    cout << endl;
    cout << "Input the first country to be compared: ";
    cin >> nameA;
    cout << "Input the second country to be compared: ";
    cin >> nameB;
    cout << "Reporting on " << nameA << " and " << nameB << "." << endl;
    cout << endl;
    int nameALoc = FindIndex(world, nameA);
    int nameBLoc = FindIndex(world, nameB);
    
    if (world.countries[nameALoc].GetLifeExpectancy() > world.countries[nameBLoc].GetLifeExpectancy()) {
        double difference = world.countries[nameALoc].GetLifeExpectancy() - world.countries[nameBLoc].GetLifeExpectancy();
        cout << "- " << nameA << " has a life expectancy of " << world.countries[nameALoc].GetLifeExpectancy() << ". This is " << difference << " more than " << nameB << ", which has a life expectancy of " << world.countries[nameBLoc].GetLifeExpectancy() << "." << endl;
    }
    if (world.countries[nameBLoc].GetLifeExpectancy() > world.countries[nameALoc].GetLifeExpectancy()) {
        double difference = world.countries[nameBLoc].GetLifeExpectancy() - world.countries[nameALoc].GetLifeExpectancy();
        cout << "- " << nameB << " has a life expectancy of " << world.countries[nameBLoc].GetLifeExpectancy() << ". This is " << difference << " more than " << nameA << ", which has a life expectancy of " << world.countries[nameALoc].GetLifeExpectancy() << "." << endl;
    }
    if (world.countries[nameALoc].GetExpectedSchooling() > world.countries[nameBLoc].GetExpectedSchooling()) {
        double difference = world.countries[nameALoc].GetExpectedSchooling() - world.countries[nameBLoc].GetExpectedSchooling();
        cout << "- " << nameA << " has an expected years of schooling for the average newborn of " << world.countries[nameALoc].GetExpectedSchooling() << ". This is " << difference << " more than " << nameB << ", which has an expected years of schooling for the average newborn of " << world.countries[nameBLoc].GetExpectedSchooling() << "." << endl;
    }
    if (world.countries[nameBLoc].GetExpectedSchooling() > world.countries[nameALoc].GetExpectedSchooling()) {
        double difference = world.countries[nameBLoc].GetExpectedSchooling() - world.countries[nameALoc].GetExpectedSchooling();
        cout << "- " << nameB << " has an expected years of schooling for the average newborn of " << world.countries[nameBLoc].GetExpectedSchooling() << ". This is " << difference << " more than " << nameA << ", which has an expected years of schooling for the average newborn of " << world.countries[nameALoc].GetExpectedSchooling() << "." << endl;
    }
    if (world.countries[nameALoc].GetAverageSchooling() > world.countries[nameBLoc].GetAverageSchooling()) {
        double difference = world.countries[nameALoc].GetAverageSchooling() - world.countries[nameBLoc].GetAverageSchooling();
        cout << "- " << nameA << " has an average years of schooling for adults 25 and older of " << world.countries[nameALoc].GetAverageSchooling() << ". This is " << difference << " more than " << nameB << ", which has an average years of schooling of " << world.countries[nameBLoc].GetAverageSchooling() << "." << endl;
    }
    if (world.countries[nameBLoc].GetAverageSchooling() > world.countries[nameALoc].GetAverageSchooling()) {
        double difference = world.countries[nameBLoc].GetAverageSchooling() - world.countries[nameALoc].GetAverageSchooling();
        cout << "- " << nameB << " has an average years of schooling for adults 25 and older of " << world.countries[nameBLoc].GetAverageSchooling() << ". This is " << difference << " more than " << nameA << ", which has an average years of schooling of " << world.countries[nameALoc].GetAverageSchooling() << "." << endl;
    }
    if (world.countries[nameALoc].GetGNIPerCapita() > world.countries[nameBLoc].GetGNIPerCapita()) {
        double difference = world.countries[nameALoc].GetGNIPerCapita() - world.countries[nameBLoc].GetGNIPerCapita();
        cout << "- " << nameA << " has a GNI per capita of " << world.countries[nameALoc].GetGNIPerCapita() << ". This is " << difference << " more than " << nameB << ", which has a GNI per capita of " << world.countries[nameBLoc].GetGNIPerCapita() << "." << endl;
    }
    if (world.countries[nameBLoc].GetGNIPerCapita() > world.countries[nameALoc].GetGNIPerCapita()) {
        double difference = world.countries[nameBLoc].GetGNIPerCapita() - world.countries[nameALoc].GetGNIPerCapita();
        cout << "- " << nameB << " has a GNI per capita of " << world.countries[nameBLoc].GetGNIPerCapita() << ". This is " << difference << " more than " << nameA << ", which has a GNI per capita of " << world.countries[nameALoc].GetGNIPerCapita() << "." << endl;
    }
}

void MakeCustomHDIValues(World& world) {
    double healthWeight;
    double educationWeight;
    double incomeWeight;
    cout << endl;
    //cout << "Type weights 0.0 < 1.0 for health index, education index, and income index respectively. Weights must sum to 1, although note that this is not representing an actual X% Y% Z% weighting, but rather a vague approximation. Use extreme weights (0.9 on the stat with desired emphasis) to see a noticeable difference. Note that life expectancy, education, and income maxes will not change." << endl;
    cout << "Type weights for health index, education index, and income index." << endl;
    cout << "- Weights must sum to 1, although note that this is not representing an actual X% Y% Z% weighting, but rather a vague approximation." << endl;
    cout << "- Use extreme weights (0.9 on the stat with desired emphasis) to see a noticeable difference." << endl;
    cout << "- Note that life expectancy, education, and income maxes will not change." << endl;
    cout << "Health Index: ";
    cin >> healthWeight;
    cout << "Education Index: ";
    cin >> educationWeight;
    cout << "Income Index: ";
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

void MergeByLifeExpectancy(vector<Country>& result, int const l, int const m, int const r) {
    auto const arrA = m - l + 1;
    auto const arrB = r - m;

    //auto *arrL = new result[arrA];
    vector<Country> arrL(arrA);
    //auto *arrR = new result[arrB];
    vector<Country> arrR(arrB);
    for (auto i = 0; i < arrA; i++) {
        arrL[i] = result[l + i];
    }
    for (auto i = 0; i < arrB; i++) {
        arrR[i] = result[m + 1 + i];
    }

    auto arrAIdx = 0;
    auto arrBIdx = 0; 
    int totArrIdx = l; 

    while (arrAIdx < arrA && arrBIdx < arrB) {
        if (arrL[arrAIdx].GetLifeExpectancy() <= arrR[arrBIdx].GetLifeExpectancy()) {
            result[totArrIdx] = arrL[arrAIdx];
            arrAIdx++;
        }
        else {
            result[totArrIdx] = arrR[arrBIdx];
            arrBIdx++;
        }
        totArrIdx++;
    }

    while (arrAIdx < arrA) 
    {
        result[totArrIdx] = arrL[arrAIdx];
        arrAIdx++;
        totArrIdx++;
    }

    while (arrBIdx < arrB) 
    {
        result[totArrIdx] = arrR[arrBIdx];
        arrBIdx++;
        totArrIdx++;
    }
}

void MergeSortByLifeExpectancy(vector<Country>& result, int const b, int const e) {
    if (b >= e)
        return;
  
    auto m = b + (e - b) / 2;
    MergeSortByLifeExpectancy(result, b, m);
    MergeSortByLifeExpectancy(result, m + 1, e);
    MergeByLifeExpectancy(result, b, m, e);
}

vector<Country> MergeSortByLifeExpectancy(World& world) {
    vector<Country> result;
    for (int i = 0; i < world.countries.size(); i++) {
        result.push_back(world.countries[i]);
    }
    
    int const b = 0;
    int const e = result.size();
  
    auto m = b + (e - b) / 2;
    MergeSortByLifeExpectancy(result, b, e);

    return result;
}

void MergeByExpectedSchooling(vector<Country>& result, int const l, int const m, int const r) {
    auto const arrA = m - l + 1;
    auto const arrB = r - m;

    //auto *arrL = new Country[arrA];
    vector<Country> arrL(arrA);
    //auto *arrR = new Country[arrB];
    vector<Country> arrR(arrB);
    for (auto i = 0; i < arrA; i++) {
        arrL[i] = result[l + i];
    }
    for (auto i = 0; i < arrB; i++) {
        arrR[i] = result[m + 1 + i];
    }

    auto arrAIdx = 0;
    auto arrBIdx = 0; 
    int totArrIdx = l; 

    while (arrAIdx < arrA && arrBIdx < arrB) {
        if (arrL[arrAIdx].GetExpectedSchooling() <= arrR[arrBIdx].GetExpectedSchooling()) {
            result[totArrIdx] = arrL[arrAIdx];
            arrAIdx++;
        }
        else {
            result[totArrIdx] = arrR[arrBIdx];
            arrBIdx++;
        }
        totArrIdx++;
    }

    while (arrAIdx < arrA) 
    {
        result[totArrIdx] = arrL[arrAIdx];
        arrAIdx++;
        totArrIdx++;
    }

    while (arrBIdx < arrB) 
    {
        result[totArrIdx] = arrR[arrBIdx];
        arrBIdx++;
        totArrIdx++;
    }
}

void MergeSortByExpectedSchooling(vector<Country>& result, int const b, int const e) {
    if (b >= e)
        return; 
  
    auto m = b + (e - b) / 2;
    MergeSortByExpectedSchooling(result, b, m);
    MergeSortByExpectedSchooling(result, m + 1, e);
    MergeByExpectedSchooling(result, b, m, e);
}

vector<Country> MergeSortByExpectedSchooling(World& world) {
    vector<Country> result = world.countries;
    
    int const b = 0;
    int const e = result.size();
  
    auto m = b + (e - b) / 2;
    MergeSortByExpectedSchooling(result, b, e);
    

    return result;
}

void MergeByAverageSchooling(vector<Country>& result, int const l, int const m, int const r) {
    auto const arrA = m - l + 1;
    auto const arrB = r - m;

    //auto *arrL = new Country[arrA];
    vector<Country> arrL(arrA);
    //auto *arrR = new Country[arrB];
    vector<Country> arrR(arrB);
    for (auto i = 0; i < arrA; i++) {
        arrL[i] = result[l + i];
    }
    for (auto i = 0; i < arrB; i++) {
        arrR[i] = result[m + 1 + i];
    }

    auto arrAIdx = 0;
    auto arrBIdx = 0; 
    int totArrIdx = l; 

    while (arrAIdx < arrA && arrBIdx < arrB) {
        if (arrL[arrAIdx].GetAverageSchooling() <= arrR[arrBIdx].GetAverageSchooling()) {
            result[totArrIdx] = arrL[arrAIdx];
            arrAIdx++;
        }
        else {
            result[totArrIdx] = arrR[arrBIdx];
            arrBIdx++;
        }
        totArrIdx++;
    }

    while (arrAIdx < arrA) 
    {
        result[totArrIdx] = arrL[arrAIdx];
        arrAIdx++;
        totArrIdx++;
    }

    while (arrBIdx < arrB) 
    {
        result[totArrIdx] = arrR[arrBIdx];
        arrBIdx++;
        totArrIdx++;
    }
}

void MergeSortByAverageSchooling(vector<Country>& result, int const b, int const e) {
    if (b >= e)
        return; 
  
    auto m = b + (e - b) / 2;
    MergeSortByAverageSchooling(result, b, m);
    MergeSortByAverageSchooling(result, m + 1, e);
    MergeByAverageSchooling(result, b, m, e);
}

vector<Country> MergeSortByAverageSchooling(World& world) {
    vector<Country> result = world.countries;
    
    int const b = 0;
    int const e = result.size();
  
    auto m = b + (e - b) / 2;
    MergeSortByAverageSchooling(result, b, e);

    return result;
}

void MergeByGNI(vector<Country>& result, int const l, int const m, int const r) {
    auto const arrA = m - l + 1;
    auto const arrB = r - m;

    vector<Country> arrL(arrA);
    vector<Country> arrR(arrB);
    
    for (auto i = 0; i < arrA; i++) {
        arrL[i] = result[l + i];
    }
    for (auto i = 0; i < arrB; i++) {
        arrR[i] = result[m + 1 + i];
    }

    auto arrAIdx = 0;
    auto arrBIdx = 0; 
    int totArrIdx = l; 

    while (arrAIdx < arrA && arrBIdx < arrB) {
        if (arrL[arrAIdx].GetGNIPerCapita() <= arrR[arrBIdx].GetGNIPerCapita()) {
            result[totArrIdx] = arrL[arrAIdx];
            arrAIdx++;
        }
        else {
            result[totArrIdx] = arrR[arrBIdx];
            arrBIdx++;
        }
        totArrIdx++;
    }

    while (arrAIdx < arrA) 
    {
        result[totArrIdx] = arrL[arrAIdx];
        arrAIdx++;
        totArrIdx++;
    }

    while (arrBIdx < arrB) 
    {
        result[totArrIdx] = arrR[arrBIdx];
        arrBIdx++;
        totArrIdx++;
    }
}

void MergeSortByGNI(vector<Country>& result, int const b, int const e) {
    if (b >= e)
        return; 
  
    auto m = b + (e - b) / 2;
    MergeSortByGNI(result, b, m);
    MergeSortByGNI(result, m + 1, e);
    MergeByGNI(result, b, m, e);
}

vector<Country> MergeSortByGNI(World& world) {
    vector<Country> result = world.countries;
    
    int const b = 0;
    int const e = result.size();

  
    auto m = b + (e - b) / 2;
    MergeSortByGNI(result, b, e);

    return result;
}

void MergeByHDI(vector<Country>& result, int const l, int const m, int const r) {
    auto const arrA = m - l + 1;
    auto const arrB = r - m;

    vector<Country> arrL(arrA);
    vector<Country> arrR(arrB);
    for (auto i = 0; i < arrA; i++) {
        arrL[i] = result[l + i];
    }
    for (auto i = 0; i < arrB; i++) {
        arrR[i] = result[m + 1 + i];
    }

    auto arrAIdx = 0;
    auto arrBIdx = 0; 
    int totArrIdx = l; 

    while (arrAIdx < arrA && arrBIdx < arrB) {
        if (arrL[arrAIdx].GetHDI() <= arrR[arrBIdx].GetHDI()) {
            result[totArrIdx] = arrL[arrAIdx];
            arrAIdx++;
        }
        else {
            result[totArrIdx] = arrR[arrBIdx];
            arrBIdx++;
        }
        totArrIdx++;
    }

    while (arrAIdx < arrA) 
    {
        result[totArrIdx] = arrL[arrAIdx];
        arrAIdx++;
        totArrIdx++;
    }

    while (arrBIdx < arrB) 
    {
        result[totArrIdx] = arrR[arrBIdx];
        arrBIdx++;
        totArrIdx++;
    }
}

void MergeSortByHDI(vector<Country>& result, int const b, int const e) {
    if (b >= e)
        return; 
  
    auto m = b + (e - b) / 2;
    MergeSortByHDI(result, b, m);
    MergeSortByHDI(result, m + 1, e);
    MergeByHDI(result, b, m, e);
}

vector<Country> MergeSortByHDI(World& world) {
    vector<Country> result = world.countries;

    int const b = 0;
    int const e = result.size();

    MergeSortByHDI(result, b, e);

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
    //Introduction
    cout << "**************************************** Welcome to the HDI Comparison Tool! ****************************************" << endl;
    cout << endl;
    
    cout << "Program options:" << endl;
    cout << "1. Export data" << endl;
    cout << "2. Test algorithm runtimes" << endl;
    cout << "Which option would you like? : ";
    int option;
    cin >> option; 
    
    if(option == 1) {
        cout << "Please input the data file you would like to analyze: ";
    
        World world;
        string filename;
        cin >> filename;
        ReadFile(filename, world);
        cout << endl;
        cout << "HDI Options:" << endl;
        cout << "1. Normal HDI" << endl;
        cout << "2. Custom HDI" << endl;
        cout << endl;
        cout << "Select an HDI option: ";
        
        int mode;
        cin >> mode;
        if (mode == 2) {
            MakeCustomHDIValues(world);
        } else if(mode == 1) {
            MakeHDIValues(world);
        }
        cout << endl;
        cout << "1. Life Expectancy" << endl;
        cout << "2. Expected Schooling" << endl;
        cout << "3. Average Schooling" << endl;
        cout << "4. GNI/capita" << endl;
        cout << "5. HDI" << endl;
        cout << "6. Country Comparison" << endl;
        cout << "Which parameter would you like to sort by?: ";
        int choice;
        cin >> choice;
        cout << endl;
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
            case 6:
            ComparisonReport(world);
            break;
        }
        for (int i = 0; i < report.size(); i++) {
            report[i].ReportBasicInfo();
        }
    }
    else if(option == 2) {
        cout << "Please input the data file you would like to analyze: ";
    
        World world;
        string filename;
        cin >> filename;
        ReadFile(filename, world);
        
        vector<Country> temp;
        typedef std::chrono::high_resolution_clock Clock;
        
        auto t1 = Clock::now();
        temp = BucketSortByLifeExpectancy(world);
        auto t2 = Clock::now();
        nanoseconds bucketTime = duration_cast<nanoseconds>(t2-t1);
        
        auto t3 = Clock::now();
        temp = MergeSortByLifeExpectancy(world);
        auto t4 = Clock::now();
        nanoseconds mergeTime = duration_cast<nanoseconds>(t4-t3);
        
        
        cout << "Bucket Sort Time: " << bucketTime.count() << endl;
        cout << "Merge Sort Time: " << mergeTime.count() << endl;
        
        
    }
    return 0;
}
