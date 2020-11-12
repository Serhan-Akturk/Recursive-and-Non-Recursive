//Project1
//Serhan Akturk
//9/10/12
#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

const int max = 70;

//Recurssive
unsigned long long int FiboR(unsigned long long int n) // array of size n
{
	if (n == 0 || n == 1)
		return (n);
	else return (FiboR(n - 1) + FiboR(n - 2));
}

//Non-Recurssive
unsigned long long int FiboNR(unsigned long long int n) // array of size n
{
	unsigned long long int F[max];
	F[0] = 0; F[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	return (F[n]);
}

int main()
{
	unsigned long long int array[] = { 1,5,10,15,20,25,30,35,40,45,50,55,60 };
	
	clock_t start1, end1, start2, end2;
	int w = 20; //setw() length


	cout << setw(w) << left << "Integer" << setw(w) << left << "FiboR(seconds)" << setw(w) << left << "FiboNR(seconds)" << setw(w) << left << "Fibo-value" << endl;

	
	for (int i = 0; i < 13; i++)
	{
		
		start1 = clock();
		unsigned long long int answer_R = FiboR(array[i]);
		end1 = clock() - start1;
		double time_taken_R = ((double)end1 / CLOCKS_PER_SEC);
		
		
		start2 = clock();
		unsigned long long answer_NR = FiboNR(array[i]);
		end2 = clock() - start2;
		double time_taken_NR = ((double)end2 / CLOCKS_PER_SEC);
		

		//Output
		cout << setw(w) << left << array[i] << fixed << setprecision(2) << setw(w) << left << time_taken_R << fixed << setprecision(2) << setw(w) << left << time_taken_NR << setw(w) << left << answer_NR << endl;
		

		/*
		//tests
		cout << array[i] << " R: " << answer_R << endl;
		cout << "  NR: " << answer_NR << endl;
		cout << endl;
		cout << array[i] << "\t" << time_taken_NR << "\t" << answer_R << endl;
		*/
	}


	system("pause");
	return 0;

}


