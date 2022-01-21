#include<iostream>
using namespace std;
int main() {
   int lan;
   int matrix[10][10];
   int row, column;
   int sum, sum1, sum2;
   int flag = 0;
   cout<<"Enter the size of the matrix:";
   cin>>lan;
	
   cout<<"\nEnter matrix : ";
   for (row = 0; row < lan; row++) {
      for (column = 0; column < lan; column++)
         cin>>matrix[row][column];
   }

   cout<<"Entered matrix is : \n";
   for (row = 0; row < lan; row++) {
      cout<<"\n";
      for (column = 0; column < lan; column++) {
         cout<<matrix[row][column]<<" ";
      }
   }

   //For diagonal elements
   sum = 0;
   for (row = 0; row < lan; row++) {
      for (column = 0; column < lan; column++) {
         if (row == column)
            sum = sum + matrix[row][column];
      }
   }

   //For Rows
   for (row = 0; row < lan; row++) {
      sum1 = 0;
      for (column = 0; column < lan; column++) {
         sum1 = sum1 + matrix[row][column];
      }
      if (sum == sum1)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }

   //For Columns
   for (row = 0; row < lan; row++) {
      sum2 = 0;
      for (column = 0; column < lan; column++) {
         sum2 = sum2 + matrix[column][row];
      }
      if (sum == sum2)
         flag = 1;
      else {
         flag = 0;
         break;
      }
   }

   if (flag == 1)
      cout<<"\nMagic square";
   else
      cout<<"\nNo Magic square";

   return 0;
}
