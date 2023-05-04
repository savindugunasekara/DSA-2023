


    #include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest= root;
   int left = 2*root+1; // index of left child 
   int right = 2*root+2; // index of right child

   if (arr[largest]<arr[left]&& left <n){// check whether the left child is larger than the root
      largest=left;
   }

   if (arr[largest]<arr[right] && right< n){//check whether the right child is larger than the root
      largest=right;
   }

   if (largest!= root){
      swap(arr[largest],arr[root]);  // if root is smaller, swap it with the child

      heapify(arr,n,largest);
   }


  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap

   for (int i=n/2-1;i>=0;i--){
      heapify(arr,n,i);  // set the root to the furthest non-leaf node

   }

  
   
  
   // extracting elements from heap one by one
    for (int j=n-1;j>0;j--){
      swap(arr[0],arr[j]);  // swap the top node with the last node
      n--;
      heapify(arr,n,0);      
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n=10;

    int heap_arr[n];

    for (int i=0;i<n;i++){
        heap_arr[i]= rand()%100;// produce a random array of 10 elements as the input

    }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
