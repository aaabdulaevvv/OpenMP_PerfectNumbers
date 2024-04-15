#include <bits/stdc++.h>
#include <omp.h>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " number_of_threads < input_file" << endl;
        return 1;
    }

    omp_set_num_threads(atoi(argv[1]));

    int n;
    scanf("%d", &n);

    auto start = chrono::high_resolution_clock::now();

    vector <int> perfect;
    #pragma omp parallel for
    for (int i=2; i<=n; i++)
    {
        int sum = 1;
        for (int j=2; j<=i/2; j++)
            if (i%j == 0)
            sum += j;
        if (sum == i)
            perfect.push_back(i);
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Time spent: " << duration.count()/1000 << "." << duration.count()%1000 << " s\n";
    for (int i=0; i<perfect.size(); i++)
        cout << perfect[i] << " ";
    return 0;
}
