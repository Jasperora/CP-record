#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void swap(long long & a, long long & b){
    long long tmp = b;
    b = a;
    a = tmp;
}

int main(){
    vector<long long> nums;
    for(int i = 0; i < 7; ++i){
        long long n;
        cin >> n;
        nums.push_back(n);
    }

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6-i; ++j){
            if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }
    cout << nums[0] << ' ' << nums[1] << ' ' << nums[6] - nums[0] - nums[1];
}