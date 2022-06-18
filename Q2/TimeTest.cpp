#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <time.h>
typedef struct coord
{
    int x, y;
} coord;
std::vector<coord> vector;

double Distance(int x, int y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

double BruteForce(int begin, int end)
{
    double min;
    int count = end - begin;
    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j < 2 && i + 1 <= count; j++)
        {
            min = Distance((vector[i].x - vector[i + j].x), (vector[i].y - vector[i + j].y));
        }
    }
    return min;
}

bool CompareX(coord x1, coord x2)
{
    return x1.x < x2.x;
}

bool CompareY(coord y1, coord y2)
{
    return y1.y < y2.y;
}

double ClosestPair(int begin, int end, int timeCount)
{
    int count = 0;

    if (begin >= end)
        return 99999999;

    else if (end - begin <= timeCount)
        return BruteForce(begin, end);
    int mid = (begin + end) / 2;
    double delta = std::min(ClosestPair(begin, mid, timeCount), ClosestPair(mid + 1, end, timeCount));

    std::vector<coord> midVec;

    for (int i = mid; i >= begin && vector[mid].x - vector[i].x < delta; i--)
    {
        midVec.push_back(vector[i]);
        count++;
    }
    for (int j = mid + 1; j <= end && vector[j].x - vector[mid].x < delta; j++)
    {
        midVec.push_back(vector[j]);
        count++;
    }

    std::sort(midVec.begin(), midVec.end(), CompareY);

    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j <= 6 && i + 1 < count; j++)
        {

            double temp = Distance((midVec[i].x - midVec[i + 1].x), (midVec[i].y - midVec[i + 1].y));
            if (temp < delta)
                delta = temp;
        }
    }
    return delta;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n = 100000, i;
    int dcTime;
    std::cin >> dcTime;
    coord temp;

    clock_t start, end;
    float cpu_time_used;

    srand((unsigned)time(0));
    for (int index = 0; index < 100000; index++)
    {
        temp.x = (rand() % 20001) + (-10000);
        temp.y = (rand() % 20001) + (-10000);
        vector.push_back(temp);
    }
    std::sort(vector.begin(), vector.end(), CompareX);
    for (int i = 0; i < dcTime; i++)
    {
        start = clock();
        double min = ClosestPair(0, n - 1, i);
        end = clock();
        cpu_time_used = difftime(end, start);
        // printf("%.3lf\n", min);
        std::cout << std::fixed << std::setprecision(4) << cpu_time_used << "," << std::endl;
    }

    return 0;
}
