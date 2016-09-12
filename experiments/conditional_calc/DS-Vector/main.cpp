#include "dsvector.h"

using namespace std;

int main()
{
        int index;
        double experiment_time, total_time = 0, nume, deno, condi;
	clock_t cond_begin, cond_end;
        DSVector ds_vector;
        ds_vector.debugOff();
        ds_vector.readSingletons();
        ds_vector.genIncreasingMassValues();
	vector <int> param;
	srand(time(NULL));
	for (int fod = 5; fod <= 20; fod = fod + 5) 
	{
		for (int A = 2; A <= fod; A++)
		{
			for (int rounds = 0; rounds < 1000; rounds++)
			{
				cond_begin = clock();
				for (int i = 0; i < A; i++)
				{
					if (rand() % 2 == 0)
						param.push_back(i);
				}
				ds_vector.fillingBeliefVecRandom(param);
				nume = ds_vector.calBelief();
				for (int i = A; i < fod; i++)
				{
						param.push_back(i);
				}
				ds_vector.fillingBeliefVecRandom(param);
				deno = ds_vector.calBelief();
				// cout << "Param size : " << param.size() << " Time : " << experiment_time << endl;
				param.clear();
				condi = nume / (1.0 + nume - deno);
				cond_end = clock();
				total_time += 1000 * (double)(cond_end - cond_begin) / CLOCKS_PER_SEC; 
			}
			cout << "FoD size : " << fod << "\tSize of A : " << A << " Time spent : " << total_time << endl;
			total_time = 0;
		}
		cout << endl;
	}
        return 0;
}
