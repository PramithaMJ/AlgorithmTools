#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((numbers[i] * numbers[j]) > max_product)
            {
                max_product = (long long)(numbers[i] * numbers[j]);
            }
        }
    }

    return max_product;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}