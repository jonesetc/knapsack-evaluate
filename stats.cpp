#include<fstream>
#include<cmath>

using namespace std;

double getAverage(double values[]);
double getDeviation(double values[], double average);

int main(int argc, char* argv[]) {
    if (argc < 2)
        return 1;

    ifstream fin;
    fin.open(argv[1]);

    ofstream fout;
    fout.open("report.txt", ios::out | ios::app);

    double realValues[5];
    double realAverage;
    double realDeviation;
    double userValues[5];
    double userAverage;
    double userDeviation;
    double systemValues[5];
    double systemAverage;
    double systemDeviation;

    for (int i = 0; i < 5; i++)
        fin >> realValues[i] >> userValues[i] >> systemValues[i];

    realAverage = getAverage(realValues);
    userAverage = getAverage(userValues);
    systemAverage = getAverage(systemValues);

    realDeviation = getDeviation(realValues, realAverage);
    userDeviation = getDeviation(userValues, userAverage);
    systemDeviation = getDeviation(systemValues, systemAverage);

    fout << "Average real time: " << realAverage << endl;
    fout << "Average user time: " << userAverage << endl;
    fout << "Average system time: " << systemAverage << endl;

    fout << "Standard deviation real time: " << realDeviation << endl;
    fout << "Standard deviation user time: " << userDeviation << endl;
    fout << "Standard deviation system time: " << systemDeviation << endl;

    fin.close();
    fout.close();

    return 0;
}


double getAverage(double values[]) {
    double sum = 0.0;

    for (int i = 0; i < 5; i++)
        sum += values[i];

    return (sum / 5.0);
}

double getDeviation(double values[], double average) {
    double sum = 0.0;

    for (int i = 0; i < 5; i++) {
        sum += pow(values[i] - average, 2.0);
    }

    return sqrt((sum / 5.0));
}
