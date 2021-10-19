#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int MIN_VAL = 1;
const int MAX_VAL = 10000;

const int MIN_SIZE = 1;
const int MAX_SIZE = 10000;

int maxElement(const vector<double> &vect)
{
    int max_pos = 0;
    for (int i = 1; i < vect.size(); i++)
    {
        if (vect[i] > vect[max_pos])
        {
            max_pos = i;
        }
    }

    return max_pos;
}

void prefixAvrgImproved(const vector<double> &inp, vector<double> &avrg)
{ // Big O(n)
    avrg.resize(inp.size());
    double sum = 0;
    for (int i = 0; i < inp.size(); i++)
    {
        sum += avrg[i];
        avrg[i] /= (i + 1);
    }
}

void prefixAvrg(const vector<double> &inp, vector<double> &avrg)
{ // Big O(n*n)
    avrg.resize(inp.size());
    for (int i = 0; i < inp.size(); i++)
    {
        avrg[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            avrg[i] += inp[j];
        }
        avrg[i] /= (i + 1);
    }
}

void randVect(vector<double> &vect, double min, double max)
{
    for (int i = 0; i < vect.size(); i++)
    {
        vect[i] = min + (1.0 * rand()) / (RAND_MAX / (max - min));
    }
}

int main()
{
    srand(time(0));
    for (int i = MIN_SIZE; i <= MAX_SIZE; i *= 2)
    {
        vector<double> vect(i);
        vector<double> avrg(i);
        randVect(vect, MIN_VAL, MAX_VAL);

        clock_t start1 = clock();
        prefixAvrg(vect, avrg);
        clock_t end1 = clock();

        clock_t start = clock();
        prefixAvrgImproved(vect, avrg);
        clock_t end = clock();

        double exec_time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
        cout << "1. Execution time: " << exec_time1 << " sec. for n = " << i << endl;

        double exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "2. Execution time: " << exec_time << " sec. for n = " << i << endl;
    }


    return 0;
}