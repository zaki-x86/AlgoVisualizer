/*
 * Copyright (c) 2021 M Zaki
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

template <typename Button>
void
merge(int left, int mid, int right, Button *button[])
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temp arrays
    int L[n1], R[n2];

    // Copy _data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
    {
        L[i] = _data[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = _data[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            _data[k] = L[i];
            setButtonValue(button[k], _data[k]);
            i++;
        }
        else
        {
            _data[k] = R[j];
            setButtonValue(button[k], _data[k]);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there
    // are any
    while (i < n1)
    {
        _data[k] = L[i];
        setButtonValue(button[k], _data[k]);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there
    // are any
    while (j < n2)
    {
        _data[k] = R[j];
        setButtonValue(button[k], _data[k]);
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void
SmergeSort(int left, int right, QPushButton *button[])
{
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(left, mid, button);
        mergeSort(mid + 1, right, button);

        merge(left, mid, right, button);
    }
}