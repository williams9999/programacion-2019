#include<iostream>
#include<math.h>

using namespace std;

int mostrar_criba(vector<int> criba)
{
    cout << endl;

    for (int i = 0; i < criba.size(); i++)
        cout << criba[i] << "\t";

    cout << endl;

}

vector<int> criba_eratostenes(int n)
{
    vector<int> criba;
    int current_primo;

    
    for (int i = 2; i <= n; i++)
        criba.push_back(i);

    if (n == 2 || n == 3)
        return criba;


    vector<int>::iterator it = criba.begin();

    current_primo = *it;

    do
    {
        vector<int>::iterator it2 = it + 1;

        for(; it2 <= criba.end(); it2++)
            if(*it2 % current_primo == 0)
                criba.erase(it2);

        it++;
        current_primo = *it;

    } while (pow(current_primo, 2) < n);

    return criba;
}

int main()
{
    int   n;
    vector<int> num_primos;

    cout << "Numero limite de numeros: ";
    cin >> n;

    num_primos = criba_eratostenes(n);

    mostrar_criba(num_primos);

    
    cin.get();
    cin.get();
    return 0;
}
