#include <vector>

class merge_sort
{
public:
    void sort(int i, std::vector<int> &values)
    {
        mergesort(values, 0, values.size()-1);
    }
private:
    void mergesort(std::vector<int> &values, int const begin, int const end)
    {
        if (begin >= end)
            return;

        int mid = begin + (end - begin)/2;
        mergesort(values, begin, mid);
        mergesort(values, mid+1, end);
        merge(values, begin, mid, end);

    }
    
    void merge(std::vector<int> values, int left, int middle, int right)
    {
        int subArrayOne = middle - left + 1;
        int subArrayTwo = right - middle;

        auto *leftArray = new int[subArrayOne];
        auto *rightArray = new int[subArrayTwo];

        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = values[left+i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = values[middle+1+j];

        int indexOne = 0, indexTwo = 0;
        int indexOfMergedArray = left;

        while (indexOne < subArrayOne && indexTwo < subArrayTwo)
        {
            if (leftArray[indexOne] <= rightArray[indexTwo])
            {
                values[indexOfMergedArray] = leftArray[indexOne];
                indexOne++;
            }
            else
            {
                values[indexOfMergedArray] = rightArray[indexTwo];
                indexTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOne < subArrayOne)
        {
            values[indexOfMergedArray] = leftArray[indexOne];
            indexOfMergedArray++;
            indexOne++;
        }

        while (indexTwo < subArrayTwo)
        {
            values[indexOfMergedArray] = rightArray[indexTwo];
            indexOfMergedArray++;
            indexTwo++;
        }

        delete[] leftArray;
        delete[] rightArray;
    }
};