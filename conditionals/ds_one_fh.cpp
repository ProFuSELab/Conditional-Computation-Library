#include "condmatrix.h"

using namespace std;

int main()
{
        pair<int, int> index;
        double experiment_time = 0.0, total_time = 0.0, blB = 0.0, compA = 0.0, strad = 0.0, condBelief = 0.0, nlz = 0.0;
	vector <int> b_param;
	int rem_ele;
        CondMatrix cond_matrix;
        cond_matrix.debugOff();

	// for (int fod = 5; fod <= 20; fod += 5)
	for (int fod = 5; fod <= 20; fod += 5)
	{       
		for (int a = 1; a <= fod; a++)
		// for (int a = 1; a <= fod; a++)
		{
			cond_matrix.clearMatrix();
			cond_matrix.newMatrix(fod - a, a);
			cond_matrix.genIncreasingMassValues();
		//	cond_matrix.printFocalElements();
			for (int arounds = 0; arounds < 1; arounds++)
			{       
				for (int b = 1; b <= a; b++)
				{       
					for (int brounds = 0; brounds < 1; brounds++)
					{       
						b_param.clear();
						for (int fill = 0; fill < a; fill++)
							b_param.push_back(fill);
						for (int rem = 1; rem <= a - b; rem++)
						{
							rem_ele = rand() % (a + 1 - rem);
							b_param.erase (b_param.begin() + rem_ele);
						}
						cond_matrix.fillingConditionedVecRandom(b_param);
						
						blB = cond_matrix.calBeliefB();
						compA = cond_matrix.calBeliefComp();
						strad = cond_matrix.calStrad();
						nlz = cond_matrix.getNConst();
						condBelief = blB / (nlz - compA - strad);
						cout << "Fod size : " << fod <<  "\t|A| : " << a << "\t|B| : " << b << "\tBl (B) :" << blB << "\t Nlz : " << nlz << "\t Bl ({A}) : " << compA << "\tS({A};B) : " << strad << "\tCond Belief : " << condBelief << endl;
						total_time += experiment_time;
					}
				}
			}
		}
		cout << "FoD size : " << fod << " Time spent : " << total_time << endl;
		total_time = 0;
	}

        return 0;
}
