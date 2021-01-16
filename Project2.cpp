#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
    template <class T>
    void swap(T a, T b){
    T temp = a;
    a = b;
    b = temp;
    }
    template <class T>
    void bubble(T a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){

                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            if(n <=16){
                std::cout << "Swap " << a[j] << " and " << a[j+1] << std::endl;
            }
            }
        }
    }
    }
    template <class T>
    void selection(T a[], int n){
        int min_index;
    for(int i=0; i<n-1; i++){
            min_index = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
         T temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
            if(n <=16){
                std::cout << "Swap " << a[i] << " and " << a[min_index] << std::endl;
            }
    }
    }
    template <class T>
    void insertion(T a[], int n){
    int i, j;
    T key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            if(n <=16){
                std::cout << "Swap " << a[j] << " and " << key << std::endl;
            }
            j = j - 1;
        }
        a[j + 1] = key;



    }
}
    template <class T>
    void double_ended_selection(T a[], int n){
        T min;
        T max;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        min = a[i];
        max = a[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if(a[k] > max) {
                max = a[k];
                max_i = k;
            } if(a[k] < min) {
                min = a[k];
                min_i = k;
            }
        }
        T temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
        if(n <=16){
                if(a[i] != a[min_i]){
                std::cout << "Swap " << a[i] << " and " << a[min_i] << std::endl;
                }
            }
        if (a[min_i] == max){
            T temp = a[j];
            a[j] = a[min_i];
            a[min_i] = temp;
            if(n <=16){
                if(a[i] != a[min_i]){
                std::cout << "Swap " << a[i] << " and " << a[min_i] << std::endl;
                }
            }
        }
        else{
            T temp = a[j];
            a[j] = a[max_i];
            a[max_i] = temp;
            if(n <=16){
                if(a[i] != a[max_i]){
                std::cout << "Swap " << a[i] << " and " << a[max_i] << std::endl;
                }
            }

    }
    }
    }

        template <class T>
        void exchange(T a[], int n){
        for(int i = 0; i <n-1; i++)
	{
		for (int j=i+1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				if(n<=16){
                    std::cout << "Swap " << a[i] << " and " << a[j] << std::endl;
				}
			}
		}
	}

}

        template <class T>
        void recursive_insertion(T a[], int n){
    if (n <= 1){
        return;
    }
    recursive_insertion(a, n-1 );
    int last = a[n-1];
    int j = n-2;
    while (j >= 0 && a[j] > last)
    {
        a[j+1] = a[j];
        if(n <=16){

                std::cout << "Swap " << a[j+1] << " and " << last << std::endl;
            }
        j--;
    }
    a[j+1] = last;


        }
        template <class T>
        void gnomeSort(T a[], int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (a[index] >= a[index - 1])
            index++;
        else{
            T temp = a[index];
            a[index] = a[index-1];
            a[index-1] = temp;
            if(n <=16){
                std::cout << "Swap " << a[index] << " and " << a[index-1] << std::endl;
            }
            index--;

        }
    }
    return;
}
int main()
{
    std::cout << "Please enter the size of the array\n";
	int size;
std::cin >> size;
	int k = size;
	int arr[size];
std::cout << "Please enter if you would like the array in random ordered, ascending ordered, or descending ordered sequence(1 for random, 2 for ascending, and 3 for descending)\n";
	int choice;
std::cin >> choice;
if(choice == 1){
	for(int i = 0; i<size; i++){
		arr[i] = rand();
	}
}
else if(choice == 2){
	for(int i = 0; i<size; i++){
		arr[i] = i;
	}
}
else if(choice == 3){
	for(int i=0; i<size; i++){
	arr[i] = k;
	k--;
	}
}
else{
	std::cout << "Wrong choice! Please restart the program\n";
	return 0;
}
std::cout << "Would you like to print the unsorted array? (1 for yes any other number for no)\n";
int print;
std::cin >> print;
if(print == 1){
    for(int i = 0; i<size; i++){
        std::cout << arr[i] << std::endl;
    }
}
std::cout << "Please enter what sorting algorithm you would like to use (1 for bubble, 2 for selection, 3 for insertion, 4 for double ended selection, 5 for exchange, 6 for recursive insertion, and 7 for gnome sort)\n";
int sortingchoice;
std::cin >> sortingchoice;
if(sortingchoice == 1){
	clock_t time_req;
	time_req = clock();
	bubble(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
	}
else if(sortingchoice == 2){
	clock_t time_req;
	time_req = clock();
	selection(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
}
else if(sortingchoice == 3){
	clock_t time_req;
	time_req = clock();
	insertion(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
}
else if(sortingchoice == 4){
	clock_t time_req;
	time_req = clock();
	double_ended_selection(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
}
else if(sortingchoice == 5){
	clock_t time_req;
	time_req = clock();
	exchange(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
}
else if(sortingchoice == 6){
	clock_t time_req;
	time_req = clock();
	recursive_insertion(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
}
else if(sortingchoice == 7){
	clock_t time_req;
	time_req = clock();
	gnomeSort(arr, size);
	time_req = clock() - time_req;
	std::cout << "Processing time: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n";
}
else{
    std::cout << "Wrong choice please restart the program!\n";
}
std::cout << "Would you like to print the sorted array? (1 for yes any other number for no)\n";
int finalarray;
std::cin >> finalarray;
if(finalarray == 1){
    for(int i=0; i<size; i++){
        std::cout << arr[i] << std::endl;
    }
}
return 0;
}
