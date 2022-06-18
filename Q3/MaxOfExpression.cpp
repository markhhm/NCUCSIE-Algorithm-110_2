#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <math.h>

using std::max;
using std::min;
using std::string;
using std::vector;

void PlacingParentheses(string expression)
{
    vector<long long int> numbers;
    vector<char> operators;
    string temp = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            operators.push_back(expression[i]);
            numbers.push_back(std::stoll(temp.c_str(), nullptr, 10));
            temp = "";
        }
        else
        {
            temp += expression[i];
        }
    }
    numbers.push_back(std::stoll(temp.c_str(), nullptr, 10));
    long long int length = numbers.size();
    long long int maxValue[length][length], minValue[length][length];

    string maxExp[length][length], minExp[length][length];

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == j)
            {
                maxExp[i][j] = std::to_string(numbers[i]);
                minExp[i][j] = std::to_string(numbers[i]);
                minValue[i][j] = maxValue[i][j] = numbers[i];
            }
            else
            {
                minValue[i][j] = LLONG_MAX;
                maxValue[i][j] = LLONG_MIN;
                minExp[i][j] = "";
                maxExp[i][j] = "";
            }
        }
    }

    long long int MM, Mm, mM, mm, mtemp, Mtemp;
    for (int L = 1; L < length; L++)
    {
        for (int i = 0; i < length - L; i++)
        {
            int j = i + L;
            for (int k = i; k < j; k++)
            {
                MM = 0, Mm = 0, mM = 0, mm = 0;
                switch (operators[k])
                {
                case '+':
                    MM = maxValue[i][k] + maxValue[k + 1][j];
                    Mm = maxValue[i][k] + minValue[k + 1][j];
                    mM = minValue[i][k] + maxValue[k + 1][j];
                    mm = minValue[i][k] + minValue[k + 1][j];
                    break;
                case '-':
                    MM = maxValue[i][k] - maxValue[k + 1][j];
                    Mm = maxValue[i][k] - minValue[k + 1][j];
                    mM = minValue[i][k] - maxValue[k + 1][j];
                    mm = minValue[i][k] - minValue[k + 1][j];
                    break;
                case '*':
                    MM = maxValue[i][k] * maxValue[k + 1][j];
                    Mm = maxValue[i][k] * minValue[k + 1][j];
                    mM = minValue[i][k] * maxValue[k + 1][j];
                    mm = minValue[i][k] * minValue[k + 1][j];
                    break;
                }

                Mtemp = max(MM, max(Mm, max(mM, mm)));
                mtemp = min(MM, min(Mm, min(mM, mm)));

                if (maxValue[i][j] < Mtemp)
                {
                    if (Mtemp == MM)
                    {
                        maxValue[i][j] = MM;
                        maxExp[i][j] = "(" + maxExp[i][k] + operators[k] + maxExp[k + 1][j] + ")";
                    }
                    else if (Mtemp == Mm)
                    {
                        maxValue[i][j] = Mm;
                        maxExp[i][j] = "(" + maxExp[i][k] + operators[k] + minExp[k + 1][j] + ")";
                    }
                    else if (Mtemp == mM)
                    {
                        maxValue[i][j] = mM;
                        maxExp[i][j] = "(" + minExp[i][k] + operators[k] + maxExp[k + 1][j] + ")";
                    }
                    else if (Mtemp == mm)
                    {
                        maxValue[i][j] = mm;
                        maxExp[i][j] = "(" + minExp[i][k] + operators[k] + minExp[k + 1][j] + ")";
                    }
                }

                if (minValue[i][j] > mtemp)
                {

                    if (mtemp == MM)
                    {
                        minValue[i][j] = MM;
                        minExp[i][j] = "(" + maxExp[i][k] + operators[k] + maxExp[k + 1][j] + ")";
                    }
                    else if (mtemp == Mm)
                    {
                        minValue[i][j] = Mm;
                        minExp[i][j] = "(" + maxExp[i][k] + operators[k] + minExp[k + 1][j] + ")";
                    }
                    else if (mtemp == mM)
                    {
                        minValue[i][j] = mM;
                        minExp[i][j] = "(" + minExp[i][k] + operators[k] + maxExp[k + 1][j] + ")";
                    }
                    else if (mtemp == mm)
                    {
                        minValue[i][j] = mm;
                        minExp[i][j] = "(" + minExp[i][k] + operators[k] + minExp[k + 1][j] + ")";
                    }
                }
            }
        }
    }
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            i <= j ? std::cout << " " << maxExp[i][j] : std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << maxValue[0][length - 1] << std::endl;
    // std::cout << maxExp[0][length - 1] << std::endl;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    string expression;
    std::cin >> expression;
    PlacingParentheses(expression);
}