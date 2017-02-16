#include "condmatrix.h"

using namespace std;

int main()
{
        pair<int, int> index;
        double experiment_time = 0.0, total_time = 0.0, blB = 0.0, compA = 0.0, strad = 0.0, condBelief = 0.0, nlz = 0.0;
	clock_t cond_begin, cond_end;
	vector <int> b_param;
	int rem_ele, round_count = 0;
        CondMatrix cond_matrix;
        cond_matrix.debugOff();

	// for (int fod = 5; fod <= 20; fod += 5)
	for (int fod = 2; fod <= 20; fod += 2)
	{       
		round_count = 0;
		total_time = 0.0;
		for (int a = 1; a <= fod; a++)
		// for (int a = 1; a <= fod; a++)
		{
			cond_matrix.clearMatrix();
			cond_matrix.newMatrix(fod - a, a);
			cond_matrix.genIncreasingMassValues();
		//	cond_matrix.printFocalElements();
			for (int arounds = 0; arounds < 1; arounds++)
			{       
				for (int b = 1; b < a; b = b + 1)
				{       
					for (int brounds = 0; brounds <= 2000 / ((fod - 1) * (fod - 1)); brounds++)
					{       
						//cout << "A : " << a << "B : " << b << endl;;
						b_param.clear();
						for (int fill = 0; fill < a; fill++)
							b_param.push_back(fill);
						for (int rem = 1; rem <= a - b; rem++)
						{
							rem_ele = rand() % (a + 1 - rem);
							b_param.erase (b_param.begin() + rem_ele);
						}
						cond_matrix.fillingConditionedVecRandom(b_param);
						
						cond_begin = clock();
						compA = cond_matrix.calBeliefComp();
						compA = cond_matrix.calAllMasses(compA);
						cond_end = clock();
					//	cout << "Fod size : " << fod <<  "\t|A| : " << a << "\t|B| : " << b << "\tBl (B) :" << blB << "\t Nlz : " << nlz << "\t Bl ({A}) : " << compA << "\tS({A};B) : " << strad << "\tCond Belief : " << condBelief << endl;
						round_count++;
						//cout << round_count << endl;
						total_time += (double)(cond_end - cond_begin) / CLOCKS_PER_SEC; 
						//cout << endl;
					}
					//cout << "Fod size: " << fod <<  "\t|A|: " << a << "\t|B|: " << b << "\t\tTime spent: " << total_time * 1000000 << endl; // to get values in micro sec multiplied by 1000000 and divided by 1000
				}
				//cout << "Fod size: " << fod <<  "\t|A|: " << a << "\t\tTime spent: " << total_time * 1000 / (a - 1) << endl; // to get values in micro sec multiplied by 1000000 and divided by 1000
			}
		}
		cout << "Fod size: " << fod << "\tRounds: " << round_count << "\t\tAverage Time spent: " << (total_time / round_count) * 1000000 << endl; // to get values in micro sec multiplied by 1000000 and divided by 1000
	}
        return 0;
}
