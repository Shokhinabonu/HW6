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

	vector<double> addIDs;
	vector<double> removeIDs;
	int randd;
	int repp = 0;

	// remove
	while (repp != 5)
	{
		start = clock();
		randd = rand() % 3700001;
		// cout<<randd;

		// if (rbt.Contains(randd))
		// {
			try
			{
				rbt.Remove(randd); // try catch
			}
			catch(invalid_argument e){
			}

			clock_t stop = clock();
			double duration = (static_cast<double>(stop - start)) / CLOCKS_PER_SEC;
			cout << "Removed " << randd << " ID number in " << (duration) << " seconds." << endl;
			repp++;
		// }
	}

	repp = 0;
	// add
	while (repp != 5)
	{
		start = clock();
		randd = rand();
		// cout<<randd;
		if (!rbt.Contains(randd))
		{
			rbt.Insert(randd); // are we inserting back the same ones?
			clock_t stop = clock();
			double duration = (static_cast<double>(stop - start)) / CLOCKS_PER_SEC;
			cout << "Added " << randd << " ID number in " << (duration) << " seconds." << endl;
			repp++;
		}
	}

	return 0;
}