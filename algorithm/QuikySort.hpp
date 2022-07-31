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
template <class T>
//两数交换
void swapMine(T &a, T&b)
{
    T c;
    c = a;
    a = b;
    b = c;
}
//打印数组
void printList(vector<int> list)
{
    int i = 0;
    while (i < list.size())
    {
        std::cout << list[i] << " ";
        i++;
    }
    std::cout << "     " << std::endl;
}
//把j位置的数，插入到i的前面，同时保证插入位置的数，依然在哪里。
void insertMine(vector<int> &list, const bool& a, int i, int j)
{   
    if (a && i < j)
    {   
        int povit = list[i];
        list[i] = list[j];
        for (int n = j; n > i+1; n--)
        {
            list[n] = list[n-1];
        }
        list[i+1] = povit;
    }
    else if (a == 0&& i > j)
    {
        int povit = list[i];
        list[i] = list[j];
        for (int n = j; n < i - 1; n++)
        {
            list[n] = list[n+1];
        }
        list[i-1] = povit;
    }
}

void testInsert()
{
    vector<int> a = {1, 4, 6, 0, 98, 73, -4};
    printList(a);
    insertMine(a, true, 0, 7);
    printList(a);
}



void testSwap()
{
    double a = 100;
    double b = -100;
    cout << "before swap:";
    std::cout << "a : " << a << " b: " << b << std::endl;
    swapMine(a, b);
    cout << "after swap:";
    std::cout << "a : " << a << " b: " << b << std::endl;
} 
void quikySort_mine(vector<int> *list)
{   
    for (int i = 0; i < list->size(); i++)
    {
        for (int j = 0; j < list->size(); j++)
        {
            if (i < j && (*list)[i] > (*list)[j])
            {
                int g = 10;
                insertMine(*list, true, i, j);
            }
            else if (j < i && (*list)[i] < (*list)[j])
            {
                insertMine(*list, false, i, j);
            }
        }
    }
}
void test_quikySort_mine()
{
    vector<int> a = {1, 0, 9, 81, -4, 5, 198237, -12313, 0, 1, 2, 9, 0};
    printList(a);
    quikySort_mine(&a);
    printList(a);
}

void testlist()
{
    int a = 0;
    int b[3] = {0 ,4, -4};
    std::cout << b[a] << std::endl;
    a--;
    std::cout << a << std::endl;
    b[a] = 100;
    std::cout << a << std::endl;
    std::cout << b[a] <<"  " << b[0] << "  " << b[2] << std::endl;
}