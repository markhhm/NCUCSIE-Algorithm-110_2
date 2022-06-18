#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <ctime>

struct Task
{
    int index, p, dl;
};

bool Compare(Task a, Task b);
void MaxProfit(std::vector<Task> Tasks, int n);
int random(void);

inline bool operator<(const Task &lhs, const Task &rhs)
{
    return lhs.p < rhs.p;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    // int n = 10000;
    //  std::cin >> n;
    std::vector<Task> Tasks;
    Task temp;

    clock_t start, endT;
    float cpu_time_used;

    // for (int i = 0; i < count; i++)
    for (int i = 0; i < 20000; i++)
    {
        // std::cin >> temp.p >> temp.dl;
        (temp.p, temp.dl) = random();
        temp.index = i + 1;
        Tasks.push_back(temp);
    }
    std::sort(Tasks.begin(), Tasks.end(), Compare);

    for (int j = 0; j < 20000; j += 500)
    {
        start = clock();
        MaxProfit(Tasks, j);
        endT = clock();
        cpu_time_used = difftime(endT, start);
        std::cout << cpu_time_used / CLOCKS_PER_SEC << std::endl;
    }

    return 0;
}

bool Compare(Task a, Task b)
{
    bool val;
    a.dl < b.dl ? val = true : val = false;
    return val;
}

void MaxProfit(std::vector<Task> Tasks, int n)
{
    int end = 0, profit = 0;
    std::priority_queue<Task> pq;
    std::vector<Task> result;
    Task temp;

    for (int i = 0; i < n; i++)
    {

        end = end + Tasks.at(i).p;
        pq.push(Tasks.at(i));

        if (end <= Tasks.at(i).dl)
        {
            profit++;
        }
        else
        {
            temp = pq.top();
            end = end - temp.p;
            pq.pop();
        }
    }
    // while (!pq.empty())
    // {
    //     result.push_back(pq.top());
    //     pq.pop();
    // }
    // std::sort(result.begin(), result.end(), Compare);
    // for (int i = 0; i < profit; i++)
    // {
    //     std::cout << result.at(i).index << " ";
    // }
}

int random(void)
{
    srand((unsigned)time(0));
    int randomNumber1, randomNumber2;

    randomNumber1 = (rand() % 100000);
    randomNumber2 = (rand() % 100000);
    return randomNumber1, randomNumber2;
}