#include<fstream>
#include<cmath>

using namespace std;

//Function prototypes
double getAverage(double values[]);
double getDeviation(double values[], double average);

int main(int argc, char* argv[]) {
    //Make sure there's an input file passed in
    if (argc < 2)
        return 1;

    //Open in and out files
    ifstream fin;
    fin.open(argv[1]);

    ofstream fout;
    fout.open("report.txt", ios::out | ios::app);

    //Make sure the in and out files opened
    if(!fin || !fout)
        return 1;

    //All of the important variables
    double realValues[5];
    double realAverage;
    double realDeviation;
    double userValues[5];
    double userAverage;
    double userDeviation;
    double systemValues[5];
    double systemAverage;
    double systemDeviation;

    //Initialize all of the arrays
    for (int i = 0; i < 5; i++)
        fin >> realValues[i] >> userValues[i] >> systemValues[i];

    //Get the averages
    realAverage = getAverage(realValues);
    userAverage = getAverage(userValues);
    systemAverage = getAverage(systemValues);

    //Get the deviations
    realDeviation = getDeviation(realValues, realAverage);
    userDeviation = getDeviation(userValues, userAverage);
    systemDeviation = getDeviation(systemValues, systemAverage);

    //Output the values
    fout << "Average real time: " << realAverage << endl;
    fout << "Average user time: " << userAverage << endl;
    fout << "Average system time: " << systemAverage << endl;

    fout << "Standard deviation real time: " << realDeviation << endl;
    fout << "Standard deviation user time: " << userDeviation << endl;
    fout << "Standard deviation system time: " << systemDeviation << endl;

    //Close the files and return
    fin.close();
    fout.close();

    return 0;
}

//Function that calculates the average of an array of 5 doubles
double getAverage(double values[]) {
    double sum = 0.0;

    for (int i = 0; i < 5; i++)
        sum += values[i];

    return (sum / 5.0);
}

//Function that calculates the deviation of an array of 5 doubles
//with a known average
double getDeviation(double values[], double average) {
    double sum = 0.0;

    for (int i = 0; i < 5; i++) {
        sum += pow(values[i] - average, 2.0);
    }

    return sqrt((sum / 5.0));
}
