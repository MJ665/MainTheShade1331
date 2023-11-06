#include<iostream>
using namespace std;

int main()
{
 string binaryNumber1, binaryNumber2, sumBinary = "";
 int lengthNumber1, lengthNumber2, index1, index2, decimalSum = 0;
 cout<<"Enter the First Binary Number: ";
 cin>>binaryNumber1;
 cout<<"Enter the Second Binary Number: ";
 cin>>binaryNumber2;
 lengthNumber1 = binaryNumber1.size();
 lengthNumber2 = binaryNumber2.size();
 index1 = lengthNumber1 - 1;
 index2 = lengthNumber2 - 1;
 while(index1>=0 || index2>=0 || decimalSum==1)
 {
    decimalSum = decimalSum + ((index1 >= 0) ? binaryNumber1[index1] - '0' : 0);
    decimalSum = decimalSum + ((index2 >= 0) ? binaryNumber2[index2] - '0' : 0);
    sumBinary = char(decimalSum % 2 + '0') + sumBinary;
    decimalSum = decimalSum/2;
    index1--;
    index2--;
 }
 cout<<"\nSum = "<<sumBinary;
 return 0;
}