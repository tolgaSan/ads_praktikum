#include "sorting.h"



namespace sorting {

	//************
	// QuickSort *
	//wählen einen pivot, den wir aus dem Array nehmen
	//Pivot darf nicht anfang oder ende sein
	//wir vergleichen pivot links und pivot rechts und
	//soriteren nach Größe
	//************  
	int partition(vector<int>&arr, int left, int right){
		//pivot auswählen, 
		int x = arr[right]; //rechte Seite Ende
		int i = left - 1; //linke Seite Anfang
		//Sortierung bzw suchen des zu tauschende Element, kleiner als pivot auf die linke Seite, größer als pivot auf die rechte Seite
		for(int j = left; j <= right-1; j++){ 
			if (arr[j] <= x) { 
				i = i+1;
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[i+1], arr[right]); //Pivot rücksetzen
		return i+1; 
	}    
	void QuickSort(vector<int>& arr, int left, int right)
	{	
		//QuickSort rekursive Sortierfunktion 
		if(left < right) {
			int pivot = partition(arr, left, right);
			QuickSort(arr, left, pivot-1); //linke sortierung
			QuickSort(arr, pivot+1, right); //rechte sortierung
		}

	}


	//************
	// MergeSort *
	// Array in kleinere Arrays teilen, bis paare entstehen
	// Paare sortieren, wieder zsm fassen
	//Beim natürlichen ist der Unterschied die runs (bereits sortierte paare zsm lassen)
	//************
	void Merge(vector<int>& a, vector<int>& b, int leftPos, int rightPos, int rightEnd)
	{
		int leftEnd = rightPos-1;
		int tmpPos = leftPos;
		int n = rightEnd - leftPos + 1;
		while(leftPos <= leftEnd && rightPos <= rightEnd) {
			if(a[leftPos] <= a[rightPos]){
				b[tmpPos] = a[leftPos];
				leftPos++;
			}else{
				b[tmpPos] = a[rightPos];
				rightPos++;
			}
			tmpPos++;
		}
		while(leftPos <= leftEnd){
			b[tmpPos++] = a[leftPos++];
		}
		while(rightPos <= rightEnd){
			b[tmpPos++] = a[rightPos++];
		}
		int i = rightEnd - n +1;
		while(i <= rightEnd){
			a[i] = b[i];
			i++;
		}

	}


	void MergeSort(vector<int>& a, vector<int>& b, int low, int high)
	{
		if(low < high) {
			int middle = (low+high)/2;
			MergeSort(a, b, low, middle);
			MergeSort(a, b, middle+1, high);
			Merge(a, b, low, middle+1, high);
		}
	}

	void natMerge(vector<int> &a, vector<int> &b, int left, int middle, int right) 
	{
		Merge(a,b,left,middle,right);
	}

	void natMergeSort(vector<int> &a, vector<int> &b)
	{
		int n = a.size();
		std::vector<int> endRun;

		while(true){
			endRun.clear();

			int i = 0;
			while(i < n) {
				int start = i;
				while(i + 1 < n && a[i] <= a[i+1]) {
					++i;
				}
				++i;
				endRun.push_back(i);
			}
			if(endRun.size() == 1) break;

			for(size_t j = 0; j < endRun.size() - 1; j += 2){
				int left = (j == 0) ? 0 : endRun[j-1];
				int mid = endRun[j];
				int right = endRun[j];
				natMerge(a,b,left,mid,right);
			}
		}
	}


	//************
	// Heapsort  *
	//arbeitet nach inorder prinzip mit "baumverfahren"
	//first bottomtop dann topdown
	// Baum wird nach und nach binär aufgebaut (in order)
	// Parent mit Kind tauschen, wenn Kind größer als Parent ist
	//************
	void heapify(vector<int> &a, int n, int i)
	{
		int largest = i;
		int left = 2*i+1;
		int right = 2*i+2;

		if(left < n && a[left] > a[largest]) largest = left;

		if(right < n && a[right] > a[largest]) largest = right;

		if(largest != i){
			int temp = a[i];
			a[i] = a[largest];
			a[largest] = temp;
			heapify(a, n, largest);
 		}
	}


	void HeapSort(vector<int> &a, int n) 
	{
		n = a.size();
		for(int i = n / 2-1; i >= 0; i--) heapify(a,n,i);

		for(int i = n - 1; i >= 0; i--){
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;
			heapify(a,i,0);
		}
	}

	//************
	// Shellsort *
	// Mittels gab die Reihe "Vorsortieren" d.h. bei gap 3 bspw. 
	//in Abstand von 3 austauschen und den gap dann reduzieren mit /2
	//************
	// Hier soll Hibbard implementiert werden
	void ShellSort_2n(vector<int> &a, int n)
	{
		//Hibbard Folge H_i = 2*H_i - 1 + 1 bestimmen
		int gap = 1;
		while( gap < n ) gap = 2*gap+1;
		gap = (gap-1)/2;
		for(int gap = n/2; gap > 0; gap /= 2){
			//ins sort von Elementen mit Abstand Gap
			for(int i = gap; i < n; i++){
				int temp = a[i];
				int j = i;
				for(; j >= gap && temp < a[j-gap]; j -= gap){
					a[j] = a[j-gap];
				}
				a[j] = temp;
			}
		}
	}

	void ShellSort_3n(vector<int>& a, int n)
	{
		int gap = 1;
		while (gap < n / 3) gap = 3*gap+1;
		
		while(gap > 0){
			for(int i = gap; i < n; i++ ){
				int temp = a[i];
				int j;
				for( j = i; j >= gap && a[j-gap] > temp; j -= gap){
					a[j] = a[j-gap];
				}
				a[j] = temp;
			}
			gap = gap/3;
		}
	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }


}





