#define LT   218
#define RT   191
#define HL   196
#define VL   179
#define SR   80
#define SC   25
#define IP   10
#define DIM   5
#define SPACE 32
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int arr[]={57,16,42,23,33,40,8,38,29,11};
int n=sizeof(arr)/sizeof(arr[0]);
void swap(int *temp1,int *temp2){
    int temp;
    temp=*temp1;
    *temp1=*temp2;
    *temp2=temp;
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setColor(int ForgC){

    //We will need this handle to get the current background attribute
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //we use csbi for the wAttributes word.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Mask out all but the background attribute
        //, and add in the foreground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void selectsort(){
    int key;
   // while(1){
           gotoxy(SR/2,5);
    printf("SORTING VISUALIZER\n");
    for(int i=0;i<5;i++){
        gotoxy(SR/2,SC/2+i);
        switch(i){
        case 0:printf("1.Bubble Sort\n");
                break;
        case 1:printf("2.Insertion Sort\n");
                break;
        case 2:printf("3.Selection Sort\n");
                break;
        case 3:printf("4.Quick Sort\n");
                break;
        default:break;
        }
}
printf("Select the sorting algorithm\n");
scanf("%d",&key);
system("cls");
switch(key){
case 1://system("cls");
        gotoxy(SR/2,2);
        printf("BUBBLE SORT");
        getchar();
        draw(10,11);
        getchar();
        bubble_sort(arr,n);
        break;
case 2:gotoxy(SR/2,2);
        printf("INSERTION SORT");
        getchar();
        draw(10,11);
        getchar();
        insertion_sort(arr,n);
        break;
case 3:gotoxy(SR/2,2);
    printf("SELECTION SORT");
       // gotoxy(SR/2,SC/2);
       getchar();
       draw(10,11);
       getchar();
        selection_sort(arr,n);
        break;
case 4:gotoxy(SR/2,2);
    printf("QUICK SORT\n");
        getchar();
        draw(10,11);
        getchar();
        quick_sort(arr,0,n-1);

              draw(10,11);
	 for(int i=0;i<4;i++){
        gotoxy(SR-10,5+i);
        switch(i){
        case 0:printf("QUICK SORT\n");
                break;
        case 1 :printf("Auxiliary Space : O(log n)");
                break;
        case 2 :printf("Time Complexity : O(n log n)\n");
                break;
        default:break;
        }
}
 getchar();
        system("cls");
        break;
default:EXIT_SUCCESS;
        }
    }

void draw(int lind,int high){
    int ctr1;
    int ctr2;
    int ctr3;
    int start;
    int inc;
    for(ctr3=0,inc=0;ctr3<10;ctr3+=1,inc+=5){
            if(ctr3==lind || ctr3==high){
                setColor(4);
            }
        start=((SR-(DIM*IP))/2)+inc;
    gotoxy(start,SC-(arr[ctr3]/3));
   // printf("%d",SC-(arr[ctr3]/3));
    printf("%c",LT);
    for(ctr1=0;ctr1<2;ctr1+=1){
        printf("%c",HL);
    }
    printf("%c",RT);
    //getchar();
   // printf("%d",start);
    for(ctr2=0;ctr2<(arr[ctr3]/3);ctr2+=1){
        gotoxy(start,(SC-(arr[ctr3]/3)+ctr2+1));
        printf("%c",VL);
        for(ctr1=0;ctr1<2;ctr1+=1){
        printf("%c",SPACE);
        }
        printf("%c",VL);
    }
    setColor(255);
    //printf("%d",ctr2);
}
setColor(255);
    gotoxy(((SR-(DIM*IP))/2),SC);
    for(ctr1=0;ctr1<(DIM*IP);ctr1+=1){
        printf("%c",HL);
    }
}
void bubble_sort(int arr[],int n){
    system("cls");
    int outer;
    int inner;
      for(outer=0;outer<n-1;outer++){
        for(inner=0;inner<n-outer-1;inner++){
            if(arr[inner]>arr[inner+1]){
                    gotoxy(SR/2,3);
                    printf("BUBBLE SORT\n");
                    gotoxy(((SR-(DIM*IP))/2),4);
                for(int ind=0;ind<10;ind++){
                    printf("%2d   ",arr[ind]);
                }
                gotoxy(SR/2,SC+2);
               // printf("\n");
                printf("%d > %d-->SWAP",arr[inner],arr[inner+1]);
                swap(&arr[inner],&arr[inner+1]);
                draw(inner,inner+1);
                getchar();
                system("cls");

            }
        }
      }
      draw(10,11);
          for(int i=0;i<4;i++){
        gotoxy(SR-10,5+i);
        switch(i){
        case 0:printf("BUBBLE SORT\n");
                break;
        case 1:      printf("Auxiliary Space : O(1)");
                break;
        case 2 :printf("Time Complexity : O(n^2)\n");
                break;
        default:break;
        }
}
getchar();
system("cls");
}
void insertion_sort(int arr[],int n){
       //printf("i'm called");
       system("cls");
        int sorted, key, unsorted;
        int swapcount=0;
    for (sorted = 1; sorted< n; sorted++)
    {
        key = arr[sorted];
        unsorted = sorted - 1;
        gotoxy(SR/2,3);
       printf("INSERTION SORT\n");
        while (unsorted >= 0 && arr[unsorted] > key)
        {
            arr[unsorted + 1] = arr[unsorted];
            unsorted = unsorted- 1;
           // swapcount+=1;
        }
        arr[unsorted + 1] = key;
        gotoxy(((SR-(DIM*IP))/2),4);
        for(int ind=0;ind<n;ind+=1){
            printf("%2d   ",arr[ind]);
        }
        gotoxy(SR/2,SC+2);
        printf("Key element[%d] of unsorted array is placed at its position %d of sorted array",key,unsorted+1);
        draw(unsorted+1,11);
        getchar();
        system("cls");
    }
   /* for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }*/
    draw(10,11);
     for(int i=0;i<4;i++){
        gotoxy(SR-10,5+i);
        switch(i){
        case 0:printf("INSERTION SORT\n");
                break;
        case 1: printf("Auxiliary Space : O(1)\n");
                break;
        case 2 :printf("Time Complexity : O(n^2)\n");
                break;
        default:break;
        }
}
getchar();
system("cls");
}
void selection_sort(int arr[],int n){
      // printf("i'm called");
      system("cls");
      int pos, inner, min_idx;
        int swapcount=0;
    for (pos = 0; pos< n-1; pos++)
    {
        gotoxy(SR/2,3);
        printf("SELECTION SORT\n");
        min_idx = pos;
        for (inner = pos+1; inner < n; inner++)
          if (arr[inner] < arr[min_idx])
            min_idx = inner;
           if(min_idx != pos)
         gotoxy(((SR-(DIM*IP))/2),4);
        for(int ind=0;ind<n;ind+=1){
            printf("%2d   ",arr[ind]);
        }
        draw(min_idx,pos);
            gotoxy(((SR-(DIM*IP))/2),SC+3);
        printf("Smallest element of unsorted array-->%d is to be placed at %d",arr[min_idx],pos);
            getchar();
            system("cls");
            swap(&arr[min_idx], &arr[pos]);
            swapcount+=1;

    }
    draw(10,11);
         for(int i=0;i<4;i++){
        gotoxy(SR-10,5+i);
        switch(i){
        case 0:printf("SELECTION SORT\n");
                break;
        case 1:      printf("Auxiliary Space : O(1)");
                break;
        case 2 :printf("Time Complexity : O(n^2)\n");
                break;
        default:break;
        }
}
getchar();
system("cls");
}
void quick_sort(int arr[], int low, int high) {
    system("cls");
   int flag=0;
   // int swapcount=0;
  // printf("i'm called");
	if(low <= high) {
            int pivot = arr[high];
            gotoxy(SR/2,3);
            printf("QUICK SORT");
        gotoxy(SR/2,SC+2);
        printf("Pivot element-->%d",pivot);
        	gotoxy(((SR-(DIM*IP))/2),4);
        for(int ind=0;ind<n;ind+=1){
            printf("%2d   ",arr[ind]);
        }
        draw(high,11);
        getchar();
        system("cls");
	int lind= (low - 1);

	for (int hind = low; hind <= high - 1; hind++) {
		if (arr[hind] < pivot) {
			lind++;
			 gotoxy(SR/2,3);
			printf("QUICK SORT\n");
			swap(&arr[lind], &arr[hind]);
			//swapcount+=1;
			gotoxy(((SR-(DIM*IP))/2),4);
        for(int ind=0;ind<n;ind+=1){
            printf("%2d   ",arr[ind]);
        }
			draw(lind,hind);
				getchar();
            system("cls");
		}
	}
	int pi = lind+1;
	swap(&arr[lind + 1], &arr[high]);
//	swapcount+=1;
	 gotoxy(SR/2,3);
	 printf("QUICK SORT\n");
	gotoxy(((SR-(DIM*IP))/2),4);
        for(int ind=0;ind<n;ind+=1){
            printf("%2d   ",arr[ind]);
        }
			draw(lind+1,high);
	gotoxy(SR/2,SC+2);
        printf("Pivot [%d] is placed at its position %d.",pivot,lind+1);
	getchar();
	system("cls");
	//printf("Here");
	draw(lind+1,high);
	//printf("\n");
	/*printf("%15c",SPACE);
	for( int ind=0;ind<10;ind+=1){
        printf("%d%4c",arr[ind],SPACE);
    }*/
    quick_sort(arr, low, pi- 1);
    quick_sort(arr, pi + 1, high);
	}
}
int main(){
    int ind;
    selectsort();
  // draw(10,11);
   // int arr[]={57,16,42,23,33,40,8,38,29,11};
    //int n=sizeof(arr)/sizeof(arr[0]);
   // system("cls");
    //drawempty();
    //draw(10,11);
return EXIT_SUCCESS;
}
