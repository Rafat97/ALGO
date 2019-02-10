/****
Activity Selection Problem

The activity selection problem is a combinatorial optimization problem concerning the selection of
non-conflicting activities to perform within a given time frame, given a set of activities each marked by a
start time (si) and finish time (fi). The problem is to select the maximum number of activities that can be
performed by a single person or machine, assuming that a person can only work on a single activity at a time.
The activity selection problem is also known as the Interval scheduling maximization problem (ISMP),
which is a special type of the more general Interval Scheduling problem.


ALGO :
    Greedy-Iterative-Activity-Selector(A, s, f):

    Sort A by finish times stored in f

    S = {A[1]}
    k = 1

    n = A.length

    for i = 2 to n:
       if s[i] ≥ f[k]:
           S = S U {A[i]}
           k = i

    return S


1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
…….a) If the start time of this activity is greater than or equal to the finish time of previously
       selected activity then select this activity and print it.


*/



#include <bits/stdc++.h>

#define ArrayMaxSize 100000000
#define ll long long


using namespace std;

struct Activitiy
{
    int start, finish;
};

bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

void printMaxActivities(Activitiy arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr+n, activityCompare);

    cout << "Following activities are selected n";

    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

    // Consider rest of the activities
    for (int j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (arr[j].start >= arr[i].finish)
      {
          cout << "(" << arr[j].start << ", "
              << arr[j].finish << "), ";
          i = j;
      }
    }
}

int main(){

    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n\n");
    printMaxActivities(arr, n);
    printf("\n\n");
    return 0;
}

