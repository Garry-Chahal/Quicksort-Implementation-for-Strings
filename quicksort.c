#include "quicksort.h"

// Swap the two cstrings provided in the parameters
void swap(char **string1, char **string2)
{
  char *temp = *string1;
  *string1 = *string2;
  *string2 = temp;
}

/*
Function that performs QuickSort based on length or alphabetical order.
If byLength is true, sort by length. Otherwise, sort by alphabetical order.
Input:  Array of cstrings
Output: Sorted list of array strings based on length or alphabetical order.
*/
void quicksort_cstrings(char *stringArray[], int size, bool byLength)
{
  // Base case if the length of the array is less than or equal to 1
  if (size <= 1)
  {
    return;
  }

  else
  {
    // The pivot is the last string in the array
    unsigned int pivot = size - 1;
    // The "larger element with the lowest index" in array used for swapping
    unsigned int swapping_index = 0;

    // Traverse through the array and compare strings with the pivot
    for (unsigned int i = 0; i < size; i++)
    {
      // Sorting by length
      if (byLength == true)
      {
        /*
        If the length of the current string is less than the 
        length of the last element (pivot)
        */
        if (strlen(stringArray[i]) < strlen(stringArray[pivot]))
        {
          // Swap the current string with the swapping index
          swap(stringArray + i, stringArray + swapping_index);
          // Increment the index to avoid swapping the same terms
          swapping_index++;
        }
      }

      // Sorting by alphabetical order
      if (byLength == false)
      {
        /*
        If the ASCII value of the first unmatched character of current string
        is less than unmatched character of the last element (pivot)
        */
        if (strcmp(stringArray[i], stringArray[pivot]) < 0)
        {
          swap(stringArray + i, stringArray + swapping_index);
          swapping_index++;
        }
      }
    }

    /*
    Swap the pivot value to the "middle", so left half is less than pivot,
    and the right half is larger than the pivot
    */
    swap(stringArray + swapping_index, stringArray + pivot);

    // Call the function again with the left half of the pivot side
    quicksort_cstrings(stringArray, swapping_index++, byLength);

    // Call the function again with the right half of the pivot side
    // This function call is over 2 lines to keep it under 80 characters.
    quicksort_cstrings(stringArray + swapping_index, size - swapping_index,
                       byLength);
  }
}