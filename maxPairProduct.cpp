#include <iostream>
#include <vector>

using namespace std;

long long maxPairProduct(vector<long long>& vect) // Pass the vector by reference to avoid unnecessary copying
{
    long long result = 0;

    for (int i = 0; i < vect.size() - 1; i++) 
        for (int j = i + 1; j < vect.size(); j++) 
        {
            if ((vect[i] * vect[j]) > result)
            {
                result = (vect[i] * vect[j]);
            }
        }
        return result;
}
    
int main()
{
    int n;
    cout << "Enter the input number size: ";
    cin >> n;

    vector<long long> vect(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }

    int maxproductresult = maxPairProduct(vect); // Pass the vector to the function
    cout << "Maximum Pair Product is : " << maxproductresult << endl;

    return 0;
}
