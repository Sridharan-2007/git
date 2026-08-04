import time
import random

def interpolation_search(arr, target):
    low, high = 0, len(arr)-1
    comparisons = 0

    while low <= high and target >= arr[low] and target <= arr[high]:

        comparisons += 1

        if low == high:
            if arr[low] == target:
                return low, comparisons
            return -1, comparisons

        pos = low + ((high-low)*(target-arr[low])) // (arr[high]-arr[low])

        if arr[pos] == target:
            return pos, comparisons

        if arr[pos] < target:
            low = pos+1
        else:
            high = pos-1

    return -1, comparisons


def binary_search(arr,target):
    low, high = 0,len(arr)-1
    comparisons=0

    while low <= high:
        mid=(low+high)//2
        comparisons+=1

        if arr[mid]==target:
            return mid,comparisons

        elif arr[mid]<target:
            low=mid+1

        else:
            high=mid-1

    return -1,comparisons



def performance_analysis():

    sizes=[1000,5000,10000,50000,100000]

    print(f"{'Size':<10}{'Interpolation':<20}{'Binary':<20}{'IS Comp':<15}{'BS Comp'}")
    print("-"*75)


    for size in sizes:

        arr=sorted(random.sample(range(size*10),size))
        target=random.choice(arr)


        start=time.perf_counter()

        for _ in range(100):
            idx_is,comp_is=interpolation_search(arr,target)

        is_time=(time.perf_counter()-start)/100



        start=time.perf_counter()

        for _ in range(100):
            idx_bs,comp_bs=binary_search(arr,target)

        bs_time=(time.perf_counter()-start)/100


        print(f"{size:<10}{is_time:.6f}s          {bs_time:.6f}s          {comp_is:<15}{comp_bs}")



arr=[2,5,10,15,23,35,48,60,75,90,105,120]

target=35

idx,comparisons=interpolation_search(arr,target)

print("Array:",arr)
print("Target:",target)
print(f"Interpolation Search: Index={idx}, Comparisons={comparisons}")


performance_analysis()