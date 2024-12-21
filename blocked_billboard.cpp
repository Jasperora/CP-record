#include <iostream>
#include <fstream>
using namespace std;


int overlap_area(int ll1_x, int ll1_y, int ur1_x, int ur1_y, int ll2_x, int ll2_y, int ur2_x, int ur2_y){
    int overlap_width = max(min(ur1_x, ur2_x)-max(ll1_x, ll2_x), 0);
    int overlap_length = max(min(ur1_y, ur2_y)-max(ll1_y, ll2_y), 0);

    return overlap_width * overlap_length;
}
int main(){
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    // ll: lower-left, ur: upper-right
    int ll1_x, ll1_y, ur1_x, ur1_y, ll2_x, ll2_y, ur2_x, ur2_y, ll_truck_x, ll_truck_y, ur_truck_x, ur_truck_y;
    fin >> ll1_x >> ll1_y >> ur1_x >> ur1_y >> ll2_x >> ll2_y >> ur2_x >> ur2_y >> ll_truck_x >> ll_truck_y >> ur_truck_x >> ur_truck_y;

    int original_total_area = (ur1_x-ll1_x)*(ur1_y-ll1_y) + (ur2_x-ll2_x)*(ur2_y-ll2_y);
    int overlap1 = overlap_area(ll1_x, ll1_y, ur1_x, ur1_y, ll_truck_x, ll_truck_y, ur_truck_x, ur_truck_y);
    int overlap2 = overlap_area(ll2_x, ll2_y, ur2_x, ur2_y, ll_truck_x, ll_truck_y, ur_truck_x, ur_truck_y);

    fout << original_total_area - overlap1 - overlap2;
}