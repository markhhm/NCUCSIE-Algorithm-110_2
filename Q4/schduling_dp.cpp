#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <ctime>
#define MAX 100000
using namespace std;

stack<int> s;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> trace;
class p
{
public:
    int num;
    int times;
    int deadline;
};
int deadline_cmp(p a, p b)
{
    if (a.deadline == b.deadline)
        return a.times < b.times;
    return a.deadline < b.deadline;
}
void ans_trace(int ans_i, int ans_j, vector<p> jobs, int n)
{
    while (ans_j != 0 || ans_i != 0)
    {
        if (ans_i - 1 == trace[ans_i][ans_j].first && ans_j - 1 == trace[ans_i][ans_j].second)
        {
            s.push(jobs[ans_i - 1].num);
            ans_i--;
            ans_j--;
        }
        else
        {
            ans_i--;
        }
    }
}
int ans_count(vector<p> jobs, int n)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            {
                if (dp[i - 1][j - 1] + jobs[i - 1].times <= jobs[i - 1].deadline)
                {
                    if (dp[i - 1][j - 1] + jobs[i - 1].times < dp[i - 1][j])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + jobs[i - 1].times;
                        ans = max(ans, dp[i][j]);
                        trace[i][j].first = i - 1;
                        trace[i][j].second = j - 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                        if (dp[i][j] != MAX)
                            ans = max(ans, dp[i][j]);
                        trace[i][j].first = i - 1;
                        trace[i][j].second = j;
                    }
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    if (dp[i][j] != MAX)
                        ans = max(ans, dp[i][j]);
                    trace[i][j].first = i - 1;
                    trace[i][j].second = j;
                }
            }
        }
    }
    return ans;
}

int random(void)
{
    srand((unsigned)time(0));
    int randomNumber1, randomNumber2;

    randomNumber1 = (rand() % 100000);
    randomNumber2 = (rand() % 100000);
    return randomNumber1, randomNumber2;
}

int main()
{
    // int n = 10000;
    //  cin >> n;
    vector<p> jobs;
    p tmp;

    clock_t start, endT;
    float cpu_time_used;

    for (int i = 0; i < 20000; i++)
    {
        // cin >> tmp.times >> tmp.deadline;
        (tmp.times, tmp.deadline) = random();
        tmp.num = i + 1;
        jobs.push_back(tmp);
    }
    sort(jobs.begin(), jobs.end(), deadline_cmp);
    for (int j = 500; j <= 20000; j += 500)
    {

        dp.resize(j + 1, vector<int>(j + 1, MAX));
        trace.resize(j + 1, vector<pair<int, int>>(j + 1));

        start = clock();
        int ans = ans_count(jobs, j);
        endT = clock();

        cpu_time_used = difftime(endT, start);
        std::cout << cpu_time_used / CLOCKS_PER_SEC << std::endl;

        dp.clear();
        trace.clear();
    }
    // int ans_i = n, ans_j = 0;
    // for (int j = 0; j <= n; j++)
    // {
    //     if (dp[n][j] == ans)
    //         ans_j = j;
    // }
    // ans_trace(ans_i, ans_j, jobs, n);
    // while (s.size() > 0)
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
}
