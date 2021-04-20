/*
 * Course: CS-2040
 * Lab 3: Histogram
 * Claudia Poptile
 * Last Updated: 4-06-21
 */
 
// May contain imports that are not used ?
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>
#include <cstring>

using namespace std;

void getValues(int nums[], int start, int end);
int axisWidth(int nums[], int size);
int greatestFrequency(int nums[], int size);
void drawHorizontalAxis(int axisWidth);
void labelHorizontalAxis(int axisWidth);
void drawCount(int value, int quantity);


/* 
 * Main method
 */
 
int main()
{
    // Get upper and lower bounds
    int min;
    cin >> min;
    int max;
    cin >> max;
    
    // Error message if min is greater than max
    if(min > max) {
        cout << "Error: The lower limit cannot be greater than the upper limit." << endl;
        return 0;
    }
    
//    char *nums;
//    nums = (char *)malloc(5+1);
//    cin.getline(nums, '\n');
//    string nums;
//    getline(cin, nums);
//    cin >> nums;    
//    cout<< nums.size()<< "beepbeepboopboop" << endl;
//    cout<< nums<< endl;
//    istringstream iss(nums);

    // Create array based off limits
    int size = max - min + 1;
    int nums[size] = { 0 };
    getValues(nums, min, max);
    
    // Display frequency for each number
    for(int i=size-1; i>=0; i--) {
        drawCount(i+min, nums[i]);
    }
    
    // Display horizontal axis of histogram
    int width = axisWidth(nums, size);
    drawHorizontalAxis(width);
    labelHorizontalAxis(width);
    
    return 0;
}

/*
 * Method gets values from console and stores ints in array
 * 
 * @param nums blank array to store number frequency
 * @param start lower limit of the histogram
 * @param end upper limit of the histogram
 */ 
void getValues(int nums[], int start, int end)
{
//    int stringLength = strlen(nums.c_str());
//    int stringLength = (int)nums.length();
//
//    int f = 0;
//    while (nums[f])
//        f++;
//    cout << f << endl;
//    
//    cout << "String length: " << stringLength << endl;
//    int arr[stringLength] = { 0 };
//    int j = 0, i, sum = 0;
//    
//    for (i = 0; nums[i] != '\0'; i++) {
//        if (nums[i] == ' '){
//            j++;
//        }
//        else {
//            arr[j] = arr[j]*10 + (nums[i] - 48);
//            cout << "im going to pee myself if this doesnt work" << arr[j] << endl;
//        }
//    }
//    
//    int values[end-start+1] = { 0 
//    };
//    cout << "String length: " << end-start+1 << endl;
//
//
//    for (int k = 0; k < end-start+1; i++)
//    {
//        int number = nums[k];
//        if (number < start || number > end) {
////            cout << "Error: value " << number << " is out of range" << endl;
//        }
//        else {
//            values[number-start]++;
//        }
//    }
    int num;
    cin >> num;
    while (cin && num != '\n') {
        if (num < start || num > end) {
            cout << "Error: value " << num << " is out of range" << endl;
        }
        else {
            nums[num-start]++;
        }
        cin >> num;
    }
}

/*
 * Method computes the axis width of the histogram
 * @param nums[] array of numbers and frequency
 * @param size size of the frequency array
 */
int axisWidth(int nums[], int size)
{
    int axisWidth = 10;
    int max = greatestFrequency(nums, size);
    if (axisWidth < max) 
    {
        axisWidth = (max + 10)-(max%10);
        if (max%10 == 0) {
            axisWidth-=10;
        }

    }
    return axisWidth;
}

/*
 * Method finds the greatest frequency of a number
 * 
 * @param nums[] array of number frequencies
 * @param arraySize size of the frequency array
 */
int greatestFrequency(int nums[], int arraySize)
{
    int max = 0;
    for (int index = 0; index < arraySize; index++)
    {
        if (nums[index] > max)
        {
            max = nums[index];
        }
    }
    return max;
}

/*
 * Method draws out the horizontal axis of the histogram
 * 
 * @param axisWidth the width of the horizontal axis
 */
void drawHorizontalAxis(int axisWidth)
{
    cout << "    ";
    for(int i=0; i < axisWidth/10; i++) {
        cout << "+----+----";
    }
    cout << "+" << endl;
}

/*
 * Method labels the horizontal axis of the histogram
 * 
 * @param axisWidth the width of the horizontal axis
 */
void labelHorizontalAxis(int axisWidth)
{
    cout << "    ";
    cout << "0    5    10";
    for(int i=1; i<axisWidth/10; i++) {
        cout << "   " << i*10+5 << "   " << (i+1)*10 ;
    }
}

/*
 * Method displays the frequency for each index in the array
 * 
 * @param value the number corresponding to the array index
 * @param quantity the frequency of the number
 */
void drawCount(int value, int quantity)
{
    cout << setw(3) << value << " |" ;
    string amount = "";
    for(int i=0; i<quantity; i++) {
        amount.append("#");
    }
    cout << setw(0) << amount;
    cout << endl;
}