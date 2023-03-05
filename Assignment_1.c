/*Write a program to search an element from a given array by using following methods:
-->Linear Search
-->Binary Search
    It will show whether searching element is present or not.If present it will show the position of the element*/



#include<stdio.h>
#include<stdlib.h>

//binary search function
int binarySearch(int arr[],int size,int item){
    int lb = 0,up = size - 1,mid,pos;

    mid = (lb+((up - lb)/2));

    while(lb <= up){
        if(arr[mid] == item){
            pos = mid;
             return pos;
        }

        if(arr[mid]<item){
            lb = mid +1;
        }

        if(arr[mid]>item){
            up = mid - 1;
        }

    }
    return -1;
}

//linear search function
int linearSearch(int arr[],int size,int item){
    int pos;
for(int i = 0;i < size;i++){
    if(item == arr[i]){
        pos = i;
        return pos;
    }
}
return -1;
}


//Sorting algorithm
void sort(int arr[],int size){
    for(int i = 0;i < size;i++){
        for (int j = 0; j < size-i-1; j++)
        {
            /* code */
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
        

    }
}


//The main function
int main(){
int *ptr,element,n;
printf("\nEnter the size of the array:");
scanf("%d",&n);

ptr = (int *)malloc(n*sizeof(int));//dynamic memory allocation of array

printf("\nEnter the elements in the array:");//Enter elements in the array
for(int i = 0; i < n;i++){
    scanf("%d",&ptr[i]);
}

printf("\nEnter element to be searched:");//Entering the element to be searched
scanf("%d",&element);

int choice;
printf("\nEnter your choice:\n1.Linear Search\n2.Binary Search\n");
//Choose which searching to be performed
scanf("%d",&choice);

printf("\n----------------------Menu------------------------------\n");


/*int f_1,f_2;

f_1 = linearSearch(ptr,n,element);
f_2 = binarySearch(ptr,n,element);
*/


//Menu
switch (choice)
{
case 1:
    /* linear search */
    linearSearch(ptr,n,element);//call linearSearch function 
    int f_1;

    f_1 = linearSearch(ptr,n,element);
    

    if(f_1 == -1){
        printf("\nElement absent!!\n");
    }
    else{
        printf("\nElement present at position %d\n",f_1);
    }
    break;
case 2:
    /* binary search */
    sort(ptr,n);//sort the array if not sorted
    
    //print the sorted array

    printf("\nThe sorted array is:");
    for(int i = 0;i < n;i++){
        printf("\t%d\n",ptr[i]);
    }

    binarySearch(ptr,n,element);//call binarySearch function


    int f_2;


    f_2 = binarySearch(ptr,n,element);

    if(f_2 == -1){
        printf("\nElement absent!!\n");
    }
    else{
        printf("\nElement is present at position %d\n",f_2);
    }
    break;


default:
printf("\nWrong choice!!\nEnter a valid option\n");
    break;
}

return 0;
}