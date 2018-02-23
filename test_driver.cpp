#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using std::cout;
using std::vector;
using std::ifstream;


//Cubic maximum contiguous subsequence sum algorithm.
int maxSubSum1(const std::vector<int> & a){
    int maxSum = 0;
    for (unsigned int i = 0; i < a.size(); ++i){
        for(unsigned int j = i;j<a.size();++j){
            int thisSum = 0;
            for(unsigned int k = i; k <= j; ++k){
                thisSum += a[k];
            }
            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

//Quadratic maximum contiguous subsequence sum algorithm.
int maxSubSum2(const std::vector<int> & a){
    int maxSum = 0;
    for(unsigned int i = 0; i < a.size(); ++i){
        int thisSum = 0;
        for(unsigned int j = i; j < a.size(); ++j){
            thisSum += a[j];
            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

// max of three ints
int max3(int maxLeftSum, int maxRightSum, int maxBorderSums){
	if (maxLeftSum > maxRightSum && maxLeftSum > maxBorderSums)
		return maxLeftSum;
	else if (maxRightSum > maxLeftSum && maxRightSum > maxBorderSums)
		return maxRightSum;
	else
		return maxBorderSums;
}

// recursive maxsum
int maxSumRec(const std::vector<int> & a, int left, int right){
    if(left == right){
        if(a[left] > 0){
            return a[left];
        }
        else{
            return 0;
        }
    }
    int center = (left + right) /2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);
    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >=left; i--){
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for(int j = center + 1; j <= right; ++j){
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum); 
}


//Driver for divide-and-conquer maximum contiguous
//subsequence sum algorithm.
int maxSubSum3(const std::vector<int> & a){
    return maxSumRec(a, 0, a.size() - 1);
}



//Linear-time maximum contiguous subsequence sum algorithm.
int maxSubSum4(const std::vector<int> &a){
    int maxSum = 0, thisSum = 0;
    for(unsigned int j = 0; j < a.size(); ++j){
       thisSum += a[j];
        if(thisSum > maxSum){
            maxSum = thisSum;
        }
        else if (thisSum < 0){
            thisSum = 0;
        }
    }
    return maxSum;
}

int main(int argc, char* argv[])
{
	vector<int> intArr;
	ifstream file;
	int num, sum;
	clock_t k, start, end;

	// *** open file and then read the contents into an array ***

	if (argc>1){
		
		file.open(argv[1]);
		if (file.good()){
			// cout << "file opened correctly\n"; // debug
			while(file >> num){
				intArr.push_back(num);
			}
			file.close();
		}
		else if (file.fail()){
			cout << "file did not open correctly\n";
		}
	}
	else {
		// not enough arguments
		cout << "not enough arguments\n";
	}
	

	// *** find and print time for maxsublist1 ***
	// data format: (maxsublist1 time), (maxsublist2 time), (maxsublist3 time), (maxsublist4 time)

	// find and print time for maxsublist1
	k = clock();
	do start = clock();
	while (start == k);
	// maxSubList1
	sum = maxSubSum1(intArr);
	end = clock();
	cout << "maxSubList1(n="<< intArr.size() << ") = " << sum << " @ " <<  (double)(end - start)/CLOCKS_PER_SEC << " seconds, \t";
	
	// find and print time for maxsublist2
	k = clock();
	do start = clock();
	while (start == k);
	// maxSubList2
	maxSubSum2(intArr);
	end = clock();
	cout << "maxSubList2(n="<< intArr.size() << ") = " << sum << " @ " <<  (double)(end - start)/CLOCKS_PER_SEC << " seconds, \t";

	// find and print time for maxsublist3
	k = clock();
	do start = clock();
	while (start == k);
	// maxsublist3
	maxSubSum3(intArr);
	end = clock();
	cout << "maxSubList3(n="<< intArr.size() << ") = " << sum << " @ " <<  (double)(end - start)/CLOCKS_PER_SEC << " seconds, \t";

	// find and print time for maxsublist4
	k = clock();
	do start = clock();
	while (start == k);
	// maxsublist4
	maxSubSum4(intArr);
	end = clock();
	cout << "maxSubList4(n="<< intArr.size() << ") = " << sum << " @ " <<  (double)(end - start)/CLOCKS_PER_SEC << " seconds";

	cout << "\n";

	return 0;
}