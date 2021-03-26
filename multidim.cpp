#include <iostream>
#include <cmath>
using namespace std;

int createArray(int N);
void LinearIndx(int i, int j);
void InverseIdx(int N, int I);

int main()
{
  cout << "8 x 8" << endl;
  createArray(9);    //The 8 x 8 values are created
  LinearIndx(8, 3);  // j should not be greater than i when passing values
  InverseIdx(8, 19); // first argument is dimension (n) and second is the linear index (A)

  createArray(33);    //The  32 x32 values are created
  LinearIndx(32, 7);  // j should not be greater than i when passing values
  InverseIdx(32, 19); // first argument is dimension (n) and second is the linear index (A)

  createArray(129);    //The 128 x 128 values are created
  LinearIndx(12, 10);  // j should not be greater than i when passing values
  InverseIdx(128, 19); // first argument is dimension (n) and second is the linear index (A)
}

int createArray(int N)
{
  cout << "First 20" << endl;
  int lenLinearIndx = (N * (N + 1)) / 2;
  int A[N][N];
  int C[N][N];
  int B[lenLinearIndx];

  int printer = 0;
  int lnprinter = 0;
  int cprinter = 0;
  int counter = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      int value = rand() % 1000;
      if (printer < 20)
      { //Only the first 20 will be printed

        //cout << "[" << i << "," << j << "]"
        //<< " ";
        cout << value << " "; //If you want to see the contents comment the first one and uncomment this
      }
      A[i][j] = value;
      B[counter] = value; //Assigning the same value to the linear index
      counter++;
      printer++;
      C[i][j] = value;
    }
    if (printer < 20)
    {
      cout << endl;
    }
  }

  //Printing the linear separately
  cout << endl;
  cout << "[";
  for (int b = 0; b < lenLinearIndx; b++)
  {
    if (lnprinter < 20)
    {
      cout << B[b] << ",";
      lnprinter++;
    }
  }
  cout << "]" << endl;
  if (lnprinter < 20)
  {
    cout << endl;
  }
  for (int c = 0; c < N; c++)
  {
    for (int c2; c2 <= c; c2++)
    {
      if (cprinter < 20)
      {
        cout << "[" << c << "," << c2 << "]"
             << " ";
        cprinter++;
      }
    }
  }
  if (cprinter < 20)
  {
    cout << endl;
  }
}

void LinearIndx(int i, int j)
{
  int I = ((i + 1) * 1) / 2 + j;
  cout << "[" << i << ", " << j << "]"
       << " corresponds to a linear "
       << "Index of " << I << endl;
}

void InverseIdx(int N, int A)
{

  if (A == 0)
  {
    cout << "i: " << 0 << endl;
    cout << "j: " << 0 << endl;
    return;
  }
  int lenLinearIndx = (N * (N + 1)) / 2;
  int i = ceil(pow(A, 0.5));
  int j = ((lenLinearIndx % A) % N) - 1; // 1 is subtracted since 0 should be exclude from the count

  if (lenLinearIndx < A)
  {
    cout << "A " << N << " x " << N << " cannot have " << A << " linear spaces" << endl;
    return;
  }
  cout << "A linear index at " << A << " corresponds to ";
  cout << "[i,j] : [" << i << "," << j << "]" << endl;
}