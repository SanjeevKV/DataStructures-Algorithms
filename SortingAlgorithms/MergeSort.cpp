#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
Space Complexity of additional O(n) is due to Merge function
MergeSort works best for linked-lists due to this reason
*/
void Merge(vector<ll>& von, ll left, ll right){
    ll mid = (left + right) / 2;
    ll right_it = mid + 1;
    ll left_it = left;
    vector<ll> sorted_array;

    //Merge while both the arrays have elements
    while(left_it <= mid && right_it <= right){
        if(von[left_it] < von[right_it]){
            sorted_array.push_back(von[left_it]);
            left_it++;
        }
        else{
            sorted_array.push_back(von[right_it]);
            right_it++;
        }
    }

    //Merge while only left array has elements
    while(left_it <= mid){
        sorted_array.push_back(von[left_it]);
        left_it++;
    }

    //Merge while only right array has elements
    while(right_it <=  right){
        sorted_array.push_back(von[right_it]);
        right_it++;
    }

    //Overwrite the elements in the original array with sorted elements
    for(ll i = left; i <= right; i++){
        von[i] = sorted_array[i-left];
    }
}

void MergeSort(vector<ll>& von, ll left, ll right){
    if(left == right)
        return;
    ll mid = (left + right) / 2; //Find the mid-point
    MergeSort(von, left, mid); //Sort the left half
    MergeSort(von, mid + 1, right); //Sort the right half
    Merge(von, left, right); //Merge the sorted halves
}

int main(){
    ll test_cases;
    cout<<"Enter the number of test cases"<<endl;
    cin>>test_cases;
    while(test_cases--){
        ll n,input;
        cout<<"Enter the number of numbers in the array"<<endl;
        cin>>n;
        vector<ll> vector_of_numbers;
        cout<<"Enter the "<< n << " numbers, whitespace separated"<<endl;
        for(ll i = 1; i <= n; i++){
            cin>>input;
            vector_of_numbers.push_back(input);
        }
        MergeSort(vector_of_numbers,0,n-1);
        for(auto it: vector_of_numbers)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
/*
Enter the number of test cases
4
Enter the number of numbers in the array
8
Enter the 8 numbers, whitespace separated
9 8 7 6 5 4 3 2
2 3 4 5 6 7 8 9
Enter the number of numbers in the array
6
Enter the 6 numbers, whitespace separated
2 4 1 6 5 8
1 2 4 5 6 8

Enter the number of numbers in the array
3
Enter the 3 numbers, whitespace separated
4 5 6
4 5 6
Enter the number of numbers in the array
7
Enter the 7 numbers, whitespace separated
9 3 5 1 7 2 6
1 2 3 5 6 7 9
*/
