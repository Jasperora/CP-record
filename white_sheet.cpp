#include <iostream>
using namespace std;


bool cover(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    // determine if first rec covers second rec
    if(x1<=x3 && x2>=x4 && y1<=y3 && y2>=y4) return true;
    else return false;
}
bool line_cover(int a1, int a2, int b1, int b2){
    // determine if b covers a
    if(b1<=a1 && b2>=a2) return true;
    else return false;
}
bool line_intersect(int a1, int a2, int b1, int b2){
    if(line_cover(a1, a2, b1, b2) || line_cover(b1, b2, a1, a2)) return true;
    if(a1<=b1 && b1<=a2 && a2<=b2) return true;
    if(b1<=a1 && a1<=b2 && b2<=a2) return true;
    return false;
}
int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    if(cover(x3, y3, x4, y4, x1, y1, x2, y2) || cover(x5, y5, x6, y6, x1, y1, x2, y2)) cout << "NO";
    else if((line_cover(x1, x2, x3, x4) && line_cover(x1, x2, x5, x6)) && min(y3, y5)<=y1 && max(y4, y6)>=y2 && line_intersect(y3, y4, y5, y6)) cout << "NO";
    else if((line_cover(y1, y2, y3, y4) && line_cover(y1, y2, y5, y6)) && min(x3, x5)<=x1 && max(x4, x6)>=x2 && line_intersect(x3, x4, x5, x6)) cout << "NO";
    else cout << "YES";
}