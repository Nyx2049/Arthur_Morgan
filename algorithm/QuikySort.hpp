#include <iostream>
#include <stdexcept>
#include <vector>
//快速排序

// void fast_sort(std::vector<int> &list)
// {
//     const int *size = new int(list.size());
    
// }
using namespace std;

//网上的标准答案
void quickSort(int *array, int left, int right)
{
    if(NULL == array)
    {
        return;
    }
 
	if(left < right)
	{
		int pivot = array[left];
		int low = left, high = right;
		while(low < high)
		{
			while(array[high] >= pivot && low < high)
				high--;
			array[low] = array[high];
			
			while(array[low] <= pivot && low < high)
				low++;
			array[high] = array[low];
		}
		array[low] = pivot;
		
		quickSort(array, left, low - 1);
		quickSort(array, low + 1, right);
	}
}

void quickSortMy(vector<double> &array, int left, int right)
{
    if (array.size() == 0)
    {   
        std::cout << "待排序的列表为空！"<< std::endl;
        return;
    }
    if (left < right)
    {
        double pivot = array[left];
        int low = left;
        int high = right;
        while (low < high)
        {
            while (array[high] >= pivot && low < high)
                high--;
            array[low] = array[high];
            while(array[low] <= pivot && low < high)
                low++;
            array[high] = array[low];
        }
        array[low] = pivot;
        quickSortMy(array, left, low - 1);
        quickSortMy(array, low + 1, right);
    }
   
}

void runQuickSort()
{
    
	int array[]={34,65,12,43,67,5,78,10,3,70},k;
	int len=sizeof(array)/sizeof(int);
	cout<<"The orginal arrayare:"<<endl;
	for(k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
	quickSort(array,0,len-1);
	cout<<"The sorted arrayare:"<<endl;
	for(k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
}

void runQuickSortMy()
{
	vector<double> array = {1, 3.8, 2.8, 1.233, 6.33, 2.9, 100.888, 298713.18, 29831.12313, 1.233, 6.33};
	cout<<"The orginal arrayare:"<<endl;
    int len=array.size();
	for(int k=0;k<array.size();k++)
		cout<<array[k]<<",";
	cout<<endl;
	quickSortMy(array,0, len-1);
	cout<<"The sorted arrayare:"<<endl;
	for(int k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
}

void testInt()
{
    vector<double> a = {1.7, 2.8, 9.9, 100};
    cout << "sizeof(a): " << sizeof(a) << "    sizeof(double)" << sizeof(double)<<
    "   a.size():"<< a.size() << endl;
    for (int i = 0; i < a.size() ; i++)
        cout << a[i] << ", ";
    a[1] = a[3]; 
    cout << "after: ";
    for (int i = 0; i < a.size() ; i++)
        cout << a[i] << ", ";
    return;
}