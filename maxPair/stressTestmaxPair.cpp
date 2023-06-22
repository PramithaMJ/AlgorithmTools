#include <iostream>
#include <vector>
#include <cstdlib> // to add random number

using namespace std;

long long maxPairProduct(vector<int> &vect) // Pass the vector by reference to avoid unnecessary copying
{
    long long result = 0;

    for (int i = 0; i < vect.size() - 1; i++)
        for (int j = i + 1; j < vect.size(); j++)
        {
            if ((vect[i] * vect[j]) > result)
            {
                result = (long long)(vect[i] * vect[j]);
            }
        }
    return result;
}

long long MaxPairwiseProductFast(vector<int> &vect)
{
    int n = vect.size();

    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
    {
        if ((max_index1 == -1) || (vect[i] > vect[max_index1]))
            max_index1 = i;
    }

    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
    {
        if ((vect[j] != vect[max_index1]) && (max_index2 == -1) || (vect[j] > vect[max_index2]))
            max_index2 = j;
    }
    return ((long long)(vect[max_index1])) * vect[max_index2];
}

int main()
{
    while (true)
    {
        int n = rand() % 10 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        long long res1 = maxPairProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2)
        {
            cout << "Wrong answer: " << res1 << " " << res2 << endl;
            break;
        }
        else
        {
            cout << "OK\n";
        }
    }

    int n;
    cin >> n;

    vector<int> vect(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }

    return 0;
}
