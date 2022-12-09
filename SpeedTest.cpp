#include <cstdlib>
#include <ctime>
#include <random>
#include "RedBlackTree.h"

using namespace std;

int main()
{

    // create a simulated 3.7 million ID number system.
    const int N = 3700000;

    clock_t start = clock();
    RedBlackTree rbt = RedBlackTree();
    for (int i = 0; i < N; i++)
    {
        rbt.Insert(i);
    }
    clock_t stop = clock();

    double duration = (static_cast<double>(stop - start)) / CLOCKS_PER_SEC;
    cout << "Collected " << rbt.Size() << " ID numbers in " << (duration) << " seconds." << endl;

    // vector<double> addIDs;
    // vector<double> removeIDs;
    int randd;
    



    int rep = 0;

    // add
    while (rep != 5)
    {
            clock_t addStart = clock();
        randd = rand() ;  
            try
            {
                rbt.Insert(randd); // try catch
                clock_t addStop = clock();
             duration = (static_cast<double>(addStop - addStart)) / CLOCKS_PER_SEC;
            cout << "Added " << randd << " ID number in " << (duration) << " seconds." << endl;
            rep++;
            }
            catch(invalid_argument &){
                cout<<"exception";

            }
             
    }






    int repp = 0;

    // remove
    while (repp != 5)
    {
        clock_t removeStart = clock();
        randd = rand() % 3700001;
        // cout<<randd;
            try
            {
                rbt.Remove(randd); // try catch
                clock_t removeStop = clock();
             duration = (static_cast<double>(removeStop - removeStart)) / CLOCKS_PER_SEC;
            cout << "Removed " << randd << " ID number in " << (duration) << " seconds." << endl;
            repp++;
            }
            catch(invalid_argument &){
                // cout<<"exception";
            }
 
    }

    return 0;
}